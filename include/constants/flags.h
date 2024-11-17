#ifndef GUARD_CONSTANTS_FLAGS_H
#define GUARD_CONSTANTS_FLAGS_H

#include "constants/opponents.h"

// Temporary Flags
// These temporary flags are are cleared every time a map is loaded. They are used
// for things like shortening an NPCs introduction text if the player already spoke
// to them once.
#define TEMP_FLAGS_START 0x0
#define FLAG_TEMP_1      (TEMP_FLAGS_START + 0x1)
#define FLAG_TEMP_2      (TEMP_FLAGS_START + 0x2)
#define FLAG_TEMP_3      (TEMP_FLAGS_START + 0x3)
#define FLAG_TEMP_4      (TEMP_FLAGS_START + 0x4)
#define FLAG_TEMP_5      (TEMP_FLAGS_START + 0x5)  // Unused Flag
#define FLAG_TEMP_6      (TEMP_FLAGS_START + 0x6)  // Unused Flag
#define FLAG_TEMP_7      (TEMP_FLAGS_START + 0x7)  // Unused Flag
#define FLAG_TEMP_8      (TEMP_FLAGS_START + 0x8)  // Unused Flag
#define FLAG_TEMP_9      (TEMP_FLAGS_START + 0x9)  // Unused Flag
#define FLAG_TEMP_A      (TEMP_FLAGS_START + 0xA)  // Unused Flag
#define FLAG_TEMP_B      (TEMP_FLAGS_START + 0xB)  // Unused Flag
#define FLAG_TEMP_C      (TEMP_FLAGS_START + 0xC)  // Unused Flag
#define FLAG_TEMP_D      (TEMP_FLAGS_START + 0xD)  // Unused Flag
#define FLAG_TEMP_E      (TEMP_FLAGS_START + 0xE)  // Unused Flag
#define FLAG_TEMP_F      (TEMP_FLAGS_START + 0xF)  // Unused Flag
#define FLAG_TEMP_10     (TEMP_FLAGS_START + 0x10) // Unused Flag
#define FLAG_TEMP_11     (TEMP_FLAGS_START + 0x11)
#define FLAG_TEMP_12     (TEMP_FLAGS_START + 0x12)
#define FLAG_TEMP_13     (TEMP_FLAGS_START + 0x13)
#define FLAG_TEMP_14     (TEMP_FLAGS_START + 0x14)
#define FLAG_TEMP_15     (TEMP_FLAGS_START + 0x15)
#define FLAG_TEMP_16     (TEMP_FLAGS_START + 0x16)
#define FLAG_TEMP_17     (TEMP_FLAGS_START + 0x17)
#define FLAG_TEMP_18     (TEMP_FLAGS_START + 0x18)
#define FLAG_TEMP_19     (TEMP_FLAGS_START + 0x19)
#define FLAG_TEMP_1A     (TEMP_FLAGS_START + 0x1A)
#define FLAG_TEMP_1B     (TEMP_FLAGS_START + 0x1B)
#define FLAG_TEMP_1C     (TEMP_FLAGS_START + 0x1C)
#define FLAG_TEMP_1D     (TEMP_FLAGS_START + 0x1D)
#define FLAG_TEMP_1E     (TEMP_FLAGS_START + 0x1E)
#define FLAG_TEMP_1F     (TEMP_FLAGS_START + 0x1F)
#define TEMP_FLAGS_END   FLAG_TEMP_1F
#define NUM_TEMP_FLAGS   (TEMP_FLAGS_END - TEMP_FLAGS_START + 1)

// Scripts
#define FLAG_HIDE_MOM_PLAYERS_HOUSE_2F                               0x20
#define FLAG_SET_WALL_CLOCK                                          0x21
#define FLAG_PALLET_LADY_NOT_BLOCKING_SIGN                           0x22
#define FLAG_HIDE_OAK_IN_PALLET_TOWN                                 0x23
#define FLAG_HIDE_MOM_IN_PALLET_TOWN                                 0x24
#define FLAG_RECEIVED_RUNNING_SHOES                                  0x25
#define FLAG_HIDE_BULBASAUR_BALL                                     0x26
#define FLAG_HIDE_SQUIRTLE_BALL                                      0x27
#define FLAG_HIDE_CHARMANDER_BALL                                    0x28
#define FLAG_HIDE_POKEDEX                                            0x29
#define FLAG_HIDE_OAK_IN_HIS_LAB                                     0x2A
#define FLAG_HIDE_RIVAL_IN_LAB                                       0x2B
#define FLAG_BEAT_RIVAL_IN_OAKS_LAB                                  0x2C
#define FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL                   0x2D
#define FLAG_OAK_SKIP_22_RIVAL_CHECK                                 0x2E
#define FLAG_OAK_SAW_DEX_COMPLETION                                  0x2F
#define FLAG_HIDE_TOWN_MAP                                           0x30
#define FLAG_GOT_POTION_ON_ROUTE_1                                   0x31
#define FLAG_HIDE_PEWTER_CITY_GYM_GUIDE                              0x32
#define FLAG_HIDE_PEWTER_MUSEUM_GUIDE                                0x33
#define FLAG_HIDE_PEWTER_CITY_POKENAV_GUY                            0x34
#define FLAG_GOT_TM39_FROM_BROCK                                     0x35
#define FLAG_GOT_OLD_AMBER                                           0x36
#define FLAG_HIDE_OLD_AMBER                                          0x37
#define FLAG_BOUGHT_MAGIKARP                                         0x38
#define FLAG_GOT_FOSSIL_FROM_MT_MOON                                 0x39
#define FLAG_GOT_DOME_FOSSIL                                         0x3A
#define FLAG_HIDE_DOME_FOSSIL                                        0x3B
#define FLAG_GOT_HELIX_FOSSIL                                        0x3C
#define FLAG_HIDE_HELIX_FOSSIL                                       0x3D
#define FLAG_HIDE_CERULEAN_RIVAL                                     0x3E
#define FLAG_GOT_TM28_FROM_ROCKET                                    0x3F
#define FLAG_HIDE_CERULEAN_ROCKET                                    0x40
#define FLAG_GOT_BICYCLE                                             0x41
#define FLAG_GOT_TM03_FROM_MISTY                                     0x42
#define FLAG_HIDE_NUGGET_BRIDGE_ROCKET                               0x43
#define FLAG_HIDE_BILL_CLEFAIRY                                      0x44
#define FLAG_HIDE_BILL_HUMAN_SEA_COTTAGE                             0x45
#define FLAG_HELPED_BILL_IN_SEA_COTTAGE                              0x46
#define FLAG_GOT_SS_TICKET                                           0x47
#define FLAG_GOT_OLD_ROD                                             0x48
#define FLAG_GOT_BIKE_VOUCHER                                        0x49
#define FLAG_HIDE_SS_ANNE_RIVAL                                      0x4A
#define FLAG_HIDE_SS_ANNE                                            0x4B
#define FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES                       0x4C
#define FLAG_GOT_TM34_FROM_SURGE                                     0x4D
#define FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION                        0x4E
#define FLAG_HIDE_VERMILION_CITY_OAKS_AIDE                           0x4F
#define FLAG_GOT_ITEMFINDER                                          0x50
#define FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE                            0x51
#define FLAG_HIDE_TOWER_RIVAL                                        0x52
#define FLAG_HIDE_TOWER_ROCKET_1                                     0x53
#define FLAG_HIDE_TOWER_ROCKET_2                                     0x54
#define FLAG_HIDE_TOWER_ROCKET_3                                     0x55
#define FLAG_RESCUED_MR_FUJI                                         0x56
#define FLAG_HIDE_TOWER_FUJI                                         0x57
#define FLAG_HIDE_POKEHOUSE_FUJI                                     0x58
#define FLAG_GOT_POKE_FLUTE                                          0x59
#define FLAG_GOT_TM33_FROM_THIRSTY_GIRL                              0x5A
#define FLAG_GOT_TM20_FROM_THIRSTY_GIRL                              0x5B
#define FLAG_GOT_TM16_FROM_THIRSTY_GIRL                              0x5C
#define FLAG_GOT_COIN_CASE                                           0x5D
#define FLAG_GOT_TEA                                                 0x5E
#define FLAG_TALKED_TO_TEA_LADY_AFTER_HOF                            0x5F
#define FLAG_GOT_EEVEE                                               0x60
#define FLAG_GOT_TM19_FROM_ERIKA                                     0x61
#define FLAG_GOT_10_COINS_FROM_GAMBLER                               0x62
#define FLAG_GOT_20_COINS_FROM_GAMBLER                               0x63
#define FLAG_GOT_20_COINS_FROM_GAMBLER_2                             0x64
#define FLAG_HIDE_GAME_CORNER_ROCKET                                 0x65
#define FLAG_OPENED_ROCKET_HIDEOUT                                   0x66
#define FLAG_HIDE_LIFT_KEY                                           0x67
#define FLAG_CAN_USE_ROCKET_HIDEOUT_LIFT                             0x68
#define FLAG_HIDE_SILPH_SCOPE                                        0x69
#define FLAG_HIDE_HIDEOUT_GIOVANNI                                   0x6A
#define FLAG_HIDE_CELADON_ROCKETS                                    0x6B
#define FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE                          0x6C
#define FLAG_RECEIVED_TM27                                           0x6D
#define FLAG_HIDE_ROUTE_12_SNORLAX                                   0x6E
#define FLAG_WOKE_UP_ROUTE_12_SNORLAX                                0x6F
#define FLAG_HIDE_ROUTE_16_SNORLAX                                   0x70
#define FLAG_GOT_GOOD_ROD                                            0x71
#define FLAG_GOT_RECORD_SETTING_MAGIKARP                             0x72
#define FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE                            0x73
#define FLAG_GOT_SUPER_ROD                                           0x74
#define FLAG_GOT_TM06_FROM_KOGA                                      0x75
#define FLAG_GOT_HITMON_FROM_DOJO                                    0x76
#define FLAG_GIVE_SECOND_HITMON                                      0x77
#define FLAG_GOT_TM29_FROM_MR_PSYCHIC                                0x78
#define FLAG_SILPH_2F_DOOR_1                                         0x79
#define FLAG_SILPH_2F_DOOR_2                                         0x7A
#define FLAG_SILPH_3F_DOOR_1                                         0x7B
#define FLAG_SILPH_3F_DOOR_2                                         0x7C
#define FLAG_SILPH_4F_DOOR_1                                         0x7D
#define FLAG_SILPH_4F_DOOR_2                                         0x7E
#define FLAG_SILPH_5F_DOOR_1                                         0x7F
#define FLAG_SILPH_5F_DOOR_2                                         0x80
#define FLAG_SILPH_5F_DOOR_3                                         0x81
#define FLAG_SILPH_6F_DOOR                                           0x82
#define FLAG_SILPH_7F_DOOR_1                                         0x83
#define FLAG_SILPH_7F_DOOR_2                                         0x84
#define FLAG_SILPH_7F_DOOR_3                                         0x85
#define FLAG_SILPH_8F_DOOR                                           0x86
#define FLAG_SILPH_9F_DOOR_1                                         0x87
#define FLAG_SILPH_9F_DOOR_2                                         0x88
#define FLAG_SILPH_9F_DOOR_3                                         0x89
#define FLAG_SILPH_9F_DOOR_4                                         0x8A
#define FLAG_SILPH_10F_DOOR                                          0x8B
#define FLAG_SILPH_11F_DOOR                                          0x8C
#define FLAG_RECEIVED_UPGRADE                                        0x8D
#define FLAG_GOT_LAPRAS_FROM_SILPH                                   0x8E
#define FLAG_GOT_MASTER_BALL_FROM_SILPH                              0x8F
#define FLAG_HIDE_SILPH_ROCKETS                                      0x90
#define FLAG_HIDE_SAFFRON_ROCKETS                                    0x91
#define FLAG_HIDE_SAFFRON_CIVILIANS                                  0x92
#define FLAG_HIDE_SILPH_RIVAL                                        0x93
#define FLAG_HIDE_SAFFRON_FAN_CLUB_BLACKBELT                         0x94
#define FLAG_HIDE_SAFFRON_FAN_CLUB_ROCKER                            0x95
#define FLAG_HIDE_SAFFRON_FAN_CLUB_WOMAN                             0x96
#define FLAG_HIDE_SAFFRON_FAN_CLUB_BEAUTY                            0x97
#define FLAG_GOT_TM04_FROM_SABRINA                                   0x98
#define FLAG_HIDE_SEAFOAM_1F_BOULDER_1                               0x99
#define FLAG_HIDE_SEAFOAM_1F_BOULDER_2                               0x9A
#define FLAG_HIDE_SEAFOAM_B1F_BOULDER_1                              0x9B
#define FLAG_HIDE_SEAFOAM_B1F_BOULDER_2                              0x9C
#define FLAG_HIDE_SEAFOAM_B2F_BOULDER_1                              0x9D
#define FLAG_HIDE_SEAFOAM_B2F_BOULDER_2                              0x9E
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_1                              0x9F
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_2                              0xA0
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_3                              0xA1
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_4                              0xA2
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_5                              0xA3
#define FLAG_HIDE_SEAFOAM_B3F_BOULDER_6                              0xA4
#define FLAG_HIDE_SEAFOAM_B4F_BOULDER_1                              0xA5
#define FLAG_HIDE_SEAFOAM_B4F_BOULDER_2                              0xA6
#define FLAG_STOPPED_SEAFOAM_B3F_CURRENT                             0xA7
#define FLAG_STOPPED_SEAFOAM_B4F_CURRENT                             0xA8
#define FLAG_FOUGHT_ARTICUNO                                         0xA9
#define FLAG_HIDE_ARTICUNO                                           0xAA
#define FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1                          0xAB
#define FLAG_HIDE_POWER_PLANT_ELECTRODE_1                            0xAC
#define FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2                          0xAD
#define FLAG_HIDE_POWER_PLANT_ELECTRODE_2                            0xAE
#define FLAG_FOUGHT_ZAPDOS                                           0xAF
#define FLAG_HIDE_ZAPDOS                                             0xB0
#define FLAG_HIDE_CINNABAR_BILL                                      0xB1
#define FLAG_HIDE_CINNABAR_SEAGALLOP                                 0xB2
#define FLAG_GOT_FOSSIL_POKEMON                                      0xB3
#define FLAG_REVIVED_DOME                                            0xB4
#define FLAG_REVIVED_HELIX                                           0xB5
#define FLAG_REVIVED_AMBER                                           0xB6
#define FLAG_POKEMON_MANSION_SWITCH_STATE                            0xB7
#define FLAG_CINNABAR_GYM_QUIZ_1                                     0xB8
#define FLAG_CINNABAR_GYM_QUIZ_2                                     0xB9
#define FLAG_CINNABAR_GYM_QUIZ_3                                     0xBA
#define FLAG_CINNABAR_GYM_QUIZ_4                                     0xBB
#define FLAG_CINNABAR_GYM_QUIZ_5                                     0xBC
#define FLAG_CINNABAR_GYM_QUIZ_6                                     0xBD
#define FLAG_GOT_TM38_FROM_BLAINE                                    0xBE
#define FLAG_GOT_TM26_FROM_GIOVANNI                                  0xBF
#define FLAG_HIDE_VIRIDIAN_GIOVANNI                                  0xC0
#define FLAG_HIDE_MISC_KANTO_ROCKETS                                 0xC1
#define FLAG_HIDE_ROUTE_22_RIVAL                                     0xC2
#define FLAG_HIDE_VICTORY_ROAD_2F_BOULDER                            0xC3
#define FLAG_HIDE_VICTORY_ROAD_3F_BOULDER                            0xC4
#define FLAG_HIDE_OAK_IN_CHAMP_ROOM                                  0xC5
#define FLAG_HIDE_CREDITS_RIVAL                                      0xC6
#define FLAG_HIDE_CREDITS_OAK                                        0xC7
#define FLAG_HIDE_CERULEAN_CAVE_GUARD                                0xC8
#define FLAG_FOUGHT_MEWTWO                                           0xC9
#define FLAG_HIDE_MEWTWO                                             0xCA
#define FLAG_HIDE_ONE_ISLAND_BILL                                    0xCB
#define FLAG_HIDE_ONE_ISLAND_POKECENTER_BILL                         0xCC
#define FLAG_HIDE_ONE_ISLAND_POKECENTER_CELIO                        0xCD
#define FLAG_SEVII_DETOUR_FINISHED                                   0xCE
#define FLAG_HIDE_MT_EMBER_EXTERIOR_ROCKETS                          0xCF
#define FLAG_HIDE_RUBY                                               0xD0
#define FLAG_GOT_RUBY                                                0xD1
#define FLAG_FOUGHT_MOLTRES                                          0xD2
#define FLAG_HIDE_MOLTRES                                            0xD3
#define FLAG_VISITED_TWO_ISLAND                                      0xD4
#define FLAG_TWO_ISLAND_SHOP_INTRODUCED                              0xD5
#define FLAG_TWO_ISLAND_SHOP_EXPANDED_1                              0xD6
#define FLAG_TWO_ISLAND_SHOP_EXPANDED_2                              0xD7
#define FLAG_TWO_ISLAND_SHOP_EXPANDED_3                              0xD8
#define FLAG_HIDE_TWO_ISLAND_WOMAN                                   0xD9
#define FLAG_HIDE_TWO_ISLAND_BEAUTY                                  0xDA
#define FLAG_HIDE_TWO_ISLAND_SUPER_NERD                              0xDB
#define FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE                    0xDC
#define FLAG_HIDE_TWO_ISLAND_GAME_CORNER_BIKER                       0xDD
#define FLAG_GOT_MOON_STONE_FROM_GAME_CORNER                         0xDE
#define FLAG_NO_ROOM_FOR_GAME_CORNER_MOON_STONE                      0xDF
#define FLAG_HIDE_LOSTELLE_IN_HER_HOME                               0xE0
#define FLAG_RESCUED_LOSTELLE                                        0xE1
#define FLAG_LEARNED_ALL_MOVES_AT_CAPE_BRINK                         0xE2
#define FLAG_GOT_NUGGET_FROM_THREE_ISLAND_PATH                       0xE3
#define FLAG_HIDE_THREE_ISLAND_LONE_BIKER                            0xE4
#define FLAG_HIDE_THREE_ISLAND_BIKERS                                0xE5
#define FLAG_HIDE_THREE_ISLAND_ANTIBIKERS                            0xE6
#define FLAG_GOT_FULL_RESTORE_FROM_THREE_ISLAND_DEFENDER             0xE7
#define FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST                           0xE8
#define FLAG_HIDE_FOUR_ISLAND_RIVAL                                  0xE9
#define FLAG_HIDE_LORELEI_IN_HER_HOUSE                               0xEA
#define FLAG_HIDE_LORELEI_HOUSE_MEOWTH_DOLL                          0xEB
#define FLAG_HIDE_LORELEI_HOUSE_CHANSEY_DOLL                         0xEC
#define FLAG_HIDE_LORELEIS_HOUSE_NIDORAN_F_DOLL                      0xED
#define FLAG_HIDE_LORELEI_HOUSE_JIGGLYPUFF_DOLL                      0xEE
#define FLAG_HIDE_LORELEIS_HOUSE_NIDORAN_M_DOLL                      0xEF
#define FLAG_HIDE_LORELEIS_HOUSE_FEAROW_DOLL                         0xF0
#define FLAG_HIDE_LORELEIS_HOUSE_PIDGEOT_DOLL                        0xF1
#define FLAG_HIDE_LORELEIS_HOUSE_LAPRAS_DOLL                         0xF2
#define FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE                       0xF3
#define FLAG_HIDE_ICEFALL_CAVE_LORELEI                               0xF4
#define FLAG_HIDE_ICEFALL_CAVE_ROCKETS                               0xF5
#define FLAG_UNLOCKED_ROCKET_WAREHOUSE                               0xF6
#define FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE                           0xF7
#define FLAG_HIDE_FIVE_ISLAND_ROCKETS                                0xF8
#define FLAG_GOT_TM42_AT_MEMORIAL_PILLAR                             0xF9
#define FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR                     0xFA
#define FLAG_HIDE_RESORT_GORGEOUS_SELPHY                             0xFB
#define FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY                      0xFC
#define FLAG_HIDE_SELPHYS_BUTLER                                     0xFD
#define FLAG_HIDE_LOST_CAVE_SELPHY                                   0xFE
#define FLAG_HIDE_SIX_ISLAND_POKECENTER_RIVAL                        0xFF
#define FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1                  0x100
#define FLAG_HIDE_RUIN_VALLEY_SCIENTIST                             0x101
#define FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE                        0x102
#define FLAG_HIDE_DOTTED_HOLE_SCIENTIST                             0x103
#define FLAG_LEARNED_YES_NAH_CHANSEY                                0x104
#define FLAG_RECOVERED_SAPPHIRE                                     0x105
#define FLAG_HIDE_SAPPHIRE                                          0x106
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1                          0x107
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2                          0x108
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3                          0x109
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4                          0x10A
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5                          0x10B
#define FLAG_UNUSED_0x10C                                           0x10C
#define FLAG_COLLECTED_SEVEN_BADGES                                 0x10D
#define FLAG_RECEIVED_SQUIRT_BOTTLE                                 0x10E
#define FLAG_MET_PRETTY_PETAL_SHOP_OWNER                            0x10F
#define FLAG_DISABLE_OAK_OLD_SEA_MAP_SCENE                          0x110

