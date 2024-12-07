.equ REQUIRED_CAUGHT_MONS, 40

Route16_NorthEntrance_2F_MapScripts::
    .byte 0

Route16_NorthEntrance_2F_EventScript_LittleBoy::
    msgbox Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend, MSGBOX_NPC
    end

Route16_NorthEntrance_2F_EventScript_LittleGirl::
    msgbox Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes, MSGBOX_NPC
    end

Route16_NorthEntrance_2F_EventScript_LeftBinoculars::
    msgbox Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore, MSGBOX_SIGN
    end

Route16_NorthEntrance_2F_EventScript_RightBinoculars::
    msgbox Route16_NorthEntrance_2F_Text_LongPathOverWater, MSGBOX_SIGN
    end

Route16_NorthEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
    goto_if_set FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE, Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin
    msgbox Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Aide_EventScript_DeclineCheckMons
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, ScriptGetPokedexInfo
    buffernumberstring 2, VAR_0x8006
    call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
    compare VAR_0x8006, REQUIRED_CAUGHT_MONS
    goto_if_lt Aide_EventScript_HaventCaughtEnough
    msgbox Route16_NorthEntrance_2F_Text_GreatHereYouGo, MSGBOX_DEFAULT
    checkitemspace ITEM_AMULET_COIN, 1
    compare VAR_RESULT, FALSE
    goto_if_eq Aide_EventScript_NoRoomForItem
    giveitem_msg Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide, ITEM_AMULET_COIN
    setflag FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE
    msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin, MSGBOX_DEFAULT
    release
    end

Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin::
    msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin, MSGBOX_DEFAULT
    release
    end

Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo::
    buffernumberstring 0, REQUIRED_CAUGHT_MONS
    bufferitemname 1, ITEM_AMULET_COIN
    return

Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend::
    .string "I'm on a relaxing ride on my new\n"
    .string "bike with my girlfriend.$"

Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes::
    .string "We're going riding together on our\n"
    .string "new bikes.$"

Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "It's the Celadon Dept. Store!$"

Route16_NorthEntrance_2F_Text_LongPathOverWater::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "There's a long path over water far\n"
    .string "away.$"

Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40::
    .string "Hi! Remember me?\n"
    .string "I'm one of Prof. Oak's Aides.\p"
    .string "If your Pokédex has complete data\n"
    .string "on 40 species, I'm supposed to\l"
    .string "give you a reward.\p"
    .string "Prof. Oak entrusted me with an\n"
    .string "Amulet Coin for you.\p"
    .string "So, {PLAYER}, let me ask you.\p"
    .string "Have you gathered data on at least\n"
    .string "40 kinds of Pokémon?$"

Route16_NorthEntrance_2F_Text_GreatHereYouGo::
    .string "Great! You have caught or owned\n"
    .string "{STR_VAR_3} kinds of Pokémon!\p"
    .string "Congratulations!\n"
    .string "Here you go!$"

Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide::
    .string "{PLAYER} received the Amulet Coin\n"
    .string "from the Aide.$"

Route16_NorthEntrance_2F_Text_ExplainAmuletCoin::
    .string "An Amulet Coin is an item to be\n"
    .string "held by a Pokémon.\p"
    .string "If the Pokémon appears in a winning\n"
    .string "battle, you will earn more money.$"
