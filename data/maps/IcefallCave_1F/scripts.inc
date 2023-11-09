IcefallCave_1F_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, IcefallCave_1F_OnResume
    map_script MAP_SCRIPT_ON_LOAD, IcefallCave_1F_OnLoad
    map_script MAP_SCRIPT_ON_FRAME_TABLE, IcefallCave_1F_OnFrame
    .byte 0

IcefallCave_1F_OnResume:
    setstepcallback STEP_CB_ICE
    end

IcefallCave_1F_OnLoad:
    special SetIcefallCaveCrackedIceMetatiles
    end

IcefallCave_1F_OnFrame:
    map_script_2 VAR_TEMP_1, 1, IcefallCave_1F_EventScript_FallDownHole
    .2byte 0

IcefallCave_1F_EventScript_FallDownHole::
    lockall
    delay 20
    applymovement OBJ_EVENT_ID_PLAYER, IcefallCave_1F_Movement_SetInvisible
    waitmovement 0
    playse SE_FALL
    delay 60
    warphole MAP_ICEFALL_CAVE_B1F
    waitstate
    releaseall
    end

IcefallCave_1F_Movement_SetInvisible::
    set_invisible
    step_end
