#include "global.h"
#include "main.h"
#include "text.h"
#include "menu.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "palette.h"
#include "party_menu.h"
#include "trig.h"
#include "overworld.h"
#include "event_data.h"
#include "secret_base.h"
#include "string_util.h"
#include "international_string_util.h"
#include "strings.h"
#include "text_window.h"
#include "constants/songs.h"
#include "m4a.h"
#include "field_effect.h"
#include "field_specials.h"
#include "fldeff.h"
#include "region_map.h"
#include "constants/region_map_sections.h"
#include "heal_location.h"
#include "constants/field_specials.h"
#include "constants/heal_locations.h"
#include "constants/map_types.h"
#include "constants/rgb.h"
#include "constants/weather.h"

/*
 *  This file handles region maps generally, and the map used when selecting a teleport destination.
 *  Specific features of other region map uses are handled elsewhere
 *
 *  For the region map in the pokenav, see pokenav_region_map.c
 *  For the region map in the pokedex, see pokdex_area_screen.c/pokedex_area_region_map.c
 *  For the region map that can be viewed on the wall of pokemon centers, see field_region_map.c
 *
 */

#define MAP_WIDTH 28
#define MAP_HEIGHT 15
#define MAPCURSOR_X_MIN 1
#define MAPCURSOR_Y_MIN 2
#define MAPCURSOR_X_MAX (MAPCURSOR_X_MIN + MAP_WIDTH - 1)
#define MAPCURSOR_Y_MAX (MAPCURSOR_Y_MIN + MAP_HEIGHT - 1)

#define TELEPORTDESTICON_RED_OUTLINE 6

enum {
    TAG_CURSOR,
    TAG_PLAYER_ICON,
    TAG_TELEPORT_ICON,
};

// Window IDs for the teleport map
enum {
    WIN_MAPSEC_NAME,
    WIN_MAPSEC_NAME_TALL, // For teleport destinations with subtitles (just Ever Grande)
    WIN_TELEPORT_TO_WHERE,
};

struct MultiNameTeleportDest
{
    const u8 *const *name;
    u16 mapSecId;
    u16 flag;
};

static EWRAM_DATA struct RegionMap *sRegionMap = NULL;

static EWRAM_DATA struct {
    void (*callback)(void);
    u16 state;
    u16 mapSecId;
    struct RegionMap regionMap;
    u8 tileBuffer[0x1c0];
    u8 nameBuffer[0x26]; // never read
    bool8 choseTeleportLocation;
} *sTeleportMap = NULL;

static bool32 sDrawTeleportDestTextWindow;

static u8 ProcessRegionMapInput_Full(void);
static u8 MoveRegionMapCursor_Full(void);
static u8 ProcessRegionMapInput_Zoomed(void);
static u8 MoveRegionMapCursor_Zoomed(void);
static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation);
static u16 GetMapSecIdAt(u16 x, u16 y);
static void RegionMap_SetBG2XAndBG2Y(s16 x, s16 y);
static void InitMapBasedOnPlayerLocation(void);
static void RegionMap_InitializeStateBasedOnSSTidalLocation(void);
static u8 GetMapsecType(u16 mapSecId);
static u16 CorrectSpecialMapSecId_Internal(u16 mapSecId);
static bool32 IsPlayerInAquaHideout(u8 mapSecId);
static void GetPositionOfCursorWithinMapSec(void);
static bool8 RegionMap_IsMapSecIdInNextRow(u16 y);
static void SpriteCB_CursorMapFull(struct Sprite *sprite);
static void FreeRegionMapCursorSprite(void);
static void HideRegionMapPlayerIcon(void);
static void UnhideRegionMapPlayerIcon(void);
static void SpriteCB_PlayerIconMapZoomed(struct Sprite *sprite);
static void SpriteCB_PlayerIconMapFull(struct Sprite *sprite);
static void SpriteCB_PlayerIcon(struct Sprite *sprite);
static void VBlankCB_TeleportMap(void);
static void CB2_TeleportMap(void);
static void SetTeleportMapCallback(void callback(void));
static void DrawTeleportDestTextWindow(void);
static void LoadTeleportDestIcons(void);
static void CreateTeleportDestIcons(void);
static void TryCreateRedOutlineTeleportDestIcons(void);
static void SpriteCB_TeleportDestIcon(struct Sprite *sprite);
static void CB_FadeInTeleportMap(void);
static void CB_HandleTeleportMapInput(void);
static void CB_ExitTeleportMap(void);

static const u16 sRegionMapCursorPal[] = INCBIN_U16("graphics/pokenav/region_map/cursor.gbapal");
static const u32 sRegionMapCursorSmallGfxLZ[] = INCBIN_U32("graphics/pokenav/region_map/cursor_small.4bpp.lz");
static const u32 sRegionMapCursorLargeGfxLZ[] = INCBIN_U32("graphics/pokenav/region_map/cursor_large.4bpp.lz");
static const u16 sRegionMapBg_Pal[] = INCBIN_U16("graphics/pokenav/region_map/map.gbapal");
static const u32 sRegionMapBg_GfxLZ[] = INCBIN_U32("graphics/pokenav/region_map/map.8bpp.lz");
static const u32 sRegionMapBg_TilemapLZ[] = INCBIN_U32("graphics/pokenav/region_map/map.bin.lz");
static const u16 sRegionMapPlayerIcon_RedPal[] = INCBIN_U16("graphics/pokenav/region_map/red_icon.gbapal");
static const u8 sRegionMapPlayerIcon_RedGfx[] = INCBIN_U8("graphics/pokenav/region_map/red_icon.4bpp");
static const u16 sRegionMapPlayerIcon_LeafPal[] = INCBIN_U16("graphics/pokenav/region_map/leaf_icon.gbapal");
static const u8 sRegionMapPlayerIcon_LeafGfx[] = INCBIN_U8("graphics/pokenav/region_map/leaf_icon.4bpp");

#include "data/region_map/region_map_layout.h"
#include "data/region_map/region_map_entries.h"

static const u16 sRegionMap_SpecialPlaceLocations[][2] =
{
    {MAPSEC_UNDERWATER_105,             MAPSEC_ROUTE_105},
    {MAPSEC_UNDERWATER_124,             MAPSEC_ROUTE_124},
    #ifdef BUGFIX
    {MAPSEC_UNDERWATER_125,             MAPSEC_ROUTE_125},
    #else
    {MAPSEC_UNDERWATER_125,             MAPSEC_ROUTE_11}, // BUG: Map will incorrectly display the name of Route 129 when diving on Route 125 (for Marine Cave only)
    #endif
    {MAPSEC_UNDERWATER_126,             MAPSEC_ROUTE_126},
    {MAPSEC_UNDERWATER_127,             MAPSEC_ROUTE_127},
    {MAPSEC_UNDERWATER_128,             MAPSEC_ROUTE_128},
    {MAPSEC_UNDERWATER_129,             MAPSEC_ROUTE_11},
    {MAPSEC_UNDERWATER_SOOTOPOLIS,      MAPSEC_SOOTOPOLIS_CITY},
    {MAPSEC_UNDERWATER_SEAFLOOR_CAVERN, MAPSEC_ROUTE_128},
    {MAPSEC_AQUA_HIDEOUT,               MAPSEC_LILYCOVE_CITY},
    {MAPSEC_AQUA_HIDEOUT_OLD,           MAPSEC_LILYCOVE_CITY},
    {MAPSEC_MAGMA_HIDEOUT,              MAPSEC_ROUTE_112},
    {MAPSEC_UNDERWATER_SEALED_CHAMBER,  MAPSEC_ROUTE_134},
    {MAPSEC_PETALBURG_WOODS,            MAPSEC_ROUTE_104},
    {MAPSEC_JAGGED_PASS,                MAPSEC_ROUTE_112},
    {MAPSEC_MT_PYRE,                    MAPSEC_ROUTE_122},
    {MAPSEC_SKY_PILLAR,                 MAPSEC_ROUTE_131},
    {MAPSEC_MIRAGE_TOWER,               MAPSEC_ROUTE_111},
    {MAPSEC_TRAINER_HILL,               MAPSEC_ROUTE_111},
    {MAPSEC_DESERT_UNDERPASS,           MAPSEC_ROUTE_114},
    {MAPSEC_ALTERING_CAVE,              MAPSEC_ROUTE_103},
    {MAPSEC_ARTISAN_CAVE,               MAPSEC_ROUTE_103},
    {MAPSEC_ABANDONED_SHIP,             MAPSEC_ROUTE_108},
    {MAPSEC_NONE,                       MAPSEC_NONE}
};

static const u8 sMapSecAquaHideoutOld[] =
{
    MAPSEC_AQUA_HIDEOUT_OLD
};

static const struct OamData sRegionMapCursorOam =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1
};

static const union AnimCmd sRegionMapCursorAnim1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sRegionMapCursorAnim2[] =
{
    ANIMCMD_FRAME( 0, 10),
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_FRAME(32, 10),
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sRegionMapCursorAnimTable[] =
{
    sRegionMapCursorAnim1,
    sRegionMapCursorAnim2
};

static const struct SpritePalette sRegionMapCursorSpritePalette =
{
    .data = sRegionMapCursorPal,
    .tag = TAG_CURSOR
};

static const struct SpriteTemplate sRegionMapCursorSpriteTemplate =
{
    .tileTag = TAG_CURSOR,
    .paletteTag = TAG_CURSOR,
    .oam = &sRegionMapCursorOam,
    .anims = sRegionMapCursorAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CursorMapFull
};

static const struct OamData sRegionMapPlayerIconOam =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2
};

