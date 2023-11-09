#include "global.h"
#include "graphics.h"
#include "palette.h"
#include "util.h"
#include "battle_transition.h"
#include "task.h"
#include "battle_transition.h"
#include "fieldmap.h"

static EWRAM_DATA struct {
    const u16 *src;
    u16 *dest;
    u16 size;
} sTilesetDMA3TransferBuffer[20] = {0};

static u8 sTilesetDMA3TransferBufferSize;
static u16 sPrimaryTilesetAnimCounter;
static u16 sPrimaryTilesetAnimCounterMax;
static u16 sSecondaryTilesetAnimCounter;
static u16 sSecondaryTilesetAnimCounterMax;
static void (*sPrimaryTilesetAnimCallback)(u16);
static void (*sSecondaryTilesetAnimCallback)(u16);

static void _InitPrimaryTilesetAnimation(void);
static void _InitSecondaryTilesetAnimation(void);
static void TilesetAnim_General(u16);
static void TilesetAnim_Building(u16);
static void TilesetAnim_CeladonCity(u16);
static void TilesetAnim_BattleFrontierOutsideWest(u16);
static void TilesetAnim_BattleFrontierOutsideEast(u16);
static void TilesetAnim_SilphCo(u16);
static void TilesetAnim_MtEmber(u16);
static void TilesetAnim_VermilionGym(u16);
static void TilesetAnim_CeladonGym(u16);
static void TilesetAnim_BattlePyramid(u16);
static void TilesetAnim_BattleDome(u16);
static void QueueAnimTiles_General_Flower(u16);
static void QueueAnimTiles_General_Water_Current_LandWatersEdge(u16);
static void QueueAnimTiles_General_SandWatersEdge(u16);
static void QueueAnimTiles_Building_TVTurnedOn(u16);
static void QueueAnimTiles_CeladonCity_Fountain(u16);
static void QueueAnimTiles_BattleFrontierOutsideWest_Flag(u16);
static void QueueAnimTiles_BattleFrontierOutsideEast_Flag(u16);
static void QueueAnimTiles_SilphCo_Fountain(u16);
static void QueueAnimTiles_MtEmber_Steam(u16);
static void QueueAnimTiles_VermilionGym_MotorizedDoor(u16);
static void QueueAnimTiles_CeladonGym_Flowers(u16);
static void QueueAnimTiles_BattlePyramid_Torch(u16);
static void QueueAnimTiles_BattlePyramid_StatueShadow(u16);
static void BlendAnimPalette_BattleDome_FloorLights(u16);
static void BlendAnimPalette_BattleDome_FloorLightsNoBlend(u16);

const u16 gTilesetAnims_General_Flower_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/0.4bpp");
const u16 gTilesetAnims_General_Flower_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/1.4bpp");
const u16 gTilesetAnims_General_Flower_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/2.4bpp");
const u16 gTilesetAnims_General_Flower_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/3.4bpp");
const u16 gTilesetAnims_General_Flower_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/4.4bpp");

const u16 *const gTilesetAnims_General_Flower[] = {
    gTilesetAnims_General_Flower_Frame0,
    gTilesetAnims_General_Flower_Frame1,
    gTilesetAnims_General_Flower_Frame2,
    gTilesetAnims_General_Flower_Frame3,
    gTilesetAnims_General_Flower_Frame4
};

const u16 gTilesetAnims_General_Water_Current_LandWatersEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/0.4bpp");
const u16 gTilesetAnims_General_Water_Current_LandWatersEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/1.4bpp");
const u16 gTilesetAnims_General_Water_Current_LandWatersEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/2.4bpp");
const u16 gTilesetAnims_General_Water_Current_LandWatersEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/3.4bpp");
const u16 gTilesetAnims_General_Water_Current_LandWatersEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/4.4bpp");
const u16 gTilesetAnims_General_Water_Current_LandWatersEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/5.4bpp");
const u16 gTilesetAnims_General_Water_Current_LandWatersEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/6.4bpp");
const u16 gTilesetAnims_General_Water_Current_LandWatersEdge_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/7.4bpp");

