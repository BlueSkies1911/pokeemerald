TrainerTower_Exterior_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_Exterior_OnTransition
    .byte 0

TrainerTower_Exterior_OnTransition::
    setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
    end

TrainerTower_Exterior_EventScript_Dario::
    trainerbattle_single TRAINER_PSYCHIC_DARIO, TrainerTower_Exterior_Text_DarioIntro, TrainerTower_Exterior_Text_DarioDefeat, TrainerTower_Exterior_EventScript_RegisterDario
    specialvar VAR_RESULT, ShouldTryRematchBattle
    goto_if_eq VAR_RESULT, TRUE, TrainerTower_Exterior_EventScript_DarioRematch
    msgbox TrainerTower_Exterior_Text_DarioPostBattle, MSGBOX_AUTOCLOSE
    end

TrainerTower_Exterior_EventScript_RegisterDario::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox TrainerTower_Exterior_Text_DarioRegister, MSGBOX_DEFAULT
    register_matchcall TRAINER_PSYCHIC_DARIO
    release
    end

TrainerTower_Exterior_EventScript_DarioRematch::
    trainerbattle_rematch TRAINER_PSYCHIC_DARIO, TrainerTower_Exterior_Text_DarioRematchIntro, TrainerTower_Exterior_Text_DarioDefeat
    msgbox TrainerTower_Exterior_Text_DarioPostBattle, MSGBOX_AUTOCLOSE
    end

TrainerTower_Exterior_EventScript_Rodette::
    trainerbattle_single TRAINER_PSYCHIC_RODETTE, TrainerTower_Exterior_Text_RodetteIntro, TrainerTower_Exterior_Text_RodetteDefeat, TrainerTower_Exterior_EventScript_RegisterRodette
    specialvar VAR_RESULT, ShouldTryRematchBattle
    goto_if_eq VAR_RESULT, TRUE, TrainerTower_Exterior_EventScript_RodetteRematch
    msgbox TrainerTower_Exterior_Text_RodettePostBattle, MSGBOX_AUTOCLOSE
    end

TrainerTower_Exterior_EventScript_RegisterRodette::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox TrainerTower_Exterior_Text_RodetteRegister, MSGBOX_DEFAULT
    register_matchcall TRAINER_PSYCHIC_RODETTE
    release
    end

TrainerTower_Exterior_EventScript_RodetteRematch::
    trainerbattle_rematch TRAINER_PSYCHIC_RODETTE, TrainerTower_Exterior_Text_RodetteRematchIntro, TrainerTower_Exterior_Text_RodetteDefeat
    msgbox TrainerTower_Exterior_Text_RodettePostBattle, MSGBOX_AUTOCLOSE
    end

TrainerTower_Exterior_EventScript_TrainerTowerSign::
    msgbox TrainerTower_Exterior_Text_TrainerTowerSign, MSGBOX_SIGN
    end

TrainerTower_Exterior_EventScript_TrainerTowerAheadSign::
    msgbox TrainerTower_Exterior_Text_TrainerTowerAhead, MSGBOX_SIGN
    end

TrainerTower_Exterior_Text_TrainerTowerSign::
    .string "Trainer Tower Entrance\n"
    .string "Rise to the challenge, Trainers!$"

TrainerTower_Exterior_Text_TrainerTowerAhead::
    .string "Trainer Tower Ahead$"
