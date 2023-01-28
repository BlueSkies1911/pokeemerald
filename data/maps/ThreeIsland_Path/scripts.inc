.set LOCALID_PROSPECTOR, 1

ThreeIsland_Path_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_Path_OnTransition
    .byte 0

ThreeIsland_Path_OnTransition:
    setflag FLAG_WORLD_MAP_THREE_ISLAND_PATH
    specialvar VAR_RESULT, IsNationalPokedexEnabled
    copyvar VAR_0x8008, VAR_RESULT
    compare VAR_0x8008, TRUE
    call_if_eq ThreeIsland_Path_EventScript_SetLayoutDugOut
    compare VAR_0x8008, FALSE
    call_if_eq ThreeIsland_Path_EventScript_MoveProspectorToWall
    end

ThreeIsland_Path_EventScript_SetLayoutDugOut::
    setmaplayoutindex LAYOUT_THREE_ISLAND_PATH_DUG_OUT
    return

ThreeIsland_Path_EventScript_MoveProspectorToWall::
    setobjectxyperm LOCALID_PROSPECTOR, 6, 3
    setobjectmovementtype LOCALID_PROSPECTOR, MOVEMENT_TYPE_FACE_RIGHT
    return

ThreeIsland_Path_EventScript_Prospector::
    lock
    faceplayer
    goto_if_set FLAG_GOT_NUGGET_FROM_THREE_ISLAND_PATH, ThreeIsland_Path_EventScript_ProspectorAlreadyGaveNugget
    specialvar VAR_RESULT, IsNationalPokedexEnabled
    compare VAR_RESULT, TRUE
    goto_if_eq ThreeIsland_Path_EventScript_ProspectorStruckGold
    msgbox ThreeIsland_Path_Text_ProspectingForGold, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_PROSPECTOR, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

ThreeIsland_Path_EventScript_ProspectorStruckGold::
    msgbox ThreeIsland_Path_Text_StruckGoldThisIsForYou, MSGBOX_DEFAULT
    giveitem ITEM_NUGGET
    compare VAR_RESULT, FALSE
    goto_if_eq ThreeIsland_Path_EventScript_NoRoomForNugget
    setflag FLAG_GOT_NUGGET_FROM_THREE_ISLAND_PATH
    goto ThreeIsland_Path_EventScript_ProspectorAlreadyGaveNugget
    end

ThreeIsland_Path_EventScript_NoRoomForNugget::
    msgbox ThreeIsland_Path_Text_WhoopsBagCrammedFull, MSGBOX_DEFAULT
    release
    end

ThreeIsland_Path_EventScript_ProspectorAlreadyGaveNugget::
    msgbox ThreeIsland_Path_Text_ThatsANugget, MSGBOX_DEFAULT
    release
    end

ThreeIsland_Path_Text_ProspectingForGold::
    .string "Hey, there!\n"
    .string "How's it going?\p"
    .string "What am I doing here, you ask?\n"
    .string "Why, I'm prospecting for gold!\p"
    .string "When I strike it rich, I'm buying\n"
    .string "a house in Kanto.$"

ThreeIsland_Path_Text_StruckGoldThisIsForYou::
    .string "Hey, there! How's it going?\n"
    .string "Did you hear? I've struck gold!\p"
    .string "You remembered that I was\n"
    .string "prospecting, didn't you?\p"
    .string "You can't begin to imagine just\n"
    .string "how happy I am.\p"
    .string "So, I'll show you!\n"
    .string "This is for you!$"

ThreeIsland_Path_Text_ThatsANugget::
    .string "That's a Nugget!\p"
    .string "I can't give you any nuggets of\n"
    .string "wisdom, so that'll have to do!$"

ThreeIsland_Path_Text_WhoopsBagCrammedFull::
    .string "Whoops, your bag is crammed full!\n"
    .string "I'll give this to you later.$"
