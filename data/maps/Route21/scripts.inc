Route21_MapScripts::
	.byte 0

Route21_EventScript_Ronald::
    trainerbattle_single TRAINER_FISHERMAN_RONALD, Route21_Text_RonaldIntro, Route21_Text_RonaldDefeat
    msgbox Route21_Text_RonaldPostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_Claude::
    trainerbattle_single TRAINER_FISHERMAN_CLAUDE, Route21_Text_ClaudeIntro, Route21_Text_ClaudeDefeat
    msgbox Route21_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_Wade::
    trainerbattle_single TRAINER_FISHERMAN_WADE, Route21_Text_WadeIntro, Route21_Text_WadeDefeat, Route21_EventScript_RegisterWade
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route21_EventScript_WadeRematch
    msgbox Route21_Text_WadePostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_RegisterWade::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route21_Text_WadeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_FISHERMAN_WADE
	release
	end

Route21_EventScript_WadeRematch::
    trainerbattle_rematch TRAINER_FISHERMAN_WADE, Route21_Text_WadeRematchIntro, Route21_Text_WadeDefeat
    msgbox Route21_Text_WadePostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_Nolan::
    trainerbattle_single TRAINER_FISHERMAN_NOLAN, Route21_Text_NolanIntro, Route21_Text_NolanDefeat
    msgbox Route21_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_Spencer::
    trainerbattle_single TRAINER_SWIMMER_MALE_SPENCER, Route21_Text_SpencerIntro, Route21_Text_SpencerDefeat
    msgbox Route21_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_Jack::
    trainerbattle_single TRAINER_SWIMMER_MALE_JACK, Route21_Text_JackIntro, Route21_Text_JackDefeat, Route21_EventScript_RegisterJack
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route21_EventScript_JackRematch
    msgbox Route21_Text_JackPostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_RegisterJack::
	special PlayerFaceTrainerAfterBattle
	msgbox Route21_Text_JackRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SWIMMER_MALE_JACK
	release
	end

Route21_EventScript_JackRematch::
    trainerbattle_rematch TRAINER_SWIMMER_MALE_JACK, Route21_Text_JackRematchIntro, Route21_Text_JackDefeat
    msgbox Route21_Text_JackPostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_Jerome::
    trainerbattle_single TRAINER_SWIMMER_MALE_JEROME, Route21_Text_JeromeIntro, Route21_Text_JeromeDefeat
    msgbox Route21_Text_JeromePostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_Roland::
    trainerbattle_single TRAINER_SWIMMER_MALE_ROLAND, Route21_Text_RolandIntro, Route21_Text_RolandDefeat
    msgbox Route21_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_Lil::
    trainerbattle_double TRAINER_SIS_AND_BRO_LIL_IAN, Route21_Text_LilIntro, Route21_Text_LilDefeat, Route21_Text_LilNotEnoughMons, Route21_EventScript_RegisterLil
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route21_EventScript_LilRematch
    msgbox Route21_Text_LilPostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_RegisterLil::
	msgbox Route21_Text_IanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SIS_AND_BRO_LIL_IAN
	release
	end

Route21_EventScript_LilRematch::
    trainerbattle_rematch_double TRAINER_SIS_AND_BRO_LIL_IAN, Route21_Text_LilRematchIntro, Route21_Text_LilDefeat, Route21_Text_LilNotEnoughMons
    msgbox Route21_Text_LilPostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_Ian::
    trainerbattle_double TRAINER_SIS_AND_BRO_LIL_IAN, Route21_Text_IanIntro, Route21_Text_IanDefeat, Route21_Text_IanNotEnoughMons, Route21_EventScript_RegisterIan
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route21_EventScript_IanRematch
    msgbox Route21_Text_IanPostBattle, MSGBOX_AUTOCLOSE
    end

Route21_EventScript_RegisterIan::
	msgbox Route21_Text_IanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SIS_AND_BRO_LIL_IAN
	release
	end

Route21_EventScript_IanRematch::
    trainerbattle_rematch_double TRAINER_SIS_AND_BRO_LIL_IAN, Route21_Text_IanRematchIntro, Route21_Text_IanDefeat, Route21_Text_IanNotEnoughMons
    msgbox Route21_Text_IanPostBattle, MSGBOX_AUTOCLOSE
    end
