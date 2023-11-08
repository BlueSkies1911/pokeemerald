.set LOCALID_TRICK_MASTER, 1

TrickHouseEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TrickHouseEntrance_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrickHouseEntrance_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TrickHouseEntrance_OnWarp
	.byte 0

	@ State descriptions for VAR_TRICK_HOUSE_ENTRANCE_STATE
	@ 0: Trick Master is hiding
	@ 1: Trick Master has left at start of challenge
	@ 2: Trick Master ready to give normal reward from previous challenge (if bag was full)
	@ 3: Trick Master still making next puzzle
	@ 4: Finished final puzzle
	@ 5: Completed previous challenge
	@ 6: 'Trick Master' mechadoll ready to give Tent reward from final challenge (if bag was full)

TrickHouseEntrance_OnTransition:
	setflag FLAG_LANDMARK_TRICK_HOUSE
	goto_if_eq VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 1, TrickHouseEntrance_EventScript_EnterFromCorridor
	goto_if_eq VAR_TRICK_HOUSE_PRIZE_PICKUP, 1, TrickHouseEntrance_EventScript_SetReadyToGiveReward
	goto_if_eq VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, TrickHouseEntrance_EventScript_MoveTrickMasterToDoor
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger
	case 1, TrickHouseEntrance_EventScript_SetNotBeingWatched1
	case 3, TrickHouseEntrance_EventScript_SetNotBeingWatched2
	case 4, TrickHouseEntrance_EventScript_SetNotBeingWatched3
	end

TrickHouseEntrance_EventScript_SetReadyToGiveReward::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 8, TrickHouseEntrance_EventScript_ReadyToGiveTentReward
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 2
	end

TrickHouseEntrance_EventScript_ReadyToGiveTentReward::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 6
	end

TrickHouseEntrance_EventScript_EnterFromCorridor::
	setvar VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 0
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, TrickHouseEntrance_EventScript_CheckReadyForPuzzle2
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, TrickHouseEntrance_EventScript_CheckReadyForPuzzle3
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 3, TrickHouseEntrance_EventScript_CheckReadyForPuzzle4
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 4, TrickHouseEntrance_EventScript_CheckReadyForPuzzle5
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 5, TrickHouseEntrance_EventScript_CheckReadyForPuzzle6
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 6, TrickHouseEntrance_EventScript_CheckReadyForPuzzle7
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 7, TrickHouseEntrance_EventScript_CheckReadyForPuzzle8
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 8, TrickHouseEntrance_EventScript_FinishedPuzzles
	return

TrickHouseEntrance_EventScript_CheckReadyForPuzzle2::
	call_if_unset FLAG_BADGE03_GET, TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

TrickHouseEntrance_EventScript_CheckReadyForPuzzle3::
	call_if_unset FLAG_BADGE04_GET, TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

TrickHouseEntrance_EventScript_CheckReadyForPuzzle4::
	call_if_unset FLAG_BADGE05_GET, TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

TrickHouseEntrance_EventScript_CheckReadyForPuzzle5::
	call_if_unset FLAG_BADGE06_GET, TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

TrickHouseEntrance_EventScript_CheckReadyForPuzzle6::
	call_if_unset FLAG_BADGE07_GET, TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

TrickHouseEntrance_EventScript_CheckReadyForPuzzle7::
	call_if_unset FLAG_BADGE08_GET, TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

TrickHouseEntrance_EventScript_CheckReadyForPuzzle8::
	call_if_unset FLAG_SYS_GAME_CLEAR, TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

TrickHouseEntrance_EventScript_FinishedPuzzles::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 4
	return

TrickHouseEntrance_EventScript_NotReadyForPuzzle::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
	return

TrickHouseEntrance_EventScript_MoveTrickMasterToDoor::
	setobjectxyperm LOCALID_TRICK_MASTER, 5, 2
	end

TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 0
	end

TrickHouseEntrance_EventScript_SetNotBeingWatched1::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

TrickHouseEntrance_EventScript_SetNotBeingWatched2::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

TrickHouseEntrance_EventScript_SetNotBeingWatched3::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

TrickHouseEntrance_OnWarp:
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, TrickHouseEntrance_EventScript_TrickMasterFound
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 1, TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 2, TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 4, TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 6, TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor
	.2byte 0

TrickHouseEntrance_EventScript_TrickMasterFound::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_TRICK_HOUSE_ENTRANCE
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	end

TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot::
	addobject LOCALID_TRICK_MASTER
	hideobjectat LOCALID_TRICK_MASTER, MAP_TRICK_HOUSE_ENTRANCE
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1
	case 1, TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2
	case 2, TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3
	case 3, TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4
	case 4, TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5
	case 5, TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6
	case 6, TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7
	case 7, TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8
	end

TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1::
	setobjectxy LOCALID_TRICK_MASTER, 6, 3
	end

TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2::
	setobjectxy LOCALID_TRICK_MASTER, 11, 5
	end

TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3::
	setobjectxy LOCALID_TRICK_MASTER, 9, 1
	end

TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4::
	setobjectxy LOCALID_TRICK_MASTER, 3, 1
	end

TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5::
	setobjectxy LOCALID_TRICK_MASTER, 0, 5
	end

TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6::
	setobjectxy LOCALID_TRICK_MASTER, 11, 1
	end

TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7::
	setobjectxy LOCALID_TRICK_MASTER, 8, 1
	end

TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8::
	setobjectxy LOCALID_TRICK_MASTER, 4, 4
	end

TrickHouseEntrance_EventScript_RemoveTrickMaster::
	removeobject LOCALID_TRICK_MASTER
	end

TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor::
	addobject LOCALID_TRICK_MASTER
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
	turnobject LOCALID_TRICK_MASTER, DIR_NORTH
	end

TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor::
	addobject LOCALID_TRICK_MASTER
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
	turnobject LOCALID_TRICK_MASTER, DIR_SOUTH
	end

TrickHouseEntrance_OnFrame:
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, TrickHouseEntrance_EventScript_BeginChallenge
	.2byte 0

TrickHouseEntrance_EventScript_BeginChallenge::
	lockall
	delay 20
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, TrickHouseEntrance_EventScript_MeetTrickMaster
	msgbox TrickHouseEntrance_Text_ComeToChallengeTrickHouse, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_TRICK_MASTER, TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 1
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 0
	releaseall
	end

TrickHouseEntrance_EventScript_TrickMaster::
	lockall
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, TrickHouseEntrance_EventScript_FoundTrickMaster
	case 2, TrickHouseEntrance_EventScript_GiveReward
	case 3, TrickHouseEntrance_EventScript_StillMakingPuzzle
	case 6, TrickHouseEntrance_EventScript_MechadollReward
	end

TrickHouseEntrance_EventScript_FoundTrickMaster::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, TrickHouseEntrance_EventScript_FoundBeneathDesk
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, TrickHouseEntrance_EventScript_FoundBehindTree
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, TrickHouseEntrance_EventScript_FoundInDresser
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 3, TrickHouseEntrance_EventScript_FoundBeyondWindow
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 4, TrickHouseEntrance_EventScript_FoundInPlanter
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 5, TrickHouseEntrance_EventScript_FoundInCupboard
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 6, TrickHouseEntrance_EventScript_FoundBehindWindow
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 7, TrickHouseEntrance_EventScript_FoundBeneathCushion
	closemessage
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1
	warpsilent MAP_TRICK_HOUSE_ENTRANCE, 6, 2
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_FoundBeneathDesk::
	msgbox TrickHouseEntrance_Text_ConcealedBeneathDesk, MSGBOX_DEFAULT
	return

TrickHouseEntrance_EventScript_FoundBehindTree::
	msgbox TrickHouseEntrance_Text_ConcealedBehindTree, MSGBOX_DEFAULT
	return

TrickHouseEntrance_EventScript_FoundInDresser::
	msgbox TrickHouseEntrance_Text_ConcealedInDresser, MSGBOX_DEFAULT
	return

TrickHouseEntrance_EventScript_FoundBeyondWindow::
	msgbox TrickHouseEntrance_Text_ConealedBeyondWindow, MSGBOX_DEFAULT
	return

TrickHouseEntrance_EventScript_FoundInPlanter::
	msgbox TrickHouseEntrance_Text_ConcealedInPlanter, MSGBOX_DEFAULT
	return

TrickHouseEntrance_EventScript_FoundInCupboard::
	msgbox TrickHouseEntrance_Text_ConcealedInCupboard, MSGBOX_DEFAULT
	return

TrickHouseEntrance_EventScript_FoundBehindWindow::
	msgbox TrickHouseEntrance_Text_ConcealedBehindWindow, MSGBOX_DEFAULT
	return

TrickHouseEntrance_EventScript_FoundBeneathCushion::
	msgbox TrickHouseEntrance_Text_ConcealedBeneathCushion, MSGBOX_DEFAULT
	return

TrickHouse_Movement_TrickMasterSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

TrickHouse_Movement_TrickMasterJumpAway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

