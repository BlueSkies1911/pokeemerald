Route12_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnResume:
    call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Route12_EventScript_TryRemoveSnorlax
    end

Route12_EventScript_TryRemoveSnorlax::
    removeobject VAR_LAST_TALKED
    return

Route12_EventScript_Snorlax::
    lock
    faceplayer
    goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
    msgbox gText_WantToUsePokeFlute, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Route12_EventScript_DontUsePokeFlute
    call Common_EventScript_AwakenSnorlax
    setwildbattle SPECIES_SNORLAX, 30, ITEM_NONE
    waitse
    playmoncry SPECIES_SNORLAX, 2
    delay 40
    waitmoncry
    setflag FLAG_HIDE_ROUTE_12_SNORLAX
    setflag FLAG_SYS_SPECIAL_WILD_BATTLE
    setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
    dowildbattle
    clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_WON
    goto_if_eq Route12_EventScript_FoughtSnorlax
    compare VAR_RESULT, B_OUTCOME_RAN
    goto_if_eq Route12_EventScript_FoughtSnorlax
    compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
    goto_if_eq Route12_EventScript_FoughtSnorlax
    release
    end

Route12_EventScript_DontUsePokeFlute::
    release
    end

Route12_EventScript_FoughtSnorlax::
    msgbox gText_SnorlaxReturnedToMountains, MSGBOX_DEFAULT
    release
    end

Route12_EventScript_SnorlaxNoPokeFlute::
    msgbox Route12_Text_MonSprawledOutInSlumber, MSGBOX_DEFAULT
    release
    end

Route12_EventScript_Ned::
    trainerbattle_single TRAINER_FISHERMAN_NED, Route12_Text_NedIntro, Route12_Text_NedDefeat
    msgbox Route12_Text_NedPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_Chip::
    trainerbattle_single TRAINER_FISHERMAN_CHIP, Route12_Text_ChipIntro, Route12_Text_ChipDefeat
    msgbox Route12_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_Hank::
    trainerbattle_single TRAINER_FISHERMAN_HANK, Route12_Text_HankIntro, Route12_Text_HankDefeat
    msgbox Route12_Text_HankPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_Elliot::
    trainerbattle_single TRAINER_FISHERMAN_ELLIOT, Route12_Text_ElliotIntro, Route12_Text_ElliotDefeat, Route12_EventScript_RegisterElliot
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route12_EventScript_ElliotRematch
    msgbox Route12_Text_ElliotPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_RegisterElliot::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_FISHERMAN_ELLIOT
	release
	end

Route12_EventScript_ElliotRematch::
    trainerbattle_rematch TRAINER_FISHERMAN_ELLIOT, Route12_Text_ElliotRematchIntro, Route12_Text_ElliotDefeat
    msgbox Route12_Text_ElliotPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_Andrew::
    trainerbattle_single TRAINER_FISHERMAN_ANDREW, Route12_Text_AndrewIntro, Route12_Text_AndrewDefeat
    msgbox Route12_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_Luca::
    trainerbattle_single TRAINER_ROCKER_LUCA, Route12_Text_LucaIntro, Route12_Text_LucaDefeat, Route12_EventScript_RegisterLuca
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route12_EventScript_LucaRematch
    msgbox Route12_Text_LucaPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_RegisterLuca::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_LucaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROCKER_LUCA
	release
	end

Route12_EventScript_LucaRematch::
    trainerbattle_rematch TRAINER_ROCKER_LUCA, Route12_Text_LucaRematchIntro, Route12_Text_LucaDefeat
    msgbox Route12_Text_LucaPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_Justin::
    trainerbattle_single TRAINER_CAMPER_JUSTIN, Route12_Text_JustinIntro, Route12_Text_JustinDefeat
    msgbox Route12_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_Jes::
    trainerbattle_double TRAINER_YOUNG_COUPLE_GIA_JES, Route12_Text_JesIntro, Route12_Text_JesDefeat, Route12_Text_JesNotEnoughMons, Route12_EventScript_RegisterJes
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route12_EventScript_JesRematch
    msgbox Route12_Text_JesPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_RegisterJes::
	msgbox Route12_Text_JesRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_YOUNG_COUPLE_GIA_JES
	release
	end

Route12_EventScript_JesRematch::
    trainerbattle_rematch_double TRAINER_YOUNG_COUPLE_GIA_JES, Route12_Text_JesRematchIntro, Route12_Text_JesDefeat, Route12_Text_JesNotEnoughMons
    msgbox Route12_Text_JesPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_Gia::
    trainerbattle_double TRAINER_YOUNG_COUPLE_GIA_JES, Route12_Text_GiaIntro, Route12_Text_GiaDefeat, Route12_Text_GiaNotEnoughMons, Route12_EventScript_RegisterGia
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route12_EventScript_GiaRematch
    msgbox Route12_Text_GiaPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_RegisterGia::
	msgbox Route12_Text_JesRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_YOUNG_COUPLE_GIA_JES
	release
	end

Route12_EventScript_GiaRematch::
    trainerbattle_rematch_double TRAINER_YOUNG_COUPLE_GIA_JES, Route12_Text_GiaRematchIntro, Route12_Text_GiaDefeat, Route12_Text_GiaNotEnoughMons
    msgbox Route12_Text_GiaPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_EventScript_RouteSign::
    msgbox Route12_Text_RouteSign, MSGBOX_SIGN
    end

Route12_EventScript_FishingSign::
    msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
    end

Route12_Text_MonSprawledOutInSlumber::
    .string "A Pokémon is sprawled out in\n"
    .string "a deep and comfortable slumber.$"

Route12_Text_RouteSign::
    .string "ROUTE 12 \n"
    .string "North to Lavender$"

Route12_Text_SportfishingArea::
    .string "Sportfishing Area$"