#define FLAG_COLLECTED_ALL_SILVER_SYMBOLS                           0x111
#define FLAG_RECEIVED_POKEBLOCK_CASE                                0x112
#define FLAG_RECEIVED_SECRET_POWER                                  0x113
#define FLAG_TV_EXPLAINED                                           0x114
#define FLAG_ENABLE_SCOTT_MATCH_CALL                                0x115
#define FLAG_SCOTT_CALL_BATTLE_FRONTIER                             0x116 // Used in order to activate a phone call from Scott, inviting the player to the SS Tidal.
#define FLAG_PENDING_DAYCARE_EGG                                    0x117
#define FLAG_UNUSED_0x118                                           0x118
#define FLAG_UNUSED_0x119                                           0x119
#define FLAG_COOL_PAINTING_MADE                                     0x11A
#define FLAG_BEAUTY_PAINTING_MADE                                   0x11B
#define FLAG_CUTE_PAINTING_MADE                                     0x11C
#define FLAG_SMART_PAINTING_MADE                                    0x11D
#define FLAG_TOUGH_PAINTING_MADE                                    0x11E
#define FLAG_HIDE_SECRET_BASE_TRAINER                               0x11F
#define FLAG_DECORATION_1                                           0x120
#define FLAG_DECORATION_2                                           0x121
#define FLAG_DECORATION_3                                           0x122
#define FLAG_DECORATION_4                                           0x123
#define FLAG_DECORATION_5                                           0x124
#define FLAG_DECORATION_6                                           0x125
#define FLAG_DECORATION_7                                           0x126
#define FLAG_DECORATION_8                                           0x127
#define FLAG_DECORATION_9                                           0x128
#define FLAG_DECORATION_10                                          0x129
#define FLAG_DECORATION_11                                          0x12A
#define FLAG_DECORATION_12                                          0x12B
#define FLAG_DECORATION_13                                          0x12C
#define FLAG_DECORATION_14                                          0x12D
#define FLAG_FAN_CLUB_STRENGTH_SHARED                               0x12E // Set when you rate the strength of another trainer in Lilycove's Trainer Fan Club.
#define FLAG_CANCEL_BATTLE_ROOM_CHALLENGE                           0x12F
#define FLAG_RECEIVED_GLASS_ORNAMENT                                0x130
#define FLAG_RECEIVED_SILVER_SHIELD                                 0x131
#define FLAG_RECEIVED_GOLD_SHIELD                                   0x132
#define FLAG_HIDE_CINNABAR_POKECENTER_BILL                          0x133
#define FLAG_DEFEATED_SS_TIDAL_TRAINERS                             0x134
#define FLAG_RECEIVED_SPELON_BERRY                                  0x135
#define FLAG_RECEIVED_PAMTRE_BERRY                                  0x136
#define FLAG_RECEIVED_WATMEL_BERRY                                  0x137
#define FLAG_RECEIVED_DURIN_BERRY                                   0x138
#define FLAG_RECEIVED_BELUE_BERRY                                   0x139
#define FLAG_RECEIVED_CHARCOAL                                      0x13A
#define FLAG_UNUSED_0x13B                                           0x13B
#define FLAG_RETURNED_RED_OR_BLUE_ORB                               0x13C
#define FLAG_RECEIVED_TM49                                          0x13D
#define FLAG_RECEIVED_TM28                                          0x13E
#define FLAG_RECEIVED_TM09                                          0x13F
#define FLAG_ENTERED_ELITE_FOUR                                     0x140
#define FLAG_RECEIVED_TM10                                          0x141
#define FLAG_RECEIVED_TM41                                          0x142
#define FLAG_RECEIVED_LAVARIDGE_EGG                                 0x143
#define FLAG_RECEIVED_REVIVED_FOSSIL_MON                            0x144
#define FLAG_SECRET_BASE_REGISTRY_ENABLED                           0x145
#define FLAG_RECEIVED_TM46                                          0x146
#define FLAG_CONTEST_SKETCH_CREATED                                 0x147  // Set but never read
#define FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE                          0x148
#define FLAG_RECEIVED_EXP_SHARE                                     0x149
#define FLAG_POKERUS_EXPLAINED                                      0x14A
#define FLAG_RECEIVED_QUICK_CLAW                                    0x14B
#define FLAG_RECEIVED_KINGS_ROCK                                    0x14C
#define FLAG_RECEIVED_MACHO_BRACE                                   0x14D
#define FLAG_RECEIVED_SOOTHE_BELL                                   0x14E
#define FLAG_RECEIVED_WHITE_HERB                                    0x14F
#define FLAG_RECEIVED_SOFT_SAND                                     0x150
#define FLAG_RECEIVED_CLEANSE_TAG                                   0x151
#define FLAG_RECEIVED_FOCUS_BAND                                    0x152
#define FLAG_DECLINED_WALLY_BATTLE_MAUVILLE                         0x153
#define FLAG_RECEIVED_DEVON_SCOPE                                   0x154
#define FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE                         0x155
#define FLAG_MET_DEVON_EMPLOYEE                                     0x156
#define FLAG_MET_RIVAL_RUSTBORO                                     0x157
#define FLAG_RECEIVED_SILK_SCARF                                    0x158
#define FLAG_NOT_READY_FOR_BATTLE_ROUTE_120                         0x159
#define FLAG_RECEIVED_SS_TICKET                                     0x15A
#define FLAG_MET_RIVAL_LILYCOVE                                     0x15B
#define FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE                      0x15C
#define FLAG_EXCHANGED_SCANNER                                      0x15D
#define FLAG_UNUSED_0x15E                                           0x15E
#define FLAG_PETALBURG_MART_EXPANDED_ITEMS                          0x15F
#define FLAG_RECEIVED_MIRACLE_SEED                                  0x160
#define FLAG_UNUSED_0x161                                           0x161
#define FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK                          0x162
#define FLAG_MET_FANCLUB_YOUNGER_BROTHER                            0x163
#define FLAG_RIVAL_LEFT_FOR_ROUTE103                                0x164
#define FLAG_OMIT_DIVE_FROM_STEVEN_LETTER                           0x165
#define FLAG_REGISTERED_STEVEN_POKENAV                              0x166
#define FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN                        0x167 // Set after you follow Steven to the entrance of the Cave of Origin.
#define FLAG_MET_ARCHIE_SOOTOPOLIS                                  0x168
#define FLAG_MET_MAXIE_SOOTOPOLIS                                   0x169
#define FLAG_MET_SCOTT_RUSTBORO                                     0x16A
#define FLAG_WALLACE_GOES_TO_SKY_PILLAR                             0x16B // Set after speaking to Wallace within the Cave of Origin.
#define FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS                           0x16C
#define FLAG_UNUSED_0x16D                                           0x16D
#define FLAG_UNUSED_0x16C                                           0x16E
#define FLAG_RECEIVED_OLD_SEA_MAP                                   0x16F
#define FLAG_WONDER_CARD_UNUSED_1                                   0x170 // These Wonder Card flags are referenced but never set
#define FLAG_WONDER_CARD_UNUSED_2                                   0x171
#define FLAG_WONDER_CARD_UNUSED_3                                   0x172
#define FLAG_WONDER_CARD_UNUSED_4                                   0x173
#define FLAG_WONDER_CARD_UNUSED_5                                   0x174
#define FLAG_WONDER_CARD_UNUSED_6                                   0x175
#define FLAG_WONDER_CARD_UNUSED_7                                   0x176
#define FLAG_WONDER_CARD_UNUSED_8                                   0x177
#define FLAG_WONDER_CARD_UNUSED_9                                   0x178
#define FLAG_WONDER_CARD_UNUSED_10                                  0x179
#define FLAG_WONDER_CARD_UNUSED_11                                  0x17A
#define FLAG_WONDER_CARD_UNUSED_12                                  0x17B
#define FLAG_WONDER_CARD_UNUSED_13                                  0x17C
#define FLAG_WONDER_CARD_UNUSED_14                                  0x17D
#define FLAG_WONDER_CARD_UNUSED_15                                  0x17E
#define FLAG_WONDER_CARD_UNUSED_16                                  0x17F
#define FLAG_WONDER_CARD_UNUSED_17                                  0x180
#define NUM_WONDER_CARD_FLAGS                (1 + FLAG_WONDER_CARD_UNUSED_17 - FLAG_RECEIVED_OLD_SEA_MAP)
#define FLAG_MIRAGE_TOWER_VISIBLE                                   0x181
#define FLAG_CHOSE_ROOT_FOSSIL                                      0x182
#define FLAG_CHOSE_CLAW_FOSSIL                                      0x183
#define FLAG_RECEIVED_POWDER_JAR                                    0x184
#define FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER                        0x185
#define FLAG_MET_BATTLE_FRONTIER_BREEDER                            0x186
#define FLAG_MET_BATTLE_FRONTIER_MANIAC                             0x187
#define FLAG_ENTERED_CONTEST                                        0x188
#define FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN                         0x189
#define FLAG_MET_BATTLE_FRONTIER_GAMBLER                            0x18A
#define FLAG_ENABLE_MR_STONE_POKENAV                                0x18B
#define FLAG_NURSE_MENTIONS_GOLD_CARD                               0x18C
#define FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR                         0x18D
#define FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR                        0x18E
#define FLAG_UNUSED_0x18F                                           0x18F
#define FLAG_UNUSED_0x190                                           0x190
#define FLAG_UNUSED_0x191                                           0x191
#define FLAG_UNUSED_0x192                                           0x192
#define FLAG_SHOWN_OLD_SEA_MAP                                      0x193
#define FLAG_MOVE_TUTOR_TAUGHT_SWAGGER                              0x194
#define FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT                              0x195
#define FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER                          0x196
#define FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK                           0x197
#define FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH                         0x198
#define FLAG_UNUSED_0x199                                           0x199
#define FLAG_UNUSED_0x19A                                           0x19A
#define FLAG_UNUSED_0x19B                                           0x19B
#define FLAG_UNUSED_0x19C                                           0x19C
#define FLAG_UNUSED_0x19D                                           0x19D
#define FLAG_UNUSED_0x19E                                           0x19E
#define FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE                        0x19F
#define FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE                        0x1A0
#define FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE                        0x1A1
#define FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT                      0x1A2
#define FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT                      0x1A3
#define FLAG_UNUSED_0x1A4                                           0x1A4
#define FLAG_DEFEATED_MEW                                           0x1A5
#define FLAG_UNUSED_0x1A6                                           0x1A6
#define FLAG_UNUSED_0x1A7                                           0x1A7
#define FLAG_CAUGHT_MEW                                             0x1A8
#define FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE                  0x1A9
#define FLAG_MET_SCOTT_IN_FUCHSIA                                   0x1AA
#define FLAG_MET_SCOTT_IN_SAFFRON                                   0x1AB
#define FLAG_MET_SCOTT_IN_LILYCOVE                                  0x1AC
#define FLAG_MET_SCOTT_IN_EVERGRANDE                                0x1AD
#define FLAG_BATTLE_FRONTIER_UNLOCKED                               0x1AE
#define FLAG_SCOTT_GIVES_BATTLE_POINTS                              0x1AF
#define FLAG_COLLECTED_ALL_GOLD_SYMBOLS                             0x1B0
#define FLAG_UNUSED_0x1B1                                           0x1B1
#define FLAG_UNUSED_0x1B2                                           0x1B2
#define FLAG_UNUSED_0x1B3                                           0x1B3
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN              0x1B4
#define FLAG_HIDE_APPRENTICE                                        0x1B5
#define FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN                0x1B6
#define FLAG_HIDE_UNION_ROOM_PLAYER_1                               0x1B7
#define FLAG_HIDE_UNION_ROOM_PLAYER_2                               0x1B8
#define FLAG_HIDE_UNION_ROOM_PLAYER_3                               0x1B9
#define FLAG_HIDE_UNION_ROOM_PLAYER_4                               0x1BA
#define FLAG_HIDE_UNION_ROOM_PLAYER_5                               0x1BB
#define FLAG_HIDE_UNION_ROOM_PLAYER_6                               0x1BC
#define FLAG_HIDE_UNION_ROOM_PLAYER_7                               0x1BD
#define FLAG_HIDE_UNION_ROOM_PLAYER_8                               0x1BE
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1               0x1BF
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2               0x1C0
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3               0x1C1
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4               0x1C2
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5               0x1C3
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6               0x1C4
#define FLAG_HIDE_MEW                                               0x1C5
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY   0x1C6
#define FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM                         0x1C7
#define FLAG_HIDE_SAFFRON_FAN_CLUB_INTERVIEWER                      0x1C8
#define FLAG_HIDE_RUSTBORO_CITY_AQUA_GRUNT                          0x1C9
#define FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1                    0x1CA
#define FLAG_HIDE_UNUSED_0x1CB                                      0x1CB
#define FLAG_HIDE_PLAYERS_HOUSE_DAD                                 0x1CC
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING          0x1CD
#define FLAG_HIDE_CONTEST_POKE_BALL                                 0x1CE
#define FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY                           0x1CF
#define FLAG_HIDE_ROUTE_109_MR_BRINEY                               0x1D0
#define FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT                          0x1D1
#define FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT                          0x1D2
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN            0x1D3
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY                    0x1D4
#define FLAG_HIDE_LILYCOVE_HARBOR_EVENT_TICKET_TAKER                0x1D5
#define FLAG_HIDE_SLATEPORT_CITY_SCOTT                              0x1D6
#define FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY                           0x1D7
#define FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE                       0x1D8
#define FLAG_HIDE_UNUSED_0x1D9                                      0x1D9
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA          0x1DA
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_BEDROOM_MOM               0x1DB
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM                0x1DC
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM                    0x1DD
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM      0x1DE
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK              0x1DF
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK                  0x1E0
#define FLAG_HIDE_UNUSED_0x1E1                                      0x1E1
#define FLAG_HIDE_UNUSED_0x1E2                                      0x1E2
#define FLAG_HIDE_MAUVILLE_CITY_SCOTT                               0x1E3
#define FLAG_HIDE_FUCHSIA_CITY_SCOTT                                0x1E4
#define FLAG_HIDE_SAFFRON_CITY_BATTLE_TENT_SCOTT                    0x1E5
#define FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE                        0x1E6
#define FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE                      0x1E7
#define FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE                          0x1E8
#define FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE                         0x1E9
#define FLAG_HIDE_PETALBURG_GYM_NORMAN                              0x1EA
#define FLAG_UNUSED_0x1EB                                           0x1EB
#define FLAG_HIDE_CELADON_CONTEST_HALL_CONTEST_ATTENDANT_1          0x1EC
#define FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR                           0x1ED
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1                          0x1EE
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2                          0x1EF
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3                          0x1F0
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4                          0x1F1
#define FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS                          0x1F2
#define FLAG_HIDE_PETALBURG_GYM_GREETER                             0x1F3
#define FLAG_UNUSED_0x1F4                                           0x1F4
#define FLAG_UNUSED_0x1F5                                           0x1F5
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM          0x1F6
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM              0x1F7
#define FLAG_HIDE_ROUTE_119_SCOTT                                   0x1F8
#define FLAG_HIDE_LILYCOVE_MOTEL_SCOTT                              0x1F9
#define FLAG_HIDE_MOSSDEEP_CITY_SCOTT                               0x1FA
#define FLAG_HIDE_FANCLUB_OLD_LADY                                  0x1FB
#define FLAG_HIDE_FANCLUB_BOY                                       0x1FC
#define FLAG_HIDE_FANCLUB_LITTLE_BOY                                0x1FD
#define FLAG_HIDE_FANCLUB_LADY                                      0x1FE
#define FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT               0x1FF
#define FLAG_HIDE_LITTLEROOT_TOWN_RIVAL                             0x200
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCH                             0x201
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1                          0x202
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1                          0x203
#define FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1                          0x204
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3                          0x205
#define FLAG_UNUSED_0x206                                           0x206
#define FLAG_UNUSED_0x207                                           0x207
#define FLAG_HIDE_CELADON_CONTEST_HALL_REPORTER                     0x208
#define FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER                   0x209
#define FLAG_HIDE_MAUVILLE_CITY_WALLY                               0x20A
#define FLAG_HIDE_MAUVILLE_CITY_WALLYS_UNCLE                        0x20B
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY                0x20C
#define FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND                   0x20D
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND     0x20E
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE         0x20F
#define FLAG_HIDE_SS_TIDAL_CORRIDOR_SCOTT                           0x210
#define FLAG_UNUSED_0x211                                           0x211
#define FLAG_UNUSED_0x212                                           0x212
#define FLAG_HIDE_ROUTE_116_DROPPED_GLASSES_MAN                     0x213
#define FLAG_HIDE_RUSTBORO_CITY_RIVAL                               0x214
#define FLAG_UNUSED_0x215                                           0x215
#define FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE                           0x216
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL       0x217
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL           0x218
#define FLAG_HIDE_ROUTE_112_TEAM_MAGMA                              0x219
#define FLAG_HIDE_CAVE_OF_ORIGIN_B1F_WALLACE                        0x21A
#define FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE         0x21B
#define FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE         0x21C
#define FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA                          0x21D
#define FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD                          0x21E
#define FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE                            0x21F
#define FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE                             0x220
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE                     0x221
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE                      0x222
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS               0x223
#define FLAG_HIDE_CELADON_CONTEST_HALL_BLEND_MASTER                 0x224
#define FLAG_HIDE_GRANITE_CAVE_STEVEN                               0x225
#define FLAG_HIDE_ROUTE_128_STEVEN                                  0x226
#define FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY                       0x227
#define FLAG_HIDE_BATTLE_FRONTIER_RECEPTION_GATE_SCOTT              0x228
#define FLAG_HIDE_ROUTE_110_BIRCH                                   0x229
#define FLAG_HIDE_UNUSED_0x22A                                      0x22A
#define FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1                             0x22B
#define FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN                      0x22C
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN               0x22D
#define FLAG_HIDE_UNUSED_0x22E                                      0x22E
#define FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY                      0x22F
#define FLAG_HIDE_RUSTBORO_CITY_SCIENTIST                           0x230
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT                  0x231
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE                      0x232
#define FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD                           0x233
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW            0x234
#define FLAG_UNUSED_0x235                                           0x235
#define FLAG_UNUSED_0x236                                           0x236
#define FLAG_HIDE_ROUTE_119_RIVAL                                   0x237
#define FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS                         0x238
#define FLAG_UNUSED_0x239                                           0x239
#define FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS                         0x23A
#define FLAG_HIDE_SKY_PILLAR_WALLACE                                0x23B
#define FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE                              0x23C
#define FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS                              0x23D
#define FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY                       0x23E
#define FLAG_UNUSED_0x23F                                           0x23F
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL                    0x240
#define FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL                           0x241
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA          0x242
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN              0x243
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1           0x244
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2           0x245
#define FLAG_HIDE_PETALBURG_GYM_WALLY                               0x246
#define FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN                           0x247
#define FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY          0x248
#define FLAG_HIDE_LANETTES_HOUSE_LANETTE                            0x249
#define FLAG_HIDE_FALLORBOR_POKEMON_CENTER_LANETTE                  0x24A
#define FLAG_HIDE_TRICK_HOUSE_ENTRANCE_MAN                          0x24B
#define FLAG_HIDE_CELADON_CONTEST_HALL_BLEND_MASTER_REPLACEMENT     0x24C
#define FLAG_HIDE_DESERT_UNDERPASS_FOSSIL                           0x24D
#define FLAG_HIDE_ROUTE_111_PLAYER_DESCENT                          0x23E
#define FLAG_HIDE_ROUTE_111_DESERT_FOSSIL                           0x24F
#define FLAG_HIDE_MT_CHIMNEY_TRAINERS                               0x240
#define FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT                         0x241
#define FLAG_HIDE_RUSTURF_TUNNEL_BRINEY                             0x242
#define FLAG_HIDE_RUSTURF_TUNNEL_PEEKO                              0x243
#define FLAG_HIDE_BRINEYS_HOUSE_PEEKO                               0x244
#define FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA                          0x245
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS         0x246
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1     0x247
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2     0x248
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_ARCHIE           0x249
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_CAPTAIN_STERN    0x24A
#define FLAG_HIDE_BATTLE_TOWER_OPPONENT                             0x24B
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL                  0x24C
#define FLAG_HIDE_ROUTE_119_TEAM_AQUA                               0x24D
#define FLAG_HIDE_ROUTE_116_MR_BRINEY                               0x24E
#define FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS                      0x24F
#define FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS                      0x250
#define FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND                        0x251
#define FLAG_HIDE_CELADON_CONTEST_HALL_CONTEST_ATTENDANT_2          0x252
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380          0x253
#define FLAG_HIDE_ROUTE_101_BIRCH                                   0x254
#define FLAG_HIDE_ROUTE_103_BIRCH                                   0x255
#define FLAG_HIDE_TRICK_HOUSE_END_MAN                               0x256
#define FLAG_HIDE_ROUTE_110_TEAM_AQUA                               0x257
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2                          0x258
#define FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2                          0x259
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2                          0x25A
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3                          0x25B
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS                     0x25C
#define FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST                      0x25D
#define FLAG_HIDE_UNUSED_0x25E                                      0x25E
#define FLAG_HIDE_LILYCOVE_HARBOR_FERRY_ATTENDANT                   0x25F
#define FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR                      0x260
#define FLAG_HIDE_UNUSED_0x261                                      0x261
#define FLAG_HIDE_UNUSED_0x262                                      0x262
#define FLAG_HIDE_MAUVILLE_CITY_WATTSON                             0x263
#define FLAG_HIDE_MAUVILLE_GYM_WATTSON                              0x264
#define FLAG_HIDE_ROUTE_121_TEAM_AQUA_GRUNTS                        0x265
#define FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE                             0x266
#define FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA                          0x267
#define FLAG_HIDE_BATTLE_TOWER_REPORTER                             0x268
#define FLAG_HIDE_ROUTE_110_RIVAL                                   0x269
#define FLAG_HIDE_CHAMPIONS_ROOM_RIVAL                              0x26A
#define FLAG_HIDE_CHAMPIONS_ROOM_BIRCH                              0x26B
#define FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE                           0x26C
#define FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE                           0x26D
#define FLAG_HIDE_AQUA_HIDEOUT_GRUNTS                               0x26E
#define FLAG_HIDE_LILYCOVE_MOTEL_GAME_DESIGNERS                     0x26F
#define FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA                              0x270
#define FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA                             0x271
#define FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO                        0x272
#define FLAG_HIDE_LAVARIDGE_TOWN_RIVAL                              0x273
#define FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_ON_BIKE                      0x274
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1                             0x275
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2                             0x276
#define FLAG_UNUSED_0x277                                           0x277
#define FLAG_UNUSED_0x278                                           0x278
#define FLAG_UNUSED_0x279                                           0x279
#define FLAG_UNUSED_0x27A                                           0x27A
#define FLAG_UNUSED_0x27B                                           0x27B
#define FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT               0x27C
#define FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW                 0x27D
#define FLAG_HIDE_ROUTE_128_ARCHIE                                  0x27E
#define FLAG_HIDE_ROUTE_128_MAXIE                                   0x27F
#define FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS                       0x280
#define FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE                          0x281
#define FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN                        0x282
#define FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE              0x283
#define FLAG_HIDE_SS_TIDAL_CORRIDOR_MR_BRINEY                       0x284
#define FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER                       0x285
#define FLAG_RECEIVED_SHOAL_SALT_1                                  0x286
#define FLAG_RECEIVED_SHOAL_SALT_2                                  0x287
#define FLAG_RECEIVED_SHOAL_SALT_3                                  0x288
#define FLAG_RECEIVED_SHOAL_SALT_4                                  0x289
#define FLAG_RECEIVED_SHOAL_SHELL_1                                 0x28A
#define FLAG_RECEIVED_SHOAL_SHELL_2                                 0x28B
#define FLAG_RECEIVED_SHOAL_SHELL_3                                 0x28C
#define FLAG_RECEIVED_SHOAL_SHELL_4                                 0x28D
#define FLAG_HIDE_ROUTE_111_SECRET_POWER_MAN                        0x28E
#define FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION                       0x28F
#define FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN      0x290
#define FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL                          0x291
#define FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL                          0x292
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT 0x293
#define FLAG_HIDE_ROUTE_118_STEVEN                                  0x294
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN                0x295
#define FLAG_UNUSED_0x296                                           0x296
#define FLAG_UNUSED_0x297                                           0x297
#define FLAG_UNUSED_0x298                                           0x298
#define FLAG_HIDE_LILYCOVE_CITY_RIVAL                               0x299
#define FLAG_HIDE_ROUTE_120_STEVEN                                  0x29A
#define FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN                            0x29B
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1                            0x29C
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2                            0x29D
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3                            0x29E
#define FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1                      0x29F
#define FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2                      0x2A0
#define FLAG_HIDE_OLDALE_TOWN_RIVAL                                 0x2A1
#define FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE      0x2A2
#define FLAG_UNUSED_0x2A3                                           0x2A3
#define FLAG_UNUSED_0x2A4                                           0x2A4
#define FLAG_HIDE_RUSTURF_TUNNEL_WANDA                              0x2A5
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA                0x2A6
#define FLAG_UNUSED_0x2A7                                           0x2A7
#define FLAG_UNUSED_0x2A8                                           0x2A8
#define FLAG_UNUSED_0x2A9                                           0x2A9
#define FLAG_UNUSED_0x2AA                                           0x2AA
#define FLAG_UNUSED_0x2AB                                           0x2AB
#define FLAG_UNUSED_0x2AC                                           0x2AC
#define FLAG_HIDE_ROUTE_101_BOY                                     0x2AD

