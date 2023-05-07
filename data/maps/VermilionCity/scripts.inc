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
    compare VAR_MAP_SCENE_VERMILION_CITY, 3
    goto_if_eq VermilionCity_EventScript_CheckSeagallopPresent
    msgbox VermilionCity_Text_WelcomeToTheSSAnne, MSGBOX_DEFAULT
    release
    end

VermilionCity_EventScript_CheckSeagallopPresent::
    setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
    goto_if_ge VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1
    goto_if_ge VermilionCity_EventScript_ChooseSeagallopDestTriPass
    msgbox VermilionCity_Text_TheShipSetSail, MSGBOX_DEFAULT
    release
    end

VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
    setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
    message VermilionCity_Text_BoardSeagallopRainbowPass
    waitmessage
    goto EventScript_SeviiDestinationsPage1
    end

VermilionCity_EventScript_ChooseSeagallopDestTriPass::
    message VermilionCity_Text_BoardSeagallopTriPass
    waitmessage
    setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
    multichoice 19, 5, MULTI_SEAGALLOP_123, FALSE
    switch VAR_RESULT
    case 0, EventScript_SailToOneIsland2
    case 1, EventScript_SailToTwoIsland2
    case 2, EventScript_SailToThreeIsland2
    case 3, EventScript_CancelSail
    case 127, EventScript_CancelSail
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
    textcolor 0
    applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    compare VAR_MAP_SCENE_VERMILION_CITY, 3
    goto_if_eq VermilionCity_EventScript_CheckSeagallopPresentTrigger
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
    setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
    goto_if_ge VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1
    goto_if_ge VermilionCity_EventScript_ChooseSeagallopDestTriPass
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

