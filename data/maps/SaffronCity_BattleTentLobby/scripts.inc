.set LOCALID_ATTENDANT, 1

SaffronCity_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SaffronCity_BattleTentLobby_OnWarp
	.byte 0

SaffronCity_BattleTentLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SaffronCity_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

SaffronCity_BattleTentLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SaffronCity_BattleTentLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SaffronCity_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, SaffronCity_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, SaffronCity_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, SaffronCity_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, SaffronCity_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

SaffronCity_BattleTentLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

SaffronCity_BattleTentLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox SaffronCity_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

SaffronCity_BattleTentLobby_EventScript_WonChallenge::
	lockall
	msgbox SaffronCity_BattleTentLobby_Text_BeatThreeTrainers, MSGBOX_DEFAULT
	message SaffronCity_BattleTentLobby_Text_WaitWhileSaveGame
	waitmessage
	saffrontent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	saffrontent_save 0
	playse SE_SAVE
	waitse

SaffronCity_BattleTentLobby_EventScript_GivePrize::
	msgbox SaffronCity_BattleTentLobby_Text_PresentYouWithPrize, MSGBOX_DEFAULT
	saffrontent_giveprize
	switch VAR_RESULT
	case FALSE, SaffronCity_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message SaffronCity_BattleTentLobby_Text_ReceivedPrize
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox SaffronCity_BattleTentLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

SaffronCity_BattleTentLobby_EventScript_NoRoomForPrize::
	msgbox SaffronCity_BattleTentLobby_Text_BagFullReturnForPrize, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

SaffronCity_BattleTentLobby_EventScript_PrizeWaiting::
	lockall
	msgbox SaffronCity_BattleTentLobby_Text_BeatThreeTrainers, MSGBOX_DEFAULT
	goto SaffronCity_BattleTentLobby_EventScript_GivePrize
	end

SaffronCity_BattleTentLobby_EventScript_LostChallenge::
	lockall
	message SaffronCity_BattleTentLobby_Text_ThankYouWaitWhileSaving
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	saffrontent_save 0
	playse SE_SAVE
	waitse
	msgbox SaffronCity_BattleTentLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

SaffronCity_BattleTentLobby_EventScript_ResumeChallenge::
	lockall
	message SaffronCity_BattleTentLobby_Text_LookingForwardToArrival
	waitmessage
	saffrontent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	goto SaffronCity_BattleTentLobby_EventScript_EnterChallenge

SaffronCity_BattleTentLobby_EventScript_Attendant::
	lock
	faceplayer
	saffrontent_getprize
	goto_if_ne VAR_RESULT, ITEM_NONE, SaffronCity_BattleTentLobby_EventScript_PrizeWaiting
	special SavePlayerParty
	msgbox SaffronCity_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
SaffronCity_BattleTentLobby_EventScript_AskEnterChallenge::
	message SaffronCity_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, SaffronCity_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, SaffronCity_BattleTentLobby_EventScript_ExplainChallenge
	case 2, SaffronCity_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, SaffronCity_BattleTentLobby_EventScript_CancelChallenge

SaffronCity_BattleTentLobby_EventScript_TryEnterChallenge::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	setvar VAR_RESULT, 2
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, SaffronCity_BattleTentLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox SaffronCity_BattleTentLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, SaffronCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	msgbox SaffronCity_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SaffronCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, SaffronCity_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, SaffronCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge

SaffronCity_BattleTentLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	saffrontent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, SaffronCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed
SaffronCity_BattleTentLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox SaffronCity_BattleTentLobby_Text_GuideYouToBattleTent, MSGBOX_DEFAULT
	closemessage
	call SaffronCity_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_SAFFRON_CITY_BATTLE_TENT_CORRIDOR, 2, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

SaffronCity_BattleTentLobby_EventScript_ExplainChallenge::
	msgbox SaffronCity_BattleTentLobby_Text_ExplainSaffronTent, MSGBOX_DEFAULT
	goto SaffronCity_BattleTentLobby_EventScript_AskEnterChallenge

SaffronCity_BattleTentLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, SaffronCity_BattleTentLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, SaffronCity_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen
SaffronCity_BattleTentLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox SaffronCity_BattleTentLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto SaffronCity_BattleTentLobby_EventScript_EndCancelChallenge

SaffronCity_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox SaffronCity_BattleTentLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto SaffronCity_BattleTentLobby_EventScript_EndCancelChallenge

SaffronCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto SaffronCity_BattleTentLobby_EventScript_CancelChallenge

SaffronCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
SaffronCity_BattleTentLobby_EventScript_CancelChallenge::
	msgbox SaffronCity_BattleTentLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
SaffronCity_BattleTentLobby_EventScript_EndCancelChallenge::
	release
	end

