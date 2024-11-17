CeladonCity_GameCorner_PrizeRoom_MapScripts::
	.byte 0

    @ Game Corner prices
    .set TM13_COINS,  4000
    .set TM23_COINS,  3500
    .set TM24_COINS,  4000
    .set TM30_COINS,  4500
    .set TM35_COINS,  4000

CeladonCity_GameCorner_PrizeRoom_EventScript_BaldingMan::
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_FancyThatPorygon, MSGBOX_NPC
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_OldMan::
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_RakedItInToday, MSGBOX_NPC
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkMons::
    lock
    faceplayer
    goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
    showcoinsbox 1, 1
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase::
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_CoinCaseRequired,  MSGBOX_DEFAULT
    release
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon::
    message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
    waitmessage
    multichoice 12, 0, MULTI_GAME_CORNER_POKEMON, FALSE
    switch VAR_RESULT
    case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_Eevee
    case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_Pinsir
    case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_Scyther
    case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_Dratini
    case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_Porygon
    case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_Eevee::
    setvar VAR_TEMP_1, SPECIES_EEVEE
    setvar VAR_TEMP_2, 1500
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_Pinsir::
    setvar VAR_TEMP_1, SPECIES_PINSIR
    setvar VAR_TEMP_2, 3000
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_Scyther::
    setvar VAR_TEMP_1, SPECIES_SCYTHER
    setvar VAR_TEMP_2, 3000
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_Dratini::
    setvar VAR_TEMP_1, SPECIES_DRATINI
    setvar VAR_TEMP_2, 5500
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_Porygon::
    setvar VAR_TEMP_1, SPECIES_PORYGON
    setvar VAR_TEMP_2, 9999
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange::
    hidecoinsbox 0, 0
    release
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon::
    bufferspeciesname 0, VAR_TEMP_1
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    checkcoins VAR_RESULT
    compare VAR_RESULT, VAR_TEMP_2
    goto_if_lt CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
    switch VAR_TEMP_1
    case SPECIES_EEVEE,    CeladonCity_GameCorner_PrizeRoom_EventScript_GiveEevee
    case SPECIES_PINSIR,   CeladonCity_GameCorner_PrizeRoom_EventScript_GivePinsir
    case SPECIES_SCYTHER,  CeladonCity_GameCorner_PrizeRoom_EventScript_GiveScyther
    case SPECIES_DRATINI,  CeladonCity_GameCorner_PrizeRoom_EventScript_GiveDratini
    case SPECIES_PORYGON,  CeladonCity_GameCorner_PrizeRoom_EventScript_GivePorygon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins::
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_NeedMoreCoins, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_GiveEevee::
    givemon VAR_TEMP_1, 20, ITEM_NONE
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_GivePinsir::
    givemon VAR_TEMP_1, 25, ITEM_NONE
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_GiveScyther::
    givemon VAR_TEMP_1, 25, ITEM_NONE
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_GiveDratini::
    givemon VAR_TEMP_1, 18, ITEM_NONE
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_GivePorygon::
    givemon VAR_TEMP_1, 26, ITEM_NONE
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon::
    compare VAR_RESULT, 0
    goto_if_eq CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty
    compare VAR_RESULT, 1
    goto_if_eq CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC
    compare VAR_RESULT, 2
    goto_if_eq CeladonCity_GameCorner_PrizeRoom_EventScript_PartyFull
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty::
    removecoins VAR_TEMP_2
    updatecoinsbox 0, 5
    bufferspeciesname 0, VAR_TEMP_1
    playfanfare MUS_LEVEL_UP
    message gText_PlayerObtainedTheMon
    waitmessage
    waitfanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    call Common_EventScript_GetGiftMonPartySlot
    call Common_EventScript_NameReceivedPartyMon
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC::
    removecoins VAR_TEMP_2
    updatecoinsbox 0, 5
    bufferspeciesname 0, VAR_TEMP_1
    playfanfare MUS_LEVEL_UP
    message gText_PlayerObtainedTheMon
    waitmessage
    waitfanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq CeladonCity_GameCorner_PrizeRoom_EventScript_TransferredToPC
    call Common_EventScript_NameReceivedBoxMon
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_TransferredToPC
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_PartyFull::
    msgbox gText_NoMoreRoomForPokemon, MSGBOX_DEFAULT
    hidecoinsbox 0, 0
    release
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_TransferredToPC::
    call Common_EventScript_TransferredToPC
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs::
    lock
    faceplayer
    goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
    showcoinsbox 1, 1
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeTM
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeTM::
    message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
    waitmessage
    multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
    switch VAR_RESULT
    case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_TM13
    case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_TM23
    case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_TM24
    case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_TM30
    case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_TM35
    case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM13::
    setvar VAR_TEMP_1, 1
    bufferitemname STR_VAR_1, ITEM_TM13
    setvar VAR_0x8004, ITEM_TM13
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM

    CeladonCity_GameCorner_PrizeRoom_EventScript_TM23::
    setvar VAR_TEMP_1, 2
    bufferitemname STR_VAR_1, ITEM_TM23
    setvar VAR_0x8004, ITEM_TM23
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM

    CeladonCity_GameCorner_PrizeRoom_EventScript_TM24::
    setvar VAR_TEMP_1, 3
    bufferitemname STR_VAR_1, ITEM_TM24
    setvar VAR_0x8004, ITEM_TM24
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM

    CeladonCity_GameCorner_PrizeRoom_EventScript_TM30::
    setvar VAR_TEMP_1, 4
    bufferitemname STR_VAR_1, ITEM_TM30
    setvar VAR_0x8004, ITEM_TM30
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM

    CeladonCity_GameCorner_PrizeRoom_EventScript_TM35::
    setvar VAR_TEMP_1, 5
    bufferitemname STR_VAR_1, ITEM_TM35
    setvar VAR_0x8004, ITEM_TM35
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM

    CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM::
    special BufferTMHMMoveName
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantTM, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    switch VAR_TEMP_1
    case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTM13
    case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTM23
    case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTM24
    case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTM30
    case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTM35
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTM13::
    checkitem ITEM_TM13
    goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, TM13_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
    removecoins TM13_COINS
    additem ITEM_TM13
    updatecoinsbox 1, 1
    playse SE_SHOP
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_HereYouGo, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTM23::
    checkitem ITEM_TM23
    goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, TM23_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
    removecoins TM23_COINS
    additem ITEM_TM23
    updatecoinsbox 1, 1
    playse SE_SHOP
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_HereYouGo, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTM24::
    checkitem ITEM_TM24
    goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, TM24_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
    removecoins TM24_COINS
    additem ITEM_TM24
    updatecoinsbox 1, 1
    playse SE_SHOP
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_HereYouGo, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTM30::
    checkitem ITEM_TM30
    goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, TM30_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
    removecoins TM30_COINS
    additem ITEM_TM30
    updatecoinsbox 1, 1
    playse SE_SHOP
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_HereYouGo, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_BuyTM35::
    checkitem ITEM_TM35
    goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, TM35_COINS, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
    removecoins TM35_COINS
    additem ITEM_TM35
    updatecoinsbox 1, 1
    playse SE_SHOP
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_HereYouGo, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis::
    msgbox gText_YouAlreadyHaveThis, MSGBOX_DEFAULT
    hidecoinsbox 0, 0
    release
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkItems::
    lock
    faceplayer
    goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
    showcoinsbox 1, 1
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeItem
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeItem::
    message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
    waitmessage
    multichoice 12 , 0, MULTI_GAME_CORNER_ITEMS, FALSE
    switch VAR_RESULT
    case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_SmokeBall
    case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_MiracleSeed
    case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_Charcoal
    case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_MysticWater
    case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_YellowFlute
    case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_SmokeBall::
    setvar VAR_TEMP_1, ITEM_SMOKE_BALL
    setvar VAR_TEMP_2, 800
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_MiracleSeed::
    setvar VAR_TEMP_1, ITEM_MIRACLE_SEED
    setvar VAR_TEMP_2, 1000
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_Charcoal::
    setvar VAR_TEMP_1, ITEM_CHARCOAL
    setvar VAR_TEMP_2, 1000
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_MysticWater::
    setvar VAR_TEMP_1, ITEM_MYSTIC_WATER
    setvar VAR_TEMP_2, 1000
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_YellowFlute::
    setvar VAR_TEMP_1, ITEM_YELLOW_FLUTE
    setvar VAR_TEMP_2, 1600
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem::
    bufferitemname 0, VAR_TEMP_1
    msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize::
    bufferitemname 0, VAR_TEMP_1
    checkcoins VAR_RESULT
    compare VAR_RESULT, VAR_TEMP_2
    goto_if_lt CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
    checkitemspace VAR_TEMP_1, 1
    compare VAR_RESULT, FALSE
    goto_if_eq CeladonCity_GameCorner_PrizeRoom_EventScript_BagFull
    removecoins VAR_TEMP_2
    updatecoinsbox 0, 5
    giveitem VAR_TEMP_1
    goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
    end