static const union AnimCmd sRegionMapPlayerIconAnim1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sRegionMapPlayerIconAnimTable[] =
{
    sRegionMapPlayerIconAnim1
};

static const u8 sMapSecIdsOffMap[] =
{
    MAPSEC_FARAWAY_ISLAND
};

static const u16 sRegionMapFramePal[] = INCBIN_U16("graphics/pokenav/region_map/frame.gbapal");
static const u32 sRegionMapFrameGfxLZ[] = INCBIN_U32("graphics/pokenav/region_map/frame.4bpp.lz");
static const u32 sRegionMapFrameTilemapLZ[] = INCBIN_U32("graphics/pokenav/region_map/frame.bin.lz");
static const u16 sTeleportTargetIcons_Pal[] = INCBIN_U16("graphics/pokenav/region_map/teleport_target_icons.gbapal");
static const u32 sTeleportTargetIcons_Gfx[] = INCBIN_U32("graphics/pokenav/region_map/teleport_target_icons.4bpp.lz");

static const u8 sMapHealLocations[][3] =
{
    [MAPSEC_PALLET_TOWN] = {MAP_GROUP(PALLET_TOWN), MAP_NUM(PALLET_TOWN), HEAL_LOCATION_PALLET_TOWN},
    [MAPSEC_VIRIDIAN_CITY] = {MAP_GROUP(VIRIDIAN_CITY), MAP_NUM(VIRIDIAN_CITY), HEAL_LOCATION_VIRIDIAN_CITY},
    [MAPSEC_PEWTER_CITY] = {MAP_GROUP(PEWTER_CITY), MAP_NUM(PEWTER_CITY), HEAL_LOCATION_PEWTER_CITY},
    [MAPSEC_CERULEAN_CITY] = {MAP_GROUP(CERULEAN_CITY), MAP_NUM(CERULEAN_CITY), HEAL_LOCATION_CERULEAN_CITY},
    [MAPSEC_VERMILION_CITY] = {MAP_GROUP(VERMILION_CITY), MAP_NUM(VERMILION_CITY), HEAL_LOCATION_VERMILION_CITY},
    [MAPSEC_LAVENDER_TOWN] = {MAP_GROUP(LAVENDER_TOWN), MAP_NUM(LAVENDER_TOWN), HEAL_LOCATION_LAVENDER_TOWN},
    [MAPSEC_CELADON_CITY] = {MAP_GROUP(CELADON_CITY), MAP_NUM(CELADON_CITY), HEAL_LOCATION_CELADON_CITY},
    [MAPSEC_FUCHSIA_CITY] = {MAP_GROUP(FUCHSIA_CITY), MAP_NUM(FUCHSIA_CITY), HEAL_LOCATION_FUCHSIA_CITY},
    [MAPSEC_SAFFRON_CITY] = {MAP_GROUP(SAFFRON_CITY), MAP_NUM(SAFFRON_CITY), HEAL_LOCATION_SAFFRON_CITY},
    [MAPSEC_CINNABAR_ISLAND] = {MAP_GROUP(CINNABAR_ISLAND), MAP_NUM(CINNABAR_ISLAND), HEAL_LOCATION_CINNABAR_ISLAND},
    [MAPSEC_INDIGO_PLATEAU] = {MAP_GROUP(INDIGO_PLATEAU), MAP_NUM(INDIGO_PLATEAU), HEAL_LOCATION_INDIGO_PLATEAU},
    [MAPSEC_ONE_ISLAND] = {MAP_GROUP(ONE_ISLAND), MAP_NUM(ONE_ISLAND), HEAL_LOCATION_ONE_ISLAND},
    [MAPSEC_TWO_ISLAND] = {MAP_GROUP(TWO_ISLAND), MAP_NUM(TWO_ISLAND), HEAL_LOCATION_TWO_ISLAND},
    [MAPSEC_THREE_ISLAND] = {MAP_GROUP(THREE_ISLAND), MAP_NUM(THREE_ISLAND), HEAL_LOCATION_THREE_ISLAND},
    [MAPSEC_FOUR_ISLAND] = {MAP_GROUP(FOUR_ISLAND), MAP_NUM(FOUR_ISLAND), HEAL_LOCATION_FOUR_ISLAND},
    [MAPSEC_FIVE_ISLAND] = {MAP_GROUP(FIVE_ISLAND), MAP_NUM(FIVE_ISLAND), HEAL_LOCATION_FIVE_ISLAND},
    [MAPSEC_SIX_ISLAND] = {MAP_GROUP(SIX_ISLAND), MAP_NUM(SIX_ISLAND), HEAL_LOCATION_SIX_ISLAND},
    [MAPSEC_SEVEN_ISLAND] = {MAP_GROUP(SEVEN_ISLAND), MAP_NUM(SEVEN_ISLAND), HEAL_LOCATION_SEVEN_ISLAND},
    [MAPSEC_ROUTE_1] = {MAP_GROUP(ROUTE1), MAP_NUM(ROUTE1), 0},
    [MAPSEC_ROUTE_2] = {MAP_GROUP(ROUTE2), MAP_NUM(ROUTE2), 0},
    [MAPSEC_ROUTE_3] = {MAP_GROUP(ROUTE3), MAP_NUM(ROUTE3), 0},
    [MAPSEC_ROUTE_4] = {MAP_GROUP(ROUTE4), MAP_NUM(ROUTE4), HEAL_LOCATION_ROUTE4},
    [MAPSEC_ROUTE_5] = {MAP_GROUP(ROUTE5), MAP_NUM(ROUTE5), 0},
    [MAPSEC_ROUTE_6] = {MAP_GROUP(ROUTE6), MAP_NUM(ROUTE6), 0},
    [MAPSEC_ROUTE_7] = {MAP_GROUP(ROUTE7), MAP_NUM(ROUTE7), 0},
    [MAPSEC_ROUTE_8] = {MAP_GROUP(ROUTE8), MAP_NUM(ROUTE8), 0},
    [MAPSEC_ROUTE_9] = {MAP_GROUP(ROUTE9), MAP_NUM(ROUTE9), 0},
    [MAPSEC_ROUTE_10] = {MAP_GROUP(ROUTE10), MAP_NUM(ROUTE10), HEAL_LOCATION_ROUTE10},
    [MAPSEC_ROUTE_11] = {MAP_GROUP(ROUTE11), MAP_NUM(ROUTE11), 0},
    [MAPSEC_ROUTE_12] = {MAP_GROUP(ROUTE12), MAP_NUM(ROUTE12), 0},
    [MAPSEC_ROUTE_13] = {MAP_GROUP(ROUTE13), MAP_NUM(ROUTE13), 0},
    [MAPSEC_ROUTE_14] = {MAP_GROUP(ROUTE14), MAP_NUM(ROUTE14), 0},
    [MAPSEC_ROUTE_15] = {MAP_GROUP(ROUTE15), MAP_NUM(ROUTE15), 0},
    [MAPSEC_ROUTE_16] = {MAP_GROUP(ROUTE16), MAP_NUM(ROUTE16), 0},
    [MAPSEC_ROUTE_17] = {MAP_GROUP(ROUTE17), MAP_NUM(ROUTE17), 0},
    [MAPSEC_ROUTE_18] = {MAP_GROUP(ROUTE18), MAP_NUM(ROUTE18), 0},
    [MAPSEC_ROUTE_19] = {MAP_GROUP(ROUTE19), MAP_NUM(ROUTE19), 0},
    [MAPSEC_ROUTE_20] = {MAP_GROUP(ROUTE20), MAP_NUM(ROUTE20), 0},
    [MAPSEC_ROUTE_21] = {MAP_GROUP(ROUTE21), MAP_NUM(ROUTE21), 0},
    [MAPSEC_ROUTE_22] = {MAP_GROUP(ROUTE22), MAP_NUM(ROUTE22), 0},
    [MAPSEC_ROUTE_23] = {MAP_GROUP(ROUTE23), MAP_NUM(ROUTE23), 0},
    [MAPSEC_ROUTE_24] = {MAP_GROUP(ROUTE24), MAP_NUM(ROUTE24), 0},
    [MAPSEC_ROUTE_25] = {MAP_GROUP(ROUTE25), MAP_NUM(ROUTE25), 0},
    [MAPSEC_TREASURE_BEACH] = {MAP_GROUP(TREASURE_BEACH), MAP_NUM(TREASURE_BEACH), 0},
    [MAPSEC_KINDLE_ROAD] = {MAP_GROUP(KINDLE_ROAD), MAP_NUM(KINDLE_ROAD), 0},
    [MAPSEC_CAPE_BRINK] = {MAP_GROUP(CAPE_BRINK), MAP_NUM(CAPE_BRINK), 0},
    [MAPSEC_THREE_ISLE_PORT] = {MAP_GROUP(THREE_ISLAND_PORT), MAP_NUM(THREE_ISLAND_PORT), 0},
    [MAPSEC_BOND_BRIDGE] = {MAP_GROUP(BOND_BRIDGE), MAP_NUM(BOND_BRIDGE), 0},
    [MAPSEC_FIVE_ISLE_MEADOW] = {MAP_GROUP(FIVE_ISLAND_MEADOW), MAP_NUM(FIVE_ISLAND_MEADOW), 0},
    [MAPSEC_MEMORIAL_PILLAR] = {MAP_GROUP(MEMORIAL_PILLAR), MAP_NUM(MEMORIAL_PILLAR), 0},
    [MAPSEC_WATER_LABYRINTH] = {MAP_GROUP(WATER_LABYRINTH), MAP_NUM(WATER_LABYRINTH), 0},
    [MAPSEC_RESORT_GORGEOUS] = {MAP_GROUP(RESORT_GORGEOUS), MAP_NUM(RESORT_GORGEOUS), 0},
    [MAPSEC_WATER_PATH] = {MAP_GROUP(WATER_PATH), MAP_NUM(WATER_PATH), 0},
    [MAPSEC_RUIN_VALLEY] = {MAP_GROUP(RUIN_VALLEY), MAP_NUM(RUIN_VALLEY), 0},
    [MAPSEC_GREEN_PATH] = {MAP_GROUP(GREEN_PATH), MAP_NUM(GREEN_PATH), 0},
    [MAPSEC_OUTCAST_ISLAND] = {MAP_GROUP(OUTCAST_ISLAND), MAP_NUM(OUTCAST_ISLAND), 0},
    [MAPSEC_TRAINER_TOWER] = {MAP_GROUP(TRAINER_TOWER_EXTERIOR), MAP_NUM(TRAINER_TOWER_EXTERIOR), 0},
    [MAPSEC_CANYON_ENTRANCE] = {MAP_GROUP(SEVAULT_CANYON_ENTRANCE), MAP_NUM(SEVAULT_CANYON_ENTRANCE), 0},
    [MAPSEC_SEVAULT_CANYON] = {MAP_GROUP(SEVAULT_CANYON), MAP_NUM(SEVAULT_CANYON), 0},
    [MAPSEC_TANOBY_RUINS] = {MAP_GROUP(TANOBY_RUINS), MAP_NUM(TANOBY_RUINS), 0},
};

