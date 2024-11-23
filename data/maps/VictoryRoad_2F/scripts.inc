VictoryRoad_2F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_2F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_2F_OnResume
    map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
	.byte 0

VictoryRoad_2F_OnLoad:
    compare VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
    call_if_ne VictoryRoad_2F_EventScript_SetRockBarrier1
    compare VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
    call_if_ne VictoryRoad_2F_EventScript_SetRockBarrier2
    end

VictoryRoad_2F_EventScript_SetRockBarrier1::
    setmetatile 13, 10, METATILE_Cave_RockBarrier_Top, 1
    setmetatile 13, 11, METATILE_Cave_RockBarrier_Bottom, 1
    return

VictoryRoad_2F_EventScript_SetRockBarrier2::
    setmetatile 33, 16, METATILE_Cave_RockBarrier_Top, 1
    setmetatile 33, 17, METATILE_Cave_RockBarrier_Bottom, 1
    return

VictoryRoad_2F_EventScript_FloorSwitch1::
    lockall
    compare VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
    goto_if_eq VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed
    setmetatile 13, 10, METATILE_Cave_Floor_Ledge_Top, 0
    setmetatile 13, 11, METATILE_Cave_Floor_Ledge_Bottom, 0
    playse SE_ICE_BREAK
    special DrawWholeMapView
    waitse
    copyobjectxytoperm 11
    setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
    releaseall
    end

VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed::
    releaseall
    end

VictoryRoad_2F_EventScript_FloorSwitch2::
    lockall
    compare VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
    goto_if_eq VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed
    setmetatile 33, 16, METATILE_Cave_Floor_Ledge_Top, 0
    setmetatile 33, 17, METATILE_Cave_Floor_Ledge_Bottom, 0
    playse SE_ICE_BREAK
    special DrawWholeMapView
    waitse
    copyobjectxytoperm 12
    setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
    releaseall
    end

VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed::
    releaseall
    end

VictoryRoad_2F_OnResume:
    call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, VictoryRoad_2F_EventScript_TryRemoveMoltres
    end

VictoryRoad_2F_EventScript_TryRemoveMoltres::
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_CAUGHT
    goto_if_ne Common_EventScript_NopReturn
    removeobject VAR_LAST_TALKED
    return

VictoryRoad_2F_OnTransition:
    call_if_unset FLAG_FOUGHT_MOLTRES, VictoryRoad_2F_EventScript_ShowMoltres
    end

VictoryRoad_2F_EventScript_ShowMoltres::
    clearflag FLAG_HIDE_MOLTRES
    return

VictoryRoad_2F_EventScript_Moltres::
    lock
    faceplayer
    setwildbattle SPECIES_MOLTRES, 50, ITEM_NONE
    waitse
    playmoncry SPECIES_MOLTRES, 2
    message gText_Gyaoo
    waitmessage
    waitmoncry
    delay 10
    playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
    waitbuttonpress
    setflag FLAG_SYS_SPECIAL_WILD_BATTLE
    special BattleSetup_StartLegendaryBattle
    waitstate
    clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_WON
    goto_if_eq VictoryRoad_2F_EventScript_DefeatedMoltres
    compare VAR_RESULT, B_OUTCOME_RAN
    goto_if_eq VictoryRoad_2F_EventScript_RanFromMoltres
    compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
    goto_if_eq VictoryRoad_2F_EventScript_RanFromMoltres
    setflag FLAG_FOUGHT_MOLTRES
    release
    end

VictoryRoad_2F_EventScript_DefeatedMoltres::
    setflag FLAG_FOUGHT_MOLTRES
    goto Common_EventScript_RemoveStaticPokemon
    end

VictoryRoad_2F_EventScript_RanFromMoltres::
    setvar VAR_0x8004, SPECIES_MOLTRES
    goto Common_EventScript_LegendaryFlewAway
    end

VictoryRoad_2F_EventScript_Dawson::
    trainerbattle_single TRAINER_POKEMANIAC_DAWSON, VictoryRoad_2F_Text_DawsonIntro, VictoryRoad_2F_Text_DawsonDefeat
    msgbox VictoryRoad_2F_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
    end

VictoryRoad_2F_EventScript_Daisuke::
    trainerbattle_single TRAINER_BLACK_BELT_DAISUKE, VictoryRoad_2F_Text_DaisukeIntro, VictoryRoad_2F_Text_DaisukeDefeat
    msgbox VictoryRoad_2F_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
    end

VictoryRoad_2F_EventScript_Nelson::
    trainerbattle_single TRAINER_JUGGLER_NELSON, VictoryRoad_2F_Text_NelsonIntro, VictoryRoad_2F_Text_NelsonDefeat
    msgbox VictoryRoad_2F_Text_NelsonPostBattle, MSGBOX_AUTOCLOSE
    end

VictoryRoad_2F_EventScript_Gregory::
    trainerbattle_single TRAINER_JUGGLER_GREGORY, VictoryRoad_2F_Text_GregoryIntro, VictoryRoad_2F_Text_GregoryDefeat
    msgbox VictoryRoad_2F_Text_GregoryPostBattle, MSGBOX_AUTOCLOSE
    end

VictoryRoad_2F_EventScript_Vincent::
    trainerbattle_single TRAINER_TAMER_VINCENT, VictoryRoad_2F_Text_VincentIntro, VictoryRoad_2F_Text_VincentDefeat
    msgbox VictoryRoad_2F_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
    end

VictoryRoad_2F_Text_DawsonIntro::
    .string "If you can get through here,\n"
    .string "you can go meet the Elite Four.$"

VictoryRoad_2F_Text_DawsonDefeat::
    .string "No!\n"
    .string "Unbelievable!$"

VictoryRoad_2F_Text_DawsonPostBattle::
    .string "I can beat you when it comes to\n"
    .string "knowledge about Pokémon!$"

VictoryRoad_2F_Text_DaisukeIntro::
    .string "This here is Victory Road.\n"
    .string "It's the final test for Trainers!$"

VictoryRoad_2F_Text_DaisukeDefeat::
    .string "Atcho!$"

VictoryRoad_2F_Text_DaisukePostBattle::
    .string "If you get stuck, try moving some\n"
    .string "boulders around.$"

VictoryRoad_2F_Text_NelsonIntro::
    .string "Ah, so you wish to challenge the\n"
    .string "Elite Four?$"

VictoryRoad_2F_Text_NelsonDefeat::
    .string "You got me!$"

VictoryRoad_2F_Text_NelsonPostBattle::
    .string "{RIVAL} also came through here.$"

VictoryRoad_2F_Text_VincentIntro::
    .string "Come on!\n"
    .string "I'll whip you!$"

VictoryRoad_2F_Text_VincentDefeat::
    .string "I got whipped!$"

VictoryRoad_2F_Text_VincentPostBattle::
    .string "You earned the right to be on\n"
    .string "Victory Road…$"

VictoryRoad_2F_Text_GregoryIntro::
    .string "Is Victory Road too tough?$"

VictoryRoad_2F_Text_GregoryDefeat::
    .string "Well done!$"

VictoryRoad_2F_Text_GregoryPostBattle::
    .string "Many Trainers give up their\n"
    .string "challenge here and go home.$"
