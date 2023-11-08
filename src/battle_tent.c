#include "global.h"
#include "battle_tent.h"
#include "overworld.h"
#include "event_data.h"
#include "region_map.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "random.h"
#include "item.h"
#include "battle_factory_screen.h"
#include "frontier_util.h"
#include "string_util.h"
#include "constants/battle_tent.h"
#include "constants/battle_tent_trainers.h"
#include "constants/battle_tent_mons.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"

// This file's functions.
static void InitFuchsiaTentChallenge(void);
static void GetFuchsiaTentPrize(void);
static void SetFuchsiaTentPrize(void);
static void SetFuchsiaTentTrainerGfx(void);
static void BufferFuchsiaTentTrainerIntro(void);
static void SaveFuchsiaTentChallenge(void);
static void SetRandomFuchsiaTentPrize(void);
static void GiveFuchsiaTentPrize(void);
static void InitSaffronTentChallenge(void);
static void GetSaffronTentPrize(void);
static void SetSaffronTentPrize(void);
static void SaveSaffronTentChallenge(void);
static void SetRandomSaffronTentPrize(void);
static void GiveSaffronTentPrize(void);
static void BufferSaffronTentTrainerName(void);
static void InitCeruleanTentChallenge(void);
static void GetCeruleanTentPrize(void);
static void SetCeruleanTentPrize(void);
static void SaveCeruleanTentChallenge(void);
static void SetRandomCeruleanTentPrize(void);
static void GiveCeruleanTentPrize(void);
static void SelectInitialRentalMons(void);
static void SwapRentalMons(void);
static void GenerateOpponentMons(void);
static void GenerateInitialRentalMons(void);

/*
 * Battle Tents are mini versions of particular Battle Frontier facilities
 * As such they each share some scripts and functions with their counterpart
 *
 * Fuchsia Battle Tent: Battle Palace
 * Saffron Battle Tent:  Battle Arena
 * Cerulean Battle Tent:  Battle Factory
 *
 */

static u16 sRandMonId;

void static (*const sFuchsiaTentFuncs[])(void) =
{
    [FUCHSIA_TENT_FUNC_INIT]               = InitFuchsiaTentChallenge,
    [FUCHSIA_TENT_FUNC_GET_PRIZE]          = GetFuchsiaTentPrize,
    [FUCHSIA_TENT_FUNC_SET_PRIZE]          = SetFuchsiaTentPrize,
    [FUCHSIA_TENT_FUNC_SET_OPPONENT_GFX]   = SetFuchsiaTentTrainerGfx,
    [FUCHSIA_TENT_FUNC_GET_OPPONENT_INTRO] = BufferFuchsiaTentTrainerIntro,
    [FUCHSIA_TENT_FUNC_SAVE]               = SaveFuchsiaTentChallenge,
    [FUCHSIA_TENT_FUNC_SET_RANDOM_PRIZE]   = SetRandomFuchsiaTentPrize,
    [FUCHSIA_TENT_FUNC_GIVE_PRIZE]         = GiveFuchsiaTentPrize
};

static const u16 sFuchsiaTentRewards[] = {ITEM_NEST_BALL};

void static (*const sSaffronTentFuncs[])(void) =
{
    [SAFFRON_TENT_FUNC_INIT]              = InitSaffronTentChallenge,
    [SAFFRON_TENT_FUNC_GET_PRIZE]         = GetSaffronTentPrize,
    [SAFFRON_TENT_FUNC_SET_PRIZE]         = SetSaffronTentPrize,
    [SAFFRON_TENT_FUNC_SAVE]              = SaveSaffronTentChallenge,
    [SAFFRON_TENT_FUNC_SET_RANDOM_PRIZE]  = SetRandomSaffronTentPrize,
    [SAFFRON_TENT_FUNC_GIVE_PRIZE]        = GiveSaffronTentPrize,
    [SAFFRON_TENT_FUNC_GET_OPPONENT_NAME] = BufferSaffronTentTrainerName
};

