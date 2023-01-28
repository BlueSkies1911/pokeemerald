.set LOCALID_PROF_OAK,        4
.set LOCALID_CHARMANDER_BALL, 5
.set LOCALID_SQUIRTLE_BALL,   6
.set LOCALID_BULBASAUR_BALL,  7
.set LOCALID_RIVAL,           8
.set LOCALID_POKEDEX_1,       9
.set LOCALID_POKEDEX_2,       10

.equ PLAYER_STARTER_NUM,      VAR_TEMP_1
.equ PLAYER_STARTER_SPECIES,  VAR_TEMP_2
.equ RIVAL_STARTER_SPECIES,   VAR_TEMP_3
.equ RIVAL_STARTER_ID,        VAR_TEMP_4

.set SHOWED_OAK_COMPLETE_DEX, FLAG_TEMP_2

ProfessorOaksLab_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, ProfessorOaksLab_OnTransition
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ProfessorOaksLab_OnWarp
    map_script MAP_SCRIPT_ON_FRAME_TABLE, ProfessorOaksLab_OnFrame
	.byte 0

ProfessorOaksLab_OnTransition:
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 1
    call_if_eq ProfessorOaksLab_EventScript_ReadyOakForStarterScene
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 7
    call_if_eq ProfessorOaksLab_EventScript_ReadyOakForNationalDexScene
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 8
    call_if_eq ProfessorOaksLab_EventScript_SetNationalDexSceneFinished
    call_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, ProfessorOaksLab_EventScript_SetSkipPokeBallCheck
    end

ProfessorOaksLab_EventScript_ReadyOakForStarterScene::
    setobjectxyperm LOCALID_PROF_OAK, 6, 11
    setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_UP
    savebgm MUS_RG_OAK
    return

ProfessorOaksLab_EventScript_ReadyOakForNationalDexScene::
    setobjectxyperm LOCALID_PROF_OAK, 6, 11
    setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_UP
    return

ProfessorOaksLab_EventScript_SetNationalDexSceneFinished::
    setvar VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 9
    return

ProfessorOaksLab_EventScript_SetSkipPokeBallCheck::
    setflag FLAG_OAK_SKIP_22_RIVAL_CHECK
    return

ProfessorOaksLab_OnWarp:
    map_script_2 VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 1, ProfessorOaksLab_EventScript_ReadyPlayerForStarterScene
    .2byte 0

ProfessorOaksLab_EventScript_ReadyPlayerForStarterScene::
    turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
    end

ProfessorOaksLab_OnFrame:
    map_script_2 VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 1, ProfessorOaksLab_ChooseStarterScene
	map_script_2 VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 7, ProfessorOaksLab_EventScript_EnterForNationalDexScene
    .2byte 0

ProfessorOaksLab_EventScript_EnterForNationalDexScene:: 
	lockall
	setvar VAR_FACING, DIR_NORTH
	applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakEnter
	waitmovement 0
	removeobject LOCALID_PROF_OAK
	setobjectxyperm LOCALID_PROF_OAK, 6, 3
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_PlayerEnter
	waitmovement 0
	goto ProfessorOaksLab_EventScript_NationalDexScene
	end

ProfessorOaksLab_ChooseStarterScene::
    lockall
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakEnter
    waitmovement 0
    removeobject LOCALID_PROF_OAK
    setobjectxyperm LOCALID_PROF_OAK, 6, 3
    setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
    clearflag FLAG_HIDE_OAK_IN_HIS_LAB
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_PlayerEnter
    waitmovement 0
    applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    clearflag FLAG_DONT_TRANSITION_MUSIC
    savebgm MUS_DUMMY
    fadedefaultbgm
    msgbox ProfessorOaksLab_Text_RivalFedUpWithWaiting, MSGBOX_DEFAULT
    closemessage
    delay 60
    msgbox ProfessorOaksLab_Text_OakThreeMonsChooseOne, MSGBOX_DEFAULT
    closemessage
    delay 30
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalReact
    waitmovement 0
    msgbox ProfessorOaksLab_Text_RivalNoFairWhatAboutMe, MSGBOX_DEFAULT
    msgbox ProfessorOaksLab_Text_OakBePatientRival, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 2
    releaseall
    end

ProfessorOaksLab_Movement_OakEnter::
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

ProfessorOaksLab_Movement_PlayerEnter::
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

ProfessorOaksLab_Movement_RivalReact::
    walk_in_place_up
    walk_in_place_up
    step_end

ProfessorOaksLab_EventScript_Rival::
    lock
    faceplayer
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 3
    goto_if_eq ProfessorOaksLab_EventScript_RivalChoseStarter
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 2
    goto_if_eq ProfessorOaksLab_EventScript_RivalWaitingForStarter
    msgbox ProfessorOaksLab_Text_RivalGrampsIsntAround, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_RivalChoseStarter::
    msgbox ProfessorOaksLab_Text_RivalMyMonLooksTougher, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_RivalWaitingForStarter::
    msgbox ProfessorOaksLab_Text_RivalGoChoosePlayer, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_ProfOak::
    lock
    faceplayer
    goto_if_set SHOWED_OAK_COMPLETE_DEX, ProfessorOaksLab_EventScript_OakJustShownCompleteDex
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 9
    goto_if_eq ProfessorOaksLab_EventScript_RatePokedex
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 8
    goto_if_eq ProfessorOaksLab_EventScript_MonsAroundWorldWait
    goto_if_set FLAG_SYS_GAME_CLEAR, ProfessorOaksLab_EventScript_TryStartNationalDexScene
    compare VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
    goto_if_eq ProfessorOaksLab_EventScript_RatePokedex
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 6
    goto_if_eq ProfessorOaksLab_EventScript_RatePokedexOrTryGiveBalls
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 1
    goto_if_ge ProfessorOaksLab_EventScript_ReceiveDexScene
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 4
    goto_if_eq ProfessorOaksLab_EventScript_OakBattleMonForItToGrow
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 3
    goto_if_eq ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon
    msgbox ProfessorOaksLab_Text_OakWhichOneWillYouChoose, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_OakJustShownCompleteDex::
    msgbox gPokedexRating_Text_ThankYouMadeDreamReality, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_RatePokedex::
    call PokedexRating_EventScript_RateInPerson
    goto_if_set FLAG_OAK_SAW_DEX_COMPLETION, ProfessorOaksLab_EventScript_DexCompleted
    release
    end
    
