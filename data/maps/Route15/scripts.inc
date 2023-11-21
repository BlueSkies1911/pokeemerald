Route15_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
    .byte 0

Route15_OnTransition:
	randomweather
    end

Route15_EventScript_Ernest::
    trainerbattle_single TRAINER_BIKER_ERNEST, Route15_Text_ErnestIntro, Route15_Text_ErnestDefeat
    msgbox Route15_Text_ErnestPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Alex::
    trainerbattle_single TRAINER_BIKER_ALEX, Route15_Text_AlexIntro, Route15_Text_AlexDefeat
    msgbox Route15_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Grace::
    trainerbattle_single TRAINER_BEAUTY_GRACE, Route15_Text_GraceIntro, Route15_Text_GraceDefeat, Route15_EventScript_RegisterGrace
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route15_EventScript_GraceRematch
    msgbox Route15_Text_GracePostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_RegisterGrace::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_GraceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BEAUTY_GRACE
	release
	end

Route15_EventScript_GraceRematch::
    trainerbattle_rematch TRAINER_BEAUTY_GRACE, Route15_Text_GraceRematchIntro, Route15_Text_GraceDefeat
    msgbox Route15_Text_GracePostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Olivia::
    trainerbattle_single TRAINER_BEAUTY_OLIVIA, Route15_Text_OliviaIntro, Route15_Text_OliviaDefeat
    msgbox Route15_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Edwin::
    trainerbattle_single TRAINER_BIRD_KEEPER_EDWIN, Route15_Text_EdwinIntro, Route15_Text_EdwinDefeat
    msgbox Route15_Text_EdwinPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Chester::
    trainerbattle_single TRAINER_BIRD_KEEPER_CHESTER, Route15_Text_ChesterIntro, Route15_Text_ChesterDefeat, Route15_EventScript_RegisterChester
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route15_EventScript_ChesterRematch
    msgbox Route15_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_RegisterChester::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_ChesterRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIRD_KEEPER_CHESTER
	release
	end

Route15_EventScript_ChesterRematch::
    trainerbattle_rematch TRAINER_BIRD_KEEPER_CHESTER, Route15_Text_ChesterRematchIntro, Route15_Text_ChesterDefeat
    msgbox Route15_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Yazmin::
    trainerbattle_single TRAINER_PICNICKER_YAZMIN, Route15_Text_YazminIntro, Route15_Text_YazminDefeat
    msgbox Route15_Text_YazminPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Kindra::
    trainerbattle_single TRAINER_PICNICKER_KINDRA, Route15_Text_KindraIntro, Route15_Text_KindraDefeat
    msgbox Route15_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Becky::
    trainerbattle_single TRAINER_PICNICKER_BECKY, Route15_Text_BeckyIntro, Route15_Text_BeckyDefeat, Route15_EventScript_RegisterBecky
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route15_EventScript_BeckyRematch
    msgbox Route15_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_RegisterBecky::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_BeckyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PICNICKER_BECKY
	release
	end

Route15_EventScript_BeckyRematch::
    trainerbattle_rematch TRAINER_PICNICKER_BECKY, Route15_Text_BeckyRematchIntro, Route15_Text_BeckyDefeat
    msgbox Route15_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Celia::
    trainerbattle_single TRAINER_PICNICKER_CELIA, Route15_Text_CeliaIntro, Route15_Text_CeliaDefeat
    msgbox Route15_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Mya::
    trainerbattle_double TRAINER_CRUSH_KIN_RON_MYA, Route15_Text_MyaIntro, Route15_Text_MyaDefeat, Route15_Text_MyaNotEnoughMons, Route15_EventScript_RegisterMya
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route15_EventScript_MyaRematch
    msgbox Route15_Text_MyaPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_RegisterMya::
	msgbox Route15_Text_MyaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CRUSH_KIN_RON_MYA
	release
	end

Route15_EventScript_MyaRematch::
    trainerbattle_rematch_double TRAINER_CRUSH_KIN_RON_MYA, Route15_Text_MyaRematchIntro, Route15_Text_MyaDefeat, Route15_Text_MyaNotEnoughMons
    msgbox Route15_Text_MyaPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_Ron::
    trainerbattle_double TRAINER_CRUSH_KIN_RON_MYA, Route15_Text_RonIntro, Route15_Text_RonDefeat, Route15_Text_RonNotEnoughMons, Route15_EventScript_RegisterMya
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route15_EventScript_RonRematch
    msgbox Route15_Text_RonPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_RonRematch::
    trainerbattle_rematch_double TRAINER_CRUSH_KIN_RON_MYA, Route15_Text_RonRematchIntro, Route15_Text_RonDefeat, Route15_Text_RonNotEnoughMons
    msgbox Route15_Text_RonPostBattle, MSGBOX_AUTOCLOSE
    end

Route15_EventScript_RouteSign::
    msgbox Route15_Text_RouteSign, MSGBOX_SIGN
    end

Route15_Text_RouteSign::
    .string "Route 15\n"
    .string "West to Fuchsia City$"
