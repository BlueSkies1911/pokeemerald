// This determines how much higher above the usual position the enemy Pokémon
// is during battle. Species that float or fly have nonzero values.
const u8 gEnemyMonElevation[NUM_SPECIES] =
{
    [SPECIES_BUTTERFREE] = 10,
    [SPECIES_BEEDRILL] = 9,
    [SPECIES_PIDGEOT] = 5,
    [SPECIES_FEAROW] = 6,
    [SPECIES_ZUBAT] = 16,
    [SPECIES_GOLBAT] = 10,
    [SPECIES_CROBAT] = 9,
    [SPECIES_VENOMOTH] = 16,
    [SPECIES_GEODUDE] = 16,
    [SPECIES_MAGNEMITE] = 17,
    [SPECIES_MAGNETON] = 9,
    [SPECIES_GASTLY] = 10,
    [SPECIES_HAUNTER] = 11,
    [SPECIES_KOFFING] = 14,
    [SPECIES_WEEZING] = 6,
    [SPECIES_PORYGON2] = 9,
    [SPECIES_AERODACTYL] = 9,
    [SPECIES_ZAPDOS] = 8,
    [SPECIES_MEW] = 11,
};
