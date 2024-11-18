.equ LOCALID_GIOVANNI,    1
.equ LOCALID_SILPH_SCOPE, 2
.equ LOCALID_LIFT_KEY,    4

.equ NUM_DOOR_GRUNTS_DEFEATED, VAR_TEMP_1

RocketHideout_B4F_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B4F_OnLoad
    .byte 0

RocketHideout_B4F_OnLoad:
    setvar NUM_DOOR_GRUNTS_DEFEATED, 0
    call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
    call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
    compare NUM_DOOR_GRUNTS_DEFEATED, 2
    call_if_ne RocketHideout_B4F_EventScript_SetBarrier
    end

RocketHideout_B4F_EventScript_CountGruntDefeated::
    addvar NUM_DOOR_GRUNTS_DEFEATED, 1
    return

RocketHideout_B4F_EventScript_Giovanni::
    lock
    faceplayer
    message RocketHideout_B4F_Text_GiovanniIntro
    waitmessage
    playbgm MUS_RG_ENCOUNTER_ROCKET, 0
    waitbuttonpress
    trainerbattle_no_intro TRAINER_BOSS_GIOVANNI, RocketHideout_B4F_Text_GiovanniDefeat
    msgbox RocketHideout_B4F_Text_GiovanniPostBattle, MSGBOX_DEFAULT
    fadescreen FADE_TO_BLACK
    closemessage
    removeobject LOCALID_GIOVANNI
    addobject LOCALID_SILPH_SCOPE
    clearflag FLAG_HIDE_SILPH_SCOPE
    setflag FLAG_HIDE_CELADON_ROCKETS
    fadescreen FADE_FROM_BLACK
    release
    end

RocketHideout_B4F_EventScript_SilphScope::
    lock
    faceplayer
    removeobject LOCALID_SILPH_SCOPE
    giveitem ITEM_SILPH_SCOPE
    compare VAR_RESULT, FALSE
    goto_if_eq Common_EventScript_BagIsFull
    release
    end

RocketHideout_B4F_EventScript_Grunt1::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_18, RocketHideout_B4F_Text_Grunt1Intro, RocketHideout_B4F_Text_Grunt1Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt1
    msgbox RocketHideout_B4F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
    release
    end

RocketHideout_B4F_EventScript_DefeatedGrunt1::
    msgbox RocketHideout_B4F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
    addobject LOCALID_LIFT_KEY
    clearflag FLAG_HIDE_LIFT_KEY
    release
    end

RocketHideout_B4F_EventScript_LiftKey::
    lock
    faceplayer
    setflag FLAG_CAN_USE_ROCKET_HIDEOUT_LIFT
    removeobject LOCALID_LIFT_KEY
    giveitem ITEM_LIFT_KEY
    compare VAR_RESULT, FALSE
    goto_if_eq Common_EventScript_BagIsFull
    release
    end

RocketHideout_B4F_EventScript_Grunt2::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_Text_Grunt2Intro, RocketHideout_B4F_Text_Grunt2Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt2
    msgbox RocketHideout_B4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
    end

RocketHideout_B4F_EventScript_DefeatedGrunt2::
    setvar NUM_DOOR_GRUNTS_DEFEATED, 0
    call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
    call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
    compare NUM_DOOR_GRUNTS_DEFEATED, 2
    call_if_eq RocketHideout_B4F_EventScript_RemoveBarrier
    compare NUM_DOOR_GRUNTS_DEFEATED, 2
    call_if_eq RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
    release
    end

RocketHideout_B4F_EventScript_Grunt3::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_Text_Grunt3Intro, RocketHideout_B4F_Text_Grunt3Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt3
    msgbox RocketHideout_B4F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
    end

RocketHideout_B4F_EventScript_DefeatedGrunt3::
    setvar NUM_DOOR_GRUNTS_DEFEATED, 0
    call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
    call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
    compare NUM_DOOR_GRUNTS_DEFEATED, 2
    call_if_eq RocketHideout_B4F_EventScript_RemoveBarrier
    compare NUM_DOOR_GRUNTS_DEFEATED, 2
    call_if_eq RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
    release
    end

RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval::
    playse SE_UNLOCK
    special DrawWholeMapView
    waitse
    return

RocketHideout_B4F_EventScript_SetBarrier::
    setmetatile 17, 12, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
    setmetatile 18, 12, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
    setmetatile 17, 13, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
    setmetatile 18, 13, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
    setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
    setmetatile 18, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
    return

RocketHideout_B4F_EventScript_RemoveBarrier::
    setmetatile 17, 12, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
    setmetatile 18, 12, METATILE_SilphCo_HideoutFloor, 0
    setmetatile 17, 13, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
    setmetatile 18, 13, METATILE_SilphCo_HideoutFloor, 0
    setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
    setmetatile 18, 14, METATILE_SilphCo_HideoutFloor, 0
    return

RocketHideout_B4F_Text_GiovanniIntro::
    .string "So! I must say, I am impressed you\n"
    .string "got here.\p"
    .string "Team Rocket captures Pokémon from\n"
    .string "around the world.\p"
    .string "They're important tools for keeping\n"
    .string "our criminal enterprise going.\p"
    .string "I am the leader, Giovanni!\p"
    .string "For your insolence, you will feel a\n"
    .string "world of pain!$"

RocketHideout_B4F_Text_GiovanniDefeat::
    .string "WHAT!\n"
    .string "This can't be!$"

RocketHideout_B4F_Text_GiovanniPostBattle::
    .string "I see that you raise Pokémon with\n"
    .string "utmost care.\p"
    .string "A child like you would never\n"
    .string "understand what I hope to achieve.\p"
    .string "I shall step aside this time!\p"
    .string "I hope we meet again…$"

RocketHideout_B4F_Text_Grunt2Intro::
    .string "I know you!\n"
    .string "You ruined our plans at Mt. Moon!$"

RocketHideout_B4F_Text_Grunt2Defeat::
    .string "Burned again!$"

RocketHideout_B4F_Text_Grunt2PostBattle::
    .string "Do you have something against Team\n"
    .string "Rocket?$"

RocketHideout_B4F_Text_Grunt3Intro::
    .string "How can you not see the beauty of\n"
    .string "our evil?$"

RocketHideout_B4F_Text_Grunt3Defeat::
    .string "Ayaya!$"

RocketHideout_B4F_Text_Grunt3PostBattle::
    .string "Boss!\n"
    .string "I'm sorry I failed you!$"

RocketHideout_B4F_Text_Grunt1Intro::
    .string "The elevator doesn't work?\n"
    .string "Who has the Lift Key?$"

RocketHideout_B4F_Text_Grunt1Defeat::
    .string "No!$"

RocketHideout_B4F_Text_Grunt1PostBattle::
    .string "Oh, no!\n"
    .string "I dropped the Lift Key!$"