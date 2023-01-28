.equ LOCALID_MUSEUM_GUIDE, 2
.equ LOCALID_GYM_GUIDE,    5
.equ LOCALID_AIDE,         7

PewterCity_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_OnTransition
    .byte 0

PewterCity_OnTransition:
    setflag FLAG_WORLD_MAP_PEWTER_CITY
    setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 0
    end

PewterCity_EventScript_Lass::
    msgbox PewterCity_Text_ClefairyCameFromMoon, MSGBOX_NPC
    end

PewterCity_EventScript_MuseumGuide::
    lock
    faceplayer
    msgbox PewterCity_Text_DidYouCheckOutMuseum, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq PewterCity_EventScript_CheckedOutMuseum
    msgbox PewterCity_Text_ReallyYouHaveToGo, MSGBOX_DEFAULT
    closemessage
    delay 10
    playbgm MUS_RG_FOLLOW_ME, 0
    compare VAR_FACING, DIR_NORTH
    call_if_eq PewterCity_EventScript_LeadToMuseumNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq PewterCity_EventScript_LeadToMuseumSouth
    compare VAR_FACING, DIR_WEST
    call_if_eq PewterCity_EventScript_LeadToMuseumWest
    compare VAR_FACING, DIR_EAST
    call_if_eq PewterCity_EventScript_LeadToMuseumEast
    msgbox PewterCity_Text_ThisIsTheMuseum, MSGBOX_DEFAULT
    closemessage
    delay 10
    applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_MuseumGuideExit
    waitmovement 0
    fadedefaultbgm
    removeobject LOCALID_MUSEUM_GUIDE
    clearflag FLAG_HIDE_PEWTER_MUSEUM_GUIDE
    release
    end

PewterCity_EventScript_CheckedOutMuseum::
    msgbox PewterCity_Text_WerentThoseFossilsAmazing, MSGBOX_DEFAULT
    release
    end

PewterCity_EventScript_LeadToMuseumNorth::
    applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumNorth
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumNorth
    waitmovement 0
    return

PewterCity_EventScript_LeadToMuseumSouth::
    applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumSouth
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumSouth
    waitmovement 0
    return

PewterCity_EventScript_LeadToMuseumWest::
    applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumWest
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumWest
    waitmovement 0
    return

PewterCity_EventScript_LeadToMuseumEast::
    applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumEast
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumEast
    waitmovement 0
    return

PewterCity_Movement_PlayerWalkToMuseumNorth::
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    delay_8
    walk_in_place_faster_up
    step_end

PewterCity_Movement_GuideWalkToMuseumNorth::
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_in_place_faster_up
    step_end

PewterCity_Movement_PlayerWalkToMuseumSouth::
    delay_16
    delay_16
    walk_left
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    delay_8
    walk_in_place_faster_up
    step_end

PewterCity_Movement_GuideWalkToMuseumSouth::
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_in_place_faster_up
    step_end

PewterCity_Movement_PlayerWalkToMuseumWest::
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    delay_8
    walk_in_place_faster_up
    step_end

PewterCity_Movement_GuideWalkToMuseumWest::
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_in_place_faster_up
    step_end

PewterCity_Movement_PlayerWalkToMuseumEast::
    walk_right
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    delay_8
    walk_in_place_faster_up
    step_end

PewterCity_Movement_GuideWalkToMuseumEast::
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_in_place_faster_up
    step_end

PewterCity_Movement_MuseumGuideExit::
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    step_end

PewterCity_EventScript_FatMan::
    lock
    faceplayer
    msgbox PewterCity_Text_BrockOnlySeriousTrainerHere, MSGBOX_DEFAULT
    release
    end

PewterCity_EventScript_BugCatcher::
    lock
    faceplayer
    msgbox PewterCity_Text_DoYouKnowWhatImDoing, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq PewterCity_EventScript_KnowWhatTheyreDoing
    msgbox PewterCity_Text_SprayingRepelToKeepWildMonsOut, MSGBOX_DEFAULT
    release
    end

