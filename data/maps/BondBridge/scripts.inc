BondBridge_MapScripts::
	.byte 0

BondBridge_EventScript_Nikki::
    trainerbattle_single TRAINER_AROMA_LADY_NIKKI, BondBridge_Text_NikkiIntro, BondBridge_Text_NikkiDefeat
    msgbox BondBridge_Text_NikkiPostBattle, MSGBOX_AUTOCLOSE
    end

BondBridge_EventScript_Violet::
    trainerbattle_single TRAINER_AROMA_LADY_VIOLET, BondBridge_Text_VioletIntro, BondBridge_Text_VioletDefeat
    msgbox BondBridge_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
    end

BondBridge_EventScript_Amira::
    trainerbattle_single TRAINER_TUBER_AMIRA, BondBridge_Text_AmiraIntro, BondBridge_Text_AmiraDefeat, BondBridge_EventScript_RegisterAmira
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq BondBridge_EventScript_AmiraRematch
    msgbox BondBridge_Text_AmiraPostBattle, MSGBOX_AUTOCLOSE
    end

BondBridge_EventScript_RegisterAmira::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox BondBridge_Text_AmiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TUBER_AMIRA
	release
	end

BondBridge_EventScript_AmiraRematch::
    trainerbattle_rematch TRAINER_TUBER_AMIRA, BondBridge_Text_AmiraRematchIntro, BondBridge_Text_AmiraDefeat
    msgbox BondBridge_Text_AmiraPostBattle, MSGBOX_AUTOCLOSE
    end

BondBridge_EventScript_Alexis::
    trainerbattle_single TRAINER_TUBER_ALEXIS, BondBridge_Text_AlexisIntro, BondBridge_Text_AlexisDefeat
    msgbox BondBridge_Text_AlexisPostBattle, MSGBOX_AUTOCLOSE
    end

BondBridge_EventScript_Tisha::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_TISHA, BondBridge_Text_TishaIntro, BondBridge_Text_TishaDefeat
    msgbox BondBridge_Text_TishaPostBattle, MSGBOX_AUTOCLOSE
    end

BondBridge_EventScript_Joy::
    trainerbattle_double TRAINER_TWINS_JOY_MEG, BondBridge_Text_JoyIntro, BondBridge_Text_JoyDefeat, BondBridge_Text_JoyNotEnoughMons, BondBridge_EventScript_RegisterJoy
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq BondBridge_EventScript_JoyRematch
    msgbox BondBridge_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
    end

BondBridge_EventScript_RegisterJoy::
	msgbox BondBridge_Text_JoyMegRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TWINS_JOY_MEG
	release
	end

BondBridge_EventScript_JoyRematch::
    trainerbattle_rematch_double TRAINER_TWINS_JOY_MEG, BondBridge_Text_JoyRematchIntro, BondBridge_Text_JoyDefeat, BondBridge_Text_JoyNotEnoughMons
    msgbox BondBridge_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
    end

BondBridge_EventScript_Meg::
    trainerbattle_double TRAINER_TWINS_JOY_MEG, BondBridge_Text_MegIntro, BondBridge_Text_MegDefeat, BondBridge_Text_MegNotEnoughMons, BondBridge_EventScript_RegisterMeg
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq BondBridge_EventScript_MegRematch
    msgbox BondBridge_Text_MegPostBattle, MSGBOX_AUTOCLOSE
    end

BondBridge_EventScript_RegisterMeg::
	msgbox BondBridge_Text_JoyMegRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TWINS_JOY_MEG
	release
	end

BondBridge_EventScript_MegRematch::
    trainerbattle_rematch_double TRAINER_TWINS_JOY_MEG, BondBridge_Text_MegRematchIntro, BondBridge_Text_MegDefeat, BondBridge_Text_MegNotEnoughMons
    msgbox BondBridge_Text_MegPostBattle, MSGBOX_AUTOCLOSE
    end

BondBridge_EventScript_BerryForestSign::
    msgbox BondBridge_Text_BerryForestAhead, MSGBOX_SIGN
    end

BondBridge_EventScript_BondBridgeSign::
    msgbox BondBridge_Text_BondBridgeSign, MSGBOX_SIGN
    end

BondBridge_Text_BerryForestAhead::
    .string "Berry Forest Ahead$"

BondBridge_Text_BondBridgeSign::
    .string "BOND BRIDGE\n"
    .string "Please be quiet when crossing.\p"
    .string "Berry Forest Ahead$"