ProfessorOaksLab_EventScript_DexCompleted::
    closemessage
    delay 40
    message gPokedexRating_Text_Wroooaaarrr
    waitmessage
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_OakExcitedNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_OakExcitedSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_OakExcitedEast
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_OakExcitedWest
    applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
    waitmovement 0
    closemessage
    delay 70
    msgbox gPokedexRating_Text_ThankYouMadeDreamReality, MSGBOX_DEFAULT
    setflag SHOWED_OAK_COMPLETE_DEX
    release
    end

ProfessorOaksLab_EventScript_OakExcitedNorth::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakExcitedNorth
    waitmovement 0
    return

ProfessorOaksLab_EventScript_OakExcitedSouth::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakExcitedSouth
    waitmovement 0
    return

ProfessorOaksLab_EventScript_OakExcitedEast::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakExcitedEast
    waitmovement 0
    return

ProfessorOaksLab_EventScript_OakExcitedWest::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakExcitedWest
    waitmovement 0
    return

ProfessorOaksLab_Movement_OakExcitedNorth::
    walk_in_place_down
    walk_in_place_fast_down
    walk_in_place_down
    walk_in_place_down
    walk_in_place_fast_down
    walk_in_place_down
    step_end

ProfessorOaksLab_Movement_OakExcitedSouth::
    walk_in_place_up
    walk_in_place_fast_up
    walk_in_place_up
    walk_in_place_up
    walk_in_place_fast_up
    walk_in_place_up
    step_end

ProfessorOaksLab_Movement_OakExcitedEast::
    walk_in_place_left
    walk_in_place_fast_left
    walk_in_place_left
    walk_in_place_left
    walk_in_place_fast_left
    walk_in_place_left
    step_end

ProfessorOaksLab_Movement_OakExcitedWest::
    walk_in_place_right
    walk_in_place_fast_right
    walk_in_place_right
    walk_in_place_right
    walk_in_place_fast_right
    walk_in_place_right
    step_end

ProfessorOaksLab_EventScript_MonsAroundWorldWait::
    msgbox ProfessorOaksLab_Text_OakMonsAroundWorldWait, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_TryStartNationalDexScene::
    call PokedexRating_EventScript_RateInPerson
    closemessage
	compare VAR_0x8009, 60
	goto_if_lt ProfessorOaksLab_EventScript_DontStartNationalDexScene
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, ProfessorOaksLab_EventScript_DontStartNationalDexScene
    delay 30
    msgbox ProfessorOaksLab_Text_OakFavorToAskYouPlayer, MSGBOX_DEFAULT
    goto ProfessorOaksLab_EventScript_NationalDexScene
    end

ProfessorOaksLab_EventScript_DontStartNationalDexScene::
    release
    end

ProfessorOaksLab_EventScript_NationalDexScene::
    msgbox ProfessorOaksLab_Text_OakSightingsOfRareMons, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest
    msgbox ProfessorOaksLab_Text_RivalJustLetMeHandleEverything, MSGBOX_DEFAULT
    fadedefaultbgm
    msgbox ProfessorOaksLab_Text_OakNeedYourHelpTooNeedToSeePokedexes, MSGBOX_DEFAULT
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_PlayerFaceOakNorth
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_PlayerFaceOakWest
    msgbox ProfessorOaksLab_Text_OakTookBothPokedexUnits
    closemessage
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesToDeskNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesToDeskSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesToDeskEast
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesToDeskWest
    addobject LOCALID_POKEDEX_1
    addobject LOCALID_POKEDEX_2
    delay 30
    msgbox ProfessorOaksLab_Text_OakNowTheseUnitsCanRecordMoreData, MSGBOX_DEFAULT
    closemessage
    removeobject LOCALID_POKEDEX_1
    removeobject LOCALID_POKEDEX_2
    delay 30
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesOverNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesOverSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesOverEast
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesOverWest
    playfanfare MUS_RG_OBTAIN_KEY_ITEM
    msgbox ProfessorOaksLab_Text_PlayersPokedexWasUpgraded, MSGBOX_DEFAULT
    waitmessage
    waitfanfare
    special EnableNationalPokedex
    msgbox ProfessorOaksLab_Text_OakMustReallyWorkToFillPokedex, MSGBOX_DEFAULT
    msgbox ProfessorOaksLab_Text_RivalIllCompleteThePokedex, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_RG_RIVAL_EXIT, 0
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_RivalExitNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_RivalExit
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_RivalExit
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_RivalExit
    removeobject LOCALID_RIVAL
    fadedefaultbgm
    setvar VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 8
    releaseall
    end

ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterNorth::
    setobjectxyperm LOCALID_RIVAL, 5, 10
    addobject LOCALID_RIVAL
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_WatchRivalEnterNorth
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalEnter
    waitmovement 0
    return

ProfessorOaksLab_Movement_WatchRivalEnterNorth::
    walk_in_place_faster_down
    delay_16
    delay_16
    delay_16
    delay_16
    delay_16
    delay_8
    walk_in_place_faster_left
    step_end

ProfessorOaksLab_Movement_RivalEnter::
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterSouth::
    setobjectxyperm LOCALID_RIVAL, 6, 10
    addobject LOCALID_RIVAL
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalEnter
    waitmovement 0
    return

ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest::
    setobjectxyperm LOCALID_RIVAL, 6, 10
    addobject LOCALID_RIVAL
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_WatchRivalEnterEastWest
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalEnter
    waitmovement 0
    return

ProfessorOaksLab_Movement_WatchRivalEnterEastWest::
    delay_4
    walk_in_place_faster_down
    step_end

ProfessorOaksLab_EventScript_PlayerFaceOakNorth::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

ProfessorOaksLab_EventScript_PlayerFaceOakWest::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    return

ProfessorOaksLab_EventScript_OakBringDexesToDeskNorth::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakBringDexesToDesk
    waitmovement 0
    return

ProfessorOaksLab_Movement_OakBringDexesToDesk::
    walk_up
    walk_left
    walk_in_place_faster_up
    delay_16
    delay_4
    step_end

ProfessorOaksLab_EventScript_OakBringDexesToDeskSouth::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakBringDexesToDeskSouth
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_WatchOakWalkToDesk
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_WatchOakWalkToDesk
    waitmovement LOCALID_PROF_OAK
    return

ProfessorOaksLab_Movement_OakBringDexesToDeskSouth::
    walk_left
    walk_left
    walk_up
    delay_16
    delay_4
    step_end

ProfessorOaksLab_Movement_WatchOakWalkToDesk::
    delay_16
    delay_8
    walk_in_place_faster_left
    step_end

