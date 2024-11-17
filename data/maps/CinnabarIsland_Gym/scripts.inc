.set LOCALID_QUINN, 2
.set LOCALID_AVERY, 4
.set LOCALID_RAMON, 5
.set LOCALID_DEREK, 6
.set LOCALID_DUSTY, 7
.set LOCALID_ZAC,   8

CinnabarIsland_Gym_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_Gym_OnLoad
	.byte 0

CinnabarIsland_Gym_OnLoad:
    goto_if_set FLAG_DEFEATED_BLAINE, CinnabarIsland_Gym_OnLoadOpenAllDoors
    call_if_set FLAG_CINNABAR_GYM_QUIZ_1, CinnabarIsland_Gym_OnLoadOpenDoor1
    call_if_set FLAG_CINNABAR_GYM_QUIZ_2, CinnabarIsland_Gym_OnLoadOpenDoor2
    call_if_set FLAG_CINNABAR_GYM_QUIZ_3, CinnabarIsland_Gym_OnLoadOpenDoor3
    call_if_set FLAG_CINNABAR_GYM_QUIZ_4, CinnabarIsland_Gym_OnLoadOpenDoor4
    call_if_set FLAG_CINNABAR_GYM_QUIZ_5, CinnabarIsland_Gym_OnLoadOpenDoor5
    call_if_set FLAG_CINNABAR_GYM_QUIZ_6, CinnabarIsland_Gym_OnLoadOpenDoor6
    end

CinnabarIsland_Gym_OnLoadOpenAllDoors::
    call CinnabarIsland_Gym_EventScript_OpenDoor1
    call CinnabarIsland_Gym_EventScript_OpenDoor2
    call CinnabarIsland_Gym_EventScript_OpenDoor3
    call CinnabarIsland_Gym_EventScript_OpenDoor4
    call CinnabarIsland_Gym_EventScript_OpenDoor5
    call CinnabarIsland_Gym_EventScript_OpenDoor6
    end

CinnabarIsland_Gym_OnLoadOpenDoor1::
    call CinnabarIsland_Gym_EventScript_OpenDoor1
    return

CinnabarIsland_Gym_OnLoadOpenDoor2::
    call CinnabarIsland_Gym_EventScript_OpenDoor2
    return

CinnabarIsland_Gym_OnLoadOpenDoor3::
    call CinnabarIsland_Gym_EventScript_OpenDoor3
    return

CinnabarIsland_Gym_OnLoadOpenDoor4::
    call CinnabarIsland_Gym_EventScript_OpenDoor4
    return

CinnabarIsland_Gym_OnLoadOpenDoor5::
    call CinnabarIsland_Gym_EventScript_OpenDoor5
    return

CinnabarIsland_Gym_OnLoadOpenDoor6::
    call CinnabarIsland_Gym_EventScript_OpenDoor6
    return

CinnabarIsland_Gym_EventScript_Blaine::
    trainerbattle_single TRAINER_LEADER_BLAINE, CinnabarIsland_Gym_Text_BlaineIntro, CinnabarIsland_Gym_Text_BlaineDefeat, CinnabarIsland_Gym_EventScript_DefeatedBlaine, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_Gym_EventScript_BlaineRematch
    goto_if_unset FLAG_GOT_TM38_FROM_BLAINE, CinnabarIsland_Gym_EventScript_GiveTM38
    msgbox CinnabarIsland_Gym_Text_BlainePostBattle, MSGBOX_DEFAULT
    release
    end

CinnabarIsland_Gym_EventScript_DefeatedBlaine::
    message CinnabarIsland_Gym_Text_ReceivedVolcanoBadge
    waitmessage
    call Common_EventScript_PlayGymBadgeFanfare
    msgbox CinnabarIsland_Gym_Text_ExplainVolcanoBadge, MSGBOX_DEFAULT
    setflag FLAG_DEFEATED_BLAINE
    setflag FLAG_BADGE07_GET
    setrespawn HEAL_LOCATION_CINNABAR_ISLAND
    setvar VAR_0x8008, 7
    call Common_EventScript_SetGymTrainers
    goto CinnabarIsland_Gym_EventScript_GiveTM38
    end

CinnabarIsland_Gym_EventScript_GiveTM38::
    checkitemspace ITEM_TM38, 1
    compare VAR_RESULT, FALSE
    goto_if_eq CinnabarIsland_Gym_EventScript_NoRoomForTM38
    giveitem_msg CinnabarIsland_Gym_Text_ReceivedTM38FromBlaine, ITEM_TM38
    setflag FLAG_GOT_TM38_FROM_BLAINE
    msgbox CinnabarIsland_Gym_Text_FireBlastIsUltimateFireMove, MSGBOX_DEFAULT
    closemessage
    delay 30
    playfanfare MUS_REGISTER_MATCH_CALL
    msgbox CinnabarIsland_Gym_Text_RegisteredBlaine, MSGBOX_DEFAULT
    waitfanfare
    closemessage
    delay 30
    setflag FLAG_ENABLE_BLAINE_MATCH_CALL
    release
    end

