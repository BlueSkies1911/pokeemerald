SaffronCity_Gym_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Sabrina::
    trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaIntro, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_DefeatedSabrina, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Gym_EventScript_SabrinaRematch
    goto_if_unset FLAG_GOT_TM04_FROM_SABRINA, SaffronCity_Gym_EventScript_GiveTM04
    msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
    release
    end

SaffronCity_Gym_EventScript_DefeatedSabrina::
    message SaffronCity_Gym_Text_ReceivedMarshBadge
    waitmessage
    call Common_EventScript_PlayGymBadgeFanfare
    msgbox SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis, MSGBOX_DEFAULT
    setflag FLAG_DEFEATED_SABRINA
    setflag FLAG_BADGE06_GET
    setvar VAR_0x8008, 6
    call Common_EventScript_SetGymTrainers
    goto SaffronCity_Gym_EventScript_GiveTM04
    end

SaffronCity_Gym_EventScript_GiveTM04::
    checkitemspace ITEM_TM04, 1
    compare VAR_RESULT, FALSE
    goto_if_eq SaffronCity_Gym_EventScript_NoRoomForTM04
    giveitem_msg SaffronCity_Gym_Text_ReceivedTM04FromSabrina, ITEM_TM04
    setflag FLAG_GOT_TM04_FROM_SABRINA
    msgbox SaffronCity_Gym_Text_ExplainTM04, MSGBOX_DEFAULT
    closemessage
    delay 30
    playfanfare MUS_REGISTER_MATCH_CALL
    msgbox SaffronCity_Gym_Text_RegisteredSabrina, MSGBOX_DEFAULT
    waitfanfare
    closemessage
    delay 30
    setflag FLAG_ENABLE_SABRINA_MATCH_CALL
    release
    end

SaffronCity_Gym_EventScript_NoRoomForTM04::
    msgbox SaffronCity_Gym_Text_BagFullOfOtherItems, MSGBOX_DEFAULT
    release
    end

SaffronCity_Gym_EventScript_SabrinaRematch::
	trainerbattle_rematch_double TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaPreRematch, SaffronCity_Gym_Text_SabrinaRematchDefeat, SaffronCity_Gym_Text_SabrinaRematchNeedTwoMons
	msgbox SaffronCity_Gym_Text_SabrinaPostRematch, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Johan::
    trainerbattle_single TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
    msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Gym_EventScript_Tyron::
    trainerbattle_single TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
    msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Gym_EventScript_Cameron::
    trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
    msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Gym_EventScript_Preston::
    trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
    msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Gym_EventScript_Amanda::
    trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
    msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Gym_EventScript_Stacy::
    trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
    msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Gym_EventScript_Tasha::
    trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
    msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Gym_EventScript_GymGuy::
    lock
    faceplayer
    goto_if_set FLAG_DEFEATED_SABRINA, SaffronCity_Gym_EventScript_GymGuyPostVictory
    msgbox SaffronCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
    release
    end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
    msgbox SaffronCity_Gym_Text_GymGuyPostVictory, MSGBOX_DEFAULT
    release
    end

SaffronCity_Gym_EventScript_GymStatue::
    lockall
    goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
    msgbox SaffronCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
    releaseall
    end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
    msgbox SaffronCity_Gym_Text_GymStatuePlayerWon, MSGBOX_DEFAULT
    releaseall
    end

SaffronCity_Gym_Text_SabrinaIntro::
    .string "I had a vision of your arrival.\p"
    .string "I have had psychic powers since\n"
    .string "I was a child.\p"
    .string "It started when a spoon I\n"
    .string "carelessly tossed, bent.\p"
    .string "I dislike battling, but if you wish,\n"
    .string "I will show you my powers!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

SaffronCity_Gym_Text_SabrinaDefeat::
    .string "This loss shocks me!\n"
    .string "But, a loss is a loss.\p"
    .string "I admit, I didn't work hard enough\n"
    .string "to win.\p"
    .string "Your victory has earned you the\n"
    .string "MarshBadge.$"

SaffronCity_Gym_Text_SabrinaPostBattle::
    .string "Psychic power isn't something that\n"
    .string "only a few people have.\p"
    .string "Everyone has psychic power.\n"
    .string "People just don't realise it.$"
    
SaffronCity_Gym_Text_ReceivedMarshBadge::
    .string "{PLAYER} received the MarshBadge\n"
    .string "from Sabrina!$"

SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis::
    .string "The MarshBadge makes Pokémon up\n"
    .string "to Lv. 70 obey you.\p"
    .string "Stronger Pokémon will become wild,\n"
    .string "ignoring your orders in battle.\p"
    .string "Just don't raise your Pokémon too\n"
    .string "much to avoid that problem.\p"
    .string "Wait, please take this TM with you.$"

SaffronCity_Gym_Text_ReceivedTM04FromSabrina::
    .string "{PLAYER} received TM04 from\n"
    .string "Sabrina.$"

SaffronCity_Gym_Text_ExplainTM04::
    .string "TM04 is Calm Mind.\p"
    .string "It makes the Pokémon concentrate\n"
    .string "to raise both Sp. Atk and Sp. Def.$"

SaffronCity_Gym_Text_RegisteredSabrina::
    .string "Registered Gym Leader Sabrina\n"
    .string "in the Pokénav.$"

