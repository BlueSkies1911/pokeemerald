#ifndef GUARD_CONSTANTS_ITEMS_H
#define GUARD_CONSTANTS_ITEMS_H

#define ITEM_NONE 0

// Poké Balls
#define ITEM_POKE_BALL 1
#define ITEM_GREAT_BALL 2
#define ITEM_ULTRA_BALL 3
#define ITEM_MASTER_BALL 4
#define ITEM_PREMIER_BALL 5
#define ITEM_HEAL_BALL 6
#define ITEM_NET_BALL 7
#define ITEM_NEST_BALL 8
#define ITEM_DIVE_BALL 9
#define ITEM_DUSK_BALL 10
#define ITEM_TIMER_BALL 11
#define ITEM_QUICK_BALL 12
#define ITEM_REPEAT_BALL 13
#define ITEM_LUXURY_BALL 14
#define ITEM_LEVEL_BALL 15
#define ITEM_LURE_BALL 16
#define ITEM_MOON_BALL 17
#define ITEM_FRIEND_BALL 18
#define ITEM_LOVE_BALL 19
#define ITEM_FAST_BALL 20
#define ITEM_HEAVY_BALL 21
#define ITEM_DREAM_BALL 22
#define ITEM_SAFARI_BALL 23
#define ITEM_CHERISH_BALL 24

// Note: If moving ball IDs around, updating FIRST_BALL/LAST_BALL is not sufficient
//       Several places expect the ball IDs to be first and contiguous (e.g. MON_DATA_POKEBALL)
//       If adding new balls, it's easiest to insert them after the last ball and increment the below IDs (and removing ITEM_034 for example)
#define FIRST_BALL ITEM_POKE_BALL
#define LAST_BALL  ITEM_CHERISH_BALL

// Medicine
#define ITEM_POTION 25
#define ITEM_SUPER_POTION 26
#define ITEM_HYPER_POTION 27
#define ITEM_MAX_POTION 28
#define ITEM_FULL_RESTORE 29
#define ITEM_REVIVE 30
#define ITEM_MAX_REVIVE 31
#define ITEM_FRESH_WATER 32
#define ITEM_SODA_POP 33
#define ITEM_LEMONADE 34
#define ITEM_MOOMOO_MILK 35
#define ITEM_ENERGY_POWDER 36
#define ITEM_ENERGY_ROOT 37
#define ITEM_HEAL_POWDER 38
#define ITEM_REVIVAL_HERB 39
#define ITEM_ANTIDOTE 40
#define ITEM_PARALYZE_HEAL 41
#define ITEM_BURN_HEAL 42
#define ITEM_ICE_HEAL 43
#define ITEM_AWAKENING 44
#define ITEM_FULL_HEAL 45
#define ITEM_ETHER 46
#define ITEM_MAX_ETHER 47
#define ITEM_ELIXIR 48
#define ITEM_MAX_ELIXIR 49
#define ITEM_BERRY_JUICE 50
#define ITEM_SACRED_ASH 51
#define ITEM_PEWTER_CRUNCHIES 52

// Vitamins
#define ITEM_HP_UP 53
#define ITEM_PROTEIN 54
#define ITEM_IRON 55
#define ITEM_CALCIUM 56
#define ITEM_ZINC 57
#define ITEM_CARBOS 58
#define ITEM_PP_UP 59
#define ITEM_PP_MAX 60

// Ability Modifiers
#define ITEM_ABILITY_CAPSULE 61
#define ITEM_ABILITY_PATCH 62

// Candy
#define ITEM_RARE_CANDY 63

// Medicinal Flutes
#define ITEM_BLUE_FLUTE 64
#define ITEM_YELLOW_FLUTE 65
#define ITEM_RED_FLUTE 66

// Encounter-modifying Flutes
#define ITEM_BLACK_FLUTE 67
#define ITEM_WHITE_FLUTE 68

// Encounter Modifiers
#define ITEM_REPEL 69
#define ITEM_SUPER_REPEL 70
#define ITEM_MAX_REPEL 71

// X Items
#define ITEM_X_ATTACK 72
#define ITEM_X_DEFENSE 73
#define ITEM_X_SP_ATK 74
#define ITEM_X_SP_DEF 75
#define ITEM_X_SPEED 76
#define ITEM_X_ACCURACY 77

