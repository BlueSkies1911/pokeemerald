.equ FOUND_FIRST_SWITCH, FLAG_TEMP_1
.equ SWITCH1_ID,         VAR_0x8004
.equ SWITCH2_ID,         VAR_0x8005
.equ TRASH_CAN_ID,       VAR_0x8008

VermilionCity_Gym_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
    map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
    .byte 0

VermilionCity_Gym_OnLoad:
    call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
    call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
    end

VermilionCity_Gym_EventScript_SetOneBeamOff::
    setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
    setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
    setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
    setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
    setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
    setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
    setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
    setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
    setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
    setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
    return

VermilionCity_Gym_EventScript_SetBeamsOff::
    setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
    setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
    setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
    setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
    setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
    setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
    setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
    setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
    setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
    setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
    return

VermilionCity_Gym_OnTransition:
    call VermilionCity_Gym_EventScript_InitTrashCans
    end

VermilionCity_Gym_EventScript_InitTrashCans::
    goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, Common_EventScript_NopReturn
    special SetVermilionTrashCans
    copyvar VAR_TEMP_0, SWITCH1_ID
    copyvar VAR_TEMP_1, SWITCH2_ID
    return

VermilionCity_Gym_EventScript_TrashCan1::
    lockall
    setvar TRASH_CAN_ID, 1
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan2::
    lockall
    setvar TRASH_CAN_ID, 2
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan3::
    lockall
    setvar TRASH_CAN_ID, 3
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan4::
    lockall
    setvar TRASH_CAN_ID, 4
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan5::
    lockall
    setvar TRASH_CAN_ID, 5
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan6::
    lockall
    setvar TRASH_CAN_ID, 6
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan7::
    lockall
    setvar TRASH_CAN_ID, 7
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan8::
    lockall
    setvar TRASH_CAN_ID, 8
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan9::
    lockall
    setvar TRASH_CAN_ID, 9
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan10::
    lockall
    setvar TRASH_CAN_ID, 10
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan11::
    lockall
    setvar TRASH_CAN_ID, 11
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan12::
    lockall
    setvar TRASH_CAN_ID, 12
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan13::
    lockall
    setvar TRASH_CAN_ID, 13
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan14::
    lockall
    setvar TRASH_CAN_ID, 14
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan15::
    lockall
    setvar TRASH_CAN_ID, 15
    goto VermilionCity_Gym_EventScript_TrashCan
    end

VermilionCity_Gym_EventScript_TrashCan::
    copyvar SWITCH1_ID, VAR_TEMP_0
    copyvar SWITCH2_ID, VAR_TEMP_1
    goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
    goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
    compare SWITCH1_ID, TRASH_CAN_ID
    goto_if_eq VermilionCity_Gym_EventScript_FoundSwitchOne
    msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere, MSGBOX_DEFAULT
    releaseall
    end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
    msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere, MSGBOX_DEFAULT
    releaseall
    end

VermilionCity_Gym_EventScript_TrySwitchTwo::
    compare SWITCH2_ID, TRASH_CAN_ID
    goto_if_eq VermilionCity_Gym_EventScript_FoundSwitchTwo
    msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset, MSGBOX_DEFAULT
    clearflag FOUND_FIRST_SWITCH
    special SetVermilionTrashCans
    copyvar VAR_TEMP_0, SWITCH1_ID
    copyvar VAR_TEMP_1, SWITCH2_ID
    call VermilionCity_Gym_EventScript_SetBeamsOn
    special DrawWholeMapView
    releaseall
    end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
    msgbox VermilionCity_Gym_Text_SecondLockOpened, MSGBOX_DEFAULT
    closemessage
    call VermilionCity_Gym_EventScript_SetBeamsOff
    special DrawWholeMapView
    playse SE_UNLOCK
    waitse
    setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
    releaseall
    end

VermilionCity_Gym_EventScript_SetBeamsOn::
    setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
    setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
    setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
    setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
    setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
    setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
    setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
    setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
    setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
    setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
    return

VermilionCity_Gym_EventScript_FoundSwitchOne::
    msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened, MSGBOX_DEFAULT
    playse SE_PIN
    waitse
    call VermilionCity_Gym_EventScript_SetOneBeamOff
    special DrawWholeMapView
    setflag FOUND_FIRST_SWITCH
    releaseall
    end

VermilionCity_Gym_EventScript_LtSurge::
    trainerbattle_single TRAINER_LEADER_LT_SURGE, VermilionCity_Gym_Text_LtSurgeIntro, VermilionCity_Gym_Text_LtSurgeDefeat, VermilionCity_Gym_EventScript_DefeatedLtSurge, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_Gym_EventScript_LtSurgeRematch
    goto_if_unset FLAG_GOT_TM34_FROM_SURGE, VermilionCity_Gym_EventScript_GiveTM34
    msgbox VermilionCity_Gym_Text_LtSurgePostBattle, MSGBOX_DEFAULT
    release
    end

