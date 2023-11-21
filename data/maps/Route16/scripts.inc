Route16_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
    map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnResume:
    call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Route16_EventScript_RemoveSnorlax
    end

Route16_EventScript_RemoveSnorlax::
    removeobject VAR_LAST_TALKED
    return

Route16_OnTransition:
	randomweather
    compare VAR_MAP_SCENE_ROUTE16, 1
    call_if_eq Route16_OnTransitionCyclingRoad
    end

Route16_OnTransitionCyclingRoad::
    setflag FLAG_SYS_CYCLING_ROAD
    return

Route16_OnWarp:
    map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route16_OnWarpCyclingRoad
    .2byte 0

Route16_OnWarpCyclingRoad:
    special ForcePlayerOntoBike
    end

Route16_EventScript_Snorlax::
    lock
    faceplayer
    goto_if_unset FLAG_GOT_POKE_FLUTE, Route16_EventScript_SnorlaxNoPokeFlute
    msgbox gText_WantToUsePokeFlute, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Route16_EventScript_DontUsePokeFlute
    call Common_EventScript_AwakenSnorlax
    setwildbattle SPECIES_SNORLAX, 30, ITEM_NONE
    waitse
    playmoncry SPECIES_SNORLAX, 2
    delay 40
    waitmoncry
    setflag FLAG_HIDE_ROUTE_16_SNORLAX
    setflag FLAG_SYS_SPECIAL_WILD_BATTLE
    dowildbattle
    clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_WON
    goto_if_eq Route16_EventScript_FoughtSnorlax
    compare VAR_RESULT, B_OUTCOME_RAN
    goto_if_eq Route16_EventScript_FoughtSnorlax
    compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
    goto_if_eq Route16_EventScript_FoughtSnorlax
    release
    end

Route16_EventScript_DontUsePokeFlute::
    release
    end

Route16_EventScript_FoughtSnorlax::
    msgbox gText_SnorlaxReturnedToMountains, MSGBOX_DEFAULT
    release
    end

Route16_EventScript_SnorlaxNoPokeFlute::
    msgbox Route16_Text_MonSprawledOutInSlumber, MSGBOX_DEFAULT
    release
    end

Route16_EventScript_Lao::
    trainerbattle_single TRAINER_BIKER_LAO, Route16_Text_LaoIntro, Route16_Text_LaoDefeat
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route16_EventScript_LaoRematch
    msgbox Route16_Text_LaoPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_LaoRematch::
    trainerbattle_rematch TRAINER_BIKER_LAO, Route16_Text_LaoRematchIntro, Route16_Text_LaoDefeat
    msgbox Route16_Text_LaoPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_Hideo::
    trainerbattle_single TRAINER_BIKER_HIDEO, Route16_Text_HideoIntro, Route16_Text_HideoDefeat
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route16_EventScript_HideoRematch
    msgbox Route16_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_HideoRematch::
    trainerbattle_rematch TRAINER_BIKER_HIDEO, Route16_Text_HideoRematchIntro, Route16_Text_HideoDefeat
    msgbox Route16_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_Ruben::
    trainerbattle_single TRAINER_BIKER_RUBEN, Route16_Text_RubenIntro, Route16_Text_RubenDefeat, Route16_EventScript_RegisterRuben
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route16_EventScript_RubenRematch
    msgbox Route16_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_RegisterRuben::
	msgbox Route16_Text_RubenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIKER_RUBEN
	release
	end

Route16_EventScript_RubenRematch::
    trainerbattle_rematch TRAINER_BIKER_RUBEN, Route16_Text_RubenRematchIntro, Route16_Text_RubenDefeat
    msgbox Route16_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_Koji::
    trainerbattle_single TRAINER_CUE_BALL_KOJI, Route16_Text_KojiIntro, Route16_Text_KojiDefeat
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route16_EventScript_KojiRematch
    msgbox Route16_Text_KojiPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_KojiRematch::
    trainerbattle_rematch TRAINER_CUE_BALL_KOJI, Route16_Text_KojiRematchIntro, Route16_Text_KojiDefeat
    msgbox Route16_Text_KojiPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_Luke::
    trainerbattle_single TRAINER_CUE_BALL_LUKE, Route16_Text_LukeIntro, Route16_Text_LukeDefeat
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route16_EventScript_LukeRematch
    msgbox Route16_Text_LukePostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_LukeRematch::
    trainerbattle_rematch TRAINER_CUE_BALL_LUKE, Route16_Text_LukeRematchIntro, Route16_Text_LukeDefeat
    msgbox Route16_Text_LukePostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_Camron::
    trainerbattle_single TRAINER_CUE_BALL_CAMRON, Route16_Text_CamronIntro, Route16_Text_CamronDefeat, Route16_EventScript_RegisterCamron
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route16_EventScript_CamronRematch
    msgbox Route16_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_RegisterCamron::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route16_Text_CamronRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CUE_BALL_CAMRON
	release
	end

Route16_EventScript_CamronRematch::
    trainerbattle_rematch TRAINER_CUE_BALL_CAMRON, Route16_Text_CamronRematchIntro, Route16_Text_CamronDefeat
    msgbox Route16_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_Jed::
    trainerbattle_double TRAINER_YOUNG_COUPLE_LEA_JED, Route16_Text_JedIntro, Route16_Text_JedDefeat, Route16_Text_JedNotEnoughMons
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route16_EventScript_JedRematch
    msgbox Route16_Text_JedPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_JedRematch::
    trainerbattle_rematch_double TRAINER_YOUNG_COUPLE_LEA_JED, Route16_Text_JedRematchIntro, Route16_Text_JedDefeat, Route16_Text_JedNotEnoughMons
    msgbox Route16_Text_JedPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_Lea::
    trainerbattle_double TRAINER_YOUNG_COUPLE_LEA_JED, Route16_Text_LeaIntro, Route16_Text_LeaDefeat, Route16_Text_LeaNotEnoughMons
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route16_EventScript_LeaRematch
    msgbox Route16_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_LeaRematch::
    trainerbattle_rematch_double TRAINER_YOUNG_COUPLE_LEA_JED, Route16_Text_LeaRematchIntro, Route16_Text_LeaDefeat, Route16_Text_LeaNotEnoughMons
    msgbox Route16_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
    end

Route16_EventScript_CyclingRoadSign::
    msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
    end

Route16_EventScript_RouteSign::
    msgbox Route16_Text_RouteSign, MSGBOX_SIGN
    end

Route16_Text_MonSprawledOutInSlumber::
    .string "A Pokémon is sprawled out in\n"
    .string "a deep and comfortable slumber.$"

Route16_Text_CyclingRoadSign::
    .string "Cycling Road\n"
    .string "Enjoy the slope!$"

Route16_Text_RouteSign::
    .string "Route 16\n"
    .string "Celadon City - Fuchsia City$"