TrickHouseEntrance_EventScript_MeetTrickMaster::
	msgbox TrickHouseEntrance_Text_TheyCallMeTrickMaster, MSGBOX_DEFAULT
	return

TrickHouseEntrance_EventScript_StillMakingPuzzle::
	msgbox TrickHouseEntrance_Text_NextTimeUseThisTrick, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TRICK_MASTER, Common_Movement_Delay48
	waitmovement 0
	msgbox TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges, MSGBOX_DEFAULT
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

TrickHouseEntrance_EventScript_GiveReward::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox TrickHouseEntrance_Text_YoureHereToAcceptReward, MSGBOX_DEFAULT
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 1, TrickHouseEntrance_EventScript_GivePuzzle1Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 2, TrickHouseEntrance_EventScript_GivePuzzle2Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 3, TrickHouseEntrance_EventScript_GivePuzzle3Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 4, TrickHouseEntrance_EventScript_GivePuzzle4Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 5, TrickHouseEntrance_EventScript_GivePuzzle5Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 6, TrickHouseEntrance_EventScript_GivePuzzle6Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 7, TrickHouseEntrance_EventScript_GivePuzzle7Reward
	end

TrickHouseEntrance_EventScript_GivePuzzle1Reward::
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, TRUE, TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_GivePuzzle2Reward::
	giveitem ITEM_TIMER_BALL
	goto_if_eq VAR_RESULT, TRUE, TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_GivePuzzle3Reward::
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, TRUE, TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_GivePuzzle4Reward::
	giveitem ITEM_SMOKE_BALL
	goto_if_eq VAR_RESULT, TRUE, TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_GivePuzzle5Reward::
	giveitem ITEM_TM12
	goto_if_eq VAR_RESULT, TRUE, TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_GivePuzzle6Reward::
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, TRUE, TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_GivePuzzle7Reward::
	giveitem ITEM_PP_MAX
	goto_if_eq VAR_RESULT, TRUE, TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_GotReward::
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

TrickHouseEntrance_EventScript_MechadollReward::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox TrickHouseEntrance_Text_MechadollWhichTent, MSGBOX_DEFAULT
	call TrickHouseEntrance_EventScript_ChooseTent
	goto_if_eq VAR_RESULT, TRUE, TrickHouseEntrance_EventScript_ReceivedTent
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_NoRoomForDecor
	msgbox TrickHouseEntrance_Text_PCFullAgain, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, TrickHouseEntrance_EventScript_GiveRedTent
	goto TrickHouseEntrance_EventScript_GiveBlueTent

TrickHouseEntrance_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

TrickHouseEntrance_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

TrickHouseEntrance_EventScript_ReceivedTent::
	msgbox TrickHouseEntrance_Text_ThenFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, TrickHousePuzzle5_Movement_MechadollShake
	waitmovement 0
	applymovement LOCALID_TRICK_MASTER, TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
	releaseall
	end

TrickHouseEntrance_EventScript_Door::
	lockall
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, TrickHouseEntrance_EventScript_ItsAScroll
	case 1, TrickHouseEntrance_EventScript_GoInHolePrompt
	case 4, TrickHouseEntrance_EventScript_LeftOnJourneyNote
	case 5, TrickHouseEntrance_EventScript_CheckLevelForMessage
	end

TrickHouseEntrance_EventScript_ItsAScroll::
	msgbox TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_GoInHolePrompt::
	msgbox TrickHouseEntrance_Text_GoInHoleBehindScroll, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, TrickHouseEntrance_EventScript_EnterPuzzleRoom
	releaseall
	end

TrickHouseEntrance_EventScript_EnterPuzzleRoom::
	setmetatile 5, 1, METATILE_TrickHouse_Stairs_Down, FALSE
	special DrawWholeMapView
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, TrickHouseEntrance_Movement_EnterRoom
	waitmovement 0
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, TrickHouseEntrance_EventScript_EnterPuzzleRoom1
	case 1, TrickHouseEntrance_EventScript_EnterPuzzleRoom2
	case 2, TrickHouseEntrance_EventScript_EnterPuzzleRoom3
	case 3, TrickHouseEntrance_EventScript_EnterPuzzleRoom4
	case 4, TrickHouseEntrance_EventScript_EnterPuzzleRoom5
	case 5, TrickHouseEntrance_EventScript_EnterPuzzleRoom6
	case 6, TrickHouseEntrance_EventScript_EnterPuzzleRoom7
	case 7, TrickHouseEntrance_EventScript_EnterPuzzleRoom8
	end