#define ITEM_DIRE_HIT 78
#define ITEM_GUARD_SPEC 79

// Escape Items
#define ITEM_ESCAPE_ROPE 80
#define ITEM_POKE_DOLL 81

// Treasures
#define ITEM_NUGGET 82
#define ITEM_BIG_NUGGET 83
#define ITEM_TINY_MUSHROOM 84
#define ITEM_BIG_MUSHROOM 85
#define ITEM_PEARL 86
#define ITEM_BIG_PEARL 87
#define ITEM_STARDUST 88
#define ITEM_STAR_PIECE 89
#define ITEM_SHOAL_SALT 90
#define ITEM_SHOAL_SHELL 91
#define ITEM_RED_SHARD 92
#define ITEM_BLUE_SHARD 93
#define ITEM_YELLOW_SHARD 94
#define ITEM_GREEN_SHARD 95
#define ITEM_HEART_SCALE 96
#define ITEM_HONEY 97

// Fossils
#define ITEM_HELIX_FOSSIL 98
#define ITEM_DOME_FOSSIL 99
#define ITEM_OLD_AMBER 100

// Apricorns
#define ITEM_RED_APRICORN 101
#define ITEM_BLUE_APRICORN 102
#define ITEM_YELLOW_APRICORN 103
#define ITEM_GREEN_APRICORN 104
#define ITEM_PINK_APRICORN 105
#define ITEM_WHITE_APRICORN 106
#define ITEM_BLACK_APRICORN 107

// Mail
#define ITEM_ORANGE_MAIL 108
#define ITEM_HARBOR_MAIL 109
#define ITEM_GLITTER_MAIL 110
#define ITEM_MECH_MAIL 111
#define ITEM_WOOD_MAIL 112
#define ITEM_WAVE_MAIL 113
#define ITEM_BEAD_MAIL 114
#define ITEM_SHADOW_MAIL 115
#define ITEM_TROPIC_MAIL 116
#define ITEM_DREAM_MAIL 117
#define ITEM_FAB_MAIL 118
#define ITEM_RETRO_MAIL 119

#define FIRST_MAIL_INDEX ITEM_ORANGE_MAIL

// Evolution Items
#define ITEM_FIRE_STONE 120
#define ITEM_WATER_STONE 121
#define ITEM_THUNDER_STONE 122
#define ITEM_LEAF_STONE 123
#define ITEM_SUN_STONE 124
#define ITEM_MOON_STONE 125
#define ITEM_DRAGON_SCALE 126
#define ITEM_UPGRADE 127
#define ITEM_OVAL_STONE 128

#define ITEM_EVERSTONE 129

// Gems
#define ITEM_NORMAL_GEM 130
#define ITEM_FIRE_GEM 131
#define ITEM_WATER_GEM 132
#define ITEM_ELECTRIC_GEM 133
#define ITEM_GRASS_GEM 134
#define ITEM_ICE_GEM 135
#define ITEM_FIGHTING_GEM 136
#define ITEM_POISON_GEM 137
#define ITEM_GROUND_GEM 138
#define ITEM_FLYING_GEM 139
#define ITEM_PSYCHIC_GEM 140
#define ITEM_BUG_GEM 141
#define ITEM_ROCK_GEM 142
#define ITEM_GHOST_GEM 143
#define ITEM_DRAGON_GEM 144
#define ITEM_DARK_GEM 145
#define ITEM_STEEL_GEM 146
#define ITEM_FAIRY_GEM 147

// Species-specific Held Items
#define ITEM_LIGHT_BALL 148
#define ITEM_LEEK 149
#define ITEM_THICK_CLUB 150
#define ITEM_LUCKY_PUNCH 151
#define ITEM_METAL_POWDER 152
#define ITEM_QUICK_POWDER 153

// Incenses
#define ITEM_ODD_INCENSE 154
#define ITEM_FULL_INCENSE 155
#define ITEM_LUCK_INCENSE 156

