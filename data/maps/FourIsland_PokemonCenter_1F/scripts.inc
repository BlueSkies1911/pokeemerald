.set LOCALID_NURSE, 1

FourIsland_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    .byte 0

FourIsland_PokemonCenter_1F_OnTransition:
    setrespawn HEAL_LOCATION_FOUR_ISLAND
    end

FourIsland_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

FourIsland_PokemonCenter_1F_EventScript_Man::
    msgbox FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave, MSGBOX_NPC
    end

FourIsland_PokemonCenter_1F_EventScript_Woman::
    msgbox FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore, MSGBOX_NPC
    end

FourIsland_PokemonCenter_1F_EventScript_Gentleman::
    msgbox FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived, MSGBOX_NPC
    end

FourIsland_PokemonCenter_1F_EventScript_PokemonJournal::
    msgbox PokemonJournal_Text_SpecialFeatureDaisyOak, MSGBOX_SIGN
    end

FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave::
    .string "There's a rare kind of Ice Pokémon\n"
    .string "that lives in the cave.\p"
    .string "We get a lot of visitors hoping to\n"
    .string "see that Pokémon.$"

FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore::
    .string "Oh? A Pokémon Egg?\n"
    .string "…I have no idea.\p"
    .string "…Oh, wait. The Day-Care people\n"
    .string "in town were saying something.\p"
    .string "They said that they'd found Eggs\n"
    .string "before on their property.$"

FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived::
    .string "What's this?\p"
    .string "The new Pokémon Journal hasn't\n"
    .string "arrived on this island?$"

PokemonJournal_Text_SpecialFeatureDaisyOak:: @ 81B1B3D
    .string "This is a Pokémon Journal from\n"
    .string "years ago…\p"
    .string "Pokémon Journal\n"
    .string "Contest Special!\p"
    .string "The Spring Pokémon Contest's\n"
    .string "Grand Champion is Daisy Oak of\l"
    .string "Pallet Town!$"