static const u8 *const sEverGrandeCityNames[] =
{
    gText_PokemonLeague,
    gText_PokemonCenter
};

static const struct MultiNameTeleportDest sMultiNameTeleportDestinations[] =
{
    {
        .name = sEverGrandeCityNames,
        .mapSecId = MAPSEC_EVER_GRANDE_CITY,
        .flag = FLAG_LANDMARK_POKEMON_LEAGUE
    }
};

static const struct BgTemplate sTeleportMapBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 2,
        .paletteMode = 1,
        .priority = 2
    }
};

static const struct WindowTemplate sTeleportMapWindowTemplates[] =
{
    [WIN_MAPSEC_NAME] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 17,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x01
    },
    [WIN_MAPSEC_NAME_TALL] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 15,
        .width = 12,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x19
    },
    [WIN_TELEPORT_TO_WHERE] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 18,
        .width = 14,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x49
    },
    DUMMY_WIN_TEMPLATE
};

static const struct SpritePalette sTeleportTargetIconsSpritePalette =
{
    .data = sTeleportTargetIcons_Pal,
    .tag = TAG_TELEPORT_ICON
};

static const u16 sRedOutlineTeleportDestinations[][2] =
{
    {
        FLAG_LANDMARK_BATTLE_FRONTIER,
        MAPSEC_BATTLE_FRONTIER
    },
    {
        -1,
        MAPSEC_NONE
    }
};

static const struct OamData sTeleportDestIcon_OamData =
{
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .priority = 2
};

static const union AnimCmd sTeleportDestIcon_Anim_8x8CanTeleport[] =
{
    ANIMCMD_FRAME( 0, 5),
    ANIMCMD_END
};

static const union AnimCmd sTeleportDestIcon_Anim_16x8CanTeleport[] =
{
    ANIMCMD_FRAME( 1, 5),
    ANIMCMD_END
};

static const union AnimCmd sTeleportDestIcon_Anim_8x16CanTeleport[] =
{
    ANIMCMD_FRAME( 3, 5),
    ANIMCMD_END
};

static const union AnimCmd sTeleportDestIcon_Anim_8x8CantTeleport[] =
{
    ANIMCMD_FRAME( 5, 5),
    ANIMCMD_END
};

static const union AnimCmd sTeleportDestIcon_Anim_16x8CantTeleport[] =
{
    ANIMCMD_FRAME( 6, 5),
    ANIMCMD_END
};

static const union AnimCmd sTeleportDestIcon_Anim_8x16CantTeleport[] =
{
    ANIMCMD_FRAME( 8, 5),
    ANIMCMD_END
};

// Only used by Battle Frontier
static const union AnimCmd sTeleportDestIcon_Anim_RedOutline[] =
{
    ANIMCMD_FRAME(10, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sTeleportDestIcon_Anims[] =
{
    [SPRITE_SHAPE(8x8)]            = sTeleportDestIcon_Anim_8x8CanTeleport,
    [SPRITE_SHAPE(16x8)]           = sTeleportDestIcon_Anim_16x8CanTeleport,
    [SPRITE_SHAPE(8x16)]           = sTeleportDestIcon_Anim_8x16CanTeleport,
    [SPRITE_SHAPE(8x8)  + 3]       = sTeleportDestIcon_Anim_8x8CantTeleport,
    [SPRITE_SHAPE(16x8) + 3]       = sTeleportDestIcon_Anim_16x8CantTeleport,
    [SPRITE_SHAPE(8x16) + 3]       = sTeleportDestIcon_Anim_8x16CantTeleport,
    [TELEPORTDESTICON_RED_OUTLINE] = sTeleportDestIcon_Anim_RedOutline
};

static const struct SpriteTemplate sTeleportDestIconSpriteTemplate =
{
    .tileTag = TAG_TELEPORT_ICON,
    .paletteTag = TAG_TELEPORT_ICON,
    .oam = &sTeleportDestIcon_OamData,
    .anims = sTeleportDestIcon_Anims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

void InitRegionMap(struct RegionMap *regionMap, bool8 zoomed)
{
    InitRegionMapData(regionMap, NULL, zoomed);
    while (LoadRegionMapGfx());
}

void InitRegionMapData(struct RegionMap *regionMap, const struct BgTemplate *template, bool8 zoomed)
{
    sRegionMap = regionMap;
    sRegionMap->initStep = 0;
    sRegionMap->zoomed = zoomed;
    sRegionMap->inputCallback = zoomed == TRUE ? ProcessRegionMapInput_Zoomed : ProcessRegionMapInput_Full;
    if (template != NULL)
    {
        sRegionMap->bgNum = template->bg;
        sRegionMap->charBaseIdx = template->charBaseIndex;
        sRegionMap->mapBaseIdx = template->mapBaseIndex;
        sRegionMap->bgManaged = TRUE;
    }
    else
    {
        sRegionMap->bgNum = 2;
        sRegionMap->charBaseIdx = 2;
        sRegionMap->mapBaseIdx = 28;
        sRegionMap->bgManaged = FALSE;
    }
}

void ShowRegionMapForPokedexAreaScreen(struct RegionMap *regionMap)
{
    sRegionMap = regionMap;
    InitMapBasedOnPlayerLocation();
    sRegionMap->playerIconSpritePosX = sRegionMap->cursorPosX;
    sRegionMap->playerIconSpritePosY = sRegionMap->cursorPosY;
}

bool8 LoadRegionMapGfx(void)
{
    switch (sRegionMap->initStep)
    {
    case 0:
        if (sRegionMap->bgManaged)
            DecompressAndCopyTileDataToVram(sRegionMap->bgNum, sRegionMapBg_GfxLZ, 0, 0, 0);
        else
            LZ77UnCompVram(sRegionMapBg_GfxLZ, (u16 *)BG_CHAR_ADDR(2));
        break;
    case 1:
        if (sRegionMap->bgManaged)
        {
            if (!FreeTempTileDataBuffersIfPossible())
                DecompressAndCopyTileDataToVram(sRegionMap->bgNum, sRegionMapBg_TilemapLZ, 0, 0, 1);
        }
        else
        {
            LZ77UnCompVram(sRegionMapBg_TilemapLZ, (u16 *)BG_SCREEN_ADDR(28));
        }
        break;
    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
            LoadPalette(sRegionMapBg_Pal, BG_PLTT_ID(7), 3 * PLTT_SIZE_4BPP);
        break;
    case 3:
        LZ77UnCompWram(sRegionMapCursorSmallGfxLZ, sRegionMap->cursorSmallImage);
        break;
    case 4:
        LZ77UnCompWram(sRegionMapCursorLargeGfxLZ, sRegionMap->cursorLargeImage);
        break;
    case 5:
        InitMapBasedOnPlayerLocation();
        sRegionMap->playerIconSpritePosX = sRegionMap->cursorPosX;
        sRegionMap->playerIconSpritePosY = sRegionMap->cursorPosY;
        sRegionMap->mapSecId = CorrectSpecialMapSecId_Internal(sRegionMap->mapSecId);
        sRegionMap->mapSecType = GetMapsecType(sRegionMap->mapSecId);
        GetMapName(sRegionMap->mapSecName, sRegionMap->mapSecId, MAP_NAME_LENGTH);
        break;
    case 6:
        if (sRegionMap->zoomed == FALSE)
        {
            CalcZoomScrollParams(0, 0, 0, 0, 0x100, 0x100, 0);
        }
        else
        {
            sRegionMap->scrollX = sRegionMap->cursorPosX * 8 - 0x34;
            sRegionMap->scrollY = sRegionMap->cursorPosY * 8 - 0x44;
            sRegionMap->zoomedCursorPosX = sRegionMap->cursorPosX;
            sRegionMap->zoomedCursorPosY = sRegionMap->cursorPosY;
            CalcZoomScrollParams(sRegionMap->scrollX, sRegionMap->scrollY, 0x38, 0x48, 0x80, 0x80, 0);
        }
        break;
    case 7:
        GetPositionOfCursorWithinMapSec();
        UpdateRegionMapVideoRegs();
        sRegionMap->cursorSprite = NULL;
        sRegionMap->playerIconSprite = NULL;
        sRegionMap->cursorMovementFrameCounter = 0;
        sRegionMap->blinkPlayerIcon = FALSE;
        if (sRegionMap->bgManaged)
        {
            SetBgAttribute(sRegionMap->bgNum, BG_ATTR_SCREENSIZE, 2);
            SetBgAttribute(sRegionMap->bgNum, BG_ATTR_CHARBASEINDEX, sRegionMap->charBaseIdx);
            SetBgAttribute(sRegionMap->bgNum, BG_ATTR_MAPBASEINDEX, sRegionMap->mapBaseIdx);
            SetBgAttribute(sRegionMap->bgNum, BG_ATTR_WRAPAROUND, 1);
            SetBgAttribute(sRegionMap->bgNum, BG_ATTR_PALETTEMODE, 1);
        }
        sRegionMap->initStep++;
        return FALSE;
    default:
        return FALSE;
    }
    sRegionMap->initStep++;
    return TRUE;
}

void BlendRegionMap(u16 color, u32 coeff)
{
    BlendPalettes(0x380, coeff, color);
    CpuCopy16(&gPlttBufferFaded[BG_PLTT_ID(7)], &gPlttBufferUnfaded[BG_PLTT_ID(7)], 3 * PLTT_SIZE_4BPP);
}

void FreeRegionMapIconResources(void)
{
    if (sRegionMap->cursorSprite != NULL)
    {
        DestroySprite(sRegionMap->cursorSprite);
        FreeSpriteTilesByTag(sRegionMap->cursorTileTag);
        FreeSpritePaletteByTag(sRegionMap->cursorPaletteTag);
    }
    if (sRegionMap->playerIconSprite != NULL)
    {
        DestroySprite(sRegionMap->playerIconSprite);
        FreeSpriteTilesByTag(sRegionMap->playerIconTileTag);
        FreeSpritePaletteByTag(sRegionMap->playerIconPaletteTag);
    }
}

u8 DoRegionMapInputCallback(void)
{
    return sRegionMap->inputCallback();
}

static u8 ProcessRegionMapInput_Full(void)
{
    u8 input;

    input = MAP_INPUT_NONE;
    sRegionMap->cursorDeltaX = 0;
    sRegionMap->cursorDeltaY = 0;
    if (JOY_HELD(DPAD_UP) && sRegionMap->cursorPosY > MAPCURSOR_Y_MIN)
    {
        sRegionMap->cursorDeltaY = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_DOWN) && sRegionMap->cursorPosY < MAPCURSOR_Y_MAX)
    {
        sRegionMap->cursorDeltaY = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_LEFT) && sRegionMap->cursorPosX > MAPCURSOR_X_MIN)
    {
        sRegionMap->cursorDeltaX = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_RIGHT) && sRegionMap->cursorPosX < MAPCURSOR_X_MAX)
    {
        sRegionMap->cursorDeltaX = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_NEW(A_BUTTON))
    {
        input = MAP_INPUT_A_BUTTON;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        input = MAP_INPUT_B_BUTTON;
    }
    if (input == MAP_INPUT_MOVE_START)
    {
        sRegionMap->cursorMovementFrameCounter = 4;
        sRegionMap->inputCallback = MoveRegionMapCursor_Full;
    }
    return input;
}