PewterCity_EventScript_KnowWhatTheyreDoing::
    msgbox PewterCity_Text_ThatsRightItsHardWork, MSGBOX_DEFAULT
    release
    end

PewterCity_EventScript_GymGuide::
    lock
    faceplayer
    msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_RG_FOLLOW_ME, 0
    compare VAR_FACING, DIR_EAST
    call_if_eq PewterCity_EventScript_WalkToGymEast
    msgbox PewterCity_Text_GoTakeOnBrock, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GymGuideExit
    waitmovement 0
    fadedefaultbgm
    removeobject LOCALID_GYM_GUIDE
    clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
    release
    end

PewterCity_EventScript_WalkToGymEast::
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWaitForGuideEast
    applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadEast
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymEast
    applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymEast
    waitmovement 0
    return

PewterCity_Movement_PlayerWaitForGuideEast::
    delay_16
    delay_16
    delay_4
    walk_in_place_faster_down
    step_end

PewterCity_Movement_GuideMoveToLeadEast::
    walk_down
    walk_left
    walk_in_place_faster_up
    walk_in_place_up
    step_end

PewterCity_Movement_PlayerWalkToGymEast::
    walk_down
    walk_left
    walk_left
    walk_left
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

PewterCity_Movement_GuideWalkToGymEast::
    walk_left
    walk_left
    walk_left
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_in_place_faster_left
    step_end

PewterCity_Movement_GymGuideExit::
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

PewterCity_EventScript_GymGuideTriggerTop::
    lockall
    setvar VAR_TEMP_1, 0
    goto PewterCity_EventScript_GymGuideTrigger
    end

PewterCity_EventScript_GymGuideTriggerMid::
    lockall
    setvar VAR_TEMP_1, 1
    goto PewterCity_EventScript_GymGuideTrigger
    end

PewterCity_EventScript_GymGuideTriggerBottom::
    lockall
    setvar VAR_TEMP_1, 2
    goto PewterCity_EventScript_GymGuideTrigger
    end

PewterCity_EventScript_GymGuideTrigger::
    msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_RG_FOLLOW_ME, 0
    compare VAR_TEMP_1, 0
    call_if_eq PewterCity_EventScript_WalkToGymTop
    compare VAR_TEMP_1, 1
    call_if_eq PewterCity_EventScript_WalkToGymMid
    compare VAR_TEMP_1, 2
    call_if_eq PewterCity_EventScript_WalkToGymBottom
    msgbox PewterCity_Text_GoTakeOnBrock, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GymGuideExit
    waitmovement 0
    fadedefaultbgm
    removeobject LOCALID_GYM_GUIDE
    clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
    releaseall
    end

PewterCity_EventScript_WalkToGymTop::
    applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadTop
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymTop
    applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymTop
    waitmovement 0
    return

PewterCity_Movement_GuideMoveToLeadTop::
    walk_left
    walk_down
    walk_in_place_faster_right
    walk_in_place_right
    step_end

PewterCity_Movement_PlayerWalkToGymTop::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

PewterCity_Movement_GuideWalkToGymTop::
    walk_left
    walk_left
    walk_left
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_in_place_faster_left
    step_end

PewterCity_EventScript_WalkToGymMid::
    applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadMid
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymMid
    applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymMid
    waitmovement 0
    return

PewterCity_Movement_GuideMoveToLeadMid::
    walk_down
    walk_in_place_down
    step_end

PewterCity_Movement_PlayerWalkToGymMid::
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

PewterCity_Movement_GuideWalkToGymMid::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_in_place_faster_left
    step_end

PewterCity_EventScript_WalkToGymBottom::
    applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadBottom
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymBottom
    applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymBottom
    waitmovement 0
    return

PewterCity_Movement_GuideMoveToLeadBottom::
    walk_down
    walk_down
    walk_in_place_down
    step_end

PewterCity_Movement_PlayerWalkToGymBottom::
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

