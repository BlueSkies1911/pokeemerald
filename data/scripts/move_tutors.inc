EventScript_DreamEaterTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_DREAM_EATER, EventScript_DreamEaterTaught
    msgbox MoveTutor_Text_DreamEaterTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_DreamEaterDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_DreamEaterDeclined
    msgbox MoveTutor_Text_DreamEaterWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_DREAM_EATER
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_DreamEaterDeclined
    setflag FLAG_TUTOR_DREAM_EATER
    goto EventScript_DreamEaterTaught
    end

EventScript_DreamEaterDeclined::
    msgbox MoveTutor_Text_DreamEaterDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_DreamEaterTaught::
    msgbox MoveTutor_Text_DreamEaterTaught, MSGBOX_DEFAULT
    release
    end

EventScript_SeismicTossTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_SEISMIC_TOSS, EventScript_SeismicTossTaught
    msgbox MoveTutor_Text_SeismicTossTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_SeismicTossDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_SeismicTossDeclined
    msgbox MoveTutor_Text_SeismicTossWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_SEISMIC_TOSS
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_SeismicTossDeclined
    setflag FLAG_TUTOR_SEISMIC_TOSS
    goto EventScript_SeismicTossTaught
    end

EventScript_SeismicTossDeclined::
    msgbox MoveTutor_Text_SeismicTossDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_SeismicTossTaught::
    msgbox MoveTutor_Text_SeismicTossTaught, MSGBOX_DEFAULT
    release
    end

EventScript_MegaPunchTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_MEGA_PUNCH, EventScript_MegaPunchTaught
    msgbox MoveTutor_Text_MegaPunchTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_MegaPunchDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_MegaPunchDeclined
    msgbox MoveTutor_Text_MegaPunchWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_MEGA_PUNCH
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_MegaPunchDeclined
    setflag FLAG_TUTOR_MEGA_PUNCH
    goto EventScript_MegaPunchTaught
    end

EventScript_MegaPunchDeclined::
    msgbox MoveTutor_Text_MegaPunchDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_MegaPunchTaught::
    msgbox MoveTutor_Text_MegaPunchTaught, MSGBOX_DEFAULT
    release
    end

EventScript_MegaKickTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_MEGA_KICK, EventScript_MegaKickTaught
    msgbox MoveTutor_Text_MegaKickTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_MegaKickDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_MegaKickDeclined
    msgbox MoveTutor_Text_MegaKickWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_MEGA_KICK
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_MegaKickDeclined
    setflag FLAG_TUTOR_MEGA_KICK
    goto EventScript_MegaKickTaught
    end

EventScript_MegaKickDeclined::
    msgbox MoveTutor_Text_MegaKickDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_MegaKickTaught::
    msgbox MoveTutor_Text_MegaKickTaught, MSGBOX_DEFAULT
    release
    end

RockTunnel_B1F_EventScript_RockSlideTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_ROCK_SLIDE, EventScript_RockSlideTaught
    msgbox MoveTutor_Text_RockSlideTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_RockSlideDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_RockSlideDeclined
    msgbox MoveTutor_Text_RockSlideWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_ROCK_SLIDE
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_RockSlideDeclined
    setflag FLAG_TUTOR_ROCK_SLIDE
    goto EventScript_RockSlideTaught
    end

EventScript_RockSlideDeclined::
    msgbox MoveTutor_Text_RockSlideDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_RockSlideTaught::
    msgbox MoveTutor_Text_RockSlideTaught, MSGBOX_DEFAULT
    release
    end

EventScript_CounterTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_COUNTER, EventScript_CounterTaught
    msgbox MoveTutor_Text_CounterTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_CounterDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_CounterDeclined
    msgbox MoveTutor_Text_CounterWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_COUNTER
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_CounterDeclined
    setflag FLAG_TUTOR_COUNTER
    goto EventScript_CounterTaught
    end

EventScript_CounterDeclined::
    msgbox MoveTutor_Text_CounterDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_CounterTaught::
    msgbox MoveTutor_Text_CounterTaught, MSGBOX_DEFAULT
    release
    end

EventScript_SoftboiledTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_SOFT_BOILED, EventScript_SoftboiledTaught
    msgbox MoveTutor_Text_SoftboiledTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_SoftboiledDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_SoftboiledDeclined
    msgbox MoveTutor_Text_SoftboiledWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_SOFT_BOILED
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_SoftboiledDeclined
    setflag FLAG_TUTOR_SOFT_BOILED
    goto EventScript_SoftboiledTaught
    end

EventScript_SoftboiledDeclined::
    msgbox MoveTutor_Text_SoftboiledDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_SoftboiledTaught::
    msgbox MoveTutor_Text_SoftboiledTaught, MSGBOX_DEFAULT
    release
    end

