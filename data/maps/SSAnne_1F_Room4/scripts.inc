SSAnne_1F_Room4_MapScripts::
	.byte 0

SSAnne_1F_Room4_EventScript_Woman::
    lock
    faceplayer
    checkplayergender
    compare VAR_RESULT, MALE
    goto_if_eq SSAnne_1F_Room4_EventScript_WomanPlayerMale
    msgbox SSAnne_1F_Room4_Text_WaitressCherryPiePlease, MSGBOX_DEFAULT
    release
    end

SSAnne_1F_Room4_EventScript_WomanPlayerMale::
    msgbox SSAnne_1F_Room4_Text_WaiterCherryPiePlease, MSGBOX_DEFAULT
    release
    end

SSAnne_1F_Room4_Text_WaiterCherryPiePlease::
    .string "Waiter, I would like a cherry pie,\n"
    .string "please!$"

SSAnne_1F_Room4_Text_WaitressCherryPiePlease::
    .string "Waitress, I would like a cherry\n"
    .string "pie, please!$"
