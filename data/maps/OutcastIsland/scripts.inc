OutcastIsland_MapScripts::
	.byte 0

OutcastIsland_EventScript_Rocket::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_46, OutcastIsland_Text_RocketIntro, OutcastIsland_Text_RocketDefeat
    msgbox OutcastIsland_Text_RocketPostBattle, MSGBOX_AUTOCLOSE
    end

OutcastIsland_EventScript_Tylor::
    trainerbattle_single TRAINER_FISHERMAN_TYLOR, OutcastIsland_Text_TylorIntro, OutcastIsland_Text_TylorDefeat
    msgbox OutcastIsland_Text_TylorPostBattle, MSGBOX_AUTOCLOSE
    end

OutcastIsland_EventScript_Mymo::
    trainerbattle_single TRAINER_SWIMMER_MALE_MYMO, OutcastIsland_Text_MymoIntro, OutcastIsland_Text_MymoDefeat
    msgbox OutcastIsland_Text_MymoPostBattle, MSGBOX_AUTOCLOSE
    end

OutcastIsland_EventScript_Nicole::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_NICOLE, OutcastIsland_Text_NicoleIntro, OutcastIsland_Text_NicoleDefeat, OutcastIsland_EventScript_RegisterNicole
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq OutcastIsland_EventScript_NicoleRematch
    msgbox OutcastIsland_Text_NicolePostBattle, MSGBOX_AUTOCLOSE
    end

OutcastIsland_EventScript_RegisterNicole::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox OutcastIsland_Text_NicoleRegister, MSGBOX_DEFAULT
    register_matchcall TRAINER_SWIMMER_FEMALE_NICOLE
    release
    end

OutcastIsland_EventScript_NicoleRematch::
    trainerbattle_rematch TRAINER_SWIMMER_FEMALE_NICOLE, OutcastIsland_Text_NicoleRematchIntro, OutcastIsland_Text_NicoleDefeat
    msgbox OutcastIsland_Text_NicolePostBattle, MSGBOX_AUTOCLOSE
    end

OutcastIsland_EventScript_Ava::
    trainerbattle_double TRAINER_SIS_AND_BRO_AVA_GEB, OutcastIsland_Text_AvaIntro, OutcastIsland_Text_AvaDefeat, OutcastIsland_Text_AvaNotEnoughMons
    msgbox OutcastIsland_Text_AvaPostBattle, MSGBOX_AUTOCLOSE
    end

OutcastIsland_EventScript_Geb::
    trainerbattle_double TRAINER_SIS_AND_BRO_AVA_GEB, OutcastIsland_Text_GebIntro, OutcastIsland_Text_GebDefeat, OutcastIsland_Text_GebNotEnoughMons
    msgbox OutcastIsland_Text_GebPostBattle, MSGBOX_AUTOCLOSE
    end