// Contest Scarves
#define ITEM_RED_SCARF 157
#define ITEM_BLUE_SCARF 158
#define ITEM_PINK_SCARF 159
#define ITEM_GREEN_SCARF 160
#define ITEM_YELLOW_SCARF 161

// EV Gain Modifiers
#define ITEM_MACHO_BRACE 162
#define ITEM_POWER_WEIGHT 163
#define ITEM_POWER_BRACER 164
#define ITEM_POWER_BELT 165
#define ITEM_POWER_LENS 166
#define ITEM_POWER_BAND 167
#define ITEM_POWER_ANKLET 168

// Type-boosting Held Items
#define ITEM_SILK_SCARF 169
#define ITEM_CHARCOAL 170
#define ITEM_MYSTIC_WATER 171
#define ITEM_MAGNET 172
#define ITEM_MIRACLE_SEED 173
#define ITEM_NEVER_MELT_ICE 174
#define ITEM_BLACK_BELT 175
#define ITEM_POISON_BARB 176
#define ITEM_SOFT_SAND 177
#define ITEM_SHARP_BEAK 178
#define ITEM_TWISTED_SPOON 179
#define ITEM_SILVER_POWDER 180
#define ITEM_HARD_STONE 181
#define ITEM_SPELL_TAG 182
#define ITEM_DRAGON_FANG 183
#define ITEM_BLACK_GLASSES 184
#define ITEM_METAL_COAT 185

// Choice Items
#define ITEM_CHOICE_BAND 186
#define ITEM_CHOICE_SPECS 187
#define ITEM_CHOICE_SCARF 188

// Status Orbs
#define ITEM_FLAME_ORB 189
#define ITEM_TOXIC_ORB 190

// Weather Rocks
#define ITEM_DAMP_ROCK 191
#define ITEM_HEAT_ROCK 192
#define ITEM_SMOOTH_ROCK 193
#define ITEM_ICY_ROCK 194

// Type-activated Stat Modifiers
#define ITEM_ABSORB_BULB 195
#define ITEM_CELL_BATTERY 196
#define ITEM_LUMINOUS_MOSS 197
#define ITEM_SNOWBALL 198

// Misc. Held Items
#define ITEM_BRIGHT_POWDER 199
#define ITEM_WHITE_HERB 200
#define ITEM_EXP_SHARE 201
#define ITEM_QUICK_CLAW 202
#define ITEM_SOOTHE_BELL 203
#define ITEM_MENTAL_HERB 204
#define ITEM_KINGS_ROCK 205
#define ITEM_AMULET_COIN 206
#define ITEM_CLEANSE_TAG 207
#define ITEM_SMOKE_BALL 208
#define ITEM_FOCUS_BAND 209
#define ITEM_LUCKY_EGG 210
#define ITEM_SCOPE_LENS 211
#define ITEM_LEFTOVERS 212
#define ITEM_SHELL_BELL 213
#define ITEM_WIDE_LENS 214
#define ITEM_MUSCLE_BAND 215
#define ITEM_WISE_GLASSES 216
#define ITEM_EXPERT_BELT 217
#define ITEM_LIGHT_CLAY 218
#define ITEM_LIFE_ORB 219
#define ITEM_POWER_HERB 220
#define ITEM_FOCUS_SASH 221
#define ITEM_ZOOM_LENS 222
#define ITEM_METRONOME 223
#define ITEM_IRON_BALL 224
#define ITEM_LAGGING_TAIL 225
#define ITEM_DESTINY_KNOT 226
#define ITEM_BLACK_SLUDGE 227
#define ITEM_GRIP_CLAW 228
#define ITEM_STICKY_BARB 229
#define ITEM_SHED_SHELL 230
#define ITEM_BIG_ROOT 231
#define ITEM_EVIOLITE 232
#define ITEM_FLOAT_STONE 233
#define ITEM_ROCKY_HELMET 234
#define ITEM_AIR_BALLOON 235
#define ITEM_RED_CARD 236
#define ITEM_RING_TARGET 237
#define ITEM_BINDING_BAND 238
#define ITEM_EJECT_BUTTON 239
#define ITEM_WEAKNESS_POLICY 240
#define ITEM_ASSAULT_VEST 241
#define ITEM_SAFETY_GOGGLES 242
#define ITEM_ADRENALINE_ORB 243
#define ITEM_PROTECTIVE_PADS 244

