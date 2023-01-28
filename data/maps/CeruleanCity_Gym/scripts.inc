CeruleanCity_Gym_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Misty::
    trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, CeruleanCity_Gym_EventScript_MistyRematch
    goto_if_unset FLAG_GOT_TM03_FROM_MISTY, CeruleanCity_Gym_EventScript_GiveTM03
    msgbox CeruleanCity_Gym_Text_ExplainTM03, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Gym_EventScript_MistyDefeated::
    message CeruleanCity_Gym_Text_ReceivedCascadeBadge
    waitmessage
    call Common_EventScript_PlayGymBadgeFanfare
    msgbox CeruleanCity_Gym_Text_ExplainCascadeBadge, MSGBOX_DEFAULT
    setflag FLAG_DEFEATED_MISTY
    setflag FLAG_BADGE02_GET
    setrespawn HEAL_LOCATION_CERULEAN_CITY
    setvar VAR_0x8008, 2
    call Common_EventScript_SetGymTrainers
    goto CeruleanCity_Gym_EventScript_GiveTM03
    end

CeruleanCity_Gym_EventScript_GiveTM03::
    checkitemspace ITEM_TM03, 1
    compare VAR_RESULT, FALSE
    goto_if_eq CeruleanCity_Gym_EventScript_NoRoomForTM03
    giveitem_msg CeruleanCity_Gym_Text_ReceivedTM03FromMisty, ITEM_TM03
    setflag FLAG_GOT_TM03_FROM_MISTY
    msgbox CeruleanCity_Gym_Text_ExplainTM03, MSGBOX_DEFAULT
    closemessage
    delay 30
    playfanfare MUS_REGISTER_MATCH_CALL
    msgbox CeruleanCity_Gym_Text_RegisteredMisty, MSGBOX_DEFAULT
    waitfanfare
    closemessage
    delay 30
    setflag FLAG_ENABLE_MISTY_MATCH_CALL
    setvar VAR_BROCK_CALL_STEP_COUNTER, 0
    setflag FLAG_ENABLE_BROCK_FIRST_CALL
    release
    end

CeruleanCity_Gym_EventScript_NoRoomForTM03::
    msgbox CeruleanCity_Gym_Text_BetterMakeRoomForThis, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Gym_EventScript_MistyRematch::
	trainerbattle_rematch_double TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyPreRematch, CeruleanCity_Gym_Text_MistyRematchDefeat, CeruleanCity_Gym_Text_MistyRematchNeedTwoMons
	msgbox CeruleanCity_Gym_Text_MistyPostRematch, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Diana::
    trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
    msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
    end

CeruleanCity_Gym_EventScript_Luis::
    trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
    msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
    end

CeruleanCity_Gym_EventScript_GymGuy::
    lock
    faceplayer
    goto_if_set FLAG_DEFEATED_MISTY, CeruleanCity_Gym_EventScript_GymGuyPostVictory
    msgbox CeruleanCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
    release
    end

CeruleanCity_EventScript_RegisterBrock::
    lockall
    pokenavcall CeruleanCity_Text_BrockRegisterCall
    waitmessage
    delay 30
    playfanfare MUS_REGISTER_MATCH_CALL
    msgbox CeruleanCity_Text_RegisteredBrock, MSGBOX_DEFAULT
    waitfanfare
    closemessage
    delay 30
    setflag FLAG_ENABLE_BROCK_MATCH_CALL
    clearflag FLAG_ENABLE_BROCK_FIRST_CALL
    releaseall
    end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
    msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Gym_EventScript_GymStatue::
    lockall
    goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
    msgbox CeruleanCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
    releaseall
    end

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
    msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon, MSGBOX_DEFAULT
    releaseall
    end

CeruleanCity_Gym_Text_MistyIntro::
    .string "Hi, you're a new face!\p"
    .string "Only those Trainers who have a\n"
    .string "policy about Pokémon can turn pro.\p"
    .string "What is your approach when you\n"
    .string "catch and train Pokémon?\p"
    .string "My policy is an all-out offensive\n"
    .string "with Water-type Pokémon!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeruleanCity_Gym_Text_MistyDefeat::
    .string "Wow!\n"
    .string "You're too much!\p"
    .string "All right!\p"
    .string "You can have the CascadeBadge to\n"
    .string "show you beat me.$"
    
CeruleanCity_Gym_Text_ReceivedCascadeBadge::
    .string "{PLAYER} received the CascadeBadge\n"
    .string "from Misty!$"

