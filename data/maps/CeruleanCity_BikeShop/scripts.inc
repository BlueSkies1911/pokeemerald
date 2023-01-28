CeruleanCity_BikeShop_MapScripts::
	.byte 0

CeruleanCity_BikeShop_EventScript_Clerk::
    lock
    faceplayer
    goto_if_set FLAG_GOT_BICYCLE, CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle
    goto_if_set FLAG_GOT_BIKE_VOUCHER, CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher
    showmoneybox 0, 0
    message CeruleanCity_BikeShop_Text_WelcomeToBikeShop
    waitmessage
    multichoice 21, 8, MULTI_BIKE_SHOP, FALSE
    switch VAR_RESULT
    case 0, CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle
    case 1, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
    case 127, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
    end

CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle::
    msgbox CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle, MSGBOX_DEFAULT
    release
    end

CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher::
    msgbox CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo, MSGBOX_DEFAULT
    msgreceiveditem CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle, ITEM_ACRO_BIKE, 1, MUS_RG_OBTAIN_KEY_ITEM
    setflag FLAG_GOT_BICYCLE
    additem ITEM_ACRO_BIKE
    removeitem ITEM_BIKE_VOUCHER
    msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain, MSGBOX_DEFAULT
    release
    end

CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle::
    msgbox CeruleanCity_BikeShop_Text_SorryYouCantAffordIt, MSGBOX_DEFAULT
    goto CeruleanCity_BikeShop_EventScript_ClerkGoodbye
    end

CeruleanCity_BikeShop_EventScript_ClerkGoodbye::
    msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain, MSGBOX_DEFAULT
    hidemoneybox
    release
    end

CeruleanCity_BikeShop_EventScript_Woman::
    msgbox CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe, MSGBOX_NPC
    end

CeruleanCity_BikeShop_EventScript_Youngster::
    lock
    faceplayer
    goto_if_set FLAG_GOT_BICYCLE, CeruleanCity_BikeShop_EventScript_YoungsterHaveBike
    msgbox CeruleanCity_BikeShop_Text_BikesCoolButExpensive, MSGBOX_DEFAULT
    release
    end

CeruleanCity_BikeShop_EventScript_YoungsterHaveBike::
    msgbox CeruleanCity_BikeShop_Text_WowYourBikeIsCool, MSGBOX_DEFAULT
    release
    end

CeruleanCity_BikeShop_EventScript_Bicycle::
    msgbox CeruleanCity_BikeShop_Text_ShinyNewBicycle, MSGBOX_SIGN
    end

CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle::
    .string "How do you like your new bicycle?\n"
    .string "Do you like how it rides?\p"
    .string "You can take it out on Cycling\n"
    .string "Road and even into caves!$"

CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo::
    .string "Oh, that's…\p"
    .string "A Bike Voucher!\p"
    .string "Okay!\n"
    .string "Here you go!$"

CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle::
    .string "{PLAYER} exchanged the\n"
    .string "Bike Voucher for an Acro Bike.$"

CeruleanCity_BikeShop_Text_WelcomeToBikeShop::
    .string "Hi!\n"
    .string "Welcome to our Bike Shop.\p"
    .string "Have we got just the bike for\n"
    .string "you!$"

CeruleanCity_BikeShop_Text_SorryYouCantAffordIt::
    .string "Sorry!\n"
    .string "You can't afford it!$"

CeruleanCity_BikeShop_Text_ThankYouComeAgain::
    .string "Thank you!\n"
    .string "Come back again sometime!$"

CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe::
    .string "A plain city bike is good enough\n"
    .string "for me.\p"
    .string "After all, you can't put a shopping\n"
    .string "basket on a mountain bike.$"

CeruleanCity_BikeShop_Text_BikesCoolButExpensive::
    .string "These bikes are cool, but they're\n"
    .string "way expensive!$"

CeruleanCity_BikeShop_Text_WowYourBikeIsCool::
    .string "Wow.\n"
    .string "Your bicycle is really cool!$"

CeruleanCity_BikeShop_Text_ShinyNewBicycle::
    .string "A shiny new bicycle!$"
