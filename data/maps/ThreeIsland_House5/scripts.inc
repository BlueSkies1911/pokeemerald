ThreeIsland_House5_MapScripts::
	.byte 0

ThreeIsland_House5_EventScript_LittleGirl::
    lock
    faceplayer
    goto_if_set FLAG_RESCUED_LOSTELLE, ThreeIsland_House5_EventScript_LittleGirlLostelleFound
    msgbox ThreeIsland_House5_Text_ImNotLostelle, MSGBOX_DEFAULT
    release
    end

ThreeIsland_House5_EventScript_LittleGirlLostelleFound::
    msgbox ThreeIsland_House5_Text_IllGoPlayWithLostelle, MSGBOX_DEFAULT
    release
    end

ThreeIsland_House5_Text_ImNotLostelle::
    .string "Me?\n"
    .string "I'm not Lostelle.\p"
    .string "She's probably gone to the\n"
    .string "Berry Forest, I think.\p"
    .string "She picks berries there for making\n"
    .string "lunch.$"

ThreeIsland_House5_Text_IllGoPlayWithLostelle::
    .string "I think I'll go play with Lostelle\n"
    .string "today.$"
