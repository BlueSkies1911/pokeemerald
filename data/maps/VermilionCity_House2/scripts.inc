VermilionCity_House2_MapScripts::
	.byte 0

VermilionCity_House2_EventScript_Elyssa::
    lock
    faceplayer
    setvar VAR_0x8008, INGAME_TRADE_FARFETCHD
    call EventScript_GetInGameTradeSpeciesInfo
    goto_if_set FLAG_DID_CH_DING_TRADE, VermilionCity_House2_EventScript_AlreadyTraded
    msgbox VermilionCity_House2_Text_DoYouHaveMonWantToTradeForMyMon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq VermilionCity_House2_EventScript_DeclineTrade
    call EventScript_ChooseMonForInGameTrade
    compare VAR_0x8004, PARTY_SIZE
    goto_if_ge VermilionCity_House2_EventScript_DeclineTrade
    call EventScript_GetInGameTradeSpecies
    compare VAR_RESULT, VAR_0x8009
    goto_if_ne VermilionCity_House2_EventScript_NotRequestedMon
    call EventScript_DoInGameTrade
    msgbox Trade_Text_HeyThanks, MSGBOX_DEFAULT
    setflag FLAG_DID_CH_DING_TRADE
    release
    end

VermilionCity_House2_EventScript_DeclineTrade::
    msgbox Trade_Text_AwwOhWell, MSGBOX_DEFAULT
    release
    end

VermilionCity_House2_EventScript_NotRequestedMon::
    bufferspeciesname 0, VAR_0x8009
    msgbox Trade_Text_WhatThatsNoMon, MSGBOX_DEFAULT
    release
    end

VermilionCity_House2_EventScript_AlreadyTraded::
    msgbox Trade_Text_IsntMyOldMonGreat, MSGBOX_DEFAULT
    release
    end

VermilionCity_House2_Text_DoYouHaveMonWantToTradeForMyMon::
    .string "Hi!\n"
    .string "Do you have a {STR_VAR_1}?\p"
    .string "Want to trade it for my\n"
    .string "{STR_VAR_2}?$"
