.set LOCALID_MEMORIAL_MAN, 1

MemorialPillar_MapScripts::
    .byte 0

MemorialPillar_EventScript_MemorialMan::
    lock
    goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, MemorialPillar_EventScript_AlreadyGotTM42
    goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, MemorialPillar_EventScript_ReturnedForTM42
    msgbox MemorialPillar_Text_ScrubScrub, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_MEMORIAL_MAN, Common_Movement_FacePlayer
    waitmovement 0
    delay 45
    msgbox MemorialPillar_Text_YourMonsLookHealthy, MSGBOX_DEFAULT
    applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox MemorialPillar_Text_ThisIsWhereIBuriedMyOnix, MSGBOX_DEFAULT
    release
    end

MemorialPillar_EventScript_AlreadyGotTM42::
    msgbox MemorialPillar_Text_ScrubScrubTectonix, MSGBOX_DEFAULT
    release
    end

MemorialPillar_EventScript_ReturnedForTM42::
    msgbox MemorialPillar_Text_StillHaveThingAsMyThanks, MSGBOX_DEFAULT
    giveitem ITEM_TM42
    compare VAR_RESULT, FALSE
    goto_if_eq MemorialPillar_EventScript_NoRoomForTM42
    call MemorialPillar_EventScript_ReceivedTM42
    release
    end

MemorialPillar_EventScript_Memorial::
    lockall
    goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
    goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
    msgbox MemorialPillar_Text_HereLiesTectonixLemonadeOffering, MSGBOX_DEFAULT
    checkitem ITEM_LEMONADE, 1
    compare VAR_RESULT, TRUE
    goto_if_eq MemorialPillar_EventScript_AskPlaceLemonade
    releaseall
    end

MemorialPillar_EventScript_AskPlaceLemonade::
    msgbox MemorialPillar_Text_LeaveAnotherLemonadeOffering, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq MemorialPillar_EventScript_PlaceLemonade
    releaseall
    end

MemorialPillar_EventScript_PlaceLemonade::
    removeitem ITEM_LEMONADE, 1
    msgbox MemorialPillar_Text_PlacedCanOfLemonade, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    delay 45
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    msgbox MemorialPillar_Text_ThankYouPleaseTakeThis, MSGBOX_DEFAULT
    giveitem ITEM_TM42
    compare VAR_RESULT, FALSE
    goto_if_eq MemorialPillar_EventScript_NoRoomForTM42
    call MemorialPillar_EventScript_ReceivedTM42
    releaseall
    end

MemorialPillar_EventScript_ReceivedTM42::
    msgbox MemorialPillar_Text_BeGoodToYourMonsToo
    applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    setflag FLAG_GOT_TM42_AT_MEMORIAL_PILLAR
    return

MemorialPillar_EventScript_NoRoomForTM42::
    setflag FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR
    msgbox MemorialPillar_Text_DontHaveRoomForIt, MSGBOX_DEFAULT
    releaseall
    end

MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced::
    msgbox MemorialPillar_Text_HereLiesTectonix, MSGBOX_DEFAULT
    releaseall
    end

MemorialPillar_EventScript_Milo::
    trainerbattle_single TRAINER_BIRD_KEEPER_MILO, MemorialPillar_Text_MiloIntro, MemorialPillar_Text_MiloDefeat, MemorialPillar_EventScript_RegisterMilo
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq MemorialPillar_EventScript_MiloRematch
    msgbox MemorialPillar_Text_MiloPostBattle, MSGBOX_AUTOCLOSE
    end

MemorialPillar_EventScript_RegisterMilo::
	msgbox MemorialPillar_Text_MiloRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIRD_KEEPER_MILO
	release
	end

MemorialPillar_EventScript_MiloRematch::
    trainerbattle_rematch TRAINER_BIRD_KEEPER_MILO, MemorialPillar_Text_MiloRematchIntro, MemorialPillar_Text_MiloDefeat
    msgbox MemorialPillar_Text_MiloPostBattle, MSGBOX_AUTOCLOSE
    end

MemorialPillar_EventScript_Chaz::
    trainerbattle_single TRAINER_BIRD_KEEPER_CHAZ, MemorialPillar_Text_ChazIntro, MemorialPillar_Text_ChazDefeat, MemorialPillar_EventScript_RegisterChaz
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq MemorialPillar_EventScript_ChazRematch
    msgbox MemorialPillar_Text_ChazPostBattle, MSGBOX_AUTOCLOSE
    end

MemorialPillar_EventScript_RegisterChaz::
	msgbox MemorialPillar_Text_ChazRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BIRD_KEEPER_CHAZ
	release
	end

MemorialPillar_EventScript_ChazRematch::
    trainerbattle_rematch TRAINER_BIRD_KEEPER_CHAZ, MemorialPillar_Text_ChazRematchIntro, MemorialPillar_Text_ChazDefeat
    msgbox MemorialPillar_Text_ChazPostBattle, MSGBOX_AUTOCLOSE
    end

MemorialPillar_EventScript_Harold::
    trainerbattle_single TRAINER_BIRD_KEEPER_HAROLD, MemorialPillar_Text_HaroldIntro, MemorialPillar_Text_HaroldDefeat
    msgbox MemorialPillar_Text_HaroldPostBattle, MSGBOX_AUTOCLOSE
    end

MemorialPillar_Text_ScrubScrub::
    .string "Scrub, scrub…$"

MemorialPillar_Text_YourMonsLookHealthy::
    .string "Hello…\n"
    .string "Your Pokémon look healthy…$"

MemorialPillar_Text_ThisIsWhereIBuriedMyOnix::
    .string "This is where I buried my Onix…\n"
    .string "It was named Tectonix…$"

MemorialPillar_Text_HereLiesTectonixLemonadeOffering::
    .string "“Here lies Tectonix” is engraved\n"
    .string "on a boulder.\p"
    .string "There is a Lemonade placed as an\n"
    .string "offering in front of the grave.$"

MemorialPillar_Text_LeaveAnotherLemonadeOffering::
    .string "Would you like to leave another\n"
    .string "Lemonade as an offering?$"

MemorialPillar_Text_PlacedCanOfLemonade::
    .string "{PLAYER} placed a can of Lemonade\n"
    .string "in front of the grave.$"

MemorialPillar_Text_ThankYouPleaseTakeThis::
    .string "Th-thank you…\p"
    .string "That was my Tectonix's favourite\n"
    .string "drink…\p"
    .string "I don't even know you, but your\n"
    .string "act of kindness…\p"
    .string "It's uplifted me a little.\p"
    .string "Can you please take this as my\n"
    .string "thanks?$"

MemorialPillar_Text_BeGoodToYourMonsToo::
    .string "Please be good to your Pokémon,\n"
    .string "too.$"

MemorialPillar_Text_DontHaveRoomForIt::
    .string "If you don't have room for it,\n"
    .string "I'll hold it for you till next time.$"

MemorialPillar_Text_StillHaveThingAsMyThanks::
    .string "Oh, it's you from that time…\p"
    .string "I still have that thing I wanted\n"
    .string "you to have as my thanks.$"

MemorialPillar_Text_ScrubScrubTectonix::
    .string "Scrub, scrub…\p"
    .string "… … …\n"
    .string "Tectonix…$"

MemorialPillar_Text_HereLiesTectonix::
    .string "Boulders and rocks are neatly piled\n"
    .string "up as a cairn.\p"
    .string "“Here lies Tectonix” is engraved\n"
    .string "on a boulder.$"
