Route14_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route14_OnTransition
    .byte 0

Route14_OnTransition:
	randomweather
    end

Route14_EventScript_Malik::
    trainerbattle_single TRAINER_BIKER_MALIK, Route14_Text_MalikIntro, Route14_Text_MalikDefeat
    msgbox Route14_Text_MalikPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Lukas::
    trainerbattle_single TRAINER_BIKER_LUKAS, Route14_Text_LukasIntro, Route14_Text_LukasDefeat, Route14_EventScript_RegisterLukas
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route14_EventScript_LukasRematch
    msgbox Route14_Text_LukasPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_RegisterLukas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route14_Text_LukasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIKER_LUKAS
	release
	end

Route14_EventScript_LukasRematch::
    trainerbattle_rematch TRAINER_BIKER_LUKAS, Route14_Text_LukasRematchIntro, Route14_Text_LukasDefeat
    msgbox Route14_Text_LukasPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Isaac::
    trainerbattle_single TRAINER_BIKER_ISAAC, Route14_Text_IsaacIntro, Route14_Text_IsaacDefeat
    msgbox Route14_Text_IsaacPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Gerald::
    trainerbattle_single TRAINER_BIKER_GERALD, Route14_Text_GeraldIntro, Route14_Text_GeraldDefeat
    msgbox Route14_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Donald::
    trainerbattle_single TRAINER_BIRD_KEEPER_DONALD, Route14_Text_DonaldIntro, Route14_Text_DonaldDefeat
    msgbox Route14_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Benny::
    trainerbattle_single TRAINER_BIRD_KEEPER_BENNY, Route14_Text_BennyIntro, Route14_Text_BennyDefeat, Route14_EventScript_RegisterBenny
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route14_EventScript_BennyRematch
    msgbox Route14_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_RegisterBenny::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route14_Text_BennyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIRD_KEEPER_BENNY
	release
	end

Route14_EventScript_BennyRematch::
    trainerbattle_rematch TRAINER_BIRD_KEEPER_BENNY, Route14_Text_BennyRematchIntro, Route14_Text_BennyDefeat
    msgbox Route14_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Carter::
    trainerbattle_single TRAINER_BIRD_KEEPER_CARTER, Route14_Text_CarterIntro, Route14_Text_CarterDefeat
    msgbox Route14_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Mitch::
    trainerbattle_single TRAINER_BIRD_KEEPER_MITCH, Route14_Text_MitchIntro, Route14_Text_MitchDefeat
    msgbox Route14_Text_MitchPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Beck::
    trainerbattle_single TRAINER_BIRD_KEEPER_BECK, Route14_Text_BeckIntro, Route14_Text_BeckDefeat
    msgbox Route14_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Marlon::
    trainerbattle_single TRAINER_BIRD_KEEPER_MARLON, Route14_Text_MarlonIntro, Route14_Text_MarlonDefeat, Route14_EventScript_RegisterMarlon
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route14_EventScript_MarlonRematch
    msgbox Route14_Text_MarlonPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_RegisterMarlon::
	msgbox Route14_Text_MarlonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIRD_KEEPER_MARLON
	release
	end

Route14_EventScript_MarlonRematch::
    trainerbattle_rematch TRAINER_BIRD_KEEPER_MARLON, Route14_Text_MarlonRematchIntro, Route14_Text_MarlonDefeat
    msgbox Route14_Text_MarlonPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Kiri::
    trainerbattle_double TRAINER_TWINS_KIRI_JAN, Route14_Text_KiriIntro, Route14_Text_KiriDefeat, Route14_Text_KiriNotEnoughMons
    msgbox Route14_Text_KiriPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_Jan::
    trainerbattle_double TRAINER_TWINS_KIRI_JAN, Route14_Text_JanIntro, Route14_Text_JanDefeat, Route14_Text_JanNotEnoughMons
    msgbox Route14_Text_JanPostBattle, MSGBOX_AUTOCLOSE
    end

Route14_EventScript_RouteSign::
    msgbox Route14_Text_RouteSign, MSGBOX_SIGN
    end

Route14_Text_RouteSign::
    .string "Route 14\n"
    .string "West to Fuchsia City$"
