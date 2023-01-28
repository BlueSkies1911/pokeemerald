.equ LOCALID_BILL,  2
.equ LOCALID_CELIO, 3

OneIsland_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    map_script MAP_SCRIPT_ON_LOAD, OneIsland_PokemonCenter_1F_OnLoad
    map_script MAP_SCRIPT_ON_FRAME_TABLE, OneIsland_PokemonCenter_1F_OnFrame
    .byte 0

OneIsland_PokemonCenter_1F_OnLoad:
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
    call_if_ge OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
    call_if_set FLAG_SYS_CAN_LINK_WITH_RS, OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
    end

OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile::
    setmetatile 13, 4, METATILE_PokemonCenter_NetworkMachine_Ruby, 1
    return

OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile::
    setmetatile 16, 4, METATILE_PokemonCenter_NetworkMachine_Sapphire, 1
    return

OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn::
    call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
    setmetatile 14, 4, METATILE_PokemonCenter_NetworkMachine_ScreenLeft_On, 1
    setmetatile 15, 4, METATILE_PokemonCenter_NetworkMachine_ScreenRight_On, 1
    return

OneIsland_PokemonCenter_1F_OnTransition:
    setrespawn HEAL_LOCATION_ONE_ISLAND
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6
    call_if_eq OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0
    call_if_eq OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2
    call_if_eq OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos
    end

OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone::
    setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7
    return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos::
    setobjectxyperm LOCALID_BILL, 9, 8
    setobjectmovementtype LOCALID_BILL, MOVEMENT_TYPE_FACE_UP
    setobjectxyperm LOCALID_CELIO, 15, 6
    setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_UP
    return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos::
    setobjectxyperm LOCALID_BILL, 14, 7
    setobjectmovementtype LOCALID_BILL, MOVEMENT_TYPE_FACE_LEFT
    setobjectxyperm LOCALID_CELIO, 14, 8
    setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_LEFT
    return

OneIsland_PokemonCenter_1F_OnFrame::
    map_script_2 VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene
    .2byte 0

OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio
    applymovement LOCALID_BILL, OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio, MSGBOX_DEFAULT
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_CELIO, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    applymovement LOCALID_CELIO, Common_Movement_Delay48
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut, MSGBOX_DEFAULT
    msgbox OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing, MSGBOX_DEFAULT
    applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterDown
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio, MSGBOX_DEFAULT
    applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    call_if_set FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp
    call_if_unset FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp
    applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive, MSGBOX_DEFAULT
    msgbox OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed, MSGBOX_DEFAULT
    applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou, MSGBOX_DEFAULT
    applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer, MSGBOX_DEFAULT
    msgreceiveditem OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill, ITEM_METEORITE, 1, MUS_RG_OBTAIN_KEY_ITEM
    additem ITEM_METEORITE
    applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis, MSGBOX_DEFAULT
    giveitem_msg OneIsland_PokemonCenter_1F_Text_ObtainedTriPass, ITEM_TRI_PASS, 1, MUS_RG_OBTAIN_KEY_ITEM
    msgbox OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands, MSGBOX_DEFAULT
    playfanfare MUS_RG_OBTAIN_KEY_ITEM
    message OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap
    waitmessage
    waitfanfare
    setflag FLAG_SYS_SEVII_MAP_123
    msgbox OneIsland_PokemonCenter_1F_Text_BillCatchYouLater, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    setflag FLAG_SYS_PC_STORAGE_DISABLED
    setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1
    releaseall
    end

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp::
    msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp, MSGBOX_DEFAULT
    return

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp::
    msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp, MSGBOX_DEFAULT
    return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio::
    walk_up
    walk_up
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_in_place_faster_up
    step_end

OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio::
    walk_up
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    walk_in_place_faster_right
    step_end

OneIsland_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end

