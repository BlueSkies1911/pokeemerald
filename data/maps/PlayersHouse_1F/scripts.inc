.set LOCALID_MOM, 1

PlayersHouse_1F_MapScripts::
	.byte 0

PlayersHouse_1F_EventScript_Mom::
    lock
    faceplayer
    compare VAR_MAP_SCENE_PALLET_TOWN_MOM, 2
    goto_if_eq PlayersHouse_1F_EventScript_MomHeal
    goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PlayersHouse_1F_EventScript_MomMeetProfOak
    checkplayergender
    call_if_eq VAR_RESULT, MALE, PlayersHouse_1F_EventScript_MomOakLookingForYouMale
    call_if_eq VAR_RESULT, FEMALE, PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
    closemessage
    applymovement LOCALID_MOM, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

PlayersHouse_1F_EventScript_MomHeal::
    msgbox PlayersHouse_1F_Text_YouShouldTakeQuickRest, MSGBOX_DEFAULT
    closemessage
    call Common_EventScript_OutOfCenterPartyHeal
    msgbox PlayersHouse_1F_Text_LookingGreatTakeCare, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_MOM, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

PlayersHouse_1F_EventScript_MomMeetProfOak::
    msgbox PlayersHouse_1F_Text_MomMeetProfOak, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_MOM, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end
    
PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
    msgbox PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou, MSGBOX_DEFAULT
    return
    
PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
    msgbox PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou, MSGBOX_DEFAULT
    return

PlayersHouse_1F_Text_YouShouldTakeQuickRest::
    .string "Mom: {PLAYER}!\n"
    .string "You should take a quick rest.$"

PlayersHouse_1F_Text_LookingGreatTakeCare::
    .string "Mom: Oh, good! You and your\n"
    .string "Pokémon are looking great.\l"
    .string "Take care now!$"

PlayersHouse_1F_Text_MomMeetProfOak::
    .string "Mom: Did you meet Prof. Oak?$"

PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou:
    .string "Mom: ...Right.\n"
    .string "All boys leave home someday.\l"
    .string "It said so on TV.\p"
    .string "Oh, yes. Prof. Oak, next door, was\n"
    .string "looking for you.$"

PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou:
    .string "Mom: ...Right.\n"
    .string "All girls dream of travelling.\l"
    .string "It said so on TV.\p"
    .string "Oh, yes. Prof. Oak, next door, was\n"
    .string "looking for you.$"
