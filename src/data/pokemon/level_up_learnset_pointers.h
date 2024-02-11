const struct LevelUpMove *const gLevelUpLearnsets[NUM_SPECIES] =
{
    [SPECIES_NONE] = sBulbasaurLevelUpLearnset,
    [SPECIES_BULBASAUR] = sBulbasaurLevelUpLearnset,
    [SPECIES_IVYSAUR] = sIvysaurLevelUpLearnset,
    [SPECIES_VENUSAUR] = sVenusaurLevelUpLearnset,
    [SPECIES_CHARMANDER] = sCharmanderLevelUpLearnset,
    [SPECIES_CHARMELEON] = sCharmeleonLevelUpLearnset,
    [SPECIES_CHARIZARD] = sCharizardLevelUpLearnset,
    [SPECIES_SQUIRTLE] = sSquirtleLevelUpLearnset,
    [SPECIES_WARTORTLE] = sWartortleLevelUpLearnset,
    [SPECIES_BLASTOISE] = sBlastoiseLevelUpLearnset,
    [SPECIES_CATERPIE] = sCaterpieLevelUpLearnset,
    [SPECIES_METAPOD] = sMetapodLevelUpLearnset,
    [SPECIES_BUTTERFREE] = sButterfreeLevelUpLearnset,
    [SPECIES_WEEDLE] = sWeedleLevelUpLearnset,
    [SPECIES_KAKUNA] = sKakunaLevelUpLearnset,
    [SPECIES_BEEDRILL] = sBeedrillLevelUpLearnset,
    [SPECIES_PIDGEY] = sPidgeyLevelUpLearnset,
    [SPECIES_PIDGEOTTO] = sPidgeottoLevelUpLearnset,
    [SPECIES_PIDGEOT] = sPidgeotLevelUpLearnset,
    [SPECIES_RATTATA] = sRattataLevelUpLearnset,
    [SPECIES_RATICATE] = sRaticateLevelUpLearnset,
    [SPECIES_SPEAROW] = sSpearowLevelUpLearnset,
    [SPECIES_FEAROW] = sFearowLevelUpLearnset,
    [SPECIES_EKANS] = sEkansLevelUpLearnset,
    [SPECIES_ARBOK] = sArbokLevelUpLearnset,
    [SPECIES_PICHU] = sPichuLevelUpLearnset,
    [SPECIES_PIKACHU] = sPikachuLevelUpLearnset,
    [SPECIES_RAICHU] = sRaichuLevelUpLearnset,
    [SPECIES_SANDSHREW] = sSandshrewLevelUpLearnset,
    [SPECIES_SANDSLASH] = sSandslashLevelUpLearnset,
    [SPECIES_NIDORAN_F] = sNidoranFLevelUpLearnset,
    [SPECIES_NIDORINA] = sNidorinaLevelUpLearnset,
    [SPECIES_NIDOQUEEN] = sNidoqueenLevelUpLearnset,
    [SPECIES_NIDORAN_M] = sNidoranMLevelUpLearnset,
    [SPECIES_NIDORINO] = sNidorinoLevelUpLearnset,
    [SPECIES_NIDOKING] = sNidokingLevelUpLearnset,
    [SPECIES_CLEFFA] = sCleffaLevelUpLearnset,
    [SPECIES_CLEFAIRY] = sClefairyLevelUpLearnset,
    [SPECIES_CLEFABLE] = sClefableLevelUpLearnset,
    [SPECIES_VULPIX] = sVulpixLevelUpLearnset,
    [SPECIES_NINETALES] = sNinetalesLevelUpLearnset,
    [SPECIES_IGGLYBUFF] = sIgglybuffLevelUpLearnset,
    [SPECIES_JIGGLYPUFF] = sJigglypuffLevelUpLearnset,
    [SPECIES_WIGGLYTUFF] = sWigglytuffLevelUpLearnset,
    [SPECIES_ZUBAT] = sZubatLevelUpLearnset,
    [SPECIES_GOLBAT] = sGolbatLevelUpLearnset,
    [SPECIES_CROBAT] = sCrobatLevelUpLearnset,
    [SPECIES_ODDISH] = sOddishLevelUpLearnset,
    [SPECIES_GLOOM] = sGloomLevelUpLearnset,
    [SPECIES_VILEPLUME] = sVileplumeLevelUpLearnset,
    [SPECIES_BELLOSSOM] = sBellossomLevelUpLearnset,
    [SPECIES_PARAS] = sParasLevelUpLearnset,
    [SPECIES_PARASECT] = sParasectLevelUpLearnset,
    [SPECIES_VENONAT] = sVenonatLevelUpLearnset,
    [SPECIES_VENOMOTH] = sVenomothLevelUpLearnset,
    [SPECIES_DIGLETT] = sDiglettLevelUpLearnset,
    [SPECIES_DUGTRIO] = sDugtrioLevelUpLearnset,
    [SPECIES_MEOWTH] = sMeowthLevelUpLearnset,
    [SPECIES_PERSIAN] = sPersianLevelUpLearnset,
    [SPECIES_PSYDUCK] = sPsyduckLevelUpLearnset,
    [SPECIES_GOLDUCK] = sGolduckLevelUpLearnset,
    [SPECIES_MANKEY] = sMankeyLevelUpLearnset,
    [SPECIES_PRIMEAPE] = sPrimeapeLevelUpLearnset,
    [SPECIES_GROWLITHE] = sGrowlitheLevelUpLearnset,
    [SPECIES_ARCANINE] = sArcanineLevelUpLearnset,
    [SPECIES_POLIWAG] = sPoliwagLevelUpLearnset,
    [SPECIES_POLIWHIRL] = sPoliwhirlLevelUpLearnset,
    [SPECIES_POLIWRATH] = sPoliwrathLevelUpLearnset,
    [SPECIES_POLITOED] = sPolitoedLevelUpLearnset,
    [SPECIES_ABRA] = sAbraLevelUpLearnset,
    [SPECIES_KADABRA] = sKadabraLevelUpLearnset,
    [SPECIES_ALAKAZAM] = sAlakazamLevelUpLearnset,
    [SPECIES_MACHOP] = sMachopLevelUpLearnset,
    [SPECIES_MACHOKE] = sMachokeLevelUpLearnset,
    [SPECIES_MACHAMP] = sMachampLevelUpLearnset,
    [SPECIES_BELLSPROUT] = sBellsproutLevelUpLearnset,
    [SPECIES_WEEPINBELL] = sWeepinbellLevelUpLearnset,
    [SPECIES_VICTREEBEL] = sVictreebelLevelUpLearnset,
    [SPECIES_TENTACOOL] = sTentacoolLevelUpLearnset,
    [SPECIES_TENTACRUEL] = sTentacruelLevelUpLearnset,
    [SPECIES_GEODUDE] = sGeodudeLevelUpLearnset,
    [SPECIES_GRAVELER] = sGravelerLevelUpLearnset,
    [SPECIES_GOLEM] = sGolemLevelUpLearnset,
    [SPECIES_PONYTA] = sPonytaLevelUpLearnset,
    [SPECIES_RAPIDASH] = sRapidashLevelUpLearnset,
    [SPECIES_SLOWPOKE] = sSlowpokeLevelUpLearnset,
    [SPECIES_SLOWBRO] = sSlowbroLevelUpLearnset,
    [SPECIES_SLOWKING] = sSlowkingLevelUpLearnset,
    [SPECIES_MAGNEMITE] = sMagnemiteLevelUpLearnset,
    [SPECIES_MAGNETON] = sMagnetonLevelUpLearnset,
    [SPECIES_FARFETCHD] = sFarfetchdLevelUpLearnset,
    [SPECIES_DODUO] = sDoduoLevelUpLearnset,
    [SPECIES_DODRIO] = sDodrioLevelUpLearnset,
    [SPECIES_SEEL] = sSeelLevelUpLearnset,
    [SPECIES_DEWGONG] = sDewgongLevelUpLearnset,
    [SPECIES_GRIMER] = sGrimerLevelUpLearnset,
    [SPECIES_MUK] = sMukLevelUpLearnset,
    [SPECIES_SHELLDER] = sShellderLevelUpLearnset,
    [SPECIES_CLOYSTER] = sCloysterLevelUpLearnset,
    [SPECIES_GASTLY] = sGastlyLevelUpLearnset,
    [SPECIES_HAUNTER] = sHaunterLevelUpLearnset,
    [SPECIES_GENGAR] = sGengarLevelUpLearnset,
    [SPECIES_ONIX] = sOnixLevelUpLearnset,
    [SPECIES_STEELIX] = sSteelixLevelUpLearnset,
    [SPECIES_DROWZEE] = sDrowzeeLevelUpLearnset,
    [SPECIES_HYPNO] = sHypnoLevelUpLearnset,
    [SPECIES_KRABBY] = sKrabbyLevelUpLearnset,
    [SPECIES_KINGLER] = sKinglerLevelUpLearnset,
    [SPECIES_VOLTORB] = sVoltorbLevelUpLearnset,
    [SPECIES_ELECTRODE] = sElectrodeLevelUpLearnset,
    [SPECIES_EXEGGCUTE] = sExeggcuteLevelUpLearnset,
    [SPECIES_EXEGGUTOR] = sExeggutorLevelUpLearnset,
    [SPECIES_CUBONE] = sCuboneLevelUpLearnset,
    [SPECIES_MAROWAK] = sMarowakLevelUpLearnset,
    [SPECIES_TYROGUE] = sTyrogueLevelUpLearnset,
    [SPECIES_HITMONLEE] = sHitmonleeLevelUpLearnset,
    [SPECIES_HITMONCHAN] = sHitmonchanLevelUpLearnset,
    [SPECIES_HITMONTOP] = sHitmontopLevelUpLearnset,
    [SPECIES_LICKITUNG] = sLickitungLevelUpLearnset,
    [SPECIES_KOFFING] = sKoffingLevelUpLearnset,
    [SPECIES_WEEZING] = sWeezingLevelUpLearnset,
    [SPECIES_RHYHORN] = sRhyhornLevelUpLearnset,
    [SPECIES_RHYDON] = sRhydonLevelUpLearnset,
    [SPECIES_CHANSEY] = sChanseyLevelUpLearnset,
    [SPECIES_BLISSEY] = sBlisseyLevelUpLearnset,
    [SPECIES_TANGELA] = sTangelaLevelUpLearnset,
    [SPECIES_KANGASKHAN] = sKangaskhanLevelUpLearnset,
    [SPECIES_HORSEA] = sHorseaLevelUpLearnset,
    [SPECIES_SEADRA] = sSeadraLevelUpLearnset,
    [SPECIES_KINGDRA] = sKingdraLevelUpLearnset,
    [SPECIES_GOLDEEN] = sGoldeenLevelUpLearnset,
    [SPECIES_SEAKING] = sSeakingLevelUpLearnset,
    [SPECIES_STARYU] = sStaryuLevelUpLearnset,
    [SPECIES_STARMIE] = sStarmieLevelUpLearnset,
    [SPECIES_MR_MIME] = sMrMimeLevelUpLearnset,
    [SPECIES_SCYTHER] = sScytherLevelUpLearnset,
    [SPECIES_SCIZOR] = sScizorLevelUpLearnset,
    [SPECIES_SMOOCHUM] = sSmoochumLevelUpLearnset,
    [SPECIES_JYNX] = sJynxLevelUpLearnset,
    [SPECIES_ELEKID] = sElekidLevelUpLearnset,
    [SPECIES_ELECTABUZZ] = sElectabuzzLevelUpLearnset,
    [SPECIES_MAGBY] = sMagbyLevelUpLearnset,
    [SPECIES_MAGMAR] = sMagmarLevelUpLearnset,
    [SPECIES_PINSIR] = sPinsirLevelUpLearnset,
    [SPECIES_TAUROS] = sTaurosLevelUpLearnset,
    [SPECIES_MAGIKARP] = sMagikarpLevelUpLearnset,
    [SPECIES_GYARADOS] = sGyaradosLevelUpLearnset,
    [SPECIES_LAPRAS] = sLaprasLevelUpLearnset,
    [SPECIES_DITTO] = sDittoLevelUpLearnset,
    [SPECIES_EEVEE] = sEeveeLevelUpLearnset,
    [SPECIES_VAPOREON] = sVaporeonLevelUpLearnset,
    [SPECIES_JOLTEON] = sJolteonLevelUpLearnset,
    [SPECIES_FLAREON] = sFlareonLevelUpLearnset,
    [SPECIES_ESPEON] = sEspeonLevelUpLearnset,
    [SPECIES_UMBREON] = sUmbreonLevelUpLearnset,
    [SPECIES_PORYGON] = sPorygonLevelUpLearnset,
    [SPECIES_PORYGON2] = sPorygon2LevelUpLearnset,
    [SPECIES_OMANYTE] = sOmanyteLevelUpLearnset,
    [SPECIES_OMASTAR] = sOmastarLevelUpLearnset,
    [SPECIES_KABUTO] = sKabutoLevelUpLearnset,
    [SPECIES_KABUTOPS] = sKabutopsLevelUpLearnset,
    [SPECIES_AERODACTYL] = sAerodactylLevelUpLearnset,
    [SPECIES_SNORLAX] = sSnorlaxLevelUpLearnset,
    [SPECIES_ARTICUNO] = sArticunoLevelUpLearnset,
    [SPECIES_ZAPDOS] = sZapdosLevelUpLearnset,
    [SPECIES_MOLTRES] = sMoltresLevelUpLearnset,
    [SPECIES_DRATINI] = sDratiniLevelUpLearnset,
    [SPECIES_DRAGONAIR] = sDragonairLevelUpLearnset,
    [SPECIES_DRAGONITE] = sDragoniteLevelUpLearnset,
    [SPECIES_MEWTWO] = sMewtwoLevelUpLearnset,
    [SPECIES_MEW] = sMewLevelUpLearnset,
};
