.set LOCALID_SIGN_LADY, 1
.set LOCALID_PROF_OAK,  3
.set LOCALID_MOM,       4

.set SIGN_LADY_READY, VAR_TEMP_2

PalletTown_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
	.byte 0

PalletTown_OnTransition:
	randomweather
    setflag FLAG_WORLD_MAP_PALLET_TOWN
    call_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_TryReadySignLady
    compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 0
    call_if_eq PalletTown_EventScript_SetSignLadyPos
    compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
    call_if_eq PalletTown_EventScript_SetSignLadyDone
    end

PalletTown_EventScript_TryReadySignLady::
    goto_if_unset FLAG_OPENED_START_MENU, Common_EventScript_NopReturn
    compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
    goto_if_ge Common_EventScript_NopReturn
    setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
    return

PalletTown_EventScript_SetSignLadyDone::
    setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
    return

PalletTown_EventScript_SetSignLadyPos::
    goto_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_MoveSignLadyToRouteEntrance
    setobjectxyperm LOCALID_SIGN_LADY, 5, 15
    setobjectmovementtype LOCALID_SIGN_LADY, MOVEMENT_TYPE_FACE_UP
    return

PalletTown_EventScript_MoveSignLadyToRouteEntrance::
    setobjectxyperm LOCALID_SIGN_LADY, 12, 2
    setobjectmovementtype LOCALID_SIGN_LADY, MOVEMENT_TYPE_FACE_DOWN
    setvar SIGN_LADY_READY, TRUE
    return

PalletTown_OnFrame:
    map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
    .2byte 0
    
PalletTown_EventScript_OakRatingScene::
    lockall
    setobjectxyperm LOCALID_PROF_OAK, 14, 14
    setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
    addobject LOCALID_PROF_OAK
    applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
    waitmovement 0
    msgbox PalletTown_Text_OakLetMeSeePokedex, MSGBOX_DEFAULT
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, ScriptGetPokedexInfo
    copyvar VAR_0x8008, VAR_0x8005
    copyvar VAR_0x8009, VAR_0x8006
    buffernumberstring 0, VAR_0x8008
    buffernumberstring 1, VAR_0x8009
    compare VAR_0x8009, 60
    goto_if_lt PalletTown_EventScript_NotEnoughMonsForNationalDex
    msgbox PalletTown_Text_CaughtXImpressiveFollowMe, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_RG_FOLLOW_ME, 0
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
    applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
    waitmovement 0
    opendoor 16, 13
    waitdooranim
    applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
    waitmovement 0
    closedoor 16, 13
    waitdooranim
    setvar VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 7
    setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
    setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
    warp MAP_PROFESSOR_OAKS_LAB, 255, 6, 12
    waitstate
    releaseall
    end

PalletTown_Movement_OakWalkToPlayersDoor::
    walk_left
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_in_place_faster_up
    step_end

PalletTown_EventScript_NotBeenToOneIslandYet::
    msgbox PalletTown_Text_OakYouEnjoyingTravelling, MSGBOX_DEFAULT
    goto PalletTown_EventScript_EndOakRatingScene
    end

PalletTown_EventScript_EndOakRatingScene::
    closemessage
    applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakExit
    waitmovement 0
    removeobject LOCALID_PROF_OAK
    setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
    releaseall
    end

PalletTown_Movement_OakExit::
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
    walk_right
    walk_right
    walk_right
    step_end

PalletTown_EventScript_NotEnoughMonsForNationalDex::
    msgbox PalletTown_Text_CaughtXPuttingInHonestEffort, MSGBOX_DEFAULT
    goto PalletTown_EventScript_EndOakRatingScene
    end

PalletTown_Movement_PlayerWalkToLabFromHouse::
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
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

PalletTown_Movement_OakWalkToLabFromHouse::
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
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_in_place_faster_up
    step_end

PalletTown_Movement_OakEnterLab::
    walk_up
    set_invisible
    step_end

PalletTown_Movement_PlayerEnterLab::
    walk_right
    walk_up
    set_invisible
    step_end