// Berries
#define ITEM_CHERI_BERRY 245
#define ITEM_CHESTO_BERRY 246
#define ITEM_PECHA_BERRY 247
#define ITEM_RAWST_BERRY 248
#define ITEM_ASPEAR_BERRY 249
#define ITEM_LEPPA_BERRY 250
#define ITEM_ORAN_BERRY 251
#define ITEM_PERSIM_BERRY 252
#define ITEM_LUM_BERRY 253
#define ITEM_SITRUS_BERRY 254
#define ITEM_FIGY_BERRY 255
#define ITEM_WIKI_BERRY 256
#define ITEM_MAGO_BERRY 257
#define ITEM_AGUAV_BERRY 258
#define ITEM_IAPAPA_BERRY 259
#define ITEM_RAZZ_BERRY 260
#define ITEM_BLUK_BERRY 261
#define ITEM_NANAB_BERRY 262
#define ITEM_WEPEAR_BERRY 263
#define ITEM_PINAP_BERRY 264
#define ITEM_POMEG_BERRY 265
#define ITEM_KELPSY_BERRY 266
#define ITEM_QUALOT_BERRY 267
#define ITEM_HONDEW_BERRY 268
#define ITEM_GREPA_BERRY 269
#define ITEM_TAMATO_BERRY 270
#define ITEM_CORNN_BERRY 271
#define ITEM_MAGOST_BERRY 272
#define ITEM_RABUTA_BERRY 273
#define ITEM_NOMEL_BERRY 274
#define ITEM_SPELON_BERRY 275
#define ITEM_PAMTRE_BERRY 276
#define ITEM_WATMEL_BERRY 277
#define ITEM_DURIN_BERRY 278
#define ITEM_BELUE_BERRY 279
#define ITEM_CHILAN_BERRY 280
#define ITEM_OCCA_BERRY 281
#define ITEM_PASSHO_BERRY 282
#define ITEM_WACAN_BERRY 283
#define ITEM_RINDO_BERRY 284
#define ITEM_YACHE_BERRY 285
#define ITEM_CHOPLE_BERRY 286
#define ITEM_KEBIA_BERRY 287
#define ITEM_SHUCA_BERRY 288
#define ITEM_COBA_BERRY 289
#define ITEM_PAYAPA_BERRY 290
#define ITEM_TANGA_BERRY 291
#define ITEM_CHARTI_BERRY 292
#define ITEM_KASIB_BERRY 293
#define ITEM_HABAN_BERRY 294
#define ITEM_COLBUR_BERRY 295
#define ITEM_BABIRI_BERRY 296
#define ITEM_ROSELI_BERRY 297
#define ITEM_LIECHI_BERRY 298
#define ITEM_GANLON_BERRY 299
#define ITEM_SALAC_BERRY 300
#define ITEM_PETAYA_BERRY 301
#define ITEM_APICOT_BERRY 302
#define ITEM_LANSAT_BERRY 303
#define ITEM_STARF_BERRY 304
#define ITEM_ENIGMA_BERRY 305
#define ITEM_MICLE_BERRY 306
#define ITEM_CUSTAP_BERRY 307
#define ITEM_JABOCA_BERRY 308
#define ITEM_ROWAP_BERRY 309
#define ITEM_KEE_BERRY 310
#define ITEM_MARANGA_BERRY 311
#define ITEM_ENIGMA_BERRY_E_READER 312

#define FIRST_BERRY_INDEX ITEM_CHERI_BERRY
#define LAST_BERRY_INDEX  ITEM_ENIGMA_BERRY_E_READER

