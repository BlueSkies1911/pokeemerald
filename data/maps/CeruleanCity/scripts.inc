.set LOCALID_POLICEMAN, 1
.set LOCALID_GRUNT,     2
.set LOCALID_SLOWBRO,   5
.set LOCALID_LASS,      6
.set LOCALID_RIVAL,     8
.set LOCALID_WOMAN,     11

CeruleanCity_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

CeruleanCity_OnTransition:
	randomweather
    setflag FLAG_WORLD_MAP_CERULEAN_CITY
	setflag FLAG_SYS_TV_START
    call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
    end

CeruleanCity_EventScript_BlockExits::
    setobjectxyperm LOCALID_POLICEMAN, 30, 12
    setobjectxyperm LOCALID_SLOWBRO, 26, 31
    setobjectxyperm LOCALID_LASS, 27, 31
    return

CeruleanCity_EventScript_RivalTriggerLeft::
    lockall
    setvar VAR_TEMP_1, 0
    goto CeruleanCity_EventScript_Rival
    end

CeruleanCity_EventScript_RivalTriggerMid::
    lockall
    setvar VAR_TEMP_1, 1
    setobjectxyperm LOCALID_RIVAL, 23, 0
    goto CeruleanCity_EventScript_Rival
    end

CeruleanCity_EventScript_RivalTriggerRight::
    lockall
    setvar VAR_TEMP_1, 2
    setobjectxyperm LOCALID_RIVAL, 24, 0
    goto CeruleanCity_EventScript_Rival
    end

CeruleanCity_EventScript_Rival::
    setvar VAR_MAP_SCENE_ROUTE22, 2
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    addobject LOCALID_RIVAL
    applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalEnter
    waitmovement 0
    msgbox CeruleanCity_Text_RivalIntro, MSGBOX_DEFAULT
    setvar VAR_LAST_TALKED, LOCALID_RIVAL
    compare VAR_STARTER_MON, 2
    call_if_eq CeruleanCity_EventScript_RivalSquirtle
    compare VAR_STARTER_MON, 1
    call_if_eq CeruleanCity_EventScript_RivalBulbasaur
    compare VAR_STARTER_MON, 0
    call_if_eq CeruleanCity_EventScript_RivalCharmander
    msgbox CeruleanCity_Text_RivalPostBattle, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_RG_RIVAL_EXIT, 0
    compare VAR_TEMP_1, 0
    call_if_eq CeruleanCity_EventScript_RivalStartExit
    compare VAR_TEMP_1, 1
    call_if_eq CeruleanCity_EventScript_RivalStartExit
    compare VAR_TEMP_1, 2
    call_if_eq CeruleanCity_EventScript_RivalStartExitRight
    playfanfare MUS_REGISTER_MATCH_CALL
    msgbox CeruleanCity_Text_RegisteredRival, MSGBOX_DEFAULT
    waitfanfare
    closemessage
    compare VAR_TEMP_1, 0
    call_if_eq CeruleanCity_EventScript_RivalReturn
    compare VAR_TEMP_1, 1
    call_if_eq CeruleanCity_EventScript_RivalReturn
    compare VAR_TEMP_1, 2
    call_if_eq CeruleanCity_EventScript_RivalReturnRight
    msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
    giveitem ITEM_EXP_SHARE
    msgbox CeruleanCity_Text_ExplainExpShareSmellYa, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalExit
    waitmovement 0
    fadedefaultbgm
    removeobject LOCALID_RIVAL
    setflag FLAG_ENABLE_RIVAL_MATCH_CALL
    setvar VAR_DAISY_CALL_STEP_COUNTER, 0
    setflag FLAG_ENABLE_DAISY_FIRST_CALL
    releaseall
    end

CeruleanCity_Movement_RivalEnter::
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

CeruleanCity_EventScript_RivalSquirtle::
    trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, CeruleanCity_Text_RivalDefeat
    return

CeruleanCity_EventScript_RivalBulbasaur::
    trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, CeruleanCity_Text_RivalDefeat
    return