ProfessorOaksLab_EventScript_OakBringDexesToDeskEast::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakBringDexesToDesk
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_WatchOakWalkToDeskEast
    waitmovement LOCALID_PROF_OAK
    return

ProfessorOaksLab_Movement_WatchOakWalkToDeskEast::
    delay_16
    delay_8
    walk_in_place_faster_up
    step_end

ProfessorOaksLab_EventScript_OakBringDexesToDeskWest::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakBringDexesToDesk
    waitmovement 0
    return

ProfessorOaksLab_EventScript_OakBringDexesOverNorth::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakBringDexesOver
    waitmovement 0
    return

ProfessorOaksLab_EventScript_OakBringDexesOverSouth::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakBringDexesOverSouth
    waitmovement 0
    return

ProfessorOaksLab_EventScript_OakBringDexesOverEast::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakBringDexesOver
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_PlayerFaceOakForDexEast
    waitmovement 0
    return

ProfessorOaksLab_EventScript_OakBringDexesOverWest::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakBringDexesOver
    waitmovement 0
    return

ProfessorOaksLab_Movement_OakBringDexesOver::
    walk_right
    walk_down
    step_end

ProfessorOaksLab_Movement_OakBringDexesOverSouth::
    walk_down
    walk_right
    step_end

ProfessorOaksLab_Movement_PlayerFaceOakForDexEast::
    delay_16
    delay_8
    walk_in_place_faster_right
    step_end

ProfessorOaksLab_EventScript_RivalExitNorth::
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_WatchRivalEnterEastWest
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalExit
    waitmovement 0
    return

ProfessorOaksLab_EventScript_RivalExit::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalExit
    waitmovement 0
    return

ProfessorOaksLab_Movement_RivalExit::
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

ProfessorOaksLab_EventScript_RatePokedexOrTryGiveBalls::
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, ScriptGetPokedexInfo
    copyvar VAR_0x8008, VAR_0x8005
    copyvar VAR_0x8009, VAR_0x8006
    buffernumberstring 0, VAR_0x8008
    buffernumberstring 1, VAR_0x8009
    compare VAR_0x8009, 1  @ Player only has starter
    goto_if_eq ProfessorOaksLab_EventScript_CheckIfPlayerNeedsBalls
    goto ProfessorOaksLab_EventScript_RatePokedex
    end

ProfessorOaksLab_EventScript_CheckIfPlayerNeedsBalls::
    goto_if_set FLAG_OAK_SKIP_22_RIVAL_CHECK, ProfessorOaksLab_EventScript_MonsAroundWorldWait
    goto_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, ProfessorOaksLab_EventScript_PlayerAlreadyGotBalls
    checkitem ITEM_POKE_BALL, 1
    compare VAR_RESULT, FALSE
    goto_if_eq ProfessorOaksLab_EventScript_PlayerOutOfBalls
    goto ProfessorOaksLab_EventScript_MonsAroundWorldWait
    end

ProfessorOaksLab_EventScript_PlayerAlreadyGotBalls::
    msgbox ProfessorOaksLab_Text_OakComeSeeMeSometime, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_PlayerOutOfBalls::
    compare VAR_MAP_SCENE_ROUTE22, 2
    goto_if_ge ProfessorOaksLab_EventScript_GivePlayerMoreBalls
    goto ProfessorOaksLab_EventScript_MonsAroundWorldWait
    end

ProfessorOaksLab_EventScript_GivePlayerMoreBalls::
    msgbox ProfessorOaksLab_Text_OakAddedNothingToPokedex, MSGBOX_DEFAULT
    giveitem_msg ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
    setflag FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL
    release
    end

ProfessorOaksLab_EventScript_ReceiveDexScene::
    msgbox ProfessorOaksLab_Text_OakHaveSomethingForMe, MSGBOX_DEFAULT
    playfanfare MUS_OBTAIN_TMHM
    message ProfessorOaksLab_Text_DeliveredOaksParcel
    waitmessage
    waitfanfare
    removeitem ITEM_OAKS_PARCEL, 1
    msgbox ProfessorOaksLab_Text_OakCustomBallIOrdered, MSGBOX_DEFAULT
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    msgbox ProfessorOaksLab_Text_RivalGramps, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_DexSceneRivalEnterNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_DexSceneRivalEnterSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest
    fadedefaultbgm
    msgbox ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor, MSGBOX_DEFAULT
    closemessage
    delay 30
    playse SE_PIN
    applymovement LOCALID_PROF_OAK, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_PROF_OAK, Common_Movement_Delay48
    waitmovement 0
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalEast
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalWest
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalNorth
    msgbox ProfessorOaksLab_Text_OakHaveRequestForYouTwo, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskEast
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskWest
    msgbox ProfessorOaksLab_Text_OakPokedexOnDesk, MSGBOX_DEFAULT
    closemessage
    delay 40
    msgbox ProfessorOaksLab_Text_OakTakeTheseWithYou, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    removeobject LOCALID_POKEDEX_1
    delay 10
    removeobject LOCALID_POKEDEX_2
    delay 25
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesOverNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesOverSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesOverEast
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_OakBringDexesOverWest
    delay 10
    playfanfare MUS_RG_OBTAIN_KEY_ITEM
    message ProfessorOaksLab_Text_ReceivedPokedexFromOak
    waitmessage
    waitfanfare
    setflag FLAG_SYS_POKEDEX_GET
    special SetUnlockedPokedexFlags
    setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
    msgbox ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese, MSGBOX_DEFAULT
    giveitem_msg ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
    msgbox ProfessorOaksLab_Text_OakExplainCatching, MSGBOX_DEFAULT
    msgbox ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream, MSGBOX_DEFAULT
    msgbox ProfessorOaksLab_Text_RivalLeaveItToMeGramps, MSGBOX_DEFAULT
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest
    msgbox ProfessorOaksLab_Text_RivalTellSisNotToGiveYouMap, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_RG_RIVAL_EXIT, 0
    compare VAR_FACING, DIR_NORTH
    call_if_eq ProfessorOaksLab_EventScript_RivalExitNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ProfessorOaksLab_EventScript_RivalExit
    compare VAR_FACING, DIR_EAST
    call_if_eq ProfessorOaksLab_EventScript_RivalExit
    compare VAR_FACING, DIR_WEST
    call_if_eq ProfessorOaksLab_EventScript_RivalExit
    removeobject LOCALID_RIVAL
    fadedefaultbgm
    setvar VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 6
    setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
    setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
    setvar VAR_MAP_SCENE_RIVALS_HOUSE, 1
    setvar VAR_MAP_SCENE_ROUTE22, 1
    setvar VAR_MAP_SCENE_PALLET_TOWN_MOM, 1
    setflag FLAG_HIDE_TOWN_MAP
    release
    end

