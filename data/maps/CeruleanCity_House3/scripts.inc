CeruleanCity_House3_MapScripts::
	.byte 0

CeruleanCity_House3_EventScript_OldWoman::
    msgbox CeruleanCity_House3_Text_PleaseTradeWithMyHusband, MSGBOX_NPC
    end

CeruleanCity_House3_EventScript_Dontae::
    lock
    faceplayer
    setvar VAR_0x8008, INGAME_TRADE_JYNX
    call EventScript_GetInGameTradeSpeciesInfo
    goto_if_set FLAG_DID_ZYNX_TRADE, CeruleanCity_House3_EventScript_AlreadyTraded
    msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq CeruleanCity_House3_EventScript_DeclineTrade
    call EventScript_ChooseMonForInGameTrade
    compare VAR_0x8004, PARTY_SIZE
    goto_if_ge CeruleanCity_House3_EventScript_DeclineTrade
    call EventScript_GetInGameTradeSpecies
    compare VAR_RESULT, VAR_0x8009
    goto_if_ne CeruleanCity_House3_EventScript_NotRequestedMon
    call EventScript_DoInGameTrade
    msgbox Trade_Text_HeyThanks, MSGBOX_DEFAULT
    setflag FLAG_DID_ZYNX_TRADE
    release
    end

CeruleanCity_House3_EventScript_DeclineTrade::
    msgbox Trade_Text_AwwOhWell, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House3_EventScript_NotRequestedMon::
    bufferspeciesname 0, VAR_0x8009
    msgbox Trade_Text_WhatThatsNoMon, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House3_EventScript_AlreadyTraded::
    msgbox Trade_Text_IsntMyOldMonGreat, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House3_Text_PleaseTradeWithMyHusband::
    .string "My husband likes trading Pokémon.\p"
    .string "You're collecting Pokémon for your\n"
    .string "Pokédex, aren't you?\p"
    .string "Would you please trade with him?$"
