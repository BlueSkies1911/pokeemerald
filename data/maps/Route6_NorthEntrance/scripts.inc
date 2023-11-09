Route6_NorthEntrance_MapScripts::
    .byte 0

Route6_NorthEntrance_EventScript_Guard::
    msgbox Route6_NorthEntrance_Text_HiHowsItGoing, MSGBOX_NPC
    end

Route6_NorthEntrance_EventScript_GuardTriggerLeft::
    lockall
    setvar VAR_TEMP_1, 0
    goto Route6_NorthEntrance_EventScript_GuardTrigger
    end

Route6_NorthEntrance_EventScript_GuardTriggerMid::
    lockall
    setvar VAR_TEMP_1, 1
    goto Route6_NorthEntrance_EventScript_GuardTrigger
    end

Route6_NorthEntrance_EventScript_GuardTriggerRight::
    lockall
    setvar VAR_TEMP_1, 2
    goto Route6_NorthEntrance_EventScript_GuardTrigger
    end

Route6_NorthEntrance_EventScript_GuardTrigger::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    goto_if_set FLAG_GOT_TEA, Route6_NorthEntrance_EventScript_GiveTea
    msgbox Route6_NorthEntrance_Text_ThirstyOnGuardDuty, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Route6_NorthEntrance_Movement_BlockPlayerEntry
    waitmovement 0
    releaseall
    end

Route6_NorthEntrance_EventScript_GiveTea::
    removeitem ITEM_TEA, 1
    goto Route6_NorthEntrance_EventScript_GuardDrinkTea
    end

Route6_NorthEntrance_EventScript_GuardDrinkTea::
    msgbox Route6_NorthEntrance_Text_ThatTeaLooksTasty, MSGBOX_DEFAULT
    closemessage
    compare VAR_TEMP_1, 0
    call_if_eq Route6_NorthEntrance_EventScript_WalkToGuardLeft
    compare VAR_TEMP_1, 1
    call_if_eq Route6_NorthEntrance_EventScript_WalkToGuardMid
    compare VAR_TEMP_1, 2
    call_if_eq Route6_NorthEntrance_EventScript_WalkToGuardRight
    msgbox Route6_NorthEntrance_Text_ThanksIllShareTeaWithGuards, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_ROUTE5_ROUTE6_ROUTE7_ROUTE8_GATES, 1
    releaseall
    end

Route6_NorthEntrance_EventScript_WalkToGuardLeft::
    applymovement OBJ_EVENT_ID_PLAYER, Route6_NorthEntrance_Movement_WalkToGuardLeft
    waitmovement 0
    return

Route6_NorthEntrance_EventScript_WalkToGuardMid::
    applymovement OBJ_EVENT_ID_PLAYER, Route6_NorthEntrance_Movement_WalkToGuardMid
    waitmovement 0
    return

Route6_NorthEntrance_EventScript_WalkToGuardRight::
    applymovement OBJ_EVENT_ID_PLAYER, Route6_NorthEntrance_Movement_WalkToGuardRight
    waitmovement 0
    return

Route6_NorthEntrance_Movement_WalkToGuardLeft::
    walk_right
    walk_right
    step_end

Route6_NorthEntrance_Movement_WalkToGuardMid::
    walk_right
    step_end

Route6_NorthEntrance_Movement_WalkToGuardRight::
    walk_in_place_right
    step_end

Route6_NorthEntrance_Movement_BlockPlayerEntry::
    walk_down
    step_end

Route6_NorthEntrance_Text_ThirstyOnGuardDuty::
    .string "I'm on guard duty.\n"
    .string "Gee, I'm thirsty, though!\p"
    .string "Oh, wait there, the road's closed.$"

Route6_NorthEntrance_Text_ThatTeaLooksTasty::
    .string "Oh, that Tea…\n"
    .string "It looks awfully tasty…$"

Route6_NorthEntrance_Text_ThanksIllShareTeaWithGuards::
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

Route6_NorthEntrance_Text_HiHowsItGoing::
    .string "Hi, how's it going?$"
