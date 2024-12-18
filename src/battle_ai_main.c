#include "global.h"
#include "main.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_util.h"
#include "battle_ai_main.h"
#include "battle_controllers.h"
#include "battle_factory.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/items.h"

#define AI_ACTION_DONE          (1 << 0)
#define AI_ACTION_FLEE          (1 << 1)
#define AI_ACTION_WATCH         (1 << 2)
#define AI_ACTION_DO_NOT_ATTACK (1 << 3)

static u32 ChooseMoveOrAction_Singles(u32 battlerAi);
static u32 ChooseMoveOrAction_Doubles(u32 battlerAi);
static inline void BattleAI_DoAIProcessing(struct AI_ThinkingStruct *aiThink, u32 battlerAi, u32 battlerDef);

// ewram
EWRAM_DATA const u8 *gAIScriptPtr = NULL;   // Still used in contests
EWRAM_DATA u8 sBattler_AI = 0;

// const rom data
static s32 AI_CheckBadMove(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_TryToFaint(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_CheckViability(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_SetupFirstTurn(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_Risky(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_PreferStrongestMove(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_PreferBatonPass(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_HPAware(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_Roaming(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_Safari(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_DoubleBattle(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_PowerfulStatus(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);

static s32 (*const sBattleAiFuncTable[])(u32, u32, u32, s32) =
{
    [0] = AI_CheckBadMove,           // AI_FLAG_CHECK_BAD_MOVE
    [1] = AI_TryToFaint,             // AI_FLAG_TRY_TO_FAINT
    [2] = AI_CheckViability,         // AI_FLAG_CHECK_VIABILITY
    [3] = AI_SetupFirstTurn,         // AI_FLAG_SETUP_FIRST_TURN
    [4] = AI_Risky,                  // AI_FLAG_RISKY
    [5] = AI_PreferStrongestMove,    // AI_FLAG_PREFER_STRONGEST_MOVE
    [6] = AI_PreferBatonPass,        // AI_FLAG_PREFER_BATON_PASS
    [7] = AI_DoubleBattle,           // AI_FLAG_DOUBLE_BATTLE
    [8] = AI_HPAware,                // AI_FLAG_HP_AWARE
    [9] = AI_PowerfulStatus,         // AI_FLAG_POWERFUL_STATUS
    [10] = NULL,                     // AI_FLAG_NEGATE_UNAWARE
    [11] = NULL,                     // AI_FLAG_WILL_SUICIDE
    [12] = NULL,                     // AI_FLAG_HELP_PARTNER
    [13] = NULL,                     // Unused
    [14] = NULL,                     // Unused
    [15] = NULL,                     // Unused
    [16] = NULL,                     // Unused
    [17] = NULL,                     // Unused
    [18] = NULL,                     // Unused
    [19] = NULL,                     // Unused
    [20] = NULL,                     // Unused
    [21] = NULL,                     // Unused
    [22] = NULL,                     // Unused
    [23] = NULL,                     // Unused
    [24] = NULL,                     // Unused
    [25] = NULL,                     // Unused
    [26] = NULL,                     // Unused
    [27] = NULL,                     // Unused
    [28] = NULL,                     // Unused
    [29] = AI_Roaming,              // AI_FLAG_ROAMING
    [30] = AI_Safari,               // AI_FLAG_SAFARI
};

// Functions
void BattleAI_SetupItems(void)
{
    s32 i;
    u8 *data = (u8 *)BATTLE_HISTORY;
    const u16 *items = GetTrainerItemsFromId(gTrainerBattleOpponent_A);

    for (i = 0; i < sizeof(struct BattleHistory); i++)
        data[i] = 0;

    // Items are allowed to use in ONLY trainer battles.
    if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_BATTLE_TOWER
                               | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_SECRET_BASE | BATTLE_TYPE_FRONTIER
                               | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_RECORDED_LINK)
            )
       )
    {
        for (i = 0; i < MAX_TRAINER_ITEMS; i++)
        {
            if (items[i] != ITEM_NONE)
            {
                BATTLE_HISTORY->trainerItems[BATTLE_HISTORY->itemsNo] = items[i];
                BATTLE_HISTORY->itemsNo++;
            }
        }
    }
}

static u32 GetWildAiFlags(void)
{
    u32 avgLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u32 flags = 0;

    if (IsDoubleBattle())
        avgLevel = (GetMonData(&gEnemyParty[0], MON_DATA_LEVEL) + GetMonData(&gEnemyParty[1], MON_DATA_LEVEL)) / 2;

    flags |= AI_FLAG_CHECK_BAD_MOVE;
    if (avgLevel >= 20)
        flags |= AI_FLAG_CHECK_VIABILITY;
    if (avgLevel >= 60)
        flags |= AI_FLAG_PREFER_STRONGEST_MOVE;
    if (avgLevel >= 80)
        flags |= AI_FLAG_HP_AWARE;

    return flags;
}

static u32 GetAiFlags(u16 trainerId)
{
    u32 flags = 0;

    if (!(gBattleTypeFlags & BATTLE_TYPE_HAS_AI))
        return 0;
    if (trainerId == 0xFFFF)
    {
        flags = GetWildAiFlags();
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            flags = GetAiScriptsInRecordedBattle();
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            flags = AI_FLAG_SAFARI;
        else if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
            flags = AI_FLAG_ROAMING;
        else if (gBattleTypeFlags & BATTLE_TYPE_FACTORY)
            flags = GetAiScriptsInBattleFactory();
        else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_TRAINER_TOWER | BATTLE_TYPE_SECRET_BASE))
            flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT;
        else
            flags = GetTrainerAIFlagsFromId(trainerId);
    }

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        flags |= AI_FLAG_DOUBLE_BATTLE;
    }

    // Automatically includes AI_FLAG_SMART_MON_CHOICES to improve smart switching
    if (flags & AI_FLAG_SMART_SWITCHING)
        flags |= AI_FLAG_SMART_MON_CHOICES;

    return flags;
}

void BattleAI_SetupFlags(void)
{
    AI_THINKING_STRUCT->aiFlags[B_POSITION_PLAYER_LEFT] = 0; // player has no AI

    AI_THINKING_STRUCT->aiFlags[B_POSITION_OPPONENT_LEFT] = GetAiFlags(gTrainerBattleOpponent_A);
    if (gTrainerBattleOpponent_B != 0)
        AI_THINKING_STRUCT->aiFlags[B_POSITION_OPPONENT_RIGHT] = GetAiFlags(gTrainerBattleOpponent_B);
    else
        AI_THINKING_STRUCT->aiFlags[B_POSITION_OPPONENT_RIGHT] = AI_THINKING_STRUCT->aiFlags[B_POSITION_OPPONENT_LEFT];

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        AI_THINKING_STRUCT->aiFlags[B_POSITION_PLAYER_RIGHT] = GetAiFlags(gPartnerTrainerId - TRAINER_PARTNER(PARTNER_NONE));
    }
    else
    {
        AI_THINKING_STRUCT->aiFlags[B_POSITION_PLAYER_RIGHT] = 0; // player
    }
}

// sBattler_AI set in ComputeBattleAiScores
void BattleAI_SetupAIData(u8 defaultScoreMoves, u32 battler)
{
    s32 i;
    u8 moveLimitations;
    u32 flags[MAX_BATTLERS_COUNT];

    // Clear AI data but preserve the flags.
    memcpy(&flags[0], &AI_THINKING_STRUCT->aiFlags[0], sizeof(u32) * MAX_BATTLERS_COUNT);
    memset(AI_THINKING_STRUCT, 0, sizeof(struct AI_ThinkingStruct));
    memcpy(&AI_THINKING_STRUCT->aiFlags[0], &flags[0], sizeof(u32) * MAX_BATTLERS_COUNT);

    // Conditional score reset, unlike Ruby.
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (defaultScoreMoves & 1)
            AI_THINKING_STRUCT->score[i] = AI_SCORE_DEFAULT;
        else
            AI_THINKING_STRUCT->score[i] = 0;

        defaultScoreMoves >>= 1;
    }

    moveLimitations = AI_DATA->moveLimitations[battler];

    // Ignore moves that aren't possible to use.
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBitTable[i] & moveLimitations)
            AI_THINKING_STRUCT->score[i] = 0;
    }

    //sBattler_AI = battler;
    gBattlerTarget = SetRandomTarget(sBattler_AI);
    gBattleStruct->aiChosenTarget[sBattler_AI] = gBattlerTarget;
}

u32 BattleAI_ChooseMoveOrAction(void)
{
    u32 ret;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        ret = ChooseMoveOrAction_Singles(sBattler_AI);
    else
        ret = ChooseMoveOrAction_Doubles(sBattler_AI);

    // Clear protect structures, some flags may be set during AI calcs
    // e.g. pranksterElevated from GetMovePriority
    memset(&gProtectStructs, 0, MAX_BATTLERS_COUNT * sizeof(struct ProtectStruct));
    #if TESTING
    TestRunner_Battle_CheckAiMoveScores(sBattler_AI);
    #endif // TESTING
    return ret;
}

// damages/other info computed in GetAIDataAndCalcDmg
u32 ComputeBattleAiScores(u32 battler)
{
    sBattler_AI = battler;
    BattleAI_SetupAIData(0xF, sBattler_AI);
    return BattleAI_ChooseMoveOrAction();
}

static void CopyBattlerDataToAIParty(u32 bPosition, u32 side)
{
    u32 battler = GetBattlerAtPosition(bPosition);
    struct AiPartyMon *aiMon = &AI_PARTY->mons[side][gBattlerPartyIndexes[battler]];
    struct BattlePokemon *bMon = &gBattleMons[battler];

    aiMon->species = bMon->species;
    aiMon->level = bMon->level;
    aiMon->status = bMon->status1;
    aiMon->gender = GetBattlerGender(battler);
    aiMon->isFainted = FALSE;
    aiMon->wasSentInBattle = TRUE;
    aiMon->switchInCount++;
}

void Ai_InitPartyStruct(void)
{
    u32 i;
    bool32 isOmniscient = (AI_THINKING_STRUCT->aiFlags[B_POSITION_OPPONENT_LEFT] & AI_FLAG_OMNISCIENT) || (AI_THINKING_STRUCT->aiFlags[B_POSITION_OPPONENT_RIGHT] & AI_FLAG_OMNISCIENT);
    struct Pokemon *mon;

    AI_PARTY->count[B_SIDE_PLAYER] = gPlayerPartyCount;
    AI_PARTY->count[B_SIDE_OPPONENT] = gEnemyPartyCount;

    // Save first 2 or 4(in doubles) mons
    CopyBattlerDataToAIParty(B_POSITION_PLAYER_LEFT, B_SIDE_PLAYER);
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        CopyBattlerDataToAIParty(B_POSITION_PLAYER_RIGHT, B_SIDE_PLAYER);

    // If player's partner is AI, save opponent mons
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        CopyBattlerDataToAIParty(B_POSITION_OPPONENT_LEFT, B_SIDE_OPPONENT);
        CopyBattlerDataToAIParty(B_POSITION_OPPONENT_RIGHT, B_SIDE_OPPONENT);
    }

    // Find fainted mons
    for (i = 0; i < AI_PARTY->count[B_SIDE_PLAYER]; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
            AI_PARTY->mons[B_SIDE_PLAYER][i].isFainted = TRUE;

        if (isOmniscient)
        {
            u32 j;
            mon = &gPlayerParty[i];
            AI_PARTY->mons[B_SIDE_PLAYER][i].item = GetMonData(mon, MON_DATA_HELD_ITEM);
            AI_PARTY->mons[B_SIDE_PLAYER][i].heldEffect = ItemId_GetHoldEffect(AI_PARTY->mons[B_SIDE_PLAYER][i].item);
            AI_PARTY->mons[B_SIDE_PLAYER][i].ability = GetMonAbility(mon);
            for (j = 0; j < MAX_MON_MOVES; j++)
                AI_PARTY->mons[B_SIDE_PLAYER][i].moves[j] = GetMonData(mon, MON_DATA_MOVE1 + j);
        }
    }
}

void Ai_UpdateSwitchInData(u32 battler)
{
    u32 i;
    u32 side = GetBattlerSide(battler);
    struct AiPartyMon *aiMon = &AI_PARTY->mons[side][gBattlerPartyIndexes[battler]];

    // See if the switched-in mon has been already in battle
    if (aiMon->wasSentInBattle)
    {
        if (aiMon->ability)
            BATTLE_HISTORY->abilities[battler] = aiMon->ability;
        if (aiMon->heldEffect)
            BATTLE_HISTORY->itemEffects[battler] = aiMon->heldEffect;
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (aiMon->moves[i])
                BATTLE_HISTORY->usedMoves[battler][i] = aiMon->moves[i];
        }
        aiMon->switchInCount++;
        aiMon->status = gBattleMons[battler].status1; // Copy status, because it could've been changed in battle.
    }
    else // If not, copy the newly switched-in mon in battle and clear battle history.
    {
        ClearBattlerMoveHistory(battler);
        ClearBattlerAbilityHistory(battler);
        ClearBattlerItemEffectHistory(battler);
        CopyBattlerDataToAIParty(GetBattlerPosition(battler), side);
    }
}

void Ai_UpdateFaintData(u32 battler)
{
    struct AiPartyMon *aiMon = &AI_PARTY->mons[GetBattlerSide(battler)][gBattlerPartyIndexes[battler]];
    ClearBattlerMoveHistory(battler);
    ClearBattlerAbilityHistory(battler);
    ClearBattlerItemEffectHistory(battler);
    aiMon->isFainted = TRUE;
}

static void SetBattlerAiData(u32 battler, struct AiLogicData *aiData)
{
    u32 ability, holdEffect;

    ability = aiData->abilities[battler] = AI_DecideKnownAbilityForTurn(battler);
    aiData->items[battler] = gBattleMons[battler].item;
    holdEffect = aiData->holdEffects[battler] = AI_DecideHoldEffectForTurn(battler);
    aiData->holdEffectParams[battler] = GetBattlerHoldEffectParam(battler);
    aiData->predictedMoves[battler] = gLastMoves[battler];
    aiData->hpPercents[battler] = GetHealthPercentage(battler);
    aiData->moveLimitations[battler] = CheckMoveLimitations(battler, 0, MOVE_LIMITATIONS_ALL);
    aiData->speedStats[battler] = GetBattlerTotalSpeedStatArgs(battler, ability, holdEffect);
}

static u32 Ai_SetMoveAccuracy(struct AiLogicData *aiData, u32 battlerAtk, u32 battlerDef, u32 move)
{
    u32 accuracy;
    u32 abilityAtk = aiData->abilities[battlerAtk];
    u32 abilityDef = aiData->abilities[battlerAtk];
    if (abilityAtk == ABILITY_NO_GUARD || abilityDef == ABILITY_NO_GUARD || gMovesInfo[move].accuracy == 0) // Moves with accuracy 0 or no guard ability always hit.
        accuracy = 100;
    else
        accuracy = GetTotalAccuracy(battlerAtk, battlerDef, move, abilityAtk, abilityDef, aiData->holdEffects[battlerAtk], aiData->holdEffects[battlerDef]);

    return accuracy;
}

static void SetBattlerAiMovesData(struct AiLogicData *aiData, u32 battlerAtk, u32 battlersCount)
{
    u32 battlerDef, i, weather;
    u16 *moves;

    SaveBattlerData(battlerAtk);
    moves = GetMovesArray(battlerAtk);
    weather = AI_GetWeather(aiData);

    // Simulate dmg for both ai controlled mons and for player controlled mons.
    for (battlerDef = 0; battlerDef < battlersCount; battlerDef++)
    {
        if (battlerAtk == battlerDef || !IsBattlerAlive(battlerDef))
            continue;

        SaveBattlerData(battlerDef);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            s32 dmg = 0;
            u8 effectiveness = AI_EFFECTIVENESS_x0;
            u32 move = moves[i];

            if (move != 0
             && move != 0xFFFF
             //&& gMovesInfo[move].power != 0  /* we want to get effectiveness and accuracy of status moves */
             && !(aiData->moveLimitations[battlerAtk] & gBitTable[i]))
            {
                dmg = AI_CalcDamage(move, battlerAtk, battlerDef, &effectiveness, TRUE, weather);
                aiData->moveAccuracy[battlerAtk][battlerDef][i] = Ai_SetMoveAccuracy(aiData, battlerAtk, battlerDef, move);
            }
            aiData->simulatedDmg[battlerAtk][battlerDef][i] = dmg;
            aiData->effectiveness[battlerAtk][battlerDef][i] = effectiveness;
        }
    }
}

void SetAiLogicDataForTurn(struct AiLogicData *aiData)
{
    u32 battlerAtk, battlersCount;

    memset(aiData, 0, sizeof(struct AiLogicData));
    if (!(gBattleTypeFlags & BATTLE_TYPE_HAS_AI))
        return;

    // Set delay timer to count how long it takes for AI to choose action/move
    gBattleStruct->aiDelayTimer = gMain.vblankCounter1;

    aiData->weatherHasEffect = WEATHER_HAS_EFFECT;
    // get/assume all battler data and simulate AI damage
    battlersCount = gBattlersCount;
    for (battlerAtk = 0; battlerAtk < battlersCount; battlerAtk++)
    {
        if (!IsBattlerAlive(battlerAtk))
            continue;

        SetBattlerAiData(battlerAtk, aiData);
        SetBattlerAiMovesData(aiData, battlerAtk, battlersCount);
    }
}

static bool32 AI_SwitchMonIfSuitable(u32 battler, bool32 doubleBattle)
{
    u32 monToSwitchId = AI_DATA->mostSuitableMonId[battler];
    if (monToSwitchId != PARTY_SIZE && IsValidForBattle(&GetBattlerParty(battler)[monToSwitchId]))
    {
        gBattleMoveDamage = monToSwitchId;
        // Edge case: See if partner already chose to switch into the same mon
        if (doubleBattle)
        {
            u32 partner = BATTLE_PARTNER(battler);
            if (AI_DATA->shouldSwitchMon & gBitTable[partner] && AI_DATA->monToSwitchId[partner] == monToSwitchId)
            {
                return FALSE;
            }
        }
        AI_DATA->shouldSwitchMon |= gBitTable[battler];
        AI_DATA->monToSwitchId[battler] = monToSwitchId;
        return TRUE;
    }
    return FALSE;
}

static bool32 AI_ShouldSwitchIfBadMoves(u32 battler, bool32 doubleBattle)
{
    u32 i, j;
    // If can switch.
    if (CountUsablePartyMons(battler) > 0
        && !IsBattlerTrapped(battler, TRUE)
        && !(gBattleTypeFlags & (BATTLE_TYPE_ARENA | BATTLE_TYPE_PALACE))
        && AI_THINKING_STRUCT->aiFlags[battler] & (AI_FLAG_CHECK_VIABILITY | AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_PREFER_BATON_PASS))
    {
        // Consider switching if all moves are worthless to use.
        if (GetTotalBaseStat(gBattleMons[battler].species) >= 310 // Mon is not weak.
            && gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 2) // Mon has more than 50% of its HP
        {
            s32 cap = AI_THINKING_STRUCT->aiFlags[battler] & (AI_FLAG_CHECK_VIABILITY) ? 95 : 93;
            if (doubleBattle)
            {
                for (i = 0; i < MAX_BATTLERS_COUNT; i++)
                {
                    if (i != battler && IsBattlerAlive(i))
                    {
                        for (j = 0; j < MAX_MON_MOVES; j++)
                        {
                            if (gBattleStruct->aiFinalScore[battler][i][j] > cap)
                                break;
                        }
                        if (j != MAX_MON_MOVES)
                            break;
                    }
                }
                if (i == MAX_BATTLERS_COUNT && AI_SwitchMonIfSuitable(battler, doubleBattle))
                    return TRUE;
            }
            else
            {
                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    if (AI_THINKING_STRUCT->score[i] > cap)
                        break;
                }

                if (i == MAX_MON_MOVES && AI_SwitchMonIfSuitable(battler, doubleBattle))
                    return TRUE;
            }

        }

        // Consider switching if your mon with truant is bodied by Protect spam.
        // Or is using a double turn semi invulnerable move(such as Fly) and is faster.
        if (GetBattlerAbility(battler) == ABILITY_TRUANT
            && IsTruantMonVulnerable(battler, gBattlerTarget)
            && gDisableStructs[battler].truantCounter
            && gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 2
            && AI_SwitchMonIfSuitable(battler, doubleBattle))
        {
            return TRUE;
        }
    }
    return FALSE;
}

static u32 ChooseMoveOrAction_Singles(u32 battlerAi)
{
    u8 currentMoveArray[MAX_MON_MOVES];
    u8 consideredMoveArray[MAX_MON_MOVES];
    u32 numOfBestMoves;
    s32 i;
    u32 flags = AI_THINKING_STRUCT->aiFlags[battlerAi];

    AI_DATA->partnerMove = 0;   // no ally
    while (flags != 0)
    {
        if (flags & 1)
        {
            BattleAI_DoAIProcessing(AI_THINKING_STRUCT, battlerAi, gBattlerTarget);
        }
        flags >>= 1;
        AI_THINKING_STRUCT->aiLogicId++;
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        gBattleStruct->aiFinalScore[battlerAi][gBattlerTarget][i] = AI_THINKING_STRUCT->score[i];
    }

    // Check special AI actions.
    if (AI_THINKING_STRUCT->aiAction & AI_ACTION_FLEE)
        return AI_CHOICE_FLEE;
    if (AI_THINKING_STRUCT->aiAction & AI_ACTION_WATCH)
        return AI_CHOICE_WATCH;

    // Switch mon if there are no good moves to use.
    if (AI_ShouldSwitchIfBadMoves(battlerAi, FALSE))
        return AI_CHOICE_SWITCH;

    numOfBestMoves = 1;
    currentMoveArray[0] = AI_THINKING_STRUCT->score[0];
    consideredMoveArray[0] = 0;

    for (i = 1; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[battlerAi].moves[i] != MOVE_NONE)
        {
            // In ruby, the order of these if statements is reversed.
            if (currentMoveArray[0] == AI_THINKING_STRUCT->score[i])
            {
                currentMoveArray[numOfBestMoves] = AI_THINKING_STRUCT->score[i];
                consideredMoveArray[numOfBestMoves++] = i;
            }
            if (currentMoveArray[0] < AI_THINKING_STRUCT->score[i])
            {
                numOfBestMoves = 1;
                currentMoveArray[0] = AI_THINKING_STRUCT->score[i];
                consideredMoveArray[0] = i;
            }
        }
    }
    return consideredMoveArray[Random() % numOfBestMoves];
}

