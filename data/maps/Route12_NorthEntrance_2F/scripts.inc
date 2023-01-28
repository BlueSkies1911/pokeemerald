Route12_NorthEntrance_2F_MapScripts::
	.byte 0

Route12_NorthEntrance_2F_EventScript_Lass::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_TM27, Route12_NorthEntrance_2F_EventScript_ExplainTM27
    msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymore, MSGBOX_DEFAULT
    checkitemspace ITEM_TM27, 1
    compare VAR_RESULT, FALSE
    goto_if_eq Route12_NorthEntrance_2F_EventScript_NoRoomForTM27
    giveitem_msg Route12_NorthEntrance_2F_Text_ReceivedTM27FromLittleGirl, ITEM_TM27
    msgbox Route12_NorthEntrance_2F_Text_ExplainTM27, MSGBOX_DEFAULT
    setflag FLAG_RECEIVED_TM27
    release
    end

Route12_NorthEntrance_2F_EventScript_NoRoomForTM27::
    msgbox Route12_NorthEntrance_2F_Text_DontHaveRoomForThis, MSGBOX_DEFAULT
    release
    end

Route12_NorthEntrance_2F_EventScript_ExplainTM27::
    msgbox Route12_NorthEntrance_2F_Text_ExplainTM27, MSGBOX_DEFAULT
    release
    end

Route12_NorthEntrance_2F_EventScript_LeftBinoculars::
    msgbox Route12_NorthEntrance_2F_Text_TheresManFishing, MSGBOX_SIGN
    end

Route12_NorthEntrance_2F_EventScript_RightBinoculars::
    msgbox Route12_NorthEntrance_2F_Text_ItsPokemonTower, MSGBOX_SIGN
    end

Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymore::
    .string "My Pokémon's ashes are stored in\n"
    .string "Pokémon Tower.\p"
    .string "You can have this TM.\n"
    .string "I don't need it anymore…$"

Route12_NorthEntrance_2F_Text_ReceivedTM27FromLittleGirl::
    .string "{PLAYER} received TM27\n"
    .string "from the little girl.$"

Route12_NorthEntrance_2F_Text_ExplainTM27::
    .string "TM27 is a move called Return…\p"
    .string "If you treat your Pokémon good,\n"
    .string "it will return your love by working\l"
    .string "its hardest in battle.$"

Route12_NorthEntrance_2F_Text_DontHaveRoomForThis::
    .string "You don't have room for this.$"

Route12_NorthEntrance_2F_Text_TheresManFishing::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "There's a man fishing!$"

Route12_NorthEntrance_2F_Text_ItsPokemonTower::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "It's Pokémon Tower!$"
