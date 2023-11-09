SSAnne_B1F_Room5_MapScripts::
	.byte 0

SSAnne_B1F_Room5_EventScript_Boy::
    msgbox SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks, MSGBOX_NPC
    end

SSAnne_B1F_Room5_EventScript_Machoke::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_MACHOKE, 0
    msgbox SSAnne_B1F_Room5_Text_Machoke, MSGBOX_DEFAULT
    waitmoncry
    release
    end

SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks::
    .string "My buddy Machoke is super strong!\p"
    .string "He has enough Strength to move\n"
    .string "big rocks!$"

SSAnne_B1F_Room5_Text_Machoke::
    .string "Machoke: Gwoh! Goggoh!$"
