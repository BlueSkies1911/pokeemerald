.set LOCALID_ATTENDANT, 1

FuchsiaCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_BattleTentCorridor_OnFrame
	.byte 0

FuchsiaCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FuchsiaCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FuchsiaCity_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, FuchsiaCity_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, FuchsiaCity_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FUCHSIA_CITY_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

FuchsiaCity_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FuchsiaCity_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FuchsiaCity_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end
