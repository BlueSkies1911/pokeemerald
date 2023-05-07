Route8_MapScripts::
	.byte 0

Route8_EventScript_Paige::
    trainerbattle_single TRAINER_LASS_PAIGE, Route8_Text_PaigeIntro, Route8_Text_PaigeDefeat
    msgbox Route8_Text_PaigePostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Andrea::
    trainerbattle_single TRAINER_LASS_ANDREA, Route8_Text_AndreaIntro, Route8_Text_AndreaDefeat
    msgbox Route8_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Megan::
    trainerbattle_single TRAINER_LASS_MEGAN, Route8_Text_MeganIntro, Route8_Text_MeganDefeat, Route8_EventScript_RegisterMegan
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route8_EventScript_MeganRematch
    msgbox Route8_Text_MeganPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_RegisterMegan::
	special PlayerFaceTrainerAfterBattle
	msgbox Route8_Text_MeganRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LASS_MEGAN
	release
	end

Route8_EventScript_MeganRematch::
    trainerbattle_rematch TRAINER_LASS_MEGAN, Route8_Text_MeganRematchIntro, Route8_Text_MeganDefeat
    msgbox Route8_Text_MeganPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Julia::
    trainerbattle_single TRAINER_LASS_JULIA, Route8_Text_JuliaIntro, Route8_Text_JuliaDefeat
    msgbox Route8_Text_JuliaPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Aidan::
    trainerbattle_single TRAINER_SUPER_NERD_AIDAN, Route8_Text_AidanIntro, Route8_Text_AidanDefeat
    msgbox Route8_Text_AidanPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Glenn::
    trainerbattle_single TRAINER_SUPER_NERD_GLENN, Route8_Text_GlennIntro, Route8_Text_GlennDefeat
    msgbox Route8_Text_GlennPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Leslie::
    trainerbattle_single TRAINER_SUPER_NERD_LESLIE, Route8_Text_LeslieIntro, Route8_Text_LeslieDefeat
    msgbox Route8_Text_LesliePostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Stan::
    trainerbattle_single TRAINER_GAMBLER_STAN, Route8_Text_StanIntro, Route8_Text_StanDefeat
    msgbox Route8_Text_StanPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Rich::
    trainerbattle_single TRAINER_GAMBLER_RICH, Route8_Text_RichIntro, Route8_Text_RichDefeat, Route8_EventScript_RegisterRich
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route8_EventScript_RichRematch
    msgbox Route8_Text_RichPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_RegisterRich::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route8_Text_RichRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GAMBLER_RICH
	release
	end

Route8_EventScript_RichRematch::
    trainerbattle_rematch TRAINER_GAMBLER_RICH, Route8_Text_RichRematchIntro, Route8_Text_RichDefeat
    msgbox Route8_Text_RichPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Eli::
    trainerbattle_double TRAINER_TWINS_ELI_ANNE, Route8_Text_EliIntro, Route8_Text_EliDefeat, Route8_Text_EliNotEnoughMons, Route8_EventScript_RegisterEli
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route8_EventScript_EliRematch
    msgbox Route8_Text_EliPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_RegisterEli::
	msgbox Route8_Text_EliAndAnneRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TWINS_ELI_ANNE
	release
	end

Route8_EventScript_EliRematch::
    trainerbattle_rematch_double TRAINER_TWINS_ELI_ANNE, Route8_Text_EliRematchIntro, Route8_Text_EliDefeat, Route8_Text_EliNotEnoughMons
    msgbox Route8_Text_EliPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Anne::
    trainerbattle_double TRAINER_TWINS_ELI_ANNE, Route8_Text_AnneIntro, Route8_Text_AnneDefeat, Route8_Text_AnneNotEnoughMons, Route8_EventScript_RegisterAnne
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route8_EventScript_AnneRematch
    msgbox Route8_Text_AnnePostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_RegisterAnne::
	msgbox Route8_Text_EliAndAnneRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TWINS_ELI_ANNE
	release
	end

Route8_EventScript_AnneRematch::
    trainerbattle_rematch_double TRAINER_TWINS_ELI_ANNE, Route8_Text_AnneRematchIntro, Route8_Text_AnneDefeat, Route8_Text_AnneNotEnoughMons
    msgbox Route8_Text_AnnePostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Ricardo::
    trainerbattle_single TRAINER_BIKER_RICARDO, Route8_Text_RicardoIntro, Route8_Text_RicardoDefeat
    msgbox Route8_Text_RicardoPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_Jaren::
    trainerbattle_single TRAINER_BIKER_JAREN, Route8_Text_JarenIntro, Route8_Text_JarenDefeat, Route8_EventScript_RegisterJaren
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route8_EventScript_JarenRematch
    msgbox Route8_Text_JarenPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_RegisterJaren::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route8_Text_JarenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIKER_JAREN
	release
	end

Route8_EventScript_JarenRematch::
    trainerbattle_rematch TRAINER_BIKER_JAREN, Route8_Text_JarenRematchIntro, Route8_Text_JarenDefeat
    msgbox Route8_Text_JarenPostBattle, MSGBOX_AUTOCLOSE
    end

Route8_EventScript_UndergroundPathSign::
    msgbox Route8_Text_UndergroundPathSign, MSGBOX_SIGN
    end

Route8_Text_UndergroundPathSign::
    .string "Underground Path\n"
    .string "Celadon City - Lavender Town$"