static u8 MoveRegionMapCursor_Full(void)
{
    u16 mapSecId;

    if (sRegionMap->cursorMovementFrameCounter != 0)
        return MAP_INPUT_MOVE_CONT;

    if (sRegionMap->cursorDeltaX > 0)
    {
        sRegionMap->cursorPosX++;
    }
    if (sRegionMap->cursorDeltaX < 0)
    {
        sRegionMap->cursorPosX--;
    }
    if (sRegionMap->cursorDeltaY > 0)
    {
        sRegionMap->cursorPosY++;
    }
    if (sRegionMap->cursorDeltaY < 0)
    {
        sRegionMap->cursorPosY--;
    }

    mapSecId = GetMapSecIdAt(sRegionMap->cursorPosX, sRegionMap->cursorPosY);
    sRegionMap->mapSecType = GetMapsecType(mapSecId);
    if (mapSecId != sRegionMap->mapSecId)
    {
        sRegionMap->mapSecId = mapSecId;
        GetMapName(sRegionMap->mapSecName, sRegionMap->mapSecId, MAP_NAME_LENGTH);
    }
    GetPositionOfCursorWithinMapSec();
    sRegionMap->inputCallback = ProcessRegionMapInput_Full;
    return MAP_INPUT_MOVE_END;
}

static u8 ProcessRegionMapInput_Zoomed(void)
{
    u8 input;

    input = MAP_INPUT_NONE;
    sRegionMap->zoomedCursorDeltaX = 0;
    sRegionMap->zoomedCursorDeltaY = 0;
    if (JOY_HELD(DPAD_UP) && sRegionMap->scrollY > -0x34)
    {
        sRegionMap->zoomedCursorDeltaY = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_DOWN) && sRegionMap->scrollY < 0x3c)
    {
        sRegionMap->zoomedCursorDeltaY = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_LEFT) && sRegionMap->scrollX > -0x2c)
    {
        sRegionMap->zoomedCursorDeltaX = -1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_HELD(DPAD_RIGHT) && sRegionMap->scrollX < 0xac)
    {
        sRegionMap->zoomedCursorDeltaX = +1;
        input = MAP_INPUT_MOVE_START;
    }
    if (JOY_NEW(A_BUTTON))
    {
        input = MAP_INPUT_A_BUTTON;
    }
    if (JOY_NEW(B_BUTTON))
    {
        input = MAP_INPUT_B_BUTTON;
    }
    if (input == MAP_INPUT_MOVE_START)
    {
        sRegionMap->inputCallback = MoveRegionMapCursor_Zoomed;
        sRegionMap->zoomedCursorMovementFrameCounter = 0;
    }
    return input;
}

static u8 MoveRegionMapCursor_Zoomed(void)
{
    u16 x;
    u16 y;
    u16 mapSecId;

    sRegionMap->scrollY += sRegionMap->zoomedCursorDeltaY;
    sRegionMap->scrollX += sRegionMap->zoomedCursorDeltaX;
    RegionMap_SetBG2XAndBG2Y(sRegionMap->scrollX, sRegionMap->scrollY);
    sRegionMap->zoomedCursorMovementFrameCounter++;
    if (sRegionMap->zoomedCursorMovementFrameCounter == 8)
    {
        x = (sRegionMap->scrollX + 0x2c) / 8 + 1;
        y = (sRegionMap->scrollY + 0x34) / 8 + 2;
        if (x != sRegionMap->zoomedCursorPosX || y != sRegionMap->zoomedCursorPosY)
        {
            sRegionMap->zoomedCursorPosX = x;
            sRegionMap->zoomedCursorPosY = y;
            mapSecId = GetMapSecIdAt(x, y);
            sRegionMap->mapSecType = GetMapsecType(mapSecId);
            if (mapSecId != sRegionMap->mapSecId)
            {
                sRegionMap->mapSecId = mapSecId;
                GetMapName(sRegionMap->mapSecName, sRegionMap->mapSecId, MAP_NAME_LENGTH);
            }
            GetPositionOfCursorWithinMapSec();
        }
        sRegionMap->zoomedCursorMovementFrameCounter = 0;
        sRegionMap->inputCallback = ProcessRegionMapInput_Zoomed;
        return MAP_INPUT_MOVE_END;
    }
    return MAP_INPUT_MOVE_CONT;
}

void SetRegionMapDataForZoom(void)
{
    if (sRegionMap->zoomed == FALSE)
    {
        sRegionMap->scrollY = 0;
        sRegionMap->scrollX = 0;
        sRegionMap->unk_040 = 0;
        sRegionMap->unk_03c = 0;
        sRegionMap->unk_060 = sRegionMap->cursorPosX * 8 - 0x34;
        sRegionMap->unk_062 = sRegionMap->cursorPosY * 8 - 0x44;
        sRegionMap->unk_044 = (sRegionMap->unk_060 << 8) / 16;
        sRegionMap->unk_048 = (sRegionMap->unk_062 << 8) / 16;
        sRegionMap->zoomedCursorPosX = sRegionMap->cursorPosX;
        sRegionMap->zoomedCursorPosY = sRegionMap->cursorPosY;
        sRegionMap->unk_04c = 0x10000;
        sRegionMap->unk_050 = -0x800;
    }
    else
    {
        sRegionMap->unk_03c = sRegionMap->scrollX * 0x100;
        sRegionMap->unk_040 = sRegionMap->scrollY * 0x100;
        sRegionMap->unk_060 = 0;
        sRegionMap->unk_062 = 0;
        sRegionMap->unk_044 = -(sRegionMap->unk_03c / 16);
        sRegionMap->unk_048 = -(sRegionMap->unk_040 / 16);
        sRegionMap->cursorPosX = sRegionMap->zoomedCursorPosX;
        sRegionMap->cursorPosY = sRegionMap->zoomedCursorPosY;
        sRegionMap->unk_04c = 0x8000;
        sRegionMap->unk_050 = 0x800;
    }
    sRegionMap->unk_06e = 0;
    FreeRegionMapCursorSprite();
    HideRegionMapPlayerIcon();
}