static const u16 sSaffronTentRewards[] = {ITEM_HYPER_POTION};

void static (*const sCeruleanTentFuncs[])(void) =
{
    [CERULEAN_TENT_FUNC_INIT]                   = InitCeruleanTentChallenge,
    [CERULEAN_TENT_FUNC_GET_PRIZE]              = GetCeruleanTentPrize,
    [CERULEAN_TENT_FUNC_SET_PRIZE]              = SetCeruleanTentPrize,
    [CERULEAN_TENT_FUNC_SAVE]                   = SaveCeruleanTentChallenge,
    [CERULEAN_TENT_FUNC_SET_RANDOM_PRIZE]       = SetRandomCeruleanTentPrize,
    [CERULEAN_TENT_FUNC_GIVE_PRIZE]             = GiveCeruleanTentPrize,
    [CERULEAN_TENT_FUNC_SELECT_RENT_MONS]       = SelectInitialRentalMons,
    [CERULEAN_TENT_FUNC_SWAP_RENT_MONS]         = SwapRentalMons,
    [CERULEAN_TENT_FUNC_GENERATE_OPPONENT_MONS] = GenerateOpponentMons,
    [CERULEAN_TENT_FUNC_GENERATE_RENTAL_MONS]   = GenerateInitialRentalMons
};

static const u16 sCeruleanTentRewards[] = {ITEM_FULL_HEAL};

// code
void CallFuchsiaTentFunction(void)
{
    sFuchsiaTentFuncs[gSpecialVar_0x8004]();
}

static void InitFuchsiaTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetFuchsiaTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.fuchsiaTentPrize;
}

static void SetFuchsiaTentPrize(void)
{
    gSaveBlock2Ptr->frontier.fuchsiaTentPrize = gSpecialVar_0x8006;
}

static void SetFuchsiaTentTrainerGfx(void)
{
    gTrainerBattleOpponent_A = (u32)((Random() % 255) * 5) / 64;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
}

static void BufferFuchsiaTentTrainerIntro(void)
{
    if (gTrainerBattleOpponent_A < FRONTIER_TRAINERS_COUNT)
        FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

static void SaveFuchsiaTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomFuchsiaTentPrize(void)
{
    gSaveBlock2Ptr->frontier.fuchsiaTentPrize = sFuchsiaTentRewards[Random() % ARRAY_COUNT(sFuchsiaTentRewards)];
}

static void GiveFuchsiaTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.fuchsiaTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.fuchsiaTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.fuchsiaTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void CallSaffronTentFunction(void)
{
    sSaffronTentFuncs[gSpecialVar_0x8004]();
}

static void InitSaffronTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetSaffronTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.saffronTentPrize;
}

static void SetSaffronTentPrize(void)
{
    gSaveBlock2Ptr->frontier.saffronTentPrize = gSpecialVar_0x8006;
}

static void SaveSaffronTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomSaffronTentPrize(void)
{
    gSaveBlock2Ptr->frontier.saffronTentPrize = sSaffronTentRewards[Random() % ARRAY_COUNT(sSaffronTentRewards)];
}

static void GiveSaffronTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.saffronTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.saffronTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.saffronTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void BufferSaffronTentTrainerName(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}

void CallCeruleanTentFunction(void)
{
    sCeruleanTentFuncs[gSpecialVar_0x8004]();
}

static void InitCeruleanTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetCeruleanTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.ceruleanTentPrize;
}

static void SetCeruleanTentPrize(void)
{
    gSaveBlock2Ptr->frontier.ceruleanTentPrize = gSpecialVar_0x8006;
}

static void SaveCeruleanTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomCeruleanTentPrize(void)
{
    gSaveBlock2Ptr->frontier.ceruleanTentPrize = sCeruleanTentRewards[Random() % ARRAY_COUNT(sCeruleanTentRewards)];
}

