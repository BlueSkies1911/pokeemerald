.equ REQUIRED_CAUGHT_MONS, 30

Route11_EastEntrance_2F_MapScripts::
    .byte 0

Route11_EastEntrance_2F_EventScript_Turner::
    lock
    faceplayer
    setvar VAR_0x8008, INGAME_TRADE_NIDORINA
    call EventScript_GetInGameTradeSpeciesInfo
    goto_if_set FLAG_DID_NINA_TRADE, Route11_EastEntrance_2F_EventScript_AlreadyTraded
    msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Route11_EastEntrance_2F_EventScript_DeclineTrade
    call EventScript_ChooseMonForInGameTrade
    compare VAR_0x8004, PARTY_SIZE
    goto_if_ge Route11_EastEntrance_2F_EventScript_DeclineTrade
    call EventScript_GetInGameTradeSpecies
    compare VAR_RESULT, VAR_0x8009
    goto_if_ne Route11_EastEntrance_2F_EventScript_NotRequestedMon
    call EventScript_DoInGameTrade
    msgbox Trade_Text_HeyThanks, MSGBOX_DEFAULT
    setflag FLAG_DID_NINA_TRADE
    release
    end

Route11_EastEntrance_2F_EventScript_AlreadyTraded::
    msgbox Trade_Text_IsntMyOldMonGreat, MSGBOX_DEFAULT
    release
    end

Route11_EastEntrance_2F_EventScript_DeclineTrade::
    msgbox Trade_Text_AwwOhWell, MSGBOX_DEFAULT
    release
    end

Route11_EastEntrance_2F_EventScript_NotRequestedMon::
    bufferspeciesname 0, VAR_0x8009
    msgbox Trade_Text_WhatThatsNoMon, MSGBOX_DEFAULT
    release
    end

Route11_EastEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    call Route11_EastEntrance_2F_EventScript_GetAideRequestInfo
    goto_if_set FLAG_GOT_ITEMFINDER, Route11_EastEntrance_2F_EventScript_AlreadyGotItemfinder
    msgbox Route11_EastEntrance_2F_Text_GiveItemfinderIfCaught30, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Aide_EventScript_DeclineCheckMons
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, ScriptGetPokedexInfo
    buffernumberstring 2, VAR_0x8006
    call Route11_EastEntrance_2F_EventScript_GetAideRequestInfo
    compare VAR_0x8006, REQUIRED_CAUGHT_MONS
    goto_if_lt Aide_EventScript_HaventCaughtEnough
    msgbox Route11_EastEntrance_2F_Text_GreatHereYouGo, MSGBOX_DEFAULT
    checkitemspace ITEM_DOWSING_MACHINE, 1
    compare VAR_RESULT, FALSE
    goto_if_eq Aide_EventScript_NoRoomForItem
    giveitem_msg Route11_EastEntrance_2F_Text_ReceivedItemfinderFromAide, ITEM_DOWSING_MACHINE
    setflag FLAG_GOT_ITEMFINDER
    msgbox Route11_EastEntrance_2F_Text_ExplainItemfinder, MSGBOX_DEFAULT
    release
    end

Route11_EastEntrance_2F_EventScript_GetAideRequestInfo::
    buffernumberstring 0, REQUIRED_CAUGHT_MONS
    bufferitemname 1, ITEM_DOWSING_MACHINE
    return

Route11_EastEntrance_2F_EventScript_AlreadyGotItemfinder::
    msgbox Route11_EastEntrance_2F_Text_ExplainItemfinder, MSGBOX_DEFAULT
    release
    end

Route11_EastEntrance_2F_EventScript_LeftBinoculars::
    lockall
    goto_if_set FLAG_WOKE_UP_ROUTE_12_SNORLAX, Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone
    msgbox Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad, MSGBOX_DEFAULT
    releaseall
    end

Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone::
    msgbox Route11_EastEntrance_2F_Text_WhatABreathtakingView, MSGBOX_DEFAULT
    releaseall
    end

Route11_EastEntrance_2F_EventScript_RightBinoculars::
    msgbox Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender, MSGBOX_SIGN
    end

Route11_EastEntrance_2F_Text_GiveItemfinderIfCaught30::
    .string "Hi! Remember me?\n"
    .string "I'm one of Prof. Oak's Aides.\p"
    .string "If your Pokédex has complete data\n"
    .string "on {STR_VAR_1} species, I'm supposed to\l"
    .string "give you a reward.\p"
    .string "Prof. Oak entrusted me with the\n"
    .string "{STR_VAR_2} for you.\p"
    .string "So, {PLAYER}, let me ask you.\p"
    .string "Have you gathered data on at least\n"
    .string "{STR_VAR_1} kinds of Pokémon?$"

Route11_EastEntrance_2F_Text_GreatHereYouGo::
    .string "Great! You have caught or owned\n"
    .string "{STR_VAR_3} kinds of Pokémon!\p"
    .string "Congratulations!\n"
    .string "Here you go!$"

Route11_EastEntrance_2F_Text_ReceivedItemfinderFromAide::
    .string "{PLAYER} received the {STR_VAR_2}\n"
    .string "from the Aide.$"

Route11_EastEntrance_2F_Text_ExplainItemfinder::
    .string "There are items on the ground that\n"
    .string "may be hidden from view.\p"
    .string "Use the Dowsing MCHN to detect any\n"
    .string "hidden items close to you.\p"
    .string "The machine is a bit limited.\n"
    .string "It can't pinpoint item locations.\p"
    .string "What it does is show the direction\n"
    .string "where the item is.\p"
    .string "Use it to get your bearings, then\n"
    .string "search the suspect area by hand.$"

Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "A big Pokémon is asleep on a road!$"

Route11_EastEntrance_2F_Text_WhatABreathtakingView::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "What a breathtaking view!$"

Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "To get to Lavender Town from\n"
    .string "Cerulean City…\p"
    .string "Rock Tunnel appears to be a good\n"
    .string "route to take.$"
