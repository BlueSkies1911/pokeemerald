FuchsiaCity_Gym_MapScripts::
	.byte 0

FuchsiaCity_Gym_EventScript_Koga::
    trainerbattle_single TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_KogaIntro, FuchsiaCity_Gym_Text_KogaDefeat, FuchsiaCity_Gym_EventScript_DefeatedKoga, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_Gym_EventScript_KogaRematch
    goto_if_unset FLAG_GOT_TM06_FROM_KOGA, FuchsiaCity_Gym_EventScript_GiveTM06
    msgbox FuchsiaCity_Gym_Text_KogaPostBattle, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_Gym_EventScript_DefeatedKoga::
    message FuchsiaCity_Gym_Text_ReceivedSoulBadge
    waitmessage
    call Common_EventScript_PlayGymBadgeFanfare
    msgbox FuchsiaCity_Gym_Text_KogaExplainSoulBadge, MSGBOX_DEFAULT
    setflag FLAG_DEFEATED_KOGA
    setflag FLAG_BADGE05_GET
    setvar VAR_0x8008, 5
    call Common_EventScript_SetGymTrainers
    goto FuchsiaCity_Gym_EventScript_GiveTM06
    end

FuchsiaCity_Gym_EventScript_GiveTM06::
    checkitemspace ITEM_TM06, 1
    compare VAR_RESULT, FALSE
    goto_if_eq FuchsiaCity_Gym_EventScript_NoRoomForTM06
    giveitem_msg FuchsiaCity_Gym_Text_ReceivedTM06FromKoga, ITEM_TM06
    setflag FLAG_GOT_TM06_FROM_KOGA
    msgbox FuchsiaCity_Gym_Text_KogaExplainTM06, MSGBOX_DEFAULT
    closemessage
    delay 30
    playfanfare MUS_REGISTER_MATCH_CALL
    msgbox FuchsiaCity_Gym_Text_RegisteredKoga, MSGBOX_DEFAULT
    waitfanfare
    closemessage
    delay 30
    setflag FLAG_ENABLE_KOGA_MATCH_CALL
    release
    end

FuchsiaCity_Gym_EventScript_NoRoomForTM06::
    msgbox FuchsiaCity_Gym_Text_MakeSpaceForThis, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_Gym_EventScript_KogaRematch::
	trainerbattle_rematch_double TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_KogaPreRematch, FuchsiaCity_Gym_Text_KogaRematchDefeat, FuchsiaCity_Gym_Text_KogaRematchNeedTwoMons
	msgbox FuchsiaCity_Gym_Text_KogaPostRematch, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Phil::
    trainerbattle_single TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat
    msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
    end

FuchsiaCity_Gym_EventScript_Edgar::
    trainerbattle_single TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat
    msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
    end

FuchsiaCity_Gym_EventScript_Kirk::
    trainerbattle_single TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat
    msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
    end

FuchsiaCity_Gym_EventScript_Shawn::
    trainerbattle_single TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat
    msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
    end

FuchsiaCity_Gym_EventScript_Kayden::
    trainerbattle_single TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat
    msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
    end

FuchsiaCity_Gym_EventScript_Nate::
    trainerbattle_single TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat
    msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
    end

FuchsiaCity_Gym_EventScript_GymGuy::
    lock
    faceplayer
    goto_if_set FLAG_DEFEATED_KOGA, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
    msgbox FuchsiaCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
    msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_Gym_EventScript_GymStatue::
    lockall
    goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
    msgbox FuchsiaCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
    releaseall
    end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
    msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon, MSGBOX_DEFAULT
    releaseall
    end

FuchsiaCity_Gym_Text_KogaIntro::
    .string "Koga: Fwahahaha!\p"
    .string "A mere child like you dares to\n"
    .string "challenge me?\p"
    .string "The very idea makes me shiver\n"
    .string "with mirth!\p"
    .string "Very well, I shall show you true\n"
    .string "terror as a ninja master.\p"
    .string "Poison brings steady doom.\n"
    .string "Sleep renders foes helpless.\p"
    .string "Despair to the creeping horror of\n"
    .string "Poison-type Pokémon!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

FuchsiaCity_Gym_Text_KogaDefeat::
    .string "Humph!\n"
    .string "You have proven your worth!\p"
    .string "Here!\n"
    .string "Take the SoulBadge!$"

FuchsiaCity_Gym_Text_KogaPostBattle::
    .string "When afflicted by Toxic, a Pokémon\n"
    .string "suffers more and more.\p"
    .string "It suffers worsening damage as the\n"
    .string "battle wears on!\p"
    .string "It will surely terrorise foes!$"
    
FuchsiaCity_Gym_Text_ReceivedSoulBadge::
    .string "{PLAYER} received the SoulBadge\n"
    .string "from Koga!$"

FuchsiaCity_Gym_Text_KogaExplainSoulBadge::
    .string "Now that you have the SoulBadge,\n"
    .string "the Defense of your Pokémon rises.\p"
    .string "It also lets you Surf outside of\n"
    .string "battle.\p"
    .string "Ah!\n"
    .string "Take this, too!$"

FuchsiaCity_Gym_Text_ReceivedTM06FromKoga::
    .string "{PLAYER} received TM06\n"
    .string "from Koga.$"