VermilionCity_Gym_EventScript_DefeatedLtSurge::
    message VermilionCity_Gym_Text_ReceivedThunderBadge
    waitmessage
    call Common_EventScript_PlayGymBadgeFanfare
    msgbox VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis, MSGBOX_DEFAULT
    call_if_unset FLAG_GOT_HM05, VermilionCity_Gym_EventScript_ShowOaksAide
    setflag FLAG_DEFEATED_LT_SURGE
    setflag FLAG_BADGE03_GET
    setvar VAR_0x8008, 3
    call Common_EventScript_SetGymTrainers
    goto VermilionCity_Gym_EventScript_GiveTM34
    end

VermilionCity_Gym_EventScript_ShowOaksAide::
    clearflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
    return

VermilionCity_Gym_EventScript_GiveTM34::
    checkitemspace ITEM_TM34, 1
    compare VAR_RESULT, FALSE
    goto_if_eq VermilionCity_Gym_EventScript_NoRoomForTM34
    giveitem_msg VermilionCity_Gym_Text_ReceivedTM34FromLtSurge, ITEM_TM34
    setflag FLAG_GOT_TM34_FROM_SURGE
    msgbox VermilionCity_Gym_Text_ExplainTM34, MSGBOX_DEFAULT
    closemessage
    delay 30
    playfanfare MUS_REGISTER_MATCH_CALL
    msgbox VermilionCity_Gym_Text_RegisteredLtSurge, MSGBOX_DEFAULT
    waitfanfare
    closemessage
    delay 30
    setflag FLAG_ENABLE_LT_SURGE_MATCH_CALL
    release
    end

VermilionCity_Gym_EventScript_NoRoomForTM34::
    msgbox VermilionCity_Gym_Text_MakeRoomInYourBag, MSGBOX_DEFAULT
    release
    end

VermilionCity_Gym_EventScript_LtSurgeRematch::
	trainerbattle_rematch_double TRAINER_LEADER_LT_SURGE, VermilionCity_Gym_Text_LtSurgePreRematch, VermilionCity_Gym_Text_LtSurgeRematchDefeat, VermilionCity_Gym_Text_LtSurgeRematchNeedTwoMons
	msgbox VermilionCity_Gym_Text_LtSurgePostRematch, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Dwayne::
    trainerbattle_single TRAINER_SAILOR_DWAYNE, VermilionCity_Gym_Text_DwayneIntro, VermilionCity_Gym_Text_DwayneDefeat
    msgbox VermilionCity_Gym_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
    end

VermilionCity_Gym_EventScript_Baily::
    trainerbattle_single TRAINER_ENGINEER_BAILY, VermilionCity_Gym_Text_BailyIntro, VermilionCity_Gym_Text_BailyDefeat
    msgbox VermilionCity_Gym_Text_BailyPostBattle, MSGBOX_AUTOCLOSE
    end

VermilionCity_Gym_EventScript_Tucker::
    trainerbattle_single TRAINER_GENTLEMAN_TUCKER, VermilionCity_Gym_Text_TuckerIntro, VermilionCity_Gym_Text_TuckerDefeat
    msgbox VermilionCity_Gym_Text_TuckerPostBattle, MSGBOX_AUTOCLOSE
    end

VermilionCity_Gym_EventScript_GymGuy::
    lock
    faceplayer
    goto_if_set FLAG_DEFEATED_LT_SURGE, VermilionCity_Gym_EventScript_GymGuyPostVictory
    msgbox VermilionCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
    release
    end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
    msgbox VermilionCity_Gym_Text_GymGuyPostVictory, MSGBOX_DEFAULT
    release
    end

VermilionCity_Gym_EventScript_GymStatue::
    lockall
    goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
    msgbox VermilionCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
    releaseall
    end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
    msgbox VermilionCity_Gym_Text_GymStatuePlayerWon, MSGBOX_DEFAULT
    releaseall
    end

VermilionCity_Gym_Text_NopeOnlyTrashHere::
    .string "Nope!\n"
    .string "There's only trash here.$"

VermilionCity_Gym_Text_SecondLockOpened::
    .string "The second electric lock opened!\n"
    .string "The motorised door opened!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
    .string "Nope!\n"
    .string "There's only trash here.\p"
    .string "Hey!\n"
    .string "The electric locks were reset!$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
    .string "Hey! There's a switch under the\n"
    .string "trash! Turn it on!\p"
    .string "The first electric lock opened!$"
    
VermilionCity_Gym_Text_LtSurgeIntro::
    .string "Hey, kid! What do you think you're\n"
    .string "doing here?\p"
    .string "You won't live long in combat!\n"
    .string "Not with your puny power!\p"
    .string "I tell you, kid, electric Pokémon\n"
    .string "saved me during the war!\p"
    .string "They zapped my enemies into\n"
    .string "paralysis!\p"
    .string "The same as I'll do to you!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

VermilionCity_Gym_Text_LtSurgeDefeat::
    .string "Now that's a shocker!\p"
    .string "You're the real deal, kid!\p"
    .string "Fine, then, take the ThunderBadge!$"
    