static u32 ChooseMoveOrAction_Doubles(u32 battlerAi)
{
    s32 i, j;
    u32 flags;
    s32 bestMovePointsForTarget[MAX_BATTLERS_COUNT];
    u8 mostViableTargetsArray[MAX_BATTLERS_COUNT];
    u8 actionOrMoveIndex[MAX_BATTLERS_COUNT];
    s32 mostViableMovesScores[MAX_MON_MOVES];
    u8 mostViableMovesIndices[MAX_MON_MOVES];
    u32 mostViableTargetsNo;
    u32 mostViableMovesNo;
    s32 mostMovePoints;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (i == battlerAi || gBattleMons[i].hp == 0)
        {
            actionOrMoveIndex[i] = 0xFF;
            bestMovePointsForTarget[i] = -1;
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
                BattleAI_SetupAIData(gBattleStruct->palaceFlags >> 4, battlerAi);
            else
                BattleAI_SetupAIData(0xF, battlerAi);

            gBattlerTarget = i;

            AI_DATA->partnerMove = GetAllyChosenMove(battlerAi);
            AI_THINKING_STRUCT->aiLogicId = 0;
            AI_THINKING_STRUCT->movesetIndex = 0;
            flags = AI_THINKING_STRUCT->aiFlags[sBattler_AI];

            while (flags != 0)
            {
                if (flags & 1)
                {
                    BattleAI_DoAIProcessing(AI_THINKING_STRUCT, battlerAi, gBattlerTarget);
                }
                flags >>= 1;
                AI_THINKING_STRUCT->aiLogicId++;
            }

            if (AI_THINKING_STRUCT->aiAction & AI_ACTION_FLEE)
            {
                actionOrMoveIndex[i] = AI_CHOICE_FLEE;
            }
            else if (AI_THINKING_STRUCT->aiAction & AI_ACTION_WATCH)
            {
                actionOrMoveIndex[i] = AI_CHOICE_WATCH;
            }
            else
            {
                mostViableMovesScores[0] = AI_THINKING_STRUCT->score[0];
                mostViableMovesIndices[0] = 0;
                mostViableMovesNo = 1;
                for (j = 1; j < MAX_MON_MOVES; j++)
                {
                    if (gBattleMons[battlerAi].moves[j] != 0)
                    {
                        if (mostViableMovesScores[0] == AI_THINKING_STRUCT->score[j])
                        {
                            mostViableMovesScores[mostViableMovesNo] = AI_THINKING_STRUCT->score[j];
                            mostViableMovesIndices[mostViableMovesNo] = j;
                            mostViableMovesNo++;
                        }
                        if (mostViableMovesScores[0] < AI_THINKING_STRUCT->score[j])
                        {
                            mostViableMovesScores[0] = AI_THINKING_STRUCT->score[j];
                            mostViableMovesIndices[0] = j;
                            mostViableMovesNo = 1;
                        }
                    }
                }
                actionOrMoveIndex[i] = mostViableMovesIndices[Random() % mostViableMovesNo];
                bestMovePointsForTarget[i] = mostViableMovesScores[0];

                // Don't use a move against ally if it has less than 100 points.
                if (i == BATTLE_PARTNER(battlerAi) && bestMovePointsForTarget[i] < AI_SCORE_DEFAULT)
                {
                    bestMovePointsForTarget[i] = -1;
                }
            }

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                gBattleStruct->aiFinalScore[battlerAi][gBattlerTarget][j] = AI_THINKING_STRUCT->score[j];
            }
        }
    }

    // Switch mon if all of the moves are bad to use against any of the target.
    if (AI_ShouldSwitchIfBadMoves(battlerAi, TRUE))
        return AI_CHOICE_SWITCH;

    mostMovePoints = bestMovePointsForTarget[0];
    mostViableTargetsArray[0] = 0;
    mostViableTargetsNo = 1;

    for (i = 1; i < MAX_BATTLERS_COUNT; i++)
    {
        if (mostMovePoints == bestMovePointsForTarget[i])
        {
            mostViableTargetsArray[mostViableTargetsNo] = i;
            mostViableTargetsNo++;
        }
        if (mostMovePoints < bestMovePointsForTarget[i])
        {
            mostMovePoints = bestMovePointsForTarget[i];
            mostViableTargetsArray[0] = i;
            mostViableTargetsNo = 1;
        }
    }

    gBattlerTarget = mostViableTargetsArray[Random() % mostViableTargetsNo];
    gBattleStruct->aiChosenTarget[battlerAi] = gBattlerTarget;
    return actionOrMoveIndex[gBattlerTarget];
}

static inline bool32 ShouldConsiderMoveForBattler(u32 battlerAi, u32 battlerDef, u32 move)
{
    if (battlerAi == BATTLE_PARTNER(battlerDef))
    {
        if (gMovesInfo[move].target == MOVE_TARGET_BOTH || gMovesInfo[move].target == MOVE_TARGET_OPPONENTS_FIELD)
            return FALSE;
    }
    return TRUE;
}

static inline void BattleAI_DoAIProcessing(struct AI_ThinkingStruct *aiThink, u32 battlerAi, u32 battlerDef)
{
    do
    {
        if (gBattleMons[battlerAi].pp[aiThink->movesetIndex] == 0)
            aiThink->moveConsidered = MOVE_NONE;
        else
            aiThink->moveConsidered = gBattleMons[battlerAi].moves[aiThink->movesetIndex];

        // There is no point in calculating scores for all 3 battlers(2 opponents + 1 ally) with certain moves.
        if (aiThink->moveConsidered != MOVE_NONE
          && aiThink->score[aiThink->movesetIndex] > 0
          && ShouldConsiderMoveForBattler(battlerAi, battlerDef, aiThink->moveConsidered))
        {
            if (aiThink->aiLogicId < ARRAY_COUNT(sBattleAiFuncTable)
              && sBattleAiFuncTable[aiThink->aiLogicId] != NULL)
            {
                // Call AI function
                aiThink->score[aiThink->movesetIndex] =
                    sBattleAiFuncTable[aiThink->aiLogicId](battlerAi,
                      battlerDef,
                      aiThink->moveConsidered,
                      aiThink->score[aiThink->movesetIndex]);
            }
        }
        else
        {
            aiThink->score[aiThink->movesetIndex] = 0;
        }
        aiThink->movesetIndex++;
    } while (aiThink->movesetIndex < MAX_MON_MOVES && !(aiThink->aiAction & AI_ACTION_DO_NOT_ATTACK));

    aiThink->movesetIndex = 0;
}

// AI Score Functions
// AI_FLAG_CHECK_BAD_MOVE - decreases move scores
static s32 AI_CheckBadMove(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    // move data
    s8 atkPriority = GetMovePriority(battlerAtk, move);
    u32 moveEffect = gMovesInfo[move].effect;
    s32 moveType;
    u32 moveTarget = gMovesInfo[move].target;
    struct AiLogicData *aiData = AI_DATA;
    u32 effectiveness = aiData->effectiveness[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex];
    bool32 isDoubleBattle = IsValidDoubleBattle(battlerAtk);
    u32 i;
    u32 weather;
    u32 predictedMove = aiData->predictedMoves[battlerDef];

    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        return score;

    SetTypeBeforeUsingMove(move, battlerAtk);
    GET_MOVE_TYPE(move, moveType);

    if (gMovesInfo[move].powderMove && !IsAffectedByPowder(battlerDef, aiData->abilities[battlerDef], aiData->holdEffects[battlerDef]))
        RETURN_SCORE_MINUS(10);

    if (IsSemiInvulnerable(battlerDef, move) && moveEffect != EFFECT_SEMI_INVULNERABLE && AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER)
        RETURN_SCORE_MINUS(10);

    if (IsTwoTurnNotSemiInvulnerableMove(battlerAtk, move) && CanTargetFaintAi(battlerDef, battlerAtk))
        RETURN_SCORE_MINUS(10);

    // check if negates type
    switch (effectiveness)
    {
    case AI_EFFECTIVENESS_x0:
        RETURN_SCORE_MINUS(20);
        break;
    case AI_EFFECTIVENESS_x0_125:
    case AI_EFFECTIVENESS_x0_25:
        switch (moveEffect)
        {
        case EFFECT_FIXED_DAMAGE_ARG:
        case EFFECT_LEVEL_DAMAGE:
        case EFFECT_PSYWAVE:
        case EFFECT_OHKO:
        case EFFECT_BIDE:
        case EFFECT_SUPER_FANG:
        case EFFECT_ENDEAVOR:
        case EFFECT_COUNTER:
        case EFFECT_MIRROR_COAT:
        case EFFECT_METAL_BURST:
            break;
        default:
            RETURN_SCORE_MINUS(10);
        }
        break;
    }

    // check non-user target
    if (!(moveTarget & MOVE_TARGET_USER))
    {
        // target ability checks
        if (!DoesBattlerIgnoreAbilityChecks(aiData->abilities[battlerAtk], move))
        {
            switch (aiData->abilities[battlerDef])
            {
            case ABILITY_MAGIC_GUARD:
                switch (moveEffect)
                {
                case EFFECT_POISON:
                case EFFECT_WILL_O_WISP:
                case EFFECT_TOXIC:
                case EFFECT_LEECH_SEED:
                    score -= 5;
                    break;
                case EFFECT_CURSE:
                    if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GHOST)) // Don't use Curse if you're a ghost type vs a Magic Guard user, they'll take no damage.
                        score -= 5;
                    break;
                }
                break;
            case ABILITY_WONDER_GUARD:
                if (effectiveness < AI_EFFECTIVENESS_x2)
                    return 0;
                break;
            case ABILITY_JUSTIFIED:
                if (moveType == TYPE_DARK && !IS_MOVE_STATUS(move))
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_RATTLED:
                if (!IS_MOVE_STATUS(move)
                  && (moveType == TYPE_DARK || moveType == TYPE_GHOST || moveType == TYPE_BUG))
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_MAGIC_BOUNCE:
                if (gMovesInfo[move].magicCoatAffected)
                    RETURN_SCORE_MINUS(20);
                break;
            case ABILITY_CLEAR_BODY:
            case ABILITY_WHITE_SMOKE:
                if (IsStatLoweringEffect(moveEffect))
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_HYPER_CUTTER:
                if ((moveEffect == EFFECT_ATTACK_DOWN ||  moveEffect == EFFECT_ATTACK_DOWN_2)
                  && move != MOVE_PLAY_NICE && move != MOVE_VENOM_DRENCH)
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_KEEN_EYE:
                if (moveEffect == EFFECT_ACCURACY_DOWN || moveEffect == EFFECT_ACCURACY_DOWN_2)
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_BIG_PECKS:
                if (moveEffect == EFFECT_DEFENSE_DOWN || moveEffect == EFFECT_DEFENSE_DOWN_2)
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_DEFIANT:
            case ABILITY_COMPETITIVE:
                if (IsStatLoweringEffect(moveEffect) && !IS_TARGETING_PARTNER(battlerAtk, battlerDef))
                    RETURN_SCORE_MINUS(8);
                break;
            case ABILITY_LEAF_GUARD:
                if ((AI_GetWeather(aiData) & B_WEATHER_SUN)
                  && IsNonVolatileStatusMoveEffect(moveEffect))
                    RETURN_SCORE_MINUS(10);
                break;
            } // def ability checks

            // target partner ability checks & not attacking partner
            if (isDoubleBattle)
            {
                switch (aiData->abilities[BATTLE_PARTNER(battlerDef)])
                {
                case ABILITY_LIGHTNING_ROD:
                    if (moveType == TYPE_ELECTRIC && !IsMoveRedirectionPrevented(move, aiData->abilities[battlerAtk]))
                        RETURN_SCORE_MINUS(20);
                    break;
                case ABILITY_STORM_DRAIN:
                    if (moveType == TYPE_WATER && !IsMoveRedirectionPrevented(move, aiData->abilities[battlerAtk]))
                        RETURN_SCORE_MINUS(20);
                    break;
                case ABILITY_MAGIC_BOUNCE:
                    if (gMovesInfo[move].magicCoatAffected && moveTarget & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY | MOVE_TARGET_OPPONENTS_FIELD))
                        RETURN_SCORE_MINUS(20);
                    break;
                }
            } // def partner ability checks
        } // ignore def ability check

        // terrain & effect checks
        if (AI_IsTerrainAffected(battlerDef, STATUS_FIELD_ELECTRIC_TERRAIN))
        {
            if (moveEffect == EFFECT_SLEEP || moveEffect == EFFECT_YAWN)
                RETURN_SCORE_MINUS(20);
        }

        if (AI_IsTerrainAffected(battlerDef, STATUS_FIELD_MISTY_TERRAIN))
        {
            if (IsNonVolatileStatusMoveEffect(moveEffect) || IsConfusionMoveEffect(moveEffect))
                RETURN_SCORE_MINUS(20);
        }

        if (AI_IsTerrainAffected(battlerAtk, STATUS_FIELD_PSYCHIC_TERRAIN) && atkPriority > 0)
        {
            RETURN_SCORE_MINUS(20);
        }
    } // end check MOVE_TARGET_USER

