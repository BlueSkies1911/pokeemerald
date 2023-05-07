.set LOCALID_GRUNT, 11

CeladonCity_GameCorner_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, CeladonCity_GameCorner_OnLoad
    .byte 0

CeladonCity_GameCorner_OnLoad::
    call_if_unset FLAG_OPENED_ROCKET_HIDEOUT, CeladonCity_GameCorner_EventScript_HideRocketHideout
    end

CeladonCity_GameCorner_EventScript_HideRocketHideout::
    setmetatile 15, 2, METATILE_GameCorner_Floor_ShadeFull, 0
    setmetatile 16, 2, METATILE_GameCorner_Floor_ShadeFull, 0
    setmetatile 17, 2, METATILE_GameCorner_Floor_ShadeFull, 0
    setmetatile 16, 3, METATILE_GameCorner_PurpleWall_Floor, 1
    setmetatile 17, 3, METATILE_GameCorner_PurpleWall_Floor, 1
    return

CeladonCity_GameCorner_EventScript_InfoClerk::
    msgbox CeladonCity_GameCorner_Text_CanExchangeCoinsNextDoor, MSGBOX_NPC
    end

CeladonCity_GameCorner_EventScript_CoinsClerk::
    lock
    faceplayer
    showmoneybox 0, 0,
    showcoinsbox 1, 6
    message CeladonCity_GameCorner_Text_WelcomeBuySomeCoins
    waitmessage
    multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
    copyvar VAR_0x8009, VAR_RESULT
    switch VAR_RESULT
    case 0, CeladonCity_GameCorner_EventScript_BuyCoins
    case 1, CeladonCity_GameCorner_EventScript_BuyCoins
    case 2, CeladonCity_GameCorner_EventScript_ClerkDeclineBuy
    case 127, CeladonCity_GameCorner_EventScript_ClerkDeclineBuy
    end

CeladonCity_GameCorner_EventScript_BuyCoins::
    goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_ClerkNoCoinCase
    compare VAR_0x8009, 0
    goto_if_eq CeladonCity_GameCorner_EventScript_Buy50Coins
    compare VAR_0x8009, 1
    goto_if_eq CeladonCity_GameCorner_EventScript_Buy500Coins
    end

CeladonCity_GameCorner_EventScript_ClerkNoCoinCase::
    msgbox CeladonCity_GameCorner_Text_SorryDontHaveCoinCase, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_ClerkEnd
    end

CeladonCity_GameCorner_EventScript_Buy50Coins::
    checkcoins VAR_TEMP_1
    compare VAR_TEMP_1, (MAX_COINS + 1) - 50
    goto_if_ge CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins
    checkmoney 1000, 0
    compare VAR_RESULT, FALSE
    goto_if_eq CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney
    addcoins 50
    removemoney 1000, 0
    goto CeladonCity_GameCorner_EventScript_BoughtCoins
    end

CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins::
    msgbox CeladonCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_ClerkEnd
    end

CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney::
    msgbox CeladonCity_GameCorner_Text_CantAffordCoins, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_ClerkEnd
    end

CeladonCity_GameCorner_EventScript_BoughtCoins::
    updatemoneybox
    updatecoinsbox 0, 5
    playse SE_SHOP
    msgbox CeladonCity_GameCorner_Text_HereAreYourCoins, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_ClerkEnd
    end

CeladonCity_GameCorner_EventScript_Buy500Coins::
    checkcoins VAR_TEMP_1
    compare VAR_TEMP_1, (MAX_COINS + 1) - 500
    goto_if_ge CeladonCity_GameCorner_EventScript_ClerkNoRoomForCoins
    checkmoney 10000, 0
    compare VAR_RESULT, FALSE
    goto_if_eq CeladonCity_GameCorner_EventScript_ClerkNotEnoughMoney
    addcoins 500
    removemoney 10000, 0
    goto CeladonCity_GameCorner_EventScript_BoughtCoins
    end

CeladonCity_GameCorner_EventScript_ClerkDeclineBuy::
    msgbox CeladonCity_GameCorner_Text_ComePlaySometime, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_ClerkEnd
    end

CeladonCity_GameCorner_EventScript_ClerkEnd::
    hidemoneybox
    hidecoinsbox 0, 5
    release
    end

CeladonCity_GameCorner_EventScript_BaldingMan::
    lock
    faceplayer
    msgbox CeladonCity_GameCorner_Text_RumouredTeamRocketRunsThisPlace, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_FaceSlotMachine::
    closemessage
    applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

