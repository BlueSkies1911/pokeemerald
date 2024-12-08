.equ REQUIRED_CAUGHT_MONS, 50

Route15_WestEntrance_2F_MapScripts::
    .byte 0

Route15_WestEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    call Route15_WestEntrance_2F_EventScript_GetAideRequestInfo
    goto_if_set FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE, Route15_WestEntrance_2F_EventScript_AlreadyGotExpShare
    msgbox Route15_WestEntrance_2F_Text_GiveItemIfCaughtEnough, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Aide_EventScript_DeclineCheckMons
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, ScriptGetPokedexInfo
    buffernumberstring 2, VAR_0x8006
    call Route15_WestEntrance_2F_EventScript_GetAideRequestInfo
    compare VAR_0x8006, REQUIRED_CAUGHT_MONS
    goto_if_lt Aide_EventScript_HaventCaughtEnough
    msgbox Route15_WestEntrance_2F_Text_GreatHereYouGo, MSGBOX_DEFAULT
    checkitemspace ITEM_EXP_SHARE, 1
    compare VAR_RESULT, FALSE
    goto_if_eq Aide_EventScript_NoRoomForItem
    giveitem_msg Route15_WestEntrance_2F_Text_ReceivedItemFromAide, ITEM_EXP_SHARE
    setflag FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE
    msgbox Route15_WestEntrance_2F_Text_ExplainExpShare, MSGBOX_DEFAULT
    release
    end

Route15_WestEntrance_2F_EventScript_AlreadyGotExpShare::
    msgbox Route15_WestEntrance_2F_Text_ExplainExpShare, MSGBOX_DEFAULT
    release
    end

Route15_WestEntrance_2F_EventScript_GetAideRequestInfo::
    buffernumberstring 0, REQUIRED_CAUGHT_MONS
    bufferitemname 1, ITEM_EXP_SHARE
    return

Route15_WestEntrance_2F_EventScript_LeftBinoculars::
    lockall
    msgbox Route15_WestEntrance_2F_Text_LargeShiningBird, MSGBOX_DEFAULT
    showmonpic SPECIES_ARTICUNO, 10, 3
    delay 20
    waitbuttonpress
    hidemonpic
    setvar VAR_0x8004, SPECIES_ARTICUNO
    special SetSeenMon
    releaseall
    end

Route15_WestEntrance_2F_EventScript_RightBinoculars::
    msgbox Route15_WestEntrance_2F_Text_SmallIslandOnHorizon, MSGBOX_SIGN
    end

Route15_WestEntrance_2F_Text_GiveItemIfCaughtEnough::
    .string "Hi! Remember me?\n"
    .string "I'm one of Prof. Oak's Aides.\p"
    .string "If your Pokédex has complete data\n"
    .string "on {STR_VAR_1} species, I'm supposed to\l"
    .string "give you a reward.\p"
    .string "Prof. Oak entrusted me with the\n"
    .string "{STR_VAR_2} for you.\p"
    .string "So, {PLAYER}, let me ask you.\p"
    .string "Have you gathered data on at least\n"
    .string "{STR_VAR_1} kinds of Pokémon?$"

Route15_WestEntrance_2F_Text_GreatHereYouGo::
    .string "Great! You have caught or owned\n"
    .string "{STR_VAR_3} kinds of Pokémon!\p"
    .string "Congratulations!\n"
    .string "Here you go!$"

Route15_WestEntrance_2F_Text_ReceivedItemFromAide::
    .string "{PLAYER} received the {STR_VAR_2}\n"
    .string "from the Aide.$"

Route15_WestEntrance_2F_Text_ExplainExpShare::
    .string "Exp. Share is an item to be held\n"
    .string "by a Pokémon.\p"
    .string "The Pokémon will receive a share\n"
    .string "of the Exp. Points without having\l"
    .string "to battle.$"

Route15_WestEntrance_2F_Text_LargeShiningBird::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "A large, shining bird is flying\n"
    .string "toward the sea.$"

Route15_WestEntrance_2F_Text_SmallIslandOnHorizon::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "It looks like a small island on\n"
    .string "the horizon!$"
