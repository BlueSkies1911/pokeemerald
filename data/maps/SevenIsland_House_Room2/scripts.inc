SevenIsland_House_Room2_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_House_Room2_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, SevenIsland_House_Room2_OnFrame
    .byte 0

SevenIsland_House_Room2_OnTransition:
    special SetEReaderTrainerGfxId
    end

SevenIsland_House_Room2_OnFrame:
    map_script_2 VAR_TEMP_1, 0, SevenIsland_House_Room2_EventScript_BattleVisitingTrainer
    .2byte 0

SevenIsland_House_Room2_EventScript_BattleVisitingTrainer::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, SevenIsland_House_Room2_Movement_PlayerEnterRoom
    waitmovement 0
    special CopyEReaderTrainerGreeting
    msgbox gStringVar4, MSGBOX_DEFAULT
    closemessage
    setvar VAR_0x8004, SPECIAL_BATTLE_EREADER
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    call_if_eq VAR_RESULT, B_OUTCOME_DREW, SevenIsland_House_Room2_EventScript_BattleTie
    call_if_eq VAR_RESULT, B_OUTCOME_WON, SevenIsland_House_Room2_EventScript_BattleWon
    call_if_eq VAR_RESULT, B_OUTCOME_LOST, SevenIsland_House_Room2_EventScript_BattleLost
    closemessage
    special HealPlayerParty
    applymovement OBJ_EVENT_ID_PLAYER, SevenIsland_House_Room2_Movement_PlayerExitRoom
    waitmovement 0
    special LoadPlayerParty
    setvar VAR_TEMP_1, 1
    warp MAP_SEVEN_ISLAND_HOUSE_ROOM1, 4, 1
    waitstate
    releaseall
    end

SevenIsland_House_Room2_EventScript_BattleTie::
    setvar VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 3
    msgbox SevenIsland_House_Room2_Text_MatchEndedUpDraw, MSGBOX_DEFAULT
    return

SevenIsland_House_Room2_EventScript_BattleWon::
    setvar VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 1
    special ShowFieldMessageStringVar4
    waitmessage
    waitbuttonpress
    return

SevenIsland_House_Room2_EventScript_BattleLost::
    setvar VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 2
    special ShowFieldMessageStringVar4
    waitmessage
    waitbuttonpress
    return

SevenIsland_House_Room2_Movement_PlayerEnterRoom:
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    step_end

SevenIsland_House_Room2_Movement_PlayerExitRoom:
    walk_left
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    delay_8
    step_end
