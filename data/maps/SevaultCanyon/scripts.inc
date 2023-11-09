SevaultCanyon_MapScripts::
	.byte 0

SevaultCanyon_EventScript_Cyndy::
    trainerbattle_single TRAINER_CRUSH_GIRL_CYNDY, SevaultCanyon_Text_CyndyIntro, SevaultCanyon_Text_CyndyDefeat
    msgbox SevaultCanyon_Text_CyndyPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_Evan::
    trainerbattle_single TRAINER_TAMER_EVAN, SevaultCanyon_Text_EvanIntro, SevaultCanyon_Text_EvanDefeat
    msgbox SevaultCanyon_Text_EvanPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_Jackson::
    trainerbattle_single TRAINER_PKMN_RANGER_JACKSON, SevaultCanyon_Text_JacksonIntro, SevaultCanyon_Text_JacksonDefeat
    msgbox SevaultCanyon_Text_JacksonPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_Katelyn::
    trainerbattle_single TRAINER_PKMN_RANGER_KATELYN, SevaultCanyon_Text_KatelynIntro, SevaultCanyon_Text_KatelynDefeat, SevaultCanyon_EventScript_RegisterKatelyn
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq SevaultCanyon_EventScript_KatelynRematch
    msgbox SevaultCanyon_Text_KatelynPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_RegisterKatelyn::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox SevaultCanyon_Text_KatelynRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PKMN_RANGER_KATELYN
	release
	end

SevaultCanyon_EventScript_KatelynRematch::
    trainerbattle_rematch TRAINER_PKMN_RANGER_KATELYN, SevaultCanyon_Text_KatelynRematchIntro, SevaultCanyon_Text_KatelynDefeat
    msgbox SevaultCanyon_Text_KatelynPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_Leroy::
    trainerbattle_single TRAINER_COOLTRAINER_LEROY, SevaultCanyon_Text_LeroyIntro, SevaultCanyon_Text_LeroyDefeat, SevaultCanyon_EventScript_RegisterLeroy
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq SevaultCanyon_EventScript_LeroyRematch
    msgbox SevaultCanyon_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_RegisterLeroy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox SevaultCanyon_Text_LeroyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_COOLTRAINER_LEROY
	release
	end

SevaultCanyon_EventScript_LeroyRematch::
    trainerbattle_rematch TRAINER_COOLTRAINER_LEROY, SevaultCanyon_Text_LeroyRematchIntro, SevaultCanyon_Text_LeroyDefeat
    msgbox SevaultCanyon_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_Michelle::
    trainerbattle_single TRAINER_COOLTRAINER_MICHELLE, SevaultCanyon_Text_MichelleIntro, SevaultCanyon_Text_MichelleDefeat, SevaultCanyon_EventScript_RegisterMichelle
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq SevaultCanyon_EventScript_MichelleRematch
    msgbox SevaultCanyon_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_RegisterMichelle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox SevaultCanyon_Text_MichelleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_COOLTRAINER_MICHELLE
	release
	end

SevaultCanyon_EventScript_MichelleRematch::
    trainerbattle_rematch TRAINER_COOLTRAINER_MICHELLE, SevaultCanyon_Text_MichelleRematchIntro, SevaultCanyon_Text_MichelleDefeat
    msgbox SevaultCanyon_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_Lex::
    trainerbattle_double TRAINER_COOL_COUPLE_LEX_NYA, SevaultCanyon_Text_LexIntro, SevaultCanyon_Text_LexDefeat, SevaultCanyon_Text_LexNotEnoughMons
    msgbox SevaultCanyon_Text_LexPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_Nya::
    trainerbattle_double TRAINER_COOL_COUPLE_LEX_NYA, SevaultCanyon_Text_NyaIntro, SevaultCanyon_Text_NyaDefeat, SevaultCanyon_Text_NyaNotEnoughMons
    msgbox SevaultCanyon_Text_NyaPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_EventScript_BlackBelt::
    msgbox SevaultCanyon_Text_BrunoTrainedWithBrawly, MSGBOX_NPC
    end

SevaultCanyon_EventScript_RouteSign::
    msgbox SevaultCanyon_Text_RouteSign, MSGBOX_SIGN
    end

SevaultCanyon_Text_BrunoTrainedWithBrawly::
    .string "Training by oneself is certainly\n"
    .string "not a bad thing.\p"
    .string "But it's also not bad to aim for\n"
    .string "the top with a partner.\p"
    .string "Even Bruno…\n"
    .string "He trained with a fellow by the\l"
    .string "name of Brawly before.$"

SevaultCanyon_Text_RouteSign::
    .string "Sevault Canyon\n"
    .string "Tanoby Ruins Ahead$"

