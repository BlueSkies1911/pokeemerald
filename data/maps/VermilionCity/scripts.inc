.equ LOCALID_FERRY_SAILOR, 6

VermilionCity_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
    .byte 0

VermilionCity_OnFrame:
    map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
    .2byte 0

VermilionCity_EventScript_ExitSSAnne::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_ExitSSAnne
    waitmovement 0
    setvar VAR_MAP_SCENE_VERMILION_CITY, 3
    releaseall
    end

VermilionCity_Movement_ExitSSAnne::
    walk_up
    walk_up
    step_end

VermilionCity_OnTransition:
	randomweather
    setflag FLAG_WORLD_MAP_VERMILION_CITY
    call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
    end

VermilionCity_EventScript_HideOaksAide::
    setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
    return

VermilionCity_EventScript_Woman::
    msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
    end

VermilionCity_EventScript_OldMan1::
    lock
    faceplayer
    compare VAR_MAP_SCENE_VERMILION_CITY, 3
    goto_if_eq VermilionCity_EventScript_OldMan1SSAnneLeft
    msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor, MSGBOX_DEFAULT
    release
    end

VermilionCity_EventScript_OldMan1SSAnneLeft::
    msgbox VermilionCity_Text_SSAnneHasDepartedForYear, MSGBOX_DEFAULT
    release
    end

VermilionCity_EventScript_OldMan2::
    msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
    end

VermilionCity_EventScript_Machop::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_MACHOP, 0
    msgbox VermilionCity_Text_Machop, MSGBOX_DEFAULT
    waitmoncry
    msgbox VermilionCity_Text_MachopStompingLandFlat, MSGBOX_DEFAULT
    release
    end

VermilionCity_EventScript_Sailor::
    msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
    end

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
	release
	end

VermilionCity_EventScript_CheckSeagallopPresent::
	call VermilionCity_Harbor_EventScript_GetOldSeaMapState
	call VermilionCity_Harbor_EventScript_GetFirstTimeShowingTicket
	call VermilionCity_Harbor_EventScript_GetHasTicketsState
	goto_if_eq VAR_TEMP_C, 2, VermilionCity_Harbor_EventScript_OldSeaMapFirstTime
	goto_if_eq VAR_TEMP_B, 4, VermilionCity_Harbor_EventScript_OldSeaMapFirstTime
	checkitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_TheShipSetSail
	goto VermilionCity_Harbor_EventScript_NoFirstTimeEventTickets
	end

VermilionCity_EventScript_TheShipSetSail::
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_Harbor_EventScript_TravelToBattleFrontier
	msgbox VermilionCity_Text_TheShipSetSail, MSGBOX_DEFAULT
	release
    end

VermilionCity_Harbor_EventScript_TravelToBattleFrontier::
	msgbox VermilionCity_Harbor_Text_TravelToBattleFrontier, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSail
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end


VermilionCity_Harbor_EventScript_NoFirstTimeEventTickets::
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	msgbox VermilionCity_Text_ReturnToFarawayIsland, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSail
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	waitstate
	release
	end

VermilionCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	message VermilionCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	multichoicedefault 17, 6, MULTI_VERMILION_WITH_BF, 0, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_Harbor_EventScript_BattleFrontier
	case 1, VermilionCity_Harbor_EventScript_FarawayIsland
	case 2, EventScript_CancelSail
	case MULTI_B_PRESSED, EventScript_CancelSail
	end

VermilionCity_Harbor_EventScript_BattleFrontier::
	msgbox VermilionCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_Harbor_EventScript_ChooseNewDestination
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

VermilionCity_Harbor_EventScript_FarawayIsland::
	msgbox VermilionCity_Harbor_Text_FarawayIslandItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_Harbor_EventScript_ChooseNewDestination
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	waitstate
	release
	end

VermilionCity_Harbor_EventScript_ChooseNewDestination::
	message VermilionCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto VermilionCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	end

VermilionCity_Harbor_EventScript_GetOldSeaMapState::
	setvar VAR_TEMP_C, 0
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 1
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 2
	return

VermilionCity_Harbor_EventScript_GetFirstTimeShowingTicket::
	setvar VAR_TEMP_B, 0
	call_if_eq VAR_TEMP_C, 2, VermilionCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap
	return

VermilionCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap::
	addvar VAR_TEMP_B, 4
	return

VermilionCity_Harbor_EventScript_GetHasTicketsState::
	setvar VAR_TEMP_A, 0
	call_if_eq VAR_TEMP_C, 1, VermilionCity_Harbor_EventScript_SetHasOldSeaMap
	return

VermilionCity_Harbor_EventScript_SetHasOldSeaMap::
	addvar VAR_TEMP_A, 4
	return

VermilionCity_Harbor_EventScript_OldSeaMapFirstTime::
	setflag FLAG_SHOWN_OLD_SEA_MAP
	msgbox EventTicket_Text_ShowOldSeaMap, MSGBOX_DEFAULT
	closemessage
	msgbox EventTicket_Text_OldSeaMapTooFar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_Delay48
	waitmovement 0
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	waitstate
	release
	end

VermilionCity_EventScript_OaksAide::
    lock
    faceplayer
    setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
    msgbox VermilionCity_Text_Route2AideHasPackageForYou, MSGBOX_DEFAULT
    release
    end

VermilionCity_EventScript_CitySign::
    msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
    end

VermilionCity_EventScript_PokemonFanClubSign::
    msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
    end

VermilionCity_EventScript_GymSign::
    msgbox VermilionCity_Text_GymSign, MSGBOX_SIGN
    end

VermilionCity_EventScript_HarborSign::
    msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
    end

VermilionCity_EventScript_SnorlaxNotice::
    msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
    end

VermilionCity_EventScript_CheckTicketLeft::
    lockall
    goto VermilionCity_EventScript_CheckTicket
    end

VermilionCity_EventScript_CheckTicketRight::
    lockall
    goto VermilionCity_EventScript_CheckTicket
    end

VermilionCity_EventScript_CheckTicket::
    applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
	msgbox VermilionCity_Text_DoYouHaveATicket, MSGBOX_DEFAULT
    goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
    msgbox VermilionCity_Text_FlashedSSTicket, MSGBOX_DEFAULT
    setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
    releaseall
    end

VermilionCity_EventScript_DontHaveSSTicket::
    msgbox VermilionCity_Text_DontHaveNeededSSTicket, MSGBOX_DEFAULT
    closemessage
    goto VermilionCity_EventScript_WalkUpPier
    end

VermilionCity_EventScript_CheckSeagallopPresentTrigger::
	call VermilionCity_Harbor_EventScript_GetOldSeaMapState
	call VermilionCity_Harbor_EventScript_GetFirstTimeShowingTicket
	call VermilionCity_Harbor_EventScript_GetHasTicketsState
	goto_if_eq VAR_TEMP_C, 2, VermilionCity_Harbor_EventScript_OldSeaMapFirstTime
	goto_if_eq VAR_TEMP_B, 4, VermilionCity_Harbor_EventScript_OldSeaMapFirstTime
	goto_if_unset FLAG_ARRIVED_ON_FARAWAY_ISLAND, VermilionCity_EventScript_TheShipSetSailWalkUp
	goto VermilionCity_Harbor_EventScript_NoFirstTimeEventTickets
    end

VermilionCity_EventScript_TheShipSetSailWalkUp::
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_Harbor_EventScript_TravelToBattleFrontier
    msgbox VermilionCity_Text_TheShipSetSail, MSGBOX_DEFAULT
    closemessage
    goto VermilionCity_EventScript_WalkUpPier
    end

VermilionCity_EventScript_WalkUpPier::
    closemessage
    applymovement LOCALID_FERRY_SAILOR, Common_Movement_FaceOriginalDirection
    applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_WalkUp
    waitmovement 0
    releaseall
    end

VermilionCity_Movement_WalkUp::
    walk_up
    step_end

VermilionCity_EventScript_ExitedTicketCheck::
    lockall
    setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
    releaseall
    end

VermilionCity_Text_GrimerMultipliesInSludge::
    .string "We're careful about pollution here.\p"
    .string "We've heard Grimer multiplies in\n"
    .string "toxic sludge.$"

VermilionCity_Text_DidYouSeeSSAnneInHarbor::
    .string "Did you see the S.S. Anne moored\n"
    .string "in the harbor?$"