ProfessorOaksLab_EventScript_DexSceneRivalEnterNorth::
    setobjectxyperm LOCALID_RIVAL, 5, 10
    addobject LOCALID_RIVAL
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_WatchRivalEnterNorth
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalEnter
    waitmovement 0
    return

ProfessorOaksLab_EventScript_DexSceneRivalEnterSouth::
    setobjectxyperm LOCALID_RIVAL, 6, 10
    addobject LOCALID_RIVAL
    applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalEnter
    waitmovement 0
    return

ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest::
    setobjectxyperm LOCALID_RIVAL, 6, 10
    addobject LOCALID_RIVAL
    applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_WatchRivalEnterEastWest
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalEnter
    waitmovement 0
    return

ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalSouth::
    applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
    waitmovement 0
    delay 15
    applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalEast::
    applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
    waitmovement 0
    delay 15
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalWest::
    applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
    waitmovement 0
    delay 15
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalNorth::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskNorth::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakWalkToDesk
    waitmovement 0
    return

ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskSouth::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakWalkToDeskSouth
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_WatchOakWalkToDesk
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_WatchOakWalkToDesk
    waitmovement LOCALID_PROF_OAK
    return

ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskEast::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakWalkToDesk
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_WatchOakWalkToDeskEast
    waitmovement LOCALID_PROF_OAK
    return

ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskWest::
    applymovement LOCALID_PROF_OAK, ProfessorOaksLab_Movement_OakWalkToDesk
    waitmovement 0
    return

ProfessorOaksLab_Movement_OakWalkToDesk::
    walk_up
    walk_left
    delay_16
    walk_in_place_faster_down
    step_end

ProfessorOaksLab_Movement_OakWalkToDeskSouth::
    walk_left
    walk_left
    walk_up
    delay_16
    walk_in_place_faster_right
    step_end

ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerNorth::
    applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    return

ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerSouth::
    applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest::
    applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

ProfessorOaksLab_EventScript_OakBattleMonForItToGrow::
    msgbox ProfessorOaksLab_Text_OakBattleMonForItToGrow, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon::
    msgbox ProfessorOaksLab_Text_OakCanReachNextTownWithMon, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_Aide1::
    lock
    faceplayer
    goto_if_set FLAG_SYS_GAME_CLEAR, ProfessorOaksLab_EventScript_Aide1GameClear
    msgbox ProfessorOaksLab_Text_StudyAsOaksAide, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_Aide1GameClear::
    msgbox ProfessorOaksLab_Text_OakIsGoingToHaveRadioShow, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_Aide2::
    lock
    faceplayer
    goto_if_set FLAG_SYS_GAME_CLEAR, ProfessorOaksLab_EventScript_Aide2GameClear
    msgbox ProfessorOaksLab_Text_StudyAsOaksAide, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_Aide2GameClear::
    msgbox ProfessorOaksLab_Text_DaisyWillGroomMons, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_Aide3::
    lock
    faceplayer
    msgbox ProfessorOaksLab_Text_OakIsAuthorityOnMons, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_Pokedex::
    msgbox ProfessorOaksLab_Text_BlankEncyclopedia, MSGBOX_NPC
    end

ProfessorOaksLab_EventScript_LeaveStarterSceneTrigger::
    lockall
    applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
    waitmovement 0
    msgbox ProfessorOaksLab_Text_OakHeyDontGoAwayYet, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_PlayerWalkUp
    waitmovement 0
    releaseall
    end

ProfessorOaksLab_Movement_PlayerWalkUp::
    walk_up
    step_end

ProfessorOaksLab_EventScript_RivalBattleTriggerLeft::
    lockall
    setvar VAR_TEMP_2, 1
    goto ProfessorOaksLab_EventScript_RivalBattle
    end

ProfessorOaksLab_EventScript_RivalBattleTriggerMid::
    lockall
    setvar VAR_TEMP_2, 2
    goto ProfessorOaksLab_EventScript_RivalBattle
    end

ProfessorOaksLab_EventScript_RivalBattleTriggerRight::
    lockall
    setvar VAR_TEMP_2, 3
    goto ProfessorOaksLab_EventScript_RivalBattle
    end

ProfessorOaksLab_EventScript_RivalBattle::
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox ProfessorOaksLab_Text_RivalLetsCheckOutMons, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
    waitmovement 0
    compare VAR_TEMP_2, 1
    goto_if_eq ProfessorOaksLab_EventScript_RivalApproachForBattleLeft
    compare VAR_TEMP_2, 2
    goto_if_eq ProfessorOaksLab_EventScript_RivalApproachForBattleMid
    compare VAR_TEMP_2, 3
    goto_if_eq ProfessorOaksLab_EventScript_RivalApproachForBattle
    end
    
ProfessorOaksLab_EventScript_RivalApproachForBattleLeft::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalApproachForBattleLeft
    waitmovement 0
    goto ProfessorOaksLab_EventScript_RivalApproachForBattle
    end
    
ProfessorOaksLab_EventScript_RivalApproachForBattleMid::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalApproachForBattleMid
    waitmovement 0
    goto ProfessorOaksLab_EventScript_RivalApproachForBattle
    end

ProfessorOaksLab_Movement_RivalApproachForBattleLeft::
    walk_left
    walk_left
    step_end

ProfessorOaksLab_Movement_RivalApproachForBattleMid::
    walk_left
    step_end

ProfessorOaksLab_EventScript_RivalApproachForBattle::
    compare VAR_STARTER_MON, 0
    goto_if_eq ProfessorOaksLab_EventScript_RivalApproachForBattleCharmander
    compare VAR_STARTER_MON, 1
    goto_if_eq ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaur
    compare VAR_STARTER_MON, 2
    goto_if_eq ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtle
    end

ProfessorOaksLab_EventScript_RivalApproachForBattleCharmander::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalApproachForBattle
    waitmovement 0
    goto ProfessorOaksLab_EventScript_RivalBattleCharmander
    end

ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaur::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalApproachForBattleLeft
    waitmovement 0
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalApproachForBattle
    waitmovement 0
    goto ProfessorOaksLab_EventScript_RivalBattleBulbasaur
    end

ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtle::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalApproachForBattleMid
    waitmovement 0
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalApproachForBattle
    waitmovement 0
    goto ProfessorOaksLab_EventScript_RivalBattleSquirtle
    end

