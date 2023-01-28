Route4_MapScripts::
	.byte 0

Route4_EventScript_Woman::
    msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
    end

Route4_EventScript_Crissy::
    trainerbattle_single TRAINER_LASS_CRISSY, Route4_Text_CrissyIntro, Route4_Text_CrissyDefeat
    msgbox Route4_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
    end

Route4_EventScript_Boy::
    lock
    faceplayer
    msgbox Route4_Text_PeopleLikeAndRespectBrock, MSGBOX_DEFAULT
    release
    end

Route4_EventScript_MtMoonSign::
    msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
    end

Route4_EventScript_RouteSign::
    msgbox Route4_Text_RouteSign, MSGBOX_SIGN
    end

Route4_Text_TrippedOverGeodude::
    .string "Ouch! I tripped over a rocky\n"
    .string "Pokémon, Geodude!$"

Route4_Text_PeopleLikeAndRespectBrock::
    .string "Oh, wow, that's the BoulderBadge!\n"
    .string "You got it from Brock, didn't you?\p"
    .string "Brock is cool. He's not just tough.\n"
    .string "People like and respect him.\p"
    .string "I want to become a Gym Leader\n"
    .string "like him.$"

Route4_Text_MtMoonEntrance::
    .string "Mt. Moon\n"
    .string "Tunnel Entrance$"

Route4_Text_RouteSign::
    .string "ROUTE 4\n"
    .string "Mt. Moon - Cerulean City$"