CinnabarIsland_Gym_EventScript_NoRoomForTM38::
    msgbox CinnabarIsland_Gym_Text_MakeSpaceForThis, MSGBOX_DEFAULT
    release
    end

CinnabarIsland_Gym_EventScript_BlaineRematch::
	trainerbattle_rematch_double TRAINER_LEADER_BLAINE, CinnabarIsland_Gym_Text_BlainePreRematch, CinnabarIsland_Gym_Text_BlaineRematchDefeat, CinnabarIsland_Gym_Text_BlaineRematchNeedTwoMons
	msgbox CinnabarIsland_Gym_Text_BlainePostRematch, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_Erik::
    trainerbattle_single TRAINER_SUPER_NERD_ERIK, CinnabarIsland_Gym_Text_ErikIntro, CinnabarIsland_Gym_Text_ErikDefeat
    msgbox CinnabarIsland_Gym_Text_ErikPostBattle, MSGBOX_AUTOCLOSE
    end

CinnabarIsland_Gym_EventScript_Avery::
    trainerbattle_single TRAINER_SUPER_NERD_AVERY, CinnabarIsland_Gym_Text_AveryIntro, CinnabarIsland_Gym_Text_AveryDefeat, CinnabarIsland_Gym_EventScript_DefeatedAvery
    msgbox CinnabarIsland_Gym_Text_AveryPostBattle, MSGBOX_AUTOCLOSE
    end

CinnabarIsland_Gym_EventScript_DefeatedAvery::
    call_if_unset FLAG_CINNABAR_GYM_QUIZ_2, CinnabarIsland_Gym_EventScript_Quiz2CompleteTrainer
    release
    end

CinnabarIsland_Gym_EventScript_Quiz2CompleteTrainer::
    call CinnabarIsland_Gym_EventScript_Quiz2Complete
    return

CinnabarIsland_Gym_EventScript_Derek::
    trainerbattle_single TRAINER_SUPER_NERD_DEREK, CinnabarIsland_Gym_Text_DerekIntro, CinnabarIsland_Gym_Text_DerekDefeat, CinnabarIsland_Gym_EventScript_DefeatedDerek
    msgbox CinnabarIsland_Gym_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
    end

CinnabarIsland_Gym_EventScript_DefeatedDerek::
    call_if_unset FLAG_CINNABAR_GYM_QUIZ_4, CinnabarIsland_Gym_EventScript_Quiz4CompleteTrainer
    release
    end

CinnabarIsland_Gym_EventScript_Quiz4CompleteTrainer::
    call CinnabarIsland_Gym_EventScript_Quiz4Complete
    return

CinnabarIsland_Gym_EventScript_Zac::
    trainerbattle_single TRAINER_SUPER_NERD_ZAC, CinnabarIsland_Gym_Text_ZacIntro, CinnabarIsland_Gym_Text_ZacDefeat, CinnabarIsland_Gym_EventScript_DefeatedZac
    msgbox CinnabarIsland_Gym_Text_ZacPostBattle, MSGBOX_AUTOCLOSE
    end

CinnabarIsland_Gym_EventScript_DefeatedZac::
    call_if_unset FLAG_CINNABAR_GYM_QUIZ_6, CinnabarIsland_Gym_EventScript_Quiz6CompleteTrainer
    release
    end

CinnabarIsland_Gym_EventScript_Quiz6CompleteTrainer::
    call CinnabarIsland_Gym_EventScript_Quiz6Complete
    return

CinnabarIsland_Gym_EventScript_Quinn::
    trainerbattle_single TRAINER_BURGLAR_QUINN, CinnabarIsland_Gym_Text_QuinnIntro, CinnabarIsland_Gym_Text_QuinnDefeat, CinnabarIsland_Gym_EventScript_DefeatedQuinn
    msgbox CinnabarIsland_Gym_Text_QuinnPostBattle, MSGBOX_AUTOCLOSE
    end

CinnabarIsland_Gym_EventScript_DefeatedQuinn::
    call_if_unset FLAG_CINNABAR_GYM_QUIZ_1, CinnabarIsland_Gym_EventScript_Quiz1CompleteTrainer
    release
    end

CinnabarIsland_Gym_EventScript_Quiz1CompleteTrainer::
    call CinnabarIsland_Gym_EventScript_Quiz1Complete
    return

CinnabarIsland_Gym_EventScript_Ramon::
    trainerbattle_single TRAINER_BURGLAR_RAMON, CinnabarIsland_Gym_Text_RamonIntro, CinnabarIsland_Gym_Text_RamonDefeat, CinnabarIsland_Gym_EventScript_DefeatedRamon
    msgbox CinnabarIsland_Gym_Text_RamonPostBattle, MSGBOX_AUTOCLOSE
    end

CinnabarIsland_Gym_EventScript_DefeatedRamon::
    call_if_unset FLAG_CINNABAR_GYM_QUIZ_3, CinnabarIsland_Gym_EventScript_Quiz3CompleteTrainer
    release
    end

CinnabarIsland_Gym_EventScript_Quiz3CompleteTrainer::
    call CinnabarIsland_Gym_EventScript_Quiz3Complete
    return