// HM Flags
#define FLAG_GOT_HM01                                               0x2AE
#define FLAG_GOT_HM02                                               0x2AF
#define FLAG_GOT_HM03                                               0x2B0
#define FLAG_GOT_HM04                                               0x2B1
#define FLAG_GOT_HM05                                               0x2B2
#define FLAG_GOT_HM06                                               0x2B3
#define FLAG_RECEIVED_HM07                                          0x2B4
#define FLAG_RECEIVED_HM08                                          0x2B5

// In-Game Trade Flags
#define FLAG_DID_MIMIEN_TRADE                                       0x2B6
#define FLAG_DID_ZYNX_TRADE                                         0x2B7
#define FLAG_DID_MS_NIDO_TRADE                                      0x2B8
#define FLAG_DID_CH_DING_TRADE                                      0x2B9
#define FLAG_DID_NINA_TRADE                                         0x2BA
#define FLAG_DID_MARC_TRADE                                         0x2BB
#define FLAG_DID_ESPHERE_TRADE                                      0x2BC
#define FLAG_DID_TANGENY_TRADE                                      0x2BD
#define FLAG_DID_SEELOR_TRADE                                       0x2BE
#define FLAG_BATTLE_FRONTIER_TRADE_DONE                             0x2BF

// Move Tutor Flags
#define FLAG_TUTOR_COUNTER                                          0x2C0
#define FLAG_TUTOR_DOUBLE_EDGE                                      0x2C1
#define FLAG_TUTOR_DREAM_EATER                                      0x2C2
#define FLAG_TUTOR_MEGA_PUNCH                                       0x2C3
#define FLAG_TUTOR_MEGA_KICK                                        0x2C4
#define FLAG_TUTOR_METRONOME                                        0x2C5
#define FLAG_TUTOR_MIMIC                                            0x2C6
#define FLAG_TUTOR_ROCK_SLIDE                                       0x2C7
#define FLAG_TUTOR_SEISMIC_TOSS                                     0x2C8
#define FLAG_TUTOR_SOFT_BOILED                                      0x2C9
#define FLAG_TUTOR_SUBSTITUTE                                       0x2CA
#define FLAG_TUTOR_THUNDER_WAVE                                     0x2CB
#define FLAG_TUTOR_EXPLOSION                                        0x2CC
#define FLAG_TUTOR_BODY_SLAM                                        0x2CD
#define FLAG_TUTOR_SWORDS_DANCE                                     0x2CE
#define FLAG_TUTOR_FRENZY_PLANT                                     0x2CF
#define FLAG_TUTOR_BLAST_BURN                                       0x2D0
#define FLAG_TUTOR_HYDRO_CANNON                                     0x2D1

// Boss Flags
#define FLAG_DEFEATED_BROCK                                         0x2D2
#define FLAG_DEFEATED_MISTY                                         0x2D3
#define FLAG_DEFEATED_LT_SURGE                                      0x2D4
#define FLAG_DEFEATED_ERIKA                                         0x2D5
#define FLAG_DEFEATED_KOGA                                          0x2D6
#define FLAG_DEFEATED_SABRINA                                       0x2D7
#define FLAG_DEFEATED_BLAINE                                        0x2D8
#define FLAG_DEFEATED_LEADER_GIOVANNI                               0x2D9
#define FLAG_DEFEATED_LORELEI                                       0x2DA
#define FLAG_DEFEATED_BRUNO                                         0x2DB
#define FLAG_DEFEATED_AGATHA                                        0x2DC
#define FLAG_DEFEATED_LANCE                                         0x2DD
#define FLAG_DEFEATED_CHAMP                                         0x2DE

// Match Call
#define FLAG_RECEIVED_POKENAV                                       0x2DF
#define FLAG_HAS_MATCH_CALL                                         0x2E0
#define FLAG_ADDED_MATCH_CALL_TO_POKENAV                            0x2E1
#define FLAG_ENABLE_PROF_OAK_FIRST_CALL                             0x2E2
#define FLAG_ENABLE_BROCK_FIRST_CALL                                0x2E3
#define FLAG_ENABLE_DAISY_FIRST_CALL                                0x2E4
#define FLAG_ENABLE_OLD_SEA_MAP_CALL                                0x2E5
#define FLAG_ENABLE_KOICHI_CALL                                     0x2E6
#define FLAG_ENABLE_MOM_MATCH_CALL                                  0x2E7
#define FLAG_ENABLE_PROF_OAK_MATCH_CALL                             0x2E8
#define FLAG_ENABLE_DAISY_MATCH_CALL                                0x2E9
#define FLAG_ENABLE_RIVAL_MATCH_CALL                                0x2EA
#define FLAG_ENABLE_BROCK_MATCH_CALL                                0x2EB
#define FLAG_ENABLE_MISTY_MATCH_CALL                                0x2EC
#define FLAG_ENABLE_LT_SURGE_MATCH_CALL                             0x2ED
#define FLAG_ENABLE_ERIKA_MATCH_CALL                                0x2EE
#define FLAG_ENABLE_KOGA_MATCH_CALL                                 0x2EF
#define FLAG_ENABLE_SABRINA_MATCH_CALL                              0x2F0
#define FLAG_ENABLE_BLAINE_MATCH_CALL                               0x2F1

