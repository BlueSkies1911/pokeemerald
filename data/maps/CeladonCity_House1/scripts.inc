CeladonCity_House1_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_RocketChief::
    msgbox CeladonCity_House1_Text_SlotsReelInTheDough, MSGBOX_NPC
    end

CeladonCity_House1_EventScript_Rocket1::
    msgbox CeladonCity_House1_Text_ShippedMonsAsSlotPrizes, MSGBOX_NPC
    end

CeladonCity_House1_EventScript_Rocket2::
    msgbox CeladonCity_House1_Text_DontTouchGameCornerPoster, MSGBOX_NPC
    end

CeladonCity_House1_Text_SlotsReelInTheDough::
    .string "Hehehe!\p"
    .string "The slots just reel in the dough,\n"
    .string "big-time!$"

CeladonCity_House1_Text_ShippedMonsAsSlotPrizes::
    .string "Chief!\p"
    .string "We just shipped two thousand\n"
    .string "more Pokémon as slot prizes\l"
    .string "again today!$"

CeladonCity_House1_Text_DontTouchGameCornerPoster::
    .string "Don't touch the poster at the Game\n"
    .string "Corner!\p"
    .string "There's no secret switch behind it!$"
