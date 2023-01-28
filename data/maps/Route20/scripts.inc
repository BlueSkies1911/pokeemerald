Route20_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	.byte 0

Route20_OnTransition:
    call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
    call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
    end

Route20_EventScript_ResetSeafoamBouldersForB3F::
    clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
    clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
    setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
    setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
    setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
    setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
    setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
    setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
    return

Route20_EventScript_ResetSeafoamBouldersForB4F::
    clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
    clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
    clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
    clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
    setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
    setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
    return

Route20_EventScript_Barry::
    trainerbattle_single TRAINER_SWIMMER_MALE_BARRY, Route20_Text_BarryIntro, Route20_Text_BarryDefeat
    msgbox Route20_Text_BarryPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_Dean::
    trainerbattle_single TRAINER_SWIMMER_MALE_DEAN, Route20_Text_DeanIntro, Route20_Text_DeanDefeat
    msgbox Route20_Text_DeanPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_Darrin::
    trainerbattle_single TRAINER_SWIMMER_MALE_DARRIN, Route20_Text_DarrinIntro, Route20_Text_DarrinDefeat, Route20_EventScript_RegisterDarrin
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route20_EventScript_DarrinRematch
    msgbox Route20_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_RegisterDarrin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_DarrinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SWIMMER_MALE_DARRIN
	release
	end

Route20_EventScript_DarrinRematch::
    trainerbattle_rematch TRAINER_SWIMMER_MALE_DARRIN, Route20_Text_DarrinRematchIntro, Route20_Text_DarrinDefeat
    msgbox Route20_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_Tiffany::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_TIFFANY, Route20_Text_TiffanyIntro, Route20_Text_TiffanyDefeat
    msgbox Route20_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_Nora::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_NORA, Route20_Text_NoraIntro, Route20_Text_NoraDefeat
    msgbox Route20_Text_NoraPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_Melissa::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_MELISSA, Route20_Text_MelissaIntro, Route20_Text_MelissaDefeat, Route20_EventScript_RegisterMelissa
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route20_EventScript_MelissaRematch
    msgbox Route20_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_RegisterMelissa::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_MelissaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SWIMMER_FEMALE_MELISSA
	release
	end

Route20_EventScript_MelissaRematch::
    trainerbattle_rematch TRAINER_SWIMMER_FEMALE_MELISSA, Route20_Text_MelissaRematchIntro, Route20_Text_MelissaDefeat
    msgbox Route20_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_Shirley::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_SHIRLEY, Route20_Text_ShirleyIntro, Route20_Text_ShirleyDefeat
    msgbox Route20_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_Roger::
    trainerbattle_single TRAINER_BIRD_KEEPER_ROGER, Route20_Text_RogerIntro, Route20_Text_RogerDefeat
    msgbox Route20_Text_RogerPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_Missy::
    trainerbattle_single TRAINER_PICNICKER_MISSY, Route20_Text_MissyIntro, Route20_Text_MissyDefeat, Route20_EventScript_RegisterMissy
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route20_EventScript_MissyRematch
    msgbox Route20_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_RegisterMissy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_MissyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PICNICKER_MISSY
	release
	end

Route20_EventScript_MissyRematch::
    trainerbattle_rematch TRAINER_PICNICKER_MISSY, Route20_Text_MissyRematchIntro, Route20_Text_MissyDefeat
    msgbox Route20_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_Irene::
    trainerbattle_single TRAINER_PICNICKER_IRENE, Route20_Text_IreneIntro, Route20_Text_IreneDefeat
    msgbox Route20_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
    end

Route20_EventScript_Camper::
    msgbox Route20_Text_MistyTrainsHere, MSGBOX_NPC
    end

Route20_EventScript_SeafoamIslandsSign::
    msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
    end

Route20_Text_MistyTrainsHere::
    .string "Strong Trainers and Water Pokémon\n"
    .string "are common sights in these parts.\p"
    .string "They say that Misty of the\n"
    .string "Cerulean Gym trains here.$"

Route20_Text_SeafoamIslands::
    .string "SEAFOAM ISLANDS$"
