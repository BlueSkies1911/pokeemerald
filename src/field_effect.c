#include "global.h"
#include "day_night.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_control_avatar.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "gpu_regs.h"
#include "main.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "util.h"
#include "constants/field_effects.h"
#include "constants/event_object_movement.h"
#include "constants/metatile_behaviors.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/map_types.h"

#define subsprite_table(ptr) {.subsprites = ptr, .subspriteCount = (sizeof ptr) / (sizeof(struct Subsprite))}

EWRAM_DATA s32 gFieldEffectArguments[8] = {0};
EWRAM_DATA u16 gReflectionPaletteBuffer[0x10] = {0};

// Static type declarations

static void Task_PokecenterHeal(u8 taskId);
static void SpriteCB_PokeballGlow(struct Sprite * sprite);
static void SpriteCB_PokecenterMonitor(struct Sprite * sprite);
static void SpriteCB_HallOfFameMonitor(struct Sprite * sprite);

static void FieldCallback_Teleport(void);
static void StartTeleportFieldEffect(void);

static void Task_FallWarpFieldEffect(u8);
static bool8 FallWarpEffect_Init(struct Task *);
static bool8 FallWarpEffect_WaitWeather(struct Task *);
static bool8 FallWarpEffect_StartFall(struct Task *);
static bool8 FallWarpEffect_Fall(struct Task *);
static bool8 FallWarpEffect_Land(struct Task *);
static bool8 FallWarpEffect_CameraShake(struct Task *);
static bool8 FallWarpEffect_End(struct Task *);

static void Task_EscalatorWarpOut(u8);
static bool8 EscalatorWarpOut_Init(struct Task *);
static bool8 EscalatorWarpOut_WaitForPlayer(struct Task *);
static bool8 EscalatorWarpOut_Up_Ride(struct Task *);
static bool8 EscalatorWarpOut_Up_End(struct Task *);
static bool8 EscalatorWarpOut_Down_Ride(struct Task *);
static bool8 EscalatorWarpOut_Down_End(struct Task *);
static void RideUpEscalatorOut(struct Task *);
static void RideDownEscalatorOut(struct Task *);
static void FadeOutAtEndOfEscalator(void);
static void WarpAtEndOfEscalator(void);

static void FieldCallback_EscalatorWarpIn(void);
static void Task_EscalatorWarpIn(u8);
static bool8 EscalatorWarpIn_Init(struct Task *);
static bool8 EscalatorWarpIn_Down_Init(struct Task *);
static bool8 EscalatorWarpIn_Down_Ride(struct Task *);
static bool8 EscalatorWarpIn_Up_Init(struct Task *);
static bool8 EscalatorWarpIn_Up_Ride(struct Task *);
static bool8 EscalatorWarpIn_WaitForMovement(struct Task *);
static bool8 EscalatorWarpIn_End(struct Task *);

static void Task_UseWaterfall(u8);
static bool8 WaterfallFieldEffect_Init(struct Task *, struct ObjectEvent *);
static bool8 WaterfallFieldEffect_ShowMon(struct Task *, struct ObjectEvent *);
static bool8 WaterfallFieldEffect_WaitForShowMon(struct Task *, struct ObjectEvent *);
static bool8 WaterfallFieldEffect_RideUp(struct Task *, struct ObjectEvent *);
static bool8 WaterfallFieldEffect_ContinueRideOrEnd(struct Task *, struct ObjectEvent *);

static void Task_UseDive(u8);
static bool8 DiveFieldEffect_Init(struct Task *);
static bool8 DiveFieldEffect_ShowMon(struct Task *);
static bool8 DiveFieldEffect_TryWarp(struct Task *);

