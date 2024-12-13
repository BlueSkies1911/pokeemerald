SSAnne_1F_Room6_MapScripts::
	.byte 0

SSAnne_1F_Room6_EventScript_Woman::
    lock
    faceplayer
    msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SSAnne_1F_Room6_EventScript_DeclineHeal
    closemessage
    call Common_EventScript_OutOfCenterPartyHeal
    msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed, MSGBOX_DEFAULT
    release
    end

SSAnne_1F_Room6_EventScript_DeclineHeal::
    checkplayergender
    compare VAR_RESULT, MALE
    goto_if_eq SSAnne_1F_Room6_EventScript_DeclineHealMale
    msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister, MSGBOX_DEFAULT
    release
    end

SSAnne_1F_Room6_EventScript_DeclineHealMale::
    msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother, MSGBOX_DEFAULT
    release
    end

SSAnne_1F_Room6_Text_TakeAShortRest::
    .string "You look tired. Would you like to\n"
    .string "take a short rest?$"

SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed::
    .string "I'm glad to see that everyone is\n"
    .string "looking refreshed and chipper.$"

SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother::
    .string "Oh, I'm sorry for fussing over you.\n"
    .string "You look like my little brother…$"

SSAnne_1F_Room6_Text_SorryYouLookLikeMySister::
    .string "Oh, I'm sorry for fussing over you.\n"
    .string "You look like my little sister…$"