CinnabarIsland_Gym_EventScript_Dusty::
    trainerbattle_single TRAINER_BURGLAR_DUSTY, CinnabarIsland_Gym_Text_DustyIntro, CinnabarIsland_Gym_Text_DustyDefeat, CinnabarIsland_Gym_EventScript_DefeatedDusty
    msgbox CinnabarIsland_Gym_Text_DustyPostBattle, MSGBOX_AUTOCLOSE
    end

CinnabarIsland_Gym_EventScript_DefeatedDusty::
    call_if_unset FLAG_CINNABAR_GYM_QUIZ_5, CinnabarIsland_Gym_EventScript_Quiz5CompleteTrainer
    release
    end

CinnabarIsland_Gym_EventScript_Quiz5CompleteTrainer::
    call CinnabarIsland_Gym_EventScript_Quiz5Complete
    return

CinnabarIsland_Gym_EventScript_Quiz1Left::
    lockall
    setvar VAR_TEMP_1, 0
    goto CinnabarIsland_Gym_EventScript_Quiz1
    end

CinnabarIsland_Gym_EventScript_Quiz1Right::
    lockall
    setvar VAR_TEMP_1, 1
    goto CinnabarIsland_Gym_EventScript_Quiz1
    end

CinnabarIsland_Gym_EventScript_Quiz1::
    msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
    msgbox CinnabarIsland_Gym_Text_QuizQuestion1, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz1Correct
    compare VAR_RESULT, NO
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz1Incorrect
    end

CinnabarIsland_Gym_EventScript_CorrectAnswer::
    playfanfare MUS_LEVEL_UP
    waitfanfare
    msgbox CinnabarIsland_Gym_Text_CorrectGoOnThrough, MSGBOX_DEFAULT
    return

CinnabarIsland_Gym_EventScript_IncorrectAnswer::
    waitse
    playse SE_BOO
    waitse
    msgbox CinnabarIsland_Gym_Text_SorryBadCall, MSGBOX_DEFAULT
    closemessage
    return

CinnabarIsland_Gym_EventScript_Quiz1Correct::
    call CinnabarIsland_Gym_EventScript_CorrectAnswer
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_1, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz1Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_Quiz1Complete::
    playse SE_UNLOCK
    waitse
    call CinnabarIsland_Gym_EventScript_OpenDoor1
    special DrawWholeMapView
    setflag FLAG_CINNABAR_GYM_QUIZ_1
    return

CinnabarIsland_Gym_EventScript_DoorAlreadyOpen::
    releaseall
    end

CinnabarIsland_Gym_EventScript_Quiz1Incorrect::
    call CinnabarIsland_Gym_EventScript_IncorrectAnswer
    goto_if_not_defeated TRAINER_BURGLAR_QUINN, CinnabarIsland_Gym_EventScript_BattleQuinn
    releaseall
    end

CinnabarIsland_Gym_EventScript_BattleQuinn::
    compare VAR_TEMP_1, 0
    call_if_eq CinnabarIsland_Gym_EventScript_QuinnApproachLeft
    compare VAR_TEMP_1, 1
    call_if_eq CinnabarIsland_Gym_EventScript_QuinnApproachRight
    msgbox CinnabarIsland_Gym_Text_QuinnIntro, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_BURGLAR_QUINN, CinnabarIsland_Gym_Text_QuinnDefeat
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_1, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz1Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_QuinnApproachLeft::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_QUINN, CinnabarIsland_Gym_Movement_QuinnApproachLeft
    waitmovement 0
    return

CinnabarIsland_Gym_EventScript_QuinnApproachRight::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_QUINN, CinnabarIsland_Gym_Movement_QuinnApproachRight
    waitmovement 0
    return

CinnabarIsland_Gym_Movement_QuinnApproachLeft::
    walk_left
    walk_left
    step_end

CinnabarIsland_Gym_Movement_QuinnApproachRight::
    walk_left
    step_end

CinnabarIsland_Gym_EventScript_Quiz2Left::
    lockall
    setvar VAR_TEMP_1, 0
    goto CinnabarIsland_Gym_EventScript_Quiz2
    end

CinnabarIsland_Gym_EventScript_Quiz2Right::
    lockall
    setvar VAR_TEMP_1, 1
    goto CinnabarIsland_Gym_EventScript_Quiz2
    end

CinnabarIsland_Gym_EventScript_Quiz2::
    msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
    msgbox CinnabarIsland_Gym_Text_QuizQuestion2, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz2Incorrect
    compare VAR_RESULT, NO
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz2Correct
    end

CinnabarIsland_Gym_EventScript_Quiz2Correct::
    call CinnabarIsland_Gym_EventScript_CorrectAnswer
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_2, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz2Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_Quiz2Complete::
    playse SE_UNLOCK
    waitse
    call CinnabarIsland_Gym_EventScript_OpenDoor2
    special DrawWholeMapView
    setflag FLAG_CINNABAR_GYM_QUIZ_2
    return

CinnabarIsland_Gym_EventScript_Quiz2Incorrect::
    call CinnabarIsland_Gym_EventScript_IncorrectAnswer
    goto_if_not_defeated TRAINER_SUPER_NERD_AVERY, CinnabarIsland_Gym_EventScript_BattleAvery
    releaseall
    end