static void Task_LavaridgeGymB1FWarp(u8);
static bool8 LavaridgeGymB1FWarpEffect_Init(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGymB1FWarpEffect_CameraShake(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGymB1FWarpEffect_Launch(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGymB1FWarpEffect_Rise(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGymB1FWarpEffect_FadeOut(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGymB1FWarpEffect_Warp(struct Task *, struct ObjectEvent *, struct Sprite *);

static void FieldCB_LavaridgeGymB1FWarpExit(void);
static void Task_LavaridgeGymB1FWarpExit(u8);
static bool8 LavaridgeGymB1FWarpExitEffect_Init(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGymB1FWarpExitEffect_StartPopOut(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGymB1FWarpExitEffect_PopOut(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGymB1FWarpExitEffect_End(struct Task *, struct ObjectEvent *, struct Sprite *);

static void Task_LavaridgeGym1FWarp(u8);
static bool8 LavaridgeGym1FWarpEffect_Init(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGym1FWarpEffect_AshPuff(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGym1FWarpEffect_Disappear(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGym1FWarpEffect_FadeOut(struct Task *, struct ObjectEvent *, struct Sprite *);
static bool8 LavaridgeGym1FWarpEffect_Warp(struct Task *, struct ObjectEvent *, struct Sprite *);

static void Task_EscapeRopeWarpOut(u8);
static void EscapeRopeWarpOutEffect_Init(struct Task *);
static void EscapeRopeWarpOutEffect_Spin(struct Task *);

static void FieldCallback_EscapeRopeWarpIn(void);
static void Task_EscapeRopeWarpIn(u8);
static void EscapeRopeWarpInEffect_Init(struct Task *);
static void EscapeRopeWarpInEffect_Spin(struct Task *);

static void Task_TeleportWarpOut(u8);
static void TeleportWarpOutFieldEffect_Init(struct Task *);
static void TeleportWarpOutFieldEffect_SpinGround(struct Task *);
static void TeleportWarpOutFieldEffect_SpinExit(struct Task *);
static void TeleportWarpOutFieldEffect_End(struct Task *);

static void FieldCallback_TeleportWarpIn(void);
static void Task_TeleportWarpIn(u8);
static void TeleportWarpInFieldEffect_Init(struct Task *);
static void TeleportWarpInFieldEffect_SpinEnter(struct Task *);
static void TeleportWarpInFieldEffect_SpinGround(struct Task *);

static void Task_FieldMoveShowMonOutdoors(u8);
static void FieldMoveShowMonOutdoorsEffect_Init(struct Task *);
static void FieldMoveShowMonOutdoorsEffect_LoadGfx(struct Task *);
static void FieldMoveShowMonOutdoorsEffect_CreateBanner(struct Task *);
static void FieldMoveShowMonOutdoorsEffect_WaitForMon(struct Task *);
static void FieldMoveShowMonOutdoorsEffect_ShrinkBanner(struct Task *);
static void FieldMoveShowMonOutdoorsEffect_RestoreBg(struct Task *);
static void FieldMoveShowMonOutdoorsEffect_End(struct Task *);
static void VBlankCB_FieldMoveShowMonOutdoors(void);
static void LoadFieldMoveOutdoorStreaksTilemap(u16);

static void Task_FieldMoveShowMonIndoors(u8);
static void FieldMoveShowMonIndoorsEffect_Init(struct Task *);
static void FieldMoveShowMonIndoorsEffect_LoadGfx(struct Task *);
static void FieldMoveShowMonIndoorsEffect_SlideBannerOn(struct Task *);
static void FieldMoveShowMonIndoorsEffect_WaitForMon(struct Task *);
static void FieldMoveShowMonIndoorsEffect_RestoreBg(struct Task *);
static void FieldMoveShowMonIndoorsEffect_SlideBannerOff(struct Task *);
static void FieldMoveShowMonIndoorsEffect_End(struct Task *);
static void VBlankCB_FieldMoveShowMonIndoors(void);
static void AnimateIndoorShowMonBg(struct Task *);
static bool8 SlideIndoorBannerOnscreen(struct Task *);
static bool8 SlideIndoorBannerOffscreen(struct Task *);

static u8 InitFieldMoveMonSprite(u32, bool8, u32);
static void SpriteCB_FieldMoveMonSlideOnscreen(struct Sprite *);
static void SpriteCB_FieldMoveMonWaitAfterCry(struct Sprite *);
static void SpriteCB_FieldMoveMonSlideOffscreen(struct Sprite *);

static void Task_SurfFieldEffect(u8);
static void SurfFieldEffect_Init(struct Task *);
static void SurfFieldEffect_FieldMovePose(struct Task *);
static void SurfFieldEffect_ShowMon(struct Task *);
static void SurfFieldEffect_JumpOnSurfBlob(struct Task *);
static void SurfFieldEffect_End(struct Task *);

// Static RAM declarations

static u8 sActiveList[32];

// External declarations
extern u8 *gFieldEffectScriptPointers[];
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

static const u32 sNewGameBirch_Gfx[] = INCBIN_U32("graphics/birch_speech/birch.4bpp");
static const u32 sUnusedBirchBeauty[] = INCBIN_U32("graphics/birch_speech/unused_beauty.4bpp");
static const u16 sNewGameBirch_Pal[16] = INCBIN_U16("graphics/birch_speech/birch.gbapal");
static const u16 sPokeballGlow_Gfx[] = INCBIN_U16("graphics/field_effects/pics/pokeball_heal/pokeball.4bpp");
static const u16 sPokeballGlow_Pal[] = INCBIN_U16("graphics/field_effects/pics/pokeball_heal/pokeball.gbapal");
static const u16 sPokecenterMonitor_Gfx[] = INCBIN_U16("graphics/field_effects/pics/pokecenter_monitor.4bpp");
static const u16 sHofMonitor_Pal[] = INCBIN_U16("graphics/field_effects/palettes/hof_monitor.gbapal");
static const u16 sHofMonitor_Gfx[] = INCBIN_U16("graphics/field_effects/pics/hof_monitor.4bpp");

// Graphics for the lights streaking past your Pokémon when it uses a field move.
static const u32 sFieldMoveStreaksOutdoors_Gfx[] = INCBIN_U32("graphics/field_effects/pics/field_move_streaks.4bpp");
static const u16 sFieldMoveStreaksOutdoors_Pal[16] = INCBIN_U16("graphics/field_effects/pics/field_move_streaks.gbapal");
static const u16 sFieldMoveStreaksOutdoors_Tilemap[320] = INCBIN_U16("graphics/field_effects/pics/field_move_streaks.bin");

// The following light streaks effect is used when the map is indoors
static const u32 sFieldMoveStreaksIndoors_Gfx[] = INCBIN_U32("graphics/field_effects/pics/field_move_streaks_indoors.4bpp");
static const u16 sFieldMoveStreaksIndoors_Pal[16] = INCBIN_U16("graphics/field_effects/pics/field_move_streaks_indoors.gbapal");
static const u16 sFieldMoveStreaksIndoors_Tilemap[320] = INCBIN_U16("graphics/field_effects/pics/field_move_streaks_indoors.bin");

static const u16 sSpotlight_Pal[16] = INCBIN_U16("graphics/field_effects/pics/spotlight.gbapal");
static const u8 sSpotlight_Gfx[] = INCBIN_U8("graphics/field_effects/pics/spotlight.4bpp");

bool8 (*const gFieldEffectScriptFuncs[])(u8 **, u32 *) =
{
    FieldEffectCmd_loadtiles,
    FieldEffectCmd_loadfadedpal,
    FieldEffectCmd_loadpal,
    FieldEffectCmd_callnative,
    FieldEffectCmd_end,
    FieldEffectCmd_loadgfx_callnative,
    FieldEffectCmd_loadtiles_callnative,
    FieldEffectCmd_loadfadedpal_callnative,
    // Added for day and night system
    FieldEffectCmd_loadpaldaynight,
    FieldEffectCmd_loadfadedpaldaynight,
    FieldEffectCmd_loadfadedpaldaynight_callnative,
};

static const struct OamData sOam_64x64 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const struct OamData sOam_8x8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const struct OamData sOam_16x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const struct SpriteFrameImage sPicTable_NewGameBirch[] =
{
    obj_frame_tiles(sNewGameBirch_Gfx)
};

static const struct SpritePalette sSpritePalette_NewGameBirch =
{
    .data = sNewGameBirch_Pal,
    .tag = 0x1006
};

static const union AnimCmd sAnim_NewGameBirch[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnimTable_NewGameBirch[] =
{
    sAnim_NewGameBirch
};

static const struct SpriteTemplate sSpriteTemplate_NewGameBirch =
{
    .tileTag = TAG_NONE,
    .paletteTag = 0x1006,
    .oam = &sOam_64x64,
    .anims = sAnimTable_NewGameBirch,
    .images = sPicTable_NewGameBirch,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct SpritePalette gSpritePalette_PokeballGlow =
{
    .data = sPokeballGlow_Pal,
    .tag = FLDEFF_PAL_TAG_POKEBALL_GLOW
};

const struct SpritePalette gSpritePalette_HofMonitor =
{
    .data = sHofMonitor_Pal,
    .tag = FLDEFF_PAL_TAG_HOF_MONITOR
};

static const struct OamData sOam_32x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const struct SpriteFrameImage sPicTable_PokeballGlow[] =
{
    {sPokeballGlow_Gfx, 0x20}
};

static const struct SpriteFrameImage sPicTable_PokecenterMonitor[] =
{
    {sPokecenterMonitor_Gfx + 0x000, 0x100},
    {sPokecenterMonitor_Gfx + 0x080, 0x100},
    {sPokecenterMonitor_Gfx + 0x100, 0x100},
    {sPokecenterMonitor_Gfx + 0x180, 0x100}
};

static const struct SpriteFrameImage sPicTable_HofMonitor[] =
{
    {sHofMonitor_Gfx + 0x00, 0x80},
    {sHofMonitor_Gfx + 0x40, 0x80},
    {sHofMonitor_Gfx + 0x80, 0x80},
    {sHofMonitor_Gfx + 0xC0, 0x80}
};

static const union AnimCmd sAnim_Static[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_Flicker[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(3, 7),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_LOOP(3),
    ANIMCMD_END
};

// Flicker on and off, for the Pokéballs / monitors during the PokéCenter heal effect
static const union AnimCmd *const sAnims_Flicker[] =
{
    sAnim_Static,
    sAnim_Flicker
};

static const union AnimCmd sAnim_HofFlicker[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_LOOP(2),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_HofFlicker[] =
{
    sAnim_HofFlicker
};

static const struct SpriteTemplate sSpriteTemplate_PokeballGlow =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_POKEBALL_GLOW,
    .oam = &sOam_8x8,
    .anims = sAnims_Flicker,
    .images = sPicTable_PokeballGlow,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PokeballGlow
};

static const struct SpriteTemplate sSpriteTemplate_PokecenterMonitor =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_POKEBALL_GLOW,
    .oam = &sOam_32x16,
    .anims = sAnims_Flicker,
    .images = sPicTable_PokecenterMonitor,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PokecenterMonitor
};

static const struct SpriteTemplate sSpriteTemplate_HofMonitor =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_HOF_MONITOR,
    .oam = &sOam_16x16,
    .anims = sAnims_HofFlicker,
    .images = sPicTable_HofMonitor,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_HallOfFameMonitor
};

bool8 (*const sFallWarpFieldEffectFuncs[])(struct Task *) =
{
    FallWarpEffect_Init,
    FallWarpEffect_WaitWeather,
    FallWarpEffect_StartFall,
    FallWarpEffect_Fall,
    FallWarpEffect_Land,
    FallWarpEffect_CameraShake,
    FallWarpEffect_End,
};

static bool8 (*const sEscalatorWarpOutFieldEffectFuncs[])(struct Task *) =
{
    EscalatorWarpOut_Init,
    EscalatorWarpOut_WaitForPlayer,
    EscalatorWarpOut_Up_Ride,
    EscalatorWarpOut_Up_End,
    EscalatorWarpOut_Down_Ride,
    EscalatorWarpOut_Down_End,
};

static bool8 (*const sEscalatorWarpInFieldEffectFuncs[])(struct Task *) =
{
    EscalatorWarpIn_Init,
    EscalatorWarpIn_Down_Init,
    EscalatorWarpIn_Down_Ride,
    EscalatorWarpIn_Up_Init,
    EscalatorWarpIn_Up_Ride,
    EscalatorWarpIn_WaitForMovement,
    EscalatorWarpIn_End,
};

static bool8 (*const sWaterfallFieldEffectFuncs[])(struct Task *, struct ObjectEvent *) =
{
    WaterfallFieldEffect_Init,
    WaterfallFieldEffect_ShowMon,
    WaterfallFieldEffect_WaitForShowMon,
    WaterfallFieldEffect_RideUp,
    WaterfallFieldEffect_ContinueRideOrEnd,
};

static bool8 (*const sDiveFieldEffectFuncs[])(struct Task *) =
{
    DiveFieldEffect_Init,
    DiveFieldEffect_ShowMon,
    DiveFieldEffect_TryWarp,
};

static bool8 (*const sLavaridgeGymB1FWarpEffectFuncs[])(struct Task *, struct ObjectEvent *, struct Sprite *) =
{
    LavaridgeGymB1FWarpEffect_Init,
    LavaridgeGymB1FWarpEffect_CameraShake,
    LavaridgeGymB1FWarpEffect_Launch,
    LavaridgeGymB1FWarpEffect_Rise,
    LavaridgeGymB1FWarpEffect_FadeOut,
    LavaridgeGymB1FWarpEffect_Warp,
};

static bool8 (*const sLavaridgeGymB1FWarpExitEffectFuncs[])(struct Task *, struct ObjectEvent *, struct Sprite *) =
{
    LavaridgeGymB1FWarpExitEffect_Init,
    LavaridgeGymB1FWarpExitEffect_StartPopOut,
    LavaridgeGymB1FWarpExitEffect_PopOut,
    LavaridgeGymB1FWarpExitEffect_End,
};

static bool8 (*const sLavaridgeGym1FWarpEffectFuncs[])(struct Task *, struct ObjectEvent *, struct Sprite *) =
{
    LavaridgeGym1FWarpEffect_Init,
    LavaridgeGym1FWarpEffect_AshPuff,
    LavaridgeGym1FWarpEffect_Disappear,
    LavaridgeGym1FWarpEffect_FadeOut,
    LavaridgeGym1FWarpEffect_Warp,
};

static void (*const sEscapeRopeWarpOutEffectFuncs[])(struct Task *) =
{
    EscapeRopeWarpOutEffect_Init,
    EscapeRopeWarpOutEffect_Spin,
};

u32 FieldEffectStart(u8 id)
{
    u8 *script;
    u32 val;

    FieldEffectActiveListAdd(id);

    script = gFieldEffectScriptPointers[id];

    while (gFieldEffectScriptFuncs[*script](&script, &val))
        ;

    return val;
}

bool8 FieldEffectCmd_loadtiles(u8 **script, u32 *val)
{
    (*script)++;
    FieldEffectScript_LoadTiles(script);
    return TRUE;
}

bool8 FieldEffectCmd_loadfadedpal(u8 **script, u32 *val)
{
    (*script)++;
    FieldEffectScript_LoadFadedPalette(script);
    return TRUE;
}

bool8 FieldEffectCmd_loadpal(u8 **script, u32 *val)
{
    (*script)++;
    FieldEffectScript_LoadPalette(script);
    return TRUE;
}

bool8 FieldEffectCmd_callnative(u8 **script, u32 *val)
{
    (*script)++;
    FieldEffectScript_CallNative(script, val);
    return TRUE;
}

bool8 FieldEffectCmd_end(u8 **script, u32 *val)
{
    return FALSE;
}

bool8 FieldEffectCmd_loadgfx_callnative(u8 **script, u32 *val)
{
    (*script)++;
    FieldEffectScript_LoadTiles(script);
    FieldEffectScript_LoadFadedPalette(script);
    FieldEffectScript_CallNative(script, val);
    return TRUE;
}

bool8 FieldEffectCmd_loadtiles_callnative(u8 **script, u32 *val)
{
    (*script)++;
    FieldEffectScript_LoadTiles(script);
    FieldEffectScript_CallNative(script, val);
    return TRUE;
}

bool8 FieldEffectCmd_loadfadedpal_callnative(u8 **script, u32 *val)
{
    (*script)++;
    FieldEffectScript_LoadFadedPalette(script);
    FieldEffectScript_CallNative(script, val);
    return TRUE;
}

bool8 FieldEffectCmd_loadpaldaynight(u8 **script, u32 *val)
{
    (*script)++;
    FieldEffectScript_LoadPaletteDayNight(script);
    return TRUE;
}

bool8 FieldEffectCmd_loadfadedpaldaynight(u8 **script, u32 *val)
{
    (*script)++;
    FieldEffectScript_LoadFadedPaletteDayNight(script);
    return TRUE;
}

bool8 FieldEffectCmd_loadfadedpaldaynight_callnative(u8 **script, u32 *val)
{
    (*script)++;
    FieldEffectScript_LoadFadedPaletteDayNight(script);
    FieldEffectScript_CallNative(script, val);
    return TRUE;
}

u32 FieldEffectScript_ReadWord(u8 **script)
{
    return (*script)[0]
         + ((*script)[1] << 8)
         + ((*script)[2] << 16)
         + ((*script)[3] << 24);
}

void FieldEffectScript_LoadTiles(u8 **script)
{
    struct SpriteSheet *sheet = (struct SpriteSheet *)FieldEffectScript_ReadWord(script);
    if (GetSpriteTileStartByTag(sheet->tag) == 0xFFFF)
        LoadSpriteSheet(sheet);
    (*script) += 4;
}

void FieldEffectScript_LoadFadedPalette(u8 **script)
{
    struct SpritePalette *palette = (struct SpritePalette *)FieldEffectScript_ReadWord(script);
    LoadSpritePalette(palette);
    UpdatePaletteGammaType(IndexOfSpritePaletteTag(palette->tag), COLOR_MAP_DARK_CONTRAST);
    UpdateSpritePaletteWithWeather(IndexOfSpritePaletteTag(palette->tag));
    (*script) += 4;
}

void FieldEffectScript_LoadPalette(u8 **script)
{
    struct SpritePalette *palette = (struct SpritePalette *)FieldEffectScript_ReadWord(script);
    LoadSpritePalette(palette);
    (*script) += 4;
}

void FieldEffectScript_LoadFadedPaletteDayNight(u8 **script)
{
    struct SpritePalette *palette = (struct SpritePalette *)FieldEffectScript_ReadWord(script);
    LoadSpritePaletteDayNight(palette);
    UpdatePaletteGammaType(IndexOfSpritePaletteTag(palette->tag), COLOR_MAP_DARK_CONTRAST);
    UpdateSpritePaletteWithWeather(IndexOfSpritePaletteTag(palette->tag));
    (*script) += 4;
}

void FieldEffectScript_LoadPaletteDayNight(u8 **script)
{
    struct SpritePalette *palette = (struct SpritePalette *)FieldEffectScript_ReadWord(script);
    LoadSpritePaletteDayNight(palette);
    (*script) += 4;
}

void FieldEffectScript_CallNative(u8 **script, u32 *val)
{
    u32 (*func)(void) = (u32 (*)(void))FieldEffectScript_ReadWord(script);
    *val = func();
    (*script) += 4;
}

void FieldEffectFreeGraphicsResources(struct Sprite *sprite)
{
    u16 sheetTileStart = sprite->sheetTileStart;
    u32 paletteNum = sprite->oam.paletteNum;
    DestroySprite(sprite);
    FieldEffectFreeTilesIfUnused(sheetTileStart);
    FieldEffectFreePaletteIfUnused(paletteNum);
}

void FieldEffectStop(struct Sprite *sprite, u8 id)
{
    FieldEffectFreeGraphicsResources(sprite);
    FieldEffectActiveListRemove(id);
}

void FieldEffectFreeTilesIfUnused(u16 tileStart)
{
    u8 i;
    u16 tag = GetSpriteTileTagByTileStart(tileStart);

    if (tag != TAG_NONE)
    {
        for (i = 0; i < MAX_SPRITES; i++)
            if (gSprites[i].inUse && gSprites[i].usingSheet && tileStart == gSprites[i].sheetTileStart)
                return;
        FreeSpriteTilesByTag(tag);
    }
}

void FieldEffectFreePaletteIfUnused(u8 paletteNum)
{
    u8 i;
    u16 tag = GetSpritePaletteTagByPaletteNum(paletteNum);

    if (tag != TAG_NONE)
    {
        for (i = 0; i < MAX_SPRITES; i++)
            if (gSprites[i].inUse && gSprites[i].oam.paletteNum == paletteNum)
                return;
        FreeSpritePaletteByTag(tag);
    }
}

void FieldEffectActiveListClear(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sActiveList); i++)
        sActiveList[i] = 0xFF;
}

void FieldEffectActiveListAdd(u8 id)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sActiveList); i++)
    {
        if (sActiveList[i] == 0xFF)
        {
            sActiveList[i] = id;
            return;
        }
    }
}

void FieldEffectActiveListRemove(u8 id)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sActiveList); i++)
    {
        if (sActiveList[i] == id)
        {
            sActiveList[i] = 0xFF;
            return;
        }
    }
}

bool8 FieldEffectActiveListContains(u8 id)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sActiveList); i++)
        if (sActiveList[i] == id)
            return TRUE;
    return FALSE;
}

u8 CreateTrainerSprite(u8 trainerSpriteID, s16 x, s16 y, u8 subpriority, u8 *buffer)
{
    struct SpriteTemplate spriteTemplate;
    LoadCompressedSpritePaletteOverrideBuffer(&gTrainerSprites[trainerSpriteID].palette, buffer);
    LoadCompressedSpriteSheetOverrideBuffer(&gTrainerSprites[trainerSpriteID].frontPic, buffer);
    spriteTemplate.tileTag = gTrainerSprites[trainerSpriteID].frontPic.tag;
    spriteTemplate.paletteTag = gTrainerSprites[trainerSpriteID].palette.tag;
    spriteTemplate.oam = &sOam_64x64;
    spriteTemplate.anims = gDummySpriteAnimTable;
    spriteTemplate.images = NULL;
    spriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    spriteTemplate.callback = SpriteCallbackDummy;
    return CreateSprite(&spriteTemplate, x, y, subpriority);
}

static void UNUSED LoadTrainerGfx_TrainerCard(u8 gender, u16 palOffset, u8 *dest)
{
    LZDecompressVram(gTrainerSprites[gender].frontPic.data, dest);
    LoadCompressedPalette(gTrainerSprites[gender].palette.data, palOffset, PLTT_SIZE_4BPP);
}

u8 AddNewGameBirchObject(s16 x, s16 y, u8 subpriority)
{
    LoadSpritePalette(&sSpritePalette_NewGameBirch);
    return CreateSprite(&sSpriteTemplate_NewGameBirch, x, y, subpriority);
}

u8 CreateMonSprite_PicBox(u16 species, s16 x, s16 y, u8 subpriority)
{
    s32 spriteId = CreateMonPicSprite(species, FALSE, 0x8000, TRUE, x, y, 0, species);
    PreservePaletteInWeather(IndexOfSpritePaletteTag(species) + 0x10);
    if (spriteId == 0xFFFF)
        return MAX_SPRITES;
    else
        return spriteId;
}

u8 CreateMonSprite_FieldMove(u16 species, bool8 isShiny, u32 personality, s16 x, s16 y, u8 subpriority)
{
    u16 spriteId = CreateMonPicSprite(species, isShiny, personality, TRUE, x, y, 0, species);
    PreservePaletteInWeather(gSprites[spriteId].oam.paletteNum + 0x10);
    if (spriteId == 0xFFFF)
        return MAX_SPRITES;
    else
        return spriteId;
}

void FreeResourcesAndDestroySprite(struct Sprite *sprite, u8 spriteId)
{
    ResetPreservedPalettesInWeather();
    if (sprite->oam.affineMode != ST_OAM_AFFINE_OFF)
    {
        FreeOamMatrix(sprite->oam.matrixNum);
    }
    FreeAndDestroyMonPicSprite(spriteId);
}

// r, g, b are between 0 and 16
void MultiplyInvertedPaletteRGBComponents(u16 i, u8 r, u8 g, u8 b)
{
    int curRed, curGreen, curBlue;
    u16 color = gPlttBufferUnfaded[i];

    curRed   = (color & RGB_RED);
    curGreen = (color & RGB_GREEN) >>  5;
    curBlue  = (color & RGB_BLUE)  >> 10;

    curRed   += (((0x1F - curRed)   * r) >> 4);
    curGreen += (((0x1F - curGreen) * g) >> 4);
    curBlue  += (((0x1F - curBlue)  * b) >> 4);

    color  = curRed;
    color |= (curGreen <<  5);
    color |= (curBlue  << 10);

    gPlttBufferFaded[i] = color;
}

// r, g, b are between 0 and 16
void MultiplyPaletteRGBComponents(u16 i, u8 r, u8 g, u8 b)
{
    int curRed, curGreen, curBlue;
    u16 color = gPlttBufferUnfaded[i];

    curRed   = (color & RGB_RED);
    curGreen = (color & RGB_GREEN) >>  5;
    curBlue  = (color & RGB_BLUE)  >> 10;

    curRed   -= ((curRed   * r) >> 4);
    curGreen -= ((curGreen * g) >> 4);
    curBlue  -= ((curBlue  * b) >> 4);

    color  = curRed;
    color |= (curGreen <<  5);
    color |= (curBlue  << 10);

    gPlttBufferFaded[i] = color;
}

static void PokecenterHealEffect_Init(struct Task *task);
static void PokecenterHealEffect_WaitForBallPlacement(struct Task *task);
static void PokecenterHealEffect_WaitForBallFlashing(struct Task *task);
static void PokecenterHealEffect_WaitForSoundAndEnd(struct Task *task);
static void HallOfFameRecordEffect_Init(struct Task *task);
static void HallOfFameRecordEffect_WaitForBallPlacement(struct Task *task);
static void HallOfFameRecordEffect_WaitForBallFlashing(struct Task *task);
static void HallOfFameRecordEffect_WaitForSoundAndEnd(struct Task *task);
static void Task_HallOfFameRecord(u8 taskId);
static u8 CreateGlowingPokeballsEffect(s16 duration, s16 x, s16 y, bool16 fanfare);
static void SpriteCB_PokeballGlowEffect(struct Sprite *sprite);
static void PokeballGlowEffect_PlaceBalls(struct Sprite *sprite);
static void PokeballGlowEffect_TryPlaySe(struct Sprite *sprite);
static void PokeballGlowEffect_FlashFirstThree(struct Sprite *sprite);
static void PokeballGlowEffect_FlashLast(struct Sprite *sprite);
static void PokeballGlowEffect_WaitAfterFlash(struct Sprite *sprite);
static void PokeballGlowEffect_Dummy(struct Sprite *sprite);
static void PokeballGlowEffect_WaitForSound(struct Sprite *sprite);
static void PokeballGlowEffect_Idle(struct Sprite *sprite);
static u8 CreatePokecenterMonitorSprite(s32 x, s32 y);
static void CreateHofMonitorSprite(s32 x, s32 y);

static void (*const sPokecenterHealEffectFuncs[])(struct Task *) =
{
    PokecenterHealEffect_Init,
    PokecenterHealEffect_WaitForBallPlacement,
    PokecenterHealEffect_WaitForBallFlashing,
    PokecenterHealEffect_WaitForSoundAndEnd
};

static void (*const sHallOfFameRecordEffectFuncs[])(struct Task *) =
{
    HallOfFameRecordEffect_Init,
    HallOfFameRecordEffect_WaitForBallPlacement,
    HallOfFameRecordEffect_WaitForBallFlashing,
    HallOfFameRecordEffect_WaitForSoundAndEnd
};

static void (*const sPokeballGlowEffectFuncs[])(struct Sprite *) =
{
    PokeballGlowEffect_PlaceBalls,
    PokeballGlowEffect_TryPlaySe,
    PokeballGlowEffect_FlashFirstThree,
    PokeballGlowEffect_FlashLast,
    PokeballGlowEffect_WaitAfterFlash,
    PokeballGlowEffect_Dummy,
    PokeballGlowEffect_WaitForSound,
    PokeballGlowEffect_Idle
};

// Task data for Task_PokecenterHeal and Task_HallOfFameRecord
#define tState              data[0]
#define tNumMons            data[1]
#define tFirstBallX         data[2]
#define tFirstBallY         data[3]
#define tMonitorX           data[4]
#define tMonitorY           data[5]
#define tGlowEffectSpriteId data[6]
#define tMonitorSpriteId    data[7]

// Sprite data for SpriteCB_PokeballGlowEffect
#define sState      data[0]
#define sTimer      data[1]
#define sCounter    data[2]
#define sNumFlashed data[3]
#define sPlayHealSe data[5]
#define sNumMons    data[6]
#define sSpriteId   data[7]

// Sprite data for SpriteCB_PokeballGlow
#define sGlowEffectSpriteId data[0]

// Sprite data for SpriteCB_PokecenterMonitor
#define sStartFlash data[0]

bool8 FldEff_PokecenterHeal(void)
{
    u8 nPokemon;
    struct Task *task;

    nPokemon = CalculatePlayerPartyCount();
    task = &gTasks[CreateTask(Task_PokecenterHeal, 0xFF)];
    task->tNumMons = nPokemon;
    task->tFirstBallX = 93;
    task->tFirstBallY = 36;
    task->tMonitorX = 128;
    task->tMonitorY = 24;
    return FALSE;
}

static void Task_PokecenterHeal(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    sPokecenterHealEffectFuncs[task->tState](task);
}

static void PokecenterHealEffect_Init(struct Task *task)
{
    task->tState++;
    task->tGlowEffectSpriteId = CreateGlowingPokeballsEffect(task->tNumMons, task->tFirstBallX, task->tFirstBallY, TRUE);
    task->tMonitorSpriteId = CreatePokecenterMonitorSprite(task->tMonitorX, task->tMonitorY);
}

static void PokecenterHealEffect_WaitForBallPlacement(struct Task *task)
{
    if (gSprites[task->tGlowEffectSpriteId].sState >= 2)
    {
        gSprites[task->tMonitorSpriteId].sStartFlash++;
        task->tState++;
    }
}

static void PokecenterHealEffect_WaitForBallFlashing(struct Task *task)
{
    if (gSprites[task->tGlowEffectSpriteId].sState > 4)
        task->tState++;
}

static void PokecenterHealEffect_WaitForSoundAndEnd(struct Task *task)
{
    if (gSprites[task->tGlowEffectSpriteId].sState > 6)
    {
        DestroySprite(&gSprites[task->tGlowEffectSpriteId]);
        FieldEffectActiveListRemove(FLDEFF_POKECENTER_HEAL);
        DestroyTask(FindTaskIdByFunc(Task_PokecenterHeal));
    }
}

bool8 FldEff_HallOfFameRecord(void)
{
    u8 nPokemon;
    struct Task *task;

    nPokemon = CalculatePlayerPartyCount();
    task = &gTasks[CreateTask(Task_HallOfFameRecord, 0xFF)];
    task->tNumMons = nPokemon;
    task->tFirstBallX = 117;
    task->tFirstBallY = 60;
    return FALSE;
}

static void Task_HallOfFameRecord(u8 taskId)
{
    struct Task *task;
    task = &gTasks[taskId];
    sHallOfFameRecordEffectFuncs[task->tState](task);
}

static void HallOfFameRecordEffect_Init(struct Task *task)
{
    u8 taskId;
    task->tState++;
    task->tGlowEffectSpriteId = CreateGlowingPokeballsEffect(task->tNumMons, task->tFirstBallX, task->tFirstBallY, FALSE);
}

static void HallOfFameRecordEffect_WaitForBallPlacement(struct Task *task)
{
    if (gSprites[task->tGlowEffectSpriteId].sState > 1)
    {
        CreateHofMonitorSprite(120, 25);
        task->data[15]++; // unused, leftover from RSE
        task->tState++;
    }
}

static void HallOfFameRecordEffect_WaitForBallFlashing(struct Task *task)
{
    if (gSprites[task->tGlowEffectSpriteId].sState > 4)
        task->tState++;
}

static void HallOfFameRecordEffect_WaitForSoundAndEnd(struct Task *task)
{
    if (gSprites[task->tGlowEffectSpriteId].sState > 6)
    {
        DestroySprite(&gSprites[task->tGlowEffectSpriteId]);
        FieldEffectActiveListRemove(FLDEFF_HALL_OF_FAME_RECORD);
        DestroyTask(FindTaskIdByFunc(Task_HallOfFameRecord));
    }
}

#undef tState
#undef tNumMons
#undef tFirstBallX
#undef tFirstBallY
#undef tMonitorX
#undef tMonitorY
#undef tGlowEffectSpriteId
#undef tMonitorSpriteId

static u8 CreateGlowingPokeballsEffect(s16 numMons, s16 x, s16 y, bool16 playHealSe)
{
    u8 spriteId;
    struct Sprite *sprite;
    spriteId = CreateInvisibleSprite(SpriteCB_PokeballGlowEffect);
    sprite = &gSprites[spriteId];
    sprite->x2 = x;
    sprite->y2 = y;
    sprite->subpriority = 0xFF;
    sprite->sPlayHealSe = playHealSe;
    sprite->sNumMons = numMons;
    sprite->sSpriteId = spriteId;
    return spriteId;
}

static void SpriteCB_PokeballGlowEffect(struct Sprite *sprite)
{
    sPokeballGlowEffectFuncs[sprite->sState](sprite);
}

static const struct Coords16 sPokeballCoordOffsets[] = {
    {0, 0},
    {6, 0},
    {0, 4},
    {6, 4},
    {0, 8},
    {6, 8}
};

static const u8 sPokeballGlowReds[]   = {16, 12,  8,  0};
static const u8 sPokeballGlowGreens[] = {16, 12,  8,  0};
static const u8 sPokeballGlowBlues[]  = { 0,  0,  0,  0};

static void PokeballGlowEffect_PlaceBalls(struct Sprite *sprite)
{
    u8 spriteId;
    if (sprite->sTimer == 0 || (--sprite->sTimer) == 0)
    {
        sprite->sTimer = 25;
        spriteId = CreateSpriteAtEnd(&sSpriteTemplate_PokeballGlow, sPokeballCoordOffsets[sprite->sCounter].x + sprite->x2, sPokeballCoordOffsets[sprite->sCounter].y + sprite->y2, 0xFF);
        gSprites[spriteId].oam.priority = 2;
        gSprites[spriteId].sGlowEffectSpriteId = sprite->sSpriteId;
        sprite->sCounter++;
        sprite->sNumMons--;
        PlaySE(SE_BALL);
    }
    if (sprite->sNumMons == 0)
    {
        sprite->sTimer = 32;
        sprite->sState++;
    }
}

static void PokeballGlowEffect_TryPlaySe(struct Sprite *sprite)
{
    if ((--sprite->sTimer) == 0)
    {
        sprite->sState++;
        sprite->sTimer = 8;
        sprite->sCounter = 0;
        sprite->sNumFlashed = 0;
        if (sprite->sPlayHealSe)
            PlayFanfare(MUS_HEAL);
    }
}

static void PokeballGlowEffect_FlashFirstThree(struct Sprite *sprite)
{
    u8 phase;
    if ((--sprite->sTimer) == 0)
    {
        sprite->sTimer = 8;
        sprite->sCounter++;
        sprite->sCounter &= 3;

        if (sprite->sCounter == 0)
            sprite->sNumFlashed++;
    }
    phase = (sprite->sCounter + 3) & 3;
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(0x1007)) + 8, sPokeballGlowReds[phase], sPokeballGlowGreens[phase], sPokeballGlowBlues[phase]);
    phase = (sprite->sCounter + 2) & 3;
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(0x1007)) + 6, sPokeballGlowReds[phase], sPokeballGlowGreens[phase], sPokeballGlowBlues[phase]);
    phase = (sprite->sCounter + 1) & 3;
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(0x1007)) + 2, sPokeballGlowReds[phase], sPokeballGlowGreens[phase], sPokeballGlowBlues[phase]);
    phase = sprite->sCounter;
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(0x1007)) + 5, sPokeballGlowReds[phase], sPokeballGlowGreens[phase], sPokeballGlowBlues[phase]);
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(0x1007)) + 3, sPokeballGlowReds[phase], sPokeballGlowGreens[phase], sPokeballGlowBlues[phase]);
    if (sprite->sNumFlashed >= 3)
    {
        sprite->sState++;
        sprite->sTimer = 8;
        sprite->sCounter = 0;
    }
}

