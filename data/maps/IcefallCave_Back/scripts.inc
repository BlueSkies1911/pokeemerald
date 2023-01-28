.equ LOCALID_ROCKET1, 1
.equ LOCALID_ROCKET2, 2
.equ LOCALID_LORELEI, 3
.equ LOCALID_ROCKET3, 4

IcefallCave_Back_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, IcefallCave_Back_OnTransition
    .byte 0

IcefallCave_Back_OnTransition:
    compare VAR_MAP_SCENE_ICEFALL_CAVE_BACK, 1
    call_if_eq IcefallCave_Back_EventScript_HideLorelei
    end

IcefallCave_Back_EventScript_HideLorelei::
    setflag FLAG_HIDE_ICEFALL_CAVE_LORELEI
    return

IcefallCave_Back_EventScript_LoreleiRocketsScene::
    lockall
    msgbox IcefallCave_Back_Text_LoreleiKeepHandsOffMons, MSGBOX_DEFAULT
    applymovement LOCALID_ROCKET1, IcefallCave_Back_Movement_WalkInPlaceDown
    waitmovement 0
    msgbox IcefallCave_Back_Text_ShutItLadyLeaveUsBe, MSGBOX_DEFAULT
    closemessage
    playse SE_PIN
    applymovement LOCALID_LORELEI, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_LORELEI, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement LOCALID_LORELEI, Common_Movement_Delay48
    waitmovement 0
    msgbox IcefallCave_Back_Text_LoreleiPlayerHelpMeKickPoachersOut, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_LORELEI, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    delay 18
    applymovement LOCALID_LORELEI, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    delay 35
    applymovement LOCALID_ROCKET3, IcefallCave_Back_Movement_Rocket3FaceLorelei
    applymovement LOCALID_LORELEI, IcefallCave_Back_Movement_LoreleiToRockets
    applymovement OBJ_EVENT_ID_PLAYER, IcefallCave_Back_Movement_PlayerToRockets
    waitmovement 0
    applymovement LOCALID_ROCKET2, IcefallCave_Back_Movement_WalkInPlaceDown
    waitmovement 0
    playbgm MUS_RG_ENCOUNTER_ROCKET, 0
    msgbox IcefallCave_Back_Text_GruntIntro, MSGBOX_DEFAULT
    setvar VAR_LAST_TALKED, LOCALID_ROCKET3
    trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_45, IcefallCave_Back_Text_GruntDefeat
    applymovement LOCALID_LORELEI, IcefallCave_Back_Movement_WalkInPlaceUp
    waitmovement 0
    msgbox IcefallCave_Back_Text_LoreleiWhereHaveYouTakenMons, MSGBOX_DEFAULT
    msgbox IcefallCave_Back_Text_NotTellingYouThat, MSGBOX_DEFAULT
    message IcefallCave_Back_Text_LoreleiWellDeepFreezeYou
    waitmessage
    waitse
    playmoncry SPECIES_LAPRAS, 2
    waitbuttonpress
    waitmoncry
    applymovement LOCALID_ROCKET1, IcefallCave_Back_Movement_Rocket1ReactToThreat
    waitmovement 0
    msgbox IcefallCave_Back_Text_OkayRocketWareHouseFiveIsland, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_LORELEI, IcefallCave_Back_Movement_LoreleiWatchRocketsExit
    applymovement OBJ_EVENT_ID_PLAYER, IcefallCave_Back_Movement_PlayerWatchRocketsExit
    applymovement LOCALID_ROCKET1, IcefallCave_Back_Movement_Rocket1Exit
    applymovement LOCALID_ROCKET2, IcefallCave_Back_Movement_Rocket2Exit
    applymovement LOCALID_ROCKET3, IcefallCave_Back_Movement_Rocket3Exit
    waitmovement 0
    removeobject LOCALID_ROCKET1
    removeobject LOCALID_ROCKET2
    removeobject LOCALID_ROCKET3
    delay 50
    applymovement LOCALID_LORELEI, IcefallCave_Back_Movement_LoreleiWalkToPlayer
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    msgbox IcefallCave_Back_Text_ThankYouThisIsAwful, MSGBOX_DEFAULT
    setflag FLAG_HIDE_RUIN_VALLEY_SCIENTIST
    clearflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
    setvar VAR_MAP_SCENE_ICEFALL_CAVE_BACK, 1
    releaseall
    end

IcefallCave_Back_Movement_PlayerToRockets::
    walk_up
    walk_up
    walk_right
    walk_up
    step_end

IcefallCave_Back_Movement_PlayerWatchRocketsExit::
    delay_16
    walk_in_place_faster_left
    delay_16
    delay_16
    walk_in_place_faster_down
    step_end