ProfessorOaksLab_Movement_RivalApproachForBattle::
    walk_left
    walk_down
    walk_down
    step_end

ProfessorOaksLab_EventScript_RivalBattleCharmander::
    trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_CHARMANDER, RIVAL_BATTLE_TUTORIAL, ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
    goto ProfessorOaksLab_EventScript_EndRivalBattle
    end

ProfessorOaksLab_EventScript_RivalBattleSquirtle::
    trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_SQUIRTLE, RIVAL_BATTLE_TUTORIAL, ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
    goto ProfessorOaksLab_EventScript_EndRivalBattle
    end

ProfessorOaksLab_EventScript_RivalBattleBulbasaur::
    trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_BULBASAUR, RIVAL_BATTLE_TUTORIAL, ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
    goto ProfessorOaksLab_EventScript_EndRivalBattle
    end

ProfessorOaksLab_EventScript_EndRivalBattle::
    special HealPlayerParty
    msgbox ProfessorOaksLab_Text_RivalGoToughenMyMon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_RG_RIVAL_EXIT, 0
    compare VAR_TEMP_2, 1
    call_if_eq ProfessorOaksLab_EventScript_RivalExitAfterBattleLeft
    compare VAR_TEMP_2, 2
    call_if_eq ProfessorOaksLab_EventScript_RivalExitAfterBattleMid
    compare VAR_TEMP_2, 3
    call_if_eq ProfessorOaksLab_EventScript_RivalExitAfterBattleRight
    removeobject LOCALID_RIVAL
    playse SE_EXIT
    fadedefaultbgm
    setvar VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 4
    setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
    releaseall
    end

ProfessorOaksLab_EventScript_RivalExitAfterBattleLeft::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalExitAfterBattleLeft
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle
    waitmovement LOCALID_RIVAL
    return

ProfessorOaksLab_EventScript_RivalExitAfterBattleMid::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalExitAfterBattleMid
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle
    waitmovement LOCALID_RIVAL
    return

ProfessorOaksLab_EventScript_RivalExitAfterBattleRight::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalExitAfterBattleRight
    applymovement OBJ_EVENT_ID_PLAYER, ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattleRight
    waitmovement LOCALID_RIVAL
    return

ProfessorOaksLab_Movement_RivalExitAfterBattleLeft::
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    delay_8
    step_end

ProfessorOaksLab_Movement_RivalExitAfterBattleRight::
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    delay_8
    step_end

ProfessorOaksLab_Movement_RivalExitAfterBattleMid::
    walk_right
    walk_down
    walk_down
    walk_down
    walk_left
    walk_down
    walk_down
    delay_8
    step_end

ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle::
    delay_16
    delay_8
    walk_in_place_faster_right
    delay_16
    walk_in_place_faster_down
    step_end

ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattleRight::
    delay_16
    delay_8
    walk_in_place_faster_left
    delay_16
    walk_in_place_faster_down
    step_end

ProfessorOaksLab_EventScript_CharmanderBall::
    lock
    faceplayer
    setvar PLAYER_STARTER_NUM, 2
    setvar PLAYER_STARTER_SPECIES, SPECIES_CHARMANDER
    setvar RIVAL_STARTER_SPECIES, SPECIES_SQUIRTLE
    setvar RIVAL_STARTER_ID, LOCALID_SQUIRTLE_BALL
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 3
    goto_if_ge ProfessorOaksLab_EventScript_LastPokeBall
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 2
    goto_if_eq ProfessorOaksLab_EventScript_ConfirmStarterChoice
    msgbox ProfessorOaksLab_Text_ThoseArePokeBalls, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_SquirtleBall::
    lock
    faceplayer
    setvar PLAYER_STARTER_NUM, 1
    setvar PLAYER_STARTER_SPECIES, SPECIES_SQUIRTLE
    setvar RIVAL_STARTER_SPECIES, SPECIES_BULBASAUR
    setvar RIVAL_STARTER_ID, LOCALID_BULBASAUR_BALL
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 3
    goto_if_ge ProfessorOaksLab_EventScript_LastPokeBall
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 2
    goto_if_eq ProfessorOaksLab_EventScript_ConfirmStarterChoice
    msgbox ProfessorOaksLab_Text_ThoseArePokeBalls, MSGBOX_DEFAULT
    release
    end
    
ProfessorOaksLab_EventScript_BulbasaurBall::
    lock
    faceplayer
    setvar PLAYER_STARTER_NUM, 0
    setvar PLAYER_STARTER_SPECIES, SPECIES_BULBASAUR
    setvar RIVAL_STARTER_SPECIES, SPECIES_CHARMANDER
    setvar RIVAL_STARTER_ID, LOCALID_CHARMANDER_BALL
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 3
    goto_if_ge ProfessorOaksLab_EventScript_LastPokeBall
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 2
    goto_if_eq ProfessorOaksLab_EventScript_ConfirmStarterChoice
    msgbox ProfessorOaksLab_Text_ThoseArePokeBalls, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_LastPokeBall::
    msgbox ProfessorOaksLab_Text_OaksLastMon, MSGBOX_DEFAULT
    release
    end

ProfessorOaksLab_EventScript_ConfirmStarterChoice::
    applymovement LOCALID_PROF_OAK, Common_Movement_FaceRight
    waitmovement 0
    showmonpic PLAYER_STARTER_SPECIES, 10, 3
    compare PLAYER_STARTER_NUM, 0
    goto_if_eq ProfessorOaksLab_EventScript_ConfirmBulbasaur
    compare PLAYER_STARTER_NUM, 1
    goto_if_eq ProfessorOaksLab_EventScript_ConfirmSquirtle
    compare PLAYER_STARTER_NUM, 2
    goto_if_eq ProfessorOaksLab_EventScript_ConfirmCharmander
    end

ProfessorOaksLab_EventScript_ConfirmBulbasaur::
    msgbox ProfessorOaksLab_Text_OakChoosingBulbasaur, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq ProfessorOaksLab_EventScript_ChoseStarter
    compare VAR_RESULT, NO
    goto_if_eq ProfessorOaksLab_EventScript_DeclinedStarter
    end

ProfessorOaksLab_EventScript_ConfirmSquirtle::
    msgbox ProfessorOaksLab_Text_OakChoosingSquirtle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq ProfessorOaksLab_EventScript_ChoseStarter
    compare VAR_RESULT, NO
    goto_if_eq ProfessorOaksLab_EventScript_DeclinedStarter
    end

