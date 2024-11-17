PokemonLab_Lounge_MapScripts::
	.byte 0

PokemonLab_Lounge_EventScript_Scientist::
    lock
    faceplayer
    goto_if_set FLAG_GOT_FOSSIL_POKEMON, PokemonLab_Lounge_EventScript_AlreadyGotFossilPokemon
    msgbox PokemonLab_Lounge_Text_FoundFossilInMtMoon, MSGBOX_DEFAULT
    call_if_set FLAG_GOT_DOME_FOSSIL, PokemonLab_Lounge_EventScript_GiveOmanyte
    call_if_unset FLAG_GOT_DOME_FOSSIL, PokemonLab_Lounge_EventScript_GiveKabuto
    compare VAR_RESULT, 0
    goto_if_eq PokemonLab_Lounge_EventScript_ReceiveFossilPokemonParty
    compare VAR_RESULT, 1
    goto_if_eq PokemonLab_Lounge_EventScript_ReceiveFossilPokemonPC
    compare VAR_RESULT, 2
    goto_if_eq Common_EventScript_NoMoreRoomForPokemon
    release
    end

PokemonLab_Lounge_EventScript_GiveOmanyte::
    setvar VAR_TEMP_1, SPECIES_OMANYTE
    givemon SPECIES_OMANYTE, 5, ITEM_NONE
    return

PokemonLab_Lounge_EventScript_GiveKabuto::
    setvar VAR_TEMP_1, SPECIES_KABUTO
    givemon SPECIES_KABUTO, 5, ITEM_NONE
    return

PokemonLab_Lounge_EventScript_ReceiveFossilPokemonParty::
    playfanfare MUS_LEVEL_UP
    call_if_set FLAG_GOT_DOME_FOSSIL, PokemonLab_Lounge_EventScript_ObtainedOmanyteFromScientist
    call_if_unset FLAG_GOT_DOME_FOSSIL, PokemonLab_Lounge_EventScript_ObtainedKabutoFromScientist
    waitfanfare
    bufferspeciesname 0, VAR_TEMP_1
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq PokemonLab_Lounge_EventScript_EndReceiveFossilPokemon
    call Common_EventScript_GetGiftMonPartySlot
    call Common_EventScript_NameReceivedPartyMon
    goto SilphCo_7F_EventScript_EndReceiveLapras
    end

PokemonLab_Lounge_EventScript_ObtainedOmanyteFromScientist::
    message PokemonLab_Lounge_Text_ObtainedOmanyteFromScientist
    waitmessage
    return

PokemonLab_Lounge_EventScript_ObtainedKabutoFromScientist::
    message PokemonLab_Lounge_Text_ObtainedKabutoFromScientist
    waitmessage
    return

PokemonLab_Lounge_EventScript_ReceiveFossilPokemonPC::
    playfanfare MUS_LEVEL_UP
    call_if_set FLAG_GOT_DOME_FOSSIL, PokemonLab_Lounge_EventScript_ObtainedOmanyteFromScientist
    call_if_unset FLAG_GOT_DOME_FOSSIL, PokemonLab_Lounge_EventScript_ObtainedKabutoFromScientist
    waitfanfare
    bufferspeciesname 0, VAR_TEMP_1
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq PokemonLab_Lounge_EventScript_FossilPokemonTransferredToPC
    call Common_EventScript_NameReceivedBoxMon
    goto PokemonLab_Lounge_EventScript_FossilPokemonTransferredToPC
    end

PokemonLab_Lounge_EventScript_FossilPokemonTransferredToPC::
    call Common_EventScript_TransferredToPC
    goto PokemonLab_Lounge_EventScript_EndReceiveFossilPokemon
    end

PokemonLab_Lounge_EventScript_EndReceiveFossilPokemon::
    call_if_set FLAG_GOT_DOME_FOSSIL, PokemonLab_Lounge_EventScript_ExplainOmanyte
    call_if_unset FLAG_GOT_DOME_FOSSIL, PokemonLab_Lounge_EventScript_ExplainKabuto
    setflag FLAG_GOT_FOSSIL_POKEMON
    release
    end

PokemonLab_Lounge_EventScript_ExplainOmanyte::
    msgbox PokemonLab_Lounge_Text_ExplainOmanyte, MSGBOX_DEFAULT
    return

PokemonLab_Lounge_EventScript_ExplainKabuto::
    msgbox PokemonLab_Lounge_Text_ExplainKabuto, MSGBOX_DEFAULT
    return

PokemonLab_Lounge_EventScript_AlreadyGotFossilPokemon::
    msgbox PokemonLab_Lounge_Text_FossilsInOtherLands, MSGBOX_DEFAULT
    release
    end

