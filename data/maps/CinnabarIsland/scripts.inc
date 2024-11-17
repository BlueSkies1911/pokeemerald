CinnabarIsland_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	.byte 0

CinnabarIsland_OnTransition:
	randomweather
    setflag FLAG_WORLD_MAP_CINNABAR_ISLAND
    call CinnabarIsland_EventScript_CheckUnlockGym
    end

CinnabarIsland_EventScript_CheckUnlockGym::
    goto_if_set FLAG_HIDE_POKEMON_MANSION_B1F_SECRET_KEY, CinnabarIsland_EventScript_UnlockGym
    return

CinnabarIsland_EventScript_UnlockGym::
    setvar VAR_TEMP_1, 1
    return

CinnabarIsland_EventScript_GymDoorLocked::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    delay 20
    msgbox CinnabarIsland_Text_DoorIsLocked, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_ForcePlayerFromDoor
    waitmovement 0
    releaseall
    end

CinnabarIsland_Movement_ForcePlayerFromDoor::
    walk_down
    step_end

CinnabarIsland_EventScript_Woman::
    msgbox CinnabarIsland_Text_BlaineLivedHereSinceBeforeLab, MSGBOX_NPC
    end

CinnabarIsland_EventScript_OldMan::
    msgbox CinnabarIsland_Text_ScientistsExperimentInMansion, MSGBOX_NPC
    end

CinnabarIsland_EventScript_IslandSign::
    msgbox CinnabarIsland_Text_IslandSign, MSGBOX_SIGN
    end

CinnabarIsland_EventScript_PokemonLabSign::
    msgbox CinnabarIsland_Text_PokemonLab, MSGBOX_SIGN
    end

CinnabarIsland_EventScript_GymSign::
    msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
    end

CinnabarIsland_Text_DoorIsLocked::
    .string "The door is locked…$"

CinnabarIsland_Text_BlaineLivedHereSinceBeforeLab::
    .string "Cinnabar Gym's Blaine is quite the\n"
    .string "odd fellow.\p"
    .string "He's lived on the island since way\n"
    .string "before the lab was built.$"

CinnabarIsland_Text_ScientistsExperimentInMansion::
    .string "Scientists conduct experiments \n"
    .string "in the burned-out building.\p"
    .string "You know, the one they call the\n"
    .string "Pokémon Mansion.$"

CinnabarIsland_Text_IslandSign::
    .string "Cinnabar Island\n"
    .string "The Fiery Town of Burning Desire$"

CinnabarIsland_Text_PokemonLab::
    .string "Pokémon Lab$"

CinnabarIsland_Text_GymSign::
    .string "Cinnabar Island Pokémon Gym\n"
    .string "Leader: Blaine\l"
    .string "The Hotheaded Quiz Master!$"
