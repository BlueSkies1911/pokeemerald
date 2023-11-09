FuchsiaCity_SafariZone_Entrance_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZone_Entrance_OnFrame
	.byte 0

FuchsiaCity_SafariZone_Entrance_OnFrame:
    map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1, FuchsiaCity_SafariZone_Entrance_EventScript_ExitWarpIn
    map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2, FuchsiaCity_SafariZone_Entrance_EventScript_ExitEarly
    map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3, FuchsiaCity_SafariZone_Entrance_EventScript_ExitWalkIn
    .2byte 0

FuchsiaCity_SafariZone_Entrance_EventScript_ExitWalkIn::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ApproachCounter
    waitmovement 0
    msgbox FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit2
    waitmovement 0
    special ExitSafariMode
    setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
    releaseall
    end

FuchsiaCity_SafariZone_Entrance_EventScript_ExitWarpIn::
    lockall
    msgbox FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit
    waitmovement 0
    special ExitSafariMode
    setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
    releaseall
    end

FuchsiaCity_SafariZone_Entrance_EventScript_ExitEarly::
    lockall
    msgbox FuchsiaCity_SafariZone_Entrance_Text_GoingToLeaveSafariZoneEarly, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq FuchsiaCity_SafariZone_Entrance_EventScript_ReturnToSafariZone
    msgbox FuchsiaCity_SafariZone_Entrance_Text_PleaseReturnSafariBalls, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit
    waitmovement 0
    special ExitSafariMode
    setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
    releaseall
    end

FuchsiaCity_SafariZone_Entrance_EventScript_ReturnToSafariZone::
    msgbox FuchsiaCity_SafariZone_Entrance_Text_GoodLuck, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ReEnter
    waitmovement 0
    warp MAP_SAFARI_ZONE_CENTER, 26, 30
    waitstate
    end

FuchsiaCity_SafariZone_Entrance_Movement_Exit::
    walk_down
    walk_down
    step_end

FuchsiaCity_SafariZone_Entrance_Movement_ReEnter::
    walk_up
    step_end

FuchsiaCity_SafariZone_Entrance_Movement_Exit2::
    walk_down
    walk_down
    step_end

FuchsiaCity_SafariZone_Entrance_Movement_ApproachCounter::
    walk_down
    delay_8
    step_end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerMid::
    lockall
    setvar VAR_TEMP_2, 0
    goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
    end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerRight::
    lockall
    setvar VAR_TEMP_2, 1
    goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
    end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerLeft::
    lockall
    setvar VAR_TEMP_2, 2
    goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
    end

FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone::
    msgbox FuchsiaCity_SafariZone_Entrance_Text_WelcomeToSafariZone, MSGBOX_DEFAULT
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    showmoneybox 0, 0, 0
    msgbox FuchsiaCity_SafariZone_Entrance_Text_PlaySafariGameFor500, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone
    msgbox FuchsiaCity_SafariZone_Entrance_Text_OkayPleaseComeAgain, MSGBOX_DEFAULT
    goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
    end

FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone::
    call FuchsiaCity_SafariZone_Entrance_EventScript_CheckSpaceForMons
    checkmoney 500, 0
    compare VAR_RESULT, FALSE
    goto_if_eq FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney
    removemoney 500, 0
    updatemoneybox
    msgbox FuchsiaCity_SafariZone_Entrance_Text_ThatllBe500WeOnlyUseSpecialBalls, MSGBOX_DEFAULT
    playfanfare MUS_LEVEL_UP
    message FuchsiaCity_SafariZone_Entrance_Text_PlayerReceived30SafariBalls
    waitfanfare
    msgbox FuchsiaCity_SafariZone_Entrance_Text_CallYouOnPAWhenYouRunOut, MSGBOX_DEFAULT
    closemessage
    hidemoneybox
    compare VAR_TEMP_2, 0
    call_if_eq FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneMid
    compare VAR_TEMP_2, 1
    call_if_eq FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneRight
    compare VAR_TEMP_2, 2
    call_if_eq FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneLeft
    special EnterSafariMode
    setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2
    warp MAP_SAFARI_ZONE_CENTER, 26, 30
    waitstate
    end

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneRight::
    applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneRight
    waitmovement 0
    return

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneMid::
    applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneMid
    waitmovement 0
    return

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneLeft::
    applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneLeft
    waitmovement 0
    return

