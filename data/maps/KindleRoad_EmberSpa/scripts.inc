KindleRoad_EmberSpa_MapScripts::
	.byte 0

KindleRoad_EmberSpa_EventScript_OldMan::
    msgbox KindleRoad_EmberSpa_Text_WaterWarmsMeToCore, MSGBOX_NPC
    end

KindleRoad_EmberSpa_EventScript_BaldingMan1::
    msgbox KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder, MSGBOX_NPC
    end

KindleRoad_EmberSpa_EventScript_BaldingMan2::
    msgbox KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic, MSGBOX_NPC
    end

KindleRoad_EmberSpa_EventScript_OldWoman::
    msgbox KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs, MSGBOX_NPC
    end

KindleRoad_EmberSpa_EventScript_BlackBelt::
    msgbox KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion, MSGBOX_NPC
    end

KindleRoad_EmberSpa_EventScript_RockSmashMan::
    lock
    faceplayer
    goto_if_set FLAG_GOT_HM06, KindleRoad_EmberSpa_EventScript_AlreadyGotHM06
    msgbox KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa, MSGBOX_DEFAULT
    giveitem ITEM_HM06
    setflag FLAG_GOT_HM06
    msgbox KindleRoad_EmberSpa_Text_ExplainHM06, MSGBOX_DEFAULT
    release
    end

KindleRoad_EmberSpa_EventScript_AlreadyGotHM06::
    msgbox KindleRoad_EmberSpa_Text_ExplainHM06, MSGBOX_DEFAULT
    release
    end

KindleRoad_EmberSpa_EventScript_SpaHeal::
    lockall
    fadescreen FADE_TO_WHITE
    special HealPlayerParty
    fadescreen FADE_FROM_WHITE
    msgbox KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed, MSGBOX_DEFAULT
    setvar VAR_TEMP_1, 1
    releaseall
    end

KindleRoad_EmberSpa_Text_WaterWarmsMeToCore::
    .string "Hm!\n"
    .string "Haaaaaaaaaaah!\p"
    .string "Aaaah! This is heavenly!\n"
    .string "The water warms me to my core!\p"
    .string "You should jump in, too.\p"
    .string "Go to the middle, relax, and get\n"
    .string "good and warm!$"

KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder::
    .string "My favourite part of bathing comes\n"
    .string "up right after this.\p"
    .string "I enjoy a bowl of chowder to\n"
    .string "warm me from the inside, too!$"

KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed::
    .string "The water is perfectly warm.\n"
    .string "It feels exquisite…\p"
    .string "{PLAYER} and the Pokémon were\n"
    .string "fully refreshed!$"

KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic::
    .string "Soaking in a hot spring pool is\n"
    .string "therapeutic, people say.$"

KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs::
    .string "Have a look at my face.\n"
    .string "See how smooth my skin is?\p"
    .string "The hot spring's water keeps my\n"
    .string "skin younger than my age.$"

KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion::
    .string "After an honest day of training,\n"
    .string "nothing beats a relaxing soak in\l"
    .string "the hot spring pool.\p"
    .string "Bruno, who's a senior ahead of me,\n"
    .string "visits the spa on occasion.\p"
    .string "He comes to rehab injuries, both\n"
    .string "his own and his Pokémon's.$"

KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa::
    .string "Hot springs go hand-in-hand with\n"
    .string "volcanoes.\p"
    .string "The Ember Spa here, well,\n"
    .string "I made it years ago.\p"
    .string "I hewed the pool right out of a\n"
    .string "gigantic boulder by hand.\p"
    .string "I was using this at the time.\n"
    .string "I suppose I can part with it.$"

KindleRoad_EmberSpa_Text_ExplainHM06::
    .string "That shatters boulders as if they\n"
    .string "were made of crackers.$"