EventScript_MimicTutor::
    goto_if_set FLAG_TUTOR_MIMIC, EventScript_MimicTaught
    msgbox MoveTutor_Text_MimicTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_MimicDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_MimicDeclined
    msgbox MoveTutor_Text_MimicWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_MIMIC
    call MoveTutor_EventScript_OpenPartyMenu
    lock
    faceplayer
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_MimicDeclined
    removeitem ITEM_POKE_DOLL, 1
    setflag FLAG_TUTOR_MIMIC
    goto EventScript_MimicTaught
    end

EventScript_MimicDeclined::
    msgbox MoveTutor_Text_MimicDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_MimicTaught::
    checkplayergender
    compare VAR_RESULT, MALE
    call_if_eq EventScript_MimicTaughtMale
    compare VAR_RESULT, FEMALE
    call_if_eq EventScript_MimicTaughtFemale
    release
    end

EventScript_MimicTaughtMale::
    msgbox MoveTutor_Text_MimicTaughtMale, MSGBOX_DEFAULT
    return

EventScript_MimicTaughtFemale::
    msgbox MoveTutor_Text_MimicTaughtFemale, MSGBOX_DEFAULT
    return

EventScript_ThunderWaveTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_THUNDER_WAVE, EventScript_ThunderWaveTaught
    msgbox MoveTutor_Text_ThunderWaveTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_ThunderWaveDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_ThunderWaveDeclined
    msgbox MoveTutor_Text_ThunderWaveWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_THUNDER_WAVE
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_ThunderWaveDeclined
    setflag FLAG_TUTOR_THUNDER_WAVE
    goto EventScript_ThunderWaveTaught
    end

EventScript_ThunderWaveDeclined::
    msgbox MoveTutor_Text_ThunderWaveDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_ThunderWaveTaught::
    msgbox MoveTutor_Text_ThunderWaveTaught, MSGBOX_DEFAULT
    release
    end

EventScript_SubstituteTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_SUBSTITUTE, EventScript_SubstituteTaught
    msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_SubstituteDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_SubstituteDeclined
    msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_SUBSTITUTE
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_SubstituteDeclined
    setflag FLAG_TUTOR_SUBSTITUTE
    goto EventScript_SubstituteTaught
    end

EventScript_SubstituteDeclined::
    msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_SubstituteTaught::
    msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
    release
    end

EventScript_MetronomeTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_METRONOME, EventScript_MetronomeTaught
    msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_MetronomeDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_MetronomeDeclined
    msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_METRONOME
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_MetronomeDeclined
    setflag FLAG_TUTOR_METRONOME
    goto EventScript_MetronomeTaught
    end

EventScript_MetronomeDeclined::
    msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_MetronomeTaught::
    msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
    release
    end

EventScript_DoubleEdgeTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_DOUBLE_EDGE, EventScript_DoubleEdgeTaught
    msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_DoubleEdgeDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_DoubleEdgeDeclined
    msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_DOUBLE_EDGE
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_DoubleEdgeDeclined
    setflag FLAG_TUTOR_DOUBLE_EDGE
    goto EventScript_DoubleEdgeTaught
    end

EventScript_DoubleEdgeDeclined::
    msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_DoubleEdgeTaught::
    msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
    release
    end

EventScript_ExplosionTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_EXPLOSION, EventScript_ExplosionTaught
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ExplosionDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ExplosionDeclined
	msgbox MoveTutor_Text_ExplosionWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_EXPLOSION
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_ExplosionDeclined
	setflag FLAG_TUTOR_EXPLOSION
	goto EventScript_ExplosionTaught
	end

EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

EventScript_ExplosionTaught::
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

EventScript_BodySlamTutor::
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_BODY_SLAM, EventScript_BodySlamTaught
    msgbox MoveTutor_Text_BodySlamTeach, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_BodySlamDeclined
    call MoveTutor_EventScript_CanOnlyBeLearnedOnce
    compare VAR_RESULT, NO
    goto_if_eq EventScript_BodySlamDeclined
    msgbox MoveTutor_Text_BodySlamWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, MOVE_BODY_SLAM
    call MoveTutor_EventScript_OpenPartyMenu
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_BodySlamDeclined
    setflag FLAG_TUTOR_BODY_SLAM
    goto EventScript_BodySlamTaught
    end

EventScript_BodySlamDeclined::
    msgbox MoveTutor_Text_BodySlamDeclined, MSGBOX_DEFAULT
    release
    end

EventScript_BodySlamTaught::
    msgbox MoveTutor_Text_BodySlamTaught, MSGBOX_DEFAULT
    release
    end

