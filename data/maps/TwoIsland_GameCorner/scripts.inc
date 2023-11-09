.equ LOCALID_DADDY,    1
.equ LOCALID_BIKER,    2
.equ LOCALID_LOSTELLE, 3

TwoIsland_GameCorner_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_GameCorner_OnTransition
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TwoIsland_GameCorner_OnWarp
    map_script MAP_SCRIPT_ON_FRAME_TABLE, TwoIsland_GameCorner_OnFrame
    map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
    .byte 0

TwoIsland_GameCorner_OnTransition:
    call_if_set FLAG_GOT_MOON_STONE_FROM_GAME_CORNER, TwoIsland_GameCorner_EventScript_SetLostelleReturnedPos
    end

TwoIsland_GameCorner_EventScript_SetLostelleReturnedPos::
    setobjectxyperm LOCALID_DADDY, 6, 2
    setobjectmovementtype LOCALID_DADDY, MOVEMENT_TYPE_FACE_DOWN
    setobjectmovementtype LOCALID_LOSTELLE, MOVEMENT_TYPE_LOOK_AROUND
    setvar VAR_MAP_SCENE_TWO_ISLAND_GAME_CORNER, 4
    return

TwoIsland_GameCorner_OnWarp:
    map_script_2 VAR_MAP_SCENE_TWO_ISLAND_GAME_CORNER, 2, TwoIsland_GameCorner_EventScript_TurnPlayerNorth
    map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
    .2byte 0

TwoIsland_GameCorner_EventScript_TurnPlayerNorth::
    turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
    end

TwoIsland_GameCorner_OnFrame:
    map_script_2 VAR_MAP_SCENE_TWO_ISLAND_GAME_CORNER, 0, TwoIsland_GameCorner_EventScript_HelpFindLostelleScene
    map_script_2 VAR_MAP_SCENE_TWO_ISLAND_GAME_CORNER, 2, TwoIsland_GameCorner_EventScript_FoundLostelleScene
    map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
    .2byte 0

TwoIsland_GameCorner_EventScript_FoundLostelleScene::
    lockall
    msgbox TwoIsland_GameCorner_Text_YouRescuedLostelle, MSGBOX_DEFAULT
    special GetPlayerBigGuyGirlString
    msgbox TwoIsland_GameCorner_Text_LostelleItsOkayDaddy, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_LOSTELLE, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    setvar VAR_MAP_SCENE_TWO_ISLAND_GAME_CORNER, 3
    releaseall
    end

TwoIsland_GameCorner_EventScript_HelpFindLostelleScene::
    lockall
    applymovement LOCALID_DADDY, Movement_171520
    waitmovement 0
    msgbox TwoIsland_GameCorner_Text_WhereHasLostelleGottenTo
    closemessage
    applymovement LOCALID_DADDY, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_DADDY, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_DADDY, Common_Movement_Delay48
    waitmovement 0
    applymovement LOCALID_DADDY, Movement_171527
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    msgbox TwoIsland_GameCorner_Text_PleaseHelpFindLostelle, MSGBOX_DEFAULT
    closemessage
    playse SE_DOOR
    waitse
    applymovement OBJ_EVENT_ID_PLAYER, Movement_17152C
    waitmovement 0
    playbgm MUS_RG_ENCOUNTER_BOY, 0
    addobject LOCALID_BIKER
    applymovement LOCALID_BIKER, TwoIsland_GameCorner_Movement_BikerLookAround
    waitmovement 0
    msgbox TwoIsland_GameCorner_Text_IsThisOnlyThreeIsland, MSGBOX_DEFAULT
    applymovement LOCALID_BIKER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    msgbox TwoIsland_GameCorner_Text_ThisIsTwoIslandMoveIt, MSGBOX_DEFAULT
    msgbox TwoIsland_GameCorner_Text_TheseIslandsAreConfusing, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_BIKER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    playse SE_EXIT
    removeobject LOCALID_BIKER
    fadedefaultbgm
    delay 60
    msgbox TwoIsland_GameCorner_Text_PunkScuffedUpMyFloor, MSGBOX_DEFAULT
    clearflag FLAG_HIDE_THREE_ISLAND_LONE_BIKER
    setvar VAR_MAP_SCENE_THREE_ISLAND, 2
    setvar VAR_MAP_SCENE_TWO_ISLAND_GAME_CORNER, 1
    releaseall
    end

