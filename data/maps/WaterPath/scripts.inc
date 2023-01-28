WaterPath_MapScripts::
	.byte 0

WaterPath_EventScript_Rose::
    trainerbattle_single TRAINER_AROMA_LADY_ROSE, WaterPath_Text_RoseIntro, WaterPath_Text_RoseDefeat
    msgbox WaterPath_Text_RosePostBattle, MSGBOX_AUTOCLOSE
    end

WaterPath_EventScript_Edward::
    trainerbattle_single TRAINER_JUGGLER_EDWARD, WaterPath_Text_EdwardIntro, WaterPath_Text_EdwardDefeat
    msgbox WaterPath_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
    end

WaterPath_EventScript_Samir::
    trainerbattle_single TRAINER_SWIMMER_MALE_SAMIR, WaterPath_Text_SamirIntro, WaterPath_Text_SamirDefeat, WaterPath_EventScript_RegisterSamir
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq WaterPath_EventScript_SamirRematch
    msgbox WaterPath_Text_SamirPostBattle, MSGBOX_AUTOCLOSE
    end

WaterPath_EventScript_RegisterSamir::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox WaterPath_Text_SamirRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SWIMMER_MALE_SAMIR
	release
	end

WaterPath_EventScript_SamirRematch::
    trainerbattle_rematch TRAINER_SWIMMER_MALE_SAMIR, WaterPath_Text_SamirRematchIntro, WaterPath_Text_SamirDefeat
    msgbox WaterPath_Text_SamirPostBattle, MSGBOX_AUTOCLOSE
    end

WaterPath_EventScript_Denise::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_DENISE, WaterPath_Text_DeniseIntro, WaterPath_Text_DeniseDefeat
    msgbox WaterPath_Text_DenisePostBattle, MSGBOX_AUTOCLOSE
    end

WaterPath_EventScript_Miu::
    trainerbattle_double TRAINER_TWINS_MIU_MIA, WaterPath_Text_MiuIntro, WaterPath_Text_MiuDefeat, WaterPath_Text_MiuNotEnoughMons
    msgbox WaterPath_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
    end

WaterPath_EventScript_Mia::
    trainerbattle_double TRAINER_TWINS_MIU_MIA, WaterPath_Text_MiaIntro, WaterPath_Text_MiaDefeat, WaterPath_Text_MiaNotEnoughMons
    msgbox WaterPath_Text_MiaPostBattle, MSGBOX_AUTOCLOSE
    end

WaterPath_EventScript_Earl::
    trainerbattle_single TRAINER_HIKER_EARL, WaterPath_Text_EarlIntro, WaterPath_Text_EarlDefeat, WaterPath_EventScript_RegisterEarl
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq WaterPath_EventScript_EarlRematch
    msgbox WaterPath_Text_EarlPostBattle, MSGBOX_AUTOCLOSE
    end

WaterPath_EventScript_RegisterEarl::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox WaterPath_Text_EarlRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HIKER_EARL
	release
	end

WaterPath_EventScript_EarlRematch::
    trainerbattle_rematch TRAINER_HIKER_EARL, WaterPath_Text_EarlRematchIntro, WaterPath_Text_EarlDefeat
    msgbox WaterPath_Text_EarlPostBattle, MSGBOX_AUTOCLOSE
    end

WaterPath_EventScript_HornWantedSign::
    msgbox WaterPath_Text_WantedUltimateHorn, MSGBOX_SIGN
    end

WaterPath_EventScript_RouteSign::
    msgbox WaterPath_Text_RouteSign, MSGBOX_SIGN
    end

WaterPath_Text_WantedUltimateHorn::
    .string "Wanted!\n"
    .string "The Ultimate Horn!$"

WaterPath_Text_RouteSign::
    .string "WATER PATH\n"
    .string "Leads to Ruin Valley$"
