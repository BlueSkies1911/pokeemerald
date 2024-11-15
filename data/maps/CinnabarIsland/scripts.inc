.equ LOCALID_BILL, 3
.equ LOCALID_SEAGALLOP, 4

CinnabarIsland_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, CinnabarIsland_OnFrame
	.byte 0

CinnabarIsland_OnTransition:
	randomweather
    setflag FLAG_WORLD_MAP_CINNABAR_ISLAND
    call CinnabarIsland_EventScript_CheckUnlockGym
    compare VAR_MAP_SCENE_CINNABAR_ISLAND, 1
    call_if_eq CinnabarIsland_EventScript_ReadyObjectsSailToOneIsland
    compare VAR_MAP_SCENE_CINNABAR_ISLAND, 3
    call_if_eq CinnabarIsland_EventScript_ReadyObjectsReturnFromSeviiIslands
    compare VAR_MAP_SCENE_CINNABAR_ISLAND_2, 1
    call_if_eq CinnabarIsland_EventScript_ReadyObjectsSailToOneIslandFromPokeCenter
    end

CinnabarIsland_EventScript_CheckUnlockGym::
    goto_if_set FLAG_HIDE_POKEMON_MANSION_B1F_SECRET_KEY, CinnabarIsland_EventScript_UnlockGym
    return

CinnabarIsland_EventScript_UnlockGym::
    setvar VAR_TEMP_1, 1
    return

CinnabarIsland_EventScript_ReadyObjectsSailToOneIsland::
    getplayerxy VAR_0x8004, VAR_0x8005
    compare VAR_0x8004, 18
    goto_if_ge CinnabarIsland_EventScript_MoveSeagallopDown
    setflag FLAG_TEMP_2
    setobjectxyperm LOCALID_BILL, 18, 20
    setobjectmovementtype LOCALID_BILL, MOVEMENT_TYPE_FACE_UP
    setobjectxyperm LOCALID_SEAGALLOP, 30, 20
    return

CinnabarIsland_EventScript_MoveSeagallopDown::
    setobjectxyperm LOCALID_SEAGALLOP, 30, 16
    return

CinnabarIsland_EventScript_ReadyObjectsReturnFromSeviiIslands::
    setobjectxyperm LOCALID_BILL, 21, 16
    setobjectmovementtype LOCALID_BILL, MOVEMENT_TYPE_FACE_UP
    return

CinnabarIsland_EventScript_ReadyObjectsSailToOneIslandFromPokeCenter::
    savebgm MUS_RG_FOLLOW_ME
    setflag FLAG_TEMP_2
    setobjectxyperm LOCALID_BILL, 15, 20
    setobjectmovementtype LOCALID_BILL, MOVEMENT_TYPE_FACE_LEFT
    setobjectxyperm LOCALID_SEAGALLOP, 30, 20
    return

CinnabarIsland_OnFrame:
    map_script_2 VAR_MAP_SCENE_CINNABAR_ISLAND_2, 1, CinnabarIsland_EventScript_ExitPokeCenterForOneIsland
    map_script_2 VAR_MAP_SCENE_CINNABAR_ISLAND, 1, CinnabarIsland_EventScript_BillScene
    map_script_2 VAR_MAP_SCENE_CINNABAR_ISLAND, 3, CinnabarIsland_EventScript_ReturnFromSeviiIslands
    .2byte 0

CinnabarIsland_EventScript_ExitPokeCenterForOneIsland::
    lockall
    clearflag FLAG_DONT_TRANSITION_MUSIC
    savebgm MUS_DUMMY
    setvar VAR_MAP_SCENE_CINNABAR_ISLAND_2, 2
    delay 20
    call CinnabarIsland_EventScript_SailToOneIsland
    releaseall
    end

CinnabarIsland_EventScript_ReturnFromSeviiIslands::
    lockall
    msgbox CinnabarIsland_Text_IfYouHaveTriPassYouCanGoAgain, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_BILL, CinnabarIsland_Movement_BillExit
    waitmovement 0
    removeobject LOCALID_BILL
    setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 4
    setflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
    clearflag FLAG_HIDE_LOSTELLE_IN_HER_HOME
    releaseall
    end

CinnabarIsland_Movement_BillExit::
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

CinnabarIsland_EventScript_BillScene::
    lockall
    call_if_unset FLAG_TEMP_2, CinnabarIsland_EventScript_BillFacePlayer1
    call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_BillFacePlayer2
    playse SE_PIN
    applymovement LOCALID_BILL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_BILL, Common_Movement_Delay48
    waitmovement 0
    call_if_unset FLAG_TEMP_2, CinnabarIsland_EventScript_BillApproachPlayer1
    call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_BillApproachPlayer2
    msgbox CinnabarIsland_Text_HeyIfItIsntPlayer, MSGBOX_DEFAULT
    msgbox CinnabarIsland_Text_ComeWithMeToOneIsland, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq CinnabarIsland_EventScript_AgreeSailToOneIsland
    compare VAR_RESULT, NO
    goto_if_eq CinnabarIsland_EventScript_DeclineSailToOneIsland
    end