Movement_171520::
    walk_left
    walk_right
    walk_right
    delay_8
    walk_in_place_faster_up
    delay_16
    step_end

Movement_171527::
    walk_down
    walk_down
    walk_down
    walk_in_place_faster_left
    step_end

Movement_17152C::
    walk_left
    walk_in_place_faster_right
    step_end

TwoIsland_GameCorner_Movement_BikerLookAround::
    walk_in_place_faster_left
    delay_8
    walk_in_place_faster_right
    delay_8
    walk_in_place_faster_up
    step_end

TwoIsland_GameCorner_EventScript_InfoMan::
    lock
    faceplayer
    compare VAR_MAP_SCENE_TWO_ISLAND_GAME_CORNER, 4
    goto_if_eq GameCorner_EventScript_InfoMan2
    goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_GameCorner_EventScript_GetGamesGoingSoon
    msgbox TwoIsland_GameCorner_Text_NotRunningAnyGamesToday, MSGBOX_DEFAULT
    release
    end

TwoIsland_GameCorner_EventScript_GetGamesGoingSoon::
    msgbox TwoIsland_GameCorner_Text_GetGamesGoingSoon, MSGBOX_DEFAULT
    release
    end

TwoIsland_GameCorner_EventScript_LostellesDaddy::
    lock
    faceplayer
    compare VAR_MAP_SCENE_TWO_ISLAND_GAME_CORNER, 4
    goto_if_eq GameCorner_EventScript_MinigameAttendant
    goto_if_set FLAG_GOT_MOON_STONE_FROM_GAME_CORNER, TwoIsland_GameCorner_EventScript_GetGameCornerRunning
    compare VAR_MAP_SCENE_TWO_ISLAND_GAME_CORNER, 3
    goto_if_eq TwoIsland_GameCorner_EventScript_GiveDaddyMeteorite
    msgbox TwoIsland_GameCorner_Text_PleaseGoToThreeIsland, MSGBOX_DEFAULT
    release
    end

TwoIsland_GameCorner_EventScript_GiveDaddyMeteorite::
    goto_if_set FLAG_NO_ROOM_FOR_GAME_CORNER_MOON_STONE, TwoIsland_GameCorner_EventScript_ReceiveMoonStone
    msgbox TwoIsland_GameCorner_Text_ThisIsForMe, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2
    playfanfare MUS_OBTAIN_TMHM
    message TwoIsland_GameCorner_Text_HandedMeteoriteToLostellesDaddy
    waitmessage
    waitfanfare
    removeitem ITEM_METEORITE, 1
    msgbox TwoIsland_GameCorner_Text_OhThisIsFromBill, MSGBOX_DEFAULT
    goto TwoIsland_GameCorner_EventScript_ReceiveMoonStone
    end

TwoIsland_GameCorner_EventScript_ReceiveMoonStone::
    checkitemspace ITEM_MOON_STONE, 1
    compare VAR_RESULT, FALSE
    goto_if_eq TwoIsland_GameCorner_EventScript_NoRoomForMoonStone
    additem ITEM_MOON_STONE
    setflag FLAG_GOT_MOON_STONE_FROM_GAME_CORNER
    msgreceiveditem TwoIsland_GameCorner_Text_ReceivedMoonStoneFromLostellesDaddy, ITEM_MOON_STONE
    release
    end

TwoIsland_GameCorner_EventScript_GetGameCornerRunning::
    msgbox TwoIsland_GameCorner_Text_IllGetGameCornerRunning, MSGBOX_DEFAULT
    release
    end

TwoIsland_GameCorner_EventScript_NoRoomForMoonStone::
    setflag FLAG_NO_ROOM_FOR_GAME_CORNER_MOON_STONE
    msgbox TwoIsland_GameCorner_Text_NotGoingToFitInBag, MSGBOX_DEFAULT
    release
    end

TwoIsland_GameCorner_EventScript_Lostelle::
    lock
    faceplayer
    msgbox TwoIsland_GameCorner_Text_PleaseShowMeYouBeingCool, MSGBOX_DEFAULT
    release
    end

TwoIsland_GameCorner_Text_WhereHasLostelleGottenTo::
    .string "Now, where's Lostelle gotten to\n"
    .string "today?\p"
    .string "She always brings me lunch every\n"
    .string "day right about now…$"

