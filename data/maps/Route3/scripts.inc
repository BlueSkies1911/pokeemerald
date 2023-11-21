Route3_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
    .byte 0

Route3_OnTransition:
	randomweather
    end

Route3_EventScript_Youngster::
    msgbox Route3_Text_TunnelFromCeruleanTiring, MSGBOX_NPC
    end

Route3_EventScript_Robin::
    trainerbattle_single TRAINER_LASS_ROBIN, Route3_Text_RobinIntro, Route3_Text_RobinDefeat
    msgbox Route3_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_Greg::
    trainerbattle_single TRAINER_BUG_CATCHER_GREG, Route3_Text_GregIntro, Route3_Text_GregDefeat
    msgbox Route3_Text_GregPostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_Sally::
    trainerbattle_single TRAINER_LASS_SALLY, Route3_Text_SallyIntro, Route3_Text_SallyDefeat
    msgbox Route3_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_James::
    trainerbattle_single TRAINER_BUG_CATCHER_JAMES, Route3_Text_JamesIntro, Route3_Text_JamesDefeat
    msgbox Route3_Text_JamesPostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_Calvin::
    trainerbattle_single TRAINER_YOUNGSTER_CALVIN, Route3_Text_CalvinIntro, Route3_Text_CalvinDefeat
    msgbox Route3_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_Janice::
    trainerbattle_single TRAINER_LASS_JANICE, Route3_Text_JaniceIntro, Route3_Text_JaniceDefeat, Route3_EventScript_RegisterJanice
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route3_EventScript_JaniceRematch
    msgbox Route3_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_RegisterJanice::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_JaniceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LASS_JANICE
	release
	end

Route3_EventScript_JaniceRematch::
    trainerbattle_rematch TRAINER_LASS_JANICE, Route3_Text_JaniceRematchIntro, Route3_Text_JaniceDefeat
    msgbox Route3_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_Colton::
    trainerbattle_single TRAINER_BUG_CATCHER_COLTON, Route3_Text_ColtonIntro, Route3_Text_ColtonDefeat, Route3_EventScript_RegisterColton
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route3_EventScript_ColtonRematch
    msgbox Route3_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_RegisterColton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_ColtonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BUG_CATCHER_COLTON
	release
	end

Route3_EventScript_ColtonRematch::
    trainerbattle_rematch TRAINER_BUG_CATCHER_COLTON, Route3_Text_ColtonRematchIntro, Route3_Text_ColtonDefeat
    msgbox Route3_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_Ben::
    trainerbattle_single TRAINER_YOUNGSTER_BEN, Route3_Text_BenIntro, Route3_Text_BenDefeat, Route3_EventScript_RegisterBen
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route3_EventScript_BenRematch
    msgbox Route3_Text_BenPostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_RegisterBen::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_BenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_YOUNGSTER_BEN
	release
	end

Route3_EventScript_BenRematch::
    trainerbattle_rematch TRAINER_YOUNGSTER_BEN, Route3_Text_BenRematchIntro, Route3_Text_BenDefeat
    msgbox Route3_Text_BenPostBattle, MSGBOX_AUTOCLOSE
    end

Route3_EventScript_RouteSign::
    msgbox Route3_Text_RouteSign, MSGBOX_SIGN
    end

Route3_Text_TunnelFromCeruleanTiring::
    .string "Whew… I better take a rest…\n"
    .string "Groan…\p"
    .string "That tunnel from Cerulean takes a\n"
    .string "lot out of you!$"

Route3_Text_RouteSign::
    .string "Route 3\n"
    .string "Mt. Moon Ahead$"
