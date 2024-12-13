CeladonCity_Condominiums_1F_MapScripts::
	.byte 0

CeladonCity_Condominiums_1F_EventScript_TeaWoman::
    lock
    faceplayer
    goto_if_set FLAG_TALKED_TO_TEA_LADY_AFTER_HOF, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
    goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy
    goto_if_set FLAG_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
    msgbox CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead, MSGBOX_DEFAULT
    setflag FLAG_GOT_TEA
    giveitem ITEM_TEA
    compare VAR_RESULT, FALSE
    goto_if_eq Common_EventScript_BagIsFull
    msgbox CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea, MSGBOX_DEFAULT
    release
    end

CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea::
    msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany, MSGBOX_DEFAULT
    release
    end

CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy::
    setflag FLAG_TALKED_TO_TEA_LADY_AFTER_HOF
    msgbox CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea, MSGBOX_DEFAULT
    release
    end

CeladonCity_Condominiums_1F_EventScript_Meowth::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_MEOWTH, 0
    msgbox CeladonCity_Condominiums_1F_Text_Meowth, MSGBOX_DEFAULT
    waitmoncry
    release
    end

CeladonCity_Condominiums_1F_EventScript_Clefairy::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_CLEFAIRY, 0
    msgbox CeladonCity_Condominiums_1F_Text_Clefairy, MSGBOX_DEFAULT
    waitmoncry
    release
    end

CeladonCity_Condominiums_1F_EventScript_Nidoran::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_NIDORAN_F, 0
    msgbox CeladonCity_Condominiums_1F_Text_Nidoran, MSGBOX_DEFAULT
    waitmoncry
    release
    end

CeladonCity_Condominiums_1F_EventScript_SuiteSign::
    msgbox CeladonCity_Condominiums_1F_Text_ManagersSuite, MSGBOX_SIGN
    end

CeladonCity_Condominiums_1F_Text_Meowth::
    .string "Meowth: Meow!$"

CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead::
    .string "You shouldn't spend all your money\n"
    .string "on drinks.\p"
    .string "Try this instead.$"

CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea::
    .string "Nothing beats thirst like some hot\n"
    .string "Tea.\p"
    .string "It really is the best.$"

CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany::
    .string "My dear Pokémon keep me company.\n"
    .string "Meowth even brings money home!$"

CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea::
    .string "Oh, hello, dearie.\n"
    .string "Did you enjoy my Tea?\p"
    .string "By the way, dear. Are you, by any\n"
    .string "chance, from Pallet Town?\p"
    .string "A girl from Pallet Town, Daisy,\n"
    .string "she enjoys Tea every day.\p"
    .string "She visits the Celadon Dept. Store\n"
    .string "to buy some Tea.$"

CeladonCity_Condominiums_1F_Text_Clefairy::
    .string "Clefairy: Pi pippippi!$"

CeladonCity_Condominiums_1F_Text_Nidoran::
    .string "Nidoran♀: Kya kyaoo!$"

CeladonCity_Condominiums_1F_Text_ManagersSuite::
    .string "Celadon Mansion\n"
    .string "Manager's Suite$"
