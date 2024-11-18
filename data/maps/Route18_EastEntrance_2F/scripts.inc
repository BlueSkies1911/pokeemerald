Route18_EastEntrance_2F_MapScripts::
	.byte 0

Route18_EastEntrance_2F_EventScript_Haden:: @ 817047E
    lock
    faceplayer
    setvar VAR_0x8008, INGAME_TRADE_LICKITUNG
    call EventScript_GetInGameTradeSpeciesInfo
    goto_if_set FLAG_DID_MARC_TRADE, Route18_EastEntrance_2F_EventScript_AlreadyTraded
    msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Route18_EastEntrance_2F_EventScript_DeclineTrade
    call EventScript_ChooseMonForInGameTrade
    compare VAR_0x8004, PARTY_SIZE
    goto_if_ge Route18_EastEntrance_2F_EventScript_DeclineTrade
    call EventScript_GetInGameTradeSpecies
    compare VAR_RESULT, VAR_0x8009
    goto_if_ne Route18_EastEntrance_2F_EventScript_NotRequestedMon
    call EventScript_DoInGameTrade
    msgbox Trade_Text_HeyThanks, MSGBOX_DEFAULT
    setflag FLAG_DID_MARC_TRADE
    release
    end

Route18_EastEntrance_2F_EventScript_AlreadyTraded::
    msgbox Trade_Text_IsntMyOldMonGreat, MSGBOX_DEFAULT
    release
    end

Route18_EastEntrance_2F_EventScript_DeclineTrade::
    msgbox Trade_Text_AwwOhWell, MSGBOX_DEFAULT
    release
    end

Route18_EastEntrance_2F_EventScript_NotRequestedMon::
    bufferspeciesname 0, VAR_0x8009
    msgbox Trade_Text_WhatThatsNoMon, MSGBOX_DEFAULT
    release
    end

Route18_EastEntrance_2F_EventScript_LeftBinoculars::
    msgbox Route18_EastEntrance_2F_Text_PalletTownInWest, MSGBOX_SIGN
    end

Route18_EastEntrance_2F_EventScript_RightBinoculars::
    msgbox Route18_EastEntrance_2F_Text_PeopleSwimming, MSGBOX_SIGN
    end

Route18_EastEntrance_2F_Text_PalletTownInWest::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "Pallet Town is in the west.$"

Route18_EastEntrance_2F_Text_PeopleSwimming::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "There are people swimming.$"