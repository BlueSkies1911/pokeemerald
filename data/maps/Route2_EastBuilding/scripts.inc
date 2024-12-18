.equ REQUIRED_SEEN_MONS, 10

Route2_EastBuilding_MapScripts::
	.byte 0

Route2_EastBuilding_EventScript_Aide::
    lock
    faceplayer
    call Route2_EastBuilding_EventScript_GetAideRequestInfo
    goto_if_set FLAG_GOT_HM05, Route2_EastBuilding_EventScript_AlreadyGotHM05
    msgbox Route2_EastBuilding_Text_GiveHM05IfSeen10Mons, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Aide_EventScript_DeclineCheckMons
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, ScriptGetPokedexInfo
    buffernumberstring 2, VAR_0x8006
    call Route2_EastBuilding_EventScript_GetAideRequestInfo
    compare VAR_0x8006, REQUIRED_SEEN_MONS
    goto_if_lt Aide_EventScript_HaventCaughtEnough
    msgbox Route2_EastBuilding_Text_GreatHereYouGo, MSGBOX_DEFAULT
    checkitemspace ITEM_HM05, 1
    compare VAR_RESULT, FALSE
    goto_if_eq Aide_EventScript_NoRoomForItem
    giveitem_msg Route2_EastBuilding_Text_ReceivedHM05FromAide, ITEM_HM05
    setflag FLAG_GOT_HM05
    msgbox Route2_EastBuilding_Text_ExplainHM05, MSGBOX_DEFAULT
    release
    end

Route2_EastBuilding_EventScript_AlreadyGotHM05::
    msgbox Route2_EastBuilding_Text_ExplainHM05, MSGBOX_DEFAULT
    release
    end

Route2_EastBuilding_EventScript_GetAideRequestInfo::
    buffernumberstring 0, REQUIRED_SEEN_MONS
    bufferitemname 1, ITEM_HM05
    return

Route2_EastBuilding_EventScript_Rocker::
    msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
    end

Route2_EastBuilding_Text_GiveHM05IfSeen10Mons::
    .string "Hi! Remember me?\n"
    .string "I'm one of Prof. Oak's Aides.\p"
    .string "If your Pokédex has complete data\n"
    .string "on ten species, I'm supposed to\l"
    .string "give you a reward.\p"
    .string "Prof. Oak entrusted me with\n"
    .string "HM05 for you.\p"
    .string "So, {PLAYER}, let me ask you.\p"
    .string "Have you gathered data on at least\n"
    .string "ten kinds of Pokémon?$"

Route2_EastBuilding_Text_GreatHereYouGo::
    .string "Great! You have caught or owned\n"
    .string "{STR_VAR_3} kinds of Pokémon!\p"
    .string "Congratulations!\n"
    .string "Here you go!$"

Route2_EastBuilding_Text_ReceivedHM05FromAide::
    .string "{PLAYER} received HM05\n"
    .string "from the Aide.$"

Route2_EastBuilding_Text_ExplainHM05::
    .string "HM05 contains the hidden move\n"
    .string "Flash.\p"
    .string "Flash lights up even the darkest\n"
    .string "of caves and dungeons.$"

Route2_EastBuilding_Text_CanGetThroughRockTunnel::
    .string "Once a Pokémon learns Flash, you\n"
    .string "can get through Rock Tunnel.$"
