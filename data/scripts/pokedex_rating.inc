PokedexRating_EventScript_RateInPerson::
	call_if_set FLAG_OAK_SAW_DEX_COMPLETION, PokedexRating_EventScript_DexCompleteIntro
	call_if_unset FLAG_OAK_SAW_DEX_COMPLETION, PokedexRating_EventScript_NormalIntro
	call PokedexRating_EventScript_Rate
	return

PokedexRating_EventScript_DexCompleteIntro::
	msgbox gPokedexRating_Text_LoveSeeingYourPokedex
	return

PokedexRating_EventScript_NormalIntro::
	msgbox gPokedexRating_Text_HowIsPokedexComingAlong
	return

PokedexRating_EventScript_ShowRatingMsg::
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	call_if_eq VAR_RESULT, FALSE, PokedexRating_EventScript_NormalFanfare
	call_if_eq VAR_RESULT, TRUE, PokedexRating_EventScript_DexCompleteFanfare
	waitfanfare
	waitbuttonpress
	return

PokedexRating_EventScript_NormalFanfare::
	playfanfare MUS_RG_DEX_RATING
	return

PokedexRating_EventScript_DexCompleteFanfare::
	playfanfare MUS_EVOLVED
	return

PokedexRating_EventScript_Rate::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008 @ Num Kanto Seen
	buffernumberstring STR_VAR_2, VAR_0x8009 @ Num Kanto Caught
	msgbox gPokedexRating_Text_SeenXOwnedY
	call PokedexRating_EventScript_ShowRatingMsg
	goto_if_eq VAR_0x800A, FALSE, Common_EventScript_NopReturn  @ National Dex not enabled
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring STR_VAR_1, VAR_0x8008 @ Num National Seen
	buffernumberstring STR_VAR_2, VAR_0x8009 @ Num National Caught
	msgbox gPokedexRating_Text_NationalDexSeenXOwnedY
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, FALSE, PokedexRating_EventScript_DexIncomplete
	goto_if_eq VAR_RESULT, TRUE, PokedexRating_EventScript_DexComplete
	end

PokedexRating_EventScript_DexIncomplete::
	msgbox gPokedexRating_Text_LookForwardToFilledNationalDex
    closemessage
	end

PokedexRating_EventScript_DexComplete::
	call_if_unset FLAG_OAK_SAW_DEX_COMPLETION, PokedexRating_EventScript_OldSeaMapStepCounter
	setflag FLAG_OAK_SAW_DEX_COMPLETION
	msgbox gPokedexRating_Text_YouveCompletedDex
    closemessage
	end

PokedexRating_EventScript_OldSeaMapStepCounter::
	setflag FLAG_ENABLE_OLD_SEA_MAP_CALL
	setvar VAR_OLD_SEA_MAP_CALL_STEP_COUNTER, 0
	return
