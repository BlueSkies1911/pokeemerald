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

CeruleanCity_House4_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox CeruleanCity_House4_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_House4_Movement_PlayerPushFromTV
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, CeruleanCity_House4_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, CeruleanCity_House4_Movement_OwnerReturn
	waitmovement 0
	release
	end

CeruleanCity_House4_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

CeruleanCity_House4_Movement_OwnerPushPlayer:
	walk_up
	step_end

CeruleanCity_House4_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

CeruleanCity_House4_Text_NothingEntertaining::
    .string "Sigh…\n"
    .string "Too much time, too little to do…\p"
    .string "Is nothing entertaining happening\n"
    .string "anywhere?$"

CeruleanCity_House4_Text_CantSeeTheTV:
	.string "Hey, down in front!\n"
	.string "I can't see the TV!$"
