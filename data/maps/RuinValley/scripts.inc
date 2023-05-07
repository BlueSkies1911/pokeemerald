.set LOCALID_SCIENTIST, 1

RuinValley_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, RuinValley_OnLoad
    .byte 0

RuinValley_OnLoad:
    call_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, RuinValley_EventScript_OpenDottedHoleDoor
    end

RuinValley_EventScript_OpenDottedHoleDoor::
    setmetatile 24, 24, METATILE_SeviiIslands67_DottedHoleDoor_Open, 0
    return

RuinValley_EventScript_Scientist::
    lock
    msgbox RuinValley_Text_CantFigureOutHowToGetInside, MSGBOX_DEFAULT
    applymovement LOCALID_SCIENTIST, Common_Movement_FacePlayer
    waitmovement 0
    msgbox RuinValley_Text_IFoundThisPlace, MSGBOX_DEFAULT
    applymovement LOCALID_SCIENTIST, Common_Movement_FaceOriginalDirection, MSGBOX_DEFAULT
    waitmovement 0
    release
    end

RuinValley_EventScript_DottedHoleDoor::
    lockall
    goto_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, RuinValley_EventScript_DottedHoleDoorOpen
    msgbox RuinValley_Text_CheckDoorMoreThoroughly, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq RuinValley_EventScript_IgnoreDottedHoleDoor
    msgbox RuinValley_Text_SeveralDotsOnTheDoor, MSGBOX_DEFAULT
    braillemsgbox Braille_Text_Cut
    releaseall
    end

RuinValley_EventScript_DottedHoleDoorOpen::
    msgbox RuinValley_Text_DoorIsOpen, MSGBOX_DEFAULT
    releaseall
    end

RuinValley_EventScript_IgnoreDottedHoleDoor::
    msgbox RuinValley_Text_LeftDoorAlone, MSGBOX_DEFAULT
    releaseall
    end

RuinValley_EventScript_Stanly::
    trainerbattle_single TRAINER_RUIN_MANIAC_STANLY, RuinValley_Text_StanlyIntro, RuinValley_Text_StanlyDefeat
    msgbox RuinValley_Text_StanlyPostBattle, MSGBOX_AUTOCLOSE
    end

RuinValley_EventScript_Foster::
    trainerbattle_single TRAINER_RUIN_MANIAC_FOSTER, RuinValley_Text_FosterIntro, RuinValley_Text_FosterDefeat
    msgbox RuinValley_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
    end

RuinValley_EventScript_Larry::
    trainerbattle_single TRAINER_RUIN_MANIAC_LARRY, RuinValley_Text_LarryIntro, RuinValley_Text_LarryDefeat, RuinValley_EventScript_RegisterLarry
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq RuinValley_EventScript_LarryRematch
    msgbox RuinValley_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
    end

RuinValley_EventScript_RegisterLarry::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox RuinValley_Text_LarryRegister, MSGBOX_DEFAULT
    register_matchcall TRAINER_RUIN_MANIAC_LARRY
    release
    end

RuinValley_EventScript_LarryRematch::
    trainerbattle_rematch TRAINER_RUIN_MANIAC_LARRY, RuinValley_Text_LarryRematchIntro, RuinValley_Text_LarryDefeat
    msgbox RuinValley_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
    end

RuinValley_EventScript_Daryl::
    trainerbattle_single TRAINER_HIKER_DARYL, RuinValley_Text_DarylIntro, RuinValley_Text_DarylDefeat
    msgbox RuinValley_Text_DarylPostBattle, MSGBOX_AUTOCLOSE
    end

RuinValley_EventScript_Hector::
    trainerbattle_single TRAINER_POKEMANIAC_HECTOR, RuinValley_Text_HectorIntro, RuinValley_Text_HectorDefeat, RuinValley_EventScript_RegisterHector
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq RuinValley_EventScript_HectorRematch
    msgbox RuinValley_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
    end

RuinValley_EventScript_RegisterHector::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox RuinValley_Text_HectorRegister, MSGBOX_DEFAULT
    register_matchcall TRAINER_POKEMANIAC_HECTOR
    release
    end

RuinValley_EventScript_HectorRematch::
    trainerbattle_rematch TRAINER_POKEMANIAC_HECTOR, RuinValley_Text_HectorRematchIntro, RuinValley_Text_HectorDefeat
    msgbox RuinValley_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
    end

RuinValley_Text_CantFigureOutHowToGetInside::
    .string "I can't figure out how I'm supposed\n"
    .string "to get inside.$"

RuinValley_Text_IFoundThisPlace::
    .string "Let me tell you, I found this\n"
    .string "place.\p"
    .string "Don't look so envious, will you?$"

RuinValley_Text_CheckDoorMoreThoroughly::
    .string "The door doesn't budge at all.\n"
    .string "Check it more thoroughly?$"

RuinValley_Text_LeftDoorAlone::
    .string "{PLAYER} left the door alone.$"

RuinValley_Text_SeveralDotsOnTheDoor::
    .string "On closer inspection, there are\n"
    .string "several dots on the door…$"

RuinValley_Text_DoorIsOpen::
    .string "The door is open.$"