static void PokeballGlowEffect_FlashLast(struct Sprite *sprite)
{
    u8 phase;
    if ((--sprite->sTimer) == 0)
    {
        sprite->sTimer = 8;
        sprite->sCounter++;
        sprite->sCounter &= 3;
        if (sprite->sCounter == 3)
        {
            sprite->sState++;
            sprite->sTimer = 30;
        }
    }
    phase = sprite->sCounter;
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(0x1007)) + 8, sPokeballGlowReds[phase], sPokeballGlowGreens[phase], sPokeballGlowBlues[phase]);
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(0x1007)) + 6, sPokeballGlowReds[phase], sPokeballGlowGreens[phase], sPokeballGlowBlues[phase]);
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(0x1007)) + 2, sPokeballGlowReds[phase], sPokeballGlowGreens[phase], sPokeballGlowBlues[phase]);
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(0x1007)) + 5, sPokeballGlowReds[phase], sPokeballGlowGreens[phase], sPokeballGlowBlues[phase]);
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(0x1007)) + 3, sPokeballGlowReds[phase], sPokeballGlowGreens[phase], sPokeballGlowBlues[phase]);
}

static void PokeballGlowEffect_WaitAfterFlash(struct Sprite *sprite)
{
    if ((--sprite->sTimer) == 0)
        sprite->sState++;
}