ProfessorOaksLab_EventScript_ConfirmCharmander::
    msgbox ProfessorOaksLab_Text_OakChoosingCharmander, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq ProfessorOaksLab_EventScript_ChoseStarter
    compare VAR_RESULT, NO
    goto_if_eq ProfessorOaksLab_EventScript_DeclinedStarter
    end

ProfessorOaksLab_EventScript_DeclinedStarter::
    hidemonpic
    release
    end

ProfessorOaksLab_EventScript_ChoseStarter::
    hidemonpic
    removeobject VAR_LAST_TALKED
    msgbox ProfessorOaksLab_Text_OakThisMonIsEnergetic, MSGBOX_DEFAULT
    setflag FLAG_SYS_POKEMON_GET
    setflag FLAG_PALLET_LADY_NOT_BLOCKING_SIGN
    givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE
    copyvar VAR_STARTER_MON, PLAYER_STARTER_NUM
    bufferspeciesname 0, PLAYER_STARTER_SPECIES
    message ProfessorOaksLab_Text_ReceivedMonFromOak
    waitmessage
    playfanfare MUS_RG_OBTAIN_KEY_ITEM
    waitfanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_GiveNicknameToStarter
    compare VAR_RESULT, NO
    goto_if_eq ProfessorOaksLab_EventScript_RivalPicksStarter
    end

EventScript_GiveNicknameToStarter::
    setvar VAR_0x8004, 0
    call Common_EventScript_NameReceivedPartyMon
    goto ProfessorOaksLab_EventScript_RivalPicksStarter
    end

ProfessorOaksLab_EventScript_RivalPicksStarter::
    closemessage
    compare PLAYER_STARTER_NUM, 0
    goto_if_eq ProfessorOaksLab_EventScript_RivalWalksToCharmander
    compare PLAYER_STARTER_NUM, 1
    goto_if_eq ProfessorOaksLab_EventScript_RivalWalksToBulbasaur
    compare PLAYER_STARTER_NUM, 2
    goto_if_eq ProfessorOaksLab_EventScript_RivalWalksToSquirtle
    end

ProfessorOaksLab_EventScript_RivalWalksToCharmander::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalWalksToCharmander
    waitmovement 0
    goto ProfessorOaksLab_EventScript_RivalTakesStarter
    end

ProfessorOaksLab_EventScript_RivalWalksToSquirtle::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalWalksToSquirtle
    waitmovement 0
    goto ProfessorOaksLab_EventScript_RivalTakesStarter
    end

ProfessorOaksLab_EventScript_RivalWalksToBulbasaur::
    applymovement LOCALID_RIVAL, ProfessorOaksLab_Movement_RivalWalksToBulbasaur
    waitmovement 0
    goto ProfessorOaksLab_EventScript_RivalTakesStarter
    end

ProfessorOaksLab_Movement_RivalWalksToCharmander::
    walk_down
    walk_right
    walk_right
    walk_right
    walk_in_place_faster_up
    step_end
    
ProfessorOaksLab_Movement_RivalWalksToSquirtle::
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    step_end

ProfessorOaksLab_Movement_RivalWalksToBulbasaur::
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    step_end

ProfessorOaksLab_EventScript_RivalTakesStarter::
    msgbox ProfessorOaksLab_Text_RivalIllTakeThisOneThen
    removeobject RIVAL_STARTER_ID
    bufferspeciesname 0, RIVAL_STARTER_SPECIES
    msgbox ProfessorOaksLab_Text_RivalReceivedMonFromOak, MSGBOX_DEFAULT
    waitmessage
    playfanfare MUS_RG_OBTAIN_KEY_ITEM
    waitfanfare
    setvar VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 3
    call_if_set FLAG_OPENED_START_MENU, ProfessorOaksLab_EventScript_ReadyEndSignLadyScene
    release
    end

ProfessorOaksLab_EventScript_ReadyEndSignLadyScene::
    setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
    return

ProfessorOaksLab_EventScript_Computer::
    msgbox ProfessorOaksLab_Text_EmailMessage, MSGBOX_SIGN
    end

ProfessorOaksLab_EventScript_LeftSign::
    msgbox ProfessorOaksLab_Text_PressStartToOpenMenu, MSGBOX_SIGN
    end

ProfessorOaksLab_EventScript_RightSign::
    lockall
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 6
    goto_if_ge ProfessorOaksLab_EventScript_RightSignAlt
    msgbox ProfessorOaksLab_Text_SaveOptionInMenu, MSGBOX_SIGN
    releaseall
    end

ProfessorOaksLab_EventScript_RightSignAlt::
    msgbox ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints, MSGBOX_SIGN
    releaseall
    end

ProfessorOaksLab_Text_RivalFedUpWithWaiting::
    .string "{RIVAL}: Gramps!\n"
    .string "I'm fed up with waiting!$"

ProfessorOaksLab_Text_OakThreeMonsChooseOne::
    .string "Oak: {RIVAL}?\n"
    .string "Let me think…\p"
    .string "Oh, that's right, I told you to\n"
    .string "come! Just wait!\p"
    .string "Here, {PLAYER}.\p"
    .string "There are three Pokémon here.\p"
    .string "Haha!\p"
    .string "The Pokémon are held inside\n"
    .string "these Pokéballs.\p"
    .string "When I was young, I was a serious\n"
    .string "Pokémon Trainer.\p"
    .string "But now, in my old age, I have\n"
    .string "only these three left.\p"
    .string "You can have one.\n"
    .string "Go on, choose!$"

ProfessorOaksLab_Text_RivalNoFairWhatAboutMe::
    .string "{RIVAL}: Hey! Gramps! No fair!\n"
    .string "What about me?$"

ProfessorOaksLab_Text_OakBePatientRival::
    .string "Oak: Be patient, {RIVAL}.\n"
    .string "You can have one, too!$"

ProfessorOaksLab_Text_RivalMyMonLooksTougher::
    .string "{RIVAL}: My Pokémon looks a lot\n"
    .string "tougher than yours.$"

ProfessorOaksLab_Text_RivalGoChoosePlayer::
    .string "{RIVAL}: Heh, I don't need to be\n"
    .string "greedy like you. I'm mature!\p"
    .string "Go ahead and choose, {PLAYER}!$"
    
ProfessorOaksLab_Text_RivalGrampsIsntAround::
    .string "{RIVAL}: What, it's only {PLAYER}?\n"
    .string "Gramps isn't around.$"

