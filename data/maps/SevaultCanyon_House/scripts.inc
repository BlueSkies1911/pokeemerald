.set LOCALID_BALDING_MAN, 1

SevaultCanyon_House_MapScripts::
    .byte 0

SevaultCanyon_House_EventScript_BaldingMan::
    lock
    goto_if_set FLAG_TEMP_2, SevaultCanyon_House_EventScript_AlreadyDanced
    playbgm MUS_SCHOOL, 0
    applymovement LOCALID_BALDING_MAN, SevaultCanyon_House_Movement_ChanseyDance
    waitmovement 0
    fadedefaultbgm
    delay 30
    applymovement LOCALID_BALDING_MAN, Common_Movement_FacePlayer
    waitmovement 0
    msgbox SevaultCanyon_House_Text_ChanseyDanceJoinIn, MSGBOX_DEFAULT
    msgbox SevaultCanyon_House_Text_WouldYouLikeToDance, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SevaultCanyon_House_EventScript_DeclineDance
    msgbox SevaultCanyon_House_Text_DancedChanseyDance, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_SOUTH
    call_if_ne SevaultCanyon_House_EventScript_PlayerFaceDown
    delay 30
    playbgm MUS_SCHOOL, 0
    applymovement OBJ_EVENT_ID_PLAYER, SevaultCanyon_House_Movement_ChanseyDance
    waitmovement 0
    fadedefaultbgm
    delay 30
    call Common_EventScript_OutOfCenterPartyHeal
    msgbox SevaultCanyon_House_Text_YoureAllChipperNow
    setflag FLAG_TEMP_2
    release
    end

SevaultCanyon_House_EventScript_PlayerFaceDown::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

SevaultCanyon_House_EventScript_AlreadyDanced::
    applymovement LOCALID_BALDING_MAN, Common_Movement_FacePlayer
    waitmovement 0
    msgbox SevaultCanyon_House_Text_ChanseyDanceJoinIn, MSGBOX_DEFAULT
    release
    end

SevaultCanyon_House_EventScript_DeclineDance::
    msgbox SevaultCanyon_House_Text_ComeOnDance, MSGBOX_DEFAULT
    release
    end

SevaultCanyon_House_Movement_ChanseyDance::
    walk_in_place_down
    delay_16
    walk_in_place_down
    delay_16
    walk_in_place_down
    delay_16
    walk_in_place_down
    delay_16
    walk_in_place_faster_right
    delay_4
    walk_in_place_faster_up
    delay_4
    walk_in_place_faster_left
    delay_4
    walk_in_place_faster_down
    delay_4
    step_end

SevaultCanyon_House_EventScript_Chansey::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_CHANSEY, 0
    msgbox SevaultCanyon_House_Text_Chansey, MSGBOX_DEFAULT
    waitmoncry
    release
    end

SevaultCanyon_House_Text_ChanseyDanceJoinIn::
    .string "Dance, dance!\n"
    .string "Chansey Dance!\p"
    .string "You join in, too!\n"
    .string "Dance, dance!$"

SevaultCanyon_House_Text_WouldYouLikeToDance::
    .string "Would you like to dance?$"

SevaultCanyon_House_Text_ComeOnDance::
    .string "Come on, dance!$"

SevaultCanyon_House_Text_DancedChanseyDance::
    .string "{PLAYER} danced the Chansey Dance!$"

SevaultCanyon_House_Text_YoureAllChipperNow::
    .string "Ahahahaha!\p"
    .string "There, you're all chipper now!\n"
    .string "Lucky!$"

SevaultCanyon_House_Text_Chansey::
    .string "Chansey: Chansi! Chansi!$"