SaffronCity_Gym_Text_BagFullOfOtherItems::
    .string "Your bag is full of other items.$"

SaffronCity_Gym_Text_SabrinaPreRematch:
	.string "Sabrina: I'm glad you have returned!\p"
	.string "I have always disliked battling, but\n"
	.string "since watching you in our battle,\l"
	.string "you have sparked my curiousity.\p"
	.string "Since then you have improved greatly…\p"
	.string "But so have I!\p"
    .string "Please, allow me to see your power!$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "Hmm…, I need to work even harder\n"
    .string "to win.$"

SaffronCity_Gym_Text_SabrinaPostRematch:
	.string "Sabrina: I must say, your power\n"
	.string "is overwhelming!\p"
	.string "It motivates me to continue training.\n"
	.string "I need to get better!$"

SaffronCity_Gym_Text_SabrinaRematchNeedTwoMons:
	.string "Sabrina: I'm glad you have returned!\p"
	.string "I have always disliked battling, but\n"
	.string "since watching you in our battle,\l"
	.string "you have sparked my curiousity.\p"
	.string "Since then you have improved greatly…\p"
	.string "But so have I!\p"
    .string "Please, allow me to see your power!\p"
	.string "Oh, no… Do you have but one\n"
	.string "Pokémon with you?\p"
	.string "Please return with two Pokémon\n"
	.string "at the very least.$"

SaffronCity_Gym_Text_AmandaIntro::
    .string "Sabrina is far younger than I,\n"
    .string "but she has earned my respect.$"

SaffronCity_Gym_Text_AmandaDefeat::
    .string "Not good enough!$"

SaffronCity_Gym_Text_AmandaPostBattle::
    .string "In a battle of equals, the one\n"
    .string "with the stronger will wins.\p"
    .string "If you wish to beat Sabrina, focus\n"
    .string "and will yourself to victory.$"

SaffronCity_Gym_Text_JohanIntro::
    .string "Does our unseen power scare you?$"

SaffronCity_Gym_Text_JohanDefeat::
    .string "I never foresaw this!$"

SaffronCity_Gym_Text_JohanPostBattle::
    .string "Psychic Pokémon fear only ghosts\n"
    .string "and bugs!$"

SaffronCity_Gym_Text_StacyIntro::
    .string "Pokémon take on the appearance of\n"
    .string "their Trainers.\p"
    .string "Your Pokémon must be tough, then!$"

SaffronCity_Gym_Text_StacyDefeat::
    .string "I knew it!$"

SaffronCity_Gym_Text_StacyPostBattle::
    .string "I have much to learn still…\p"
    .string "I must master Psychic and teach it\n"
    .string "to my Pokémon…$"

SaffronCity_Gym_Text_TyronIntro::
    .string "You understand, don't you?\p"
    .string "That power alone isn't enough to\n"
    .string "win in the world of Pokémon?$"

SaffronCity_Gym_Text_TyronDefeat::
    .string "I don't believe this!$"

SaffronCity_Gym_Text_TyronPostBattle::
    .string "Sabrina just wiped out the Karate\n"
    .string "Master next door.$"

SaffronCity_Gym_Text_TashaIntro::
    .string "You and I, our Pokémon shall\n"
    .string "battle!$"

SaffronCity_Gym_Text_TashaDefeat::
    .string "I lost after all!$"

SaffronCity_Gym_Text_TashaPostBattle::
    .string "I knew that this was going to take\n"
    .string "place.$"

SaffronCity_Gym_Text_CameronIntro::
    .string "Sabrina is young, but she's also\n"
    .string "our highly skilled Leader.\p"
    .string "You won't reach her easily!$"

SaffronCity_Gym_Text_CameronDefeat::
    .string "Ow!\n"
    .string "Down and out!$"

SaffronCity_Gym_Text_CameronPostBattle::
    .string "There used to be two Pokémon Gyms\n"
    .string "in Saffron.\p"
    .string "The Fighting Dojo next door lost\n"
    .string "its Gym status, though.\p"
    .string "We simply creamed them when we\n"
    .string "decided to have just one Gym.$"

SaffronCity_Gym_Text_PrestonIntro::
    .string "Saffron Pokémon Gym is famous for\n"
    .string "training psychics.\p"
    .string "You want to see Sabrina, don't\n"
    .string "you? I can tell!$"

SaffronCity_Gym_Text_PrestonDefeat::
    .string "Arrrgh!$"

SaffronCity_Gym_Text_PrestonPostBattle::
    .string "That's right! I used telepathy to\n"
    .string "read your mind!$"

SaffronCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Sabrina's Pokémon use psychic\n"
    .string "power instead of force.\p"
    .string "Fighting Pokémon are especially\n"
    .string "weak against Psychic Pokémon.\p"
    .string "They'll get destroyed before they\n"
    .string "can even aim a punch!$"

SaffronCity_Gym_Text_GymGuyPostVictory::
    .string "Psychic power, huh?\p"
    .string "If I had that, I'd make a bundle\n"
    .string "at the slots!$"

SaffronCity_Gym_Text_GymStatue::
    .string "Saffron Pokémon Gym\n"
    .string "Leader: Sabrina\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "Saffron Pokémon Gym\n"
    .string "Leader: Sabrina\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