static void GiveCeruleanTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.ceruleanTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.ceruleanTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.ceruleanTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void SelectInitialRentalMons(void)
{
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void SwapRentalMons(void)
{
    DoBattleFactorySwapScreen();
}

bool8 InCeruleanBattleTent(void)
{
    return gMapHeader.regionMapSectionId == MAPSEC_CERULEAN_CITY
           && (gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_CORRIDOR || gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_BATTLE_ROOM);
}

static void GenerateInitialRentalMons(void)
{
    s32 i, j;
    u8 firstMonId;
    u16 monSetId;
    u16 currSpecies;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];

    firstMonId = 0;
    gFacilityTrainers = gCeruleanBattleTentTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = 0;
        monIds[i] = 0;
        heldItems[i] = 0;
    }
    gFacilityTrainerMons = gCeruleanBattleTentMons;
    currSpecies = SPECIES_NONE;
    i = 0;
    while (i != PARTY_SIZE)
    {
        // Cannot have two pokemon of the same species.
        monSetId = Random() % NUM_CERULEAN_TENT_MONS;
        for (j = firstMonId; j < firstMonId + i; j++)
        {
            u16 monId = monIds[j];
            if (monIds[j] == monSetId)
                break;
            if (species[j] == gFacilityTrainerMons[monSetId].species)
            {
                if (currSpecies == SPECIES_NONE)
                    currSpecies = gFacilityTrainerMons[monSetId].species;
                else
                    break;
            }
        }
        if (j != i + firstMonId)
            continue;

        // Cannot have two same held items.
        for (j = firstMonId; j < i + firstMonId; j++)
        {
            if (heldItems[j] != 0 && heldItems[j] == gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId])
            {
                if (gFacilityTrainerMons[monSetId].species == currSpecies)
                    currSpecies = SPECIES_NONE;
                break;
            }
        }
        if (j != i + firstMonId)
            continue;

        gSaveBlock2Ptr->frontier.rentalMons[i].monId = monSetId;
        species[i] = gFacilityTrainerMons[monSetId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId];
        monIds[i] = monSetId;
        i++;
    }
}

static void GenerateOpponentMons(void)
{
    u16 trainerId;
    s32 i, j, k;
    const u16 *monSet;
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    s32 numMons = 0;

    gFacilityTrainers = gCeruleanBattleTentTrainers;
    gFacilityTrainerMons = gCeruleanBattleTentMons;

    while (1)
    {
        do
        {
            // Choose a random trainer, ensuring no repeats in this challenge
            trainerId = Random() % NUM_BATTLE_TENT_TRAINERS;
            for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
            {
                if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                    break;
            }
        } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

        gTrainerBattleOpponent_A = trainerId;
        monSet = gFacilityTrainers[gTrainerBattleOpponent_A].monSet;
        while (monSet[numMons] != 0xFFFF)
            numMons++;
        if (numMons > 8)
            break;
        numMons = 0;
    }

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < TENT_STAGES_PER_CHALLENGE - 1)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = gTrainerBattleOpponent_A;

    monSet = gFacilityTrainers[gTrainerBattleOpponent_A].monSet;
    i = 0;
    while (i != FRONTIER_PARTY_SIZE)
    {
        sRandMonId = monSet[Random() % numMons];

        // Ensure none of the opponent's pokemon are the same as the potential rental pokemon for the player
        for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); j++)
        {
            if (gFacilityTrainerMons[sRandMonId].species == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[j].monId].species)
                break;
        }
        if (j != (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons))
            continue;

        // Ensure this species hasn't already been chosen for the opponent
        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[sRandMonId].species)
                break;
        }
        if (k != i)
            continue;

        // Ensure held items don't repeat on the opponent's team
        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != ITEM_NONE && heldItems[k] == gBattleFrontierHeldItems[gFacilityTrainerMons[sRandMonId].itemTableId])
                break;
        }
        if (k != i)
            continue;

        // Successful selection
        species[i] = gFacilityTrainerMons[sRandMonId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[sRandMonId].itemTableId];
        gFrontierTempParty[i] = sRandMonId;
        i++;
    }
}
