GreenPath_MapScripts::
	.byte 0

GreenPath_EventScript_Jaclyn::
    trainerbattle_single TRAINER_PSYCHIC_JACLYN, GreenPath_Text_JaclynIntro, GreenPath_Text_JaclynDefeat, GreenPath_EventScript_RegisterJaclyn
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq GreenPath_EventScript_JaclynRematch
    msgbox GreenPath_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
    end

GreenPath_EventScript_RegisterJaclyn::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox GreenPath_Text_JaclynRegister, MSGBOX_DEFAULT
    register_matchcall TRAINER_PSYCHIC_JACLYN
    release
    end

GreenPath_EventScript_JaclynRematch::
    trainerbattle_rematch TRAINER_PSYCHIC_JACLYN, GreenPath_Text_JaclynRematchIntro, GreenPath_Text_JaclynDefeat
    msgbox GreenPath_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
    end

GreenPath_EventScript_RightRouteSign::
    msgbox GreenPath_Text_LeftRouteSign, MSGBOX_SIGN
    end

GreenPath_EventScript_LeftRouteSign::
    msgbox GreenPath_Text_RightRouteSign, MSGBOX_SIGN
    end

GreenPath_Text_RightRouteSign::
    .string "GREEN PATH\n"
    .string "Think Green, Keep Nature Clean!$"

GreenPath_Text_LeftRouteSign::
    .string "GREEN PATH\n"
    .string "Pattern Bush Ahead$"