PewterCity_Movement_GuideWalkToGymBottom::
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_in_place_faster_left
    step_end

PewterCity_EventScript_PokenavAide::
    lock
    faceplayer
    setvar VAR_TEMP_1, 0
    call PewterCity_EventScript_AideGivePokenav
    release
    end

PewterCity_EventScript_PokenavAideTriggerTop::
    lockall
    setvar VAR_TEMP_1, 1
    call PewterCity_EventScript_AideGivePokenav
    releaseall
    end

PewterCity_EventScript_PokenavAideTriggerMid::
    lockall
    setvar VAR_TEMP_1, 2
    call PewterCity_EventScript_AideGivePokenav
    releaseall
    end

PewterCity_EventScript_PokenavAideTriggerBottom::
    lockall
    setvar VAR_TEMP_1, 3
    call PewterCity_EventScript_AideGivePokenav
    releaseall
    end

PewterCity_EventScript_AideGivePokenav::
    compare VAR_TEMP_1, 1
    call_if_eq PewterCity_EventScript_AideNoticePlayer
    compare VAR_TEMP_1, 2
    call_if_eq PewterCity_EventScript_AideNoticePlayer
    compare VAR_TEMP_1, 3
    call_if_eq PewterCity_EventScript_AideNoticePlayer
    waitse
    playse SE_PIN
    applymovement LOCALID_AIDE, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_AIDE, Common_Movement_Delay48
    waitmovement 0
    msgbox PewterCity_Text_OhPlayer, MSGBOX_DEFAULT
    compare VAR_TEMP_1, 0
    call_if_eq PewterCity_EventScript_AideApproachPlayer0
    compare VAR_TEMP_1, 1
    call_if_eq PewterCity_EventScript_AideApproachPlayer1
    compare VAR_TEMP_1, 2
    call_if_eq PewterCity_EventScript_AideApproachPlayer2
    compare VAR_TEMP_1, 3
    call_if_eq PewterCity_EventScript_AideApproachPlayer3
    msgbox PewterCity_Text_AskedToDeliverThis, MSGBOX_DEFAULT
    playfanfare MUS_RG_OBTAIN_KEY_ITEM
    message PewterCity_Text_ReceivedPokenavFromAide
    waitmessage
    waitfanfare
    setflag FLAG_SYS_POKENAV_GET
    setflag FLAG_RECEIVED_POKENAV
    setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
    setflag FLAG_ENABLE_MOM_MATCH_CALL
    msgbox PewterCity_Text_AideExplainPokenavRestUp, MSGBOX_DEFAULT
    closemessage
    call Common_EventScript_OutOfCenterPartyHeal
    call PewterCity_EventScript_AideNoticePlayer
    msgbox PewterCity_Text_MustBeGoingBackToLab, MSGBOX_DEFAULT
    closemessage
    compare VAR_TEMP_1, 0
    call_if_eq PewterCity_EventScript_AideExit0
    compare VAR_TEMP_1, 1
    call_if_eq PewterCity_EventScript_AideExit1
    compare VAR_TEMP_1, 2
    call_if_eq PewterCity_EventScript_AideExit2
    compare VAR_TEMP_1, 3
    call_if_eq PewterCity_EventScript_AideExit3
    delay 30
    msgbox PewterCity_Text_RunningShoesLetterFromMom, MSGBOX_DEFAULT
    closemessage
    removeobject LOCALID_AIDE
    setvar VAR_MAP_SCENE_PEWTER_CITY, 2
    setvar VAR_OAK_CALL_STEP_COUNTER, 0
    setflag FLAG_ENABLE_PROF_OAK_FIRST_CALL
    return

PewterCity_EventScript_AideNoticePlayer::
    applymovement LOCALID_AIDE, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

PewterCity_EventScript_AideApproachPlayer0::
    closemessage
    delay 20
    return

PewterCity_EventScript_AideApproachPlayer1::
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

PewterCity_EventScript_AideApproachPlayer2::
    closemessage
    applymovement LOCALID_AIDE, PewterCity_Movement_AideApproachPlayerMid
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

