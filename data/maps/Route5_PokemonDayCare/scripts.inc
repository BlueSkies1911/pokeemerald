Route5_PokemonDayCare_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route5_PokemonDayCare_OnTransition
	.byte 0

Route5_PokemonDayCare_OnTransition:
    setflag FLAG_LANDMARK_POKEMON_DAYCARE
    end

Route5_PokemonDayCare_EventScript_DaycareMan::
    lock
    faceplayer
    showmoneybox 0, 0
    specialvar VAR_RESULT, IsThereMonInRoute5Daycare
    compare VAR_RESULT, TRUE
    goto_if_eq Route5_PokemonDayCare_EventScript_CheckOnMon
    msgbox Route5_PokemonDayCare_Text_WantMeToRaiseMon, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq Route5_PokemonDayCare_EventScript_TryGiveMon
    msgbox Route5_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
    goto Route5_PokemonDayCare_EventScript_CloseMoneyBox
    end

Route5_PokemonDayCare_EventScript_CheckOnMon::
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, GetNumLevelsGainedForRoute5DaycareMon
    compare VAR_RESULT, 0
    call_if_ne Route5_PokemonDayCare_EventScript_MonHasGrownByXLevels
    compare VAR_RESULT, 0
    call_if_eq Route5_PokemonDayCare_EventScript_NotEnoughTime
    special GetCostToWithdrawRoute5DaycareMon
    msgbox Route5_PokemonDayCare_Text_OweMeXForMonsReturn, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq Route5_PokemonDayCare_EventScript_TryRetrieveMon
    goto Route5_PokemonDayCare_EventScript_ComeAgain
    end

Route5_PokemonDayCare_EventScript_MonHasGrownByXLevels::
    msgbox Route5_PokemonDayCare_Text_MonHasGrownByXLevels, MSGBOX_DEFAULT
    return

Route5_PokemonDayCare_EventScript_NotEnoughTime::
    msgbox Route5_PokemonDayCare_Text_MonNeedsToSpendMoreTime, MSGBOX_DEFAULT
    return

Route5_PokemonDayCare_EventScript_TryRetrieveMon::
    specialvar VAR_RESULT, CalculatePlayerPartyCount
    compare VAR_RESULT, PARTY_SIZE
    goto_if_eq Route5_PokemonDayCare_EventScript_NoRoomInParty
    specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
    compare VAR_RESULT, TRUE
    goto_if_eq Route5_PokemonDayCare_EventScript_RetrieveMon
    msgbox Route5_PokemonDayCare_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
    goto Route5_PokemonDayCare_EventScript_CloseMoneyBox
    end

Route5_PokemonDayCare_EventScript_NoRoomInParty::
    msgbox Route5_PokemonDayCare_Text_YouveGotNoRoomForIt, MSGBOX_DEFAULT
    goto Route5_PokemonDayCare_EventScript_CloseMoneyBox
    end

Route5_PokemonDayCare_EventScript_CloseMoneyBox::
    hidemoneybox
    release
    end

Route5_PokemonDayCare_EventScript_RetrieveMon::
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, TakePokemonFromRoute5Daycare
    special SubtractMoneyFromVar0x8005
    updatemoneybox
    copyvar VAR_0x8008, VAR_RESULT
    getpartysize
    subvar VAR_RESULT, 1
    bufferpartymonnick 0, VAR_RESULT
    copyvar VAR_RESULT, VAR_0x8008
    msgbox Route5_PokemonDayCare_Text_ThankYouHeresMon, MSGBOX_DEFAULT
    waitse
    playmoncry VAR_RESULT, 0
    msgbox Route5_PokemonDayCare_Text_PlayerGotMonBack, MSGBOX_DEFAULT
    waitmoncry
    goto Route5_PokemonDayCare_EventScript_CloseMoneyBox
    end

Route5_PokemonDayCare_EventScript_ComeAgain::
    msgbox Route5_PokemonDayCare_Text_ComeAnytimeYouLike, MSGBOX_DEFAULT
    goto Route5_PokemonDayCare_EventScript_CloseMoneyBox
    end

