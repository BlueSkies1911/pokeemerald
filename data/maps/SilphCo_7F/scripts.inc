.set LOCALID_RIVAL,     1
.set LOCALID_WORKER_M2, 8

SilphCo_7F_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
    map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad:
    call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
    call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
    call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
    end

SilphCo_7F_OnTransition:
    compare VAR_MAP_SCENE_SILPH_CO_11F, 1
    call_if_ge SilphCo_7F_EventScript_SetObjRocketsGone
    end

SilphCo_7F_EventScript_SetObjRocketsGone::
    setobjectmovementtype LOCALID_WORKER_M2, MOVEMENT_TYPE_FACE_UP
    return

SilphCo_7F_EventScript_RivalTriggerTop::
    lockall
    setvar VAR_TEMP_1, 0
    goto SilphCo_7F_EventScript_RivalScene
    end

SilphCo_7F_EventScript_RivalTriggerBottom::
    lockall
    setvar VAR_TEMP_1, 1
    goto SilphCo_7F_EventScript_RivalScene
    end

SilphCo_7F_EventScript_RivalScene::
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox SilphCo_7F_Text_RivalWhatKeptYou, MSGBOX_DEFAULT
    compare VAR_TEMP_1, 0
    call_if_eq SilphCo_7F_EventScript_RivalApproachTop
    compare VAR_TEMP_1, 1
    call_if_eq SilphCo_7F_EventScript_RivalApproachBottom
    msgbox SilphCo_7F_Text_RivalIntro, MSGBOX_DEFAULT
    setvar VAR_LAST_TALKED, LOCALID_RIVAL
    compare VAR_STARTER_MON, 2
    call_if_eq SilphCo_7F_EventScript_RivalSquirtle
    compare VAR_STARTER_MON, 1
    call_if_eq SilphCo_7F_EventScript_RivalBulbasaur
    compare VAR_STARTER_MON, 0
    call_if_eq SilphCo_7F_EventScript_RivalCharmander
    msgbox SilphCo_7F_Text_RivalPostBattle, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_RG_RIVAL_EXIT, 0
    compare VAR_TEMP_1, 0
    call_if_eq SilphCo_7F_EventScript_RivalExitTop
    compare VAR_TEMP_1, 1
    call_if_eq SilphCo_7F_EventScript_RivalExitBottom
    playse SE_WARP_IN
    fadedefaultbgm
    removeobject LOCALID_RIVAL
    waitse
    setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
    releaseall
    end

SilphCo_7F_EventScript_RivalApproachTop::
    closemessage
    applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalApproachTop
    waitmovement 0
    return

SilphCo_7F_EventScript_RivalApproachBottom::
    return

SilphCo_7F_EventScript_RivalSquirtle::
    trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
    return

SilphCo_7F_EventScript_RivalBulbasaur::
    trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
    return

SilphCo_7F_EventScript_RivalCharmander::
    trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
    return

SilphCo_7F_EventScript_RivalExitTop::
    applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalExitTop
    waitmovement 0
    return

SilphCo_7F_EventScript_RivalExitBottom::
    applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalExitBottom
    waitmovement 0
    return

SilphCo_7F_Movement_RivalApproachTop::
    walk_up
    step_end

SilphCo_7F_Movement_RivalExitTop::
    walk_right
    walk_right
    walk_right
    walk_up
    delay_16
    step_end

SilphCo_7F_Movement_RivalExitBottom::
    walk_left
    walk_up
    walk_up
    walk_right
    walk_right
    walk_right
    walk_right
    delay_16
    step_end

SilphCo_7F_EventScript_Joshua::
    trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
    msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
    end

SilphCo_7F_EventScript_Grunt1::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
    msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
    end

SilphCo_7F_EventScript_Grunt2::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
    msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
    end

SilphCo_7F_EventScript_Grunt3::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
    msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
    end

SilphCo_7F_EventScript_LaprasGuy::
    lock
    faceplayer
    goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
    msgbox SilphCo_7F_Text_HaveMonForSavingUs, MSGBOX_DEFAULT
    setvar VAR_TEMP_1, SPECIES_LAPRAS
    givemon SPECIES_LAPRAS, 25, ITEM_NONE
    compare VAR_RESULT, 0
    goto_if_eq SilphCo_7F_EventScript_ReceiveLaprasParty
    compare VAR_RESULT, 1
    goto_if_eq SilphCo_7F_EventScript_ReceiveLaprasPC
    compare VAR_RESULT, 2
    goto_if_eq Common_EventScript_NoMoreRoomForPokemon
    release
    end

