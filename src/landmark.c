#include "global.h"
#include "event_data.h"
#include "constants/region_map_sections.h"

struct Landmark
{
    const u8 *name;
    u16 flag;
};

struct LandmarkList
{
    u8 mapSection;
    u8 id;
    const struct Landmark *const *landmarks;
};

static const u8 LandmarkName_ViridianForest[] = _("Viridian Forest");
static const u8 LandmarkName_MtMoon[] = _("Mt. Moon");
static const u8 LandmarkName_DiglettsCave[] = _("Digletts Cave");
static const u8 LandmarkName_RockTunnel[] = _("Rock Tunnel");
static const u8 LandmarkName_UndergroundPath[] = _("Underground Path");
static const u8 LandmarkName_UndergroundPath2[] = _("Underground Path");
static const u8 LandmarkName_SeafoamIslands[] = _("Seafoam Islands");
static const u8 LandmarkName_PowerPlant[] = _("Power Plant");
static const u8 LandmarkName_VictoryRoad[] = _("Victory Road");
static const u8 LandmarkName_FlowerShop[] = _("Flower Shop");
static const u8 LandmarkName_PokemonDayCare[] = _("Pokémon Day Care");
static const u8 LandmarkName_FishermansHouse[] = _("Fisherman's House");
static const u8 LandmarkName_CyclingRoad[] = _("Cycling Road");
static const u8 LandmarkName_ReceptionGate[] = _("Reception Gate");
static const u8 LandmarkName_SeaCottage[] = _("Sea Cottage");

static const struct Landmark Landmark_ViridianForest = {LandmarkName_ViridianForest, -1};
static const struct Landmark Landmark_MtMoon = {LandmarkName_MtMoon, FLAG_LANDMARK_MT_MOON};
static const struct Landmark Landmark_DiglettsCave = {LandmarkName_DiglettsCave, FLAG_LANDMARK_DIGLETTS_CAVE};
static const struct Landmark Landmark_RockTunnel = {LandmarkName_RockTunnel, FLAG_LANDMARK_ROCK_TUNNEL};
static const struct Landmark Landmark_UndergroundPath = {LandmarkName_UndergroundPath, FLAG_LANDMARK_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL};
static const struct Landmark Landmark_UndergroundPath2 = {LandmarkName_UndergroundPath2, FLAG_LANDMARK_UNDERGROUND_PATH_EAST_WEST_TUNNEL};
static const struct Landmark Landmark_SeafoamIslands = {LandmarkName_SeafoamIslands, FLAG_LANDMARK_SEAFOAM_ISLANDS};
static const struct Landmark Landmark_PowerPlant = {LandmarkName_PowerPlant, FLAG_LANDMARK_POWER_PLANT};
static const struct Landmark Landmark_VictoryRoad = {LandmarkName_VictoryRoad, FLAG_LANDMARK_VICTORY_ROAD};
static const struct Landmark Landmark_FlowerShop = {LandmarkName_FlowerShop, FLAG_LANDMARK_FLOWER_SHOP};
static const struct Landmark Landmark_PokemonDayCare = {LandmarkName_PokemonDayCare, FLAG_LANDMARK_POKEMON_DAYCARE};
static const struct Landmark Landmark_FishermansHouse = {LandmarkName_FishermansHouse, FLAG_LANDMARK_FISHERMANS_HOUSE};
static const struct Landmark Landmark_CyclingRoad = {LandmarkName_CyclingRoad, FLAG_LANDMARK_CYCLING_ROAD};
static const struct Landmark Landmark_ReceptionGate = {LandmarkName_ReceptionGate, FLAG_LANDMARK_RECEPTION_GATE};
static const struct Landmark Landmark_SeaCottage = {LandmarkName_SeaCottage, FLAG_LANDMARK_SEA_COTTAGE};