CeruleanCity_EventScript_RivalCharmander::
    trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, CeruleanCity_Text_RivalDefeat
    return

CeruleanCity_EventScript_RivalStartExit::
    applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
    applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExit
    waitmovement 0
    return

CeruleanCity_Movement_PlayerWatchRivalExit::
    delay_16
    delay_8
    walk_in_place_faster_right
    delay_16
    walk_in_place_faster_down
    step_end

CeruleanCity_Movement_RivalStartExit::
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    delay_16
    step_end

CeruleanCity_EventScript_RivalStartExitRight::
    applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
    applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExitRight
    waitmovement 0
    return

CeruleanCity_Movement_PlayerWatchRivalExitRight::
    delay_16
    delay_8
    walk_in_place_faster_left
    delay_16
    walk_in_place_faster_down
    step_end

CeruleanCity_Movement_RivalStartExitRight::
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    delay_16
    step_end

CeruleanCity_EventScript_RivalReturn::
    applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalReturn
    waitmovement 0
    return

CeruleanCity_Movement_RivalReturn::
    delay_16
    delay_16
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

CeruleanCity_EventScript_RivalReturnRight::
    applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalReturnRight
    waitmovement 0
    return

CeruleanCity_Movement_RivalReturnRight::
    delay_16
    delay_16
    walk_right
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end
    
CeruleanCity_Movement_RivalExit::
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

CeruleanCity_EventScript_RegisterDaisyCall::
    lockall
    pokenavcall CeruleanCity_Text_DaisyPokenavCall
    waitmessage
    delay 30
    playfanfare MUS_REGISTER_MATCH_CALL
    msgbox CeruleanCity_Text_RegisteredDaisy, MSGBOX_DEFAULT
    waitfanfare
    closemessage
    delay 30
    setflag FLAG_ENABLE_DAISY_MATCH_CALL
    clearflag FLAG_ENABLE_DAISY_FIRST_CALL
    setvar VAR_MAP_SCENE_RIVALS_HOUSE, 3
    releaseall
    end
    
CeruleanCity_EventScript_Policeman::
    lock
    faceplayer
    msgbox CeruleanCity_Text_PeopleHereWereRobbed, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_POLICEMAN, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

CeruleanCity_EventScript_GruntTriggerTop::
    lockall
    setvar VAR_TEMP_1, 0
    applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    goto CeruleanCity_EventScript_GruntTrigger
    end

CeruleanCity_EventScript_GruntTriggerBottom::
    lockall
    setvar VAR_TEMP_1, 1
    applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    goto CeruleanCity_EventScript_GruntTrigger
    end

CeruleanCity_EventScript_GruntTrigger::
    playbgm MUS_RG_ENCOUNTER_ROCKET, 0
    msgbox CeruleanCity_Text_GruntIntro, MSGBOX_DEFAULT
    setvar VAR_LAST_TALKED, LOCALID_GRUNT
    trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
    setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
    goto CeruleanCity_EventScript_GruntDefeated
    end

CeruleanCity_EventScript_Grunt::
    lock
    faceplayer
    goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
    playbgm MUS_RG_ENCOUNTER_ROCKET, 0
    message CeruleanCity_Text_GruntIntro
    waitmessage
    waitbuttonpress
    trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
    setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
    goto CeruleanCity_EventScript_GruntDefeated
    end

CeruleanCity_EventScript_GruntDefeated::
    msgbox CeruleanCity_Text_OkayIllReturnStolenTM, MSGBOX_DEFAULT
    checkitemspace ITEM_TM28, 1
    compare VAR_RESULT, FALSE
    goto_if_eq CeruleanCity_EventScript_NoRoomForTM28
    giveitem_msg CeruleanCity_Text_RecoveredTM28FromGrunt, ITEM_TM28
    msgbox CeruleanCity_Text_BetterGetMovingBye, MSGBOX_DEFAULT
    closemessage
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_GRUNT
    fadescreen FADE_FROM_BLACK
    setflag FLAG_GOT_TM28_FROM_ROCKET
    release
    end