IcefallCave_Back_Movement_WalkInPlaceDown::
    walk_in_place_down
    step_end

IcefallCave_Back_Movement_UnusedPushRight::
    lock_facing_direction
    walk_right
    unlock_facing_direction
    step_end

IcefallCave_Back_Movement_Rocket1ReactToThreat::
    walk_in_place_fast_down
    step_end

IcefallCave_Back_Movement_Rocket1Exit::
    walk_right
    walk_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    step_end

IcefallCave_Back_Movement_Rocket2Exit::
    delay_16
    walk_left
    walk_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    step_end

IcefallCave_Back_Movement_Rocket3Exit::
    delay_16
    walk_down
    delay_16
    walk_down
    walk_fast_right
    walk_fast_right
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    step_end

IcefallCave_Back_Movement_Rocket3FaceLorelei::
    delay_16
    delay_8
    walk_in_place_faster_right
    step_end

IcefallCave_Back_Movement_UnusedWalkLeft::
    walk_left
    walk_left
    step_end

IcefallCave_Back_Movement_LoreleiToRockets::
    walk_left
    walk_up
    step_end

IcefallCave_Back_Movement_WalkInPlaceUp::
    walk_in_place_up
    step_end

IcefallCave_Back_Movement_LoreleiWatchRocketsExit::
    delay_8
    walk_in_place_faster_right
    delay_16
    delay_16
    walk_in_place_faster_down
    step_end

IcefallCave_Back_Movement_LoreleiWalkToPlayer::
    walk_right
    step_end

IcefallCave_Back_EventScript_Lorelei::
    msgbox IcefallCave_Back_Text_ThankYouThisIsAwful, MSGBOX_NPC
    end

IcefallCave_Back_Text_LoreleiKeepHandsOffMons::
    .string "Lorelei: Keep your filthy hands\n"
    .string "off the Pokémon in the cave!\p"
    .string "Do as I say, or you'll have me to\n"
    .string "answer to!$"

IcefallCave_Back_Text_ShutItLadyLeaveUsBe::
    .string "Aww, shut it, lady, and leave\n"
    .string "us be.\p"
    .string "Don't let your glasses get all\n"
    .string "steamed up!$"

IcefallCave_Back_Text_LoreleiPlayerHelpMeKickPoachersOut::
    .string "Lorelei: {PLAYER}?!\n"
    .string "What are you doing here?\p"
    .string "No, we can catch up later.\n"
    .string "Right now, I need your help.\p"
    .string "Help me kick these poachers out\n"
    .string "before they do anything else.\p"
    .string "They've been catching Pokémon\n"
    .string "here, then selling them off!\p"
    .string "Are you ready?\n"
    .string "You take that one, please!$"

IcefallCave_Back_Text_GruntIntro::
    .string "W-what?!\p"
    .string "Who says we can't do what we want\n"
    .string "with the Pokémon we catch?$"

IcefallCave_Back_Text_GruntDefeat::
    .string "We didn't plan on this!$"

IcefallCave_Back_Text_LoreleiWhereHaveYouTakenMons::
    .string "Lorelei: Humph.\n"
    .string "So despicably weak.\p"
    .string "You!\n"
    .string "Tell me!\p"
    .string "Where have you taken the captured\n"
    .string "Pokémon?\p"
    .string "I'm smashing your ring once and\n"
    .string "for all!$"

IcefallCave_Back_Text_NotTellingYouThat::
    .string "N-no way!\n"
    .string "I'm not telling you that!$"

IcefallCave_Back_Text_LoreleiWellDeepFreezeYou::
    .string "Lorelei: If you won't confess,\n"
    .string "we'll deep-freeze you.\p"
    .string "My Lapras is furious for what\n"
    .string "you've done to its friends.\p"
    .string "Go, Lapras!\n"
    .string "Ice Beam…$"

IcefallCave_Back_Text_OkayRocketWareHouseFiveIsland::
    .string "Wawaah! Okay!\n"
    .string "I'll talk!\p"
    .string "The Pokémon are in the Rocket\n"
    .string "Warehouse on Five Island.\p"
    .string "There! I said it!\n"
    .string "We'll be going now!\p"
    .string "…But I doubt you'll ever make it\n"
    .string "into the Rocket Warehouse!\p"
    .string "Heheheheh!$"

IcefallCave_Back_Text_ThankYouThisIsAwful::
    .string "{PLAYER}, thank you.\n"
    .string "But this is awful…\p"
    .string "I was born and raised here on\n"
    .string "these islands.\p"
    .string "I had no idea that those horrible\n"
    .string "criminals were loose here…$"

