PokemonLeague_AgathasRoom_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_AgathasRoom_OnResume
    map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_AgathasRoom_OnLoad
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_AgathasRoom_OnWarp
    map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_AgathasRoom_OnFrame
    .byte 0

PokemonLeague_AgathasRoom_OnResume:
    setvar VAR_0x8004, 2
    call PokemonLeague_EventScript_DoLightingEffect
    end

PokemonLeague_AgathasRoom_OnLoad:
    call_if_set FLAG_DEFEATED_AGATHA, PokemonLeague_AgathasRoom_EventScript_SetDoorOpen
    compare VAR_MAP_SCENE_POKEMON_LEAGUE, 3
    call_if_eq PokemonLeague_AgathasRoom_EventScript_CloseEntry
    end

PokemonLeague_AgathasRoom_EventScript_CloseEntry::
    call PokemonLeague_EventScript_CloseEntry
    return

PokemonLeague_AgathasRoom_EventScript_SetDoorOpen::
    call PokemonLeague_EventScript_SetDoorOpen
    return

PokemonLeague_AgathasRoom_OnWarp:
    map_script_2 VAR_TEMP_1, 0, PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth
    .2byte 0

PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth::
    turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
    end

PokemonLeague_AgathasRoom_OnFrame:
    map_script_2 VAR_MAP_SCENE_POKEMON_LEAGUE, 2, PokemonLeague_AgathasRoom_EventScript_EnterRoom
    .2byte 0

PokemonLeague_AgathasRoom_EventScript_EnterRoom::
    lockall
    call PokemonLeague_EventScript_EnterRoom
    setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 3
    releaseall
    end

PokemonLeague_AgathasRoom_EventScript_Agatha::
    lock
    faceplayer
    goto_if_set FLAG_DEFEATED_AGATHA, PokemonLeague_AgathasRoom_EventScript_PostBattle
    call_if_unset FLAG_SYS_GAME_CLEAR, PokemonLeague_AgathasRoom_EventScript_Intro
    call_if_set FLAG_SYS_GAME_CLEAR, PokemonLeague_AgathasRoom_EventScript_RematchIntro
    setflag FLAG_TEMP_3
    setflag FLAG_TEMP_5
    call_if_unset FLAG_SYS_CAN_LINK_WITH_RS, PokemonLeague_AgathasRoom_EventScript_Battle
    call_if_set FLAG_SYS_CAN_LINK_WITH_RS, PokemonLeague_AgathasRoom_EventScript_Rematch
    clearflag FLAG_TEMP_5
    goto PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha
    end

PokemonLeague_AgathasRoom_EventScript_Intro::
    msgbox PokemonLeague_AgathasRoom_Text_Intro, MSGBOX_DEFAULT
    return

PokemonLeague_AgathasRoom_EventScript_RematchIntro::
    msgbox PokemonLeague_AgathasRoom_Text_RematchIntro
    return

PokemonLeague_AgathasRoom_EventScript_Battle::
    trainerbattle_no_intro TRAINER_ELITE_FOUR_AGATHA, PokemonLeague_AgathasRoom_Text_Defeat
    return

PokemonLeague_AgathasRoom_EventScript_Rematch::
    trainerbattle_no_intro TRAINER_ELITE_FOUR_AGATHA_2, PokemonLeague_AgathasRoom_Text_Defeat
    return

PokemonLeague_AgathasRoom_EventScript_PostBattle::
    msgbox PokemonLeague_AgathasRoom_Text_PostBattle, MSGBOX_DEFAULT
    release
    end

PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha::
    setflag FLAG_DEFEATED_AGATHA
    call PokemonLeague_EventScript_OpenDoor
    msgbox PokemonLeague_AgathasRoom_Text_PostBattle, MSGBOX_DEFAULT
    release
    end

PokemonLeague_AgathasRoom_Text_Intro::
    .string "I am Agatha of the Elite Four.\p"
    .string "I hear Oak's taken a lot of\n"
    .string "interest in you, child.\p"
    .string "That old duff was once tough and\n"
    .string "handsome.\p"
    .string "But that was decades ago.\n"
    .string "He's a shadow of his former self.\p"
    .string "Now he just wants to fiddle with\n"
    .string "his Pokédex.\p"
    .string "He's wrong.\n"
    .string "Pokémon are for battling!\p"
    .string "{PLAYER}! I'll show you how a real\n"
    .string "Trainer battles!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PokemonLeague_AgathasRoom_Text_RematchIntro::
    .string "I am Agatha of the Elite Four.\p"
    .string "You're the child that Oak's taken\n"
    .string "under his wing, aren't you?\p"
    .string "That old duff was once tough and\n"
    .string "handsome.\p"
    .string "But that was decades ago.\n"
    .string "He's a shadow of his former self.\p"
    .string "Now he just wants to fiddle with\n"
    .string "his Pokédex.\p"
    .string "He's wrong.\n"
    .string "Pokémon are for battling!\p"
    .string "{PLAYER}! I'll show you how a real\n"
    .string "Trainer battles!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PokemonLeague_AgathasRoom_Text_Defeat::
    .string "Oh, my!\n"
    .string "You're something special, child!$"

PokemonLeague_AgathasRoom_Text_PostBattle::
    .string "You win!\p"
    .string "I see what the old duff sees in\n"
    .string "you now.\p"
    .string "I have nothing else to say.\n"
    .string "Run along now, child!$"
