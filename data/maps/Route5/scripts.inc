.equ LOCALID_DAYCARE_MAN, 1

Route5_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route5_OnTransition
    .byte 0

Route5_OnTransition:
	randomweather
    call Route5_EventScript_TrySetDayCareManPos
    end

Route5_EventScript_TrySetDayCareManPos::
    goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route5_EventScript_EndSetDayCareManPos
    setobjectxyperm LOCALID_DAYCARE_MAN, 26, 25
Route5_EventScript_EndSetDayCareManPos::
    return

Route5_EventScript_UndergroundPathSign::
    msgbox Route5_Text_UndergroundPathSign, MSGBOX_SIGN
    end

Route5_Text_UndergroundPathSign::
    .string "Underground Path\n"
    .string "Cerulean City - Vermilion City$"
