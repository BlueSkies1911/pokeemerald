.set LOCALID_NIDORAN, 3

PewterCity_House1_MapScripts::
    .byte 0

PewterCity_House1_EventScript_BaldingMan::
    msgbox PewterCity_House1_Text_TradeMonsAreFinicky, MSGBOX_NPC
    end

PewterCity_House1_EventScript_LittleBoy::
    lock
    msgbox PewterCity_House1_Text_NidoranSit, MSGBOX_DEFAULT
    call PewterCity_House1_EventScript_DoNidoranCry
    release
    end

PewterCity_House1_EventScript_Nidoran::
    lock
    faceplayer
    call PewterCity_House1_EventScript_DoNidoranCry
    applymovement LOCALID_NIDORAN, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

PewterCity_House1_EventScript_DoNidoranCry::
    waitse
    playmoncry SPECIES_NIDORAN_M, 0
    msgbox PewterCity_House1_Text_Nidoran, MSGBOX_DEFAULT
    waitmoncry
    return

PewterCity_House1_Text_Nidoran::
    .string "Nidoran♂: Bowbow!$"

PewterCity_House1_Text_NidoranSit::
    .string "Nidoran, sit!$"

PewterCity_House1_Text_TradeMonsAreFinicky::
    .string "Our Pokémon's an outsider, so it's\n"
    .string "finicky and hard to handle.\p"
    .string "An outsider is a Pokémon that you\n"
    .string "get in a trade.\p"
    .string "It grows fast, but it may ignore an\n"
    .string "unskilled Trainer in battle.\p"
    .string "If only we had some Badges…$"
