PatternBush_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, PatternBush_OnTransition
	.byte 0

PatternBush_OnTransition:
    setflag FLAG_WORLD_MAP_PATTERN_BUSH
    getplayerxy VAR_TEMP_1, VAR_TEMP_2
    compare VAR_TEMP_1, 50
    call_if_ge PatternBush_EventScript_SetEscapeRightExit
    compare VAR_TEMP_1, 49
    call_if_le PatternBush_EventScript_SetEscapeLeftExit
    end

PatternBush_EventScript_SetEscapeRightExit::
    setescapewarp MAP_GREEN_PATH, 255, 64, 10
    return

PatternBush_EventScript_SetEscapeLeftExit::
    setescapewarp MAP_GREEN_PATH, 255, 45, 10
    return

PatternBush_EventScript_Bethany::
    trainerbattle_single TRAINER_PKMN_BREEDER_BETHANY, PatternBush_Text_BethanyIntro, PatternBush_Text_BethanyDefeat
    msgbox PatternBush_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Allison::
    trainerbattle_single TRAINER_PKMN_BREEDER_ALLISON, PatternBush_Text_AllisonIntro, PatternBush_Text_AllisonDefeat
    msgbox PatternBush_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Garret::
    trainerbattle_single TRAINER_BUG_CATCHER_GARRET, PatternBush_Text_GarretIntro, PatternBush_Text_GarretDefeat
    msgbox PatternBush_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Jonah::
    trainerbattle_single TRAINER_BUG_CATCHER_JONAH, PatternBush_Text_JonahIntro, PatternBush_Text_JonahDefeat
    msgbox PatternBush_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Vance::
    trainerbattle_single TRAINER_BUG_CATCHER_VANCE, PatternBush_Text_VanceIntro, PatternBush_Text_VanceDefeat
    msgbox PatternBush_Text_VancePostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Nash::
    trainerbattle_single TRAINER_YOUNGSTER_NASH, PatternBush_Text_NashIntro, PatternBush_Text_NashDefeat
    msgbox PatternBush_Text_NashPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Cordell::
    trainerbattle_single TRAINER_YOUNGSTER_CORDELL, PatternBush_Text_CordellIntro, PatternBush_Text_CordellDefeat
    msgbox PatternBush_Text_CordellPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Dalia::
    trainerbattle_single TRAINER_LASS_DALIA, PatternBush_Text_DaliaIntro, PatternBush_Text_DaliaDefeat
    msgbox PatternBush_Text_DaliaPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Joana::
    trainerbattle_single TRAINER_LASS_JOANA, PatternBush_Text_JoanaIntro, PatternBush_Text_JoanaDefeat
    msgbox PatternBush_Text_JoanaPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Riley::
    trainerbattle_single TRAINER_CAMPER_RILEY, PatternBush_Text_RileyIntro, PatternBush_Text_RileyDefeat
    msgbox PatternBush_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Marcy::
    trainerbattle_single TRAINER_PICNICKER_MARCY, PatternBush_Text_MarcyIntro, PatternBush_Text_MarcyDefeat
    msgbox PatternBush_Text_MarcyPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_EventScript_Layton::
    trainerbattle_single TRAINER_RUIN_MANIAC_LAYTON, PatternBush_Text_LaytonIntro, PatternBush_Text_LaytonDefeat
    msgbox PatternBush_Text_LaytonPostBattle, MSGBOX_AUTOCLOSE
    end

PatternBush_Text_BethanyIntro::
    .string "I'm curious, how do you raise your\n"
    .string "Pokémon?$"

PatternBush_Text_BethanyDefeat::
    .string "You raise your Pokémon with a\n"
    .string "whole lot of love!$"

PatternBush_Text_BethanyPostBattle::
    .string "In the same way your mother raised\n"
    .string "you full of love, you should raise\l"
    .string "your Pokémon.$"

PatternBush_Text_AllisonIntro::
    .string "I'm working to preserve the natural\n"
    .string "ecology of Pokémon here.$"

PatternBush_Text_AllisonDefeat::
    .string "Oh, for someone so young, you are\n"
    .string "tremendous!$"

PatternBush_Text_AllisonPostBattle::
    .string "I'm not saying that you shouldn't\n"
    .string "catch Pokémon.\p"
    .string "I just want people to raise their\n"
    .string "Pokémon responsibly.$"