// the following checks apply to any target (including user)

    // heal block check
    if (gStatuses3[battlerAtk] & STATUS3_HEAL_BLOCK && IsHealBlockPreventingMove(battlerAtk, move))
        return 0; // Can't even select heal blocked move

    // check move effects
    switch (moveEffect)
    {
        case EFFECT_HIT: // only applies to Vital Throw
            if (gMovesInfo[move].priority < 0 && AI_STRIKES_FIRST(battlerAtk, battlerDef, move) && aiData->hpPercents[battlerAtk] < 40)
                score -= 2;    // don't want to move last
            break;
        default:
            break;  // check move damage
        case EFFECT_SLEEP:
            if (!AI_CanPutToSleep(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_EXPLOSION:
            if (!(AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_WILL_SUICIDE))
                score -= 2;

            if (effectiveness == AI_EFFECTIVENESS_x0)
            {
                score -= 10;
            }
            else if (IsAbilityOnField(ABILITY_DAMP) && !DoesBattlerIgnoreAbilityChecks(aiData->abilities[battlerAtk], move))
            {
                score -= 10;
            }
            else if (CountUsablePartyMons(battlerAtk) == 0)
            {
                if (CountUsablePartyMons(battlerDef) != 0)
                    score -= 10;
                else
                    score -= 1;
            }
            break;
    // stat raising effects
        case EFFECT_ATTACK_UP:
        case EFFECT_ATTACK_UP_2:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ATK) || !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
                score -= 10;
            break;
        case EFFECT_DEFENSE_UP:
        case EFFECT_DEFENSE_UP_2:
        case EFFECT_DEFENSE_CURL:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_DEF))
                score -= 10;
            break;
        case EFFECT_SPECIAL_ATTACK_UP:
        case EFFECT_SPECIAL_ATTACK_UP_2:
        case EFFECT_SPECIAL_ATTACK_UP_3:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPATK) || !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_SPECIAL))
                score -= 10;
            break;
        case EFFECT_SPECIAL_DEFENSE_UP:
        case EFFECT_SPECIAL_DEFENSE_UP_2:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPDEF))
                score -= 10;
            break;
        case EFFECT_ACCURACY_UP:
        case EFFECT_ACCURACY_UP_2:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ACC))
                score -= 10;
            break;
        case EFFECT_EVASION_UP:
        case EFFECT_EVASION_UP_2:
        case EFFECT_MINIMISE:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_EVASION))
                score -= 10;
            break;
        case EFFECT_COSMIC_POWER:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_DEF))
                score -= 10;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPDEF))
                score -= 8;
            break;
        case EFFECT_BULK_UP:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ATK) || !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
                score -= 10;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_DEF))
                score -= 8;
            break;
        case EFFECT_CALM_MIND:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPATK))
                score -= 10;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPDEF))
                score -= 8;
            break;
        case EFFECT_DRAGON_DANCE:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ATK) || !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
                score -= 10;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPEED))
                score -= 8;
            break;
        case EFFECT_COIL:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ACC))
                score -= 10;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ATK) || !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
                score -= 8;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_DEF))
                score -= 6;
            break;
        case EFFECT_ATTACK_ACCURACY_UP: //hone claws
            if (gBattleMons[battlerAtk].statStages[STAT_ATK] >= MAX_STAT_STAGE
                && (gBattleMons[battlerAtk].statStages[STAT_ACC] >= MAX_STAT_STAGE || !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL)))
                score -= 10;
            break;
        case EFFECT_CHARGE:
            if (gStatuses3[battlerAtk] & STATUS3_CHARGED_UP)
                score -= 20;
            else if (!HasMoveWithType(battlerAtk, TYPE_ELECTRIC))
                score -= 10;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPDEF))
                score -= 5;
            break;
        case EFFECT_QUIVER_DANCE:
            if (gBattleMons[battlerAtk].statStages[STAT_SPATK] >= MAX_STAT_STAGE || !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_SPECIAL))
                score -= 10;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPEED))
                score -= 8;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPDEF))
                score -= 6;
            break;
        case EFFECT_SHELL_SMASH:
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ATK) || !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
                score -= 10;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPATK) || !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_SPECIAL))
                score -= 8;
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPEED))
                score -= 6;
            break;
        case EFFECT_GROWTH:
        case EFFECT_ATTACK_SPATK_UP:    // work up
            if ((!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ATK) && !BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPATK))
             || (!HasDamagingMove(battlerAtk)))
                score -= 10;
            break;
        case EFFECT_ROTOTILLER:
            if (isDoubleBattle)
            {
                if (!(IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GRASS)
                  && AI_IsBattlerGrounded(battlerAtk)
                  && (BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ATK) || BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPATK)))
                  && !(IS_BATTLER_OF_TYPE(BATTLE_PARTNER(battlerAtk), TYPE_GRASS)
                  && AI_IsBattlerGrounded(BATTLE_PARTNER(battlerAtk))
                  && (BattlerStatCanRise(BATTLE_PARTNER(battlerAtk), aiData->abilities[BATTLE_PARTNER(battlerAtk)], STAT_ATK)
                   || BattlerStatCanRise(BATTLE_PARTNER(battlerAtk), aiData->abilities[BATTLE_PARTNER(battlerAtk)], STAT_SPATK))))
                {
                    score -= 10;
                }
            }
            else if (!(IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GRASS)
              && AI_IsBattlerGrounded(battlerAtk)
              && (BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ATK) || BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPATK))))
            {
                score -= 10;
            }
            break;
        case EFFECT_ACUPRESSURE:
            if (DoesSubstituteBlockMove(battlerAtk, battlerDef, move) || AreBattlersStatsMaxed(battlerDef))
                score -= 10;
            break;
        case EFFECT_MAGNETIC_FLUX:
            if (aiData->abilities[battlerAtk] == ABILITY_PLUS || aiData->abilities[battlerAtk] == ABILITY_MINUS)
            {
                if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_DEF))
                    score -= 10;
                else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPDEF))
                    score -= 8;
            }
            else if (!isDoubleBattle)
            {
                score -= 10;    // our stats wont rise from this move
            }

            if (isDoubleBattle)
            {
                if (aiData->abilities[BATTLE_PARTNER(battlerAtk)] == ABILITY_PLUS || aiData->abilities[BATTLE_PARTNER(battlerAtk)] == ABILITY_MINUS)
                {
                    if (!BattlerStatCanRise(BATTLE_PARTNER(battlerAtk), aiData->abilities[BATTLE_PARTNER(battlerAtk)], STAT_DEF))
                        score -= 10;
                    else if (!BattlerStatCanRise(BATTLE_PARTNER(battlerAtk), aiData->abilities[BATTLE_PARTNER(battlerAtk)], STAT_SPDEF))
                        score -= 8;
                }
                else if (aiData->abilities[battlerAtk] != ABILITY_PLUS && aiData->abilities[battlerAtk] != ABILITY_MINUS)
                {
                    score -= 10;    // nor our or our partner's ability is plus/minus
                }
            }
            break;
    // stat lowering effects
        case EFFECT_ATTACK_DOWN:
        case EFFECT_ATTACK_DOWN_2:
            if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_ATK)) //|| !HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL))
                score -= 10;
            else if (aiData->abilities[battlerDef] == ABILITY_HYPER_CUTTER)
                score -= 10;
            break;
        case EFFECT_DEFENSE_DOWN:
        case EFFECT_DEFENSE_DOWN_2:
            if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_DEF))
                score -= 10;
            break;
        case EFFECT_SPEED_DOWN:
        case EFFECT_SPEED_DOWN_2:
            if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_SPEED))
                score -= 10;
            else if (aiData->abilities[battlerDef] == ABILITY_SPEED_BOOST)
                score -= 10;
            break;
        case EFFECT_SPECIAL_ATTACK_DOWN:
        case EFFECT_SPECIAL_ATTACK_DOWN_2:
            if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_SPATK)) //|| !HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL))
                score -= 10;
            break;
        case EFFECT_SPECIAL_DEFENSE_DOWN:
        case EFFECT_SPECIAL_DEFENSE_DOWN_2:
            if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_SPDEF))
                score -= 10;
            break;
        case EFFECT_ACCURACY_DOWN:
        case EFFECT_ACCURACY_DOWN_2:
            if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_ACC))
                score -= 10;
            else if (aiData->abilities[battlerDef] == ABILITY_KEEN_EYE)
                score -= 8;
            break;
        case EFFECT_EVASION_DOWN:
        case EFFECT_EVASION_DOWN_2:
            if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_EVASION))
                score -= 10;
            break;
        case EFFECT_TICKLE:
            if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_ATK))
                score -= 10;
            else if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_DEF))
                score -= 8;
            break;
        case EFFECT_VENOM_DRENCH:
            if (!(gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY))
            {
                score -= 10;
            }
            else
            {
                if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_SPEED))
                    score -= 10;
                else if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_SPATK))
                    score -= 8;
                else if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_ATK))
                    score -= 6;
            }
            break;
        case EFFECT_CAPTIVATE:
            if (!AreBattlersOfOppositeGender(battlerAtk, battlerDef))
                score -= 10;
            break;
    // other
        case EFFECT_HAZE:
            if (PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
            {
                score -= 10;    // partner already using haze
            }
            else
            {
                for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerAtk].statStages[i] > DEFAULT_STAT_STAGE || gBattleMons[BATTLE_PARTNER(battlerAtk)].statStages[i] > DEFAULT_STAT_STAGE)
                        score -= 10;  // Don't want to reset our boosted stats
                }
                for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerDef].statStages[i] < DEFAULT_STAT_STAGE || gBattleMons[BATTLE_PARTNER(battlerDef)].statStages[i] < DEFAULT_STAT_STAGE)
                        score -= 10; //Don't want to reset enemy lowered stats
                }
            }
            break;
        case EFFECT_PRESENT:
        case EFFECT_FIXED_DAMAGE_ARG:
        case EFFECT_FOCUS_PUNCH:
            // AI_CBM_HighRiskForDamage
            if (aiData->abilities[battlerDef] == ABILITY_WONDER_GUARD && effectiveness < AI_EFFECTIVENESS_x2)
                score -= 10;
            break;
        case EFFECT_COUNTER:
        case EFFECT_MIRROR_COAT:
            if (IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef]) || gBattleMons[battlerDef].status2 & (STATUS2_INFATUATION | STATUS2_CONFUSION))
                score -= 1;
            if (predictedMove == MOVE_NONE || gMovesInfo[predictedMove].category == DAMAGE_CATEGORY_STATUS
              || DoesSubstituteBlockMove(battlerAtk, BATTLE_PARTNER(battlerDef), predictedMove))
                score -= 10;
            break;

        case EFFECT_ROAR:
            if (CountUsablePartyMons(battlerDef) == 0)
                score -= 10;
            else if (aiData->abilities[battlerDef] == ABILITY_SUCTION_CUPS)
                score -= 10;
            break;
        case EFFECT_POISON:
        case EFFECT_TOXIC:
            if (!AI_CanPoison(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_LIGHT_SCREEN:
            if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_LIGHTSCREEN
              || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_REFLECT:
            if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_REFLECT
              || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_AURORA_VEIL:
            if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_AURORA_VEIL
              || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove)
              || !(weather & B_WEATHER_HAIL))
                score -= 10;
            break;
        case EFFECT_OHKO:
            if (move == MOVE_SHEER_COLD && IS_BATTLER_OF_TYPE(battlerDef, TYPE_ICE))
                return 0;
            if (!ShouldTryOHKO(battlerAtk, battlerDef, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], move))
                score -= 10;
            break;
        case EFFECT_MIST:
            if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_MIST
              || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_FOCUS_ENERGY:
            if (gBattleMons[battlerAtk].status2 & STATUS2_FOCUS_ENERGY)
                score -= 10;
            break;
        case EFFECT_CONFUSE:
        case EFFECT_SWAGGER:
        case EFFECT_FLATTER:
            if (!AI_CanConfuse(battlerAtk, battlerDef, aiData->abilities[battlerDef], BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_PARALYZE:
            if (!AI_CanParalyze(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_SUBSTITUTE:
            if (gBattleMons[battlerAtk].status2 & STATUS2_SUBSTITUTE || aiData->abilities[battlerDef] == ABILITY_INFILTRATOR)
                score -= 8;
            else if (aiData->hpPercents[battlerAtk] <= 25)
                score -= 10;
            else if (HasSubstituteIgnoringMove(battlerDef))
                score -= 8;
            break;
        case EFFECT_LEECH_SEED:
            if (gStatuses3[battlerDef] & STATUS3_LEECHSEED
             || IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS)
             || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            else if (aiData->abilities[battlerDef] == ABILITY_LIQUID_OOZE)
                score -= 3;
            break;
        case EFFECT_DISABLE:
            if (gDisableStructs[battlerDef].disableTimer == 0
                && aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB
                && !PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
            {
                if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER) // Attacker should go first
                {
                    if (gLastMoves[battlerDef] == MOVE_NONE || gLastMoves[battlerDef] == 0xFFFF)
                        score -= 10;    // no anticipated move to disable
                }
                else if (predictedMove == MOVE_NONE)
                {
                    score -= 10;
                }
            }
            else
            {
                score -= 10;
            }
            break;
        case EFFECT_ENCORE:
            if (gDisableStructs[battlerDef].encoreTimer == 0
                && aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB
                && !DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
            {
                if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER) // Attacker should go first
                {
                    if (gLastMoves[battlerDef] == MOVE_NONE || gLastMoves[battlerDef] == 0xFFFF)
                        score -= 10;    // no anticipated move to encore
                }
                else if (predictedMove == MOVE_NONE)
                {
                    score -= 10;
                }
            }
            else
            {
                score -= 10;
            }
            break;
        case EFFECT_SNORE:
        case EFFECT_SLEEP_TALK:
            if (IsWakeupTurn(battlerAtk) || !AI_IsBattlerAsleepOrComatose(battlerAtk))
                score -= 10;    // if mon will wake up, is not asleep, or is not comatose
            break;
        case EFFECT_MEAN_LOOK:
            if (IsBattlerTrapped(battlerDef, TRUE) || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_NIGHTMARE:
            if (gBattleMons[battlerDef].status2 & STATUS2_NIGHTMARE)
                score -= 10;
            else if (!AI_IsBattlerAsleepOrComatose(battlerDef))
                score -= 8;
            else if (DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_CURSE:
            if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GHOST))
            {
                if (gBattleMons[battlerDef].status2 & STATUS2_CURSED
                  || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                    score -= 10;
                else if (aiData->hpPercents[battlerAtk] <= 50)
                    score -= 6;
            }
            else // regular curse
            {
                if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_ATK) || !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
                    score -= 10;
                else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_DEF))
                    score -= 8;
            }
            break;
        case EFFECT_SPIKES:
            if (gSideTimers[GetBattlerSide(battlerDef)].spikesAmount >= 3)
                score -= 10;
            else if (PartnerMoveIsSameNoTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove)
              && gSideTimers[GetBattlerSide(battlerDef)].spikesAmount == 2)
                score -= 10; // only one mon needs to set up the last layer of Spikes
            break;
        case EFFECT_STEALTH_ROCK:
            if (gSideTimers[GetBattlerSide(battlerDef)].stealthRockAmount > 0
              || PartnerMoveIsSameNoTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove)) //Only one mon needs to set up Stealth Rocks
                score -= 10;
            break;
        case EFFECT_TOXIC_SPIKES:
            if (gSideTimers[GetBattlerSide(battlerDef)].toxicSpikesAmount >= 2)
                score -= 10;
            else if (PartnerMoveIsSameNoTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove) && gSideTimers[GetBattlerSide(battlerDef)].toxicSpikesAmount == 1)
                score -= 10; // only one mon needs to set up the last layer of Toxic Spikes
            break;
        case EFFECT_FORESIGHT:
            if (gBattleMons[battlerDef].status2 & STATUS2_FORESIGHT)
                score -= 10;
            else if (gBattleMons[battlerDef].statStages[STAT_EVASION] <= 4
              || !(IS_BATTLER_OF_TYPE(battlerDef, TYPE_GHOST))
              || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 9;
            break;
        case EFFECT_PERISH_SONG:
            if (isDoubleBattle)
            {
                if (CountUsablePartyMons(battlerAtk) == 0
                  && aiData->abilities[battlerAtk] != ABILITY_SOUNDPROOF
                  && aiData->abilities[BATTLE_PARTNER(battlerAtk)] != ABILITY_SOUNDPROOF
                  && CountUsablePartyMons(FOE(battlerAtk)) >= 1)
                {
                    score -= 10; //Don't wipe your team if you're going to lose
                }
                else if ((!IsBattlerAlive(FOE(battlerAtk)) || aiData->abilities[FOE(battlerAtk)] == ABILITY_SOUNDPROOF
                  || gStatuses3[FOE(battlerAtk)] & STATUS3_PERISH_SONG)
                  && (!IsBattlerAlive(BATTLE_PARTNER(FOE(battlerAtk))) || aiData->abilities[BATTLE_PARTNER(FOE(battlerAtk))] == ABILITY_SOUNDPROOF
                  || gStatuses3[BATTLE_PARTNER(FOE(battlerAtk))] & STATUS3_PERISH_SONG))
                {
                    score -= 10; //Both enemies are perish songed
                }
                else if (DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                {
                    score -= 10;
                }
            }
            else
            {
                if (CountUsablePartyMons(battlerAtk) == 0 && aiData->abilities[battlerAtk] != ABILITY_SOUNDPROOF
                  && CountUsablePartyMons(battlerDef) >= 1)
                    score -= 10;

                if (gStatuses3[FOE(battlerAtk)] & STATUS3_PERISH_SONG || aiData->abilities[FOE(battlerAtk)] == ABILITY_SOUNDPROOF)
                    score -= 10;
            }
            break;
        case EFFECT_SANDSTORM:
            if (weather & B_WEATHER_SANDSTORM
             || IsMoveEffectWeather(aiData->partnerMove))
                score -= 8;
            break;
        case EFFECT_SUNNY_DAY:
            if (weather & B_WEATHER_SUN
             || IsMoveEffectWeather(aiData->partnerMove))
                score -= 8;
            break;
        case EFFECT_RAIN_DANCE:
            if (weather & B_WEATHER_RAIN
             || IsMoveEffectWeather(aiData->partnerMove))
                score -= 8;
            break;
        case EFFECT_HAIL:
            if (weather & B_WEATHER_HAIL
             || IsMoveEffectWeather(aiData->partnerMove))
                score -= 8;
            break;
        case EFFECT_ATTRACT:
            if (!AI_CanBeInfatuated(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
                score -= 10;
            break;
        case EFFECT_SAFEGUARD:
            if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_SAFEGUARD
              || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_MAGNITUDE:
            if (aiData->abilities[battlerDef] == ABILITY_LEVITATE)
                score -= 10;
            break;
        case EFFECT_BATON_PASS:
            if (CountUsablePartyMons(battlerAtk) == 0)
                score -= 10;
            else if (gBattleMons[battlerAtk].status2 & STATUS2_SUBSTITUTE
              || (gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_AQUA_RING | STATUS3_MAGNET_RISE | STATUS3_POWER_TRICK))
              || AnyStatIsRaised(battlerAtk))
                break;
            else
                score -= 6;
            break;
        case EFFECT_HIT_ESCAPE:
            break;
        case EFFECT_BELLY_DRUM:
            if (aiData->hpPercents[battlerAtk] <= 60)
                score -= 10;
            break;
        case EFFECT_FUTURE_SIGHT:
            if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_FUTUREATTACK
              || gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_FUTUREATTACK)
                score -= 12;
            else
                score += GOOD_EFFECT;
            break;
        case EFFECT_TELEPORT:
            score -= 10;
            break;
        case EFFECT_FIRST_TURN_ONLY:
            if (!gDisableStructs[battlerAtk].isFirstTurn)
                score -= 10;
            break;
        case EFFECT_STOCKPILE:
            if (gDisableStructs[battlerAtk].stockpileCounter >= 3)
                score -= 10;
            break;
        case EFFECT_SWALLOW:
            if (gDisableStructs[battlerAtk].stockpileCounter == 0)
            {
                score -= 10;
            }
            else
            {
                if (AtMaxHp(battlerAtk))
                    score -= 10;
                else if (aiData->hpPercents[battlerAtk] >= 80)
                    score -= 5; // do it if nothing better
            }
            break;
        case EFFECT_TORMENT:
            if (gBattleMons[battlerDef].status2 & STATUS2_TORMENT
              || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
            {
                score -= 10;
                break;
            }
            if (aiData->holdEffects[battlerDef] == HOLD_EFFECT_MENTAL_HERB)
                score -= 6;
            break;
        case EFFECT_WILL_O_WISP:
            if (!AI_CanBurn(battlerAtk, battlerDef, aiData->abilities[battlerDef], BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_MEMENTO:
            if (CountUsablePartyMons(battlerAtk) == 0 || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            else if (gBattleMons[battlerDef].statStages[STAT_ATK] == MIN_STAT_STAGE && gBattleMons[battlerDef].statStages[STAT_SPATK] == MIN_STAT_STAGE)
                score -= 10;
            break;
        case EFFECT_FOLLOW_ME:
        case EFFECT_HELPING_HAND:
            if (!isDoubleBattle
              || !IsBattlerAlive(BATTLE_PARTNER(battlerAtk))
              || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove)
              || (aiData->partnerMove != MOVE_NONE && IS_MOVE_STATUS(aiData->partnerMove))
              || *(gBattleStruct->monToSwitchIntoId + BATTLE_PARTNER(battlerAtk)) != PARTY_SIZE) //Partner is switching out.
                score -= 10;
            break;
        case EFFECT_TRICK:
        case EFFECT_KNOCK_OFF:
            if (aiData->abilities[battlerDef] == ABILITY_STICKY_HOLD)
                score -= 10;
            break;
        case EFFECT_INGRAIN:
            if (gStatuses3[battlerAtk] & STATUS3_ROOTED)
                score -= 10;
            break;
        case EFFECT_AQUA_RING:
            if (gStatuses3[battlerAtk] & STATUS3_AQUA_RING)
                score -= 10;
            break;
        case EFFECT_RECYCLE:
            if (GetUsedHeldItem(battlerAtk) == 0 || gBattleMons[battlerAtk].item != 0)
                score -= 10;
            break;
        case EFFECT_IMPRISON:
            if (gStatuses3[battlerAtk] & STATUS3_IMPRISONED_OTHERS)
                score -= 10;
            break;
        case EFFECT_REFRESH:
            if (!(gBattleMons[battlerDef].status1 & (STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS)))
                score -= 10;
            break;
        case EFFECT_PSYCHO_SHIFT:
            if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY && !AI_CanPoison(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
                score -= 10;
            else if (gBattleMons[battlerAtk].status1 & STATUS1_BURN && !AI_CanBurn(battlerAtk, battlerDef,
              aiData->abilities[battlerDef], BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            else if (gBattleMons[battlerAtk].status1 & STATUS1_PARALYSIS && !AI_CanParalyze(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
                score -= 10;
            else if (gBattleMons[battlerAtk].status1 & STATUS1_SLEEP && !AI_CanPutToSleep(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
                score -= 10;
            else
                score -= 10;    // attacker has no status to transmit
            break;
        case EFFECT_MUD_SPORT:
            if (gFieldStatuses & STATUS_FIELD_MUDSPORT
              || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_WATER_SPORT:
            if (gFieldStatuses & STATUS_FIELD_WATERSPORT
              || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_ABSORB:
            if (aiData->abilities[battlerDef] == ABILITY_LIQUID_OOZE)
                score -= 6;
            break;
        case EFFECT_STRENGTH_SAP:
            if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], STAT_ATK))
                score -= 10;
            break;
        case EFFECT_COPYCAT:
        case EFFECT_MIRROR_MOVE:
            return AI_CheckBadMove(battlerAtk, battlerDef, predictedMove, score);
        case EFFECT_BIDE:
            if (!HasDamagingMove(battlerDef)
              || aiData->hpPercents[battlerAtk] < 30 //Close to death
              || gBattleMons[battlerDef].status1 & (STATUS1_SLEEP | STATUS1_FREEZE)) //No point in biding if can't take damage
                score -= 10;
            break;
        case EFFECT_HIT_SWITCH_TARGET:
            if (DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10; // don't scare away pokemon twice
            else if (aiData->hpPercents[battlerDef] < 10 && GetBattlerSecondaryDamage(battlerDef))
                score -= 10;    // don't blow away mon that will faint soon
            else if (gStatuses3[battlerDef] & STATUS3_PERISH_SONG)
                score -= 10;
            break;
        case EFFECT_CONVERSION:
            //Check first move type
            if (IS_BATTLER_OF_TYPE(battlerAtk, gMovesInfo[gBattleMons[battlerAtk].moves[0]].type))
                score -= 10;
            break;
        case EFFECT_REST:
            if (!AI_CanSleep(battlerAtk, aiData->abilities[battlerAtk]))
                score -= 10;
            //fallthrough
        case EFFECT_RESTORE_HP:
        case EFFECT_SOFTBOILED:
        case EFFECT_ROOST:
            if (AtMaxHp(battlerAtk))
                score -= 10;
            else if (aiData->hpPercents[battlerAtk] >= 90)
                score -= 9; //No point in healing, but should at least do it if nothing better
            break;
        case EFFECT_MORNING_SUN:
        case EFFECT_SYNTHESIS:
        case EFFECT_MOONLIGHT:
            if ((AI_GetWeather(aiData) & (B_WEATHER_RAIN | B_WEATHER_SANDSTORM | B_WEATHER_HAIL)))
                score -= 3;
            else if (AtMaxHp(battlerAtk))
                score -= 10;
            else if (aiData->hpPercents[battlerAtk] >= 90)
                score -= 9; //No point in healing, but should at least do it if nothing better
            break;
        case EFFECT_RECOIL_IF_MISS:
            if (aiData->abilities[battlerAtk] != ABILITY_MAGIC_GUARD && AI_DATA->moveAccuracy[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex] < 75)
                score -= 6;
            break;
        case EFFECT_TRANSFORM:
            if (gBattleMons[battlerAtk].status2 & STATUS2_TRANSFORMED
              || (gBattleMons[battlerDef].status2 & (STATUS2_TRANSFORMED | STATUS2_SUBSTITUTE))) //Leave out Illusion b/c AI is supposed to be fooled
                score -= 10;
            break;
        case EFFECT_SPITE:
        case EFFECT_MIMIC:
            if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER) // Attacker should go first
            {
                if (gLastMoves[battlerDef] == MOVE_NONE
                  || gLastMoves[battlerDef] == 0xFFFF)
                    score -= 10;
            }
            else if (predictedMove == MOVE_NONE)
            {
                // TODO predicted move separate from gLastMoves
                score -= 10;
            }
            break;
        case EFFECT_METRONOME:
            break;

        case EFFECT_CONVERSION_2:
            //TODO
            break;
        case EFFECT_LOCK_ON:
            if (gStatuses3[battlerDef] & STATUS3_ALWAYS_HITS
              || aiData->abilities[battlerAtk] == ABILITY_NO_GUARD
              || aiData->abilities[battlerDef] == ABILITY_NO_GUARD
              || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_LASER_FOCUS:
            if (gStatuses3[battlerAtk] & STATUS3_LASER_FOCUS)
                score -= 10;
            else if (aiData->abilities[battlerDef] == ABILITY_SHELL_ARMOR || aiData->abilities[battlerDef] == ABILITY_BATTLE_ARMOR)
                score -= 8;
            break;
        case EFFECT_SKETCH:
            if (gLastMoves[battlerDef] == MOVE_NONE)
                score -= 10;
            break;
        case EFFECT_DESTINY_BOND:
            if (gBattleMons[battlerDef].status2 & STATUS2_DESTINY_BOND)
                score -= 10;
            break;
        case EFFECT_HEAL_BELL:
            if (!AnyPartyMemberStatused(battlerAtk, gMovesInfo[move].soundMove) || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_ENDURE:
            if (gBattleMons[battlerAtk].hp == 1 || GetBattlerSecondaryDamage(battlerAtk)) //Don't use Endure if you'll die after using it
                score -= 10;
            break;
        case EFFECT_PROTECT:
            {
                bool32 decreased = FALSE;
                switch (move)
                {
                case MOVE_QUICK_GUARD:
                case MOVE_WIDE_GUARD:
                    if (!isDoubleBattle)
                    {
                        score -= 10;
                        decreased = TRUE;
                    }
                    break;
                } // move check

                if (decreased)
                    break;
                if (IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef]))
                {
                    score -= 10;
                    break;
                }

                if (move != MOVE_QUICK_GUARD
                  && move != MOVE_WIDE_GUARD) //These moves have infinite usage
                {
                    if (GetBattlerSecondaryDamage(battlerAtk) >= gBattleMons[battlerAtk].hp
                      && aiData->abilities[battlerDef] != ABILITY_MOXIE)
                    {
                        score -= 10; //Don't protect if you're going to faint after protecting
                    }
                    else if (gDisableStructs[battlerAtk].protectUses == 1 && Random() % 100 < 50)
                    {
                        if (!isDoubleBattle)
                            score -= 6;
                        else
                            score -= 10; //Don't try double protecting in doubles
                    }
                    else if (gDisableStructs[battlerAtk].protectUses >= 2)
                    {
                        score -= 10;
                    }
                }

                /*if (AI_THINKING_STRUCT->aiFlags[battlerAtk] == AI_SCRIPT_CHECK_BAD_MOVE //Only basic AI
                && IS_DOUBLE_BATTLE) //Make the regular AI know how to use Protect minimally in Doubles
                {
                    u8 shouldProtect = ShouldProtect(battlerAtk, battlerDef, move);
                    if (shouldProtect == USE_PROTECT || shouldProtect == PROTECT_FROM_FOES)
                        IncreaseFoeProtectionViability(&viability, 0xFF, battlerAtk, battlerDef);
                    else if (shouldProtect == PROTECT_FROM_ALLIES)
                        IncreaseAllyProtectionViability(&viability, 0xFF);
                }*/
            }
            break;
        case EFFECT_MIRACLE_EYE:
            if (gStatuses3[battlerDef] & STATUS3_MIRACLE_EYED)
                score -= 10;

            if (gBattleMons[battlerDef].statStages[STAT_EVASION] <= 4
              || !(IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK))
              || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 9;
            break;
        case EFFECT_DEFOG:
            if (gSideStatuses[GetBattlerSide(battlerDef)]
             & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL | SIDE_STATUS_SAFEGUARD | SIDE_STATUS_MIST)
              || gSideTimers[GetBattlerSide(battlerDef)].auroraVeilTimer != 0
              || gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_HAZARDS_ANY)
            {
                if (PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                {
                    score -= 10; //Only need one hazards removal
                    break;
                }
            }

            if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_HAZARDS_ANY)
            {
                score -= 10; //Don't blow away opposing hazards
                break;
            }

            if (isDoubleBattle)
            {
                if (IsHazardMoveEffect(gMovesInfo[aiData->partnerMove].effect) // partner is going to set up hazards
                  && AI_WhoStrikesFirst(BATTLE_PARTNER(battlerAtk), battlerAtk, aiData->partnerMove) == AI_IS_FASTER) // partner is going to set up before the potential Defog
                {
                    score -= 10;
                    break; // Don't use Defog if partner is going to set up hazards
                }
            }

            // evasion check
            if (gBattleMons[battlerDef].statStages[STAT_EVASION] == MIN_STAT_STAGE) // don't want to raise target stats unless its your partner
                score -= 10;
            break;
        case EFFECT_PSYCH_UP:   // haze stats check
            {
                for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerAtk].statStages[i] > DEFAULT_STAT_STAGE || gBattleMons[BATTLE_PARTNER(battlerAtk)].statStages[i] > DEFAULT_STAT_STAGE)
                        score -= 10;  // Don't want to reset our boosted stats
                }
                for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerDef].statStages[i] < DEFAULT_STAT_STAGE || gBattleMons[BATTLE_PARTNER(battlerDef)].statStages[i] < DEFAULT_STAT_STAGE)
                        score -= 10; //Don't want to copy enemy lowered stats
                }
            }
            break;
        case EFFECT_SEMI_INVULNERABLE:
            if (predictedMove != MOVE_NONE
              && AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_SLOWER
              && gMovesInfo[predictedMove].effect == EFFECT_SEMI_INVULNERABLE)
                score -= 10; // Don't Fly/dig/etc if opponent is going to fly/dig/etc after you

            if (BattlerWillFaintFromWeather(battlerAtk, aiData->abilities[battlerAtk])
              && (move == MOVE_FLY || move == MOVE_BOUNCE))
                score -= 10; // Attacker will faint while in the air
            break;
        case EFFECT_HEALING_WISH:   //healing wish, lunar dance
            if (CountUsablePartyMons(battlerAtk) == 0 || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            else if (IsPartyFullyHealedExceptBattler(battlerAtk))
                score -= 10;
            break;
        case EFFECT_FINAL_GAMBIT:
            if (CountUsablePartyMons(battlerAtk) == 0 || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_NATURE_POWER:
            return AI_CheckBadMove(battlerAtk, battlerDef, GetNaturePowerMove(), score);
        case EFFECT_TAUNT:
            if (gDisableStructs[battlerDef].tauntTimer > 0
              || DoesPartnerHaveSameMoveEffect(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_BESTOW:
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_NONE
              || !CanBattlerGetOrLoseItem(battlerAtk, gBattleMons[battlerAtk].item))    // AI knows its own item
                score -= 10;
            break;
        case EFFECT_ROLE_PLAY:
            if (aiData->abilities[battlerAtk] == aiData->abilities[battlerDef]
              || aiData->abilities[battlerDef] == ABILITY_NONE
              || gAbilitiesInfo[aiData->abilities[battlerDef]].cantBeCopied)
                score -= 10;
            else if (IsAbilityOfRating(aiData->abilities[battlerAtk], 5))
                score -= 4;
            break;
        case EFFECT_WISH:
            if (gWishFutureKnock.wishCounter[battlerAtk] != 0)
                score -= 10;
            break;
        case EFFECT_ASSIST:
            if (CountUsablePartyMons(battlerAtk) == 0)
                score -= 10;    // no teammates to assist from
            break;
        case EFFECT_MAGIC_COAT:
            if (!HasMagicCoatAffectedMove(battlerDef))
                score -= 10;
            break;
        case EFFECT_YAWN:
            if (gStatuses3[battlerDef] & STATUS3_YAWN)
                score -= 10;
            else if (!AI_CanPutToSleep(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_SKILL_SWAP:
            if (aiData->abilities[battlerAtk] == ABILITY_NONE || aiData->abilities[battlerDef] == ABILITY_NONE
              || gAbilitiesInfo[aiData->abilities[battlerAtk]].cantBeSwapped
              || gAbilitiesInfo[aiData->abilities[battlerDef]].cantBeSwapped)
                score -= 10;
            break;
        case EFFECT_WORRY_SEED:
            if (aiData->abilities[battlerDef] == ABILITY_INSOMNIA
              || gAbilitiesInfo[aiData->abilities[battlerDef]].cantBeOverwritten)
                score -= 10;
            break;
        case EFFECT_GASTRO_ACID:
            if (gStatuses3[battlerDef] & STATUS3_GASTRO_ACID)
                score -= 10;
            break;
        case EFFECT_ENTRAINMENT:
            if (aiData->abilities[battlerAtk] == ABILITY_NONE
              || gAbilitiesInfo[aiData->abilities[battlerAtk]].cantBeCopied
              || gAbilitiesInfo[aiData->abilities[battlerDef]].cantBeOverwritten)
                score -= 10;
            break;
        case EFFECT_SIMPLE_BEAM:
            if (aiData->abilities[battlerDef] == ABILITY_SIMPLE
              || gAbilitiesInfo[aiData->abilities[battlerDef]].cantBeOverwritten)
                score -= 10;
            break;
        case EFFECT_SNATCH:
            if (!HasSnatchAffectedMove(battlerDef)
              || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_POWER_TRICK:
            if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
                score -= 10;
            else if (gBattleMons[battlerAtk].defense >= gBattleMons[battlerAtk].attack && !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
                score -= 10;
            break;
        case EFFECT_POWER_SWAP: // Don't use if attacker's stat stages are higher than opponents
            if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
                score -= 10;
            else if (gBattleMons[battlerAtk].statStages[STAT_ATK] >= gBattleMons[battlerDef].statStages[STAT_ATK]
              && gBattleMons[battlerAtk].statStages[STAT_SPATK] >= gBattleMons[battlerDef].statStages[STAT_SPATK])
                score -= 10;
            break;
        case EFFECT_GUARD_SWAP: // Don't use if attacker's stat stages are higher than opponents
            if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
                score -= 10;
            else if (gBattleMons[battlerAtk].statStages[STAT_DEF] >= gBattleMons[battlerDef].statStages[STAT_DEF]
              && gBattleMons[battlerAtk].statStages[STAT_SPDEF] >= gBattleMons[battlerDef].statStages[STAT_SPDEF])
                score -= 10;
            break;
        case EFFECT_POWER_SPLIT:
            if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
            {
                score -= 10;
            }
            else
            {
                u32 atkAttack = gBattleMons[battlerAtk].attack;
                u32 defAttack = gBattleMons[battlerDef].attack;
                u32 atkSpAttack = gBattleMons[battlerAtk].spAttack;
                u32 defSpAttack = gBattleMons[battlerDef].spAttack;

                if (atkAttack + atkSpAttack >= defAttack + defSpAttack) // Combined attacker stats are > than combined target stats
                    score -= 10;
                break;
            }
            break;
        case EFFECT_GUARD_SPLIT:
            if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
            {
                score -= 10;
            }
            else
            {
                u32 atkDefense = gBattleMons[battlerAtk].defense;
                u32 defDefense = gBattleMons[battlerDef].defense;
                u32 atkSpDefense = gBattleMons[battlerAtk].spDefense;
                u32 defSpDefense = gBattleMons[battlerDef].spDefense;

                if (atkDefense + atkSpDefense >= defDefense + defSpDefense) //Combined attacker stats are > than combined target stats
                    score -= 10;
                break;
            }
            break;
        case EFFECT_ME_FIRST:
            if (predictedMove != MOVE_NONE)
            {
                if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_SLOWER)
                    score -= 10;    // Target is predicted to go first, Me First will fail
                else
                    return AI_CheckBadMove(battlerAtk, battlerDef, predictedMove, score);
            }
            else
            {
                score -= 10; //Target is predicted to switch most likely
            }
            break;
        case EFFECT_NATURAL_GIFT:
            if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM
              || GetPocketByItemId(gBattleMons[battlerAtk].item) != POCKET_BERRIES)
                score -= 10;
            break;
        case EFFECT_GRASSY_TERRAIN:
            if (PartnerMoveEffectIsTerrain(BATTLE_PARTNER(battlerAtk), aiData->partnerMove) || gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
                score -= 10;
            break;
        case EFFECT_ELECTRIC_TERRAIN:
            if (PartnerMoveEffectIsTerrain(BATTLE_PARTNER(battlerAtk), aiData->partnerMove) || gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
                score -= 10;
            break;
        case EFFECT_PSYCHIC_TERRAIN:
            if (PartnerMoveEffectIsTerrain(BATTLE_PARTNER(battlerAtk), aiData->partnerMove) || gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
                score -= 10;
            break;
        case EFFECT_MISTY_TERRAIN:
            if (PartnerMoveEffectIsTerrain(BATTLE_PARTNER(battlerAtk), aiData->partnerMove) || gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
                score -= 10;
            break;
        case EFFECT_TRICK_ROOM:
            if (PartnerMoveIs(BATTLE_PARTNER(battlerAtk), aiData->partnerMove, MOVE_TRICK_ROOM))
            {
                score -= 10;
            }
            else if (!(AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_POWERFUL_STATUS))
            {
                if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM) // Trick Room Up
                {
                    if (GetBattlerSideSpeedAverage(battlerAtk) < GetBattlerSideSpeedAverage(battlerDef)) // Attacker side slower than target side
                        score -= 10; // Keep the Trick Room up
                }
                else
                {
                    if (GetBattlerSideSpeedAverage(battlerAtk) >= GetBattlerSideSpeedAverage(battlerDef)) // Attacker side faster than target side
                        score -= 10; // Keep the Trick Room down
                }
            }
            break;
        case EFFECT_MAGIC_ROOM:
            if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM || PartnerMoveIsSameNoTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_WONDER_ROOM:
            if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM || PartnerMoveIsSameNoTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_GRAVITY:
            if ((gFieldStatuses & STATUS_FIELD_GRAVITY
              && !IS_BATTLER_OF_TYPE(battlerAtk, TYPE_FLYING)
              && aiData->holdEffects[battlerAtk] != HOLD_EFFECT_AIR_BALLOON) // Should revert Gravity in this case
              || PartnerMoveIsSameNoTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_ION_DELUGE:
            if (gFieldStatuses & STATUS_FIELD_ION_DELUGE
              || PartnerMoveIsSameNoTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_FLING:
            if (!CanFling(battlerAtk))
            {
                score -= 10;
            }
            else
            {
                /* TODO Fling
                u8 effect = gFlingTable[gBattleMons[battlerAtk].item].effect;
                switch (effect)
                {
                case MOVE_EFFECT_BURN:
                    if (!AI_CanBurn(battlerAtk, battlerDef, BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                        score -= 10;
                    break;
                case MOVE_EFFECT_PARALYSIS:
                    if (!AI_CanParalyze(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
                        score -= 10;
                    break;
                case MOVE_EFFECT_POISON:
                    if (!AI_CanPoison(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
                        score -= 10;
                    break;
                case MOVE_EFFECT_TOXIC:
                    if (!AI_CanPoison(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
                        score -= 10;
                    break;
                case MOVE_EFFECT_FREEZE:
                    if (!CanBeFrozen(battlerDef, TRUE)
                     || MoveBlockedBySubstitute(move, battlerAtk, battlerDef))
                        score -= 10;
                    break;
                }*/
            }
            break;
        case EFFECT_EMBARGO:
            if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM
              || gDisableStructs[battlerDef].embargoTimer != 0
              || PartnerMoveIsSameAsAttacker(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_TELEKINESIS:
            if (gStatuses3[battlerDef] & (STATUS3_TELEKINESIS | STATUS3_ROOTED | STATUS3_SMACKED_DOWN)
              || gFieldStatuses & STATUS_FIELD_GRAVITY
              || aiData->holdEffects[battlerDef] == HOLD_EFFECT_IRON_BALL
              || IsTelekinesisBannedSpecies(gBattleMons[battlerDef].species)
              || PartnerMoveIsSameAsAttacker(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_HEAL_BLOCK:
            if (gDisableStructs[battlerDef].healBlockTimer != 0
              || PartnerMoveIsSameAsAttacker(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_SOAK:
            if (PartnerMoveIsSameAsAttacker(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove)
              || (GetBattlerType(battlerDef, 0) == TYPE_WATER
              && GetBattlerType(battlerDef, 1) == TYPE_WATER
              && GetBattlerType(battlerDef, 2) == TYPE_MYSTERY))
                score -= 10;    // target is already water-only
            break;
        case EFFECT_HEAL_PULSE: // and floral healing
            if (!IS_TARGETING_PARTNER(battlerAtk, battlerDef)) // Don't heal enemies
            {
                score -= 10;
                break;
            }
            if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
            {
                if (gStatuses3[battlerDef] & STATUS3_HEAL_BLOCK)
                    return 0;
                if (AtMaxHp(battlerDef))
                    score -= 10;
                else if (gBattleMons[battlerDef].hp > gBattleMons[battlerDef].maxHP / 2)
                    score -= 5;
            }
            break;
        case EFFECT_DO_NOTHING:
            score -= 10;
            break;
        case EFFECT_QUASH:
            if (!isDoubleBattle
            || AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_SLOWER
            || PartnerMoveIsSameAsAttacker(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_AFTER_YOU:
            if (!IS_TARGETING_PARTNER(battlerAtk, battlerDef)
              || !isDoubleBattle
              || AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_SLOWER
              || PartnerMoveIsSameAsAttacker(BATTLE_PARTNER(battlerAtk), battlerDef, move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_SUCKER_PUNCH:
            if (predictedMove != MOVE_NONE)
            {
                if (IS_MOVE_STATUS(predictedMove) || AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_SLOWER) // Opponent going first
                    score -= 10;
            }
            break;
        case EFFECT_TAILWIND:
            if (gSideTimers[GetBattlerSide(battlerAtk)].tailwindTimer != 0
              || PartnerMoveIs(BATTLE_PARTNER(battlerAtk), aiData->partnerMove, MOVE_TAILWIND)
              || (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer > 1)) // Trick Room active and not ending this turn
                score -= 10;
            break;
        case EFFECT_LUCKY_CHANT:
            if (gSideTimers[GetBattlerSide(battlerAtk)].luckyChantTimer != 0
              || PartnerMoveIsSameNoTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
                score -= 10;
            break;
        case EFFECT_MAGNET_RISE:
            if (gFieldStatuses & STATUS_FIELD_GRAVITY
              ||  gDisableStructs[battlerAtk].magnetRiseTimer != 0
              || aiData->holdEffects[battlerAtk] == HOLD_EFFECT_IRON_BALL
              || gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_MAGNET_RISE | STATUS3_SMACKED_DOWN)
              || !IsBattlerGrounded(battlerAtk))
                score -= 10;
            break;
        case EFFECT_CAMOUFLAGE:
            if (!CanCamouflage(battlerAtk))
                score -= 10;
            break;
        case EFFECT_SYNCHRONOISE:
            //Check holding ring target or is of same type
            if (aiData->holdEffects[battlerDef] == HOLD_EFFECT_RING_TARGET
              || IS_BATTLER_OF_TYPE(battlerDef, GetBattlerType(battlerAtk, 0))
              || IS_BATTLER_OF_TYPE(battlerDef, GetBattlerType(battlerAtk, 1))
              || IS_BATTLER_OF_TYPE(battlerDef, GetBattlerType(battlerAtk, 2)))
                break;
            else
                score -= 10;
            break;
        case EFFECT_ERUPTION:
            if (effectiveness <= AI_EFFECTIVENESS_x0_5)
                score -= 1;
            if (aiData->hpPercents[battlerDef] < 50)
                score -= 1;
            break;
        case EFFECT_FLAIL:
            if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_SLOWER // Opponent should go first
              || aiData->hpPercents[battlerAtk] > 50)
                score -= 4;
            break;
        case EFFECT_SKY_DROP:
            if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_FLYING))
                score -= 10;
            if (BattlerWillFaintFromWeather(battlerAtk, aiData->abilities[battlerAtk])
            ||  DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
            ||  GetBattlerWeight(battlerDef) >= 2000) //200.0 kg
                score -= 10;
            break;
    } // move effect checks

    if (score < 0)
        score = 0;

    return score;
}

static s32 AI_TryToFaint(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u32 movesetIndex = AI_THINKING_STRUCT->movesetIndex;

    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        return score;

    if (gMovesInfo[move].power == 0)
        return score; // can't make anything faint with no power

    if (CanIndexMoveFaintTarget(battlerAtk, battlerDef, movesetIndex, 0) && gMovesInfo[move].effect != EFFECT_EXPLOSION)
    {
        if (AI_STRIKES_FIRST(battlerAtk, battlerDef, move))
            score += FAST_KILL;
        else
            score += SLOW_KILL;
    }
    else if (CanTargetFaintAi(battlerDef, battlerAtk)
            && GetWhichBattlerFaster(battlerAtk, battlerDef, TRUE) != AI_IS_FASTER
            && GetMovePriority(battlerAtk, move) > 0)
    {
        score += LAST_CHANCE;
    }

    return score;
}

// double battle logic
static s32 AI_DoubleBattle(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    // move data
    u32 moveType = gMovesInfo[move].type;
    u32 effect = gMovesInfo[move].effect;
    u32 moveTarget = gMovesInfo[move].target;
    // ally data
    u32 battlerAtkPartner = BATTLE_PARTNER(battlerAtk);
    struct AiLogicData *aiData = AI_DATA;
    u32 atkPartnerAbility = aiData->abilities[BATTLE_PARTNER(battlerAtk)];
    u32 atkPartnerHoldEffect = aiData->holdEffects[BATTLE_PARTNER(battlerAtk)];
    bool32 partnerProtecting = (gMovesInfo[aiData->partnerMove].effect == EFFECT_PROTECT);
    bool32 attackerHasBadAbility = (gAbilitiesInfo[aiData->abilities[battlerAtk]].aiRating < 0);
    bool32 partnerHasBadAbility = (gAbilitiesInfo[atkPartnerAbility].aiRating < 0);
    u32 predictedMove = aiData->predictedMoves[battlerDef];

    SetTypeBeforeUsingMove(move, battlerAtk);
    GET_MOVE_TYPE(move, moveType);

    // check what effect partner is using
    if (aiData->partnerMove != 0)
    {
        switch (gMovesInfo[aiData->partnerMove].effect)
        {
        case EFFECT_HELPING_HAND:
            if (IS_MOVE_STATUS(move))
                score -= 7;
            break;
        case EFFECT_PERISH_SONG:
            if (!(gBattleMons[battlerDef].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED)))
            {
                if (IsTrappingMove(aiData->partnerMove) || predictedMove == MOVE_INGRAIN)
                    score += WEAK_EFFECT;
            }
            break;
        // Don't change weather if ally already decided to do so.
        case EFFECT_SUNNY_DAY:
        case EFFECT_HAIL:
        case EFFECT_RAIN_DANCE:
        case EFFECT_SANDSTORM:
            if (IsMoveEffectWeather(move))
                score -= 10;
            break;
        }
    } // check partner move effect

    // Adjust for always crit moves
    if (gMovesInfo[aiData->partnerMove].alwaysCriticalHit && aiData->abilities[battlerAtk] == ABILITY_ANGER_POINT)
    {
        if (AI_WhoStrikesFirst(battlerAtk, battlerAtkPartner, move) == AI_IS_SLOWER)   // Partner moving first
        {
            // discourage raising our attack since it's about to be maxed out
            if (IsAttackBoostMoveEffect(effect))
                score -= 3;
            // encourage moves hitting multiple opponents
            if (!IS_MOVE_STATUS(move) && (moveTarget & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY)))
                score += GOOD_EFFECT;
        }
    }

    // consider our move effect relative to partner state
    switch (effect)
    {
    case EFFECT_HELPING_HAND:
        if (!IsBattlerAlive(battlerAtkPartner) || !HasDamagingMove(battlerAtkPartner))
            score -= 5;
        break;
    case EFFECT_PERISH_SONG:
        if (aiData->partnerMove != 0 && HasTrappingMoveEffect(battlerAtkPartner))
            score += WEAK_EFFECT;
        break;
    case EFFECT_MAGNET_RISE:
        if (IsBattlerGrounded(battlerAtk)
          && (HasMove(battlerAtkPartner, MOVE_EARTHQUAKE) || HasMove(battlerAtkPartner, MOVE_MAGNITUDE))
          && (AI_GetMoveEffectiveness(MOVE_EARTHQUAKE, battlerAtk, battlerAtkPartner) != AI_EFFECTIVENESS_x0)) // Doesn't resist ground move
        {
            RETURN_SCORE_PLUS(DECENT_EFFECT);   // partner has earthquake or magnitude -> good idea to use magnet rise
        }
        break;
    } // our effect relative to partner

    // consider global move effects
    switch (effect)
    {
    case EFFECT_SANDSTORM:
        if (ShouldSetSandstorm(battlerAtkPartner, atkPartnerAbility, atkPartnerHoldEffect))
        {
            RETURN_SCORE_PLUS(WEAK_EFFECT);   // our partner benefits from sandstorm
        }
        break;
    case EFFECT_RAIN_DANCE:
        if (ShouldSetRain(battlerAtkPartner, atkPartnerAbility, atkPartnerHoldEffect))
        {
            RETURN_SCORE_PLUS(WEAK_EFFECT);   // our partner benefits from rain
        }
        break;
    case EFFECT_SUNNY_DAY:
        if (ShouldSetSun(battlerAtkPartner, atkPartnerAbility, atkPartnerHoldEffect))
        {
            RETURN_SCORE_PLUS(WEAK_EFFECT);   // our partner benefits from sun
        }
        break;
    case EFFECT_HAIL:
        if (IsBattlerAlive(battlerAtkPartner)
         && ShouldSetHail(battlerAtkPartner, atkPartnerAbility, atkPartnerHoldEffect))
        {
            RETURN_SCORE_PLUS(DECENT_EFFECT);   // our partner benefits from hail
        }
        break;
    } // global move effect check

    // check specific target
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
    {
        // partner ability checks
        if (!partnerProtecting && moveTarget != MOVE_TARGET_BOTH && !DoesBattlerIgnoreAbilityChecks(aiData->abilities[battlerAtk], move))
        {
            switch (atkPartnerAbility)
            {
            case ABILITY_VOLT_ABSORB:
                if (!(AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_HP_AWARE))
                {
                    RETURN_SCORE_MINUS(10);
                }
                break;  // handled in AI_HPAware
            case ABILITY_MOTOR_DRIVE:
                if (moveType == TYPE_ELECTRIC && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, STAT_SPEED))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_LIGHTNING_ROD:
                if (moveType == TYPE_ELECTRIC
                    && HasMoveWithCategory(battlerAtkPartner, DAMAGE_CATEGORY_SPECIAL)
                    && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, STAT_SPATK))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_WATER_ABSORB:
            case ABILITY_DRY_SKIN:
                if (!(AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_HP_AWARE))
                {
                    RETURN_SCORE_MINUS(10);
                }
                break;  // handled in AI_HPAware
            case ABILITY_STORM_DRAIN:
                if (moveType == TYPE_WATER
                    && HasMoveWithCategory(battlerAtkPartner, DAMAGE_CATEGORY_SPECIAL)
                    && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, STAT_SPATK))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_FLASH_FIRE:
                if (moveType == TYPE_FIRE
                    && HasMoveWithType(battlerAtkPartner, TYPE_FIRE)
                    && !(gBattleResources->flags->flags[battlerAtkPartner] & RESOURCE_FLAG_FLASH_FIRE))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_JUSTIFIED:
                if (moveType == TYPE_DARK
                    && !IS_MOVE_STATUS(move)
                    && HasMoveWithCategory(battlerAtkPartner, DAMAGE_CATEGORY_PHYSICAL)
                    && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, STAT_ATK)
                    && !CanIndexMoveFaintTarget(battlerAtk, battlerAtkPartner, AI_THINKING_STRUCT->movesetIndex, 1))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_RATTLED:
                if (!IS_MOVE_STATUS(move)
                    && (moveType == TYPE_DARK || moveType == TYPE_GHOST || moveType == TYPE_BUG)
                    && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, STAT_SPEED)
                    && !CanIndexMoveFaintTarget(battlerAtk, battlerAtkPartner, AI_THINKING_STRUCT->movesetIndex, 1))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_DEFIANT:
                if (IsStatLoweringEffect(effect)
                    && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, STAT_ATK))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_COMPETITIVE:
                if (IsStatLoweringEffect(effect)
                    && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, STAT_SPATK))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            }
        } // ability checks

        // attacker move effects specifically targeting partner
        if (!partnerProtecting)
        {
            switch (effect)
            {
            case EFFECT_SWAGGER:
                if (gBattleMons[battlerAtkPartner].statStages[STAT_ATK] < MAX_STAT_STAGE
                 && HasMoveWithCategory(battlerAtkPartner, DAMAGE_CATEGORY_PHYSICAL)
                 && (!AI_CanBeConfused(battlerAtk, battlerAtkPartner, move, TRUE)
                  || atkPartnerHoldEffect == HOLD_EFFECT_CURE_CONFUSION
                  || atkPartnerHoldEffect == HOLD_EFFECT_CURE_STATUS))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_FLATTER:
                if (gBattleMons[battlerAtkPartner].statStages[STAT_SPATK] < MAX_STAT_STAGE
                 && HasMoveWithCategory(battlerAtkPartner, DAMAGE_CATEGORY_SPECIAL)
                 && (!AI_CanBeConfused(battlerAtk, battlerAtkPartner, move, TRUE)
                  || atkPartnerHoldEffect == HOLD_EFFECT_CURE_CONFUSION
                  || atkPartnerHoldEffect == HOLD_EFFECT_CURE_STATUS))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_BEAT_UP:
                if (atkPartnerAbility == ABILITY_JUSTIFIED
                  && moveType == TYPE_DARK
                  && !IS_MOVE_STATUS(move)
                  && HasMoveWithCategory(battlerAtkPartner, DAMAGE_CATEGORY_PHYSICAL)
                  && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, STAT_ATK)
                  && !CanIndexMoveFaintTarget(battlerAtk, battlerAtkPartner, AI_THINKING_STRUCT->movesetIndex, 0))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_SKILL_SWAP:
                if (aiData->abilities[battlerAtk] != aiData->abilities[BATTLE_PARTNER(battlerAtk)] && !attackerHasBadAbility)
                {
                    if (aiData->abilities[BATTLE_PARTNER(battlerAtk)] == ABILITY_TRUANT)
                    {
                        RETURN_SCORE_PLUS(10);
                    }
                    else if (aiData->abilities[battlerAtk] == ABILITY_COMPOUND_EYES
                     && HasMoveWithLowAccuracy(battlerAtkPartner, FOE(battlerAtkPartner), 90, TRUE, atkPartnerAbility, aiData->abilities[FOE(battlerAtkPartner)], atkPartnerHoldEffect, aiData->holdEffects[FOE(battlerAtkPartner)]))
                    {
                        RETURN_SCORE_PLUS(3);
                    }
                }
                break;
            case EFFECT_ROLE_PLAY:
                if (attackerHasBadAbility && !partnerHasBadAbility)
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_WORRY_SEED:
            case EFFECT_GASTRO_ACID:
            case EFFECT_SIMPLE_BEAM:
                if (partnerHasBadAbility)
                {
                    RETURN_SCORE_PLUS(DECENT_EFFECT);
                }
                break;
            case EFFECT_ENTRAINMENT:
                if (partnerHasBadAbility && IsAbilityOfRating(aiData->abilities[battlerAtk], 0))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_SOAK:
                if (atkPartnerAbility == ABILITY_WONDER_GUARD
                 && (GetBattlerType(battlerAtkPartner, 0) != TYPE_WATER
                 || GetBattlerType(battlerAtkPartner, 1) != TYPE_WATER
                 || GetBattlerType(battlerAtkPartner, 2) != TYPE_WATER))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_AFTER_YOU:
                if (AI_WhoStrikesFirst(battlerAtkPartner, FOE(battlerAtkPartner), aiData->partnerMove) == AI_IS_SLOWER  // Opponent mon 1 goes before partner
                  || AI_WhoStrikesFirst(battlerAtkPartner, BATTLE_PARTNER(FOE(battlerAtkPartner)), aiData->partnerMove) == AI_IS_SLOWER) // Opponent mon 2 goes before partner
                {
                    if (gMovesInfo[aiData->partnerMove].effect == EFFECT_COUNTER || gMovesInfo[aiData->partnerMove].effect == EFFECT_MIRROR_COAT)
                        break; // These moves need to go last
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_HEAL_PULSE:
                if (AI_WhoStrikesFirst(battlerAtk, FOE(battlerAtk), move) == AI_IS_FASTER
                  && AI_WhoStrikesFirst(battlerAtk, BATTLE_PARTNER(FOE(battlerAtk)), move) == AI_IS_FASTER
                  && gBattleMons[battlerAtkPartner].hp < gBattleMons[battlerAtkPartner].maxHP / 2)
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                break;
            } // attacker move effects
        } // check partner protecting

        score -= 30; // otherwise, don't target partner
    }
    else // checking opponent
    {
        // these checks mostly handled in AI_CheckBadMove and AI_CheckViability
        switch (effect)
        {
        case EFFECT_SKILL_SWAP:
            if (aiData->abilities[battlerAtk] == ABILITY_TRUANT)
                score += GOOD_EFFECT;
            else if (IsAbilityOfRating(aiData->abilities[battlerAtk], 0) || IsAbilityOfRating(aiData->abilities[battlerDef], 10))
                score += DECENT_EFFECT; // we want to transfer our bad ability or take their awesome ability
            break;
        }

        // lightning rod, flash fire against enemy handled in AI_CheckBadMove
    }

    return score;
}

static bool32 IsPinchBerryItemEffect(u32 holdEffect)
{
    switch (holdEffect)
    {
    case HOLD_EFFECT_ATTACK_UP:
    case HOLD_EFFECT_DEFENSE_UP:
    case HOLD_EFFECT_SPEED_UP:
    case HOLD_EFFECT_SP_ATTACK_UP:
    case HOLD_EFFECT_SP_DEFENSE_UP:
    case HOLD_EFFECT_CRITICAL_UP:
    case HOLD_EFFECT_RANDOM_STAT_UP:
    case HOLD_EFFECT_CUSTAP_BERRY:
    case HOLD_EFFECT_MICLE_BERRY:
        return TRUE;
    }

    return FALSE;
}

static s32 CompareMoveAccuracies(u32 battlerAtk, u32 battlerDef, u32 moveSlot1, u32 moveSlot2)
{
    u32 acc1 = AI_DATA->moveAccuracy[battlerAtk][battlerDef][moveSlot1];
    u32 acc2 = AI_DATA->moveAccuracy[battlerAtk][battlerDef][moveSlot2];

    if (acc1 > acc2)
        return 1;
    else if (acc2 > acc1)
        return -1;
    return 0;
}

static inline bool32 ShouldUseSpreadDamageMove(u32 battlerAtk, u32 move, u32 moveIndex, u32 hitsToFaintOpposingBattler)
{
    u32 partnerBattler = BATTLE_PARTNER(battlerAtk);
    u32 noOfHitsToFaintPartner = GetNoOfHitsToKOBattler(battlerAtk, partnerBattler, moveIndex);
    return (IsDoubleBattle()
         && noOfHitsToFaintPartner != 0 // Immunity check
         && IsBattlerAlive(partnerBattler)
         && gMovesInfo[move].target == MOVE_TARGET_FOES_AND_ALLY
         && !(noOfHitsToFaintPartner < 4 && hitsToFaintOpposingBattler == 1)
         && noOfHitsToFaintPartner < 7);
}

static s32 AI_CompareDamagingMoves(u32 battlerAtk, u32 battlerDef, u32 currId)
{
    u32 i;
    bool32 multipleBestMoves = FALSE;
    s32 viableMoveScores[MAX_MON_MOVES];
    s32 bestViableMoveScore;
    s32 noOfHits[MAX_MON_MOVES];
    s32 score = 0;
    s32 leastHits = 1000;
    u16 *moves = GetMovesArray(battlerAtk);
    bool8 isTwoTurnNotSemiInvulnerableMove[MAX_MON_MOVES];

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && gMovesInfo[moves[i]].power)
        {
            noOfHits[i] = GetNoOfHitsToKOBattler(battlerAtk, battlerDef, i);
            if (ShouldUseSpreadDamageMove(battlerAtk,moves[i], i, noOfHits[i]))
            {
                noOfHits[i] = -1;
                viableMoveScores[i] = 0;
                isTwoTurnNotSemiInvulnerableMove[i] = FALSE;
            }
            else if (noOfHits[i] < leastHits && noOfHits[i] != 0)
            {
                leastHits = noOfHits[i];
            }
            viableMoveScores[i] = AI_SCORE_DEFAULT;
            isTwoTurnNotSemiInvulnerableMove[i] = IsTwoTurnNotSemiInvulnerableMove(battlerAtk, moves[i]);
        }
        else
        {
            noOfHits[i] = -1;
            viableMoveScores[i] = 0;
            isTwoTurnNotSemiInvulnerableMove[i] = FALSE;
        }
        /*
            MgbaPrintf_("%S: required hits: %d Dmg: %d", gMoveNames[moves[i]], noOfHits[i], AI_DATA->simulatedDmg[battlerAtk][battlerDef][i]);
        */
    }

    // Priority list:
    // 1. Less no of hits to ko
    // 2. Not charging
    // 3. More accuracy
    // 4. Better effect

    // Current move requires the least hits to KO. Compare with other moves.
    if (leastHits == noOfHits[currId])
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (i == currId)
                continue;
            if (noOfHits[currId] == noOfHits[i])
            {
                multipleBestMoves = TRUE;
                // We need to make sure it's the current move which is objectively better.
                if (isTwoTurnNotSemiInvulnerableMove[i] && !isTwoTurnNotSemiInvulnerableMove[currId])
                    viableMoveScores[i] -= 3;
                else if (!isTwoTurnNotSemiInvulnerableMove[i] && isTwoTurnNotSemiInvulnerableMove[currId])
                    viableMoveScores[currId] -= 3;

                switch (CompareMoveAccuracies(battlerAtk, battlerDef, currId, i))
                {
                case 1:
                    viableMoveScores[i] -= 2;
                    break;
                case -1:
                    viableMoveScores[currId] -= 2;
                    break;
                }
                switch (AI_WhichMoveBetter(moves[currId], moves[i], battlerAtk, battlerDef, noOfHits[currId]))
                {
                case 1:
                    viableMoveScores[i] -= 1;
                    break;
                case -1:
                    viableMoveScores[currId] -= 1;
                    break;
                }
            }
        }
        // Turns out the current move deals the most dmg compared to the other 3.
        if (!multipleBestMoves)
            score += BEST_DAMAGE_MOVE;
        else
        {
            bestViableMoveScore = 0;
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (viableMoveScores[i] > bestViableMoveScore)
                    bestViableMoveScore = viableMoveScores[i];
            }
            // Unless a better move was found increase score of current move
            if (viableMoveScores[currId] == bestViableMoveScore)
                score += BEST_DAMAGE_MOVE;
        }
    }

    return score;
}

static u32 AI_CalcMoveEffectScore(u32 battlerAtk, u32 battlerDef, u32 move)
{
    // move data
    u32 moveEffect = gMovesInfo[move].effect;
    struct AiLogicData *aiData = AI_DATA;
    u32 movesetIndex = AI_THINKING_STRUCT->movesetIndex;
    u32 effectiveness = aiData->effectiveness[battlerAtk][battlerDef][movesetIndex];

    s32 score = 0;
    u32 predictedMove = aiData->predictedMoves[battlerDef];
    u32 predictedMoveSlot = GetMoveSlot(GetMovesArray(battlerDef), predictedMove);
    bool32 isDoubleBattle = IsValidDoubleBattle(battlerAtk);
    u32 i;

    // check status move preference
    if (AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_PREFER_STATUS_MOVES && IS_MOVE_STATUS(move) && effectiveness != AI_EFFECTIVENESS_x0)
        score += 10;

    // check thawing moves
    if ((gBattleMons[battlerAtk].status1 & STATUS1_FREEZE) && gMovesInfo[move].thawsUser)
        score += 10;

    // check burn / frostbite
    if (AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_SMART_SWITCHING && AI_DATA->abilities[battlerAtk] == ABILITY_NATURAL_CURE)
    {
        if (gBattleMons[battlerAtk].status1 & STATUS1_BURN && HasOnlyMovesWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL, TRUE))
            score -= 20; // Force switch if all your attacking moves are physical and you have Natural Cure.
    }

    // move effect checks
    switch (moveEffect)
    {
    case EFFECT_SLEEP:
    case EFFECT_YAWN:
        IncreaseSleepScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_ABSORB:
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_BIG_ROOT && effectiveness >= AI_EFFECTIVENESS_x1)
            score += DECENT_EFFECT;
    case EFFECT_EXPLOSION:
    case EFFECT_MEMENTO:
        if (AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_WILL_SUICIDE && gBattleMons[battlerDef].statStages[STAT_EVASION] < 7)
        {
            if (aiData->hpPercents[battlerAtk] < 50 && AI_RandLessThan(128))
                score += DECENT_EFFECT;
        }
        break;
    case EFFECT_MIRROR_MOVE:
        if (predictedMove != MOVE_NONE)
            return AI_CheckViability(battlerAtk, battlerDef, gLastMoves[battlerDef], score);
        break;
    case EFFECT_ATTACK_UP:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK, &score);
        break;
    case EFFECT_ATTACK_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK_2, &score);
        break;
    case EFFECT_DEFENSE_UP:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF, &score);
        break;
    case EFFECT_DEFENSE_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF_2, &score);
        break;
    case EFFECT_SPEED_UP:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED, &score);
        break;
    case EFFECT_SPEED_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED_2, &score);
        break;
    case EFFECT_SPECIAL_ATTACK_UP:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK, &score);
        break;
    case EFFECT_SPECIAL_ATTACK_UP_2:
    case EFFECT_SPECIAL_ATTACK_UP_3:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK_2, &score);
        break;
    case EFFECT_SPECIAL_DEFENSE_UP:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF, &score);
        break;
    case EFFECT_SPECIAL_DEFENSE_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF_2, &score);
        break;
    case EFFECT_ACCURACY_UP:
    case EFFECT_ACCURACY_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ACC, &score);
        break;
    case EFFECT_EVASION_UP:
    case EFFECT_EVASION_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_EVASION, &score);
        break;
    case EFFECT_ATTACK_DOWN:
    case EFFECT_ATTACK_DOWN_2:
        if (!ShouldLowerAttack(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            score -= 2;
        if (gBattleMons[battlerDef].statStages[STAT_ATK] < DEFAULT_STAT_STAGE)
            score -= 1;
        else if (aiData->hpPercents[battlerAtk] <= 90)
            score -= 1;
        if (gBattleMons[battlerDef].statStages[STAT_ATK] > 3 && !AI_RandLessThan(50))
            score -= 2;
        else if (aiData->hpPercents[battlerDef] < 70)
            score -= 2;
        break;
    case EFFECT_DEFENSE_DOWN:
    case EFFECT_DEFENSE_DOWN_2:
        if (!ShouldLowerDefense(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            score -= 2;
        if ((aiData->hpPercents[battlerAtk] < 70 && !AI_RandLessThan(50)) || (gBattleMons[battlerDef].statStages[STAT_DEF] <= 3 && !AI_RandLessThan(50)))
            score -= 2;
        if (aiData->hpPercents[battlerDef] <= 70)
            score -= 2;
        break;
    case EFFECT_SPEED_DOWN:
    case EFFECT_SPEED_DOWN_2:
        if (AI_STRIKES_FIRST(battlerAtk, battlerDef, move))
            score -= 3;
        else if (!AI_RandLessThan(70))
            score += DECENT_EFFECT;
        break;
    case EFFECT_SPECIAL_ATTACK_DOWN:
    case EFFECT_SPECIAL_ATTACK_DOWN_2:
        if (!ShouldLowerSpAtk(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            score -= 2;
        if (gBattleMons[battlerDef].statStages[STAT_SPATK] < DEFAULT_STAT_STAGE)
            score -= 1;
        else if (aiData->hpPercents[battlerAtk] <= 90)
            score -= 1;
        if (gBattleMons[battlerDef].statStages[STAT_SPATK] > 3 && !AI_RandLessThan(50))
            score -= 2;
        else if (aiData->hpPercents[battlerDef] < 70)
            score -= 2;
        break;
    case EFFECT_SPECIAL_DEFENSE_DOWN:
    case EFFECT_SPECIAL_DEFENSE_DOWN_2:
        if (!ShouldLowerSpDef(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            score -= 2;
        if ((aiData->hpPercents[battlerAtk] < 70 && !AI_RandLessThan(50))
          || (gBattleMons[battlerDef].statStages[STAT_SPDEF] <= 3 && !AI_RandLessThan(50)))
            score -= 2;
        if (aiData->hpPercents[battlerDef] <= 70)
            score -= 2;
        break;
    case EFFECT_ACCURACY_DOWN:
    case EFFECT_ACCURACY_DOWN_2:
        if (ShouldLowerAccuracy(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            score -= 2;
        if ((aiData->hpPercents[battlerAtk] < 70 || aiData->hpPercents[battlerDef] < 70) && AI_RandLessThan(100))
            score -= 1;
        if (gBattleMons[battlerDef].statStages[STAT_ACC] <= 4 && !AI_RandLessThan(80))
            score -= 2;
        if (gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY && !AI_RandLessThan(70))
            score += DECENT_EFFECT;
        if (gStatuses3[battlerDef] & STATUS3_LEECHSEED && !AI_RandLessThan(70))
            score += DECENT_EFFECT;
        if (gStatuses3[battlerDef] & STATUS3_ROOTED && AI_RandLessThan(128))
            score += WEAK_EFFECT;
        if (gBattleMons[battlerDef].status2 & STATUS2_CURSED && !AI_RandLessThan(70))
            score += DECENT_EFFECT;
        if (aiData->hpPercents[battlerAtk] > 70 || gBattleMons[battlerDef].statStages[STAT_ACC] < DEFAULT_STAT_STAGE)
            break;
        else if (aiData->hpPercents[battlerAtk] < 40 || aiData->hpPercents[battlerDef] < 40 || !AI_RandLessThan(70))
            score -= 2;
        break;
    case EFFECT_EVASION_DOWN:
    case EFFECT_EVASION_DOWN_2:
        if (!ShouldLowerEvasion(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            score -= 2;
        if ((aiData->hpPercents[battlerAtk] < 70 || gBattleMons[battlerDef].statStages[STAT_EVASION] <= 3) && !AI_RandLessThan(50))
            score -= 2;
        if (aiData->hpPercents[battlerDef] <= 70)
            score -= 2;
        if (gBattleMons[battlerAtk].statStages[STAT_ACC] < DEFAULT_STAT_STAGE)
            score += WEAK_EFFECT;
        if (gBattleMons[battlerDef].statStages[STAT_EVASION] < 7 || aiData->abilities[battlerAtk] == ABILITY_NO_GUARD)
            score -= 2;
        break;
    case EFFECT_BIDE:
        if (aiData->hpPercents[battlerAtk] < 90)
            score -= 2; // Should be either removed or turned into increasing score
    case EFFECT_ACUPRESSURE:
        break;
    case EFFECT_ATTACK_ACCURACY_UP: // hone claws
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ACC, &score);
        break;
    case EFFECT_GROWTH:
    case EFFECT_ATTACK_SPATK_UP:    // work up
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK, &score);
        break;
    case EFFECT_HAZE:
        if (AnyStatIsRaised(BATTLE_PARTNER(battlerAtk))
          || PartnerHasSameMoveEffectWithoutTarget(BATTLE_PARTNER(battlerAtk), move, aiData->partnerMove))
            break;
        score += AI_TryToClearStats(battlerAtk, battlerDef, isDoubleBattle);
        break;
    case EFFECT_ROAR:
        if ((gMovesInfo[move].soundMove && aiData->abilities[battlerDef] == ABILITY_SOUNDPROOF) 
          || aiData->abilities[battlerDef] == ABILITY_SUCTION_CUPS)
            break;
        score += AI_TryToClearStats(battlerAtk, battlerDef, isDoubleBattle);
        break;
    case EFFECT_MULTI_HIT:
    case EFFECT_TRIPLE_KICK:
        if (AI_MoveMakesContact(aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk], move)
          && aiData->abilities[battlerAtk] != ABILITY_MAGIC_GUARD
          && aiData->holdEffects[battlerDef] == HOLD_EFFECT_ROCKY_HELMET)
            score -= 2;
        break;
    case EFFECT_CONVERSION:
        if (!IS_BATTLER_OF_TYPE(battlerAtk, gMovesInfo[gBattleMons[battlerAtk].moves[0]].type))
            score += WEAK_EFFECT;
        break;
    case EFFECT_SWALLOW:
        if (gDisableStructs[battlerAtk].stockpileCounter == 0)
        {
            break;
        }
        else
        {
            u32 healPercent = 0;
            switch (gDisableStructs[battlerAtk].stockpileCounter)
            {
            case 1:
                healPercent = 25;
                break;
            case 2:
                healPercent = 50;
                break;
            case 3:
                healPercent = 100;
                break;
            default:
                break;
            }

            if (ShouldRecover(battlerAtk, battlerDef, move, healPercent))
                score += DECENT_EFFECT;
        }
        break;
    case EFFECT_RESTORE_HP:
    case EFFECT_SOFTBOILED:
    case EFFECT_ROOST:
    case EFFECT_MORNING_SUN:
    case EFFECT_SYNTHESIS:
    case EFFECT_MOONLIGHT:
        if (ShouldRecover(battlerAtk, battlerDef, move, 50))
            score += GOOD_EFFECT;
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_BIG_ROOT)
            score += DECENT_EFFECT;
        break;
    case EFFECT_TOXIC:
    case EFFECT_POISON:
        IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_REFLECT:
    case EFFECT_AURORA_VEIL:
        if (ShouldSetScreen(battlerAtk, battlerDef, moveEffect))
        {
            score += BEST_EFFECT;
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_LIGHT_CLAY)
                score += DECENT_EFFECT;
        }
        break;
    case EFFECT_REST:
        if (!(AI_CanSleep(battlerAtk, aiData->abilities[battlerAtk])))
        {
            break;
        }
        else if (ShouldRecover(battlerAtk, battlerDef, move, 100))
        {
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_CURE_SLP
              || aiData->holdEffects[battlerAtk] == HOLD_EFFECT_CURE_STATUS
              || HasMoveEffect(EFFECT_SLEEP_TALK, battlerAtk)
              || HasMoveEffect(EFFECT_SNORE, battlerAtk)
              || aiData->abilities[battlerAtk] == ABILITY_SHED_SKIN
              || aiData->abilities[battlerAtk] == ABILITY_EARLY_BIRD
              || (AI_GetWeather(aiData) & B_WEATHER_RAIN && gWishFutureKnock.weatherDuration != 1 && aiData->abilities[battlerAtk] == ABILITY_HYDRATION))
                score += GOOD_EFFECT;
        }
        break;
    case EFFECT_OHKO:
        if (gStatuses3[battlerAtk] & STATUS3_ALWAYS_HITS)
            score += BEST_EFFECT;
        break;
    case EFFECT_MEAN_LOOK:
        if (ShouldTrap(battlerAtk, battlerDef, move))
            score += GOOD_EFFECT;
        break;
    case EFFECT_FOCUS_ENERGY:
    case EFFECT_LASER_FOCUS:
        if (aiData->abilities[battlerAtk] == ABILITY_SUPER_LUCK
          || aiData->abilities[battlerAtk] == ABILITY_SNIPER
          || aiData->holdEffects[battlerAtk] == HOLD_EFFECT_SCOPE_LENS
          || HasHighCritRatioMove(battlerAtk))
            score += GOOD_EFFECT;
        break;
    case EFFECT_CONFUSE:
        IncreaseConfusionScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_PARALYZE:
        IncreaseParalyzeScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_SUBSTITUTE:
        score += GOOD_EFFECT;
        if (gStatuses3[battlerDef] & STATUS3_PERISH_SONG)
            score += GOOD_EFFECT;
        if (gBattleMons[battlerDef].status1 & (STATUS1_BURN | STATUS1_PSN_ANY))
            score += DECENT_EFFECT;
        if (HasMoveEffect(battlerDef, EFFECT_SLEEP)
          || HasMoveEffect(battlerDef, EFFECT_TOXIC)
          || HasMoveEffect(battlerDef, EFFECT_POISON)
          || HasMoveEffect(battlerDef, EFFECT_PARALYZE)
          || HasMoveEffect(battlerDef, EFFECT_WILL_O_WISP)
          || HasMoveEffect(battlerDef, EFFECT_CONFUSE)
          || HasMoveEffect(battlerDef, EFFECT_LEECH_SEED))
            score += GOOD_EFFECT;
        if (!gBattleMons[battlerDef].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION && aiData->hpPercents[battlerAtk] > 70))
            score += WEAK_EFFECT;
        break;
    case EFFECT_MIMIC:
        if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER)
        {
            if (gLastMoves[battlerDef] != MOVE_NONE && gLastMoves[battlerDef] != 0xFFFF)
                return AI_CheckViability(battlerAtk, battlerDef, gLastMoves[battlerDef], score);
        }
        break;
    case EFFECT_LEECH_SEED:
        if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS)
          || gStatuses3[battlerDef] & STATUS3_LEECHSEED
          || HasMoveWithAdditionalEffect(battlerDef, MOVE_EFFECT_RAPID_SPIN)
          || aiData->abilities[battlerDef] == ABILITY_LIQUID_OOZE
          || aiData->abilities[battlerDef] == ABILITY_MAGIC_GUARD)
            break;
        score += GOOD_EFFECT;
        if (!HasDamagingMove(battlerDef) || IsBattlerTrapped(battlerDef, FALSE))
            score += DECENT_EFFECT;
        break;
    case EFFECT_DO_NOTHING:
        //todo - check z splash, z celebrate, z happy hour (lol)
        break;
    case EFFECT_TELEPORT: // Either remove or add better logic
        if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || GetBattlerSide(battlerAtk) != B_SIDE_PLAYER)
            break;
        //fallthrough
    case EFFECT_HIT_ESCAPE:
        if (!IsDoubleBattle())
        {
            switch (ShouldPivot(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, movesetIndex))
            {
            case 0: // no
                score -= 10;    // technically should go in CheckBadMove, but this is easier/less computationally demanding
                break;
            case 1: // maybe
                break;
            case 2: // yes
                score += BEST_EFFECT;
                break;
            }
        }
        else //Double Battle
        {
            if (CountUsablePartyMons(battlerAtk) == 0)
                break; // Can't switch

            //if (switchAbility == ABILITY_INTIMIDATE && PartyHasMoveCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL))
                //score += 7;
        }
        break;
    case EFFECT_BATON_PASS:
        if (ShouldSwitch(battlerAtk, FALSE) && (gBattleMons[battlerAtk].status2 & STATUS2_SUBSTITUTE
          || (gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_AQUA_RING | STATUS3_MAGNET_RISE | STATUS3_POWER_TRICK))
          || AnyStatIsRaised(battlerAtk)))
            score += BEST_EFFECT;
        break;
    case EFFECT_DISABLE:
        if (gDisableStructs[battlerDef].disableTimer == 0
        && (gLastMoves[battlerDef] != MOVE_NONE)
        && (gLastMoves[battlerDef] != 0xFFFF)
        && (aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB)
        && (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER))
        {
            if (CanTargetMoveFaintAi(gLastMoves[battlerDef], battlerDef, battlerAtk, 1))
                score += GOOD_EFFECT; // Disable move that can kill attacker
        }
        break;
    case EFFECT_ENCORE:
        if (gDisableStructs[battlerDef].encoreTimer == 0
        && (aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB)
        && (gBattleMoveEffects[gMovesInfo[gLastMoves[battlerDef]].effect].encourageEncore))
            score += BEST_EFFECT;
        break;
    case EFFECT_SLEEP_TALK:
    case EFFECT_SNORE:
        if (!IsWakeupTurn(battlerAtk) && gBattleMons[battlerAtk].status1 & STATUS1_SLEEP)
            score += BEST_EFFECT;
        break;
    case EFFECT_LOCK_ON:
        if (HasMoveEffect(battlerAtk, EFFECT_OHKO))
            score += GOOD_EFFECT;
        else if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 85, TRUE, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], aiData->holdEffects[battlerAtk], aiData->holdEffects[battlerDef]))
            score += GOOD_EFFECT;
        break;
    case EFFECT_DESTINY_BOND:
        if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER && CanTargetFaintAi(battlerDef, battlerAtk))
            score += GOOD_EFFECT;
        break;
    case EFFECT_SPITE:
        //TODO - predicted move
        break;
    case EFFECT_WISH:
    case EFFECT_HEAL_BELL:
        if (ShouldUseWishAromatherapy(battlerAtk, battlerDef, move))
            score += DECENT_EFFECT;
        break;
    case EFFECT_CURSE:
        if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GHOST))
        {
            if (IsBattlerTrapped(battlerDef, TRUE))
                score += GOOD_EFFECT;
            else
                score += WEAK_EFFECT;
        }
        else
        {
            IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK, &score);
            IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF, &score);
        }
        break;
    case EFFECT_PROTECT:
        if (predictedMove == 0xFFFF)
            predictedMove = MOVE_NONE;
        switch (move)
        {
        case MOVE_QUICK_GUARD:
            if (predictedMove != MOVE_NONE && gMovesInfo[predictedMove].priority > 0)
                ProtectChecks(battlerAtk, battlerDef, move, predictedMove, &score);
            break;
        case MOVE_WIDE_GUARD:
            if (predictedMove != MOVE_NONE && gMovesInfo[predictedMove].target & (MOVE_TARGET_FOES_AND_ALLY | MOVE_TARGET_BOTH))
            {
                ProtectChecks(battlerAtk, battlerDef, move, predictedMove, &score);
            }
            else if (isDoubleBattle && gMovesInfo[aiData->partnerMove].target & MOVE_TARGET_FOES_AND_ALLY)
            {
                ProtectChecks(battlerAtk, battlerDef, move, predictedMove, &score);
            }
            break;
        default: // protect
            ProtectChecks(battlerAtk, battlerDef, move, predictedMove, &score);
            break;
        }
        break;
    case EFFECT_ENDURE:
        if (CanTargetFaintAi(battlerDef, battlerAtk))
        {
            if (gBattleMons[battlerAtk].hp > gBattleMons[battlerAtk].maxHP / 4 // Pinch berry couldn't have activated yet
             && IsPinchBerryItemEffect(aiData->holdEffects[battlerAtk]))
                score += GOOD_EFFECT;
            else if ((gBattleMons[battlerAtk].hp > 1) // Only spam endure for Flail/Reversal if you're not at Min Health
             && (HasMoveEffect(battlerAtk, EFFECT_FLAIL) || HasMoveEffect(battlerAtk, EFFECT_ENDEAVOR)))
                score += GOOD_EFFECT;
        }
        break;
    case EFFECT_SPIKES:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_TOXIC_SPIKES:
        if (AI_ShouldSetUpHazards(battlerAtk, battlerDef, aiData));
        {
            if (gDisableStructs[battlerAtk].isFirstTurn)
                score += BEST_EFFECT;
            else
                score += DECENT_EFFECT;
        }
        break;
    case EFFECT_FORESIGHT:
        if (aiData->abilities[battlerAtk] == ABILITY_SCRAPPY)
            break;
        else if (gBattleMons[battlerDef].statStages[STAT_EVASION] > DEFAULT_STAT_STAGE
         || (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GHOST)
         && (HasMoveWithType(battlerAtk, TYPE_NORMAL)
         || HasMoveWithType(battlerAtk, TYPE_FIGHTING))))
            score += DECENT_EFFECT;
        break;
    case EFFECT_MIRACLE_EYE:
        if (gBattleMons[battlerDef].statStages[STAT_EVASION] > DEFAULT_STAT_STAGE
          || (IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK) && (HasMoveWithType(battlerAtk, TYPE_PSYCHIC))))
            score += DECENT_EFFECT;
        break;
    case EFFECT_PERISH_SONG:
        if (IsBattlerTrapped(battlerDef, TRUE))
            score += GOOD_EFFECT;
        break;
    case EFFECT_SANDSTORM:
        if (ShouldSetSandstorm(battlerAtk, aiData->holdEffects[battlerAtk], aiData->holdEffects[battlerAtk]))
        {
            score += DECENT_EFFECT;
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_SMOOTH_ROCK)
                score += WEAK_EFFECT;
            if (HasMoveEffect(battlerDef, EFFECT_MORNING_SUN)
              || HasMoveEffect(battlerDef, EFFECT_SYNTHESIS)
              || HasMoveEffect(battlerDef, EFFECT_MOONLIGHT))
                score += WEAK_EFFECT;
        }
        break;
    case EFFECT_HAIL:
        if (ShouldSetHail(battlerAtk, aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk]))
        {
            if ((HasMoveEffect(battlerAtk, EFFECT_AURORA_VEIL) || HasMoveEffect(BATTLE_PARTNER(battlerAtk), EFFECT_AURORA_VEIL))
              && ShouldSetScreen(battlerAtk, battlerDef, EFFECT_AURORA_VEIL))
                score += GOOD_EFFECT;

            score += DECENT_EFFECT;
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_ICY_ROCK)
                score += WEAK_EFFECT;
            if (HasMoveEffect(battlerDef, EFFECT_MORNING_SUN)
              || HasMoveEffect(battlerDef, EFFECT_SYNTHESIS)
              || HasMoveEffect(battlerDef, EFFECT_MOONLIGHT))
                score += WEAK_EFFECT;
        }
        break;
    case EFFECT_RAIN_DANCE:
        if (ShouldSetRain(battlerAtk, aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk]))
        {
            score += DECENT_EFFECT;
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_DAMP_ROCK)
                score += WEAK_EFFECT;
            if (HasMoveEffect(battlerDef, EFFECT_MORNING_SUN)
              || HasMoveEffect(battlerDef, EFFECT_SYNTHESIS)
              || HasMoveEffect(battlerDef, EFFECT_SOLAR_BEAM)
              || HasMoveEffect(battlerDef, EFFECT_MOONLIGHT))
                score += WEAK_EFFECT;
            if (HasMoveWithType(battlerDef, TYPE_FIRE) || HasMoveWithType(BATTLE_PARTNER(battlerDef), TYPE_FIRE))
                score += WEAK_EFFECT;
        }
        break;
    case EFFECT_SUNNY_DAY:
        if (ShouldSetSun(battlerAtk, aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk]))
        {
            score += DECENT_EFFECT;
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_HEAT_ROCK)
                score += WEAK_EFFECT;
            if (HasMoveWithType(battlerDef, TYPE_WATER) || HasMoveWithType(BATTLE_PARTNER(battlerDef), TYPE_WATER))
                score += WEAK_EFFECT;
            if (HasMoveEffect(battlerDef, EFFECT_THUNDER) || HasMoveEffect(BATTLE_PARTNER(battlerDef), EFFECT_THUNDER))
                score += WEAK_EFFECT;
        }
        break;
    case EFFECT_FELL_STINGER:
        if (gBattleMons[battlerAtk].statStages[STAT_ATK] < MAX_STAT_STAGE
        && CanIndexMoveFaintTarget(battlerAtk, battlerDef, movesetIndex, 0))
            score += BEST_EFFECT;
        break;
    case EFFECT_BELLY_DRUM:
        if (!CanTargetFaintAi(battlerDef, battlerAtk)
        && gBattleMons[battlerAtk].statStages[STAT_ATK] < MAX_STAT_STAGE - 2
        && HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
            score += BEST_EFFECT;
        break;
    case EFFECT_PSYCH_UP:
        score += AI_ShouldCopyStatChanges(battlerAtk, battlerDef);
        break;
    case EFFECT_SEMI_INVULNERABLE:
        if (predictedMove != MOVE_NONE && !isDoubleBattle)
        {
            if ((AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER)
             && (gMovesInfo[predictedMove].effect == EFFECT_EXPLOSION || gMovesInfo[predictedMove].effect == EFFECT_PROTECT))
                score += GOOD_EFFECT;
            else if (gMovesInfo[predictedMove].effect == EFFECT_SEMI_INVULNERABLE && !(gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE))
                score += GOOD_EFFECT;
        }
        break;
    case EFFECT_DEFENSE_CURL:
        if (HasMoveEffect(battlerAtk, EFFECT_ROLLOUT) && !(gBattleMons[battlerAtk].status2 & STATUS2_DEFENSE_CURL))
            score += DECENT_EFFECT;
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF, &score);
        break;
    case EFFECT_FIRST_TURN_ONLY:
        if (ShouldFakeOut(battlerAtk, battlerDef, move) && MoveHasAdditionalEffectWithChance(move, MOVE_EFFECT_FLINCH, 100))
            score += GOOD_EFFECT;
        else if (gDisableStructs[battlerAtk].isFirstTurn && GetBestDmgMoveFromBattler(battlerAtk, battlerDef) == move)
            score += BEST_EFFECT;
        break;
    case EFFECT_STOCKPILE:
        if (HasMoveEffect(battlerAtk, EFFECT_SWALLOW) || HasMoveEffect(battlerAtk, EFFECT_SPIT_UP))
            score += DECENT_EFFECT;
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF, &score);
        break;
    case EFFECT_SWAGGER:
    case EFFECT_FLATTER:
        if (HasMoveEffect(battlerAtk, EFFECT_FOUL_PLAY)
         || HasMoveEffect(battlerAtk, EFFECT_PSYCH_UP))
            score += DECENT_EFFECT;
        IncreaseConfusionScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_FURY_CUTTER:
        if (!isDoubleBattle && aiData->holdEffects[battlerAtk] == HOLD_EFFECT_METRONOME)
            score += GOOD_EFFECT;
        break;
    case EFFECT_ATTRACT:
        if (!isDoubleBattle
        && (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_SLOWER)
        && BattlerWillFaintFromSecondaryDamage(battlerDef, aiData->abilities[battlerDef]))
            break; // Don't use if the attract won't have a change to activate
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY
        || (gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
        || IsBattlerTrapped(battlerDef, TRUE))
            score += GOOD_EFFECT;
        else
            score += DECENT_EFFECT;
        break;
    case EFFECT_SAFEGUARD:
        if (!AI_IsTerrainAffected(battlerAtk, STATUS_FIELD_MISTY_TERRAIN) || !IsBattlerGrounded(battlerAtk))
            score += DECENT_EFFECT; // TODO: check if opp has status move?
        //if (CountUsablePartyMons(battlerDef) != 0)
            //score += 8;
        break;
    case EFFECT_PURSUIT:
        // TODO
        // if (IsPredictedToSwitch(battlerDef, battlerAtk))
        //     score += GOOD_EFFECT;
        // else if (IsPredictedToUsePursuitableMove(battlerDef, battlerAtk) && !MoveWouldHitFirst(move, battlerAtk, battlerDef)) //Pursuit against fast U-Turn
        //     score += GOOD_EFFECT;
        // break;
    case EFFECT_DEFOG:
        if ((gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_HAZARDS_ANY && CountUsablePartyMons(battlerAtk) != 0)
            || (gSideStatuses[GetBattlerSide(battlerDef)] & (SIDE_STATUS_SCREEN_ANY | SIDE_STATUS_SAFEGUARD | SIDE_STATUS_MIST)))
        {
            score += GOOD_EFFECT;
        }
        else if (!(gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_SPIKES)) //Don't blow away hazards if you set them up
        {
            if (isDoubleBattle)
            {
                if (IsHazardMoveEffect(gMovesInfo[aiData->partnerMove].effect) // Partner is going to set up hazards
                    && AI_WhoStrikesFirst(battlerAtk, BATTLE_PARTNER(battlerAtk), move) == AI_IS_SLOWER) // Partner going first
                    break; // Don't use Defog if partner is going to set up hazards
            }
            if (ShouldLowerEvasion(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
                score += DECENT_EFFECT;
        }
        break;
    case EFFECT_TORMENT:
        break;
    case EFFECT_WILL_O_WISP:
        IncreaseBurnScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_FOLLOW_ME:
        if (isDoubleBattle
          && move != MOVE_SPOTLIGHT
          && !IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef])
          && (move != MOVE_RAGE_POWDER || IsAffectedByPowder(battlerDef, aiData->abilities[battlerDef], aiData->holdEffects[battlerDef])) // Rage Powder doesn't affect powder immunities
          && IsBattlerAlive(BATTLE_PARTNER(battlerAtk)))
        {
            u32 predictedMoveOnPartner = gLastMoves[BATTLE_PARTNER(battlerAtk)];
            if (predictedMoveOnPartner != MOVE_NONE && !IS_MOVE_STATUS(predictedMoveOnPartner))
                score += GOOD_EFFECT;
        }
        break;
    case EFFECT_CHARGE:
        if (HasDamagingMoveOfType(battlerAtk, TYPE_ELECTRIC))
            score += DECENT_EFFECT;
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF, &score);
        break;
    case EFFECT_TAUNT:
        if (IS_MOVE_STATUS(predictedMove))
            score += GOOD_EFFECT;
        else if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_STATUS))
            score += DECENT_EFFECT;
        break;
    case EFFECT_TRICK:
    case EFFECT_BESTOW:
        switch (aiData->holdEffects[battlerAtk])
        {
        case HOLD_EFFECT_CHOICE_SCARF:
            score += DECENT_EFFECT; // assume its beneficial
            break;
        case HOLD_EFFECT_CHOICE_BAND:
            if (!HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL))
                score += DECENT_EFFECT;
            break;
        case HOLD_EFFECT_CHOICE_SPECS:
            if (!HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL))
                score += DECENT_EFFECT;
            break;
        case HOLD_EFFECT_TOXIC_ORB:
            if (!ShouldPoisonSelf(battlerAtk, aiData->abilities[battlerAtk]))
                score += DECENT_EFFECT;
            break;
        case HOLD_EFFECT_FLAME_ORB:
            if (!ShouldBurnSelf(battlerAtk, aiData->abilities[battlerAtk]) && AI_CanBeBurned(battlerAtk, aiData->abilities[battlerDef]))
                score += DECENT_EFFECT;
            break;
        case HOLD_EFFECT_BLACK_SLUDGE:
            if (!IS_BATTLER_OF_TYPE(battlerDef, TYPE_POISON) && aiData->abilities[battlerDef] != ABILITY_MAGIC_GUARD)
                score += DECENT_EFFECT;
            break;
        case HOLD_EFFECT_IRON_BALL:
            if (!HasMoveEffect(battlerDef, EFFECT_FLING) || !IsBattlerGrounded(battlerDef))
                score += DECENT_EFFECT;
            break;
        case HOLD_EFFECT_LAGGING_TAIL:
        case HOLD_EFFECT_STICKY_BARB:
            score += DECENT_EFFECT;
            break;
        case HOLD_EFFECT_EJECT_BUTTON:
            if (HasDamagingMove(battlerAtk)
             || (isDoubleBattle && IsBattlerAlive(BATTLE_PARTNER(battlerAtk)) && HasDamagingMove(BATTLE_PARTNER(battlerAtk))))
                score += DECENT_EFFECT; // Force 'em out next turn
            break;
        default:
            if (move != MOVE_BESTOW && aiData->items[battlerAtk] == ITEM_NONE)
            {
                switch (aiData->holdEffects[battlerDef])
                {
                case HOLD_EFFECT_CHOICE_BAND:
                    break;
                case HOLD_EFFECT_TOXIC_ORB:
                    if (ShouldPoisonSelf(battlerAtk, aiData->abilities[battlerAtk]))
                        score += DECENT_EFFECT;
                    break;
                case HOLD_EFFECT_FLAME_ORB:
                    if (ShouldBurnSelf(battlerAtk, aiData->abilities[battlerAtk]))
                        score += DECENT_EFFECT;
                    break;
                case HOLD_EFFECT_BLACK_SLUDGE:
                    if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_POISON) || aiData->abilities[battlerAtk] == ABILITY_MAGIC_GUARD)
                        score += DECENT_EFFECT;
                    break;
                case HOLD_EFFECT_IRON_BALL:
                    if (HasMoveEffect(battlerAtk, EFFECT_FLING))
                        score += DECENT_EFFECT;
                    break;
                case HOLD_EFFECT_LAGGING_TAIL:
                case HOLD_EFFECT_STICKY_BARB:
                    break;
                default:
                    score += WEAK_EFFECT;    //other hold effects generally universally good
                    break;
                }
            }
        }
        break;
    case EFFECT_ROLE_PLAY:
        if (!gAbilitiesInfo[aiData->abilities[battlerDef]].cantBeCopied
          && !IsAbilityOfRating(aiData->abilities[battlerAtk], 5)
          && IsAbilityOfRating(aiData->abilities[battlerDef], 5))
            score += DECENT_EFFECT;
        break;
    case EFFECT_INGRAIN:
        score += WEAK_EFFECT;
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_BIG_ROOT)
            score += GOOD_EFFECT;
        break;
    case EFFECT_MAGIC_COAT:
        if (IS_MOVE_STATUS(predictedMove) && gMovesInfo[predictedMove].target & (MOVE_TARGET_SELECTED | MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_BOTH))
            score += GOOD_EFFECT;
        break;
    case EFFECT_RECYCLE:
        if (GetUsedHeldItem(battlerAtk) != ITEM_NONE)
            score += WEAK_EFFECT;
        if (IsRecycleEncouragedItem(GetUsedHeldItem(battlerAtk)))
            score += WEAK_EFFECT;
        break;
    case EFFECT_BRICK_BREAK:
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_REFLECT)
            score += DECENT_EFFECT;
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_LIGHTSCREEN)
            score += DECENT_EFFECT;
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_AURORA_VEIL)
            score += DECENT_EFFECT;
        break;
    case EFFECT_SKILL_SWAP:
        if (gAbilitiesInfo[aiData->abilities[battlerDef]].aiRating > gAbilitiesInfo[aiData->abilities[battlerAtk]].aiRating)
            score += DECENT_EFFECT;
        break;
    case EFFECT_WORRY_SEED:
    case EFFECT_GASTRO_ACID:
    case EFFECT_SIMPLE_BEAM:
        if (IsAbilityOfRating(aiData->abilities[battlerDef], 5))
            score += DECENT_EFFECT;
        break;
    case EFFECT_ENTRAINMENT:
        if ((IsAbilityOfRating(aiData->abilities[battlerDef], 5) || gAbilitiesInfo[aiData->abilities[battlerAtk]].aiRating <= 0)
        && (aiData->abilities[battlerDef] != aiData->abilities[battlerAtk] && !(gStatuses3[battlerDef] & STATUS3_GASTRO_ACID)))
            score += DECENT_EFFECT;
        break;
    case EFFECT_IMPRISON:
        if (predictedMove != MOVE_NONE && HasMove(battlerAtk, predictedMove))
            score += DECENT_EFFECT;
        else if (gDisableStructs[battlerAtk].isFirstTurn == 0)
            score += WEAK_EFFECT;
        break;
    case EFFECT_REFRESH:
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY)
            score += DECENT_EFFECT;
        break;
    case EFFECT_PSYCHO_SHIFT:
        if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY)
            IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_BURN)
            IncreaseBurnScore(battlerAtk, battlerDef, move, &score);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_PARALYSIS)
            IncreaseParalyzeScore(battlerAtk, battlerDef, move, &score);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_SLEEP)
            IncreaseSleepScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_GRUDGE:
        break;
    case EFFECT_SNATCH:
        if (predictedMove != MOVE_NONE && gMovesInfo[predictedMove].snatchAffected)
            score += GOOD_EFFECT; // Steal move
        break;
    case EFFECT_MUD_SPORT:
        if (!HasMoveWithType(battlerAtk, TYPE_ELECTRIC) && HasMoveWithType(battlerDef, TYPE_ELECTRIC))
            score += WEAK_EFFECT;
        break;
    case EFFECT_WATER_SPORT:
        if (!HasMoveWithType(battlerAtk, TYPE_FIRE) && (HasMoveWithType(battlerDef, TYPE_FIRE)))
            score += WEAK_EFFECT;
        break;
    case EFFECT_TICKLE:
        if (gBattleMons[battlerDef].statStages[STAT_DEF] > 4 && HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL)
         && ShouldLowerDefense(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            score += DECENT_EFFECT;
        else if (ShouldLowerAttack(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            score += DECENT_EFFECT;
        break;
    case EFFECT_COSMIC_POWER:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF, &score);
        break;
    case EFFECT_BULK_UP:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF, &score);
        break;
    case EFFECT_CALM_MIND:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF, &score);
        break;
    case EFFECT_QUIVER_DANCE:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF, &score);
        break;
    case EFFECT_SHELL_SMASH:
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_RESTORE_STATS)
            score += WEAK_EFFECT;

        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK, &score);
        break;
    case EFFECT_DRAGON_DANCE:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK, &score);
        break;
    case EFFECT_GUARD_SWAP:
        if (gBattleMons[battlerDef].statStages[STAT_DEF] > gBattleMons[battlerAtk].statStages[STAT_DEF]
          && gBattleMons[battlerDef].statStages[STAT_SPDEF] >= gBattleMons[battlerAtk].statStages[STAT_SPDEF])
            score += DECENT_EFFECT;
        else if (gBattleMons[battlerDef].statStages[STAT_SPDEF] > gBattleMons[battlerAtk].statStages[STAT_SPDEF]
          && gBattleMons[battlerDef].statStages[STAT_DEF] >= gBattleMons[battlerAtk].statStages[STAT_DEF])
            score += DECENT_EFFECT;
        break;
    case EFFECT_POWER_SWAP:
        if (gBattleMons[battlerDef].statStages[STAT_ATK] > gBattleMons[battlerAtk].statStages[STAT_ATK]
          && gBattleMons[battlerDef].statStages[STAT_SPATK] >= gBattleMons[battlerAtk].statStages[STAT_SPATK])
            score += DECENT_EFFECT;
        else if (gBattleMons[battlerDef].statStages[STAT_SPATK] > gBattleMons[battlerAtk].statStages[STAT_SPATK]
          && gBattleMons[battlerDef].statStages[STAT_ATK] >= gBattleMons[battlerAtk].statStages[STAT_ATK])
            score += DECENT_EFFECT;
        break;
    case EFFECT_POWER_TRICK:
        if (!(gStatuses3[battlerAtk] & STATUS3_POWER_TRICK)
        && gBattleMons[battlerAtk].defense > gBattleMons[battlerAtk].attack
        && HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
            score += DECENT_EFFECT;
        break;
    case EFFECT_GUARD_SPLIT:
        {
            u32 newDefense = (gBattleMons[battlerAtk].defense + gBattleMons[battlerDef].defense) / 2;
            u32 newSpDef = (gBattleMons[battlerAtk].spDefense + gBattleMons[battlerDef].spDefense) / 2;

            if ((newDefense > gBattleMons[battlerAtk].defense && newSpDef >= gBattleMons[battlerAtk].spDefense)
            || (newSpDef > gBattleMons[battlerAtk].spDefense && newDefense >= gBattleMons[battlerAtk].defense))
                score += DECENT_EFFECT;
        }
        break;
    case EFFECT_POWER_SPLIT:
        {
            u32 newAttack = (gBattleMons[battlerAtk].attack + gBattleMons[battlerDef].attack) / 2;
            u32 newSpAtk = (gBattleMons[battlerAtk].spAttack + gBattleMons[battlerDef].spAttack) / 2;

            if ((newAttack > gBattleMons[battlerAtk].attack && newSpAtk >= gBattleMons[battlerAtk].spAttack)
            || (newSpAtk > gBattleMons[battlerAtk].spAttack && newAttack >= gBattleMons[battlerAtk].attack))
                score += DECENT_EFFECT;
        }
        break;
    case EFFECT_ELECTRIC_TERRAIN:
    case EFFECT_MISTY_TERRAIN:
        if (gStatuses3[battlerAtk] & STATUS3_YAWN && IsBattlerGrounded(battlerAtk))
            score += BEST_EFFECT;
    case EFFECT_GRASSY_TERRAIN:
    case EFFECT_PSYCHIC_TERRAIN:
        score += GOOD_EFFECT;
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_TERRAIN_EXTENDER)
            score += GOOD_EFFECT;
        break;
    case EFFECT_TRICK_ROOM:
        if (!(AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_POWERFUL_STATUS))
        {
            if (!(gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && GetBattlerSideSpeedAverage(battlerAtk) < GetBattlerSideSpeedAverage(battlerDef))
                score += GOOD_EFFECT;
            else if ((gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && GetBattlerSideSpeedAverage(battlerAtk) >= GetBattlerSideSpeedAverage(battlerDef))
                score += GOOD_EFFECT;
        }
        break;
    case EFFECT_MAGIC_ROOM:
        score += WEAK_EFFECT;
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_NONE && aiData->holdEffects[battlerDef] != HOLD_EFFECT_NONE)
            score += WEAK_EFFECT;
        if (isDoubleBattle && aiData->holdEffects[BATTLE_PARTNER(battlerAtk)] == HOLD_EFFECT_NONE && aiData->holdEffects[BATTLE_PARTNER(battlerDef)] != HOLD_EFFECT_NONE)
            score += WEAK_EFFECT;
        break;
    case EFFECT_WONDER_ROOM:
        if ((HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL) && gBattleMons[battlerAtk].defense < gBattleMons[battlerAtk].spDefense)
          || (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL) && gBattleMons[battlerAtk].spDefense < gBattleMons[battlerAtk].defense))
            score += DECENT_EFFECT;
        break;
    case EFFECT_GRAVITY:
        if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
        {
            if (HasSleepMoveWithLowAccuracy(battlerAtk, battlerDef)) // Has Gravity for a move like Hypnosis
                IncreaseSleepScore(battlerAtk, battlerDef, move, &score);
            if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, FALSE, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], aiData->holdEffects[battlerAtk], aiData->holdEffects[battlerDef]))
                score += DECENT_EFFECT;
        }
        break;
    case EFFECT_ION_DELUGE:
        if ((aiData->abilities[battlerAtk] == ABILITY_VOLT_ABSORB
          || aiData->abilities[battlerAtk] == ABILITY_MOTOR_DRIVE
          || aiData->abilities[battlerAtk] == ABILITY_LIGHTNING_ROD)
          && gMovesInfo[predictedMove].type == TYPE_NORMAL)
            score += DECENT_EFFECT;
        break;
    case EFFECT_FLING:
        /* TODO
        switch (gFlingTable[aiData->items[battlerAtk]].effect)
        {
        case MOVE_EFFECT_BURN:
            IncreaseBurnScore(battlerAtk, battlerDef, move, &score);
            break;
        case MOVE_EFFECT_FLINCH:
            score += ShouldTryToFlinch(battlerAtk, battlerDef, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], move);
            break;
        case MOVE_EFFECT_PARALYSIS:
            IncreaseParalyzeScore(battlerAtk, battlerDef, move, &score);
            break;
        case MOVE_EFFECT_POISON:
        case MOVE_EFFECT_TOXIC:
            IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
            break;
        case MOVE_EFFECT_FREEZE:
            if (AI_CanFreeze(battlerAtk, battlerDef))
                score += GOOD_EFFECT;
            break;
        }*/
        break;
    case EFFECT_EMBARGO:
        if (aiData->holdEffects[battlerDef] != HOLD_EFFECT_NONE)
            score += DECENT_EFFECT;
        break;
    case EFFECT_TELEKINESIS:
        if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, FALSE, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], aiData->holdEffects[battlerAtk], aiData->holdEffects[battlerDef])
          || !IsBattlerGrounded(battlerDef))
            score += DECENT_EFFECT;
        break;
    case EFFECT_HEAL_BLOCK:
        if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER && predictedMove != MOVE_NONE && IsHealingMove(predictedMove))
            score += DECENT_EFFECT; // Try to cancel healing move
        else if (HasHealingEffect(battlerDef) || aiData->holdEffects[battlerDef] == HOLD_EFFECT_LEFTOVERS
          || (aiData->holdEffects[battlerDef] == HOLD_EFFECT_BLACK_SLUDGE && IS_BATTLER_OF_TYPE(battlerDef, TYPE_POISON)))
            score += DECENT_EFFECT;
        break;
    case EFFECT_SOAK:
        if (HasMoveWithType(battlerAtk, TYPE_ELECTRIC) || HasMoveWithType(battlerAtk, TYPE_GRASS) || HasMoveEffect(battlerAtk, EFFECT_FREEZE_DRY))
            score += DECENT_EFFECT; // Get some super effective moves
        break;
    case EFFECT_QUASH:
        if (isDoubleBattle && AI_WhoStrikesFirst(BATTLE_PARTNER(battlerAtk), battlerDef, aiData->partnerMove) == AI_IS_SLOWER)
            score += DECENT_EFFECT; // Attacker partner wouldn't go before target
        break;
    case EFFECT_TAILWIND:
        if (GetBattlerSideSpeedAverage(battlerAtk) < GetBattlerSideSpeedAverage(battlerDef))
            score += GOOD_EFFECT;
        break;
    case EFFECT_LUCKY_CHANT:
        if (!isDoubleBattle && CountUsablePartyMons(battlerDef) > 0)
            score += GOOD_EFFECT;
        break;
    case EFFECT_MAGNET_RISE:
        if (IsBattlerGrounded(battlerAtk) && HasDamagingMoveOfType(battlerDef, TYPE_ELECTRIC)
          && !(AI_GetTypeEffectiveness(MOVE_EARTHQUAKE, battlerDef, battlerAtk) == AI_EFFECTIVENESS_x0)) // Doesn't resist ground move
        {
            if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER) // Attacker goes first
           {
                if (gMovesInfo[predictedMove].type == TYPE_GROUND)
                    score += GOOD_EFFECT; // Cause the enemy's move to fail
                break;
            }
            else // Opponent Goes First
            {
                if (HasDamagingMoveOfType(battlerDef, TYPE_GROUND))
                    score += DECENT_EFFECT;
                break;
            }
        }
        break;
    case EFFECT_CAMOUFLAGE:
        if (predictedMove != MOVE_NONE && AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER // Attacker goes first
         && !IS_MOVE_STATUS(move) && AI_GetTypeEffectiveness(predictedMove, battlerDef, battlerAtk) != AI_EFFECTIVENESS_x0)
            score += DECENT_EFFECT;
        break;
    case EFFECT_COUNTER:
        if ((!IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef]) && predictedMove != MOVE_NONE)
         && (GetNoOfHitsToKOBattler(battlerDef, battlerAtk, predictedMoveSlot) >= 2)
         && (gMovesInfo[predictedMove].category == DAMAGE_CATEGORY_PHYSICAL))
            score += GOOD_EFFECT;
        break;
    case EFFECT_MIRROR_COAT:
        if ((!IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef]) && predictedMove != MOVE_NONE)
         && (GetNoOfHitsToKOBattler(battlerDef, battlerAtk, predictedMoveSlot) >= 2)
         && (gMovesInfo[predictedMove].category == DAMAGE_CATEGORY_SPECIAL))
            score += GOOD_EFFECT;
        break;
    case EFFECT_FOCUS_PUNCH:
        if (!isDoubleBattle && effectiveness > AI_EFFECTIVENESS_x0_5)
        {
            if (IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef]))
                score += DECENT_EFFECT;
            if (gBattleMons[battlerDef].status2 & (STATUS2_INFATUATION | STATUS2_CONFUSION))
                score += DECENT_EFFECT;
        }
        break;
    case EFFECT_ENDEAVOR:
        if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_SLOWER && !CanTargetFaintAi(battlerDef, battlerAtk))
            score += DECENT_EFFECT;
        break;
    } // move effect checks

    // check move additional effects that are likely to happen
    for (i = 0; i < gMovesInfo[move].numAdditionalEffects; i++)
    {
        // Only consider effects with a guaranteed chance to happen
        if (!MoveEffectIsGuaranteed(battlerAtk, aiData->abilities[battlerAtk], &gMovesInfo[move].additionalEffects[i]))
            continue;

        // Consider move effects that target self
        if (gMovesInfo[move].additionalEffects[i].self)
        {
            u32 StageStatId;

            switch (gMovesInfo[move].additionalEffects[i].moveEffect)
            {
            case MOVE_EFFECT_ATK_PLUS_1:
            case MOVE_EFFECT_DEF_PLUS_1:
            case MOVE_EFFECT_SPD_PLUS_1:
            case MOVE_EFFECT_SP_ATK_PLUS_1:
            case MOVE_EFFECT_SP_DEF_PLUS_1:
                StageStatId = STAT_CHANGE_ATK + gMovesInfo[move].additionalEffects[i].moveEffect - MOVE_EFFECT_ATK_PLUS_1;
                IncreaseStatUpScore(battlerAtk, battlerDef, StageStatId, &score);
                break;
            case MOVE_EFFECT_ATK_PLUS_2:
            case MOVE_EFFECT_DEF_PLUS_2:
            case MOVE_EFFECT_SPD_PLUS_2:
            case MOVE_EFFECT_SP_ATK_PLUS_2:
            case MOVE_EFFECT_SP_DEF_PLUS_2:
                StageStatId = STAT_CHANGE_ATK_2 + gMovesInfo[move].additionalEffects[i].moveEffect - MOVE_EFFECT_ATK_PLUS_1;
                IncreaseStatUpScore(battlerAtk, battlerDef, StageStatId, &score);
                break;
            case MOVE_EFFECT_ACC_PLUS_1:
            case MOVE_EFFECT_ACC_PLUS_2:
                IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ACC, &score);
                break;
            case MOVE_EFFECT_EVS_PLUS_1:
            case MOVE_EFFECT_EVS_PLUS_2:
                IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_EVASION, &score);
                break;
            case MOVE_EFFECT_RAPID_SPIN:
                if ((gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_HAZARDS_ANY && CountUsablePartyMons(battlerAtk) != 0)
                || (gStatuses3[battlerAtk] & STATUS3_LEECHSEED || gBattleMons[battlerAtk].status2 & STATUS2_WRAPPED))
                    score += GOOD_EFFECT;
                break;
            }
        }
        else // consider move effects that hinder the target
        {
            switch (gMovesInfo[move].additionalEffects[i].moveEffect)
            {
                case MOVE_EFFECT_FLINCH:
                    score += ShouldTryToFlinch(battlerAtk, battlerDef, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], move);
                    break;
                case MOVE_EFFECT_SPD_MINUS_1:
                case MOVE_EFFECT_SPD_MINUS_2:
                    if (!ShouldLowerSpeed(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
                        break;
                case MOVE_EFFECT_ATK_MINUS_1:
                case MOVE_EFFECT_DEF_MINUS_1:
                case MOVE_EFFECT_SP_ATK_MINUS_1:
                case MOVE_EFFECT_SP_DEF_MINUS_1:
                case MOVE_EFFECT_ACC_MINUS_1:
                case MOVE_EFFECT_EVS_MINUS_1:
                    score += DECENT_EFFECT;
                    break;
                case MOVE_EFFECT_ATK_MINUS_2:
                case MOVE_EFFECT_DEF_MINUS_2:
                case MOVE_EFFECT_SP_ATK_MINUS_2:
                case MOVE_EFFECT_SP_DEF_MINUS_2:
                case MOVE_EFFECT_ACC_MINUS_2:
                case MOVE_EFFECT_EVS_MINUS_2:
                    score += DECENT_EFFECT;
                    break;
                case MOVE_EFFECT_POISON:
                    IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
                    break;
                case MOVE_EFFECT_CLEAR_SMOG:
                    score += AI_TryToClearStats(battlerAtk, battlerDef, FALSE);
                    break;
                case MOVE_EFFECT_BUG_BITE:   // And pluck
                    if (gBattleMons[battlerDef].status2 & STATUS2_SUBSTITUTE || aiData->abilities[battlerDef] == ABILITY_STICKY_HOLD)
                        break;
                    else if (ItemId_GetPocket(aiData->items[battlerDef]) == POCKET_BERRIES)
                        score += DECENT_EFFECT;
                    break;
                case MOVE_EFFECT_SMACK_DOWN:
                    if (!IsBattlerGrounded(battlerDef) && HasDamagingMoveOfType(battlerAtk, TYPE_GROUND) && !CanTargetFaintAi(battlerDef, battlerAtk))
                        score += DECENT_EFFECT;
                    break;
                case MOVE_EFFECT_KNOCK_OFF:
                    if (CanKnockOffItem(battlerDef, aiData->items[battlerDef]))
                    {
                        switch (aiData->holdEffects[battlerDef])
                        {
                        case HOLD_EFFECT_IRON_BALL:
                            if (HasMoveEffect(battlerDef, EFFECT_FLING))
                                score += DECENT_EFFECT;
                            break;
                        case HOLD_EFFECT_LAGGING_TAIL:
                        case HOLD_EFFECT_STICKY_BARB:
                            break;
                        default:
                            score += DECENT_EFFECT;
                            break;
                        }
                    }
                    break;
                case MOVE_EFFECT_STEAL_ITEM:
                    {
                        if (aiData->items[battlerAtk] == ITEM_NONE
                        && aiData->items[battlerDef] != ITEM_NONE
                        && CanBattlerGetOrLoseItem(battlerDef, aiData->items[battlerDef])
                        && CanBattlerGetOrLoseItem(battlerAtk, aiData->items[battlerDef])
                        && !HasMoveEffect(battlerAtk, EFFECT_ACROBATICS)
                        && aiData->abilities[battlerDef] != ABILITY_STICKY_HOLD)
                        {
                            switch (aiData->holdEffects[battlerDef])
                            {
                            case HOLD_EFFECT_NONE:
                                break;
                            case HOLD_EFFECT_CHOICE_BAND:
                            case HOLD_EFFECT_CHOICE_SCARF:
                            case HOLD_EFFECT_CHOICE_SPECS:
                                score += DECENT_EFFECT;
                                break;
                            case HOLD_EFFECT_TOXIC_ORB:
                                if (ShouldPoisonSelf(battlerAtk, aiData->abilities[battlerAtk]))
                                    score += DECENT_EFFECT;
                                break;
                            case HOLD_EFFECT_FLAME_ORB:
                                if (ShouldBurnSelf(battlerAtk, aiData->abilities[battlerAtk]))
                                    score += DECENT_EFFECT;
                                break;
                            case HOLD_EFFECT_BLACK_SLUDGE:
                                if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_POISON))
                                    score += DECENT_EFFECT;
                                break;
                            case HOLD_EFFECT_IRON_BALL:
                                if (HasMoveEffect(battlerAtk, EFFECT_FLING))
                                    score += DECENT_EFFECT;
                                break;
                            case HOLD_EFFECT_LAGGING_TAIL:
                            case HOLD_EFFECT_STICKY_BARB:
                                break;
                            default:
                                score += WEAK_EFFECT;
                                break;
                            }
                        }
                        break;
                    }
                    break;
                case MOVE_EFFECT_FEINT:
                    if (gMovesInfo[predictedMove].effect == EFFECT_PROTECT)
                        score += GOOD_EFFECT;
                    break;
                case MOVE_EFFECT_WRAP:
                    if (!HasMoveWithAdditionalEffect(battlerDef, MOVE_EFFECT_RAPID_SPIN) && ShouldTrap(battlerAtk, battlerDef, move))
                        score += BEST_EFFECT;
                    break;
            }
        }
    }

    if (score <= 1)
        return NOT_GOOD_ENOUGH;
    else if (score <= 3)
        return GOOD_MOVE_EFFECTS;
    else if (score <= 5)
        return PREFERRED_MOVE_EFFECTS;
    else
        return BEST_MOVE_EFFECTS;
}