static void PokeballGlowEffect_Dummy(struct Sprite *sprite)
{
    sprite->sState++;
}

static void PokeballGlowEffect_WaitForSound(struct Sprite *sprite)
{
    if (sprite->sPlayHealSe == FALSE || IsFanfareTaskInactive())
        sprite->sState++;
}

static void PokeballGlowEffect_Idle(struct Sprite *sprite)
{
    // Idle until destroyed
}

static void SpriteCB_PokeballGlow(struct Sprite *sprite)
{
    if (gSprites[sprite->sGlowEffectSpriteId].sState > 4)
        FieldEffectFreeGraphicsResources(sprite);
}

#undef sState
#undef sTimer
#undef sCounter
#undef sNumFlashed
#undef sPlayHealSe
#undef sNumMons
#undef sSpriteId

#undef sGlowEffectSpriteId

static u8 CreatePokecenterMonitorSprite(s32 x, s32 y)
{
    u8 spriteId;
    struct Sprite *sprite;
    spriteId = CreateSpriteAtEnd(&sSpriteTemplate_PokecenterMonitor, x, y, 0);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 2;
    sprite->invisible = TRUE;
    return spriteId;
}

static void SpriteCB_PokecenterMonitor(struct Sprite *sprite)
{
    if (sprite->sStartFlash != FALSE)
    {
        sprite->sStartFlash = FALSE;
        sprite->invisible = FALSE;
        StartSpriteAnim(sprite, 1);
    }
    if (sprite->animEnded)
        FieldEffectFreeGraphicsResources(sprite);
}

#undef sStartFlash

static void CreateHofMonitorSprite(s32 x, s32 y)
{
    CreateSpriteAtEnd(&sSpriteTemplate_HofMonitor, x, y, 0);
}

static void SpriteCB_HallOfFameMonitor(struct Sprite *sprite)
{
    if (sprite->animEnded)
        FieldEffectFreeGraphicsResources(sprite);
}

void ReturnToFieldFromTeleportMapSelect(void)
{
    SetMainCallback2(CB2_ReturnToField);
    gFieldCallback = FieldCallback_Teleport;
}

static void FieldCallback_Teleport(void)
{
    Overworld_ResetStateAfterTeleport();
    FieldEffectStart(FLDEFF_USE_TELEPORT);
    gFieldEffectArguments[0] = (u32)GetCursorSelectionMonId();
}

bool8 FldEff_UseTeleport(void)
{
    u8 taskId = CreateFieldMoveTask();
    gTasks[taskId].data[8] = (u32)StartTeleportFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartTeleportFieldEffect;
    SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    return FALSE;
}

static void StartTeleportFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_TELEPORT);
    FldEff_TeleportWarpOut();
}

#define tState      data[0]
#define tFallOffset data[1]
#define tTotalFall  data[2]
#define tSetTrigger data[3]
#define tSubsprMode data[4]

#define tVertShake  data[1] // re-used
#define tNumShakes  data[2]

void FieldCB_FallWarpExit(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    LockPlayerFieldControls();
    FreezeObjectEvents();
    CreateTask(Task_FallWarpFieldEffect, 0);
    gFieldCallback = NULL;
}

static void Task_FallWarpFieldEffect(u8 taskId)
{
    struct Task *task;
    task = &gTasks[taskId];
    while (sFallWarpFieldEffectFuncs[task->tState](task));
}

static bool8 FallWarpEffect_Init(struct Task *task)
{
    struct ObjectEvent *playerObject;
    struct Sprite *playerSprite;
    playerObject = &gObjectEvents[gPlayerAvatar.objectEventId];
    playerSprite = &gSprites[gPlayerAvatar.spriteId];
    CameraObjectFreeze();
    gObjectEvents[gPlayerAvatar.objectEventId].invisible = TRUE;
    gPlayerAvatar.preventStep = TRUE;
    ObjectEventSetHeldMovement(playerObject, GetFaceDirectionMovementAction(GetPlayerFacingDirection()));
    task->tSubsprMode = playerSprite->subspriteMode;
    playerObject->fixedPriority = 1;
    playerSprite->oam.priority = 1;
    playerSprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    task->tState++;
    return TRUE;
}

static bool8 FallWarpEffect_WaitWeather(struct Task *task)
{
    if (IsWeatherNotFadingIn())
        task->tState++;

    return FALSE;
}

static bool8 FallWarpEffect_StartFall(struct Task *task)
{
    struct Sprite *sprite;
    s16 centerToCornerVecY;
    sprite = &gSprites[gPlayerAvatar.spriteId];
    centerToCornerVecY = -(sprite->centerToCornerVecY << 1);
    sprite->y2 = -(sprite->y + sprite->centerToCornerVecY + gSpriteCoordOffsetY + centerToCornerVecY);
    task->tFallOffset = 1;
    task->tTotalFall = 0;
    gObjectEvents[gPlayerAvatar.objectEventId].invisible = FALSE;
    PlaySE(SE_FALL);
    task->tState++;
    return FALSE;
}

static bool8 FallWarpEffect_Fall(struct Task *task)
{
    struct ObjectEvent *objectEvent;
    struct Sprite *sprite;

    objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    sprite = &gSprites[gPlayerAvatar.spriteId];
    sprite->y2 += task->tFallOffset;
    if (task->tFallOffset < 8)
    {
        task->tTotalFall += task->tFallOffset;

        if (task->tTotalFall & 0xf)
            task->tFallOffset <<= 1;
    }
    if (task->tSetTrigger == FALSE && sprite->y2 >= -16)
    {
        task->tSetTrigger++;
        objectEvent->fixedPriority = 0;
        sprite->subspriteMode = task->tSubsprMode;
        objectEvent->triggerGroundEffectsOnMove = 1;
    }
    if (sprite->y2 >= 0)
    {
        PlaySE(SE_M_STRENGTH);
        objectEvent->triggerGroundEffectsOnStop = 1;
        objectEvent->landingJump = 1;
        sprite->y2 = 0;
        task->tState++;
    }
    return FALSE;
}

static bool8 FallWarpEffect_Land(struct Task *task)
{
    task->tState++;
    task->tVertShake = 4;
    task->tNumShakes = 0;
    SetCameraPanningCallback(NULL);
    return TRUE;
}

static bool8 FallWarpEffect_CameraShake(struct Task *task)
{
    SetCameraPanning(0, task->tVertShake);
    task->tVertShake = -task->tVertShake;
    task->tNumShakes++;

    if ((task->tNumShakes & 3) == 0)
        task->tVertShake >>= 1;

    if (task->tVertShake == 0)
        task->tState++;

    return FALSE;
}