SilphCo_7F_EventScript_ReceiveLaprasParty::
    playfanfare MUS_LEVEL_UP
    message SilphCo_7F_Text_ObtainedLaprasFromEmployee
    waitmessage
    waitfanfare
    bufferspeciesname 0, SPECIES_LAPRAS
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SilphCo_7F_EventScript_EndReceiveLapras
    call Common_EventScript_GetGiftMonPartySlot
    call Common_EventScript_NameReceivedPartyMon
    goto SilphCo_7F_EventScript_EndReceiveLapras
    end

SilphCo_7F_EventScript_ReceiveLaprasPC::
    playfanfare MUS_LEVEL_UP
    message SilphCo_7F_Text_ObtainedLaprasFromEmployee
    waitmessage
    waitfanfare
    bufferspeciesname 0, SPECIES_LAPRAS
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SilphCo_7F_EventScript_LaprasTransferredToPC
    call Common_EventScript_NameReceivedBoxMon
    goto SilphCo_7F_EventScript_LaprasTransferredToPC
    end

SilphCo_7F_EventScript_LaprasTransferredToPC::
    call Common_EventScript_TransferredToPC
    goto SilphCo_7F_EventScript_EndReceiveLapras
    end

SilphCo_7F_EventScript_EndReceiveLapras::
    msgbox SilphCo_7F_Text_ExplainLapras, MSGBOX_DEFAULT
    setflag FLAG_GOT_LAPRAS_FROM_SILPH
    release
    end

SilphCo_7F_EventScript_AlreadyGotLapras::
    msgbox SilphCo_7F_Text_RocketBossWentToBoardroom, MSGBOX_DEFAULT
    release
    end

SilphCo_7F_EventScript_WorkerM1::
    lock
    faceplayer
    compare VAR_MAP_SCENE_SILPH_CO_11F, 1
    goto_if_ge SilphCo_7F_EventScript_WorkerM1RocketsGone
    msgbox SilphCo_7F_Text_RocketsAfterMasterBall, MSGBOX_DEFAULT
    release
    end

SilphCo_7F_EventScript_WorkerM1RocketsGone::
    msgbox SilphCo_7F_Text_CanceledMasterBallProject, MSGBOX_DEFAULT
    release
    end

SilphCo_7F_EventScript_WorkerM2::
    lock
    faceplayer
    compare VAR_MAP_SCENE_SILPH_CO_11F, 1
    goto_if_ge SilphCo_7F_EventScript_WorkerM2RocketsGone
    msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver, MSGBOX_DEFAULT
    release
    end

SilphCo_7F_EventScript_WorkerM2RocketsGone::
    msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket, MSGBOX_DEFAULT
    release
    end

SilphCo_7F_EventScript_WorkerF::
    lock
    faceplayer
    compare VAR_MAP_SCENE_SILPH_CO_11F, 1
    goto_if_ge SilphCo_7F_EventScript_WorkerFRocketsGone
    msgbox SilphCo_7F_Text_ReallyDangerousHere, MSGBOX_DEFAULT
    release
    end

SilphCo_7F_EventScript_WorkerFRocketsGone::
    msgbox SilphCo_7F_Text_ThankYouSoMuch, MSGBOX_DEFAULT
    release
    end

SilphCo_7F_EventScript_FloorSign::
    msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
    end

SilphCo_7F_Text_RivalWhatKeptYou::
    .string "{RIVAL}: What kept you, {PLAYER}?$"

SilphCo_7F_Text_RivalIntro::
    .string "{RIVAL}: Hahaha! I thought you'd\n"
    .string "turn up if I waited here!\p"
    .string "I guess Team Rocket slowed you\n"
    .string "down! Not that I care!\p"
    .string "I saw you in Saffron, so I decided\n"
    .string "to see if you got better!$"

SilphCo_7F_Text_RivalDefeat::
    .string "Oh, man!\n"
    .string "So, you are ready for\l"
    .string "Boss Rocket!$"

