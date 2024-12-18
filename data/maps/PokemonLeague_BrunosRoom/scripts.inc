.set LOCALID_BRUNO, 1

PokemonLeague_BrunosRoom_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
    map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_BrunosRoom_OnLoad
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_BrunosRoom_OnWarp
    map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_BrunosRoom_OnFrame
    .byte 0

PokemonLeague_BrunosRoom_OnResume:
    setvar VAR_0x8004, 1
    call PokemonLeague_EventScript_DoLightingEffect
    end

PokemonLeague_BrunosRoom_OnLoad:
    call_if_set FLAG_DEFEATED_BRUNO, PokemonLeague_BrunosRoom_EventScript_SetDoorOpen
    compare VAR_MAP_SCENE_POKEMON_LEAGUE, 2
    call_if_eq PokemonLeague_BrunosRoom_EventScript_CloseEntry
    end

PokemonLeague_BrunosRoom_EventScript_CloseEntry::
    call PokemonLeague_EventScript_CloseEntry
    return

PokemonLeague_BrunosRoom_EventScript_SetDoorOpen::
    call PokemonLeague_EventScript_SetDoorOpen
    return

PokemonLeague_BrunosRoom_OnWarp:
    map_script_2 VAR_TEMP_1, 0, PokemonLeague_BrunosRoom_EventScript_TurnPlayerNorth
    .2byte 0

PokemonLeague_BrunosRoom_EventScript_TurnPlayerNorth::
    turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
    end

PokemonLeague_BrunosRoom_OnFrame:
    map_script_2 VAR_MAP_SCENE_POKEMON_LEAGUE, 1, PokemonLeague_BrunosRoom_EventScript_EnterRoom
    .2byte 0

PokemonLeague_BrunosRoom_EventScript_EnterRoom::
    lockall
    call PokemonLeague_EventScript_EnterRoom
    setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 2
    releaseall
    end

PokemonLeague_BrunosRoom_EventScript_Bruno::
    lock
    faceplayer
    goto_if_set FLAG_DEFEATED_BRUNO, PokemonLeague_BrunosRoom_EventScript_PostBattle
    call_if_unset FLAG_SYS_GAME_CLEAR, PokemonLeague_BrunosRoom_EventScript_Intro
    call_if_set FLAG_SYS_GAME_CLEAR, PokemonLeague_BrunosRoom_EventScript_RematchIntro
    setflag FLAG_TEMP_3
    setflag FLAG_TEMP_5
    call_if_unset FLAG_SYS_CAN_LINK_WITH_RS, PokemonLeague_BrunosRoom_EventScript_Battle
    call_if_set FLAG_SYS_CAN_LINK_WITH_RS, PokemonLeague_BrunosRoom_EventScript_Rematch
    clearflag FLAG_TEMP_5
    goto PokemonLeague_BrunosRoom_EventScript_DefeatedBruno
    end

PokemonLeague_BrunosRoom_EventScript_Intro::
    msgbox PokemonLeague_BrunosRoom_Text_Intro, MSGBOX_DEFAULT
    return

PokemonLeague_BrunosRoom_EventScript_RematchIntro::
    msgbox PokemonLeague_BrunosRoom_Text_RematchIntro, MSGBOX_DEFAULT
    return

PokemonLeague_BrunosRoom_EventScript_Battle::
    trainerbattle_no_intro TRAINER_ELITE_FOUR_BRUNO, PokemonLeague_BrunosRoom_Text_Defeat
    return

PokemonLeague_BrunosRoom_EventScript_Rematch::
    trainerbattle_no_intro TRAINER_ELITE_FOUR_BRUNO_2, PokemonLeague_BrunosRoom_Text_Defeat
    return

PokemonLeague_BrunosRoom_EventScript_PostBattle::
    msgbox PokemonLeague_BrunosRoom_Text_PostBattle, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_NORTH
    call_if_eq PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayRight
    compare VAR_FACING, DIR_SOUTH
    call_if_eq PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayLeft
    compare VAR_FACING, DIR_WEST
    call_if_eq PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
    compare VAR_FACING, DIR_EAST
    call_if_eq PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
    release
    end

PokemonLeague_BrunosRoom_EventScript_DefeatedBruno::
    setflag FLAG_DEFEATED_BRUNO
    call PokemonLeague_EventScript_OpenDoor
    msgbox PokemonLeague_BrunosRoom_Text_PostBattle, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_NORTH
    call_if_eq PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayRight
    compare VAR_FACING, DIR_SOUTH
    call_if_eq PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayLeft
    compare VAR_FACING, DIR_WEST
    call_if_eq PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
    compare VAR_FACING, DIR_EAST
    call_if_eq PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
    release
    end

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayLeft::
    applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    return

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayRight::
    applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    return

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown::
    applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

PokemonLeague_BrunosRoom_Text_Intro::
    .string "I am Bruno of the Elite Four!\p"
    .string "Through rigorous training, people\n"
    .string "and Pokémon can become stronger\l"
    .string "without limit.\p"
    .string "I've lived and trained with my\n"
    .string "fighting Pokémon!\l"
    .string "And that will never change!\p"
    .string "{PLAYER}!\p"
    .string "We will grind you down with our\n"
    .string "superior power!\p"
    .string "Hoo hah!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PokemonLeague_BrunosRoom_Text_RematchIntro::
    .string "I am Bruno of the Elite Four!\p"
    .string "Through rigorous training, people\n"
    .string "and Pokémon can become stronger\l"
    .string "without limit.\p"
    .string "I've lived and trained with my\n"
    .string "fighting Pokémon!\l"
    .string "And that will never change!\p"
    .string "{PLAYER}!\p"
    .string "We will grind you down with our\n"
    .string "superior power!\p"
    .string "Hoo hah!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PokemonLeague_BrunosRoom_Text_Defeat::
    .string "Why?\n"
    .string "How could I lose?$"

PokemonLeague_BrunosRoom_Text_PostBattle::
    .string "My job is done.\n"
    .string "Go face your next challenge.$"
