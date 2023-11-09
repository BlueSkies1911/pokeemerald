TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TrickHousePuzzle6_OnWarp
	.byte 0

TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, TrickHousePuzzle6_EventScript_FoundScroll
	goto TrickHousePuzzle_EventScript_ReadScrollAgain
	end

TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto TrickHousePuzzle_EventScript_FoundScroll
	end

TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_PKMN_RANGER_SOPHIA, TrickHousePuzzle6_Text_SophiaIntro, TrickHousePuzzle6_Text_SophiaDefeat
	msgbox TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle6_EventScript_Elijah::
	trainerbattle_single TRAINER_BIRD_KEEPER_ELIJAH, TrickHousePuzzle6_Text_ElijahIntro, TrickHousePuzzle6_Text_ElijahDefeat
	msgbox TrickHousePuzzle6_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_PKMN_RANGER_SEBASTIAN, TrickHousePuzzle6_Text_SebastianIntro, TrickHousePuzzle6_Text_SebastianDefeat
	msgbox TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“Trick Master is my life.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

TrickHousePuzzle6_Text_SophiaIntro:
	.string "When I heard there was a strange\n"
	.string "house, I had to check it out.$"

TrickHousePuzzle6_Text_SophiaDefeat:
	.string "I've discovered a tough Trainer!$"

TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "I'm sure having a good time checking\n"
	.string "this place out.\p"
	.string "It's a challenge I've found worth\n"
	.string "repeating!$"

TrickHousePuzzle6_Text_ElijahIntro:
	.string "Maybe I could get my Bird Pokémon\n"
	.string "to fly over the wall…$"

TrickHousePuzzle6_Text_ElijahDefeat:
	.string "Gwaaah! I blew it!$"

TrickHousePuzzle6_Text_ElijahPostBattle:
	.string "Ehehehe… I guess I lost because\n"
	.string "I was trying to cheat.$"

TrickHousePuzzle6_Text_SebastianIntro:
	.string "I'm getting dizzy from these rotating\n"
	.string "doors…$"

TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Everything's spinning around and\n"
	.string "around. I can't take this anymore…$"

TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "You don't seem to be affected at all.\n"
	.string "Or do you have your poker face on?$"

