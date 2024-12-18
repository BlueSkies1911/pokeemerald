.equ CHECKED_MUSHROOMS,  FLAG_TEMP_1
.equ HAS_BIG_MUSHROOM,   FLAG_TEMP_2
.equ HAS_TINY_MUSHROOMS, FLAG_TEMP_3
.equ HAS_BOTH_MUSHROOMS, FLAG_TEMP_4

TwoIsland_House_MapScripts::
	.byte 0

TwoIsland_House_EventScript_MoveManiac::
    lock
    faceplayer
    clearflag HAS_BIG_MUSHROOM
    clearflag HAS_TINY_MUSHROOMS
    clearflag HAS_BOTH_MUSHROOMS
    goto_if_set CHECKED_MUSHROOMS, TwoIsland_House_EventScript_CheckPlayerHasMushrooms
    msgbox TwoIsland_House_Text_TeachMonMoveForMushroom, MSGBOX_DEFAULT
    setflag CHECKED_MUSHROOMS
    goto TwoIsland_House_EventScript_CheckPlayerHasMushrooms
    end

TwoIsland_House_EventScript_CheckPlayerHasMushrooms::
    checkitem ITEM_BIG_MUSHROOM, 1
    compare VAR_RESULT, TRUE
    call_if_eq TwoIsland_House_EventScript_SetHasBigMushroom
    checkitem ITEM_TINY_MUSHROOM, 2
    compare VAR_RESULT, TRUE
    call_if_eq TwoIsland_House_EventScript_SetHasTinyMushrooms
    goto_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_CheckAlsoHasTinyMushrooms
    goto_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_CheckAlsoHasBigMushroom
    goto TwoIsland_House_EventScript_EndTutorMove
    end

TwoIsland_House_EventScript_CheckAlsoHasTinyMushrooms::
    call_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_SetHasBothMushrooms
    goto TwoIsland_House_EventScript_AskTutorMon
    end

TwoIsland_House_EventScript_CheckAlsoHasBigMushroom::
    call_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_SetHasBothMushrooms
    goto TwoIsland_House_EventScript_AskTutorMon
    end

TwoIsland_House_EventScript_AskTutorMon::
    msgbox TwoIsland_House_Text_WantMeToTeachMove, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq TwoIsland_House_EventScript_EndTutorMove
    goto TwoIsland_House_EventScript_ChooseMonToTutor
    end

TwoIsland_House_EventScript_ChooseMonToTutor::
    msgbox TwoIsland_House_Text_TutorWhichMon, MSGBOX_DEFAULT
    special ChooseMonForMoveRelearner
    waitstate
    compare VAR_0x8004, PARTY_SIZE
    goto_if_ge TwoIsland_House_EventScript_EndTutorMove
    special IsSelectedMonEgg
    compare VAR_RESULT, TRUE
    goto_if_eq TwoIsland_House_EventScript_CantTutorEgg
    compare VAR_0x8005, 0
    goto_if_eq TwoIsland_House_EventScript_NoMoveToTutorMon
    goto TwoIsland_House_EventScript_ChooseMoveToTeach
    end

TwoIsland_House_EventScript_ChooseMoveToTeach::
    msgbox TwoIsland_House_Text_TeachWhichMove, MSGBOX_DEFAULT
    special TeachMoveRelearnerMove
    waitstate
    compare VAR_0x8004, 0
    goto_if_eq TwoIsland_House_EventScript_ChooseMonToTutor
    goto_if_set HAS_BOTH_MUSHROOMS, TwoIsland_House_EventScript_ChooseMushroom
    goto_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_GiveBigMushroom
    goto_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_GiveTinyMushrooms
    end

TwoIsland_House_EventScript_GiveBigMushroom::
    removeitem ITEM_BIG_MUSHROOM, 1
    msgbox TwoIsland_House_Text_HandedOverOneBigMushroom, MSGBOX_DEFAULT
    goto TwoIsland_House_EventScript_EndTutorMove
    end