PatternBush_Text_GarretIntro::
    .string "I caught a Bug Pokémon that lives\n"
    .string "only around here!$"

PatternBush_Text_GarretDefeat::
    .string "Heheh…\n"
    .string "Isn't my Pokémon awesome?$"

PatternBush_Text_GarretPostBattle::
    .string "There's a girl near the bush who\n"
    .string "measures Heracross for Trainers.$"

PatternBush_Text_JonahIntro::
    .string "You know, it just doesn't feel right\n"
    .string "if I don't use Bug Pokémon.$"

PatternBush_Text_JonahDefeat::
    .string "It's okay, losing is a fun part of\n"
    .string "Pokémon's appeal, too.$"

PatternBush_Text_JonahPostBattle::
    .string "By the way, “appeal” is a weird\n"
    .string "word, if you think about it.\p"
    .string "Like, is it like an orange peel?\n"
    .string "Or like a ringing bell?$"

PatternBush_Text_VanceIntro::
    .string "Yeah, yeah, yeah!\n"
    .string "Look at all the Bug Pokémon!$"

PatternBush_Text_VanceDefeat::
    .string "I got beat while I was still busy\n"
    .string "celebrating!$"

PatternBush_Text_VancePostBattle::
    .string "I'm going to bring my little brother\n"
    .string "here next time.$"

PatternBush_Text_NashIntro::
    .string "Look, look! There are funny\n"
    .string "patterns on the ground.$"

PatternBush_Text_NashDefeat::
    .string "Super awesome!$"

PatternBush_Text_NashPostBattle::
    .string "The funny patterns on the ground…\p"
    .string "They look like the patterns on my\n"
    .string "grandpa's clothes.$"

PatternBush_Text_CordellIntro::
    .string "I bet you think I'm just some guy,\n"
    .string "don't you, eh?$"

PatternBush_Text_CordellDefeat::
    .string "I bet you think I'm weak,\n"
    .string "don't you, eh?$"

PatternBush_Text_CordellPostBattle::
    .string "Ayup, you townies come around all\n"
    .string "so dandy with a hat that flashy…\p"
    .string "How about giving me that?$"

PatternBush_Text_DaliaIntro::
    .string "Take a deep breath.\n"
    .string "Isn't the air delicious?$"

PatternBush_Text_DaliaDefeat::
    .string "If you'd like, I can teach you how\n"
    .string "to breathe properly.$"

PatternBush_Text_DaliaPostBattle::
    .string "First, exhale.\n"
    .string "Blow everything out.\p"
    .string "When you can't exhale anymore,\n"
    .string "inhale the clean air!\p"
    .string "Isn't it refreshing?$"

PatternBush_Text_JoanaIntro::
    .string "I love Bug Pokémon.\n"
    .string "That's why I'm here all the time.\p"
    .string "Am I the only girl like that?$"

PatternBush_Text_JoanaDefeat::
    .string "I lost, but I'm still laughing.\n"
    .string "Am I the only girl like that?$"

PatternBush_Text_JoanaPostBattle::
    .string "I'm going to keep on collecting\n"
    .string "Bug Pokémon.\p"
    .string "Am I the only girl like that?$"

PatternBush_Text_RileyIntro::
    .string "This is a good spot.\n"
    .string "I'll pitch my tent here.$"

PatternBush_Text_RileyDefeat::
    .string "Wimped out…$"

PatternBush_Text_RileyPostBattle::
    .string "I'm going to observe the night sky\n"
    .string "here.$"

PatternBush_Text_MarcyIntro::
    .string "Oh, yuck!\n"
    .string "I think a bug stung me!$"

PatternBush_Text_MarcyDefeat::
    .string "It wasn't a bug.\n"
    .string "I cut my shin on some grass.$"

PatternBush_Text_MarcyPostBattle::
    .string "A little cut like that…\n"
    .string "A little spit's enough to cure it!$"

PatternBush_Text_LaytonIntro::
    .string "Have you noticed something odd\n"
    .string "about these parts?$"

PatternBush_Text_LaytonDefeat::
    .string "Have you taken a good look around\n"
    .string "your feet?$"

PatternBush_Text_LaytonPostBattle::
    .string "There are places here in Pattern\n"
    .string "Bush where grass won't grow.\p"
    .string "What could be the cause of such\n"
    .string "a phenomenon?$"