// TMs/HMs
#define ITEM_TM01 313
#define ITEM_TM02 314
#define ITEM_TM03 315
#define ITEM_TM04 316
#define ITEM_TM05 317
#define ITEM_TM06 318
#define ITEM_TM07 319
#define ITEM_TM08 320
#define ITEM_TM09 321
#define ITEM_TM10 322
#define ITEM_TM11 323
#define ITEM_TM12 324
#define ITEM_TM13 325
#define ITEM_TM14 326
#define ITEM_TM15 327
#define ITEM_TM16 328
#define ITEM_TM17 329
#define ITEM_TM18 330
#define ITEM_TM19 331
#define ITEM_TM20 332
#define ITEM_TM21 333
#define ITEM_TM22 334
#define ITEM_TM23 335
#define ITEM_TM24 336
#define ITEM_TM25 337
#define ITEM_TM26 338
#define ITEM_TM27 339
#define ITEM_TM28 340
#define ITEM_TM29 341
#define ITEM_TM30 342
#define ITEM_TM31 343
#define ITEM_TM32 344
#define ITEM_TM33 345
#define ITEM_TM34 346
#define ITEM_TM35 347
#define ITEM_TM36 348
#define ITEM_TM37 349
#define ITEM_TM38 350
#define ITEM_TM39 351
#define ITEM_TM40 352
#define ITEM_TM41 353
#define ITEM_TM42 354
#define ITEM_TM43 355
#define ITEM_TM44 356
#define ITEM_TM45 357
#define ITEM_TM46 358
#define ITEM_TM47 359
#define ITEM_TM48 360
#define ITEM_TM49 361
#define ITEM_TM50 362
#define ITEM_TM51 363
#define ITEM_TM52 364
#define ITEM_TM53 365
#define ITEM_TM54 366
#define ITEM_TM55 367
#define ITEM_TM56 368
#define ITEM_TM57 369
#define ITEM_TM58 370
#define ITEM_TM59 371
#define ITEM_TM60 372
#define ITEM_TM61 373
#define ITEM_TM62 374
#define ITEM_TM63 375
#define ITEM_TM64 376
#define ITEM_TM65 377
#define ITEM_TM66 378
#define ITEM_TM67 379
#define ITEM_TM68 380
#define ITEM_TM69 381
#define ITEM_TM70 382
#define ITEM_TM71 383
#define ITEM_TM72 384
#define ITEM_TM73 385
#define ITEM_TM74 386
#define ITEM_TM75 387
#define ITEM_TM76 388
#define ITEM_TM77 389
#define ITEM_TM78 390
#define ITEM_TM79 391
#define ITEM_TM80 392
#define ITEM_TM81 393
#define ITEM_TM82 394
#define ITEM_TM83 395
#define ITEM_TM84 396
#define ITEM_TM85 397
#define ITEM_TM86 398
#define ITEM_TM87 399
#define ITEM_TM88 400
#define ITEM_TM89 401
#define ITEM_TM90 402
#define ITEM_TM91 403
#define ITEM_TM92 404
#define ITEM_TM93 405
#define ITEM_TM94 406
#define ITEM_TM95 407
#define ITEM_TM96 408
#define ITEM_TM97 409
#define ITEM_TM98 410
#define ITEM_TM99 411
#define ITEM_TM100 412

#define ITEM_HM01 413
#define ITEM_HM02 414
#define ITEM_HM03 415
#define ITEM_HM04 416
#define ITEM_HM05 417
#define ITEM_HM06 418
#define ITEM_HM07 419
#define ITEM_HM08 420