// AI_FLAG_CHECK_VIABILITY - Chooses best possible move to hit player
static s32 AI_CheckViability(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    // Targeting partner, check benefits of doing that instead
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        return score;

    if (gMovesInfo[move].power)
    {
        if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex) == 0)
            score -= 20;
        else
            score += AI_CompareDamagingMoves(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex);
    }

    score += AI_CalcMoveEffectScore(battlerAtk, battlerDef, move);

    return score;
}

// Effects that are encouraged on the first turn of battle
static s32 AI_SetupFirstTurn(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u8 i;
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef)
      || gBattleResults.battleTurnCounter != 0)
        return score;

    if (AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_SMART_SWITCHING
      && AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_SLOWER
      && CanTargetFaintAi(battlerDef, battlerAtk)
      && GetMovePriority(battlerAtk, move) == 0)
    {
        RETURN_SCORE_MINUS(20);    // No point in setting up if you will faint. Should just switch if possible..
    }

    // check effects to prioritize first turn
    switch (gMovesInfo[move].effect)
    {
    case EFFECT_ATTACK_UP:
    case EFFECT_DEFENSE_UP:
    case EFFECT_SPEED_UP:
    case EFFECT_SPECIAL_ATTACK_UP:
    case EFFECT_SPECIAL_DEFENSE_UP:
    case EFFECT_ACCURACY_UP:
    case EFFECT_EVASION_UP:
    case EFFECT_ATTACK_DOWN:
    case EFFECT_DEFENSE_DOWN:
    case EFFECT_SPEED_DOWN:
    case EFFECT_SPECIAL_ATTACK_DOWN:
    case EFFECT_SPECIAL_DEFENSE_DOWN:
    case EFFECT_ACCURACY_DOWN:
    case EFFECT_EVASION_DOWN:
    case EFFECT_CONVERSION:
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_FOCUS_ENERGY:
    case EFFECT_CONFUSE:
    case EFFECT_ATTACK_UP_2:
    case EFFECT_DEFENSE_UP_2:
    case EFFECT_SPEED_UP_2:
    case EFFECT_SPECIAL_ATTACK_UP_2:
    case EFFECT_SPECIAL_ATTACK_UP_3:
    case EFFECT_SPECIAL_DEFENSE_UP_2:
    case EFFECT_ACCURACY_UP_2:
    case EFFECT_EVASION_UP_2:
    case EFFECT_ATTACK_DOWN_2:
    case EFFECT_DEFENSE_DOWN_2:
    case EFFECT_SPEED_DOWN_2:
    case EFFECT_SPECIAL_ATTACK_DOWN_2:
    case EFFECT_SPECIAL_DEFENSE_DOWN_2:
    case EFFECT_ACCURACY_DOWN_2:
    case EFFECT_EVASION_DOWN_2:
    case EFFECT_REFLECT:
    case EFFECT_POISON:
    case EFFECT_PARALYZE:
    case EFFECT_SUBSTITUTE:
    case EFFECT_LEECH_SEED:
    case EFFECT_MINIMISE:
    case EFFECT_CURSE:
    case EFFECT_SWAGGER:
    case EFFECT_CAMOUFLAGE:
    case EFFECT_YAWN:
    case EFFECT_DEFENSE_CURL:
    case EFFECT_TORMENT:
    case EFFECT_FLATTER:
    case EFFECT_WILL_O_WISP:
    case EFFECT_INGRAIN:
    case EFFECT_IMPRISON:
    case EFFECT_TICKLE:
    case EFFECT_COSMIC_POWER:
    case EFFECT_BULK_UP:
    case EFFECT_CALM_MIND:
    case EFFECT_ACUPRESSURE:
    case EFFECT_AUTOTOMISE:
    case EFFECT_SHELL_SMASH:
    case EFFECT_GROWTH:
    case EFFECT_QUIVER_DANCE:
    case EFFECT_ATTACK_SPATK_UP:
    case EFFECT_ATTACK_ACCURACY_UP:
    case EFFECT_PSYCHIC_TERRAIN:
    case EFFECT_GRASSY_TERRAIN:
    case EFFECT_ELECTRIC_TERRAIN:
    case EFFECT_MISTY_TERRAIN:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_TOXIC_SPIKES:
    case EFFECT_TRICK_ROOM:
    case EFFECT_WONDER_ROOM:
    case EFFECT_MAGIC_ROOM:
    case EFFECT_TAILWIND:
    case EFFECT_DRAGON_DANCE:
    case EFFECT_RAIN_DANCE:
    case EFFECT_SUNNY_DAY:
    case EFFECT_SANDSTORM:
    case EFFECT_HAIL:
        score += DECENT_EFFECT;
        break;
    default:
        break;
    }

    return score;
}