PokemonLab_Lounge_EventScript_Clifton::
    lock
    faceplayer
    setvar VAR_0x8008, INGAME_TRADE_ELECTRODE
    call EventScript_GetInGameTradeSpeciesInfo
    goto_if_set FLAG_DID_ESPHERE_TRADE, PokemonLab_Lounge_EventScript_CliftonAlreadyTraded
    msgbox Trade_Text_DoYouHaveMonWouldYouTradeForMon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq PokemonLab_Lounge_EventScript_CliftonDeclineTrade
    call EventScript_ChooseMonForInGameTrade
    compare VAR_0x8004, PARTY_SIZE
    goto_if_ge PokemonLab_Lounge_EventScript_CliftonDeclineTrade
    call EventScript_GetInGameTradeSpecies
    compare VAR_RESULT, VAR_0x8009
    goto_if_ne PokemonLab_Lounge_EventScript_CliftonNotRequestedMon
    call EventScript_DoInGameTrade
    msgbox Trade_Text_HeyThanks, MSGBOX_DEFAULT
    setflag FLAG_DID_ESPHERE_TRADE
    release
    end

PokemonLab_Lounge_EventScript_CliftonDeclineTrade::
    msgbox Trade_Text_AwwOhWell, MSGBOX_DEFAULT
    release
    end

PokemonLab_Lounge_EventScript_CliftonNotRequestedMon::
    bufferspeciesname 0, VAR_0x8009
    msgbox Trade_Text_WhatThatsNoMon, MSGBOX_DEFAULT
    release
    end

PokemonLab_Lounge_EventScript_CliftonAlreadyTraded::
    msgbox Trade_Text_IsntMyOldMonGreat, MSGBOX_DEFAULT
    release
    end

PokemonLab_Lounge_EventScript_Norma::
    lock
    faceplayer
    setvar VAR_0x8008, INGAME_TRADE_TANGELA
    call EventScript_GetInGameTradeSpeciesInfo
    goto_if_set FLAG_DID_TANGENY_TRADE, PokemonLab_Lounge_EventScript_NormaAlreadyTraded
    msgbox Trade_Text_DoYouHaveMonWantToTradeForMon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq PokemonLab_Lounge_EventScript_NormaDeclineTrade
    call EventScript_ChooseMonForInGameTrade
    compare VAR_0x8004, PARTY_SIZE
    goto_if_ge PokemonLab_Lounge_EventScript_NormaDeclineTrade
    call EventScript_GetInGameTradeSpecies
    compare VAR_RESULT, VAR_0x8009
    goto_if_ne PokemonLab_Lounge_EventScript_NormaNotRequestedMon
    call EventScript_DoInGameTrade
    msgbox Trade_Text_HeyThanks, MSGBOX_DEFAULT
    setflag FLAG_DID_TANGENY_TRADE
    release
    end

PokemonLab_Lounge_EventScript_NormaDeclineTrade::
    msgbox Trade_Text_AwwOhWell, MSGBOX_DEFAULT
    release
    end

PokemonLab_Lounge_EventScript_NormaNotRequestedMon::
    bufferspeciesname 0, VAR_0x8009
    msgbox Trade_Text_WhatThatsNoMon, MSGBOX_DEFAULT
    release
    end

PokemonLab_Lounge_EventScript_NormaAlreadyTraded::
    msgbox Trade_Text_IsntMyOldMonGreat, MSGBOX_DEFAULT
    release
    end

PokemonLab_Lounge_Text_FoundFossilInMtMoon::
    .string "I found this most remarkable fossil\n"
    .string "inside Mt. Moon.\p"
    .string "I thought it would be a powerful,\n"
    .string "prehistoric Pokémon, but it was\l"
    .string "only a weak crustacean.\p"
    .string "Here, why don't you take\n"
    .string "this Pokemon?$"

PokemonLab_Lounge_Text_ObtainedOmanyteFromScientist::
    .string "{PLAYER} obtained an Omanyte\n"
    .string "from the Scientist!$"

PokemonLab_Lounge_Text_ObtainedKabutoFromScientist::
    .string "{PLAYER} obtained a Kabuto\n"
    .string "from the Scientist!$"

PokemonLab_Lounge_Text_ExplainOmanyte::
    .string "That Pokémon is called Omanyte.\n"
    .string "A Trainer like you may have a\l"
    .string "use for it.$"

PokemonLab_Lounge_Text_ExplainKabuto::
    .string "That Pokémon is called Kabuto.\n"
    .string "A Trainer like you may have a\l"
    .string "use for it.$"

PokemonLab_Lounge_Text_FossilsInOtherLands::
    .string "I've heard tales of ancient, powerful\n"
    .string "Pokémon from distant regions.\p"
    .string "I'm going to travel to these lands\n"
    .string "to dig for fossils.\p"
    .string "Hopefully, I can uncover one\n"
    .string "of these Pokémon!$"
