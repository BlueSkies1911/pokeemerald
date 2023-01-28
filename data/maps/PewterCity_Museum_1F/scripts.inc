.set LOCALID_SCIENTIST1, 1
.set LOCALID_OLD_AMBER,  4

PewterCity_Museum_1F_MapScripts::
    .byte 0

PewterCity_Museum_1F_EventScript_Scientist1::
    lock
    faceplayer
    compare VAR_FACING, DIR_WEST
    goto_if_eq PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
    compare VAR_FACING, DIR_SOUTH
    goto_if_eq PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
    compare VAR_FACING, DIR_NORTH
    goto_if_eq PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
    msgbox PewterCity_Museum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
    release
    end

PewterCity_Museum_1F_EventScript_Scientist1BehindCounter::
    msgbox PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter
    compare VAR_RESULT, NO
    goto_if_eq PewterCity_Museum_1F_EventScript_ExplainAmber
    end

PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter::
    msgbox PewterCity_Museum_1F_Text_AmberContainsGeneticMatter, MSGBOX_DEFAULT
    applymovement LOCALID_SCIENTIST1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

PewterCity_Museum_1F_EventScript_ExplainAmber::
    msgbox PewterCity_Museum_1F_Text_AmberIsFossilizedSap, MSGBOX_DEFAULT
    applymovement LOCALID_SCIENTIST1, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

PewterCity_Museum_1F_EventScript_EntranceTriggerLeft::
    lockall
    setvar VAR_TEMP_1, 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    goto PewterCity_Museum_1F_EventScript_EntranceTrigger
    end

PewterCity_Museum_1F_EventScript_EntranceTriggerMid::
    lockall
    setvar VAR_TEMP_1, 1
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    goto PewterCity_Museum_1F_EventScript_EntranceTrigger
    end

PewterCity_Museum_1F_EventScript_EntranceTriggerRight::
    lockall
    setvar VAR_TEMP_1, 2
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    goto PewterCity_Museum_1F_EventScript_EntranceTrigger
    end

PewterCity_Museum_1F_EventScript_EntranceTrigger::
    showmoneybox 0, 0
    msgbox PewterCity_Museum_1F_Text_Its50YForChildsTicket, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq PewterCity_Museum_1F_EventScript_TryPayForTicket
    msgbox PewterCity_Museum_1F_Text_ComeAgain, MSGBOX_DEFAULT
    closemessage
    hidemoneybox
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
    waitmovement 0
    releaseall
    end

PewterCity_Museum_1F_EventScript_TryPayForTicket::
    checkmoney 50
    compare VAR_RESULT, FALSE
    goto_if_eq PewterCity_Museum_1F_EventScript_NotEnoughMoney
    closemessage
    compare VAR_TEMP_1, 0
    call_if_eq PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft
    compare VAR_TEMP_1, 1
    call_if_eq PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid
    compare VAR_TEMP_1, 2
    call_if_eq PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight
    playse SE_SHOP
    removemoney 50
    updatemoneybox
    waitse
    msgbox PewterCity_Museum_1F_Text_Right50YThankYou, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 1
    hidemoneybox
    releaseall
    end

PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft::
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterLeft
    waitmovement 0
    return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid::
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterMid
    waitmovement 0
    return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight::
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterRight
    waitmovement 0
    return

PewterCity_Museum_1F_EventScript_NotEnoughMoney::
    msgbox PewterCity_Museum_1F_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
    closemessage
    hidemoneybox
    applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
    waitmovement 0
    releaseall
    end

PewterCity_Museum_1F_Movement_ForcePlayerExit::
    walk_down
    step_end

PewterCity_Museum_1F_Movement_ApproachCounterLeft::
    walk_right
    walk_right
    delay_8
    walk_in_place_right
    step_end

PewterCity_Museum_1F_Movement_ApproachCounterMid::
    walk_right
    delay_8
    walk_in_place_right
    step_end

PewterCity_Museum_1F_Movement_ApproachCounterRight::
    delay_8
    walk_in_place_right
    step_end

PewterCity_Museum_1F_EventScript_Scientist2::
    msgbox PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit, MSGBOX_NPC
    end

PewterCity_Museum_1F_EventScript_OldMan::
    msgbox PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife, MSGBOX_NPC
    end

PewterCity_Museum_1F_EventScript_OldAmberScientist::
    lock
    faceplayer
    goto_if_set FLAG_GOT_OLD_AMBER, PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber
    msgbox PewterCity_Museum_1F_Text_WantYouToGetAmberExamined, MSGBOX_DEFAULT
    checkitemspace ITEM_OLD_AMBER, 1
    compare VAR_RESULT, FALSE
    goto_if_eq PewterCity_Museum_1F_EventScript_NoRoomForOldAmber
    setflag FLAG_GOT_OLD_AMBER
    removeobject LOCALID_OLD_AMBER
    giveitem_msg PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan, ITEM_OLD_AMBER, 1, MUS_RG_OBTAIN_KEY_ITEM
    release
    end