// Adds score bonus to 'riskier' move effects and high crit moves
static s32 AI_Risky(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u8 i;
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        return score;

    if (gMovesInfo[move].criticalHitStage > 0)
        score += DECENT_EFFECT;

    switch (gMovesInfo[move].effect)
    {
    case EFFECT_SLEEP:
    case EFFECT_EXPLOSION:
    case EFFECT_MIRROR_MOVE:
    case EFFECT_OHKO:
    case EFFECT_CONFUSE:
    case EFFECT_METRONOME:
    case EFFECT_PSYWAVE:
    case EFFECT_COUNTER:
    case EFFECT_DESTINY_BOND:
    case EFFECT_SWAGGER:
    case EFFECT_ATTRACT:
    case EFFECT_PRESENT:
    case EFFECT_BELLY_DRUM:
    case EFFECT_MIRROR_COAT:
    case EFFECT_FOCUS_PUNCH:
    case EFFECT_REVENGE:
        if (Random() & 1)
            score += DECENT_EFFECT;
        break;
    case EFFECT_HIT:
    {
        // TEMPORARY - should applied to all moves regardless of EFFECT
        // Consider move effects
        for (i = 0; i < gMovesInfo[move].numAdditionalEffects; i++)
        {
            switch (gMovesInfo[move].additionalEffects[i].moveEffect)
            {
                case MOVE_EFFECT_ALL_STATS_UP:
                    if (Random() & 1)
                        score += DECENT_EFFECT;
                    break;
                default:
                    break;
            }
        }
    }
    default:
        break;
    }

    return score;
}