#define ITEM_TM01_FOCUS_PUNCH ITEM_TM01
#define ITEM_TM02_DRAGON_CLAW ITEM_TM02
#define ITEM_TM03_WATER_PULSE ITEM_TM03
#define ITEM_TM04_CALM_MIND ITEM_TM04
#define ITEM_TM05_ROAR ITEM_TM05
#define ITEM_TM06_TOXIC ITEM_TM06
#define ITEM_TM07_HAIL ITEM_TM07
#define ITEM_TM08_BULK_UP ITEM_TM08
#define ITEM_TM09_BULLET_SEED ITEM_TM09
#define ITEM_TM10_HIDDEN_POWER ITEM_TM10
#define ITEM_TM11_SUNNY_DAY ITEM_TM11
#define ITEM_TM12_TAUNT ITEM_TM12
#define ITEM_TM13_ICE_BEAM ITEM_TM13
#define ITEM_TM14_BLIZZARD ITEM_TM14
#define ITEM_TM15_HYPER_BEAM ITEM_TM15
#define ITEM_TM16_LIGHT_SCREEN ITEM_TM16
#define ITEM_TM17_PROTECT ITEM_TM17
#define ITEM_TM18_RAIN_DANCE ITEM_TM18
#define ITEM_TM19_GIGA_DRAIN ITEM_TM19
#define ITEM_TM20_SAFEGUARD ITEM_TM20
#define ITEM_TM21_FRUSTRATION ITEM_TM21
#define ITEM_TM22_SOLAR_BEAM ITEM_TM22
#define ITEM_TM23_IRON_TAIL ITEM_TM23
#define ITEM_TM24_THUNDERBOLT ITEM_TM24
#define ITEM_TM25_THUNDER ITEM_TM25
#define ITEM_TM26_EARTHQUAKE ITEM_TM26
#define ITEM_TM27_RETURN ITEM_TM27
#define ITEM_TM28_DIG ITEM_TM28
#define ITEM_TM29_PSYCHIC ITEM_TM29
#define ITEM_TM30_SHADOW_BALL ITEM_TM30
#define ITEM_TM31_BRICK_BREAK ITEM_TM31
#define ITEM_TM32_DOUBLE_TEAM ITEM_TM32
#define ITEM_TM33_REFLECT ITEM_TM33
#define ITEM_TM34_SHOCK_WAVE ITEM_TM34
#define ITEM_TM35_FLAMETHROWER ITEM_TM35
#define ITEM_TM36_SLUDGE_BOMB ITEM_TM36
#define ITEM_TM37_SANDSTORM ITEM_TM37
#define ITEM_TM38_FIRE_BLAST ITEM_TM38
#define ITEM_TM39_ROCK_TOMB ITEM_TM39
#define ITEM_TM40_AERIAL_ACE ITEM_TM40
#define ITEM_TM41_TORMENT ITEM_TM41
#define ITEM_TM42_FACADE ITEM_TM42
#define ITEM_TM43_SECRET_POWER ITEM_TM43
#define ITEM_TM44_REST ITEM_TM44
#define ITEM_TM45_ATTRACT ITEM_TM45
#define ITEM_TM46_THIEF ITEM_TM46
#define ITEM_TM47_STEEL_WING ITEM_TM47
#define ITEM_TM48_SKILL_SWAP ITEM_TM48
#define ITEM_TM49_SNATCH ITEM_TM49
#define ITEM_TM50_OVERHEAT ITEM_TM50

#define ITEM_HM01_CUT ITEM_HM01
#define ITEM_HM02_FLY ITEM_HM02
#define ITEM_HM03_SURF ITEM_HM03
#define ITEM_HM04_STRENGTH ITEM_HM04
#define ITEM_HM05_FLASH ITEM_HM05
#define ITEM_HM06_ROCK_SMASH ITEM_HM06
#define ITEM_HM07_WATERFALL ITEM_HM07
#define ITEM_HM08_DIVE ITEM_HM08

// Misc. Key Items
#define ITEM_MACH_BIKE 421
#define ITEM_ACRO_BIKE 422
#define ITEM_OLD_ROD 423
#define ITEM_GOOD_ROD 424
#define ITEM_SUPER_ROD 425
#define ITEM_DOWSING_MACHINE 426
#define ITEM_COIN_CASE 427
#define ITEM_POWDER_JAR 428
#define ITEM_SQUIRT_BOTTLE 429
#define ITEM_POKEBLOCK_CASE 430
#define ITEM_SOOT_SACK 431
#define ITEM_POKE_FLUTE 432

// Story Key Items
#define ITEM_SS_TICKET 433
#define ITEM_OLD_SEA_MAP 434
#define ITEM_METEORITE 435
#define ITEM_CONTEST_PASS 436
#define ITEM_OAKS_PARCEL 437
#define ITEM_SECRET_KEY 438
#define ITEM_BIKE_VOUCHER 439
#define ITEM_GOLD_TEETH 440
#define ITEM_CARD_KEY 441
#define ITEM_LIFT_KEY 442
#define ITEM_SILPH_SCOPE 443
#define ITEM_TRI_PASS 444
#define ITEM_RAINBOW_PASS 445
#define ITEM_TEA 446
#define ITEM_RUBY 447
#define ITEM_SAPPHIRE 448