CinnabarIsland_Gym_EventScript_BattleAvery::
    compare VAR_TEMP_1, 0
    call_if_eq CinnabarIsland_Gym_EventScript_AveryApproachLeft
    compare VAR_TEMP_1, 1
    call_if_eq CinnabarIsland_Gym_EventScript_AveryApproachRight
    msgbox CinnabarIsland_Gym_Text_AveryIntro, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_SUPER_NERD_AVERY, CinnabarIsland_Gym_Text_AveryDefeat
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_2, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz2Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_AveryApproachLeft::
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Gym_Movement_PlayerFaceAvery
    applymovement LOCALID_AVERY, CinnabarIsland_Gym_Movement_AveryApproachLeft
    waitmovement 0
    return

CinnabarIsland_Gym_EventScript_AveryApproachRight::
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Gym_Movement_PlayerFaceAvery
    applymovement LOCALID_AVERY, CinnabarIsland_Gym_Movement_AveryApproachRight
    waitmovement 0
    return

CinnabarIsland_Gym_Movement_AveryApproachLeft::
    walk_up
    walk_up
    walk_left
    step_end

CinnabarIsland_Gym_Movement_AveryApproachRight::
    walk_up
    walk_up
    walk_in_place_faster_left
    step_end

CinnabarIsland_Gym_Movement_PlayerFaceAvery::
    delay_16
    delay_16
    walk_in_place_faster_right
    step_end

CinnabarIsland_Gym_EventScript_Quiz3Left::
    lockall
    setvar VAR_TEMP_1, 0
    goto CinnabarIsland_Gym_EventScript_Quiz3
    end

CinnabarIsland_Gym_EventScript_Quiz3Right::
    lockall
    setvar VAR_TEMP_1, 1
    goto CinnabarIsland_Gym_EventScript_Quiz3
    end

CinnabarIsland_Gym_EventScript_Quiz3::
    msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
    msgbox CinnabarIsland_Gym_Text_QuizQuestion3, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz3Incorrect
    compare VAR_RESULT, NO
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz3Correct
    end

CinnabarIsland_Gym_EventScript_Quiz3Correct::
    call CinnabarIsland_Gym_EventScript_CorrectAnswer
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_3, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz3Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_Quiz3Complete::
    playse SE_UNLOCK
    waitse
    call CinnabarIsland_Gym_EventScript_OpenDoor3
    special DrawWholeMapView
    setflag FLAG_CINNABAR_GYM_QUIZ_3
    return

CinnabarIsland_Gym_EventScript_Quiz3Incorrect::
    call CinnabarIsland_Gym_EventScript_IncorrectAnswer
    goto_if_not_defeated TRAINER_BURGLAR_RAMON, CinnabarIsland_Gym_EventScript_BattleRamon
    releaseall
    end

CinnabarIsland_Gym_EventScript_BattleRamon::
    compare VAR_TEMP_1, 0
    call_if_eq CinnabarIsland_Gym_EventScript_RamonApproachLeft
    compare VAR_TEMP_1, 1
    call_if_eq CinnabarIsland_Gym_EventScript_RamonApproachRight
    msgbox CinnabarIsland_Gym_Text_RamonIntro, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_BURGLAR_RAMON, CinnabarIsland_Gym_Text_RamonDefeat
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_3, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz3Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_RamonApproachLeft::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_RAMON, CinnabarIsland_Gym_Movement_RamonApproachLeft
    waitmovement 0
    return

CinnabarIsland_Gym_EventScript_RamonApproachRight::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_RAMON, CinnabarIsland_Gym_Movement_RamonApproachRight
    waitmovement 0
    return

CinnabarIsland_Gym_Movement_RamonApproachLeft::
    walk_left
    walk_left
    step_end

CinnabarIsland_Gym_Movement_RamonApproachRight::
    walk_left
    step_end

CinnabarIsland_Gym_EventScript_Quiz4Left::
    lockall
    setvar VAR_TEMP_1, 0
    goto CinnabarIsland_Gym_EventScript_Quiz4
    end

CinnabarIsland_Gym_EventScript_Quiz4Right::
    lockall
    setvar VAR_TEMP_1, 1
    goto CinnabarIsland_Gym_EventScript_Quiz4
    end

CinnabarIsland_Gym_EventScript_Quiz4::
    msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
    msgbox CinnabarIsland_Gym_Text_QuizQuestion4, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz4Incorrect
    compare VAR_RESULT, NO
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz4Correct
    end

CinnabarIsland_Gym_EventScript_Quiz4Correct::
    call CinnabarIsland_Gym_EventScript_CorrectAnswer
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_4, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz4Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_Quiz4Complete::
    playse SE_UNLOCK
    waitse
    call CinnabarIsland_Gym_EventScript_OpenDoor4
    special DrawWholeMapView
    setflag FLAG_CINNABAR_GYM_QUIZ_4
    return

CinnabarIsland_Gym_EventScript_Quiz4Incorrect::
    call CinnabarIsland_Gym_EventScript_IncorrectAnswer
    goto_if_not_defeated TRAINER_SUPER_NERD_DEREK, CinnabarIsland_Gym_EventScript_BattleDerek
    releaseall
    end