CinnabarIsland_EventScript_BillFacePlayer1::
    applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

CinnabarIsland_EventScript_BillFacePlayer2::
    applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    return

CinnabarIsland_EventScript_BillApproachPlayer1::
    applymovement LOCALID_BILL, CinnabarIsland_Movement_BillApproachPlayer1
    waitmovement 0
    return

CinnabarIsland_EventScript_BillApproachPlayer2::
    applymovement LOCALID_BILL, CinnabarIsland_Movement_BillApproachPlayer2
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    return

CinnabarIsland_EventScript_AgreeSailToOneIsland::
    msgbox CinnabarIsland_Text_AllRightLetsGo, MSGBOX_DEFAULT
    closemessage
    call CinnabarIsland_EventScript_SailToOneIsland
    releaseall
    end

CinnabarIsland_EventScript_DeclineSailToOneIsland::
    msgbox CinnabarIsland_Text_IllBeWaitingInPokeCenter, MSGBOX_DEFAULT
    closemessage
    call_if_unset FLAG_TEMP_2, CinnabarIsland_EventScript_BillExitToPokeCenter
    call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_BillReturnToPokeCenter
    removeobject LOCALID_BILL
    setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 2
    clearflag FLAG_HIDE_CINNABAR_POKECENTER_BILL
    releaseall
    end

CinnabarIsland_EventScript_BillExitToPokeCenter::
    applymovement LOCALID_BILL, CinnabarIsland_Movement_BillExitToPokeCenter
    waitmovement 0
    return

CinnabarIsland_Movement_BillExitToPokeCenter::
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

CinnabarIsland_EventScript_BillReturnToPokeCenter::
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_PlayerWatchBillExit
    applymovement LOCALID_BILL, CinnabarIsland_Movement_BillApproachDoor
    waitmovement 0
    opendoor 14, 19
    waitdooranim
    applymovement LOCALID_BILL, CinnabarIsland_Movement_BillReEnterPokeCenter
    waitmovement 0
    closedoor 14, 19
    waitdooranim
    return

CinnabarIsland_Movement_PlayerWatchBillExit::
    walk_left
    walk_in_place_faster_right
    step_end

CinnabarIsland_Movement_BillApproachDoor::
    delay_16
    walk_left
    walk_in_place_faster_up
    step_end

CinnabarIsland_Movement_BillReEnterPokeCenter::
    walk_up
    delay_4
    set_invisible
    step_end

CinnabarIsland_EventScript_SailToOneIsland::
    call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_ApproachShore
    addobject LOCALID_SEAGALLOP
    call_if_unset FLAG_TEMP_2, CinnabarIsland_EventScript_BoatArrive
    call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_BoatArriveExitedPokeCenter
    msgbox CinnabarIsland_Text_MyPalsBoatArrived, MSGBOX_DEFAULT
    closemessage
    call_if_unset FLAG_TEMP_2, CinnabarIsland_EventScript_BoardBoat
    call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_BoardBoatExitedPokeCenter
    setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 2
    removeobject LOCALID_BILL
    delay 40
    setflag FLAG_HIDE_CINNABAR_SEAGALLOP
    setvar VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 1
    setvar VAR_0x8004, SEAGALLOP_CINNABAR_ISLAND
    setvar VAR_0x8006, SEAGALLOP_ONE_ISLAND
    goto EventScript_SetSail
    end

CinnabarIsland_EventScript_ApproachShore::
    applymovement LOCALID_BILL, CinnabarIsland_Movement_ApproachShore
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_ApproachShore
    waitmovement 0
    return

CinnabarIsland_EventScript_BoatArrive::
    applymovement LOCALID_BILL, CinnabarIsland_Movement_BillFaceBoat
    applymovement LOCALID_SEAGALLOP, CinnabarIsland_Movement_BoatArrive
    waitmovement 0
    return

CinnabarIsland_EventScript_BoatArriveExitedPokeCenter::
    applymovement LOCALID_SEAGALLOP, CinnabarIsland_Movement_BoatArrive
    waitmovement 0
    return

CinnabarIsland_EventScript_BoardBoat::
    applymovement LOCALID_BILL, CinnabarIsland_Movement_BillBoardBoat
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_PlayerBoardBoat
    waitmovement 0
    return

CinnabarIsland_EventScript_BoardBoatExitedPokeCenter::
    applymovement LOCALID_BILL, CinnabarIsland_Movement_BillBoardBoatFromShore
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_PlayerBoardBoatFromShore
    waitmovement 0
    return

CinnabarIsland_Movement_BoatArrive::
    delay_16
    delay_16
    walk_fast_left
    walk_fast_left
    walk_left
    walk_slower_left
    walk_slower_left
    step_end

CinnabarIsland_Movement_BillBoardBoat::
    walk_right
    walk_down
    walk_down
    walk_right
    delay_4
    set_invisible
    step_end