Route5_PokemonDayCare_EventScript_TryGiveMon::
    specialvar VAR_RESULT, CountPartyNonEggMons
    compare VAR_RESULT, 1
    goto_if_eq Route5_PokemonDayCare_EventScript_OnlyOneMonInParty
    msgbox Route5_PokemonDayCare_Text_WhichMonShouldIRaise, MSGBOX_DEFAULT
    fadescreen FADE_TO_BLACK
    hidemoneybox
    special ChooseSendDaycareMon
    waitstate
    showmoneybox 0, 0
    compare VAR_0x8004, PARTY_SIZE
    goto_if_ge Route5_PokemonDayCare_EventScript_ComeAgain
    specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
    compare VAR_RESULT, 0
    goto_if_eq Route5_PokemonDayCare_EventScript_OnlyOneAliveMonInParty
    specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
    msgbox Route5_PokemonDayCare_Text_LookAfterMonForAWhile, MSGBOX_DEFAULT
    waitse
    playmoncry VAR_0x8005, 0
    msgbox Route5_PokemonDayCare_Text_ComeSeeMeInAWhile, MSGBOX_DEFAULT
    waitmoncry
    special PutMonInRoute5Daycare
    incrementgamestat GAME_STAT_USED_DAYCARE
    goto Route5_PokemonDayCare_EventScript_CloseMoneyBox
    end

Route5_PokemonDayCare_EventScript_OnlyOneMonInParty::
    msgbox Route5_PokemonDayCare_Text_OnlyHaveOneMonWithYou, MSGBOX_DEFAULT
    goto Route5_PokemonDayCare_EventScript_CloseMoneyBox
    end

Route5_PokemonDayCare_EventScript_OnlyOneAliveMonInParty::
    msgbox Route5_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
    goto Route5_PokemonDayCare_EventScript_CloseMoneyBox
    end

Route5_PokemonDayCare_Text_MonHasGrownByXLevels::
    .string "Your {STR_VAR_1} has grown a lot.\n"
    .string "Yes, quite a lot, I'd say.\p"
    .string "Let me see…\n"
    .string "By level, it's grown by {STR_VAR_2}.\p"
    .string "Aren't I great?$"

Route5_PokemonDayCare_Text_MonNeedsToSpendMoreTime::
    .string "You're back already?\p"
    .string "Your {STR_VAR_1} needs to spend\n"
    .string "some more time with me.$"

Route5_PokemonDayCare_Text_OweMeXForMonsReturn::
    .string "You owe me ¥{STR_VAR_2} for the return\n"
    .string "of this Pokémon.$"

Route5_PokemonDayCare_Text_YouveGotNoRoomForIt::
    .string "You can't take this Pokémon back\n"
    .string "if you've got no room for it.$"

Route5_PokemonDayCare_Text_ComeAnytimeYouLike::
    .string "Fine.\n"
    .string "Come anytime you like.$"

Route5_PokemonDayCare_Text_WantMeToRaiseMon::
    .string "I run the Day Care service.\p"
    .string "Would you like me to raise one of\n"
    .string "your Pokémon?$"

Route5_PokemonDayCare_Text_OnlyHaveOneMonWithYou::
    .string "Oh? You only have one Pokémon\n"
    .string "with you.$"

Route5_PokemonDayCare_Text_WhichMonShouldIRaise::
    .string "Which Pokémon should I raise?$"

Route5_PokemonDayCare_Text_WhatWillYouBattleWith::
    .string "If you leave me that Pokémon,\n"
    .string "what will you battle with?$"

Route5_PokemonDayCare_Text_LookAfterMonForAWhile::
    .string "Fine, I'll look after your\n"
    .string "{STR_VAR_1} for a while.$"

Route5_PokemonDayCare_Text_ComeSeeMeInAWhile::
    .string "Come see me in a while.$"

Route5_PokemonDayCare_Text_DontHaveEnoughMoney::
    .string "You don't have enough money.$"

Route5_PokemonDayCare_Text_ComeAgain::
    .string "Come again.$"

Route5_PokemonDayCare_Text_ThankYouHeresMon::
    .string "Thank you!\n"
    .string "Here's your Pokémon.$"

Route5_PokemonDayCare_Text_PlayerGotMonBack::
    .string "{PLAYER} got {STR_VAR_1} back\n"
    .string "from the Day Care Man.$"