// Adds score bonus to best powered move
static s32 AI_PreferStrongestMove(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        return score;

    if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex) == 1)
        score += BEST_EFFECT;
    else if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex) == 2)
        score += DECENT_EFFECT;

    return score;
}

// Prefers moves that are good for baton pass
static s32 AI_PreferBatonPass(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef)
      || CountUsablePartyMons(battlerAtk) == 0
      || gMovesInfo[move].power != 0
      || !HasMoveEffect(battlerAtk, EFFECT_BATON_PASS)
      || IsBattlerTrapped(battlerAtk, TRUE))
        return score;

    if (IsStatRaisingEffect(gMovesInfo[move].effect))
    {
        if (gBattleResults.battleTurnCounter == 0)
            score += GOOD_EFFECT;
        else if (AI_DATA->hpPercents[battlerAtk] < 60)
            score -= 10;
        else
            score += WEAK_EFFECT;
    }

    // other specific checks
    switch (gMovesInfo[move].effect)
    {
    case EFFECT_INGRAIN:
        if (!(gStatuses3[battlerAtk] & STATUS3_ROOTED))
            score += DECENT_EFFECT;
        break;
    case EFFECT_AQUA_RING:
        if (!(gStatuses3[battlerAtk] & STATUS3_AQUA_RING))
            score += DECENT_EFFECT;
        break;
    case EFFECT_PROTECT:
        if (gLastMoves[battlerAtk] == MOVE_PROTECT || gLastMoves[battlerAtk] == MOVE_DETECT)
            score -= 2;
        else
            score += DECENT_EFFECT;
        break;
    case EFFECT_BATON_PASS:
        // TODO: Increase Score based on current stats.
        if (gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_AQUA_RING))
            score += DECENT_EFFECT;
        if (gStatuses3[battlerAtk] & STATUS3_LEECHSEED)
            score -= 3;
        break;
    default:
        break;
    }

    return score;
}

