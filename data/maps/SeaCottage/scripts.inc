.equ LOCALID_BILL_HUMAN,    1
.equ LOCALID_BILL_CLEFAIRY, 2

.equ BILL_IN_TELEPORTER,     FLAG_TEMP_2
.equ RETURN_AFTER_SS_TICKET, FLAG_TEMP_3

SeaCottage_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SeaCottage_OnTransition
    .byte 0

SeaCottage_OnTransition:
    setflag FLAG_LANDMARK_SEA_COTTAGE
    call_if_unset FLAG_HELPED_BILL_IN_SEA_COTTAGE, SeaCottage_EventScript_HideClefairyBill
    call_if_set FLAG_GOT_SS_TICKET, SeaCottage_EventScript_SetReturnedAfterSSTicket
    end

SeaCottage_EventScript_HideClefairyBill::
    clearflag FLAG_HIDE_BILL_CLEFAIRY
    setobjectxyperm LOCALID_BILL_HUMAN, 3, 3
    return

SeaCottage_EventScript_SetReturnedAfterSSTicket::
    setflag RETURN_AFTER_SS_TICKET
    return

SeaCottage_EventScript_Bill::
    lock
    faceplayer
    goto_if_set RETURN_AFTER_SS_TICKET, SeaCottage_EventScript_BillGoLookAtPC
    goto_if_set FLAG_GOT_SS_TICKET, SeaCottage_EventScript_BillGoToSSAnne
    goto_if_set FLAG_HELPED_BILL_IN_SEA_COTTAGE, SeaCottage_EventScript_BillGiveSSTicket
    checkplayergender
    compare VAR_RESULT, MALE
    goto_if_eq SeaCottage_EventScript_BillAskForHelpMale
    compare VAR_RESULT, FEMALE
    goto_if_eq SeaCottage_EventScript_BillAskForHelpFemale
    end

SeaCottage_EventScript_BillGoLookAtPC::
    msgbox SeaCottage_Text_CheckOutRareMonsOnPC, MSGBOX_DEFAULT
    release
    end

SeaCottage_EventScript_BillGoToSSAnne::
    msgbox SeaCottage_Text_SSAnnePartyYouGoInstead, MSGBOX_DEFAULT
    release
    end

SeaCottage_EventScript_BillGiveSSTicket::
    checkplayergender
    compare VAR_RESULT, MALE
    call_if_eq SeaCottage_EventScript_BillThanksMale
    compare VAR_RESULT, FEMALE
    call_if_eq SeaCottage_EventScript_BillThanksFemale
    checkitemspace ITEM_SS_TICKET, 1
    compare VAR_RESULT, FALSE
    goto_if_eq SeaCottage_EventScript_NoRoomForSSTicket
    giveitem_msg SeaCottage_Text_ReceivedSSTicketFromBill, ITEM_SS_TICKET, 1, MUS_RG_OBTAIN_KEY_ITEM
    setflag FLAG_HIDE_NUGGET_BRIDGE_ROCKET
    setflag FLAG_GOT_SS_TICKET
    setflag FLAG_SYS_PC_BILL
    goto SeaCottage_EventScript_BillGoToSSAnne
    end

SeaCottage_EventScript_BillThanksMale::
    msgbox SeaCottage_Text_ThanksBudTakeThis, MSGBOX_DEFAULT
    return

SeaCottage_EventScript_BillThanksFemale::
    msgbox SeaCottage_Text_ThanksLadyTakeThis, MSGBOX_DEFAULT
    return

SeaCottage_EventScript_NoRoomForSSTicket::
    msgbox SeaCottage_Text_YouveGotTooMuchStuff, MSGBOX_DEFAULT
    release
    end

SeaCottage_EventScript_BillAskForHelpMale::
    msgbox SeaCottage_Text_ImBillHelpMeOutPal, MSGBOX_YESNO
    goto SeaCottage_EventScript_BillAskForHelp
    end

SeaCottage_EventScript_BillAskForHelpFemale::
    msgbox SeaCottage_Text_ImBillHelpMeOutLady, MSGBOX_YESNO
    goto SeaCottage_EventScript_BillAskForHelp
    end