CeladonCity_GameCorner_EventScript_Woman1::
    lock
    faceplayer
    msgbox CeladonCity_GameCorner_Text_ThinkMachinesHaveDifferentOdds, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_Fisher::
    lock
    faceplayer
    goto_if_set FLAG_GOT_10_COINS_FROM_GAMBLER, CeladonCity_GameCorner_EventScript_FisherAlreadyGotCoins
    msgbox CeladonCity_GameCorner_Text_DoYouWantToPlay
    goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_GamblerNoCoinCase
    checkcoins VAR_TEMP_1
    compare VAR_TEMP_1, (MAX_COINS + 1) - 10
    goto_if_ge CeladonCity_GameCorner_EventScript_FisherNoRoomForCoins
    addcoins 10
    msgbox CeladonCity_GameCorner_Text_Received10CoinsFromMan, MSGBOX_DEFAULT
    playse SE_SHOP
    waitse
    setflag FLAG_GOT_10_COINS_FROM_GAMBLER
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_FisherNoRoomForCoins::
    msgbox CeladonCity_GameCorner_Text_DontNeedMyCoins, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_GamblerNoCoinCase::
    msgbox CeladonCity_GameCorner_Text_DontHaveCoinCase, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_FisherAlreadyGotCoins::
    msgbox CeladonCity_GameCorner_Text_WinsComeAndGo, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_GymGuy::
    lock
    faceplayer
    goto_if_set FLAG_DEFEATED_ERIKA, CeladonCity_GameCorner_EventScript_GymGuyPostVictory
    msgbox CeladonCity_GameCorner_Text_GymGuyAdvice, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_GymGuyPostVictory::
    msgbox CeladonCity_GameCorner_Text_RareMonsForCoins, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_Woman2::
    lock
    faceplayer
    msgbox CeladonCity_GameCorner_Text_WinOrLoseItsOnlyLuck, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_OldMan::
    lock
    faceplayer
    msgbox CeladonCity_GameCorner_Text_SoEasyToGetHooked, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_Scientist::
    lock
    faceplayer
    goto_if_set FLAG_GOT_20_COINS_FROM_GAMBLER, CeladonCity_GameCorner_EventScript_ScientistAlreadyGotCoins
    msgbox CeladonCity_GameCorner_Text_WantSomeCoins, MSGBOX_DEFAULT
    goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_GamblerNoCoinCase
    checkcoins VAR_TEMP_1
    compare VAR_TEMP_1, (MAX_COINS + 1) - 20
    goto_if_ge CeladonCity_GameCorner_EventScript_ScientistNoRoomForCoins
    addcoins 20
    msgbox CeladonCity_GameCorner_Text_Received20CoinsFromNiceGuy, MSGBOX_DEFAULT
    playse SE_SHOP
    waitse
    setflag FLAG_GOT_20_COINS_FROM_GAMBLER
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_ScientistNoRoomForCoins::
    msgbox CeladonCity_GameCorner_Text_YouHaveLotsOfCoins, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_ScientistAlreadyGotCoins::
    msgbox CeladonCity_GameCorner_Text_NeedMoreCoinsForMonIWant, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_Gentleman::
    lock
    faceplayer
    goto_if_set FLAG_GOT_20_COINS_FROM_GAMBLER_2, CeladonCity_GameCorner_EventScript_GentlemanAlreadyGotCoins
    msgbox CeladonCity_GameCorner_Text_HereAreSomeCoinsShoo, MSGBOX_DEFAULT
    goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_EventScript_GamblerNoCoinCase
    checkcoins VAR_TEMP_1
    compare VAR_TEMP_1, (MAX_COINS + 1) - 20
    goto_if_ge CeladonCity_GameCorner_EventScript_GentlemanNoRoomForCoins
    addcoins 20
    msgbox CeladonCity_GameCorner_Text_Received20CoinsFromMan, MSGBOX_DEFAULT
    playse SE_SHOP
    waitse
    setflag FLAG_GOT_20_COINS_FROM_GAMBLER_2
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_GentlemanNoRoomForCoins::
    msgbox CeladonCity_GameCorner_Text_YouveGotPlentyCoins, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_GentlemanAlreadyGotCoins::
    msgbox CeladonCity_GameCorner_Text_WatchReelsClosely, MSGBOX_DEFAULT
    goto CeladonCity_GameCorner_EventScript_FaceSlotMachine
    end

CeladonCity_GameCorner_EventScript_RocketGrunt::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_7, CeladonCity_GameCorner_Text_GruntIntro, CeladonCity_GameCorner_Text_GruntDefeat, CeladonCity_GameCorner_EventScript_DefeatedGrunt
    end