CeruleanCity_EventScript_NoRoomForTM28::
    msgbox CeruleanCity_Text_MakeRoomForThisCantRun, MSGBOX_DEFAULT
    release
    end

CeruleanCity_EventScript_LittleBoy::
    lock
    faceplayer
    goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
    msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree, MSGBOX_DEFAULT
    release
    end

CeruleanCity_EventScript_LittleBoySlowbroMoved::
    msgbox CeruleanCity_Text_YouCanCutDownSmallTrees, MSGBOX_DEFAULT
    release
    end

CeruleanCity_EventScript_BaldingMan::
    msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
    end

CeruleanCity_EventScript_Slowbro::
    lock
    random 4
    copyvar VAR_0x8008, VAR_RESULT
    compare VAR_0x8008, 0
    call_if_eq CeruleanCity_EventScript_SlowbroText1
    compare VAR_0x8008, 1
    call_if_eq CeruleanCity_EventScript_SlowbroText2
    compare VAR_0x8008, 2
    call_if_eq CeruleanCity_EventScript_SlowbroText3
    compare VAR_0x8008, 3
    call_if_eq CeruleanCity_EventScript_SlowbroText4
    release
    end

CeruleanCity_EventScript_SlowbroText1::
    msgbox CeruleanCity_Text_SlowbroTookSnooze, MSGBOX_DEFAULT
    return

CeruleanCity_EventScript_SlowbroText2::
    msgbox CeruleanCity_Text_SlowbroLoafingAround, MSGBOX_DEFAULT
    return

CeruleanCity_EventScript_SlowbroText3::
    msgbox CeruleanCity_Text_SlowbroTurnedAway, MSGBOX_DEFAULT
    return

CeruleanCity_EventScript_SlowbroText4::
    msgbox CeruleanCity_Text_SlowbroIgnoredOrders, MSGBOX_DEFAULT
    return

CeruleanCity_EventScript_Lass::
    lock
    random 3
    copyvar VAR_0x8008, VAR_RESULT
    compare VAR_0x8008, 0
    call_if_eq CeruleanCity_EventScript_SlowbroCommand1
    compare VAR_0x8008, 1
    call_if_eq CeruleanCity_EventScript_SlowbroCommand2
    compare VAR_0x8008, 2
    call_if_eq CeruleanCity_EventScript_SlowbroCommand3
    waitmessage
    delay 40
    playse SE_PIN
    applymovement LOCALID_SLOWBRO, Common_Movement_QuestionMark
    waitmovement 0
    delay 30
    compare VAR_0x8008, 0
    call_if_eq CeruleanCity_EventScript_SlowbroFailed1
    compare VAR_0x8008, 1
    call_if_eq CeruleanCity_EventScript_SlowbroFailed2
    compare VAR_0x8008, 2
    call_if_eq CeruleanCity_EventScript_SlowbroFailed3
    release
    end

CeruleanCity_EventScript_SlowbroCommand1::
    message CeruleanCity_Text_SlowbroUseSonicboom
    return

CeruleanCity_EventScript_SlowbroCommand2::
    message CeruleanCity_Text_SlowbroPunch
    return

CeruleanCity_EventScript_SlowbroCommand3::
    message CeruleanCity_Text_SlowbroWithdraw
    return

CeruleanCity_EventScript_SlowbroFailed1::
    msgbox CeruleanCity_Text_SlowbroPayAttention
    return

CeruleanCity_EventScript_SlowbroFailed2::
    msgbox CeruleanCity_Text_NoYouBlewItAgain
    return

CeruleanCity_EventScript_SlowbroFailed3::
    msgbox CeruleanCity_Text_HardToControlMonsObedience
    return

CeruleanCity_EventScript_Youngster::
    msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
    end

CeruleanCity_EventScript_Woman::
    lock
    faceplayer
    msgbox CeruleanCity_Text_WantBrightRedBicycle, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

CeruleanCity_EventScript_CeruleanCaveGuard::
    msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
    end