// Mystery Gift Flags (Unknown)
#define FLAG_MYSTERY_GIFT_DONE                                      0x2F2
#define FLAG_MYSTERY_GIFT_1                                         0x2F3
#define FLAG_MYSTERY_GIFT_2                                         0x2F4
#define FLAG_MYSTERY_GIFT_3                                         0x2F5
#define FLAG_MYSTERY_GIFT_4                                         0x2F6
#define FLAG_MYSTERY_GIFT_5                                         0x2F7
#define FLAG_MYSTERY_GIFT_6                                         0x2F8
#define FLAG_MYSTERY_GIFT_7                                         0x2F9
#define FLAG_MYSTERY_GIFT_8                                         0x2FA
#define FLAG_MYSTERY_GIFT_9                                         0x2FB
#define FLAG_MYSTERY_GIFT_10                                        0x2FC
#define FLAG_MYSTERY_GIFT_11                                        0x2FD
#define FLAG_MYSTERY_GIFT_12                                        0x2FE
#define FLAG_MYSTERY_GIFT_13                                        0x2FF
#define FLAG_MYSTERY_GIFT_14                                        0x300
#define FLAG_MYSTERY_GIFT_15                                        0x301

// Item Ball Flags
#define FLAG_HIDE_VIRIDIAN_FOREST_POKE_BALL                         0x302
#define FLAG_HIDE_VIRIDIAN_FOREST_ANTIDOTE                          0x303
#define FLAG_HIDE_VIRIDIAN_FOREST_POTION_1                          0x304
#define FLAG_HIDE_VIRIDIAN_FOREST_POTION_2                          0x305
#define FLAG_HIDE_MT_MOON_1F_PARALYZE_HEAL                          0x306
#define FLAG_HIDE_MT_MOON_1F_TM09                                   0x307
#define FLAG_HIDE_MT_MOON_1F_POTION                                 0x308
#define FLAG_HIDE_MT_MOON_1F_RARE_CANDY                             0x309
#define FLAG_HIDE_MT_MOON_1F_ESCAPE_ROPE                            0x30A
#define FLAG_HIDE_MT_MOON_1F_MOON_STONE                             0x30B
#define FLAG_HIDE_MT_MOON_B2F_STAR_PIECE                            0x30C
#define FLAG_HIDE_MT_MOON_B2F_TM46                                  0x30D
#define FLAG_HIDE_MT_MOON_B2F_REVIVE                                0x30E
#define FLAG_HIDE_MT_MOON_B2F_ANTIDOTE                              0x30F
#define FLAG_HIDE_SSANNE_1F_ROOM2_TM31                              0x310
#define FLAG_HIDE_SSANNE_2F_ROOM2_STARDUST                          0x311
#define FLAG_HIDE_SSANNE_2F_ROOM4_X_ATTACK                          0x312
#define FLAG_HIDE_SSANNE_B1F_ROOM2_TM44                             0x313
#define FLAG_HIDE_SSANNE_B1F_ROOM3_ETHER                            0x314
#define FLAG_HIDE_SSANNE_B1F_ROOM5_SUPER_POTION                     0x315
#define FLAG_HIDE_SSANNE_KITCHEN_GREAT_BALL                         0x316
#define FLAG_HIDE_ROCK_TUNNEL_1F_REPEL                              0x317
#define FLAG_HIDE_ROCK_TUNNEL_1F_PEARL                              0x318
#define FLAG_HIDE_ROCK_TUNNEL_1F_ESCAPE_ROPE                        0x319
#define FLAG_HIDE_ROCK_TUNNEL_B1F_REVIVE                            0x31A
#define FLAG_HIDE_ROCK_TUNNEL_B1F_MAX_ETHER                         0x31B
#define FLAG_HIDE_ROCKET_HIDEOUT_B1F_ESCAPE_ROPE                    0x31C
#define FLAG_HIDE_ROCKET_HIDEOUT_B1F_HYPER_POTION                   0x31D
#define FLAG_HIDE_ROCKET_HIDEOUT_B2F_TM12                           0x31E
#define FLAG_HIDE_ROCKET_HIDEOUT_B2F_SUPER_POTION                   0x31F
#define FLAG_HIDE_ROCKET_HIDEOUT_B2F_X_SPEED                        0x320
#define FLAG_HIDE_ROCKET_HIDEOUT_B2F_MOON_STONE                     0x321
#define FLAG_HIDE_ROCKET_HIDEOUT_B3F_RARE_CANDY                     0x322
#define FLAG_HIDE_ROCKET_HIDEOUT_B3F_TM21                           0x323
#define FLAG_HIDE_ROCKET_HIDEOUT_B3F_BLACK_GLASSES                  0x324
#define FLAG_HIDE_ROCKET_HIDEOUT_B4F_CALCIUM                        0x325
#define FLAG_HIDE_ROCKET_HIDEOUT_B4F_TM49                           0x326
#define FLAG_HIDE_ROCKET_HIDEOUT_B4F_MAX_ETHER                      0x327
#define FLAG_HIDE_POKEMON_TOWER_3F_ESCAPE_ROPE                      0x328
#define FLAG_HIDE_POKEMON_TOWER_4F_ELIXIR                           0x329
#define FLAG_HIDE_POKEMON_TOWER_4F_AWAKENING                        0x32A
#define FLAG_HIDE_POKEMON_TOWER_4F_GREAT_BALL                       0x32B
#define FLAG_HIDE_POKEMON_TOWER_5F_NUGGET                           0x32C
#define FLAG_HIDE_POKEMON_TOWER_5F_CLEANSE_TAG                      0x32D
#define FLAG_HIDE_POKEMON_TOWER_6F_RARE_CANDY                       0x32E
#define FLAG_HIDE_POKEMON_TOWER_6F_X_ACCURACY                       0x32F
#define FLAG_HIDE_SILPH_CO_3F_HYPER_POTION                          0x330
#define FLAG_HIDE_SILPH_CO_4F_MAX_REVIVE                            0x331
#define FLAG_HIDE_SILPH_CO_4F_ESCAPE_ROPE                           0x332
#define FLAG_HIDE_SILPH_CO_4F_FULL_HEAL                             0x333
#define FLAG_HIDE_SILPH_CO_4F_TM41                                  0x334
#define FLAG_HIDE_SILPH_CO_5F_PROTEIN                               0x335
#define FLAG_HIDE_SILPH_CO_5F_TM01                                  0x336
#define FLAG_HIDE_SILPH_CO_5F_CARD_KEY                              0x337
#define FLAG_HIDE_SILPH_CO_6F_HP_UP                                 0x338
#define FLAG_HIDE_SILPH_CO_6F_X_SPECIAL                             0x339
#define FLAG_HIDE_SILPH_CO_7F_CALCIUM                               0x33A
#define FLAG_HIDE_SILPH_CO_7F_TM08                                  0x33B
#define FLAG_HIDE_SILPH_CO_8F_IRON                                  0x33C
#define FLAG_HIDE_SILPH_CO_10F_CARBOS                               0x33D
#define FLAG_HIDE_SILPH_CO_10F_ULTRA_BALL                           0x33E
#define FLAG_HIDE_SILPH_CO_10F_RARE_CANDY                           0x33F
#define FLAG_HIDE_SILPH_CO_11F_ZINC                                 0x340
#define FLAG_HIDE_SEAFOAM_ISLANDS_1F_ICE_HEAL                       0x341
#define FLAG_HIDE_SEAFOAM_ISLANDS_B1F_WATER_STONE                   0x342
#define FLAG_HIDE_SEAFOAM_ISLANDS_B1F_REVIVE                        0x343
#define FLAG_HIDE_SEAFOAM_ISLANDS_B2F_BIG_PEARL                     0x344
#define FLAG_HIDE_SEAFOAM_ISLANDS_B3F_HM07                          0x345
#define FLAG_HIDE_SEAFOAM_ISLANDS_B4F_ULTRA_BALL                    0x346
#define FLAG_HIDE_POWER_PLANT_MAX_POTION                            0x347
#define FLAG_HIDE_POWER_PLANT_TM17                                  0x348
#define FLAG_HIDE_POWER_PLANT_TM25                                  0x349
#define FLAG_HIDE_POWER_PLANT_THUNDER_STONE                         0x34A
#define FLAG_HIDE_POWER_PLANT_ELIXIR                                0x34B
#define FLAG_HIDE_POKEMON_MANSION_1F_CARBOS                         0x34C
#define FLAG_HIDE_POKEMON_MANSION_1F_ESCAPE_ROPE                    0x34D
#define FLAG_HIDE_POKEMON_MANSION_1F_PROTEIN                        0x34E
#define FLAG_HIDE_POKEMON_MANSION_2F_ZINC                           0x34F
#define FLAG_HIDE_POKEMON_MANSION_2F_HP_UP                          0x350
#define FLAG_HIDE_POKEMON_MANSION_2F_CALCIUM                        0x351
#define FLAG_HIDE_POKEMON_MANSION_3F_MAX_POTION                     0x352
#define FLAG_HIDE_POKEMON_MANSION_3F_IRON                           0x353
#define FLAG_HIDE_POKEMON_MANSION_B1F_TM14                          0x354
#define FLAG_HIDE_POKEMON_MANSION_B1F_FULL_RESTORE                  0x355
#define FLAG_HIDE_POKEMON_MANSION_B1F_TM22                          0x356
#define FLAG_HIDE_POKEMON_MANSION_B1F_SECRET_KEY                    0x357
#define FLAG_HIDE_VICTORY_ROAD_1F_RARE_CANDY                        0x358
#define FLAG_HIDE_VICTORY_ROAD_1F_TM02                              0x359
#define FLAG_HIDE_VICTORY_ROAD_2F_GUARD_SPEC                        0x35A
#define FLAG_HIDE_VICTORY_ROAD_2F_TM07                              0x35B
#define FLAG_HIDE_VICTORY_ROAD_2F_FULL_HEAL                         0x35C
#define FLAG_HIDE_VICTORY_ROAD_2F_TM37                              0x35D
#define FLAG_HIDE_VICTORY_ROAD_3F_MAX_REVIVE                        0x35E
#define FLAG_HIDE_VICTORY_ROAD_3F_TM50                              0x35F
#define FLAG_HIDE_CERULEAN_CAVE_1F_MAX_ELIXIR                       0x360
#define FLAG_HIDE_CERULEAN_CAVE_1F_NUGGET                           0x361
#define FLAG_HIDE_CERULEAN_CAVE_1F_FULL_RESTORE                     0x362
#define FLAG_HIDE_CERULEAN_CAVE_2F_FULL_RESTORE                     0x363
#define FLAG_HIDE_CERULEAN_CAVE_2F_PP_UP                            0x364
#define FLAG_HIDE_CERULEAN_CAVE_2F_ULTRA_BALL                       0x365
#define FLAG_HIDE_CERULEAN_CAVE_B1F_MAX_REVIVE                      0x366
#define FLAG_HIDE_CERULEAN_CAVE_B1F_ULTRA_BALL                      0x367
#define FLAG_HIDE_MT_EMBER_EXTERIOR_ULTRA_BALL                      0x368
#define FLAG_HIDE_MT_EMBER_EXTERIOR_FIRE_STONE                      0x369
#define FLAG_HIDE_MT_EMBER_EXTERIOR_DIRE_HIT                        0x36A
#define FLAG_HIDE_BERRY_FOREST_MAX_ETHER                            0x36B
#define FLAG_HIDE_BERRY_FOREST_FULL_HEAL                            0x36C
#define FLAG_HIDE_BERRY_FOREST_MAX_ELIXIR                           0x36D
#define FLAG_HIDE_ICEFALL_CAVE_1F_ULTRA_BALL                        0x36E
#define FLAG_HIDE_ICEFALL_CAVE_B1F_FULL_RESTORE                     0x36F
#define FLAG_HIDE_ICEFALL_CAVE_B1F_NEVER_MELT_ICE                   0x370
#define FLAG_HIDE_ROCKET_WAREHOUSE_BIG_PEARL                        0x371
#define FLAG_HIDE_ROCKET_WAREHOUSE_TM36                             0x372
#define FLAG_HIDE_ROCKET_WAREHOUSE_PEARL                            0x373
#define FLAG_HIDE_ROCKET_WAREHOUSE_UP_GRADE                         0x374
#define FLAG_HIDE_LOST_CAVE_ROOM10_SILK_SCARF                       0x375
#define FLAG_HIDE_LOST_CAVE_ROOM11_FULL_INCENSE                     0x376
#define FLAG_HIDE_LOST_CAVE_ROOM12_ODD_INCENSE                      0x377
#define FLAG_HIDE_LOST_CAVE_ROOM13_MAX_REVIVE                       0x378
#define FLAG_HIDE_LOST_CAVE_ROOM14_RARE_CANDY                       0x379
#define FLAG_HIDE_SAFARI_ZONE_CENTER_NUGGET                         0x37A
#define FLAG_HIDE_SAFARI_ZONE_EAST_MAX_POTION                       0x37B
#define FLAG_HIDE_SAFARI_ZONE_EAST_FULL_RESTORE                     0x37C
#define FLAG_HIDE_SAFARI_ZONE_EAST_TM11                             0x37D
#define FLAG_HIDE_SAFARI_ZONE_EAST_LEAF_STONE                       0x37E
#define FLAG_HIDE_SAFARI_ZONE_NORTH_PROTEIN                         0x37F
#define FLAG_HIDE_SAFARI_ZONE_NORTH_TM47                            0x380
#define FLAG_HIDE_SAFARI_ZONE_NORTH_QUICK_CLAW                      0x381
#define FLAG_HIDE_SAFARI_ZONE_WEST_TM32                             0x382
#define FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH                       0x383
#define FLAG_HIDE_SAFARI_ZONE_WEST_MAX_POTION                       0x384
#define FLAG_HIDE_SAFARI_ZONE_WEST_MAX_REVIVE                       0x385
#define FLAG_HIDE_VIRIDIAN_CITY_POTION                              0x386
#define FLAG_HIDE_CELADON_CITY_ETHER                                0x387
#define FLAG_HIDE_EEVEE_BALL                                        0x388
#define FLAG_HIDE_FUCHSIA_CITY_WARDENS_HOUSE_RARE_CANDY             0x389
#define FLAG_HIDE_DOJO_HITMONLEE_BALL                               0x38A
#define FLAG_HIDE_DOJO_HITMONCHAN_BALL                              0x38B
#define FLAG_HIDE_TWO_ISLAND_REVIVE                                 0x38C
#define FLAG_HIDE_THREE_ISLAND_ZINC                                 0x38D
#define FLAG_HIDE_FOUR_ISLAND_STAR_PIECE                            0x38E
#define FLAG_HIDE_FOUR_ISLAND_STARDUST                              0x38F
#define FLAG_HIDE_ROUTE2_ETHER                                      0x390
#define FLAG_HIDE_ROUTE2_PARALYZE_HEAL                              0x391
#define FLAG_HIDE_ROUTE4_TM05                                       0x392
#define FLAG_HIDE_ROUTE9_TM40                                       0x393
#define FLAG_HIDE_ROUTE9_BURN_HEAL                                  0x394
#define FLAG_HIDE_ROUTE11_X_DEFEND                                  0x395
#define FLAG_HIDE_ROUTE11_GREAT_BALL                                0x396
#define FLAG_HIDE_ROUTE11_AWAKENING                                 0x397
#define FLAG_HIDE_ROUTE12_TM48                                      0x398
#define FLAG_HIDE_ROUTE12_IRON                                      0x399
#define FLAG_HIDE_ROUTE15_TM18                                      0x39A
#define FLAG_HIDE_ROUTE24_TM45                                      0x39B
#define FLAG_HIDE_ROUTE25_TM43                                      0x39C
#define FLAG_HIDE_KINDLE_ROAD_ETHER                                 0x39D
#define FLAG_HIDE_KINDLE_ROAD_MAX_REPEL                             0x39E
#define FLAG_HIDE_KINDLE_ROAD_CARBOS                                0x39F
#define FLAG_HIDE_FIVE_ISLAND_MEADOW_MAX_POTION                     0x3A0
#define FLAG_HIDE_FIVE_ISLAND_MEADOW_PP_UP                          0x3A1
#define FLAG_HIDE_MEMORIAL_PILLAR_METAL_COAT                        0x3A2
#define FLAG_HIDE_WATER_PATH_ELIXIR                                 0x3A3
#define FLAG_HIDE_WATER_PATH_DRAGON_SCALE                           0x3A4
#define FLAG_HIDE_RUIN_VALLEY_FULL_RESTORE                          0x3A5
#define FLAG_HIDE_RUIN_VALLEY_HP_UP                                 0x3A6
#define FLAG_HIDE_RUIN_VALLEY_SUN_STONE                             0x3A7
#define FLAG_HIDE_OUTCAST_ISLAND_PP_UP                              0x3A8
#define FLAG_HIDE_SEVAULT_CANYON_KINGS_ROCK                         0x3A9
#define FLAG_HIDE_SEVAULT_CANYON_MAX_ELIXIR                         0x3AA
#define FLAG_HIDE_SEVAULT_CANYON_NUGGET                             0x3AB
#define FLAG_HIDE_SEVAULT_CANYON_HOUSE_LUCKY_PUNCH                  0x3AC
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_1_ORANGE_MAIL                  0x3AD
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_HARBOR_MAIL                  0x3AE
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_WAVE_MAIL                    0x3AF
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_SHADOW_MAIL                  0x3B0
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_WOOD_MAIL                    0x3B1
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_4_MECH_MAIL                    0x3B2
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_6_GLITTER_MAIL                 0x3B3
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_7_TROPIC_MAIL                  0x3B4
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_8_BEAD_MAIL                    0x3B5