bool8 UpdateRegionMapZoom(void)
{
    bool8 retVal;

    if (sRegionMap->unk_06e >= 16)
    {
        return FALSE;
    }
    sRegionMap->unk_06e++;
    if (sRegionMap->unk_06e == 16)
    {
        sRegionMap->unk_044 = 0;
        sRegionMap->unk_048 = 0;
        sRegionMap->scrollX = sRegionMap->unk_060;
        sRegionMap->scrollY = sRegionMap->unk_062;
        sRegionMap->unk_04c = (sRegionMap->zoomed == FALSE) ? (128 << 8) : (256 << 8);
        sRegionMap->zoomed = !sRegionMap->zoomed;
        sRegionMap->inputCallback = (sRegionMap->zoomed == FALSE) ? ProcessRegionMapInput_Full : ProcessRegionMapInput_Zoomed;
        CreateRegionMapCursor(sRegionMap->cursorTileTag, sRegionMap->cursorPaletteTag);
        UnhideRegionMapPlayerIcon();
        retVal = FALSE;
    }
    else
    {
        sRegionMap->unk_03c += sRegionMap->unk_044;
        sRegionMap->unk_040 += sRegionMap->unk_048;
        sRegionMap->scrollX = sRegionMap->unk_03c >> 8;
        sRegionMap->scrollY = sRegionMap->unk_040 >> 8;
        sRegionMap->unk_04c += sRegionMap->unk_050;
        if ((sRegionMap->unk_044 < 0 && sRegionMap->scrollX < sRegionMap->unk_060) || (sRegionMap->unk_044 > 0 && sRegionMap->scrollX > sRegionMap->unk_060))
        {
            sRegionMap->scrollX = sRegionMap->unk_060;
            sRegionMap->unk_044 = 0;
        }
        if ((sRegionMap->unk_048 < 0 && sRegionMap->scrollY < sRegionMap->unk_062) || (sRegionMap->unk_048 > 0 && sRegionMap->scrollY > sRegionMap->unk_062))
        {
            sRegionMap->scrollY = sRegionMap->unk_062;
            sRegionMap->unk_048 = 0;
        }
        if (sRegionMap->zoomed == FALSE)
        {
            if (sRegionMap->unk_04c < (128 << 8))
            {
                sRegionMap->unk_04c = (128 << 8);
                sRegionMap->unk_050 = 0;
            }
        }
        else
        {
            if (sRegionMap->unk_04c > (256 << 8))
            {
                sRegionMap->unk_04c = (256 << 8);
                sRegionMap->unk_050 = 0;
            }
        }
        retVal = TRUE;
    }
    CalcZoomScrollParams(sRegionMap->scrollX, sRegionMap->scrollY, 0x38, 0x48, sRegionMap->unk_04c >> 8, sRegionMap->unk_04c >> 8, 0);
    return retVal;
}

static void CalcZoomScrollParams(s16 scrollX, s16 scrollY, s16 c, s16 d, u16 e, u16 f, u8 rotation)
{
    s32 var1;
    s32 var2;
    s32 var3;
    s32 var4;

    sRegionMap->bg2pa = e * gSineTable[rotation + 64] >> 8;
    sRegionMap->bg2pc = e * -gSineTable[rotation] >> 8;
    sRegionMap->bg2pb = f * gSineTable[rotation] >> 8;
    sRegionMap->bg2pd = f * gSineTable[rotation + 64] >> 8;

    var1 = (scrollX << 8) + (c << 8);
    var2 = d * sRegionMap->bg2pb + sRegionMap->bg2pa * c;
    sRegionMap->bg2x = var1 - var2;

    var3 = (scrollY << 8) + (d << 8);
    var4 = sRegionMap->bg2pd * d + sRegionMap->bg2pc * c;
    sRegionMap->bg2y = var3 - var4;

    sRegionMap->needUpdateVideoRegs = TRUE;
}

static void RegionMap_SetBG2XAndBG2Y(s16 x, s16 y)
{
    sRegionMap->bg2x = (x << 8) + 0x1c00;
    sRegionMap->bg2y = (y << 8) + 0x2400;
    sRegionMap->needUpdateVideoRegs = TRUE;
}

void UpdateRegionMapVideoRegs(void)
{
    if (sRegionMap->needUpdateVideoRegs)
    {
        SetGpuReg(REG_OFFSET_BG2PA, sRegionMap->bg2pa);
        SetGpuReg(REG_OFFSET_BG2PB, sRegionMap->bg2pb);
        SetGpuReg(REG_OFFSET_BG2PC, sRegionMap->bg2pc);
        SetGpuReg(REG_OFFSET_BG2PD, sRegionMap->bg2pd);
        SetGpuReg(REG_OFFSET_BG2X_L, sRegionMap->bg2x);
        SetGpuReg(REG_OFFSET_BG2X_H, sRegionMap->bg2x >> 16);
        SetGpuReg(REG_OFFSET_BG2Y_L, sRegionMap->bg2y);
        SetGpuReg(REG_OFFSET_BG2Y_H, sRegionMap->bg2y >> 16);
        sRegionMap->needUpdateVideoRegs = FALSE;
    }
}

void PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(s16 x, s16 y)
{
    CalcZoomScrollParams(x, y, 0x38, 0x48, 0x100, 0x100, 0);
    UpdateRegionMapVideoRegs();
    if (sRegionMap->playerIconSprite != NULL)
    {
        sRegionMap->playerIconSprite->x2 = -x;
        sRegionMap->playerIconSprite->y2 = -y;
    }
}

static u16 GetMapSecIdAt(u16 x, u16 y)
{
    if (y < MAPCURSOR_Y_MIN || y > MAPCURSOR_Y_MAX || x < MAPCURSOR_X_MIN || x > MAPCURSOR_X_MAX)
    {
        return MAPSEC_NONE;
    }
    y -= MAPCURSOR_Y_MIN;
    x -= MAPCURSOR_X_MIN;
    return sRegionMap_MapSectionLayout[y][x];
}

static void InitMapBasedOnPlayerLocation(void)
{
    const struct MapHeader *mapHeader;
    u16 mapWidth;
    u16 mapHeight;
    u16 x;
    u16 y;
    u16 dimensionScale;
    u16 xOnMap;
    struct WarpData *warp;

    switch (GetMapTypeByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
    {
    default:
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_ROUTE:
    case MAP_TYPE_UNDERWATER:
    case MAP_TYPE_OCEAN_ROUTE:
        sRegionMap->mapSecId = gMapHeader.regionMapSectionId;
        sRegionMap->playerIsInCave = FALSE;
        mapWidth = gMapHeader.mapLayout->width;
        mapHeight = gMapHeader.mapLayout->height;
        x = gSaveBlock1Ptr->pos.x;
        y = gSaveBlock1Ptr->pos.y;
        if (sRegionMap->mapSecId == MAPSEC_UNDERWATER_SEAFLOOR_CAVERN || sRegionMap->mapSecId == MAPSEC_UNDERWATER_MARINE_CAVE)
            sRegionMap->playerIsInCave = TRUE;
        break;
    case MAP_TYPE_UNDERGROUND:
    case MAP_TYPE_UNKNOWN:
        if (gMapHeader.allowEscaping)
        {
            mapHeader = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->escapeWarp.mapGroup, gSaveBlock1Ptr->escapeWarp.mapNum);
            sRegionMap->mapSecId = mapHeader->regionMapSectionId;
            sRegionMap->playerIsInCave = TRUE;
            mapWidth = mapHeader->mapLayout->width;
            mapHeight = mapHeader->mapLayout->height;
            x = gSaveBlock1Ptr->escapeWarp.x;
            y = gSaveBlock1Ptr->escapeWarp.y;
        }
        else
        {
            sRegionMap->mapSecId = gMapHeader.regionMapSectionId;
            sRegionMap->playerIsInCave = TRUE;
            mapWidth = 1;
            mapHeight = 1;
            x = 1;
            y = 1;
        }
        break;
    case MAP_TYPE_SECRET_BASE:
        mapHeader = Overworld_GetMapHeaderByGroupAndId((u16)gSaveBlock1Ptr->dynamicWarp.mapGroup, (u16)gSaveBlock1Ptr->dynamicWarp.mapNum);
        sRegionMap->mapSecId = mapHeader->regionMapSectionId;
        sRegionMap->playerIsInCave = TRUE;
        mapWidth = mapHeader->mapLayout->width;
        mapHeight = mapHeader->mapLayout->height;
        x = gSaveBlock1Ptr->dynamicWarp.x;
        y = gSaveBlock1Ptr->dynamicWarp.y;
        break;
    case MAP_TYPE_INDOOR:
        sRegionMap->mapSecId = gMapHeader.regionMapSectionId;
        if (sRegionMap->mapSecId != MAPSEC_DYNAMIC)
        {
            warp = &gSaveBlock1Ptr->escapeWarp;
            mapHeader = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum);
        }
        else
        {
            warp = &gSaveBlock1Ptr->dynamicWarp;
            mapHeader = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum);
            sRegionMap->mapSecId = mapHeader->regionMapSectionId;
        }

        if (IsPlayerInAquaHideout(sRegionMap->mapSecId))
            sRegionMap->playerIsInCave = TRUE;
        else
            sRegionMap->playerIsInCave = FALSE;

        mapWidth = mapHeader->mapLayout->width;
        mapHeight = mapHeader->mapLayout->height;
        x = warp->x;
        y = warp->y;
        break;
    }

    xOnMap = x;

    dimensionScale = mapWidth / gRegionMapEntries[sRegionMap->mapSecId].width;
    if (dimensionScale == 0)
    {
        dimensionScale = 1;
    }
    x /= dimensionScale;
    if (x >= gRegionMapEntries[sRegionMap->mapSecId].width)
    {
        x = gRegionMapEntries[sRegionMap->mapSecId].width - 1;
    }

    dimensionScale = mapHeight / gRegionMapEntries[sRegionMap->mapSecId].height;
    if (dimensionScale == 0)
    {
        dimensionScale = 1;
    }
    y /= dimensionScale;
    if (y >= gRegionMapEntries[sRegionMap->mapSecId].height)
    {
        y = gRegionMapEntries[sRegionMap->mapSecId].height - 1;
    }

    switch (sRegionMap->mapSecId)
    {
    case MAPSEC_ROUTE_114:
        if (y != 0)
            x = 0;
        break;
    case MAPSEC_ROUTE_126:
    case MAPSEC_UNDERWATER_126:
        x = 0;
        if (gSaveBlock1Ptr->pos.x > 32)
            x++;
        if (gSaveBlock1Ptr->pos.x > 51)
            x++;

        y = 0;
        if (gSaveBlock1Ptr->pos.y > 37)
            y++;
        if (gSaveBlock1Ptr->pos.y > 56)
            y++;
        break;
    case MAPSEC_ROUTE_121:
        x = 0;
        if (xOnMap > 14)
            x++;
        if (xOnMap > 28)
            x++;
        if (xOnMap > 54)
            x++;
        break;
    }
    sRegionMap->cursorPosX = gRegionMapEntries[sRegionMap->mapSecId].x + x + MAPCURSOR_X_MIN;
    sRegionMap->cursorPosY = gRegionMapEntries[sRegionMap->mapSecId].y + y + MAPCURSOR_Y_MIN;
}