CinnabarIsland_Gym_EventScript_BattleDerek::
    compare VAR_TEMP_1, 0
    call_if_eq CinnabarIsland_Gym_EventScript_DerekApproachLeft
    compare VAR_TEMP_1, 1
    call_if_eq CinnabarIsland_Gym_EventScript_DerekApproachRight
    msgbox CinnabarIsland_Gym_Text_DerekIntro, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_SUPER_NERD_DEREK, CinnabarIsland_Gym_Text_DerekDefeat
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_4, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz4Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_DerekApproachLeft::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_DEREK, CinnabarIsland_Gym_Movement_DerekApproachLeft
    waitmovement 0
    return

CinnabarIsland_Gym_EventScript_DerekApproachRight::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_DEREK, CinnabarIsland_Gym_Movement_DerekApproachRight
    waitmovement 0
    return

CinnabarIsland_Gym_Movement_DerekApproachLeft::
    walk_left
    walk_left
    step_end

CinnabarIsland_Gym_Movement_DerekApproachRight::
    walk_left
    step_end

CinnabarIsland_Gym_EventScript_Quiz5Left::
    lockall
    setvar VAR_TEMP_1, 0
    goto CinnabarIsland_Gym_EventScript_Quiz5
    end

CinnabarIsland_Gym_EventScript_Quiz5Right::
    lockall
    setvar VAR_TEMP_1, 1
    goto CinnabarIsland_Gym_EventScript_Quiz5
    end

CinnabarIsland_Gym_EventScript_Quiz5::
    msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
    msgbox CinnabarIsland_Gym_Text_QuizQuestion5, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz5Correct
    compare VAR_RESULT, NO
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz5Incorrect
    end

CinnabarIsland_Gym_EventScript_Quiz5Correct::
    call CinnabarIsland_Gym_EventScript_CorrectAnswer
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_5, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz5Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_Quiz5Complete::
    playse SE_UNLOCK
    waitse
    call CinnabarIsland_Gym_EventScript_OpenDoor5
    special DrawWholeMapView
    setflag FLAG_CINNABAR_GYM_QUIZ_5
    return

CinnabarIsland_Gym_EventScript_Quiz5Incorrect::
    call CinnabarIsland_Gym_EventScript_IncorrectAnswer
    goto_if_not_defeated TRAINER_BURGLAR_DUSTY, CinnabarIsland_Gym_EventScript_BattleDusty
    releaseall
    end

CinnabarIsland_Gym_EventScript_BattleDusty::
    compare VAR_TEMP_1, 0
    call_if_eq CinnabarIsland_Gym_EventScript_DustyApproachLeft
    compare VAR_TEMP_1, 1
    call_if_eq CinnabarIsland_Gym_EventScript_DustyApproachRight
    msgbox CinnabarIsland_Gym_Text_DustyIntro, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_BURGLAR_DUSTY, CinnabarIsland_Gym_Text_DustyDefeat
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_5, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz5Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_DustyApproachLeft::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_DUSTY, CinnabarIsland_Gym_Movement_DustyApproachLeft
    waitmovement 0
    return

CinnabarIsland_Gym_EventScript_DustyApproachRight::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_DUSTY, CinnabarIsland_Gym_Movement_DustyApproachRight
    waitmovement 0
    return

CinnabarIsland_Gym_Movement_DustyApproachLeft::
    walk_left
    walk_left
    step_end

CinnabarIsland_Gym_Movement_DustyApproachRight::
    walk_left
    step_end

CinnabarIsland_Gym_EventScript_Quiz6Left::
    lockall
    setvar VAR_TEMP_1, 0
    goto CinnabarIsland_Gym_EventScript_Quiz6
    end

CinnabarIsland_Gym_EventScript_Quiz6Right::
    lockall
    setvar VAR_TEMP_1, 1
    goto CinnabarIsland_Gym_EventScript_Quiz6
    end

CinnabarIsland_Gym_EventScript_Quiz6::
    msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
    msgbox CinnabarIsland_Gym_Text_QuizQuestion6, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz6Incorrect
    compare VAR_RESULT, NO
    goto_if_eq CinnabarIsland_Gym_EventScript_Quiz6Correct
    end

CinnabarIsland_Gym_EventScript_Quiz6Correct::
    call CinnabarIsland_Gym_EventScript_CorrectAnswer
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_6, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz6Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_Quiz6Complete::
    playse SE_UNLOCK
    waitse
    call CinnabarIsland_Gym_EventScript_OpenDoor6
    special DrawWholeMapView
    setflag FLAG_CINNABAR_GYM_QUIZ_6
    return

CinnabarIsland_Gym_EventScript_Quiz6Incorrect::
    call CinnabarIsland_Gym_EventScript_IncorrectAnswer
    goto_if_not_defeated TRAINER_SUPER_NERD_ZAC, CinnabarIsland_Gym_EventScript_BattleZac
    releaseall
    end