SeaCottage_EventScript_BillAskForHelp::
    compare VAR_RESULT, NO
    call_if_eq SeaCottage_EventScript_DeclineHelpBill
    msgbox SeaCottage_Text_RunCellSeparationOnPC, MSGBOX_DEFAULT
    closemessage
    delay 10
    compare VAR_FACING, DIR_SOUTH
    call_if_eq SeaCottage_EventScript_BillWalkToTeleporterSouth
    compare VAR_FACING, DIR_NORTH
    call_if_eq SeaCottage_EventScript_BillWalkToTeleporter
    compare VAR_FACING, DIR_WEST
    call_if_eq SeaCottage_EventScript_BillWalkToTeleporter
    compare VAR_FACING, DIR_EAST
    call_if_eq SeaCottage_EventScript_BillWalkToTeleporter
    opendoor 10, 3
    waitdooranim
    applymovement LOCALID_BILL_CLEFAIRY, SeaCottage_Movement_BillEnterTeleporter
    waitmovement 0
    removeobject LOCALID_BILL_CLEFAIRY
    playse SE_CONTEST_CURTAIN_FALL
    closedoor 10, 3
    waitdooranim
    setflag BILL_IN_TELEPORTER
    release
    end
    
SeaCottage_EventScript_DeclineHelpBill::
    checkplayergender
    compare VAR_RESULT, MALE
    call_if_eq SeaCottage_EventScript_DeclineHelpBillMale
    compare VAR_RESULT, FEMALE
    call_if_eq SeaCottage_EventScript_DeclineHelpBillFemale
    return

SeaCottage_EventScript_DeclineHelpBillMale::
    msgbox SeaCottage_Text_NoPleaseChief, MSGBOX_DEFAULT
    return

SeaCottage_EventScript_DeclineHelpBillFemale::
    msgbox SeaCottage_Text_NoPleaseBeautiful, MSGBOX_DEFAULT
    return

SeaCottage_EventScript_BillWalkToTeleporterSouth::
    applymovement LOCALID_BILL_CLEFAIRY, SeaCottage_Movement_BillWalkToTeleporterSouth
    waitmovement 0
    return

SeaCottage_Movement_BillWalkToTeleporterSouth::
    walk_right
    walk_up
    walk_up
    walk_left
    walk_in_place_faster_up
    step_end

SeaCottage_Movement_BillEnterTeleporter::
    walk_up
    step_end

SeaCottage_EventScript_BillWalkToTeleporter::
    applymovement LOCALID_BILL_CLEFAIRY, SeaCottage_Movement_BillWalkToTeleporter
    waitmovement 0
    return

SeaCottage_Movement_BillWalkToTeleporter::
    walk_up
    walk_up
    step_end

SeaCottage_EventScript_Computer::
    lockall
    goto_if_set RETURN_AFTER_SS_TICKET, SeaCottage_EventScript_OpenBillsMonList
    goto_if_set BILL_IN_TELEPORTER, SeaCottage_EventScript_RunCellSeparator
    msgbox SeaCottage_Text_TeleporterIsDisplayed, MSGBOX_DEFAULT
    releaseall
    end

SeaCottage_EventScript_OpenBillsMonList::
    msgbox SeaCottage_Text_BillsFavoriteMonList, MSGBOX_DEFAULT
    goto SeaCottage_EventScript_BillsMonList
    end

SeaCottage_EventScript_BillsMonList::
    message SeaCottage_Text_SeeWhichMon
    waitmessage
    multichoice 0, 0, MULTI_EEVEELUTIONS, FALSE
    switch VAR_RESULT
    case 0, SeaCottage_EventScript_ViewEevee
    case 1, SeaCottage_EventScript_ViewFlareon
    case 2, SeaCottage_EventScript_ViewJolteon
    case 3, SeaCottage_EventScript_ViewVaporeon
    case 4, SeaCottage_EventScript_ExitBillsMonList
    case 127, SeaCottage_EventScript_ExitBillsMonList
    end

