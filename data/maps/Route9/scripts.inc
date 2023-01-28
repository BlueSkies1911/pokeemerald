Route9_MapScripts::
	.byte 0

Route9_EventScript_Brent::
    trainerbattle_single TRAINER_BUG_CATCHER_BRENT, Route9_Text_BrentIntro, Route9_Text_BrentDefeat
    msgbox Route9_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_Conner::
    trainerbattle_single TRAINER_BUG_CATCHER_CONNER, Route9_Text_ConnerIntro, Route9_Text_ConnerDefeat
    msgbox Route9_Text_ConnerPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_Chris::
    trainerbattle_single TRAINER_CAMPER_CHRIS, Route9_Text_ChrisIntro, Route9_Text_ChrisDefeat, Route9_EventScript_RegisterChris
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route9_EventScript_ChrisRematch
    msgbox Route9_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_RegisterChris::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route9_Text_ChrisRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CAMPER_CHRIS
	release
	end

Route9_EventScript_ChrisRematch::
    trainerbattle_rematch TRAINER_CAMPER_CHRIS, Route9_Text_ChrisRematchIntro, Route9_Text_ChrisDefeat
    msgbox Route9_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_Drew::
    trainerbattle_single TRAINER_CAMPER_DREW, Route9_Text_DrewIntro, Route9_Text_DrewDefeat
    msgbox Route9_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_Alicia::
    trainerbattle_single TRAINER_PICNICKER_ALICIA, Route9_Text_AliciaIntro, Route9_Text_AliciaDefeat
    msgbox Route9_Text_AliciaPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_Caitlin::
    trainerbattle_single TRAINER_PICNICKER_CAITLIN, Route9_Text_CaitlinIntro, Route9_Text_CaitlinDefeat, Route9_EventScript_RegisterCaitlin
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route9_EventScript_CaitlinRematch
    msgbox Route9_Text_CaitlinPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_RegisterCaitlin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route9_Text_CaitlinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PICNICKER_CAITLIN
	release
	end

Route9_EventScript_CaitlinRematch::
    trainerbattle_rematch TRAINER_PICNICKER_CAITLIN, Route9_Text_CaitlinRematchIntro, Route9_Text_CaitlinDefeat
    msgbox Route9_Text_CaitlinPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_Alan::
    trainerbattle_single TRAINER_HIKER_ALAN, Route9_Text_AlanIntro, Route9_Text_AlanDefeat
    msgbox Route9_Text_AlanPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_Brice::
    trainerbattle_single TRAINER_HIKER_BRICE, Route9_Text_BriceIntro, Route9_Text_BriceDefeat
    msgbox Route9_Text_BricePostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_Jeremy::
    trainerbattle_single TRAINER_HIKER_JEREMY, Route9_Text_JeremyIntro, Route9_Text_JeremyDefeat, Route9_EventScript_RegisterJeremy
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route9_EventScript_JeremyRematch
    msgbox Route9_Text_JeremyPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_RegisterJeremy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route9_Text_JeremyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HIKER_JEREMY
	release
	end

Route9_EventScript_JeremyRematch::
    trainerbattle_rematch TRAINER_HIKER_JEREMY, Route9_Text_JeremyRematchIntro, Route9_Text_JeremyDefeat
    msgbox Route9_Text_JeremyPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_EventScript_RouteSign::
    msgbox Route9_Text_RouteSign, MSGBOX_SIGN
    end

Route9_Text_RouteSign::
    .string "ROUTE 9\n"
    .string "Cerulean City - Rock Tunnel$"
