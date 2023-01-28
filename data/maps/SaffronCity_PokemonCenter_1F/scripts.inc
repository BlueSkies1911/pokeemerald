.set LOCALID_NURSE, 1

SaffronCity_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    .byte 0

SaffronCity_PokemonCenter_1F_OnTransition:
    setrespawn HEAL_LOCATION_SAFFRON_CITY
    end

SaffronCity_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

SaffronCity_PokemonCenter_1F_EventScript_Gentleman::
    msgbox SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame, MSGBOX_NPC
    end

SaffronCity_PokemonCenter_1F_EventScript_Woman::
    msgbox SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies, MSGBOX_NPC
    end

SaffronCity_PokemonCenter_1F_EventScript_Youngster::
    lock
    faceplayer
    compare VAR_MAP_SCENE_SILPH_CO_11F, 1
    goto_if_eq SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone
    msgbox SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone::
    msgbox SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonCenter_1F_EventScript_PokemonJournalSabrina::
    lockall
    msgbox PokemonJournal_Text_SpecialFeatureSabrina, MSGBOX_DEFAULT
    releaseall
    end

SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame::
    .string "Silph Co. is widely known to all.\p"
    .string "It's a victim of its own fame - it\n"
    .string "attracted Team Rocket.$"

SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies::
    .string "Pokémon growth rates differ from\n"
    .string "species to species.$"

SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets::
    .string "Sigh…\n"
    .string "Wouldn't this be great?\p"
    .string "If the Elite Four came and\n"
    .string "stomped Team Rocket?$"

SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff::
    .string "Team Rocket took off!\n"
    .string "We can go out safely again!\l"
    .string "That's great!$"

PokemonJournal_Text_SpecialFeatureSabrina::
    .string "Pokémon Journal\p"
    .string "Special Feature: Saffron Gym\n"
    .string "Leader Sabrina!\p"
    .string "People say that Sabrina can\n"
    .string "communicate with her Pokémon\l"
    .string "during battle without speaking.$"
