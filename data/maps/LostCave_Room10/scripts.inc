.set LOCALID_SELPHY, 1

LostCave_Room10_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, LostCave_Room10_OnResume
    map_script MAP_SCRIPT_ON_FRAME_TABLE, LostCave_Room10_OnFrame
    .byte 0

LostCave_Room10_OnResume:
    call_if_defeated TRAINER_LADY_SELPHY, LostCave_Room10_EventScript_StopSelphySceneTrigger
    end

LostCave_Room10_EventScript_StopSelphySceneTrigger::
    setvar VAR_MAP_SCENE_LOST_CAVE_ROOM10, 1
    return

LostCave_Room10_OnFrame:
    map_script_2 VAR_MAP_SCENE_LOST_CAVE_ROOM10, 0, LostCave_Room10_EventScript_FindSelphyScene
    .2byte 0

LostCave_Room10_EventScript_FindSelphyScene::
    lockall
    applymovement LOCALID_SELPHY, LostCave_Room10_Movement_SelphyWander
    waitmovement 0
    delay 100
    applymovement LOCALID_SELPHY, LostCave_Room10_Movement_SelphyApproach
    waitmovement 0
    msgbox LostCave_Room10_Text_SelphyIntro, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_LADY_SELPHY, LostCave_Room10_Text_SelphyDefeat
    msgbox LostCave_Room10_Text_MayIAskYouToTakeMeHome, MSGBOX_DEFAULT
    closemessage
    call LostCave_Room10_EventScript_SetSelphyFound
    warp MAP_RESORT_GORGEOUS, 255, 39, 10
    waitstate
    releaseall
    end

LostCave_Room10_EventScript_SetSelphyFound::
    setflag FLAG_HIDE_LOST_CAVE_SELPHY
    clearflag FLAG_HIDE_RESORT_GORGEOUS_SELPHY
    setvar VAR_MAP_SCENE_LOST_CAVE_ROOM10, 1
    setvar VAR_MAP_SCENE_RESORT_GORGEOUS, 1
    return

LostCave_Room10_Movement_SelphyWander::
    walk_left
    delay_16
    walk_right
    delay_16
    walk_in_place_faster_up
    delay_16
    walk_in_place_faster_down
    step_end

LostCave_Room10_Movement_SelphyApproach::
    walk_down
    walk_down
    step_end

LostCave_Room10_Text_SelphyIntro::
    .string "W-what do you intend to do with\n"
    .string "me?$"

LostCave_Room10_Text_SelphyDefeat::
    .string "Oh… I was afraid that you meant to\n"
    .string "harm me.$"

LostCave_Room10_Text_MayIAskYouToTakeMeHome::
    .string "I am so glad that you happened\n"
    .string "here.\p"
    .string "I grew rather bored of walking,\n"
    .string "and I am feeling fatigued.\p"
    .string "May I ask you to take me home\n"
    .string "from here?$"
