.equ LOCALID_GRUNT1, 5
.equ LOCALID_GRUNT2, 1
.equ LOCALID_GRUNT3, 2
.equ LOCALID_ADMIN1, 3
.equ LOCALID_ADMIN2, 4

.equ PLAYER_X_POS, VAR_0x8004
.equ PLAYER_Y_POS, VAR_0x8005

RocketWarehouse_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, RocketWarehouse_OnLoad
    map_script MAP_SCRIPT_ON_TRANSITION, RocketWarehouse_OnTransition
    .byte 0

RocketWarehouse_OnTransition:
    setflag FLAG_WORLD_MAP_ROCKET_WAREHOUSE
    end

RocketWarehouse_OnLoad:
    call_if_defeated TRAINER_TEAM_ROCKET_ADMIN, RocketWarehouse_EventScript_SetArrowsForReEntry
    end

RocketWarehouse_EventScript_SetArrowsForReEntry::
    setmetatile 26, 20, METATILE_SilphCo_Arrow_Up, 0
    setmetatile 27, 20, METATILE_SilphCo_Arrow_Up, 0
    return

RocketWarehouse_EventScript_Cage::
    lockall
    goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, RocketWarehouse_EventScript_CageUnlocked
    msgbox RocketWarehouse_Text_ManyMonsLockedInPen, MSGBOX_DEFAULT
    releaseall
    end

RocketWarehouse_EventScript_CageUnlocked::
    msgbox RocketWarehouse_Text_PenUnlockedMonsFled, MSGBOX_DEFAULT
    releaseall
    end

RocketWarehouse_EventScript_Computer::
    msgbox RocketWarehouse_Text_ReportWithGraphsAndText, MSGBOX_SIGN
    end

RocketWarehouse_EventScript_Admin2Trigger::
    lockall
    applymovement LOCALID_ADMIN2, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
    releaseall
    end

RocketWarehouse_EventScript_Gideon::
    trainerbattle_single TRAINER_SCIENTIST_GIDEON, RocketWarehouse_Text_GideonIntro, RocketWarehouse_Text_GideonDefeat, RocketWarehouse_EventScript_DefeatedGideon
    goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, RocketWarehouse_EventScript_MentionGiovannisKid
    msgbox RocketWarehouse_Text_GetLostLeaveMeBe, MSGBOX_AUTOCLOSE
    end

RocketWarehouse_EventScript_MentionGiovannisKid::
    msgbox RocketWarehouse_Text_GiovannisKidHasRedHair, MSGBOX_AUTOCLOSE
    end

RocketWarehouse_EventScript_DefeatedGideon::
    msgbox RocketWarehouse_Text_GideonPostBattle, MSGBOX_DEFAULT
    setflag FLAG_RECOVERED_SAPPHIRE
    giveitem ITEM_SAPPHIRE
    release
    end

RocketWarehouse_EventScript_Grunt2::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_47, RocketWarehouse_Text_Grunt2Intro, RocketWarehouse_Text_Grunt2Defeat
    msgbox RocketWarehouse_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
    end

RocketWarehouse_EventScript_Grunt3::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_48, RocketWarehouse_Text_Grunt3Intro, RocketWarehouse_Text_Grunt3Defeat
    msgbox RocketWarehouse_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
    end

RocketWarehouse_EventScript_Admin2::
    trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN_2, RocketWarehouse_Text_Admin2Intro, RocketWarehouse_Text_Admin2Defeat, RocketWarehouse_EventScript_DefeatedAdmin2
    msgbox RocketWarehouse_Text_Admin2PostBattle, MSGBOX_AUTOCLOSE
    end

RocketWarehouse_EventScript_DefeatedAdmin2::
    getplayerxy PLAYER_X_POS, PLAYER_Y_POS
    compare PLAYER_X_POS, 24
    call_if_le RocketWarehouse_EventScript_PlayerFaceAdmin2
    msgbox RocketWarehouse_Text_Admin2PostBattle, MSGBOX_DEFAULT
    closemessage
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_GRUNT2
    removeobject LOCALID_GRUNT3
    removeobject LOCALID_ADMIN2
    removeobject LOCALID_ADMIN1
    setflag FLAG_HIDE_FIVE_ISLAND_ROCKETS
    fadescreen FADE_FROM_BLACK
    setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
    setflag FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE
    release
    end

RocketWarehouse_EventScript_PlayerFaceAdmin2::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    return

