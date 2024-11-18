CeruleanCave_B1F_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, CeruleanCave_B1F_OnResume
    map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCave_B1F_OnTransition
    .byte 0

CeruleanCave_B1F_OnResume::
    call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, CeruleanCave_B1F_EventScript_TryRemoveMewtwo
    end

CeruleanCave_B1F_EventScript_TryRemoveMewtwo::
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_CAUGHT
    goto_if_ne Common_EventScript_NopReturn
    removeobject VAR_LAST_TALKED
    return

CeruleanCave_B1F_OnTransition::
    call_if_unset FLAG_FOUGHT_MEWTWO, CeruleanCave_B1F_EventScript_ShowMewtwo
    end

CeruleanCave_B1F_EventScript_ShowMewtwo::
    clearflag FLAG_HIDE_MEWTWO
    return

CeruleanCave_B1F_EventScript_Mewtwo::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_MEWTWO, 2
    message CeruleanCave_B1F_Text_Mew
    waitmessage
    waitmoncry
    delay 20
    playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
    waitbuttonpress
    setwildbattle SPECIES_MEWTWO, 70, ITEM_NONE
    setflag FLAG_SYS_SPECIAL_WILD_BATTLE
    special BattleSetup_StartLegendaryBattle
    waitstate
    clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_WON
    goto_if_eq CeruleanCave_B1F_EventScript_DefeatedMewtwo
    compare VAR_RESULT, B_OUTCOME_RAN
    goto_if_eq CeruleanCave_B1F_EventScript_RanFromMewtwo
    compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
    goto_if_eq CeruleanCave_B1F_EventScript_RanFromMewtwo
    setflag FLAG_FOUGHT_MEWTWO
    release
    end

CeruleanCave_B1F_EventScript_DefeatedMewtwo::
    setflag FLAG_FOUGHT_MEWTWO
    goto Common_EventScript_RemoveStaticPokemon
    end

CeruleanCave_B1F_EventScript_RanFromMewtwo::
    setvar VAR_0x8004, SPECIES_MEWTWO
    goto Common_EventScript_LegendaryFlewAway
    end

CeruleanCave_B1F_Text_Mew::
    .string "Mew!$"