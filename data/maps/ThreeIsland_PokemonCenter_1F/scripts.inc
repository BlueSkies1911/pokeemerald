.set LOCALID_NURSE, 1

ThreeIsland_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    .byte 0

ThreeIsland_PokemonCenter_1F_OnTransition:
    setrespawn HEAL_LOCATION_THREE_ISLAND
    end

ThreeIsland_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

ThreeIsland_PokemonCenter_1F_EventScript_Sailor::
    msgbox ThreeIsland_PokemonCenter_1F_Text_ImpossibleToSurfBetweenIslands, MSGBOX_NPC
    end

ThreeIsland_PokemonCenter_1F_EventScript_Lass::
    msgbox ThreeIsland_PokemonCenter_1F_Text_AlwaysBerriesInBerryForest, MSGBOX_NPC
    end

ThreeIsland_PokemonCenter_1F_EventScript_Rocker::
    msgbox ThreeIsland_PokemonCenter_1F_Text_PCNetworkCanLinkWithKanto, MSGBOX_NPC
    end

ThreeIsland_PokemonCenter_1F_Text_PCNetworkCanLinkWithKanto::
    .string "Hey, did you hear the news?\p"
    .string "The PC network here can now link\n"
    .string "with PCs in Kanto.\p"
    .string "I don't know how that came about,\n"
    .string "but it's fantastic!$"

ThreeIsland_PokemonCenter_1F_Text_ImpossibleToSurfBetweenIslands::
    .string "It's impossible to Surf between the\n"
    .string "islands around these parts.\p"
    .string "The tides are too fast and\n"
    .string "treacherous.$"

ThreeIsland_PokemonCenter_1F_Text_AlwaysBerriesInBerryForest::
    .string "Let's crush berries!\n"
    .string "…That'd be wasting berries?\p"
    .string "You can always find some berries\n"
    .string "on the ground in Berry Forest.$"
