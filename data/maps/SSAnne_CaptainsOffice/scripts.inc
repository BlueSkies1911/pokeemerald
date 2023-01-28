.set LOCALID_CAPTAIN, 1

SSAnne_CaptainsOffice_MapScripts::
    .byte 0

SSAnne_CaptainsOffice_EventScript_Captain::
    lock
    goto_if_set FLAG_GOT_HM01, SSAnne_CaptainsOffice_EventScript_AlreadyGotCut
    msgbox SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick, MSGBOX_DEFAULT
    message SSAnne_CaptainsOffice_Text_RubbedCaptainsBack
    waitmessage
    playfanfare MUS_HEAL
    waitfanfare
    delay 50
    applymovement LOCALID_CAPTAIN, Common_Movement_FacePlayer
    waitmovement 0
    msgbox SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut, MSGBOX_DEFAULT
    giveitem_msg SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain, ITEM_HM01, 1, MUS_RG_OBTAIN_KEY_ITEM
    msgbox SSAnne_CaptainsOffice_Text_ExplainCut, MSGBOX_DEFAULT
    setflag FLAG_GOT_HM01
    setvar VAR_MAP_SCENE_VERMILION_CITY, 1
    release
    end

SSAnne_CaptainsOffice_EventScript_AlreadyGotCut::
    applymovement LOCALID_CAPTAIN, Common_Movement_FacePlayer
    waitmovement 0
    msgbox SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon, MSGBOX_DEFAULT
    release
    end

SSAnne_CaptainsOffice_EventScript_Book::
    msgbox SSAnne_CaptainsOffice_Text_HowToConquerSeasickness, MSGBOX_SIGN
    end

SSAnne_CaptainsOffice_EventScript_TrashCan::
    msgbox SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked, MSGBOX_SIGN
    end

SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon::
    .string "Captain: …Whew!\p"
    .string "Now that I'm not sick anymore,\n"
    .string "I guess it's time.\p"
    .string "The S.S. Anne will set sail soon!\p"
    .string "Farewell, until our return to\n"
    .string "Vermilion City!$"

SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick::
    .string "Captain: Ooargh…\n"
    .string "I feel hideous…\l"
    .string "Urrp! Seasick…$"

SSAnne_CaptainsOffice_Text_RubbedCaptainsBack::
    .string "{PLAYER} rubbed the Captain's\n"
    .string "back!\p"
    .string "Rub-rub…\n"
    .string "Rub-rub…$"

SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut::
    .string "Captain: Whew! Thank you!\n"
    .string "I'm feeling much better now.\p"
    .string "You want to see my hidden Cut\n"
    .string "technique?\p"
    .string "I could show you my prized Cut\n"
    .string "technique if I weren't so ill…\p"
    .string "I know! You can have this!\n"
    .string "This Hidden Machine!\p"
    .string "Teach Cut to your Pokémon, and\n"
    .string "you can see it Cut anytime!$"

SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain::
    .string "{PLAYER} obtained HM01\n"
    .string "from the Captain!$"

SSAnne_CaptainsOffice_Text_ExplainCut::
    .string "Using Cut, you can chop down\n"
    .string "small trees.\p"
    .string "Why not try it with the trees\n"
    .string "around Vermilion City?$"

SSAnne_CaptainsOffice_Text_HowToConquerSeasickness::
    .string "How to Conquer Seasickness…\n"
    .string "The Captain's reading this!$"

SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked::
    .string "Yuck!\n"
    .string "Shouldn't have looked!$"


