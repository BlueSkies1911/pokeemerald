#ifndef GUARD_CONSTANTS_BERRY_H
#define GUARD_CONSTANTS_BERRY_H

#define BERRY_NONE 0

#define BERRY_FIRMNESS_UNKNOWN     0
#define BERRY_FIRMNESS_VERY_SOFT   1
#define BERRY_FIRMNESS_SOFT        2
#define BERRY_FIRMNESS_HARD        3
#define BERRY_FIRMNESS_VERY_HARD   4
#define BERRY_FIRMNESS_SUPER_HARD  5

#define BERRY_COLOR_RED    0
#define BERRY_COLOR_BLUE   1
#define BERRY_COLOR_PURPLE 2
#define BERRY_COLOR_GREEN  3
#define BERRY_COLOR_YELLOW 4
#define BERRY_COLOR_PINK   5

#define FLAVOR_SPICY   0
#define FLAVOR_DRY     1
#define FLAVOR_SWEET   2
#define FLAVOR_BITTER  3
#define FLAVOR_SOUR    4
#define FLAVOR_COUNT   5

#define BERRY_STAGE_NO_BERRY    0  // there is no tree planted and the soil is completely flat.
#define BERRY_STAGE_PLANTED     1
#define BERRY_STAGE_SPROUTED    2
#define BERRY_STAGE_TALLER      3
#define BERRY_STAGE_FLOWERING   4
#define BERRY_STAGE_BERRIES     5
#define BERRY_STAGE_TRUNK       6 // These follow BERRY_STAGE_BERRIES to preserve save compatibility
#define BERRY_STAGE_BUDDING     7
#define BERRY_STAGE_SPARKLING   255

// Berries can be watered in the following stages:
// - BERRY_STAGE_PLANTED
// - BERRY_STAGE_SPROUTED
// - BERRY_STAGE_TALLER
// - BERRY_STAGE_FLOWERING
#define NUM_WATER_STAGES 4

