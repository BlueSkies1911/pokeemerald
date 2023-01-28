WaterLabyrinth_MapScripts::
	.byte 0

WaterLabyrinth_EventScript_EggGentleman::
    lock
    faceplayer
    goto_if_set FLAG_GOT_TOGEPI_EGG, WaterLabyrinth_EventScript_PostEggComment
    goto_if_set FLAG_NO_ROOM_FOR_TOGEPI_EGG, WaterLabyrinth_EventScript_ReturnForEgg
    msgbox WaterLabyrinth_Text_LetMeTakeLookAtMons, MSGBOX_DEFAULT
    specialvar VAR_RESULT, GetLeadMonFriendshipScore
    compare VAR_RESULT, 6  @ Max friendship
    goto_if_eq WaterLabyrinth_EventScript_LeadMonMaxFriendship
    msgbox WaterLabyrinth_Text_HmmISeeIsee, MSGBOX_DEFAULT
    release
    end

WaterLabyrinth_EventScript_MonDaisyComment::
    msgbox WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy, MSGBOX_NPC
    end

WaterLabyrinth_EventScript_LeadMonMaxFriendship::
    msgbox WaterLabyrinth_Text_TreatMonRightHaveThis, MSGBOX_DEFAULT
    goto WaterLabyrinth_EventScript_TryGiveEgg
    end

WaterLabyrinth_EventScript_TryGiveEgg::
    getpartysize
    compare VAR_RESULT, PARTY_SIZE
    goto_if_eq WaterLabyrinth_EventScript_NoRoomForEgg
    setflag FLAG_GOT_TOGEPI_EGG
    giveegg SPECIES_TOGEPI
    playfanfare MUS_LEVEL_UP
    message WaterLabyrinth_Text_ReceivedEggFromMan
    waitfanfare
    waitmessage
    goto WaterLabyrinth_EventScript_PostEggComment
    end

@ If the player has a Togepi/Togetic from this game (assumed to be the one the man gave you) then comment on it
@ Otherwise make normal comment
WaterLabyrinth_EventScript_PostEggComment::
    bufferspeciesname 1, SPECIES_TOGEPI
    setvar VAR_0x8004, SPECIES_TOGEPI
    specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
    compare VAR_RESULT, TRUE
    goto_if_eq WaterLabyrinth_EventScript_MonDaisyComment
    bufferspeciesname 1, SPECIES_TOGETIC
    setvar VAR_0x8004, SPECIES_TOGETIC
    specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
    compare VAR_RESULT, TRUE
    goto_if_eq WaterLabyrinth_EventScript_MonDaisyComment
    msgbox WaterLabyrinth_Text_GladIMetSomeoneLikeYou, MSGBOX_DEFAULT
    release
    end

WaterLabyrinth_EventScript_NoRoomForEgg::
    setflag FLAG_NO_ROOM_FOR_TOGEPI_EGG
    msgbox WaterLabyrinth_Text_DontHaveSpaceInYourParty, MSGBOX_DEFAULT
    release
    end

WaterLabyrinth_EventScript_ReturnForEgg::
    goto WaterLabyrinth_EventScript_TryGiveEgg
    end

WaterLabyrinth_EventScript_Alize::
    trainerbattle_single TRAINER_PKMN_BREEDER_ALIZE, WaterLabyrinth_Text_AlizeIntro, WaterLabyrinth_Text_AlizeDefeat, WaterLabyrinth_EventScript_RegisterAlize
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq WaterLabyrinth_EventScript_AlizeRematch
    msgbox WaterLabyrinth_Text_AlizePostBattle, MSGBOX_AUTOCLOSE
    end

WaterLabyrinth_EventScript_RegisterAlize::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox WaterLabyrinth_Text_AlizeRegister, MSGBOX_DEFAULT
    register_matchcall TRAINER_PKMN_BREEDER_ALIZE
    release
    end

WaterLabyrinth_EventScript_AlizeRematch::
    trainerbattle_rematch TRAINER_PKMN_BREEDER_ALIZE, WaterLabyrinth_Text_AlizeRematchIntro, WaterLabyrinth_Text_AlizeDefeat
    msgbox WaterLabyrinth_Text_AlizePostBattle, MSGBOX_AUTOCLOSE
    end

WaterLabyrinth_Text_LetMeTakeLookAtMons::
    .string "You travel all over the place,\n"
    .string "don't you?\p"
    .string "You're not driving your Pokémon\n"
    .string "too harshly, are you?\p"
    .string "Let me take a look.\n"
    .string "… … …   … … …$"

WaterLabyrinth_Text_HmmISeeIsee::
    .string "Ah, hmm…\n"
    .string "I see, I see…$"

WaterLabyrinth_Text_TreatMonRightHaveThis::
    .string "Oh, impressive.\n"
    .string "You treat your Pokémon right.\p"
    .string "I think you can be entrusted with\n"
    .string "this.\p"
    .string "Please, I'd like you to have this.$"

WaterLabyrinth_Text_ReceivedEggFromMan::
    .string "{PLAYER} received an egg\n"
    .string "from the man!$"

WaterLabyrinth_Text_DontHaveSpaceInYourParty::
    .string "…Unfortunately, you don't have\n"
    .string "space for this in your party.\p"
    .string "You'd better come back for it\n"
    .string "another time.$"

WaterLabyrinth_Text_GladIMetSomeoneLikeYou::
    .string "I received that egg while I was\n"
    .string "travelling.\p"
    .string "I'm glad I met someone like you.$"

WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy::
    .string "Oh, hello.\n"
    .string "That's a cute {STR_VAR_2}.\p"
    .string "Seeing it reminds me of a sweet \n"
    .string "little girl I met while travelling.\p"
    .string "She was gently grooming Pokémon…\n"
    .string "She was a little angel.\p"
    .string "That little girl's name…\n"
    .string "I think it was Daisy.$"