CinnabarIsland_Movement_BillApproachPlayer1::
    walk_up
    step_end

CinnabarIsland_Movement_BillApproachPlayer2::
    walk_left
    walk_left
    walk_left
    step_end

CinnabarIsland_Movement_BillFaceBoat::
    delay_16
    delay_16
    delay_8
    walk_in_place_faster_right
    step_end

CinnabarIsland_Movement_ApproachShore::
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

CinnabarIsland_Movement_BillBoardBoatFromShore::
    walk_right
    delay_4
    set_invisible
    step_end

CinnabarIsland_Movement_PlayerBoardBoat::
    walk_down
    walk_right
    walk_down
    walk_down
    walk_in_place_faster_right
    delay_4
    walk_right
    delay_4
    set_invisible
    step_end

CinnabarIsland_Movement_PlayerBoardBoatFromShore::
    walk_right
    delay_4
    walk_right
    delay_4
    set_invisible
    step_end

CinnabarIsland_EventScript_GymDoorLocked::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    delay 20
    msgbox CinnabarIsland_Text_DoorIsLocked, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_ForcePlayerFromDoor
    waitmovement 0
    releaseall
    end

CinnabarIsland_Movement_ForcePlayerFromDoor::
    walk_down
    step_end

CinnabarIsland_EventScript_Woman::
    msgbox CinnabarIsland_Text_BlaineLivedHereSinceBeforeLab, MSGBOX_NPC
    end

CinnabarIsland_EventScript_OldMan::
    msgbox CinnabarIsland_Text_ScientistsExperimentInMansion, MSGBOX_NPC
    end

CinnabarIsland_EventScript_IslandSign::
    msgbox CinnabarIsland_Text_IslandSign, MSGBOX_SIGN
    end

CinnabarIsland_EventScript_PokemonLabSign::
    msgbox CinnabarIsland_Text_PokemonLab, MSGBOX_SIGN
    end

CinnabarIsland_EventScript_GymSign::
    msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
    end

CinnabarIsland_Text_HeyIfItIsntPlayer::
    .string "Huh?\n"
    .string "Hey, if it isn't {PLAYER}!$"

CinnabarIsland_Text_ComeWithMeToOneIsland::
    .string "Look, it's me, Bill.\n"
    .string "Long time no see!\p"
    .string "I hope you're still using my\n"
    .string "PC system.\p"
    .string "Well, listen, since we met up here,\n"
    .string "how about spending time with me?\p"
    .string "There's this little island in the far\n"
    .string "south called One Island.\p"
    .string "A friend invited me, so I'm on my\n"
    .string "way out there.\p"
    .string "How about it?\n"
    .string "Do you feel like coming with me?$"

CinnabarIsland_Text_AllRightLetsGo::
    .string "All right, then.\n"
    .string "Let's go!$"

CinnabarIsland_Text_IllBeWaitingInPokeCenter::
    .string "What, are you too busy?\p"
    .string "Well, all right.\n"
    .string "The boat hasn't arrived yet anyway.\p"
    .string "I'll be waiting at the Pokémon\n"
    .string "Center over there.\p"
    .string "Come see me when you're done with\n"
    .string "your business here.$"

CinnabarIsland_Text_MyPalsBoatArrived::
    .string "Looks like my pal's boat arrived,\n"
    .string "too.\p"
    .string "He sent it specially here to\n"
    .string "Cinnabar to pick me up.$"

CinnabarIsland_Text_IfYouHaveTriPassYouCanGoAgain::
    .string "Hey, wasn't that a long cruise?\p"
    .string "My buddy Celio seemed to enjoy\n"
    .string "your company.\p"
    .string "I'm sure he'd welcome you if you\n"
    .string "were to visit him again.\p"
    .string "If you have a Tri-Pass, you can\n"
    .string "always take a ferry there from\l"
    .string "Vermilion Port.\p"
    .string "All right, thanks for your company!$"

CinnabarIsland_Text_DoorIsLocked::
    .string "The door is locked…$"

CinnabarIsland_Text_BlaineLivedHereSinceBeforeLab::
    .string "Cinnabar Gym's Blaine is quite the\n"
    .string "odd fellow.\p"
    .string "He's lived on the island since way\n"
    .string "before the lab was built.$"

CinnabarIsland_Text_ScientistsExperimentInMansion::
    .string "Scientists conduct experiments \n"
    .string "in the burned-out building.\p"
    .string "You know, the one they call the\n"
    .string "Pokémon Mansion.$"

CinnabarIsland_Text_IslandSign::
    .string "Cinnabar Island\n"
    .string "The Fiery Town of Burning Desire$"

CinnabarIsland_Text_PokemonLab::
    .string "Pokémon Lab$"

CinnabarIsland_Text_GymSign::
    .string "Cinnabar Island Pokémon Gym\n"
    .string "Leader: Blaine\l"
    .string "The Hotheaded Quiz Master!$"
