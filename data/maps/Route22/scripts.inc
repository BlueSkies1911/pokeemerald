.set LOCALID_RIVAL, 1

Route22_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route22_OnTransition
    .byte 0

Route22_OnTransition:
	randomweather
    end

Route22_EventScript_EarlyRivalTriggerTop::
    lockall
    setvar VAR_TEMP_1, 0
    goto Route22_EventScript_EarlyRival
    end

Route22_EventScript_EarlyRivalTriggerMid::
    lockall
    setvar VAR_TEMP_1, 1
    setobjectxyperm LOCALID_RIVAL, 25, 6
    goto Route22_EventScript_EarlyRival
    end

Route22_EventScript_EarlyRivalTriggerBottom::
    lockall
    setvar VAR_TEMP_1, 2
    setobjectxyperm LOCALID_RIVAL, 25, 6
    goto Route22_EventScript_EarlyRival
    end

Route22_EventScript_EarlyRival::
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    addobject LOCALID_RIVAL
    compare VAR_TEMP_1, 0
    call_if_eq Route22_EventScript_EarlyRivalApproach
    compare VAR_TEMP_1, 1
    call_if_eq Route22_EventScript_EarlyRivalApproach
    compare VAR_TEMP_1, 2
    call_if_eq Route22_EventScript_EarlyRivalApproachBottom
    delay 6
    msgbox Route22_Text_EarlyRivalIntro, MSGBOX_DEFAULT
    compare VAR_STARTER_MON, 2
    call_if_eq Route22_EventScript_EarlyRivalSquirtle
    compare VAR_STARTER_MON, 1
    call_if_eq Route22_EventScript_EarlyRivalBulbasaur
    compare VAR_STARTER_MON, 0
    call_if_eq Route22_EventScript_EarlyRivalCharmander
    msgbox Route22_Text_EarlyRivalPostBattle, MSGBOX_DEFAULT
    closemessage
    delay 10
    playbgm MUS_RG_RIVAL_EXIT, 0
    compare VAR_TEMP_1, 0
    call_if_eq Route22_EventScript_EarlyRivalExit
    compare VAR_TEMP_1, 1
    call_if_eq Route22_EventScript_EarlyRivalExit
    compare VAR_TEMP_1, 2
    call_if_eq Route22_EventScript_EarlyRivalExitBottom
    fadedefaultbgm
    removeobject LOCALID_RIVAL
    setvar VAR_MAP_SCENE_ROUTE22, 2
    releaseall
    end

Route22_EventScript_EarlyRivalApproach::
    applymovement LOCALID_RIVAL, Route22_Movement_RivalApproach
    waitmovement 0
    return

Route22_Movement_RivalApproach::
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

Route22_EventScript_EarlyRivalApproachBottom::
    applymovement LOCALID_RIVAL, Route22_Movement_RivalApproachBottom
    applymovement OBJ_EVENT_ID_PLAYER, Route22_Movement_PlayerFaceRival
    waitmovement 0
    return

Route22_Movement_RivalApproachBottom::
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_in_place_faster_down
    step_end

Route22_Movement_PlayerFaceRival::
    delay_16
    delay_16
    delay_16
    delay_16
    delay_16
    delay_16
    delay_16
    delay_8
    walk_in_place_faster_up
    step_end

Route22_EventScript_EarlyRivalSquirtle::
    trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
    return

Route22_EventScript_EarlyRivalBulbasaur::
    trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
    return

Route22_EventScript_EarlyRivalCharmander::
    trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
    return

Route22_EventScript_EarlyRivalExit::
    applymovement LOCALID_RIVAL, Route22_Movement_EarlyRivalExit
    waitmovement 0
    return

Route22_Movement_EarlyRivalExit::
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

Route22_EventScript_EarlyRivalExitBottom::
    applymovement LOCALID_RIVAL, Route22_Movement_EarlyRivalExitBottom
    waitmovement 0
    return

Route22_Movement_EarlyRivalExitBottom::
    walk_right
    walk_right
    walk_right
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

Route22_EventScript_LateRivalTriggerTop::
    lockall
    setvar VAR_TEMP_1, 0
    goto Route22_EventScript_LateRival
    end

Route22_EventScript_LateRivalTriggerMid::
    lockall
    setvar VAR_TEMP_1, 1
    setobjectxyperm LOCALID_RIVAL, 25, 6
    goto Route22_EventScript_LateRival
    end