#define FLAG_ITEM_ROUTE_120_NEST_BALL                               0x3B6
#define FLAG_ITEM_ROUTE_123_ELIXIR                                  0x3B7
#define FLAG_ITEM_NEW_MAUVILLE_THUNDER_STONE                        0x3B8
#define FLAG_RECEIVED_TM45                                          0x3B9
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_TM07                          0x3BA
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_NEVER_MELT_ICE                0x3BB
#define FLAG_ITEM_ROUTE_104_X_ACCURACY                              0x3BC
#define FLAG_ITEM_MAUVILLE_CITY_X_SPEED                             0x3BD
#define FLAG_ITEM_PETALBURD_WOODS_PARALYZE_HEAL                     0x3BE
#define FLAG_ITEM_ROUTE_115_GREAT_BALL                              0x3BF
#define FLAG_ITEM_MT_PYRE_3F_SUPER_REPEL                            0x3C0
#define FLAG_ITEM_ROUTE_118_HYPER_POTION                            0x3C1
#define FLAG_ITEM_NEW_MAUVILLE_FULL_HEAL                            0x3C2
#define FLAG_ITEM_NEW_MAUVILLE_PARALYZE_HEAL                        0x3C3
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MASTER_BALL                      0x3C4
#define FLAG_ITEM_MT_PYRE_2F_ULTRA_BALL                             0x3C5
#define FLAG_ITEM_MT_PYRE_4F_ODD_INCENSE                            0x3C6
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_NUGGET                           0x3C7
#define FLAG_ITEM_ROUTE_108_STAR_PIECE                              0x3C8
#define FLAG_ITEM_ROUTE_104_POTION                                  0x3C9
#define FLAG_ITEM_ROUTE_119_NUGGET                                  0x3CA
#define FLAG_ITEM_ROUTE_111_ELIXIR                                  0x3CB
#define FLAG_ITEM_ROUTE_109_POTION                                  0x3CC
#define FLAG_ITEM_ROUTE_116_POTION                                  0x3CD
#define FLAG_ITEM_ROUTE_119_ELIXIR_2                                0x3CE
#define FLAG_ITEM_ROUTE_120_REVIVE                                  0x3CF
#define FLAG_ITEM_ROUTE_121_REVIVE                                  0x3D0
#define FLAG_ITEM_ROUTE_121_ZINC                                    0x3D1
#define FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY                       0x3D2
#define FLAG_ITEM_ROUTE_123_PP_UP                                   0x3D3
#define FLAG_ITEM_ROUTE_123_REVIVAL_HERB                            0x3D4
#define FLAG_ITEM_ROUTE_125_BIG_PEARL                               0x3D5
#define FLAG_ITEM_ROUTE_127_RARE_CANDY                              0x3D6
#define FLAG_ITEM_ROUTE_132_PROTEIN                                 0x3D7
#define FLAG_ITEM_ROUTE_133_MAX_REVIVE                              0x3D8
#define FLAG_ITEM_ROUTE_134_CARBOS                                  0x3D9
#define FLAG_ITEM_ROUTE_134_STAR_PIECE                              0x3DA
#define FLAG_ITEM_ROUTE_114_ENERGY_POWDER                           0x3DB
#define FLAG_ITEM_ROUTE_115_PP_UP                                   0x3DC
#define FLAG_ITEM_ARTISAN_CAVE_B1F_HP_UP                            0x3DD
#define FLAG_ITEM_ARTISAN_CAVE_1F_CARBOS                            0x3DE
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_MAX_ELIXIR                    0x3DF
#define FLAG_ITEM_RUSTURF_TUNNEL_MAX_ETHER                          0x3E0
#define FLAG_ITEM_RUSTURF_TUNNEL_POKE_BALL                          0x3E1
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_1R_NUGGET                        0x3E2
#define FLAG_ITEM_ROUTE_113_HYPER_POTION                            0x3E3
#define FLAG_ITEM_LILYCOVE_CITY_MAX_REPEL                           0x3E4
#define FLAG_ITEM_MOSSDEEP_CITY_NET_BALL                            0x3E5
#define FLAG_ITEM_ROUTE_115_HEAL_POWDER                             0x3E6
#define FLAG_ITEM_MAGMA_HIDEOUT_4F_MAX_REVIVE                       0x3E7