SilphCo_7F_Text_RivalPostBattle::
    .string "Well, {PLAYER}!\n"
    .string "I'm moving on up and ahead!\p"
    .string "By checking my Pokédex, I'm\n"
    .string "starting to see what's strong and\l"
    .string "how they evolve!\p"
    .string "Am I a genius or what?\p"
    .string "I'm going to the Pokémon League to\n"
    .string "boot out the Elite Four.\p"
    .string "I'll become the world's most\n"
    .string "powerful Trainer!\p"
    .string "{PLAYER}, well, good luck to you!\n"
    .string "Don't sweat it!\l"
    .string "Smell ya!$"

SilphCo_7F_Text_Grunt3Intro::
    .string "Uh-oh!\n"
    .string "I smell a little mouse!$"

SilphCo_7F_Text_Grunt3Defeat::
    .string "Lights out!$"

SilphCo_7F_Text_Grunt3PostBattle::
    .string "You won't find my boss by just\n"
    .string "scurrying around!$"

SilphCo_7F_Text_JoshuaIntro::
    .string "Heheh!\p"
    .string "You mistook me for a Silph worker?$"

SilphCo_7F_Text_JoshuaDefeat::
    .string "I'm done!$"

SilphCo_7F_Text_JoshuaPostBattle::
    .string "Despite your age, you are a\n"
    .string "skilled Trainer!$"

SilphCo_7F_Text_Grunt1Intro::
    .string "I am one of the four Rocket\n"
    .string "Brothers!$"

SilphCo_7F_Text_Grunt1Defeat::
    .string "Aack!\n"
    .string "Brothers, I lost!$"

SilphCo_7F_Text_Grunt1PostBattle::
    .string "Doesn't matter.\n"
    .string "My brothers will repay the favour!$"

SilphCo_7F_Text_Grunt2Intro::
    .string "A child intruder?\n"
    .string "That must be you!$"

SilphCo_7F_Text_Grunt2Defeat::
    .string "Fine!\n"
    .string "I lost!$"

SilphCo_7F_Text_Grunt2PostBattle::
    .string "Go on home before my Boss gets\n"
    .string "ticked off!$"

SilphCo_7F_Text_HaveMonForSavingUs::
    .string "Oh! Hi! You're not a Rocket!\n"
    .string "You came to save us?\l"
    .string "Why, thank you!\p"
    .string "I want you to have this Pokémon\n"
    .string "for saving us.$"

SilphCo_7F_Text_ObtainedLaprasFromEmployee::
    .string "{PLAYER} obtained a Lapras from\n"
    .string "the Silph employee!$"

SilphCo_7F_Text_ExplainLapras::
    .string "It's a Lapras.\n"
    .string "It's a very intelligent Pokémon.\p"
    .string "We kept it in our lab, but it will\n"
    .string "be much better off with you.\p"
    .string "I think you will be a good Trainer\n"
    .string "for Lapras!\p"
    .string "It's a good swimmer.\n"
    .string "It'll give you a lift across water!$"

SilphCo_7F_Text_RocketBossWentToBoardroom::
    .string "Team Rocket's boss went to the\n"
    .string "boardroom!\p"
    .string "Is our President okay?\n"
    .string "I'm worried.$"

SilphCo_7F_Text_RocketsAfterMasterBall::
    .string "Team Rocket was after the Master\n"
    .string "Ball, which catches any Pokémon.$"

SilphCo_7F_Text_CanceledMasterBallProject::
    .string "We cancelled the Master Ball\n"
    .string "project because of Team Rocket.$"

SilphCo_7F_Text_BadIfTeamRocketTookOver::
    .string "It would be bad if Team Rocket\n"
    .string "took over Silph or our Pokémon.$"

SilphCo_7F_Text_WowYouChasedOffTeamRocket::
    .string "Wow!\p"
    .string "You chased off Team Rocket all by\n"
    .string "yourself?$"

SilphCo_7F_Text_ReallyDangerousHere::
    .string "You!\n"
    .string "It's really dangerous here!\p"
    .string "You came to save me?\n"
    .string "You can't!$"

SilphCo_7F_Text_ThankYouSoMuch::
    .string "Thank you so much!$"

SilphCo_7F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "7F$"
