SSAnne_1F_Room3_MapScripts::
	.byte 0

SSAnne_1F_Room3_EventScript_LittleGirl::
    msgbox SSAnne_1F_Room3_Text_AlwaysTravelWithWigglytuff, MSGBOX_NPC
    end

SSAnne_1F_Room3_EventScript_BaldingMan::
    msgbox SSAnne_1F_Room3_Text_CruiseIsElegantAndCozy, MSGBOX_NPC
    end

SSAnne_1F_Room3_EventScript_Wigglytuff::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_WIGGLYTUFF, 0
    msgbox SSAnne_1F_Room3_Text_Wigglytuff
    waitmoncry
    release
    end

SSAnne_1F_Room3_Text_CruiseIsElegantAndCozy::
    .string "A world cruise is so elegant yet\n"
    .string "cozy!$"

SSAnne_1F_Room3_Text_AlwaysTravelWithWigglytuff::
    .string "I always travel with Wigglytuff.\n"
    .string "I never leave home without it.$"

SSAnne_1F_Room3_Text_Wigglytuff::
    .string "Wigglytuff: Puup pupuu!$"