PalletTown_EventScript_SignLady::
    lock
    compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
    goto_if_eq PalletTown_EventScript_SignLadyDone
    compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
    goto_if_eq PalletTown_EventScript_SignLadyJustShowedSign
    compare SIGN_LADY_READY, TRUE
    goto_if_eq PalletTown_EventScript_SignLadyStartShowSign
    goto_if_set FLAG_TEMP_2, PalletTown_EventScript_SignLadyGoReadSign
    msgbox PalletTown_Text_HmmIsThatRight, MSGBOX_DEFAULT
    applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_SIGN_LADY, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_SIGN_LADY, Common_Movement_Delay48
    waitmovement 0
    msgbox PalletTown_Text_OhLookLook, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_EAST
    call_if_eq PalletTown_EventScript_SignLadyMoveOutOfWayRight
    compare VAR_FACING, DIR_EAST
    call_if_ne PalletTown_EventScript_SignLadyMoveOutOfWayLeft
    copyobjectxytoperm 1
    setflag FLAG_TEMP_2
    release
    end

PalletTown_EventScript_SignLadyDone::
    applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
    waitmovement 0
    msgbox PalletTown_Text_RaisingMonsToo, MSGBOX_DEFAULT
    release
    end

PalletTown_EventScript_SignLadyJustShowedSign::
    applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
    waitmovement 0
    msgbox PalletTown_Text_SignsAreUsefulArentThey, MSGBOX_DEFAULT
    release
    end

PalletTown_EventScript_SignLadyStartShowSign::
    applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
    waitmovement 0
    call PalletTown_EventScript_SignLadyShowSign
    release
    end

PalletTown_EventScript_SignLadyShowSign::
    msgbox PalletTown_Text_LookCopiedTrainerTipsSign, MSGBOX_DEFAULT
    closemessage
    delay 20
    setflag FLAG_OPENED_START_MENU
    setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
    setvar SIGN_LADY_READY, FALSE
    msgbox PalletTown_Text_PressStartToOpenMenuCopy, MSGBOX_SIGN
    return

PalletTown_EventScript_SignLadyGoReadSign::
    applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
    waitmovement 0
    msgbox PalletTown_Text_ReadItReadIt, MSGBOX_DEFAULT
    release
    end

PalletTown_EventScript_SignLadyMoveOutOfWayRight::
    applymovement LOCALID_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayRight
    waitmovement 0
    return

PalletTown_Movement_SignLadyMoveOutOfWayRight::
    walk_right
    walk_in_place_faster_left
    step_end

PalletTown_EventScript_SignLadyMoveOutOfWayLeft::
    applymovement LOCALID_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayLeft
    waitmovement 0
    return

PalletTown_Movement_SignLadyMoveOutOfWayLeft::
    walk_left
    walk_in_place_faster_right
    step_end

PalletTown_EventScript_FatMan::
    msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
    end

PalletTown_EventScript_OakTriggerLeft::
    lockall
    setvar VAR_TEMP_1, 0
    goto PalletTown_EventScript_OakTrigger
    end

PalletTown_EventScript_OakTriggerRight::
    lockall
    setvar VAR_TEMP_1, 1
    goto PalletTown_EventScript_OakTrigger
    end

PalletTown_EventScript_OakTrigger::
    delay 30
    playbgm MUS_RG_OAK, 0
    message PalletTown_Text_OakDontGoOut
    waitmessage
    delay 85
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    playse SE_PIN
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
    waitmovement 0
    delay 30
    addobject LOCALID_PROF_OAK
    compare VAR_TEMP_1, 0
    call_if_eq PalletTown_EventScript_OakEnterLeft
    compare VAR_TEMP_1, 1
    call_if_eq PalletTown_EventScript_OakEnterRight
    delay 30
    msgbox PalletTown_Text_OakGrassUnsafeNeedMon, MSGBOX_DEFAULT
    closemessage
    delay 30
    compare VAR_TEMP_1, 0
    call_if_eq PalletTown_EventScript_OakLeadPlayerToLabLeft
    compare VAR_TEMP_1, 1
    call_if_eq PalletTown_EventScript_OakLeadPlayerToLabRight
    opendoor 16, 13
    waitdooranim
    applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
    waitmovement 0
    closedoor 16, 13
    waitdooranim
    setvar VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 1
    clearflag FLAG_HIDE_OAK_IN_HIS_LAB
    setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
    setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
    setflag FLAG_DONT_TRANSITION_MUSIC
    warp MAP_PROFESSOR_OAKS_LAB, 255, 6, 12
    waitstate
    releaseall
    end

PalletTown_EventScript_OakEnterLeft::
    applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLeft
    waitmovement 0
    return

PalletTown_Movement_OakEnterLeft::
    walk_up
    walk_up
    walk_right
    walk_up
    walk_up
    walk_right
    walk_up
    walk_up
    step_end

PalletTown_EventScript_OakEnterRight::
    applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterRight
    waitmovement 0
    return