PewterCity_Museum_1F_EventScript_NoRoomForOldAmber::
    msgbox PewterCity_Museum_1F_Text_DontHaveSpaceForThis, MSGBOX_DEFAULT
    release
    end

PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber::
    msgbox PewterCity_Museum_1F_Text_GetOldAmberChecked, MSGBOX_DEFAULT
    release
    end

PewterCity_Museum_1F_EventScript_OldAmber::
    msgbox PewterCity_Museum_1F_Text_BeautifulPieceOfAmber, MSGBOX_NPC
    end

PewterCity_Museum_1F_EventScript_AerodactylFossil::
    lockall
    setvar VAR_0x8004, SPECIES_AERODACTYL
    setvar VAR_0x8005, 10
    setvar VAR_0x8006, 3
    special OpenMuseumFossilPic
    msgbox PewterCity_Museum_1F_Text_AerodactylFossil, MSGBOX_DEFAULT
    special CloseMuseumFossilPic
    releaseall
    end

PewterCity_Museum_1F_EventScript_KabutopsFossil::
    lockall
    setvar VAR_0x8004, SPECIES_KABUTOPS
    setvar VAR_0x8005, 10
    setvar VAR_0x8006, 3
    special OpenMuseumFossilPic
    msgbox PewterCity_Museum_1F_Text_KabutopsFossil, MSGBOX_DEFAULT
    special CloseMuseumFossilPic
    releaseall
    end

PewterCity_Museum_1F_EventScript_PokemonJournalBrock::
    lockall
    msgbox PokemonJournal_Text_SpecialFeatureBrock, MSGBOX_DEFAULT
    releaseall
    end

PewterCity_Museum_1F_Text_Its50YForChildsTicket::
    .string "Yes, yes.\n"
    .string "It's ¥50 for a child's ticket.\p"
    .string "Would you like to come in?$"

PewterCity_Museum_1F_Text_ComeAgain::
    .string "Come again!$"

PewterCity_Museum_1F_Text_Right50YThankYou::
    .string "Right, ¥50!\n"
    .string "Thank you!$"

PewterCity_Museum_1F_Text_DontHaveEnoughMoney::
    .string "You don't have enough money.$"

PewterCity_Museum_1F_Text_PleaseEnjoyYourself::
    .string "Please enjoy yourself.$"

PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs::
    .string "You can't sneak in the back way!\n"
    .string "Nice try, kid, but no.\p"
    .string "Oh, whatever!\n"
    .string "Do you know what Amber is?$"

PewterCity_Museum_1F_Text_AmberContainsGeneticMatter::
    .string "Amber contains the genetic matter\n"
    .string "of ancient Pokémon.\p"
    .string "There's a lab somewhere trying to\n"
    .string "resurrect Pokémon from Amber.$"

PewterCity_Museum_1F_Text_AmberIsFossilizedSap::
    .string "Amber is actually sap, that gooey\n"
    .string "stuff that oozes from trees.\p"
    .string "The ancient sap fossilized over\n"
    .string "time to become rock-hard Amber.$"

PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife::
    .string "I should be grateful for my long\n"
    .string "life.\p"
    .string "Never did I think I would get to\n"
    .string "see the bones of a dragon!$"

PewterCity_Museum_1F_Text_WantYouToGetAmberExamined::
    .string "Ssh! Listen, I need to share a\n"
    .string "secret with someone.\p"
    .string "I think that this chunk of Amber\n"
    .string "contains Pokémon DNA!\p"
    .string "It would be a shattering scientific\n"
    .string "breakthrough if Pokémon could be\l"
    .string "resurrected from it.\p"
    .string "But, my colleagues just ignore\n"
    .string "what I have to say.\p"
    .string "So, I have a favour to ask!\p"
    .string "I want you to get this examined at\n"
    .string "a Pokémon Lab somewhere.$"

PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan::
    .string "{PLAYER} received the Old Amber\n"
    .string "from the man.$"

PewterCity_Museum_1F_Text_GetOldAmberChecked::
    .string "Ssh!\n"
    .string "Get the Old Amber checked!$"

PewterCity_Museum_1F_Text_DontHaveSpaceForThis::
    .string "You don't have space for this.$"

PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit::
    .string "We have two fossils of rare,\n"
    .string "prehistoric Pokémon on exhibit.$"

PewterCity_Museum_1F_Text_BeautifulPieceOfAmber::
    .string "There is a beautiful piece of\n"
    .string "Amber in a clear gold colour.$"

PewterCity_Museum_1F_Text_AerodactylFossil::
    .string "Aerodactyl Fossil\n"
    .string "A primitive and rare Pokémon.$"

PewterCity_Museum_1F_Text_KabutopsFossil::
    .string "Kabutops Fossil\n"
    .string "A primitive and rare Pokémon.$"

PokemonJournal_Text_SpecialFeatureBrock::
    .string "Pokémon Journal\p"
    .string "Special Feature: Pewter Gym\n"
    .string "Leader Brock!\p"
    .string "Brock rarely laughs, but is said to\n"
    .string "be unable to stop if he starts.$"