static u8 GetMapsecType(u16 mapSecId)
{
    switch (mapSecId)
    {
    case MAPSEC_NONE:
        return MAPSECTYPE_NONE;
    case MAPSEC_PALLET_TOWN:
        return FlagGet(FLAG_WORLD_MAP_PALLET_TOWN) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_VIRIDIAN_CITY:
        return FlagGet(FLAG_WORLD_MAP_VIRIDIAN_CITY) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_PEWTER_CITY:
        return FlagGet(FLAG_WORLD_MAP_PEWTER_CITY) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_CERULEAN_CITY:
        return FlagGet(FLAG_WORLD_MAP_CERULEAN_CITY) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_VERMILION_CITY:
        return FlagGet(FLAG_WORLD_MAP_VERMILION_CITY) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_LAVENDER_TOWN:
        return FlagGet(FLAG_WORLD_MAP_LAVENDER_TOWN) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_CELADON_CITY:
        return FlagGet(FLAG_WORLD_MAP_CELADON_CITY) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_FUCHSIA_CITY:
        return FlagGet(FLAG_WORLD_MAP_FUCHSIA_CITY) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_SAFFRON_CITY:
        return FlagGet(FLAG_WORLD_MAP_SAFFRON_CITY) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_CINNABAR_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_CINNABAR_ISLAND) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_INDIGO_PLATEAU:
        return FlagGet(FLAG_WORLD_MAP_INDIGO_PLATEAU) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_ONE_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_ONE_ISLAND) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_TWO_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_TWO_ISLAND) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_THREE_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_THREE_ISLAND) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_FOUR_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_FOUR_ISLAND) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_FIVE_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_FIVE_ISLAND) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_SIX_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_SIX_ISLAND) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_SEVEN_ISLAND:
        return FlagGet(FLAG_WORLD_MAP_SEVEN_ISLAND) ? MAPSECTYPE_CITY_CANTELEPORT : MAPSECTYPE_CITY_CANTTELEPORT;
    case MAPSEC_BATTLE_FRONTIER:
        return FlagGet(FLAG_LANDMARK_BATTLE_FRONTIER) ? MAPSECTYPE_BATTLE_FRONTIER : MAPSECTYPE_NONE;
    default:
        return MAPSECTYPE_ROUTE;
    }
}

u16 GetRegionMapSecIdAt(u16 x, u16 y)
{
    return GetMapSecIdAt(x, y);
}

static u16 CorrectSpecialMapSecId_Internal(u16 mapSecId)
{
    u32 i;

    for (i = 0; sRegionMap_SpecialPlaceLocations[i][0] != MAPSEC_NONE; i++)
    {
        if (sRegionMap_SpecialPlaceLocations[i][0] == mapSecId)
        {
            return sRegionMap_SpecialPlaceLocations[i][1];
        }
    }
    return mapSecId;
}

// Probably meant to be an "IsPlayerInIndoorDungeon" function, but in practice it only has the one mapsec
// Additionally, because the mapsec doesnt exist in Emerald, this function always returns FALSE
static bool32 IsPlayerInAquaHideout(u8 mapSecId)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMapSecAquaHideoutOld); i++)
    {
        if (sMapSecAquaHideoutOld[i] == mapSecId)
            return TRUE;
    }
    return FALSE;
}

u16 CorrectSpecialMapSecId(u16 mapSecId)
{
    return CorrectSpecialMapSecId_Internal(mapSecId);
}

static void GetPositionOfCursorWithinMapSec(void)
{
    u16 x;
    u16 y;
    u16 posWithinMapSec;

    if (sRegionMap->mapSecId == MAPSEC_NONE)
    {
        sRegionMap->posWithinMapSec = 0;
        return;
    }
    if (!sRegionMap->zoomed)
    {
        x = sRegionMap->cursorPosX;
        y = sRegionMap->cursorPosY;
    }
    else
    {
        x = sRegionMap->zoomedCursorPosX;
        y = sRegionMap->zoomedCursorPosY;
    }
    posWithinMapSec = 0;
    while (1)
    {
        if (x <= MAPCURSOR_X_MIN)
        {
            if (RegionMap_IsMapSecIdInNextRow(y))
            {
                y--;
                x = MAPCURSOR_X_MAX + 1;
            }
            else
            {
                break;
            }
        }
        else
        {
            x--;
            if (GetMapSecIdAt(x, y) == sRegionMap->mapSecId)
            {
                posWithinMapSec++;
            }
        }
    }
    sRegionMap->posWithinMapSec = posWithinMapSec;
}

static bool8 RegionMap_IsMapSecIdInNextRow(u16 y)
{
    u16 x;

    if (y-- == 0)
    {
        return FALSE;
    }
    for (x = MAPCURSOR_X_MIN; x <= MAPCURSOR_X_MAX; x++)
    {
        if (GetMapSecIdAt(x, y) == sRegionMap->mapSecId)
        {
            return TRUE;
        }
    }
    return FALSE;
}

static void SpriteCB_CursorMapFull(struct Sprite *sprite)
{
    if (sRegionMap->cursorMovementFrameCounter != 0)
    {
        sprite->x += 2 * sRegionMap->cursorDeltaX;
        sprite->y += 2 * sRegionMap->cursorDeltaY;
        sRegionMap->cursorMovementFrameCounter--;
    }
}

static void SpriteCB_CursorMapZoomed(struct Sprite *sprite)
{

}

void CreateRegionMapCursor(u16 tileTag, u16 paletteTag)
{
    u8 spriteId;
    struct SpriteTemplate template;
    struct SpritePalette palette;
    struct SpriteSheet sheet;

    palette = sRegionMapCursorSpritePalette;
    template = sRegionMapCursorSpriteTemplate;
    sheet.tag = tileTag;
    template.tileTag = tileTag;
    sRegionMap->cursorTileTag = tileTag;
    palette.tag = paletteTag;
    template.paletteTag = paletteTag;
    sRegionMap->cursorPaletteTag = paletteTag;
    if (!sRegionMap->zoomed)
    {
        sheet.data = sRegionMap->cursorSmallImage;
        sheet.size = sizeof(sRegionMap->cursorSmallImage);
        template.callback = SpriteCB_CursorMapFull;
    }
    else
    {
        sheet.data = sRegionMap->cursorLargeImage;
        sheet.size = sizeof(sRegionMap->cursorLargeImage);
        template.callback = SpriteCB_CursorMapZoomed;
    }
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSprite(&template, 56, 72, 0);
    if (spriteId != MAX_SPRITES)
    {
        sRegionMap->cursorSprite = &gSprites[spriteId];
        if (sRegionMap->zoomed == TRUE)
        {
            sRegionMap->cursorSprite->oam.size = SPRITE_SIZE(32x32);
            sRegionMap->cursorSprite->x -= 8;
            sRegionMap->cursorSprite->y -= 8;
            StartSpriteAnim(sRegionMap->cursorSprite, 1);
        }
        else
        {
            sRegionMap->cursorSprite->oam.size = SPRITE_SIZE(16x16);
            sRegionMap->cursorSprite->x = 8 * sRegionMap->cursorPosX + 4;
            sRegionMap->cursorSprite->y = 8 * sRegionMap->cursorPosY + 4;
        }
        sRegionMap->cursorSprite->data[1] = 2;
        sRegionMap->cursorSprite->data[2] = OBJ_PLTT_ID(IndexOfSpritePaletteTag(paletteTag)) + 1;
        sRegionMap->cursorSprite->data[3] = TRUE;
    }
}

static void FreeRegionMapCursorSprite(void)
{
    if (sRegionMap->cursorSprite != NULL)
    {
        DestroySprite(sRegionMap->cursorSprite);
        FreeSpriteTilesByTag(sRegionMap->cursorTileTag);
        FreeSpritePaletteByTag(sRegionMap->cursorPaletteTag);
    }
}

static void UNUSED SetUnkCursorSpriteData(void)
{
    sRegionMap->cursorSprite->data[3] = TRUE;
}

static void UNUSED ClearUnkCursorSpriteData(void)
{
    sRegionMap->cursorSprite->data[3] = FALSE;
}

