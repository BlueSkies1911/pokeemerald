#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"
#include "match_call.h"
#include "pokenav.h"
#include "strings.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"


// NPC below means non-trainer character (no rematch or check page)
// Steven also uses this type but has a check page by using a MatchCallCheckPageOverride
enum
{
    MC_TYPE_NPC,
    MC_TYPE_TRAINER,
    MC_TYPE_OAK,
    MC_TYPE_RIVAL,
    MC_TYPE_LEADER
};

// Static type declarations

typedef struct MatchCallTextDataStruct {
    const u8 *text;
    u16 flag;
    u16 flag2;
} match_call_text_data_t;

struct MatchCallStructCommon {
    u8 type;
    u8 mapSec;
    u16 flag;
};

struct MatchCallStructNPC {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

// Shared by MC_TYPE_TRAINER and MC_TYPE_LEADER
struct MatchCallStructTrainer {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallLocationOverride {
    u16 flag;
    u8 mapSec;
};

struct MatchCallOak {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
};

struct MatchCallRival {
    u8 type;
    u16 flag;
    const u8 *desc;\
    const match_call_text_data_t *textData;
};

typedef union {
    const struct MatchCallStructCommon *common;
    const struct MatchCallStructNPC *npc;
    const struct MatchCallStructTrainer *trainer;
    const struct MatchCallOak *oak;
    const struct MatchCallRival *rival;
    const struct MatchCallStructTrainer *leader;
} match_call_t;

struct MatchCallCheckPageOverride {
    u16 idx;
    u16 facilityClass;
    u32 flag;
    const u8 *flavorTexts[CHECK_PAGE_ENTRY_COUNT];
};

// Static RAM declarations

// Static ROM declarations

static bool32 MatchCall_GetEnabled_NPC(match_call_t);
static bool32 MatchCall_GetEnabled_Trainer(match_call_t);
static bool32 MatchCall_GetEnabled_Oak(match_call_t);
static bool32 MatchCall_GetEnabled_Rival(match_call_t);

static u8 MatchCall_GetMapSec_NPC(match_call_t);
static u8 MatchCall_GetMapSec_Trainer(match_call_t);
static u8 MatchCall_GetMapSec_Oak(match_call_t);
static u8 MatchCall_GetMapSec_Rival(match_call_t);

static bool32 MatchCall_IsRematchable_NPC(match_call_t);
static bool32 MatchCall_IsRematchable_Trainer(match_call_t);
static bool32 MatchCall_IsRematchable_Oak(match_call_t);
static bool32 MatchCall_IsRematchable_Rival(match_call_t);

static bool32 MatchCall_HasCheckPage_NPC(match_call_t);
static bool32 MatchCall_HasCheckPage_Trainer(match_call_t);
static bool32 MatchCall_HasCheckPage_Oak(match_call_t);
static bool32 MatchCall_HasCheckPage_Rival(match_call_t);

static u32 MatchCall_GetRematchTableIdx_NPC(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Trainer(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Oak(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Rival(match_call_t);

static void MatchCall_GetMessage_NPC(match_call_t, u8 *);
static void MatchCall_GetMessage_Trainer(match_call_t, u8 *);
static void MatchCall_GetMessage_Oak(match_call_t, u8 *);
static void MatchCall_GetMessage_Rival(match_call_t, u8 *);

static void MatchCall_GetNameAndDesc_NPC(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Trainer(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Oak(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Rival(match_call_t, const u8 **, const u8 **);

static void MatchCall_BufferCallMessageText(const match_call_text_data_t *, u8 *);
static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *, u16, u8 *);
static void MatchCall_GetNameAndDescByRematchIdx(u32, const u8 **, const u8 **);

// .rodata

static const struct MatchCallOak sProfOakMatchCallHeader =
{
    .type = MC_TYPE_OAK,
    .mapSec = 0,
    .flag = FLAG_ENABLE_PROF_OAK_MATCH_CALL,
    .desc = gText_ProfOakMatchCallDesc,
    .name = gText_ProfOakMatchCallName
};

static const match_call_text_data_t sMomTextScripts[] = {
    { MatchCall_Text_Mom1, 0xFFFF,                      0xFFFF },
    { MatchCall_Text_Mom2, FLAG_DEFEATED_LT_SURGE,      0xFFFF },
    { MatchCall_Text_Mom3, FLAG_SYS_GAME_CLEAR,         0xFFFF },
    { NULL,                0xFFFF,                      0xFFFF }
};

static const struct MatchCallStructNPC sMomMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_PALLET_TOWN,
    .flag = FLAG_ENABLE_MOM_MATCH_CALL,
    .desc = gText_MomMatchCallDesc,
    .name = gText_MomMatchCallName,
    .textData = sMomTextScripts
};

static const match_call_text_data_t sStevenTextScripts[] = {
    { MatchCall_Text_Steven1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Steven2, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Steven3, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Steven4, FLAG_HIDE_ZAPDOS,                    0xFFFF },
    { MatchCall_Text_Steven5, FLAG_DEFEATED_BLAINE,                0xFFFF },
    { MatchCall_Text_Steven7, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                   0xFFFF,                              0xFFFF },
};

static const struct MatchCallStructNPC sStevenMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_REGISTERED_STEVEN_POKENAV,
    .desc = gText_StevenMatchCallDesc,
    .name = gText_StevenMatchCallName,
    .textData = sStevenTextScripts
};

static const match_call_text_data_t sDaisyTextScripts[] = {
    { MatchCall_Text_Daisy1,    0xFFFF,                              0xFFFF },
    { NULL,                     0xFFFF,                              0xFFFF }
};

static const struct MatchCallStructNPC sDaisyMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_PALLET_TOWN,
    .flag = FLAG_ENABLE_DAISY_MATCH_CALL,
    .desc = gText_DaisyMatchCallDesc,
    .name = gText_DaisyMatchCallName,
    .textData = sDaisyTextScripts
};

static const match_call_text_data_t sRivalTextScripts[] = {
    { MatchCall_Text_Rival1,  0xFFFF,                              0xFFFF },
    { MatchCall_Text_Rival2,  FLAG_GOT_HM01,                       0xFFFF },
    { MatchCall_Text_Rival3,  FLAG_WORLD_MAP_LAVENDER_TOWN,        0xFFFF },
    { MatchCall_Text_Rival4,  FLAG_GOT_POKE_FLUTE,                 0xFFFF },
    { MatchCall_Text_Rival5,  FLAG_GOT_HM03,                       0xFFFF },
    { MatchCall_Text_Rival6,  FLAG_HIDE_SAFFRON_ROCKETS,           0xFFFF },
    { MatchCall_Text_Rival7,  FLAG_WORLD_MAP_CINNABAR_ISLAND,      0xFFFF },
    { MatchCall_Text_Rival8,  FLAG_COLLECTED_SEVEN_BADGES,         0xFFFF },
    { MatchCall_Text_Rival9,  FLAG_DEFEATED_LEADER_GIOVANNI,       0xFFFF },
    { MatchCall_Text_Rival10, FLAG_LANDMARK_VICTORY_ROAD,          0xFFFF },
    { NULL,                   0xFFFF,                              0xFFFF }
};

static const struct MatchCallRival sRivalMatchCallHeader =
{
    .type = MC_TYPE_RIVAL,
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gText_RivalMatchCallDesc,
    .textData = sRivalTextScripts
};

static const match_call_text_data_t sScottTextScripts[] = {
    { MatchCall_Text_Scott1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Scott2, FLAG_CINNABAR_GYM_QUIZ_1,            0xFFFF },
    { MatchCall_Text_Scott3, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Scott4, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Scott5, FLAG_HIDE_ZAPDOS,                    0xFFFF },
    { MatchCall_Text_Scott6, FLAG_DEFEATED_LEADER_GIOVANNI,       0xFFFF },
    { MatchCall_Text_Scott7, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                  0xFFFF,                              0xFFFF }
};


static const struct MatchCallStructNPC sScottMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_ENABLE_SCOTT_MATCH_CALL,
    .desc = gText_ScottMatchCallDesc,
    .name = gText_ScottMatchCallName,
    .textData = sScottTextScripts
};

static const match_call_text_data_t sBrockTextScripts[] = {
    { MatchCall_Text_Brock1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Brock2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Brock3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Brock4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                  0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sBrockMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_PEWTER_CITY,
    .flag = FLAG_ENABLE_BROCK_MATCH_CALL,
    .rematchTableIdx = REMATCH_LEADER_BROCK,
    .desc = gText_BrockMatchCallDesc,
    .name = NULL,
    .textData = sBrockTextScripts
};

static const match_call_text_data_t sMistyTextScripts[] = {
    { MatchCall_Text_Misty1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Misty2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Misty3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Misty4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                  0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sMistyMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_CERULEAN_CITY,
    .flag = FLAG_ENABLE_MISTY_MATCH_CALL,
    .rematchTableIdx = REMATCH_LEADER_MISTY,
    .desc = gText_MistyMatchCallDesc,
    .name = NULL,
    .textData = sMistyTextScripts
};

static const match_call_text_data_t sLtSurgeTextScripts[] = {
    { MatchCall_Text_LtSurge1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_LtSurge2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_LtSurge3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_LtSurge4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                    0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sLtSurgeMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_VERMILION_CITY,
    .flag = FLAG_ENABLE_LT_SURGE_MATCH_CALL,
    .rematchTableIdx = REMATCH_LEADER_LT_SURGE,
    .desc = gText_LtSurgeMatchCallDesc,
    .name = NULL,
    .textData = sLtSurgeTextScripts
};

static const match_call_text_data_t sErikaTextScripts[] = {
    { MatchCall_Text_Erika1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Erika2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Erika3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Erika4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                  0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sErikaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_CELADON_CITY,
    .flag = FLAG_ENABLE_ERIKA_MATCH_CALL,
    .rematchTableIdx = REMATCH_LEADER_ERIKA,
    .desc = gText_ErikaMatchCallDesc,
    .name = NULL,
    .textData = sErikaTextScripts
};

static const match_call_text_data_t sKogaTextScripts[] = {
    { MatchCall_Text_Koga1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Koga2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Koga3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Koga4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                 0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sKogaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_FUCHSIA_CITY,
    .flag = FLAG_ENABLE_KOGA_MATCH_CALL,
    .rematchTableIdx = REMATCH_LEADER_KOGA,
    .desc = gText_KogaMatchCallDesc,
    .name = NULL,
    .textData = sKogaTextScripts
};

static const match_call_text_data_t sSabrinaTextScripts[] = {
    { MatchCall_Text_Sabrina1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Sabrina2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Sabrina3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Sabrina4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                    0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sSabrinaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_SAFFRON_CITY,
    .flag = FLAG_ENABLE_SABRINA_MATCH_CALL,
    .rematchTableIdx = REMATCH_LEADER_SABRINA,
    .desc = gText_SabrinaMatchCallDesc,
    .name = NULL,
    .textData = sSabrinaTextScripts
};

static const match_call_text_data_t sBlaineTextScripts[] = {
    { MatchCall_Text_Blaine1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Blaine2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Blaine3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Blaine4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                   0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sBlaineMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_CINNABAR_ISLAND,
    .flag = FLAG_ENABLE_BLAINE_MATCH_CALL,
    .rematchTableIdx = REMATCH_LEADER_BLAINE,
    .desc = gText_BlaineMatchCallDesc,
    .name = NULL,
    .textData = sBlaineTextScripts
};

static const match_call_text_data_t sLoreleiTextScripts[] = {
    { MatchCall_Text_Lorelei, 0xFFFF, 0xFFFF },
    { NULL,                   0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sLoreleiMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_INDIGO_PLATEAU,
    .flag = FLAG_REMATCH_ELITE_FOUR_LORELEI,
    .rematchTableIdx = REMATCH_ELITE_FOUR_LORELEI,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sLoreleiTextScripts
};

static const match_call_text_data_t sBrunoTextScripts[] = {
    { MatchCall_Text_Bruno, 0xFFFF, 0xFFFF },
    { NULL,                 0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sBrunoMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_INDIGO_PLATEAU,
    .flag = FLAG_REMATCH_ELITE_FOUR_BRUNO,
    .rematchTableIdx = REMATCH_ELITE_FOUR_BRUNO,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sBrunoTextScripts
};

static const match_call_text_data_t sAgathaTextScripts[] = {
    { MatchCall_Text_Agatha, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sAgathaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_INDIGO_PLATEAU,
    .flag = FLAG_REMATCH_ELITE_FOUR_AGATHA,
    .rematchTableIdx = REMATCH_ELITE_FOUR_AGATHA,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sAgathaTextScripts
};

static const match_call_text_data_t sLanceTextScripts[] = {
    { MatchCall_Text_Lance, 0xFFFF, 0xFFFF },
    { NULL,                 0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sLanceMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_INDIGO_PLATEAU,
    .flag = FLAG_REMATCH_ELITE_FOUR_LANCE,
    .rematchTableIdx = REMATCH_ELITE_FOUR_LANCE,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sLanceTextScripts
};

static const match_call_t sMatchCallHeaders[] = {
    [MC_HEADER_MOM]        = {.npc    = &sMomMatchCallHeader},
    [MC_HEADER_PROF_OAK]   = {.oak    = &sProfOakMatchCallHeader},
    [MC_HEADER_DAISY]      = {.npc    = &sDaisyMatchCallHeader},
    [MC_HEADER_RIVAL]      = {.rival  = &sRivalMatchCallHeader},
    [MC_HEADER_STEVEN]     = {.npc    = &sStevenMatchCallHeader},
    [MC_HEADER_SCOTT]      = {.npc    = &sScottMatchCallHeader},
    [MC_HEADER_BROCK]      = {.leader = &sBrockMatchCallHeader},
    [MC_HEADER_MISTY]      = {.leader = &sMistyMatchCallHeader},
    [MC_HEADER_LT_SURGE]   = {.leader = &sLtSurgeMatchCallHeader},
    [MC_HEADER_ERIKA]      = {.leader = &sErikaMatchCallHeader},
    [MC_HEADER_KOGA]       = {.leader = &sKogaMatchCallHeader},
    [MC_HEADER_SABRINA]    = {.leader = &sSabrinaMatchCallHeader},
    [MC_HEADER_BLAINE]     = {.leader = &sBlaineMatchCallHeader},
    [MC_HEADER_LORELEI]    = {.leader = &sLoreleiMatchCallHeader},
    [MC_HEADER_BRUNO]      = {.leader = &sBrunoMatchCallHeader},
    [MC_HEADER_AGATHA]     = {.leader = &sAgathaMatchCallHeader},
    [MC_HEADER_LANCE]      = {.leader = &sLanceMatchCallHeader}
};

static bool32 (*const sMatchCallGetEnabledFuncs[])(match_call_t) = {
    MatchCall_GetEnabled_NPC,
    MatchCall_GetEnabled_Trainer,
    MatchCall_GetEnabled_Rival,
    MatchCall_GetEnabled_Oak
};

static u8 (*const sMatchCallGetMapSecFuncs[])(match_call_t) = {
    MatchCall_GetMapSec_NPC,
    MatchCall_GetMapSec_Trainer,
    MatchCall_GetMapSec_Rival,
    MatchCall_GetMapSec_Oak
};

static bool32 (*const sMatchCall_IsRematchableFunctions[])(match_call_t) = {
    MatchCall_IsRematchable_NPC,
    MatchCall_IsRematchable_Trainer,
    MatchCall_IsRematchable_Rival,
    MatchCall_IsRematchable_Oak
};

static bool32 (*const sMatchCall_HasCheckPageFunctions[])(match_call_t) = {
    MatchCall_HasCheckPage_NPC,
    MatchCall_HasCheckPage_Trainer,
    MatchCall_HasCheckPage_Rival,
    MatchCall_HasCheckPage_Oak
};

static u32 (*const sMatchCall_GetRematchTableIdxFunctions[])(match_call_t) = {
    MatchCall_GetRematchTableIdx_NPC,
    MatchCall_GetRematchTableIdx_Trainer,
    MatchCall_GetRematchTableIdx_Rival,
    MatchCall_GetRematchTableIdx_Oak
};

static void (*const sMatchCall_GetMessageFunctions[])(match_call_t, u8 *) = {
    MatchCall_GetMessage_NPC,
    MatchCall_GetMessage_Trainer,
    MatchCall_GetMessage_Rival,
    MatchCall_GetMessage_Oak
};

static void (*const sMatchCall_GetNameAndDescFunctions[])(match_call_t, const u8 **, const u8 **) = {
    MatchCall_GetNameAndDesc_NPC,
    MatchCall_GetNameAndDesc_Trainer,
    MatchCall_GetNameAndDesc_Rival,
    MatchCall_GetNameAndDesc_Oak
};

static const struct MatchCallCheckPageOverride sCheckPageOverrides[] = {
    {
        .idx = MC_HEADER_STEVEN,
        .facilityClass = FACILITY_CLASS_STEVEN,
        .flag = 0xFFFF,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallSteven_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallSteven_Pokemon,
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallSteven_Intro1_BeforeMeteorFallsBattle,
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallSteven_Intro2_BeforeMeteorFallsBattle
        }
    },
    {
        .idx = MC_HEADER_STEVEN,
        .facilityClass = FACILITY_CLASS_STEVEN,
        .flag = FLAG_DEFEATED_BLAINE,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallSteven_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallSteven_Pokemon,
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallSteven_Intro1_AfterMeteorFallsBattle,
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallSteven_Intro2_AfterMeteorFallsBattle
        }
    },
    {
        .idx = MC_HEADER_RIVAL,
        .facilityClass = FACILITY_CLASS_RIVAL_LATE,
        .flag = 0xFFFF,
        .flavorTexts = MCFLAVOR(Rival)
    }
};

// .text

static u32 MatchCallGetFunctionIndex(match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        default:
        case MC_TYPE_NPC:
            return 0;
        case MC_TYPE_TRAINER:
        case MC_TYPE_LEADER:
            return 1;
        case MC_TYPE_RIVAL:
            return 2;
        case MC_TYPE_OAK:
            return 3;
    }
}

u32 GetTrainerIdxByRematchIdx(u32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 GetRematchIdxByTrainerIdx(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < REMATCH_TABLE_ENTRIES; rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 MatchCall_GetEnabled(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetEnabledFuncs[i](matchCall);
}

static bool32 MatchCall_GetEnabled_NPC(match_call_t matchCall)
{
    if (matchCall.npc->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.npc->flag);
}

static bool32 MatchCall_GetEnabled_Trainer(match_call_t matchCall)
{
    if (matchCall.trainer->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.trainer->flag);
}

static bool32 MatchCall_GetEnabled_Rival(match_call_t matchCall)
{
    if (matchCall.rival->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.rival->flag);
}

static bool32 MatchCall_GetEnabled_Oak(match_call_t matchCall)
{
    return FlagGet(matchCall.oak->flag);
}

u8 MatchCall_GetMapSec(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetMapSecFuncs[i](matchCall);
}

static u8 MatchCall_GetMapSec_NPC(match_call_t matchCall)
{
    return matchCall.npc->mapSec;
}

static u8 MatchCall_GetMapSec_Trainer(match_call_t matchCall)
{
    return matchCall.trainer->mapSec;
}

static u8 MatchCall_GetMapSec_Rival(match_call_t matchCall)
{
    return MAPSEC_NONE;
}

static u8 MatchCall_GetMapSec_Oak(match_call_t matchCall)
{
    return MAPSEC_PALLET_TOWN;
}

bool32 MatchCall_IsRematchable(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_IsRematchableFunctions[i](matchCall);
}

static bool32 MatchCall_IsRematchable_NPC(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Trainer(match_call_t matchCall)
{
    if (matchCall.trainer->rematchTableIdx >= REMATCH_ELITE_FOUR_ENTRIES)
        return FALSE;
    return gSaveBlock1Ptr->trainerRematches[matchCall.trainer->rematchTableIdx] ? TRUE : FALSE;
}

static bool32 MatchCall_IsRematchable_Rival(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Oak(match_call_t matchCall)
{
    return FALSE;
}

bool32 MatchCall_HasCheckPage(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    if (sMatchCall_HasCheckPageFunctions[i](matchCall))
        return TRUE;
    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
            return TRUE;
    }
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_NPC(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Trainer(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Rival(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Oak(match_call_t matchCall)
{
    return FALSE;
}

u32 MatchCall_GetRematchTableIdx(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return REMATCH_TABLE_ENTRIES;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_GetRematchTableIdxFunctions[i](matchCall);
}

static u32 MatchCall_GetRematchTableIdx_NPC(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Trainer(match_call_t matchCall)
{
    return matchCall.trainer->rematchTableIdx;
}

static u32 MatchCall_GetRematchTableIdx_Rival(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Oak(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

void MatchCall_GetMessage(u32 idx, u8 *dest)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetMessageFunctions[i](matchCall, dest);
}

static void MatchCall_GetMessage_NPC(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText(matchCall.npc->textData, dest);
}

// This is the one functional difference between MC_TYPE_TRAINER and MC_TYPE_LEADER
static void MatchCall_GetMessage_Trainer(match_call_t matchCall, u8 *dest)
{
    if (matchCall.common->type != MC_TYPE_LEADER)
        MatchCall_BufferCallMessageText(matchCall.trainer->textData, dest);
    else
        MatchCall_BufferCallMessageTextByRematchTeam(matchCall.leader->textData, matchCall.leader->rematchTableIdx, dest);
}

static void MatchCall_GetMessage_Rival(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText(matchCall.rival->textData, dest);
}

static void MatchCall_GetMessage_Oak(match_call_t matchCall, u8 *dest)
{
    BufferPokedexRatingForMatchCall(dest);
}

static void MatchCall_BufferCallMessageText(const match_call_text_data_t *textData, u8 *dest)
{
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
        ;
    if (i)
        i--;
    while (i)
    {
        if (textData[i].flag != 0xFFFF && FlagGet(textData[i].flag) == TRUE)
            break;
        i--;
    }
    if (textData[i].flag2 != 0xFFFF)
        FlagSet(textData[i].flag2);
    StringExpandPlaceholders(dest, textData[i].text);
}

static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *textData, u16 idx, u8 *dest)
{
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
    {
        if (textData[i].flag == 0xFFFE)
            break;
        if (textData[i].flag != 0xFFFF && !FlagGet(textData[i].flag))
            break;
    }
    if (textData[i].flag != 0xFFFE)
    {
        if (i)
            i--;
        if (textData[i].flag2 != 0xFFFF)
            FlagSet(textData[i].flag2);
        StringExpandPlaceholders(dest, textData[i].text);
    }
    else
    {
        if (FlagGet(FLAG_SYS_GAME_CLEAR))
        {
            do
            {
                if (gSaveBlock1Ptr->trainerRematches[idx])
                    i += 2;
                else if (CountBattledRematchTeams(idx) >= 2)
                    i += 3;
                else
                    i++;
            } while (0);
        }

        StringExpandPlaceholders(dest, textData[i].text);
    }
}

void MatchCall_GetNameAndDesc(u32 idx, const u8 **desc, const u8 **name)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetNameAndDescFunctions[i](matchCall, desc, name);
}

static void MatchCall_GetNameAndDesc_NPC(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.npc->desc;
    *name = matchCall.npc->name;
}

static void MatchCall_GetNameAndDesc_Trainer(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    match_call_t _matchCall = matchCall;
    if (_matchCall.trainer->name == NULL)
        MatchCall_GetNameAndDescByRematchIdx(_matchCall.trainer->rematchTableIdx, desc, name);
    else
        *name = _matchCall.trainer->name;
    *desc = _matchCall.trainer->desc;
}

static void MatchCall_GetNameAndDesc_Rival(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.rival->desc;
    *name = gSaveBlock2Ptr->rivalName;
}

static void MatchCall_GetNameAndDesc_Oak(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.oak->desc;
    *name = matchCall.oak->name;
}

static void MatchCall_GetNameAndDescByRematchIdx(u32 idx, const u8 **desc, const u8 **name)
{
    const struct Trainer *trainer = gTrainers + GetTrainerIdxByRematchIdx(idx);
    *desc = gTrainerClassNames[trainer->trainerClass];
    *name = trainer->trainerName;
}

const u8 *MatchCall_GetOverrideFlavorText(u32 idx, u32 offset)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
        {
            for (; i + 1 < ARRAY_COUNT(sCheckPageOverrides) &&
                sCheckPageOverrides[i + 1].idx == idx &&
                FlagGet(sCheckPageOverrides[i + 1].flag); i++);
            return sCheckPageOverrides[i].flavorTexts[offset];
        }
    }
    return NULL;
}

int MatchCall_GetOverrideFacilityClass(u32 idx)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
            return sCheckPageOverrides[i].facilityClass;
    }
    return -1;
}

bool32 MatchCall_HasRematchId(u32 idx)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sMatchCallHeaders); i++)
    {
        u32 id = MatchCall_GetRematchTableIdx(i);
        if (id != REMATCH_TABLE_ENTRIES && id == idx)
            return TRUE;
    }
    return FALSE;
}

void SetMatchCallRegisteredFlag(void)
{
    int r0 = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (r0 >= 0)
        FlagSet(FLAG_MATCH_CALL_REGISTERED + r0);
}