SeaCottage_EventScript_ViewEevee::
    showmonpic SPECIES_EEVEE, 10, 3
    waitbuttonpress
    hidemonpic
    setvar VAR_0x8004, SPECIES_EEVEE
    special SetSeenMon
    goto SeaCottage_EventScript_BillsMonList
    end

SeaCottage_EventScript_ViewFlareon::
    showmonpic SPECIES_FLAREON, 10, 3
    waitbuttonpress
    hidemonpic
    setvar VAR_0x8004, SPECIES_FLAREON
    special SetSeenMon
    goto SeaCottage_EventScript_BillsMonList
    end

SeaCottage_EventScript_ViewJolteon::
    showmonpic SPECIES_JOLTEON, 10, 3
    waitbuttonpress
    hidemonpic
    setvar VAR_0x8004, SPECIES_JOLTEON
    special SetSeenMon
    goto SeaCottage_EventScript_BillsMonList
    end

SeaCottage_EventScript_ViewVaporeon::
    showmonpic SPECIES_VAPOREON, 10, 3
    waitbuttonpress
    hidemonpic
    setvar VAR_0x8004, SPECIES_VAPOREON
    special SetSeenMon
    goto SeaCottage_EventScript_BillsMonList
    end

SeaCottage_EventScript_ExitBillsMonList::
    releaseall
    end

SeaCottage_EventScript_RunCellSeparator::
    fadeoutbgm 0
    msgbox SeaCottage_Text_InitiatedTeleportersCellSeparator, MSGBOX_DEFAULT
    closemessage
    clearflag BILL_IN_TELEPORTER
    setflag FLAG_HELPED_BILL_IN_SEA_COTTAGE
    special SpawnCameraObject
    applymovement OBJ_EVENT_ID_CAMERA, SeaCottage_Movement_CameraPanToTeleporters
    waitmovement 0
    delay 35
    playse SE_PIN
    waitse
    setvar VAR_0x8004, 0
    special AnimateTeleporterHousing
    delay 10
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    setvar VAR_0x8004, 1
    special AnimateTeleporterHousing
    playse SE_WARP_IN
    special AnimateTeleporterCable
    waitse
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    call SeaCottage_EventScript_PlayTeleporterBeepSE
    opendoor 3, 3
    waitdooranim
    fadeinbgm 0
    addobject LOCALID_BILL_HUMAN
    clearflag FLAG_HIDE_BILL_HUMAN_SEA_COTTAGE
    delay 50
    playfanfare MUS_LEVEL_UP
    applymovement LOCALID_BILL_HUMAN, SeaCottage_Movement_BillExitTeleporter
    waitmovement 0
    waitfanfare
    applymovement OBJ_EVENT_ID_CAMERA, SeaCottage_Movement_CameraPanBackFromTeleporters
    waitmovement 0
    playse SE_CONTEST_CURTAIN_FALL
    closedoor 3, 3
    waitdooranim
    applymovement LOCALID_BILL_HUMAN, SeaCottage_Movement_BillWalkToMiddleOfRoom
    waitmovement 0
    special RemoveCameraObject
    releaseall
    end

SeaCottage_Movement_CameraPanToTeleporters::
    walk_up
    walk_up
    walk_right
    walk_right
    step_end

SeaCottage_EventScript_PlayTeleporterBeepSE::
    playse SE_BALL
    waitse
    delay 20
    return

SeaCottage_Movement_BillExitTeleporter::
    walk_down
    step_end

SeaCottage_Movement_CameraPanBackFromTeleporters::
    delay_16
    delay_16
    walk_down
    walk_down
    walk_left
    walk_left
    step_end

SeaCottage_Movement_BillWalkToMiddleOfRoom::
    walk_right
    walk_right
    walk_right
    walk_right
    walk_down
    walk_down
    step_end

SeaCottage_Text_CheckOutRareMonsOnPC::
    .string "Bill: Feel like checking out some\n"
    .string "of my rare Pokémon on my PC?\p"
    .string "Go on, check out my PC.$"

