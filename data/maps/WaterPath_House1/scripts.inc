WaterPath_House1_MapScripts::
	.byte 0

WaterPath_House1_EventScript_Beauty::
    lock
    faceplayer
    setvar VAR_0x8004, SPECIES_HERACROSS
    specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
    compare VAR_RESULT, FALSE
    goto_if_eq WaterPath_House1_EventScript_NoHeracrossInParty
    special GetHeracrossSizeRecordInfo
    msgbox WaterPath_House1_Text_MayIMeasureHeracross, MSGBOX_DEFAULT
    special ChoosePartyMon
    waitstate
    copyvar VAR_RESULT, VAR_0x8004
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge WaterPath_House1_EventScript_DontShowMon
    special CompareHeracrossSize
    compare VAR_RESULT, 1
    goto_if_eq WaterPath_House1_EventScript_ShownNonHeracross
    compare VAR_RESULT, 2
    goto_if_eq WaterPath_House1_EventScript_ShownSmallHeracross
    compare VAR_RESULT, 3
    goto_if_eq WaterPath_House1_EventScript_ShownBigHeracross
    compare VAR_RESULT, 4
    goto_if_eq WaterPath_House1_EventScript_ShownTiedHeracross
    release
    end

WaterPath_House1_EventScript_NoHeracrossInParty::
    msgbox WaterPath_House1_Text_LoveItNeedItHeracross, MSGBOX_DEFAULT
    release
    end

WaterPath_House1_EventScript_DontShowMon::
    release
    end

WaterPath_House1_EventScript_ShownNonHeracross::
    msgbox WaterPath_House1_Text_ThisWontDo, MSGBOX_DEFAULT
    release
    end

WaterPath_House1_EventScript_ShownSmallHeracross::
    goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, WaterPath_House1_EventScript_ShownBigHeracross
    msgbox WaterPath_House1_Text_ItsXInchesYInchesWasBiggest, MSGBOX_DEFAULT
    release
    end

WaterPath_House1_EventScript_ShownTiedHeracross::
    goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, WaterPath_House1_EventScript_ShownBigHeracross
    msgbox WaterPath_House1_Text_ItsXInchesSameAsBefore, MSGBOX_DEFAULT
    release
    end

WaterPath_House1_EventScript_ShownBigHeracross::
    setflag FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1
    msgbox WaterPath_House1_Text_ItsXInchesDeserveReward, MSGBOX_DEFAULT
    giveitem ITEM_NEST_BALL
    compare VAR_RESULT, FALSE
    goto_if_eq WaterPath_House1_EventScript_NoRoomForNestBall
    msgbox WaterPath_House1_Text_WantToSeeBiggerOne, MSGBOX_DEFAULT
    release
    end

WaterPath_House1_EventScript_NoRoomForNestBall::
    msgbox WaterPath_House1_Text_YourBagIsFull, MSGBOX_DEFAULT
    release
    end

WaterPath_House1_EventScript_SizeRecord::
    lockall
    goto_if_set FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, WaterPath_House1_EventScript_SizeRecordNonEmpty
    msgbox WaterPath_House1_Text_BlankChartOfSomeSort, MSGBOX_DEFAULT
    releaseall
    end

WaterPath_House1_EventScript_SizeRecordNonEmpty::
    special GetHeracrossSizeRecordInfo
    msgbox WaterPath_House1_Text_BiggestHeracrossIsXInches, MSGBOX_DEFAULT
    releaseall
    end

WaterPath_House1_Text_LoveItNeedItHeracross::
    .string "Hera, hera, Heracross!\n"
    .string "Big and shiny, it's the bug boss!\l"
    .string "Love it, need it, Heracross!$"

WaterPath_House1_Text_MayIMeasureHeracross::
    .string "Eeeeek!\n"
    .string "That's a Heracross!\p"
    .string "Please, please, may I measure how\n"
    .string "big it is?$"

WaterPath_House1_Text_ItsXInchesDeserveReward::
    .string "Eeeek, it's {STR_VAR_2} inches!\n"
    .string "I've never seen anything like this!\l"
    .string "You deserve a reward!$"

WaterPath_House1_Text_WantToSeeBiggerOne::
    .string "I want to see a much, much bigger\n"
    .string "Heracross than that one.\p"
    .string "Oh, how I adore them, big\n"
    .string "Heracross!$"

WaterPath_House1_Text_ItsXInchesSameAsBefore::
    .string "Huh? This {STR_VAR_2}-inch measurement…\n"
    .string "Oh, boo! It's the same as before.$"

WaterPath_House1_Text_ItsXInchesYInchesWasBiggest::
    .string "Oh, it's just {STR_VAR_2} inches.\n"
    .string "The Heracross before was bigger.\p"
    .string "It was {STR_VAR_3} inches, the biggest\n"
    .string "Heracross you've brought me.$"

WaterPath_House1_Text_ThisWontDo::
    .string "Oh, no! This won't do!\p"
    .string "Heracross looks much more macho\n"
    .string "and cool, and has a lovely horn!$"

WaterPath_House1_Text_YourBagIsFull::
    .string "Your bag is full.\n"
    .string "My reward won't fit.$"

WaterPath_House1_Text_BiggestHeracrossIsXInches::
    .string "The biggest Heracross that I have\n"
    .string "ever seen measured so far is:\p"
    .string "{STR_VAR_3} inches!$"

WaterPath_House1_Text_BlankChartOfSomeSort::
    .string "It's a blank chart of some sort.\p"
    .string "It has spaces for writing in\n"
    .string "records of some kind.$"