static bool8 FallWarpEffect_End(struct Task *task)
{
    s16 x, y;
    gPlayerAvatar.preventStep = FALSE;
    UnlockPlayerFieldControls();
    CameraObjectReset();
    UnfreezeObjectEvents();
    InstallCameraPanAheadCallback();
    PlayerGetDestCoords(&x, &y);
    // Seafoam Islands
    if (MetatileBehavior_IsSurfableInSeafoamIslands(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
    {
        VarSet(VAR_TEMP_1, 1);
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_SURFING);
    }
    DestroyTask(FindTaskIdByFunc(Task_FallWarpFieldEffect));
    return FALSE;
}

#undef tState
#undef tFallOffset
#undef tTotalFall
#undef tSetTrigger
#undef tSubsprMode
#undef tVertShake
#undef tNumShakes

#define tState   data[0]
#define tGoingUp data[1]

void StartEscalatorWarp(u8 metatileBehavior, u8 priority)
{
    u8 taskId;
    taskId = CreateTask(Task_EscalatorWarpOut, priority);
    gTasks[taskId].tGoingUp = FALSE;
    if (metatileBehavior == MB_UP_ESCALATOR)
    {
        gTasks[taskId].tGoingUp = TRUE;
    }
}

static void Task_EscalatorWarpOut(u8 taskId)
{
    struct Task *task;
    task = &gTasks[taskId];
    while (sEscalatorWarpOutFieldEffectFuncs[task->tState](task));
}

static bool8 EscalatorWarpOut_Init(struct Task *task)
{
    FreezeObjectEvents();
    CameraObjectFreeze();
    StartEscalator(task->tGoingUp);
    task->tState++;
    return FALSE;
}

static bool8 EscalatorWarpOut_WaitForPlayer(struct Task *task)
{
    struct ObjectEvent *objectEvent;
    objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (!ObjectEventIsMovementOverridden(objectEvent) || ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        ObjectEventSetHeldMovement(objectEvent, GetFaceDirectionMovementAction(GetPlayerFacingDirection()));
        task->tState++;
        task->data[2] = 0;
        task->data[3] = 0;
        if ((u8)task->tGoingUp == FALSE)
        {
            task->tState = 4; // jump to EscalatorWarpOut_Down_Ride
        }
        PlaySE(SE_ESCALATOR);
    }
    return FALSE;
}

static bool8 EscalatorWarpOut_Up_Ride(struct Task *task)
{
    RideUpEscalatorOut(task);
    if (task->data[2] > 3)
    {
        FadeOutAtEndOfEscalator();
        task->tState++;
    }
    return FALSE;
}

static bool8 EscalatorWarpOut_Up_End(struct Task *task)
{
    RideUpEscalatorOut(task);
    WarpAtEndOfEscalator();
    return FALSE;
}

static bool8 EscalatorWarpOut_Down_Ride(struct Task *task)
{
    RideDownEscalatorOut(task);
    if (task->data[2] > 3)
    {
        FadeOutAtEndOfEscalator();
        task->tState++;
    }
    return FALSE;
}

static bool8 EscalatorWarpOut_Down_End(struct Task *task)
{
    RideDownEscalatorOut(task);
    WarpAtEndOfEscalator();
    return FALSE;
}

static void RideUpEscalatorOut(struct Task *task)
{
    struct Sprite *sprite;
    sprite = &gSprites[gPlayerAvatar.spriteId];
    sprite->x2 = Cos(0x84, task->data[2]);
    sprite->y2 = Sin(0x94, task->data[2]);
    task->data[3]++;
    if (task->data[3] & 1)
    {
        task->data[2]++;
    }
}

static void RideDownEscalatorOut(struct Task *task)
{
    struct Sprite *sprite;
    sprite = &gSprites[gPlayerAvatar.spriteId];
    sprite->x2 = Cos(0x7c, task->data[2]);
    sprite->y2 = Sin(0x76, task->data[2]);
    task->data[3]++;
    if (task->data[3] & 1)
    {
        task->data[2]++;
    }
}

static void FadeOutAtEndOfEscalator(void)
{
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
}

static void WarpAtEndOfEscalator(void)
{
    if (!gPaletteFade.active && BGMusicStopped() == TRUE)
    {
        StopEscalator();
        WarpIntoMap();
        gFieldCallback = FieldCallback_EscalatorWarpIn;
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(FindTaskIdByFunc(Task_EscalatorWarpOut));
    }
}

#undef tState
#undef tGoingUp

static void FieldCallback_EscalatorWarpIn(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    LockPlayerFieldControls();
    CreateTask(Task_EscalatorWarpIn, 0);
    gFieldCallback = NULL;
}

#define tState data[0]

static void Task_EscalatorWarpIn(u8 taskId)
{
    struct Task *task;
    task = &gTasks[taskId];
    while (sEscalatorWarpInFieldEffectFuncs[task->tState](task));
}

static bool8 EscalatorWarpIn_Init(struct Task *task)
{
    struct ObjectEvent *objectEvent;
    s16 x;
    s16 y;
    u8 behavior;
    CameraObjectFreeze();
    objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    ObjectEventSetHeldMovement(objectEvent, GetFaceDirectionMovementAction(DIR_EAST));
    PlayerGetDestCoords(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y);
    task->tState++;
    task->data[1] = 16;

    if (behavior == MB_DOWN_ESCALATOR)
    {
        // If dest is down escalator tile, player is riding up
        behavior = TRUE;
        task->tState = 3; // jump to EscalatorWarpIn_Up_Init
    }
    else // MB_UP_ESCALATOR
    {
        // If dest is up escalator tile, player is riding down
        behavior = FALSE;
    }
    StartEscalator(behavior);
    return TRUE;
}

static bool8 EscalatorWarpIn_Down_Init(struct Task *task)
{
    struct Sprite *sprite;
    sprite = &gSprites[gPlayerAvatar.spriteId];
    sprite->x2 = Cos(0x84, task->data[1]);
    sprite->y2 = Sin(0x94, task->data[1]);
    task->tState++;
    return FALSE;
}

static bool8 EscalatorWarpIn_Down_Ride(struct Task *task)
{
    struct Sprite *sprite;
    sprite = &gSprites[gPlayerAvatar.spriteId];
    sprite->x2 = Cos(0x84, task->data[1]);
    sprite->y2 = Sin(0x94, task->data[1]);
    task->data[2]++;
    if (task->data[2] & 1)
    {
        task->data[1]--;
    }
    if (task->data[1] == 0)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        task->tState = 5;
    }
    return FALSE;
}

static bool8 EscalatorWarpIn_Up_Init(struct Task *task)
{
    struct Sprite *sprite;
    sprite = &gSprites[gPlayerAvatar.spriteId];
    sprite->x2 = Cos(0x7c, task->data[1]);
    sprite->y2 = Sin(0x76, task->data[1]);
    task->tState++;
    return FALSE;
}

static bool8 EscalatorWarpIn_Up_Ride(struct Task *task)
{
    struct Sprite *sprite;
    sprite = &gSprites[gPlayerAvatar.spriteId];
    sprite->x2 = Cos(0x7c, task->data[1]);
    sprite->y2 = Sin(0x76, task->data[1]);
    task->data[2]++;
    if (task->data[2] & 1)
    {
        task->data[1]--;
    }
    if (task->data[1] == 0)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        task->tState++;
    }
    return FALSE;
}

static bool8 EscalatorWarpIn_WaitForMovement(struct Task *task)
{
    if (IsEscalatorMoving())
    {
        return FALSE;
    }
    StopEscalator();
    task->tState++;
    return TRUE;
}

static bool8 EscalatorWarpIn_End(struct Task *task)
{
    struct ObjectEvent *objectEvent;
    objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        CameraObjectReset();
        UnlockPlayerFieldControls();
        ObjectEventSetHeldMovement(objectEvent, GetWalkNormalMovementAction(DIR_EAST));
        DestroyTask(FindTaskIdByFunc(Task_EscalatorWarpIn));
    }
    return FALSE;
}

#undef tState

#define tState data[0]
#define tMonId data[1]

bool8 FldEff_UseWaterfall(void)
{
    u8 taskId;
    taskId = CreateTask(Task_UseWaterfall, 0xff);
    gTasks[taskId].tMonId = gFieldEffectArguments[0];
    Task_UseWaterfall(taskId);
    return FALSE;
}

static void Task_UseWaterfall(u8 taskId)
{
    while (sWaterfallFieldEffectFuncs[gTasks[taskId].tState](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId]));
}

static bool8 WaterfallFieldEffect_Init(struct Task *task, struct ObjectEvent *objectEvent)
{
    LockPlayerFieldControls();
    gPlayerAvatar.preventStep = TRUE;
    task->tState++;
    return FALSE;
}

static bool8 WaterfallFieldEffect_ShowMon(struct Task *task, struct ObjectEvent *objectEvent)
{
    LockPlayerFieldControls();
    if (!ObjectEventIsMovementOverridden(objectEvent))
    {
        ObjectEventClearHeldMovementIfFinished(objectEvent);
        gFieldEffectArguments[0] = task->tMonId;
        FieldEffectStart(FLDEFF_FIELD_MOVE_SHOW_MON_INIT);
        task->tState++;
    }
    return FALSE;
}

static bool8 WaterfallFieldEffect_WaitForShowMon(struct Task *task, struct ObjectEvent *objectEvent)
{
    if (FieldEffectActiveListContains(FLDEFF_FIELD_MOVE_SHOW_MON))
    {
        return FALSE;
    }
    task->tState++;
    return TRUE;
}

static bool8 WaterfallFieldEffect_RideUp(struct Task *task, struct ObjectEvent *objectEvent)
{
    ObjectEventSetHeldMovement(objectEvent, GetWalkSlowMovementAction(DIR_NORTH));
    task->tState++;
    return FALSE;
}

static bool8 WaterfallFieldEffect_ContinueRideOrEnd(struct Task *task, struct ObjectEvent *objectEvent)
{
    if (!ObjectEventClearHeldMovementIfFinished(objectEvent))
        return FALSE;

    if (MetatileBehavior_IsWaterfall(objectEvent->currentMetatileBehavior))
    {
        // Still ascending waterfall, back to WaterfallFieldEffect_RideUp
        task->tState = 3;
        return TRUE;
    }

    UnlockPlayerFieldControls();
    gPlayerAvatar.preventStep = FALSE;
    DestroyTask(FindTaskIdByFunc(Task_UseWaterfall));
    FieldEffectActiveListRemove(FLDEFF_USE_WATERFALL);
    return FALSE;
}

#undef tState
#undef tMonId

bool8 FldEff_UseDive(void)
{
    u8 taskId;
    taskId = CreateTask(Task_UseDive, 0xff);
    gTasks[taskId].data[15] = gFieldEffectArguments[0];
    gTasks[taskId].data[14] = gFieldEffectArguments[1];
    Task_UseDive(taskId);
    return FALSE;
}

void Task_UseDive(u8 taskId)
{
    while (sDiveFieldEffectFuncs[gTasks[taskId].data[0]](&gTasks[taskId]));
}

static bool8 DiveFieldEffect_Init(struct Task *task)
{
    gPlayerAvatar.preventStep = TRUE;
    task->data[0]++;
    return FALSE;
}

static bool8 DiveFieldEffect_ShowMon(struct Task *task)
{
    LockPlayerFieldControls();
    gFieldEffectArguments[0] = task->data[15];
    FieldEffectStart(FLDEFF_FIELD_MOVE_SHOW_MON_INIT);
    task->data[0]++;
    return FALSE;
}

static bool8 DiveFieldEffect_TryWarp(struct Task *task)
{
    struct MapPosition mapPosition;
    PlayerGetDestCoords(&mapPosition.x, &mapPosition.y);

    // Wait for show mon first
    if (!FieldEffectActiveListContains(FLDEFF_FIELD_MOVE_SHOW_MON))
    {
        TryDoDiveWarp(&mapPosition, gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior);
        DestroyTask(FindTaskIdByFunc(Task_UseDive));
        FieldEffectActiveListRemove(FLDEFF_USE_DIVE);
    }
    return FALSE;
}

void StartLavaridgeGymB1FWarp(u8 priority)
{
    CreateTask(Task_LavaridgeGymB1FWarp, priority);
}

static void Task_LavaridgeGymB1FWarp(u8 taskId)
{
    while (sLavaridgeGymB1FWarpEffectFuncs[gTasks[taskId].data[0]](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId], &gSprites[gPlayerAvatar.spriteId]));
}

static bool8 LavaridgeGymB1FWarpEffect_Init(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FreezeObjectEvents();
    CameraObjectFreeze();
    SetCameraPanningCallback(NULL);
    gPlayerAvatar.preventStep = TRUE;
    objectEvent->fixedPriority = 1;
    task->data[1] = 1;
    task->data[0]++;
    return TRUE;
}

static bool8 LavaridgeGymB1FWarpEffect_CameraShake(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    SetCameraPanning(0, task->data[1]);
    task->data[1] = -task->data[1];
    task->data[2]++;
    if (task->data[2] > 7)
    {
        task->data[2] = 0;
        task->data[0]++;
    }
    return FALSE;
}

static bool8 LavaridgeGymB1FWarpEffect_Launch(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->y2 = 0;
    task->data[3] = 1;
    gFieldEffectArguments[0] = objectEvent->currentCoords.x;
    gFieldEffectArguments[1] = objectEvent->currentCoords.y;
    gFieldEffectArguments[2] = sprite->subpriority - 1;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_ASH_LAUNCH);
    PlaySE(SE_M_EXPLOSION);
    task->data[0]++;
    return TRUE;
}

static bool8 LavaridgeGymB1FWarpEffect_Rise(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    s16 centerToCornerVecY;
    SetCameraPanning(0, task->data[1]);
    if (task->data[1] = -task->data[1], ++task->data[2] <= 17)
    {
        if (!(task->data[2] & 1) && (task->data[1] <= 3))
        {
            task->data[1] <<= 1;
        }
    } else if (!(task->data[2] & 4) && (task->data[1] > 0))
    {
        task->data[1] >>= 1;
    }
    if (task->data[2] > 6)
    {
        centerToCornerVecY = -(sprite->centerToCornerVecY << 1);
        if (sprite->y2 > -(sprite->y + sprite->centerToCornerVecY + gSpriteCoordOffsetY + centerToCornerVecY))
        {
            sprite->y2 -= task->data[3];
            if (task->data[3] <= 7)
            {
                task->data[3]++;
            }
        } else
        {
            task->data[4] = 1;
        }
    }
    if (task->data[5] == 0 && sprite->y2 < -0x10)
    {
        task->data[5]++;
        objectEvent->fixedPriority = 1;
        sprite->oam.priority = 1;
        sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    }
    if (task->data[1] == 0 && task->data[4] != 0)
    {
        task->data[0]++;
    }
    return FALSE;
}

static bool8 LavaridgeGymB1FWarpEffect_FadeOut(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    task->data[0]++;
    return FALSE;
}