TrickHouseEntrance_Movement_EnterRoom:
	set_invisible
	step_end

TrickHouseEntrance_EventScript_EnterPuzzleRoom1::
	warp MAP_TRICK_HOUSE_PUZZLE1, 0, 21
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_EnterPuzzleRoom2::
	warp MAP_TRICK_HOUSE_PUZZLE2, 0, 21
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_EnterPuzzleRoom3::
	warp MAP_TRICK_HOUSE_PUZZLE3, 0, 21
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_EnterPuzzleRoom4::
	warp MAP_TRICK_HOUSE_PUZZLE4, 0, 21
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_EnterPuzzleRoom5::
	warp MAP_TRICK_HOUSE_PUZZLE5, 0, 21
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_EnterPuzzleRoom6::
	warp MAP_TRICK_HOUSE_PUZZLE6, 0, 21
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_EnterPuzzleRoom7::
	warp MAP_TRICK_HOUSE_PUZZLE7, 0, 21
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_EnterPuzzleRoom8::
	warp MAP_TRICK_HOUSE_PUZZLE8, 0, 21
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_LeftOnJourneyNote::
	msgbox TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_CheckLevelForMessage::
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 8, TrickHouseEntrance_EventScript_LeftOnJourneyNote2
	msgbox TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_LeftOnJourneyNote2::
	msgbox TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
	releaseall
	end

TrickHousePuzzle_EventScript_Door::
	lockall
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, TrickHousePuzzle1_EventScript_Door
	case 1, TrickHousePuzzle2_EventScript_Door
	case 2, TrickHousePuzzle3_EventScript_Door
	case 3, TrickHousePuzzle4_EventScript_Door
	case 4, TrickHousePuzzle5_EventScript_Door
	case 5, TrickHousePuzzle6_EventScript_Door
	case 6, TrickHousePuzzle7_EventScript_Door
	case 7, TrickHousePuzzle8_EventScript_Door
	end

TrickHousePuzzle1_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, TrickHousePuzzle_EventScript_DoorLocked
	msgbox TrickHousePuzzle1_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle2_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0, TrickHousePuzzle_EventScript_DoorLocked
	msgbox TrickHousePuzzle2_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle3_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0, TrickHousePuzzle_EventScript_DoorLocked
	msgbox TrickHousePuzzle3_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle4_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, TrickHousePuzzle_EventScript_DoorLocked
	msgbox TrickHousePuzzle4_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle5_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0, TrickHousePuzzle_EventScript_DoorLocked
	msgbox TrickHousePuzzle5_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle6_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, TrickHousePuzzle_EventScript_DoorLocked
	msgbox TrickHousePuzzle6_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle7_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0, TrickHousePuzzle_EventScript_DoorLocked
	msgbox TrickHousePuzzle7_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle8_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, TrickHousePuzzle_EventScript_DoorLocked
	msgbox TrickHousePuzzle8_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle_EventScript_DoorLocked::
	msgbox TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere, MSGBOX_DEFAULT
	releaseall
	end

TrickHousePuzzle_EventScript_ReadScrollAgain::
	msgbox TrickHousePuzzle_Text_SecretCodeWrittenOnIt, MSGBOX_DEFAULT
	releaseall
	end

TrickHousePuzzle_EventScript_FoundScroll::
	playfanfare MUS_OBTAIN_ITEM
	message TrickHousePuzzle_Text_FoundAScroll
	waitfanfare
	msgbox TrickHousePuzzle_Text_MemorisedSecretCode, MSGBOX_DEFAULT
	releaseall
	end

TrickHouseEntrance_EventScript_TrickMasterHiding::
	lockall
	msgbox TrickHouseEntrance_Text_YoureBeingWatched, MSGBOX_DEFAULT
	releaseall
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, TrickHouseEntrance_EventScript_DoHidingSpotSparkle1
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, TrickHouseEntrance_EventScript_DoHidingSpotSparkle2
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, TrickHouseEntrance_EventScript_DoHidingSpotSparkle3
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

TrickHouseEntrance_EventScript_DoHidingSpotSparkle1::
	setvar VAR_0x8004, 6  @ x
	setvar VAR_0x8005, 3  @ y
	call TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

TrickHouseEntrance_EventScript_DoHidingSpotSparkle2::
	setvar VAR_0x8004, 11  @ x
	setvar VAR_0x8005, 5   @ y
	call TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

TrickHouseEntrance_EventScript_DoHidingSpotSparkle3::
	setvar VAR_0x8004, 9  @ x
	setvar VAR_0x8005, 2  @ y
	call TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

