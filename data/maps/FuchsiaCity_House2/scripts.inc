FuchsiaCity_House2_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_FishingGurusBrother::
    lock
    faceplayer
    goto_if_set FLAG_GOT_GOOD_ROD, FuchsiaCity_House2_EventScript_AlreadyGotGoodRod
    msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq FuchsiaCity_House2_EventScript_GiveGoodRod
    msgbox FuchsiaCity_House2_Text_OhThatsDisappointing, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_House2_EventScript_AlreadyGotGoodRod::
    msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_House2_EventScript_GiveGoodRod::
    msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis, MSGBOX_DEFAULT
    checkitemspace ITEM_GOOD_ROD, 1
    compare VAR_RESULT, FALSE
    goto_if_eq FuchsiaCity_House2_EventScript_NoRoomForGoodRod
    giveitem_msg FuchsiaCity_House2_Text_ReceivedGoodRod, ITEM_GOOD_ROD
    msgbox FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons, MSGBOX_DEFAULT
    setflag FLAG_GOT_GOOD_ROD
    release
    end

FuchsiaCity_House2_EventScript_NoRoomForGoodRod::
    msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_House2_Text_DoYouLikeToFish::
    .string "I'm the Fishing Guru's older\n"
    .string "brother.\p"
    .string "I simply looove fishing!\n"
    .string "I can't bear to go without.\p"
    .string "Tell me, do you like to fish?$"

FuchsiaCity_House2_Text_LikeYourStyleTakeThis::
    .string "Grand! I like your style.\n"
    .string "I think we can be friends.\p"
    .string "Take this and fish, young friend!$"

FuchsiaCity_House2_Text_ReceivedGoodRod::
    .string "{PLAYER} received a Good Rod from\n"
    .string "the Fishing Guru's brother.$"

FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons::
    .string "Fishing is a way of life!\n"
    .string "It is like the finest poetry.\p"
    .string "A crummy Old Rod could only catch\n"
    .string "Magikarp, yes?\p"
    .string "But with a Good Rod, you can\n"
    .string "catch much better Pokémon.$"

FuchsiaCity_House2_Text_OhThatsDisappointing::
    .string "Oh…\n"
    .string "That's so disappointing…$"

FuchsiaCity_House2_Text_HowAreTheFishBiting::
    .string "Hello there, {PLAYER}!\p"
    .string "How are the fish biting?$"

FuchsiaCity_House2_Text_YouHaveNoRoomForGift::
    .string "Oh, no!\p"
    .string "I had a gift for you, but you have\n"
    .string "no room for it!$"
