FuchsiaCity_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	.byte 0

FuchsiaCity_OnTransition:
	randomweather
    setflag FLAG_WORLD_MAP_FUCHSIA_CITY
    call_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetOmanyteGfx
    call_if_unset FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetKabutoGfx
    end

FuchsiaCity_EventScript_SetOmanyteGfx::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
    return

FuchsiaCity_EventScript_SetKabutoGfx::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
    return

FuchsiaCity_EventScript_LittleBoy::
    msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
    end

FuchsiaCity_EventScript_OldMan::
    msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
    end

FuchsiaCity_EventScript_Erik::
    msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
    end

FuchsiaCity_EventScript_Youngster::
    msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
    end

FuchsiaCity_EventScript_Lass::
    msgbox FuchsiaCity_Text_MyFatherIsGymLeader, MSGBOX_NPC
    end

FuchsiaCity_EventScript_CitySign::
    msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
    end

FuchsiaCity_EventScript_SafariZoneSign::
    msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
    end

FuchsiaCity_EventScript_SafariGameSign::
    msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
    end

FuchsiaCity_EventScript_WardensHomeSign::
    msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
    end

FuchsiaCity_EventScript_GymSign::
    msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
    end

FuchsiaCity_EventScript_ChanseySign::
    lockall
    setvar VAR_0x8004, SPECIES_CHANSEY
    special SetSeenMon
    showmonpic SPECIES_CHANSEY, 10, 3
    msgbox FuchsiaCity_Text_ChanseySign, MSGBOX_DEFAULT
    hidemonpic
    releaseall
    end

FuchsiaCity_EventScript_VoltorbSign::
    lockall
    setvar VAR_0x8004, SPECIES_VOLTORB
    special SetSeenMon
    showmonpic SPECIES_VOLTORB, 10, 3
    msgbox FuchsiaCity_Text_VoltorbSign, MSGBOX_DEFAULT
    hidemonpic
    releaseall
    end

FuchsiaCity_EventScript_KangaskhanSign::
    lockall
    setvar VAR_0x8004, SPECIES_KANGASKHAN
    special SetSeenMon
    showmonpic SPECIES_KANGASKHAN, 10, 3
    msgbox FuchsiaCity_Text_KangaskhanSign, MSGBOX_DEFAULT
    hidemonpic
    releaseall
    end

FuchsiaCity_EventScript_SlowpokeSign::
    lockall
    setvar VAR_0x8004, SPECIES_SLOWPOKE
    special SetSeenMon
    showmonpic SPECIES_SLOWPOKE, 10, 3
    msgbox FuchsiaCity_Text_SlowpokeSign, MSGBOX_DEFAULT
    hidemonpic
    releaseall
    end

FuchsiaCity_EventScript_LaprasSign::
    lockall
    setvar VAR_0x8004, SPECIES_LAPRAS
    special SetSeenMon
    showmonpic SPECIES_LAPRAS, 10, 3
    msgbox FuchsiaCity_Text_LaprasSign, MSGBOX_DEFAULT
    hidemonpic
    releaseall
    end

FuchsiaCity_EventScript_FossilMonSign::
    lockall
    goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
    setvar VAR_0x8004, SPECIES_KABUTO
    special SetSeenMon
    showmonpic SPECIES_KABUTO, 10, 3
    msgbox FuchsiaCity_Text_KabutoSign, MSGBOX_DEFAULT
    hidemonpic
    releaseall
    end

FuchsiaCity_EventScript_OmanyteSign::
    setvar VAR_0x8004, SPECIES_OMANYTE
    special SetSeenMon
    showmonpic SPECIES_OMANYTE, 10, 3
    msgbox FuchsiaCity_Text_OmanyteSign, MSGBOX_DEFAULT
    hidemonpic
    releaseall
    end

FuchsiaCity_EventScript_BattleTentSign::
	msgbox FuchsiaCity_Text_BattleTentSign, MSGBOX_SIGN
	end

FuchsiaCity_Text_DidYouTrySafariGame::
    .string "Did you try the Safari Game?\p"
    .string "There are some rare Pokémon that\n"
    .string "can only be caught there.$"

FuchsiaCity_Text_SafariZoneZooInFront::
    .string "The Safari Zone has a zoo in front\n"
    .string "of the entrance.\p"
    .string "Out back is the Safari Game for\n"
    .string "catching Pokémon.$"

FuchsiaCity_Text_WheresSara::
    .string "Erik: Where's Sara?\n"
    .string "I said I'd meet her here.$"

FuchsiaCity_Text_ItemBallInThere::
    .string "That item ball in there…\n"
    .string "Were you wanting that?\p"
    .string "Me, too!\n"
    .string "…Huh? That's a Pokémon?$"

FuchsiaCity_Text_MyFatherIsGymLeader::
    .string "My father is the Gym Leader of\n"
    .string "this town.\p"
    .string "I'm training to use Poison Pokémon\n"
    .string "as well as my father.$"

FuchsiaCity_Text_CitySign::
    .string "Fuchsia City\n"
    .string "Behold! It's Passion Pink!$"

FuchsiaCity_Text_SafariZoneSign::
    .string "Pokémon Paradise\n"
    .string "Safari Zone$"

FuchsiaCity_Text_SafariGameSign::
    .string "Safari Game\n"
    .string "Pokémon-U-Catch!$"

FuchsiaCity_Text_WardensHomeSign::
    .string "Safari Zone\n"
    .string "Warden's Home$"

FuchsiaCity_Text_SafariZoneOfficeSign::
    .string "Pokémon Paradise!\n"
    .string "Welcome to the Safari Zone!\l"
    .string "Safari Zone Office$"

FuchsiaCity_Text_GymSign::
    .string "Fuchsia City Pokémon Gym\n"
    .string "Leader: Koga\l"
    .string "The Poisonous Ninja Master$"

FuchsiaCity_Text_ChanseySign::
    .string "Name: Chansey\n"
    .string "Catching one is all up to chance.$"

FuchsiaCity_Text_VoltorbSign::
    .string "Name: Voltorb\n"
    .string "The very image of a Poké Ball.$"

FuchsiaCity_Text_KangaskhanSign::
    .string "Name: Kangaskhan\p"
    .string "A maternal Pokémon that raises its\n"
    .string "young in a pouch on its belly.$"

FuchsiaCity_Text_SlowpokeSign::
    .string "Name: Slowpoke\n"
    .string "Friendly and very slow moving.$"

FuchsiaCity_Text_LaprasSign::
    .string "Name: Lapras\n"
    .string "The king of the seas.$"

FuchsiaCity_Text_OmanyteSign::
    .string "Name: Omanyte\n"
    .string "An extremely rare Pokémon that was\l"
    .string "regenerated from a fossil.$"

FuchsiaCity_Text_KabutoSign::
    .string "Name: Kabuto\n"
    .string "An extremely rare Pokémon that was\l"
    .string "regenerated from a fossil.$"

FuchsiaCity_Text_BattleTentSign:
	.string "Battle Tent Fuchsia Site\n"
	.string "“Feast Your Eyes on Battles!”$"
