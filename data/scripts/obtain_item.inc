.set ITEMID, VAR_0x8000
.set AMOUNT, VAR_0x8001

Std_ObtainItem::
	additem ITEMID, AMOUNT
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_ObtainItemMessage
	return

EventScript_ObtainItemMessage::
	bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
	checkitemtype ITEMID
	call EventScript_BufferPocketNameAndTryFanfare
	call_if_eq VAR_0x8007, TRUE, EventScript_ObtainedItem
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForItem
	return

EventScript_BufferPocketNameAndTryFanfare::
	switch VAR_RESULT
	case POCKET_ITEMS,      EventScript_BufferItemsPocket
	case POCKET_KEY_ITEMS,  EventScript_BufferKeyItemsPocket
	case POCKET_POKE_BALLS, EventScript_BufferPokeballsPocket
	case POCKET_TM_HM,      EventScript_BufferTMHMsPocket
	case POCKET_BERRIES,    EventScript_BufferBerriesPocket
	end

EventScript_BufferItemsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferKeyItemsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_KEYITEMS
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferPokeballsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_POKEBALLS
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferTMHMsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_TMHMS
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedTMHM
	return

EventScript_BufferBerriesPocket::
	bufferstdstring STR_VAR_3, STDSTRING_BERRIES
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedItem
	return

EventScript_ObtainedItem::
	message gText_ObtainedTheItem
	waitfanfare
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	setvar VAR_RESULT, TRUE
	return

EventScript_NoRoomForItem::
	setvar VAR_RESULT, FALSE
	return

EventScript_PlayFanfareObtainedItem::
	playfanfare MUS_OBTAIN_ITEM
	return

EventScript_PlayFanfareObtainedTMHM::
	playfanfare MUS_OBTAIN_TMHM
	return

Std_ObtainDecoration::
	adddecoration ITEMID
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_ObtainDecorationMessage
	return

EventScript_ObtainDecorationMessage::
	bufferdecorationname STR_VAR_2, ITEMID
	call_if_eq VAR_0x8007, TRUE, EventScript_ObtainedDecor
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForDecor
	return

EventScript_ObtainedDecor::
	playfanfare MUS_OBTAIN_ITEM
	message gText_ObtainedTheDecor
	waitfanfare
	msgbox gText_TheDecorWasTransferredToThePC, MSGBOX_DEFAULT
	setvar VAR_RESULT, TRUE
	return

EventScript_NoRoomForDecor::
	setvar VAR_RESULT, FALSE
	return

Std_FindItem::
	lock
	faceplayer
	waitse
	copyvar VAR_0x8004, ITEMID
	copyvar VAR_0x8005, AMOUNT
	checkitemspace ITEMID, AMOUNT
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
	checkitemtype ITEMID
	call EventScript_BufferPocketNameAndTryFanfare
	call_if_eq VAR_0x8007, TRUE, EventScript_PickUpItem
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomToPickUpItem
	release
	return

Std_PutItemAway::
    bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
    checkitemtype VAR_0x8000
    call EventScript_BufferPutAwayPocketName
    msgbox gText_PutItemInPocket
    return

EventScript_PickUpItem::
	removeobject VAR_LAST_TALKED
	additem VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, BufferTMHMMoveName
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, TRUE, EventScript_FoundTMHM
	call_if_eq VAR_0x8008, FALSE, EventScript_FoundItem
	waitfanfare
	waitmessage
	bufferitemnameplural STR_VAR_2, VAR_0x8004, VAR_0x8005
	pyramid_inchallenge
	goto_if_eq VAR_RESULT, TRUE, EventScript_PutBattlePyramidItemInBag
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	return

EventScript_PutBattlePyramidItemInBag::
	msgbox gText_PlayerPutItemInBag, MSGBOX_DEFAULT
	return

EventScript_FoundTMHM::
	bufferitemnameplural STR_VAR_1, VAR_0x8004, VAR_0x8005
	message gText_PlayerFoundOneTMHM
	return

EventScript_FoundItem::
	message gText_PlayerFoundOneItem
	return

EventScript_FoundCoins::
    buffernumberstring 0, VAR_0x8006
    message gText_FoundXCoins
    return

EventScript_NoRoomToPickUpItem::
	msgbox gText_ObtainedTheItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	return

EventScript_HiddenItemScript::
	lockall
	waitse
    compare VAR_0x8005, ITEM_COINS10
    goto_if_eq EventScript_HiddenCoins10
    compare VAR_0x8005, ITEM_COINS20
    goto_if_eq EventScript_HiddenCoins20
    compare VAR_0x8005, ITEM_COINS40
    goto_if_eq EventScript_HiddenCoins40
    compare VAR_0x8005, ITEM_COINS100
    goto_if_eq EventScript_HiddenCoins100
	additem VAR_0x8005
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural STR_VAR_2, VAR_0x8005, 1
	checkitemtype VAR_0x8005
	call EventScript_BufferPocketNameAndTryFanfare
	goto_if_eq VAR_0x8007, TRUE, EventScript_PickUpHiddenItem
	goto_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForHiddenItem
	end

EventScript_PickUpHiddenItem::
	copyvar VAR_0x8008, VAR_0x8004
	copyvar VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, BufferTMHMMoveName
	goto_if_eq VAR_RESULT, TRUE, EventScript_FoundHiddenTMHM
	goto_if_eq VAR_RESULT, FALSE, EventScript_FoundHiddenItem
	end