static s32 AI_HPAware(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u32 effect = gMovesInfo[move].effect;
    u32 moveType = gMovesInfo[move].type;

    SetTypeBeforeUsingMove(move, battlerAtk);
    GET_MOVE_TYPE(move, moveType);

    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
    {
        if (effect == EFFECT_HEAL_PULSE
         || (moveType == TYPE_ELECTRIC && AI_DATA->abilities[BATTLE_PARTNER(battlerAtk)] == ABILITY_VOLT_ABSORB)
         || (moveType == TYPE_WATER && (AI_DATA->abilities[BATTLE_PARTNER(battlerAtk)] == ABILITY_DRY_SKIN || AI_DATA->abilities[BATTLE_PARTNER(battlerAtk)] == ABILITY_WATER_ABSORB)))
        {
            if (gStatuses3[battlerDef] & STATUS3_HEAL_BLOCK)
                return 0;

            if (CanTargetFaintAi(FOE(battlerAtk), BATTLE_PARTNER(battlerAtk))
              || (CanTargetFaintAi(BATTLE_PARTNER(FOE(battlerAtk)), BATTLE_PARTNER(battlerAtk))))
                score -= 1;

            if (AI_DATA->hpPercents[battlerDef] <= 50)
                score += WEAK_EFFECT;
        }
    }
    else
    {
        // Consider AI HP
        if (AI_DATA->hpPercents[battlerAtk] > 70)
        {
            // high hp
            switch (effect)
            {
            case EFFECT_EXPLOSION:
            case EFFECT_RESTORE_HP:
            case EFFECT_REST:
            case EFFECT_DESTINY_BOND:
            case EFFECT_FLAIL:
            case EFFECT_ENDURE:
            case EFFECT_MORNING_SUN:
            case EFFECT_SYNTHESIS:
            case EFFECT_MOONLIGHT:
            case EFFECT_SOFTBOILED:
            case EFFECT_ROOST:
            case EFFECT_MEMENTO:
            case EFFECT_GRUDGE:
                score -= 2;
                break;
            default:
                break;
            }
        }
        else if (AI_DATA->hpPercents[battlerAtk] > 30)
        {
            // med hp
            if (IsStatRaisingEffect(effect) || IsStatLoweringEffect(effect))
                score -= 2;

            switch (effect)
            {
            case EFFECT_EXPLOSION:
            case EFFECT_BIDE:
            case EFFECT_CONVERSION:
            case EFFECT_LIGHT_SCREEN:
            case EFFECT_MIST:
            case EFFECT_FOCUS_ENERGY:
            case EFFECT_CONVERSION_2:
            case EFFECT_SAFEGUARD:
            case EFFECT_BELLY_DRUM:
                score -= 2;
                break;
            default:
                break;
            }
        }
        else
        {
            // low hp
            if (IsStatRaisingEffect(effect) || IsStatLoweringEffect(effect))
                score -= 2;

            // check other discouraged low hp effects
            switch (effect)
            {
            case EFFECT_BIDE:
            case EFFECT_CONVERSION:
            case EFFECT_REFLECT:
            case EFFECT_LIGHT_SCREEN:
            case EFFECT_AURORA_VEIL:
            case EFFECT_MIST:
            case EFFECT_FOCUS_ENERGY:
            case EFFECT_RAGE:
            case EFFECT_CONVERSION_2:
            case EFFECT_LOCK_ON:
            case EFFECT_SAFEGUARD:
            case EFFECT_BELLY_DRUM:
            case EFFECT_PSYCH_UP:
            case EFFECT_MIRROR_COAT:
            case EFFECT_TICKLE:
            case EFFECT_SUNNY_DAY:
            case EFFECT_SANDSTORM:
            case EFFECT_HAIL:
            case EFFECT_RAIN_DANCE:
                score -= 2;
                break;
            default:
                break;
            }
        }
    }

    // consider target HP
    if (CanIndexMoveFaintTarget(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex, 0))
    {
        score += DECENT_EFFECT;
    }
    else
    {
        if (AI_DATA->hpPercents[battlerDef] > 70)
        {
            // high HP
            ; // nothing yet
        }
        else if (AI_DATA->hpPercents[battlerDef] > 30)
        {
            // med HP - check discouraged effects
            switch (effect)
            {
            case EFFECT_ATTACK_UP:
            case EFFECT_DEFENSE_UP:
            case EFFECT_SPEED_UP:
            case EFFECT_SPECIAL_ATTACK_UP:
            case EFFECT_SPECIAL_DEFENSE_UP:
            case EFFECT_ACCURACY_UP:
            case EFFECT_EVASION_UP:
            case EFFECT_ATTACK_DOWN:
            case EFFECT_DEFENSE_DOWN:
            case EFFECT_SPEED_DOWN:
            case EFFECT_SPECIAL_ATTACK_DOWN:
            case EFFECT_SPECIAL_DEFENSE_DOWN:
            case EFFECT_ACCURACY_DOWN:
            case EFFECT_EVASION_DOWN:
            case EFFECT_MIST:
            case EFFECT_FOCUS_ENERGY:
            case EFFECT_ATTACK_UP_2:
            case EFFECT_DEFENSE_UP_2:
            case EFFECT_SPEED_UP_2:
            case EFFECT_SPECIAL_ATTACK_UP_2:
            case EFFECT_SPECIAL_DEFENSE_UP_2:
            case EFFECT_ACCURACY_UP_2:
            case EFFECT_EVASION_UP_2:
            case EFFECT_ATTACK_DOWN_2:
            case EFFECT_DEFENSE_DOWN_2:
            case EFFECT_SPEED_DOWN_2:
            case EFFECT_SPECIAL_ATTACK_DOWN_2:
            case EFFECT_SPECIAL_DEFENSE_DOWN_2:
            case EFFECT_ACCURACY_DOWN_2:
            case EFFECT_EVASION_DOWN_2:
            case EFFECT_POISON:
            case EFFECT_PAIN_SPLIT:
            case EFFECT_PERISH_SONG:
            case EFFECT_SAFEGUARD:
            case EFFECT_TICKLE:
            case EFFECT_COSMIC_POWER:
            case EFFECT_BULK_UP:
            case EFFECT_CALM_MIND:
            case EFFECT_DRAGON_DANCE:
            case EFFECT_SPECIAL_ATTACK_UP_3:
                score -= 2;
                break;
            default:
                break;
            }
        }
        else
        {
            // low HP
            if (IS_MOVE_STATUS(move))
                score -= 2; // don't use status moves if target is at low health
        }
    }

    return score;
}

