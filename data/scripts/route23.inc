Route23_EventScript_MissingBoulderBadge::
	msgbox Text_OnlySkilledTrainersAllowedThrough, MSGBOX_DEFAULT
	playse SE_BOO
	msgbox Text_CantLetYouPass, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_MissingBadge::
	message Text_OnlyPassWithBadgeDontHaveYet
	waitmessage
	playse SE_BOO
	waitbuttonpress
	closemessage
	waitse
	release
	end

Route23_EventScript_AlreadyRecognizedBoulderBadge::
	message Text_OhThatsBadgeGoRightAhead
	waitmessage
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	release
	end

Route23_EventScript_AlreadyRecognizedBadge::
	message Text_OnlyPassWithBadgeOhGoAhead
    waitmessage
    playfanfare MUS_LEVEL_UP
    waitfanfare
    waitbuttonpress
    release
	end

Route22_NorthEntrance_EventScript_BadgeGuard::
	compare VAR_MAP_SCENE_ROUTE23, VAR_TEMP_1
	goto_if_ge Route23_EventScript_AlreadyRecognizedBoulderBadge
	switch VAR_TEMP_1
	case 1, Route23_EventScript_CheckBoulderBadge
	case 2, Route23_EventScript_CheckCascadeBadge
	case 3, Route23_EventScript_CheckThunderBadge
	case 4, Route23_EventScript_CheckRainbowBadge
	case 5, Route23_EventScript_CheckSoulBadge
	case 6, Route23_EventScript_CheckMarshBadge
	case 7, Route23_EventScript_CheckVolcanoBadge
	case 8, Route23_EventScript_CheckEarthBadge
	end

Route23_EventScript_BadgeGuard::
	compare VAR_MAP_SCENE_ROUTE23, VAR_TEMP_1
	goto_if_ge Route23_EventScript_AlreadyRecognizedBadge
	switch VAR_TEMP_1
	case 1, Route23_EventScript_CheckBoulderBadge
	case 2, Route23_EventScript_CheckCascadeBadge
	case 3, Route23_EventScript_CheckThunderBadge
	case 4, Route23_EventScript_CheckRainbowBadge
	case 5, Route23_EventScript_CheckSoulBadge
	case 6, Route23_EventScript_CheckMarshBadge
	case 7, Route23_EventScript_CheckVolcanoBadge
	case 8, Route23_EventScript_CheckEarthBadge
	end

Route23_EventScript_CheckBoulderBadge::
	goto_if_set FLAG_BADGE01_GET, Route23_EventScript_RecognizeBoulderBadge
	goto Route23_EventScript_MissingBoulderBadge
	end

Route23_EventScript_CheckCascadeBadge::
	goto_if_set FLAG_BADGE02_GET, Route23_EventScript_RecognizeBadge
	goto Route23_EventScript_MissingBadge
	end

Route23_EventScript_CheckThunderBadge::
	goto_if_set FLAG_BADGE03_GET, Route23_EventScript_RecognizeBadge
	goto Route23_EventScript_MissingBadge
	end

Route23_EventScript_CheckRainbowBadge::
	goto_if_set FLAG_BADGE04_GET, Route23_EventScript_RecognizeBadge
	goto Route23_EventScript_MissingBadge
	end

Route23_EventScript_CheckSoulBadge::
	goto_if_set FLAG_BADGE05_GET, Route23_EventScript_RecognizeBadge
	goto Route23_EventScript_MissingBadge
	end

Route23_EventScript_CheckMarshBadge::
	goto_if_set FLAG_BADGE06_GET, Route23_EventScript_RecognizeBadge
	goto Route23_EventScript_MissingBadge
	end

Route23_EventScript_CheckVolcanoBadge::
	goto_if_set FLAG_BADGE07_GET, Route23_EventScript_RecognizeBadge
	goto Route23_EventScript_MissingBadge
	end

Route23_EventScript_CheckEarthBadge::
	goto_if_set FLAG_BADGE08_GET, Route23_EventScript_RecognizeBadge
	goto Route23_EventScript_MissingBadge
	end

Route23_EventScript_RecognizeBoulderBadge::
	message Text_OhThatsBadgeGoRightAhead
	waitmessage
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	copyvar VAR_MAP_SCENE_ROUTE23, VAR_TEMP_1
	release
	end