static bool8 LavaridgeGymB1FWarpEffect_Warp(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (!gPaletteFade.active && BGMusicStopped() == TRUE)
    {
        WarpIntoMap();
        gFieldCallback = FieldCB_LavaridgeGymB1FWarpExit;
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(FindTaskIdByFunc(Task_LavaridgeGymB1FWarp));
    }
    return FALSE;
}

static void FieldCB_LavaridgeGymB1FWarpExit(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    LockPlayerFieldControls();
    gFieldCallback = NULL;
    CreateTask(Task_LavaridgeGymB1FWarpExit, 0);
}

static void Task_LavaridgeGymB1FWarpExit(u8 taskId)
{
    while (sLavaridgeGymB1FWarpExitEffectFuncs[gTasks[taskId].data[0]](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId], &gSprites[gPlayerAvatar.spriteId]));
}

static bool8 LavaridgeGymB1FWarpExitEffect_Init(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    CameraObjectFreeze();
    FreezeObjectEvents();
    gPlayerAvatar.preventStep = TRUE;
    objectEvent->invisible = TRUE;
    task->data[0]++;
    return FALSE;
}

static bool8 LavaridgeGymB1FWarpExitEffect_StartPopOut(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (IsWeatherNotFadingIn())
    {
        gFieldEffectArguments[0] = objectEvent->currentCoords.x;
        gFieldEffectArguments[1] = objectEvent->currentCoords.y;
        gFieldEffectArguments[2] = sprite->subpriority - 1;
        gFieldEffectArguments[3] = sprite->oam.priority;
        task->data[1] = FieldEffectStart(FLDEFF_ASH_PUFF);
        task->data[0]++;
    }
    return FALSE;
}

static bool8 LavaridgeGymB1FWarpExitEffect_PopOut(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite = &gSprites[task->data[1]];
    if (sprite->animCmdIndex > 1)
    {
        task->data[0]++;
        objectEvent->invisible = FALSE;
        CameraObjectReset();
        PlaySE(SE_M_DIG);
        ObjectEventSetHeldMovement(objectEvent, GetJumpMovementAction(DIR_EAST));
    }
    return FALSE;
}

static bool8 LavaridgeGymB1FWarpExitEffect_End(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
        DestroyTask(FindTaskIdByFunc(Task_LavaridgeGymB1FWarpExit));
    }
    return FALSE;
}

// For the ash effect when jumping off the Lavaridge Gym B1F warp tiles
u8 FldEff_AshLaunch(void)
{
    u8 spriteId;
    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_ASH_LAUNCH], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    gSprites[spriteId].oam.priority = gFieldEffectArguments[3];
    gSprites[spriteId].coordOffsetEnabled = TRUE;
    return spriteId;
}

void SpriteCB_AshLaunch(struct Sprite *sprite)
{
    if (sprite->animEnded)
        FieldEffectStop(sprite, FLDEFF_ASH_LAUNCH);
}

void StartLavaridgeGym1FWarp(u8 priority)
{
    CreateTask(Task_LavaridgeGym1FWarp, priority);
}

static void Task_LavaridgeGym1FWarp(u8 taskId)
{
    while(sLavaridgeGym1FWarpEffectFuncs[gTasks[taskId].data[0]](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId], &gSprites[gPlayerAvatar.spriteId]));
}

static bool8 LavaridgeGym1FWarpEffect_Init(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FreezeObjectEvents();
    CameraObjectFreeze();
    gPlayerAvatar.preventStep = TRUE;
    objectEvent->fixedPriority = 1;
    task->data[0]++;
    return FALSE;
}

static bool8 LavaridgeGym1FWarpEffect_AshPuff(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        if (task->data[1] > 3)
        {
            gFieldEffectArguments[0] = objectEvent->currentCoords.x;
            gFieldEffectArguments[1] = objectEvent->currentCoords.y;
            gFieldEffectArguments[2] = sprite->subpriority - 1;
            gFieldEffectArguments[3] = sprite->oam.priority;
            task->data[1] = FieldEffectStart(FLDEFF_ASH_PUFF);
            task->data[0]++;
        } else
        {
            task->data[1]++;
            ObjectEventSetHeldMovement(objectEvent, GetWalkInPlaceFasterMovementAction(objectEvent->facingDirection));
            PlaySE(SE_LAVARIDGE_FALL_WARP);
        }
    }
    return FALSE;
}

static bool8 LavaridgeGym1FWarpEffect_Disappear(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (gSprites[task->data[1]].animCmdIndex == 2)
    {
        objectEvent->invisible = TRUE;
        task->data[0]++;
    }
    return FALSE;
}

static bool8 LavaridgeGym1FWarpEffect_FadeOut(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (!FieldEffectActiveListContains(FLDEFF_ASH_PUFF))
    {
        TryFadeOutOldMapMusic();
        WarpFadeOutScreen();
        task->data[0]++;
    }
    return FALSE;
}

static bool8 LavaridgeGym1FWarpEffect_Warp(struct Task *task, struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (!gPaletteFade.active && BGMusicStopped() == TRUE)
    {
        WarpIntoMap();
        gFieldCallback = FieldCB_FallWarpExit;
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(FindTaskIdByFunc(Task_LavaridgeGym1FWarp));
    }
    return FALSE;
}

// For the ash effect when a trainer pops out of ash, or when the player enters/exits a warp in Lavaridge Gym 1F
u8 FldEff_AshPuff(void)
{
    u8 spriteId;
    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_ASH_PUFF], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    gSprites[spriteId].oam.priority = gFieldEffectArguments[3];
    gSprites[spriteId].coordOffsetEnabled = TRUE;
    return spriteId;
}

void SpriteCB_AshPuff(struct Sprite *sprite)
{
    if (sprite->animEnded)
        FieldEffectStop(sprite, FLDEFF_ASH_PUFF);
}

#define tState     data[0]
#define tSpinDelay data[1]
#define tNumTurns  data[2]
#define tTimer     data[14]
#define tStartDir  data[15]

void StartEscapeRopeFieldEffect(void)
{
    LockPlayerFieldControls();
    FreezeObjectEvents();
    CreateTask(Task_EscapeRopeWarpOut, 80);
}

static void Task_EscapeRopeWarpOut(u8 taskId)
{
    sEscapeRopeWarpOutEffectFuncs[gTasks[taskId].tState](&gTasks[taskId]);
}

static void EscapeRopeWarpOutEffect_Init(struct Task *task)
{
    task->tState++;
    task->tTimer = 64;
    task->tStartDir = GetPlayerFacingDirection();
}

static void EscapeRopeWarpOutEffect_Spin(struct Task *task)
{
    struct ObjectEvent *objectEvent;
    u8 spinDirections[5] =  {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};
    if (task->tTimer != 0 && (--task->tTimer) == 0)
    {
        TryFadeOutOldMapMusic();
        WarpFadeOutScreen();
    }
    objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (!ObjectEventIsMovementOverridden(objectEvent) || ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        if (task->tTimer == 0 && !gPaletteFade.active && BGMusicStopped() == TRUE)
        {
            SetObjectEventDirection(objectEvent, task->tStartDir);
            SetWarpDestinationToEscapeWarp();
            WarpIntoMap();
            gFieldCallback = FieldCallback_EscapeRopeWarpIn;
            SetMainCallback2(CB2_LoadMap);
            DestroyTask(FindTaskIdByFunc(Task_EscapeRopeWarpOut));
        }
        else if (task->tSpinDelay == 0 || (--task->tSpinDelay) == 0)
        {
            ObjectEventSetHeldMovement(objectEvent, GetFaceDirectionMovementAction(spinDirections[objectEvent->facingDirection]));
            if (task->tNumTurns < 12)
                task->tNumTurns++;
            task->tSpinDelay = 8 >> (task->tNumTurns >> 2);
        }
    }
}

static void (*const sEscapeRopeWarpInEffectFuncs[])(struct Task *) = {
    EscapeRopeWarpInEffect_Init,
    EscapeRopeWarpInEffect_Spin
};

static void FieldCallback_EscapeRopeWarpIn(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    LockPlayerFieldControls();
    FreezeObjectEvents();
    gFieldCallback = NULL;
    gObjectEvents[gPlayerAvatar.objectEventId].invisible = TRUE;
    CreateTask(Task_EscapeRopeWarpIn, 0);
}

static void Task_EscapeRopeWarpIn(u8 taskId)
{
    sEscapeRopeWarpInEffectFuncs[gTasks[taskId].tState](&gTasks[taskId]);
}

static void EscapeRopeWarpInEffect_Init(struct Task *task)
{
    if (IsWeatherNotFadingIn())
    {
        task->tState++;
        task->tStartDir = GetPlayerFacingDirection();
    }
}

static void EscapeRopeWarpInEffect_Spin(struct Task *task)
{
    u8 spinDirections[5] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};
    struct ObjectEvent *objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (task->tSpinDelay == 0 || (--task->tSpinDelay) == 0)
    {
        if (ObjectEventIsMovementOverridden(objectEvent) && !ObjectEventClearHeldMovementIfFinished(objectEvent))
        {
            return;
        }
        if (task->tNumTurns >= 32 && task->tStartDir == GetPlayerFacingDirection())
        {
            objectEvent->invisible = FALSE;
            UnlockPlayerFieldControls();
            UnfreezeObjectEvents();
            DestroyTask(FindTaskIdByFunc(Task_EscapeRopeWarpIn));
            return;
        }
        ObjectEventSetHeldMovement(objectEvent, GetFaceDirectionMovementAction(spinDirections[objectEvent->facingDirection]));
        if (task->tNumTurns < 32)
            task->tNumTurns++;
        task->tSpinDelay = task->tNumTurns >> 2;
    }
    objectEvent->invisible ^= 1;
}

#undef tState
#undef tSpinDelay
#undef tNumTurns
#undef tTimer
#undef tStartDir

#define tState data[0]

void FldEff_TeleportWarpOut(void)
{
    CreateTask(Task_TeleportWarpOut, 0);
}

static void (*const sTeleportWarpOutFieldEffectFuncs[])(struct Task *) = {
    TeleportWarpOutFieldEffect_Init,
    TeleportWarpOutFieldEffect_SpinGround,
    TeleportWarpOutFieldEffect_SpinExit,
    TeleportWarpOutFieldEffect_End
};

static void Task_TeleportWarpOut(u8 taskId)
{
    sTeleportWarpOutFieldEffectFuncs[gTasks[taskId].tState](&gTasks[taskId]);
}

static void TeleportWarpOutFieldEffect_Init(struct Task *task)
{
    LockPlayerFieldControls();
    FreezeObjectEvents();
    CameraObjectFreeze();
    task->data[15] = GetPlayerFacingDirection();
    task->tState++;
}

static void TeleportWarpOutFieldEffect_SpinGround(struct Task *task)
{
    u8 spinDirections[5] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};
    struct ObjectEvent *objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (task->data[1] == 0 || (--task->data[1]) == 0)
    {
        ObjectEventTurn(objectEvent, spinDirections[objectEvent->facingDirection]);
        task->data[1] = 8;
        task->data[2]++;
    }
    if (task->data[2] > 7 && task->data[15] == objectEvent->facingDirection)
    {
        task->tState++;
        task->data[1] = 4;
        task->data[2] = 8;
        task->data[3] = 1;
        PlaySE(SE_WARP_IN);
    }
}

static void TeleportWarpOutFieldEffect_SpinExit(struct Task *task)
{
    u8 spinDirections[5] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};
    struct ObjectEvent *objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[gPlayerAvatar.spriteId];
    if ((--task->data[1]) <= 0)
    {
        task->data[1] = 4;
        ObjectEventTurn(objectEvent, spinDirections[objectEvent->facingDirection]);
    }
    sprite->y -= task->data[3];
    task->data[4] += task->data[3];
    if ((--task->data[2]) <= 0 && (task->data[2] = 4, task->data[3] < 8))
    {
        task->data[3] <<= 1;
    }
    if (task->data[4] > 8 && (sprite->oam.priority = 1, sprite->subspriteMode != SUBSPRITES_OFF))
    {
        sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    }
    if (task->data[4] >= DISPLAY_HEIGHT + 8)
    {
        task->tState++;
        TryFadeOutOldMapMusic();
        WarpFadeOutScreen();
    }
}

static void TeleportWarpOutFieldEffect_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        if (BGMusicStopped() == TRUE)
        {
            WarpIntoMap();
            SetMainCallback2(CB2_LoadMap);
            gFieldCallback = FieldCallback_TeleportWarpIn;
            DestroyTask(FindTaskIdByFunc(Task_TeleportWarpOut));
        }
    }
}

