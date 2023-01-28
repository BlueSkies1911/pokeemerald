Route18_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition:
    compare VAR_MAP_SCENE_ROUTE16, 1
    call_if_eq Route18_OnTransitionCyclingRoad
    end

Route18_OnTransitionCyclingRoad::
    setflag FLAG_SYS_CYCLING_ROAD
    return

Route18_OnWarp:
    map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route18_OnWarpCyclingRoad
    .2byte 0

Route18_OnWarpCyclingRoad::
    special ForcePlayerOntoBike
    end

Route18_EventScript_Wilton::
    trainerbattle_single TRAINER_BIRD_KEEPER_WILTON, Route18_Text_WiltonIntro, Route18_Text_WiltonDefeat
    msgbox Route18_Text_WiltonPostBattle, MSGBOX_AUTOCLOSE
    end

Route18_EventScript_Ramiro::
    trainerbattle_single TRAINER_BIRD_KEEPER_RAMIRO, Route18_Text_RamiroIntro, Route18_Text_RamiroDefeat
    msgbox Route18_Text_RamiroPostBattle, MSGBOX_AUTOCLOSE
    end

Route18_EventScript_Jacob::
    trainerbattle_single TRAINER_BIRD_KEEPER_JACOB, Route18_Text_JacobIntro, Route18_Text_JacobDefeat, Route18_EventScript_RegisterJacob
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route18_EventScript_JacobRematch
    msgbox Route18_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
    end

Route18_EventScript_RegisterJacob::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route18_Text_JacobRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIRD_KEEPER_JACOB
	release
	end

Route18_EventScript_JacobRematch::
    trainerbattle_rematch TRAINER_BIRD_KEEPER_JACOB, Route18_Text_JacobRematchIntro, Route18_Text_JacobDefeat
    msgbox Route18_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
    end

Route18_EventScript_RouteSign::
    msgbox Route18_Text_RouteSign, MSGBOX_SIGN
    end

Route18_EventScript_CyclingRoadSign::
    msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
    end

Route18_Text_RouteSign::
    .string "ROUTE 18\n"
    .string "Celadon City - Fuchsia City$"

Route18_Text_CyclingRoadSign::
    .string "CYCLING ROAD\n"
    .string "No pedestrians permitted!$"