Route22_EventScript_LateRivalTriggerBottom::
    lockall
    setvar VAR_TEMP_1, 2
    setobjectxyperm LOCALID_RIVAL, 25, 6
    goto Route22_EventScript_LateRival
    end

Route22_EventScript_LateRival::
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    addobject LOCALID_RIVAL
    compare VAR_TEMP_1, 0
    call_if_eq Route22_EventScript_LateRivalApproach
    compare VAR_TEMP_1, 1
    call_if_eq Route22_EventScript_LateRivalApproach
    compare VAR_TEMP_1, 2
    call_if_eq Route22_EventScript_LateRivalApproachBottom
    msgbox Route22_Text_LateRivalIntro, MSGBOX_DEFAULT
    setvar VAR_LAST_TALKED, LOCALID_RIVAL
    compare VAR_STARTER_MON, 2
    call_if_eq Route22_EventScript_LateRivalSquirtle
    compare VAR_STARTER_MON, 1
    call_if_eq Route22_EventScript_LateRivalBulbasaur
    compare VAR_STARTER_MON, 0
    call_if_eq Route22_EventScript_LateRivalCharmander
    msgbox Route22_Text_LateRivalPostBattle, MSGBOX_DEFAULT
    closemessage
    delay 10
    playbgm MUS_RG_RIVAL_EXIT, 0
    applymovement LOCALID_RIVAL, Route22_Movement_LateRivalExit
    waitmovement 0
    fadedefaultbgm
    removeobject LOCALID_RIVAL
    setvar VAR_MAP_SCENE_ROUTE22, 4
    releaseall
    end

Route22_EventScript_LateRivalApproach::
    applymovement LOCALID_RIVAL, Route22_Movement_RivalApproach
    waitmovement 0
    return

Route22_EventScript_LateRivalApproachBottom::
    applymovement LOCALID_RIVAL, Route22_Movement_RivalApproachBottom
    applymovement OBJ_EVENT_ID_PLAYER, Route22_Movement_PlayerFaceRival
    waitmovement 0
    return

Route22_EventScript_LateRivalSquirtle::
    trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE, Route22_Text_LateRivalDefeat
    return

Route22_EventScript_LateRivalBulbasaur::
    trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR, Route22_Text_LateRivalDefeat
    return

Route22_EventScript_LateRivalCharmander::
    trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER, Route22_Text_LateRivalDefeat
    return

Route22_Movement_LateRivalExit::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

Route22_EventScript_LeagueGateSign::
    msgbox Route22_Text_LeagueGateSign, MSGBOX_SIGN
    end

Route22_Text_EarlyRivalIntro::
    .string "{RIVAL}: Hey! {PLAYER}!\p"
    .string "You're off to the Pokémon League?\n"
    .string "Forget about it!\p"
    .string "You probably don't have any\n"
    .string "Badges, do you?\p"
    .string "The guard won't let you through\n"
    .string "without them.\p"
    .string "By the way, did your Pokémon get\n"
    .string "any stronger?$"

Route22_Text_EarlyRivalDefeat::
    .string "Awww!\n"
    .string "You just lucked out!$"

Route22_Text_EarlyRivalPostBattle::
    .string "I heard the Pokémon League is\n"
    .string "crawling with tough Trainers.\p"
    .string "I have to figure out how to get\n"
    .string "past them.\p"
    .string "You should quit dawdling and get a\n"
    .string "move on!$"

Route22_Text_LateRivalIntro::
    .string "{RIVAL}: What? {PLAYER}!\n"
    .string "What a surprise to see you here!\p"
    .string "So you're going to the Pokémon\n"
    .string "League?\p"
    .string "You collected all the badges, too?\n"
    .string "That's cool!\p"
    .string "Then I'll whip you, {PLAYER}, as a\n"
    .string "warm-up for the Pokémon League!\p"
    .string "Come on!$"

Route22_Text_LateRivalDefeat::
    .string "What!?\p"
    .string "I was just careless, you!$"

Route22_Text_LateRivalPostBattle::
    .string "That loosened me up.\n"
    .string "I'm ready for the Pokémon League!\p"
    .string "{PLAYER}, you need more practice.\p"
    .string "But hey, you know that!\n"
    .string "I'm out of here. Smell ya!$"

Route22_Text_LeagueGateSign::
    .string "Pokémon League\n"
    .string "Front Gate$"