PewterCity_Movement_AideApproachPlayerMid::
    delay_4
    walk_down
    step_end

PewterCity_EventScript_AideApproachPlayer3::
    closemessage
    applymovement LOCALID_AIDE, PewterCity_Movement_AideApproachPlayerBottom
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

PewterCity_Movement_AideApproachPlayerBottom::
    delay_4
    walk_down
    walk_down
    step_end

PewterCity_EventScript_AideExit0::
    applymovement LOCALID_AIDE, PewterCity_Movement_AideExit0
    waitmovement 0
    return

PewterCity_EventScript_AideExit1::
    applymovement LOCALID_AIDE, PewterCity_Movement_AideExit1
    waitmovement 0
    return

PewterCity_EventScript_AideExit2::
    applymovement LOCALID_AIDE, PewterCity_Movement_AideExit2
    waitmovement 0
    return

PewterCity_EventScript_AideExit3::
    applymovement LOCALID_AIDE, PewterCity_Movement_AideExit3
    waitmovement 0
    return

PewterCity_Movement_AideExit0::
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

PewterCity_Movement_AideExit1::
    walk_left
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

PewterCity_Movement_AideExit2::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

PewterCity_Movement_AideExit3::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

PewterCity_EventScript_RegisterOak::
    lockall
    pokenavcall PewterCity_Text_OakRegisterCall
    waitmessage
    delay 30
    playfanfare MUS_REGISTER_MATCH_CALL
    msgbox PewterCity_Text_RegisteredOak, MSGBOX_DEFAULT
    waitfanfare
    closemessage
    delay 30
    setflag FLAG_ENABLE_PROF_OAK_MATCH_CALL
    clearflag FLAG_ENABLE_PROF_OAK_FIRST_CALL
    releaseall
    end

PewterCity_EventScript_MuseumSign::
    msgbox PewterCity_Text_MuseumOfScience, MSGBOX_SIGN
    end

PewterCity_EventScript_PoliceNotice::
    msgbox PewterCity_Text_CallPoliceIfInfoOnThieves, MSGBOX_SIGN
    end

PewterCity_EventScript_GymSign::
    lockall
    msgbox PewterCity_Text_GymSign, MSGBOX_SIGN
    releaseall
    end

PewterCity_EventScript_TrainerTips::
    msgbox PewterCity_Text_TrainerTipsEarningEXP, MSGBOX_SIGN
    end

PewterCity_EventScript_CitySign::
    msgbox PewterCity_Text_CitySign, MSGBOX_SIGN
    end

PewterCity_Text_ClefairyCameFromMoon::
    .string "Clefairy came from the moon.\n"
    .string "That's what the rumor is.\p"
    .string "They appeared after Moon Stones\n"
    .string "fell on Mt. Moon.$"

PewterCity_Text_DidYouCheckOutMuseum::
    .string "Did you check out the Museum?$"

PewterCity_Text_WerentThoseFossilsAmazing::
    .string "Weren't those fossils from Mt. Moon\n"
    .string "amazing?$"

PewterCity_Text_ReallyYouHaveToGo::
    .string "Really?\n"
    .string "You absolutely have to go!$"

PewterCity_Text_ThisIsTheMuseum::
    .string "This is it, the Museum.\p"
    .string "You have to pay to get in, but it's\n"
    .string "worth it. See you around!$"

PewterCity_Text_BrockOnlySeriousTrainerHere::
    .string "There aren't many serious Pokémon\n"
    .string "Trainers here.\p"
    .string "They're all like Bug Catchers,\n"
    .string "you know, just hobbyists.\p"
    .string "But Pewter Gym's Brock isn't like\n"
    .string "that, not one bit.$"

PewterCity_Text_DoYouKnowWhatImDoing::
    .string "Psssst!\n"
    .string "Do you know what I'm doing?$"

PewterCity_Text_SprayingRepelToKeepWildMonsOut::
    .string "I'm spraying Repel to keep wild\n"
    .string "Pokémon out of my garden!$"