TwoIsland_GameCorner_Text_PleaseHelpFindLostelle::
    .string "Hm? You, there!\n"
    .string "Are you a friend of Lostelle's?\p"
    .string "Have you seen Lostelle around?\n"
    .string "I don't know where she might be.\l"
    .string "She should've been here long ago.\p"
    .string "Lostelle's a cutie - she got my\n"
    .string "looks - so what if someone…\p"
    .string "What if something's happened to\n"
    .string "my Lostelle?!\p"
    .string "Please, help me find her!\n"
    .string "Please go search Three Island!$"

TwoIsland_GameCorner_Text_IsThisOnlyThreeIsland::
    .string "Hah? What is this Game Corner?\n"
    .string "How much sadder can this get?\p"
    .string "Those clowns…\p"
    .string "They said they'd be waiting on the\n"
    .string "island, so where are they?\p"
    .string "Hey, you! Is this the only Three\n"
    .string "Island around here?$"

TwoIsland_GameCorner_Text_ThisIsTwoIslandMoveIt::
    .string "Try waking up before you crawl out\n"
    .string "of bed, you punk.\p"
    .string "This is Two Island!\p"
    .string "Move it! Get your filthy motorbike\n"
    .string "out of my place!$"

TwoIsland_GameCorner_Text_TheseIslandsAreConfusing::
    .string "Huh…\n"
    .string "Oh, oh, gotcha.\p"
    .string "Tch…\n"
    .string "These islands are confusing…$"

TwoIsland_GameCorner_Text_PunkScuffedUpMyFloor::
    .string "Would you look at that?\n"
    .string "That punk scuffed up my floor.$"

TwoIsland_GameCorner_Text_PleaseGoToThreeIsland::
    .string "Hey, but listen! I'm begging you,\n"
    .string "you have to go to Three Island.\p"
    .string "If anything were to happen to my\n"
    .string "Lostelle…\p"
    .string "My place is the house with the red\n"
    .string "roof on Three Island.\p"
    .string "She may just show up late here,\n"
    .string "so I can't run off anywhere.\p"
    .string "That's why I have to get you to do\n"
    .string "me this big favour.$"

TwoIsland_GameCorner_Text_NotRunningAnyGamesToday::
    .string "I'm sorry.\n"
    .string "We're not running any games today.$"

TwoIsland_GameCorner_Text_GetGamesGoingSoon::
    .string "We'll get the games going soon\n"
    .string "for you!$"

TwoIsland_GameCorner_Text_YouRescuedLostelle::
    .string "So you rescued Lostelle?\n"
    .string "How can I thank you?\p"
    .string "Lostelle, darling, forgive me!\p"
    .string "Daddy didn't know you were scared\n"
    .string "and in trouble!$"

TwoIsland_GameCorner_Text_LostelleItsOkayDaddy::
    .string "Lostelle: It's okay, Daddy.\n"
    .string "I got to be friends with {PLAYER}!$"

TwoIsland_GameCorner_Text_ThisIsForMe::
    .string "Oh, what's that?\n"
    .string "You're saying that this is for me?\p"
    .string "How did you know that I love rare\n"
    .string "rocks and gems?\p"
    .string "You sure know how to make a guy\n"
    .string "happy.$"

TwoIsland_GameCorner_Text_HandedMeteoriteToLostellesDaddy::
    .string "{PLAYER} handed the Meteorite\n"
    .string "to Lostelle's daddy.$"

TwoIsland_GameCorner_Text_OhThisIsFromBill::
    .string "Oh, I see, this is from Bill!\n"
    .string "You have to thank him for me!\p"
    .string "You know, you've been fantastic.\n"
    .string "I want you to have this.$"

TwoIsland_GameCorner_Text_ReceivedMoonStoneFromLostellesDaddy::
    .string "{PLAYER} received a Moon Stone\n"
    .string "from Lostelle's daddy.$"

TwoIsland_GameCorner_Text_NotGoingToFitInBag::
    .string "Your Bag's not going to fit another\n"
    .string "thing…$"

TwoIsland_GameCorner_Text_IllGetGameCornerRunning::
    .string "All right, I'll get the Game Corner\n"
    .string "running right away.\p"
    .string "You have to come visit with a\n"
    .string "friend.$"

TwoIsland_GameCorner_Text_PleaseShowMeYouBeingCool::
    .string "Listen, listen!\p"
    .string "Please show me you being cool\n"
    .string "again!$"
