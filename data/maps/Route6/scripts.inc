Route6_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
    .byte 0

Route6_OnTransition:
	randomweather
    end

Route6_EventScript_Keigo::
    trainerbattle_single TRAINER_BUG_CATCHER_KEIGO, Route6_Text_KeigoIntro, Route6_Text_KeigoDefeat
    msgbox Route6_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
    end

Route6_EventScript_Elijah::
    trainerbattle_single TRAINER_BUG_CATCHER_ELIJAH, Route6_Text_ElijahIntro, Route6_Text_ElijahDefeat
    msgbox Route6_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
    end

Route6_EventScript_Ricky::
    trainerbattle_single TRAINER_CAMPER_RICKY, Route6_Text_RickyIntro, Route6_Text_RickyDefeat, Route6_EventScript_RegisterRicky
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route6_EventScript_RickyRematch
    msgbox Route6_Text_RickyPostBattle, MSGBOX_AUTOCLOSE
    end

Route6_EventScript_RegisterRicky::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route6_Text_RickyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CAMPER_RICKY
	release
	end

Route6_EventScript_RickyRematch::
    trainerbattle_rematch TRAINER_CAMPER_RICKY, Route6_Text_RickyRematchIntro, Route6_Text_RickyDefeat
    msgbox Route6_Text_RickyPostBattle, MSGBOX_AUTOCLOSE
    end

Route6_EventScript_Jeff::
    trainerbattle_single TRAINER_CAMPER_JEFF, Route6_Text_JeffIntro, Route6_Text_JeffDefeat, Route6_EventScript_RegisterJeff
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route6_EventScript_JeffRematch
    msgbox Route6_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
    end

Route6_EventScript_RegisterJeff::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route6_Text_JeffRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CAMPER_JEFF
	release
	end

Route6_EventScript_JeffRematch::
    trainerbattle_rematch TRAINER_CAMPER_JEFF, Route6_Text_JeffRematchIntro, Route6_Text_JeffDefeat
    msgbox Route6_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
    end

Route6_EventScript_Nancy::
    trainerbattle_single TRAINER_PICNICKER_NANCY, Route6_Text_NancyIntro, Route6_Text_NancyDefeat
    msgbox Route6_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
    end

Route6_EventScript_Isabelle::
    trainerbattle_single TRAINER_PICNICKER_ISABELLE, Route6_Text_IsabelleIntro, Route6_Text_IsabelleDefeat, Route6_EventScript_RegisterIsabelle
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route6_EventScript_IsabelleRematch
    msgbox Route6_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
    end

Route6_EventScript_RegisterIsabelle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route6_Text_IsabelleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PICNICKER_ISABELLE
	release
	end

Route6_EventScript_IsabelleRematch::
    trainerbattle_rematch TRAINER_PICNICKER_ISABELLE, Route6_Text_IsabelleRematchIntro, Route6_Text_IsabelleDefeat
    msgbox Route6_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
    end

Route6_EventScript_UndergroundPathSign::
    msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
    end

Route6_Text_UndergroundPathSign::
    .string "Underground Path\n"
    .string "Cerulean City - Vermilion City$"