VermilionCity_Gym_Text_ReceivedThunderBadge::
    .string "{PLAYER} received the ThunderBadge\n"
    .string "from Lt. Surge!$"

VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis::
    .string "The ThunderBadge cranks up your\n"
    .string "Pokémon's Speed!\p"
    .string "It also lets your Pokémon smash\n"
    .string "rocks lightning-fast anytime, kid!\p"
    .string "You're special, kid!\n"
    .string "Take this!$"

VermilionCity_Gym_Text_MakeRoomInYourBag::
    .string "Yo, kid, make room in your bag!$"

VermilionCity_Gym_Text_ReceivedTM34FromLtSurge::
    .string "{PLAYER} received TM34\n"
    .string "from Lt. Surge.$"

VermilionCity_Gym_Text_ExplainTM34::
    .string "TM34 contains Shock Wave!\p"
    .string "Teach it to an Electric Pokémon!$"

VermilionCity_Gym_Text_LtSurgePostBattle::
    .string "A little word of advice, kid!\p"
    .string "Electricity is sure powerful!\p"
    .string "But, it's useless against\n"
    .string "Ground-type Pokémon!$"

VermilionCity_Gym_Text_RegisteredLtSurge::
    .string "Registered Gym Leader Lt. Surge\n"
    .string "in the Pokénav.$"

VermilionCity_Gym_Text_LtSurgePreRematch:
	.string "Lt. Surge: Hey kid! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my Pokémon!\p"
	.string "I'll paralyse your Pokémon\n"
    .string "into submission!\p"
	.string "Don't say I didn't warn you!$"

VermilionCity_Gym_Text_LtSurgeRematchDefeat:
    .string "I'm shocked!\p"
    .string "You're still the real deal, kid!$"

VermilionCity_Gym_Text_LtSurgePostRematch:
	.string "Lt Surge: You're strong kid!\p"
	.string "I would have been honoured to fight\n"
	.string "alongside you during the war!\p"
	.string "I'll need to go back to my\n"
    .string "military training to get stronger.\p"
	.string "So, come back again sometime,\n"
	.string "won't you?$"

VermilionCity_Gym_Text_LtSurgeRematchNeedTwoMons:
	.string "Lt. Surge: Hey kid! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my Pokémon!\p"
	.string "Oops! Wait!\n"
	.string "You've only one Pokémon with you!\p"
	.string "Come see me with two or more\n"
	.string "Pokémon, all right?$"

VermilionCity_Gym_Text_TuckerIntro::
    .string "When I was in the Army, Lt. Surge\n"
    .string "was my strict Commanding Officer.\p"
    .string "He was a hard taskmaster.$"

VermilionCity_Gym_Text_TuckerDefeat::
    .string "Stop!\n"
    .string "You're very good!$"

VermilionCity_Gym_Text_TuckerPostBattle::
    .string "It's not easy opening that door.\p"
    .string "Lt. Surge was always famous for\n"
    .string "his cautious nature in the Army.$"

VermilionCity_Gym_Text_BailyIntro::
    .string "I'm a lightweight, but I'm good\n"
    .string "with electricity!\p"
    .string "That's why I joined this Gym.$"

VermilionCity_Gym_Text_BailyDefeat::
    .string "Fried!$"

VermilionCity_Gym_Text_BailyPostBattle::
    .string "Okay, I'll talk!\p"
    .string "Lt. Surge said he hid door\n"
    .string "switches inside something.$"

VermilionCity_Gym_Text_DwayneIntro::
    .string "This is no place for kids!\n"
    .string "Not even if you're good!$"

VermilionCity_Gym_Text_DwayneDefeat::
    .string "Wow!\n"
    .string "Surprised me!$"

VermilionCity_Gym_Text_DwaynePostBattle::
    .string "Lt. Surge installed the traps in\n"
    .string "the Gym himself.\p"
    .string "He set up double locks everywhere.\n"
    .string "Let me give you a hint.\p"
    .string "When you open the first lock, the\n"
    .string "second lock is right next to it.$"

VermilionCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Lt. Surge has a nickname.\p"
    .string "People refer to him as the\n"
    .string "Lightning American!\p"
    .string "He's an expert on electric\n"
    .string "Pokémon.\p"
    .string "Bird/Water-type Pokémon match\n"
    .string "poorly against the Electric type.\p"
    .string "Beware of paralysis, too.\p"
    .string "Lt. Surge is very cautious.\p"
    .string "He's locked himself in, so it won't\n"
    .string "be easy getting to him.$"

VermilionCity_Gym_Text_GymGuyPostVictory::
    .string "Whew!\n"
    .string "That match was electric!$"

VermilionCity_Gym_Text_GymStatue::
    .string "Vermilion Pokémon Gym\n"
    .string "Leader: Lt. Surge\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

VermilionCity_Gym_Text_GymStatuePlayerWon::
    .string "Vermilion Pokémon Gym\n"
    .string "Leader: Lt. Surge\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