static void FieldCallback_TeleportWarpIn(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    LockPlayerFieldControls();
    FreezeObjectEvents();
    gFieldCallback = NULL;
    gObjectEvents[gPlayerAvatar.objectEventId].invisible = TRUE;
    CameraObjectFreeze();
    CreateTask(Task_TeleportWarpIn, 0);
}

static void (*const sTeleportWarpInFieldEffectFuncs[])(struct Task *) = {
    TeleportWarpInFieldEffect_Init,
    TeleportWarpInFieldEffect_SpinEnter,
    TeleportWarpInFieldEffect_SpinGround
};

static void Task_TeleportWarpIn(u8 taskId)
{
    sTeleportWarpInFieldEffectFuncs[gTasks[taskId].data[0]](&gTasks[taskId]);
}

static void TeleportWarpInFieldEffect_Init(struct Task *task)
{
    struct Sprite *sprite;
    s16 centerToCornerVecY;
    if (IsWeatherNotFadingIn())
    {
        sprite = &gSprites[gPlayerAvatar.spriteId];
        centerToCornerVecY = -(sprite->centerToCornerVecY << 1);
        sprite->y2 = -(sprite->y + sprite->centerToCornerVecY + gSpriteCoordOffsetY + centerToCornerVecY);
        gObjectEvents[gPlayerAvatar.objectEventId].invisible = FALSE;
        task->data[0]++;
        task->data[1] = 8;
        task->data[2] = 1;
        task->data[14] = sprite->subspriteMode;
        task->data[15] = GetPlayerFacingDirection();
        PlaySE(SE_WARP_IN);
    }
}

static void TeleportWarpInFieldEffect_SpinEnter(struct Task *task)
{
    u8 spinDirections[5] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};
    struct ObjectEvent *objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[gPlayerAvatar.spriteId];
    if ((sprite->y2 += task->data[1]) >= -8)
    {
        if (task->data[13] == 0)
        {
            task->data[13]++;
            objectEvent->triggerGroundEffectsOnMove = TRUE;
            sprite->subspriteMode = task->data[14];
        }
    } else
    {
        sprite->oam.priority = 1;
        if (sprite->subspriteMode != SUBSPRITES_OFF)
        {
            sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        }
    }
    if (sprite->y2 >= -0x30 && task->data[1] > 1 && !(sprite->y2 & 1))
    {
        task->data[1]--;
    }
    if ((--task->data[2]) == 0)
    {
        task->data[2] = 4;
        ObjectEventTurn(objectEvent, spinDirections[objectEvent->facingDirection]);
    }
    if (sprite->y2 >= 0)
    {
        sprite->y2 = 0;
        task->data[0]++;
        task->data[1] = 1;
        task->data[2] = 0;
    }
}

static void TeleportWarpInFieldEffect_SpinGround(struct Task *task)
{
    u8 spinDirections[5] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};
    struct ObjectEvent *objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if ((--task->data[1]) == 0)
    {
        ObjectEventTurn(objectEvent, spinDirections[objectEvent->facingDirection]);
        task->data[1] = 8;
        if ((++task->data[2]) > 4 && task->data[14] == objectEvent->facingDirection)
        {
            UnlockPlayerFieldControls();
            CameraObjectReset();
            UnfreezeObjectEvents();
            DestroyTask(FindTaskIdByFunc(Task_TeleportWarpIn));
        }
    }
}

// Task data for Task_FieldMoveShowMonOutDoors
#define tState       data[0]
#define tWinHoriz    data[1]
#define tWinVert     data[2]
#define tWinIn       data[3]
#define tWinOut      data[4]
#define tBgHoriz     data[5]
#define tBgVert      data[6]
#define tMonSpriteId data[15]

// Sprite data for field move mon sprite
#define sSpecies       data[0]
#define sOnscreenTimer data[1]
#define sSlidOffscreen data[7]

// There are two variants (outdoor/indoor) of the "show mon for a field move" effect
// Outdoor has a black background with thick white streaks and appears from the right by stretching vertically and horizontally
// Indoor has blue background with thin white streaks and appears from the left by stretching horizontally
// For both the background streaks move to the right, and the mon sprite enters from the right and exits left
bool8 FldEff_FieldMoveShowMon(void)
{
    u8 taskId;
    if (IsMapTypeOutdoors(GetCurrentMapType()) == TRUE)
        taskId = CreateTask(Task_FieldMoveShowMonOutdoors, 0xff);
    else
        taskId = CreateTask(Task_FieldMoveShowMonIndoors, 0xff);

    gTasks[taskId].tMonSpriteId = InitFieldMoveMonSprite(gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    return FALSE;
}

#define SHOW_MON_CRY_NO_DUCKING (1 << 31)

bool8 FldEff_FieldMoveShowMonInit(void)
{
    struct Pokemon *pokemon;
    bool32 noDucking = gFieldEffectArguments[0] & SHOW_MON_CRY_NO_DUCKING;
    pokemon = &gPlayerParty[(u8)gFieldEffectArguments[0]];
    gFieldEffectArguments[0] = GetMonData(pokemon, MON_DATA_SPECIES);
    gFieldEffectArguments[1] = GetMonData(pokemon, MON_DATA_IS_SHINY);
    gFieldEffectArguments[2] = GetMonData(pokemon, MON_DATA_PERSONALITY);
    gFieldEffectArguments[0] |= noDucking;
    FieldEffectStart(FLDEFF_FIELD_MOVE_SHOW_MON);
    FieldEffectActiveListRemove(FLDEFF_FIELD_MOVE_SHOW_MON_INIT);
    return FALSE;
}

static void (*const sFieldMoveShowMonOutdoorsEffectFuncs[])(struct Task *) = {
    FieldMoveShowMonOutdoorsEffect_Init,
    FieldMoveShowMonOutdoorsEffect_LoadGfx,
    FieldMoveShowMonOutdoorsEffect_CreateBanner,
    FieldMoveShowMonOutdoorsEffect_WaitForMon,
    FieldMoveShowMonOutdoorsEffect_ShrinkBanner,
    FieldMoveShowMonOutdoorsEffect_RestoreBg,
    FieldMoveShowMonOutdoorsEffect_End,
};

static void Task_FieldMoveShowMonOutdoors(u8 taskId)
{
    sFieldMoveShowMonOutdoorsEffectFuncs[gTasks[taskId].tState](&gTasks[taskId]);
}

static void FieldMoveShowMonOutdoorsEffect_Init(struct Task *task)
{
    task->data[11] = REG_WININ;
    task->data[12] = REG_WINOUT;
    StoreWordInTwoHalfwords((u16*) &task->data[13], (u32)gMain.vblankCallback);
    task->tWinHoriz = WIN_RANGE(DISPLAY_WIDTH, DISPLAY_WIDTH + 1);
    task->tWinVert = WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1);
    task->tWinIn = WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR;
    task->tWinOut = WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR;
    SetGpuReg(REG_OFFSET_WIN0H, task->tWinHoriz);
    SetGpuReg(REG_OFFSET_WIN0V, task->tWinVert);
    SetGpuReg(REG_OFFSET_WININ, task->tWinIn);
    SetGpuReg(REG_OFFSET_WINOUT, task->tWinOut);
    SetVBlankCallback(VBlankCB_FieldMoveShowMonOutdoors);
    task->tState++;
}

static void FieldMoveShowMonOutdoorsEffect_LoadGfx(struct Task *task)
{
    u16 offset = ((REG_BG0CNT >> 2) << 14);
    u16 delta = ((REG_BG0CNT >> 8) << 11);
    CpuCopy16(sFieldMoveStreaksOutdoors_Gfx, (void *)(VRAM + offset), 0x200);
    CpuFill32(0, (void *)(VRAM + delta), 0x800);
    LoadPalette(sFieldMoveStreaksOutdoors_Pal, BG_PLTT_ID(15), sizeof(sFieldMoveStreaksOutdoors_Pal));
    LoadFieldMoveOutdoorStreaksTilemap(delta);
    task->tState++;
}

static void FieldMoveShowMonOutdoorsEffect_CreateBanner(struct Task *task)
{
    s16 horiz;
    s16 vertHi;
    s16 vertLo;
    task->tBgHoriz -= 16;
    horiz = ((u16)task->tWinHoriz >> 8);
    vertHi = ((u16)task->tWinVert >> 8);
    vertLo = ((u16)task->tWinVert & 0xff);
    horiz -= 16;
    vertHi -= 2;
    vertLo += 2;

    if (horiz < 0)
        horiz = 0;

    if (vertHi < DISPLAY_HEIGHT / 4)
        vertHi = DISPLAY_HEIGHT / 4;

    if (vertLo > DISPLAY_WIDTH / 2)
        vertLo = DISPLAY_WIDTH / 2;

    task->tWinHoriz = (horiz << 8) | (task->tWinHoriz & 0xff);
    task->tWinVert = (vertHi << 8) | vertLo;
    if (horiz == 0 && vertHi == DISPLAY_HEIGHT / 4 && vertLo == DISPLAY_WIDTH / 2)
    {
        gSprites[task->tMonSpriteId].callback = SpriteCB_FieldMoveMonSlideOnscreen;
        task->tState++;
    }
}

static void FieldMoveShowMonOutdoorsEffect_WaitForMon(struct Task *task)
{
    task->tBgHoriz -= 16;

    if (gSprites[task->tMonSpriteId].sSlidOffscreen)
        task->tState++;
}

static void FieldMoveShowMonOutdoorsEffect_ShrinkBanner(struct Task *task)
{
    s16 vertHi;
    s16 vertLo;
    task->tBgHoriz -= 16;
    vertHi = (task->tWinVert >> 8);
    vertLo = (task->tWinVert & 0xFF);
    vertHi += 6;
    vertLo -= 6;

    if (vertHi > DISPLAY_HEIGHT / 2)
        vertHi = DISPLAY_HEIGHT / 2;

    if (vertLo < DISPLAY_HEIGHT / 2 + 1)
        vertLo = DISPLAY_HEIGHT / 2 + 1;

    task->tWinVert = (vertHi << 8) | vertLo;

    if (vertHi == DISPLAY_HEIGHT / 2 && vertLo == DISPLAY_HEIGHT / 2 + 1)
        task->tState++;
}

static void FieldMoveShowMonOutdoorsEffect_RestoreBg(struct Task *task)
{
    u16 bg0cnt = (REG_BG0CNT >> 8) << 11;
    CpuFill32(0, (void *)VRAM + bg0cnt, 0x800);
    task->tWinHoriz = DISPLAY_WIDTH + 1;
    task->tWinVert = DISPLAY_HEIGHT + 1;
    task->tWinIn = task->data[11];
    task->tWinOut = task->data[12];
    task->tState++;
}

static void FieldMoveShowMonOutdoorsEffect_End(struct Task *task)
{
    IntrCallback callback;
    LoadWordFromTwoHalfwords((u16 *)&task->data[13], (u32 *)&callback);
    SetVBlankCallback(callback);
    InitTextBoxGfxAndPrinters();
    FreeResourcesAndDestroySprite(&gSprites[task->tMonSpriteId], task->tMonSpriteId);
    FieldEffectActiveListRemove(FLDEFF_FIELD_MOVE_SHOW_MON);
    DestroyTask(FindTaskIdByFunc(Task_FieldMoveShowMonOutdoors));
}

static void VBlankCB_FieldMoveShowMonOutdoors(void)
{
    IntrCallback callback;
    struct Task *task = &gTasks[FindTaskIdByFunc(Task_FieldMoveShowMonOutdoors)];
    LoadWordFromTwoHalfwords((u16 *)&task->data[13], (u32 *)&callback);
    callback();
    SetGpuReg(REG_OFFSET_WIN0H, task->tWinHoriz);
    SetGpuReg(REG_OFFSET_WIN0V, task->tWinVert);
    SetGpuReg(REG_OFFSET_WININ, task->tWinIn);
    SetGpuReg(REG_OFFSET_WINOUT, task->tWinOut);
    SetGpuReg(REG_OFFSET_BG0HOFS, task->tBgHoriz);
    SetGpuReg(REG_OFFSET_BG0VOFS, task->tBgVert);
}

static void LoadFieldMoveOutdoorStreaksTilemap(u16 offs)
{
    u16 i;
    u16 *dest;
    dest = (u16 *)(VRAM + ARRAY_COUNT(sFieldMoveStreaksOutdoors_Tilemap) + offs);
    for (i = 0; i < ARRAY_COUNT(sFieldMoveStreaksOutdoors_Tilemap); i++, dest++)
    {
        *dest = sFieldMoveStreaksOutdoors_Tilemap[i] | 0xF000;
    }
}

#undef tState
#undef tWinHoriz
#undef tWinVert
#undef tWinIn
#undef tWinOut
#undef tBgHoriz
#undef tBgVert
#undef tMonSpriteId

