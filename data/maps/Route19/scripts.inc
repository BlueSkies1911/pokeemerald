Route19_MapScripts::
	.byte 0

Route19_EventScript_Richard::
    trainerbattle_single TRAINER_SWIMMER_MALE_RICHARD, Route19_Text_RichardIntro, Route19_Text_RichardDefeat
    msgbox Route19_Text_RichardPostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_Reece::
    trainerbattle_single TRAINER_SWIMMER_MALE_REECE, Route19_Text_ReeceIntro, Route19_Text_ReeceDefeat
    msgbox Route19_Text_ReecePostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_Matthew::
    trainerbattle_single TRAINER_SWIMMER_MALE_MATTHEW, Route19_Text_MatthewIntro, Route19_Text_MatthewDefeat, Route19_EventScript_RegisterMatthew
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route19_EventScript_MatthewRematch
    msgbox Route19_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_RegisterMatthew::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route19_Text_MatthewRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SWIMMER_MALE_MATTHEW
	release
	end

Route19_EventScript_MatthewRematch::
    trainerbattle_rematch TRAINER_SWIMMER_MALE_MATTHEW, Route19_Text_MatthewRematchIntro, Route19_Text_MatthewDefeat
    msgbox Route19_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_Douglas::
    trainerbattle_single TRAINER_SWIMMER_MALE_DOUGLAS, Route19_Text_DouglasIntro, Route19_Text_DouglasDefeat
    msgbox Route19_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_David::
    trainerbattle_single TRAINER_SWIMMER_MALE_DAVID, Route19_Text_DavidIntro, Route19_Text_DavidDefeat
    msgbox Route19_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_Tony::
    trainerbattle_single TRAINER_SWIMMER_MALE_TONY, Route19_Text_TonyIntro, Route19_Text_TonyDefeat, Route19_EventScript_RegisterTony
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route19_EventScript_TonyRematch
    msgbox Route19_Text_TonyPostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_RegisterTony::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route19_Text_TonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SWIMMER_MALE_TONY
	release
	end

Route19_EventScript_TonyRematch::
    trainerbattle_rematch TRAINER_SWIMMER_MALE_TONY, Route19_Text_TonyRematchIntro, Route19_Text_TonyDefeat
    msgbox Route19_Text_TonyPostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_Axle::
    trainerbattle_single TRAINER_SWIMMER_MALE_AXLE, Route19_Text_AxleIntro, Route19_Text_AxleDefeat
    msgbox Route19_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_Anya::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_ANYA, Route19_Text_AnyaIntro, Route19_Text_AnyaDefeat
    msgbox Route19_Text_AnyaPostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_Alice::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_ALICE, Route19_Text_AliceIntro, Route19_Text_AliceDefeat, Route19_EventScript_RegisterAlice
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route19_EventScript_AliceRematch
    msgbox Route19_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_RegisterAlice::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route19_Text_AliceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SWIMMER_FEMALE_ALICE
	release
	end

Route19_EventScript_AliceRematch::
    trainerbattle_rematch TRAINER_SWIMMER_FEMALE_ALICE, Route19_Text_AliceRematchIntro, Route19_Text_AliceDefeat
    msgbox Route19_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_Connie::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_CONNIE, Route19_Text_ConnieIntro, Route19_Text_ConnieDefeat
    msgbox Route19_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_Lia::
    trainerbattle_double TRAINER_SIS_AND_BRO_LIA_LUC, Route19_Text_LiaIntro, Route19_Text_LiaDefeat, Route19_Text_LiaNotEnoughMons
    msgbox Route19_Text_LiaPostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_Luc::
    trainerbattle_double TRAINER_SIS_AND_BRO_LIA_LUC, Route19_Text_LucIntro, Route19_Text_LucDefeat, Route19_Text_LucNotEnoughMons
    msgbox Route19_Text_LucPostBattle, MSGBOX_AUTOCLOSE
    end

Route19_EventScript_RouteSign::
    msgbox Route19_Text_RouteSign, MSGBOX_SIGN
    end

Route19_Text_RouteSign::
    .string "SEA ROUTE 19\n"
    .string "Fuchsia City - Seafoam Islands$"
