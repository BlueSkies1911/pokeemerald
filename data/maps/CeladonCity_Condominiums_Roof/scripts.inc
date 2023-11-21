CeladonCity_Condominiums_Roof_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_Condominiums_Roof_OnTransition
    .byte 0

CeladonCity_Condominiums_Roof_OnTransition:
	randomweather
    end

CeladonCity_Condominiums_Roof_EventScript_Sign::
    msgbox CeladonCity_Condominiums_Roof_Text_IKnowEverything, MSGBOX_SIGN
    end

CeladonCity_Condominiums_Roof_Text_IKnowEverything::
    .string "I KNOW EVERYTHING!$"