// IDs for berry tree objects, indexes into berryTrees in SaveBlock1
// Named for whatever berry is initially planted there on a new game
// Those with no initial berry are named "soil"
#define BERRY_TREE_ROUTE_1_PECHA      1
#define BERRY_TREE_ROUTE_1_ORAN       2
#define BERRY_TREE_ROUTE_2_SOIL_1     3
#define BERRY_TREE_ROUTE_2_ORAN_1     4
#define BERRY_TREE_ROUTE_2_SOIL_2     5
#define BERRY_TREE_ROUTE_2_CHERI_1    6
#define BERRY_TREE_ROUTE_2_ORAN_2     7
#define BERRY_TREE_ROUTE_2_SOIL_3     8
#define BERRY_TREE_ROUTE_2_PECHA      9
#define BERRY_TREE_ROUTE_2_CHERI_2    10
#define BERRY_TREE_ROUTE_2_LEPPA      11
#define BERRY_TREE_ROUTE_3_NANAB_1    12
#define BERRY_TREE_ROUTE_3_NANAB_2    13
#define BERRY_TREE_ROUTE_3_NANAB_3    14
#define BERRY_TREE_ROUTE_4_CHERI_1    15
#define BERRY_TREE_ROUTE_4_CHERI_2    16
#define BERRY_TREE_ROUTE_4_LEPPA_1    17
#define BERRY_TREE_ROUTE_4_LEPPA_2    18
#define BERRY_TREE_ROUTE_6_RAWST_1    19
#define BERRY_TREE_ROUTE_6_RAWST_2    20
#define BERRY_TREE_ROUTE_6_PECHA_1    21
#define BERRY_TREE_ROUTE_6_PECHA_2    22
#define BERRY_TREE_ROUTE_7_CHESTO_1   23
#define BERRY_TREE_ROUTE_7_SOIL       24
#define BERRY_TREE_ROUTE_7_CHESTO_2   25
#define BERRY_TREE_ROUTE_8_RAZZ_1     26
#define BERRY_TREE_ROUTE_8_RAZZ_2     27
#define BERRY_TREE_ROUTE_8_LUM        28
#define BERRY_TREE_ROUTE_8_ORAN       29
#define BERRY_TREE_ROUTE_9_PERSIM_1   30
#define BERRY_TREE_ROUTE_9_PERSIM_2   31
#define BERRY_TREE_ROUTE_10_WEPEAR_1  32
#define BERRY_TREE_ROUTE_10_PERSIM_1  33
#define BERRY_TREE_ROUTE_10_PERSIM_2  34
#define BERRY_TREE_ROUTE_10_WEPEAR_2  35
#define BERRY_TREE_ROUTE_10_PINAP_1   36
#define BERRY_TREE_ROUTE_10_PINAP_2   37
#define BERRY_TREE_ROUTE_11_KELPSY_1  38
#define BERRY_TREE_ROUTE_11_KELPSY_2  39
#define BERRY_TREE_ROUTE_11_KELPSY_3  40
#define BERRY_TREE_ROUTE_13_POMEG_1   41
#define BERRY_TREE_ROUTE_13_POMEG_2   42
#define BERRY_TREE_ROUTE_14_SITRUS_1  43
#define BERRY_TREE_ROUTE_14_POMEG     44
#define BERRY_TREE_ROUTE_14_SITRUS_2  45
#define BERRY_TREE_ROUTE_14_ASPEAR    46
#define BERRY_TREE_ROUTE_14_PECHA     47
#define BERRY_TREE_ROUTE_15_ASPEAR_1  48
#define BERRY_TREE_ROUTE_15_ASPEAR_2  49
#define BERRY_TREE_ROUTE_15_PECHA_1   50
#define BERRY_TREE_ROUTE_15_PECHA_2   51
#define BERRY_TREE_ROUTE_16_HONDEW_1  52
#define BERRY_TREE_ROUTE_16_HONDEW_2  53
#define BERRY_TREE_ROUTE_18_LEPPA_1   54
#define BERRY_TREE_ROUTE_18_LEPPA_2   55
#define BERRY_TREE_ROUTE_22_ASPEAR    56
#define BERRY_TREE_ROUTE_22_CHESTO    57
#define BERRY_TREE_ROUTE_23_SITRUS_1  58
#define BERRY_TREE_ROUTE_23_RAWST     59
#define BERRY_TREE_ROUTE_23_SITRUS_2  60
#define BERRY_TREE_ROUTE_25_BLUK_1    61
#define BERRY_TREE_ROUTE_25_ORAN      62
#define BERRY_TREE_ROUTE_25_BLUK_2    63
#define BERRY_TREE_ROUTE_123_QUALOT_1 64
#define BERRY_TREE_ROUTE_123_POMEG_1  65
#define BERRY_TREE_ROUTE_117_WEPEAR_3 66
#define BERRY_TREE_ROUTE_123_POMEG_2  67
#define BERRY_TREE_ROUTE_120_RAZZ     68
#define BERRY_TREE_ROUTE_120_NANAB    69
#define BERRY_TREE_ROUTE_120_PINAP    70
#define BERRY_TREE_ROUTE_120_WEPEAR   71
#define BERRY_TREE_ROUTE_121_SOIL_1   72
#define BERRY_TREE_ROUTE_121_NANAB_1  73
#define BERRY_TREE_ROUTE_121_NANAB_2  74
#define BERRY_TREE_ROUTE_121_SOIL_2   75
#define BERRY_TREE_UNUSED             76
#define BERRY_TREE_ROUTE_123_POMEG_3  77
#define BERRY_TREE_ROUTE_123_POMEG_4  78
#define BERRY_TREE_ROUTE_123_GREPA_1  79
#define BERRY_TREE_ROUTE_123_GREPA_2  80
#define BERRY_TREE_ROUTE_123_SOIL     81
#define BERRY_TREE_ROUTE_123_GREPA_3  82
#define BERRY_TREE_ROUTE_123_GREPA_4  83
#define BERRY_TREE_ROUTE_123_QUALOT_2 84
#define BERRY_TREE_ROUTE_123_QUALOT_3 85
#define BERRY_TREE_ROUTE_123_QUALOT_4 86
#define BERRY_TREE_ROUTE_130_LIECHI   87
#define BERRY_TREE_ROUTE_123_PECHA    88
#define BERRY_TREE_ROUTE_123_RAWST    89

// Remainder are unused

#define BERRY_TREES_COUNT 128

#endif // GUARD_CONSTANTS_BERRY_H