// Hidden Items
#define FLAG_HIDDEN_ITEMS_START                                     0x3E8
#define HIDDEN_ITEM_VIRIDIAN_FOREST_POTION                                          (FLAG_HIDDEN_ITEMS_START + 0x00)
#define HIDDEN_ITEM_VIRIDIAN_FOREST_ANTIDOTE                                        (FLAG_HIDDEN_ITEMS_START + 0x01)
#define HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM                                       (FLAG_HIDDEN_ITEMS_START + 0x02)
#define HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM_2                                     (FLAG_HIDDEN_ITEMS_START + 0x03)
#define HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM_3                                     (FLAG_HIDDEN_ITEMS_START + 0x04)
#define HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM                                        (FLAG_HIDDEN_ITEMS_START + 0x05)
#define HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM_2                                      (FLAG_HIDDEN_ITEMS_START + 0x06)
#define HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM_3                                      (FLAG_HIDDEN_ITEMS_START + 0x07)
#define HIDDEN_ITEM_MT_MOON_B2F_MOON_STONE                                          (FLAG_HIDDEN_ITEMS_START + 0x08)
#define HIDDEN_ITEM_MT_MOON_B2F_ETHER                                               (FLAG_HIDDEN_ITEMS_START + 0x09)
#define HIDDEN_ITEM_SSANNE_EXTERIOR_PEWTER_CRUNCHIES                                (FLAG_HIDDEN_ITEMS_START + 0x0A)
#define HIDDEN_ITEM_SSANNE_B1F_CORRIDOR_HYPER_POTION                                (FLAG_HIDDEN_ITEMS_START + 0x0B)
#define HIDDEN_ITEM_SSANNE_KITCHEN_PECHA_BERRY                                      (FLAG_HIDDEN_ITEMS_START + 0x0C)
#define HIDDEN_ITEM_SSANNE_KITCHEN_CHERI_BERRY                                      (FLAG_HIDDEN_ITEMS_START + 0x0D)
#define HIDDEN_ITEM_SSANNE_KITCHEN_CHESTO_BERRY                                     (FLAG_HIDDEN_ITEMS_START + 0x0E)
#define HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_POTION                      (FLAG_HIDDEN_ITEMS_START + 0x0F)
#define HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ANTIDOTE                    (FLAG_HIDDEN_ITEMS_START + 0x10)
#define HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_PARALYZE_HEAL               (FLAG_HIDDEN_ITEMS_START + 0x11)
#define HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_AWAKENING                   (FLAG_HIDDEN_ITEMS_START + 0x12)
#define HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_BURN_HEAL                   (FLAG_HIDDEN_ITEMS_START + 0x13)
#define HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ICE_HEAL                    (FLAG_HIDDEN_ITEMS_START + 0x14)
#define HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ETHER                       (FLAG_HIDDEN_ITEMS_START + 0x15)
#define HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_POTION                        (FLAG_HIDDEN_ITEMS_START + 0x16)
#define HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ANTIDOTE                      (FLAG_HIDDEN_ITEMS_START + 0x17)
#define HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_PARALYZE_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x18)
#define HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_AWAKENING                     (FLAG_HIDDEN_ITEMS_START + 0x19)
#define HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_BURN_HEAL                     (FLAG_HIDDEN_ITEMS_START + 0x1A)
#define HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ICE_HEAL                      (FLAG_HIDDEN_ITEMS_START + 0x1B)
#define HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ETHER                         (FLAG_HIDDEN_ITEMS_START + 0x1C)
#define HIDDEN_ITEM_SILPH_CO_2F_ULTRA_BALL                                          (FLAG_HIDDEN_ITEMS_START + 0x1D)
#define HIDDEN_ITEM_SILPH_CO_3F_PROTEIN                                             (FLAG_HIDDEN_ITEMS_START + 0x1E)
#define HIDDEN_ITEM_SILPH_CO_4F_IRON                                                (FLAG_HIDDEN_ITEMS_START + 0x1F)
#define HIDDEN_ITEM_SILPH_CO_5F_PP_UP                                               (FLAG_HIDDEN_ITEMS_START + 0x20)
#define HIDDEN_ITEM_SILPH_CO_5F_ELIXIR                                              (FLAG_HIDDEN_ITEMS_START + 0x21)
#define HIDDEN_ITEM_SILPH_CO_6F_CARBOS                                              (FLAG_HIDDEN_ITEMS_START + 0x22)
#define HIDDEN_ITEM_SILPH_CO_7F_ZINC                                                (FLAG_HIDDEN_ITEMS_START + 0x23)
#define HIDDEN_ITEM_SILPH_CO_8F_NUGGET                                              (FLAG_HIDDEN_ITEMS_START + 0x24)
#define HIDDEN_ITEM_SILPH_CO_9F_CALCIUM                                             (FLAG_HIDDEN_ITEMS_START + 0x25)
#define HIDDEN_ITEM_SILPH_CO_9F_MAX_POTION                                          (FLAG_HIDDEN_ITEMS_START + 0x26)
#define HIDDEN_ITEM_SILPH_CO_10F_HP_UP                                              (FLAG_HIDDEN_ITEMS_START + 0x27)
#define HIDDEN_ITEM_SILPH_CO_11F_REVIVE                                             (FLAG_HIDDEN_ITEMS_START + 0x28)
#define HIDDEN_ITEM_ROCKET_HIDEOUT_B1F_PP_UP                                        (FLAG_HIDDEN_ITEMS_START + 0x29)
#define HIDDEN_ITEM_ROCKET_HIDEOUT_B3F_NUGGET                                       (FLAG_HIDDEN_ITEMS_START + 0x2A)
#define HIDDEN_ITEM_ROCKET_HIDEOUT_B4F_NET_BALL                                     (FLAG_HIDDEN_ITEMS_START + 0x2B)
#define HIDDEN_ITEM_ROCKET_HIDEOUT_B4F_NEST_BALL                                    (FLAG_HIDDEN_ITEMS_START + 0x2C)
#define HIDDEN_ITEM_POKEMON_TOWER_5F_BIG_MUSHROOM                                   (FLAG_HIDDEN_ITEMS_START + 0x2D)
#define HIDDEN_ITEM_POKEMON_TOWER_7F_SOOTHE_BELL                                    (FLAG_HIDDEN_ITEMS_START + 0x2E)
#define HIDDEN_ITEM_SEAFOAM_ISLANDS_B3F_NUGGET                                      (FLAG_HIDDEN_ITEMS_START + 0x2F)
#define HIDDEN_ITEM_SEAFOAM_ISLANDS_B4F_WATER_STONE                                 (FLAG_HIDDEN_ITEMS_START + 0x30)
#define HIDDEN_ITEM_POWER_PLANT_MAX_ELIXIR                                          (FLAG_HIDDEN_ITEMS_START + 0x31)
#define HIDDEN_ITEM_POWER_PLANT_THUNDER_STONE                                       (FLAG_HIDDEN_ITEMS_START + 0x32)
#define HIDDEN_ITEM_POKEMON_MANSION_1F_MOON_STONE                                   (FLAG_HIDDEN_ITEMS_START + 0x33)
#define HIDDEN_ITEM_POKEMON_MANSION_3F_RARE_CANDY                                   (FLAG_HIDDEN_ITEMS_START + 0x34)
#define HIDDEN_ITEM_POKEMON_MANSION_B1F_ELIXIR                                      (FLAG_HIDDEN_ITEMS_START + 0x35)
#define HIDDEN_ITEM_VICTORY_ROAD_1F_ULTRA_BALL                                      (FLAG_HIDDEN_ITEMS_START + 0x36)
#define HIDDEN_ITEM_VICTORY_ROAD_1F_FULL_RESTORE                                    (FLAG_HIDDEN_ITEMS_START + 0x37)
#define HIDDEN_ITEM_CERULEAN_CAVE_1F_ULTRA_BALL                                     (FLAG_HIDDEN_ITEMS_START + 0x38)
#define HIDDEN_ITEM_MT_EMBER_EXTERIOR_FIRE_STONE                                    (FLAG_HIDDEN_ITEMS_START + 0x39)
#define HIDDEN_ITEM_MT_EMBER_EXTERIOR_ULTRA_BALL                                    (FLAG_HIDDEN_ITEMS_START + 0x3A)
#define HIDDEN_ITEM_BERRY_FOREST_RAZZ_BERRY                                         (FLAG_HIDDEN_ITEMS_START + 0x3B)
#define HIDDEN_ITEM_BERRY_FOREST_BLUK_BERRY                                         (FLAG_HIDDEN_ITEMS_START + 0x3C)
#define HIDDEN_ITEM_BERRY_FOREST_NANAB_BERRY                                        (FLAG_HIDDEN_ITEMS_START + 0x3D)
#define HIDDEN_ITEM_BERRY_FOREST_WEPEAR_BERRY                                       (FLAG_HIDDEN_ITEMS_START + 0x3E)
#define HIDDEN_ITEM_BERRY_FOREST_ORAN_BERRY                                         (FLAG_HIDDEN_ITEMS_START + 0x3F)
#define HIDDEN_ITEM_BERRY_FOREST_CHERI_BERRY                                        (FLAG_HIDDEN_ITEMS_START + 0x40)
#define HIDDEN_ITEM_BERRY_FOREST_CHESTO_BERRY                                       (FLAG_HIDDEN_ITEMS_START + 0x41)
#define HIDDEN_ITEM_BERRY_FOREST_PECHA_BERRY                                        (FLAG_HIDDEN_ITEMS_START + 0x42)
#define HIDDEN_ITEM_BERRY_FOREST_RAWST_BERRY                                        (FLAG_HIDDEN_ITEMS_START + 0x43)
#define HIDDEN_ITEM_BERRY_FOREST_ASPEAR_BERRY                                       (FLAG_HIDDEN_ITEMS_START + 0x44)
#define HIDDEN_ITEM_BERRY_FOREST_PERSIM_BERRY                                       (FLAG_HIDDEN_ITEMS_START + 0x45)
#define HIDDEN_ITEM_BERRY_FOREST_PINAP_BERRY                                        (FLAG_HIDDEN_ITEMS_START + 0x46)
#define HIDDEN_ITEM_BERRY_FOREST_LUM_BERRY                                          (FLAG_HIDDEN_ITEMS_START + 0x47)
#define HIDDEN_ITEM_ROCKET_WAREHOUSE_NEST_BALL                                      (FLAG_HIDDEN_ITEMS_START + 0x48)
#define HIDDEN_ITEM_ROCKET_WAREHOUSE_NET_BALL                                       (FLAG_HIDDEN_ITEMS_START + 0x49)
#define HIDDEN_ITEM_SAFARI_ZONE_CENTER_LEAF_STONE                                   (FLAG_HIDDEN_ITEMS_START + 0x4A)
#define HIDDEN_ITEM_SAFARI_ZONE_WEST_REVIVE                                         (FLAG_HIDDEN_ITEMS_START + 0x4B)
#define HIDDEN_ITEM_VIRIDIAN_CITY_GYM_MACHO_BRACE                                   (FLAG_HIDDEN_ITEMS_START + 0x4C)
#define HIDDEN_ITEM_PEWTER_CITY_POKE_BALL                                           (FLAG_HIDDEN_ITEMS_START + 0x4D)
#define HIDDEN_ITEM_CERULEAN_CITY_RARE_CANDY                                        (FLAG_HIDDEN_ITEMS_START + 0x4E)
#define HIDDEN_ITEM_VERMILION_CITY_MAX_ETHER                                        (FLAG_HIDDEN_ITEMS_START + 0x4F)
#define HIDDEN_ITEM_CELADON_CITY_PP_UP                                              (FLAG_HIDDEN_ITEMS_START + 0x50)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS                                  (FLAG_HIDDEN_ITEMS_START + 0x51)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_2                                (FLAG_HIDDEN_ITEMS_START + 0x52)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_3                                (FLAG_HIDDEN_ITEMS_START + 0x53)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_4                                (FLAG_HIDDEN_ITEMS_START + 0x54)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_5                                (FLAG_HIDDEN_ITEMS_START + 0x55)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_6                                (FLAG_HIDDEN_ITEMS_START + 0x56)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_7                                (FLAG_HIDDEN_ITEMS_START + 0x57)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_8                                (FLAG_HIDDEN_ITEMS_START + 0x58)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_9                                (FLAG_HIDDEN_ITEMS_START + 0x59)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_10                               (FLAG_HIDDEN_ITEMS_START + 0x5A)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_11                               (FLAG_HIDDEN_ITEMS_START + 0x5B)
#define HIDDEN_ITEM_CELADON_CITY_GAME_CORNER_COINS_12                               (FLAG_HIDDEN_ITEMS_START + 0x5C)
#define HIDDEN_ITEM_FUCHSIA_CITY_MAX_REVIVE                                         (FLAG_HIDDEN_ITEMS_START + 0x5D)
#define HIDDEN_ITEM_SAFFRON_CITY_COPYCATS_HOUSE_2F_NUGGET                           (FLAG_HIDDEN_ITEMS_START + 0x5E)
#define HIDDEN_ITEM_THREE_ISLAND_PP_UP                                              (FLAG_HIDDEN_ITEMS_START + 0x5F)
#define HIDDEN_ITEM_FOUR_ISLAND_PEARL                                               (FLAG_HIDDEN_ITEMS_START + 0x60)
#define HIDDEN_ITEM_FOUR_ISLAND_ULTRA_BALL                                          (FLAG_HIDDEN_ITEMS_START + 0x61)
#define HIDDEN_ITEM_SIX_ISLAND_LEPPA_BERRY                                          (FLAG_HIDDEN_ITEMS_START + 0x62)
#define HIDDEN_ITEM_ROUTE3_POTION                                                   (FLAG_HIDDEN_ITEMS_START + 0x63)
#define HIDDEN_ITEM_ROUTE4_GREAT_BALL                                               (FLAG_HIDDEN_ITEMS_START + 0x64)
#define HIDDEN_ITEM_ROUTE4_REPEL                                                    (FLAG_HIDDEN_ITEMS_START + 0x65)
#define HIDDEN_ITEM_ROUTE6_RARE_CANDY                                               (FLAG_HIDDEN_ITEMS_START + 0x66)
#define HIDDEN_ITEM_ROUTE7_GREAT_BALL                                               (FLAG_HIDDEN_ITEMS_START + 0x67)
#define HIDDEN_ITEM_ROUTE8_ETHER                                                    (FLAG_HIDDEN_ITEMS_START + 0x68)
#define HIDDEN_ITEM_ROUTE8_REVIVE                                                   (FLAG_HIDDEN_ITEMS_START + 0x69)
#define HIDDEN_ITEM_ROUTE8_PP_UP                                                    (FLAG_HIDDEN_ITEMS_START + 0x6A)
#define HIDDEN_ITEM_ROUTE9_ETHER                                                    (FLAG_HIDDEN_ITEMS_START + 0x6B)
#define HIDDEN_ITEM_ROUTE9_RARE_CANDY                                               (FLAG_HIDDEN_ITEMS_START + 0x6C)
#define HIDDEN_ITEM_ROUTE9_SUPER_POTION                                             (FLAG_HIDDEN_ITEMS_START + 0x6D)
#define HIDDEN_ITEM_ROUTE10_SUPER_POTION                                            (FLAG_HIDDEN_ITEMS_START + 0x6E)
#define HIDDEN_ITEM_ROUTE10_MAX_ETHER                                               (FLAG_HIDDEN_ITEMS_START + 0x6F)
#define HIDDEN_ITEM_ROUTE11_ESCAPE_ROPE                                             (FLAG_HIDDEN_ITEMS_START + 0x70)
#define HIDDEN_ITEM_ROUTE12_HYPER_POTION                                            (FLAG_HIDDEN_ITEMS_START + 0x71)
#define HIDDEN_ITEM_ROUTE12_RARE_CANDY                                              (FLAG_HIDDEN_ITEMS_START + 0x72)
#define HIDDEN_ITEM_ROUTE12_LEFTOVERS                                               (FLAG_HIDDEN_ITEMS_START + 0x73)
#define HIDDEN_ITEM_ROUTE13_PP_UP                                                   (FLAG_HIDDEN_ITEMS_START + 0x74)
#define HIDDEN_ITEM_ROUTE14_MAX_ELIXIR                                              (FLAG_HIDDEN_ITEMS_START + 0x75)
#define HIDDEN_ITEM_ROUTE14_ZINC                                                    (FLAG_HIDDEN_ITEMS_START + 0x76)
#define HIDDEN_ITEM_ROUTE16_LEFTOVERS                                               (FLAG_HIDDEN_ITEMS_START + 0x77)
#define HIDDEN_ITEM_ROUTE17_FULL_RESTORE                                            (FLAG_HIDDEN_ITEMS_START + 0x78)
#define HIDDEN_ITEM_ROUTE17_MAX_REVIVE                                              (FLAG_HIDDEN_ITEMS_START + 0x79)
#define HIDDEN_ITEM_ROUTE17_MAX_ELIXIR                                              (FLAG_HIDDEN_ITEMS_START + 0x7A)
#define HIDDEN_ITEM_ROUTE17_RARE_CANDY                                              (FLAG_HIDDEN_ITEMS_START + 0x7B)
#define HIDDEN_ITEM_ROUTE17_PP_UP                                                   (FLAG_HIDDEN_ITEMS_START + 0x7C)
#define HIDDEN_ITEM_ROUTE20_STARDUST                                                (FLAG_HIDDEN_ITEMS_START + 0x7D)
#define HIDDEN_ITEM_ROUTE21_PEARL                                                   (FLAG_HIDDEN_ITEMS_START + 0x7E)
#define HIDDEN_ITEM_ROUTE23_FULL_RESTORE                                            (FLAG_HIDDEN_ITEMS_START + 0x7F)
#define HIDDEN_ITEM_ROUTE23_ULTRA_BALL                                              (FLAG_HIDDEN_ITEMS_START + 0x80)
#define HIDDEN_ITEM_ROUTE23_MAX_ETHER                                               (FLAG_HIDDEN_ITEMS_START + 0x81)
#define HIDDEN_ITEM_ROUTE23_FULL_HEAL                                               (FLAG_HIDDEN_ITEMS_START + 0x82)
#define HIDDEN_ITEM_ROUTE23_HYPER_POTION                                            (FLAG_HIDDEN_ITEMS_START + 0x83)
#define HIDDEN_ITEM_ROUTE23_ICE_HEAL                                                (FLAG_HIDDEN_ITEMS_START + 0x84)
#define HIDDEN_ITEM_ROUTE23_MAX_REVIVE                                              (FLAG_HIDDEN_ITEMS_START + 0x85)
#define HIDDEN_ITEM_ROUTE23_MAX_ELIXIR                                              (FLAG_HIDDEN_ITEMS_START + 0x86)
#define HIDDEN_ITEM_ROUTE24_ANTIDOTE                                                (FLAG_HIDDEN_ITEMS_START + 0x87)
#define HIDDEN_ITEM_ROUTE25_ELIXIR                                                  (FLAG_HIDDEN_ITEMS_START + 0x88)
#define HIDDEN_ITEM_ROUTE25_ETHER                                                   (FLAG_HIDDEN_ITEMS_START + 0x89)
#define HIDDEN_ITEM_ROUTE25_POTION                                                  (FLAG_HIDDEN_ITEMS_START + 0x8A)
#define HIDDEN_ITEM_TREASURE_BEACH_STARDUST                                         (FLAG_HIDDEN_ITEMS_START + 0x8B)
#define HIDDEN_ITEM_TREASURE_BEACH_STARDUST_2                                       (FLAG_HIDDEN_ITEMS_START + 0x8C)
#define HIDDEN_ITEM_TREASURE_BEACH_PEARL                                            (FLAG_HIDDEN_ITEMS_START + 0x8D)
#define HIDDEN_ITEM_TREASURE_BEACH_PEARL_2                                          (FLAG_HIDDEN_ITEMS_START + 0x8E)
#define HIDDEN_ITEM_TREASURE_BEACH_ULTRA_BALL                                       (FLAG_HIDDEN_ITEMS_START + 0x8F)
#define HIDDEN_ITEM_TREASURE_BEACH_ULTRA_BALL_2                                     (FLAG_HIDDEN_ITEMS_START + 0x90)
#define HIDDEN_ITEM_TREASURE_BEACH_STAR_PIECE                                       (FLAG_HIDDEN_ITEMS_START + 0x91)
#define HIDDEN_ITEM_TREASURE_BEACH_BIG_PEARL                                        (FLAG_HIDDEN_ITEMS_START + 0x92)
#define HIDDEN_ITEM_CAPE_BRINK_PP_MAX                                               (FLAG_HIDDEN_ITEMS_START + 0x93)
#define HIDDEN_ITEM_CAPE_BRINK_RARE_CANDY                                           (FLAG_HIDDEN_ITEMS_START + 0x94)
#define HIDDEN_ITEM_THREE_ISLAND_PATH_NUGGET                                        (FLAG_HIDDEN_ITEMS_START + 0x95)
#define HIDDEN_ITEM_BOND_BRIDGE_MAX_REPEL                                           (FLAG_HIDDEN_ITEMS_START + 0x96)
#define HIDDEN_ITEM_BOND_BRIDGE_PEARL                                               (FLAG_HIDDEN_ITEMS_START + 0x97)
#define HIDDEN_ITEM_BOND_BRIDGE_STARDUST                                            (FLAG_HIDDEN_ITEMS_START + 0x98)
#define HIDDEN_ITEM_MEMORIAL_PILLAR_BIG_PEARL                                       (FLAG_HIDDEN_ITEMS_START + 0x99)
#define HIDDEN_ITEM_MEMORIAL_PILLAR_RAZZ_BERRY                                      (FLAG_HIDDEN_ITEMS_START + 0x9A)
#define HIDDEN_ITEM_MEMORIAL_PILLAR_SITRUS_BERRY                                    (FLAG_HIDDEN_ITEMS_START + 0x9B)
#define HIDDEN_ITEM_MEMORIAL_PILLAR_BLUK_BERRY                                      (FLAG_HIDDEN_ITEMS_START + 0x9C)
#define HIDDEN_ITEM_RESORT_GORGEOUS_NEST_BALL                                       (FLAG_HIDDEN_ITEMS_START + 0x9D)
#define HIDDEN_ITEM_RESORT_GORGEOUS_STARDUST                                        (FLAG_HIDDEN_ITEMS_START + 0x9E)
#define HIDDEN_ITEM_RESORT_GORGEOUS_STAR_PIECE                                      (FLAG_HIDDEN_ITEMS_START + 0x9F)
#define HIDDEN_ITEM_RESORT_GORGEOUS_STARDUST_2                                      (FLAG_HIDDEN_ITEMS_START + 0xA0)
#define HIDDEN_ITEM_WATER_PATH_ASPEAR_BERRY                                         (FLAG_HIDDEN_ITEMS_START + 0xA1)
#define HIDDEN_ITEM_WATER_PATH_ORAN_BERRY                                           (FLAG_HIDDEN_ITEMS_START + 0xA2)
#define HIDDEN_ITEM_WATER_PATH_PINAP_BERRY                                          (FLAG_HIDDEN_ITEMS_START + 0xA3)
#define HIDDEN_ITEM_GREEN_PATH_ULTRA_BALL                                           (FLAG_HIDDEN_ITEMS_START + 0xA4)
#define HIDDEN_ITEM_OUTCAST_ISLAND_STAR_PIECE                                       (FLAG_HIDDEN_ITEMS_START + 0xA5)
#define HIDDEN_ITEM_OUTCAST_ISLAND_NET_BALL                                         (FLAG_HIDDEN_ITEMS_START + 0xA6)
#define HIDDEN_ITEM_TRAINER_TOWER_EXTERIOR_BIG_PEARL                                (FLAG_HIDDEN_ITEMS_START + 0xA7)
#define HIDDEN_ITEM_TRAINER_TOWER_EXTERIOR_PEARL                                    (FLAG_HIDDEN_ITEMS_START + 0xA8)
#define HIDDEN_ITEM_TRAINER_TOWER_EXTERIOR_NANAB_BERRY                              (FLAG_HIDDEN_ITEMS_START + 0xA9)
#define HIDDEN_ITEM_SEVAULT_CANYON_ENTRANCE_RAWST_BERRY                             (FLAG_HIDDEN_ITEMS_START + 0xAA)
#define HIDDEN_ITEM_SEVAULT_CANYON_CHERI_BERRY                                      (FLAG_HIDDEN_ITEMS_START + 0xAB)
#define HIDDEN_ITEM_TANOBY_RUINS_HEART_SCALE                                        (FLAG_HIDDEN_ITEMS_START + 0xAC)
#define HIDDEN_ITEM_TANOBY_RUINS_HEART_SCALE_2                                      (FLAG_HIDDEN_ITEMS_START + 0xAD)
#define HIDDEN_ITEM_TANOBY_RUINS_HEART_SCALE_3                                      (FLAG_HIDDEN_ITEMS_START + 0xAE)
#define HIDDEN_ITEM_TANOBY_RUINS_HEART_SCALE_4                                      (FLAG_HIDDEN_ITEMS_START + 0xAF)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_CALCIUM                                   (FLAG_HIDDEN_ITEMS_START + 0xB0)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_ZINC                                      (FLAG_HIDDEN_ITEMS_START + 0xB1)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_PROTEIN                                   (FLAG_HIDDEN_ITEMS_START + 0xB2)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_IRON                                      (FLAG_HIDDEN_ITEMS_START + 0xB3)
#define FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET                                         (FLAG_HIDDEN_ITEMS_START + 0xB4)
#define FLAG_HIDDEN_ITEM_UNUSED_0xB5                                                (FLAG_HIDDEN_ITEMS_START + 0xB5)
#define FLAG_HIDDEN_ITEM_UNUSED_0xB6                                                (FLAG_HIDDEN_ITEMS_START + 0xB6)
#define FLAG_HIDDEN_ITEM_UNUSED_0xB7                                                (FLAG_HIDDEN_ITEMS_START + 0xB7)
#define FLAG_HIDDEN_ITEM_UNUSED_0xB8                                                (FLAG_HIDDEN_ITEMS_START + 0xB8)
#define FLAG_HIDDEN_ITEM_UNUSED_0xB9                                                (FLAG_HIDDEN_ITEMS_START + 0xB9)
#define FLAG_HIDDEN_ITEM_UNUSED_0xBA                                                (FLAG_HIDDEN_ITEMS_START + 0xBA)
#define FLAG_HIDDEN_ITEM_UNUSED_0xBB                                                (FLAG_HIDDEN_ITEMS_START + 0xBB)
#define FLAG_HIDDEN_ITEM_UNUSED_0xBC                                                (FLAG_HIDDEN_ITEMS_START + 0xBC)

// Trainer Rematch Flags
#define FLAG_MATCH_CALL_REGISTERED                                  0x4A5
#define FLAG_REMATCH_LASS_JANICE                                    0x4A6
#define FLAG_REMATCH_BUG_CATCHER_COLTON                             0x4A7
#define FLAG_REMATCH_YOUNGSTER_BEN                                  0x4A8
#define FLAG_REMATCH_CAMPER_RICKY                                   0x4A9
#define FLAG_REMATCH_PICNICKER_ISABELLE                             0x4AA
#define FLAG_REMATCH_CAMPER_JEFF                                    0x4AB
#define FLAG_REMATCH_GAMBLER_RICH                                   0x4AC
#define FLAG_REMATCH_TWINS_ELI_ANNE                                 0x4AD
#define FLAG_REMATCH_LASS_MEGAN                                     0x4AE
#define FLAG_REMATCH_BIKER_JAREN                                    0x4AF
#define FLAG_REMATCH_PICNICKER_CAITLIN                              0x4B0
#define FLAG_REMATCH_HIKER_JEREMY                                   0x4B1
#define FLAG_REMATCH_CAMPER_CHRIS                                   0x4B2
#define FLAG_REMATCH_HIKER_TRENT                                    0x4B3
#define FLAG_REMATCH_POKEMANIAC_HERMAN                              0x4B4
#define FLAG_REMATCH_POKEMANIAC_MARK                                0x4B5
#define FLAG_REMATCH_ENGINEER_BERNIE                                0x4B6
#define FLAG_REMATCH_YOUNGSTER_YASU                                 0x4B7
#define FLAG_REMATCH_GAMBLER_DARIAN                                 0x4B8
#define FLAG_REMATCH_FISHERMAN_ELLIOT                               0x4B9
#define FLAG_REMATCH_YOUNG_COUPLE_GIA_JES                           0x4BA
#define FLAG_REMATCH_ROCKER_LUCA                                    0x4BB
#define FLAG_REMATCH_PICNICKER_SUSIE                                0x4BC
#define FLAG_REMATCH_BEAUTY_SHEILA                                  0x4BD
#define FLAG_REMATCH_BIRD_KEEPER_ROBERT                             0x4BE
#define FLAG_REMATCH_BIRD_KEEPER_MARLON                             0x4BF
#define FLAG_REMATCH_BIRD_KEEPER_BENNY                              0x4C0
#define FLAG_REMATCH_BIKER_LUKAS                                    0x4C1
#define FLAG_REMATCH_PICNICKER_BECKY                                0x4C2
#define FLAG_REMATCH_CRUSH_KIN_RON_MYA                              0x4C3
#define FLAG_REMATCH_BEAUTY_GRACE                                   0x4C4
#define FLAG_REMATCH_BIRD_KEEPER_CHESTER                            0x4C5
#define FLAG_REMATCH_BIKER_RUBEN                                    0x4C6
#define FLAG_REMATCH_CUE_BALL_CAMRON                                0x4C7
#define FLAG_REMATCH_CUE_BALL_ISAIAH                                0x4C8
#define FLAG_REMATCH_CUE_BALL_COREY                                 0x4C9
#define FLAG_REMATCH_BIKEAR_JAXON                                   0x4CA
#define FLAG_REMATCH_BIRD_KEEPER_JACOB                              0x4CB
#define FLAG_REMATCH_SWIMMER_MALE_TONY                              0x4CC
#define FLAG_REMATCH_SWIMMER_MALE_MATTHEW                           0x4CD
#define FLAG_REMATCH_SWIMMER_FEMALE_ALICE                           0x4CE
#define FLAG_REMATCH_SWIMMER_MALE_DARRIN                            0x4CF
#define FLAG_REMATCH_PICNICKER_MISSY                                0x4D0
#define FLAG_REMATCH_SWIMMER_FEMALE_MELISSA                         0x4D1
#define FLAG_REMATCH_FISHERMAN_WADE                                 0x4D2
#define FLAG_REMATCH_SIS_AND_BRO_LIL_IAN                            0x4D3
#define FLAG_REMATCH_SWIMMER_MALE_JACK                              0x4D4
#define FLAG_REMATCH_YOUNGSTER_TIMMY                                0x4D5
#define FLAG_REMATCH_LASS_RELI                                      0x4D6
#define FLAG_REMATCH_HIKER_FRANKLIN                                 0x4D7
#define FLAG_REMATCH_PICNICKER_KELSEY                               0x4D8
#define FLAG_REMATCH_YOUNGSTER_CHAD                                 0x4D9
#define FLAG_REMATCH_CRUSH_GIRL_TANYA                               0x4DA
#define FLAG_REMATCH_CRUSH_KIN_MIK_KIA                              0x4DB
#define FLAG_REMATCH_BLACK_BELT_HUGH                                0x4DC
#define FLAG_REMATCH_BLACK_BELT_SHEA                                0x4DD
#define FLAG_REMATCH_CRUSH_GIRL_SHARON                              0x4DE
#define FLAG_REMATCH_SWIMMER_MALE_FINN                              0x4DF
#define FLAG_REMATCH_TUBER_AMIRA                                    0x4E0
#define FLAG_REMATCH_TWINS_JOY_MEG                                  0x4E1
#define FLAG_REMATCH_BIRD_KEEPER_MILO                               0x4E2
#define FLAG_REMATCH_BIRD_KEEPER_CHAZ                               0x4E3
#define FLAG_REMATCH_PKMN_BREEDER_ALIZE                             0x4E4
#define FLAG_REMATCH_PAINTER_RAYNA                                  0x4E5
#define FLAG_REMATCH_YOUNGSTER_DESTIN                               0x4E6
#define FLAG_REMATCH_HIKER_EARL                                     0x4E7
#define FLAG_REMATCH_SWIMMER_MALE_SAMIR                             0x4E8
#define FLAG_REMATCH_POKEMANIAC_HECTOR                              0x4E9
#define FLAG_REMATCH_RUIN_MANIAC_LARRY                              0x4EA
#define FLAG_REMATCH_PSYCHIC_JACLYN                                 0x4EB
#define FLAG_REMATCH_SWIMMER_FEMALE_NICOLE                          0x4EC
#define FLAG_REMATCH_PSYCHIC_RODETTE                                0x4ED
#define FLAG_REMATCH_PSYCHIC_DARIO                                  0x4EE
#define FLAG_REMATCH_JUGGLER_MASON                                  0x4EF
#define FLAG_REMATCH_PKMN_RANGER_NICOLAS                            0x4F0
#define FLAG_REMATCH_PKMN_RANGER_MADELINE                           0x4F1
#define FLAG_REMATCH_PKMN_RANGER_KATELYN                            0x4F2
#define FLAG_REMATCH_COOLTRAINER_LEROY                              0x4F3
#define FLAG_REMATCH_COOLTRAINER_MICHELLE                           0x4F4
#define FLAG_REMATCH_LEADER_BROCK                                   0x4F5
#define FLAG_REMATCH_LEADER_MISTY                                   0x4F6
#define FLAG_REMATCH_LEADER_LT_SURGE                                0x4F7
#define FLAG_REMATCH_LEADER_ERIKA                                   0x4F8
#define FLAG_REMATCH_LEADER_KOGA                                    0x4F9
#define FLAG_REMATCH_LEADER_SABRINA                                 0x4FA
#define FLAG_REMATCH_LEADER_BLAINE                                  0x4FB
#define FLAG_REMATCH_ELITE_FOUR_LORELEI                             0x4FC
#define FLAG_REMATCH_ELITE_FOUR_BRUNO                               0x4FD
#define FLAG_REMATCH_ELITE_FOUR_AGATHA                              0x4FE
#define FLAG_REMATCH_ELITE_FOUR_LANCE                               0x4FF