CeladonCity_GameCorner_PrizeRoom_EventScript_BagFull::
    call Common_EventScript_BagIsFull
    hidecoinsbox 0, 0
    release
    end

CeladonCity_GameCorner_PrizeRoom_Text_FancyThatPorygon::
    .string "I sure do fancy that Porygon!\n"
    .string "But, it's hard to win at slots!$"

CeladonCity_GameCorner_PrizeRoom_Text_RakedItInToday::
    .string "Gahaha! I raked it in today!\n"
    .string "If only every day were like this…$"

CeladonCity_GameCorner_PrizeRoom_Text_CoinCaseRequired::
    .string "A Coin Case is required…$"

CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes::
    .string "We exchange your Coins for prizes.$"

CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize::
    .string "Which prize would you like?$"

CeladonCity_GameCorner_PrizeRoom_Text_NeedMoreCoins::
    .string "Sorry, you'll need more Coins\n"
    .string "than that.$"

CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize::
    .string "So, you want the {STR_VAR_1}?$"

CeladonCity_GameCorner_PrizeRoom_Text_YouWantTM::
    .string "So your choice is {STR_VAR_1} {STR_VAR_2}?$"

CeladonCity_GameCorner_PrizeRoom_Text_HereYouGo::
    .string "Here you go!$"
