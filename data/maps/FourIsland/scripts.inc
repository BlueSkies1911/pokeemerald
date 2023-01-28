.equ LOCALID_DAYCARE_MAN, 1
.equ LOCALID_RIVAL, 10

FourIsland_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, FourIsland_OnFrame
    .byte 0

FourIsland_OnTransition:
    setflag FLAG_WORLD_MAP_FOUR_ISLAND
    compare VAR_MAP_SCENE_FOUR_ISLAND, 0
    call_if_eq FourIsland_EventScript_ShowRival
    call FourIsland_EventScript_TrySetDayCareManPos
    end

FourIsland_EventScript_ShowRival::
    clearflag FLAG_HIDE_FOUR_ISLAND_RIVAL
    return

FourIsland_EventScript_TrySetDayCareManPos::
    goto_if_unset FLAG_PENDING_DAYCARE_EGG, FourIsland_EventScript_EndSetDayCareManPos
    setobjectxyperm LOCALID_DAYCARE_MAN, 16, 14

FourIsland_EventScript_EndSetDayCareManPos::
    return

FourIsland_OnFrame:
    map_script_2 VAR_MAP_SCENE_FOUR_ISLAND, 0, FourIsland_EventScript_RivalScene
    .2byte 0

FourIsland_EventScript_RivalScene::
    lockall
    applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_RIVAL, Common_Movement_Delay48
    waitmovement 0
    delay 25
    applymovement LOCALID_RIVAL, FourIsland_Movement_RivalApproach
    waitmovement 0
    msgbox FourIsland_Text_RivalAlreadyGotEggBeSmellingYa, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, FourIsland_Movement_PlayerWatchRivalExit
    applymovement LOCALID_RIVAL, FourIsland_Movement_RivalExit
    waitmovement 0
    fadedefaultbgm
    playse SE_EXIT
    delay 35
    removeobject LOCALID_RIVAL
    setvar VAR_MAP_SCENE_FOUR_ISLAND, 1
    releaseall
    end

FourIsland_Movement_RivalApproach::
    walk_right
    walk_right
    walk_down
    walk_down
    step_end

FourIsland_Movement_RivalExit::
    delay_16
    delay_4
    walk_down
    step_end

FourIsland_Movement_PlayerWatchRivalExit::
    walk_left
    walk_in_place_faster_right
    step_end

FourIsland_EventScript_OldWoman::
    lock
    faceplayer
    goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, FourIsland_EventScript_OldWomanLoreleiLeft
    msgbox FourIsland_Text_LoreleiHasReturned, MSGBOX_DEFAULT
    release
    end

FourIsland_EventScript_OldWomanLoreleiLeft::
    msgbox FourIsland_Text_LoreleiMetLaprasAsChild, MSGBOX_DEFAULT
    release
    end

FourIsland_EventScript_LittleGirl::
    msgbox FourIsland_Text_LoreleiHasLotsOfStuffedDolls, MSGBOX_NPC
    end

FourIsland_EventScript_FatMan::
    msgbox FourIsland_Text_MadeSlushieUsingIcefallCaveIce, MSGBOX_NPC
    end

FourIsland_EventScript_IslandSign::
    msgbox FourIsland_Text_IslandSign, MSGBOX_SIGN
    end

FourIsland_EventScript_LoreleisHouseSign::
    msgbox FourIsland_Text_LoreleisHouse, MSGBOX_SIGN
    end

FourIsland_Text_LoreleiHasReturned::
    .string "Lorelei has returned.\p"
    .string "Did she find the city life too\n"
    .string "stressful, I wonder?$"

FourIsland_Text_LoreleiMetLaprasAsChild::
    .string "Lorelei has gone back.\p"
    .string "The Lapras she has, I imagine it\n"
    .string "to be the one she met as a child.\p"
    .string "I believe it was in Icefall Cave\n"
    .string "that she caught it.\p"
    .string "Perhaps that Pokémon has been with\n"
    .string "her ever since.$"

FourIsland_Text_RivalAlreadyGotEggBeSmellingYa::
    .string "{RIVAL}: Hey!\n"
    .string "{PLAYER}!\p"
    .string "What are you doing here in the\n"
    .string "Sevii Islands?\p"
    .string "You should quit copying me,\n"
    .string "you know?\p"
    .string "Anyways, I already got my Pokémon\n"
    .string "egg, so I'm done with this island.\p"
    .string "Heh, I bet you don't even know\n"
    .string "about Pokémon eggs.\p"
    .string "You'll never fill your National\n"
    .string "Pokédex that way.\p"
    .string "By the way, I saw someone we both\n"
    .string "know on this island.\p"
    .string "Why don't you go look around if\n"
    .string "it makes you curious?\p"
    .string "Me, I don't have the time to\n"
    .string "waste.\p"
    .string "Be smelling ya!$"

FourIsland_Text_LoreleiHasLotsOfStuffedDolls::
    .string "Oh, you found me!\n"
    .string "Please don't tell Lorelei.\p"
    .string "Did you know that Lorelei has lots\n"
    .string "and lots of stuffed dolls?\p"
    .string "Every time she comes back to\n"
    .string "Four Island, her collection grows!$"

FourIsland_Text_MadeSlushieUsingIcefallCaveIce::
    .string "Ooh, chilly!\p"
    .string "I made a slushie using ice I\n"
    .string "shaved inside Icefall Cave.\p"
    .string "It's chilly and tasty!$"

FourIsland_Text_LoreleisHouse::
    .string "Lorelei's House$"

FourIsland_Text_IslandSign::
    .string "FOUR ISLAND\n"
    .string "The Warm, Blue, Floe Island$"
