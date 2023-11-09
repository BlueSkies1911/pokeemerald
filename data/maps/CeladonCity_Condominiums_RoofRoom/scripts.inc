.set LOCALID_EEVEE_POKEBALL, 2

CeladonCity_Condominiums_RoofRoom_MapScripts::
    .byte 0

CeladonCity_Condominiums_RoofRoom_EventScript_BlackBelt::
    msgbox CeladonCity_Condominiums_RoofRoom_Text_TheresNothingIDontKnow, MSGBOX_NPC
    end

CeladonCity_Condominiums_RoofRoom_EventScript_EeveeBall::
    lock
    faceplayer
    setvar VAR_TEMP_1, SPECIES_EEVEE
    givemon SPECIES_EEVEE, 25, ITEM_NONE
    compare VAR_RESULT, 0
    goto_if_eq CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveeParty
    compare VAR_RESULT, 1
    goto_if_eq CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveePC
    compare VAR_RESULT, 2
    goto_if_eq Common_EventScript_NoMoreRoomForPokemon
    release
    end

CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveeParty::
    removeobject LOCALID_EEVEE_POKEBALL
    playfanfare MUS_LEVEL_UP
    message CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee
    waitmessage
    waitfanfare
    bufferspeciesname 0, SPECIES_EEVEE
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
    call Common_EventScript_GetGiftMonPartySlot
    call Common_EventScript_NameReceivedPartyMon
    goto CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
    end

CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveePC::
    removeobject LOCALID_EEVEE_POKEBALL
    playfanfare MUS_LEVEL_UP
    message CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee
    waitmessage
    waitfanfare
    bufferspeciesname 0, SPECIES_EEVEE
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC
    call Common_EventScript_NameReceivedBoxMon
    goto CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC
    end

CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC::
    call Common_EventScript_TransferredToPC
    goto CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
    end

CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee::
    setflag FLAG_GOT_EEVEE
    release
    end

CeladonCity_Condominiums_RoofRoom_EventScript_TMsPamphlet::
    msgbox CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs, MSGBOX_SIGN
    end

CeladonCity_Condominiums_RoofRoom_EventScript_Blackboard::
    lockall
    msgbox CeladonCity_Condominiums_RoofRoom_Text_WirelessAdapterLecture, MSGBOX_DEFAULT
    message CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading
    waitmessage
    setvar VAR_0x8004, 4
    multichoice 0, 0, MULTI_LINKED_DIRECT_UNION, FALSE
    switch VAR_RESULT
    case 0, CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub
    case 1, CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner
    case 2, CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom
    case 3, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
    case 127, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
    end

CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading::
    message CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading
    waitmessage
    multichoice 0, 0, MULTI_LINKED_DIRECT_UNION, FALSE
    switch VAR_RESULT
    case 0, CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub
    case 1, CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner
    case 2, CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom
    case 3, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
    case 127, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
    end

CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub::
    msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainWirelessClub, MSGBOX_DEFAULT
    goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
    end

CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner::
    msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainDirectCorner, MSGBOX_DEFAULT
    goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
    end

CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom::
    msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainUnionRoom, MSGBOX_DEFAULT
    goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
    end

CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard::
    releaseall
    end

CeladonCity_Condominiums_RoofRoom_Text_TheresNothingIDontKnow::
    .string "There is nothing that I don't know,\n"
    .string "like I wrote on the blackboard.\p"
    .string "I know about the world of Pokémon\n"
    .string "in your Game Boy Advance!\p"
    .string "Get together with your friends and\n"
    .string "enjoy trading Pokémon!$"

CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee::
    .string "{PLAYER} obtained an Eevee!$"

CeladonCity_Condominiums_RoofRoom_Text_WirelessAdapterLecture::
    .string "Pokémon Lecture\p"
    .string "Playing with the Wireless Adapter$"

CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading::
    .string "Which heading do you want to read?$"

CeladonCity_Condominiums_RoofRoom_Text_ExplainWirelessClub::
    .string "The Pokémon Wireless Club is\n"
    .string "upstairs at any Pokémon Center.\p"
    .string "Visit one to link up with friend(s)\n"
    .string "using your Wireless Adapter.$"

CeladonCity_Condominiums_RoofRoom_Text_ExplainDirectCorner::
    .string "To link only with a friend, go to\n"
    .string "the Direct Corner.\p"
    .string "It is the right counter at the\n"
    .string "Pokémon Wireless Club.\p"
    .string "Go into the Trade Corner or the\n"
    .string "Colosseum with your friend.$"

CeladonCity_Condominiums_RoofRoom_Text_ExplainUnionRoom::
    .string "To link and communicate with\n"
    .string "anyone, go to the Union Room.\p"
    .string "It is the left counter at the\n"
    .string "Pokémon Wireless Club.\p"
    .string "Go to the Union Room and enjoy\n"
    .string "meeting other Trainers.$"

CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs::
    .string "It's a pamphlet on TMs.\p"
    .string "… …\p"
    .string "There are fifty TMs in all.\p"
    .string "There are also seven HMs that\n"
    .string "can be used repeatedly.\p"
    .string "Silph Co.$"