// Trainer Flags
// Trainer flags occupy 0x500 - 0x85F, the last 9 of which are unused
// See constants/opponents.h. The values there + FLAG_TRAINER_FLAG_START are the flag IDs

#define TRAINER_FLAGS_START                                         0x500
#define TRAINER_FLAGS_END                                           (TRAINER_FLAGS_START + MAX_TRAINERS_COUNT - 1) // 0x85F

// System Flags

#define SYSTEM_FLAGS                                          (TRAINER_FLAGS_END + 1) // 0x860

#define FLAG_SYS_POKEMON_GET                                  (SYSTEM_FLAGS + 0x0) // FLAG_0x860
#define FLAG_SYS_POKEDEX_GET                                  (SYSTEM_FLAGS + 0x1)
#define FLAG_SYS_POKENAV_GET                                  (SYSTEM_FLAGS + 0x2)
#define FLAG_OPENED_START_MENU                                (SYSTEM_FLAGS + 0x3)
#define FLAG_SYS_GAME_CLEAR                                   (SYSTEM_FLAGS + 0x4)
#define FLAG_SYS_CHAT_USED                                    (SYSTEM_FLAGS + 0x5)
#define FLAG_UNLOCKED_TRENDY_SAYINGS                          (SYSTEM_FLAGS + 0x6)

// Badges
#define FLAG_BADGE01_GET                                      (SYSTEM_FLAGS + 0x7)
#define FLAG_BADGE02_GET                                      (SYSTEM_FLAGS + 0x8)
#define FLAG_BADGE03_GET                                      (SYSTEM_FLAGS + 0x9)
#define FLAG_BADGE04_GET                                      (SYSTEM_FLAGS + 0xA)
#define FLAG_BADGE05_GET                                      (SYSTEM_FLAGS + 0xB)
#define FLAG_BADGE06_GET                                      (SYSTEM_FLAGS + 0xC)
#define FLAG_BADGE07_GET                                      (SYSTEM_FLAGS + 0xD)
#define FLAG_BADGE08_GET                                      (SYSTEM_FLAGS + 0xE)
#define NUM_BADGES                                            (1 + FLAG_BADGE08_GET - FLAG_BADGE01_GET)

// Towns and Cities
#define FLAG_WORLD_MAP_PALLET_TOWN                            (SYSTEM_FLAGS + 0xF)
#define FLAG_WORLD_MAP_VIRIDIAN_CITY                          (SYSTEM_FLAGS + 0x10)
#define FLAG_WORLD_MAP_PEWTER_CITY                            (SYSTEM_FLAGS + 0x11)
#define FLAG_WORLD_MAP_CERULEAN_CITY                          (SYSTEM_FLAGS + 0x12)
#define FLAG_WORLD_MAP_VERMILION_CITY                         (SYSTEM_FLAGS + 0x13)
#define FLAG_WORLD_MAP_LAVENDER_TOWN                          (SYSTEM_FLAGS + 0x14)
#define FLAG_WORLD_MAP_CELADON_CITY                           (SYSTEM_FLAGS + 0x15)
#define FLAG_WORLD_MAP_FUCHSIA_CITY                           (SYSTEM_FLAGS + 0x16)
#define FLAG_WORLD_MAP_SAFFRON_CITY                           (SYSTEM_FLAGS + 0x17)
#define FLAG_WORLD_MAP_CINNABAR_ISLAND                        (SYSTEM_FLAGS + 0x18)
#define FLAG_WORLD_MAP_INDIGO_PLATEAU                         (SYSTEM_FLAGS + 0x19)
#define FLAG_WORLD_MAP_ONE_ISLAND                             (SYSTEM_FLAGS + 0x1A)
#define FLAG_WORLD_MAP_TWO_ISLAND                             (SYSTEM_FLAGS + 0x1B)
#define FLAG_WORLD_MAP_THREE_ISLAND                           (SYSTEM_FLAGS + 0x1C)
#define FLAG_WORLD_MAP_FOUR_ISLAND                            (SYSTEM_FLAGS + 0x1D)
#define FLAG_WORLD_MAP_FIVE_ISLAND                            (SYSTEM_FLAGS + 0x1E)
#define FLAG_WORLD_MAP_SIX_ISLAND                             (SYSTEM_FLAGS + 0x1F)
#define FLAG_WORLD_MAP_SEVEN_ISLAND                           (SYSTEM_FLAGS + 0x20)
#define FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F               (SYSTEM_FLAGS + 0x21)
#define FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F              (SYSTEM_FLAGS + 0x22)

#define FLAG_LANDMARK_MT_MOON                                 (SYSTEM_FLAGS + 0x23)
#define FLAG_LANDMARK_DIGLETTS_CAVE                           (SYSTEM_FLAGS + 0x24)
#define FLAG_LANDMARK_ROCK_TUNNEL                             (SYSTEM_FLAGS + 0x25)
#define FLAG_LANDMARK_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL     (SYSTEM_FLAGS + 0x26)
#define FLAG_LANDMARK_UNDERGROUND_PATH_EAST_WEST_TUNNEL       (SYSTEM_FLAGS + 0x27)
#define FLAG_LANDMARK_SEAFOAM_ISLANDS                         (SYSTEM_FLAGS + 0x28)
#define FLAG_LANDMARK_POWER_PLANT                             (SYSTEM_FLAGS + 0x29)
#define FLAG_LANDMARK_VICTORY_ROAD                            (SYSTEM_FLAGS + 0x2A)
#define FLAG_LANDMARK_FLOWER_SHOP                             (SYSTEM_FLAGS + 0x2B)
#define FLAG_LANDMARK_POKEMON_DAYCARE                         (SYSTEM_FLAGS + 0x2C)
#define FLAG_LANDMARK_FISHERMANS_HOUSE                        (SYSTEM_FLAGS + 0x2D)
#define FLAG_LANDMARK_CYCLING_ROAD                            (SYSTEM_FLAGS + 0x2E)
#define FLAG_LANDMARK_RECEPTION_GATE                          (SYSTEM_FLAGS + 0x2F)
#define FLAG_LANDMARK_SEA_COTTAGE                             (SYSTEM_FLAGS + 0x30)
#define FLAG_UNUSED_0x960                                     (SYSTEM_FLAGS + 0x31)
#define FLAG_UNUSED_0x962                                     (SYSTEM_FLAGS + 0x32)
#define FLAG_UNUSED_0x963                                     (SYSTEM_FLAGS + 0x33)
#define FLAG_WORLD_MAP_MT_EMBER_EXTERIOR                      (SYSTEM_FLAGS + 0x34)
#define FLAG_WORLD_MAP_THREE_ISLAND_PATH                      (SYSTEM_FLAGS + 0x35)
#define FLAG_WORLD_MAP_BERRY_FOREST                           (SYSTEM_FLAGS + 0x36)
#define FLAG_WORLD_MAP_ICEFALL_CAVE_ENTRANCE                  (SYSTEM_FLAGS + 0x37)
#define FLAG_WORLD_MAP_ROCKET_WAREHOUSE                       (SYSTEM_FLAGS + 0x38)
#define FLAG_WORLD_MAP_LOST_CAVE_ENTRANCE                     (SYSTEM_FLAGS + 0x39)
#define FLAG_WORLD_MAP_DOTTED_HOLE_1F                         (SYSTEM_FLAGS + 0x3A)
#define FLAG_WORLD_MAP_PATTERN_BUSH                           (SYSTEM_FLAGS + 0x3B)
#define FLAG_WORLD_MAP_SEVAULT_CANYON_TANOBY_KEY              (SYSTEM_FLAGS + 0x3C)
#define FLAG_WORLD_MAP_TANOBY_RUINS_MONEAN_CHAMBER            (SYSTEM_FLAGS + 0x3D)

#define FLAG_SYS_CAN_LINK_WITH_RS                             (SYSTEM_FLAGS + 0x3E) // Seems to be related to linking.
#define FLAG_NURSE_UNION_ROOM_REMINDER                        (SYSTEM_FLAGS + 0x3F)

#define FLAG_SYS_SPECIAL_WILD_BATTLE                          (SYSTEM_FLAGS + 0x40)
#define FLAG_SYS_USE_FLASH                                    (SYSTEM_FLAGS + 0x41)
#define FLAG_SYS_USE_STRENGTH                                 (SYSTEM_FLAGS + 0x42)
#define FLAG_SYS_WEATHER_CTRL                                 (SYSTEM_FLAGS + 0x43)
#define FLAG_SYS_CYCLING_ROAD                                 (SYSTEM_FLAGS + 0x44)
#define FLAG_SYS_SAFARI_MODE                                  (SYSTEM_FLAGS + 0x45)
#define FLAG_SYS_CRUISE_MODE                                  (SYSTEM_FLAGS + 0x46)

#define FLAG_SYS_TV_HOME                                      (SYSTEM_FLAGS + 0x47)
#define FLAG_SYS_TV_WATCH                                     (SYSTEM_FLAGS + 0x48)
#define FLAG_SYS_TV_START                                     (SYSTEM_FLAGS + 0x49)
#define FLAG_SYS_MIX_RECORD                                   (SYSTEM_FLAGS + 0x4A)
#define FLAG_SYS_CLOCK_SET                                    (SYSTEM_FLAGS + 0x4B)
#define FLAG_SYS_NATIONAL_DEX                                 (SYSTEM_FLAGS + 0x4C)
#define FLAG_SYS_SHOAL_TIDE                                   (SYSTEM_FLAGS + 0x4D)
#define FLAG_SYS_RIBBON_GET                                   (SYSTEM_FLAGS + 0x4E)

#define FLAG_UNUSED_0x8FB                                     (SYSTEM_FLAGS + 0x4F)
#define FLAG_LANDMARK_MR_BRINEY_HOUSE                         (SYSTEM_FLAGS + 0x50)
#define FLAG_LANDMARK_ABANDONED_SHIP                          (SYSTEM_FLAGS + 0x51)
#define FLAG_LANDMARK_SEASHORE_HOUSE                          (SYSTEM_FLAGS + 0x52)
#define FLAG_LANDMARK_NEW_MAUVILLE                            (SYSTEM_FLAGS + 0x53)
#define FLAG_LANDMARK_OLD_LADY_REST_SHOP                      (SYSTEM_FLAGS + 0x54)
#define FLAG_LANDMARK_TRICK_HOUSE                             (SYSTEM_FLAGS + 0x55)
#define FLAG_LANDMARK_WINSTRATE_FAMILY                        (SYSTEM_FLAGS + 0x56)
#define FLAG_LANDMARK_GLASS_WORKSHOP                          (SYSTEM_FLAGS + 0x57)
#define FLAG_LANDMARK_LANETTES_HOUSE                          (SYSTEM_FLAGS + 0x58)
#define FLAG_UNUSED_0x964                                     (SYSTEM_FLAGS + 0x59)
#define FLAG_LANDMARK_SEAFLOOR_CAVERN                         (SYSTEM_FLAGS + 0x5A)
#define FLAG_LANDMARK_BATTLE_FRONTIER                         (SYSTEM_FLAGS + 0x5B)
#define FLAG_UNUSED_0x967                                     (SYSTEM_FLAGS + 0x5C)
#define FLAG_LANDMARK_FIERY_PATH                              (SYSTEM_FLAGS + 0x5D)
#define FLAG_LANDMARK_POKEMON_LEAGUE                          (SYSTEM_FLAGS + 0x5E)
#define FLAG_LANDMARK_ISLAND_CAVE                             (SYSTEM_FLAGS + 0x5F)
#define FLAG_LANDMARK_DESERT_RUINS                            (SYSTEM_FLAGS + 0x60)
#define FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE                    (SYSTEM_FLAGS + 0x61)
#define FLAG_LANDMARK_SCORCHED_SLAB                           (SYSTEM_FLAGS + 0x62)
#define FLAG_LANDMARK_ANCIENT_TOMB                            (SYSTEM_FLAGS + 0x63)
#define FLAG_LANDMARK_TUNNELERS_REST_HOUSE                    (SYSTEM_FLAGS + 0x64)
#define FLAG_LANDMARK_HUNTERS_HOUSE                           (SYSTEM_FLAGS + 0x65)
#define FLAG_LANDMARK_SEALED_CHAMBER                          (SYSTEM_FLAGS + 0x66)
#define FLAG_LANDMARK_SKY_PILLAR                              (SYSTEM_FLAGS + 0x67)
#define FLAG_LANDMARK_BERRY_MASTERS_HOUSE                     (SYSTEM_FLAGS + 0x68)
#define FLAG_LANDMARK_ALTERING_CAVE                           (SYSTEM_FLAGS + 0x69)
#define FLAG_LANDMARK_DESERT_UNDERPASS                        (SYSTEM_FLAGS + 0x6A)
#define FLAG_LANDMARK_ARTISAN_CAVE                            (SYSTEM_FLAGS + 0x6B)
#define FLAG_LANDMARK_TRAINER_TOWER                           (SYSTEM_FLAGS + 0x6C)

#define FLAG_SYS_PC_BILL                                      (SYSTEM_FLAGS + 0x6D)
#define FLAG_SYS_MYSTERY_EVENT_ENABLE                         (SYSTEM_FLAGS + 0x6E)
#define FLAG_SYS_ENC_UP_ITEM                                  (SYSTEM_FLAGS + 0x6F)
#define FLAG_SYS_ENC_DOWN_ITEM                                (SYSTEM_FLAGS + 0x70)
#define FLAG_SYS_BRAILLE_DIG                                  (SYSTEM_FLAGS + 0x71)
#define FLAG_SYS_UNUSED_0x72                                  (SYSTEM_FLAGS + 0x72)
#define FLAG_SYS_UNUSED_0x73                                  (SYSTEM_FLAGS + 0x73)
#define FLAG_SYS_UNUSED_0x74                                  (SYSTEM_FLAGS + 0x74)
#define FLAG_SYS_UNUSED_0x75                                  (SYSTEM_FLAGS + 0x75)

