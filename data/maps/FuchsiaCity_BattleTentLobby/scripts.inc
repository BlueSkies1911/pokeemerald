.set LOCALID_ATTENDANT, 1

FuchsiaCity_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FuchsiaCity_BattleTentLobby_OnWarp
	.byte 0

FuchsiaCity_BattleTentLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, FuchsiaCity_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

FuchsiaCity_BattleTentLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

FuchsiaCity_BattleTentLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FuchsiaCity_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, FuchsiaCity_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, FuchsiaCity_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, FuchsiaCity_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, FuchsiaCity_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

FuchsiaCity_BattleTentLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

FuchsiaCity_BattleTentLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

FuchsiaCity_BattleTentLobby_EventScript_WonChallenge::
	lockall
	msgbox FuchsiaCity_BattleTentLobby_Text_AchievedThreeWinStreak, MSGBOX_DEFAULT
	message FuchsiaCity_BattleTentLobby_Text_FeatWillBeRecorded
	waitmessage
	fuchsiatent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	fuchsiatent_save 0
	playse SE_SAVE
	waitse

FuchsiaCity_BattleTentLobby_EventScript_GivePrize::
	msgbox FuchsiaCity_BattleTentLobby_Text_PresentYouWithPrize, MSGBOX_DEFAULT
	fuchsiatent_giveprize
	switch VAR_RESULT
	case FALSE, FuchsiaCity_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message BattleFrontier_BattleDomeLobby_Text_ReceivedPrize  @ Odd that it used Dome's copy instead of Palace's
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox FuchsiaCity_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

FuchsiaCity_BattleTentLobby_EventScript_NoRoomForPrize::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

FuchsiaCity_BattleTentLobby_EventScript_PrizeWaiting::
	lockall
	msgbox FuchsiaCity_BattleTentLobby_Text_AchievedThreeWinStreak, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_GivePrize
	end

FuchsiaCity_BattleTentLobby_EventScript_LostChallenge::
	lockall
	message FuchsiaCity_BattleTentLobby_Text_ResultsWillBeRecorded
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	fuchsiatent_save 0
	playse SE_SAVE
	waitse
	msgbox FuchsiaCity_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

FuchsiaCity_BattleTentLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	fuchsiatent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	goto FuchsiaCity_BattleTentLobby_EventScript_EnterChallenge

FuchsiaCity_BattleTentLobby_EventScript_Attendant::
	lock
	faceplayer
	fuchsiatent_getprize
	goto_if_ne VAR_RESULT, ITEM_NONE, FuchsiaCity_BattleTentLobby_EventScript_PrizeWaiting
	special SavePlayerParty
	msgbox FuchsiaCity_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
FuchsiaCity_BattleTentLobby_EventScript_AskEnterChallenge::
	message FuchsiaCity_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, FuchsiaCity_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, FuchsiaCity_BattleTentLobby_EventScript_ExplainChallenge
	case 2, FuchsiaCity_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, FuchsiaCity_BattleTentLobby_EventScript_CancelChallenge

FuchsiaCity_BattleTentLobby_EventScript_TryEnterChallenge::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	setvar VAR_RESULT, 2
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, FuchsiaCity_BattleTentLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox FuchsiaCity_BattleTentLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	msgbox FuchsiaCity_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FuchsiaCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, FuchsiaCity_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, FuchsiaCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge

FuchsiaCity_BattleTentLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	fuchsiatent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed
FuchsiaCity_BattleTentLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox FuchsiaCity_BattleTentLobby_Text_NowFollowMe, MSGBOX_DEFAULT
	closemessage
	call FuchsiaCity_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_FUCHSIA_CITY_BATTLE_TENT_CORRIDOR, 2, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

FuchsiaCity_BattleTentLobby_EventScript_ExplainChallenge::
	msgbox FuchsiaCity_BattleTentLobby_Text_ExplainFuchsiaTent, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_AskEnterChallenge

FuchsiaCity_BattleTentLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, FuchsiaCity_BattleTentLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, FuchsiaCity_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen

FuchsiaCity_BattleTentLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox FuchsiaCity_BattleTentLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_EndCancelChallenge

FuchsiaCity_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox FuchsiaCity_BattleTentLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_EndCancelChallenge

FuchsiaCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto FuchsiaCity_BattleTentLobby_EventScript_CancelChallenge

FuchsiaCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
FuchsiaCity_BattleTentLobby_EventScript_CancelChallenge::
	msgbox FuchsiaCity_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT
FuchsiaCity_BattleTentLobby_EventScript_EndCancelChallenge::
	release
	end

FuchsiaCity_BattleTentLobby_EventScript_WalkToDoor::
	applymovement LOCALID_ATTENDANT, FuchsiaCity_BattleTentLobby_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_BattleTentLobby_Movement_WalkToDoor
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, FuchsiaCity_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

FuchsiaCity_BattleTentLobby_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

FuchsiaCity_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

FuchsiaCity_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

