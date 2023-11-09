ViridianForest_NorthEntrance_MapScripts::
    .byte 0

ViridianForest_NorthEntrance_EventScript_Youngster::
    msgbox ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests, MSGBOX_NPC
    end

ViridianForest_NorthEntrance_EventScript_OldMan::
    msgbox ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees, MSGBOX_NPC
    end

ViridianForest_NorthEntrance_EventScript_CooltrainerF::
    msgbox ViridianForest_NorthEntrance_Text_CanCancelEvolution, MSGBOX_NPC
    end
    
ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests::
    .string "Many Pokémon live only in forests \n"
    .string "and caves.\p"
    .string "You need to be persistent and look\n"
    .string "everywhere to get different kinds.$"

ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees::
    .string "Have you noticed the skinny trees\n"
    .string "on the roadside?\p"
    .string "They can be cut down by a special\n"
    .string "Pokémon move, I hear.$"

ViridianForest_NorthEntrance_Text_CanCancelEvolution::
    .string "Do you know the evolution-cancel\n"
    .string "technique?\p"
    .string "When a Pokémon is evolving, you\n"
    .string "can stop the process.\p"
    .string "It's a technique for raising\n"
    .string "Pokémon the way they are.$"
