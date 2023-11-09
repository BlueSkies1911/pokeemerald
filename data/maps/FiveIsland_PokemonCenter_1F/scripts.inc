.set LOCALID_NURSE, 1

FiveIsland_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    .byte 0

FiveIsland_PokemonCenter_1F_OnTransition:
    setrespawn HEAL_LOCATION_FIVE_ISLAND
    end

FiveIsland_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

FiveIsland_PokemonCenter_1F_EventScript_Chef::
    msgbox FiveIsland_PokemonCenter_1F_Text_OnMyWayToPrepareMeal, MSGBOX_NPC
    end

FiveIsland_PokemonCenter_1F_EventScript_CooltrainerF::
    msgbox FiveIsland_PokemonCenter_1F_Text_YoureOnQuestToCatchEveryMon, MSGBOX_NPC
    end

FiveIsland_PokemonCenter_1F_EventScript_PokemonJournal::
    msgbox PokemonJournal_Text_SpecialFeatureLorelei, MSGBOX_SIGN
    end

FiveIsland_PokemonCenter_1F_Text_OnMyWayToPrepareMeal::
    .string "I'm on my way to prepare a meal\n"
    .string "for a certain high-society person.$"

FiveIsland_PokemonCenter_1F_Text_YoureOnQuestToCatchEveryMon::
    .string "You're on a quest to catch every\n"
    .string "single kind of Pokémon?\p"
    .string "…How incredible. Please tell me if\n"
    .string "you catch a strong one!$"

PokemonJournal_Text_SpecialFeatureLorelei::
    .string "Pokémon Journal\p"
    .string "Special Feature:\n"
    .string "Elite Four's Lorelei!\p"
    .string "Known for her logical, calculated,\n"
    .string "and cool battling style, Lorelei\l"
    .string "has a surprising secret!$"