#define ITEM_COINS10 449
#define ITEM_COINS20 450
#define ITEM_COINS40 451
#define ITEM_COINS100 452

#define ITEMS_COUNT 453
#define ITEM_FIELD_ARROW ITEMS_COUNT

// A special item id associated with "Cancel"/"Exit" etc. in a list of items or decorations
// Its icon is defined at ITEMS_COUNT as the "return to field" arrow
#define ITEM_LIST_END 0xFFFF

// Range of berries given out by various NPCS
#define FIRST_BERRY_MASTER_BERRY      ITEM_POMEG_BERRY
#define LAST_BERRY_MASTER_BERRY       ITEM_NOMEL_BERRY
#define FIRST_BERRY_MASTER_WIFE_BERRY ITEM_CHERI_BERRY
#define LAST_BERRY_MASTER_WIFE_BERRY  ITEM_SITRUS_BERRY
#define FIRST_KIRI_BERRY              ITEM_POMEG_BERRY
#define LAST_KIRI_BERRY               ITEM_NOMEL_BERRY
#define FIRST_ROUTE_114_MAN_BERRY     ITEM_RAZZ_BERRY
#define LAST_ROUTE_114_MAN_BERRY      ITEM_PINAP_BERRY

#define NUM_BERRY_MASTER_BERRIES          (LAST_BERRY_MASTER_BERRY - FIRST_BERRY_MASTER_BERRY + 1)
#define NUM_BERRY_MASTER_BERRIES_SKIPPED  (FIRST_BERRY_MASTER_BERRY - FIRST_BERRY_INDEX)
#define NUM_BERRY_MASTER_WIFE_BERRIES     (LAST_BERRY_MASTER_WIFE_BERRY - FIRST_BERRY_MASTER_WIFE_BERRY + 1)
#define NUM_KIRI_BERRIES                  (LAST_KIRI_BERRY - FIRST_KIRI_BERRY + 1)
#define NUM_KIRI_BERRIES_SKIPPED          (FIRST_KIRI_BERRY - FIRST_BERRY_INDEX)
#define NUM_ROUTE_114_MAN_BERRIES         (LAST_ROUTE_114_MAN_BERRY - FIRST_ROUTE_114_MAN_BERRY + 1)
#define NUM_ROUTE_114_MAN_BERRIES_SKIPPED (FIRST_ROUTE_114_MAN_BERRY - FIRST_BERRY_INDEX)

#define ITEM_TO_BERRY(itemId)(((itemId) - FIRST_BERRY_INDEX) + 1)
#define ITEM_TO_MAIL(itemId)((itemId) - FIRST_MAIL_INDEX)
#define MAIL_NONE 0xFF

#define NUM_TECHNICAL_MACHINES 100
#define NUM_HIDDEN_MACHINES 8

#define MAX_BAG_ITEM_CAPACITY  99
#define MAX_PC_ITEM_CAPACITY   999
#define MAX_BERRY_CAPACITY     999

#define BAG_ITEM_CAPACITY_DIGITS 2
#define BERRY_CAPACITY_DIGITS 3
#define MAX_ITEM_DIGITS BERRY_CAPACITY_DIGITS

// Secondary IDs for rods
#define OLD_ROD   0
#define GOOD_ROD  1
#define SUPER_ROD 2

// Secondary IDs for bikes
#define MACH_BIKE 0
#define ACRO_BIKE 1

// Item type IDs (used to determine the exit callback)
#define ITEM_USE_MAIL        0
#define ITEM_USE_PARTY_MENU  1
#define ITEM_USE_FIELD       2
#define ITEM_USE_PBLOCK_CASE 3
#define ITEM_USE_BAG_MENU    4 // No exit callback, stays in bag menu

// Item battle usage IDs (only checked to see if nonzero)
#define ITEM_B_USE_MEDICINE 1
#define ITEM_B_USE_OTHER    2

// Check if the item is one that can be used on a Pokémon.
#define ITEM_HAS_EFFECT(item) ((item) >= ITEM_POTION && (item) <= LAST_BERRY_INDEX)

#endif  // GUARD_CONSTANTS_ITEMS_H
