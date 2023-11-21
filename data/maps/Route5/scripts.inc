Route5_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route5_OnTransition
    .byte 0

Route5_OnTransition:
	randomweather
    end

Route5_EventScript_UndergroundPathSign::
    msgbox Route5_Text_UndergroundPathSign, MSGBOX_SIGN
    end

Route5_Text_UndergroundPathSign::
    .string "Underground Path\n"
    .string "Cerulean City - Vermilion City$"
