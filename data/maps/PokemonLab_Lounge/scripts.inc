PokemonLab_Lounge_MapScripts::
	.byte 0

PokemonLab_Lounge_EventScript_Scientist::
    msgbox PokemonLab_Lounge_Text_FoundFossilInMtMoon, MSGBOX_NPC
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
    .string "I think it's of a rare, prehistoric\n"
    .string "Pokémon.$"
