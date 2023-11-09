SevaultCanyon_Entrance_MapScripts::
	.byte 0

SevaultCanyon_Entrance_EventScript_Miah::
    trainerbattle_single TRAINER_AROMA_LADY_MIAH, SevaultCanyon_Entrance_Text_MiahIntro, SevaultCanyon_Entrance_Text_MiahDefeat
    msgbox SevaultCanyon_Entrance_Text_MiahPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_Entrance_EventScript_Eve::
    trainerbattle_double TRAINER_YOUNG_COUPLE_EVE_JON, SevaultCanyon_Entrance_Text_EveIntro, SevaultCanyon_Entrance_Text_EveDefeat, SevaultCanyon_Entrance_Text_EveNotEnoughMons
    msgbox SevaultCanyon_Entrance_Text_EvePostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_Entrance_EventScript_Jon::
    trainerbattle_double TRAINER_YOUNG_COUPLE_EVE_JON, SevaultCanyon_Entrance_Text_JonIntro, SevaultCanyon_Entrance_Text_JonDefeat, SevaultCanyon_Entrance_Text_JonNotEnoughMons
    msgbox SevaultCanyon_Entrance_Text_JonPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_Entrance_EventScript_Mason::
    trainerbattle_single TRAINER_JUGGLER_MASON, SevaultCanyon_Entrance_Text_MasonIntro, SevaultCanyon_Entrance_Text_MasonDefeat, SevaultCanyon_Entrance_EventScript_RegisterMason
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq SevaultCanyon_Entrance_EventScript_MasonRematch
    msgbox SevaultCanyon_Entrance_Text_MasonPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_Entrance_EventScript_RegisterMason::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox SevaultCanyon_Entrance_Text_MasonRegister, MSGBOX_DEFAULT
    register_matchcall TRAINER_JUGGLER_MASON
    release
    end

SevaultCanyon_Entrance_EventScript_MasonRematch::
    trainerbattle_rematch TRAINER_JUGGLER_MASON, SevaultCanyon_Entrance_Text_MasonRematchIntro, SevaultCanyon_Entrance_Text_MasonDefeat
    msgbox SevaultCanyon_Entrance_Text_MasonPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_Entrance_EventScript_Nicolas::
    trainerbattle_single TRAINER_PKMN_RANGER_NICOLAS, SevaultCanyon_Entrance_Text_NicolasIntro, SevaultCanyon_Entrance_Text_NicolasDefeat, SevaultCanyon_Entrance_EventScript_RegisterNicolas
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq SevaultCanyon_Entrance_EventScript_NicolasRematch
    msgbox SevaultCanyon_Entrance_Text_NicolasPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_Entrance_EventScript_RegisterNicolas::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox SevaultCanyon_Entrance_Text_NicolasRegister, MSGBOX_DEFAULT
    register_matchcall TRAINER_PKMN_RANGER_NICOLAS
    release
    end

SevaultCanyon_Entrance_EventScript_NicolasRematch::
    trainerbattle_rematch TRAINER_PKMN_RANGER_NICOLAS, SevaultCanyon_Entrance_Text_NicolasRematchIntro, SevaultCanyon_Entrance_Text_NicolasDefeat
    msgbox SevaultCanyon_Entrance_Text_NicolasPostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_Entrance_EventScript_Madeline::
    trainerbattle_single TRAINER_PKMN_RANGER_MADELINE, SevaultCanyon_Entrance_Text_MadelineIntro, SevaultCanyon_Entrance_Text_MadelineDefeat, SevaultCanyon_Entrance_EventScript_RegisterMadeline
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq SevaultCanyon_Entrance_EventScript_MadelineRematch
    msgbox SevaultCanyon_Entrance_Text_MadelinePostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_Entrance_EventScript_RegisterMadeline::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox SevaultCanyon_Entrance_Text_MadelineRegister, MSGBOX_DEFAULT
    register_matchcall TRAINER_PKMN_RANGER_MADELINE
    release
    end

SevaultCanyon_Entrance_EventScript_MadelineRematch::
    trainerbattle_rematch TRAINER_PKMN_RANGER_MADELINE, SevaultCanyon_Entrance_Text_MadelineRematchIntro, SevaultCanyon_Entrance_Text_MadelineDefeat
    msgbox SevaultCanyon_Entrance_Text_MadelinePostBattle, MSGBOX_AUTOCLOSE
    end

SevaultCanyon_Entrance_EventScript_RouteSign::
    msgbox SevaultCanyon_Entrance_Text_RouteSign, MSGBOX_SIGN
    end

SevaultCanyon_Entrance_Text_RouteSign::
    .string "Sevault Canyon Entrance\p"
    .string "Trainers are asked to refrain from\n"
    .string "damaging plants in the canyon.$"
