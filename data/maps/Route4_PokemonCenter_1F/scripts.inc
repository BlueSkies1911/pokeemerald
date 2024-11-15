.set LOCALID_NURSE, 1
.equ MAGIKARP_PRICE, 500

Route4_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route4_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    .byte 0

Route4_PokemonCenter_1F_OnTransition:
    setflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
    setrespawn HEAL_LOCATION_ROUTE4
    end

Route4_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

Route4_PokemonCenter_1F_EventScript_MagikarpSalesman::
    lock
    faceplayer
    goto_if_set FLAG_BOUGHT_MAGIKARP, Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp
    showmoneybox 0, 0
    checkplayergender
    compare VAR_RESULT, MALE
    goto_if_eq Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale
    compare VAR_RESULT, FEMALE
    goto_if_eq Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale
    end

Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp::
    msgbox Route4_PokemonCenter_1F_Text_IDontGiveRefunds
    release
    end

Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale::
    msgbox Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500, MSGBOX_YESNO
    goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
    end

Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale::
    msgbox Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500, MSGBOX_YESNO
    goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
    end

Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp::
    compare VAR_RESULT, NO
    goto_if_eq Route4_PokemonCenter_1F_EventScript_DeclineMagikarp
    checkmoney MAGIKARP_PRICE, 0
    compare VAR_RESULT, FALSE
    goto_if_eq Route4_PokemonCenter_1F_EventScript_NotEnoughMoney
    setvar VAR_TEMP_1, SPECIES_MAGIKARP
    givemon SPECIES_MAGIKARP, 5, ITEM_NONE
    compare VAR_RESULT, 0
    goto_if_eq Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty
    compare VAR_RESULT, 1
    goto_if_eq Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC
    compare VAR_RESULT, 2
    goto_if_eq Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp
    end

Route4_PokemonCenter_1F_EventScript_DeclineMagikarp::
    msgbox Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou, MSGBOX_DEFAULT
    hidemoneybox
    release
    end

Route4_PokemonCenter_1F_EventScript_NotEnoughMoney::
    msgbox Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney, MSGBOX_DEFAULT
    hidemoneybox
    release
    end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty::
    call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
    call Common_EventScript_GetGiftMonPartySlot
    fadescreen FADE_TO_BLACK
    hidemoneybox
    special ChangePokemonNickname
    waitstate
    goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
    end

Route4_PokemonCenter_1F_EventScript_PayForMagikarp::
    removemoney MAGIKARP_PRICE, 0
    updatemoneybox
    playfanfare MUS_LEVEL_UP
    message Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp
    waitmessage
    waitfanfare
    bufferspeciesname 0, SPECIES_MAGIKARP
    return

Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp::
    hidemoneybox
    goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
    end

Route4_PokemonCenter_1F_EventScript_BoughtMagikarp:: @ 816F86A
    setflag FLAG_BOUGHT_MAGIKARP
    release
    end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC::
    call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox
    fadescreen FADE_TO_BLACK
    hidemoneybox
    special ChangeBoxPokemonNickname
    waitstate
    lock
    faceplayer
    goto Route4_PokemonCenter_1F_EventScript_TransferMagikarp
    end

Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox::
    call Common_EventScript_TransferredToPC
    goto Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
    end

Route4_PokemonCenter_1F_EventScript_TransferMagikarp::
    call Common_EventScript_TransferredToPC
    goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
    end

Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp::
    msgbox Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon
    hidemoneybox
    release
    end

Route4_PokemonCenter_1F_EventScript_Gentleman::
    lock
    msgbox Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean
    release
    end

Route4_PokemonCenter_1F_EventScript_Boy::
    msgbox Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou, MSGBOX_NPC
    end

Route4_PokemonCenter_1F_EventScript_Youngster::
    msgbox Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC, MSGBOX_NPC
    end

Route4_PokemonCenter_1F_EventScript_Newspaper::
    lock
    msgbox Route4_PokemonCenter_1F_Text_ItsANewspaper
    release
    end

Route4_PokemonCenter_1F_Text_IDontGiveRefunds::
    .string "Man: Well, I don't give refunds.\n"
    .string "You knew what you were getting!$"

Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500::
    .string "Man: Hello there, laddie!\n"
    .string "Have I got a deal just for you!\p"
    .string "I'll let you have a secret Pokémon\n"
    .string "- a Magikarp - for just ¥500!\p"
    .string "So, you'll buy it, am I right?$"

Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500::
    .string "Man: Hello there, sweetie pie!\n"
    .string "Have I got a deal just for you!\p"
    .string "I'll let you have a secret Pokémon\n"
    .string "- a Magikarp - for just ¥500!\p"
    .string "So, you'll buy it, am I right?$"

Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou::
    .string "No? You say no? I'm only doing this\n"
    .string "as a favour to you!$"

Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney::
    .string "You'll need more money than that!$"

Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp::
    .string "{PLAYER} paid an outrageous ¥500\n"
    .string "and bought the Magikarp…$"

Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon::
    .string "There's no more room for any more\n"
    .string "Pokémon, it looks like.$"

Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean::
    .string "Team Rocket attacks Cerulean\n"
    .string "citizens…\p"
    .string "Not a day goes by without Team\n"
    .string "Rocket being in the news.$"

Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou::
    .string "Okay, set six Poké Balls in my\n"
    .string "belt…\p"
    .string "Yeah, that'll do it. At most, you\n"
    .string "can have six Pokémon with you.$"

Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC::
    .string "Sometimes, you'll have too many\n"
    .string "Pokémon with you to add any more.\p"
    .string "In that case, you should just\n"
    .string "store some using any PC.$"

Route4_PokemonCenter_1F_Text_ItsANewspaper::
    .string "It's a newspaper.$"
