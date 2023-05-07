KindleRoad_MapScripts::
	.byte 0

KindleRoad_EventScript_Maria::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_MARIA, KindleRoad_Text_MariaIntro, KindleRoad_Text_MariaDefeat
    msgbox KindleRoad_Text_MariaPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Abigail::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_ABIGAIL, KindleRoad_Text_AbigailIntro, KindleRoad_Text_AbigailDefeat
    msgbox KindleRoad_Text_AbigailPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Finn::
    trainerbattle_single TRAINER_SWIMMER_MALE_FINN, KindleRoad_Text_FinnIntro, KindleRoad_Text_FinnDefeat, KindleRoad_EventScript_RegisterFinn
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq KindleRoad_EventScript_FinnRematch
    msgbox KindleRoad_Text_FinnPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_RegisterFinn::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox KindleRoad_Text_FinnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SWIMMER_MALE_FINN
	release
	end

KindleRoad_EventScript_FinnRematch::
    trainerbattle_rematch TRAINER_SWIMMER_MALE_FINN, KindleRoad_Text_FinnRematchIntro, KindleRoad_Text_FinnDefeat
    msgbox KindleRoad_Text_FinnPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Garrett::
    trainerbattle_single TRAINER_SWIMMER_MALE_GARRETT, KindleRoad_Text_GarrettIntro, KindleRoad_Text_GarrettDefeat
    msgbox KindleRoad_Text_GarrettPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Tommy::
    trainerbattle_single TRAINER_FISHERMAN_TOMMY, KindleRoad_Text_TommyIntro, KindleRoad_Text_TommyDefeat
    msgbox KindleRoad_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Sharon::
    trainerbattle_single TRAINER_CRUSH_GIRL_SHARON, KindleRoad_Text_SharonIntro, KindleRoad_Text_SharonDefeat, KindleRoad_EventScript_RegisterSharon
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq KindleRoad_EventScript_SharonRematch
    msgbox KindleRoad_Text_SharonPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_RegisterSharon::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox KindleRoad_Text_SharonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CRUSH_GIRL_SHARON
	release
	end

KindleRoad_EventScript_SharonRematch::
    trainerbattle_rematch TRAINER_CRUSH_GIRL_SHARON, KindleRoad_Text_SharonRematchIntro, KindleRoad_Text_SharonDefeat
    msgbox KindleRoad_Text_SharonPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Tanya::
    trainerbattle_single TRAINER_CRUSH_GIRL_TANYA, KindleRoad_Text_TanyaIntro, KindleRoad_Text_TanyaDefeat, KindleRoad_EventScript_RegisterTanya
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq KindleRoad_EventScript_TanyaRematch
    msgbox KindleRoad_Text_TanyaPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_RegisterTanya::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox KindleRoad_Text_TanyaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CRUSH_GIRL_TANYA
	release
	end

KindleRoad_EventScript_TanyaRematch::
    trainerbattle_rematch TRAINER_CRUSH_GIRL_TANYA, KindleRoad_Text_TanyaRematchIntro, KindleRoad_Text_TanyaDefeat
    msgbox KindleRoad_Text_TanyaPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Shea::
    trainerbattle_single TRAINER_BLACK_BELT_SHEA, KindleRoad_Text_SheaIntro, KindleRoad_Text_SheaDefeat, KindleRoad_EventScript_RegisterShea
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq KindleRoad_EventScript_SheaRematch
    msgbox KindleRoad_Text_SheaPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_RegisterShea::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox KindleRoad_Text_SheaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BLACK_BELT_SHEA
	release
	end

KindleRoad_EventScript_SheaRematch::
    trainerbattle_rematch TRAINER_BLACK_BELT_SHEA, KindleRoad_Text_SheaRematchIntro, KindleRoad_Text_SheaDefeat
    msgbox KindleRoad_Text_SheaPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Hugh::
    trainerbattle_single TRAINER_BLACK_BELT_HUGH, KindleRoad_Text_HughIntro, KindleRoad_Text_HughDefeat, KindleRoad_EventScript_RegisterHugh
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq KindleRoad_EventScript_HughRematch
    msgbox KindleRoad_Text_HughPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_RegisterHugh::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox KindleRoad_Text_HughRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BLACK_BELT_HUGH
	release
	end

KindleRoad_EventScript_HughRematch::
    trainerbattle_rematch TRAINER_BLACK_BELT_HUGH, KindleRoad_Text_HughRematchIntro, KindleRoad_Text_HughDefeat
    msgbox KindleRoad_Text_HughPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Bryce::
    trainerbattle_single TRAINER_CAMPER_BRYCE, KindleRoad_Text_BryceIntro, KindleRoad_Text_BryceDefeat
    msgbox KindleRoad_Text_BrycePostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Claire::
    trainerbattle_single TRAINER_PICNICKER_CLAIRE, KindleRoad_Text_ClaireIntro, KindleRoad_Text_ClaireDefeat
    msgbox KindleRoad_Text_ClairePostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Kia::
    trainerbattle_double TRAINER_CRUSH_KIN_MIK_KIA, KindleRoad_Text_KiaIntro, KindleRoad_Text_KiaDefeat, KindleRoad_Text_KiaNotEnoughMons, KindleRoad_EventScript_RegisterKia
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq KindleRoad_EventScript_KiaRematch
    msgbox KindleRoad_Text_KiaPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_RegisterKia::
	msgbox KindleRoad_Text_KiaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CRUSH_KIN_MIK_KIA
	release
	end

KindleRoad_EventScript_KiaRematch::
    trainerbattle_rematch_double TRAINER_CRUSH_KIN_MIK_KIA, KindleRoad_Text_KiaRematchIntro, KindleRoad_Text_KiaDefeat, KindleRoad_Text_KiaNotEnoughMons
    msgbox KindleRoad_Text_KiaPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_Mik::
    trainerbattle_double TRAINER_CRUSH_KIN_MIK_KIA, KindleRoad_Text_MikIntro, KindleRoad_Text_MikDefeat, KindleRoad_Text_MikNotEnoughMons, KindleRoad_EventScript_RegisterMik
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq KindleRoad_EventScript_MikRematch
    msgbox KindleRoad_Text_MikPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_RegisterMik::
	msgbox KindleRoad_Text_MikRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CRUSH_KIN_MIK_KIA
	release
	end

KindleRoad_EventScript_MikRematch::
    trainerbattle_rematch_double TRAINER_CRUSH_KIN_MIK_KIA, KindleRoad_Text_MikRematchIntro, KindleRoad_Text_MikDefeat, KindleRoad_Text_MikNotEnoughMons
    msgbox KindleRoad_Text_MikPostBattle, MSGBOX_AUTOCLOSE
    end

KindleRoad_EventScript_RouteSign::
    msgbox KindleRoad_Text_RouteSign, MSGBOX_SIGN
    end

KindleRoad_EventScript_EmberSpaSign::
    msgbox KindleRoad_Text_EmberSpaSign, MSGBOX_SIGN
    end

KindleRoad_Text_RouteSign::
    .string "This is Kindle Road.\p"
    .string "Go straight for Mt. Ember.$"

KindleRoad_Text_EmberSpaSign::
    .string "Ember Spa\n"
    .string "Light the Fire in Your Heart!$"