VermilionCity_Text_SSAnneHasDepartedForYear::
    .string "So, the S.S. Anne has departed?\p"
    .string "She'll be back in Vermilion about\n"
    .string "this time next year.$"

VermilionCity_Text_BuildingOnThisLand::
    .string "I'm putting up a building on this\n"
    .string "plot of land. I own it all.\p"
    .string "My Pokémon is tamping the land\n"
    .string "to lay the foundation.$"

VermilionCity_Text_Machop::
    .string "Machop: Guoh! Gogogoh!$"

VermilionCity_Text_MachopStompingLandFlat::
    .string "A Machop is stomping the land flat.$"

VermilionCity_Text_SSAnneVisitsOnceAYear::
    .string "The S.S. Anne is a famous luxury\n"
    .string "cruise ship.\p"
    .string "It visits Vermilion once a year.$"

VermilionCity_Text_WelcomeToTheSSAnne::
    .string "Welcome to the S.S. Anne!$"

VermilionCity_Text_Route2AideHasPackageForYou::
    .string "Oh, hello, {PLAYER}!\n"
    .string "How are you doing?\p"
    .string "It's me, one of Prof. Oak's Aides.\p"
    .string "Did you meet the other Aide?\p"
    .string "He had a package from Prof. Oak\n"
    .string "for you, {PLAYER}.\p"
    .string "He said he'd look for you around\n"
    .string "Route 2, {PLAYER}.\p"
    .string "If you're in the Route 2 area,\n"
    .string "please look for him.$"

VermilionCity_Text_DoYouHaveATicket::
    .string "Welcome to the S.S. Anne!\p"
    .string "Excuse me, do you have a ticket?$"

VermilionCity_Text_DontHaveNeededSSTicket::
    .string "{PLAYER} doesn't have the needed\n"
    .string "S.S. Ticket.\p"
    .string "Sorry!\p"
    .string "You need a ticket to get aboard.$"

VermilionCity_Text_FlashedSSTicket::
    .string "{PLAYER} flashed the S.S. Ticket!\p"
    .string "Great!\n"
    .string "Welcome to the S.S. Anne!$"

VermilionCity_Text_TheShipSetSail::
    .string "The ship set sail.$"

VermilionCity_Text_ReturnToFarawayIsland::
    .string "Do you wish to return\n"
    .string "to Faraway Island?$"

VermilionCity_Harbor_Text_TravelToBattleFrontier::
    .string "Do you wish to travel\n"
    .string "to the Battle Frontier?$"

VermilionCity_Harbor_Text_FlashedTicketWhereTo:
	.string "Welcome!\p"
	.string "Where would you like to go?$"

VermilionCity_Harbor_Text_BattleFrontierItIs:
	.string "Battle Frontier it is, then!$"

VermilionCity_Harbor_Text_FarawayIslandItIs:
	.string "Faraway Island it is, then!$"

VermilionCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Then, where would you like to go?$"

VermilionCity_Text_BoardSeagallopTriPass::
    .string "Ah, you have a Tri-Pass.\p"
    .string "Would you like to board\n"
    .string "a Seagallop ferry?$"

VermilionCity_Text_Seagallop7Departing::
    .string "Okay, everything's in order.\p"
    .string "Seagallop Hi-Speed 7 will be\n"
    .string "departing immediately.$"

VermilionCity_Text_BoardSeagallopRainbowPass::
    .string "Ah, you have a Rainbow Pass.\p"
    .string "Would you like to board\n"
    .string "a Seagallop ferry?$"

VermilionCity_Text_CitySign::
    .string "Vermilion City\n"
    .string "The Port of Exquisite Sunsets$"

VermilionCity_Text_PokemonFanClubSign::
    .string "Pokémon Fan Club\n"
    .string "All Pokémon fans welcome!$"

VermilionCity_Text_GymSign::
    .string "Vermilion City Pokémon Gym\n"
    .string "Leader: Lt. Surge\l"
    .string "The Lightning American!$"

VermilionCity_Text_VermilionHarbor::
    .string "Vermilion Harbor$"

VermilionCity_Text_SnorlaxBlockingRoute12::
    .string "NOTICE!\p"
    .string "Route 12 may be blocked off by a\n"
    .string "sleeping Pokémon.\p"
    .string "Detour through Rock Tunnel to\n"
    .string "Lavender Town.\p"
    .string "Vermilion Police$"