SeaCottage_Text_SSAnnePartyYouGoInstead::
    .string "That cruise ship S.S. Anne is in\n"
    .string "Vermilion City.\p"
    .string "I hear there are lots of Trainers\n"
    .string "on board, too.\p"
    .string "They invited me to their party, but\n"
    .string "I can't stand fancy do's.\p"
    .string "Why don't you go instead of me?\n"
    .string "Go on and have a good time.$"

SeaCottage_Text_ThanksBudTakeThis::
    .string "Bill: Yeehah!\n"
    .string "Thanks, bud! I owe you one!\p"
    .string "So, did you come to see my\n"
    .string "Pokémon collection?\p"
    .string "You didn't?\n"
    .string "That's a bummer.\p"
    .string "I've got to thank you…\n"
    .string "Oh, here, maybe this'll do.$"

SeaCottage_Text_ThanksLadyTakeThis::
    .string "Bill: Yeehah!\n"
    .string "Thanks, lady! I owe you one!\p"
    .string "So, did you come to see my\n"
    .string "Pokémon collection?\p"
    .string "You didn't?\n"
    .string "That's a bummer.\p"
    .string "I've got to thank you…\n"
    .string "Oh, here, maybe this'll do.$"

SeaCottage_Text_YouveGotTooMuchStuff::
    .string "You've got too much stuff!$"

SeaCottage_Text_ReceivedSSTicketFromBill::
    .string "{PLAYER} received an S.S. Ticket\n"
    .string "from Bill.$"

SeaCottage_Text_ImBillHelpMeOutPal::
    .string "Hiya! I'm a Pokémon…\n"
    .string "…No I'm not!\p"
    .string "Call me Bill!\n"
    .string "I'm a true-blue Pokémaniac!\p"
    .string "Hey!\n"
    .string "What's with that skeptical look?\p"
    .string "I'm not joshing you, pal.\p"
    .string "I screwed up an experiment and got\n"
    .string "combined with a Pokémon!\p"
    .string "So, how about it?\n"
    .string "Help me out here!$"

SeaCottage_Text_ImBillHelpMeOutLady::
    .string "Hiya! I'm a Pokémon…\n"
    .string "…No I'm not!\p"
    .string "Call me Bill!\n"
    .string "I'm a true-blue Pokémaniac!\p"
    .string "Hey!\n"
    .string "What's with that skeptical look?\p"
    .string "I'm not joshing you, lady.\p"
    .string "I screwed up an experiment and got\n"
    .string "combined with a Pokémon!\p"
    .string "So, how about it?\n"
    .string "Help me out here!$"

SeaCottage_Text_NoPleaseChief::
    .string "No!?\n"
    .string "Now don't be so cold!\p"
    .string "Come on, you gotta help a guy in\n"
    .string "deep, deep trouble!\p"
    .string "What do you say, chief?\n"
    .string "Please?\l"
    .string "Okay?\l"
    .string "All right!$"

SeaCottage_Text_NoPleaseBeautiful::
    .string "No!?\n"
    .string "Now don't be so cold!\p"
    .string "Come on, you gotta help a guy in\n"
    .string "deep, deep trouble!\p"
    .string "What do you say, beautiful?\n"
    .string "Please?\l"
    .string "Okay?\l"
    .string "All right!$"

SeaCottage_Text_RunCellSeparationOnPC::
    .string "Wait till I get inside the\n"
    .string "Teleporter.\p"
    .string "When I do, go to my PC and run\n"
    .string "the Cell Separation System.$"

SeaCottage_Text_BillsFavoriteMonList::
    .string "Bill's favourite Pokémon list!$"

SeaCottage_Text_SeeWhichMon::
    .string "Which Pokémon do you want to see?$"

SeaCottage_Text_InitiatedTeleportersCellSeparator::
    .string "{PLAYER} initiated the Teleporter's\n"
    .string "Cell Separator.$"

SeaCottage_Text_TeleporterIsDisplayed::
    .string "Teleporter is displayed on the PC\n"
    .string "monitor.$"