static const struct Landmark *const Landmarks_Route2_0[]  =
{
    &Landmark_ViridianForest,
    &Landmark_DiglettsCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route2_1[]  =
{
    &Landmark_ViridianForest,
    NULL,
};

static const struct Landmark *const Landmarks_Route2_2[]  =
{
    &Landmark_FlowerShop,
    NULL,
};

static const struct Landmark *const Landmarks_Route4_0[]  =
{
    &Landmark_MtMoon,
    NULL,
};

static const struct Landmark *const Landmarks_Route4_1[]  =
{
    &Landmark_MtMoon,
    NULL,
};

static const struct Landmark *const Landmarks_Route5_0[]  =
{
    &Landmark_PokemonDayCare,
    NULL,
};

static const struct Landmark *const Landmarks_Route5_1[]  =
{
    &Landmark_UndergroundPath,
    NULL,
};

static const struct Landmark *const Landmarks_Route6_0[]  =
{
    &Landmark_UndergroundPath,
    NULL,
};

static const struct Landmark *const Landmarks_Route7_1[]  =
{
    &Landmark_UndergroundPath2,
    NULL,
};

static const struct Landmark *const Landmarks_Route8_0[]  =
{
    &Landmark_UndergroundPath2,
    NULL,
};

static const struct Landmark *const Landmarks_Route10_0[]  =
{
    &Landmark_RockTunnel,
    NULL,
};

static const struct Landmark *const Landmarks_Route10_1[]  =
{
    &Landmark_RockTunnel,
    &Landmark_PowerPlant,
    NULL,
};

static const struct Landmark *const Landmarks_Route10_2[]  =
{
    &Landmark_RockTunnel,
    NULL,
};

static const struct Landmark *const Landmarks_Route11_0[]  =
{
    &Landmark_DiglettsCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route12_3[]  =
{
    &Landmark_FishermansHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route16_0[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route16_1[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route17_0[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route17_1[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route17_2[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route17_3[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route17_4[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route18_0[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route18_1[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route20_2[]  =
{
    &Landmark_SeafoamIslands,
    NULL,
};

static const struct Landmark *const Landmarks_Route20_3[]  =
{
    &Landmark_SeafoamIslands,
    NULL,
};

static const struct Landmark *const Landmarks_Route22_0[]  =
{
    &Landmark_ReceptionGate,
    NULL,
};

static const struct Landmark *const Landmarks_Route23_0[]  =
{
    &Landmark_VictoryRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route25_1[]  =
{
    &Landmark_SeaCottage,
    NULL,
};

static const struct LandmarkList sLandmarkLists[] =
{
    {MAPSEC_ROUTE_2, 0, Landmarks_Route2_0},
    {MAPSEC_ROUTE_2, 1, Landmarks_Route2_1},
    {MAPSEC_ROUTE_2, 2, Landmarks_Route2_2},
    {MAPSEC_ROUTE_4, 0, Landmarks_Route4_0},
    {MAPSEC_ROUTE_4, 0, Landmarks_Route4_1},
    {MAPSEC_ROUTE_5, 0, Landmarks_Route5_0},
    {MAPSEC_ROUTE_5, 1, Landmarks_Route5_1},
    {MAPSEC_ROUTE_6, 0, Landmarks_Route6_0},
    {MAPSEC_ROUTE_7, 1, Landmarks_Route7_1},
    {MAPSEC_ROUTE_8, 0, Landmarks_Route8_0},
    {MAPSEC_ROUTE_10, 0, Landmarks_Route10_0},
    {MAPSEC_ROUTE_10, 1, Landmarks_Route10_1},
    {MAPSEC_ROUTE_10, 2, Landmarks_Route10_2},
    {MAPSEC_ROUTE_11, 0, Landmarks_Route11_0},
    {MAPSEC_ROUTE_12, 3, Landmarks_Route12_3},
    {MAPSEC_ROUTE_16, 0, Landmarks_Route16_0},
    {MAPSEC_ROUTE_16, 1, Landmarks_Route16_1},
    {MAPSEC_ROUTE_17, 0, Landmarks_Route17_0},
    {MAPSEC_ROUTE_17, 1, Landmarks_Route17_1},
    {MAPSEC_ROUTE_17, 2, Landmarks_Route17_2},
    {MAPSEC_ROUTE_17, 3, Landmarks_Route17_3},
    {MAPSEC_ROUTE_17, 4, Landmarks_Route17_4},
    {MAPSEC_ROUTE_18, 0, Landmarks_Route18_0},
    {MAPSEC_ROUTE_18, 1, Landmarks_Route18_1},
    {MAPSEC_ROUTE_20, 2, Landmarks_Route20_2},
    {MAPSEC_ROUTE_20, 3, Landmarks_Route20_3},
    {MAPSEC_ROUTE_22, 0, Landmarks_Route22_0},
    {MAPSEC_ROUTE_23, 0, Landmarks_Route23_0},
    {MAPSEC_ROUTE_25, 1, Landmarks_Route25_1},
    {MAPSEC_NONE, 0, NULL},
};

static const struct Landmark *const *GetLandmarks(u8 mapSection, u8 id);

const u8 *GetLandmarkName(u8 mapSection, u8 id, u8 count)
{
    const struct Landmark *const *landmarks = GetLandmarks(mapSection, id);

    if (!landmarks)
        return NULL;

    while (1)
    {
        const struct Landmark *landmark = *landmarks;

        if (landmark->flag == 0xFFFF || FlagGet(landmark->flag) == TRUE)
        {
            if (count == 0)
                break;
            else
                count--;
        }

        landmarks++;
        if (!*landmarks)
            return NULL;
    }

    return (*landmarks)->name;
}

static const struct Landmark *const *GetLandmarks(u8 mapSection, u8 id)
{
    u16 i = 0;

    for (; sLandmarkLists[i].mapSection != MAPSEC_NONE; i++)
    {
        if (sLandmarkLists[i].mapSection > mapSection)
            return NULL;
        if (sLandmarkLists[i].mapSection == mapSection)
            break;
    }

    if (sLandmarkLists[i].mapSection == MAPSEC_NONE)
        return NULL;

    for (; sLandmarkLists[i].mapSection == mapSection; i++)
    {
        if (sLandmarkLists[i].id == id)
            return sLandmarkLists[i].landmarks;
    }

    return NULL;
}
