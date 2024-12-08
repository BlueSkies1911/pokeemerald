PewterCity_Gym_MapScripts::
    .byte 0

PewterCity_Gym_EventScript_Brock::
    trainerbattle_single TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockIntro, PewterCity_Gym_Text_BrockDefeat, PewterCity_Gym_EventScript_DefeatedBrock, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PewterCity_Gym_EventScript_BrockRematch
    goto_if_unset FLAG_GOT_TM39_FROM_BROCK, PewterCity_Gym_EventScript_GiveTM39
    msgbox PewterCity_Gym_Text_BrockPostBattle, MSGBOX_DEFAULT
    release
    end

PewterCity_Gym_EventScript_DefeatedBrock::
    message PewterCity_Gym_Text_ReceivedBoulderBadge
    waitmessage
    call Common_EventScript_PlayGymBadgeFanfare
    msgbox PewterCity_Gym_Text_BoulderBadgeInfoTakeThis, MSGBOX_DEFAULT
    setflag FLAG_DEFEATED_BROCK
    setflag FLAG_BADGE01_GET
    setvar VAR_MAP_SCENE_PEWTER_CITY, 1
    setflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
    clearflag FLAG_HIDE_PEWTER_CITY_POKENAV_GUY
    setvar VAR_0x8008, 1
    call Common_EventScript_SetGymTrainers
    goto PewterCity_Gym_EventScript_GiveTM39
    end

PewterCity_Gym_EventScript_GiveTM39::
    msgbox PewterCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
    checkitemspace ITEM_TM39, 1
    compare VAR_RESULT, FALSE
    goto_if_eq PewterCity_Gym_EventScript_NoRoomForTM39
    giveitem_msg PewterCity_Gym_Text_ReceivedTM39FromBrock, ITEM_TM39
    setflag FLAG_GOT_TM39_FROM_BROCK
    msgbox PewterCity_Gym_Text_ExplainTM39, MSGBOX_DEFAULT
    release
    end

PewterCity_Gym_EventScript_NoRoomForTM39::
    msgbox PewterCity_Gym_Text_DontHaveRoomForThis, MSGBOX_DEFAULT
    release
    end

PewterCity_Gym_EventScript_BrockRematch::
	trainerbattle_rematch_double TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockPreRematch, PewterCity_Gym_Text_BrockRematchDefeat, PewterCity_Gym_Text_BrockRematchNeedTwoMons
	msgbox PewterCity_Gym_Text_BrockPostRematch, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Liam::
    trainerbattle_single TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat
    msgbox PewterCity_Gym_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
    end

PewterCity_Gym_EventScript_GymGuy::
    lock
    faceplayer
    goto_if_set FLAG_DEFEATED_BROCK, PewterCity_Gym_EventScript_GymGuyPostVictory
    msgbox PewterCity_Gym_Text_LetMeTakeYouToTheTop, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq PewterCity_Gym_EventScript_GymGuyTakeMeToTop
    compare VAR_RESULT, NO
    goto_if_eq PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop
    end

PewterCity_Gym_EventScript_GymGuyPostVictory::
    msgbox PewterCity_Gym_Text_YoureChampMaterial, MSGBOX_DEFAULT
    release
    end

PewterCity_Gym_EventScript_GymGuyTakeMeToTop::
    msgbox PewterCity_Gym_Text_LetsGetHappening, MSGBOX_DEFAULT
    goto PewterCity_Gym_EventScript_GymGuyAdvice
    end

PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop::
    msgbox PewterCity_Gym_Text_ItsFreeLetsGetHappening, MSGBOX_DEFAULT
    goto PewterCity_Gym_EventScript_GymGuyAdvice
    end

PewterCity_Gym_EventScript_GymGuyAdvice::
    msgbox PewterCity_Gym_Text_TryDifferentPartyOrders, MSGBOX_DEFAULT
    release
    end

PewterCity_Gym_EventScript_GymStatue::
    lockall
    goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
    msgbox PewterCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
    releaseall
    end

PewterCity_Gym_EventScript_GymStatuePostVictory::
    msgbox PewterCity_Gym_Text_GymStatuePlayerWon, MSGBOX_DEFAULT
    releaseall
    end

PewterCity_Gym_Text_BrockIntro::
    .string "So, you're here. I'm Brock.\n"
    .string "I'm Pewter's Gym Leader.\p"
    .string "My rock-hard willpower is evident\n"
    .string "even in my Pokémon.\p"
    .string "My Pokémon are all rock hard, and\n"
    .string "have true-grit determination.\p"
    .string "That's right - my Pokémon are all\n"
    .string "the Rock type!\p"
    .string "Fuhaha! You're going to challenge\n"
    .string "me knowing that you'll lose?\p"
    .string "That's the Trainer's honour that\n"
    .string "compels you to challenge me.\p"
    .string "Fine, then!\n"
    .string "Show me your best!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

