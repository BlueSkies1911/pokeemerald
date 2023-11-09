PokemonLab_ResearchRoom_MapScripts::
	.byte 0

PokemonLab_ResearchRoom_EventScript_MetronomeTutor::
    goto EventScript_MetronomeTutor
    end

PokemonLab_ResearchRoom_EventScript_Scientist::
    msgbox PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
    end

PokemonLab_ResearchRoom_EventScript_Computer::
    msgbox PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
    end

PokemonLab_ResearchRoom_EventScript_AmberPipe::
    msgbox PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
    end

PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons::
    .string "Eevee can evolve into one of three\n"
    .string "kinds of Pokémon.$"

PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
    .string "There's an e-mail message.\p"
    .string "… … …\p"
    .string "There are three legendary bird\n"
    .string "Pokémon.\p"
    .string "They are Articuno, Zapdos, and\n"
    .string "Moltres.\p"
    .string "Their whereabouts are unknown.\p"
    .string "We plan to explore the cavern\n"
    .string "close to Cerulean.\p"
    .string "From: Pokémon Research Team…$"

PokemonLab_ResearchRoom_Text_AnAmberPipe::
    .string "An amber pipe!$"
