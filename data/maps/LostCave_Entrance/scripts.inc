LostCave_Entrance_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, LostCave_Entrance_OnTransition
	.byte 0

LostCave_Entrance_OnTransition:
    setflag FLAG_WORLD_MAP_LOST_CAVE_ENTRANCE
    end
