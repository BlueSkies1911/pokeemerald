Route13_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route13_OnTransition
    .byte 0

Route13_OnTransition:
	randomweather
    end

Route13_EventScript_Jared::
    trainerbattle_single TRAINER_BIKER_JARED, Route13_Text_JaredIntro, Route13_Text_JaredDefeat
    msgbox Route13_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_Lola::
    trainerbattle_single TRAINER_BEAUTY_LOLA, Route13_Text_LolaIntro, Route13_Text_LolaDefeat
    msgbox Route13_Text_LolaPostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_Sheila::
    trainerbattle_single TRAINER_BEAUTY_SHEILA, Route13_Text_SheilaIntro, Route13_Text_SheilaDefeat, Route13_EventScript_RegisterSheila
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route13_EventScript_SheilaRematch
    msgbox Route13_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_RegisterSheila::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route13_Text_SheilaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BEAUTY_SHEILA
	release
	end

Route13_EventScript_SheilaRematch::
    trainerbattle_rematch TRAINER_BEAUTY_SHEILA, Route13_Text_SheilaRematchIntro, Route13_Text_SheilaDefeat
    msgbox Route13_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_Sebastian::
    trainerbattle_single TRAINER_BIRD_KEEPER_SEBASTIAN, Route13_Text_SebastianIntro, Route13_Text_SebastianDefeat
    msgbox Route13_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_Perry::
    trainerbattle_single TRAINER_BIRD_KEEPER_PERRY, Route13_Text_PerryIntro, Route13_Text_PerryDefeat
    msgbox Route13_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_Robert::
    trainerbattle_single TRAINER_BIRD_KEEPER_ROBERT, Route13_Text_RobertIntro, Route13_Text_RobertDefeat, Route13_EventScript_RegisterRobert
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route13_EventScript_RobertRematch
    msgbox Route13_Text_RobertPostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_RegisterRobert::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route13_Text_RobertRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIRD_KEEPER_ROBERT
	release
	end

Route13_EventScript_RobertRematch::
    trainerbattle_rematch TRAINER_BIRD_KEEPER_ROBERT, Route13_Text_RobertRematchIntro, Route13_Text_RobertDefeat
    msgbox Route13_Text_RobertPostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_Alma::
    trainerbattle_single TRAINER_PICNICKER_ALMA, Route13_Text_AlmaIntro, Route13_Text_AlmaDefeat
    msgbox Route13_Text_AlmaPostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_Susie::
    trainerbattle_single TRAINER_PICNICKER_SUSIE, Route13_Text_SusieIntro, Route13_Text_SusieDefeat, Route13_EventScript_RegisterSusie
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route13_EventScript_SusieRematch
    msgbox Route13_Text_SusiePostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_RegisterSusie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route13_Text_SusieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PICNICKER_SUSIE
	release
	end

Route13_EventScript_SusieRematch::
    trainerbattle_rematch TRAINER_PICNICKER_SUSIE, Route13_Text_SusieRematchIntro, Route13_Text_SusieDefeat
    msgbox Route13_Text_SusiePostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_Valerie::
    trainerbattle_single TRAINER_PICNICKER_VALERIE, Route13_Text_ValerieIntro, Route13_Text_ValerieDefeat
    msgbox Route13_Text_ValeriePostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_Gwen::
    trainerbattle_single TRAINER_PICNICKER_GWEN, Route13_Text_GwenIntro, Route13_Text_GwenDefeat
    msgbox Route13_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
    end

Route13_EventScript_TrainerTips1::
    msgbox Route13_Text_LookToLeftOfThatPost, MSGBOX_SIGN
    end

Route13_EventScript_TrainerTips2::
    msgbox Route13_Text_SelectToSwitchItems, MSGBOX_SIGN
    end

Route13_EventScript_RouteSign::
    msgbox Route13_Text_RouteSign, MSGBOX_SIGN
    end

Route13_Text_LookToLeftOfThatPost::
    .string "Trainer Tips\p"
    .string "Look, look!\n"
    .string "Look to the left of that post!$"

Route13_Text_SelectToSwitchItems::
    .string "Trainer Tips\p"
    .string "Use Select to switch items in the\n"
    .string "Items window.$"

Route13_Text_RouteSign::
    .string "Route 13\n"
    .string "North to Silence Bridge$"