PewterCity_Text_ThatsRightItsHardWork::
    .string "That's right!\n"
    .string "It's hard work!$"

PewterCity_Text_BrocksLookingForChallengersFollowMe::
    .string "You're a Trainer, right?\p"
    .string "Brock's looking for new\n"
    .string "challengers. Follow me!$"

PewterCity_Text_GoTakeOnBrock::
    .string "If you have the right stuff,\n"
    .string "go take on Brock!$"

PewterCity_Text_OhPlayer::
    .string "Oh, {PLAYER}!$"

PewterCity_Text_AskedToDeliverThis::
    .string "I'm glad I caught up to you.\n"
    .string "I'm Prof. Oak's Aide.\p"
    .string "I've been asked to deliver this,\n"
    .string "so here you go.$"

PewterCity_Text_ReceivedPokenavFromAide::
    .string "{PLAYER} received the\n"
    .string "Pokénav from the Aide.$"

PewterCity_Text_AideExplainPokenavRestUp:
    .string "Aide: That device…\p"
    .string "It's a Pokémon Navigator, or Pokénav\n"
    .string "for short.\p"
    .string "It's an indispensable tool for any\n"
    .string "Trainer on an adventure.\p"
    .string "It has a map of the Kanto region\n"
    .string "to help you on your journey!\p"
    .string "By the way, I've heard that sinister\n"
    .string "criminals--Team Rocket, I believe--\l"
    .string "have been making trouble far and wide.\p"
    .string "I think it would be best if you rested\n"
    .string "up before you go on your way.$"

PewterCity_Text_MustBeGoingBackToLab::
    .string "Well, I must be going back to\n"
    .string "the lab.\p"
    .string "Bye-bye!$"

PewterCity_Text_RunningShoesLetterFromMom::
    .string "There's a letter attached…\p"
    .string "Dear {PLAYER},\p"
    .string "Here is a Pokénav for\n"
    .string "my beloved challenger.\p"
    .string "Remember, I'll always cheer for\n"
    .string "you! Don't ever give up!\p"
    .string "From Mom$"

PewterCity_Text_OakRegisterCall:
    .string "… … … … … …\n"
    .string "… … … … … Beep!\p"
    .string "Prof. Oak: Oh, hello, {PLAYER}?\n"
    .string "This is Prof. Oak.\p"
    .string "I see my Aide has delivered the\n"
    .string "Pokénav! Excellent!\p"
    .string "Now I'll be able to rate your\n"
    .string "Pokédex, even when we're apart.\p"
    .string "And where might {RIVAL} be?\n"
    .string "… … … … … …\p"
    .string "Oh, I see!\n"
    .string "You two are running separately.\l"
    .string "Well, that's fine.\p"
    .string "Well, I had better get going.\n"
    .string "See you again, {PLAYER}!\l"
    .string "Please keep an eye out for\l"
    .string "{RIVAL} for me.\p"
    .string "… … … … … …\n"
    .string "… … … … … Click!$"

PewterCity_Text_RegisteredOak:
    .string "Registered Prof. Oak\n"
    .string "in the Pokénav.$"

PewterCity_Text_MuseumOfScience::
    .string "Pewter Museum Of Science$"

PewterCity_Text_CallPoliceIfInfoOnThieves::
    .string "NOTICE!\p"
    .string "Thieves have been stealing Pokémon\n"
    .string "fossils from Mt. Moon.\p"
    .string "Please call the Pewter Police if\n"
    .string "you have any information.$"

PewterCity_Text_GymSign::
    .string "Pewter City Pokémon Gym\n"
    .string "Leader: Brock\l"
    .string "The Rock-Solid Pokémon Trainer!$"

PewterCity_Text_TrainerTipsEarningEXP::
    .string "Trainer Tips\p"
    .string "All Pokémon that appear in battle,\n"
    .string "however briefly, earn Exp. Points.$"

PewterCity_Text_CitySign::
    .string "PEWTER CITY\n"
    .string "A Stone Gray City$"