ProfessorOaksLab_Text_OakComeSeeMeSometime::
    .string "Oak: Come see me sometime.\p"
    .string "After all, I want to know how your\n"
    .string "Pokédex is coming along.$"

ProfessorOaksLab_Text_OakAddedNothingToPokedex::
    .string "Ah, {PLAYER}!\n"
    .string "How is your Pokédex shaping up?\p"
    .string "{RIVAL} has already caught some\n"
    .string "Pokémon and added to the data.\p"
    .string "So, {PLAYER}, let's have a look at\n"
    .string "your Pokédex.\p"
    .string "…What's the matter?\n"
    .string "You've added no new data at all.\p"
    .string "I'll give you these, so do try a\n"
    .string "little harder.$"

ProfessorOaksLab_Text_OakMonsAroundWorldWait::
    .string "Pokémon around the world wait for\n"
    .string "you, {PLAYER}!$"

ProfessorOaksLab_Text_OakFavorToAskYouPlayer::
    .string "Ah, now this is excellent!\p"
    .string "{PLAYER}, I have another important\n"
    .string "favour to ask of you.\p"
    .string "I need you to listen closely.$"

ProfessorOaksLab_Text_OakSightingsOfRareMons::
    .string "Recently, there have been sightings\n"
    .string "of many rare Pokémon species.\p"
    .string "I'm talking about Pokémon that\n"
    .string "have never been seen in Kanto.\p"
    .string "I would love to go see things for\n"
    .string "myself, but I'm much too old.\p"
    .string "Since I can't do it, {PLAYER}, I'd\n"
    .string "like you to go in my place.$"

ProfessorOaksLab_Text_RivalJustLetMeHandleEverything::
    .string "{RIVAL}: Hey, I heard that!\p"
    .string "Gramps, what's with favouring\n"
    .string "{PLAYER} over me all the time?\p"
    .string "I went and collected more Pokémon,\n"
    .string "and faster, too.\p"
    .string "You should just let me handle\n"
    .string "everything.$"

ProfessorOaksLab_Text_OakNeedYourHelpTooNeedToSeePokedexes::
    .string "Oak: I know, I know.\n"
    .string "Of course I need your help, too.\p"
    .string "Now, I need to see both your\n"
    .string "Pokédexes.$"

ProfessorOaksLab_Text_OakTookBothPokedexUnits::
    .string "Prof. Oak took both Pokédex\n"
    .string "units.$"

ProfessorOaksLab_Text_OakNowTheseUnitsCanRecordMoreData::
    .string "… … …  … … …\p"
    .string "… … …  … … …\p"
    .string "…And that's done!\p"
    .string "Now these units can record data on\n"
    .string "a lot more Pokémon.$"

ProfessorOaksLab_Text_PlayersPokedexWasUpgraded::
    .string "{PLAYER}'s Pokédex was upgraded!$"

ProfessorOaksLab_Text_OakMustReallyWorkToFillPokedex::
    .string "Now, {PLAYER} and {RIVAL}!\p"
    .string "This time, you really must work\n"
    .string "towards filling your Pokédexes.\p"
    .string "I urge you to make them the best\n"
    .string "and the most complete of all time!\p"
    .string "Truly, this is a monumentally great\n"
    .string "undertaking in Pokémon history!$"

ProfessorOaksLab_Text_RivalIllCompleteThePokedex::
    .string "{RIVAL}: Gramps, calm down.\n"
    .string "Don't get so excited.\p"
    .string "I'll get the Pokédex completed,\n"
    .string "don't you worry about a thing.\p"
    .string "I think I'll try looking around\n"
    .string "One Island first…\p"
    .string "Anyways, I'm outta here!$"

ProfessorOaksLab_Text_OakHaveSomethingForMe::
    .string "Oak: Oh, {PLAYER}!\n"
    .string "How is my old Pokémon?\p"
    .string "Well, it seems to be growing more\n"
    .string "attached to you.\p"
    .string "You must be talented as a Pokémon\n"
    .string "Trainer.\p"
    .string "What's that?\n"
    .string "You have something for me?$"

ProfessorOaksLab_Text_DeliveredOaksParcel::
    .string "{PLAYER} delivered Oak's Parcel.$"

ProfessorOaksLab_Text_OakCustomBallIOrdered::
    .string "Ah! \n"
    .string "It's the custom Pokéball!\p"
    .string "I had it on order.\n"
    .string "Thank you!$"

ProfessorOaksLab_Text_RivalGramps::
    .string "{RIVAL}: Gramps!$"

ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor::
    .string "{RIVAL}: I almost forgot!\n"
    .string "What did you call me for?$"

ProfessorOaksLab_Text_OakHaveRequestForYouTwo::
    .string "Oak: Oh, right!\n"
    .string "I have a request for you two.$"

ProfessorOaksLab_Text_OakPokedexOnDesk::
    .string "On the desk there is my invention,\n"
    .string "the Pokédex!\p"
    .string "It automatically records data on\n"
    .string "Pokémon you've seen or caught.\p"
    .string "It's a high-tech encyclopedia!$"

ProfessorOaksLab_Text_OakTakeTheseWithYou::
    .string "Oak: {PLAYER} and {RIVAL}.\n"
    .string "Take these with you.$"

ProfessorOaksLab_Text_ReceivedPokedexFromOak::
    .string "{PLAYER} received the Pokédex\n"
    .string "from Prof. Oak.$"

ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese::
    .string "Oak: You can't get detailed data\n"
    .string "on Pokémon by just seeing them.\p"
    .string "You must catch them to obtain\n"
    .string "complete data.\p"
    .string "So, here are some tools for\n"
    .string "catching wild Pokémon.$"

ProfessorOaksLab_Text_ReceivedFivePokeBalls::
    .string "{PLAYER} received five Pokéballs.$"

ProfessorOaksLab_Text_OakExplainCatching:
    .string "When a wild Pokémon appears,\n"
    .string "it's fair game.\p"
    .string "Just throw a Pokéball at it and\n"
    .string "try to catch it!\p"
    .string "This won't always work, however.\p"
    .string "A healthy Pokémon can escape.\n"
    .string "You have to be lucky!$"

ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream::
    .string "To make a complete guide on all\n"
    .string "the Pokémon in the world…\p"
    .string "That was my dream!\p"
    .string "But, I'm too old.\n"
    .string "I can't get the job done.\p"
    .string "So, I want you two to fulfill my\n"
    .string "dream for me.\p"
    .string "Get moving, you two.\p"
    .string "This is a great undertaking in\n"
    .string "Pokémon history!$"