CinnabarIsland_Gym_EventScript_BattleZac::
    compare VAR_TEMP_1, 0
    call_if_eq CinnabarIsland_Gym_EventScript_ZacApproachLeft
    compare VAR_TEMP_1, 1
    call_if_eq CinnabarIsland_Gym_EventScript_ZacApproachRight
    msgbox CinnabarIsland_Gym_Text_ZacIntro, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_SUPER_NERD_ZAC, CinnabarIsland_Gym_Text_ZacDefeat
    goto_if_set FLAG_CINNABAR_GYM_QUIZ_6, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
    call CinnabarIsland_Gym_EventScript_Quiz6Complete
    releaseall
    end

CinnabarIsland_Gym_EventScript_ZacApproachLeft::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_ZAC, CinnabarIsland_Gym_Movement_ZacApproachLeft
    waitmovement 0
    return

CinnabarIsland_Gym_EventScript_ZacApproachRight::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_ZAC, CinnabarIsland_Gym_Movement_ZacApproachRight
    waitmovement 0
    return

CinnabarIsland_Gym_Movement_ZacApproachLeft::
    walk_left
    walk_left
    step_end

CinnabarIsland_Gym_Movement_ZacApproachRight::
    walk_left
    step_end

CinnabarIsland_Gym_EventScript_GymGuy::
    lock
    faceplayer
    goto_if_set FLAG_DEFEATED_BLAINE, CinnabarIsland_Gym_EventScript_GymGuyPostVictory
    msgbox CinnabarIsland_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
    release
    end

CinnabarIsland_Gym_EventScript_GymGuyPostVictory::
    msgbox CinnabarIsland_Gym_Text_GymGuyPostVictory, MSGBOX_DEFAULT
    release
    end

CinnabarIsland_Gym_EventScript_GymStatue::
    lockall
    goto_if_set FLAG_BADGE07_GET, CinnabarIsland_Gym_EventScript_GymStatuePostVictory
    msgbox CinnabarIsland_Gym_Text_GymStatue, MSGBOX_DEFAULT
    releaseall
    end

CinnabarIsland_Gym_EventScript_GymStatuePostVictory::
    msgbox CinnabarIsland_Gym_Text_GymStatuePlayerWon, MSGBOX_DEFAULT
    releaseall
    end

CinnabarIsland_Gym_EventScript_BlaineFujiPhoto::
    msgbox CinnabarIsland_Gym_Text_PhotoOfBlaineAndFuji, MSGBOX_SIGN
    end

CinnabarIsland_Gym_EventScript_OpenDoor1::
    setmetatile 26,  8, METATILE_CinnabarGym_Floor_WallLeftCorner, 0
    setmetatile 27,  8, METATILE_CinnabarGym_Floor_WallRightCorner, 0
    setmetatile 26,  9, METATILE_CinnabarGym_Floor_WallLeftEdge, 0
    setmetatile 27,  9, METATILE_CinnabarGym_Floor_WallRightEdge, 0
    setmetatile 26, 10, METATILE_CinnabarGym_Floor_ShadeFull, 0
    setmetatile 27, 10, METATILE_CinnabarGym_Floor, 0
    setmetatile 28, 10, METATILE_CinnabarGym_Floor_ShadeDiagonal, 0
    return

CinnabarIsland_Gym_EventScript_OpenDoor2::
    setmetatile 17,  8, METATILE_CinnabarGym_Floor_WallLeftCorner, 0
    setmetatile 18,  8, METATILE_CinnabarGym_Floor_WallRightCorner, 0
    setmetatile 17,  9, METATILE_CinnabarGym_Floor_WallLeftEdge, 0
    setmetatile 18,  9, METATILE_CinnabarGym_Floor_WallRightEdge, 0
    setmetatile 17, 10, METATILE_CinnabarGym_Floor_ShadeFull, 0
    setmetatile 18, 10, METATILE_CinnabarGym_Floor, 0
    setmetatile 19, 10, METATILE_CinnabarGym_Floor_ShadeDiagonal, 0
    return

CinnabarIsland_Gym_EventScript_OpenDoor3::
    setmetatile 17, 15, METATILE_CinnabarGym_Floor_WallLeftCorner, 0
    setmetatile 18, 15, METATILE_CinnabarGym_Floor_WallRightCorner, 0
    setmetatile 17, 16, METATILE_CinnabarGym_Floor_WallLeftEdge, 0
    setmetatile 18, 16, METATILE_CinnabarGym_Floor_WallRightEdge, 0
    setmetatile 17, 17, METATILE_CinnabarGym_Floor_ShadeFull, 0
    setmetatile 18, 17, METATILE_CinnabarGym_Floor, 0
    setmetatile 19, 17, METATILE_CinnabarGym_Floor_ShadeDiagonal, 0
    return

CinnabarIsland_Gym_EventScript_OpenDoor4::
    setmetatile 11, 21, METATILE_CinnabarGym_Wall_RetractedBarrier, 1
    setmetatile 11, 22, METATILE_CinnabarGym_Floor_ShadeFull, 0
    setmetatile 11, 23, METATILE_CinnabarGym_Floor, 0
    return

