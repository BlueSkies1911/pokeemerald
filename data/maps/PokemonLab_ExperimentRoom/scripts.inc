.equ HELIX_FOSSIL, 1
.equ DOME_FOSSIL,  2
.equ OLD_AMBER,    3

PokemonLab_ExperimentRoom_MapScripts::
	.byte 0

PokemonLab_ExperimentRoom_EventScript_Garett::
    lock
    faceplayer
    setvar VAR_0x8008, INGAME_TRADE_SEEL
    call EventScript_GetInGameTradeSpeciesInfo
    goto_if_set FLAG_DID_SEELOR_TRADE, PokemonLab_ExperimentRoom_EventScript_AlreadyTraded
    msgbox Trade_Text_DoYouHaveMonWouldYouTradeForMon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_DeclineTrade
    call EventScript_ChooseMonForInGameTrade
    compare VAR_0x8004, PARTY_SIZE
    goto_if_ge PokemonLab_ExperimentRoom_EventScript_DeclineTrade
    call EventScript_GetInGameTradeSpecies
    compare VAR_RESULT, VAR_0x8009
    goto_if_ne PokemonLab_ExperimentRoom_EventScript_NotRequestedMon
    call EventScript_DoInGameTrade
    msgbox Trade_Text_HeyThanks, MSGBOX_DEFAULT
    setflag FLAG_DID_SEELOR_TRADE
    release
    end

PokemonLab_ExperimentRoom_EventScript_DeclineTrade::
    msgbox Trade_Text_AwwOhWell, MSGBOX_DEFAULT
    release
    end

PokemonLab_ExperimentRoom_EventScript_NotRequestedMon::
    bufferspeciesname 0, VAR_0x8009
    msgbox Trade_Text_WhatThatsNoMon, MSGBOX_DEFAULT
    release
    end

PokemonLab_ExperimentRoom_EventScript_AlreadyTraded::
    msgbox Trade_Text_IsntMyOldMonGreat, MSGBOX_DEFAULT
    release
    end

PokemonLab_ExperimentRoom_EventScript_FossilScientist::
    lock
    faceplayer
    setvar VAR_RESULT, FALSE
    call_if_set FLAG_REVIVED_AMBER, PokemonLab_ExperimentRoom_EventScript_CheckRevivedMtMoonFossil
    compare VAR_RESULT, TRUE
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_RevivedAllFossils
    compare VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_GiveRevivedMon
    compare VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_FossilStillReviving
    call PokemonLab_ExperimentRoom_EventScript_CheckAddHelixFossilToList
    compare VAR_RESULT, TRUE
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelix
    call PokemonLab_ExperimentRoom_EventScript_CheckAddDomeFossilToList
    compare VAR_RESULT, TRUE
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_ChooseFossilDome
    call PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
    compare VAR_RESULT, TRUE
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_ChooseFossilAmber
    msgbox PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe, MSGBOX_DEFAULT
    goto PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    end

PokemonLab_ExperimentRoom_EventScript_CheckAddHelixFossilToList::
    goto_if_unset FLAG_GOT_HELIX_FOSSIL, PokemonLab_ExperimentRoom_EventScript_SetResultFalse
    goto_if_set FLAG_REVIVED_HELIX, PokemonLab_ExperimentRoom_EventScript_SetResultFalse
    setvar VAR_RESULT, TRUE
    return

PokemonLab_ExperimentRoom_EventScript_CheckAddDomeFossilToList::
    goto_if_unset FLAG_GOT_DOME_FOSSIL, PokemonLab_ExperimentRoom_EventScript_SetResultFalse
    goto_if_set FLAG_REVIVED_DOME, PokemonLab_ExperimentRoom_EventScript_SetResultFalse
    setvar VAR_RESULT, TRUE
    return

PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList::
    goto_if_unset FLAG_GOT_OLD_AMBER, PokemonLab_ExperimentRoom_EventScript_SetResultFalse
    goto_if_set FLAG_REVIVED_AMBER, PokemonLab_ExperimentRoom_EventScript_SetResultFalse
    setvar VAR_RESULT, TRUE
    return

PokemonLab_ExperimentRoom_EventScript_SetResultFalse::
    setvar VAR_RESULT, FALSE
    return

PokemonLab_ExperimentRoom_EventScript_DontShowFossil::
    msgbox PokemonLab_ExperimentRoom_Text_NoIsTooBad, MSGBOX_DEFAULT
    release
    end

PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelix::
    message PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
    waitmessage
    call PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
    compare VAR_RESULT, TRUE
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelixAmber
    multichoice 0, 0, MULTI_HELIX, FALSE
    switch VAR_RESULT
    case 0, PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
    case 1, PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    case 127, PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    end

PokemonLab_ExperimentRoom_EventScript_ChooseFossilDome::
    message PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
    waitmessage
    call PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
    compare VAR_RESULT, TRUE
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_ChooseFossilDomeAmber
    multichoice 0, 0, MULTI_DOME, FALSE
    switch VAR_RESULT
    case 0, PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
    case 1, PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    case 127, PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    end

PokemonLab_ExperimentRoom_EventScript_ChooseFossilAmber::
    message PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
    waitmessage
    multichoice 0, 0, MULTI_AMBER, FALSE
    switch VAR_RESULT
    case 0, PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
    case 1, PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    case 127, PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    end

PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelixAmber::
    multichoice 0, 0, MULTI_HELIX_AMBER, FALSE
    switch VAR_RESULT
    case 0, PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
    case 1, PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
    case 2, PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    case 127, PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    end

PokemonLab_ExperimentRoom_EventScript_ChooseFossilDomeAmber::
    multichoice 0, 0, MULTI_DOME_AMBER, FALSE
    switch VAR_RESULT
    case 0, PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
    case 1, PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
    case 2, PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    case 127, PokemonLab_ExperimentRoom_EventScript_DontShowFossil
    end

PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil::
    bufferspeciesname 0, SPECIES_OMANYTE
    bufferitemname 1, ITEM_HELIX_FOSSIL
    msgbox PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
    msgbox PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
    removeitem ITEM_HELIX_FOSSIL
    msgbox PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
    setvar VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL
    release
    end

PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil::
    bufferspeciesname 0, SPECIES_KABUTO
    bufferitemname 1, ITEM_DOME_FOSSIL
    msgbox PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
    msgbox PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor, MSGBOX_DEFAULT
    removeitem ITEM_DOME_FOSSIL
    msgbox PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
    setvar VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL
    release
    end

PokemonLab_ExperimentRoom_EventScript_ShowOldAmber::
    bufferspeciesname 0, SPECIES_AERODACTYL
    bufferitemname 1, ITEM_OLD_AMBER
    msgbox PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
    msgbox PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor, MSGBOX_DEFAULT
    removeitem ITEM_OLD_AMBER
    msgbox PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
    setvar VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER
    release
    end

PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil::
    msgbox PokemonLab_ExperimentRoom_Text_YouComeAgain, MSGBOX_DEFAULT
    release
    end

PokemonLab_ExperimentRoom_EventScript_FossilStillReviving::
    msgbox PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk, MSGBOX_DEFAULT
    release
    end

PokemonLab_ExperimentRoom_EventScript_GiveRevivedMon::
    compare VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_GiveOmanyte
    compare VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_GiveKabuto
    compare VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_GiveAerodactyl
    end

PokemonLab_ExperimentRoom_EventScript_GiveOmanyte::
    setvar VAR_TEMP_1, SPECIES_OMANYTE
    bufferspeciesname 0, SPECIES_OMANYTE
    msgbox PokemonLab_ExperimentRoom_Text_FossilMonBackToLife, MSGBOX_DEFAULT
    givemon SPECIES_OMANYTE, 5, ITEM_NONE
    compare VAR_RESULT, 2
    goto_if_eq Common_EventScript_NoMoreRoomForPokemon
    setflag FLAG_REVIVED_HELIX
    compare VAR_RESULT, 0
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
    compare VAR_RESULT, 1
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
    end

PokemonLab_ExperimentRoom_EventScript_GiveKabuto::
    setvar VAR_TEMP_1, SPECIES_KABUTO
    bufferspeciesname 0, SPECIES_KABUTO
    msgbox PokemonLab_ExperimentRoom_Text_FossilMonBackToLife, MSGBOX_DEFAULT
    givemon SPECIES_KABUTO, 5, ITEM_NONE
    compare VAR_RESULT, 2
    goto_if_eq Common_EventScript_NoMoreRoomForPokemon
    setflag FLAG_REVIVED_DOME
    compare VAR_RESULT, 0
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
    compare VAR_RESULT, 1
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
    end

