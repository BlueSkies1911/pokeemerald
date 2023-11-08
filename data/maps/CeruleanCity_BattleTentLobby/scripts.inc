.set LOCALID_ATTENDANT, 1

CeruleanCity_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CeruleanCity_BattleTentLobby_OnWarp
	.byte 0

CeruleanCity_BattleTentLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, CeruleanCity_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

CeruleanCity_BattleTentLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

CeruleanCity_BattleTentLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, CeruleanCity_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, CeruleanCity_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, CeruleanCity_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, CeruleanCity_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, CeruleanCity_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

CeruleanCity_BattleTentLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

CeruleanCity_BattleTentLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox CeruleanCity_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

CeruleanCity_BattleTentLobby_EventScript_WonChallenge::
	lockall
	message CeruleanCity_BattleTentLobby_Text_WonThreeMatchesReturnMons
	waitmessage
	ceruleantent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	ceruleantent_save 0
	playse SE_SAVE
	waitse
CeruleanCity_BattleTentLobby_EventScript_GivePrize::
	msgbox CeruleanCity_BattleTentLobby_Text_AwardYouThisPrize, MSGBOX_DEFAULT
	ceruleantent_giveprize
	switch VAR_RESULT
	case FALSE, CeruleanCity_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize  @ Odd that it uses Tower's instead of Factory's or its own
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto CeruleanCity_BattleTentLobby_EventScript_EndGivePrize

CeruleanCity_BattleTentLobby_EventScript_NoRoomForPrize::
	msgbox CeruleanCity_BattleTentLobby_Text_NoRoomInBagMakeRoom, MSGBOX_DEFAULT
	goto CeruleanCity_BattleTentLobby_EventScript_EndGivePrize

CeruleanCity_BattleTentLobby_EventScript_LostChallenge::
	lockall
	message CeruleanCity_BattleTentLobby_Text_ReturnRentalMonsSaveResults
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	ceruleantent_save 0
	playse SE_SAVE
	waitse

CeruleanCity_BattleTentLobby_EventScript_EndGivePrize::
	msgbox CeruleanCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

CeruleanCity_BattleTentLobby_EventScript_ResumeChallenge::
	lockall
	message CeruleanCity_BattleTentLobby_Text_BeenWaitingForYou
	waitmessage
	ceruleantent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	setvar VAR_0x8006, 2
	goto CeruleanCity_BattleTentLobby_EventScript_EnterChallenge

CeruleanCity_BattleTentLobby_EventScript_Attendant::
	lock
	faceplayer
	ceruleantent_getprize
	goto_if_ne VAR_RESULT, ITEM_NONE, CeruleanCity_BattleTentLobby_EventScript_GivePrize
	special SavePlayerParty
	msgbox CeruleanCity_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
CeruleanCity_BattleTentLobby_EventScript_AskEnterChallenge::
	message CeruleanCity_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, CeruleanCity_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, CeruleanCity_BattleTentLobby_EventScript_ExplainChallenge
	case 2, CeruleanCity_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, CeruleanCity_BattleTentLobby_EventScript_CancelChallenge

CeruleanCity_BattleTentLobby_EventScript_TryEnterChallenge::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox CeruleanCity_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, CeruleanCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, CeruleanCity_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, CeruleanCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge

CeruleanCity_BattleTentLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	ceruleantent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, CeruleanCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
CeruleanCity_BattleTentLobby_EventScript_EnterChallenge::
	msgbox CeruleanCity_BattleTentLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call CeruleanCity_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_CERULEAN_CITY_BATTLE_TENT_CORRIDOR, 2, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

CeruleanCity_BattleTentLobby_EventScript_WalkToDoor::
	applymovement LOCALID_ATTENDANT, CeruleanCity_BattleTentLobby_Movement_AttendantWalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_BattleTentLobby_Movement_PlayerWalkToDoor
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, CeruleanCity_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

CeruleanCity_BattleTentLobby_Movement_AttendantWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

CeruleanCity_BattleTentLobby_Movement_PlayerWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

CeruleanCity_BattleTentLobby_EventScript_ExplainChallenge::
	msgbox CeruleanCity_BattleTentLobby_Text_ExplainCeruleanTent, MSGBOX_DEFAULT
	goto CeruleanCity_BattleTentLobby_EventScript_AskEnterChallenge

CeruleanCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto CeruleanCity_BattleTentLobby_EventScript_CancelChallenge

CeruleanCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
CeruleanCity_BattleTentLobby_EventScript_CancelChallenge::
	msgbox CeruleanCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BattleTentLobby_EventScript_TormentGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM41, CeruleanCity_BattleTentLobby_EventScript_ReceivedTorment
	msgbox CeruleanCity_BattleTentLobby_Text_CouldntFindMonForMe, MSGBOX_DEFAULT
	giveitem ITEM_TM41
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM41
	msgbox CeruleanCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BattleTentLobby_EventScript_ReceivedTorment::
	msgbox CeruleanCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BattleTentLobby_EventScript_Man::
	msgbox CeruleanCity_BattleTentLobby_Text_IllTryUsingBugMons, MSGBOX_NPC
	end

CeruleanCity_BattleTentLobby_EventScript_Girl::
	msgbox CeruleanCity_BattleTentLobby_Text_BattleEvenWithoutToughMons, MSGBOX_NPC
	end

CeruleanCity_BattleTentLobby_EventScript_Woman::
	msgbox CeruleanCity_BattleTentLobby_Text_NiceIfMoreSelection, MSGBOX_NPC
	end

CeruleanCity_BattleTentLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto CeruleanCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

CeruleanCity_BattleTentLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_CERULEAN_TENT_RULES, FALSE
	switch VAR_RESULT
	case 0, CeruleanCity_BattleTentLobby_EventScript_RulesBasics
	case 1, CeruleanCity_BattleTentLobby_EventScript_RulesSwapPartner
	case 2, CeruleanCity_BattleTentLobby_EventScript_RulesSwapNumber
	case 3, CeruleanCity_BattleTentLobby_EventScript_RulesSwapNotes
	case 4, CeruleanCity_BattleTentLobby_EventScript_RulesMons
	case 5, CeruleanCity_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, CeruleanCity_BattleTentLobby_EventScript_ExitRules
	end

CeruleanCity_BattleTentLobby_EventScript_RulesBasics::
	msgbox CeruleanCity_BattleTentLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto CeruleanCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

CeruleanCity_BattleTentLobby_EventScript_RulesSwapPartner::
	msgbox CeruleanCity_BattleTentLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto CeruleanCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

CeruleanCity_BattleTentLobby_EventScript_RulesSwapNumber::
	msgbox CeruleanCity_BattleTentLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto CeruleanCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

CeruleanCity_BattleTentLobby_EventScript_RulesSwapNotes::
	msgbox CeruleanCity_BattleTentLobby_Text_ExplainSwapNotes, MSGBOX_DEFAULT
	goto CeruleanCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

CeruleanCity_BattleTentLobby_EventScript_RulesMons::
	msgbox CeruleanCity_BattleTentLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto CeruleanCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

CeruleanCity_BattleTentLobby_EventScript_ExitRules::
	releaseall
	end

CeruleanCity_BattleTentLobby_Text_CouldntFindMonForMe:
	.string "So, like, I couldn't find myself any\n"
	.string "Pokémon that were, like, for me.\p"
	.string "So, I figured, like, hey, I should file\n"
	.string "a complaint to the guy there?\p"
	.string "And he wouldn't hear me out, like, hey!\n"
	.string "So, like, total bummer, man!\p"
	.string "Hey, like, you! Zip it, you know?\n"
	.string "Just, you know, take this!$"

CeruleanCity_BattleTentLobby_Text_ExplainTorment:
	.string "That's, like, TM41, you know?\n"
	.string "Hey, it's Torment, you hearing me?\p"
	.string "Like, it won't let the other guy\n"
	.string "use the same move twice in a row, see?\p"
	.string "Hey, now, you listen here, like,\n"
	.string "I'm not laying a torment on you!$"

CeruleanCity_BattleTentLobby_Text_IllTryUsingBugMons:
	.string "I don't really like Bug Pokémon,\n"
	.string "but maybe I'll try using some for\l"
	.string "a change of pace.\p"
	.string "Who knows, I might even get to like\n"
	.string "them!$"

CeruleanCity_BattleTentLobby_Text_BattleEvenWithoutToughMons:
	.string "You can battle all you want here even\n"
	.string "if you don't have any tough Pokémon.$"

CeruleanCity_BattleTentLobby_Text_NiceIfMoreSelection:
	.string "Wouldn't it be nice if they had more of\n"
	.string "a selection?$"

