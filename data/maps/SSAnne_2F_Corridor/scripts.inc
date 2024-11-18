.set LOCALID_RIVAL, 1

SSAnne_2F_Corridor_MapScripts::
    .byte 0

SSAnne_2F_Corridor_EventScript_RivalTriggerLeft::
    lockall
    setvar VAR_TEMP_1, 0
    goto SSAnne_2F_Corridor_EventScript_RivalTrigger
    end

SSAnne_2F_Corridor_EventScript_RivalTriggerMid::
    lockall
    setvar VAR_TEMP_1, 1
    goto SSAnne_2F_Corridor_EventScript_RivalTrigger
    end

SSAnne_2F_Corridor_EventScript_RivalTriggerRight::
    lockall
    setvar VAR_TEMP_1, 2
    goto SSAnne_2F_Corridor_EventScript_RivalTrigger
    end

SSAnne_2F_Corridor_EventScript_RivalTrigger::
    playse SE_EXIT
    delay 5
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    addobject LOCALID_RIVAL
    delay 10
    applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    delay 20
    compare VAR_TEMP_1, 0
    call_if_eq SSAnne_2F_Corridor_EventScript_RivalApproachLeft
    compare VAR_TEMP_1, 1
    call_if_eq SSAnne_2F_Corridor_EventScript_RivalApproachMid
    compare VAR_TEMP_1, 2
    call_if_eq SSAnne_2F_Corridor_EventScript_RivalApproachRight
    msgbox SSAnne_2F_Corridor_Text_RivalIntro, MSGBOX_DEFAULT
    setvar VAR_LAST_TALKED, LOCALID_RIVAL
    compare VAR_STARTER_MON, 2
    call_if_eq SSAnne_2F_Corridor_EventScript_RivalSquirtle
    compare VAR_STARTER_MON, 1
    call_if_eq SSAnne_2F_Corridor_EventScript_RivalBulbasaur
    compare VAR_STARTER_MON, 0
    call_if_eq SSAnne_2F_Corridor_EventScript_RivalCharmander
    msgbox SSAnne_2F_Corridor_Text_RivalPostBattle, MSGBOX_DEFAULT
    closemessage
    delay 10
    playbgm MUS_RG_RIVAL_EXIT, 0
    compare VAR_TEMP_1, 0
    call_if_eq SSAnne_2F_Corridor_EventScript_RivalExitLeft
    compare VAR_TEMP_1, 1
    call_if_eq SSAnne_2F_Corridor_EventScript_RivalExitMid
    compare VAR_TEMP_1, 2
    call_if_eq SSAnne_2F_Corridor_EventScript_RivalExitRight
    fadedefaultbgm
    removeobject LOCALID_RIVAL
    setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
    releaseall
    end

SSAnne_2F_Corridor_EventScript_RivalApproachLeft::
    applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachLeft
    waitmovement 0
    return

SSAnne_2F_Corridor_Movement_RivalApproachLeft::
    walk_down
    walk_down
    walk_down
    step_end

SSAnne_2F_Corridor_EventScript_RivalApproachMid::
    applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachMid
    applymovement OBJ_EVENT_ID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid
    waitmovement 0
    return

SSAnne_2F_Corridor_Movement_RivalApproachMid::
    walk_down
    walk_down
    walk_down
    walk_down
    walk_in_place_faster_right
    step_end

SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid::
    delay_16
    delay_16
    delay_16
    delay_16
    walk_in_place_faster_left
    step_end

SSAnne_2F_Corridor_EventScript_RivalApproachRight::
    applymovement OBJ_EVENT_ID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight
    applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachRight
    waitmovement 0
    return

SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight::
    delay_16
    delay_16
    delay_16
    delay_16
    walk_in_place_faster_left
    step_end
    
SSAnne_2F_Corridor_Movement_RivalApproachRight::
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    delay_4
    step_end

SSAnne_2F_Corridor_EventScript_RivalSquirtle::
    trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_SQUIRTLE, SSAnne_2F_Corridor_Text_RivalDefeat
    return

SSAnne_2F_Corridor_EventScript_RivalBulbasaur::
    trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_BULBASAUR, SSAnne_2F_Corridor_Text_RivalDefeat
    return

SSAnne_2F_Corridor_EventScript_RivalCharmander::
    trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_CHARMANDER, SSAnne_2F_Corridor_Text_RivalDefeat
    return

SSAnne_2F_Corridor_EventScript_RivalExitLeft::
    applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitLeft
    waitmovement 0
    return

SSAnne_2F_Corridor_Movement_RivalExitLeft::
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

SSAnne_2F_Corridor_EventScript_RivalExitMid::
    applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitMid
    waitmovement 0
    return

SSAnne_2F_Corridor_Movement_RivalExitMid::
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

SSAnne_2F_Corridor_EventScript_RivalExitRight::
    applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitRight
    waitmovement 0
    return

SSAnne_2F_Corridor_Movement_RivalExitRight::
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

SSAnne_2F_Corridor_EventScript_Sailor::
    msgbox SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner, MSGBOX_NPC
    end

SSAnne_2F_Corridor_Text_RivalIntro::
    .string "{RIVAL}: Bonjour!\n"
    .string "{PLAYER}!\p"
    .string "Imagine seeing you here!\n"
    .string "{PLAYER}, were you really invited?\p"
    .string "So how's your Pokédex coming?\p"
    .string "I already caught 40 kinds, pal.\n"
    .string "Different kinds are everywhere.\p"
    .string "Crawl around in grassy areas, and\n"
    .string "look hard for them.$"

SSAnne_2F_Corridor_Text_RivalDefeat::
    .string "Humph!\p"
    .string "At least you're raising your\n"
    .string "Pokémon!$"

SSAnne_2F_Corridor_Text_RivalPostBattle::
    .string "{RIVAL}: I heard there was a\n"
    .string "Cut Master on board.\p"
    .string "But he was just a seasick old man!\p"
    .string "Cut itself is really useful.\n"
    .string "Yup, it'll be handy.\p"
    .string "You should go see him, too.\n"
    .string "Smell ya!$"

SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner::
    .string "This ship, she is a luxury liner for\n"
    .string "Trainers of the world!\p"
    .string "At every port, we hold parties with\n"
    .string "invited Trainers.$"