void CreateRegionMapPlayerIcon(u16 tileTag, u16 paletteTag)
{
    u8 spriteId;
    struct SpriteSheet sheet = {sRegionMapPlayerIcon_RedGfx, 0x80, tileTag};
    struct SpritePalette palette = {sRegionMapPlayerIcon_RedPal, paletteTag};
    struct SpriteTemplate template = {tileTag, paletteTag, &sRegionMapPlayerIconOam, sRegionMapPlayerIconAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy};

    if (IsEventIslandMapSecId(gMapHeader.regionMapSectionId))
    {
        sRegionMap->playerIconSprite = NULL;
        return;
    }
    if (gSaveBlock2Ptr->playerGender == FEMALE)
    {
        sheet.data = sRegionMapPlayerIcon_LeafGfx;
        palette.data = sRegionMapPlayerIcon_LeafPal;
    }
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSprite(&template, 0, 0, 1);
    sRegionMap->playerIconSprite = &gSprites[spriteId];
    if (!sRegionMap->zoomed)
    {
        sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 8 + 4;
        sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 8 + 4;
        sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapFull;
    }
    else
    {
        sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 16 - 0x30;
        sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 16 - 0x42;
        sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapZoomed;
    }
}

static void HideRegionMapPlayerIcon(void)
{
    if (sRegionMap->playerIconSprite != NULL)
    {
        sRegionMap->playerIconSprite->invisible = TRUE;
        sRegionMap->playerIconSprite->callback = SpriteCallbackDummy;
    }
}

static void UnhideRegionMapPlayerIcon(void)
{
    if (sRegionMap->playerIconSprite != NULL)
    {
        if (sRegionMap->zoomed == TRUE)
        {
            sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 16 - 0x30;
            sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 16 - 0x42;
            sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapZoomed;
            sRegionMap->playerIconSprite->invisible = FALSE;
        }
        else
        {
            sRegionMap->playerIconSprite->x = sRegionMap->playerIconSpritePosX * 8 + 4;
            sRegionMap->playerIconSprite->y = sRegionMap->playerIconSpritePosY * 8 + 4;
            sRegionMap->playerIconSprite->x2 = 0;
            sRegionMap->playerIconSprite->y2 = 0;
            sRegionMap->playerIconSprite->callback = SpriteCB_PlayerIconMapFull;
            sRegionMap->playerIconSprite->invisible = FALSE;
        }
    }
}

#define sY       data[0]
#define sX       data[1]
#define sVisible data[2]
#define sTimer   data[7]

static void SpriteCB_PlayerIconMapZoomed(struct Sprite *sprite)
{
    sprite->x2 = -2 * sRegionMap->scrollX;
    sprite->y2 = -2 * sRegionMap->scrollY;
    sprite->sY = sprite->y + sprite->y2 + sprite->centerToCornerVecY;
    sprite->sX = sprite->x + sprite->x2 + sprite->centerToCornerVecX;
    if (sprite->sY < -8 || sprite->sY > DISPLAY_HEIGHT + 8 || sprite->sX < -8 || sprite->sX > DISPLAY_WIDTH + 8)
        sprite->sVisible = FALSE;
    else
        sprite->sVisible = TRUE;

    if (sprite->sVisible == TRUE)
        SpriteCB_PlayerIcon(sprite);
    else
        sprite->invisible = TRUE;
}

static void SpriteCB_PlayerIconMapFull(struct Sprite *sprite)
{
    SpriteCB_PlayerIcon(sprite);
}

static void SpriteCB_PlayerIcon(struct Sprite *sprite)
{
    if (sRegionMap->blinkPlayerIcon)
    {
        if (++sprite->sTimer > 16)
        {
            sprite->sTimer = 0;
            sprite->invisible = sprite->invisible ? FALSE : TRUE;
        }
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

void TrySetPlayerIconBlink(void)
{
    if (sRegionMap->playerIsInCave)
        sRegionMap->blinkPlayerIcon = TRUE;
}

#undef sY
#undef sX
#undef sVisible
#undef sTimer

u8 *GetMapName(u8 *dest, u16 regionMapId, u16 padLength)
{
    u8 *str;
    u16 i;

    if (regionMapId == MAPSEC_SECRET_BASE)
    {
        str = GetSecretBaseMapName(dest);
    }
    else if (regionMapId < MAPSEC_NONE)
    {
        str = StringCopy(dest, gRegionMapEntries[regionMapId].name);
    }
    else
    {
        if (padLength == 0)
        {
            padLength = 18;
        }
        return StringFill(dest, CHAR_SPACE, padLength);
    }
    if (padLength != 0)
    {
        for (i = str - dest; i < padLength; i++)
        {
            *str++ = CHAR_SPACE;
        }
        *str = EOS;
    }
    return str;
}

// TODO: probably needs a better name
u8 *GetMapNameGeneric(u8 *dest, u16 mapSecId)
{
    switch (mapSecId)
    {
    case MAPSEC_DYNAMIC:
        return StringCopy(dest, gText_Ferry);
    case MAPSEC_SECRET_BASE:
        return StringCopy(dest, gText_SecretBase);
    default:
        return GetMapName(dest, mapSecId, 0);
    }
}

u8 *GetMapNameHandleAquaHideout(u8 *dest, u16 mapSecId)
{
    if (mapSecId == MAPSEC_AQUA_HIDEOUT_OLD)
        return StringCopy(dest, gText_Hideout);
    else
        return GetMapNameGeneric(dest, mapSecId);
}

static void GetMapSecDimensions(u16 mapSecId, u16 *x, u16 *y, u16 *width, u16 *height)
{
    *x = gRegionMapEntries[mapSecId].x;
    *y = gRegionMapEntries[mapSecId].y;
    *width = gRegionMapEntries[mapSecId].width;
    *height = gRegionMapEntries[mapSecId].height;
}

bool8 IsRegionMapZoomed(void)
{
    return sRegionMap->zoomed;
}

bool32 IsEventIslandMapSecId(u8 mapSecId)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMapSecIdsOffMap); i++)
    {
        if (mapSecId == sMapSecIdsOffMap[i])
            return TRUE;
    }
    return FALSE;
}

void CB2_OpenTeleportMap(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        sTeleportMap = Alloc(sizeof(*sTeleportMap));
        if (sTeleportMap == NULL)
        {
            SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        }
        else
        {
            ResetPaletteFade();
            ResetSpriteData();
            FreeSpriteTileRanges();
            FreeAllSpritePalettes();
            gMain.state++;
        }
        break;
    case 1:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(1, sTeleportMapBgTemplates, ARRAY_COUNT(sTeleportMapBgTemplates));
        gMain.state++;
        break;
    case 2:
        InitWindows(sTeleportMapWindowTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 3:
        LoadUserWindowBorderGfx(0, 0x65, BG_PLTT_ID(13));
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 4:
        InitRegionMap(&sTeleportMap->regionMap, FALSE);
        CreateRegionMapCursor(TAG_CURSOR, TAG_CURSOR);
        CreateRegionMapPlayerIcon(TAG_PLAYER_ICON, TAG_PLAYER_ICON);
        sTeleportMap->mapSecId = sTeleportMap->regionMap.mapSecId;
        StringFill(sTeleportMap->nameBuffer, CHAR_SPACE, MAP_NAME_LENGTH);
        sDrawTeleportDestTextWindow = TRUE;
        DrawTeleportDestTextWindow();
        gMain.state++;
        break;
    case 5:
        LZ77UnCompVram(sRegionMapFrameGfxLZ, (u16 *)BG_CHAR_ADDR(3));
        gMain.state++;
        break;
    case 6:
        LZ77UnCompVram(sRegionMapFrameTilemapLZ, (u16 *)BG_SCREEN_ADDR(30));
        gMain.state++;
        break;
    case 7:
        LoadPalette(sRegionMapFramePal, BG_PLTT_ID(1), sizeof(sRegionMapFramePal));
        PutWindowTilemap(WIN_TELEPORT_TO_WHERE);
        FillWindowPixelBuffer(WIN_TELEPORT_TO_WHERE, PIXEL_FILL(0));
        AddTextPrinterParameterized(WIN_TELEPORT_TO_WHERE, FONT_NORMAL, gText_TeleportToWhere, 0, 1, 0, NULL);
        ScheduleBgCopyTilemapToVram(0);
        gMain.state++;
        break;
    case 8:
        LoadTeleportDestIcons();
        gMain.state++;
        break;
    case 9:
        BlendPalettes(PALETTES_ALL, 16, 0);
        SetVBlankCallback(VBlankCB_TeleportMap);
        gMain.state++;
        break;
    case 10:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        SetTeleportMapCallback(CB_FadeInTeleportMap);
        SetMainCallback2(CB2_TeleportMap);
        gMain.state++;
        break;
    }
}

