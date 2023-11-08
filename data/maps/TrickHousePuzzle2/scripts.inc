TrickHousePuzzle2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrickHousePuzzle2_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TrickHousePuzzle2_OnTransition
	.byte 0

TrickHousePuzzle2_OnResume:
	call_if_eq VAR_TEMP_1, 1, TrickHousePuzzle2_EventScript_PressButton1
	call_if_eq VAR_TEMP_2, 1, TrickHousePuzzle2_EventScript_PressButton2
	call_if_eq VAR_TEMP_3, 1, TrickHousePuzzle2_EventScript_PressButton3
	call_if_eq VAR_TEMP_4, 1, TrickHousePuzzle2_EventScript_PressButton4
	end

TrickHousePuzzle2_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	end

TrickHousePuzzle2_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0, TrickHousePuzzle2_EventScript_FoundScroll
	goto TrickHousePuzzle_EventScript_ReadScrollAgain
	end

TrickHousePuzzle2_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 1
	goto TrickHousePuzzle_EventScript_FoundScroll
	end

TrickHousePuzzle2_EventScript_Button1::
	lockall
	setvar VAR_TEMP_1, 1
	playse SE_PIN
	call TrickHousePuzzle2_EventScript_PressButton1
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle2_EventScript_Button2::
	lockall
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call TrickHousePuzzle2_EventScript_PressButton2
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle2_EventScript_Button3::
	lockall
	setvar VAR_TEMP_3, 1
	playse SE_PIN
	call TrickHousePuzzle2_EventScript_PressButton3
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle2_EventScript_Button4::
	lockall
	setvar VAR_TEMP_4, 1
	playse SE_PIN
	call TrickHousePuzzle2_EventScript_PressButton4
	special DrawWholeMapView
	releaseall
	end

TrickHousePuzzle2_EventScript_PressButton1::
	setmetatile 11, 12, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 1, 13, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

TrickHousePuzzle2_EventScript_PressButton2::
	setmetatile 0, 4, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 5, 6, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

TrickHousePuzzle2_EventScript_PressButton3::
	setmetatile 14, 5, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 7, 15, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

TrickHousePuzzle2_EventScript_PressButton4::
	setmetatile 7, 11, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 14, 12, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

TrickHousePuzzle2_EventScript_Ted::
	trainerbattle_single TRAINER_SUPER_NERD_TED, TrickHousePuzzle2_Text_TedIntro, TrickHousePuzzle2_Text_TedDefeat
	msgbox TrickHousePuzzle2_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle2_EventScript_Paul::
	trainerbattle_single TRAINER_SUPER_NERD_PAUL, TrickHousePuzzle2_Text_PaulIntro, TrickHousePuzzle2_Text_PaulDefeat
	msgbox TrickHousePuzzle2_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle2_EventScript_Georgia::
	trainerbattle_single TRAINER_AROMA_LADY_GEORGIA, TrickHousePuzzle2_Text_GeorgiaIntro, TrickHousePuzzle2_Text_GeorgiaDefeat
	msgbox TrickHousePuzzle2_Text_GeorgiaPostBattle, MSGBOX_AUTOCLOSE
	end

TrickHousePuzzle2_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“Trick Master is smart.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

TrickHousePuzzle2_Text_TedIntro:
	.string "Which switch closes which hole?$"

TrickHousePuzzle2_Text_TedDefeat:
	.string "After that battle, I'm even more\n"
	.string "confused!$"

TrickHousePuzzle2_Text_TedPostBattle:
	.string "Can I get you to push all the buttons\n"
	.string "for me?$"

TrickHousePuzzle2_Text_PaulIntro:
	.string "Oh! You're on your second Trick House\n"
	.string "challenge!$"

TrickHousePuzzle2_Text_PaulDefeat:
	.string "You're good at battling too?$"

TrickHousePuzzle2_Text_PaulPostBattle:
	.string "The Trick Master rigged all the tricks\n"
	.string "in this house all by himself.$"

TrickHousePuzzle2_Text_GeorgiaIntro:
	.string "I want to make my own Gym one day.\n"
	.string "So, I'm studying how to set traps.$"

TrickHousePuzzle2_Text_GeorgiaDefeat:
	.string "I didn't study battling enough!$"

TrickHousePuzzle2_Text_GeorgiaPostBattle:
	.string "You're strong, aren't you?\n"
	.string "Maybe even enough to be a Gym Leader!$"

