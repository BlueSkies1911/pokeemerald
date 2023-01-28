Route11_MapScripts::
	.byte 0

Route11_EventScript_Eddie::
    trainerbattle_single TRAINER_YOUNGSTER_EDDIE, Route11_Text_EddieIntro, Route11_Text_EddieDefeat
    msgbox Route11_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_Dillon::
    trainerbattle_single TRAINER_YOUNGSTER_DILLON, Route11_Text_DillonIntro, Route11_Text_DillonDefeat
    msgbox Route11_Text_DillonPostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_Yasu::
    trainerbattle_single TRAINER_YOUNGSTER_YASU, Route11_Text_YasuIntro, Route11_Text_YasuDefeat, Route11_EventScript_RegisterYasu
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route11_EventScript_YasuRematch
    msgbox Route11_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_RegisterYasu::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route11_Text_YasuRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_YOUNGSTER_YASU
	release
	end

Route11_EventScript_YasuRematch::
    trainerbattle_rematch TRAINER_YOUNGSTER_YASU, Route11_Text_YasuRematchIntro, Route11_Text_YasuDefeat
    msgbox Route11_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_Dave::
    trainerbattle_single TRAINER_YOUNGSTER_DAVE, Route11_Text_DaveIntro, Route11_Text_DaveDefeat
    msgbox Route11_Text_DavePostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_Braxton::
    trainerbattle_single TRAINER_ENGINEER_BRAXTON, Route11_Text_BraxtonIntro, Route11_Text_BraxtonDefeat
    msgbox Route11_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_Bernie::
    trainerbattle_single TRAINER_ENGINEER_BERNIE, Route11_Text_BernieIntro, Route11_Text_BernieDefeat, Route11_EventScript_RegisterBernie
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route11_EventScript_BernieRematch
    msgbox Route11_Text_BerniePostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_RegisterBernie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route11_Text_BernieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ENGINEER_BERNIE
	release
	end

Route11_EventScript_BernieRematch::
    trainerbattle_rematch TRAINER_ENGINEER_BERNIE, Route11_Text_BernieRematchIntro, Route11_Text_BernieDefeat
    msgbox Route11_Text_BerniePostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_Hugo::
    trainerbattle_single TRAINER_GAMBLER_HUGO, Route11_Text_HugoIntro, Route11_Text_HugoDefeat
    msgbox Route11_Text_HugoPostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_Jasper::
    trainerbattle_single TRAINER_GAMBLER_JASPER, Route11_Text_JasperIntro, Route11_Text_JasperDefeat
    msgbox Route11_Text_JasperPostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_Dirk::
    trainerbattle_single TRAINER_GAMBLER_DIRK, Route11_Text_DirkIntro, Route11_Text_DirkDefeat
    msgbox Route11_Text_DirkPostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_Darian::
    trainerbattle_single TRAINER_GAMBLER_DARIAN, Route11_Text_DarianIntro, Route11_Text_DarianDefeat, Route11_EventScript_RegisterDarian
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route11_EventScript_DarianRematch
    msgbox Route11_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_RegisterDarian::
	msgbox Route11_Text_DarianRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GAMBLER_DARIAN
	release
	end

Route11_EventScript_DarianRematch::
    trainerbattle_rematch TRAINER_GAMBLER_DARIAN, Route11_Text_DarianRematchIntro, Route11_Text_DarianDefeat
    msgbox Route11_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
    end

Route11_EventScript_DiglettsCaveSign::
    msgbox Route11_Text_DiglettsCave, MSGBOX_SIGN
    end

Route11_Text_DiglettsCave::
    .string "Diglett's Cave$"