SaffronCity_BattleTentLobby_EventScript_WalkToDoor::
	applymovement LOCALID_ATTENDANT, SaffronCity_BattleTentLobby_Movement_AttendantWalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, SaffronCity_BattleTentLobby_Movement_PlayerWalkToDoor
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, SaffronCity_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, SaffronCity_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

SaffronCity_BattleTentLobby_Movement_AttendantWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

SaffronCity_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

SaffronCity_BattleTentLobby_Movement_PlayerWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

SaffronCity_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

SaffronCity_BattleTentLobby_EventScript_Hiker::
	msgbox SaffronCity_BattleTentLobby_Text_CameToCampOut, MSGBOX_NPC
	end

SaffronCity_BattleTentLobby_EventScript_LittleBoy::
	msgbox SaffronCity_BattleTentLobby_Text_MakeThinkImJustKid, MSGBOX_NPC
	end

SaffronCity_BattleTentLobby_EventScript_Lass::
	msgbox SaffronCity_BattleTentLobby_Text_SaffronTentMyFavorite, MSGBOX_NPC
	end

SaffronCity_BattleTentLobby_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_SAFFRON, SaffronCity_BattleTentLobby_EventScript_ScottAlreadySpokenTo
	msgbox SaffronCity_BattleTentLobby_Text_ScottLookingForSomeone, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_SAFFRON
	release
	end

SaffronCity_BattleTentLobby_EventScript_ScottAlreadySpokenTo::
	msgbox SaffronCity_BattleTentLobby_Text_ScottMakeChallenge, MSGBOX_DEFAULT
	release
	end

SaffronCity_BattleTentLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto SaffronCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SaffronCity_BattleTentLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_SAFFRON_TENT_RULES, FALSE
	switch VAR_RESULT
	case 0, SaffronCity_BattleTentLobby_EventScript_RulesLevel
	case 1, SaffronCity_BattleTentLobby_EventScript_RulesBattle
	case 2, SaffronCity_BattleTentLobby_EventScript_RulesMind
	case 3, SaffronCity_BattleTentLobby_EventScript_RulesSkill
	case 4, SaffronCity_BattleTentLobby_EventScript_RulesBody
	case 5, SaffronCity_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, SaffronCity_BattleTentLobby_EventScript_ExitRules
	end

SaffronCity_BattleTentLobby_EventScript_RulesLevel::
	msgbox BattleTentLobby_Text_ExplainLevelRules, MSGBOX_DEFAULT
	goto SaffronCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SaffronCity_BattleTentLobby_EventScript_RulesBattle::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto SaffronCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SaffronCity_BattleTentLobby_EventScript_RulesMind::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto SaffronCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SaffronCity_BattleTentLobby_EventScript_RulesSkill::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto SaffronCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SaffronCity_BattleTentLobby_EventScript_RulesBody::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto SaffronCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SaffronCity_BattleTentLobby_EventScript_ExitRules::
	releaseall
	end

SaffronCity_BattleTentLobby_Text_MakeThinkImJustKid:
	.string "Fufufufufu.\p"
	.string "I'm going to make everyone think\n"
	.string "I'm just a kid and let them play down.\p"
	.string "Then, I'll shock them and grab\n"
	.string "the title!$"

SaffronCity_BattleTentLobby_Text_SaffronTentMyFavorite:
	.string "You know how Battle Tents offer\n"
	.string "different events in different towns?\p"
	.string "My favorite is definitely the Battle\n"
	.string "Tent in Saffron Town.\p"
	.string "I think it's fantastic how Trainers\n"
	.string "try to win with all their faith in\l"
	.string "their Pokémon.$"

SaffronCity_BattleTentLobby_Text_CameToCampOut:
	.string "I heard something about some tent,\n"
	.string "so I came to camp out.\p"
	.string "I didn't know that tents these days\n"
	.string "are so luxurious!\p"
	.string "Since I'm here, I may as well try\n"
	.string "my hand at battling!$"

SaffronCity_BattleTentLobby_Text_ScottLookingForSomeone:
	.string "Scott: Hi, {PLAYER}{KUN}!\n"
	.string "So you came out to this Battle Tent!\p"
	.string "The people in these parts tend to be\n"
	.string "easygoing and laid-back.\p"
	.string "But, you see, what I'm looking for are\n"
	.string "people with…\p"
	.string "How should I say this?\p"
	.string "Someone bursting with the desire\n"
	.string "and the drive to win.\p"
	.string "If there were a Trainer like that,\n"
	.string "I'd immediately…\p"
	.string "Whoops! Never mind!\n"
	.string "Keep working at it!$"

SaffronCity_BattleTentLobby_Text_ScottMakeChallenge:
	.string "Scott: Instead of wasting your\n"
	.string "time with the likes of me, why not\l"
	.string "make a challenge?$"