PokemonLab_ExperimentRoom_EventScript_GiveAerodactyl::
    setvar VAR_TEMP_1, SPECIES_AERODACTYL
    bufferspeciesname 0, SPECIES_AERODACTYL
    msgbox PokemonLab_ExperimentRoom_Text_FossilMonBackToLife, MSGBOX_DEFAULT
    givemon SPECIES_AERODACTYL, 5, ITEM_NONE
    compare VAR_RESULT, 2
    goto_if_eq Common_EventScript_NoMoreRoomForPokemon
    setflag FLAG_REVIVED_AMBER
    compare VAR_RESULT, 0
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
    compare VAR_RESULT, 1
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
    end

PokemonLab_ExperimentRoom_EventScript_NicknameMonParty::
    playfanfare MUS_LEVEL_UP
    message PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor
    waitmessage
    waitfanfare
    setvar VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_EndGiveMon
    call Common_EventScript_GetGiftMonPartySlot
    call Common_EventScript_NameReceivedPartyMon
    goto PokemonLab_ExperimentRoom_EventScript_EndGiveMon
    end

PokemonLab_ExperimentRoom_EventScript_NicknameMonPC::
    playfanfare MUS_LEVEL_UP
    message PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor
    waitmessage
    waitfanfare
    setvar VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq PokemonLab_ExperimentRoom_EventScript_MonSentToPC
    call Common_EventScript_NameReceivedBoxMon
    goto PokemonLab_ExperimentRoom_EventScript_MonSentToPC
    end

PokemonLab_ExperimentRoom_EventScript_MonSentToPC::
    call Common_EventScript_TransferredToPC
    goto PokemonLab_ExperimentRoom_EventScript_EndGiveMon
    end

PokemonLab_ExperimentRoom_EventScript_EndGiveMon::
    release
    end

PokemonLab_ExperimentRoom_EventScript_RevivedAllFossils::
    msgbox PokemonLab_ExperimentRoom_Text_YouComeAgain, MSGBOX_DEFAULT
    release
    end

PokemonLab_ExperimentRoom_EventScript_CheckRevivedMtMoonFossil::
    goto_if_set FLAG_GOT_HELIX_FOSSIL, PokemonLab_ExperimentRoom_EventScript_CheckRevivedHelix
    goto_if_set FLAG_GOT_DOME_FOSSIL, PokemonLab_ExperimentRoom_EventScript_CheckRevivedDome
    goto PokemonLab_ExperimentRoom_EventScript_SetResultFalse
    end

PokemonLab_ExperimentRoom_EventScript_CheckRevivedHelix::
    goto_if_unset FLAG_REVIVED_HELIX, PokemonLab_ExperimentRoom_EventScript_SetResultFalse
    setvar VAR_RESULT, TRUE
    return

PokemonLab_ExperimentRoom_EventScript_CheckRevivedDome::
    goto_if_unset FLAG_REVIVED_DOME, PokemonLab_ExperimentRoom_EventScript_SetResultFalse
    setvar VAR_RESULT, TRUE
    return

PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe::
    .string "Hiya!\p"
    .string "I am important doctor.\n"
    .string "Yes, very much so, indeed.\p"
    .string "Here, I study rare Pokémon fossils.\n"
    .string "All the time, I study.\p"
    .string "You!\n"
    .string "Have you a fossil for me?$"

PokemonLab_ExperimentRoom_Text_NoIsTooBad::
    .string "No!\n"
    .string "Is too bad!$"

PokemonLab_ExperimentRoom_Text_FossilMonBackToLife::
    .string "You late.\n"
    .string "Where were you?\p"
    .string "Your fossil is back to life!\n"
    .string "It was {STR_VAR_1} like I think!$"

PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor::
    .string "{PLAYER} received the {STR_VAR_1}\n"
    .string "from the doctor.$"

PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain::
    .string "Oh!\n"
    .string "That is {STR_VAR_2}, it is!\p"
    .string "It is fossil of {STR_VAR_1},\n"
    .string "a Pokémon that is already extinct!\p"
    .string "My Resurrection Machine will make\n"
    .string "that Pokémon live again!$"

PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor::
    .string "So!\n"
    .string "You hurry and give me that!\p"
    .string "{PLAYER} handed over the\n"
    .string "{STR_VAR_2} to the weird doctor.$"

PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk::
    .string "I take a little time!\n"
    .string "You go for walk a little while!$"

PokemonLab_ExperimentRoom_Text_YouComeAgain::
    .string "Aiyah!\n"
    .string "You come again!$"