CeladonCity_GameCorner_EventScript_DefeatedGrunt::
    msgbox CeladonCity_GameCorner_Text_GruntPostBattle, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_WEST
    call_if_eq CeladonCity_GameCorner_EventScript_GruntExitWest
    compare VAR_FACING, DIR_WEST
    call_if_ne CeladonCity_GameCorner_EventScript_GruntExit
    removeobject LOCALID_GRUNT
    release
    end

CeladonCity_GameCorner_EventScript_GruntExitWest::
    applymovement LOCALID_GRUNT, CeladonCity_GameCorner_Movement_GruntExitWest
    waitmovement 0
    return

CeladonCity_GameCorner_EventScript_GruntExit::
    applymovement LOCALID_GRUNT, CeladonCity_GameCorner_Movement_GruntExit
    waitmovement 0
    return

CeladonCity_GameCorner_Movement_GruntExitWest::
    walk_down
    walk_right
    walk_right
    walk_up
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

CeladonCity_GameCorner_Movement_GruntExit::
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

CeladonCity_GameCorner_EventScript_SlotMachine0::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_NoCoinCase::
    msgbox CeladonCity_GameCorner_Text_CoinCaseIsRequired, MSGBOX_DEFAULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine1::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 1
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine2::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 2
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine3::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 3
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine4::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 4
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine5::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 5
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine6::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 6
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine7::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 7
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine8::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 8
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine9::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 9
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine10::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 10
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine11::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 11
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine12::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 2
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine13::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 3
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine14::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 4
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine15::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 5
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine16::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 6
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine17::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 7
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine18::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 8
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine19::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 9
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine20::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 10
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_SlotMachine21::
    lockall
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoCoinCase
    setvar VAR_0x8004, 11
    specialvar VAR_RESULT, GetSlotMachineId
    playslotmachine VAR_RESULT
    releaseall
    end

CeladonCity_GameCorner_EventScript_UnusableSlotMachine1::
    msgbox CeladonCity_GameCorner_Text_OutOfOrder, MSGBOX_SIGN
    end

CeladonCity_GameCorner_EventScript_UnusableSlotMachine2::
    msgbox CeladonCity_GameCorner_Text_OutToLunch, MSGBOX_SIGN
    end

CeladonCity_GameCorner_EventScript_UnusableSlotMachine3::
    msgbox CeladonCity_GameCorner_Text_SomeonesKeys, MSGBOX_SIGN
    end
CeladonCity_GameCorner_EventScript_PhotoPrinter::
    msgbox CeladonCity_GameCorner_Text_PhotoPrinter, MSGBOX_SIGN
    end

CeladonCity_GameCorner_EventScript_Poster::
    lockall
    msgbox CeladonCity_GameCorner_Text_SwitchBehindPosterPushIt, MSGBOX_DEFAULT
    call_if_unset FLAG_OPENED_ROCKET_HIDEOUT, CeladonCity_GameCorner_EventScript_OpenRocketHideout
    releaseall
    end

CeladonCity_GameCorner_EventScript_OpenRocketHideout::
    playse SE_UNLOCK
    setmetatile 15, 2, METATILE_GameCorner_Floor_StairsTop, 0
    setmetatile 16, 2, METATILE_GameCorner_StairsTop, 1
    setmetatile 17, 2, METATILE_GameCorner_StairsBottom, 1
    setmetatile 16, 3, METATILE_GameCorner_PurpleWall_StairsTop, 1
    setmetatile 17, 3, METATILE_GameCorner_PurpleWall_StairsBottom, 1
    special DrawWholeMapView
    setflag FLAG_OPENED_ROCKET_HIDEOUT
    return

CeladonCity_GameCorner_Text_CanExchangeCoinsNextDoor::
    .string "Welcome!\p"
    .string "You can exchange your Coins for\n"
    .string "fabulous prizes next door.$"

CeladonCity_GameCorner_Text_WelcomeBuySomeCoins::
    .string "Welcome to Rocket Game Corner!\p"
    .string "Do you need some game Coins?\n"
    .string "Would you like to buy some?$"

CeladonCity_GameCorner_Text_ComePlaySometime::
    .string "No?\n"
    .string "Please come play sometime!$"

CeladonCity_GameCorner_Text_SorryDontHaveCoinCase::
    .string "Oh, I'm sorry.\n"
    .string "You don't have a Coin Case.$"

CeladonCity_GameCorner_Text_CoinCaseIsFull::
    .string "Whoops!\n"
    .string "Your Coin Case is full.$"

CeladonCity_GameCorner_Text_CantAffordCoins::
    .string "You can't afford the Coins.$"

CeladonCity_GameCorner_Text_HereAreYourCoins::
    .string "Thank you.\n"
    .string "Here are your Coins!$"