static s32 AI_PowerfulStatus(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u32 moveEffect = gMovesInfo[move].effect;

    if (gMovesInfo[move].category != DAMAGE_CATEGORY_STATUS || gMovesInfo[AI_DATA->partnerMove].effect == moveEffect)
        return score;

    switch (moveEffect)
    {
    case EFFECT_TAILWIND:
        if (!gSideTimers[GetBattlerSide(battlerAtk)].tailwindTimer && !(gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer > 1))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_TRICK_ROOM:
        if (!(gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && !HasMoveEffect(battlerDef, EFFECT_TRICK_ROOM))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_MAGIC_ROOM:
        if (!(gFieldStatuses & STATUS_FIELD_MAGIC_ROOM) && !HasMoveEffect(battlerDef, EFFECT_MAGIC_ROOM))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_WONDER_ROOM:
        if (!(gFieldStatuses & STATUS_FIELD_WONDER_ROOM) && !HasMoveEffect(battlerDef, EFFECT_WONDER_ROOM))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_GRAVITY:
        if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_SAFEGUARD:
        if (!(gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_SAFEGUARD))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_MIST:
        if (!(gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_MIST))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_REFLECT:
    case EFFECT_AURORA_VEIL:
        if (ShouldSetScreen(battlerAtk, battlerDef, moveEffect))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_SPIKES:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_TOXIC_SPIKES:
        if (AI_ShouldSetUpHazards(battlerAtk, battlerDef, AI_DATA))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_GRASSY_TERRAIN:
        if (!(gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_ELECTRIC_TERRAIN:
        if (!(gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_PSYCHIC_TERRAIN:
        if (!(gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_MISTY_TERRAIN:
        if (!(gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_SANDSTORM:
        if (!(AI_GetWeather(AI_DATA) & B_WEATHER_SANDSTORM))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_SUNNY_DAY:
        if (!(AI_GetWeather(AI_DATA) & B_WEATHER_SUN))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_RAIN_DANCE:
        if (!(AI_GetWeather(AI_DATA) & B_WEATHER_RAIN))
            score += POWERFUL_STATUS_MOVE;
        break;
    case EFFECT_HAIL:
        if (!(AI_GetWeather(AI_DATA) & B_WEATHER_HAIL))
            score += POWERFUL_STATUS_MOVE;
        break;
    }

    return score;
}

static void AI_Flee(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_FLEE | AI_ACTION_DO_NOT_ATTACK);
}

static void AI_Watch(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_WATCH | AI_ACTION_DO_NOT_ATTACK);
}

// Roaming pokemon logic
static s32 AI_Roaming(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    if (IsBattlerTrapped(battlerAtk, FALSE))
        return score;

    AI_Flee();
    return score;
}

// Safari pokemon logic
static s32 AI_Safari(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u32 safariFleeRate = gBattleStruct->safariEscapeFactor * 5; // Safari flee rate, from 0-20.

    if ((Random() % 100) < safariFleeRate)
        AI_Flee();
    else
        AI_Watch();

    return score;
}
