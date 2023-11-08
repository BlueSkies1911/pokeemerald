TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TrickHousePuzzle1_OnLoad
	.byte 0

TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, TrickHousePuzzle1_EventScript_OpenDoor
	end

TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, TrickHousePuzzle1_EventScript_FoundScroll
	goto TrickHousePuzzle_EventScript_ReadScrollAgain
	end

TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto TrickHousePuzzle_EventScript_FoundScroll
	end

TrickHousePuzzle1_EventScript_Krise::
	trainerbattle_single TRAINER_LASS_KRISE, TrickHousePuzzle1_Text_KriseIntro, TrickHousePuzzle1_Text_KriseDefeat
	msgbox TrickHousePuzzle1_Text_KrisePostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle1_EventScript_Allen::
	trainerbattle_single TRAINER_YOUNGSTER_ALLEN, TrickHousePuzzle1_Text_AllenIntro, TrickHousePuzzle1_Text_AllenDefeat
	msgbox TrickHousePuzzle1_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle1_EventScript_Tiana::
	trainerbattle_single TRAINER_LASS_TIANA, TrickHousePuzzle1_Text_TianaIntro, TrickHousePuzzle1_Text_TianaDefeat
	msgbox TrickHousePuzzle1_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“Trick Master is fabulous.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

TrickHousePuzzle1_Text_KriseIntro:
	.string "I'll hack and slash my way to victory\n"
	.string "with the Cut we just learned!$"

TrickHousePuzzle1_Text_KriseDefeat:
	.string "Why are you so serious?$"

TrickHousePuzzle1_Text_KrisePostBattle:
	.string "I never get tired of hacking\n"
	.string "and slashing!$"

TrickHousePuzzle1_Text_AllenIntro:
	.string "I wandered into this weird house\n"
	.string "by accident…$"

TrickHousePuzzle1_Text_AllenDefeat:
	.string "And now I've lost…$"

TrickHousePuzzle1_Text_AllenPostBattle:
	.string "I lost my way, I lost a battle, and I'm\n"
	.string "now even more lost… I can't get out…$"

TrickHousePuzzle1_Text_TianaIntro:
	.string "Just who is the Trick Master?$"

TrickHousePuzzle1_Text_TianaDefeat:
	.string "I lost while I was lost in thought!$"

TrickHousePuzzle1_Text_TianaPostBattle:
	.string "You're strong!\n"
	.string "Just who are you?$"

