CeruleanCity_House2_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Hiker::
    lock
    faceplayer
    goto_if_set FLAG_GOT_TM28_FROM_ROCKET, CeruleanCity_House2_EventScript_HikerGotTM28
    msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House2_EventScript_HikerGotTM28::
    msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House2_EventScript_Lass::
    msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
    end

CeruleanCity_House2_EventScript_WallHole::
    msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
    end

CeruleanCity_House2_Text_RocketsStoleTMForDig::
    .string "Those miserable Rockets!\p"
    .string "Look what they've done to my\n"
    .string "house!\p"
    .string "They stole a TM for teaching\n"
    .string "Pokémon how to dig holes!\p"
    .string "I was going to use it on a\n"
    .string "Mankey or a Sandshrew…\p"
    .string "That cost me a bundle, it did!$"

CeruleanCity_House2_Text_TeachDiglettDigWithoutTM::
    .string "I figure what's lost is lost.\p"
    .string "I decided to teach Diglett how to\n"
    .string "dig without a TM.$"

CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood::
    .string "Team Rocket must be trying to dig\n"
    .string "their way into no good!$"

CeruleanCity_House2_Text_TeamRocketLeftWayOut::
    .string "Team Rocket left a way out!$"