FuchsiaCity_SafariZone_Entrance_EventScript_CheckSpaceForMons::
    getpartysize
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ne Common_EventScript_NopReturn
    specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
    compare VAR_RESULT, TRUE
    goto_if_eq Common_EventScript_NopReturn
    msgbox SafariZone_Text_ExcuseMeYourPCBoxIsFull, MSGBOX_DEFAULT
    goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
    end

FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney::
    msgbox FuchsiaCity_SafariZone_Entrance_Text_OopsNotEnoughMoney, MSGBOX_DEFAULT
    goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
    end

FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack::
    closemessage
    hidemoneybox
    applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ForceBack
    waitmovement 0
    releaseall
    end

FuchsiaCity_SafariZone_Entrance_Movement_ForceBack::
    walk_down
    step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneMid::
    walk_up
    walk_up
    step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneRight::
    walk_up
    walk_left
    walk_up
    step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneLeft::
    walk_up
    walk_right
    walk_up
    step_end

FuchsiaCity_SafariZone_Entrance_EventScript_InfoAttendant::
    lock
    faceplayer
    msgbox FuchsiaCity_SafariZone_Entrance_Text_FirstTimeAtSafariZone, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq FuchsiaCity_SafariZone_Entrance_EventScript_ExplainSafariZone
    msgbox FuchsiaCity_SafariZone_Entrance_Text_SorryYoureARegularHere, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_SafariZone_Entrance_EventScript_ExplainSafariZone::
    msgbox FuchsiaCity_SafariZone_Entrance_Text_ExplainSafariZone, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_SafariZone_Entrance_Text_WelcomeToSafariZone::
    .string "Welcome to the Safari Zone!$"

FuchsiaCity_SafariZone_Entrance_Text_PlaySafariGameFor500::
    .string "For just ¥500, you can play the\n"
    .string "Safari Game.\p"
    .string "You can roam the wide-open safari\n"
    .string "and catch what you like.\p"
    .string "Would you like to play?$"

FuchsiaCity_SafariZone_Entrance_Text_ThatllBe500WeOnlyUseSpecialBalls::
    .string "That'll be ¥500, please!\p"
    .string "We only use a special kind of \n"
    .string "Poké Ball here.$"

FuchsiaCity_SafariZone_Entrance_Text_PlayerReceived30SafariBalls::
    .string "{PLAYER} received 30 Safari Balls\n"
    .string "from the attendant.$"

FuchsiaCity_SafariZone_Entrance_Text_CallYouOnPAWhenYouRunOut::
    .string "We'll call you on the PA when you\n"
    .string "run out of time or Safari Balls.\p"
    .string "Well, I'll wish you the best of\n"
    .string "luck!$"

FuchsiaCity_SafariZone_Entrance_Text_OkayPleaseComeAgain::
    .string "Okay.\n"
    .string "Please come again!$"

FuchsiaCity_SafariZone_Entrance_Text_OopsNotEnoughMoney::
    .string "Oops!\n"
    .string "Not enough money!$"

FuchsiaCity_SafariZone_Entrance_Text_GoingToLeaveSafariZoneEarly::
    .string "Are you going to leave the\n"
    .string "Safari Zone early?$"

FuchsiaCity_SafariZone_Entrance_Text_PleaseReturnSafariBalls::
    .string "Please return any Safari Balls\n"
    .string "you may have left.$"

FuchsiaCity_SafariZone_Entrance_Text_GoodLuck::
    .string "Good luck!$"

FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain::
    .string "Did you catch your fair share?\n"
    .string "Come again!$"

FuchsiaCity_SafariZone_Entrance_Text_FirstTimeAtSafariZone::
    .string "Hi! Is it your first time here at\n"
    .string "the Safari Zone?$"

FuchsiaCity_SafariZone_Entrance_Text_ExplainSafariZone::
    .string "The Safari Zone actually has\n"
    .string "four zones in it.\p"
    .string "Each zone has different kinds of\n"
    .string "Pokémon, even some rare ones.\p"
    .string "Use the supplied Safari Balls to\n"
    .string "catch them.\p"
    .string "You can also throw Bait or Rocks\n"
    .string "besides the Safari Balls.\p"
    .string "If you throw Bait, the Pokémon\n"
    .string "becomes less likely to flee, but\l"
    .string "harder to catch.\p"
    .string "If you throw Rocks, the Pokémon\n"
    .string "becomes more likely to flee, but\l"
    .string "easier to catch.\p"
    .string "When you run out of time or Safari\n"
    .string "Balls, it's game over for you!$"

FuchsiaCity_SafariZone_Entrance_Text_SorryYoureARegularHere::
    .string "Sorry, you're a regular here!$"