RocketWarehouse_EventScript_Grunt1::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_42, RocketWarehouse_Text_Grunt1Intro, RocketWarehouse_Text_Grunt1Defeat
    msgbox RocketWarehouse_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
    end

RocketWarehouse_EventScript_Admin1::
    trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN, RocketWarehouse_Text_Admin1Intro, RocketWarehouse_Text_Admin1Defeat, RocketWarehouse_EventScript_DefeatedAdmin1
    msgbox RocketWarehouse_Text_MadeItSoYouCanComeBackThrough, MSGBOX_AUTOCLOSE
    end

RocketWarehouse_EventScript_DefeatedAdmin1::
    getplayerxy PLAYER_X_POS, PLAYER_Y_POS
    specialvar VAR_RESULT, GetPlayerFacingDirection
    compare VAR_RESULT, DIR_NORTH
    call_if_eq RocketWarehouse_EventScript_PlayerFaceAdmin1
    msgbox RocketWarehouse_Text_Admin1PostBattle, MSGBOX_DEFAULT
    closemessage
    compare PLAYER_X_POS, 24
    call_if_le RocketWarehouse_EventScript_AdminWalkToSwitchFar
    compare PLAYER_X_POS, 25
    call_if_eq RocketWarehouse_EventScript_AdminWalkToSwitch
    compare PLAYER_X_POS, 26
    call_if_eq RocketWarehouse_EventScript_AdminFaceSwitch
    compare PLAYER_X_POS, 27
    call_if_eq RocketWarehouse_EventScript_AdminFaceSwitch
    playse SE_PIN
    call RocketWarehouse_EventScript_SetArrowsForReEntry
    special DrawWholeMapView
    waitse
    compare PLAYER_X_POS, 24
    call_if_le RocketWarehouse_EventScript_AdminFacePlayerLeft
    compare PLAYER_X_POS, 25
    call_if_eq RocketWarehouse_EventScript_AdminFacePlayerLeft
    compare PLAYER_X_POS, 26
    call_if_eq RocketWarehouse_EventScript_AdminFacePlayerLeft
    compare PLAYER_X_POS, 27
    call_if_eq RocketWarehouse_EventScript_AdminFacePlayerDown
    msgbox RocketWarehouse_Text_MadeItSoYouCanComeBackThrough, MSGBOX_DEFAULT
    release
    end

RocketWarehouse_EventScript_PlayerFaceAdmin1::
    compare PLAYER_X_POS, 27
    goto_if_eq Common_EventScript_NopReturn
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    return

RocketWarehouse_EventScript_AdminWalkToSwitchFar::
    applymovement LOCALID_ADMIN1, RocketWarehouse_Movement_AdminWalkToSwitchFar
    waitmovement 0
    return

RocketWarehouse_EventScript_AdminWalkToSwitch::
    applymovement LOCALID_ADMIN1, RocketWarehouse_Movement_AdminWalkToSwitch
    waitmovement 0
    return

RocketWarehouse_EventScript_AdminFaceSwitch::
    applymovement LOCALID_ADMIN1, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

RocketWarehouse_EventScript_AdminFacePlayerLeft::
    applymovement LOCALID_ADMIN1, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    return

RocketWarehouse_EventScript_AdminFacePlayerDown::
    applymovement LOCALID_ADMIN1, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

RocketWarehouse_Movement_AdminWalkToSwitchFar::
    walk_right
    walk_right
    walk_in_place_faster_up
    step_end

RocketWarehouse_Movement_AdminWalkToSwitch::
    walk_right
    walk_in_place_faster_up
    step_end

RocketWarehouse_Text_ManyMonsLockedInPen::
    .string "There are many Pokémon locked\n"
    .string "away in the pen…$"

RocketWarehouse_Text_PenUnlockedMonsFled::
    .string "The pen door is unlocked.\n"
    .string "The Pokémon appear to have fled.$"

RocketWarehouse_Text_Grunt2Intro::
    .string "Did you come here knowing it's\n"
    .string "Team Rocket's Warehouse?$"

RocketWarehouse_Text_Grunt2Defeat::
    .string "What do you think you're doing?!$"

RocketWarehouse_Text_Grunt2PostBattle::
    .string "Team Rocket broke up?\n"
    .string "What planet are you from?$"

RocketWarehouse_Text_Grunt1Intro::
    .string "Oh, now your Pokémon look strong.\n"
    .string "You're willing to sell them?\p"
    .string "Oh?\n"
    .string "You wanted to battle?$"

