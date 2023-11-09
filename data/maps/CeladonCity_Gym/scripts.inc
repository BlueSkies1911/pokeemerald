CeladonCity_Gym_MapScripts::
	.byte 0

CeladonCity_Gym_EventScript_Erika::
    trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_ErikaIntro, CeladonCity_Gym_Text_ErikaDefeat, CeladonCity_Gym_EventScript_DefeatedErika, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Gym_EventScript_ErikaRematch
    goto_if_unset FLAG_GOT_TM19_FROM_ERIKA, CeladonCity_Gym_EventScript_GiveTM19
    msgbox CeladonCity_Gym_Text_ErikaPostBattle, MSGBOX_DEFAULT
    release
    end

CeladonCity_Gym_EventScript_DefeatedErika::
    message CeladonCity_Gym_Text_ReceivedRainbowBadge
    waitmessage
    call Common_EventScript_PlayGymBadgeFanfare
    msgbox CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis, MSGBOX_DEFAULT
    setflag FLAG_DEFEATED_ERIKA
    setflag FLAG_BADGE04_GET
    setvar VAR_0x8008, 4
    call Common_EventScript_SetGymTrainers
    goto CeladonCity_Gym_EventScript_GiveTM19
    end

CeladonCity_Gym_EventScript_GiveTM19::
    checkitemspace ITEM_TM19, 1
    compare VAR_RESULT, FALSE
    goto_if_eq CeladonCity_Gym_EventScript_NoRoomForTM19
    giveitem_msg CeladonCity_Gym_Text_ReceivedTM19FromErika, ITEM_TM19
    setflag FLAG_GOT_TM19_FROM_ERIKA
    msgbox CeladonCity_Gym_Text_ExplainTM19, MSGBOX_DEFAULT
    closemessage
    delay 30
    playfanfare MUS_REGISTER_MATCH_CALL
    msgbox CeladonCity_Gym_Text_RegisteredErika, MSGBOX_DEFAULT
    waitfanfare
    closemessage
    delay 30
    setflag FLAG_ENABLE_ERIKA_MATCH_CALL
    release
    end

CeladonCity_Gym_EventScript_NoRoomForTM19::
    msgbox CeladonCity_Gym_Text_ShouldMakeRoomForThis, MSGBOX_DEFAULT
    release
    end

CeladonCity_Gym_EventScript_ErikaRematch::
	trainerbattle_rematch_double TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_ErikaPreRematch, CeladonCity_Gym_Text_ErikaRematchDefeat, CeladonCity_Gym_Text_ErikaRematchNeedTwoMons
	msgbox CeladonCity_Gym_Text_ErikaPostRematch, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Kay::
    trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
    msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
    end

CeladonCity_Gym_EventScript_Lisa::
    trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
    msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
    end

CeladonCity_Gym_EventScript_Tina::
    trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
    msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
    end

CeladonCity_Gym_EventScript_Bridget::
    trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
    msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
    end

CeladonCity_Gym_EventScript_Tamia::
    trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
    msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
    end

CeladonCity_Gym_EventScript_Lori::
    trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
    msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
    end

CeladonCity_Gym_EventScript_Mary::
    trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
    msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
    end

CeladonCity_Gym_EventScript_GymStatue::
    lockall
    goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
    msgbox CeladonCity_Gym_Text_GymStatue
    releaseall
    end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
    msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
    releaseall
    end

CeladonCity_Gym_Text_ErikaIntro::
    .string "Hello…\n"
    .string "Lovely weather, isn't it?\l"
    .string "It's so pleasant…\p"
    .string "…Oh, dear…\n"
    .string "I must have dozed off. Welcome.\p"
    .string "My name is Erika.\n"
    .string "I am the Leader of Celadon Gym.\p"
    .string "I am a student of the art of\n"
    .string "flower arranging.\p"
    .string "My Pokémon are solely of the\n"
    .string "Grass type.\p"
    .string "…Oh, I'm sorry, I had no idea that\n"
    .string "you wished to challenge me.\p"
    .string "Very well, but I shall not lose.$"

CeladonCity_Gym_Text_ErikaDefeat::
    .string "Oh!\n"
    .string "I concede defeat.\l"
    .string "You are remarkably strong.\p"
    .string "I must confer on you the\n"
    .string "RainbowBadge.$"
    
CeladonCity_Gym_Text_ReceivedRainbowBadge::
    .string "{PLAYER} received the RainbowBadge\n"
    .string "from Erika!$"

CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis::
    .string "The RainbowBadge will make\n"
    .string "Pokémon up to Lv. 50 obey.\p"
    .string "It also allows Pokémon to use\n"
    .string "Strength in and out of battle.\p"
    .string "Please also take this with you.$"

CeladonCity_Gym_Text_ReceivedTM19FromErika::
    .string "{PLAYER} received TM19\n"
    .string "from Erika.$"

CeladonCity_Gym_Text_ExplainTM19::
    .string "TM19 contains Giga Drain.\p"
    .string "Half the damage it inflicts is\n"
    .string "drained to heal your Pokémon.\p"
    .string "Wouldn't you agree that it's a\n"
    .string "wonderful move?$"

