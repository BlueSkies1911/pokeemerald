
.set LOCALID_MOM,       1

PlayersHouse_2F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, PlayersHouse_2F_OnTransition
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayersHouse_2F_OnWarp
    map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayersHouse_2F_OnFrame
    .byte 0

PlayersHouse_2F_OnTransition:
    compare VAR_MAP_SCENE_PLAYERS_HOUSE_2F, 0
    call_if_eq PlayersHouse_2F_EventScript_SetRespawn
    end

PlayersHouse_2F_EventScript_SetRespawn::
    setrespawn HEAL_LOCATION_PALLET_TOWN
    return

PlayersHouse_2F_OnWarp:
    map_script_2 VAR_MAP_SCENE_PLAYERS_HOUSE_2F, 0, PlayersHouse_2F_FirstWarpIn
    .2byte 0

PlayersHouse_2F_FirstWarpIn::
    turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
    end

PlayersHouse_2F_OnFrame:
    map_script_2 VAR_MAP_SCENE_PLAYERS_HOUSE_2F, 0, PlayersHouse_2F_FirstFrameIn
    .2byte 0

PlayersHouse_2F_FirstFrameIn::
    lockall
    playse SE_EXIT
    delay 5
    msgbox PlayersHouse_2F_Text_WakeUp, MSGBOX_DEFAULT
    closemessage
    special SpawnCameraObject
    applymovement OBJ_EVENT_ID_CAMERA, PlayersHouse_2F_Movement_CameraPanToCenter
    waitmovement 0
    msgbox PlayersHouse_2F_Text_YoureLate, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
    waitmovement 0
    delay 48
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
    waitmovement 0
    delay 48
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
    waitmovement 0
    playse SE_PIN
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
    waitmovement 0
    delay 48
    applymovement LOCALID_MOM, Common_Movement_WalkInPlaceRight
    waitmovement 0
    delay 48
    playse SE_PIN
    applymovement LOCALID_MOM, Common_Movement_ExclamationMark
    waitmovement 0
    msgbox PlayersHouse_2F_Text_ClockStopped, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_MOM, Common_Movement_WalkInPlaceDown
    waitmovement 0
    msgbox PlayersHouse_2F_Text_NoWonderSleptIn, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_CAMERA, PlayersHouse_2F_Movement_CameraPanBackFromCenter
    waitmovement 0
    special RemoveCameraObject
    setvar VAR_MAP_SCENE_PLAYERS_HOUSE_2F, 1
    releaseall
    end

PlayersHouse_2F_Movement_CameraPanToCenter::
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    step_end

PlayersHouse_2F_Movement_CameraPanBackFromCenter::
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

PlayersHouse_2F_EventScript_GoSetTheClock::
	msgbox PlayersHouse_2F_Text_GoSetTheClock, MSGBOX_NPC
	end

PlayersHouse_2F_EventScript_NES::
    msgbox PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
    end

PlayersHouse_2F_EventScript_PC::
    setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
    special DoPCTurnOnEffect
    playse SE_PC_ON
    msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
    special BedroomPC
    waitstate
    releaseall
    end

PlayersHouse_2F_EventScript_ShutDownPC::
    setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
    playse SE_PC_OFF
    special DoPCTurnOffEffect
    releaseall
    end

PlayersHouse_2F_EventScript_WallClock::
    lockall
    checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_2F_EventScript_SetClockGfxMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_2F_EventScript_SetClockGfxFemale
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	setflag FLAG_SET_WALL_CLOCK
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PlayersHouse_2F_Text_ClockSetStartJourney, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_MOM
	setflag FLAG_HIDE_MOM_PLAYERS_HOUSE_2F
	releaseall
	end

PlayersHouse_2F_EventScript_SetClockGfxMale::
	setvar VAR_0x8004, MALE
    return

PlayersHouse_2F_EventScript_SetClockGfxFemale::
	setvar VAR_0x8004, FEMALE
    return


PlayersHouse_2F_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterRight
	special StartWallClock
	waitstate
	return

PlayersHouse_2F_Text_WakeUp::
    .string "{PLAYER}!$"

PlayersHouse_2F_Text_YoureLate::
    .string "Mom: {PLAYER}, {PLAYER}!\p"
    .string "Wake up! You're late!$"

PlayersHouse_2F_Text_ClockStopped::
    .string "Mom: Oh, no!\n"
    .string "The clock has stopped working!$"

PlayersHouse_2F_Text_NoWonderSleptIn::
    .string "No wonder you slept in!\p"
    .string "You should set it before\n"
    .string "you leave on your journey.$"

PlayersHouse_2F_Text_GoSetTheClock:
	.string "Mom: Go set the clock, honey.$"

PlayersHouse_2F_Text_ClockSetStartJourney:
	.string "Mom: Great! Now that you've\n"
    .string "fixed the clock, you should\l"
    .string "head out to see Prof. Oak!\p"
    .string "Don't worry, {PLAYER}.\n"
    .string "I'll keep your room tidy.\p"
	.string "Before you leave, you should\n"
    .string "make sure that everything's\l"
	.string "all there on your desk.$"
    
PlayersHouse_2F_Text_PlayedWithNES::
    .string "{PLAYER} played with the NES.\p"
    .string "…Okay!\n"
    .string "It's time to go!$"

PlayersHouse_2F_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"
