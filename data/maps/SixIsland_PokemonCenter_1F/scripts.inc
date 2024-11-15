.set LOCALID_NURSE, 1
.equ LOCALID_RIVAL, 2

SixIsland_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    map_script MAP_SCRIPT_ON_FRAME_TABLE, SixIsland_PokemonCenter_1F_OnFrame
    .byte 0

SixIsland_PokemonCenter_1F_OnTransition:
    setrespawn HEAL_LOCATION_SIX_ISLAND
    compare VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F, 0
    call_if_eq SixIsland_PokemonCenter_1F_EventScript_ShowRival
    end

SixIsland_PokemonCenter_1F_EventScript_ShowRival::
    clearflag FLAG_HIDE_SIX_ISLAND_POKECENTER_RIVAL
    return

SixIsland_PokemonCenter_1F_OnFrame::
    map_script_2 VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F, 0, SixIsland_PokemonCenter_1F_EventScript_RivalScene
    .2byte 0

SixIsland_PokemonCenter_1F_EventScript_RivalScene::
    lockall
    applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    playbgm MUS_RG_ENCOUNTER_RIVAL, 0
    applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_RIVAL, Common_Movement_Delay48
    waitmovement 0
    delay 25
    applymovement LOCALID_RIVAL, SixIsland_PokemonCenter_1F_Movement_RivalApproach
    waitmovement 0
    msgbox SixIsland_PokemonCenter_1F_Text_RivalImpossibleToGetAllMonsAroundHere, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, SixIsland_PokemonCenter_1F_Movement_PlayerWatchRivalExit
    applymovement LOCALID_RIVAL, SixIsland_PokemonCenter_1F_Movement_RivalExit
    waitmovement 0
    fadedefaultbgm
    playse SE_EXIT
    delay 35
    removeobject LOCALID_RIVAL
    setvar VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F, 1
    setvar VAR_MAP_SCENE_FOUR_ISLAND, 1
    releaseall
    end

SixIsland_PokemonCenter_1F_Movement_RivalApproach::
    walk_right
    walk_right
    walk_down
    walk_down
    step_end

SixIsland_PokemonCenter_1F_Movement_RivalExit::
    delay_16
    delay_4
    walk_down
    step_end

SixIsland_PokemonCenter_1F_Movement_PlayerWatchRivalExit::
    walk_left
    walk_in_place_faster_right
    step_end

SixIsland_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

SixIsland_PokemonCenter_1F_EventScript_Hiker::
    msgbox SixIsland_PokemonCenter_1F_Text_SomethingHiddenOnThisIsland, MSGBOX_NPC
    end

SixIsland_PokemonCenter_1F_EventScript_OldMan::
    msgbox SixIsland_PokemonCenter_1F_Text_SomeMonsEvolveByTradingWithHeldItem, MSGBOX_NPC
    end

SixIsland_PokemonCenter_1F_Text_SomethingHiddenOnThisIsland::
    .string "For ten years, I've searched for\n"
    .string "ruins.\p"
    .string "No, make that twenty years.\p"
    .string "I get this feeling that there's\n"
    .string "something hidden on this island.$"

SixIsland_PokemonCenter_1F_Text_SomeMonsEvolveByTradingWithHeldItem::
    .string "You know of Pokémon that evolve\n"
    .string "only upon trading, yes?\p"
    .string "But did you know that there are\n"
    .string "still others?\p"
    .string "Some Pokémon evolve only when\n"
    .string "traded while holding specific items.$"

SixIsland_PokemonCenter_1F_Text_RivalImpossibleToGetAllMonsAroundHere::
    .string "{RIVAL}: Hey, {PLAYER}!\n"
    .string "How's your Pokédex filling up?\p"
    .string "It looks like it's impossible to get\n"
    .string "all the Pokémon by hanging around\l"
    .string "just these parts.\p"
    .string "Maybe there are Pokémon we don't\n"
    .string "know about somewhere far away…\p"
    .string "… … …  … … …  … … …\p"
    .string "Well, if I can't do it, there's no\n"
    .string "way for you to get it done.\p"
    .string "I'm not going to get all desperate\n"
    .string "over this.\p"
    .string "I'll keep collecting Pokémon at my\n"
    .string "own pace while I train them.\p"
    .string "That's what I'll do.\n"
    .string "So there's no point staying here.\l"
    .string "I may as well leave for home.\p"
    .string "That's that, then!\n"
    .string "Smell ya later!$"
