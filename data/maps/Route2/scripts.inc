Route2_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
    .byte 0

Route2_OnTransition:
	randomweather
    end

Route2_EventScript_RouteSign::
    msgbox Route2_Text_RouteSign, MSGBOX_SIGN
    end

Route2_EventScript_DiglettsCaveSign::
    msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
    end

Route2_EventScript_FlowerShopSign::
	msgbox Route2_Text_PrettyPetalFlowShop, MSGBOX_SIGN
	end
    
Route2_Text_RouteSign::
    .string "Route 2\n"
    .string "Viridian City - Pewter City$"

Route2_Text_DiglettsCave::
    .string "Diglett's Cave$"

Route2_Text_PrettyPetalFlowShop::
	.string "Pretty Petal Flower Shop$"
