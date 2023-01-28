.set LOCALID_NURSE, 1
.set LOCALID_BILL, 5

CinnabarIsland_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    .byte 0

CinnabarIsland_PokemonCenter_1F_OnTransition:
    setrespawn HEAL_LOCATION_CINNABAR_ISLAND
    end

CinnabarIsland_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

CinnabarIsland_PokemonCenter_1F_EventScript_Bill::
    lock
    faceplayer
    msgbox CinnabarIsland_PokemonCenter_1F_Text_ReadyToSailToOneIsland, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq CinnabarIsland_PokemonCenter_1F_EventScript_NotReadyToSail
    msgbox CinnabarIsland_PokemonCenter_1F_Text_LetsGo, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_RG_FOLLOW_ME, 1
    savebgm MUS_RG_FOLLOW_ME
    setflag FLAG_DONT_TRANSITION_MUSIC
    setflag FLAG_HIDE_CINNABAR_POKECENTER_BILL
    delay 20
    compare VAR_FACING, DIR_SOUTH
    call_if_eq CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillEast
    compare VAR_FACING, DIR_WEST
    call_if_eq CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillWest
    removeobject LOCALID_BILL
    setvar VAR_MAP_SCENE_CINNABAR_ISLAND_2, 1
    clearflag FLAG_HIDE_CINNABAR_BILL
    warp MAP_CINNABAR_ISLAND, 255, 14, 19
    waitstate
    release
    end

CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillSouth::
    applymovement LOCALID_BILL, CinnabarIsland_PokemonCenter_1F_Movement_BillExit
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitSouth
    waitmovement 0
    return

CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillEast::
    applymovement LOCALID_BILL, CinnabarIsland_PokemonCenter_1F_Movement_BillExitEast
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitEast
    waitmovement 0
    return

CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillWest::
    applymovement LOCALID_BILL, CinnabarIsland_PokemonCenter_1F_Movement_BillExit
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitWest
    waitmovement 0
    return

CinnabarIsland_PokemonCenter_1F_EventScript_NotReadyToSail::
    msgbox CinnabarIsland_PokemonCenter_1F_Text_OhNotDoneYet, MSGBOX_DEFAULT
    release
    end

CinnabarIsland_PokemonCenter_1F_Movement_BillExit::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    delay_8
    set_invisible
    step_end

CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitSouth::
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    delay_16
    walk_down
    step_end

CinnabarIsland_PokemonCenter_1F_Movement_BillExitEast::
    walk_up
    walk_left
    walk_left
    walk_down
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    delay_8
    set_invisible
    step_end

CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitEast::
    delay_16
    delay_16
    delay_16
    face_left
    delay_16
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    delay_8
    walk_down
    delay_8
    set_invisible
    step_end

CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitWest::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    delay_16
    walk_down
    step_end

CinnabarIsland_PokemonCenter_1F_EventScript_Gentleman::
    msgbox CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom, MSGBOX_NPC
    end

CinnabarIsland_PokemonCenter_1F_EventScript_CooltrainerF::
    msgbox CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked, MSGBOX_NPC
    end

CinnabarIsland_PokemonCenter_1F_EventScript_Youngster::
    msgbox CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves, MSGBOX_NPC
    end

CinnabarIsland_PokemonCenter_1F_EventScript_PokemonJournalMrFuji::
    msgbox PokemonJournal_Text_SpecialFeatureMrFuji, MSGBOX_SIGN
    end

CinnabarIsland_PokemonCenter_1F_Text_ReadyToSailToOneIsland::
    .string "Bill: Hey, you kept me waiting!\n"
    .string "Ready to set sail to One Island?$"

CinnabarIsland_PokemonCenter_1F_Text_OhNotDoneYet::
    .string "Oh, you're still not done yet?$"

CinnabarIsland_PokemonCenter_1F_Text_LetsGo::
    .string "Well, that's it.\n"
    .string "Let's go!$"

CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked::
    .string "I came to visit the Cinnabar Gym,\n"
    .string "but the door is locked tight.\p"
    .string "There should be a key for it\n"
    .string "somewhere.\p"
    .string "Could it be in that burned-out\n"
    .string "mansion?\p"
    .string "The Gym Leader's friend used to\n"
    .string "live there, they say.$"

CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom::
    .string "Do you have lots of friends?\p"
    .string "Linking up with the usual friends\n"
    .string "is fun, of course.\p"
    .string "But how about visiting the\n"
    .string "Union Room every so often?\p"
    .string "Who knows, you may end up making\n"
    .string "new friends.\p"
    .string "I think it would be worth your time\n"
    .string "to check the Union Room.$"

CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves::
    .string "Pokémon can still learn techniques\n"
    .string "after cancelling evolution.\p"
    .string "Evolution can wait until new moves\n"
    .string "have been learned.$"

PokemonJournal_Text_SpecialFeatureMrFuji::
    .string "Pokémon Journal\p"
    .string "Special Feature:\n"
    .string "Mr. Fuji of Pokémon House!\p"
    .string "Editor: The shy Mr. Fuji turned\n"
    .string "down our interview requests.\p"
    .string "He is a kindly man who is adored\n"
    .string "and respected in Lavender Town.$"
