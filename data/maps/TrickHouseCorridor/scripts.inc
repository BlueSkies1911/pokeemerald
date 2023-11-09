TrickHouseCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TrickHouseCorridor_OnTransition
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TrickHouseCorridor_OnWarp
	.byte 0

TrickHouseCorridor_OnTransition:
	setvar VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 1
	end

TrickHouseCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, TrickHouseCorridor_EventScript_TurnPlayerNorth
	.2byte 0

TrickHouseCorridor_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end
