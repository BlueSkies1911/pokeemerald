.set LOCALID_WONDER_NEWS_BERRY_MAN, 1

CeruleanCity_House4_MapScripts::
	.byte 0

CeruleanCity_House4_EventScript_WonderNewsBerryMan::
    lock
    goto CeruleanCity_House4_EventScript_NoNews
    end

CeruleanCity_House4_EventScript_NoNews::
    msgbox CeruleanCity_House4_Text_NothingEntertaining, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House4_Text_NothingEntertaining::
    .string "Sigh…\n"
    .string "Too much time, too little to do…\p"
    .string "Is nothing entertaining happening\n"
    .string "anywhere?$"