FuchsiaCity_BattleTentLobby_EventScript_AttractGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM45, FuchsiaCity_BattleTentLobby_EventScript_ReceivedAttract
	msgbox FuchsiaCity_BattleTentLobby_Text_AttractionRunsDeep, MSGBOX_DEFAULT
	giveitem ITEM_TM45
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM45
	msgbox FuchsiaCity_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_BattleTentLobby_EventScript_ReceivedAttract::
	msgbox FuchsiaCity_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_BattleTentLobby_EventScript_Boy1::
	msgbox FuchsiaCity_BattleTentLobby_Text_TaughtWhatKindsOfMoves, MSGBOX_NPC
	end

FuchsiaCity_BattleTentLobby_EventScript_Boy2::
	lock
	msgbox FuchsiaCity_BattleTentLobby_Text_MonsReluctantToUseDislikedMoves, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_BattleTentLobby_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_FUCHSIA, FuchsiaCity_BattleTentLobby_EventScript_ScottAlreadySpokenTo
	msgbox FuchsiaCity_BattleTentLobby_Text_ScottCanMeetToughTrainers, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_FUCHSIA
	release
	end

FuchsiaCity_BattleTentLobby_EventScript_ScottAlreadySpokenTo::
	msgbox FuchsiaCity_BattleTentLobby_Text_ScottVisitRegularly, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_BattleTentLobby_EventScript_LittleBoy::
	lock
	msgbox FuchsiaCity_BattleTentLobby_Text_GentleMonsScaryIfAngry, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_BattleTentLobby_EventScript_RulesBoard::
	lockall
	msgbox FuchsiaCity_BattleTentLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

FuchsiaCity_BattleTentLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BATTLE_TENT_RULES
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, FuchsiaCity_BattleTentLobby_EventScript_RulesLevel
	case 1, FuchsiaCity_BattleTentLobby_EventScript_RulesBasics
	case 2, FuchsiaCity_BattleTentLobby_EventScript_RulesNature
	case 3, FuchsiaCity_BattleTentLobby_EventScript_RulesMoves
	case 4, FuchsiaCity_BattleTentLobby_EventScript_RulesUnderpowered
	case 5, FuchsiaCity_BattleTentLobby_EventScript_RulesWhenInDanger
	case 6, FuchsiaCity_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, FuchsiaCity_BattleTentLobby_EventScript_ExitRules
	end

FuchsiaCity_BattleTentLobby_EventScript_RulesLevel::
	msgbox BattleTentLobby_Text_ExplainLevelRules, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

FuchsiaCity_BattleTentLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

FuchsiaCity_BattleTentLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

FuchsiaCity_BattleTentLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

FuchsiaCity_BattleTentLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

FuchsiaCity_BattleTentLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto FuchsiaCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

FuchsiaCity_BattleTentLobby_EventScript_ExitRules::
	releaseall
	end

FuchsiaCity_BattleTentLobby_Text_MonsReluctantToUseDislikedMoves:
	.string "If it doesn't like a certain move,\n"
	.string "a Pokémon will be reluctant to use it.\p"
	.string "It doesn't matter how strong it is,\n"
	.string "either.\p"
	.string "For example, a Pokémon with a Gentle\n"
	.string "nature probably won't enjoy hurting\l"
	.string "its opponents.\p"
	.string "If it can't seem to live up to its\n"
	.string "potential, it's probably failing at\l"
	.string "using a disliked move against its will.$"

FuchsiaCity_BattleTentLobby_Text_GentleMonsScaryIfAngry:
	.string "My big sister is gentle usually.\n"
	.string "But when she gets angry,\l"
	.string "she's really, really scary!\p"
	.string "I bet a gentle Pokémon will be scary\n"
	.string "if it gets angry!$"

FuchsiaCity_BattleTentLobby_Text_AttractionRunsDeep:
	.string "My feelings toward my Pokémon…\n"
	.string "The attraction runs deep…\p"
	.string "Oh, hi, you didn't see that, did you?\n"
	.string "Well, it doesn't matter.\p"
	.string "How would you like this TM for\n"
	.string "your Pokémon?$"

FuchsiaCity_BattleTentLobby_Text_AttractionMutual:
	.string "My feelings toward my Pokémon…\n"
	.string "I'm sure the attraction is mutual!\p"
	.string "They battle exactly the way I want\n"
	.string "them to!$"

FuchsiaCity_BattleTentLobby_Text_TaughtWhatKindsOfMoves:
	.string "What kind of moves have you taught\n"
	.string "your Pokémon?\p"
	.string "I think you would give yourself\n"
	.string "an advantage if they knew how to\l"
	.string "heal or protect themselves.$"

FuchsiaCity_BattleTentLobby_Text_ScottCanMeetToughTrainers:
	.string "Scott: Hey there, {PLAYER}{KUN}!\n"
	.string "I thought I might see you here.\p"
	.string "A Battle Tent's a place where\n"
	.string "you can meet tough Trainers.\p"
	.string "It doesn't matter what the rules are,\n"
	.string "or how battles are waged, either.\p"
	.string "{PLAYER}{KUN}, I expect you to do\n"
	.string "the best you can!$"

FuchsiaCity_BattleTentLobby_Text_ScottVisitRegularly:
	.string "Scott: I visit here regularly in hopes\n"
	.string "of seeing tough Trainers in action\l"
	.string "in whatever the situation.$"