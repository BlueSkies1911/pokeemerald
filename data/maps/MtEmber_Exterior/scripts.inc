.set LOCALID_GRUNT1, 2
.set LOCALID_GRUNT2, 3

MtEmber_Exterior_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_Exterior_OnTransition
    map_script MAP_SCRIPT_ON_LOAD, MtEmber_Exterior_OnLoad
    .byte 0

MtEmber_Exterior_OnTransition:
    setflag FLAG_WORLD_MAP_MT_EMBER_EXTERIOR
    compare VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2
    call_if_eq MtEmber_Exterior_EventScript_RocketsFaceDown
    end

MtEmber_Exterior_EventScript_RocketsFaceDown::
    setobjectmovementtype LOCALID_GRUNT1, MOVEMENT_TYPE_FACE_DOWN
    setobjectmovementtype LOCALID_GRUNT2, MOVEMENT_TYPE_FACE_DOWN
    return

MtEmber_Exterior_OnLoad:
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
    call_if_ge MtEmber_Exterior_EventScript_OpenCave
    end

MtEmber_Exterior_EventScript_OpenCave::
    setmetatile 42, 39, METATILE_MtEmber_CaveEntrance, 0
    return

MtEmber_Exterior_EventScript_Grunt1::
    lock
    goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_Grunt1Defeated
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
    goto_if_eq MtEmber_Exterior_EventScript_BattleGrunt1
    msgbox MtEmber_Exterior_Text_WellTryDiggingHere, MSGBOX_DEFAULT
    release
    end

MtEmber_Exterior_EventScript_Grunt1Defeated::
    msgbox MtEmber_Exterior_Text_Grunt1PostBattle, MSGBOX_DEFAULT
    release
    end

MtEmber_Exterior_EventScript_BattleGrunt1::
    applymovement LOCALID_GRUNT1, Common_Movement_FacePlayer
    waitmovement 0
    playbgm MUS_RG_ENCOUNTER_ROCKET, 0
    msgbox MtEmber_Exterior_Text_Grunt1Intro, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_Text_Grunt1Defeat
    msgbox MtEmber_Exterior_Text_Grunt1PostBattle, MSGBOX_DEFAULT
    goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedBothGrunts
    release
    end

MtEmber_Exterior_EventScript_DefeatedBothGrunts::
    msgbox MtEmber_Exterior_Text_WellRegroupDontStepInsideThere, MSGBOX_DEFAULT
    closemessage
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_GRUNT1
    removeobject LOCALID_GRUNT2
    fadescreen FADE_FROM_BLACK
    release
    end

MtEmber_Exterior_EventScript_Grunt2::
    lock
    faceplayer
    goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedGrunt2
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
    goto_if_eq MtEmber_Exterior_EventScript_BattleGrunt2
    msgbox MtEmber_Exterior_Text_YoureInTheWayGetLost, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_GRUNT2, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

MtEmber_Exterior_EventScript_DefeatedGrunt2::
    msgbox MtEmber_Exterior_Text_Grunt2PostBattle, MSGBOX_DEFAULT
    release
    end

MtEmber_Exterior_EventScript_BattleGrunt2::
    playbgm MUS_RG_ENCOUNTER_ROCKET, 0
    msgbox MtEmber_Exterior_Text_Grunt2Intro, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_Text_Grunt2Defeat
    msgbox MtEmber_Exterior_Text_Grunt2PostBattle, MSGBOX_DEFAULT
    goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_DefeatedBothGrunts
    release
    end

MtEmber_Exterior_EventScript_RocketPasswordScene::
    lockall
    msgbox MtEmber_Exterior_Text_PunchedThroughAtLast, MSGBOX_DEFAULT
    message MtEmber_Exterior_Text_WhatsPasswordAgain
    waitmessage
    playse SE_PIN
    applymovement LOCALID_GRUNT2, Common_Movement_QuestionMark
    waitmovement 0
    waitbuttonpress
    msgbox MtEmber_Exterior_Text_FirstPasswordGoldeen, MSGBOX_DEFAULT
    applymovement LOCALID_GRUNT1, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_GRUNT1, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_GRUNT1, Common_Movement_Delay48
    waitmovement 0
    applymovement LOCALID_GRUNT2, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    call MtEmber_Exterior_EventScript_RocketsFaceDown
    msgbox MtEmber_Exterior_Text_SnoopsBeenListeningIn, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2
    releaseall
    end