@ NOTE: This defeat text actually causes a buffer overflow. It's too long for the gDisplayedStringBattle
@ buffer that it's put into, and it stomps all over the gBattleTextBuffs after, as well as the otherwise
@ unused array after that, gUnknown_2022AE8. Perhaps that's the reason why said array exists.
PewterCity_Gym_Text_BrockDefeat::
    .string "I took you for granted, and so\n"
    .string "I lost.\p"
    .string "As proof of your victory, I confer\n"
    .string "on you this…the official Pokémon\l"
    .string "League BoulderBadge.$"
    
PewterCity_Gym_Text_ReceivedBoulderBadge::
    .string "{PLAYER} received the BoulderBadge\n"
    .string "from Brock!$"
    
PewterCity_Gym_Text_BoulderBadgeInfoTakeThis::
    .string "Just having the BoulderBadge makes\n"
    .string "your Pokémon more powerful.\p"
    .string "It also enables the use of the\n"
    .string "move Flash outside of battle.\p"
    .string "Of course, a Pokémon must know the\n"
    .string "move Flash to use it.$"

PewterCity_Gym_Text_TakeThisWithYou::
    .string "Wait!\n"
    .string "Take this with you.$"

PewterCity_Gym_Text_ReceivedTM39FromBrock::
    .string "{PLAYER} received TM39\n"
    .string "from Brock.$"

PewterCity_Gym_Text_ExplainTM39::
    .string "A TM, Technical Machine, contains a\n"
    .string "technique for Pokémon.\p"
    .string "Using a TM teaches the move it\n"
    .string "contains to a Pokémon.\p"
    .string "A TM can be used as many times as.\n"
    .string "you'd like, so please enjoy it.\p"
    .string "Anyways…\n"
    .string "TM39 contains Rock Tomb.\p"
    .string "It hurls boulders at the foe and\n"
    .string "lowers its Speed.$"

PewterCity_Gym_Text_BrockPostBattle::
    .string "There are all kinds of Trainers in\n"
    .string "this huge world of ours.\p"
    .string "You appear to be very gifted as a\n"
    .string "Pokémon Trainer.\p"
    .string "So let me make a suggestion.\p"
    .string "Go to the Gym in Cerulean and test\n"
    .string "your abilities.$"

PewterCity_Gym_Text_DontHaveRoomForThis::
    .string "You don't have room for this.$"

PewterCity_Gym_Text_BrockPreRematch:
	.string "Brock: I'm so glad to see you again.\n"
	.string "I'm Brock, the Gym Leader here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"

PewterCity_Gym_Text_BrockRematchDefeat:
	.string "Grr…\n"
	.string "Again, I have lost…$"

PewterCity_Gym_Text_BrockPostRematch:
	.string "Brock: I still have much to learn\n"
	.string "when it comes to battling Pokémon.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"

PewterCity_Gym_Text_BrockRematchNeedTwoMons:
	.string "Brock: I'm so glad to see you again.\n"
	.string "I'm Brock, the Gym Leader here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one Pokémon with you?\p"
	.string "Please return with at least one more\n"
	.string "Pokémon.$"

PewterCity_Gym_Text_LiamIntro::
    .string "Stop right there, kid!\p"
    .string "You're ten thousand light-years \n"
    .string "from facing Brock!$"

PewterCity_Gym_Text_LiamDefeat::
    .string "Darn!\p"
    .string "Light-years isn't time…\n"
    .string "It measures distance!$"

PewterCity_Gym_Text_LiamPostBattle::
    .string "You're pretty hot.\n"
    .string "…But not as hot as Brock!$"

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
    .string "Hiya!\n"
    .string "Do you want to dream big?\p"
    .string "Do you dare to dream of becoming\n"
    .string "the Pokémon champ?\p"
    .string "I'm no Trainer, but I can advise\n"
    .string "you on how to win.\p"
    .string "Let me take you to the top!$"

PewterCity_Gym_Text_LetsGetHappening::
    .string "All right!\n"
    .string "Let's get happening!$"

PewterCity_Gym_Text_TryDifferentPartyOrders::
    .string "The first Pokémon out in a match is\n"
    .string "at the left of the Pokémon List.\p"
    .string "By changing the order of Pokémon,\n"
    .string "you may gain an advantage.\p"
    .string "Try different orders to suit your\n"
    .string "opponent's party.$"

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
    .string "It's a free service!\n"
    .string "Let's get happening!$"

PewterCity_Gym_Text_YoureChampMaterial::
    .string "Just as I thought!\n"
    .string "You're Pokémon champ material!$"

PewterCity_Gym_Text_GymStatue::
    .string "Pewter Pokémon Gym\n"
    .string "Leader: Brock\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "Pewter Pokémon Gym\n"
    .string "Leader: Brock\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
