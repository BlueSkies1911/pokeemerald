.set LOCALID_NURSE, 1
.set LOCALID_BILL, 5

CinnabarIsland_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    .byte 0

CinnabarIsland_PokemonCenter_1F_OnTransition:
    setrespawn HEAL_LOCATION_CINNABAR_ISLAND
    end

CinnabarIsland_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

CinnabarIsland_PokemonCenter_1F_EventScript_Gentleman::
    msgbox CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom, MSGBOX_NPC
    end

CinnabarIsland_PokemonCenter_1F_EventScript_CooltrainerF::
    msgbox CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked, MSGBOX_NPC
    end

CinnabarIsland_PokemonCenter_1F_EventScript_Youngster::
    msgbox CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves, MSGBOX_NPC
    end

CinnabarIsland_PokemonCenter_1F_EventScript_PokemonJournalMrFuji::
    msgbox PokemonJournal_Text_SpecialFeatureMrFuji, MSGBOX_SIGN
    end

CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked::
    .string "I came to visit the Cinnabar Gym,\n"
    .string "but the door is locked tight.\p"
    .string "There should be a key for it\n"
    .string "somewhere.\p"
    .string "Could it be in that burned-out\n"
    .string "mansion?\p"
    .string "The Gym Leader's friend used to\n"
    .string "live there, they say.$"

CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom::
    .string "Do you have lots of friends?\p"
    .string "Linking up with the usual friends\n"
    .string "is fun, of course.\p"
    .string "But how about visiting the\n"
    .string "Union Room every so often?\p"
    .string "Who knows, you may end up making\n"
    .string "new friends.\p"
    .string "I think it would be worth your time\n"
    .string "to check the Union Room.$"

CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves::
    .string "Pokémon can still learn techniques\n"
    .string "after cancelling evolution.\p"
    .string "Evolution can wait until new moves\n"
    .string "have been learned.$"

PokemonJournal_Text_SpecialFeatureMrFuji::
    .string "Pokémon Journal\p"
    .string "Special Feature:\n"
    .string "Mr. Fuji of Pokémon House!\p"
    .string "Editor: The shy Mr. Fuji turned\n"
    .string "down our interview requests.\p"
    .string "He is a kindly man who is adored\n"
    .string "and respected in Lavender Town.$"
