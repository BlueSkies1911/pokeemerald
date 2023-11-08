.set LOCALID_ATTENDANT, 1

SaffronCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_BattleTentCorridor_OnFrame
	.byte 0

SaffronCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SaffronCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SaffronCity_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, SaffronCity_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, SaffronCity_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, SaffronCity_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, SaffronCity_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_SAFFRON_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

SaffronCity_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SaffronCity_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
SaffronCity_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SaffronCity_ContestHall_Text_DoAllRightInPreliminary:
	.string "We do all right in the preliminary round,\n"
	.string "but we can never win the appeals…\p"
	.string "Maybe it means I have to watch what\n"
	.string "other contestants are doing…$"

@ Unused
SaffronCity_ContestHall_Text_MonAllTheseRibbons:
	.string "See!\n"
	.string "My Pokémon won all these Ribbons!\p"
	.string "Have your Pokémon earned any Ribbons?\n"
	.string "You can check them on your Pokénav.$"

@ Unused
SaffronCity_ContestHall_Text_CantWinEverywhere:
	.string "I can't beat Gym Leaders…\p"
	.string "I can't win any Contests…\p"
	.string "I've been here, there, and everywhere,\n"
	.string "and it's all for naught…$"

@ Unused
SaffronCity_ContestHall_Text_SuperRankStage:
	.string "Pokémon Contests\n"
	.string "Super Rank Stage!$"

