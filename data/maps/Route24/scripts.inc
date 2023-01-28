.equ LOCALID_ROCKET, 1

Route24_MapScripts::
    .byte 0

Route24_EventScript_RocketTriggerLeft::
    lockall
    setvar VAR_TEMP_1, 0
    goto Route24_EventScript_RocketTrigger
    end

Route24_EventScript_RocketTriggerRight::
    lockall
    setvar VAR_TEMP_1, 1
    goto Route24_EventScript_RocketTrigger
    end

Route24_EventScript_RocketTrigger::
    compare VAR_TEMP_1, 0
    call_if_eq Route24_EventScript_RocketApproachPlayer
    compare VAR_TEMP_1, 1
    call_if_eq Route24_EventScript_RocketMotionToPlayer
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    msgbox Route24_Text_JustEarnedFabulousPrize, MSGBOX_DEFAULT
    checkitemspace ITEM_NUGGET, 1
    compare VAR_RESULT, FALSE
    goto_if_eq Route24_EventScript_NoRoomForNuggetTrigger
    call Route24_EventScript_BattleRocket
    releaseall
    end

Route24_EventScript_RocketApproachPlayer::
    applymovement LOCALID_ROCKET, Route24_Movement_RocketApproachPlayer
    waitmovement 0
    return

Route24_Movement_RocketApproachPlayer::
    walk_left
    step_end

Route24_EventScript_RocketMotionToPlayer::
    applymovement LOCALID_ROCKET, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    return

Route24_EventScript_NoRoomForNuggetTrigger::
    msgbox Route24_Text_YouDontHaveAnyRoom, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_WalkDown
    waitmovement 0
    compare VAR_TEMP_1, 0
    call_if_eq Route24_EventScript_RocketWalkBackToPos
    release
    end

Route24_Movement_WalkDown::
    walk_down
    step_end

Route24_EventScript_RocketWalkBackToPos::
    applymovement LOCALID_ROCKET, Route24_Movement_RocketWalkBackToPos
    waitmovement 0
    return

Route24_Movement_RocketWalkBackToPos::
    walk_right
    walk_in_place_faster_left
    step_end

Route24_EventScript_Rocket::
    lock
    faceplayer
    compare VAR_MAP_SCENE_ROUTE24, 1
    goto_if_eq Route24_EventScript_RocketPostBattle
    msgbox Route24_Text_JustEarnedFabulousPrize
    checkitemspace ITEM_NUGGET, 1
    compare VAR_RESULT, FALSE
    goto_if_eq Route24_EventScript_NoRoomForNugget
    call Route24_EventScript_BattleRocket
    release
    end

Route24_EventScript_RocketPostBattle::
    msgbox Route24_Text_YoudBecomeTopRocketLeader, MSGBOX_DEFAULT
    release
    end

Route24_EventScript_NoRoomForNugget::
    msgbox Route24_Text_YouDontHaveAnyRoom, MSGBOX_DEFAULT
    release
    end

Route24_EventScript_BattleRocket::
    giveitem_msg Route24_Text_ReceivedNuggetFromMysteryTrainer, ITEM_NUGGET
    message Route24_Text_JoinTeamRocket
    waitmessage
    playbgm MUS_RG_ENCOUNTER_ROCKET, 0
    waitbuttonpress
    setvar VAR_LAST_TALKED, LOCALID_ROCKET
    trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketDefeat
    msgbox Route24_Text_YoudBecomeTopRocketLeader, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_ROUTE24, 1
    return

Route24_EventScript_Timmy::
    trainerbattle_single TRAINER_YOUNGSTER_TIMMY, Route24_Text_TimmyIntro, Route24_Text_TimmyDefeat, Route24_EventScript_RegisterTimmy
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route24_EventScript_TimmyRematch
    msgbox Route24_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
    end

Route24_EventScript_RegisterTimmy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route24_Text_TimmyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_YOUNGSTER_TIMMY
	release
	end

Route24_EventScript_TimmyRematch::
    trainerbattle_rematch TRAINER_YOUNGSTER_TIMMY, Route24_Text_TimmyRematchIntro, Route24_Text_TimmyDefeat
    msgbox Route24_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
    end

Route24_EventScript_Cale::
    trainerbattle_single TRAINER_BUG_CATCHER_CALE, Route24_Text_CaleIntro, Route24_Text_CaleDefeat
    msgbox Route24_Text_CalePostBattle, MSGBOX_AUTOCLOSE
    end

Route24_EventScript_Reli::
    trainerbattle_single TRAINER_LASS_RELI, Route24_Text_ReliIntro, Route24_Text_ReliDefeat, Route24_EventScript_RegisterReli
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route24_EventScript_ReliRematch
    msgbox Route24_Text_ReliPostBattle, MSGBOX_AUTOCLOSE
    end

Route24_EventScript_RegisterReli::
	msgbox Route24_Text_ReliRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LASS_RELI
	release
	end

Route24_EventScript_ReliRematch::
    trainerbattle_rematch TRAINER_LASS_RELI, Route24_Text_ReliRematchIntro, Route24_Text_ReliDefeat
    msgbox Route24_Text_ReliPostBattle, MSGBOX_AUTOCLOSE
    end

Route24_EventScript_Ali::
    trainerbattle_single TRAINER_LASS_ALI, Route24_Text_AliIntro, Route24_Text_AliDefeat
    msgbox Route24_Text_AliPostBattle, MSGBOX_AUTOCLOSE
    end

Route24_EventScript_Shane::
    trainerbattle_single TRAINER_CAMPER_SHANE, Route24_Text_ShaneIntro, Route24_Text_ShaneDefeat
    msgbox Route24_Text_ShanePostBattle, MSGBOX_AUTOCLOSE
    end

Route24_EventScript_Ethan::
    trainerbattle_single TRAINER_CAMPER_ETHAN, Route24_Text_EthanIntro, Route24_Text_EthanDefeat
    msgbox Route24_Text_EthanPostBattle, MSGBOX_AUTOCLOSE
    end

Route24_Text_JustEarnedFabulousPrize::
    .string "Congratulations! You beat our\n"
    .string "five contest Trainers!\p"
    .string "You just earned a fabulous prize!$"

Route24_Text_YouDontHaveAnyRoom::
    .string "You don't have any room!$"

Route24_Text_YoudBecomeTopRocketLeader::
    .string "With your ability, you'd become\n"
    .string "a top leader in Team Rocket.\p"
    .string "Come on, think of the opportunity!\n"
    .string "Don't let this chance go to waste.$"

Route24_Text_ReceivedNuggetFromMysteryTrainer::
    .string "{PLAYER} received a Nugget\n"
    .string "from the Mystery Trainer!$"

Route24_Text_JoinTeamRocket::
    .string "By the way, how would you like to\n"
    .string "join Team Rocket?\p"
    .string "We're a group of professional\n"
    .string "criminals specialising in Pokémon!\p"
    .string "Want to join?\p"
    .string "Are you sure?\p"
    .string "Come on, join us!\p"
    .string "I'm telling you to join!\p"
    .string "…Okay, you need convincing!\p"
    .string "I'll make you an offer you can't\n"
    .string "refuse!$"

Route24_Text_RocketDefeat::
    .string "Arrgh!\n"
    .string "You are good!$"