static void VBlankCB_TeleportMap(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_TeleportMap(void)
{
    sTeleportMap->callback();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
}

static void SetTeleportMapCallback(void callback(void))
{
    sTeleportMap->callback = callback;
    sTeleportMap->state = 0;
}

static void DrawTeleportDestTextWindow(void)
{
    u16 i;
    bool32 namePrinted;
    const u8 *name;

    if (sTeleportMap->regionMap.mapSecType > MAPSECTYPE_NONE && sTeleportMap->regionMap.mapSecType < NUM_MAPSEC_TYPES)
    {
        namePrinted = FALSE;
        for (i = 0; i < ARRAY_COUNT(sMultiNameTeleportDestinations); i++)
        {
            if (sTeleportMap->regionMap.mapSecId == sMultiNameTeleportDestinations[i].mapSecId)
            {
                if (FlagGet(sMultiNameTeleportDestinations[i].flag))
                {
                    StringLength(sMultiNameTeleportDestinations[i].name[sTeleportMap->regionMap.posWithinMapSec]);
                    namePrinted = TRUE;
                    ClearStdWindowAndFrameToTransparent(WIN_MAPSEC_NAME, FALSE);
                    DrawStdFrameWithCustomTileAndPalette(WIN_MAPSEC_NAME_TALL, FALSE, 101, 13);
                    AddTextPrinterParameterized(WIN_MAPSEC_NAME_TALL, FONT_NORMAL, sTeleportMap->regionMap.mapSecName, 0, 1, 0, NULL);
                    name = sMultiNameTeleportDestinations[i].name[sTeleportMap->regionMap.posWithinMapSec];
                    AddTextPrinterParameterized(WIN_MAPSEC_NAME_TALL, FONT_NORMAL, name, GetStringRightAlignXOffset(FONT_NORMAL, name, 96), 17, 0, NULL);
                    ScheduleBgCopyTilemapToVram(0);
                    sDrawTeleportDestTextWindow = TRUE;
                }
                break;
            }
        }
        if (!namePrinted)
        {
            if (sDrawTeleportDestTextWindow == TRUE)
            {
                ClearStdWindowAndFrameToTransparent(WIN_MAPSEC_NAME_TALL, FALSE);
                DrawStdFrameWithCustomTileAndPalette(WIN_MAPSEC_NAME, FALSE, 101, 13);
            }
            else
            {
                // Window is already drawn, just empty it
                FillWindowPixelBuffer(WIN_MAPSEC_NAME, PIXEL_FILL(1));
            }
            AddTextPrinterParameterized(WIN_MAPSEC_NAME, FONT_NORMAL, sTeleportMap->regionMap.mapSecName, 0, 1, 0, NULL);
            ScheduleBgCopyTilemapToVram(0);
            sDrawTeleportDestTextWindow = FALSE;
        }
    }
    else
    {
        // Selection is on MAPSECTYPE_NONE, draw empty teleport destination text window
        if (sDrawTeleportDestTextWindow == TRUE)
        {
            ClearStdWindowAndFrameToTransparent(WIN_MAPSEC_NAME_TALL, FALSE);
            DrawStdFrameWithCustomTileAndPalette(WIN_MAPSEC_NAME, FALSE, 101, 13);
        }
        FillWindowPixelBuffer(WIN_MAPSEC_NAME, PIXEL_FILL(1));
        CopyWindowToVram(WIN_MAPSEC_NAME, COPYWIN_GFX);
        ScheduleBgCopyTilemapToVram(0);
        sDrawTeleportDestTextWindow = FALSE;
    }
}


static void LoadTeleportDestIcons(void)
{
    struct SpriteSheet sheet;

    LZ77UnCompWram(sTeleportTargetIcons_Gfx, sTeleportMap->tileBuffer);
    sheet.data = sTeleportMap->tileBuffer;
    sheet.size = sizeof(sTeleportMap->tileBuffer);
    sheet.tag = TAG_TELEPORT_ICON;
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&sTeleportTargetIconsSpritePalette);
    CreateTeleportDestIcons();
    TryCreateRedOutlineTeleportDestIcons();
}

// Sprite data for SpriteCB_TeleportDestIcon
#define sIconMapSec   data[0]
#define sFlickerTimer data[1]

static void CreateTeleportDestIcons(void)
{
    u16 canTeleportFlag;
    u16 mapSecId;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 shape;
    u8 spriteId;

    canTeleportFlag = FLAG_WORLD_MAP_PALLET_TOWN;
    for (mapSecId = MAPSEC_PALLET_TOWN; mapSecId <= MAPSEC_INDIGO_PLATEAU; mapSecId++)
    {
        GetMapSecDimensions(mapSecId, &x, &y, &width, &height);
        x = (x + MAPCURSOR_X_MIN) * 8 + 4;
        y = (y + MAPCURSOR_Y_MIN) * 8 + 4;

        if (width == 2)
            shape = SPRITE_SHAPE(16x8);
        else if (height == 2)
            shape = SPRITE_SHAPE(8x16);
        else
            shape = SPRITE_SHAPE(8x8);

        spriteId = CreateSprite(&sTeleportDestIconSpriteTemplate, x, y, 10);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].oam.shape = shape;

            if (FlagGet(canTeleportFlag))
                gSprites[spriteId].callback = SpriteCB_TeleportDestIcon;
            else
                shape += 3;

            StartSpriteAnim(&gSprites[spriteId], shape);
            gSprites[spriteId].sIconMapSec = mapSecId;
        }
        canTeleportFlag++;
    }
}

// Draw a red outline box on the mapsec if its corresponding flag has been set
// Only used for Battle Frontier, but set up to handle more
static void TryCreateRedOutlineTeleportDestIcons(void)
{
    u16 i;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 mapSecId;
    u8 spriteId;

    for (i = 0; sRedOutlineTeleportDestinations[i][1] != MAPSEC_NONE; i++)
    {
        if (FlagGet(sRedOutlineTeleportDestinations[i][0]))
        {
            mapSecId = sRedOutlineTeleportDestinations[i][1];
            GetMapSecDimensions(mapSecId, &x, &y, &width, &height);
            x = (x + MAPCURSOR_X_MIN) * 8;
            y = (y + MAPCURSOR_Y_MIN) * 8;
            spriteId = CreateSprite(&sTeleportDestIconSpriteTemplate, x, y, 10);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
                gSprites[spriteId].callback = SpriteCB_TeleportDestIcon;
                StartSpriteAnim(&gSprites[spriteId], TELEPORTDESTICON_RED_OUTLINE);
                gSprites[spriteId].sIconMapSec = mapSecId;
            }
        }
    }
}

// Flickers teleport destination icon color (by hiding the teleport icon sprite) if the cursor is currently on it
static void SpriteCB_TeleportDestIcon(struct Sprite *sprite)
{
    if (sTeleportMap->regionMap.mapSecId == sprite->sIconMapSec)
    {
        if (++sprite->sFlickerTimer > 16)
        {
            sprite->sFlickerTimer = 0;
            sprite->invisible = sprite->invisible ? FALSE : TRUE;
        }
    }
    else
    {
        sprite->sFlickerTimer = 16;
        sprite->invisible = FALSE;
    }
}

#undef sIconMapSec
#undef sFlickerTimer

static void CB_FadeInTeleportMap(void)
{
    switch (sTeleportMap->state)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        sTeleportMap->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            SetTeleportMapCallback(CB_HandleTeleportMapInput);
        }
        break;
    }
}

static void CB_HandleTeleportMapInput(void)
{
    if (sTeleportMap->state == 0)
    {
        switch (DoRegionMapInputCallback())
        {
        case MAP_INPUT_NONE:
        case MAP_INPUT_MOVE_START:
        case MAP_INPUT_MOVE_CONT:
            break;
        case MAP_INPUT_MOVE_END:
            DrawTeleportDestTextWindow();
            break;
        case MAP_INPUT_A_BUTTON:
            if (sTeleportMap->regionMap.mapSecType == MAPSECTYPE_CITY_CANTELEPORT || sTeleportMap->regionMap.mapSecType == MAPSECTYPE_BATTLE_FRONTIER)
            {
                m4aSongNumStart(SE_SELECT);
                sTeleportMap->choseTeleportLocation = TRUE;
                SetTeleportMapCallback(CB_ExitTeleportMap);
            }
            break;
        case MAP_INPUT_B_BUTTON:
            m4aSongNumStart(SE_SELECT);
            sTeleportMap->choseTeleportLocation = FALSE;
            SetTeleportMapCallback(CB_ExitTeleportMap);
            break;
        }
    }
}

static void CB_ExitTeleportMap(void)
{
    switch (sTeleportMap->state)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTeleportMap->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            FreeRegionMapIconResources();
            if (sTeleportMap->choseTeleportLocation)
            {
                switch (sTeleportMap->regionMap.mapSecId)
                {
                case MAPSEC_BATTLE_FRONTIER:
                    SetWarpDestinationToHealLocation(HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST);
                    break;
                case MAPSEC_LITTLEROOT_TOWN:
                    SetWarpDestinationToHealLocation(gSaveBlock2Ptr->playerGender == MALE ? HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE : HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE);
                    break;
                case MAPSEC_EVER_GRANDE_CITY:
                    SetWarpDestinationToHealLocation(FlagGet(FLAG_LANDMARK_POKEMON_LEAGUE) && sTeleportMap->regionMap.posWithinMapSec == 0 ? HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE : HEAL_LOCATION_EVER_GRANDE_CITY);
                    break;
                default:
                    if (sMapHealLocations[sTeleportMap->regionMap.mapSecId][2] != HEAL_LOCATION_NONE)
                        SetWarpDestinationToHealLocation(sMapHealLocations[sTeleportMap->regionMap.mapSecId][2]);
                    else
                        SetWarpDestinationToMapWarp(sMapHealLocations[sTeleportMap->regionMap.mapSecId][0], sMapHealLocations[sTeleportMap->regionMap.mapSecId][1], WARP_ID_NONE);
                    break;
                }
                ReturnToFieldFromTeleportMapSelect();
            }
            else
            {
                SetMainCallback2(CB2_ReturnToPartyMenuFromTeleportMap);
            }
            TRY_FREE_AND_SET_NULL(sTeleportMap);
            FreeAllWindowBuffers();
        }
        break;
    }
}