CinnabarIsland_Gym_EventScript_OpenDoor5::
    setmetatile  5, 16, METATILE_CinnabarGym_Floor_WallLeftCorner, 0
    setmetatile  6, 16, METATILE_CinnabarGym_Floor_WallRightCorner, 0
    setmetatile  5, 17, METATILE_CinnabarGym_Floor_WallLeftEdge, 0
    setmetatile  6, 17, METATILE_CinnabarGym_Floor_WallRightEdge, 0
    setmetatile  5, 18, METATILE_CinnabarGym_Floor_ShadeFull, 0
    setmetatile  6, 18, METATILE_CinnabarGym_Floor, 0
    setmetatile  7, 18, METATILE_CinnabarGym_Floor_ShadeDiagonal, 0
    return

CinnabarIsland_Gym_EventScript_OpenDoor6::
    setmetatile  5,  8, METATILE_CinnabarGym_Floor_WallLeftCorner, 0
    setmetatile  6,  8, METATILE_CinnabarGym_Floor_WallRightCorner, 0
    setmetatile  5,  9, METATILE_CinnabarGym_Floor_WallLeftEdge, 0
    setmetatile  6,  9, METATILE_CinnabarGym_Floor_WallRightEdge, 0
    setmetatile  5, 10, METATILE_CinnabarGym_Floor_ShadeFull, 0
    setmetatile  6, 10, METATILE_CinnabarGym_Floor, 0
    setmetatile  7, 10, METATILE_CinnabarGym_Floor_ShadeDiagonal, 0
    return

CinnabarIsland_Gym_Text_BlaineIntro::
    .string "Hah!\p"
    .string "I am Blaine, the red-hot Leader\n"
    .string "of Cinnabar Gym!\p"
    .string "My fiery Pokémon are all rough\n"
    .string "and ready with intense heat!\p"
    .string "They incinerate all challengers!\p"
    .string "Hah!\n"
    .string "You better have Burn Heal!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

CinnabarIsland_Gym_Text_BlaineDefeat::
    .string "I have burned down to nothing!\n"
    .string "Not even ashes remain!\p"
    .string "You have earned the VolcanoBadge.$"

CinnabarIsland_Gym_Text_BlainePostBattle::
    .string "Fire Blast is the ultimate fire\n"
    .string "technique.\p"
    .string "Don't waste it on Water Pokémon.$"
    
CinnabarIsland_Gym_Text_ReceivedVolcanoBadge::
    .string "{PLAYER} received the VolcanoBadge\n"
    .string "from Blaine!$"

CinnabarIsland_Gym_Text_ExplainVolcanoBadge::
    .string "Hah!\p"
    .string "The VolcanoBadge heightens the\n"
    .string "Special stats of your Pokémon.\p"
    .string "Here, you can have this, too!$"

CinnabarIsland_Gym_Text_ReceivedTM38FromBlaine::
    .string "{PLAYER} received TM38\n"
    .string "from Blaine.$"

CinnabarIsland_Gym_Text_FireBlastIsUltimateFireMove::
    .string "TM38 contains Fire Blast.\n"
    .string "Teach it to Fire-type Pokémon.\p"
    .string "Vulpix or Charmeleon would be\n"
    .string "ideal for that move.$"

CinnabarIsland_Gym_Text_RegisteredBlaine::
    .string "Registered Gym Leader Blaine\n"
    .string "in the Pokénav.$"

CinnabarIsland_Gym_Text_MakeSpaceForThis::
    .string "Make space for this, child!$"

CinnabarIsland_Gym_Text_BlainePreRematch:
	.string "Blaine: Hah! Losing a battle isn't\n"
	.string "going to deflate me.\p"
	.string "I love Pokémon.\n"
	.string "I love to battle.\l"
	.string "That's why I opened this Gym!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!$"

CinnabarIsland_Gym_Text_BlaineRematchDefeat:
	.string "Whew!\n"
	.string "On the verge of eruption!$"

CinnabarIsland_Gym_Text_BlainePostRematch:
	.string "Blaine: Hah! I lost the match,\n"
	.string "but I'm completely satisfied.\p"
	.string "It's not often I get to enjoy a battle\n"
	.string "this heated.\p"
	.string "Let's have another one like this\n"
	.string "again sometime!$"

CinnabarIsland_Gym_Text_BlaineRematchNeedTwoMons:
	.string "Blaine: Hah! Losing a battle isn't\n"
	.string "going to deflate me.\p"
	.string "I love Pokémon.\n"
	.string "I love to battle.\l"
	.string "That's why I opened this Gym!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!\p"
	.string "Ah, no, no, no.\n"
	.string "You have with you but one Pokémon.\p"
	.string "I hate to say this, but when you come\n"
	.string "see me, bring at least two Pokémon.$"

CinnabarIsland_Gym_Text_ErikIntro::
    .string "Do you know how hot Pokémon fire\n"
    .string "breath can get?$"

CinnabarIsland_Gym_Text_ErikDefeat::
    .string "Yow!\n"
    .string "Hot, hot, hot!$"

CinnabarIsland_Gym_Text_ErikPostBattle::
    .string "Fire, or to be more precise,\n"
    .string "combustion…\p"
    .string "…Oxygen in the air…\n"
    .string "Blah, blah, blah, blah…$"