OneIsland_PokemonCenter_1F_EventScript_Bill::
    lock
    goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll
    msgbox OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll::
    applymovement LOCALID_BILL, Common_Movement_FacePlayer
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_EventScript_Celio::
    lock
    faceplayer
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7
    goto_if_eq OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6
    goto_if_eq OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire
    goto_if_set FLAG_RECOVERED_SAPPHIRE, OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
    goto_if_eq OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
    goto_if_set FLAG_GOT_RUBY, OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
    goto_if_eq OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby
    specialvar VAR_RESULT, IsNationalPokedexEnabled
    compare VAR_RESULT, TRUE
    goto_if_eq OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby
    compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3
    goto_if_eq OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex
    msgbox OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_CELIO, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact::
    msgbox OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou, MSGBOX_DEFAULT
    random 3
    compare VAR_RESULT, 0
    goto_if_eq OneIsland_PokemonCenter_1F_EventScript_BillFact1
    compare VAR_RESULT, 1
    goto_if_eq OneIsland_PokemonCenter_1F_EventScript_BillFact2
    msgbox OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_EventScript_BillFact1::
    msgbox OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_EventScript_BillFact2::
    msgbox OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire::
    msgbox OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire::
    playfanfare MUS_OBTAIN_TMHM
    message OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio
    waitmessage
    waitfanfare
    removeitem ITEM_SAPPHIRE, 1
    msgbox OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
    waitmovement 0
    playse SE_CLICK
    call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
    special DrawWholeMapView
    msgbox OneIsland_PokemonCenter_1F_Text_OkayThisIsGood, MSGBOX_DEFAULT
    closemessage
    delay 60
    applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
    waitmovement 0
    delay 30
    applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
    waitmovement 0
    delay 40
    playse SE_PC_ON
    call OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
    special DrawWholeMapView
    msgbox OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette, MSGBOX_DEFAULT
    applymovement LOCALID_CELIO, Common_Movement_FacePlayer
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou, MSGBOX_DEFAULT
	special SetPostgameFlags
    setflag FLAG_SYS_CAN_LINK_WITH_RS
    setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
    setflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
    setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6
    special InitRoamer
    release
    end

OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass::
    msgbox OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby::
    msgbox OneIsland_PokemonCenter_1F_Text_OhThats, MSGBOX_DEFAULT
    playfanfare MUS_OBTAIN_TMHM
    message OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio
    waitmessage
    waitfanfare
    closemessage
    applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
    waitmovement 0
    playse SE_CLICK
    call OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
    special DrawWholeMapView
    delay 30
    applymovement LOCALID_CELIO, Common_Movement_FacePlayer
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
    goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
    end

OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio::
    msgbox OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
    goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
    end

OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass::
    msgbox OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands, MSGBOX_DEFAULT
    removeitem ITEM_RUBY, 1
    removeitem ITEM_TRI_PASS, 1
    setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
    additem ITEM_RAINBOW_PASS
    setflag FLAG_SYS_SEVII_MAP_4567
    playfanfare MUS_RG_OBTAIN_KEY_ITEM
    message OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass
    waitmessage
    waitfanfare
    playfanfare MUS_RG_OBTAIN_KEY_ITEM
    message OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage
    waitmessage
    waitfanfare
    goto OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
    end

OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby::
    msgbox OneIsland_PokemonCenter_1F_Text_TryingToFindGem, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby::
    msgbox OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful, MSGBOX_DEFAULT
    applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway, MSGBOX_DEFAULT
    applymovement LOCALID_CELIO, Common_Movement_FacePlayer
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 1
    setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
    release
    end

OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex::
    msgbox OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine::
    walk_in_place_up
    delay_8
    walk_in_place_up
    step_end

OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine::
    walk_in_place_faster_up
    walk_in_place_up
    delay_16
    walk_in_place_up
    walk_in_place_up
    step_end

OneIsland_PokemonCenter_1F_EventScript_LittleBoy::
    msgbox OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt, MSGBOX_NPC
    end

OneIsland_PokemonCenter_1F_EventScript_Hiker::
    msgbox OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland, MSGBOX_NPC
    end

