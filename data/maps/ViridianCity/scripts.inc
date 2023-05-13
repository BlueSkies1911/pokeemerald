.set LOCALID_OLD_MAN,      3
.set LOCALID_TUTORIAL_MAN, 4
.set LOCALID_WOMAN,        5

ViridianCity_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
    .byte 0

ViridianCity_OnTransition:
    setflag FLAG_WORLD_MAP_VIRIDIAN_CITY
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0
    call_if_eq ViridianCity_EventScript_SetOldManBlockingRoad
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
    call_if_eq ViridianCity_EventScript_SetOldManStandingByRoad
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
    call_if_ge ViridianCity_EventScript_SetOldManNormal
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0
    call_if_eq ViridianCity_EventScript_TryUnlockGym
    end

ViridianCity_EventScript_SetOldManBlockingRoad::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
    setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 11
    setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
    return

ViridianCity_EventScript_SetOldManStandingByRoad::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
    setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 8
    setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
    return

ViridianCity_EventScript_SetOldManNormal::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
    return

ViridianCity_EventScript_TryUnlockGym::
    goto_if_unset FLAG_BADGE02_GET, Common_EventScript_NopReturn
    goto_if_unset FLAG_BADGE03_GET, Common_EventScript_NopReturn
    goto_if_unset FLAG_BADGE04_GET, Common_EventScript_NopReturn
    goto_if_unset FLAG_BADGE05_GET, Common_EventScript_NopReturn
    goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
    goto_if_unset FLAG_BADGE07_GET, Common_EventScript_NopReturn
    setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
    return

ViridianCity_EventScript_DreamEaterTutor::
    goto EventScript_DreamEaterTutor
    end
    
ViridianCity_EventScript_OldMan::
    lock
    faceplayer
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
    goto_if_eq ViridianCity_EventScript_OldManGymLeaderReturned
    msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_OLD_MAN, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

ViridianCity_EventScript_OldManGymLeaderReturned::
    msgbox ViridianCity_Text_ViridiansGymLeaderReturned, MSGBOX_DEFAULT
    release
    end

ViridianCity_EventScript_TutorialOldMan::
    lock
    faceplayer
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
    goto_if_ge ViridianCity_EventScript_TutorialCompleted
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
    goto_if_eq ViridianCity_EventScript_TutorialStart
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0
    goto_if_eq ViridianCity_EventScript_TutorialNotReady
    end

ViridianCity_EventScript_TutorialCompleted::
    msgbox ViridianCity_Text_WeakenMonsFirstToCatch, MSGBOX_DEFAULT
    release
    end

ViridianCity_EventScript_TutorialStart::
    call ViridianCity_EventScript_DoTutorialBattle
    release
    end

ViridianCity_EventScript_DoTutorialBattle::
    msgbox ViridianCity_Text_ShowYouHowToCatchMons, MSGBOX_DEFAULT
    closemessage
    special StartOldManTutorialBattle
    waitstate
    lock
    faceplayer
    msgbox ViridianCity_Text_ThatWasEducationalTakeThis, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
    giveitem ITEM_POKE_BALL, 5
    msgbox ViridianCity_Text_WatchThatToLearnBasics, MSGBOX_DEFAULT
    return

ViridianCity_EventScript_TutorialNotReady::
    msgbox ViridianCity_Text_ThisIsPrivateProperty, MSGBOX_DEFAULT
    closemessage
    release
    end

ViridianCity_EventScript_Woman::
    lock
    faceplayer
    compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0
    goto_if_eq ViridianCity_EventScript_WomanRoadBlocked
    msgbox ViridianCity_Text_GoShoppingInPewterOccasionally, MSGBOX_DEFAULT
    release
    end

ViridianCity_EventScript_WomanRoadBlocked::
    msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

ViridianCity_EventScript_Youngster::
    lock
    faceplayer
    msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq ViridianCity_EventScript_YoungsterExplainCaterpillars
    compare VAR_RESULT, NO
    goto_if_eq ViridianCity_EventScript_YoungsterDeclineExplanation
    end

ViridianCity_EventScript_YoungsterExplainCaterpillars::
    msgbox ViridianCity_Text_ExplainCaterpieWeedle, MSGBOX_DEFAULT
    release
    end

ViridianCity_EventScript_YoungsterDeclineExplanation::
    msgbox ViridianCity_Text_OhOkayThen, MSGBOX_DEFAULT
    release
    end

ViridianCity_EventScript_Boy::
    msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
    end

ViridianCity_EventScript_RoadBlocked::
    lockall
    msgbox ViridianCity_Text_ThisIsPrivateProperty, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_WalkDown
    waitmovement 0
    releaseall
    end

ViridianCity_Movement_WalkDown::
    walk_down
    step_end

