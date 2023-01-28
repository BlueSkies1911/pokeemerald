
.set LOCALID_NURSE,         1
.set LOCALID_MART_CLERK,    2
.set LOCALID_RECEPTIONIST,  3
.set LOCALID_COOLTRAINER_F, 4
.set LOCALID_BALDING_MAN,   5

TrainerTower_Lobby_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, TrainerTower_Lobby_OnResume
    map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerTower_Lobby_OnReturn
    map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_Lobby_OnTransition
    map_script MAP_SCRIPT_ON_LOAD, TrainerTower_Lobby_OnLoad
    map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_Lobby_OnFrame
    .byte 0

TrainerTower_Lobby_OnTransition:
    setflag FLAG_LANDMARK_TRAINER_TOWER_LOBBY
    getplayerxy VAR_TEMP_D, VAR_RESULT
    end

TrainerTower_Lobby_OnResume:
    trainerhill_resumetimer
    setvar VAR_TEMP_0, 0
    trainerhill_getusingereader
    goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
    setobjectxy OBJ_EVENT_ID_PLAYER, 9, 7
    applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Lobby_Movement_PlayerFaceAttendant
    end

TrainerTower_Lobby_EventScript_TryFaceAttendant::
    trainerhill_getwon
    goto_if_eq VAR_RESULT, TRUE, TrainerTower_Lobby_EventScript_PlayerDontFaceAttendant
    applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Lobby_Movement_PlayerFaceAttendant
    end

TrainerTower_Lobby_EventScript_PlayerDontFaceAttendant::
    end

TrainerTower_Lobby_OnReturn:
    addobject LOCALID_NURSE
    addobject LOCALID_MART_CLERK
    addobject LOCALID_RECEPTIONIST
    addobject LOCALID_COOLTRAINER_F
    addobject LOCALID_BALDING_MAN
    end

TrainerTower_Lobby_OnLoad:
    call_if_eq VAR_TEMP_D, 17, TrainerTower_Lobby_EventScript_OpenCounterDoor
    end

TrainerTower_Lobby_EventScript_OpenCounterDoor::
    setmetatile 17, 10, METATILE_TrainerTower_Floor_ShadeBottomLeft, FALSE
    return

TrainerTower_Lobby_OnFrame:
    map_script_2 VAR_TEMP_0, 0, TrainerTower_Lobby_EventScript_ExitChallenge
    map_script_2 VAR_TEMP_D, 17, TrainerTower_Lobby_EventScript_ExitElevator
    map_script_2 VAR_TEMP_5, 1, TrainerTower_Lobby_EventScript_EntryTrigger
    map_script_2 VAR_TEMP_1, 1, TrainerTower_EventScript_WarpToEntranceCounter
    .2byte 0

TrainerTower_Lobby_EventScript_ExitElevator::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Lobby_Movement_PlayerExitElevator
    waitmovement 0
    setmetatile 17, 10, METATILE_TrainerTower_CounterBarrier, TRUE
    special DrawWholeMapView
    playse SE_CLICK
    waitse
    setvar VAR_TEMP_D, 0
    releaseall
    end

TrainerTower_Lobby_EventScript_ExitChallenge::
    setvar VAR_TEMP_0, 1
    trainerhill_getstatus
    switch VAR_RESULT
    case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerTower_Lobby_EventScript_ExitChallengeLost
    case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerTower_Lobby_EventScript_ExitChallengeECard
    case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerTower_Lobby_EventScript_EndExitChallenge

TrainerTower_Lobby_EventScript_ExitChallengeLost::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Lobby_Movement_PlayerFaceAttendant
    msgbox TrainerTower_Lobby_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
    goto TrainerTower_Lobby_EventScript_PlayerExitChallenge

TrainerTower_Lobby_EventScript_ExitChallengeECard::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Lobby_Movement_PlayerFaceAttendant
    msgbox TrainerTower_Lobby_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerTower_Lobby_EventScript_PlayerExitChallenge::
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Lobby_Movement_PushPlayerBackFromCounter
    waitmovement 0
    setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
    special HealPlayerParty
    releaseall
TrainerTower_Lobby_EventScript_EndExitChallenge::
    end