PalletTown_Movement_OakEnterRight::
    walk_right
    walk_up
    walk_up
    walk_right
    walk_up
    walk_up
    walk_right
    walk_up
    walk_up
    step_end

PalletTown_EventScript_OakLeadPlayerToLabLeft::
    applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
    waitmovement 0
    return

PalletTown_Movement_OakWalkToLabLeft::
    walk_down
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_in_place_faster_up
    step_end

PalletTown_Movement_PlayerWalkToLabLeft:: @ 8165731
    walk_down
    walk_down
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

PalletTown_EventScript_OakLeadPlayerToLabRight::
    applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
    applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
    waitmovement 0
    return

PalletTown_Movement_OakWalkToLabRight::
    walk_down
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_in_place_faster_up
    step_end

PalletTown_Movement_PlayerWalkToLabRight:: @ 8165744
    walk_down
    walk_down
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

PalletTown_EventScript_SignLadyTrigger::
    lockall
    applymovement LOCALID_SIGN_LADY, Common_Movement_WalkInPlaceFasterRight
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    call PalletTown_EventScript_SignLadyShowSign
    releaseall
    end

PalletTown_EventScript_MomTriggerLeft::
    opendoor 6, 7
    waitdooranim
    addobject LOCALID_MOM
    message PalletTown_Text_MomWait
    waitmessage
    delay 85
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    playse SE_PIN
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
    waitmovement 0
    goto PalletTown_EventScript_MomTrigger
    releaseall
    end

PalletTown_EventScript_MomTriggerRight::
    opendoor 6, 7
    waitdooranim
    addobject LOCALID_MOM
    message PalletTown_Text_MomWait
    waitmessage
    delay 85
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    playse SE_PIN
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
    waitmovement 0
    goto PalletTown_EventScript_MomTrigger
    releaseall
    end
    
PalletTown_EventScript_MomTrigger::
    delay 30
    applymovement LOCALID_MOM, PalletTown_Movement_MomWalkOutDoor
    waitmovement 0
    closedoor 6, 7
    waitdooranim
    applymovement LOCALID_MOM, PalletTown_Movement_MomWalkToPlayer
    waitmovement 0
    applymovement LOCALID_MOM, Common_Movement_FacePlayer
    waitmovement 0
    call PalletTown_EventScript_GiveRunningShoes
    applymovement LOCALID_MOM, PalletTown_Movement_MomWalkHome
    waitmovement 0
    opendoor 6, 7
    waitdooranim
    applymovement LOCALID_MOM, PalletTown_Movement_MomWalkInside
    waitmovement 0
    removeobject LOCALID_MOM
    closedoor 6, 7
    waitdooranim
    setvar VAR_MAP_SCENE_PALLET_TOWN_MOM, 2
    setflag FLAG_SYS_B_DASH
    setflag FLAG_SYS_TV_HOME
    releaseall
    end

PalletTown_Movement_MomWalkOutDoor::
    walk_down
    step_end

PalletTown_Movement_MomWalkToPlayer::
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_right
    walk_up
    step_end

PalletTown_EventScript_GiveRunningShoes::
    msgbox PalletTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
    playfanfare MUS_OBTAIN_ITEM
    message PalletTown_Text_SwitchShoesWithRunningShoes
    waitfanfare
    setflag FLAG_RECEIVED_RUNNING_SHOES
    msgbox PalletTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
    msgbox PalletTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
    closemessage
    delay 30
    return

PalletTown_Movement_MomWalkHome::
    walk_down
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

PalletTown_Movement_MomWalkInside::
    walk_up
    step_end

PalletTown_EventScript_OaksLabSign::
    lockall
    msgbox PalletTown_Text_OakPokemonResearchLab, MSGBOX_SIGN
    releaseall
    end

PalletTown_EventScript_PlayersHouseSign::
    msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
    end

PalletTown_EventScript_RivalsHouseSign::
    msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
    end

PalletTown_EventScript_TownSign::
    msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
    end

PalletTown_EventScript_TrainerTips::
    lockall
    msgbox PalletTown_Text_PressStartToOpenMenu, MSGBOX_SIGN
    setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
    releaseall
    end

PalletTown_Text_OakYouEnjoyingTravelling::
    .string "Oak: Ah, {PLAYER}!\n"
    .string "You seem to be enjoying travelling.\p"
    .string "Knowing you, {PLAYER}, I can easily\n"
    .string "imagine you going out to even more\l"
    .string "exotic locales.\p"
    .string "Good for you, good for you.\n"
    .string "Hohoho.$"

