PokemonLab_Entrance_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, PokemonLab_Entrance_OnTransition
	.byte 0

PokemonLab_Entrance_OnTransition:
    compare VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
    call_if_eq PokemonLab_Entrance_EventScript_ReadyFossil
    end

PokemonLab_Entrance_EventScript_ReadyFossil::
    setvar VAR_MAP_SCENE_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2
    return

PokemonLab_Entrance_EventScript_Scientist::
    msgbox PokemonLab_Entrance_Text_StudyMonsExtensively, MSGBOX_NPC
    end

PokemonLab_Entrance_EventScript_DrFujiPhoto::
    msgbox PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji, MSGBOX_SIGN
    end

PokemonLab_Entrance_EventScript_MeetingRoomSign::
    msgbox PokemonLab_Entrance_Text_MeetingRoomSign, MSGBOX_SIGN
    end

PokemonLab_Entrance_EventScript_RAndDRoomSign::
    msgbox PokemonLab_Entrance_Text_RAndDRoomSign, MSGBOX_SIGN
    end

PokemonLab_Entrance_EventScript_TestingRoomSign::
    msgbox PokemonLab_Entrance_Text_TestingRoomSign, MSGBOX_SIGN
    end

PokemonLab_Entrance_Text_StudyMonsExtensively::
    .string "We study Pokémon extensively\n"
    .string "every day.\p"
    .string "People often bring us rare Pokémon\n"
    .string "for examination.$"

PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji::
    .string "A photo of the lab's founder…\n"
    .string "Dr. Fuji?!$"

PokemonLab_Entrance_Text_MeetingRoomSign::
    .string "Pokémon Lab\n"
    .string "Meeting Room$"

PokemonLab_Entrance_Text_RAndDRoomSign::
    .string "Pokémon Lab\n"
    .string "R & D Room$"

PokemonLab_Entrance_Text_TestingRoomSign::
    .string "Pokémon Lab\n"
    .string "Testing Room$"