EventScript_FoundHiddenTMHM::
	bufferitemnameplural STR_VAR_1, VAR_0x8004, 1
	message gText_PlayerFoundOneTMHM
	goto EventScript_PutHiddenItemInPocket
	end

EventScript_FoundHiddenItem::
	message gText_PlayerFoundOneItem
	goto EventScript_PutHiddenItemInPocket
	end

EventScript_PutHiddenItemInPocket::
	waitmessage
	waitfanfare
	bufferitemnameplural STR_VAR_2, VAR_0x8004, 1
	copyvar VAR_0x8004, VAR_0x8008
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	special TryPutTreasureInvestigatorsOnAir
	special SetHiddenItemFlag
	releaseall
	end

EventScript_NoRoomForHiddenItem::
	msgbox gText_PlayerFoundOneItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	releaseall
	end

EventScript_HiddenCoins10::
    setvar VAR_0x8006, 10
    goto EventScript_TryPickUpHiddenCoins
    end

EventScript_HiddenCoins20::
    setvar VAR_0x8006, 20
    goto EventScript_TryPickUpHiddenCoins
    end

EventScript_HiddenCoins40::
    setvar VAR_0x8006, 40
    goto EventScript_TryPickUpHiddenCoins
    end

EventScript_HiddenCoins100::
    setvar VAR_0x8006, 100
    goto EventScript_TryPickUpHiddenCoins
    end

EventScript_TryPickUpHiddenCoins::
    goto_if_unset FLAG_GOT_COIN_CASE, EventScript_NoCaseForHiddenCoins
    checkcoins VAR_RESULT
    compare VAR_RESULT, (MAX_COINS + 1) - VAR_0x8006
    goto_if_ge EventScript_HiddenCoinsButCaseIsFull
    addcoins VAR_0x8006
    bufferstdstring 1, STDSTRING_COINS
    call EventScript_ReceivedItemFanfare1
    call EventScript_FoundCoins
    waitfanfare
    waitmessage
    msgbox gText_PutCoinsAwayInCoinCase, MSGBOX_DEFAULT
    special SetHiddenItemFlag
    releaseall
    end

EventScript_HiddenCoinsButCaseIsFull::
    buffernumberstring 0, VAR_0x8006
    bufferstdstring 1, STDSTRING_COINS
    msgbox gText_FoundXCoins, MSGBOX_DEFAULT
    msgbox gText_CoinCaseIsFull, MSGBOX_DEFAULT
    setvar VAR_RESULT, 0
    releaseall
    end

EventScript_NoCaseForHiddenCoins::
    buffernumberstring 0, VAR_0x8006
    bufferstdstring 1, STDSTRING_COINS
    msgbox gText_FoundXCoins, MSGBOX_DEFAULT
    msgbox gText_NothingToPutThemIn, MSGBOX_DEFAULT
    setvar VAR_RESULT, 0
    releaseall
    end

Std_ReceivedItem::
    compare VAR_0x8002, MUS_LEVEL_UP
    call_if_eq EventScript_ReceivedItemFanfare1
    compare VAR_0x8002, MUS_RG_OBTAIN_KEY_ITEM
    call_if_eq EventScript_ReceivedItemFanfare2
    message 0x0
    waitmessage
    waitfanfare
    compare VAR_0x8002, MUS_LEVEL_UP
    call_if_eq EventScript_ReceivedItemWaitFanfare
    bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
    checkitemtype ITEMID
    call EventScript_BufferPutAwayPocketName
    msgbox gText_PutItemInPocket
    return

EventScript_ReceivedItemFanfare1::
    playfanfare MUS_LEVEL_UP
    return

EventScript_ReceivedItemFanfare2::
    playfanfare MUS_RG_OBTAIN_KEY_ITEM
    return

EventScript_ReceivedItemWaitFanfare::
    delay 50
    return

EventScript_BufferPutAwayPocketName:: @ 81A8E6F
    switch VAR_RESULT
    case POCKET_ITEMS,       EventScript_BufferPutAwayPocketItems
    case POCKET_KEY_ITEMS,   EventScript_BufferPutAwayPocketKeyItems
    case POCKET_POKE_BALLS,  EventScript_BufferPutAwayPocketPokeBalls
    case POCKET_TM_HM,       EventScript_BufferPutAwayPocketTMCase
    case POCKET_BERRIES,     EventScript_BufferPutAwayPocketBerryPouch
    end

EventScript_BufferPutAwayPocketItems::
    bufferstdstring STR_VAR_3, STDSTRING_ITEMS
    return

EventScript_BufferPutAwayPocketKeyItems::
    bufferstdstring STR_VAR_3, STDSTRING_KEYITEMS
    return

EventScript_BufferPutAwayPocketPokeBalls::
    bufferstdstring STR_VAR_3, STDSTRING_POKEBALLS
    return

EventScript_BufferPutAwayPocketTMCase::
    bufferstdstring STR_VAR_3, STDSTRING_TMHMS
    return

EventScript_BufferPutAwayPocketBerryPouch::
    bufferstdstring STR_VAR_3, STDSTRING_BERRIES
    return