PalletTown_Text_OakLetMeSeePokedex::
    .string "Oak: Ah, {PLAYER}!\n"
    .string "You're back, are you?\p"
    .string "How much have you filled in your\n"
    .string "Pokédex?\p"
    .string "May I see it?\p"
    .string "Let's see…$"

PalletTown_Text_CaughtXPuttingInHonestEffort::
    .string "You've caught {STR_VAR_2}…\p"
    .string "Hm, it looks as if you're putting\n"
    .string "in an honest effort.\p"
    .string "When you manage to fill it some\n"
    .string "more, come show me, please.$"

PalletTown_Text_CaughtXImpressiveFollowMe::
    .string "You've caught… {STR_VAR_2}!?\n"
    .string "Now, this is impressive!\p"
    .string "There's something I wanted to ask\n"
    .string "of you, {PLAYER}.\p"
    .string "Come.\n"
    .string "Follow me.$"

PalletTown_Text_RaisingMonsToo::
    .string "I'm raising Pokémon, too.\p"
    .string "When they get strong, they can\n"
    .string "protect me.$"

PalletTown_Text_SignsAreUsefulArentThey::
    .string "Signs are useful, aren't they?$"

PalletTown_Text_LookCopiedTrainerTipsSign::
    .string "Look, look!\p"
    .string "I copied what it said on one of\n"
    .string "those 'Trainer Tips' signs!$"
    
PalletTown_Text_PressStartToOpenMenuCopy::
    .string "Trainer Tips!\p"
    .string "Press Start to open the Menu!$"

PalletTown_Text_ReadItReadIt::
    .string "Read it, read it!$"

PalletTown_Text_HmmIsThatRight::
    .string "Hmm…\n"
    .string "Is that right…$"

PalletTown_Text_OhLookLook::
    .string "Oh!\n"
    .string "Look, look!$"

PalletTown_Text_CanStoreItemsAndMonsInPC::
    .string "Technology is incredible!\p"
    .string "You can now store and recall items\n"
    .string "and Pokémon as data via PC.$"

PalletTown_Text_OakDontGoOut::
    .string "Oak: Hey! Wait!\n"
    .string "Don't go out!$"

PalletTown_Text_OakGrassUnsafeNeedMon::
    .string "Oak: It's unsafe!\n"
    .string "Wild Pokémon live in tall grass!\p"
    .string "You need your own Pokémon for\n"
    .string "your protection.\p"
    .string "I know!\n"
    .string "Here, come with me!$"

PalletTown_Text_MomWait::
    .string "Mom: Wait, {PLAYER}!$"
    
PalletTown_Text_WearTheseRunningShoes::
    .string "Mom: {PLAYER}! {PLAYER}! Did you\n"
    .string "introduce yourself to Prof. Oak?\p"
    .string "Oh! What an adorable Pokémon!\n"
    .string "You got it from Prof. Oak. How nice!\p"
    .string "You're your father's child, all right.\n"
    .string "You look good together with Pokémon!\p"
    .string "Here, honey! If you're going out on an\n"
    .string "adventure, wear these Running Shoes.\p"
    .string "They'll put a zip in your step!$"

PalletTown_Text_SwitchShoesWithRunningShoes:
    .string "{PLAYER} switched shoes with the\n"
    .string "Running Shoes.$"

PalletTown_Text_ExplainRunningShoes:
    .string "Mom: {PLAYER}, those shoes came with\n"
    .string "instructions.\p"
    .string "“Press the B Button while wearing these\n"
    .string "Running Shoes to run extra-fast!\p"
    .string "“Slip on these Running Shoes and race\n"
    .string "in the great outdoors!”$"

PalletTown_Text_ComeHomeIfAnythingHappens:
    .string "… … … … … … … …\n"
    .string "… … … … … … … …\p"
    .string "To think that you have your very own\n"
    .string "Pokémon now…\l"
    .string "Your father will be overjoyed.\p"
    .string "…But please be careful.\n"
    .string "If anything happens, you can come home.\p"
    .string "Go on, go get them, honey!$"

PalletTown_Text_OakPokemonResearchLab::
    .string "Oak Pokémon Research Lab$"

PalletTown_Text_PlayersHouse::
    .string "{PLAYER}'s house$"

PalletTown_Text_RivalsHouse::
    .string "{RIVAL}'s house$"

PalletTown_Text_TownSign::
    .string "Pallet Town\n"
    .string "Shades of your journey await!$"
    
PalletTown_Text_PressStartToOpenMenu::
    .string "Trainer Tips!\p"
    .string "Press Start to open the Menu!$"