OneIsland_PokemonCenter_1F_EventScript_BattleGirl::
    lock
    faceplayer
    goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked
    msgbox OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked::
    msgbox OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend, MSGBOX_DEFAULT
    release
    end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachine::
    lockall
    goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn
    goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto
    msgbox OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment, MSGBOX_DEFAULT
    releaseall
    end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto::
    msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto, MSGBOX_DEFAULT
    releaseall
    end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn::
    msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn, MSGBOX_DEFAULT
    releaseall
    end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerTop::
    lockall
    setvar VAR_TEMP_1, 1
    goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
    end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidTop::
    lockall
    setvar VAR_TEMP_1, 2
    goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
    end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidBottom::
    lockall
    setvar VAR_TEMP_1, 3
    goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
    end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerBottom::
    lockall
    setvar VAR_TEMP_1, 4
    goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
    end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene::
    playse SE_PIN
    applymovement LOCALID_BILL, Common_Movement_ExclamationMark
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer, MSGBOX_DEFAULT
    closemessage
    compare VAR_TEMP_1, 1
    call_if_eq OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop
    compare VAR_TEMP_1, 2
    call_if_eq OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop
    compare VAR_TEMP_1, 3
    call_if_eq OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom
    compare VAR_TEMP_1, 4
    call_if_eq OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom
    delay 10
    msgbox OneIsland_PokemonCenter_1F_Text_BillWeGotItDone, MSGBOX_DEFAULT
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick, MSGBOX_DEFAULT
    applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot, MSGBOX_DEFAULT
    msgbox OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    delay 10
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    delay 15
    msgbox OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    delay 15
    applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    msgbox OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime, MSGBOX_DEFAULT
    closemessage
    delay 25
    applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerExit
    applymovement LOCALID_BILL, OneIsland_PokemonCenter_1F_Movement_BillExit
    waitmovement 0
    playse SE_EXIT
    setflag FLAG_HIDE_ONE_ISLAND_POKECENTER_BILL
    setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3
    clearflag FLAG_HIDE_CINNABAR_BILL
    setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 3
    setvar VAR_0x8004, SEAGALLOP_ONE_ISLAND
    setvar VAR_0x8006, SEAGALLOP_CINNABAR_ISLAND
    goto EventScript_SetSail
    end

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop::
    applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop
    waitmovement 0
    return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop::
    applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop
    waitmovement 0
    return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom::
    applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom
    waitmovement 0
    return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom::
    applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom
    waitmovement 0
    return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop::
    walk_right
    walk_down
    walk_in_place_faster_right
    step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop::
    walk_right
    step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom::
    walk_right
    walk_up
    walk_in_place_faster_right
    step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom::
    walk_right
    walk_up
    walk_up
    walk_in_place_faster_right
    step_end

OneIsland_PokemonCenter_1F_Movement_PlayerExit::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    step_end

OneIsland_PokemonCenter_1F_Movement_BillExit::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    step_end

OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio::
    .string "Bill: Hey, there!\n"
    .string "Celio!$"

OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut::
    .string "Celio: Bill!\n"
    .string "I can't believe you came out here.$"

OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing::
    .string "Bill: Well, absolutely!\n"
    .string "How's your research coming along?\p"
    .string "…Oh, wait a sec.$"

OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio::
    .string "{PLAYER}, this is my buddy Celio.\n"
    .string "He's one dedicated PC Maniac!$"

OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp::
    .string "Celio, this is {PLAYER}, a rising\n"
    .string "contender as the Pokémon Champ!$"

OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp::
    .string "Celio, this is {PLAYER}, the\n"
    .string "reigning Pokémon Champ!$"

OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive::
    .string "Celio: That's really impressive.\p"
    .string "I hate to say it, but I have zero\n"
    .string "aptitude for battling.\p"
    .string "Anyways, I'm glad to meet you.$"

OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed::
    .string "Bill: So, bring me up to speed.\n"
    .string "How's your machine running?$"

OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours::
    .string "Celio: It's running fine, but we're\n"
    .string "too remote out here.\p"
    .string "The PCs on this island just can't\n"
    .string "link with your PC, Bill.$"

OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou::
    .string "Bill: Oh, yeah?\n"
    .string "Okay, let me take a look-see.\p"
    .string "…Hang on here…\n"
    .string "I think we can make it work.\l"
    .string "Let me help you, okay?$"

OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer::
    .string "{PLAYER}, can I get you to wait for\n"
    .string "me just a bit?\p"
    .string "…Actually, can I get you to do\n"
    .string "me a favour?\p"
    .string "The island next to this one's\n"
    .string "called Two Island.\p"
    .string "There's a guy there that runs\n"
    .string "a Game Corner.\p"
    .string "He has this thing for rare rocks\n"
    .string "and gems.\p"
    .string "We keep in touch, being fellow\n"
    .string "maniacs.\p"
    .string "So, can I get you to deliver this\n"
    .string "Meteorite to him?$"

OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill::
    .string "{PLAYER} accepted the Meteorite\n"
    .string "from Bill.$"

OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis::
    .string "Celio: {PLAYER}, if you are going\n"
    .string "to Two Island, please take this.$"

OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands::
    .string "It's a pass for the ferry service\n"
    .string "serving the local islands.\p"
    .string "It will let you travel between the\n"
    .string "Islands One, Two, and Three.\p"
    .string "Oh, you should have this, too.$"

OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap::
    .string "{PLAYER} received an extra page\n"
    .string "for the Town Map!$"

OneIsland_PokemonCenter_1F_Text_BillCatchYouLater::
    .string "Bill: I'll catch you later!\n"
    .string "Say hi to the guy for me!$"

OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis::
    .string "Hmm…\p"
    .string "How about we try this like this…$"

OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore::
    .string "Oh, hey, {PLAYER}!\p"
    .string "Did you see?\n"
    .string "We got the PC working!\p"
    .string "I've got a few things to show\n"
    .string "Celio here.\p"
    .string "Can you go out on a stroll or\n"
    .string "something for a while more?$"

OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost::
    .string "I'm sorry for taking up so much of\n"
    .string "Bill's time.\p"
    .string "I'm also sorry for being such a \n"
    .string "poor host on your visit here.$"

OneIsland_PokemonCenter_1F_Text_UsualPCServicesUnavailable::
    .string "The usual PC services aren't\n"
    .string "available…$"

OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer::
    .string "Bill: Oh, hey!\n"
    .string "{PLAYER}!$"

OneIsland_PokemonCenter_1F_Text_BillWeGotItDone::
    .string "BILL: What kept you so long?\n"
    .string "Been out having a good time?\p"
    .string "We got it done.\n"
    .string "The PCs are up and running!$"

OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick::
    .string "Celio: The job went incredibly\n"
    .string "quick.\p"
    .string "Bill is one amazing guy…$"

OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot::
    .string "Bill: No, no! There was almost\n"
    .string "nothing left for me to do.\p"
    .string "Celio, I have to hand it to you.\n"
    .string "You've learned a lot.$"

OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe::
    .string "Celio: Oh, really?\n"
    .string "Ehehe…$"

OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto::
    .string "Bill: Well, there you have it.\n"
    .string "I'm finished with the job.\l"
    .string "We should head back to Kanto.\p"
    .string "Celio, I'll be seeing you again.$"

OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime::
    .string "Celio: {PLAYER}, I'm really sorry\n"
    .string "that we sent you off alone today.\p"
    .string "I promise, I will show you around\n"
    .string "these islands sometime.$"

OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine::
    .string "Celio: Hello!\n"
    .string "You look awfully busy as always.\p"
    .string "How am I doing?\p"
    .string "Well, I'm modifying my Network\n"
    .string "Machine.\p"
    .string "When I get done with the machine,\n"
    .string "I hope you'll be first to use it,\l"
    .string "{PLAYER}.$"

OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful::
    .string "Celio: {PLAYER}, how have things\n"
    .string "been for you?\p"
    .string "Oh, is that right?\n"
    .string "You've caught more Pokémon.\p"
    .string "Do you know what?\n"
    .string "Maybe I can be useful to you.$"

OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway::
    .string "I'm modifying the Network Machine\n"
    .string "right now.\p"
    .string "I'm changing it so it can handle\n"
    .string "trades over long distances.\p"
    .string "When I get finished, you'll be\n"
    .string "trading for exotic Pokémon from\l"
    .string "Trainers far away.$"

OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone::
    .string "But, there is a slight catch.\p"
    .string "For the link to work, the Machine\n"
    .string "needs a special gemstone.\p"
    .string "It's supposed to be on One Island,\n"
    .string "but I haven't found one yet.\p"
    .string "Who knows where it could be.$"

OneIsland_PokemonCenter_1F_Text_TryingToFindGem::
    .string "I was trying to find the gem\n"
    .string "even while I was studying.\p"
    .string "As a result, I've made no headway\n"
    .string "in both my search and studies…\p"
    .string "If I relied on Bill, I'm sure my\n"
    .string "research would progress.\p"
    .string "But this time, I want to try to do\n"
    .string "things by myself.$"

OneIsland_PokemonCenter_1F_Text_OhThats::
    .string "Oh!\n"
    .string "Th-that's…$"

OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio::
    .string "{PLAYER} handed the Ruby\n"
    .string "to Celio.$"

OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor::
    .string "Thank you!\n"
    .string "{PLAYER}, you're simply amazing.\p"
    .string "… … …  … … …\p"
    .string "Um… May I ask one more giant favour\n"
    .string "of you?$"

OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp::
    .string "It… It's not anything weird.\n"
    .string "Please, I need your help.$"

OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands::
    .string "While I was studying gemstones,\n"
    .string "I discovered something important.\p"
    .string "There is another gem that forms\n"
    .string "a pair with this Ruby.\p"
    .string "That other gemstone is supposed to\n"
    .string "be in the Sevii Islands.\p"
    .string "{PLAYER}, please, I need you to go\n"
    .string "find the other gem.\p"
    .string "{PLAYER}, may I have your ferry\n"
    .string "pass and the Town Map?$"

OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass::
    .string "{PLAYER} returned the Tri-Pass and\n"
    .string "received the Rainbow Pass.$"

OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage::
    .string "Obtained an extra page for the\n"
    .string "Town Map!$"

OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands::
    .string "This is my own ferry pass.\p"
    .string "It will let you get to all the\n"
    .string "Sevii Islands.\p"
    .string "{PLAYER}, please, I can't do\n"
    .string "it without your help.$"

OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio::
    .string "{PLAYER} handed the Sapphire\n"
    .string "to Celio.$"

OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime::
    .string "Celio: So this is the gem that\n"
    .string "forms a pair with the Ruby…\p"
    .string "{PLAYER}, you've gone through a lot\n"
    .string "to get this, didn't you?\p"
    .string "You don't have to tell me. I know\n"
    .string "it wasn't easy.\p"
    .string "Thank you so much!\p"
    .string "Now it's my turn to work for you!\n"
    .string "Please give me a little time.$"

OneIsland_PokemonCenter_1F_Text_OkayThisIsGood::
    .string "Okay, this is good…$"

OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette::
    .string "I did it!\n"
    .string "I linked up with Lanette!$"

OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou::
    .string "{PLAYER}…\n"
    .string "{PLAYER}, I did it!\p"
    .string "I've managed to link up with\n"
    .string "Trainers in the Hoenn region!\p"
    .string "Finally, the Network Machine is\n"
    .string "fully operational!\p"
    .string "{PLAYER}, I owe it all to you!\p"
    .string "Thanks to you, my dream came\n"
    .string "true…$"

OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck::
    .string "I…\n"
    .string "I'm not crying.\p"
    .string "That's enough about me!\p"
    .string "{PLAYER}, you're going to keep\n"
    .string "looking for exotic Pokémon, right?\p"
    .string "I wish you the best of luck!$"

OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou::
    .string "Celio: Hello!\p"
    .string "{PLAYER}, I've been hearing rumors\n"
    .string "about you.$"

OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra::
    .string "{PLAYER}, what's your favourite kind\n"
    .string "of Pokémon?\p"
    .string "Bill is a Pokémaniac, so he loves\n"
    .string "every kind.\p"
    .string "Apparently, the first one he caught\n"
    .string "was an Abra.$"

OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod::
    .string "By the way, {PLAYER}, you're from\n"
    .string "Pallet Town, aren't you?\p"
    .string "I've heard that it's a quiet and\n"
    .string "pleasant place.\p"
    .string "Bill's hometown is Goldenrod City,\n"
    .string "where his folks still live.\p"
    .string "I've heard that it's quite the\n"
    .string "festive, bustling city.\p"
    .string "I'd like to go there one day.$"

OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk::
    .string "{PLAYER}, is there anything that\n"
    .string "you can't stand?\p"
    .string "Apparently, Bill simply can't\n"
    .string "stomach milk at all.$"

OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt::
    .string "Oh, you're a stranger here!\n"
    .string "Hi! Where did you come from?\p"
    .string "…Pallet Town?\n"
    .string "I don't know it!$"

OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland::
    .string "On this island, there's an enormous\n"
    .string "volcano.\p"
    .string "It hasn't erupted lately, so why\n"
    .string "not enjoy a hike?$"

OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend::
    .string "I wish I could trade Pokémon with\n"
    .string "my boyfriend who lives far away…$"

OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend::
    .string "I traded Pokémon with my boyfriend\n"
    .string "far away!\p"
    .string "Everyone's saying that we can\n"
    .string "thank you and Celio.\p"
    .string "So, thank you!$"

OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment::
    .string "Network Machine\n"
    .string "Link Level 0\p"
    .string "…Pokémon Storage System under\n"
    .string "adjustment…$"

OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto::
    .string "Network Machine\n"
    .string "Link Level 1\p"
    .string "Link established with the Kanto\n"
    .string "region.$"

OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn::
    .string "Network Machine\n"
    .string "Link Level 2\p"
    .string "Link established with the Kanto\n"
    .string "and Hoenn regions.$"

OneIsland_PokemonCenter_1F_Text_ObtainedTriPass::
    .string "Obtained the Tri-Pass!$"
