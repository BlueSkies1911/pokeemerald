MtEmber_Summit_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_Summit_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, MtEmber_Summit_OnResume
	.byte 0

MtEmber_Summit_OnResume:
    call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, MtEmber_Summit_EventScript_TryRemoveMoltres
    end

MtEmber_Summit_EventScript_TryRemoveMoltres::
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_CAUGHT
    goto_if_ne Common_EventScript_NopReturn
    removeobject VAR_LAST_TALKED
    return

MtEmber_Summit_OnTransition:
    call_if_unset FLAG_FOUGHT_MOLTRES, MtEmber_Summit_EventScript_ShowMoltres
    end

MtEmber_Summit_EventScript_ShowMoltres::
    clearflag FLAG_HIDE_MOLTRES
    return

MtEmber_Summit_EventScript_Moltres::
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
    goto_if_eq MtEmber_Summit_EventScript_DefeatedMoltres
    compare VAR_RESULT, B_OUTCOME_RAN
    goto_if_eq MtEmber_Summit_EventScript_RanFromMoltres
    compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
    goto_if_eq MtEmber_Summit_EventScript_RanFromMoltres
    setflag FLAG_FOUGHT_MOLTRES
    release
    end

MtEmber_Summit_EventScript_DefeatedMoltres::
    setflag FLAG_FOUGHT_MOLTRES
    goto Common_EventScript_RemoveStaticPokemon
    end

MtEmber_Summit_EventScript_RanFromMoltres::
    setvar VAR_0x8004, SPECIES_MOLTRES
    goto Common_EventScript_LegendaryFlewAway
    end