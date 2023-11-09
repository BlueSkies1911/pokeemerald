Route25_MapScripts::
	.byte 0

Route25_EventScript_Joey::
    trainerbattle_single TRAINER_YOUNGSTER_JOEY, Route25_Text_JoeyIntro, Route25_Text_JoeyDefeat
    msgbox Route25_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_Dan::
    trainerbattle_single TRAINER_YOUNGSTER_DAN, Route25_Text_DanIntro, Route25_Text_DanDefeat
    msgbox Route25_Text_DanPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_Chad::
    trainerbattle_single TRAINER_YOUNGSTER_CHAD, Route25_Text_ChadIntro, Route25_Text_ChadDefeat, Route25_EventScript_RegisterChad
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route25_EventScript_ChadRematch
    msgbox Route25_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_RegisterChad::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route25_Text_ChadRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_YOUNGSTER_CHAD
	release
	end

Route25_EventScript_ChadRematch::
    trainerbattle_rematch TRAINER_YOUNGSTER_CHAD, Route25_Text_ChadRematchIntro, Route25_Text_ChadDefeat
    msgbox Route25_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_Kelsey::
    trainerbattle_single TRAINER_PICNICKER_KELSEY, Route25_Text_KelseyIntro, Route25_Text_KelseyDefeat, Route25_EventScript_RegisterKelsey
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route25_EventScript_KelseyRematch
    msgbox Route25_Text_KelseyPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_RegisterKelsey::
	msgbox Route25_Text_KelseyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PICNICKER_KELSEY
	release
	end

Route25_EventScript_KelseyRematch::
    trainerbattle_rematch TRAINER_PICNICKER_KELSEY, Route25_Text_KelseyRematchIntro, Route25_Text_KelseyDefeat
    msgbox Route25_Text_KelseyPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_Haley::
    trainerbattle_single TRAINER_LASS_HALEY, Route25_Text_HaleyIntro, Route25_Text_HaleyDefeat
    msgbox Route25_Text_HaleyPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_Franklin::
    trainerbattle_single TRAINER_HIKER_FRANKLIN, Route25_Text_FranklinIntro, Route25_Text_FranklinDefeat, Route25_EventScript_RegisterFranklin
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route25_EventScript_FranklinRematch
    msgbox Route25_Text_FranklinPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_RegisterFranklin::
	msgbox Route25_Text_FranklinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HIKER_FRANKLIN
	release
	end

Route25_EventScript_FranklinRematch::
    trainerbattle_rematch TRAINER_HIKER_FRANKLIN, Route25_Text_FranklinRematchIntro, Route25_Text_FranklinDefeat
    msgbox Route25_Text_FranklinPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_Nob::
    trainerbattle_single TRAINER_HIKER_NOB, Route25_Text_NobIntro, Route25_Text_NobDefeat
    msgbox Route25_Text_NobPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_Wayne::
    trainerbattle_single TRAINER_HIKER_WAYNE, Route25_Text_WayneIntro, Route25_Text_WayneDefeat
    msgbox Route25_Text_WaynePostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_Flint::
    trainerbattle_single TRAINER_CAMPER_FLINT, Route25_Text_FlintIntro, Route25_Text_FlintDefeat
    msgbox Route25_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
    end

Route25_EventScript_Man::
    msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
    end

Route25_EventScript_Beauty::
    msgbox Route25_Text_MistyHighHopesAboutThisPlace, MSGBOX_NPC
    end

Route25_EventScript_SeaCottageSign::
    msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
    end

Route25_Text_AreYouHereAlone::
    .string "Hello, are you here alone?\p"
    .string "If you're out at Cerulean's cape…\n"
    .string "Well, it should be as a couple.$"

Route25_Text_MistyHighHopesAboutThisPlace::
    .string "This cape is a famous date spot.\p"
    .string "Misty, the Gym Leader, has high\n"
    .string "hopes about this place.$"

Route25_Text_SeaCottageSign::
    .string "Sea Cottage\n"
    .string "Bill lives here!$"
