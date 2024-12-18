Route8_WestEntrance_MapScripts::
	.byte 0

Route8_WestEntrance_EventScript_Guard::
    msgbox Route8_WestEntrance_Text_HiHowsItGoing, MSGBOX_NPC
    end

Route8_WestEntrance_EventScript_GuardTriggerTop::
    lockall
    setvar VAR_TEMP_1, 0
    goto Route8_WestEntrance_EventScript_GuardTrigger
    end

Route8_WestEntrance_EventScript_GuardTriggerMid::
    lockall
    setvar VAR_TEMP_1, 1
    goto Route8_WestEntrance_EventScript_GuardTrigger
    end

Route8_WestEntrance_EventScript_GuardTriggerBottom::
    lockall
    setvar VAR_TEMP_1, 2
    goto Route8_WestEntrance_EventScript_GuardTrigger
    end

Route8_WestEntrance_EventScript_GuardTrigger::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    goto_if_set FLAG_GOT_TEA, Route8_WestEntrance_EventScript_GiveTea
    msgbox Route8_WestEntrance_Text_ThirstyOnGuardDuty, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Route8_WestEntrance_Movement_BlockPlayerEntry
    waitmovement 0
    releaseall
    end

Route8_WestEntrance_EventScript_GiveTea::
    removeitem ITEM_TEA, 1
    goto Route8_WestEntrance_EventScript_GuardDrinkTea
    end

Route8_WestEntrance_EventScript_GuardDrinkTea::
    msgbox Route8_WestEntrance_Text_ThatTeaLooksTasty, MSGBOX_DEFAULT
    closemessage
    compare VAR_TEMP_1, 0
    call_if_eq Route8_WestEntrance_EventScript_WalkToGuardTop
    compare VAR_TEMP_1, 1
    call_if_eq Route8_WestEntrance_EventScript_WalkToGuardMid
    compare VAR_TEMP_1, 2
    call_if_eq Route8_WestEntrance_EventScript_WalkToGuardBottom
    msgbox Route8_WestEntrance_Text_ThanksIllShareTeaWithGuards, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_ROUTE5_ROUTE6_ROUTE7_ROUTE8_GATES, 1
    releaseall
    end

Route8_WestEntrance_EventScript_WalkToGuardTop::
    applymovement OBJ_EVENT_ID_PLAYER, Route8_WestEntrance_Movement_WalkToGuardTop
    waitmovement 0
    return

Route8_WestEntrance_EventScript_WalkToGuardMid::
    applymovement OBJ_EVENT_ID_PLAYER, Route8_WestEntrance_Movement_WalkToGuardMid
    waitmovement 0
    return

Route8_WestEntrance_EventScript_WalkToGuardBottom::
    applymovement OBJ_EVENT_ID_PLAYER, Route8_WestEntrance_Movement_WalkToGuardBottom
    waitmovement 0
    return

Route8_WestEntrance_Movement_WalkToGuardMid::
    walk_up
    step_end

Route8_WestEntrance_Movement_WalkToGuardBottom::
    walk_up
    walk_up
    step_end

Route8_WestEntrance_Movement_WalkToGuardTop::
    walk_in_place_up
    step_end

Route8_WestEntrance_Movement_BlockPlayerEntry::
    walk_right
    step_end

Route8_WestEntrance_Text_ThirstyOnGuardDuty::
    .string "I'm on guard duty.\n"
    .string "Gee, I'm thirsty, though!\p"
    .string "Oh, wait there, the road's closed.$"

Route8_WestEntrance_Text_ThatTeaLooksTasty::
    .string "Oh, that Tea…\n"
    .string "It looks awfully tasty…$"

Route8_WestEntrance_Text_ThanksIllShareTeaWithGuards::
    .string "Huh? I can have this drink?\n"
    .string "Gee, thanks!\l"
    .string "… …\l"
    .string "Glug, glug…\l"
    .string "… …\l"
    .string "Gulp…\l"
    .string "If you want to go to Saffron\l"
    .string "City…\l"
    .string "… …\l"
    .string "You can go on through.\p"
    .string "I'll share this Tea with the other\n"
    .string "guards!$"

Route8_WestEntrance_Text_HiHowsItGoing::
    .string "Hi, how's it going?$"