#define FLAG_SYS_UNUSED_0x76                                  (SYSTEM_FLAGS + 0x76)

#define FLAG_SYS_SHOAL_ITEM                                   (SYSTEM_FLAGS + 0x77)
#define FLAG_SYS_B_DASH                                       (SYSTEM_FLAGS + 0x78) // RECEIVED Running Shoes
#define FLAG_SYS_CTRL_OBJ_DELETE                              (SYSTEM_FLAGS + 0x79)
#define FLAG_SYS_RESET_RTC_ENABLE                             (SYSTEM_FLAGS + 0x7A)

#define FLAG_SYS_TOWER_SILVER                                 (SYSTEM_FLAGS + 0x7B)
#define FLAG_SYS_TOWER_GOLD                                   (SYSTEM_FLAGS + 0x7C)
#define FLAG_SYS_DOME_SILVER                                  (SYSTEM_FLAGS + 0x7D)
#define FLAG_SYS_DOME_GOLD                                    (SYSTEM_FLAGS + 0x7E)
#define FLAG_SYS_PALACE_SILVER                                (SYSTEM_FLAGS + 0x7F)
#define FLAG_SYS_PALACE_GOLD                                  (SYSTEM_FLAGS + 0x80)
#define FLAG_SYS_ARENA_SILVER                                 (SYSTEM_FLAGS + 0x81)
#define FLAG_SYS_ARENA_GOLD                                   (SYSTEM_FLAGS + 0x82)
#define FLAG_SYS_FACTORY_SILVER                               (SYSTEM_FLAGS + 0x83)
#define FLAG_SYS_FACTORY_GOLD                                 (SYSTEM_FLAGS + 0x84)
#define FLAG_SYS_PIKE_SILVER                                  (SYSTEM_FLAGS + 0x85)
#define FLAG_SYS_PIKE_GOLD                                    (SYSTEM_FLAGS + 0x86)
#define FLAG_SYS_PYRAMID_SILVER                               (SYSTEM_FLAGS + 0x87)
#define FLAG_SYS_PYRAMID_GOLD                                 (SYSTEM_FLAGS + 0x88)
#define FLAG_SYS_FRONTIER_PASS                                (SYSTEM_FLAGS + 0x89)

#define FLAG_SYS_UNUSED_0x8A                                  (SYSTEM_FLAGS + 0x8A)
#define FLAG_SYS_UNUSED_0x8B                                  (SYSTEM_FLAGS + 0x8B)
#define FLAG_SYS_UNUSED_0x8C                                  (SYSTEM_FLAGS + 0x8C)
#define FLAG_ENABLE_SHIP_FARAWAY_ISLAND                       (SYSTEM_FLAGS + 0x8D)

#define FLAG_SHOWN_BOX_WAS_FULL_MESSAGE                       (SYSTEM_FLAGS + 0x8E)

#define FLAG_ARRIVED_ON_FARAWAY_ISLAND                        (SYSTEM_FLAGS + 0x8F)
#define FLAG_ARRIVED_AT_MARINE_CAVE_EMERGE_SPOT               (SYSTEM_FLAGS + 0x90)
#define FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE                   (SYSTEM_FLAGS + 0x91)

#define FLAG_SYS_MYSTERY_GIFT_ENABLE                          (SYSTEM_FLAGS + 0x92)

#define FLAG_ENTERED_MIRAGE_TOWER                             (SYSTEM_FLAGS + 0x93)
#define FLAG_UNUSED_0x94                                      (SYSTEM_FLAGS + 0x94)
#define FLAG_UNUSED_0x95                                      (SYSTEM_FLAGS + 0x95)

#define FLAG_RECEIVED_POKEDEX_FROM_BIRCH                      (SYSTEM_FLAGS + 0x96)

#define FLAG_SYS_PC_STORAGE_DISABLED                          (SYSTEM_FLAGS + 0x97)
#define FLAG_SYS_SEVII_MAP_123                                (SYSTEM_FLAGS + 0x98)
#define FLAG_SYS_SEVII_MAP_4567                               (SYSTEM_FLAGS + 0x99)
#define FLAG_SYS_UNLOCKED_TANOBY_RUINS                        (SYSTEM_FLAGS + 0x9A)

#define FLAG_UNUSED_0x8FA                                     (SYSTEM_FLAGS + 0x9B) // Unused Flag
#define FLAG_UNUSED_0x8FC                                     (SYSTEM_FLAGS + 0x9C) // Unused Flag
#define FLAG_UNUSED_0x8FD                                     (SYSTEM_FLAGS + 0x9D) // Unused Flag
#define FLAG_UNUSED_0x8FE                                     (SYSTEM_FLAGS + 0x9E) // Unused Flag
#define FLAG_UNUSED_0x8FF                                     (SYSTEM_FLAGS + 0x9F) // Unused Flag
#define FLAG_UNUSED_0x900                                     (SYSTEM_FLAGS + 0xA0) // Unused Flag
#define FLAG_UNUSED_0x901                                     (SYSTEM_FLAGS + 0xA1) // Unused Flag
#define FLAG_UNUSED_0x902                                     (SYSTEM_FLAGS + 0xA2) // Unused Flag
#define FLAG_UNUSED_0x903                                     (SYSTEM_FLAGS + 0xA3) // Unused Flag
#define FLAG_UNUSED_0x904                                     (SYSTEM_FLAGS + 0xA4) // Unused Flag
#define FLAG_UNUSED_0x905                                     (SYSTEM_FLAGS + 0xA5) // Unused Flag
#define FLAG_UNUSED_0x906                                     (SYSTEM_FLAGS + 0xA6) // Unused Flag
#define FLAG_UNUSED_0x907                                     (SYSTEM_FLAGS + 0xA7) // Unused Flag
#define FLAG_UNUSED_0x908                                     (SYSTEM_FLAGS + 0xA8) // Unused Flag
#define FLAG_UNUSED_0x909                                     (SYSTEM_FLAGS + 0xA9) // Unused Flag
#define FLAG_UNUSED_0x90A                                     (SYSTEM_FLAGS + 0xAA) // Unused Flag
#define FLAG_UNUSED_0x90B                                     (SYSTEM_FLAGS + 0xAB) // Unused Flag
#define FLAG_UNUSED_0x90C                                     (SYSTEM_FLAGS + 0xAC) // Unused Flag
#define FLAG_UNUSED_0x90D                                     (SYSTEM_FLAGS + 0xAD) // Unused Flag
#define FLAG_UNUSED_0x90E                                     (SYSTEM_FLAGS + 0xAE) // Unused Flag
#define FLAG_UNUSED_0x90F                                     (SYSTEM_FLAGS + 0xAF) // Unused Flag
#define FLAG_UNUSED_0x910                                     (SYSTEM_FLAGS + 0xB0) // Unused Flag
#define FLAG_UNUSED_0x911                                     (SYSTEM_FLAGS + 0xB1) // Unused Flag
#define FLAG_UNUSED_0x912                                     (SYSTEM_FLAGS + 0xB2) // Unused Flag
#define FLAG_UNUSED_0x913                                     (SYSTEM_FLAGS + 0xB3) // Unused Flag
#define FLAG_UNUSED_0x914                                     (SYSTEM_FLAGS + 0xB4) // Unused Flag
#define FLAG_UNUSED_0x915                                     (SYSTEM_FLAGS + 0xB5) // Unused Flag
#define FLAG_UNUSED_0x916                                     (SYSTEM_FLAGS + 0xB6) // Unused Flag
#define FLAG_UNUSED_0x917                                     (SYSTEM_FLAGS + 0xB7) // Unused Flag
#define FLAG_UNUSED_0x918                                     (SYSTEM_FLAGS + 0xB8) // Unused Flag
#define FLAG_UNUSED_0x919                                     (SYSTEM_FLAGS + 0xB9) // Unused Flag
#define FLAG_UNUSED_0x91A                                     (SYSTEM_FLAGS + 0xBA) // Unused Flag
#define FLAG_UNUSED_0x91B                                     (SYSTEM_FLAGS + 0xBB) // Unused Flag
#define FLAG_UNUSED_0x91C                                     (SYSTEM_FLAGS + 0xBC) // Unused Flag
#define FLAG_UNUSED_0x91D                                     (SYSTEM_FLAGS + 0xBD) // Unused Flag
#define FLAG_UNUSED_0x91E                                     (SYSTEM_FLAGS + 0xBE) // Unused Flag
#define FLAG_UNUSED_0x91F                                     (SYSTEM_FLAGS + 0xBF) // Unused Flag

// Daily Flags
// These flags are cleared once per day
// The start and end are byte-aligned because the flags are cleared in byte increments
#define DAILY_FLAGS_START                           (FLAG_UNUSED_0x91F + (8 - FLAG_UNUSED_0x91F % 8))
#define FLAG_RANDOM_WEATHER_RESET                   (DAILY_FLAGS_START + 0x0)
#define FLAG_DAILY_CONTEST_LOBBY_RECEIVED_BERRY     (DAILY_FLAGS_START + 0x1)
#define FLAG_DAILY_SECRET_BASE                      (DAILY_FLAGS_START + 0x2)
#define FLAG_UNUSED_0x923                           (DAILY_FLAGS_START + 0x3)  // Unused Flag
#define FLAG_UNUSED_0x924                           (DAILY_FLAGS_START + 0x4)  // Unused Flag
#define FLAG_UNUSED_0x925                           (DAILY_FLAGS_START + 0x5)  // Unused Flag
#define FLAG_UNUSED_0x926                           (DAILY_FLAGS_START + 0x6)  // Unused Flag
#define FLAG_UNUSED_0x927                           (DAILY_FLAGS_START + 0x7)  // Unused Flag
#define FLAG_UNUSED_0x928                           (DAILY_FLAGS_START + 0x8)  // Unused Flag
#define FLAG_UNUSED_0x929                           (DAILY_FLAGS_START + 0x9)  // Unused Flag
#define FLAG_DAILY_PICKED_LOTO_TICKET               (DAILY_FLAGS_START + 0xA)
#define FLAG_DAILY_ROUTE_114_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xB)
#define FLAG_DAILY_ROUTE_111_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xC)
#define FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY      (DAILY_FLAGS_START + 0xD)
#define FLAG_DAILY_ROUTE_120_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xE)
#define FLAG_DAILY_LILYCOVE_RECEIVED_BERRY          (DAILY_FLAGS_START + 0xF)
#define FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY       (DAILY_FLAGS_START + 0x10)
#define FLAG_DAILY_BERRY_MASTERS_WIFE               (DAILY_FLAGS_START + 0x11)
#define FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY        (DAILY_FLAGS_START + 0x12)
#define FLAG_UNUSED_0x933                           (DAILY_FLAGS_START + 0x13) // Unused Flag
#define FLAG_DAILY_APPRENTICE_LEAVES                (DAILY_FLAGS_START + 0x14)

#define FLAG_UNUSED_0x935                           (DAILY_FLAGS_START + 0x15) // Unused Flag
#define FLAG_UNUSED_0x936                           (DAILY_FLAGS_START + 0x16) // Unused Flag
#define FLAG_UNUSED_0x937                           (DAILY_FLAGS_START + 0x17) // Unused Flag
#define FLAG_UNUSED_0x938                           (DAILY_FLAGS_START + 0x18) // Unused Flag
#define FLAG_UNUSED_0x939                           (DAILY_FLAGS_START + 0x19) // Unused Flag
#define FLAG_UNUSED_0x93A                           (DAILY_FLAGS_START + 0x1A) // Unused Flag
#define FLAG_UNUSED_0x93B                           (DAILY_FLAGS_START + 0x1B) // Unused Flag
#define FLAG_UNUSED_0x93C                           (DAILY_FLAGS_START + 0x1C) // Unused Flag
#define FLAG_UNUSED_0x93D                           (DAILY_FLAGS_START + 0x1D) // Unused Flag
#define FLAG_UNUSED_0x93E                           (DAILY_FLAGS_START + 0x1E) // Unused Flag
#define FLAG_UNUSED_0x93F                           (DAILY_FLAGS_START + 0x1F) // Unused Flag
#define FLAG_UNUSED_0x940                           (DAILY_FLAGS_START + 0x20) // Unused Flag
#define FLAG_UNUSED_0x941                           (DAILY_FLAGS_START + 0x21) // Unused Flag
#define FLAG_UNUSED_0x942                           (DAILY_FLAGS_START + 0x22) // Unused Flag
#define FLAG_UNUSED_0x943                           (DAILY_FLAGS_START + 0x23) // Unused Flag
#define FLAG_UNUSED_0x944                           (DAILY_FLAGS_START + 0x24) // Unused Flag
#define FLAG_UNUSED_0x945                           (DAILY_FLAGS_START + 0x25) // Unused Flag
#define FLAG_UNUSED_0x946                           (DAILY_FLAGS_START + 0x26) // Unused Flag
#define FLAG_UNUSED_0x947                           (DAILY_FLAGS_START + 0x27) // Unused Flag
#define FLAG_UNUSED_0x948                           (DAILY_FLAGS_START + 0x28) // Unused Flag
#define FLAG_UNUSED_0x949                           (DAILY_FLAGS_START + 0x29) // Unused Flag
#define FLAG_UNUSED_0x94A                           (DAILY_FLAGS_START + 0x2A) // Unused Flag
#define FLAG_UNUSED_0x94B                           (DAILY_FLAGS_START + 0x2B) // Unused Flag
#define FLAG_UNUSED_0x94C                           (DAILY_FLAGS_START + 0x2C) // Unused Flag
#define FLAG_UNUSED_0x94D                           (DAILY_FLAGS_START + 0x2D) // Unused Flag
#define FLAG_UNUSED_0x94E                           (DAILY_FLAGS_START + 0x2E) // Unused Flag
#define FLAG_UNUSED_0x94F                           (DAILY_FLAGS_START + 0x2F) // Unused Flag
#define FLAG_UNUSED_0x950                           (DAILY_FLAGS_START + 0x30) // Unused Flag
#define FLAG_UNUSED_0x951                           (DAILY_FLAGS_START + 0x31) // Unused Flag
#define FLAG_UNUSED_0x952                           (DAILY_FLAGS_START + 0x32) // Unused Flag
#define FLAG_UNUSED_0x953                           (DAILY_FLAGS_START + 0x33) // Unused Flag
#define FLAG_UNUSED_0x954                           (DAILY_FLAGS_START + 0x34) // Unused Flag
#define FLAG_UNUSED_0x955                           (DAILY_FLAGS_START + 0x35) // Unused Flag
#define FLAG_UNUSED_0x956                           (DAILY_FLAGS_START + 0x36) // Unused Flag
#define FLAG_UNUSED_0x957                           (DAILY_FLAGS_START + 0x37) // Unused Flag
#define FLAG_UNUSED_0x958                           (DAILY_FLAGS_START + 0x38) // Unused Flag
#define FLAG_UNUSED_0x959                           (DAILY_FLAGS_START + 0x39) // Unused Flag
#define FLAG_UNUSED_0x95A                           (DAILY_FLAGS_START + 0x3A) // Unused Flag
#define FLAG_UNUSED_0x95B                           (DAILY_FLAGS_START + 0x3B) // Unused Flag
#define FLAG_UNUSED_0x95C                           (DAILY_FLAGS_START + 0x3C) // Unused Flag
#define FLAG_UNUSED_0x95D                           (DAILY_FLAGS_START + 0x3D) // Unused Flag
#define FLAG_UNUSED_0x95E                           (DAILY_FLAGS_START + 0x3E) // Unused Flag
#define FLAG_UNUSED_0x95F                           (DAILY_FLAGS_START + 0x3F) // Unused Flag
#define DAILY_FLAGS_END                             (FLAG_UNUSED_0x95F + (7 - FLAG_UNUSED_0x95F % 8))
#define NUM_DAILY_FLAGS                             (DAILY_FLAGS_END - DAILY_FLAGS_START + 1)

#define FLAGS_COUNT (DAILY_FLAGS_END + 1)

// Special Flags (Stored in EWRAM (sSpecialFlags), not in the SaveBlock)
#define SPECIAL_FLAGS_START                     0x4000
#define FLAG_HIDE_MAP_NAME_POPUP                (SPECIAL_FLAGS_START + 0x0)
#define FLAG_DONT_TRANSITION_MUSIC              (SPECIAL_FLAGS_START + 0x1)
#define FLAG_ENABLE_MULTI_CORRIDOR_DOOR         (SPECIAL_FLAGS_START + 0x2)
#define FLAG_SPECIAL_FLAG_UNUSED_0x4003         (SPECIAL_FLAGS_START + 0x3) // Unused Flag
#define FLAG_STORING_ITEMS_IN_PYRAMID_BAG       (SPECIAL_FLAGS_START + 0x4)
// FLAG_SPECIAL_FLAG_0x4005 - 0x407F also exist and are unused
#define SPECIAL_FLAGS_END                       (SPECIAL_FLAGS_START + 0x7F)
#define NUM_SPECIAL_FLAGS                       (SPECIAL_FLAGS_END - SPECIAL_FLAGS_START + 1)

// Temp flag aliases
#define FLAG_TEMP_SKIP_GABBY_INTERVIEW          FLAG_TEMP_1
#define FLAG_TEMP_HIDE_MIRAGE_ISLAND_BERRY_TREE FLAG_TEMP_11

#endif // GUARD_CONSTANTS_FLAGS_H
