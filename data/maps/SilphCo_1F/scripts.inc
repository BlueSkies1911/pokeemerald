SilphCo_1F_MapScripts::
	.byte 0

SilphCo_1F_EventScript_Receptionist::
    lock
    faceplayer
    goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_1F_EventScript_GiveUpgrade
    goto_if_le VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_1F_EventScript_WelcomeMessage
    release
    end

SilphCo_1F_EventScript_GiveUpgrade::
    goto_if_set FLAG_RECEIVED_UPGRADE, SilphCo_1F_EventScript_WelcomeMessage
    msgbox SilphCo_1F_Text_YouSavedUsGiveUpgrade, MSGBOX_DEFAULT
    giveitem ITEM_UPGRADE
    setflag FLAG_RECEIVED_UPGRADE
    release
    end

SilphCo_1F_EventScript_WelcomeMessage::
    msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_DEFAULT
    release
    end

SilphCo_1F_EventScript_FloorSign::
    msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
    end

SilphCo_1F_Text_YouSavedUsGiveUpgrade::
    .string "Hey! It's you!\n"
    .string "Thanks for saving us!\p"
    .string "Please take this as a\n"
    .string "sign of our gratitude!$"

SilphCo_1F_Text_WelcomePresidentInBoardroom::
    .string "Welcome.\p"
    .string "The President is in the boardroom\n"
    .string "on 11F.$"

SilphCo_1F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "1F$"
