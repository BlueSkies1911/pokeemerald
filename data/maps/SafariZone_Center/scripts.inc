SafariZone_Center_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_Center_OnTransition
    .byte 0

SafariZone_Center_OnTransition:
	randomweather
    end

SafariZone_Center_EventScript_RestHouseSign::
    msgbox SafariZone_Center_Text_RestHouse, MSGBOX_SIGN
    end

SafariZone_Center_EventScript_TrainerTips::
    msgbox SafariZone_Center_Text_PressStartToCheckTime, MSGBOX_SIGN
    end

SafariZone_Center_EventScript_AreaSign::
    msgbox SafariZone_Center_Text_CenterArea, MSGBOX_SIGN
    end

SafariZone_Center_Text_RestHouse::
    .string "Rest House$"

SafariZone_Center_Text_PressStartToCheckTime::
    .string "Trainer Tips\p"
    .string "Press Start to check\n"
    .string "remaining time.$"

SafariZone_Center_Text_CenterArea::
    .string "Center Area$"
