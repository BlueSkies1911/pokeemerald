TrainerTower_Roof_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_OnFrame
    map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_Roof_OnTransition
    .byte 0

TrainerTower_Roof_OnTransition:
	randomweather
    end

TrainerTower_Roof_EventScript_Owner::
	trainertower_settrainerflags
	lock
	faceplayer
	trainertower_getownerstate
	switch VAR_RESULT
	case 0, TrainerTower_Roof_EventScript_Arrived
	case 1, TrainerTower_Roof_EventScript_GivePrize
	case 2, TrainerTower_Roof_EventScript_AlreadyReceivedPrize
TrainerTower_Roof_EventScript_Arrived::
	msgbox TrainerTower_Roof_Text_YouFinallyCameBravo, MSGBOX_DEFAULT
TrainerTower_Roof_EventScript_GivePrize::
	trainertower_giveprize
	switch VAR_RESULT
	case 0, TrainerTower_Roof_EventScript_ReceivePrize
	case 1, TrainerTower_Roof_EventScript_NoRoomForPrize
	case 2, TrainerTower_Roof_EventScript_CheckFinalTime
TrainerTower_Roof_EventScript_ReceivePrize::
	msgbox TrainerTower_Roof_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitfanfare
	waitmessage
	goto TrainerTower_Roof_EventScript_CheckFinalTime

TrainerTower_Roof_EventScript_NoRoomForPrize::
	msgbox TrainerTower_Roof_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	msgbox TrainerTower_Roof_Text_FullUpBeBackLaterForThis, MSGBOX_DEFAULT
	goto TrainerTower_Roof_EventScript_CheckFinalTime

TrainerTower_Roof_EventScript_CheckFinalTime::
	trainertower_finaltime
	switch VAR_RESULT
	case 0, TrainerTower_Roof_EventScript_NewRecord
	case 1, TrainerTower_Roof_EventScript_NoNewRecord
	case 2, TrainerTower_Roof_EventScript_EndSpeakToOwner
TrainerTower_Roof_EventScript_NewRecord::
	msgbox TrainerTower_Roof_Text_GotHereMarvelouslyQuickly, MSGBOX_DEFAULT
	goto TrainerTower_Roof_EventScript_EndSpeakToOwner
	end

TrainerTower_Roof_EventScript_NoNewRecord::
	msgbox TrainerTower_Roof_Text_YouWerentVeryQuick, MSGBOX_DEFAULT
	goto TrainerTower_Roof_EventScript_EndSpeakToOwner
	end

TrainerTower_Roof_EventScript_EndSpeakToOwner::
	msgbox TrainerTower_Roof_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerTower_Roof_EventScript_AlreadyReceivedPrize::
	msgbox TrainerTower_Roof_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerTower_Roof_Text_YouFinallyCameBravo:
	.string "Hm! Hm!\p"
	.string "You finally came!\n"
	.string "Yes, you have arrived!\p"
	.string "Wait! Don't say it!\n"
	.string "I know why you came all the way\l"
	.string "here by yourself!\p"
	.string "You wanted to see me, the owner\n"
	.string "of the Trainer Tower, because…\p"
	.string "You want to form a tag team with me!\n"
	.string "Wa-hoo!\p"
	.string "…Uh?\n"
	.string "That's not it?\p"
	.string "Anyway, I watched you on your way up.\n"
	.string "Marvelous battling! Bravo, indeed!$"

TrainerTower_Roof_Text_HaveTheMostMarvelousGift:
	.string "For a marvelous someone like you,\n"
	.string "I have the most marvelous gift!$"

TrainerTower_Roof_Text_FullUpBeBackLaterForThis:
	.string "Oh, no, full up with things!\n"
	.string "You'll be back later for this!$"

TrainerTower_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh, hold on here! Did you possibly get\n"
	.string "here marvelously quickly?\p"
	.string "How splendid! You needn't have\n"
	.string "hurried so to see me!\p"
	.string "That is so delightful. I'll have the Time\n"
	.string "Board at the reception updated!$"

TrainerTower_Roof_Text_YouWerentVeryQuick:
	.string "But, oh…\n"
	.string "You weren't very quick getting here.$"

TrainerTower_Roof_Text_ArriveZippierNextTime:
	.string "Perhaps it would please me more if you\n"
	.string "arrived zippier next time.\p"
	.string "Then, I should be pleased to form\n"
	.string "a tag team with you!\p"
	.string "Until we meet again, amigo!$"