EventScript_SwordsDanceTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_SWORDS_DANCE, EventScript_SwordsDanceTaught
	msgbox MoveTutor_Text_SwordsDanceTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SwordsDanceDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SwordsDanceDeclined
	msgbox MoveTutor_Text_SwordsDanceWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_SwordsDanceDeclined
	setflag FLAG_TUTOR_SWORDS_DANCE
	goto EventScript_SwordsDanceTaught
	end

EventScript_SwordsDanceDeclined::
	msgbox MoveTutor_Text_SwordsDanceDeclined, MSGBOX_DEFAULT
	release
	end

EventScript_SwordsDanceTaught::
	msgbox MoveTutor_Text_SwordsDanceTaught, MSGBOX_DEFAULT
	release
	end

CapeBrink_House_EventScript_StarterTutor::
	lock
	faceplayer
	goto_if_set FLAG_LEARNED_ALL_MOVES_AT_CAPE_BRINK, CapeBrinkTutor_EventScript_TaughtAllMoves
	goto_if_set FLAG_TEMP_2, CapeBrinkTutor_EventScript_MoveJustTaught
	bufferleadmonspeciesname 0
	msgbox MoveTutor_Text_UltimateMoveThatMon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, CapeBrinkGetMoveToTeachLeadPokemon
	compare VAR_RESULT, FALSE
	goto_if_eq CapeBrinkTutor_EventScript_NoLeadStarter
	copyvar VAR_0x8009, VAR_0x8005
	compare VAR_FACING, DIR_NORTH
	call_if_eq CapeBrinkTutor_EventScript_JumpInPlaceDown
	compare VAR_FACING, DIR_SOUTH
	call_if_eq CapeBrinkTutor_EventScript_JumpInPlaceUp
	compare VAR_FACING, DIR_EAST
	call_if_eq CapeBrinkTutor_EventScript_JumpInPlaceLeft
	compare VAR_FACING, DIR_WEST
	call_if_eq CapeBrinkTutor_EventScript_JumpInPlaceRight
	msgbox MoveTutor_Text_AllowMeToTeachMonUltimateMove, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CapeBrinkTutor_EventScript_DeclineMove
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq CapeBrinkTutor_EventScript_DeclineMove
	msgbox MoveTutor_Text_LetMeConferUltimateMove, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	goto CapeBrinkTutor_EventScript_ChooseMon

CapeBrinkTutor_EventScript_MoveJustTaught::
	msgbox MoveTutor_Text_MakeBestUseOfMove, MSGBOX_DEFAULT
	release
	end

CapeBrinkTutor_EventScript_TaughtAllMoves::
	msgbox MoveTutor_Text_FeelRejuvenated, MSGBOX_DEFAULT
	release
	end

CapeBrinkTutor_EventScript_TaughtMove::
	copyvar VAR_0x8005, VAR_0x8009
	specialvar VAR_RESULT, HasLearnedAllMovesFromCapeBrinkTutor
	compare VAR_RESULT, TRUE
	goto_if_eq CapeBrinkTutor_EventScript_LearnedAllMoves
	msgbox MoveTutor_Text_TaughtMove, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

CapeBrinkTutor_EventScript_LearnedAllMoves::
	msgbox MoveTutor_Text_PassedOnEverythingIKnow, MSGBOX_DEFAULT
	setflag FLAG_LEARNED_ALL_MOVES_AT_CAPE_BRINK
	release
	end

CapeBrinkTutor_EventScript_ChooseMon::
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, FALSE
	goto_if_eq CapeBrinkTutor_EventScript_DeclineMove
	goto CapeBrinkTutor_EventScript_TaughtMove
	end

CapeBrinkTutor_EventScript_JumpInPlaceDown::
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceDown
	waitmovement 0
	return

CapeBrinkTutor_EventScript_JumpInPlaceUp::
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceUp
	waitmovement 0
	return

CapeBrinkTutor_EventScript_JumpInPlaceLeft::
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceLeft
	waitmovement 0
	return

CapeBrinkTutor_EventScript_JumpInPlaceRight::
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceRight
	waitmovement 0
	return

CapeBrinkTutor_EventScript_DeclineMove::
	msgbox MoveTutor_Text_YouRejectIt, MSGBOX_DEFAULT
	release
	end

CapeBrinkTutor_EventScript_NoLeadStarter::
	msgbox MoveTutor_Text_JustMistaken, MSGBOX_DEFAULT
	release
	end

Movement_JumpInPlaceDown:
	jump_in_place_down
	step_end

Movement_JumpInPlaceUp:
	jump_in_place_up
	step_end

Movement_JumpInPlaceLeft:
	jump_in_place_left
	step_end

Movement_JumpInPlaceRight:
	jump_in_place_right
	step_end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_CanOnlyBeLearnedOnce::
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	return
