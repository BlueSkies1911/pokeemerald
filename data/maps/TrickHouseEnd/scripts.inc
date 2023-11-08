.set LOCALID_TRICK_MASTER, 1

TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TrickHouseEnd_OnWarp
	.byte 0

TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	end

TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_TrickHouse_Door_Closed, TRUE
	return

TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, TrickHouseEnd_EventScript_CompletedPuzzle8
	end

TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, TrickHouseEnd_EventScript_BagFull
	msgbox TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, TrickHouseEnd_EventScript_BagFull
	msgbox TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, TrickHouseEnd_EventScript_BagFull
	msgbox TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, TrickHouseEnd_EventScript_BagFull
	msgbox TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM12
	call_if_eq VAR_RESULT, FALSE, TrickHouseEnd_EventScript_BagFull
	msgbox TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, TrickHouseEnd_EventScript_BagFull
	msgbox TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, TrickHouseEnd_EventScript_BagFull
	msgbox TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, TrickHouseEnd_EventScript_NoRoomForTent
	msgbox TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, TrickHouseEnd_EventScript_GiveRedTent
	goto TrickHouseEnd_EventScript_GiveBlueTent

TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

TrickHouseEnd_EventScript_TrickMasterExit::
	applymovement LOCALID_TRICK_MASTER, TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_TRICK_MASTER, TrickHouseEnd_Movement_TrickMasterSurprise
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrickHouseEnd_Movement_KeepPlayerInRoom
	waitmovement 0
	delay 4
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	releaseall
	end

TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

TrickHouseEnd_Text_YouveMadeItToMe:
	.string "Aak!\n"
	.string "You've made it to me?\l"
	.string "Hmmm… You're sharp!$"

TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "It took me all night to plant all those\n"
	.string "trees…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four, five, six places!$"

TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "It took me all night to make the maze…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four, five places!$"

TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "It took me all night to prepare\n"
	.string "the wall panels…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four places!$"

TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "It took me all night to shove in those\n"
	.string "boulders…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three places!$"

TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "It took me all night to make Mechadolls\n"
	.string "and another to think up the quiz…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two places!$"

TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "It took me all night to install\n"
	.string "the doors…\p"
	.string "You're almost my equal in greatness!$"

TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "It took me all night setting up arrows…\p"
	.string "You're my equal in greatness!$"

TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "It took me all night polishing floors…\p"
	.string "You're above me in greatness!\n"
	.string "Possibly…$"

TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "Wh-what should I do?\n"
	.string "My fountain of ideas for tricks has\l"
	.string "run dry…\p"
	.string "Perhaps it is time I toured the country\n"
	.string "on a quest to devise new tricks…$"

TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.string "I hate to admit defeat, but you have\n"
	.string "bested me!\p"
	.string "Still, you must have been reeled in by\n"
	.string "my charisma for you to visit me again\l"
	.string "and again. Yes, you must have!\p"
	.string "But that has nothing to do with my\n"
	.string "losing!\p"
	.string "In recognition of the friendship\n"
	.string "between you, the driven, and the genius\l"
	.string "that is myself, I demand that you take\l"
	.string "this keepsake!\p"
	.string "Actually there are two--\n"
	.string "a Red Tent and a Blue Tent.\l"
	.string "Which do you prefer?$"

TrickHouseEnd_Text_NoRoomInPC:
	.string "What? No room in your PC?\n"
	.string "What am I to make of that?\p"
	.string "I wish I could say that, but I am much\n"
	.string "too kind and caring, so come back later!$"

TrickHouseEnd_Text_LeavingOnJourney:
	.string "… … … … … …\p"
	.string "I am leaving on a journey of discovery.\n"
	.string "A quest in search of new tricks.\p"
	.string "I wish that you will one day visit and\n"
	.string "entertain me again.\p"
	.string "And now, farewell!$"

TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "Fine!\n"
	.string "You have earned this reward!$"

TrickHouseEnd_Text_NoRoomForThis:
	.string "What? Have you no room for this?\n"
	.string "What manner of items do you carry?\p"
	.string "But fine, since you've reached me,\n"
	.string "your reward will be with me till later.$"

TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "Scrub that smug smirk from your face!\n"
	.string "It's much too early to think you've won!\p"
	.string "I'll make new tricks to stump you, I will.\n"
	.string "You may mock me only when you're done.\p"
	.string "Come back for the next exciting\n"
	.string "installment!$"

TrickHouseEnd_Text_YoureIgnoringMe:
	.string "Now, now! You're ignoring me now?\n"
	.string "Now that, I consider heartbreaking!$"

