.set LOCALID_NURSE, 1

CeruleanCity_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    .byte 0

CeruleanCity_PokemonCenter_1F_OnTransition:
    setrespawn HEAL_LOCATION_CERULEAN_CITY
    end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
    msgbox CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac, MSGBOX_NPC
    end

CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
    msgbox CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons, MSGBOX_NPC
    end

CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
    lock
    faceplayer
    msgbox CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons, MSGBOX_DEFAULT
    release
    end

CeruleanCity_PokemonCenter_1F_EventScript_Lass::
    msgbox CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs, MSGBOX_NPC
    end

CeruleanCity_PokemonCenter_1F_EventScript_PokemonJournalMisty::
    lock
    faceplayer
    msgbox PokemonJournal_Text_SpecialFeatureMisty, MSGBOX_DEFAULT
    release
    end

CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac::
    .string "Have you heard about Bill?\p"
    .string "Everyone calls him a Pokémaniac!\p"
    .string "I think people are just jealous of\n"
    .string "Bill, though.\p"
    .string "Who wouldn't want to boast about\n"
    .string "their Pokémon?$"

CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons::
    .string "That Bill!\p"
    .string "I heard that he'll do whatever it\n"
    .string "takes to get rare Pokémon.\p"
    .string "He's not above doing all sorts\n"
    .string "of things, I've heard.$"

CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons::
    .string "Bill has lots of Pokémon!\n"
    .string "He collects rare ones, too!$"

CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs::
    .string "Why don't you go upstairs and try\n"
    .string "trading Pokémon with your friends?\p"
    .string "You could get a lot more variety\n"
    .string "by trading.\p"
    .string "The Pokémon you get in trades grow\n"
    .string "quickly, too.$"

PokemonJournal_Text_SpecialFeatureMisty::
    .string "Pokémon Journal\p"
    .string "Special Feature: Cerulean Gym\n"
    .string "Leader Misty!\p"
    .string "Misty is said to worship Lorelei\n"
    .string "of the Elite Four.$"
