#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_tower.h"
#include "battle_setup.h"
#include "ereader_helpers.h"
#include "event_data.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_message_box.h"
#include "international_string_util.h"
#include "item.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_tower.h"
#include "window.h"
#include "util.h"
#include "constants/battle_ai.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/trainer_tower.h"
#include "constants/trainer_types.h"

#define TOWER_MAX_TIME 215999 // 60 * 60 * 60 - 1

struct FloorTrainers
{
    u8 name[TOWER_TRAINERS_PER_FLOOR][TRAINER_NAME_LENGTH + 1];
    u8 facilityClass[TOWER_TRAINERS_PER_FLOOR];
};

static EWRAM_DATA struct {
    u8 floorId;
    struct TrainerTowerChallenge challenge;
    struct TrainerTowerFloor floors[NUM_TRAINER_TOWER_FLOORS];
} *sTowerData = NULL;

static EWRAM_DATA struct FloorTrainers *sFloorTrainers = NULL;
EWRAM_DATA u32 *gTrainerTowerVBlankCounter = NULL;

// This file's functions.
static void TrainerTowerStartChallenge(void);
static void GetOwnerState(void);
static void GiveChallengePrize(void);
static void CheckFinalTime(void);
static void TrainerTowerResumeTimer(void);
static void TrainerTowerSetPlayerLost(void);
static void TrainerTowerGetChallengeStatus(void);
static void BufferChallengeTime(void);
static void GetAllFloorsUsed(void);
static void GetInEReaderMode(void);
static void IsTrainerTowerChallengeActive(void);
static void ShowTrainerTowerPostBattleText(void);
static void SetAllTrainerFlags(void);
static void GetGameSaved(void);
static void SetGameSaved(void);
static void ClearGameSaved(void);
static void GetChallengeWon(void);
static void TrainerTowerSetMode(void);
static void SetUpDataStruct(void);
static void FreeDataStruct(void);
static void TrainerTowerDummy(void);
static void SetTimerValue(u32 *dst, u32 val);
static u32 GetTimerValue(u32 *src);
static void SetTrainerTowerMonLevel(struct Pokemon *mon, u8 level);
static u16 GetPrizeItemId(void);

// const data
#include "data/battle_frontier/trainer_tower.h"

