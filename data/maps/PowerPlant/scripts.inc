PowerPlant_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, PowerPlant_OnResume
    map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_OnTransition
	.byte 0

PowerPlant_OnResume:
    call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, PowerPlant_EventScript_TryRemoveZapdos
    end

PowerPlant_EventScript_TryRemoveZapdos::
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_CAUGHT
    goto_if_ne Common_EventScript_NopReturn
    removeobject VAR_LAST_TALKED
    return

PowerPlant_OnTransition:
    setflag FLAG_WORLD_MAP_POWER_PLANT
    call_if_unset FLAG_FOUGHT_ZAPDOS, PowerPlant_EventScript_ShowZapdos
    call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1, PowerPlant_EventScript_ShowElectrode1
    call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2, PowerPlant_EventScript_ShowElectrode2
    end

PowerPlant_EventScript_ShowZapdos::
    clearflag FLAG_HIDE_ZAPDOS
    return

PowerPlant_EventScript_ShowElectrode1::
    clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_1
    return

PowerPlant_EventScript_ShowElectrode2::
    clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_2
    return

PowerPlant_EventScript_Zapdos::
    lock
    faceplayer
    setwildbattle SPECIES_ZAPDOS, 50, ITEM_NONE
    waitse
    playmoncry SPECIES_ZAPDOS, 2
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
    goto_if_eq PowerPlant_EventScript_DefeatedZapdos
    compare VAR_RESULT, B_OUTCOME_RAN
    goto_if_eq PowerPlant_EventScript_RanFromZapdos
    compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
    goto_if_eq PowerPlant_EventScript_RanFromZapdos
    setflag FLAG_FOUGHT_ZAPDOS
    release
    end

PowerPlant_EventScript_DefeatedZapdos::
    setflag FLAG_FOUGHT_ZAPDOS
    goto Common_EventScript_RemoveStaticPokemon
    end

PowerPlant_EventScript_RanFromZapdos::
    setvar VAR_0x8004, SPECIES_ZAPDOS
    goto Common_EventScript_LegendaryFlewAway
    end

PowerPlant_EventScript_Electrode1::
    lock
    faceplayer
    setwildbattle SPECIES_ELECTRODE, 34, ITEM_NONE
    waitse
    playmoncry SPECIES_ELECTRODE, 2
    delay 40
    waitmoncry
    setflag FLAG_SYS_SPECIAL_WILD_BATTLE
    dowildbattle
    clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_WON
    goto_if_eq PowerPlant_EventScript_FoughtElectrode1
    compare VAR_RESULT, B_OUTCOME_RAN
    goto_if_eq PowerPlant_EventScript_FoughtElectrode1
    compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
    goto_if_eq PowerPlant_EventScript_FoughtElectrode1
    setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
    release
    end

PowerPlant_EventScript_FoughtElectrode1::
    setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
    goto Common_EventScript_RemoveStaticPokemon
    end

PowerPlant_EventScript_Electrode2::
    lock
    faceplayer
    setwildbattle SPECIES_ELECTRODE, 34, ITEM_NONE
    waitse
    playmoncry SPECIES_ELECTRODE, 2
    delay 40
    waitmoncry
    setflag FLAG_SYS_SPECIAL_WILD_BATTLE
    dowildbattle
    clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_WON
    goto_if_eq PowerPlant_EventScript_FoughtElectrode2
    compare VAR_RESULT, B_OUTCOME_RAN
    goto_if_eq PowerPlant_EventScript_FoughtElectrode2
    compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
    goto_if_eq PowerPlant_EventScript_FoughtElectrode2
    setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
    release
    end

PowerPlant_EventScript_FoughtElectrode2::
    setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
    goto Common_EventScript_RemoveStaticPokemon
    end