TwoIsland_House_EventScript_GiveTinyMushrooms::
    removeitem ITEM_TINY_MUSHROOM, 2
    msgbox TwoIsland_House_Text_HandedOverTwoTinyMushrooms, MSGBOX_DEFAULT
    goto TwoIsland_House_EventScript_EndTutorMove
    end

TwoIsland_House_EventScript_ChooseMushroom::
    message TwoIsland_House_Text_IllNeedMushroomOrTwo
    waitmessage
    multichoice 0, 0, MULTI_MUSHROOMS, TRUE
    switch VAR_RESULT
    case 0, TwoIsland_House_EventScript_GiveTinyMushrooms
    case 1, TwoIsland_House_EventScript_GiveBigMushroom
    end

TwoIsland_House_EventScript_NoMoveToTutorMon::
    msgbox TwoIsland_House_Text_NoMoveICanTeachThatMon, MSGBOX_DEFAULT
    goto TwoIsland_House_EventScript_ChooseMonToTutor
    end

TwoIsland_House_EventScript_CantTutorEgg::
    msgbox TwoIsland_House_Text_CantTeachAnEgg, MSGBOX_DEFAULT
    goto TwoIsland_House_EventScript_ChooseMonToTutor
    end

TwoIsland_House_EventScript_EndTutorMove::
    msgbox TwoIsland_House_Text_NeedMushroomOrTwoToLearnMove, MSGBOX_DEFAULT
    release
    end

TwoIsland_House_EventScript_SetHasBigMushroom::
    setflag HAS_BIG_MUSHROOM
    return

TwoIsland_House_EventScript_SetHasTinyMushrooms::
    setflag HAS_TINY_MUSHROOMS
    return

TwoIsland_House_EventScript_SetHasBothMushrooms::
    setflag HAS_BOTH_MUSHROOMS
    return

TwoIsland_House_Text_TeachMonMoveForMushroom::
    .string "I'm the Pokémon Move Maniac.\p"
    .string "I know every single move that\n"
    .string "Pokémon learn growing up.\p"
    .string "I'm also a mushroom maniac.\p"
    .string "Bring me two TinyMushrooms,\n"
    .string "or one Big Mushroom.\p"
    .string "If you do that for me, I'll teach\n"
    .string "a move to one Pokémon.$"

TwoIsland_House_Text_WantMeToTeachMove::
    .string "Sniff, sniff…\n"
    .string "Hm! You smell of Mushrooms!\p"
    .string "Do you want me to teach a move\n"
    .string "to a Pokémon of yours?$"

TwoIsland_House_Text_TutorWhichMon::
    .string "Which Pokémon needs tutoring?$"

TwoIsland_House_Text_TeachWhichMove::
    .string "Which move should I teach?$"

TwoIsland_House_Text_NoMoveICanTeachThatMon::
    .string "Sorry…\p"
    .string "It doesn't appear as if I have a\n"
    .string "move I can teach that Pokémon.$"

TwoIsland_House_Text_IllNeedMushroomOrTwo::
    .string "Then, I'll need a Mushroom or two.\n"
    .string "What are you going to give me?$"

TwoIsland_House_Text_HandedOverTwoTinyMushrooms::
    .string "{PLAYER} handed over two\n"
    .string "TinyMushrooms in exchange.$"

TwoIsland_House_Text_HandedOverOneBigMushroom::
    .string "{PLAYER} handed over one\n"
    .string "Big Mushroom in exchange.$"

TwoIsland_House_Text_NeedMushroomOrTwoToLearnMove::
    .string "If your Pokémon need to learn a\n"
    .string "move, I need a Mushroom or two.$"

TwoIsland_House_Text_CantTeachAnEgg::
    .string "Hunh? There isn't a single move\n"
    .string "that I can teach an Egg.$"

