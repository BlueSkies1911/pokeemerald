// All Pokémon pics are 64x64, but this data table defines where in this 64x64 frame
// the sprite's non-transparent pixels actually are.
// .size is the dimensions of this drawn pixel area.
// .y_offset is the number of pixels between the drawn pixel area and the bottom edge.
const struct MonCoords gMonBackPicCoords[] =
{
    [SPECIES_NONE]                         = { .size = MON_COORDS_SIZE(40, 40), .y_offset = 12 },
    [SPECIES_BULBASAUR]                    = { .size = MON_COORDS_SIZE(56, 40), .y_offset = 13 },
    [SPECIES_IVYSAUR]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  9 },
    [SPECIES_VENUSAUR]                     = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 10 },
    [SPECIES_CHARMANDER]                   = { .size = MON_COORDS_SIZE(48, 48), .y_offset =  9 },
    [SPECIES_CHARMELEON]                   = { .size = MON_COORDS_SIZE(56, 48), .y_offset =  8 },
    [SPECIES_CHARIZARD]                    = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  1 },
    [SPECIES_SQUIRTLE]                     = { .size = MON_COORDS_SIZE(48, 48), .y_offset =  9 },
    [SPECIES_WARTORTLE]                    = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  7 },
    [SPECIES_BLASTOISE]                    = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  7 },
    [SPECIES_CATERPIE]                     = { .size = MON_COORDS_SIZE(48, 40), .y_offset = 12 },
    [SPECIES_METAPOD]                      = { .size = MON_COORDS_SIZE(40, 48), .y_offset =  8 },
    [SPECIES_BUTTERFREE]                   = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_WEEDLE]                       = { .size = MON_COORDS_SIZE(56, 56), .y_offset =  7 },
    [SPECIES_KAKUNA]                       = { .size = MON_COORDS_SIZE(32, 40), .y_offset = 12 },
    [SPECIES_BEEDRILL]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_PIDGEY]                       = { .size = MON_COORDS_SIZE(56, 48), .y_offset = 11 },
    [SPECIES_PIDGEOTTO]                    = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_PIDGEOT]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  7 },
    [SPECIES_RATTATA]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  7 },
    [SPECIES_RATICATE]                     = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 10 },
    [SPECIES_SPEAROW]                      = { .size = MON_COORDS_SIZE(56, 56), .y_offset =  6 },
    [SPECIES_FEAROW]                       = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  4 },
    [SPECIES_EKANS]                        = { .size = MON_COORDS_SIZE(56, 48), .y_offset = 10 },
    [SPECIES_ARBOK]                        = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  1 },
    [SPECIES_PICHU]                        = { .size = MON_COORDS_SIZE(48, 56), .y_offset =  8 },
    [SPECIES_PIKACHU]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  4 },
    [SPECIES_RAICHU]                       = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_SANDSHREW]                    = { .size = MON_COORDS_SIZE(48, 40), .y_offset = 13 },
    [SPECIES_SANDSLASH]                    = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 11 },
    [SPECIES_NIDORAN_F]                    = { .size = MON_COORDS_SIZE(48, 40), .y_offset = 13 },
    [SPECIES_NIDORINA]                     = { .size = MON_COORDS_SIZE(56, 56), .y_offset =  5 },
    [SPECIES_NIDOQUEEN]                    = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_NIDORAN_M]                    = { .size = MON_COORDS_SIZE(48, 48), .y_offset =  9 },
    [SPECIES_NIDORINO]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  8 },
    [SPECIES_NIDOKING]                     = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  2 },
    [SPECIES_CLEFFA]                       = { .size = MON_COORDS_SIZE(48, 40), .y_offset = 13 },
    [SPECIES_CLEFAIRY]                     = { .size = MON_COORDS_SIZE(56, 40), .y_offset = 14 },
    [SPECIES_CLEFABLE]                     = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 10 },
    [SPECIES_VULPIX]                       = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  9 },
    [SPECIES_NINETALES]                    = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_IGGLYBUFF]                    = { .size = MON_COORDS_SIZE(40, 40), .y_offset = 13 },
    [SPECIES_JIGGLYPUFF]                   = { .size = MON_COORDS_SIZE(56, 48), .y_offset = 12 },
    [SPECIES_WIGGLYTUFF]                   = { .size = MON_COORDS_SIZE(56, 64), .y_offset =  0 },
    [SPECIES_ZUBAT]                        = { .size = MON_COORDS_SIZE(56, 56), .y_offset =  7 },
    [SPECIES_GOLBAT]                       = { .size = MON_COORDS_SIZE(56, 40), .y_offset = 13 },
    [SPECIES_CROBAT]                       = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  1 },
    [SPECIES_ODDISH]                       = { .size = MON_COORDS_SIZE(48, 48), .y_offset = 10 },
    [SPECIES_GLOOM]                        = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 11 },
    [SPECIES_VILEPLUME]                    = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_BELLOSSOM]                    = { .size = MON_COORDS_SIZE(48, 48), .y_offset = 11 },
    [SPECIES_PARAS]                        = { .size = MON_COORDS_SIZE(64, 32), .y_offset = 18 },
    [SPECIES_PARASECT]                     = { .size = MON_COORDS_SIZE(64, 40), .y_offset = 13 },
    [SPECIES_VENONAT]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_VENOMOTH]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  4 },
    [SPECIES_DIGLETT]                      = { .size = MON_COORDS_SIZE(40, 40), .y_offset = 14 },
    [SPECIES_DUGTRIO]                      = { .size = MON_COORDS_SIZE(48, 32), .y_offset = 17 },
    [SPECIES_MEOWTH]                       = { .size = MON_COORDS_SIZE(56, 56), .y_offset =  6 },
    [SPECIES_PERSIAN]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  7 },
    [SPECIES_PSYDUCK]                      = { .size = MON_COORDS_SIZE(48, 48), .y_offset =  9 },
    [SPECIES_GOLDUCK]                      = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  3 },
    [SPECIES_MANKEY]                       = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  8 },
    [SPECIES_PRIMEAPE]                     = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 10 },
    [SPECIES_GROWLITHE]                    = { .size = MON_COORDS_SIZE(48, 56), .y_offset =  8 },
    [SPECIES_ARCANINE]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  4 },
    [SPECIES_POLIWAG]                      = { .size = MON_COORDS_SIZE(48, 32), .y_offset = 18 },
    [SPECIES_POLIWHIRL]                    = { .size = MON_COORDS_SIZE(64, 40), .y_offset = 13 },
    [SPECIES_POLIWRATH]                    = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  7 },
    [SPECIES_POLITOED]                     = { .size = MON_COORDS_SIZE(56, 56), .y_offset =  5 },
    [SPECIES_ABRA]                         = { .size = MON_COORDS_SIZE(56, 48), .y_offset = 12 },
    [SPECIES_KADABRA]                      = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  8 },
    [SPECIES_ALAKAZAM]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_MACHOP]                       = { .size = MON_COORDS_SIZE(48, 56), .y_offset =  6 },
    [SPECIES_MACHOKE]                      = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  8 },
    [SPECIES_MACHAMP]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  7 },
    [SPECIES_BELLSPROUT]                   = { .size = MON_COORDS_SIZE(40, 48), .y_offset = 11 },
    [SPECIES_WEEPINBELL]                   = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 11 },
    [SPECIES_VICTREEBEL]                   = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_TENTACOOL]                    = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  9 },
    [SPECIES_TENTACRUEL]                   = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 11 },
    [SPECIES_GEODUDE]                      = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 11 },
    [SPECIES_GRAVELER]                     = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 10 },
    [SPECIES_GOLEM]                        = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 11 },
    [SPECIES_PONYTA]                       = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  4 },
    [SPECIES_RAPIDASH]                     = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  0 },
    [SPECIES_SLOWPOKE]                     = { .size = MON_COORDS_SIZE(64, 40), .y_offset = 13 },
    [SPECIES_SLOWBRO]                      = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  9 },
    [SPECIES_SLOWKING]                     = { .size = MON_COORDS_SIZE(56, 64), .y_offset =  3 },
    [SPECIES_MAGNEMITE]                    = { .size = MON_COORDS_SIZE(48, 40), .y_offset = 15 },
    [SPECIES_MAGNETON]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_FARFETCHD]                    = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  9 },
    [SPECIES_DODUO]                        = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_DODRIO]                       = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  3 },
    [SPECIES_SEEL]                         = { .size = MON_COORDS_SIZE(64, 40), .y_offset = 13 },
    [SPECIES_DEWGONG]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_GRIMER]                       = { .size = MON_COORDS_SIZE(64, 40), .y_offset = 13 },
    [SPECIES_MUK]                          = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  9 },
    [SPECIES_SHELLDER]                     = { .size = MON_COORDS_SIZE(48, 24), .y_offset = 21 },
    [SPECIES_CLOYSTER]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  7 },
    [SPECIES_GASTLY]                       = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_HAUNTER]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  4 },
    [SPECIES_GENGAR]                       = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  8 },
    [SPECIES_ONIX]                         = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  0 },
    [SPECIES_STEELIX]                      = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  2 },
    [SPECIES_DROWZEE]                      = { .size = MON_COORDS_SIZE(56, 48), .y_offset =  9 },
    [SPECIES_HYPNO]                        = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_KRABBY]                       = { .size = MON_COORDS_SIZE(56, 40), .y_offset = 15 },
    [SPECIES_KINGLER]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_VOLTORB]                      = { .size = MON_COORDS_SIZE(48, 40), .y_offset = 14 },
    [SPECIES_ELECTRODE]                    = { .size = MON_COORDS_SIZE(64, 40), .y_offset = 13 },
    [SPECIES_EXEGGCUTE]                    = { .size = MON_COORDS_SIZE(64, 32), .y_offset = 18 },
    [SPECIES_EXEGGUTOR]                    = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  8 },
    [SPECIES_CUBONE]                       = { .size = MON_COORDS_SIZE(56, 48), .y_offset = 10 },
    [SPECIES_MAROWAK]                      = { .size = MON_COORDS_SIZE(48, 56), .y_offset =  8 },
    [SPECIES_TYROGUE]                      = { .size = MON_COORDS_SIZE(48, 48), .y_offset = 10 },
    [SPECIES_HITMONLEE]                    = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  4 },
    [SPECIES_HITMONCHAN]                   = { .size = MON_COORDS_SIZE(56, 56), .y_offset =  6 },
    [SPECIES_HITMONTOP]                    = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_LICKITUNG]                    = { .size = MON_COORDS_SIZE(64, 40), .y_offset = 13 },
    [SPECIES_KOFFING]                      = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  3 },
    [SPECIES_WEEZING]                      = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  9 },
    [SPECIES_RHYHORN]                      = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 11 },
    [SPECIES_RHYDON]                       = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_CHANSEY]                      = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 11 },
    [SPECIES_BLISSEY]                      = { .size = MON_COORDS_SIZE(64, 32), .y_offset = 16 },
    [SPECIES_TANGELA]                      = { .size = MON_COORDS_SIZE(64, 40), .y_offset = 12 },
    [SPECIES_KANGASKHAN]                   = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_HORSEA]                       = { .size = MON_COORDS_SIZE(48, 40), .y_offset = 14 },
    [SPECIES_SEADRA]                       = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_KINGDRA]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  7 },
    [SPECIES_GOLDEEN]                      = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  9 },
    [SPECIES_SEAKING]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_STARYU]                       = { .size = MON_COORDS_SIZE(56, 56), .y_offset =  6 },
    [SPECIES_STARMIE]                      = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  4 },
    [SPECIES_MR_MIME]                      = { .size = MON_COORDS_SIZE(64, 48), .y_offset =  8 },
    [SPECIES_SCYTHER]                      = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  3 },
    [SPECIES_SCIZOR]                       = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  4 },
    [SPECIES_SMOOCHUM]                     = { .size = MON_COORDS_SIZE(40, 48), .y_offset =  9 },
    [SPECIES_JYNX]                         = { .size = MON_COORDS_SIZE(56, 64), .y_offset =  3 },
    [SPECIES_ELEKID]                       = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 10 },
    [SPECIES_ELECTABUZZ]                   = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  4 },
    [SPECIES_MAGBY]                        = { .size = MON_COORDS_SIZE(40, 48), .y_offset = 10 },
    [SPECIES_MAGMAR]                       = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  3 },
    [SPECIES_PINSIR]                       = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_TAUROS]                       = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 13 },
    [SPECIES_MAGIKARP]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_GYARADOS]                     = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  5 },
    [SPECIES_LAPRAS]                       = { .size = MON_COORDS_SIZE(56, 64), .y_offset =  3 },
    [SPECIES_DITTO]                        = { .size = MON_COORDS_SIZE(48, 32), .y_offset = 17 },
    [SPECIES_EEVEE]                        = { .size = MON_COORDS_SIZE(56, 48), .y_offset = 10 },
    [SPECIES_VAPOREON]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_JOLTEON]                      = { .size = MON_COORDS_SIZE(56, 56), .y_offset =  7 },
    [SPECIES_FLAREON]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  9 },
    [SPECIES_ESPEON]                       = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  8 },
    [SPECIES_UMBREON]                      = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  2 },
    [SPECIES_PORYGON]                      = { .size = MON_COORDS_SIZE(56, 40), .y_offset = 13 },
    [SPECIES_PORYGON2]                     = { .size = MON_COORDS_SIZE(56, 48), .y_offset = 11 },
    [SPECIES_OMANYTE]                      = { .size = MON_COORDS_SIZE(48, 40), .y_offset = 12 },
    [SPECIES_OMASTAR]                      = { .size = MON_COORDS_SIZE(56, 56), .y_offset =  7 },
    [SPECIES_KABUTO]                       = { .size = MON_COORDS_SIZE(48, 40), .y_offset = 13 },
    [SPECIES_KABUTOPS]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  6 },
    [SPECIES_AERODACTYL]                   = { .size = MON_COORDS_SIZE(64, 48), .y_offset = 10 },
    [SPECIES_SNORLAX]                      = { .size = MON_COORDS_SIZE(64, 40), .y_offset = 13 },
    [SPECIES_ARTICUNO]                     = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_ZAPDOS]                       = { .size = MON_COORDS_SIZE(64, 40), .y_offset = 12 },
    [SPECIES_MOLTRES]                      = { .size = MON_COORDS_SIZE(64, 56), .y_offset =  5 },
    [SPECIES_DRATINI]                      = { .size = MON_COORDS_SIZE(56, 48), .y_offset =  8 },
    [SPECIES_DRAGONAIR]                    = { .size = MON_COORDS_SIZE(40, 56), .y_offset =  4 },
    [SPECIES_DRAGONITE]                    = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  1 },
    [SPECIES_MEWTWO]                       = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  1 },
    [SPECIES_MEW]                          = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  0 },
    [SPECIES_EGG]                          = { .size = MON_COORDS_SIZE(24, 24), .y_offset = 20 },
};

