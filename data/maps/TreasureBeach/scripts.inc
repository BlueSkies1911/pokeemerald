TreasureBeach_MapScripts::
	.byte 0

TreasureBeach_EventScript_Amara::
    trainerbattle_single TRAINER_SWIMMER_FEMALE_AMARA, TreasureBeach_Text_AmaraIntro, TreasureBeach_Text_AmaraDefeat
    msgbox TreasureBeach_Text_AmaraPostBattle, MSGBOX_AUTOCLOSE
    end

TreasureBeach_EventScript_Boy::
    msgbox TreasureBeach_Text_GoodThingsWashUpOnBeach, MSGBOX_NPC
    end

TreasureBeach_Text_GoodThingsWashUpOnBeach::
    .string "Good things get washed up by the\n"
    .string "ocean current onto this beach.\p"
    .string "That's why I often come here for\n"
    .string "some beachcombing.$"