TrainerTower_Lobby_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

TrainerTower_Lobby_EventScript_Receptionist::
    lock
    faceplayer
    trainerhill_inchallenge
    goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_EventScript_ThanksForPlaying
    msgbox TrainerTower_Lobby_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
    goto TrainerTower_Lobby_EventScript_ReceptionistEnd

TrainerTower_Lobby_EventScript_ThanksForPlaying::
    msgbox TrainerTower_Lobby_Text_ThanksForCompeting, MSGBOX_DEFAULT
TrainerTower_Lobby_EventScript_ReceptionistEnd::
    release
    end

TrainerTower_Lobby_EventScript_EntryTrigger::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Lobby_Movement_PlayerFaceAttendant
    msgbox TrainerTower_Lobby_Text_WelcomeToTrainerTower, MSGBOX_DEFAULT
    trainerhill_getsaved
    call_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_EventScript_SaveGame
    trainerhill_allfloorsused
    goto_if_eq VAR_RESULT, TRUE, TrainerTower_Lobby_EventScript_AllFloorsUsed
    msgbox TrainerTower_Lobby_Text_TrainersUpToFloorNum, MSGBOX_DEFAULT
    goto TrainerTower_Lobby_EventScript_AskChallengeTrainers

TrainerTower_Lobby_EventScript_AllFloorsUsed::
    msgbox TrainerTower_Lobby_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerTower_Lobby_EventScript_AskChallengeTrainers::
    message TrainerTower_Lobby_Text_LikeToChallengeTrainers
    waitmessage
    multichoice 15, 6, MULTI_YESNOINFO, FALSE
    switch VAR_RESULT
    case 0, TrainerTower_Lobby_EventScript_ChooseChallenge
    case 1, TrainerTower_Lobby_EventScript_CancelEntry
    case 2, TrainerTower_Lobby_EventScript_Info
    case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_CancelEntry
    end

TrainerTower_Lobby_EventScript_Info::
    msgbox TrainerTower_Lobby_Text_ExplainTrainerTower, MSGBOX_DEFAULT
    goto TrainerTower_Lobby_EventScript_AskChallengeTrainers
    end

TrainerTower_Lobby_EventScript_ChooseChallenge::
    multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
    switch VAR_RESULT
    case 4, TrainerTower_Lobby_EventScript_CancelEntry
    case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_CancelEntry
    trainerhill_setmode VAR_RESULT
    setvar VAR_MAP_SCENE_TRAINER_TOWER, 1
    setvar VAR_TEMP_5, 0
    special HealPlayerParty
    msgbox TrainerTower_Lobby_Text_StartClockGetSetGo, MSGBOX_DEFAULT
    trainerhill_start
    releaseall
    end

TrainerTower_Lobby_EventScript_CancelEntry::
    setvar VAR_TEMP_5, 0
    msgbox TrainerTower_Lobby_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Lobby_Movement_PushPlayerBackFromCounter
    waitmovement 0
    releaseall
    end

TrainerTower_Lobby_EventScript_SaveGame::
    msgbox TrainerTower_Lobby_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
    trainerhill_setsaved
    setvar VAR_TEMP_5, 1
    call Common_EventScript_SaveGame
    goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_EventScript_SaveFailed
    trainerhill_setsaved
    return

TrainerTower_Lobby_EventScript_SaveFailed::
    trainerhill_clearsaved
    goto TrainerTower_Lobby_EventScript_CancelEntry
    end

TrainerTower_Lobby_Movement_PlayerFaceAttendant:
    face_right
    step_end

TrainerTower_Lobby_Movement_PushPlayerBackFromCounter:: @ 8164AD6
	walk_down
	step_end

TrainerTower_Lobby_Movement_PlayerExitElevator:
    walk_down
    walk_down
    step_end

TrainerTower_Lobby_EventScript_ShowRecords::
    lockall
    fadescreen FADE_TO_BLACK
    special ShowTrainerHillRecords
    waitstate
    releaseall
    end

TrainerTower_Lobby_EventScript_CooltrainerF::
    msgbox TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers, MSGBOX_NPC
    end

