PokemonTower_6F_MapScripts::
	.byte 0

PokemonTower_6F_EventScript_MarowakGhost::
	lockall
	msgbox PokemonTower_6F_Text_BeGoneIntruders, MSGBOX_DEFAULT
	setwildbattle SPECIES_MAROWAK, 30, ITEM_NONE
	special StartMarowakBattle
	waitstate
	compare VAR_RESULT, FALSE  @ Set by CB2_EndMarowakBattle
	goto_if_eq PokemonTower_6F_EventScript_DefeatedMarowakGhost
	applymovement OBJ_EVENT_ID_PLAYER, PokemonTower_6F_Movement_ForcePlayerUp
	waitmovement 0
	releaseall
	end

PokemonTower_6F_EventScript_DefeatedMarowakGhost::
	message PokemonTower_6F_Text_GhostWasCubonesMother
	waitmessage
	waitse
	playmoncry SPECIES_MAROWAK, 0
	waitbuttonpress
	waitmoncry
	msgbox PokemonTower_6F_Text_MothersSpiritWasCalmed, MSGBOX_DEFAULT
	setvar VAR_MAP_SCENE_POKEMON_TOWER_6F, 1
	releaseall
	end

PokemonTower_6F_Movement_ForcePlayerUp::
	walk_up
	step_end

PokemonTower_6F_EventScript_Angelica::
    trainerbattle_single TRAINER_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaIntro, PokemonTower_6F_Text_AngelicaDefeat
    msgbox PokemonTower_6F_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
    end

PokemonTower_6F_EventScript_Emilia::
    trainerbattle_single TRAINER_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaIntro, PokemonTower_6F_Text_EmiliaDefeat
    msgbox PokemonTower_6F_Text_EmiliaPostBattle, MSGBOX_AUTOCLOSE
    end

PokemonTower_6F_EventScript_Jennifer::
    trainerbattle_single TRAINER_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferIntro, PokemonTower_6F_Text_JenniferDefeat
    msgbox PokemonTower_6F_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
    end

PokemonTower_6F_Text_BeGoneIntruders::
    .string "Be gone…\n"
    .string "Intruders…$"

PokemonTower_6F_Text_GhostWasCubonesMother::
    .string "The ghost was the restless spirit\n"
    .string "of Cubone's mother!$"

PokemonTower_6F_Text_MothersSpiritWasCalmed::
    .string "The mother's spirit was calmed.\p"
    .string "It departed to the afterlife…$"

PokemonTower_6F_Text_AngelicaIntro::
    .string "Give…me…\n"
    .string "blood…$"

PokemonTower_6F_Text_AngelicaDefeat::
    .string "Groan!$"

PokemonTower_6F_Text_AngelicaPostBattle::
    .string "I feel anemic and weak…$"

PokemonTower_6F_Text_EmiliaIntro::
    .string "Urff…\n"
    .string "Kwaah!$"

PokemonTower_6F_Text_EmiliaDefeat::
    .string "Something fell out!$"

PokemonTower_6F_Text_EmiliaPostBattle::
    .string "My hair didn't fall out!\n"
    .string "It was a malevolent spirit!$"

PokemonTower_6F_Text_JenniferIntro::
    .string "Ke…ke…ke…\n"
    .string "ke…ke…ke!$"

PokemonTower_6F_Text_JenniferDefeat::
    .string "Keee!$"

PokemonTower_6F_Text_JenniferPostBattle::
    .string "What's going on here?$"