struct
{
    u8 trainerClass;
    u8 musicId;
} static const sTrainerClassesAndMusic[] =
{
    {TRAINER_CLASS_TEAM_AQUA, TRAINER_ENCOUNTER_MUSIC_AQUA},
    {TRAINER_CLASS_AQUA_ADMIN, TRAINER_ENCOUNTER_MUSIC_AQUA},
    {TRAINER_CLASS_AQUA_LEADER, TRAINER_ENCOUNTER_MUSIC_AQUA},
    {TRAINER_CLASS_AROMA_LADY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_BATTLE_GIRL, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_SWIMMER_F, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_POKEFAN, TRAINER_ENCOUNTER_MUSIC_TWINS},
    {TRAINER_CLASS_DRAGON_TAMER, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_COOLTRAINER, TRAINER_ENCOUNTER_MUSIC_COOL},
    {TRAINER_CLASS_GUITARIST, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_SAILOR, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_TWINS, TRAINER_ENCOUNTER_MUSIC_TWINS},
    {TRAINER_CLASS_INTERVIEWER, TRAINER_ENCOUNTER_MUSIC_INTERVIEWER},
    {TRAINER_CLASS_RUIN_MANIAC, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_GENTLEMAN, TRAINER_ENCOUNTER_MUSIC_RICH},
    {TRAINER_CLASS_SWIMMER_M, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_POKEMANIAC, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_BLACK_BELT, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_OLD_COUPLE, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_BUG_MANIAC, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_CAMPER, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_KINDLER, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_TEAM_MAGMA, TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {TRAINER_CLASS_MAGMA_ADMIN, TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {TRAINER_CLASS_MAGMA_LEADER, TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {TRAINER_CLASS_LASS, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_BUG_CATCHER, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_NINJA_BOY, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_RICH_BOY, TRAINER_ENCOUNTER_MUSIC_RICH},
    {TRAINER_CLASS_HEX_MANIAC, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_BEAUTY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_LADY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_PARASOL_LADY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_PICNICKER, TRAINER_ENCOUNTER_MUSIC_GIRL},
    {TRAINER_CLASS_PKMN_BREEDER, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_COLLECTOR, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_PKMN_RANGER, TRAINER_ENCOUNTER_MUSIC_COOL},
    {TRAINER_CLASS_RIVAL, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_YOUNG_COUPLE, TRAINER_ENCOUNTER_MUSIC_GIRL},
    {TRAINER_CLASS_PSYCHIC, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_SR_AND_JR, TRAINER_ENCOUNTER_MUSIC_TWINS},
    {TRAINER_CLASS_ELITE_FOUR, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_YOUNGSTER, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_EXPERT, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_TRIATHLETE, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_BIRD_KEEPER, TRAINER_ENCOUNTER_MUSIC_COOL},
    {TRAINER_CLASS_FISHERMAN, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_CHAMPION, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_TUBER_M, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_TUBER_F, TRAINER_ENCOUNTER_MUSIC_GIRL},
    {TRAINER_CLASS_SIS_AND_BRO, TRAINER_ENCOUNTER_MUSIC_SWIMMER},
    {TRAINER_CLASS_HIKER, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_LEADER, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_SCHOOL_KID, TRAINER_ENCOUNTER_MUSIC_MALE},
};

static const u16 sPrizeListRareCandy1[]  = {ITEM_RARE_CANDY,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListLuxuryBall1[] = {ITEM_LUXURY_BALL,      ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxRevive1[]  = {ITEM_MAX_REVIVE,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxEther1[]   = {ITEM_MAX_ETHER,        ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListElixir1[]     = {ITEM_ELIXIR,           ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListRoar[]        = {ITEM_TM05_ROAR,        ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListSludgeBomb[]  = {ITEM_TM36_SLUDGE_BOMB, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListToxic[]       = {ITEM_TM06_TOXIC,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListSunnyDay[]    = {ITEM_TM11_SUNNY_DAY,   ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListEarthQuake[]  = {ITEM_TM26_EARTHQUAKE,  ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};

static const u16 sPrizeListRareCandy2[]  = {ITEM_RARE_CANDY,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListLuxuryBall2[] = {ITEM_LUXURY_BALL,      ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxRevive2[]  = {ITEM_MAX_REVIVE,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxEther2[]   = {ITEM_MAX_ETHER,        ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListElixir2[]     = {ITEM_ELIXIR,           ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListBrickBreak[]  = {ITEM_TM31_BRICK_BREAK, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListTorment[]     = {ITEM_TM41_TORMENT,     ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListRound[]       = {ITEM_TM48_ROUND,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListRoost[]       = {ITEM_TM19_ROOST,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};
static const u16 sPrizeListAttract[]     = {ITEM_TM45_ATTRACT,     ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_POKE_DOLL, ITEM_GREAT_BALL};

static const u16 *const sPrizeLists1[NUM_TRAINER_TOWER_PRIZE_LISTS] =
{
    sPrizeListRareCandy1,
    sPrizeListLuxuryBall1,
    sPrizeListMaxRevive1,
    sPrizeListMaxEther1,
    sPrizeListElixir1,
    sPrizeListRoar,
    sPrizeListSludgeBomb,
    sPrizeListToxic,
    sPrizeListSunnyDay,
    sPrizeListEarthQuake
};

static const u16 *const sPrizeLists2[NUM_TRAINER_TOWER_PRIZE_LISTS] =
{
    sPrizeListRareCandy2,
    sPrizeListLuxuryBall2,
    sPrizeListMaxRevive2,
    sPrizeListMaxEther2,
    sPrizeListElixir2,
    sPrizeListBrickBreak,
    sPrizeListTorment,
    sPrizeListRound,
    sPrizeListRoost,
    sPrizeListAttract
};

static const u16 *const *const sPrizeListSets[] =
{
    sPrizeLists1,
    sPrizeLists2
};

static const u16 sEReader_Pal[] = INCBIN_U16("graphics/trainer_tower/ereader.gbapal");
static const u8 sRecordWinColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

static const struct TrainerTowerChallenge *const sChallengeData[NUM_TRAINER_TOWER_MODES] =
{
    [TOWER_MODE_NORMAL]  = &sChallenge_Normal,
    [TOWER_MODE_VARIETY] = &sChallenge_Variety,
    [TOWER_MODE_UNIQUE]  = &sChallenge_Unique,
    [TOWER_MODE_EXPERT]  = &sChallenge_Expert,
};

// Unused.
static const u8 *const sFloorStrings[] =
{
    gText_TrainerTower1F,
    gText_TrainerTower2F,
    gText_TrainerTower3F,
    gText_TrainerTower4F,
};

static void (* const sTowerFunctions[])(void) =
{
    [TRAINER_TOWER_FUNC_START]                 = TrainerTowerStartChallenge,
    [TRAINER_TOWER_FUNC_GET_OWNER_STATE]       = GetOwnerState,
    [TRAINER_TOWER_FUNC_GIVE_PRIZE]            = GiveChallengePrize,
    [TRAINER_TOWER_FUNC_CHECK_FINAL_TIME]      = CheckFinalTime,
    [TRAINER_TOWER_FUNC_RESUME_TIMER]          = TrainerTowerResumeTimer,
    [TRAINER_TOWER_FUNC_SET_LOST]              = TrainerTowerSetPlayerLost,
    [TRAINER_TOWER_FUNC_GET_CHALLENGE_STATUS]  = TrainerTowerGetChallengeStatus,
    [TRAINER_TOWER_FUNC_GET_CHALLENGE_TIME]    = BufferChallengeTime,
    [TRAINER_TOWER_FUNC_GET_ALL_FLOORS_USED]   = GetAllFloorsUsed,
    [TRAINER_TOWER_FUNC_GET_IN_EREADER_MODE]   = GetInEReaderMode,
    [TRAINER_TOWER_FUNC_IN_CHALLENGE]          = IsTrainerTowerChallengeActive,
    [TRAINER_TOWER_FUNC_POST_BATTLE_TEXT]      = ShowTrainerTowerPostBattleText,
    [TRAINER_TOWER_FUNC_SET_ALL_TRAINER_FLAGS] = SetAllTrainerFlags,
    [TRAINER_TOWER_FUNC_GET_GAME_SAVED]        = GetGameSaved,
    [TRAINER_TOWER_FUNC_SET_GAME_SAVED]        = SetGameSaved,
    [TRAINER_TOWER_FUNC_CLEAR_GAME_SAVED]      = ClearGameSaved,
    [TRAINER_TOWER_FUNC_GET_WON]               = GetChallengeWon,
    [TRAINER_TOWER_FUNC_SET_MODE]              = TrainerTowerSetMode,
};

static const u8 *const sModeStrings[NUM_TRAINER_TOWER_MODES] =
{
    [TOWER_MODE_NORMAL]  = gText_NormalTagMatch,
    [TOWER_MODE_VARIETY] = gText_VarietyTagMatch,
    [TOWER_MODE_UNIQUE]  = gText_UniqueTagMatch,
    [TOWER_MODE_EXPERT]  = gText_ExpertTagMatch,
};

static const struct ObjectEventTemplate sTrainerObjectEventTemplate =
{
    .graphicsId = OBJ_EVENT_GFX_RED_NORMAL,
    .elevation = 3,
    .movementType = MOVEMENT_TYPE_LOOK_AROUND,
    .movementRangeX = 1,
    .movementRangeY = 1,
    .trainerType = TRAINER_TYPE_NORMAL,
};

static const u32 sNextFloorMapNum[NUM_TRAINER_TOWER_FLOORS] =
{
    [TRAINER_TOWER_1F - 1] = MAP_NUM(TRAINER_TOWER_2F),
    [TRAINER_TOWER_2F - 1] = MAP_NUM(TRAINER_TOWER_3F),
    [TRAINER_TOWER_3F - 1] = MAP_NUM(TRAINER_TOWER_4F),
    [TRAINER_TOWER_4F - 1] = MAP_NUM(TRAINER_TOWER_ROOF)
};
static const u8 sTrainerPartySlots[TOWER_TRAINERS_PER_FLOOR][PARTY_SIZE / 2] =
{
    {0, 1, 2},
    {3, 4, 5}
};

void CallTrainerTowerFunction(void)
{
    SetUpDataStruct();
    sTowerFunctions[gSpecialVar_0x8004]();
    FreeDataStruct();
}

void ResetTrainerTowerResults(void)
{
    s32 i;

    gSaveBlock2Ptr->frontier.savedGame = 0;
    gSaveBlock2Ptr->frontier.unk_EF9 = 0;
    gSaveBlock1Ptr->trainerTower.bestTime = 0;
    for (i = 0; i < NUM_TRAINER_TOWER_MODES; i++)
        SetTimerValue(&gSaveBlock1Ptr->trainerTowerTimes[i], TOWER_MAX_TIME);
}

static u8 GetFloorId(void)
{
    return gMapHeader.mapLayoutId - LAYOUT_TRAINER_TOWER_1F;
}

u8 GetTrainerTowerOpponentClass(u16 trainerId)
{
    u8 id = trainerId - 1;

    return gFacilityClassToTrainerClass[sFloorTrainers->facilityClass[id]];
}

void GetTrainerTowerTrainerName(u8 *dst, u16 trainerId)
{
    s32 i;
    u8 id = trainerId - 1;

    for (i = 0; i < TRAINER_NAME_LENGTH + 1; i++)
        dst[i] = sFloorTrainers->name[id][i];
}

u8 GetTrainerTowerTrainerFrontSpriteId(u16 trainerId)
{
    u8 id, facilityClass;

    SetUpDataStruct();
    id = trainerId - 1;
    facilityClass = sTowerData->floors[sTowerData->floorId].trainers[id].facilityClass;
    FreeDataStruct();

    return gFacilityClassToPicIndex[facilityClass];
}

void InitTrainerTowerBattleStruct(void)
{
    s32 i, j;

    SetUpDataStruct();
    sFloorTrainers = AllocZeroed(sizeof(*sFloorTrainers));

    for (i = 0; i < TOWER_TRAINERS_PER_FLOOR; i++)
    {
        for (j = 0; j < TRAINER_NAME_LENGTH + 1; j++)
            sFloorTrainers->name[i][j] = sTowerData->floors[sTowerData->floorId].trainers[i].name[j];

        sFloorTrainers->facilityClass[i] = sTowerData->floors[sTowerData->floorId].trainers[i].facilityClass;
    }
    SetTrainerTowerVBlankCounter(&gSaveBlock1Ptr->trainerTower.timer);
    FreeDataStruct();
}

void FreeTrainerTowerBattleStruct(void)
{
    TRY_FREE_AND_SET_NULL(sFloorTrainers);
}

static void SetUpDataStruct(void)
{
    if (sTowerData == NULL)
    {
        sTowerData = AllocZeroed(sizeof(*sTowerData));
        sTowerData->floorId = gMapHeader.mapLayoutId - LAYOUT_TRAINER_TOWER_1F;

        // This copy depends on the floor data for each challenge being directly after the
        // challenge header data, and for the field 'floors' in sTowerData to come directly
        // after the field 'challenge'.
        // e.g. for TOWER_MODE_NORMAL, it will copy sChallenge_Normal to sTowerData->challenge and
        // it will copy sFloors_Normal to sTowerData->floors
        CpuCopy32(sChallengeData[gSaveBlock1Ptr->trainerTower.mode], &sTowerData->challenge, sizeof(sTowerData->challenge) + sizeof(sTowerData->floors));
        TrainerTowerDummy();
    }
}

static void FreeDataStruct(void)
{
    TRY_FREE_AND_SET_NULL(sTowerData);
}

void CopyTrainerTowerTrainerText(u8 which, u16 trainerId)
{
    u8 id, floorId;

    SetUpDataStruct();
    floorId = GetFloorId();
    id = trainerId - 1;

    switch (which)
    {
    case TRAINER_TOWER_TEXT_INTRO:
        FrontierSpeechToString(sTowerData->floors[floorId].trainers[id].speechBefore);
        break;
    case TRAINER_TOWER_TEXT_PLAYER_LOST:
        FrontierSpeechToString(sTowerData->floors[floorId].trainers[id].speechWin);
        break;
    case TRAINER_TOWER_TEXT_PLAYER_WON:
        FrontierSpeechToString(sTowerData->floors[floorId].trainers[id].speechLose);
        break;
    case TRAINER_TOWER_TEXT_AFTER:
        FrontierSpeechToString(sTowerData->floors[floorId].trainers[id].speechAfter);
        break;
    }

    FreeDataStruct();
}

static void TrainerTowerStartChallenge(void)
{
    TrainerTowerDummy();
    if (!ReadTrainerTowerAndValidate())
        gSaveBlock1Ptr->trainerTower.field_3D6E_0f = 1;
    else
        gSaveBlock1Ptr->trainerTower.field_3D6E_0f = 0;

    gSaveBlock1Ptr->trainerTower.unk_3D6C = 0;
    SetTrainerTowerVBlankCounter(&gSaveBlock1Ptr->trainerTower.timer);
    gSaveBlock1Ptr->trainerTower.timer = 0;
    gSaveBlock1Ptr->trainerTower.spokeToOwner = 0;
    gSaveBlock1Ptr->trainerTower.checkedFinalTime = 0;
    gSaveBlock1Ptr->trainerTower.maybeECardScanDuringChallenge = 0;
    gSaveBlock2Ptr->frontier.trainerFlags = 0;
    gBattleOutcome = 0;
    gSaveBlock1Ptr->trainerTower.receivedPrize = 0;
}

static void GetOwnerState(void)
{
    ClearTrainerTowerVBlankCounter();
    gSpecialVar_Result = 0;
    if (gSaveBlock1Ptr->trainerTower.spokeToOwner)
        gSpecialVar_Result++;
    if (gSaveBlock1Ptr->trainerTower.receivedPrize && gSaveBlock1Ptr->trainerTower.checkedFinalTime)
        gSpecialVar_Result++;

    gSaveBlock1Ptr->trainerTower.spokeToOwner = TRUE;
}

static void GiveChallengePrize(void)
{
    u16 itemId = GetPrizeItemId();

    if (sTowerData->challenge.numFloors != NUM_TRAINER_TOWER_FLOORS || gSaveBlock1Ptr->trainerTower.receivedPrize)
    {
        gSpecialVar_Result = 2;
    }
    else if (AddBagItem(itemId, 1) == TRUE)
    {
        CopyItemName(itemId, gStringVar2);
        gSaveBlock1Ptr->trainerTower.receivedPrize = TRUE;
        gSaveBlock2Ptr->frontier.unk_EF9 = 0;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }
}

// If bestTime > timer, the challenge was completed faster and its a new record
// Otherwise the owner says it was a slow time and to complete it faster next time
static void CheckFinalTime(void)
{
    if (gSaveBlock1Ptr->trainerTower.checkedFinalTime)
    {
        gSpecialVar_Result = 2;
    }
    else if (GetTimerValue(&gSaveBlock1Ptr->trainerTower.bestTime) > gSaveBlock1Ptr->trainerTower.timer)
    {
        SetTimerValue(&gSaveBlock1Ptr->trainerTower.bestTime, gSaveBlock1Ptr->trainerTower.timer);
        gSaveBlock1Ptr->trainerTowerTimes[gSaveBlock1Ptr->trainerTower.mode] = gSaveBlock1Ptr->trainerTower.bestTime;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }

    gSaveBlock1Ptr->trainerTower.checkedFinalTime = TRUE;
}

static void TrainerTowerResumeTimer(void)
{
    if (!gSaveBlock1Ptr->trainerTower.spokeToOwner)
    {
        if (gSaveBlock1Ptr->trainerTower.timer >= TOWER_MAX_TIME)
            gSaveBlock1Ptr->trainerTower.timer = TOWER_MAX_TIME;
        else
            SetTrainerTowerVBlankCounter(&gSaveBlock1Ptr->trainerTower.timer);
    }
}

static void TrainerTowerSetPlayerLost(void)
{
    gSaveBlock1Ptr->trainerTower.hasLost = TRUE;
}

static void TrainerTowerGetChallengeStatus(void)
{
    if (gSaveBlock1Ptr->trainerTower.hasLost)
    {
        // The player lost their last match.
        gSaveBlock1Ptr->trainerTower.hasLost = FALSE;
        gSpecialVar_Result = TRAINER_TOWER_PLAYER_STATUS_LOST;
    }
    else if (gSaveBlock1Ptr->trainerTower.maybeECardScanDuringChallenge)
    {
        // Unreachable code. Something relating to eCards?
        gSaveBlock1Ptr->trainerTower.maybeECardScanDuringChallenge = 0;
        gSpecialVar_Result = TRAINER_TOWER_PLAYER_STATUS_ECARD_SCANNED;
    }
    else
    {
        // Continue playing.
        gSpecialVar_Result = TRAINER_TOWER_PLAYER_STATUS_NORMAL;
    }
}

static void BufferChallengeTime(void)
{
    s32 total, minutes, secondsWhole, secondsFraction;

    total = gSaveBlock1Ptr->trainerTower.timer;
    if (total >= TOWER_MAX_TIME)
        total = TOWER_MAX_TIME;

    minutes = total / (60 * 60);
    total %= (60 * 60);
    secondsWhole = total / 60;
    total %= 60;
    secondsFraction = (total * 168) / 100;

    ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar2, secondsWhole, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar3, secondsFraction, STR_CONV_MODE_LEADING_ZEROS, 2);
}

// Returns TRUE if all 4 floors are used
// Returns FALSE otherwise, and buffers the number of floors used
// The only time fewer than all 4 floors are used is for the JP-exclusive E-Reader and Default modes
static void GetAllFloorsUsed(void)
{
    SetUpDataStruct();
    if (sTowerData->challenge.numFloors != NUM_TRAINER_TOWER_FLOORS)
    {
        ConvertIntToDecimalStringN(gStringVar1, sTowerData->challenge.numFloors, STR_CONV_MODE_LEFT_ALIGN, 1);
        gSpecialVar_Result = FALSE;
    }
    else
    {
        gSpecialVar_Result = TRUE;
    }

    FreeDataStruct();
}

// May have been dummied. Every time this is called a conditional for var result occurs afterwards
// Relation to E-Reader is an assumption, most dummied Trainer Tower code seems to be JP E-Reader mode related
static void GetInEReaderMode(void)
{
    SetUpDataStruct();
    gSpecialVar_Result = FALSE;
    FreeDataStruct();
}

bool8 InTrainerTowerChallenge(void)
{
    if (VarGet(VAR_MAP_SCENE_TRAINER_TOWER) == 0)
        return FALSE;
    else if (gSaveBlock1Ptr->trainerTower.spokeToOwner)
        return FALSE;
    else if (GetCurrentTrainerTowerMapId() != 0)
        return TRUE;
    else
        return FALSE;
}

static void IsTrainerTowerChallengeActive(void)
{
    if (!InTrainerTowerChallenge())
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
}

static void TrainerTowerDummy(void)
{

}

void PrintOnTrainerTowerRecordsWindow(void)
{
    s32 i, x, y;
    u32 total, minutes, secondsWhole, secondsFraction;

    SetUpDataStruct();
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    x = GetStringCenterAlignXOffset(FONT_NORMAL, gText_TimeBoard, 0xD0);
    AddTextPrinterParameterized3(0, FONT_NORMAL, x, 2, sRecordWinColors, TEXT_SKIP_DRAW, gText_TimeBoard);

    y = 18;
    for (i = 0; i < NUM_TRAINER_TOWER_MODES; i++)
    {
        AddTextPrinterParameterized3(0, FONT_NORMAL, 0, y, sRecordWinColors, TEXT_SKIP_DRAW, sModeStrings[i]);
        y += 15;
        total = GetTimerValue(&gSaveBlock1Ptr->trainerTowerTimes[i]);
        minutes = total / (60 * 60);
        total %= (60 * 60);
        ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);
        secondsWhole = total / 60;
        total %= 60;
        ConvertIntToDecimalStringN(gStringVar2, secondsWhole, STR_CONV_MODE_RIGHT_ALIGN, 2);
        secondsFraction = (total * 168) / 100;
        ConvertIntToDecimalStringN(gStringVar3, secondsFraction, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringExpandPlaceholders(StringCopy(gStringVar4, gText_TimeCleared), gText_XMinYDotZSec);
        x = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0xD0);
        AddTextPrinterParameterized3(0, FONT_NORMAL, x, y, sRecordWinColors, TEXT_SKIP_DRAW, gStringVar4);
        y += 17;
    }

    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
    FreeDataStruct();
}

// Leftover from Fire Red / Leaf Green as in these games,
// the timer had to be xored by the encryption key in Sav2.
static u32 GetTimerValue(u32 *src)
{
    return *src;
}

static void SetTimerValue(u32 *dst, u32 val)
{
    *dst = val;
}

void LoadTrainerTowerObjectEventTemplates(void)
{
    u8 i, floorId;
    struct ObjectEventTemplate *eventTemplates = gSaveBlock1Ptr->objectEventTemplates;

    if (!LoadTrainerTowerFloorObjectEventScripts())
        return;

    SetUpDataStruct();
    for (i = 0; i < TOWER_TRAINERS_PER_FLOOR; i++)
        gSaveBlock2Ptr->frontier.trainerIds[i] = 0xFFFF;
    CpuFill32(0, gSaveBlock1Ptr->objectEventTemplates, sizeof(gSaveBlock1Ptr->objectEventTemplates));

    floorId = GetFloorId();
    for (i = 0; i < TOWER_TRAINERS_PER_FLOOR; i++)
    {
        u8 bits;

        eventTemplates[i] = sTrainerObjectEventTemplate;
        eventTemplates[i].localId = i + 1;
        eventTemplates[i].graphicsId = FacilityClassToGraphicsId(sTowerData->floors[floorId].trainers[i].facilityClass);
        eventTemplates[i].x = sTowerData->floors[floorId].map.trainerCoords[i] & 0xF;
        eventTemplates[i].y = ((sTowerData->floors[floorId].map.trainerCoords[i] >> 4) & 0xF) + TOWER_FLOOR_HEIGHT_MARGIN;
        bits = i << 2;
        eventTemplates[i].movementType = ((sTowerData->floors[floorId].map.trainerDirections >> bits) & 0xF) + MOVEMENT_TYPE_FACE_UP;
        eventTemplates[i].trainerRange_berryTreeId = (sTowerData->floors[floorId].map.trainerRanges >> bits) & 0xF;
        eventTemplates[i].script = TrainerTower_EventScript_TrainerBattle;
        gSaveBlock2Ptr->frontier.trainerIds[i] = i + 1;
    }

    FreeDataStruct();
}

bool32 LoadTrainerTowerFloorObjectEventScripts(void)
{
    SetUpDataStruct();
    // Something may have been dummied here
    FreeDataStruct();
    return TRUE;
}

static u16 GetMetatileForFloor(u8 floorId, u32 x, u32 y, u32 floorWidth) // floorWidth is always 16
{
    bool8 impassable;
    u16 metatile;
    u16 elevation;

    impassable = (sTowerData->floors[floorId].map.collisionData[y] >> (15 - x) & 1);
    metatile = sTowerData->floors[floorId].map.metatileData[floorWidth * y + x] + NUM_METATILES_IN_PRIMARY;
    elevation = 3 << MAPGRID_ELEVATION_SHIFT;

    return ((impassable << MAPGRID_COLLISION_SHIFT) & MAPGRID_COLLISION_MASK) | elevation | (metatile & MAPGRID_METATILE_ID_MASK);
}

void GenerateTrainerTowerFloorLayout(u16 *mapArg)
{
    s32 y, x;
    const u16 *src;
    u16 *dst;
    u8 mapId = GetCurrentTrainerTowerMapId();

    if (mapId == TRAINER_TOWER_LOBBY)
    {
        InitMapFromSavedGame();
        return;
    }

    SetUpDataStruct();
    if (mapId == TRAINER_TOWER_ROOF)
    {
        InitMapFromSavedGame();
        FreeDataStruct();
        return;
    }

    mapId = GetFloorId();
    src = gMapHeader.mapLayout->map;
    gBackupMapLayout.map = mapArg;
    // Dimensions include border area loaded beyond map
    gBackupMapLayout.width = TOWER_FLOOR_WIDTH + 15;
    gBackupMapLayout.height = TOWER_FLOOR_HEIGHT + 14;
    dst = mapArg + 224;

    // First 5 rows of the map (Entrance / Exit) are always the same
    for (y = 0; y < TOWER_FLOOR_HEIGHT_MARGIN; y++)
    {
        for (x = 0; x < TOWER_FLOOR_WIDTH; x++)
            dst[x] = src[x];
        dst += 31;
        src += 16;
    }

    // Load the 16x16 floor-specific layout
    for (y = 0; y < TOWER_FLOOR_HEIGHT_MAIN; y++)
    {
        for (x = 0; x < TOWER_FLOOR_WIDTH; x++)
            dst[x] = GetMetatileForFloor(mapId, x, y, TOWER_FLOOR_WIDTH);
        dst += 31;
    }

    RunOnLoadMapScript();
    FreeDataStruct();
}

bool32 InTrainerTower(void)
{
    bool32 ret;

    if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_1F
        || gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_2F
        || gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_3F
        || gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_4F)
        ret = TRUE;
    else
        ret = FALSE;

    return ret;
}

u8 GetCurrentTrainerTowerMapId(void)
{
    u8 mapId;

    if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_1F)
        mapId = TRAINER_TOWER_1F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_2F)
        mapId = TRAINER_TOWER_2F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_3F)
        mapId = TRAINER_TOWER_3F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_4F)
        mapId = TRAINER_TOWER_4F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_ROOF)
        mapId = TRAINER_TOWER_ROOF;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_LOBBY)
        mapId = TRAINER_TOWER_LOBBY;
    else
        mapId = 0;

    return mapId;
}

const struct WarpEvent* SetWarpDestinationTrainerTower4F(void)
{
    const struct MapHeader *header = Overworld_GetMapHeaderByGroupAndId(MAP_GROUP(TRAINER_TOWER_4F), MAP_NUM(TRAINER_TOWER_4F));

    return &header->events->warps[1];
}

// For warping from the roof in challenges where the 4F is not the final challenge floor
// This would only occur in the JP-exclusive Default and E-Reader challenges
const struct WarpEvent* SetWarpDestinationTrainerTowerFinalFloor(u8 warpEventId)
{
    u8 numFloors;
    const struct MapHeader *header;

    if (warpEventId == 1)
        return &gMapHeader.events->warps[1];

    numFloors = GetNumFloorsInTrainerTowerChallenge();
    if (numFloors == 0 || numFloors > NUM_TRAINER_TOWER_FLOORS)
        numFloors = NUM_TRAINER_TOWER_FLOORS;

    header = Overworld_GetMapHeaderByGroupAndId(MAP_GROUP(TRAINER_TOWER_4F), sNextFloorMapNum[numFloors - 1]);
    return &header->events->warps[0];
}

u16 LocalIdToTowerTrainerId(u8 localId)
{
    return gSaveBlock2Ptr->frontier.trainerIds[localId - 1];
}

bool8 GetTowerTrainerFlag(u8 objectEventId)
{
    u32 trainerIndexStart = GetFloorId() * TOWER_TRAINERS_PER_FLOOR;
    u8 bitId = gObjectEvents[objectEventId].localId - 1 + trainerIndexStart;

    return gSaveBlock2Ptr->frontier.trainerFlags & gBitTable[bitId];
}

void SetTowerTrainerFlag(void)
{
    u8 i;
    u8 trainerIndexStart = GetFloorId() * TOWER_TRAINERS_PER_FLOOR;

    for (i = 0; i < TOWER_TRAINERS_PER_FLOOR; i++)
    {
        if (gSaveBlock2Ptr->frontier.trainerIds[i] == gTrainerBattleOpponent_A)
        {
            gSaveBlock2Ptr->frontier.trainerFlags |= gBitTable[trainerIndexStart + i];
            break;
        }
    }

    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        for (i = 0; i < TOWER_TRAINERS_PER_FLOOR; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == gTrainerBattleOpponent_B)
            {
                gSaveBlock2Ptr->frontier.trainerFlags |= gBitTable[trainerIndexStart + i];
                break;
            }
        }
    }
}

const u8 *GetTrainerTowerTrainerScript(void)
{
    return TrainerTower_EventScript_TrainerBattle;
}

static void ShowTrainerTowerPostBattleText(void)
{
    CopyTrainerTowerTrainerText(TRAINER_TOWER_TEXT_AFTER, gSpecialVar_LastTalked);
    ShowFieldMessageFromBuffer();
}

static void CreateNPCTrainerTowerParty(u16 trainerId, u8 firstMonId)
{
    u8 trId, level;
    s32 i, floorId, partySlot;

    if (trainerId == 0 || trainerId > TOWER_TRAINERS_PER_FLOOR)
        return;

    trId = trainerId - 1;
    SetUpDataStruct();
    level = GetHighestLevelInPlayerParty();
    floorId = GetFloorId();
    for (i = firstMonId, partySlot = 0; i < firstMonId + PARTY_SIZE / 2; i++, partySlot++)
    {
        u8 id = sTrainerPartySlots[trId][partySlot];
        struct Pokemon *mon = &gEnemyParty[i];

        CreateBattleTowerMon(mon, &sTowerData->floors[floorId].trainers[trId].mons[id]);
        SetTrainerTowerMonLevel(mon, level);
    }

    FreeDataStruct();
}

void FillTowerTrainerParty(void)
{
    ZeroEnemyPartyMons();
    CreateNPCTrainerTowerParty(gTrainerBattleOpponent_A, 0);
}

void FillTowerTrainersParties(void)
{
    ZeroEnemyPartyMons();
    CreateNPCTrainerTowerParty(gTrainerBattleOpponent_A, 0);
    CreateNPCTrainerTowerParty(gTrainerBattleOpponent_B, PARTY_SIZE / 2);
}

u8 GetTrainerEncounterMusicIdInTrainerTower(u16 trainerId)
{
    s32 i;
    u8 trId, facilityClass;

    SetUpDataStruct();
    trId = trainerId - 1;
    facilityClass = sTowerData->floors[sTowerData->floorId].trainers[trId].facilityClass;
    FreeDataStruct();

    for (i = 0; i < ARRAY_COUNT(sTrainerClassesAndMusic); i++)
    {
        if (sTrainerClassesAndMusic[i].trainerClass == gFacilityClassToTrainerClass[facilityClass])
            return sTrainerClassesAndMusic[i].musicId;
    }

    return 0;
}

static void SetTrainerTowerMonLevel(struct Pokemon *mon, u8 level)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 exp = gExperienceTables[gSpeciesInfo[species].growthRate][level];

    SetMonData(mon, MON_DATA_EXP, &exp);
    SetMonData(mon, MON_DATA_LEVEL, &level);
    CalculateMonStats(mon);
}

u8 GetNumFloorsInTrainerTowerChallenge(void)
{
    u8 floors;

    SetUpDataStruct();
    floors = sTowerData->challenge.numFloors;
    FreeDataStruct();

    return floors;
}

static void SetAllTrainerFlags(void)
{
    gSaveBlock2Ptr->frontier.trainerFlags = 0xFF;
}

// Palette never loaded, OnTrainerTowerEReaderChallengeFloor always FALSE
void TryLoadTrainerTowerEReaderPalette(void)
{
    if (OnTrainerTowerEReaderChallengeFloor() == TRUE)
        LoadPalette(sEReader_Pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
}

static void GetGameSaved(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.savedGame;
}

static void SetGameSaved(void)
{
    gSaveBlock2Ptr->frontier.savedGame = TRUE;
}

static void ClearGameSaved(void)
{
    gSaveBlock2Ptr->frontier.savedGame = FALSE;
}

// Always FALSE
bool32 OnTrainerTowerEReaderChallengeFloor(void)
{
    if (!InTrainerTowerChallenge() || GetCurrentTrainerTowerMapId() == TRAINER_TOWER_LOBBY)
        return FALSE;

    GetInEReaderMode();
    if (gSpecialVar_Result == FALSE)
        return FALSE;
    else
        return TRUE;
}

static void GetChallengeWon(void)
{
    if (gSaveBlock1Ptr->trainerTower.hasLost)
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
}

static void TrainerTowerSetMode(void)
{
    gSaveBlock1Ptr->trainerTower.mode = gSpecialVar_0x8005;
    gSaveBlock1Ptr->trainerTower.bestTime = gSaveBlock1Ptr->trainerTowerTimes[gSpecialVar_0x8005];
}

// Determines which prize list to use from the set of prize lists.
static u8 GetPrizeListId(bool8 allowTMs)
{
    u8 prizeListId, i, modBy;

    // The initial selection depends on the trainer numbers for the completed challenge.
    // These don't change with the available challenge modes, so Normal/Unique will always
    // have a prizeListId of 8, and Variety/Expert will have a prizeListId of 24.
    prizeListId = 0;
    for (i = 0; i < NUM_TRAINER_TOWER_FLOORS; i++)
    {
        prizeListId ^= sTowerData->floors[i].trainerNum1 & 0x1F;
        prizeListId ^= sTowerData->floors[i].trainerNum2 & 0x1F;
    }

    // In practice, the conditional below is always true.
    // The 2nd half of the lists in both sets of lists all have a TM as the "grand prize", while the 1st half do not,
    // so taking the mod of the (total / 2) ensures that a prize list without a TM will be used.
    if (allowTMs)
        modBy = NUM_TRAINER_TOWER_PRIZE_LISTS;
    else
        modBy = NUM_TRAINER_TOWER_PRIZE_LISTS / 2;

    prizeListId %= modBy;
    return prizeListId;
}

static u16 GetPrizeItemId(void)
{
    u8 i;
    const u16 *prizeList;
    s32 trainerNumSum = 0, prizeListSetId, minutes, id;

    // First determine which set of prize lists to use. The sets of lists only differ in
    // what TMs they can offer as the "grand prize" for a time under 12 minutes.
    // Which set of lists gets used is based on the sum of all the trainer numbers for that
    // challenge. These don't change with the available challenge modes, so Normal will always
    // have a prizeListSetId of 0, and Unique/Variety/Expert will have a prizeListSetId of 1.
    for (i = 0; i < NUM_TRAINER_TOWER_FLOORS; i++)
    {
        trainerNumSum += sTowerData->floors[i].trainerNum1;
        trainerNumSum += sTowerData->floors[i].trainerNum2;
    }
    prizeListSetId = trainerNumSum / 256;
    prizeListSetId %= (int)ARRAY_COUNT(sPrizeListSets);

    // Now get which prize list to use from the set. See GetPrizeListId for details.
    // The below conditional will always be true, because a Trainer Tower challenge can't be entered
    // until the player has entered the Hall of Fame (FLAG_SYS_GAME_CLEAR is set) and because all
    // of the available challenge modes have the full 8 trainers (NUM_TRAINER_TOWER_TRAINERS).
    if (FlagGet(FLAG_SYS_GAME_CLEAR) && sTowerData->challenge.numTrainers == NUM_TRAINER_TOWER_TRAINERS)
        i = GetPrizeListId(TRUE);
    else
        i = GetPrizeListId(FALSE);

    // 1 is added to Expert mode's prize list selection because otherwise it has the same prizes as Variety
    if (gSaveBlock1Ptr->trainerTower.mode == TOWER_MODE_EXPERT)
        i = (i + 1) % NUM_TRAINER_TOWER_PRIZE_LISTS;

    // After the above (non-random) calculations, the following are the possible prize list selections:
    // sPrizeListSets[0][8] (Normal)
    // sPrizeListSets[1][4] (Variety)
    // sPrizeListSets[1][8] (Unique)
    // sPrizeListSets[1][5] (Expert)
    prizeList = sPrizeListSets[prizeListSetId][i];

    // Which prize is given from the list depends on the time scored.
    // The prize for any time after 12 minutes is the same in every list.
    // The prizes for a time under 12 minutes are:
    // - ITEM_TM_SUNNY_DAY     (Normal)
    // - ITEM_ELIXIR           (Variety)
    // - ITEM_TM19_ROOST       (Unique)
    // - ITEM_TM31_BRICK_BREAK (Expert)
    // As an additional note, if players were allowed to enter a Trainer Tower challenge before
    // entering the Hall of Fame, there would be 1 additional prize possibility (ITEM_MAX_ETHER)
    // as Normal / Unique modes would use sPrizeListSets[0][3] / sPrizeListSets[1][3] respectively.
    minutes = (signed)(gSaveBlock1Ptr->trainerTower.timer) / (60 * 60);
    if (minutes < 12)
        id = 0; // Depends on list
    else if (minutes < 13)
        id = 1; // ITEM_ETHER
    else if (minutes < 14)
        id = 2; // ITEM_MAX_POTION
    else if (minutes < 16)
        id = 3; // ITEM_REVIVE
    else if (minutes < 18)
        id = 4; // ITEM_POKE_DOLL
    else
        id = 5; // ITEM_GREAT_BALL

    return prizeList[id];
}