TrainerTower_Lobby_EventScript_BaldingMan::
    msgbox TrainerTower_Lobby_Text_StairsTougherThanAnyBattle, MSGBOX_NPC
    end

TrainerTower_Lobby_EventScript_MartClerk::
    lock
    faceplayer
    message gText_HowMayIServeYou
    waitmessage
    pokemart TrainerTower_Lobby_Mart_Items
    msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
    release
    end

    .align 2
TrainerTower_Lobby_Mart_Items::
    .2byte ITEM_ULTRA_BALL
    .2byte ITEM_GREAT_BALL
    .2byte ITEM_FULL_RESTORE
    .2byte ITEM_MAX_POTION
    .2byte ITEM_HYPER_POTION
    .2byte ITEM_REVIVE
    .2byte ITEM_FULL_HEAL
    .2byte ITEM_ESCAPE_ROPE
    .2byte ITEM_MAX_REPEL
    .2byte ITEM_NONE
    release
    end

TrainerTower_Lobby_Text_WelcomeToTrainerTower:
    .string "Hello!\p"
    .string "Welcome to Trainer Tower where\n"
    .string "Trainers gather from all over!$"

TrainerTower_Lobby_Text_SaveGameBeforeEnter:
    .string "Is this your first visit here?\p"
    .string "Before you enter, please save\n"
    .string "your game.$"

TrainerTower_Lobby_Text_TrainersUpToFloorNum:
    .string "Trainers from all over the world\n"
    .string "gather here to battle.\p"
    .string "Let me see…\p"
    .string "Right now, there are Trainers only\n"
    .string "up to Floor {STR_VAR_1}.$"

TrainerTower_Lobby_Text_TrainersInEveryRoom:
    .string "Let's see…\n"
    .string "The Trainers here now are…\p"
    .string "There appear to be Trainers gathered\n"
    .string "in every room.$"

TrainerTower_Lobby_Text_LikeToChallengeTrainers:
    .string "Would you like to challenge the\n"
    .string "waiting Trainers?$"

TrainerTower_Lobby_Text_StartClockGetSetGo:
    .string "Okay, I'll get the clock started,\n"
    .string "so give it everything you have.\p"
    .string "On your marks…\p"
    .string "Get set…\p"
    .string "Go!$"

TrainerTower_Lobby_Text_PleaseVisitUsAgain:
    .string "Please do visit us again!$"

TrainerTower_Lobby_Text_TooBadTremendousEffort:
    .string "That was too bad.\p"
    .string "I think you put in a tremendous\n"
    .string "effort in your battling.\p"
    .string "Please come back and try again!$"

TrainerTower_Lobby_Text_HopeYouGiveItYourBest:
    .string "I hope you give it your best.$"

TrainerTower_Lobby_Text_MovedReceptionHereForSwitch:
    .string "When the Trainers switch places,\n"
    .string "the movement can be hectic.\p"
    .string "To avoid the stampede, we moved\n"
    .string "the reception counter here.\p"
    .string "I'm sorry for the inconvenience.$"

TrainerTower_Lobby_Text_ThanksForCompeting:
    .string "Thank you for competing!$"

TrainerTower_Lobby_Text_ExplainTrainerTower:
    .string "Here at Trainer Tower, there is an\n"
    .string "event called Time Attack.\p"
    .string "You will be timed on how quickly\n"
    .string "you can get from the reception\l"
    .string "counter to the owner on the roof.\p"
    .string "The best times will be recorded on\n"
    .string "the Time Board.\p"
    .string "Try competing with friends to see\n"
    .string "who can beat it the fastest.\p"
    .string "You will not earn any Exp. Points\n"
    .string "or money by beating Trainers here.$"
    
TrainerTower_Lobby_Text_ChallengeTime:
    .string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"

TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers:
    .string "I'm here to see how good I am.\p"
    .string "I wonder what kinds of Trainers\n"
    .string "are waiting for me?\p"
    .string "It's nerve-racking!$"

TrainerTower_Lobby_Text_StairsTougherThanAnyBattle:
    .string "Gasp, gasp…\n"
    .string "Gasp…\p"
    .string "Never mind battling! These stairs…\n"
    .string "They're tougher than any battle…$"