ProfessorOaksLab_Text_RivalLeaveItToMeGramps::
    .string "{RIVAL}: All right, Gramps!\n"
    .string "Leave it all to me!$"

ProfessorOaksLab_Text_RivalTellSisNotToGiveYouMap::
    .string "{PLAYER}, I hate to say it, but you\n"
    .string "won't be necessary for this.\p"
    .string "I know! I'll borrow a Town Map\n"
    .string "from my sis!\p"
    .string "I'll tell her not to lend you one,\n"
    .string "{PLAYER}! Hahaha!\p"
    .string "Don't bother coming around to\n"
    .string "my place after this!$"

ProfessorOaksLab_Text_OakBattleMonForItToGrow::
    .string "Oak: {PLAYER}, raise your young\n"
    .string "Pokémon by making it battle.\p"
    .string "It has to battle for it to grow.$"

ProfessorOaksLab_Text_OakCanReachNextTownWithMon::
    .string "Oak: If a wild Pokémon appears,\n"
    .string "your Pokémon can battle it.\p"
    .string "With it at your side, you should be\n"
    .string "able to reach the next town.$"

ProfessorOaksLab_Text_OakWhichOneWillYouChoose::
    .string "Oak: Now, {PLAYER}.\p"
    .string "Inside those three Pokéballs are\n"
    .string "Pokémon.\p"
    .string "Which one will you choose for\n"
    .string "yourself?$"

ProfessorOaksLab_Text_StudyAsOaksAide::
    .string "I study Pokémon as Prof. Oak's\n"
    .string "Aide.$"

ProfessorOaksLab_Text_OakIsGoingToHaveRadioShow::
    .string "Prof. Oak is going to have his own\n"
    .string "radio show soon.\p"
    .string "The program will be called Prof.\n"
    .string "Oak's Pokémon Seminar.$"

ProfessorOaksLab_Text_DaisyWillGroomMons::
    .string "Hi, {PLAYER}. I bet you've become\n"
    .string "good friends with your Pokémon.\p"
    .string "By the way, did you know about\n"
    .string "Daisy?\p"
    .string "If you show Daisy your Pokémon,\n"
    .string "she can tell how much it likes you.\p"
    .string "Occasionally, she will even groom\n"
    .string "a Pokémon for you.\p"
    .string "This is a secret, so please don't\n"
    .string "tell anyone.$"

ProfessorOaksLab_Text_OakIsAuthorityOnMons::
    .string "Prof. Oak may not look like much,\n"
    .string "but he's the authority on Pokémon.\p"
    .string "Many Pokémon Trainers hold him in\n"
    .string "high regard.$"

ProfessorOaksLab_Text_BlankEncyclopedia::
    .string "It's like an encyclopedia, but the\n"
    .string "pages are blank.$"

ProfessorOaksLab_Text_OakHeyDontGoAwayYet::
    .string "Oak: Hey!\n"
    .string "Don't go away yet!$"

ProfessorOaksLab_Text_RivalLetsCheckOutMons::
    .string "{RIVAL}: Wait, {PLAYER}!\n"
    .string "Let's check out our Pokémon!\p"
    .string "Come on, I'll take you on!$"

ProfessorOaksLab_Text_RivalDefeat::
    .string "WHAT?\n"
    .string "Unbelievable!\l"
    .string "I picked the wrong Pokémon!$"

Text_RivalVictory::
    .string "{RIVAL}: Yeah!\n"
    .string "Am I great or what?$"

ProfessorOaksLab_Text_RivalGoToughenMyMon::
    .string "{RIVAL}: Okay! I'll make my\n"
    .string "Pokémon battle to toughen it up!\p"
    .string "{PLAYER}! Gramps!\n"
    .string "Smell you later!$"

ProfessorOaksLab_Text_ThoseArePokeBalls::
    .string "Those are Pokéballs.\n"
    .string "They contain Pokémon!$"

ProfessorOaksLab_Text_OaksLastMon::
    .string "That's Prof. Oak's last Pokémon.$"

ProfessorOaksLab_Text_OakChoosingCharmander::
    .string "Ah! Charmander is your choice.\n"
    .string "You should raise it patiently.\p"
    .string "So, {PLAYER}, you're claiming\n"
    .string "the {COLOR}{RED}Fire{COLOR}{DARK_GRAY} Pokémon Charmander?$"

ProfessorOaksLab_Text_OakChoosingSquirtle::
    .string "Hm! Squirtle is your choice.\n"
    .string "It's one worth raising.\p"
    .string "So, {PLAYER}, you've decided on\n"
    .string "the {COLOR}{BLUE}Water{COLOR}{DARK_GRAY} Pokémon Squirtle?$"

ProfessorOaksLab_Text_OakChoosingBulbasaur::
    .string "I see! Bulbasaur is your choice.\n"
    .string "It's very easy to raise.\p"
    .string "So, {PLAYER}, you want to go with\n"
    .string "the {COLOR}{GREEN}Grass{COLOR}{DARK_GRAY} Pokémon Bulbasaur?$"

ProfessorOaksLab_Text_OakThisMonIsEnergetic::
    .string "This Pokémon is really quite\n"
    .string "energetic!$"

ProfessorOaksLab_Text_ReceivedMonFromOak::
    .string "{PLAYER} received the {STR_VAR_1}\n"
    .string "from Prof. Oak!$"

ProfessorOaksLab_Text_RivalIllTakeThisOneThen::
    .string "{RIVAL}: I'll take this one, then!$"

ProfessorOaksLab_Text_RivalReceivedMonFromOak::
    .string "{RIVAL} received the {STR_VAR_1}\n"
    .string "from Prof. Oak!$"

ProfessorOaksLab_Text_EmailMessage::
    .string "There's an e-mail message here.\p"
    .string "…\p"
    .string "Finally!\n"
    .string "The ultimate Trainers of the\l"
    .string "Pokémon League are ready to\l"
    .string "take on all comers!\p"
    .string "Bring your best Pokémon and see\n"
    .string "how you rate as a Trainer!\p"
    .string "Pokémon League HQ\n"
    .string "Indigo Plateau\p"
    .string "Prof. Oak, please visit us!\n"
    .string "…$"

ProfessorOaksLab_Text_PressStartToOpenMenu::
    .string "Press Start to open the Menu!$"

ProfessorOaksLab_Text_SaveOptionInMenu::
    .string "The Save option is on the Menu.\n"
    .string "Use it regularly.$"

ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints::
    .string "All Pokémon types have strong and\n"
    .string "weak points against others.$"
