SaffronCity_MrPsychicsHouse_MapScripts::
	.byte 0

SaffronCity_MrPsychicsHouse_EventScript_MrPsychic::
    lock
    faceplayer
    goto_if_set FLAG_GOT_TM29_FROM_MR_PSYCHIC, SaffronCity_MrPsychicsHouse_EventScript_AlreadyGotTM29
    msgbox SaffronCity_MrPsychicsHouse_Text_YouWantedThis, MSGBOX_DEFAULT
    checkitemspace ITEM_TM29, 1
    compare VAR_RESULT, FALSE
    goto_if_eq SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29
    giveitem_msg SaffronCity_MrPsychicsHouse_Text_ReceivedTM29FromMrPsychic, ITEM_TM29
    msgbox SaffronCity_MrPsychicsHouse_Text_ExplainTM29, MSGBOX_DEFAULT
    setflag FLAG_GOT_TM29_FROM_MR_PSYCHIC
    release
    end

SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29::
    msgbox SaffronCity_MrPsychicsHouse_Text_YouveNoRoom, MSGBOX_DEFAULT
    release
    end

SaffronCity_MrPsychicsHouse_EventScript_AlreadyGotTM29::
    msgbox SaffronCity_MrPsychicsHouse_Text_ExplainTM29, MSGBOX_DEFAULT
    release
    end

SaffronCity_MrPsychicsHouse_Text_YouWantedThis::
    .string "…Wait! Don't say a word!\p"
    .string "You wanted this!$"

SaffronCity_MrPsychicsHouse_Text_ReceivedTM29FromMrPsychic::
    .string "{PLAYER} received TM29\n"
    .string "from Mr. Psychic.$"

SaffronCity_MrPsychicsHouse_Text_ExplainTM29::
    .string "You already know, don't you?\n"
    .string "TM29 is Psychic.\p"
    .string "It's an attack that may also lower\n"
    .string "the target's special stats.$"

SaffronCity_MrPsychicsHouse_Text_YouveNoRoom::
    .string "Where do you plan to put this?\n"
    .string "You've no room.$"
