CeruleanCity_House5_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_BerryPowderMan::
    lock
    faceplayer
    msgbox CeruleanCity_House5_Text_ILikeBerries, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House5_EventScript_BerryCrushRankings::
    msgbox CeruleanCity_House5_Text_ILikeBerries, MSGBOX_SIGN
    end

CeruleanCity_House5_Text_ILikeBerries::
    .string "Hi! I like berries!$"