CeladonCity_Gym_Text_ShouldMakeRoomForThis::
    .string "You should make room for this.$"

CeladonCity_Gym_Text_ErikaPostBattle::
    .string "You are cataloging Pokémon?\n"
    .string "I must say I'm impressed.\p"
    .string "I would never collect Pokémon if\n"
    .string "they were unattractive.$"

CeladonCity_Gym_Text_RegisteredErika::
    .string "Registered Gym Leader Erika\n"
    .string "in the Pokénav.$"

CeladonCity_Gym_Text_ErikaPreRematch:
	.string "Erika: Losing a battle isn't going\n"
	.string "to harshen my mood.\p"
	.string "I love Pokémon.\n"
	.string "I love to battle.\l"
	.string "And… I love this gym!\p"
	.string "Let me show you\n"
	.string "in another battle!$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "Whew!\n"
	.string "You just keep getting better!$"

CeladonCity_Gym_Text_ErikaPostRematch:
	.string "Erika: I lost the match,\n"
	.string "but I'm completely at peace.\p"
	.string "It's not often I get to enjoy a battle\n"
	.string "this elegant.\p"
	.string "Let's have another one like this\n"
	.string "again sometime!$"

CeladonCity_Gym_Text_ErikaRematchNeedTwoMons:
	.string "Erika: Losing a battle isn't going\n"
	.string "to harshen my mood.\p"
	.string "I love Pokémon.\n"
	.string "I love to battle.\l"
	.string "And… I love this gym!\p"
	.string "Let me show you\n"
	.string "in another battle!\p"
	.string "Oh, wait. Do you only have one Pokémon\n"
	.string "that can battle?\p"
	.string "I hate to say this, but when you come\n"
	.string "see me, bring at least two Pokémon.$"

CeladonCity_Gym_Text_KayIntro::
    .string "I should tell you about this Gym.\p"
    .string "Only real ladies are allowed in\n"
    .string "here!$"

CeladonCity_Gym_Text_KayDefeat::
    .string "You're too rough!$"

CeladonCity_Gym_Text_KayPostBattle::
    .string "Bleaah!\n"
    .string "I hope Erika wipes you out!$"

CeladonCity_Gym_Text_BridgetIntro::
    .string "Oh, welcome.\n"
    .string "I was getting bored.$"

CeladonCity_Gym_Text_BridgetDefeat::
    .string "My makeup!$"

CeladonCity_Gym_Text_BridgetPostBattle::
    .string "Grass-type Pokémon are tough\n"
    .string "against the Water type.\p"
    .string "They also have an edge on Rock-\n"
    .string "and Ground-type Pokémon.$"

CeladonCity_Gym_Text_TinaIntro::
    .string "…Weren't you peeking in here\n"
    .string "earlier?$"

CeladonCity_Gym_Text_TinaDefeat::
    .string "You're an eye-opener!$"

CeladonCity_Gym_Text_TinaPostBattle::
    .string "Oh, you were looking at Erika…\n"
    .string "You weren't looking at me…$"

CeladonCity_Gym_Text_TamiaIntro::
    .string "Look, look!\n"
    .string "See my Pokémon!\p"
    .string "I like the Grass type.\n"
    .string "I like how they're easy to raise.$"

CeladonCity_Gym_Text_TamiaDefeat::
    .string "No!$"

CeladonCity_Gym_Text_TamiaPostBattle::
    .string "We only use Grass-type Pokémon at\n"
    .string "our Gym.\p"
    .string "Why? We also use them for making\n"
    .string "flower arrangements!$"

CeladonCity_Gym_Text_LisaIntro::
    .string "Oh, hey!\p"
    .string "We don't like Bug- or Fire-type\n"
    .string "Pokémon in here!$"

CeladonCity_Gym_Text_LisaDefeat::
    .string "Oh!\n"
    .string "You!$"

CeladonCity_Gym_Text_LisaPostBattle::
    .string "Our Leader Erika might be quiet,\n"
    .string "but she's famous around here.$"

CeladonCity_Gym_Text_LoriIntro::
    .string "Pleased to meet you.\n"
    .string "My hobby is Pokémon training.$"

CeladonCity_Gym_Text_LoriDefeat::
    .string "Oh!\n"
    .string "Splendid!$"

CeladonCity_Gym_Text_LoriPostBattle::
    .string "I have a blind date coming up.\n"
    .string "I have to learn to be polite,\l"
    .string "especially if I have to battle.$"

CeladonCity_Gym_Text_MaryIntro::
    .string "Welcome to Celadon Gym!\p"
    .string "You'd better not underestimate\n"
    .string "the nice ladies here.$"

CeladonCity_Gym_Text_MaryDefeat::
    .string "Oh!\n"
    .string "Beaten!$"

CeladonCity_Gym_Text_MaryPostBattle::
    .string "I didn't bring my best Pokémon.\n"
    .string "Wait until next time!$"

CeladonCity_Gym_Text_GymStatue::
    .string "Celadon Pokémon Gym\n"
    .string "Leader: Erika\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "Celadon Pokémon Gym\n"
    .string "Leader: Erika\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
