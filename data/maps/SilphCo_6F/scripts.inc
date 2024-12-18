SilphCo_6F_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, SilphCo_6F_OnLoad
	.byte 0

SilphCo_6F_OnLoad::
    call_if_unset FLAG_SILPH_6F_DOOR, EventScript_Close6FDoor
    end

SilphCo_6F_EventScript_Taylor::
    trainerbattle_single TRAINER_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorIntro, SilphCo_6F_Text_TaylorDefeat
    msgbox SilphCo_6F_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
    end

SilphCo_6F_EventScript_Grunt1::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_30, SilphCo_6F_Text_Grunt1Intro, SilphCo_6F_Text_Grunt1Defeat
    msgbox SilphCo_6F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
    end

SilphCo_6F_EventScript_Grunt2::
    trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_31, SilphCo_6F_Text_Grunt2Intro, SilphCo_6F_Text_Grunt2Defeat
    msgbox SilphCo_6F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
    end

SilphCo_6F_EventScript_WorkerM2::
    lock
    faceplayer
    compare VAR_MAP_SCENE_SILPH_CO_11F, 1
    goto_if_ge SilphCo_6F_EventScript_WorkerM2RocketsGone
    msgbox SilphCo_6F_Text_TargetedSilphForOurMonProducts, MSGBOX_DEFAULT
    release
    end

SilphCo_6F_EventScript_WorkerM2RocketsGone::
    msgbox SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder, MSGBOX_DEFAULT
    release
    end

SilphCo_6F_EventScript_WorkerM3::
    lock
    faceplayer
    compare VAR_MAP_SCENE_SILPH_CO_11F, 1
    goto_if_ge SilphCo_6F_EventScript_WorkerM3RocketsGone
    msgbox SilphCo_6F_Text_RocketsTookOverBuilding, MSGBOX_DEFAULT
    release
    end

SilphCo_6F_EventScript_WorkerM3RocketsGone::
    msgbox SilphCo_6F_Text_BetterGetBackToWork, MSGBOX_DEFAULT
    release
    end

SilphCo_6F_EventScript_WorkerM1::
    lock
    faceplayer
    compare VAR_MAP_SCENE_SILPH_CO_11F, 1
    goto_if_ge SilphCo_6F_EventScript_WorkerM1RocketsGone
    msgbox SilphCo_6F_Text_HelpMePlease, MSGBOX_DEFAULT
    release
    end

SilphCo_6F_EventScript_WorkerM1RocketsGone::
    msgbox SilphCo_6F_Text_WeGotEngaged, MSGBOX_DEFAULT
    release
    end

SilphCo_6F_EventScript_WorkerF1::
    lock
    faceplayer
    compare VAR_MAP_SCENE_SILPH_CO_11F, 1
    goto_if_ge SilphCo_6F_EventScript_WorkerF1RocketsGone
    msgbox SilphCo_6F_Text_ThatManIsSuchACoward, MSGBOX_DEFAULT
    release
    end

SilphCo_6F_EventScript_WorkerF1RocketsGone::
    msgbox SilphCo_6F_Text_NeedsMeToLookAfterHim, MSGBOX_DEFAULT
    release
    end

SilphCo_6F_EventScript_WorkerF2::
    lock
    faceplayer
    compare VAR_MAP_SCENE_SILPH_CO_11F, 1
    goto_if_ge SilphCo_6F_EventScript_WorkerF2RocketsGone
    msgbox SilphCo_6F_Text_RocketsTryingToConquerWorld, MSGBOX_DEFAULT
    release
    end

SilphCo_6F_EventScript_WorkerF2RocketsGone::
    msgbox SilphCo_6F_Text_RocketsRanAwayBecauseOfYou, MSGBOX_DEFAULT
    release
    end

SilphCo_6F_EventScript_FloorSign::
    msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
    end

SilphCo_6F_Text_Grunt1Intro::
    .string "I am one of the four Rocket\n"
    .string "Brothers!$"

SilphCo_6F_Text_Grunt1Defeat::
    .string "Flame out!$"

SilphCo_6F_Text_Grunt1PostBattle::
    .string "No matter!\n"
    .string "My brothers will avenge me!$"

SilphCo_6F_Text_TaylorIntro::
    .string "That rotten President!\p"
    .string "Serves him right for shipping me\n"
    .string "off to the Tiksi Branch!\p"
    .string "That's why Team Rocket came after\n"
    .string "us, I'm sure of it!$"

SilphCo_6F_Text_TaylorDefeat::
    .string "Shoot!$"

SilphCo_6F_Text_TaylorPostBattle::
    .string "Tiksi Branch?\n"
    .string "It's in Russian no-man's-land!$"

SilphCo_6F_Text_Grunt2Intro::
    .string "You dare betray Team Rocket?$"

SilphCo_6F_Text_Grunt2Defeat::
    .string "You traitor!$"

SilphCo_6F_Text_Grunt2PostBattle::
    .string "If you stand for justice, you\n"
    .string "betray us bad guys!$"

SilphCo_6F_Text_RocketsTookOverBuilding::
    .string "The Rockets came and took over\n"
    .string "the building!$"

SilphCo_6F_Text_BetterGetBackToWork::
    .string "Well, better get back to work.$"

SilphCo_6F_Text_HelpMePlease::
    .string "Oh dear, oh dear.\n"
    .string "Help me, please!$"

SilphCo_6F_Text_WeGotEngaged::
    .string "We got engaged.\n"
    .string "Heheh!$"

SilphCo_6F_Text_ThatManIsSuchACoward::
    .string "That man next to me…\n"
    .string "He's such a coward!$"

SilphCo_6F_Text_NeedsMeToLookAfterHim::
    .string "He's so helpless, he needed\n"
    .string "someone like me to look after him.$"

SilphCo_6F_Text_RocketsTryingToConquerWorld::
    .string "Team Rocket is trying to conquer\n"
    .string "the world with Pokémon.$"

SilphCo_6F_Text_RocketsRanAwayBecauseOfYou::
    .string "Team Rocket ran away, and it's all\n"
    .string "because of you!$"

SilphCo_6F_Text_TargetedSilphForOurMonProducts::
    .string "They must have targeted Silph for\n"
    .string "our Pokémon products.$"

SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder::
    .string "Come work for Silph when you\n"
    .string "get older.$"

SilphCo_6F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "6F$"