const u16 *const gTilesetAnims_General_Water_Current_LandWatersEdge[] = {
    gTilesetAnims_General_Water_Current_LandWatersEdge_Frame0,
    gTilesetAnims_General_Water_Current_LandWatersEdge_Frame1,
    gTilesetAnims_General_Water_Current_LandWatersEdge_Frame2,
    gTilesetAnims_General_Water_Current_LandWatersEdge_Frame3,
    gTilesetAnims_General_Water_Current_LandWatersEdge_Frame4,
    gTilesetAnims_General_Water_Current_LandWatersEdge_Frame5,
    gTilesetAnims_General_Water_Current_LandWatersEdge_Frame6,
    gTilesetAnims_General_Water_Current_LandWatersEdge_Frame7
};

const u16 gTilesetAnims_General_SandWatersEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/0.4bpp");
const u16 gTilesetAnims_General_SandWatersEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/1.4bpp");
const u16 gTilesetAnims_General_SandWatersEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/2.4bpp");
const u16 gTilesetAnims_General_SandWatersEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/3.4bpp");
const u16 gTilesetAnims_General_SandWatersEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/4.4bpp");
const u16 gTilesetAnims_General_SandWatersEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/5.4bpp");
const u16 gTilesetAnims_General_SandWatersEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/6.4bpp");
const u16 gTilesetAnims_General_SandWatersEdge_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/7.4bpp");

const u16 *const gTilesetAnims_General_SandWatersEdge[] = {
    gTilesetAnims_General_SandWatersEdge_Frame0,
    gTilesetAnims_General_SandWatersEdge_Frame1,
    gTilesetAnims_General_SandWatersEdge_Frame2,
    gTilesetAnims_General_SandWatersEdge_Frame3,
    gTilesetAnims_General_SandWatersEdge_Frame4,
    gTilesetAnims_General_SandWatersEdge_Frame5,
    gTilesetAnims_General_SandWatersEdge_Frame6,
    gTilesetAnims_General_SandWatersEdge_Frame7
};

const u16 gTilesetAnims_Building_TvTurnedOn_Frame0[] = INCBIN_U16("data/tilesets/primary/building/anim/tv_turned_on/0.4bpp");
const u16 gTilesetAnims_Building_TvTurnedOn_Frame1[] = INCBIN_U16("data/tilesets/primary/building/anim/tv_turned_on/1.4bpp");

const u16 *const gTilesetAnims_Building_TvTurnedOn[] = {
    gTilesetAnims_Building_TvTurnedOn_Frame0,
    gTilesetAnims_Building_TvTurnedOn_Frame1
};