// Task data for Task_FieldMoveShowMonIndoors
#define tState       data[0]
#define tBgHoriz     data[1]
#define tBgVert      data[2]
#define tBgOffsetIdx data[3]
#define tBgOffset    data[4]
#define tMonSpriteId data[15]

static void (*const sFieldMoveShowMonIndoorsEffectFuncs[])(struct Task *) = {
    FieldMoveShowMonIndoorsEffect_Init,
    FieldMoveShowMonIndoorsEffect_LoadGfx,
    FieldMoveShowMonIndoorsEffect_SlideBannerOn,
    FieldMoveShowMonIndoorsEffect_WaitForMon,
    FieldMoveShowMonIndoorsEffect_RestoreBg,
    FieldMoveShowMonIndoorsEffect_SlideBannerOff,
    FieldMoveShowMonIndoorsEffect_End,
};

static void Task_FieldMoveShowMonIndoors(u8 taskId)
{
    sFieldMoveShowMonIndoorsEffectFuncs[gTasks[taskId].tState](&gTasks[taskId]);
}

static void FieldMoveShowMonIndoorsEffect_Init(struct Task *task)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, task->tBgHoriz);
    SetGpuReg(REG_OFFSET_BG0VOFS, task->tBgVert);
    StoreWordInTwoHalfwords((u16 *)&task->data[13], (u32)gMain.vblankCallback);
    SetVBlankCallback(VBlankCB_FieldMoveShowMonIndoors);
    task->tState++;
}

static void FieldMoveShowMonIndoorsEffect_LoadGfx(struct Task *task)
{
    u16 offset;
    u16 delta;
    offset = ((REG_BG0CNT >> 2) << 14);
    delta = ((REG_BG0CNT >> 8) << 11);
    task->data[12] = delta;
    CpuCopy16(sFieldMoveStreaksIndoors_Gfx, (void *)(VRAM + offset), 0x80);
    CpuFill32(0, (void *)(VRAM + delta), 0x800);
    LoadPalette(sFieldMoveStreaksIndoors_Pal, BG_PLTT_ID(15), sizeof(sFieldMoveStreaksIndoors_Pal));
    task->tState++;
}

static void FieldMoveShowMonIndoorsEffect_SlideBannerOn(struct Task *task)
{
    if (SlideIndoorBannerOnscreen(task))
    {
        SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, DISPLAY_WIDTH));
        SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(DISPLAY_HEIGHT / 4, DISPLAY_HEIGHT - DISPLAY_HEIGHT / 4));
        gSprites[task->tMonSpriteId].callback = SpriteCB_FieldMoveMonSlideOnscreen;
        task->tState++;
    }
    AnimateIndoorShowMonBg(task);
}

static void FieldMoveShowMonIndoorsEffect_WaitForMon(struct Task *task)
{
    AnimateIndoorShowMonBg(task);
    if (gSprites[task->tMonSpriteId].sSlidOffscreen)
        task->tState++;
}

static void FieldMoveShowMonIndoorsEffect_RestoreBg(struct Task *task)
{
    AnimateIndoorShowMonBg(task);
    task->tBgOffsetIdx = task->tBgHoriz & 7;
    task->tBgOffset = 0;
    SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0xFF, 0xFF));
    SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(0xFF, 0xFF));
    task->tState++;
}

static void FieldMoveShowMonIndoorsEffect_SlideBannerOff(struct Task *task)
{
    AnimateIndoorShowMonBg(task);
    if (SlideIndoorBannerOffscreen(task))
        task->tState++;
}

static void FieldMoveShowMonIndoorsEffect_End(struct Task *task)
{
    IntrCallback intrCallback;
    u16 bg0cnt;
    bg0cnt = (REG_BG0CNT >> 8) << 11;
    CpuFill32(0, (void *)VRAM + bg0cnt, 0x800);
    LoadWordFromTwoHalfwords((u16 *)&task->data[13], (u32 *)&intrCallback);
    SetVBlankCallback(intrCallback);
    InitTextBoxGfxAndPrinters();
    FreeResourcesAndDestroySprite(&gSprites[task->tMonSpriteId], task->tMonSpriteId);
    FieldEffectActiveListRemove(FLDEFF_FIELD_MOVE_SHOW_MON);
    DestroyTask(FindTaskIdByFunc(Task_FieldMoveShowMonIndoors));
}

static void VBlankCB_FieldMoveShowMonIndoors(void)
{
    IntrCallback intrCallback;
    struct Task *task;
    task = &gTasks[FindTaskIdByFunc(Task_FieldMoveShowMonIndoors)];
    LoadWordFromTwoHalfwords((u16 *)&task->data[13], (u32 *)&intrCallback);
    intrCallback();
    SetGpuReg(REG_OFFSET_BG0HOFS, task->tBgHoriz);
    SetGpuReg(REG_OFFSET_BG0VOFS, task->tBgVert);
}

static void AnimateIndoorShowMonBg(struct Task *task)
{
    task->tBgHoriz -= 16;
    task->tBgOffsetIdx += 16;
}

static bool8 SlideIndoorBannerOnscreen(struct Task *task)
{
    u16 i;
    u16 srcOffs;
    u16 dstOffs;
    u16 *dest;

    if (task->tBgOffset >= 32)
        return TRUE;

    dstOffs = (task->tBgOffsetIdx >> 3) & 0x1f;
    if (dstOffs >= task->tBgOffset)
    {
        dstOffs = (32 - dstOffs) & 0x1f;
        srcOffs = (32 - task->tBgOffset) & 0x1f;
        dest = (u16 *)(VRAM + 0x140 + (u16)task->data[12]);
        for (i = 0; i < 10; i++)
        {
            dest[dstOffs + i * 32] = sFieldMoveStreaksIndoors_Tilemap[srcOffs + i * 32];
            dest[dstOffs + i * 32] |= 0xf000;

            dest[((dstOffs + 1) & 0x1f) + i * 32] = sFieldMoveStreaksIndoors_Tilemap[((srcOffs + 1) & 0x1f) + i * 32] | 0xf000;
            dest[((dstOffs + 1) & 0x1f) + i * 32] |= 0xf000;
        }
        task->tBgOffset += 2;
    }
    return FALSE;
}

static bool8 SlideIndoorBannerOffscreen(struct Task *task)
{
    u16 i;
    u16 dstOffs;
    u16 *dest;

    if (task->tBgOffset >= 32)
        return TRUE;

    dstOffs = task->tBgOffsetIdx >> 3;
    if (dstOffs >= task->tBgOffset)
    {
        dstOffs = (task->tBgHoriz >> 3) & 0x1f;
        dest = (u16 *)(VRAM + 0x140 + (u16)task->data[12]);
        for (i = 0; i < 10; i++)
        {
            dest[dstOffs + i * 32] = 0xf000;
            dest[((dstOffs + 1) & 0x1f) + i * 32] = 0xf000;
        }
        task->tBgOffset += 2;
    }
    return FALSE;
}

#undef tState
#undef tBgHoriz
#undef tBgVert
#undef tBgOffsetIdx
#undef tBgOffset
#undef tMonSpriteId

static u8 InitFieldMoveMonSprite(u32 species, bool8 isShiny, u32 personality)
{
    bool16 noDucking;
    u8 monSprite;
    struct Sprite *sprite;
    noDucking = (species & SHOW_MON_CRY_NO_DUCKING) >> 16;
    species &= ~SHOW_MON_CRY_NO_DUCKING;
    monSprite = CreateMonSprite_FieldMove(species, isShiny, personality, 320, 80, 0);
    sprite = &gSprites[monSprite];
    sprite->callback = SpriteCallbackDummy;
    sprite->oam.priority = 0;
    sprite->sSpecies = species;
    sprite->data[6] = noDucking;
    return monSprite;
}

static void SpriteCB_FieldMoveMonSlideOnscreen(struct Sprite *sprite)
{
    if ((sprite->x -= 20) <= DISPLAY_WIDTH / 2)
    {
        sprite->x = DISPLAY_WIDTH / 2;
        sprite->sOnscreenTimer = 30;
        sprite->callback = SpriteCB_FieldMoveMonWaitAfterCry;
        if (sprite->data[6])
            PlayCry_NormalNoDucking(sprite->sSpecies, 0, CRY_VOLUME_RS, CRY_PRIORITY_NORMAL);
        else
            PlayCry_Normal(sprite->sSpecies, 0);
    }
}

static void SpriteCB_FieldMoveMonWaitAfterCry(struct Sprite *sprite)
{
    if ((--sprite->sOnscreenTimer) == 0)
        sprite->callback = SpriteCB_FieldMoveMonSlideOffscreen;
}

static void SpriteCB_FieldMoveMonSlideOffscreen(struct Sprite *sprite)
{
    if (sprite->x < -64)
        sprite->sSlidOffscreen = TRUE;
    else
        sprite->x -= 20;
}

#undef tState
#undef tMonSpriteId
#undef sSpecies
#undef sSlidOffscreen
#undef sOnscreenTimer

#define tState data[0]
#define tDestX data[1]
#define tDestY data[2]
#define tMonId data[15]

u8 FldEff_UseSurf(void)
{
    u8 taskId = CreateTask(Task_SurfFieldEffect, 0xff);
    gTasks[taskId].tMonId = gFieldEffectArguments[0];
    Overworld_ClearSavedMusic();
    if (Overworld_MusicCanOverrideMapMusic(MUS_RG_SURF))
        Overworld_ChangeMusicTo(MUS_RG_SURF);
    return FALSE;
}

static void (*const sSurfFieldEffectFuncs[])(struct Task *) = {
    SurfFieldEffect_Init,
    SurfFieldEffect_FieldMovePose,
    SurfFieldEffect_ShowMon,
    SurfFieldEffect_JumpOnSurfBlob,
    SurfFieldEffect_End,
};

static void Task_SurfFieldEffect(u8 taskId)
{
    sSurfFieldEffectFuncs[gTasks[taskId].tState](&gTasks[taskId]);
}

static void SurfFieldEffect_Init(struct Task *task)
{
    LockPlayerFieldControls();
    FreezeObjectEvents();
    gPlayerAvatar.preventStep = TRUE;
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_SURFING);
    PlayerGetDestCoords(&task->tDestX, &task->tDestY);
    MoveCoords(gObjectEvents[gPlayerAvatar.objectEventId].movementDirection, &task->tDestX, &task->tDestY);
    task->tState++;
}

static void SurfFieldEffect_FieldMovePose(struct Task *task)
{
    struct ObjectEvent *objectEvent;
    objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (!ObjectEventIsMovementOverridden(objectEvent) || ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        SetPlayerAvatarFieldMove();
        ObjectEventSetHeldMovement(objectEvent, MOVEMENT_ACTION_START_ANIM_IN_DIRECTION);
        task->tState++;
    }
}

static void SurfFieldEffect_ShowMon(struct Task *task)
{
    struct ObjectEvent *objectEvent;
    objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (ObjectEventCheckHeldMovementStatus(objectEvent))
    {
        gFieldEffectArguments[0] = task->tMonId | SHOW_MON_CRY_NO_DUCKING;
        FieldEffectStart(FLDEFF_FIELD_MOVE_SHOW_MON_INIT);
        task->tState++;
    }
}

static void SurfFieldEffect_JumpOnSurfBlob(struct Task *task)
{
    struct ObjectEvent *objectEvent;
    if (!FieldEffectActiveListContains(FLDEFF_FIELD_MOVE_SHOW_MON))
    {
        objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
        ObjectEventSetGraphicsId(objectEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_SURFING));
        ObjectEventClearHeldMovementIfFinished(objectEvent);
        ObjectEventSetHeldMovement(objectEvent, GetJumpSpecialMovementAction(objectEvent->movementDirection));
        gFieldEffectArguments[0] = task->tDestX;
        gFieldEffectArguments[1] = task->tDestY;
        gFieldEffectArguments[2] = gPlayerAvatar.objectEventId;
        objectEvent->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
        task->tState++;
    }
}

static void SurfFieldEffect_End(struct Task *task)
{
    struct ObjectEvent *objectEvent;
    objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        gPlayerAvatar.preventStep = FALSE;
        gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_CONTROLLABLE;
        ObjectEventSetHeldMovement(objectEvent, GetFaceDirectionMovementAction(objectEvent->movementDirection));
        SetSurfBlob_BobState(objectEvent->fieldEffectSpriteId, BOB_PLAYER_AND_MON);
        UnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        FieldEffectActiveListRemove(FLDEFF_USE_SURF);
        DestroyTask(FindTaskIdByFunc(Task_SurfFieldEffect));
    }
}

#undef tState
#undef tDestX
#undef tDestY
#undef tMonId
