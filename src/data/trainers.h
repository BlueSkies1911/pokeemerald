const struct Trainer gTrainers[] = {
    [TRAINER_NONE] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = 0,
        .party = NULL,
    },

    [TRAINER_AROMA_LADY_GEORGIA] =
    {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("Georgia"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_AromaLadyGeorgia),
    },

    [TRAINER_AROMA_LADY_MIAH] =
    {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("Miah"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_AromaLadyMiah),
    },

    [TRAINER_AROMA_LADY_NIKKI] =
    {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("Nikki"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_AromaLadyNikki),
    },
    
    [TRAINER_AROMA_LADY_ROSE] =
    {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("Rose"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_AromaLadyRose),
    },

    [TRAINER_AROMA_LADY_VIOLET] =
    {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("Violet"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_AromaLadyViolet),
    },
    
    [TRAINER_BEAUTY_BRIDGET] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Bridget"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautyBridget),
    },
    
    [TRAINER_BEAUTY_GRACE] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Grace"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautyGrace),
    },

    [TRAINER_BEAUTY_GRACE_2] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Grace"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautyGrace2),
    },

    [TRAINER_BEAUTY_GRACE_3] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Grace"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautyGrace3),
    },

    [TRAINER_BEAUTY_GRACE_4] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Grace"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautyGrace4),
    },

    [TRAINER_BEAUTY_GRACE_5] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Grace"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautyGrace5),
    },
    
    [TRAINER_BEAUTY_LOLA] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Lola"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautyLola),
    },
    
    [TRAINER_BEAUTY_LORI] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Lori"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautyLori),
    },

    [TRAINER_BEAUTY_OLIVIA] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Olivia"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautyOlivia),
    },

    [TRAINER_BEAUTY_SHEILA] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Sheila"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautySheila),
    },

    [TRAINER_BEAUTY_SHEILA_2] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Sheila"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautySheila2),
    },

    [TRAINER_BEAUTY_SHEILA_3] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Sheila"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautySheila3),
    },

    [TRAINER_BEAUTY_SHEILA_4] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Sheila"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautySheila4),
    },

    [TRAINER_BEAUTY_SHEILA_5] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Sheila"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautySheila5),
    },

    [TRAINER_BEAUTY_TAMIA] =
    {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Tamia"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BeautyTamia),
    },

    [TRAINER_BIKER_ALEX] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Alex"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerAlex),
    },
    
    [TRAINER_BIKER_BILLY] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Billy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerBilly),
    },
    
    [TRAINER_BIKER_ERNEST] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Ernest"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerErnest),
    },

    [TRAINER_BIKER_GERALD] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Gerald"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerGerald),
    },

    [TRAINER_BIKER_GOON] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Goon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerGoon),
    },

    [TRAINER_BIKER_GOON_2] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Goon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerGoon2),
    },

    [TRAINER_BIKER_GOON_3] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Goon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerGoon3),
    },

    [TRAINER_BIKER_HIDEO] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Hideo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerHideo),
    },

    [TRAINER_BIKER_ISAAC] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Isaac"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerIsaac),
    },
    
    [TRAINER_BIKER_JARED] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jared"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJared),
    },

    [TRAINER_BIKER_JAREN] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jaren"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJaren),
    },

    [TRAINER_BIKER_JAREN_2] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jaren"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJaren2),
    },

    [TRAINER_BIKER_JAREN_3] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jaren"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJaren3),
    },

    [TRAINER_BIKER_JAREN_4] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jaren"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJaren4),
    },

    [TRAINER_BIKER_JAREN_5] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jaren"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJaren5),
    },

    [TRAINER_BIKER_JAXON] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jaxon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJaxon),
    },

    [TRAINER_BIKER_JAXON_2] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jaxon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJaxon2),
    },

    [TRAINER_BIKER_JAXON_3] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jaxon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJaxon3),
    },

    [TRAINER_BIKER_JAXON_4] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jaxon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJaxon4),
    },

    [TRAINER_BIKER_JAXON_5] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Jaxon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerJaxon5),
    },
    
    [TRAINER_BIKER_LAO] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Lao"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerLao),
    },
    
    [TRAINER_BIKER_LUKAS] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Lukas"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerLukas),
    },

    [TRAINER_BIKER_LUKAS_2] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Lukas"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerLukas2),
    },

    [TRAINER_BIKER_LUKAS_3] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Lukas"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerLukas3),
    },

    [TRAINER_BIKER_LUKAS_4] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Lukas"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerLukas4),
    },

    [TRAINER_BIKER_LUKAS_5] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Lukas"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerLukas5),
    },
    
    [TRAINER_BIKER_MALIK] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Malik"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerMalik),
    },

    [TRAINER_BIKER_NIKOLAS] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Nikolas"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerNikolas),
    },

    [TRAINER_BIKER_RICARDO] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Ricardo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerRicardo),
    },

    [TRAINER_BIKER_RUBEN] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Ruben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerRuben),
    },

    [TRAINER_BIKER_RUBEN_2] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Ruben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerRuben2),
    },

    [TRAINER_BIKER_RUBEN_3] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Ruben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerRuben3),
    },

    [TRAINER_BIKER_RUBEN_4] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Ruben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerRuben4),
    },

    [TRAINER_BIKER_RUBEN_5] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Ruben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerRuben5),
    },
    
    [TRAINER_BIKER_VIRGIL] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("Virgil"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerVirgil),
    },

    [TRAINER_BIKER_WILLIAM] =
    {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("William"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BikerWilliam),
    },

    [TRAINER_BIRD_KEEPER_BECK] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Beck"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperBeck),
    },

    [TRAINER_BIRD_KEEPER_BENNY] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Benny"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperBenny),
    },

    [TRAINER_BIRD_KEEPER_BENNY_2] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Benny"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperBenny2),
    },

    [TRAINER_BIRD_KEEPER_BENNY_3] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Benny"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperBenny3),
    },

    [TRAINER_BIRD_KEEPER_BENNY_4] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Benny"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperBenny4),
    },

    [TRAINER_BIRD_KEEPER_BENNY_5] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Benny"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperBenny5),
    },
    
    [TRAINER_BIRD_KEEPER_CARTER] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Carter"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperCarter),
    },

    [TRAINER_BIRD_KEEPER_CHAZ] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Chaz"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperChaz),
    },

    [TRAINER_BIRD_KEEPER_CHAZ_2] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Chaz"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperChaz2),
    },

    [TRAINER_BIRD_KEEPER_CHAZ_3] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Chaz"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperChaz3),
    },

    [TRAINER_BIRD_KEEPER_CHAZ_4] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Chaz"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperChaz4),
    },

    [TRAINER_BIRD_KEEPER_CHAZ_5] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Chaz"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperChaz5),
    },

    [TRAINER_BIRD_KEEPER_CHESTER] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Chester"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperChester),
    },

    [TRAINER_BIRD_KEEPER_CHESTER_2] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Chester"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperChester2),
    },

    [TRAINER_BIRD_KEEPER_CHESTER_3] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Chester"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperChester3),
    },

    [TRAINER_BIRD_KEEPER_CHESTER_4] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Chester"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperChester4),
    },

    [TRAINER_BIRD_KEEPER_CHESTER_5] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Chester"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperChester5),
    },
    
    [TRAINER_BIRD_KEEPER_DONALD] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Donald"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperDonald),
    },
    
    [TRAINER_BIRD_KEEPER_EDWIN] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Edwin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperEdwin),
    },

    [TRAINER_BIRD_KEEPER_ELIJAH] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Elijah"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperElijah),
    },

    [TRAINER_BIRD_KEEPER_HAROLD] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Harold"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperHarold),
    },

    [TRAINER_BIRD_KEEPER_JACOB] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Jacob"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperJacob),
    },

    [TRAINER_BIRD_KEEPER_JACOB_2] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Jacob"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperJacob2),
    },

    [TRAINER_BIRD_KEEPER_JACOB_3] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Jacob"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperJacob3),
    },

    [TRAINER_BIRD_KEEPER_JACOB_4] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Jacob"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperJacob4),
    },

    [TRAINER_BIRD_KEEPER_JACOB_5] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Jacob"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperJacob5),
    },

    [TRAINER_BIRD_KEEPER_MARLON] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Marlon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMarlon),
    },

    [TRAINER_BIRD_KEEPER_MARLON_2] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Marlon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMarlon2),
    },

    [TRAINER_BIRD_KEEPER_MARLON_3] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Marlon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMarlon3),
    },

    [TRAINER_BIRD_KEEPER_MARLON_4] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Marlon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMarlon4),
    },

    [TRAINER_BIRD_KEEPER_MARLON_5] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Marlon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMarlon5),
    },

    [TRAINER_BIRD_KEEPER_MILO] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Milo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMilo),
    },

    [TRAINER_BIRD_KEEPER_MILO_2] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Milo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMilo2),
    },

    [TRAINER_BIRD_KEEPER_MILO_3] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Milo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMilo3),
    },

    [TRAINER_BIRD_KEEPER_MILO_4] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Milo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMilo4),
    },

    [TRAINER_BIRD_KEEPER_MILO_5] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Milo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMilo5),
    },

    [TRAINER_BIRD_KEEPER_MITCH] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Mitch"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperMitch),
    },

    [TRAINER_BIRD_KEEPER_PERRY] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Perry"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperPerry),
    },

    [TRAINER_BIRD_KEEPER_RAMIRO] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Ramiro"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperRamiro),
    },

    [TRAINER_BIRD_KEEPER_ROBERT] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Robert"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperRobert),
    },

    [TRAINER_BIRD_KEEPER_ROBERT_2] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Robert"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperRobert2),
    },

    [TRAINER_BIRD_KEEPER_ROBERT_3] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Robert"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperRobert3),
    },

    [TRAINER_BIRD_KEEPER_ROBERT_4] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Robert"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperRobert4),
    },

    [TRAINER_BIRD_KEEPER_ROBERT_5] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Robert"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperRobert5),
    },
    
    [TRAINER_BIRD_KEEPER_ROGER] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Roger"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperRoger),
    },
    
    [TRAINER_BIRD_KEEPER_SEBASTIAN] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Sebastian"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperSebastian),
    },
    
    [TRAINER_BIRD_KEEPER_WILTON] =
    {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Wilton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BirdKeeperWilton),
    },

    [TRAINER_BLACK_BELT_AARON] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Aaron"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltAaron),
    },
    
    [TRAINER_BLACK_BELT_ATSUSHI] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Atsushi"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltAtsushi),
    },
    
    [TRAINER_BLACK_BELT_DAISUKE] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Daisuke"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltDaisuke),
    },

    [TRAINER_BLACK_BELT_HIDEKI] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Hideki"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltHideki),
    },

    [TRAINER_BLACK_BELT_HITOSHI] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Hitoshi"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltHitoshi),
    },

    [TRAINER_BLACK_BELT_HUGH] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Hugh"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltHugh),
    },

    [TRAINER_BLACK_BELT_HUGH_2] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Hugh"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltHugh2),
    },

    [TRAINER_BLACK_BELT_HUGH_3] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Hugh"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltHugh3),
    },

    [TRAINER_BLACK_BELT_HUGH_4] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Hugh"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltHugh4),
    },

    [TRAINER_BLACK_BELT_HUGH_5] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Hugh"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltHugh5),
    },

    [TRAINER_BLACK_BELT_KIYO] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Kiyo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltKiyo),
    },
    
    [TRAINER_BLACK_BELT_KOICHI] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Koichi"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltKoichi),
    },

    [TRAINER_BLACK_BELT_MIKE] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Mike"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltMike),
    },
    
    [TRAINER_BLACK_BELT_SHEA] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Shea"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltShea),
    },

    [TRAINER_BLACK_BELT_SHEA_2] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Shea"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltShea2),
    },

    [TRAINER_BLACK_BELT_SHEA_3] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Shea"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltShea3),
    },

    [TRAINER_BLACK_BELT_SHEA_4] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Shea"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltShea4),
    },

    [TRAINER_BLACK_BELT_SHEA_5] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Shea"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltShea5),
    },

    [TRAINER_BLACK_BELT_TAKASHI] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Takashi"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltTakashi),
    },

    [TRAINER_BLACK_BELT_YUJI] =
    {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Yuji"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BlackBeltYuji),
    },
    
    [TRAINER_BUG_CATCHER_ANTHONY] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Anthony"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherAnthony),
    },
    
    [TRAINER_BUG_CATCHER_BRENT] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Brent"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherBrent),
    },
    
    [TRAINER_BUG_CATCHER_CALE] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Cale"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherCale),
    },

    [TRAINER_BUG_CATCHER_CHARLIE] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Charlie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherCharlie),
    },
    
    [TRAINER_BUG_CATCHER_COLTON] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Colton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherColton),
    },

    [TRAINER_BUG_CATCHER_COLTON_2] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Colton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherColton2),
    },

    [TRAINER_BUG_CATCHER_COLTON_3] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Colton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherColton3),
    },

    [TRAINER_BUG_CATCHER_COLTON_4] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Colton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherColton4),
    },

    [TRAINER_BUG_CATCHER_COLTON_5] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Colton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherColton5),
    },
    
    [TRAINER_BUG_CATCHER_CONNER] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Conner"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherConner),
    },
    
    [TRAINER_BUG_CATCHER_DOUG] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Doug"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherDoug),
    },
    
    [TRAINER_BUG_CATCHER_ELIJAH] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Elijah"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherElijah),
    },

    [TRAINER_BUG_CATCHER_GARRET] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Garret"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherGarret),
    },
    
    [TRAINER_BUG_CATCHER_GREG] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Greg"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherGreg),
    },
    
    [TRAINER_BUG_CATCHER_JAMES] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("James"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherJames),
    },
    
    [TRAINER_BUG_CATCHER_JONAH] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Jonah"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherJonah),
    },
    
    [TRAINER_BUG_CATCHER_KEIGO] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Keigo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherKeigo),
    },
    
    [TRAINER_BUG_CATCHER_KENT] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Kent"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherKent),
    },
    
    [TRAINER_BUG_CATCHER_RICK] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Rick"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherRick),
    },
    
    [TRAINER_BUG_CATCHER_ROBBY] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Robby"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherRobby),
    },
    
    [TRAINER_BUG_CATCHER_SAMMY] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Sammy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherSammy),
    },
    
    [TRAINER_BUG_CATCHER_VANCE] =
    {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Vance"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BugCatcherVance),
    },
    
    [TRAINER_BURGLAR_ARNIE] =
    {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("Arnie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BurglarArnie),
    },

    [TRAINER_BURGLAR_DUSTY] =
    {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("Dusty"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BurglarDusty),
    },
    
    [TRAINER_BURGLAR_LEWIS] =
    {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("Lewis"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BurglarLewis),
    },
    
    [TRAINER_BURGLAR_QUINN] =
    {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("Quinn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BurglarQuinn),
    },

    [TRAINER_BURGLAR_RAMON] =
    {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("Ramon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BurglarRamon),
    },
    
    [TRAINER_BURGLAR_SIMON] =
    {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("Simon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BurglarSimon),
    },
    
    [TRAINER_CAMPER_BRYCE] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Bryce"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperBryce),
    },
    
    [TRAINER_CAMPER_CHRIS] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Chris"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperChris),
    },

    [TRAINER_CAMPER_CHRIS_2] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Chris"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperChris2),
    },

    [TRAINER_CAMPER_CHRIS_3] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Chris"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperChris3),
    },

    [TRAINER_CAMPER_CHRIS_4] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Chris"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperChris4),
    },

    [TRAINER_CAMPER_CHRIS_5] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Chris"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperChris5),
    },
    
    [TRAINER_CAMPER_DREW] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Drew"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperDrew),
    },
    
    [TRAINER_CAMPER_ETHAN] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Ethan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperEthan),
    },
    
    [TRAINER_CAMPER_FLINT] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Flint"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperFlint),
    },
    
    [TRAINER_CAMPER_JEFF] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Jeff"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperJeff),
    },

    [TRAINER_CAMPER_JEFF_2] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Jeff"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperJeff2),
    },

    [TRAINER_CAMPER_JEFF_3] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Jeff"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperJeff3),
    },

    [TRAINER_CAMPER_JEFF_4] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Jeff"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperJeff4),
    },

    [TRAINER_CAMPER_JEFF_5] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Jeff"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperJeff5),
    },
    
    [TRAINER_CAMPER_JUSTIN] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Justin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperJustin),
    },

    [TRAINER_CAMPER_LARRY] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Larry"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperLarry),
    },
    
    [TRAINER_CAMPER_LIAM] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Liam"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperLiam),
    },
    
    [TRAINER_CAMPER_RICKY] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Ricky"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperRicky),
    },

    [TRAINER_CAMPER_RICKY_2] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Ricky"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperRicky2),
    },

    [TRAINER_CAMPER_RICKY_3] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Ricky"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperRicky3),
    },

    [TRAINER_CAMPER_RICKY_4] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Ricky"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperRicky4),
    },

    [TRAINER_CAMPER_RICKY_5] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Ricky"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperRicky5),
    },
    
    [TRAINER_CAMPER_RILEY] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Riley"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperRiley),
    },

    [TRAINER_CAMPER_SHANE] =
    {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Shane"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CamperShane),
    },
    
    [TRAINER_CHANNELER_AMANDA] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Amanda"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerAmanda),
    },
    
    [TRAINER_CHANNELER_ANGELICA] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Angelica"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerAngelica),
    },

    [TRAINER_CHANNELER_CARLY] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Carly"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerCarly),
    },

    [TRAINER_CHANNELER_EMILIA] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Emilia"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerEmilia),
    },
    
    [TRAINER_CHANNELER_HOPE] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Hope"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerHope),
    },

    [TRAINER_CHANNELER_JANAE] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Janae"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerJanae),
    },

    [TRAINER_CHANNELER_JENNIFER] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Jennifer"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerJennifer),
    },

    [TRAINER_CHANNELER_JODY] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Jody"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerJody),
    },

    [TRAINER_CHANNELER_KARINA] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Karina"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerKarina),
    },

    [TRAINER_CHANNELER_LAUREL] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Laurel"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerLaurel),
    },

    [TRAINER_CHANNELER_PATRICIA] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Patricia"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerPatricia),
    },
    
    [TRAINER_CHANNELER_PAULA] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Paula"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerPaula),
    },

    [TRAINER_CHANNELER_RUTH] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Ruth"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerRuth),
    },

    [TRAINER_CHANNELER_STACY] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Stacy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerStacy),
    },

    [TRAINER_CHANNELER_TAMMY] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Tammy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerTammy),
    },

    [TRAINER_CHANNELER_TASHA] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Tasha"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerTasha),
    },

    [TRAINER_CHANNELER_VALERIE] =
    {
        .trainerClass = TRAINER_CLASS_CHANNELER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("Valerie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ChannelerValerie),
    },

    [TRAINER_COOL_COUPLE_LEX_NYA] =
    {
        .trainerClass = TRAINER_CLASS_COOL_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .trainerName = _("Lex & Nya"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CoolCoupleLexNya),
    },
    
    [TRAINER_COOL_COUPLE_RAY_TYRA] =
    {
        .trainerClass = TRAINER_CLASS_COOL_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .trainerName = _("Ray & Tyra"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CoolCoupleRayTyra),
    },

    [TRAINER_COOLTRAINER_ALEXA] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Alexa"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerAlexa),
    },

    [TRAINER_COOLTRAINER_BRAXTON] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Braxton"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerBraxton),
    },
    
    [TRAINER_COOLTRAINER_CAROLINE] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Caroline"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerCaroline),
    },

    [TRAINER_COOLTRAINER_COLBY] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Colby"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerColby),
    },
    
    [TRAINER_COOLTRAINER_GEORGE] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("George"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerGeorge),
    },

    [TRAINER_COOLTRAINER_KEIRA] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Keira"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .party = TRAINER_PARTY(sParty_CooltrainerKeira),
    },

    [TRAINER_COOLTRAINER_LEROY] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Leroy"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerLeroy),
    },

    [TRAINER_COOLTRAINER_LEROY_2] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Leroy"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerLeroy2),
    },

    [TRAINER_COOLTRAINER_LEROY_3] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Leroy"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerLeroy3),
    },

    [TRAINER_COOLTRAINER_LEROY_4] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Leroy"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerLeroy4),
    },

    [TRAINER_COOLTRAINER_LEROY_5] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Leroy"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerLeroy5),
    },

    [TRAINER_COOLTRAINER_MARY] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Mary"),
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerMary),
    },

    [TRAINER_COOLTRAINER_MICHELLE] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Michelle"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerMichelle),
    },

    [TRAINER_COOLTRAINER_MICHELLE_2] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Michelle"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerMichelle2),
    },

    [TRAINER_COOLTRAINER_MICHELLE_3] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Michelle"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerMichelle3),
    },

    [TRAINER_COOLTRAINER_MICHELLE_4] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Michelle"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerMichelle4),
    },

    [TRAINER_COOLTRAINER_MICHELLE_5] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Michelle"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerMichelle5),
    },
    
    [TRAINER_COOLTRAINER_NAOMI] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Naomi"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerNaomi),
    },
    
    [TRAINER_COOLTRAINER_ROLANDO] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Rolando"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerRolando),
    },
    
    [TRAINER_COOLTRAINER_SAMUEL] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Samuel"),
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerSamuel),
    },

    [TRAINER_COOLTRAINER_VINCENT] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Vincent"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerVincent),
    },
    
    [TRAINER_COOLTRAINER_WARREN] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Warren"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerWarren),
    },
    
    [TRAINER_COOLTRAINER_YUJI] =
    {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("Yuji"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_CooltrainerYuji),
    },

    [TRAINER_CRUSH_GIRL_CORA] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Cora"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlCora),
    },

    [TRAINER_CRUSH_GIRL_CYNDY] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Cyndy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlCyndy),
    },

    [TRAINER_CRUSH_GIRL_JOCELYN] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Jocelyn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlJocelyn),
    },

    [TRAINER_CRUSH_GIRL_PAULA] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Paula"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlPaula),
    },

    [TRAINER_CRUSH_GIRL_SHARON] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Sharon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlSharon),
    },

    [TRAINER_CRUSH_GIRL_SHARON_2] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Sharon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlSharon2),
    },

    [TRAINER_CRUSH_GIRL_SHARON_3] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Sharon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlSharon3),
    },

    [TRAINER_CRUSH_GIRL_SHARON_4] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Sharon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlSharon4),
    },

    [TRAINER_CRUSH_GIRL_SHARON_5] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Sharon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlSharon5),
    },
    
    [TRAINER_CRUSH_GIRL_TANYA] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Tanya"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlTanya),
    },

    [TRAINER_CRUSH_GIRL_TANYA_2] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Tanya"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlTanya2),
    },

    [TRAINER_CRUSH_GIRL_TANYA_3] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Tanya"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlTanya3),
    },

    [TRAINER_CRUSH_GIRL_TANYA_4] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Tanya"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlTanya4),
    },

    [TRAINER_CRUSH_GIRL_TANYA_5] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("Tanya"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushGirlTanya5),
    },
    
    [TRAINER_CRUSH_KIN_MIK_KIA] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("Mik & Kia"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushKinMikKia),
    },

    [TRAINER_CRUSH_KIN_MIK_KIA_2] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("Mik & Kia"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushKinMikKia2),
    },

    [TRAINER_CRUSH_KIN_MIK_KIA_3] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("Mik & Kia"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushKinMikKia3),
    },

    [TRAINER_CRUSH_KIN_MIK_KIA_4] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("Mik & Kia"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushKinMikKia4),
    },

    [TRAINER_CRUSH_KIN_MIK_KIA_5] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("Mik & Kia"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushKinMikKia5),
    },
    
    [TRAINER_CRUSH_KIN_RON_MYA] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("Ron & Mya"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushKinRonMya),
    },

    [TRAINER_CRUSH_KIN_RON_MYA_2] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("Ron & Mya"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushKinRonMya2),
    },

    [TRAINER_CRUSH_KIN_RON_MYA_3] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("Ron & Mya"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushKinRonMya3),
    },

    [TRAINER_CRUSH_KIN_RON_MYA_4] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("Ron & Mya"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushKinRonMya4),
    },

    [TRAINER_CRUSH_KIN_RON_MYA_5] =
    {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("Ron & Mya"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CrushKinRonMya5),
    },

    [TRAINER_CUE_BALL_CAMRON] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Camron"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallCamron),
    },

    [TRAINER_CUE_BALL_CAMRON_2] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Camron"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallCamron2),
    },

    [TRAINER_CUE_BALL_CAMRON_3] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Camron"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallCamron3),
    },

    [TRAINER_CUE_BALL_CAMRON_4] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Camron"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallCamron4),
    },

    [TRAINER_CUE_BALL_CAMRON_5] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Camron"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallCamron5),
    },
    
    [TRAINER_CUE_BALL_COREY] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Corey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallCorey),
    },

    [TRAINER_CUE_BALL_COREY_2] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Corey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallCorey2),
    },

    [TRAINER_CUE_BALL_COREY_3] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Corey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallCorey3),
    },

    [TRAINER_CUE_BALL_COREY_4] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Corey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallCorey4),
    },

    [TRAINER_CUE_BALL_COREY_5] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Corey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallCorey5),
    },

    [TRAINER_CUE_BALL_ISAIAH] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Isaiah"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallIsaiah),
    },

    [TRAINER_CUE_BALL_ISAIAH_2] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Isaiah"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallIsaiah2),
    },

    [TRAINER_CUE_BALL_ISAIAH_3] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Isaiah"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallIsaiah3),
    },

    [TRAINER_CUE_BALL_ISAIAH_4] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Isaiah"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallIsaiah4),
    },

    [TRAINER_CUE_BALL_ISAIAH_5] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Isaiah"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallIsaiah5),
    },

    [TRAINER_CUE_BALL_JAMAL] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Jamal"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallJamal),
    },
    
    [TRAINER_CUE_BALL_KOJI] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Koji"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallKoji),
    },

    [TRAINER_CUE_BALL_LUKE] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Luke"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallLuke),
    },

    [TRAINER_CUE_BALL_PAXTON] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Paxton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallPaxton),
    },
    
    [TRAINER_CUE_BALL_RAUL] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Raul"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallRaul),
    },
    
    [TRAINER_CUE_BALL_ZEEK] =
    {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("Zeek"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_CueBallZeek),
    },
    
    [TRAINER_ENGINEER_BAILY] =
    {
        .trainerClass = TRAINER_CLASS_ENGINEER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ENGINEER,
        .trainerName = _("Baily"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_EngineerBaily),
    },

    [TRAINER_ENGINEER_BERNIE] =
    {
        .trainerClass = TRAINER_CLASS_ENGINEER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ENGINEER,
        .trainerName = _("Bernie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_EngineerBernie),
    },

    [TRAINER_ENGINEER_BERNIE_2] =
    {
        .trainerClass = TRAINER_CLASS_ENGINEER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ENGINEER,
        .trainerName = _("Bernie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_EngineerBernie2),
    },

    [TRAINER_ENGINEER_BERNIE_3] =
    {
        .trainerClass = TRAINER_CLASS_ENGINEER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ENGINEER,
        .trainerName = _("Bernie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_EngineerBernie3),
    },

    [TRAINER_ENGINEER_BERNIE_4] =
    {
        .trainerClass = TRAINER_CLASS_ENGINEER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ENGINEER,
        .trainerName = _("Bernie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_EngineerBernie4),
    },

    [TRAINER_ENGINEER_BERNIE_5] =
    {
        .trainerClass = TRAINER_CLASS_ENGINEER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ENGINEER,
        .trainerName = _("Bernie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_EngineerBernie5),
    },
    
    [TRAINER_ENGINEER_BRAXTON] =
    {
        .trainerClass = TRAINER_CLASS_ENGINEER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ENGINEER,
        .trainerName = _("Braxton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_EngineerBraxton),
    },
    
    [TRAINER_FISHERMAN_ANDREW] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Andrew"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanAndrew),
    },
    
    [TRAINER_FISHERMAN_BARNY] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Barny"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanBarny),
    },

    [TRAINER_FISHERMAN_CHIP] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Chip"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanChip),
    },

    [TRAINER_FISHERMAN_CLAUDE] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Claude"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanClaude),
    },
    
    [TRAINER_FISHERMAN_DALE] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Dale"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanDale),
    },

    [TRAINER_FISHERMAN_ELLIOT] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Elliot"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanElliot),
    },

    [TRAINER_FISHERMAN_ELLIOT_2] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Elliot"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanElliot2),
    },

    [TRAINER_FISHERMAN_ELLIOT_3] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Elliot"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanElliot3),
    },

    [TRAINER_FISHERMAN_ELLIOT_4] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Elliot"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanElliot4),
    },

    [TRAINER_FISHERMAN_ELLIOT_5] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Elliot"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .party = TRAINER_PARTY(sParty_FishermanElliot5),
    },

    [TRAINER_FISHERMAN_HANK] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Hank"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanHank),
    },
    
    [TRAINER_FISHERMAN_NED] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Ned"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanNed),
    },

    [TRAINER_FISHERMAN_NOLAN] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Nolan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanNolan),
    },
    
    [TRAINER_FISHERMAN_RONALD] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Ronald"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanRonald),
    },
    
    [TRAINER_FISHERMAN_TOMMY] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Tommy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanTommy),
    },
    
    [TRAINER_FISHERMAN_TYLOR] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Tylor"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanTylor),
    },

    [TRAINER_FISHERMAN_WADE] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Wade"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanWade),
    },

    [TRAINER_FISHERMAN_WADE_2] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Wade"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanWade2),
    },

    [TRAINER_FISHERMAN_WADE_3] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Wade"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanWade3),
    },

    [TRAINER_FISHERMAN_WADE_4] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Wade"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanWade4),
    },

    [TRAINER_FISHERMAN_WADE_5] =
    {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("Wade"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_FishermanWade5),
    },
    
    [TRAINER_GAMBLER_DARIAN] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Darian"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerDarian),
    },

    [TRAINER_GAMBLER_DARIAN_2] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Darian"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerDarian2),
    },

    [TRAINER_GAMBLER_DARIAN_3] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Darian"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerDarian3),
    },

    [TRAINER_GAMBLER_DARIAN_4] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Darian"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerDarian4),
    },

    [TRAINER_GAMBLER_DARIAN_5] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Darian"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerDarian5),
    },
    
    [TRAINER_GAMBLER_DIRK] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Dirk"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerDirk),
    },
    
    [TRAINER_GAMBLER_HUGO] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Hugo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerHugo),
    },
    
    [TRAINER_GAMBLER_JASPER] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Jasper"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerJasper),
    },

    [TRAINER_GAMBLER_RICH] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Rich"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerRich),
    },

    [TRAINER_GAMBLER_RICH_2] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Rich"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerRich2),
    },

    [TRAINER_GAMBLER_RICH_3] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Rich"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerRich3),
    },

    [TRAINER_GAMBLER_RICH_4] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Rich"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerRich4),
    },

    [TRAINER_GAMBLER_RICH_5] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Rich"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerRich5),
    },
    
    [TRAINER_GAMBLER_STAN] =
    {
        .trainerClass = TRAINER_CLASS_GAMBLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GAMBLER,
        .trainerName = _("Stan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GamblerStan),
    },
    
    [TRAINER_GENTLEMAN_ARTHUR] =
    {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("Arthur"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GentlemanArthur),
    },
    
    [TRAINER_GENTLEMAN_BROOKS] =
    {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("Brooks"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GentlemanBrooks),
    },

    [TRAINER_GENTLEMAN_CLIFFORD] =
    {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("Clifford"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GentlemanClifford),
    },

    [TRAINER_GENTLEMEN_EVERETT] =
    {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("Everett"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .party = TRAINER_PARTY(sParty_GentlemenEverett),
    },
    
    [TRAINER_GENTLEMAN_LAMAR] =
    {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("Lamar"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GentlemanLamar),
    },
    
    [TRAINER_GENTLEMAN_THOMAS] =
    {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("Thomas"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GentlemanThomas),
    },
    
    [TRAINER_GENTLEMAN_TUCKER] =
    {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("Tucker"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_GentlemanTucker),
    },
    
    [TRAINER_HIKER_ALAN] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Alan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerAlan),
    },

    [TRAINER_HIKER_ALLEN] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Allen"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerAllen),
    },
    
    [TRAINER_HIKER_BRICE] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Brice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerBrice),
    },
    
    [TRAINER_HIKER_CLARK] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Clark"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerClark),
    },
    
    [TRAINER_HIKER_DARYL] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Daryl"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerDaryl),
    },
    
    [TRAINER_HIKER_DUDLEY] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Dudley"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerDudley),
    },

    [TRAINER_HIKER_EARL] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Earl"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerEarl),
    },

    [TRAINER_HIKER_EARL_2] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Earl"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerEarl2),
    },

    [TRAINER_HIKER_EARL_3] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Earl"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerEarl3),
    },

    [TRAINER_HIKER_EARL_4] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Earl"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerEarl4),
    },

    [TRAINER_HIKER_EARL_5] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Earl"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerEarl5),
    },

    [TRAINER_HIKER_ERIC] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Eric"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerEric),
    },
    
    [TRAINER_HIKER_FRANKLIN] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Franklin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerFranklin),
    },

    [TRAINER_HIKER_FRANKLIN_2] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Franklin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerFranklin2),
    },

    [TRAINER_HIKER_FRANKLIN_3] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Franklin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerFranklin3),
    },

    [TRAINER_HIKER_FRANKLIN_4] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Franklin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerFranklin4),
    },

    [TRAINER_HIKER_FRANKLIN_5] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Franklin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerFranklin5),
    },
    
    [TRAINER_HIKER_JEREMY] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Jeremy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerJeremy),
    },

    [TRAINER_HIKER_JEREMY_2] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Jeremy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerJeremy2),
    },

    [TRAINER_HIKER_JEREMY_3] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Jeremy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerJeremy3),
    },

    [TRAINER_HIKER_JEREMY_4] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Jeremy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerJeremy4),
    },

    [TRAINER_HIKER_JEREMY_5] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Jeremy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerJeremy5),
    },
    
    [TRAINER_HIKER_LENNY] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Lenny"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerLenny),
    },

    [TRAINER_HIKER_LUCAS] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Lucas"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerLucas),
    },
    
    [TRAINER_HIKER_MARCOS] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Marcos"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerMarcos),
    },
    
    [TRAINER_HIKER_NOB] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Nob"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerNob),
    },
    
    [TRAINER_HIKER_OLIVER] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Oliver"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerOliver),
    },

    [TRAINER_HIKER_SAWYER] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Sawyer"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerSawyer),
    },
    
    [TRAINER_HIKER_TRENT] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Trent"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerTrent),
    },

    [TRAINER_HIKER_TRENT_2] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Trent"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerTrent2),
    },

    [TRAINER_HIKER_TRENT_3] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Trent"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerTrent3),
    },

    [TRAINER_HIKER_TRENT_4] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Trent"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerTrent4),
    },

    [TRAINER_HIKER_TRENT_5] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Trent"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerTrent5),
    },
    
    [TRAINER_HIKER_WAYNE] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Wayne"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_HikerWayne),
    },
    
    [TRAINER_JUGGLER_DALTON] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Dalton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerDalton),
    },
    
    [TRAINER_JUGGLER_EDWARD] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Edward"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerEdward),
    },
    
    [TRAINER_JUGGLER_GREGORY] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Gregory"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerGregory),
    },
    
    [TRAINER_JUGGLER_KAYDEN] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Kayden"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerKayden),
    },
    
    [TRAINER_JUGGLER_KIRK] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Kirk"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerKirk),
    },

    [TRAINER_JUGGLER_MASON] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Mason"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerMason),
    },

    [TRAINER_JUGGLER_MASON_2] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Mason"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerMason2),
    },

    [TRAINER_JUGGLER_MASON_3] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Mason"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerMason3),
    },

    [TRAINER_JUGGLER_MASON_4] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Mason"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerMason4),
    },

    [TRAINER_JUGGLER_MASON_5] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Mason"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerMason5),
    },

    [TRAINER_JUGGLER_NATE] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Nate"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerNate),
    },
    
    [TRAINER_JUGGLER_NELSON] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Nelson"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerNelson),
    },

    [TRAINER_JUGGLER_SHAWN] =
    {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("Shawn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_JugglerShawn),
    },
    
    [TRAINER_LADY_GILLIAN] =
    {
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("Gillian"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LadyGillian),
    },
    
    [TRAINER_LADY_JACKI] =
    {
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("Jacki"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LadyJacki),
    },
    
    [TRAINER_LADY_SELPHY] =
    {
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("Selphy"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LadySelphy),
    },
    
    [TRAINER_LASS_ALI] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Ali"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassAli),
    },

    [TRAINER_LASS_ANDREA] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Andrea"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassAndrea),
    },
    
    [TRAINER_LASS_ANN] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Ann"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassAnn),
    },
    
    [TRAINER_LASS_CRISSY] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Crissy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassCrissy),
    },
    
    [TRAINER_LASS_DALIA] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Dalia"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassDalia),
    },
    
    [TRAINER_LASS_DAWN] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Dawn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassDawn),
    },
    
    [TRAINER_LASS_HALEY] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Haley"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassHaley),
    },
    
    [TRAINER_LASS_IRIS] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Iris"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassIris),
    },
    
    [TRAINER_LASS_JANICE] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Janice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassJanice),
    },

    [TRAINER_LASS_JANICE_2] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Janice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassJanice2),
    },

    [TRAINER_LASS_JANICE_3] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Janice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassJanice3),
    },

    [TRAINER_LASS_JANICE_4] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Janice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassJanice4),
    },

    [TRAINER_LASS_JANICE_5] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Janice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassJanice5),
    },
    
    [TRAINER_LASS_JOANA] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Joana"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassJoana),
    },

    [TRAINER_LASS_JULIA] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Julia"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassJulia),
    },
    
    [TRAINER_LASS_KAY] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Kay"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassKay),
    },

    [TRAINER_LASS_KRISE] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Krise"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassKrise),
    },

    [TRAINER_LASS_LISA] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Lisa"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassLisa),
    },
    
    [TRAINER_LASS_MEGAN] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Megan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassMegan),
    },

    [TRAINER_LASS_MEGAN_2] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Megan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassMegan2),
    },

    [TRAINER_LASS_MEGAN_3] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Megan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassMegan3),
    },

    [TRAINER_LASS_MEGAN_4] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Megan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassMegan4),
    },

    [TRAINER_LASS_MEGAN_5] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Megan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassMegan5),
    },
    
    [TRAINER_LASS_MIRIAM] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Miriam"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassMiriam),
    },
    
    [TRAINER_LASS_PAIGE] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Paige"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassPaige),
    },
    
    [TRAINER_LASS_RELI] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Reli"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassReli),
    },

    [TRAINER_LASS_RELI_2] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Reli"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassReli2),
    },

    [TRAINER_LASS_RELI_3] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Reli"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassReli3),
    },

    [TRAINER_LASS_RELI_4] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Reli"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassReli4),
    },

    [TRAINER_LASS_RELI_5] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Reli"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassReli5),
    },
    
    [TRAINER_LASS_ROBIN] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Robin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassRobin),
    },
    
    [TRAINER_LASS_SALLY] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Sally"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassSally),
    },

    [TRAINER_LASS_TIANA] =
    {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Tiana"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_LassTiana),
    },

    [TRAINER_LEADER_BROCK] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BROCK,
        .trainerName = _("Brock"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderBrock),
    },

    [TRAINER_LEADER_BROCK_2] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BROCK,
        .trainerName = _("Brock"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderBrock2),
    },

    [TRAINER_LEADER_BROCK_3] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BROCK,
        .trainerName = _("Brock"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderBrock3),
    },

    [TRAINER_LEADER_BROCK_4] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BROCK,
        .trainerName = _("Brock"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderBrock4),
    },

    [TRAINER_LEADER_BROCK_5] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BROCK,
        .trainerName = _("Brock"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderBrock5),
    },
    
    [TRAINER_LEADER_MISTY] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_MISTY,
        .trainerName = _("Misty"),
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderMisty),
    },

    [TRAINER_LEADER_MISTY_2] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_MISTY,
        .trainerName = _("Misty"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderMisty2),
    },

    [TRAINER_LEADER_MISTY_3] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_MISTY,
        .trainerName = _("Misty"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderMisty3),
    },

    [TRAINER_LEADER_MISTY_4] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_MISTY,
        .trainerName = _("Misty"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderMisty4),
    },

    [TRAINER_LEADER_MISTY_5] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_MISTY,
        .trainerName = _("Misty"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderMisty5),
    },
    
    [TRAINER_LEADER_LT_SURGE] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_LT_SURGE,
        .trainerName = _("Lt. Surge"),
        .items = {ITEM_SUPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderLtSurge),
    },

    [TRAINER_LEADER_LT_SURGE_2] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_LT_SURGE,
        .trainerName = _("Lt. Surge"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderLtSurge2),
    },

    [TRAINER_LEADER_LT_SURGE_3] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_LT_SURGE,
        .trainerName = _("Lt. Surge"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderLtSurge3),
    },

    [TRAINER_LEADER_LT_SURGE_4] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_LT_SURGE,
        .trainerName = _("Lt. Surge"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderLtSurge4),
    },

    [TRAINER_LEADER_LT_SURGE_5] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_LT_SURGE,
        .trainerName = _("Lt. Surge"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderLtSurge5),
    },
    
    [TRAINER_LEADER_ERIKA] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ERIKA,
        .trainerName = _("Erika"),
        .items = {ITEM_HYPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderErika),
    },

    [TRAINER_LEADER_ERIKA_2] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ERIKA,
        .trainerName = _("Erika"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderErika2),
    },

    [TRAINER_LEADER_ERIKA_3] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ERIKA,
        .trainerName = _("Erika"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderErika3),
    },

    [TRAINER_LEADER_ERIKA_4] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ERIKA,
        .trainerName = _("Erika"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderErika4),
    },

    [TRAINER_LEADER_ERIKA_5] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ERIKA,
        .trainerName = _("Erika"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderErika5),
    },
    
    [TRAINER_LEADER_KOGA] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_KOGA,
        .trainerName = _("Koga"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderKoga),
    },

    [TRAINER_LEADER_KOGA_2] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_KOGA,
        .trainerName = _("Koga"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderKoga2),
    },

    [TRAINER_LEADER_KOGA_3] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_KOGA,
        .trainerName = _("Koga"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderKoga3),
    },

    [TRAINER_LEADER_KOGA_4] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_KOGA,
        .trainerName = _("Koga"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderKoga4),
    },

    [TRAINER_LEADER_KOGA_5] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_KOGA,
        .trainerName = _("Koga"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderKoga5),
    },
    
    [TRAINER_LEADER_SABRINA] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_SABRINA,
        .trainerName = _("Sabrina"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderSabrina),
    },

    [TRAINER_LEADER_SABRINA_2] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_SABRINA,
        .trainerName = _("Sabrina"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY,
        .party = TRAINER_PARTY(sParty_LeaderSabrina2),
    },

    [TRAINER_LEADER_SABRINA_3] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_SABRINA,
        .trainerName = _("Sabrina"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY,
        .party = TRAINER_PARTY(sParty_LeaderSabrina3),
    },

    [TRAINER_LEADER_SABRINA_4] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_SABRINA,
        .trainerName = _("Sabrina"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY,
        .party = TRAINER_PARTY(sParty_LeaderSabrina4),
    },

    [TRAINER_LEADER_SABRINA_5] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_SABRINA,
        .trainerName = _("Sabrina"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY,
        .party = TRAINER_PARTY(sParty_LeaderSabrina5),
    },
    
    [TRAINER_LEADER_BLAINE] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .trainerName = _("Blaine"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderBlaine),
    },

    [TRAINER_LEADER_BLAINE_2] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .trainerName = _("Blaine"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderBlaine2),
    },

    [TRAINER_LEADER_BLAINE_3] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .trainerName = _("Blaine"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderBlaine3),
    },

    [TRAINER_LEADER_BLAINE_4] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .trainerName = _("Blaine"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderBlaine4),
    },

    [TRAINER_LEADER_BLAINE_5] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .trainerName = _("Blaine"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_NONE},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderBlaine5),
    },
    
    [TRAINER_BOSS_GIOVANNI] =
    {
        .trainerClass = TRAINER_CLASS_BOSS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_LEADER_GIOVANNI,
        .trainerName = _("Giovanni"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BossGiovanni),
    },
    
    [TRAINER_BOSS_GIOVANNI_2] =
    {
        .trainerClass = TRAINER_CLASS_BOSS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_LEADER_GIOVANNI,
        .trainerName = _("Giovanni"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_BossGiovanni2),
    },
    
    [TRAINER_LEADER_GIOVANNI] =
    {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_LEADER_GIOVANNI,
        .trainerName = _("Giovanni"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_LeaderGiovanni),
    },

    [TRAINER_PAINTER_CELINA] =
    {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("Celina"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PainterCelina),
    },
    
    [TRAINER_PAINTER_DAISY] =
    {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("Daisy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PainterDaisy),
    },

    [TRAINER_PAINTER_EDNA] =
    {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("Edna"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PainterEdna),
    },

    [TRAINER_PAINTER_RAYNA] =
    {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("Rayna"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PainterRayna),
    },

    [TRAINER_PAINTER_RAYNA_2] =
    {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("Rayna"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PainterRayna2),
    },

    [TRAINER_PAINTER_RAYNA_3] =
    {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("Rayna"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PainterRayna3),
    },

    [TRAINER_PAINTER_RAYNA_4] =
    {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("Rayna"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PainterRayna4),
    },

    [TRAINER_PAINTER_RAYNA_5] =
    {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("Rayna"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PainterRayna5),
    },
    
    [TRAINER_PICNICKER_ALICIA] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Alicia"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerAlicia),
    },
    
    [TRAINER_PICNICKER_ALMA] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Alma"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerAlma),
    },
    
    [TRAINER_PICNICKER_ARIANA] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Ariana"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerAriana),
    },

    [TRAINER_PICNICKER_BECKY] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Becky"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerBecky),
    },

    [TRAINER_PICNICKER_BECKY_2] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Becky"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerBecky2),
    },

    [TRAINER_PICNICKER_BECKY_3] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Becky"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerBecky3),
    },

    [TRAINER_PICNICKER_BECKY_4] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Becky"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerBecky4),
    },

    [TRAINER_PICNICKER_BECKY_5] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Becky"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerBecky5),
    },
    
    [TRAINER_PICNICKER_CAITLIN] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Caitlin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerCaitlin),
    },

    [TRAINER_PICNICKER_CAITLIN_2] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Caitlin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerCaitlin2),
    },

    [TRAINER_PICNICKER_CAITLIN_3] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Caitlin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerCaitlin3),
    },

    [TRAINER_PICNICKER_CAITLIN_4] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Caitlin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerCaitlin4),
    },

    [TRAINER_PICNICKER_CAITLIN_5] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Caitlin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerCaitlin5),
    },
    
    [TRAINER_PICNICKER_CAROL] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Carol"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerCarol),
    },

    [TRAINER_PICNICKER_CELIA] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Celia"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerCelia),
    },

    [TRAINER_PICNICKER_CHARLOTTE] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Charlotte"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicknickerCharlotte),
    },
    
    [TRAINER_PICNICKER_CLAIRE] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Claire"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerClaire),
    },
    
    [TRAINER_PICNICKER_DANA] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Dana"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerDana),
    },
    
    [TRAINER_PICNICKER_DIANA] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Diana"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerDiana),
    },

    [TRAINER_PICNICKER_GWEN] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Gwen"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerGwen),
    },
    
    [TRAINER_PICNICKER_HEIDI] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Heidi"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerHeidi),
    },

    [TRAINER_PICNICKER_IRENE] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Irene"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerIrene),
    },
    
    [TRAINER_PICNICKER_ISABELLE] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Isabelle"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerIsabelle),
    },

    [TRAINER_PICNICKER_ISABELLE_2] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Isabelle"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerIsabelle2),
    },

    [TRAINER_PICNICKER_ISABELLE_3] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Isabelle"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerIsabelle3),
    },

    [TRAINER_PICNICKER_ISABELLE_4] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Isabelle"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerIsabelle4),
    },

    [TRAINER_PICNICKER_ISABELLE_5] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Isabelle"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerIsabelle5),
    },
    
    [TRAINER_PICNICKER_KELSEY] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Kelsey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerKelsey),
    },

    [TRAINER_PICNICKER_KELSEY_2] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Kelsey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerKelsey2),
    },

    [TRAINER_PICNICKER_KELSEY_3] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Kelsey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerKelsey3),
    },

    [TRAINER_PICNICKER_KELSEY_4] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Kelsey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerKelsey4),
    },

    [TRAINER_PICNICKER_KELSEY_5] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Kelsey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerKelsey5),
    },

    [TRAINER_PICNICKER_KINDRA] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Kindra"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerKindra),
    },

    [TRAINER_PICNICKER_LEAH] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Leah"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerLeah),
    },
    
    [TRAINER_PICNICKER_MARCY] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Marcy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerMarcy),
    },

    [TRAINER_PICNICKER_MARTHA] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Martha"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerMartha),
    },
    
    [TRAINER_PICNICKER_MISSY] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Missy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerMissy),
    },

    [TRAINER_PICNICKER_MISSY_2] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Missy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerMissy2),
    },

    [TRAINER_PICNICKER_MISSY_3] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Missy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerMissy3),
    },

    [TRAINER_PICNICKER_MISSY_4] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Missy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerMissy4),
    },

    [TRAINER_PICNICKER_MISSY_5] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Missy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerMissy5),
    },
    
    [TRAINER_PICNICKER_NANCY] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Nancy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerNancy),
    },
    
    [TRAINER_PICNICKER_SOFIA] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Sofia"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerSofia),
    },

    [TRAINER_PICNICKER_SUSIE] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Susie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerSusie),
    },

    [TRAINER_PICNICKER_SUSIE_2] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Susie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerSusie2),
    },

    [TRAINER_PICNICKER_SUSIE_3] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Susie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerSusie3),
    },

    [TRAINER_PICNICKER_SUSIE_4] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Susie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerSusie4),
    },

    [TRAINER_PICNICKER_SUSIE_5] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Susie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerSusie5),
    },
    
    [TRAINER_PICNICKER_TINA] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Tina"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerTina),
    },

    [TRAINER_PICNICKER_VALERIE] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Valerie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerValerie),
    },
    
    [TRAINER_PICNICKER_YAZMIN] =
    {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("Yasmin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PicnickerYazmin),
    },
    
    [TRAINER_PKMN_BREEDER_ALIZE] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("Alize"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PkmnBreederAlize),
    },

    [TRAINER_PKMN_BREEDER_ALIZE_2] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("Alize"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PkmnBreederAlize2),
    },

    [TRAINER_PKMN_BREEDER_ALIZE_3] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("Alize"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PkmnBreederAlize3),
    },

    [TRAINER_PKMN_BREEDER_ALIZE_4] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("Alize"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PkmnBreederAlize4),
    },

    [TRAINER_PKMN_BREEDER_ALIZE_5] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("Alize"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PkmnBreederAlize5),
    },

    [TRAINER_PKMN_BREEDER_ALLISON] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("Allison"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PkmnBreederAllison),
    },

    [TRAINER_PKMN_BREEDER_BETHANY] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("Bethany"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PkmnBreederBethany),
    },
    
    [TRAINER_PKMN_RANGER_BETH] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Beth"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerBeth),
    },

    [TRAINER_PKMN_RANGER_JACKSON] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("Jackson"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerJackson),
    },

    [TRAINER_PKMN_RANGER_KATELYN] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Katelyn"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerKatelyn),
    },

    [TRAINER_PKMN_RANGER_KATELYN_2] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Katelyn"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerKatelyn2),
    },

    [TRAINER_PKMN_RANGER_KATELYN_3] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Katelyn"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerKatelyn3),
    },

    [TRAINER_PKMN_RANGER_KATELYN_4] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Katelyn"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerKatelyn4),
    },

    [TRAINER_PKMN_RANGER_KATELYN_5] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Katelyn"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerKatelyn5),
    },

    [TRAINER_PKMN_RANGER_LOGAN] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("Logan"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerLogan),
    },

    [TRAINER_PKMN_RANGER_MADELINE] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Madeline"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerMadeline),
    },

    [TRAINER_PKMN_RANGER_MADELINE_2] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Madeline"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerMadeline2),
    },

    [TRAINER_PKMN_RANGER_MADELINE_3] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Madeline"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerMadeline3),
    },

    [TRAINER_PKMN_RANGER_MADELINE_4] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Madeline"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerMadeline4),
    },

    [TRAINER_PKMN_RANGER_MADELINE_5] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Madeline"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerMadeline5),
    },
    
    [TRAINER_PKMN_RANGER_NICOLAS] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("Nicolas"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerNicolas),
    },

    [TRAINER_PKMN_RANGER_NICOLAS_2] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("Nicolas"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerNicolas2),
    },

    [TRAINER_PKMN_RANGER_NICOLAS_3] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("Nicolas"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerNicolas3),
    },

    [TRAINER_PKMN_RANGER_NICOLAS_4] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("Nicolas"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerNicolas4),
    },

    [TRAINER_PKMN_RANGER_NICOLAS_5] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("Nicolas"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerNicolas5),
    },

    [TRAINER_PKMN_RANGER_SEBASTIAN] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("Sebastian"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerSebastian),
    },

    [TRAINER_PKMN_RANGER_SOPHIA] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("Sophia"),
        .items = {ITEM_FULL_RESTORE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_PkmnRangerSophia),
    },

    [TRAINER_POKEMANIAC_ASHTON] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Ashton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacAshton),
    },

    [TRAINER_POKEMANIAC_COOPER] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Cooper"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacCooper),
    },
    
    [TRAINER_POKEMANIAC_DAWSON] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Dawson"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacDawson),
    },
    
    [TRAINER_POKEMANIAC_HECTOR] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Hector"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacHector),
    },

    [TRAINER_POKEMANIAC_HECTOR_2] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Hector"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacHector2),
    },

    [TRAINER_POKEMANIAC_HECTOR_3] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Hector"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacHector3),
    },

    [TRAINER_POKEMANIAC_HECTOR_4] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Hector"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacHector4),
    },

    [TRAINER_POKEMANIAC_HECTOR_5] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Hector"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacHector5),
    },
    
    [TRAINER_POKEMANIAC_HERMAN] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Herman"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacHerman),
    },

    [TRAINER_POKEMANIAC_HERMAN_2] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Herman"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacHerman2),
    },

    [TRAINER_POKEMANIAC_HERMAN_3] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Herman"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacHerman3),
    },

    [TRAINER_POKEMANIAC_HERMAN_4] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Herman"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacHerman4),
    },

    [TRAINER_POKEMANIAC_HERMAN_5] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Herman"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacHerman5),
    },
    
    [TRAINER_POKEMANIAC_MARK] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Mark"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacMark),
    },

    [TRAINER_POKEMANIAC_MARK_2] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Mark"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacMark2),
    },

    [TRAINER_POKEMANIAC_MARK_3] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Mark"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacMark3),
    },

    [TRAINER_POKEMANIAC_MARK_4] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Mark"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacMark4),
    },

    [TRAINER_POKEMANIAC_MARK_5] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Mark"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacMark5),
    },

    [TRAINER_POKEMANIAC_STEVE] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Steve"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacSteve),
    },

    [TRAINER_POKEMANIAC_WINSTON] =
    {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("Winston"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PokemaniacWinston),
    },

    [TRAINER_PSYCHIC_ALEXIS] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Alexis"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicAlexis),
    },

    [TRAINER_PSYCHIC_ALVARO] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Alvaro"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .party = TRAINER_PARTY(sParty_PsychicAlvaro),
    },

    [TRAINER_PSYCHIC_CAMERON] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Cameron"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicCameron),
    },
    
    [TRAINER_PSYCHIC_DARIO] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Dario"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicDario),
    },

    [TRAINER_PSYCHIC_DARIO_2] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Dario"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicDario2),
    },

    [TRAINER_PSYCHIC_DARIO_3] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Dario"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicDario3),
    },

    [TRAINER_PSYCHIC_DARIO_4] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Dario"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicDario4),
    },

    [TRAINER_PSYCHIC_DARIO_5] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Dario"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicDario5),
    },

    [TRAINER_PSYCHIC_JACLYN] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Jaclyn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicJaclyn),
    },
    
    [TRAINER_PSYCHIC_JACLYN_2] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Jaclyn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicJaclyn2),
    },
    
    [TRAINER_PSYCHIC_JACLYN_3] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Jaclyn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicJaclyn3),
    },
    
    [TRAINER_PSYCHIC_JACLYN_4] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Jaclyn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicJaclyn4),
    },
    
    [TRAINER_PSYCHIC_JACLYN_5] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Jaclyn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicJaclyn5),
    },

    [TRAINER_PSYCHIC_JOHAN] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Johan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicJohan),
    },

    [TRAINER_PSYCHIC_JOSHUA] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Joshua"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicJoshua),
    },

    [TRAINER_PSYCHIC_LAURA] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Laura"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicLaura),
    },

    [TRAINER_PSYCHIC_MARIELA] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Mariela"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .party = TRAINER_PARTY(sParty_PsychicMariela),
    },

    [TRAINER_PSYCHIC_PRESTON] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Preston"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicPreston),
    },
    
    [TRAINER_PSYCHIC_RODETTE] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Rodette"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicRodette),
    },

    [TRAINER_PSYCHIC_RODETTE_2] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Rodette"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicRodette2),
    },

    [TRAINER_PSYCHIC_RODETTE_3] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Rodette"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicRodette3),
    },

    [TRAINER_PSYCHIC_RODETTE_4] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Rodette"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicRodette4),
    },

    [TRAINER_PSYCHIC_RODETTE_5] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("Rodette"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicRodette5),
    },

    [TRAINER_PSYCHIC_TYRON] =
    {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Tyron"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_PsychicTyron),
    },
    
    [TRAINER_RIVAL_OAKS_LAB_SQUIRTLE] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalOaksLabSquirtle),
    },
    
    [TRAINER_RIVAL_OAKS_LAB_BULBASAUR] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalOaksLabBulbasaur),
    },
    
    [TRAINER_RIVAL_OAKS_LAB_CHARMANDER] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalOaksLabCharmander),
    },
    
    [TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalRoute22EarlySquirtle),
    },
    
    [TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalRoute22EarlyBulbasaur),
    },
    
    [TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalRoute22EarlyCharmander),
    },
    
    [TRAINER_RIVAL_CERULEAN_SQUIRTLE] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalCeruleanSquirtle),
    },
    
    [TRAINER_RIVAL_CERULEAN_BULBASAUR] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalCeruleanBulbasaur),
    },
    
    [TRAINER_RIVAL_CERULEAN_CHARMANDER] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_EARLY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalCeruleanCharmander),
    },
    
    [TRAINER_RIVAL_SS_ANNE_SQUIRTLE] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalSsAnneSquirtle),
    },
    
    [TRAINER_RIVAL_SS_ANNE_BULBASAUR] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalSsAnneBulbasaur),
    },

    [TRAINER_RIVAL_SS_ANNE_CHARMANDER] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalSsAnneCharmander),
    },
    
    [TRAINER_RIVAL_POKEMON_TOWER_SQUIRTLE] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalPokemonTowerSquirtle),
    },

    [TRAINER_RIVAL_POKEMON_TOWER_BULBASAUR] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalPokemonTowerBulbasaur),
    },

    [TRAINER_RIVAL_POKEMON_TOWER_CHARMANDER] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalPokemonTowerCharmander),
    },
    
    [TRAINER_RIVAL_SILPH_SQUIRTLE] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalSilphSquirtle),
    },
    
    [TRAINER_RIVAL_SILPH_BULBASAUR] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalSilphBulbasaur),
    },

    [TRAINER_RIVAL_SILPH_CHARMANDER] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalSilphCharmander),
    },
    
    [TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalRoute22LateSquirtle),
    },
    
    [TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalRoute22LateBulbasaur),
    },
    
    [TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_RivalRoute22LateCharmander),
    },
    
    [TRAINER_ROCKER_LUCA] =
    {
        .trainerClass = TRAINER_CLASS_ROCKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ROCKER,
        .trainerName = _("Luca"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RockerLuca),
    },

    [TRAINER_ROCKER_LUCA_2] =
    {
        .trainerClass = TRAINER_CLASS_ROCKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ROCKER,
        .trainerName = _("Luca"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RockerLuca2),
    },

    [TRAINER_ROCKER_LUCA_3] =
    {
        .trainerClass = TRAINER_CLASS_ROCKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ROCKER,
        .trainerName = _("Luca"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RockerLuca3),
    },

    [TRAINER_ROCKER_LUCA_4] =
    {
        .trainerClass = TRAINER_CLASS_ROCKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ROCKER,
        .trainerName = _("Luca"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RockerLuca4),
    },

    [TRAINER_ROCKER_LUCA_5] =
    {
        .trainerClass = TRAINER_CLASS_ROCKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ROCKER,
        .trainerName = _("Luca"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RockerLuca5),
    },

    [TRAINER_RUIN_MANIAC_BENJAMIN] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Benjamin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacBenjamin),
    },
    
    [TRAINER_RUIN_MANIAC_BRANDON] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Brandon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacBrandon),
    },

    [TRAINER_RUIN_MANIAC_FOSTER] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Foster"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacFoster),
    },

    [TRAINER_RUIN_MANIAC_LARRY] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Larry"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacLarry),
    },

    [TRAINER_RUIN_MANIAC_LARRY_2] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Larry"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacLarry2),
    },

    [TRAINER_RUIN_MANIAC_LARRY_3] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Larry"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacLarry3),
    },

    [TRAINER_RUIN_MANIAC_LARRY_4] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Larry"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacLarry4),
    },

    [TRAINER_RUIN_MANIAC_LARRY_5] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Larry"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacLarry5),
    },

    [TRAINER_RUIN_MANIAC_LAWSON] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Lawson"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacLawson),
    },
    
    [TRAINER_RUIN_MANIAC_LAYTON] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Layton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacLayton),
    },

    [TRAINER_RUIN_MANIAC_STANLY] =
    {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("Stanly"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_RuinManiacStanly),
    },
    
    [TRAINER_SAILOR_DUNCAN] =
    {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("Duncan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SailorDuncan),
    },
    
    [TRAINER_SAILOR_DWAYNE] =
    {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("Dwayne"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SailorDwayne),
    },
    
    [TRAINER_SAILOR_DYLAN] =
    {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("Dylan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SailorDylan),
    },
    
    [TRAINER_SAILOR_EDMOND] =
    {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("Edmond"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SailorEdmond),
    },
    
    [TRAINER_SAILOR_HUEY] =
    {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("Huey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SailorHuey),
    },
    
    [TRAINER_SAILOR_LEONARD] =
    {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("Leonard"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SailorLeonard),
    },
    
    [TRAINER_SAILOR_PHILLIP] =
    {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("Phillip"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SailorPhillip),
    },
    
    [TRAINER_SAILOR_TREVOR] =
    {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("Trevor"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SailorTrevor),
    },
    
    [TRAINER_SCIENTIST_BEAU] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Beau"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistBeau),
    },
    
    [TRAINER_SCIENTIST_BRAYDON] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Braydon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistBraydon),
    },
    
    [TRAINER_SCIENTIST_CONNOR] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Connor"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistConnor),
    },
    
    [TRAINER_SCIENTIST_ED] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Ed"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistEd),
    },

    [TRAINER_SCIENTIST_GIDEON] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Gideon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistGideon),
    },
    
    [TRAINER_SCIENTIST_IVAN] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Ivan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistIvan),
    },
    
    [TRAINER_SCIENTIST_JERRY] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Jerry"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistJerry),
    },
    
    [TRAINER_SCIENTIST_JOSE] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Jose"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistJose),
    },
    
    [TRAINER_SCIENTIST_JOSHUA] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Joshua"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistJoshua),
    },
    
    [TRAINER_SCIENTIST_PARKER] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Parker"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistParker),
    },

    [TRAINER_SCIENTIST_RODNEY] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Rodney"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistRodney),
    },

    [TRAINER_SCIENTIST_TAYLOR] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Taylor"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistTaylor),
    },
    
    [TRAINER_SCIENTIST_TED] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Ted"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistTed),
    },
    
    [TRAINER_SCIENTIST_TRAVIS] =
    {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("Travis"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_ScientistTravis),
    },

    [TRAINER_SIS_AND_BRO_AVA_GEB] =
    {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("Ava & Geb"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SisAndBroAvaGeb),
    },
    
    [TRAINER_SIS_AND_BRO_LIA_LUC] =
    {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("Lia & Luc"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SisAndBroLiaLuc),
    },
    
    [TRAINER_SIS_AND_BRO_LIL_IAN] =
    {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("Lil & Ian"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SisAndBroLilIan),
    },

    [TRAINER_SIS_AND_BRO_LIL_IAN_2] =
    {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("Lil & Ian"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SisAndBroLilIan2),
    },

    [TRAINER_SIS_AND_BRO_LIL_IAN_3] =
    {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("Lil & Ian"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SisAndBroLilIan3),
    },

    [TRAINER_SIS_AND_BRO_LIL_IAN_4] =
    {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("Lil & Ian"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SisAndBroLilIan4),
    },

    [TRAINER_SIS_AND_BRO_LIL_IAN_5] =
    {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("Lil & Ian"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SisAndBroLilIan5),
    },
    
    [TRAINER_SUPER_NERD_AIDAN] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Aidan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdAidan),
    },

    [TRAINER_SUPER_NERD_AVERY] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Avery"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdAvery),
    },

    [TRAINER_SUPER_NERD_DEREK] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Derek"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdDerek),
    },
    
    [TRAINER_SUPER_NERD_ERIK] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Erik"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdErik),
    },

    [TRAINER_SUPER_NERD_GLENN] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Glenn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdGlenn),
    },
    
    [TRAINER_SUPER_NERD_JOVAN] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Jovan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdJovan),
    },
    
    [TRAINER_SUPER_NERD_LESLIE] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Leslie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdLeslie),
    },
    
    [TRAINER_SUPER_NERD_MIGUEL] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Miguel"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdMiguel),
    },

    [TRAINER_SUPER_NERD_PAUL] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Paul"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdPaul),
    },

    [TRAINER_SUPER_NERD_TED] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Ted"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdTed),
    },

    [TRAINER_SUPER_NERD_ZAC] =
    {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Zac"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SuperNerdZac),
    },

    [TRAINER_SWIMMER_FEMALE_ABIGAIL] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Abigail"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleAbigail),
    },

    [TRAINER_SWIMMER_FEMALE_ALICE] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Alice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleAlice),
    },

    [TRAINER_SWIMMER_FEMALE_ALICE_2] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Alice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleAlice2),
    },

    [TRAINER_SWIMMER_FEMALE_ALICE_3] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Alice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleAlice3),
    },

    [TRAINER_SWIMMER_FEMALE_ALICE_4] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Alice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleAlice4),
    },

    [TRAINER_SWIMMER_FEMALE_ALICE_5] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Alice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleAlice5),
    },
    
    [TRAINER_SWIMMER_FEMALE_AMARA] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Amara"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleAmara),
    },
    
    [TRAINER_SWIMMER_FEMALE_ANYA] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Anya"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleAnya),
    },

    [TRAINER_SWIMMER_FEMALE_CONNIE] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Connie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleConnie),
    },

    [TRAINER_SWIMMER_FEMALE_DENISE] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Denise"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleDenise),
    },
    
    [TRAINER_SWIMMER_FEMALE_MARIA] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Maria"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleMaria),
    },

    [TRAINER_SWIMMER_FEMALE_MELISSA] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Melissa"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleMelissa),
    },

    [TRAINER_SWIMMER_FEMALE_MELISSA_2] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Melissa"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleMelissa2),
    },

    [TRAINER_SWIMMER_FEMALE_MELISSA_3] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Melissa"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleMelissa3),
    },

    [TRAINER_SWIMMER_FEMALE_MELISSA_4] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Melissa"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleMelissa4),
    },

    [TRAINER_SWIMMER_FEMALE_MELISSA_5] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Melissa"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleMelissa5),
    },

    [TRAINER_SWIMMER_FEMALE_NORA] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Nora"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleNora),
    },
    
    [TRAINER_SWIMMER_FEMALE_NICOLE] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Nicole"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleNicole),
    },

    [TRAINER_SWIMMER_FEMALE_NICOLE_2] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Nicole"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleNicole2),
    },

    [TRAINER_SWIMMER_FEMALE_NICOLE_3] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Nicole"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleNicole3),
    },

    [TRAINER_SWIMMER_FEMALE_NICOLE_4] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Nicole"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleNicole4),
    },

    [TRAINER_SWIMMER_FEMALE_NICOLE_5] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Nicole"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleNicole5),
    },
    
    [TRAINER_SWIMMER_FEMALE_SHIRLEY] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Shirley"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleShirley),
    },
    
    [TRAINER_SWIMMER_FEMALE_TIFFANY] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Tiffany"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleTiffany),
    },

    [TRAINER_SWIMMER_FEMALE_TISHA] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("Tisha"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerFemaleTisha),
    },

    [TRAINER_SWIMMER_MALE_AXLE] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Axle"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleAxle),
    },
    
    [TRAINER_SWIMMER_MALE_BARRY] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Barry"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleBarry),
    },

    [TRAINER_SWIMMER_MALE_DARRIN] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Darrin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleDarrin),
    },

    [TRAINER_SWIMMER_MALE_DARRIN_2] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Darrin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleDarrin2),
    },

    [TRAINER_SWIMMER_MALE_DARRIN_3] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Darrin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleDarrin3),
    },

    [TRAINER_SWIMMER_MALE_DARRIN_4] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Darrin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleDarrin4),
    },

    [TRAINER_SWIMMER_MALE_DARRIN_5] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Darrin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleDarrin5),
    },

    [TRAINER_SWIMMER_MALE_DAVID] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("David"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleDavid),
    },

    [TRAINER_SWIMMER_MALE_DEAN] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Dean"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleDean),
    },

    [TRAINER_SWIMMER_MALE_DOUGLAS] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Douglas"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleDouglas),
    },
    
    [TRAINER_SWIMMER_MALE_FINN] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Finn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleFinn),
    },

    [TRAINER_SWIMMER_MALE_FINN_2] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Finn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleFinn2),
    },

    [TRAINER_SWIMMER_MALE_FINN_3] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Finn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleFinn3),
    },

    [TRAINER_SWIMMER_MALE_FINN_4] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Finn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleFinn4),
    },

    [TRAINER_SWIMMER_MALE_FINN_5] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Finn"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleFinn5),
    },

    [TRAINER_SWIMMER_MALE_GARRETT] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Garrett"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleGarrett),
    },

    [TRAINER_SWIMMER_MALE_JACK] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Jack"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleJack),
    },

    [TRAINER_SWIMMER_MALE_JACK_2] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Jack"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleJack2),
    },

    [TRAINER_SWIMMER_MALE_JACK_3] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Jack"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleJack3),
    },

    [TRAINER_SWIMMER_MALE_JACK_4] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Jack"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleJack4),
    },

    [TRAINER_SWIMMER_MALE_JACK_5] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Jack"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleJack5),
    },

    [TRAINER_SWIMMER_MALE_JEROME] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Jerome"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleJerome),
    },
    
    [TRAINER_SWIMMER_MALE_LUIS] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Luis"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleLuis),
    },

    [TRAINER_SWIMMER_MALE_MATTHEW] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Matthew"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleMatthew),
    },

    [TRAINER_SWIMMER_MALE_MATTHEW_2] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Matthew"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleMatthew2),
    },

    [TRAINER_SWIMMER_MALE_MATTHEW_3] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Matthew"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleMatthew3),
    },

    [TRAINER_SWIMMER_MALE_MATTHEW_4] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Matthew"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleMatthew4),
    },

    [TRAINER_SWIMMER_MALE_MATTHEW_5] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Matthew"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleMatthew5),
    },

    [TRAINER_SWIMMER_MALE_MYMO] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Mymo"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleMymo),
    },

    [TRAINER_SWIMMER_MALE_REECE] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Reece"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleReece),
    },
    
    [TRAINER_SWIMMER_MALE_RICHARD] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Richard"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleRichard),
    },

    [TRAINER_SWIMMER_MALE_ROLAND] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Roland"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleRoland),
    },
    
    [TRAINER_SWIMMER_MALE_SAMIR] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Samir"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleSamir),
    },

    [TRAINER_SWIMMER_MALE_SAMIR_2] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Samir"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleSamir2),
    },

    [TRAINER_SWIMMER_MALE_SAMIR_3] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Samir"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleSamir3),
    },

    [TRAINER_SWIMMER_MALE_SAMIR_4] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Samir"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleSamir4),
    },

    [TRAINER_SWIMMER_MALE_SAMIR_5] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Samir"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleSamir5),
    },
    
    [TRAINER_SWIMMER_MALE_SPENCER] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Spencer"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleSpencer),
    },
    
    [TRAINER_SWIMMER_MALE_TOBY] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Toby"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleToby),
    },

    [TRAINER_SWIMMER_MALE_TONY] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Tony"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleTony),
    },

    [TRAINER_SWIMMER_MALE_TONY_2] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Tony"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleTony2),
    },

    [TRAINER_SWIMMER_MALE_TONY_3] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Tony"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleTony3),
    },

    [TRAINER_SWIMMER_MALE_TONY_4] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Tony"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleTony4),
    },

    [TRAINER_SWIMMER_MALE_TONY_5] =
    {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("Tony"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_SwimmerMaleTony5),
    },

    [TRAINER_TAMER_COLE] =
    {
        .trainerClass = TRAINER_CLASS_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = _("Cole"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TamerCole),
    },

    [TRAINER_TAMER_EDGAR] =
    {
        .trainerClass = TRAINER_CLASS_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = _("Edgar"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TamerEdgar),
    },

    [TRAINER_TAMER_EVAN] =
    {
        .trainerClass = TRAINER_CLASS_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = _("Evan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TamerEvan),
    },
    
    [TRAINER_TAMER_JASON] =
    {
        .trainerClass = TRAINER_CLASS_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = _("Jason"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TamerJason),
    },
    
    [TRAINER_TAMER_PHIL] =
    {
        .trainerClass = TRAINER_CLASS_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = _("Phil"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TamerPhil),
    },
    
    [TRAINER_TAMER_VINCENT] =
    {
        .trainerClass = TRAINER_CLASS_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = _("Vincent"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TamerVincent),
    },
    
    [TRAINER_TEAM_ROCKET_ADMIN] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("Admin"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_TeamRocketAdmin),
    },

    [TRAINER_TEAM_ROCKET_ADMIN_2] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Admin"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_TeamRocketAdmin2),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_2] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt2),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_3] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt3),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_4] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt4),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_5] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt5),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_6] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt6),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_7] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt7),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_8] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt8),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_9] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt9),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_10] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt10),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_11] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt11),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_12] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt12),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_13] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt13),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_14] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt14),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_15] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt15),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_16] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt16),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_17] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt17),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_18] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt18),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_19] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt19),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_20] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt20),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_21] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt21),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_23] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt23),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_24] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt24),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_25] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt25),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_26] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt26),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_27] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt27),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_28] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt28),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_29] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt29),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_30] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt30),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_31] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt31),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_32] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt32),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_33] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt33),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_34] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt34),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_35] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt35),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_36] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt36),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_37] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt37),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_38] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt38),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_39] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt39),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_40] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt40),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_41] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt41),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_42] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt42),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_43] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt43),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_44] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt44),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_45] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt45),
    },
    
    [TRAINER_TEAM_ROCKET_GRUNT_46] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt46),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_47] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt47),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_48] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt48),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_49] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt49),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_50] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt50),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_51] =
    {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TeamRocketGrunt51),
    },

    [TRAINER_TUBER_ALEXIS] =
    {
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("Alexis"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TuberAlexis),
    },

    [TRAINER_TUBER_AMIRA] =
    {
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("Amira"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TuberAmira),
    },

    [TRAINER_TUBER_AMIRA_2] =
    {
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("Amira"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TuberAmira2),
    },

    [TRAINER_TUBER_AMIRA_3] =
    {
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("Amira"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TuberAmira3),
    },

    [TRAINER_TUBER_AMIRA_4] =
    {
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("Amira"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TuberAmira4),
    },

    [TRAINER_TUBER_AMIRA_5] =
    {
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("Amira"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TuberAmira5),
    },
    
    [TRAINER_TWINS_ELI_ANNE] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Eli & Anne"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsEliAnne),
    },

    [TRAINER_TWINS_ELI_ANNE_2] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Eli & Anne"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsEliAnne2),
    },

    [TRAINER_TWINS_ELI_ANNE_3] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Eli & Anne"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsEliAnne3),
    },

    [TRAINER_TWINS_ELI_ANNE_4] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Eli & Anne"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsEliAnne4),
    },

    [TRAINER_TWINS_ELI_ANNE_5] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Eli & Anne"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsEliAnne5),
    },

    [TRAINER_TWINS_JOY_MEG] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Joy & Meg"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsJoyMeg),
    },

    [TRAINER_TWINS_JOY_MEG_2] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Joy & Meg"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsJoyMeg2),
    },

    [TRAINER_TWINS_JOY_MEG_3] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Joy & Meg"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsJoyMeg3),
    },

    [TRAINER_TWINS_JOY_MEG_4] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Joy & Meg"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsJoyMeg4),
    },

    [TRAINER_TWINS_JOY_MEG_5] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Joy & Meg"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsJoyMeg5),
    },

    [TRAINER_TWINS_KIRI_JAN] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Kiri & Jan"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsKiriJan),
    },

    [TRAINER_TWINS_MIU_MIA] =
    {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("Miu & Mia"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_TwinsMiuMia),
    },

    [TRAINER_YOUNG_COUPLE_EVE_JON] =
    {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("Eve & Jon"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungCoupleEveJon),
    },
    
    [TRAINER_YOUNG_COUPLE_GIA_JES] =
    {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("Gia & Jes"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungCoupleGiaJes),
    },

    [TRAINER_YOUNG_COUPLE_GIA_JES_2] =
    {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("Gia & Jes"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungCoupleGiaJes2),
    },

    [TRAINER_YOUNG_COUPLE_GIA_JES_3] =
    {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("Gia & Jes"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungCoupleGiaJes3),
    },

    [TRAINER_YOUNG_COUPLE_GIA_JES_4] =
    {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("Gia & Jes"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungCoupleGiaJes4),
    },

    [TRAINER_YOUNG_COUPLE_GIA_JES_5] =
    {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("Gia & Jes"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungCoupleGiaJes5),
    },
    
    [TRAINER_YOUNG_COUPLE_LEA_JED] =
    {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("Lea & Jed"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungCoupleLeaJed),
    },

    [TRAINER_YOUNGSTER_ALLEN] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Allen"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterAllen),
    },
    
    [TRAINER_YOUNGSTER_BEN] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Ben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterBen),
    },

    [TRAINER_YOUNGSTER_BEN_2] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Ben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterBen2),
    },

    [TRAINER_YOUNGSTER_BEN_3] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Ben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterBen3),
    },

    [TRAINER_YOUNGSTER_BEN_4] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Ben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterBen4),
    },

    [TRAINER_YOUNGSTER_BEN_5] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Ben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterBen5),
    },
    
    [TRAINER_YOUNGSTER_CALVIN] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Calvin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterCalvin),
    },
    
    [TRAINER_YOUNGSTER_CHAD] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Chad"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterChad),
    },

    [TRAINER_YOUNGSTER_CHAD_2] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Chad"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterChad2),
    },

    [TRAINER_YOUNGSTER_CHAD_3] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Chad"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterChad3),
    },

    [TRAINER_YOUNGSTER_CHAD_4] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Chad"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterChad4),
    },

    [TRAINER_YOUNGSTER_CHAD_5] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Chad"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterChad5),
    },
    
    [TRAINER_YOUNGSTER_CORDELL] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Cordell"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterCordell),
    },
    
    [TRAINER_YOUNGSTER_DAN] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Dan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterDan),
    },
    
    [TRAINER_YOUNGSTER_DAVE] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Dave"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterDave),
    },
    
    [TRAINER_YOUNGSTER_DESTIN] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Destin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterDestin),
    },

    [TRAINER_YOUNGSTER_DESTIN_2] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Destin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterDestin2),
    },

    [TRAINER_YOUNGSTER_DESTIN_3] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Destin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterDestin3),
    },

    [TRAINER_YOUNGSTER_DESTIN_4] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Destin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterDestin4),
    },

    [TRAINER_YOUNGSTER_DESTIN_5] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Destin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterDestin5),
    },

    [TRAINER_YOUNGSTER_DILLON] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Dillon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterDillon),
    },
    
    [TRAINER_YOUNGSTER_EDDIE] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Eddie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterEddie),
    },
    
    [TRAINER_YOUNGSTER_JOEY] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Joey"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterJoey),
    },
    
    [TRAINER_YOUNGSTER_JOHNSON] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Johnson"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterJohnson),
    },
    
    [TRAINER_YOUNGSTER_JOSH] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Josh"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterJosh),
    },
    
    [TRAINER_YOUNGSTER_NASH] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Nash"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterNash),
    },
    
    [TRAINER_YOUNGSTER_TIMMY] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Timmy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterTimmy),
    },

    [TRAINER_YOUNGSTER_TIMMY_2] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Timmy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterTimmy2),
    },

    [TRAINER_YOUNGSTER_TIMMY_3] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Timmy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterTimmy3),
    },

    [TRAINER_YOUNGSTER_TIMMY_4] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Timmy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterTimmy4),
    },

    [TRAINER_YOUNGSTER_TIMMY_5] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Timmy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterTimmy5),
    },
    
    [TRAINER_YOUNGSTER_TYLER] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Tyler"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterTyler),
    },
    
    [TRAINER_YOUNGSTER_YASU] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Yasu"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterYasu),
    },

    [TRAINER_YOUNGSTER_YASU_2] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Yasu"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterYasu2),
    },

    [TRAINER_YOUNGSTER_YASU_3] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Yasu"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterYasu3),
    },

    [TRAINER_YOUNGSTER_YASU_4] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Yasu"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterYasu4),
    },

    [TRAINER_YOUNGSTER_YASU_5] =
    {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Yasu"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .party = TRAINER_PARTY(sParty_YoungsterYasu5),
    },
    
    [TRAINER_ELITE_FOUR_LORELEI] =
    {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LORELEI,
        .trainerName = _("Lorelei"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_PURPLE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_EliteFourLorelei),
    },
    
    [TRAINER_ELITE_FOUR_LORELEI_2] =
    {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LORELEI,
        .trainerName = _("Lorelei"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_PURPLE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_EliteFourLorelei2),
    },
    [TRAINER_ELITE_FOUR_BRUNO] =
    {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_BRUNO,
        .trainerName = _("Bruno"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_GREEN,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_EliteFourBruno),
    },
    
    [TRAINER_ELITE_FOUR_BRUNO_2] =
    {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_BRUNO,
        .trainerName = _("Bruno"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_GREEN,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_EliteFourBruno2),
    },

    [TRAINER_ELITE_FOUR_AGATHA] =
    {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_AGATHA,
        .trainerName = _("Agatha"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_PINK,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_EliteFourAgatha),
    },
    
    [TRAINER_ELITE_FOUR_AGATHA_2] =
    {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_AGATHA,
        .trainerName = _("Agatha"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_PINK,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_EliteFourAgatha2),
    },

    [TRAINER_ELITE_FOUR_LANCE] =
    {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LANCE,
        .trainerName = _("Lance"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_BLUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_EliteFourLance),
    },

    [TRAINER_ELITE_FOUR_LANCE_2] =
    {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LANCE,
        .trainerName = _("Lance"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_BLUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_EliteFourLance2),
    },
    
    [TRAINER_CHAMPION_FIRST_SQUIRTLE] =
    {
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_ChampionFirstSquirtle),
    },

    [TRAINER_CHAMPION_REMATCH_SQUIRTLE] =
    {
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_ChampionRematchSquirtle),
    },
    
    [TRAINER_CHAMPION_FIRST_BULBASAUR] =
    {
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_ChampionFirstBulbasaur),
    },

    [TRAINER_CHAMPION_REMATCH_BULBASAUR] =
    {
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_ChampionRematchBulbasaur),
    },

    [TRAINER_CHAMPION_FIRST_CHARMANDER] =
    {
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_ChampionFirstCharmander),
    },

    [TRAINER_CHAMPION_REMATCH_CHARMANDER] =
    {
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CHAMPION_RIVAL,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_ChampionRematchCharmander),
    },

    [TRAINER_FRONTIER_BRAIN_ANABEL] =
    {
        .trainerClass = TRAINER_CLASS_SALON_MAIDEN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
        .trainerName = _("Anabel"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_FrontierBrainAnabel),
    },

    [TRAINER_FRONTIER_BRAIN_TUCKER] =
    {
        .trainerClass = TRAINER_CLASS_DOME_ACE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_DOME_ACE_TUCKER,
        .trainerName = _("Tucker"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_FrontierBrainTucker),
    },

    [TRAINER_FRONTIER_BRAIN_SPENSER] =
    {
        .trainerClass = TRAINER_CLASS_PALACE_MAVEN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PALACE_MAVEN_SPENSER,
        .trainerName = _("Spenser"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_FrontierBrainSpenser),
    },

    [TRAINER_FRONTIER_BRAIN_GRETA] =
    {
        .trainerClass = TRAINER_CLASS_ARENA_TYCOON,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ARENA_TYCOON_GRETA,
        .trainerName = _("Greta"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_FrontierBrainGreta),
    },

    [TRAINER_FRONTIER_BRAIN_NOLAND] =
    {
        .trainerClass = TRAINER_CLASS_FACTORY_HEAD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FACTORY_HEAD_NOLAND,
        .trainerName = _("Noland"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_FrontierBrainNoland),
    },

    [TRAINER_FRONTIER_BRAIN_LUCY] =
    {
        .trainerClass = TRAINER_CLASS_PIKE_QUEEN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PIKE_QUEEN_LUCY,
        .trainerName = _("Lucy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_FrontierBrainLucy),
    },

    [TRAINER_FRONTIER_BRAIN_BRANDON] =
    {
        .trainerClass = TRAINER_CLASS_PYRAMID_KING,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PYRAMID_KING_BRANDON,
        .trainerName = _("Brandon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_FrontierBrainBrandon),
    },

    [TRAINER_STEVEN] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_STEVEN,
        .trainerName = _("Steven"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .party = TRAINER_PARTY(sParty_Steven),
    },

    [TRAINER_RED] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RED,
        .trainerName = _("Red"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .party = TRAINER_PARTY(sParty_Red),
    },

    [TRAINER_LEAF] =
    {
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEAF,
        .trainerName = _("Leaf"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .party = TRAINER_PARTY(sParty_Leaf),
    },

    [TRAINER_BRENDAN_PLACEHOLDER] =
    {
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RS_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .party = TRAINER_PARTY(sParty_BrendanLinkPlaceholder),
    },

    [TRAINER_MAY_PLACEHOLDER] =
    {
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RS_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .party = TRAINER_PARTY(sParty_MayLinkPlaceholder),
    },
};
