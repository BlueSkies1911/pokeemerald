TrickHousePuzzle8_MapScripts::
	.byte 0

TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, TrickHousePuzzle8_EventScript_FoundScroll
	goto TrickHousePuzzle_EventScript_ReadScrollAgain
	end

TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto TrickHousePuzzle_EventScript_FoundScroll
	end

TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_COOLTRAINER_VINCENT, TrickHousePuzzle8_Text_VincentIntro, TrickHousePuzzle8_Text_VincentDefeat
	msgbox TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_COOLTRAINER_KEIRA, TrickHousePuzzle8_Text_KeiraIntro, TrickHousePuzzle8_Text_KeiraDefeat
	msgbox TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle8_EventScript_Braxton::
	trainerbattle_single TRAINER_COOLTRAINER_BRAXTON, TrickHousePuzzle8_Text_BraxtonIntro, TrickHousePuzzle8_Text_BraxtonDefeat
	msgbox TrickHousePuzzle8_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“Trick Master I love.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

TrickHousePuzzle8_Text_VincentIntro:
	.string "Not many Trainers have made it\n"
	.string "this far.$"

TrickHousePuzzle8_Text_VincentDefeat:
	.string "That must mean you're tough, too…$"

TrickHousePuzzle8_Text_VincentPostBattle:
	.string "You've beaten the Pokémon League\n"
	.string "Champion? That's too much!$"

TrickHousePuzzle8_Text_KeiraIntro:
	.string "Consider yourself lucky to be\n"
	.string "battling me!$"

TrickHousePuzzle8_Text_KeiraDefeat:
	.string "This isn't right!\n"
	.string "I can't lose!$"

TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "It's a miracle that you beat me.\n"
	.string "You can brag about it.$"

TrickHousePuzzle8_Text_BraxtonIntro:
	.string "You've been slugging through the Trick\n"
	.string "House challenge, too.$"

TrickHousePuzzle8_Text_BraxtonDefeat:
	.string "I see…\n"
	.string "You possess an extraordinary style.$"

TrickHousePuzzle8_Text_BraxtonPostBattle:
	.string "Seeing someone like you should please\n"
	.string "the Trick Master.$"

