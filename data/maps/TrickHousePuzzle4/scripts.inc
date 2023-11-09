TrickHousePuzzle4_MapScripts::
	.byte 0

TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, TrickHousePuzzle4_EventScript_FoundScroll
	goto TrickHousePuzzle_EventScript_ReadScrollAgain
	end

TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto TrickHousePuzzle_EventScript_FoundScroll
	end

TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CRUSH_GIRL_CORA, TrickHousePuzzle4_Text_CoraIntro, TrickHousePuzzle4_Text_CoraDefeat
	msgbox TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_BLACK_BELT_YUJI, TrickHousePuzzle4_Text_YujiIntro, TrickHousePuzzle4_Text_YujiDefeat
	msgbox TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_CRUSH_GIRL_PAULA, TrickHousePuzzle4_Text_PaulaIntro, TrickHousePuzzle4_Text_PaulaDefeat
	msgbox TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“Trick Master is cool.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

TrickHousePuzzle4_Text_CoraIntro:
	.string "It's too much bother to think this out.\n"
	.string "I only wanted to battle!$"

TrickHousePuzzle4_Text_CoraDefeat:
	.string "Even though I lost, I still like battling\n"
	.string "the best!$"

TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Wouldn't you agree? You would go\n"
	.string "anywhere if Trainers were there.$"

TrickHousePuzzle4_Text_YujiIntro:
	.string "Heh! Boulders like this, I can brush\n"
	.string "aside with one finger!$"

TrickHousePuzzle4_Text_YujiDefeat:
	.string "I can push boulders, but I can't solve\n"
	.string "the puzzle…$"

TrickHousePuzzle4_Text_YujiPostBattle:
	.string "It's not good enough to be brawny…\n"
	.string "You have to use your head. Be brainy!$"

TrickHousePuzzle4_Text_PaulaIntro:
	.string "The Trick House is getting trickier,\n"
	.string "isn't it?$"

TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaak!$"

TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Has anyone made it to the end?$"