Route23_EventScript_RecognizeBadge::
	message Text_OnlyPassWithBadgeOhGoAhead
    waitmessage
    playfanfare MUS_LEVEL_UP
    waitfanfare
    waitbuttonpress
	copyvar VAR_MAP_SCENE_ROUTE23, VAR_TEMP_1
	release
	end

Route23_EventScript_BadgeGuardTrigger::
	applymovement VAR_0x8009, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	switch VAR_TEMP_1
	case 1, Route23_EventScript_CheckBoulderBadgeTrigger
	case 2, Route23_EventScript_CheckCascadeBadgeTrigger
	case 3, Route23_EventScript_CheckThunderBadgeTrigger
	case 4, Route23_EventScript_CheckRainbowBadgeTrigger
	case 5, Route23_EventScript_CheckSoulBadgeTrigger
	case 6, Route23_EventScript_CheckMarshBadgeTrigger
	case 7, Route23_EventScript_CheckVolcanoBadgeTrigger
	case 8, Route23_EventScript_CheckEarthBadgeTrigger
	end

Route23_EventScript_CheckBoulderBadgeTrigger::
	goto_if_set FLAG_BADGE01_GET, Route23_EventScript_RecognizeBoulderBadgeTrigger
	goto Route23_EventScript_MissingBoulderBadgeTrigger
	end

Route23_EventScript_CheckCascadeBadgeTrigger::
	goto_if_set FLAG_BADGE02_GET, Route23_EventScript_RecognizeBadgeTrigger
	goto Route23_EventScript_MissingBadgeTrigger
	end

Route23_EventScript_CheckThunderBadgeTrigger::
	goto_if_set FLAG_BADGE03_GET, Route23_EventScript_RecognizeBadgeTrigger
	goto Route23_EventScript_MissingBadgeTrigger
	end

Route23_EventScript_CheckRainbowBadgeTrigger::
	goto_if_set FLAG_BADGE04_GET, Route23_EventScript_RecognizeBadgeTrigger
	goto Route23_EventScript_MissingBadgeTrigger
	end

Route23_EventScript_CheckSoulBadgeTrigger::
	goto_if_set FLAG_BADGE05_GET, Route23_EventScript_RecognizeBadgeTrigger
	goto Route23_EventScript_MissingBadgeTrigger
	end

Route23_EventScript_CheckMarshBadgeTrigger::
	goto_if_set FLAG_BADGE06_GET, Route23_EventScript_RecognizeBadgeTrigger
	goto Route23_EventScript_MissingBadgeTrigger
	end

Route23_EventScript_CheckVolcanoBadgeTrigger::
	goto_if_set FLAG_BADGE07_GET, Route23_EventScript_RecognizeBadgeTrigger
	goto Route23_EventScript_MissingBadgeTrigger
	end

Route23_EventScript_CheckEarthBadgeTrigger::
	goto_if_set FLAG_BADGE08_GET, Route23_EventScript_RecognizeBadgeTrigger
	goto Route23_EventScript_MissingBadgeTrigger
	end

Route23_EventScript_MissingBoulderBadgeTrigger::
	msgbox Text_OnlySkilledTrainersAllowedThrough, MSGBOX_DEFAULT
	playse SE_BOO
	msgbox Text_CantLetYouPass, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route23_Movement_WalkDown
	applymovement VAR_0x8009, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

Route23_EventScript_MissingBadgeTrigger::
	message Text_OnlyPassWithBadgeDontHaveYet
	waitmessage
	playse SE_BOO
	waitbuttonpress
	closemessage
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Route23_Movement_WalkDown
	applymovement VAR_0x8009, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

Route23_EventScript_RecognizeBoulderBadgeTrigger::
	message Text_OhThatsBadgeGoRightAhead
	waitmessage
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	copyvar VAR_MAP_SCENE_ROUTE23, VAR_TEMP_1
	releaseall
	end

Route23_EventScript_RecognizeBadgeTrigger::
	message Text_OnlyPassWithBadgeOhGoAhead
    waitmessage
    playfanfare MUS_LEVEL_UP
    waitfanfare
    waitbuttonpress
	copyvar VAR_MAP_SCENE_ROUTE23, VAR_TEMP_1
	releaseall
	end

Route23_Movement_WalkDown::
	walk_down
	step_end