CinnabarIsland_Gym_Text_QuinnIntro::
    .string "I was a thief, but I went straight\n"
    .string "as a Trainer.$"

CinnabarIsland_Gym_Text_QuinnDefeat::
    .string "I surrender!$"

CinnabarIsland_Gym_Text_QuinnPostBattle::
    .string "I get this uncontrollable urge to\n"
    .string "steal other people's Pokémon.$"

CinnabarIsland_Gym_Text_AveryIntro::
    .string "I've studied Pokémon thoroughly.\n"
    .string "You can't win!$"

CinnabarIsland_Gym_Text_AveryDefeat::
    .string "Waah!\n"
    .string "My studies were insufficient!$"

CinnabarIsland_Gym_Text_AveryPostBattle::
    .string "My theories are too complicated\n"
    .string "for you to understand.$"

CinnabarIsland_Gym_Text_RamonIntro::
    .string "I like using Fire-type Pokémon.\n"
    .string "I just do.$"

CinnabarIsland_Gym_Text_RamonDefeat::
    .string "Too hot to handle!$"

CinnabarIsland_Gym_Text_RamonPostBattle::
    .string "I wish there were a thief Pokémon.\n"
    .string "I'd use that!$"

CinnabarIsland_Gym_Text_DerekIntro::
    .string "I know why Blaine became a\n"
    .string "Trainer.$"

CinnabarIsland_Gym_Text_DerekDefeat::
    .string "Ow!$"

CinnabarIsland_Gym_Text_DerekPostBattle::
    .string "Our Leader, Blaine, became lost\n"
    .string "in the mountains for good.\p"
    .string "Night fell when a fiery bird\n"
    .string "Pokémon appeared.\p"
    .string "Its light allowed Blaine to find\n"
    .string "his way down safely.$"

CinnabarIsland_Gym_Text_DustyIntro::
    .string "I've been to many Gyms, but this\n"
    .string "one best suits my style.$"

CinnabarIsland_Gym_Text_DustyDefeat::
    .string "Yowza!\n"
    .string "Too hot!$"

CinnabarIsland_Gym_Text_DustyPostBattle::
    .string "Ponyta, Ninetales…\n"
    .string "Those are popular Fire Pokémon.$"

CinnabarIsland_Gym_Text_ZacIntro::
    .string "Fire is weak against Water.$"

CinnabarIsland_Gym_Text_ZacDefeat::
    .string "Oh!\n"
    .string "Snuffed out!$"

CinnabarIsland_Gym_Text_ZacPostBattle::
    .string "Water beats fire, of course.\p"
    .string "But fire melts ice, so the Fire\n"
    .string "type beats Ice-type Pokémon.$"

CinnabarIsland_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "The hotheaded Blaine is a Fire\n"
    .string "Pokémon pro.\p"
    .string "Douse his spirits with water!\p"
    .string "You'd better take some\n"
    .string "Burn Heals, too.$"

CinnabarIsland_Gym_Text_GymGuyPostVictory::
    .string "{PLAYER}!\n"
    .string "You beat that firebrand!$"

CinnabarIsland_Gym_Text_GymStatue::
    .string "Cinnabar Pokémon Gym\n"
    .string "Leader: Blaine\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

CinnabarIsland_Gym_Text_GymStatuePlayerWon::
    .string "Cinnabar Pokémon Gym\n"
    .string "Leader: Blaine\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"

CinnabarIsland_Gym_Text_PokemonQuizRules::
    .string "Pokémon Quiz!\p"
    .string "Get it right, and the door opens to\n"
    .string "the next room.\p"
    .string "Get it wrong, and face a Trainer!\p"
    .string "If you want to conserve your\n"
    .string "Pokémon for the Gym Leader…\p"
    .string "Then get it right!\n"
    .string "Here we go!$"

CinnabarIsland_Gym_Text_QuizQuestion1::
    .string "Caterpie evolves into Metapod?$"

CinnabarIsland_Gym_Text_QuizQuestion2::
    .string "There are nine certified Pokémon\n"
    .string "League Badges?$"

CinnabarIsland_Gym_Text_QuizQuestion3::
    .string "Poliwag evolves three times?$"

CinnabarIsland_Gym_Text_QuizQuestion4::
    .string "Are electric moves effective\n"
    .string "against Ground-type Pokémon?$"

CinnabarIsland_Gym_Text_QuizQuestion5::
    .string "Pokémon of the same kind and level\n"
    .string "are not identical?$"

CinnabarIsland_Gym_Text_QuizQuestion6::
    .string "TM28 contains Tombstoner?$"

CinnabarIsland_Gym_Text_CorrectGoOnThrough::
    .string "You're absolutely correct!\p"
    .string "Go on through!$"

CinnabarIsland_Gym_Text_SorryBadCall::
    .string "Sorry!\n"
    .string "Bad call!$"

CinnabarIsland_Gym_Text_PhotoOfBlaineAndFuji::
    .string "It's a photo of Blaine and\n"
    .string "Mr. Fuji.\p"
    .string "They're standing shoulder to\n"
    .string "shoulder with big grins.$"
