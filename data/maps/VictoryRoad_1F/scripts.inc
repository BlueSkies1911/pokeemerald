VictoryRoad_1F_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_1F_OnLoad
    map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
    .byte 0

VictoryRoad_1F_OnLoad:
    compare VAR_MAP_SCENE_VICTORY_ROAD_1F, 100
    call_if_ne VictoryRoad_1F_EventScript_SetRockBarrier
    end

VictoryRoad_1F_EventScript_SetRockBarrier::
    setmetatile 12, 14, METATILE_Cave_RockBarrier_Top, 1
    setmetatile 12, 15, METATILE_Cave_RockBarrier_Bottom, 1
    return

VictoryRoad_1F_OnTransition:
    setflag FLAG_LANDMARK_VICTORY_ROAD
    end

VictoryRoad_1F_EventScript_FloorSwitch::
    lockall
    compare VAR_MAP_SCENE_VICTORY_ROAD_1F, 100
    goto_if_eq VictoryRoad_1F_EventScript_FloorSwitchAlreadyPressed
    setmetatile 12, 14, METATILE_Cave_Floor_Ledge_Top, 0
    setmetatile 12, 15, METATILE_Cave_Floor_Ledge_Bottom, 0
    playse SE_ICE_BREAK
    special DrawWholeMapView
    waitse
    copyobjectxytoperm 5
    setvar VAR_MAP_SCENE_VICTORY_ROAD_1F, 100
    releaseall
    end

VictoryRoad_1F_EventScript_FloorSwitchAlreadyPressed::
    releaseall
    end

VictoryRoad_1F_EventScript_Naomi::
    trainerbattle_single TRAINER_COOLTRAINER_NAOMI, VictoryRoad_1F_Text_NaomiIntro, VictoryRoad_1F_Text_NaomiDefeat
    msgbox VictoryRoad_1F_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
    end

VictoryRoad_1F_EventScript_Rolando::
    trainerbattle_single TRAINER_COOLTRAINER_ROLANDO, VictoryRoad_1F_Text_RolandoIntro, VictoryRoad_1F_Text_RolandoDefeat
    msgbox VictoryRoad_1F_Text_RolandoPostBattle, MSGBOX_AUTOCLOSE
    end

VictoryRoad_1F_Text_NaomiIntro::
    .string "I wonder if you are good enough\n"
    .string "for me?$"

VictoryRoad_1F_Text_NaomiDefeat::
    .string "I lost out…$"

VictoryRoad_1F_Text_NaomiPostBattle::
    .string "I never wanted to lose to anybody,\n"
    .string "especially to a younger kid…$"

VictoryRoad_1F_Text_RolandoIntro::
    .string "I can see you're good.\n"
    .string "Let me see exactly how good!$"

VictoryRoad_1F_Text_RolandoDefeat::
    .string "I had a chance…$"

VictoryRoad_1F_Text_RolandoPostBattle::
    .string "Tch!\n"
    .string "I concede, you are better than I!$"