CeruleanCity_EventScript_CitySign::
    msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
    end

CeruleanCity_EventScript_GymSign::
    msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
    end

CeruleanCity_EventScript_BikeShopSign::
    msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
    end

CeruleanCity_EventScript_TrainerTips::
    msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
    end

CeruleanCity_Text_RivalIntro::
    .string "{RIVAL}: Yo! {PLAYER}!\p"
    .string "You're still struggling along back\n"
    .string "here?\p"
    .string "I'm doing great! I caught a bunch\n"
    .string "of strong and smart Pokémon!\p"
    .string "Here, let me see what you caught,\n"
    .string "{PLAYER}!$"

CeruleanCity_Text_RivalDefeat::
    .string "Hey!\n"
    .string "Take it easy!\l"
    .string "You won already!$"

CeruleanCity_Text_RivalPostBattle::
    .string "{RIVAL}: Hey, guess what?\p"
    .string "I went to Bill's and got him to\n"
    .string "show me his rare Pokémon.\p"
    .string "That added a lot of pages to my\n"
    .string "Pokédex!\p"
    .string "After all, Bill's world famous as a\n"
    .string "Pokémaniac.\p"
    .string "He invented the Pokémon Storage\n"
    .string "System on PC, too.\p"
    .string "Since you're using his system,\n"
    .string "you should go thank him.\p"
    .string "Well, I better get rolling!\n"
    .string "Smell ya later!$"

CeruleanCity_Text_RegisteredRival::
    .string "Registered {RIVAL}\n"
    .string "in the Pokénav.$"

CeruleanCity_Text_OhRightLittlePresentAsFavor::
    .string "Oh, yeah, right.\p"
    .string "I feel sorry for you. No, really.\n"
    .string "You're always plodding behind me.\p"
    .string "So here, I'll give you a little\n"
    .string "present as a favour.$"

CeruleanCity_Text_ExplainExpShareSmellYa::
    .string "That's an Exp. Share…\n"
    .string "It shares experience with the Pokémon\l"
    .string "holding it, even if they don't battle.\p"
    .string "Use it to train your Pokémon so next\n"
    .string "time you're more of a challenge for me.\p"
    .string "All right, this time I really am\n"
    .string "gone. Smell ya!$"

CeruleanCity_Text_DaisyPokenavCall::
    .string "… … … … … …\n"
    .string "… … … … … Beep!\p"
    .string "Daisy: Oh, hello, {PLAYER}?\n"
    .string "This is Daisy, your neighbour.\p"
    .string "I asked {RIVAL} for your number\n"
    .string "so I could get in contact with you.\p"
    .string "I wanted to let you know that I've\n"
    .string "finally finished my training and\l"
    .string "I'm ready to massage your Pokémon!\p"
    .string "I promise, I will take good care\n"
    .string "of them and make them happier!\p"
    .string "Oh! And don't worry about payment,\n"
    .string "I remember that I still owe you!\p"
    .string "I hope to see you and your\n"
    .string "Pokémon soon!\p"
    .string "… … … … … …\n"
    .string "… … … … … Click!$"

CeruleanCity_Text_RegisteredDaisy::
    .string "Registered Masseuse Daisy\n"
    .string "in the Pokénav.$"

CeruleanCity_Text_PeopleHereWereRobbed::
    .string "The people here were robbed.\p"
    .string "It's obvious that Team Rocket is\n"
    .string "behind this most heinous crime!\p"
    .string "Even our police force has\n"
    .string "trouble with the Rockets!$"

CeruleanCity_Text_GruntIntro::
    .string "Hey! Stay out!\n"
    .string "It's not your yard!\p"
    .string "…Huh?\n"
    .string "Me?\p"
    .string "I'm an innocent bystander!\n"
    .string "Don't you believe me?$"

CeruleanCity_Text_GruntDefeat::
    .string "Grunt: Stop! I give up!\n"
    .string "I'll leave quietly!$"

