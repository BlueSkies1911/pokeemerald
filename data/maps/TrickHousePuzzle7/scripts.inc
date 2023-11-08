TrickHousePuzzle7_MapScripts::
	.byte 0

TrickHousePuzzle7_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0, TrickHousePuzzle7_EventScript_FoundScroll
	goto TrickHousePuzzle_EventScript_ReadScrollAgain
	end

TrickHousePuzzle7_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 1
	goto TrickHousePuzzle_EventScript_FoundScroll
	end

TrickHousePuzzle7_EventScript_YellowButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

TrickHousePuzzle7_EventScript_BlueButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

TrickHousePuzzle7_EventScript_GreenButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

TrickHousePuzzle7_EventScript_PurpleButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

TrickHousePuzzle7_EventScript_Joshua::
	trainerbattle_single TRAINER_PSYCHIC_JOSHUA, TrickHousePuzzle7_Text_JoshuaIntro, TrickHousePuzzle7_Text_JoshuaDefeat
	msgbox TrickHousePuzzle7_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle7_EventScript_Valerie::
	trainerbattle_single TRAINER_CHANNELER_VALERIE, TrickHousePuzzle7_Text_ValerieIntro, TrickHousePuzzle7_Text_ValerieDefeat
	msgbox TrickHousePuzzle7_Text_ValeriePostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle7_EventScript_Alexis::
	trainerbattle_single TRAINER_PSYCHIC_ALEXIS, TrickHousePuzzle7_Text_AlexisIntro, TrickHousePuzzle7_Text_AlexisDefeat
	msgbox TrickHousePuzzle7_Text_AlexisPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle7_EventScript_Mariela::
	trainerbattle_single TRAINER_PSYCHIC_MARIELA, TrickHousePuzzle7_Text_MarielaIntro, TrickHousePuzzle7_Text_MarielaDefeat
	msgbox TrickHousePuzzle7_Text_MarielaPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle7_EventScript_Alvaro::
	trainerbattle_single TRAINER_PSYCHIC_ALVARO, TrickHousePuzzle7_Text_AlvaroIntro, TrickHousePuzzle7_Text_AlvaroDefeat
	msgbox TrickHousePuzzle7_Text_AlvaroPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle7_EventScript_Everett::
	trainerbattle_single TRAINER_GENTLEMEN_EVERETT, TrickHousePuzzle7_Text_EverettIntro, TrickHousePuzzle7_Text_EverettDefeat
	msgbox TrickHousePuzzle7_Text_EverettPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle7_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“Trick Master is huggable.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

TrickHousePuzzle7_Text_JoshuaIntro:
	.string "The Trick Master always vanishes\n"
	.string "like smoke. How does he do it?$"

TrickHousePuzzle7_Text_JoshuaDefeat:
	.string "Aiyeeeh! You're much too strong!\n"
	.string "How do you do it?$"

TrickHousePuzzle7_Text_JoshuaPostBattle:
	.string "I wish I could appear and disappear as\n"
	.string "if I were smoke, too.$"

TrickHousePuzzle7_Text_ValerieIntro:
	.string "Going around the same spot…\n"
	.string "It begets ill fortune…$"

TrickHousePuzzle7_Text_ValerieDefeat:
	.string "Defeated!\n"
	.string "It's a bad sign…$"

TrickHousePuzzle7_Text_ValeriePostBattle:
	.string "I've circled the same spot over ten\n"
	.string "times now… It's ill fortune…$"

TrickHousePuzzle7_Text_AlexisIntro:
	.string "Whoever wins will get through here\n"
	.string "first. That's the feeling I get.$"

TrickHousePuzzle7_Text_AlexisDefeat:
	.string "Oh!\n"
	.string "Well, go ahead, then!$"

TrickHousePuzzle7_Text_AlexisPostBattle:
	.string "You're solving all the puzzles in the\n"
	.string "Trick House. That's the feeling I get.$"

TrickHousePuzzle7_Text_MarielaIntro:
	.string "Nufufufu, here at last!\n"
	.string "Let's get right with it!$"

TrickHousePuzzle7_Text_MarielaDefeat:
	.string "You're so casual about winning!$"

TrickHousePuzzle7_Text_MarielaPostBattle:
	.string "Humph! I'm not upset!\n"
	.string "Not me!$"

TrickHousePuzzle7_Text_AlvaroIntro:
	.string "I ever so closely watched you coming!$"

TrickHousePuzzle7_Text_AlvaroDefeat:
	.string "This outcome I didn't see coming…$"

TrickHousePuzzle7_Text_AlvaroPostBattle:
	.string "Well, anyway, we both picked a weird\n"
	.string "place to get acquainted.\p"
	.string "As one weirdo to another,\n"
	.string "let's do our best!$"

TrickHousePuzzle7_Text_EverettIntro:
	.string "It's awfully cramped in here…$"

TrickHousePuzzle7_Text_EverettDefeat:
	.string "Oh, yes, strong you are.$"

TrickHousePuzzle7_Text_EverettPostBattle:
	.string "I was hoping to switch places with you\n"
	.string "when I beat you, but…$"