ViridianCity_EventScript_GymDoorLocked::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    delay 20
    msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_JumpDownLedge
    waitmovement 0
    releaseall
    end

ViridianCity_Movement_JumpDownLedge::
    jump_2_down
    step_end

ViridianCity_EventScript_TutorialTriggerLeft::
    lockall
    applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    call ViridianCity_EventScript_DoTutorialBattle
    release
    end

ViridianCity_EventScript_TutorialTriggerRight::
    lockall
    applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    call ViridianCity_EventScript_DoTutorialBattle
    release
    end
    
ViridianCity_EventScript_TrainerTips1::
    msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
    end

ViridianCity_EventScript_GymSign::
    msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
    end

ViridianCity_EventScript_TrainerTips2::
    msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
    end

ViridianCity_EventScript_CitySign::
    msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
    end

ViridianCity_EventScript_GymDoor::
    msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
    end

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
    .string "This Pokémon Gym is always closed.\p"
    .string "I wonder who the Leader is?$"

ViridianCity_Text_ViridiansGymLeaderReturned::
    .string "Viridian Gym's Leader returned!$"

ViridianCity_Text_WeakenMonsFirstToCatch::
    .string "Well, now, I've had my coffee, and\n"
    .string "that's what I need to get going!\p"
    .string "But I made it too strong.\n"
    .string "It gave me a headache…\p"
    .string "Incidentally, are you filling your\n"
    .string "Pokédex?\p"
    .string "At first, focus on weakening the\n"
    .string "Pokémon before trying to catch it.$"

ViridianCity_Text_ShowYouHowToCatchMons:: @ 817DD4E
    .string "Well, now, I've had my coffee, and\n"
    .string "that's what I need to get going!\p"
    .string "Hm?\n"
    .string "What is that red box you have?\p"
    .string "Ah, so you're working on your\n"
    .string "Pokédex.\p"
    .string "Then let me give you a word of\n"
    .string "advice.\p"
    .string "Whenever you catch a Pokémon,\n"
    .string "the Pokédex automatically updates\l"
    .string "its data.\p"
    .string "…You don't know how to catch\n"
    .string "a Pokémon?\p"
    .string "I suppose I had better show you\n"
    .string "then!$"

ViridianCity_Text_ThatWasEducationalTakeThis:: @ 817DE9B
    .string "There! Now tell me, that was\n"
    .string "educational, was it not?\p"
    .string "And here, take these, too.$"

ViridianCity_Text_WatchThatToLearnBasics:: @ 817DEEB
    .string "Those are Pokeballs!\p"
    .string "They are necessary if you want\n"
    .string "to fill that Pokédex of yours.$"

ViridianCity_Text_ThisIsPrivateProperty::
    .string "I absolutely forbid you from\n"
    .string "going through here!\p"
    .string "This is private property!$"

ViridianCity_Text_GoShoppingInPewterOccasionally::
    .string "I go shopping in Pewter City\n"
    .string "occasionally.\p"
    .string "I have to take the winding trail in\n"
    .string "Viridian Forest when I go.$"

ViridianCity_Text_GrandpaHasntHadCoffeeYet::
    .string "Oh, Grandpa!\n"
    .string "Don't be so mean!\p"
    .string "I'm so sorry.\n"
    .string "He hasn't had his coffee yet.$"

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
    .string "You want to know about the two\n"
    .string "kinds of caterpillar Pokémon?$"

ViridianCity_Text_ExplainCaterpieWeedle::
    .string "Caterpie has no poison,\n"
    .string "but Weedle does.\p"
    .string "Watch that your Pokémon aren't\n"
    .string "stabbed by Weedle's Poison Sting.$"

ViridianCity_Text_OhOkayThen::
    .string "Oh, okay then!$"

ViridianCity_Text_CanCarryMonsAnywhere::
    .string "Those Poké Balls at your waist!\n"
    .string "You have Pokémon, don't you?\p"
    .string "It's great that you can carry and\n"
    .string "use Pokémon anytime, anywhere.$"

ViridianCity_Text_CatchMonsForEasierBattles::
    .string "Trainer Tips\p"
    .string "Catch Pokémon and expand your\n"
    .string "collection.\p"
    .string "The more you have, the easier it\n"
    .string "is to battle.$"

ViridianCity_Text_GymSign::
    .string "Viridian City Pokémon Gym$"

ViridianCity_Text_MovesLimitedByPP::
    .string "Trainer Tips\p"
    .string "The battle moves of Pokémon are\n"
    .string "limited by their Power Points, PP.\p"
    .string "To replenish PP, rest your tired\n"
    .string "Pokémon at a Pokémon Center.$"

ViridianCity_Text_CitySign::
    .string "Viridian City \n"
    .string "The Eternally Green Paradise$"

ViridianCity_Text_GymDoorsAreLocked::
    .string "Viridian Gym's doors are locked…$"