TrickHouseEntrance_EventScript_DoHidingSpotSparkle::
	setvar VAR_0x8006, 0
	dofieldeffectsparkle VAR_0x8004, VAR_0x8005, VAR_0x8006
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	return

TrickHouseEntrance_Text_YoureBeingWatched:
	.string "You're being watched…$"

TrickHouseEntrance_Text_ConcealedBeneathDesk:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "beneath this desk? You're sharp!$"

TrickHouseEntrance_Text_ConcealedBehindTree:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "behind this tree? You're sharp!$"

TrickHouseEntrance_Text_ConcealedInDresser:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this dresser? You're sharp!$"

TrickHouseEntrance_Text_ConealedBeyondWindow:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "beyond this window? You're sharp!$"

TrickHouseEntrance_Text_ConcealedInPlanter:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this planter? You're sharp!$"

TrickHouseEntrance_Text_ConcealedInCupboard:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this cupboard? You're sharp!$"

TrickHouseEntrance_Text_ConcealedBehindWindow:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "behind this window? You're sharp!$"

TrickHouseEntrance_Text_ConcealedBeneathCushion:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "beneath this cushion? You're sharp!$"

TrickHouseEntrance_Text_TheyCallMeTrickMaster:
	.string "Behold!\p"
	.string "For I am the greatest living mystery\n"
	.string "of a man in all of Kanto!\l"
	.string "They call me…\p"
	.string "The Trick Master!\n"
	.string "Wahahaha! Glad to meet you!$"

TrickHouseEntrance_Text_ComeToChallengeTrickHouse:
	.string "You, you've come to challenge\n"
	.string "my Trick House, haven't you?\p"
	.string "That's why you're here, isn't it?\n"
	.string "Yes, it is!\p"
	.string "Consider your challenge accepted!\p"
	.string "Enter through the scroll there,\n"
	.string "and let your challenge commence!\p"
	.string "I shall be waiting in the back!$"

TrickHouseEntrance_Text_ItsAScroll:
	.string "It's a scroll.$"

TrickHouseEntrance_Text_GoInHoleBehindScroll:
	.string "There is a big hole behind the scroll!\p"
	.string "Want to go in?$"

TrickHouseEntrance_Text_LeavingOnJourneyNote:
	.string "There is a note affixed to the scroll…\p"
	.string "“I am leaving on a journey.\n"
	.string "Don't look for me. Trick Master”$"

TrickHouseEntrance_Text_NextTimeUseThisTrick:
	.string "For the next time, I'll use this trick,\n"
	.string "and that scheme, and those ruses…\p"
	.string "Mufufufu… If I may say so, it's\n"
	.string "brilliantly difficult, even for me!$"

TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges:
	.string "Hah? What?!\n"
	.string "Oh, it's you!\p"
	.string "I'm in the midst of devising new tricky\n"
	.string "challenges!\p"
	.string "It's not too much to ask for a bit more\n"
	.string "time for me to think, is it now?\l"
	.string "You wouldn't begrudge me that?\l"
	.string "Come back in a little while!$"

TrickHouseEntrance_Text_YoureHereToAcceptReward:
	.string "Ah, it's you! You're here to accept the\n"
	.string "reward from before, isn't that right?\l"
	.string "Yes, right I am!\p"
	.string "Here!\n"
	.string "I'll give it to you now!$"

TrickHouseEntrance_Text_DidYouNotComeToClaimReward:
	.string "Hah?\n"
	.string "Did you not come to claim your reward?$"

TrickHouseEntrance_Text_MechadollWhichTent:
	.string "Mechadoll 5 I am!\n"
	.string "If reward is not taken by you,\l"
	.string "then Trick Master you cannot follow.\p"
	.string "Red Tent or Blue Tent,\n"
	.string "which do you prefer?$"

TrickHouseEntrance_Text_ThenFarewell:
	.string "Then farewell.$"

TrickHouseEntrance_Text_PCFullAgain:
	.string "Your PC status: full again.\n"
	.string "Mean, you are.$"

TrickHousePuzzle_Text_FoundAScroll:
	.string "{PLAYER} found a scroll.$"

TrickHousePuzzle_Text_MemorisedSecretCode:
	.string "{PLAYER} memorised the secret code\n"
	.string "written on the scroll.$"

TrickHousePuzzle_Text_SecretCodeWrittenOnIt:
	.string "A secret code is written on it.$"

TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere:
	.string "The door is locked.\p"
	.string "…On closer inspection, this is written\n"
	.string "on it: “Write the secret code here.”$"