RocketWarehouse_Text_Grunt1Defeat::
    .string "Oh, but…\n"
    .string "Too much!$"

RocketWarehouse_Text_Grunt1PostBattle::
    .string "We can give you a great price.\n"
    .string "Sell us your Pokémon!$"

RocketWarehouse_Text_Grunt3Intro::
    .string "I got word about you from the\n"
    .string "others.\p"
    .string "But there's no way a kid like you'd\n"
    .string "know our Boss Giovanni!$"

RocketWarehouse_Text_Grunt3Defeat::
    .string "Don't…you…dare…laugh…$"

RocketWarehouse_Text_Grunt3PostBattle::
    .string "Don't mess in the doings of adults,\n"
    .string "you jumped-up pip-squeak!$"

RocketWarehouse_Text_Admin1Intro::
    .string "I don't know or care if what I'm\n"
    .string "doing is right or wrong…\p"
    .string "I just put my faith in Giovanni\n"
    .string "and do as I am told.$"

RocketWarehouse_Text_Admin1Defeat::
    .string "I…\n"
    .string "I'm shattered…$"

RocketWarehouse_Text_Admin1PostBattle::
    .string "You're doing things according to\n"
    .string "your beliefs and morals.\p"
    .string "I understand now…$"

RocketWarehouse_Text_MadeItSoYouCanComeBackThrough::
    .string "I've made it so you can come back\n"
    .string "in through there.\p"
    .string "Why don't you go get rested and\n"
    .string "refreshed for what lies ahead?\p"
    .string "The Admin after me outranks me\n"
    .string "thoroughly as a Trainer.\p"
    .string "You'd better steel yourself for one\n"
    .string "harsh challenge.$"

RocketWarehouse_Text_Admin2Intro::
    .string "That's quite enough of you \n"
    .string "playing the hero, kid.\p"
    .string "Spreading lies about how Team\n"
    .string "Rocket has disbanded…\p"
    .string "It's such an obvious attempt to\n"
    .string "cause confusion in our ranks.\p"
    .string "Fortunately, we're not so ignorant\n"
    .string "to fall for the lies of a child!\p"
    .string "And now, I'll show you how scary\n"
    .string "an angry adult can be!$"

RocketWarehouse_Text_Admin2Defeat::
    .string "Urgh…\n"
    .string "You were too strong…\p"
    .string "…\n"
    .string "Th-that's Giovanni's badge!\p"
    .string "So it's true?\n"
    .string "Team Rocket really has disbanded?$"

RocketWarehouse_Text_Admin2PostBattle::
    .string "We will abandon this Warehouse…\p"
    .string "But don't think this is over.\n"
    .string "I won't let this be the end.\p"
    .string "I will find Giovanni.\n"
    .string "And I will resurrect Team Rocket!\l"
    .string "I will…\p"
    .string "Until then, farewell!$"

RocketWarehouse_Text_ReportWithGraphsAndText::
    .string "A report with graphs and text is on\n"
    .string "the PC monitor.\p"
    .string "“The Influence of Magnetic Waves\n"
    .string "on Pokémon Evolution”…\p"
    .string "… … … … … …\p"
    .string "It's too difficult to understand…$"

RocketWarehouse_Text_GideonIntro::
    .string "I almost managed to sell the\n"
    .string "Sapphire for huge money…\p"
    .string "Then, you just had to come along\n"
    .string "and blow the whole deal apart!\p"
    .string "Fufu… Fufufufu…\n"
    .string "There's no forgiveness for you!$"

RocketWarehouse_Text_GideonDefeat::
    .string "Gah! Darn!\n"
    .string "Darn! Darn!$"

RocketWarehouse_Text_GideonPostBattle::
    .string "If I can't sell it, it's worthless!\n"
    .string "Go ahead, take it!$"

RocketWarehouse_Text_GetLostLeaveMeBe::
    .string "What do you want now?\n"
    .string "Go on, get lost, leave me be.$"

RocketWarehouse_Text_GiovannisKidHasRedHair::
    .string "What, you again?\p"
    .string "You… You're not Giovanni's kid,\n"
    .string "are you?\p"
    .string "No, that can't be right!\n"
    .string "Giovanni's kid has red hair.\p"
    .string "You don't have any reasons for\n"
    .string "bugging me. Leave me alone!$"