const u16 gTilesetAnims_CeladonCity_Fountain_Frame0[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/0.4bpp");
const u16 gTilesetAnims_CeladonCity_Fountain_Frame1[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/1.4bpp");
const u16 gTilesetAnims_CeladonCity_Fountain_Frame2[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/2.4bpp");
const u16 gTilesetAnims_CeladonCity_Fountain_Frame3[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/3.4bpp");
const u16 gTilesetAnims_CeladonCity_Fountain_Frame4[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/4.4bpp");

const u16 *const gTilesetAnims_CeladonCity_Fountain[] = {
    gTilesetAnims_CeladonCity_Fountain_Frame0,
    gTilesetAnims_CeladonCity_Fountain_Frame1,
    gTilesetAnims_CeladonCity_Fountain_Frame2,
    gTilesetAnims_CeladonCity_Fountain_Frame3,
    gTilesetAnims_CeladonCity_Fountain_Frame4
};

const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/flag/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/flag/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/flag/2.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideWest_Flag[] = {
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame0,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame1,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame2,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame3
};

const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/flag/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/flag/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/flag/2.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideEast_Flag[] = {
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame0,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame1,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame2,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame3
};

const u16 gTilesetAnims_SilphCo_Fountain_Frame0[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/0.4bpp");
const u16 gTilesetAnims_SilphCo_Fountain_Frame1[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/1.4bpp");
const u16 gTilesetAnims_SilphCo_Fountain_Frame2[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/2.4bpp");
const u16 gTilesetAnims_SilphCo_Fountain_Frame3[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/3.4bpp");

const u16 *const gTilesetAnims_SilphCo_Fountain[] = {
    gTilesetAnims_SilphCo_Fountain_Frame0,
    gTilesetAnims_SilphCo_Fountain_Frame1,
    gTilesetAnims_SilphCo_Fountain_Frame2,
    gTilesetAnims_SilphCo_Fountain_Frame3
};

const u16 gTilesetAnims_MtEmber_Steam_Frame0[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/0.4bpp");
const u16 gTilesetAnims_MtEmber_Steam_Frame1[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/1.4bpp");
const u16 gTilesetAnims_MtEmber_Steam_Frame2[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/2.4bpp");
const u16 gTilesetAnims_MtEmber_Steam_Frame3[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/3.4bpp");

const u16 *const gTilesetAnims_MtEmber_Steam[] = {
    gTilesetAnims_MtEmber_Steam_Frame0,
    gTilesetAnims_MtEmber_Steam_Frame1,
    gTilesetAnims_MtEmber_Steam_Frame2,
    gTilesetAnims_MtEmber_Steam_Frame3
};

const u16 gTilesetAnims_VermilionGym_MotorizedDoor_Frame0[] = INCBIN_U16("data/tilesets/secondary/vermilion_gym/anim/motorizeddoor/0.4bpp");
const u16 gTilesetAnims_VermilionGym_MotorizedDoor_Frame1[] = INCBIN_U16("data/tilesets/secondary/vermilion_gym/anim/motorizeddoor/1.4bpp");

const u16 *const gTilesetAnims_VermilionGym_MotorizedDoor[] = {
    gTilesetAnims_VermilionGym_MotorizedDoor_Frame0,
    gTilesetAnims_VermilionGym_MotorizedDoor_Frame1
};

const u16 gTilesetAnims_CeladonGym_Flowers_Frame0[] = INCBIN_U16("data/tilesets/secondary/celadon_gym/anim/flowers/0.4bpp");
const u16 gTilesetAnims_CeladonGym_Flowers_Frame1[] = INCBIN_U16("data/tilesets/secondary/celadon_gym/anim/flowers/1.4bpp");
const u16 gTilesetAnims_CeladonGym_Flowers_Frame2[] = INCBIN_U16("data/tilesets/secondary/celadon_gym/anim/flowers/2.4bpp");

const u16 *const gTilesetAnims_CeladonGym_Flowers[] = {
    gTilesetAnims_CeladonGym_Flowers_Frame0,
    gTilesetAnims_CeladonGym_Flowers_Frame1,
    gTilesetAnims_CeladonGym_Flowers_Frame2,
    gTilesetAnims_CeladonGym_Flowers_Frame1
};

const u16 gTilesetAnims_BattlePyramid_Torch_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/torch/0.4bpp");
const u16 gTilesetAnims_BattlePyramid_Torch_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/torch/1.4bpp");
const u16 gTilesetAnims_BattlePyramid_Torch_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/torch/2.4bpp");
const u16 tileset_anims_space_9[16] = {};

const u16 *const gTilesetAnims_BattlePyramid_Torch[] = {
    gTilesetAnims_BattlePyramid_Torch_Frame0,
    gTilesetAnims_BattlePyramid_Torch_Frame1,
    gTilesetAnims_BattlePyramid_Torch_Frame2
};

const u16 gTilesetAnims_BattlePyramid_StatueShadow_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/statue_shadow/0.4bpp");
const u16 gTilesetAnims_BattlePyramid_StatueShadow_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/statue_shadow/1.4bpp");
const u16 gTilesetAnims_BattlePyramid_StatueShadow_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/statue_shadow/2.4bpp");
const u16 tileset_anims_space_10[7808] = {};

const u16 *const gTilesetAnims_BattlePyramid_StatueShadow[] = {
    gTilesetAnims_BattlePyramid_StatueShadow_Frame0,
    gTilesetAnims_BattlePyramid_StatueShadow_Frame1,
    gTilesetAnims_BattlePyramid_StatueShadow_Frame2
};

static const u16 *const sTilesetAnims_BattleDomeFloorLightPals[] = {
    gTilesetAnims_BattleDomePals0_0,
    gTilesetAnims_BattleDomePals0_1,
    gTilesetAnims_BattleDomePals0_2,
    gTilesetAnims_BattleDomePals0_3,
};

static void ResetTilesetAnimBuffer(void)
{
    sTilesetDMA3TransferBufferSize = 0;
    CpuFill32(0, sTilesetDMA3TransferBuffer, sizeof sTilesetDMA3TransferBuffer);
}

static void AppendTilesetAnimToBuffer(const u16 *src, u16 *dest, u16 size)
{
    if (sTilesetDMA3TransferBufferSize < 20)
    {
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].src = src;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].dest = dest;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].size = size;
        sTilesetDMA3TransferBufferSize ++;
    }
}

void TransferTilesetAnimsBuffer(void)
{
    int i;

    for (i = 0; i < sTilesetDMA3TransferBufferSize; i ++)
        DmaCopy16(3, sTilesetDMA3TransferBuffer[i].src, sTilesetDMA3TransferBuffer[i].dest, sTilesetDMA3TransferBuffer[i].size);

    sTilesetDMA3TransferBufferSize = 0;
}

void InitTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    _InitPrimaryTilesetAnimation();
    _InitSecondaryTilesetAnimation();
}

void InitSecondaryTilesetAnimation(void)
{
    _InitSecondaryTilesetAnimation();
}

void UpdateTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    if (++sPrimaryTilesetAnimCounter >= sPrimaryTilesetAnimCounterMax)
        sPrimaryTilesetAnimCounter = 0;
    if (++sSecondaryTilesetAnimCounter >= sSecondaryTilesetAnimCounterMax)
        sSecondaryTilesetAnimCounter = 0;

    if (sPrimaryTilesetAnimCallback)
        sPrimaryTilesetAnimCallback(sPrimaryTilesetAnimCounter);
    if (sSecondaryTilesetAnimCallback)
        sSecondaryTilesetAnimCallback(sSecondaryTilesetAnimCounter);
}

static void _InitPrimaryTilesetAnimation(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 0;
    sPrimaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->primaryTileset && gMapHeader.mapLayout->primaryTileset->callback)
        gMapHeader.mapLayout->primaryTileset->callback();
}

static void _InitSecondaryTilesetAnimation(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 0;
    sSecondaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->secondaryTileset && gMapHeader.mapLayout->secondaryTileset->callback)
        gMapHeader.mapLayout->secondaryTileset->callback();
}

void InitTilesetAnim_General(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 256;
    sPrimaryTilesetAnimCallback = TilesetAnim_General;
}

void InitTilesetAnim_Building(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 256;
    sPrimaryTilesetAnimCallback = TilesetAnim_Building;
}

void InitTilesetAnim_CeladonCity(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 120;
    sSecondaryTilesetAnimCallback = TilesetAnim_CeladonCity;
}

void InitTilesetAnim_BattleFrontierOutsideWest(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleFrontierOutsideWest;
}

void InitTilesetAnim_BattleFrontierOutsideEast(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleFrontierOutsideEast;
}

void InitTilesetAnim_SilphCo(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 160;
    sSecondaryTilesetAnimCallback = TilesetAnim_SilphCo;
}

void InitTilesetAnim_MtEmber(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_MtEmber;
}

void InitTilesetAnim_VermilionGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 240;
    sSecondaryTilesetAnimCallback = TilesetAnim_VermilionGym;
}

void InitTilesetAnim_CeladonGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_CeladonGym;
}

void InitTilesetAnim_BattlePyramid(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattlePyramid;
}

void InitTilesetAnim_BattleDome(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleDome;
}

static void TilesetAnim_General(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_General_SandWatersEdge(timer / 8);
    if (timer % 16 == 1)
        QueueAnimTiles_General_Water_Current_LandWatersEdge(timer / 16);
    if (timer % 16 == 2)
        QueueAnimTiles_General_Flower(timer / 16);
}

static void TilesetAnim_Building(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Building_TVTurnedOn(timer / 8);
}

static void TilesetAnim_CeladonCity(u16 timer)
{
    if (timer % 12 == 0)
        QueueAnimTiles_CeladonCity_Fountain(timer / 12);
}

static void TilesetAnim_BattleFrontierOutsideWest(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_BattleFrontierOutsideWest_Flag(timer / 8);
}

static void TilesetAnim_BattleFrontierOutsideEast(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_BattleFrontierOutsideEast_Flag(timer / 8);
}

static void TilesetAnim_SilphCo(u16 timer)
{
    if (timer % 10 == 0)
        QueueAnimTiles_SilphCo_Fountain(timer / 10);
}

static void TilesetAnim_MtEmber(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_MtEmber_Steam(timer / 16);
}

static void TilesetAnim_VermilionGym(u16 timer)
{
    if (timer % 2 == 0)
        QueueAnimTiles_VermilionGym_MotorizedDoor(timer / 2);
}

static void TilesetAnim_CeladonGym(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_CeladonGym_Flowers(timer / 16);
}

static void TilesetAnim_BattlePyramid(u16 timer)
{
    if (timer % 8 == 0)
    {
        QueueAnimTiles_BattlePyramid_Torch(timer / 8);
        QueueAnimTiles_BattlePyramid_StatueShadow(timer / 8);
    }
}

static void TilesetAnim_BattleDome(u16 timer)
{
    if (timer % 4 == 0)
        BlendAnimPalette_BattleDome_FloorLights(timer / 4);
}

static void TilesetAnim_BattleDome2(u16 timer)
{
    if (timer % 4 == 0)
        BlendAnimPalette_BattleDome_FloorLightsNoBlend(timer / 4);
}

static void QueueAnimTiles_General_Flower(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_Flower);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_Flower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(508)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_Water_Current_LandWatersEdge(u16 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_General_Water_Current_LandWatersEdge);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_Water_Current_LandWatersEdge[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(416)), 48 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_SandWatersEdge(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_SandWatersEdge);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_SandWatersEdge[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(464)), 18 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Building_TVTurnedOn(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Building_TvTurnedOn);
    AppendTilesetAnimToBuffer(gTilesetAnims_Building_TvTurnedOn[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(197)), 2 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_CeladonCity_Fountain(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_CeladonCity_Fountain);
    AppendTilesetAnimToBuffer(gTilesetAnims_CeladonCity_Fountain[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(744)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattleFrontierOutsideWest_Flag(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattleFrontierOutsideWest_Flag);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideWest_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 298)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattleFrontierOutsideEast_Flag(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattleFrontierOutsideEast_Flag);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideEast_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 298)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_SilphCo_Fountain(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_SilphCo_Fountain);
    AppendTilesetAnimToBuffer(gTilesetAnims_SilphCo_Fountain[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(976)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_MtEmber_Steam(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_MtEmber_Steam);
    AppendTilesetAnimToBuffer(gTilesetAnims_MtEmber_Steam[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(896)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_VermilionGym_MotorizedDoor(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_VermilionGym_MotorizedDoor);
    AppendTilesetAnimToBuffer(gTilesetAnims_VermilionGym_MotorizedDoor[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(880)), 7 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_CeladonGym_Flowers(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_CeladonGym_Flowers);
    AppendTilesetAnimToBuffer(gTilesetAnims_CeladonGym_Flowers[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(739)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattlePyramid_Torch(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattlePyramid_Torch);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattlePyramid_Torch[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 359)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattlePyramid_StatueShadow(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattlePyramid_StatueShadow);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattlePyramid_StatueShadow[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 343)), 8 * TILE_SIZE_4BPP);
}

static void BlendAnimPalette_BattleDome_FloorLights(u16 timer)
{
    CpuCopy16(sTilesetAnims_BattleDomeFloorLightPals[timer % ARRAY_COUNT(sTilesetAnims_BattleDomeFloorLightPals)], &gPlttBufferUnfaded[BG_PLTT_ID(8)], PLTT_SIZE_4BPP);
    BlendPalette(BG_PLTT_ID(8), 16, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
    if ((u8)FindTaskIdByFunc(Task_BattleTransition_Intro) != TASK_NONE)
    {
        sSecondaryTilesetAnimCallback = TilesetAnim_BattleDome2;
        sSecondaryTilesetAnimCounterMax = 32;
    }
}

static void BlendAnimPalette_BattleDome_FloorLightsNoBlend(u16 timer)
{
    CpuCopy16(sTilesetAnims_BattleDomeFloorLightPals[timer % ARRAY_COUNT(sTilesetAnims_BattleDomeFloorLightPals)], &gPlttBufferUnfaded[BG_PLTT_ID(8)], PLTT_SIZE_4BPP);
    if ((u8)FindTaskIdByFunc(Task_BattleTransition_Intro) == TASK_NONE)
    {
        BlendPalette(BG_PLTT_ID(8), 16, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
        if (!--sSecondaryTilesetAnimCounterMax)
            sSecondaryTilesetAnimCallback = NULL;
    }
}