FuchsiaCity_Gym_Text_KogaExplainTM06::
    .string "Sealed within that TM06 lies\n"
    .string "Toxic!\p"
    .string "It is a secret technique dating\n"
    .string "back some four hundred years.$"

FuchsiaCity_Gym_Text_RegisteredKoga::
    .string "Registered Gym Leader Koga\n"
    .string "in the Pokénav.$"

FuchsiaCity_Gym_Text_MakeSpaceForThis::
    .string "Make space for this, child!$"

FuchsiaCity_Gym_Text_KogaPreRematch:
    .string "Koga: Fwahahaha!\p"
    .string "Poison brings steady doom.\n"
    .string "Sleep renders foes helpless.\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning Champion.\p"
    .string "But this time I will show the\n"
    .string "true terror of a ninja master!$"

FuchsiaCity_Gym_Text_KogaRematchDefeat:
	.string "You've once again proven your worth!$"

FuchsiaCity_Gym_Text_KogaPostRematch:
	.string "Koga: Even though I have lost,\n"
	.string "my heart remains unbroken.\p"
	.string "I now know what I must do to\n"
	.string "achieve my goals.\p"
	.string "I am convinced of it!$"

FuchsiaCity_Gym_Text_KogaRematchNeedTwoMons:
    .string "Koga: Fwahahaha!\p"
    .string "Poison brings steady doom.\n"
    .string "Sleep renders foes helpless.\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning Champion.\p"
    .string "But this time I will show the\n"
    .string "true terror of a ninja master!$"
	.string "Oh, no… Do you have but one\n"
	.string "Pokémon with you?\p"
	.string "Please return with two Pokémon\n"
	.string "at the very least.$"

FuchsiaCity_Gym_Text_KaydenIntro::
    .string "Strength isn't the key for Pokémon.\n"
    .string "Do you understand this?\p"
    .string "Pokémon is about strategy!\p"
    .string "I'll show you how strategy can\n"
    .string "beat brute strength.$"

FuchsiaCity_Gym_Text_KaydenDefeat::
    .string "What?\n"
    .string "Extraordinary!$"

FuchsiaCity_Gym_Text_KaydenPostBattle::
    .string "So, you mix brawn with brains?\n"
    .string "Good strategy!\p"
    .string "That's remarkable for a child\n"
    .string "Trainer.$"

FuchsiaCity_Gym_Text_KirkIntro::
    .string "I was a magician once upon a time.\p"
    .string "But I dreamt of becoming a ninja,\n"
    .string "so I joined this Gym.$"

FuchsiaCity_Gym_Text_KirkDefeat::
    .string "I'm done for!$"

FuchsiaCity_Gym_Text_KirkPostBattle::
    .string "Even though I've lost, I will keep\n"
    .string "training according to the teachings\l"
    .string "of Koga, my ninja master.$"

FuchsiaCity_Gym_Text_NateIntro::
    .string "Let's see you beat my special\n"
    .string "techniques!$"

FuchsiaCity_Gym_Text_NateDefeat::
    .string "You had me fooled!$"

FuchsiaCity_Gym_Text_NatePostBattle::
    .string "I like poison and sleep techniques,\n"
    .string "as they linger after battle!$"

FuchsiaCity_Gym_Text_PhilIntro::
    .string "Stop right there!\p"
    .string "The famed invisible walls of\n"
    .string "Fuchsia Gym have you frustrated?$"

FuchsiaCity_Gym_Text_PhilDefeat::
    .string "Whoa!\n"
    .string "You've got it!$"

FuchsiaCity_Gym_Text_PhilPostBattle::
    .string "You impressed me!\n"
    .string "Here's a hint!\p"
    .string "Look very closely for gaps in the\n"
    .string "invisible walls!$"

FuchsiaCity_Gym_Text_EdgarIntro::
    .string "I also study the way of the ninja\n"
    .string "with Master Koga!\p"
    .string "Ninja have a long history of using\n"
    .string "animals!$"

FuchsiaCity_Gym_Text_EdgarDefeat::
    .string "Awoo!$"

FuchsiaCity_Gym_Text_EdgarPostBattle::
    .string "I still have much to learn.$"

FuchsiaCity_Gym_Text_ShawnIntro::
    .string "Master Koga comes from a long line\n"
    .string "of ninjas.\p"
    .string "What did you descend from?$"

FuchsiaCity_Gym_Text_ShawnDefeat::
    .string "You're more skilled than I'd\n"
    .string "thought!$"

FuchsiaCity_Gym_Text_ShawnPostBattle::
    .string "Where there is light, there is\n"
    .string "shadow!\p"
    .string "Light and shadow!\n"
    .string "Which do you choose?$"

FuchsiaCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Fuchsia Gym is a tricked-up place.\n"
    .string "It's riddled with invisible walls!\p"
    .string "Koga might appear close, but he's\n"
    .string "blocked off.\p"
    .string "You have to find gaps in the walls\n"
    .string "to reach him.$"

FuchsiaCity_Gym_Text_GymGuyPostVictory::
    .string "It's amazing how ninja can terrify,\n"
    .string "even now!$"

FuchsiaCity_Gym_Text_GymStatue::
    .string "Fuchsia Pokémon Gym\n"
    .string "Leader: Koga\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
    .string "Fuchsia Pokémon Gym\n"
    .string "Leader: Koga\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
