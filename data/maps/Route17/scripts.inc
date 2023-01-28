Route17_MapScripts::
	.byte 0

Route17_EventScript_Billy::
    trainerbattle_single TRAINER_BIKER_BILLY, Route17_Text_BillyIntro, Route17_Text_BillyDefeat
    msgbox Route17_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_Nikolas::
    trainerbattle_single TRAINER_BIKER_NIKOLAS, Route17_Text_NikolasIntro, Route17_Text_NikolasDefeat
    msgbox Route17_Text_NikolasPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_Jaxon::
    trainerbattle_single TRAINER_BIKER_JAXON, Route17_Text_JaxonIntro, Route17_Text_JaxonDefeat, Route17_EventScript_RegisterJaxon
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route17_EventScript_JaxonRematch
    msgbox Route17_Text_JaxonPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_RegisterJaxon::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_JaxonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIKER_JAXON
	release
	end

Route17_EventScript_JaxonRematch::
    trainerbattle_rematch TRAINER_BIKER_JAXON, Route17_Text_JaxonRematchIntro, Route17_Text_JaxonDefeat
    msgbox Route17_Text_JaxonPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_William::
    trainerbattle_single TRAINER_BIKER_WILLIAM, Route17_Text_WilliamIntro, Route17_Text_WilliamDefeat
    msgbox Route17_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_Raul::
    trainerbattle_single TRAINER_CUE_BALL_RAUL, Route17_Text_RaulIntro, Route17_Text_RaulDefeat
    msgbox Route17_Text_RaulPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_Isaiah::
    trainerbattle_single TRAINER_CUE_BALL_ISAIAH, Route17_Text_IsaiahIntro, Route17_Text_IsaiahDefeat, Route17_EventScript_RegisterIsaiah
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route17_EventScript_IsaiahRematch
    msgbox Route17_Text_IsaiahPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_RegisterIsaiah::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_IsaiahRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CUE_BALL_ISAIAH
	release
	end

Route17_EventScript_IsaiahRematch::
    trainerbattle_rematch TRAINER_CUE_BALL_ISAIAH, Route17_Text_IsaiahRematchIntro, Route17_Text_IsaiahDefeat
    msgbox Route17_Text_IsaiahPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_Zeek::
    trainerbattle_single TRAINER_CUE_BALL_ZEEK, Route17_Text_ZeekIntro, Route17_Text_ZeekDefeat
    msgbox Route17_Text_ZeekPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_Jamal::
    trainerbattle_single TRAINER_CUE_BALL_JAMAL, Route17_Text_JamalIntro, Route17_Text_JamalDefeat
    msgbox Route17_Text_JamalPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_Corey::
    trainerbattle_single TRAINER_CUE_BALL_COREY, Route17_Text_CoreyIntro, Route17_Text_CoreyDefeat, Route17_EventScript_RegisterCorey
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route17_EventScript_CoreyRematch
    msgbox Route17_Text_CoreyPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_RegisterCorey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_CoreyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CUE_BALL_COREY
	release
	end

Route17_EventScript_CoreyRematch::
    trainerbattle_rematch TRAINER_CUE_BALL_COREY, Route17_Text_CoreyRematchIntro, Route17_Text_CoreyDefeat
    msgbox Route17_Text_CoreyPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_Virgil::
    trainerbattle_single TRAINER_BIKER_VIRGIL, Route17_Text_VirgilIntro, Route17_Text_VirgilDefeat
    msgbox Route17_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
    end

Route17_EventScript_ItemsNotice::
    msgbox Route17_Text_WatchOutForDiscardedItems, MSGBOX_SIGN
    end

Route17_EventScript_TrainerTips1::
    msgbox Route17_Text_SameSpeciesGrowDifferentRates, MSGBOX_SIGN
    end

Route17_EventScript_TrainerTips2::
    msgbox Route17_Text_PressBToStayInPlace, MSGBOX_SIGN
    end

Route17_EventScript_RouteSign::
    msgbox Route17_Text_RouteSign, MSGBOX_SIGN
    end

Route17_EventScript_BallsNotice::
    msgbox Route17_Text_DontThrowGameThrowBalls, MSGBOX_SIGN
    end

Route17_EventScript_CyclingRoadSign::
    msgbox Route17_Text_CyclingRoadSign, MSGBOX_SIGN
    end

Route17_Text_WatchOutForDiscardedItems::
    .string "It's a notice.\p"
    .string "Watch out for discarded items.$"

Route17_Text_SameSpeciesGrowDifferentRates::
    .string "Trainer Tips\p"
    .string "All Pokémon are unique.\p"
    .string "Even Pokémon of the same species\n"
    .string "and level grow at different rates.$"

Route17_Text_PressBToStayInPlace::
    .string "Trainer Tips\p"
    .string "Press the B Button to stay in place\n"
    .string "while on a slope.$"

Route17_Text_RouteSign::
    .string "ROUTE 17\n"
    .string "Celadon City - Fuchsia City$"

Route17_Text_DontThrowGameThrowBalls::
    .string "It's a notice!\p"
    .string "Don't throw the game, throw\n"
    .string "Pokéballs instead!$"

Route17_Text_CyclingRoadSign::
    .string "CYCLING ROAD\n"
    .string "Slope ends here!$"