MtEmber_Exterior_EventScript_Logan::
    trainerbattle_single TRAINER_PKMN_RANGER_LOGAN, MtEmber_Exterior_Text_LoganIntro, MtEmber_Exterior_Text_LoganDefeat
    msgbox MtEmber_Exterior_Text_LoganPostBattle, MSGBOX_AUTOCLOSE
    end

MtEmber_Exterior_EventScript_Beth::
    trainerbattle_single TRAINER_PKMN_RANGER_BETH, MtEmber_Exterior_Text_BethIntro, MtEmber_Exterior_Text_BethDefeat
    msgbox MtEmber_Exterior_Text_BethPostBattle, MSGBOX_AUTOCLOSE
    end

MtEmber_Exterior_EventScript_Jocelyn::
    trainerbattle_single TRAINER_CRUSH_GIRL_JOCELYN, MtEmber_Exterior_Text_JocelynIntro, MtEmber_Exterior_Text_JocelynDefeat
    msgbox MtEmber_Exterior_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
    end

MtEmber_Exterior_Text_WellTryDiggingHere::
    .string "Over here.\n"
    .string "We'll try digging here.\p"
    .string "That treasure the Admins've been\n"
    .string "talking about should be here.$"

MtEmber_Exterior_Text_YoureInTheWayGetLost::
    .string "What the…?\n"
    .string "You're in the way. Get lost.$"

MtEmber_Exterior_Text_PunchedThroughAtLast::
    .string "Whew, punched through at last.\n"
    .string "Let's go treasure hunting!$"

MtEmber_Exterior_Text_WhatsPasswordAgain::
    .string "Any treasure we find, we haul back\n"
    .string "to the Warehouse, understood?\p"
    .string "…Oh, and what're the passwords?\n"
    .string "At the Rocket Warehouse, I mean.$"

MtEmber_Exterior_Text_FirstPasswordGoldeen::
    .string "What, you forgot the password?\n"
    .string "There're actually two.\p"
    .string "The first one's “Goldeen need\n"
    .string "log.”\p"
    .string "And the second one is…$"

MtEmber_Exterior_Text_SnoopsBeenListeningIn::
    .string "Hey!\n"
    .string "This snoop's been listening in!$"

MtEmber_Exterior_Text_Grunt1Intro::
    .string "You've been eavesdropping on us,\n"
    .string "haven't you?$"

MtEmber_Exterior_Text_Grunt1Defeat::
    .string "Huh, what?$"

MtEmber_Exterior_Text_Grunt1PostBattle::
    .string "Why'd you have to win?$"

MtEmber_Exterior_Text_Grunt2Intro::
    .string "Trying to horn in on our treasure?\n"
    .string "Don't bet on it!$"

MtEmber_Exterior_Text_Grunt2Defeat::
    .string "Wait!\n"
    .string "But how?$"

MtEmber_Exterior_Text_Grunt2PostBattle::
    .string "Develop amnesia conveniently and\n"
    .string "forget everything you heard!$"

MtEmber_Exterior_Text_WellRegroupDontStepInsideThere::
    .string "What a setback…\n"
    .string "We'll have to regroup.\p"
    .string "You! Don't even think about taking\n"
    .string "a step inside here!\p"
    .string "If you know what's good for you,\n"
    .string "don't even think about this!$"

MtEmber_Exterior_Text_LoganIntro::
    .string "An active volcano is one that's\n"
    .string "erupting, or about to.$"

MtEmber_Exterior_Text_LoganDefeat::
    .string "Whew… That was hot!\n"
    .string "Sweat's erupting from me!$"

MtEmber_Exterior_Text_LoganPostBattle::
    .string "They say there're over 1,500\n"
    .string "active volcanoes in the world.\p"
    .string "Just thinking about them makes me\n"
    .string "feel all hot and gooey inside!$"

MtEmber_Exterior_Text_BethIntro::
    .string "Do you know how caves form inside\n"
    .string "volcanoes?$"

MtEmber_Exterior_Text_BethDefeat::
    .string "Atchah!\n"
    .string "You're shockingly good!$"

MtEmber_Exterior_Text_BethPostBattle::
    .string "When lava at the surface of magma\n"
    .string "hardens, and the magma inside flows\l"
    .string "out, caverns are left behind.$"

MtEmber_Exterior_Text_JocelynIntro::
    .string "I've been in training so I can mend\n"
    .string "my broken heart…\p"
    .string "It toughened me up physically at\n"
    .string "least! Hi-yah!$"

MtEmber_Exterior_Text_JocelynDefeat::
    .string "I think I tried to overdo it…$"

MtEmber_Exterior_Text_JocelynPostBattle::
    .string "The way you battle, it reminds me\n"
    .string "of the guy who dumped me…$"