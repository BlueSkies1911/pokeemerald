WaterLabyrinth_MapScripts::
	.byte 0

WaterLabyrinth_EventScript_EggGentleman::
    lock
    faceplayer
    release
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
    .string "{PLAYER} received an Egg\n"
    .string "from the man!$"

WaterLabyrinth_Text_DontHaveSpaceInYourParty::
    .string "…Unfortunately, you don't have\n"
    .string "space for this in your party.\p"
    .string "You'd better come back for it\n"
    .string "another time.$"

WaterLabyrinth_Text_GladIMetSomeoneLikeYou::
    .string "I received that Egg while I was\n"
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