CeladonCity_GameCorner_Text_RumouredTeamRocketRunsThisPlace::
    .string "Keep this quiet.\p"
    .string "It's rumoured that this place is run\n"
    .string "by Team Rocket.$"

CeladonCity_GameCorner_Text_ThinkMachinesHaveDifferentOdds::
    .string "I think these machines have\n"
    .string "different odds.$"

CeladonCity_GameCorner_Text_DoYouWantToPlay::
    .string "Kid, do you want to play?$"

CeladonCity_GameCorner_Text_Received10CoinsFromMan::
    .string "{PLAYER} received 10 Coins\n"
    .string "from the man.$"

CeladonCity_GameCorner_Text_DontNeedMyCoins::
    .string "You don't need my Coins!$"

CeladonCity_GameCorner_Text_WinsComeAndGo::
    .string "Wins seem to come and go.\n"
    .string "Nothing's a sure thing.$"

CeladonCity_GameCorner_Text_WinOrLoseItsOnlyLuck::
    .string "These slot games…\n"
    .string "Win or lose, it's only by luck.$"

CeladonCity_GameCorner_Text_GymGuyAdvice::
    .string "Hey!\p"
    .string "You have better things to do,\n"
    .string "champ in the making!\p"
    .string "Celadon Gym's Leader is Erika.\p"
    .string "She is a user of Grass-type\n"
    .string "Pokémon, and at one with nature.\p"
    .string "She might appear docile because of\n"
    .string "her flower arranging…\p"
    .string "But she's not one to be taken\n"
    .string "lightly!$"

CeladonCity_GameCorner_Text_RareMonsForCoins::
    .string "They offer rare Pokémon that can\n"
    .string "be exchanged for your Coins.\p"
    .string "But, I just can't seem to win!$"

CeladonCity_GameCorner_Text_SoEasyToGetHooked::
    .string "Games are scary!\n"
    .string "It's so easy to get hooked!$"

CeladonCity_GameCorner_Text_WantSomeCoins::
    .string "What's up?\n"
    .string "Want some Coins?$"

CeladonCity_GameCorner_Text_Received20CoinsFromNiceGuy::
    .string "{PLAYER} received 20 Coins\n"
    .string "from the nice guy.$"

CeladonCity_GameCorner_Text_YouHaveLotsOfCoins::
    .string "You have lots of Coins!$"

CeladonCity_GameCorner_Text_NeedMoreCoinsForMonIWant::
    .string "Darn! I need more Coins for the\n"
    .string "Pokémon I want!$"

CeladonCity_GameCorner_Text_HereAreSomeCoinsShoo::
    .string "Hey, what? You're throwing me off!\n"
    .string "Here are some Coins, so shoo!$"

CeladonCity_GameCorner_Text_Received20CoinsFromMan::
    .string "{PLAYER} received 20 Coins\n"
    .string "from the man.$"

CeladonCity_GameCorner_Text_YouveGotPlentyCoins::
    .string "You've got plenty of your own\n"
    .string "Coins!$"

CeladonCity_GameCorner_Text_WatchReelsClosely::
    .string "The trick is to watch the reels\n"
    .string "closely.$"

CeladonCity_GameCorner_Text_GruntIntro::
    .string "I'm guarding this poster!\n"
    .string "Go away, or else!$"

CeladonCity_GameCorner_Text_GruntDefeat::
    .string "Dang!$"

CeladonCity_GameCorner_Text_GruntPostBattle::
    .string "The Team Rocket Hideout might\n"
    .string "be discovered!\p"
    .string "I better tell Boss!$"

CeladonCity_GameCorner_Text_OutOfOrder::
    .string "OUT OF ORDER\n"
    .string "This is broken.$"

CeladonCity_GameCorner_Text_OutToLunch::
    .string "OUT TO LUNCH\n"
    .string "This is reserved.$"

CeladonCity_GameCorner_Text_SomeonesKeys::
    .string "Someone's keys!\n"
    .string "They'll be back.$"

CeladonCity_GameCorner_Text_PhotoPrinter::
    .string "Oh, Wow!\n"
    .string "A Photo Printer!\p"
    .string "… … … … …\n"
    .string "Oh, it's broken.$"

CeladonCity_GameCorner_Text_SwitchBehindPosterPushIt::
    .string "Hey!\p"
    .string "A switch behind the poster!?\n"
    .string "Let's push it!$"

CeladonCity_GameCorner_Text_CoinCaseIsRequired::
    .string "A Coin Case is required…$"

CeladonCity_GameCorner_Text_DontHaveCoinCase::
    .string "Oops!\n"
    .string "Don't have the Coin Case!$"