CeruleanCity_Text_OkayIllReturnStolenTM::
    .string "…Okay.\n"
    .string "I'll return the TM I stole.$"

CeruleanCity_Text_RecoveredTM28FromGrunt::
    .string "{PLAYER} recovered TM28 from\n"
    .string "the Team Rocket Grunt.$"

CeruleanCity_Text_BetterGetMovingBye::
    .string "I better get moving!\n"
    .string "Bye!$"

CeruleanCity_Text_MakeRoomForThisCantRun::
    .string "Make room for this!\n"
    .string "I can't run until I give it to you!$"

CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree::
    .string "If that Slowbro wasn't there, you\n"
    .string "could cut down the small tree.\p"
    .string "That way, you could get to the\n"
    .string "other side.\p"
    .string "I think there's a way around it,\n"
    .string "though.$"

CeruleanCity_Text_YouCanCutDownSmallTrees::
    .string "Did you know that you can cut down\n"
    .string "small trees?\p"
    .string "Even that small tree in front of\n"
    .string "the shop can be cut down.\p"
    .string "I think there's a way around it,\n"
    .string "though.$"

CeruleanCity_Text_PokemonEncyclopediaAmusing::
    .string "You're making an encyclopedia on\n"
    .string "Pokémon? That sounds amusing.$"

CeruleanCity_Text_SlowbroTookSnooze::
    .string "Slowbro took a snooze…$"

CeruleanCity_Text_SlowbroLoafingAround::
    .string "Slowbro is loafing around…$"

CeruleanCity_Text_SlowbroTurnedAway::
    .string "Slowbro turned away…$"

CeruleanCity_Text_SlowbroIgnoredOrders::
    .string "Slowbro ignored orders…$"

CeruleanCity_Text_SlowbroUseSonicboom::
    .string "Okay! Slowbro!\n"
    .string "Use Sonicboom!$"

CeruleanCity_Text_SlowbroPunch::
    .string "Slowbro, punch!$"

CeruleanCity_Text_SlowbroWithdraw::
    .string "Slowbro, Withdraw!$"

CeruleanCity_Text_SlowbroPayAttention::
    .string "Come on, Slowbro, pay attention!$"

CeruleanCity_Text_NoYouBlewItAgain::
    .string "No!\n"
    .string "You blew it again!$"

CeruleanCity_Text_HardToControlMonsObedience::
    .string "No! That's wrong!\n"
    .string "It's so hard to control Pokémon!\p"
    .string "Your Pokémon's obedience depends\n"
    .string "on your abilities as a Trainer.$"

CeruleanCity_Text_TrainerLifeIsToughIsntIt::
    .string "You're a Trainer, too?\p"
    .string "Collecting, battling…\n"
    .string "It's a tough life, isn't it?$"

CeruleanCity_Text_WantBrightRedBicycle::
    .string "I want a bright red bicycle.\p"
    .string "I'll keep it at home, so it won't\n"
    .string "get dirty.$"

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "This is Cerulean Cave.\p"
    .string "Horribly strong Pokémon live inside\n"
    .string "there.\p"
    .string "It takes a very special Trainer to\n"
    .string "be allowed inside there.\p"
    .string "You'd have to be strong enough to\n"
    .string "become the Pokémon League\l"
    .string "Champion for starters.\p"
    .string "And, you would have to have\n"
    .string "made a great achievement.$"

CeruleanCity_Text_CitySign::
    .string "Cerulean City\n"
    .string "A mysterious, blue aura surrounds it$"

CeruleanCity_Text_GymSign::
    .string "Cerulean City Pokémon Gym\n"
    .string "Leader: Misty\l"
    .string "The Tomboyish Mermaid!$"

CeruleanCity_Text_BikeShopSign::
    .string "Bike Shop\n"
    .string "Grass and caves handled easily!$"

CeruleanCity_Text_TrainerTipsHeldItems::
    .string "Trainer Tips\p"
    .string "A Pokémon can be made to hold\n"
    .string "an item.\p"
    .string "Some items can even be used by\n"
    .string "the holding Pokémon in battle.$"