CeruleanCity_Gym_Text_ExplainCascadeBadge::
    .string "The CascadeBadge makes all\n"
    .string "Pokémon up to Lv. 30 obey.\p"
    .string "That includes even outsiders you\n"
    .string "got in trades.\p"
    .string "There's more. You can now use Cut\n"
    .string "anytime, even out of battle.\p"
    .string "You can cut down small trees to\n"
    .string "open new pathways.\p"
    .string "You can also have my favourite TM.$"

CeruleanCity_Gym_Text_BetterMakeRoomForThis::
    .string "You better make room for this!$"

CeruleanCity_Gym_Text_ReceivedTM03FromMisty::
    .string "{PLAYER} received TM03\n"
    .string "from Misty.$"

CeruleanCity_Gym_Text_ExplainTM03::
    .string "TM03 teaches Water Pulse.\p"
    .string "Use it on an aquatic Pokémon!$"

CeruleanCity_Gym_Text_RegisteredMisty:
    .string "Registered Gym Leader Misty\n"
    .string "in the Pokénav.$"

CeruleanCity_Gym_Text_MistyPreRematch:
	.string "Misty: Oh! You're back!\p"
	.string "How has your approach to\n"
	.string "catching and training\l"
	.string "Pokémon developed?\p"
	.string "How about you show me\n"
	.string "in a battle!$"

CeruleanCity_Gym_Text_MistyRematchDefeat:
	.string "Wow!\n"
	.string "You're still too much!$"

CeruleanCity_Gym_Text_MistyPostRematch:
	.string "Misty: You've shown me that\n"
    .string "to get better at battling,\l"
    .string "I'm going to have to improve\l"
	.string "my approach to Pokémon.$"

CeruleanCity_Gym_Text_MistyRematchNeedTwoMons:
	.string "Misty: Oh! You're back!\p"
	.string "How has your approach to\n"
	.string "catching and training\l"
	.string "Pokémon developed?\p"
	.string "How about you show me\n"
	.string "in a battle!\p"
	.string "Oh? You only have one Pokémon\n"
	.string "that can battle.\p"
	.string "I'm sorry, but I'd like you to come back\n"
	.string "with at least two Pokémon.$"

CeruleanCity_Gym_Text_DianaIntro::
    .string "What? You?\n"
    .string "I'm more than good enough for you!\p"
    .string "Misty won't have to be bothered.$"

CeruleanCity_Gym_Text_DianaDefeat::
    .string "You overwhelmed me!$"

CeruleanCity_Gym_Text_DianaPostBattle::
    .string "You have to face other Trainers\n"
    .string "to see how good you really are.$"

CeruleanCity_Gym_Text_LuisIntro::
    .string "Splash!\p"
    .string "I'm first up!\n"
    .string "Let's do it!$"

CeruleanCity_Gym_Text_LuisDefeat::
    .string "That can't be!$"

CeruleanCity_Gym_Text_LuisPostBattle::
    .string "Misty is a Trainer who's going to\n"
    .string "keep improving.\p"
    .string "She won't lose to someone like you!$"

CeruleanCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Let me give you some advice!\p"
    .string "The leader, Misty, is a pro who\n"
    .string "uses Water-type Pokémon.\p"
    .string "You can drain all their water with\n"
    .string "Grass-type Pokémon.\p"
    .string "Or, you might use Electric-type\n"
    .string "Pokémon and zap them!$"

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
    .string "You beat Misty!\n"
    .string "See, what'd I tell ya?\p"
    .string "You and me, kid, we make a pretty\n"
    .string "darn-good team!$"

CeruleanCity_Text_BrockRegisterCall::
    .string "… … … … … …\n"
    .string "… … … … … Beep!\p"
    .string "Brock: Oh, hello, {PLAYER}?\n"
    .string "This is Brock of Pewter City.\p"
    .string "I heard from Misty that you're\n"
    .string "moving up through the ranks of\l"
    .string "Trainers at an incredible clip.\p"
    .string "Well, I'd rather not think that\n"
    .string "I can't beat you.\p"
    .string "I promise, I will shape up my gym\n"
    .string "so that you may challenge us again.\p"
    .string "I hope you'll be looking forward to\n"
    .string "that occasion as much as me!\p"
    .string "… … … … … …\n"
    .string "… … … … … Click!$"

CeruleanCity_Text_RegisteredBrock::
    .string "Registered Gym Leader Brock\n"
    .string "in the Pokénav.$"

CeruleanCity_Gym_Text_GymStatue::
    .string "Cerulean Pokémon Gym\n"
    .string "Leader: Misty\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "Cerulean Pokémon Gym\n"
    .string "Leader: Misty\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
