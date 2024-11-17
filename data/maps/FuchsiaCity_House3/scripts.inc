.equ CHECKED_MUSHROOMS,  FLAG_TEMP_1
.equ HAS_BIG_MUSHROOM,   FLAG_TEMP_2
.equ HAS_TINY_MUSHROOMS, FLAG_TEMP_3
.equ HAS_BOTH_MUSHROOMS, FLAG_TEMP_4

FuchsiaCity_House3_MapScripts::
	.byte 0

FuchsiaCity_House3_EventScript_MoveDeleter::
    lock
    faceplayer
    msgbox FuchsiaCity_House3_Text_WouldYouLikeToForgetMove, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
    goto FuchsiaCity_House3_EventScript_CancelForgetMove
    end

FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter::
    msgbox FuchsiaCity_House3_Text_WhichMonShouldForgetMove, MSGBOX_DEFAULT
    special ChoosePartyMon
    waitstate
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FuchsiaCity_House3_EventScript_CancelForgetMove
    special IsSelectedMonEgg
    goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_House3_EventScript_CantForgetMoveEgg
    special GetNumMovesSelectedMonHas
    goto_if_eq VAR_RESULT, 1, FuchsiaCity_House3_EventScript_CantForgetOnlyMove
    msgbox FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
    fadescreen FADE_TO_BLACK
    special MoveDeleterChooseMoveToForget
    fadescreen FADE_FROM_BLACK
    goto_if_eq VAR_0x8005, MAX_MON_MOVES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
    special BufferMoveDeleterNicknameAndMove
    msgbox FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
    switch VAR_RESULT
    case YES, FuchsiaCity_House3_EventScript_ForgetMove
    case NO, FuchsiaCity_House3_EventScript_CancelForgetMove
    releaseall
    end

FuchsiaCity_House3_EventScript_ForgetMove::
    special MoveDeleterForgetMove
    playfanfare MUS_MOVE_DELETED
    waitfanfare
    msgbox FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely, MSGBOX_DEFAULT
    releaseall
    end

FuchsiaCity_House3_EventScript_CantForgetOnlyMove::
    special BufferMoveDeleterNicknameAndMove
    msgbox FuchsiaCity_House3_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
    releaseall
    end

FuchsiaCity_House3_EventScript_CantForgetMoveEgg::
    msgbox FuchsiaCity_House3_Text_NoEggShouldKnowMoves, MSGBOX_DEFAULT
    releaseall
    end

FuchsiaCity_House3_EventScript_CancelForgetMove::
    msgbox FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves, MSGBOX_DEFAULT
    releaseall
    end

FuchsiaCity_House3_EventScript_MoveManiac::
    lock
    faceplayer
    clearflag HAS_BIG_MUSHROOM
    clearflag HAS_TINY_MUSHROOMS
    clearflag HAS_BOTH_MUSHROOMS
    goto_if_set CHECKED_MUSHROOMS, FuchsiaCity_House3_EventScript_CheckPlayerHasMushrooms
    msgbox FuchsiaCity_House3_Text_TeachMonMoveForMushroom, MSGBOX_DEFAULT
    setflag CHECKED_MUSHROOMS
    goto FuchsiaCity_House3_EventScript_CheckPlayerHasMushrooms
    end

FuchsiaCity_House3_EventScript_CheckPlayerHasMushrooms::
    checkitem ITEM_BIG_MUSHROOM, 1
    compare VAR_RESULT, TRUE
    call_if_eq FuchsiaCity_House3_EventScript_SetHasBigMushroom
    checkitem ITEM_TINY_MUSHROOM, 2
    compare VAR_RESULT, TRUE
    call_if_eq FuchsiaCity_House3_EventScript_SetHasTinyMushrooms
    goto_if_set HAS_BIG_MUSHROOM, FuchsiaCity_House3_EventScript_CheckAlsoHasTinyMushrooms
    goto_if_set HAS_TINY_MUSHROOMS, FuchsiaCity_House3_EventScript_CheckAlsoHasBigMushroom
    goto FuchsiaCity_House3_EventScript_EndTutorMove
    end

FuchsiaCity_House3_EventScript_CheckAlsoHasTinyMushrooms::
    call_if_set HAS_TINY_MUSHROOMS, FuchsiaCity_House3_EventScript_SetHasBothMushrooms
    goto FuchsiaCity_House3_EventScript_AskTutorMon
    end

FuchsiaCity_House3_EventScript_CheckAlsoHasBigMushroom::
    call_if_set HAS_BIG_MUSHROOM, FuchsiaCity_House3_EventScript_SetHasBothMushrooms
    goto FuchsiaCity_House3_EventScript_AskTutorMon
    end

FuchsiaCity_House3_EventScript_AskTutorMon::
    msgbox FuchsiaCity_House3_Text_WantMeToTeachMove, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq FuchsiaCity_House3_EventScript_EndTutorMove
    goto FuchsiaCity_House3_EventScript_ChooseMonToTutor
    end

FuchsiaCity_House3_EventScript_ChooseMonToTutor::
    msgbox FuchsiaCity_House3_Text_TutorWhichMon, MSGBOX_DEFAULT
    special ChooseMonForMoveRelearner
    waitstate
    compare VAR_0x8004, PARTY_SIZE
    goto_if_ge FuchsiaCity_House3_EventScript_EndTutorMove
    special IsSelectedMonEgg
    compare VAR_RESULT, TRUE
    goto_if_eq FuchsiaCity_House3_EventScript_CantTutorEgg
    compare VAR_0x8005, 0
    goto_if_eq FuchsiaCity_House3_EventScript_NoMoveToTutorMon
    goto FuchsiaCity_House3_EventScript_ChooseMoveToTeach
    end

FuchsiaCity_House3_EventScript_ChooseMoveToTeach::
    msgbox FuchsiaCity_House3_Text_TeachWhichMove, MSGBOX_DEFAULT
    special TeachMoveRelearnerMove
    waitstate
    compare VAR_0x8004, 0
    goto_if_eq FuchsiaCity_House3_EventScript_ChooseMonToTutor
    goto_if_set HAS_BOTH_MUSHROOMS, FuchsiaCity_House3_EventScript_ChooseMushroom
    goto_if_set HAS_BIG_MUSHROOM, FuchsiaCity_House3_EventScript_GiveBigMushroom
    goto_if_set HAS_TINY_MUSHROOMS, FuchsiaCity_House3_EventScript_GiveTinyMushrooms
    end

FuchsiaCity_House3_EventScript_GiveBigMushroom::
    removeitem ITEM_BIG_MUSHROOM, 1
    msgbox FuchsiaCity_House3_Text_HandedOverOneBigMushroom, MSGBOX_DEFAULT
    goto FuchsiaCity_House3_EventScript_EndTutorMove
    end

FuchsiaCity_House3_EventScript_GiveTinyMushrooms::
    removeitem ITEM_TINY_MUSHROOM, 2
    msgbox FuchsiaCity_House3_Text_HandedOverTwoTinyMushrooms, MSGBOX_DEFAULT
    goto FuchsiaCity_House3_EventScript_EndTutorMove
    end

FuchsiaCity_House3_EventScript_ChooseMushroom::
    message FuchsiaCity_House3_Text_IllNeedMushroomOrTwo
    waitmessage
    multichoice 0, 0, MULTI_MUSHROOMS, TRUE
    switch VAR_RESULT
    case 0, FuchsiaCity_House3_EventScript_GiveTinyMushrooms
    case 1, FuchsiaCity_House3_EventScript_GiveBigMushroom
    end

FuchsiaCity_House3_EventScript_NoMoveToTutorMon::
    msgbox FuchsiaCity_House3_Text_NoMoveICanTeachThatMon, MSGBOX_DEFAULT
    goto FuchsiaCity_House3_EventScript_ChooseMonToTutor
    end

FuchsiaCity_House3_EventScript_CantTutorEgg::
    msgbox FuchsiaCity_House3_Text_CantTeachAnEgg, MSGBOX_DEFAULT
    goto FuchsiaCity_House3_EventScript_ChooseMonToTutor
    end

FuchsiaCity_House3_EventScript_EndTutorMove::
    msgbox FuchsiaCity_House3_Text_NeedMushroomOrTwoToLearnMove, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_House3_EventScript_SetHasBigMushroom::
    setflag HAS_BIG_MUSHROOM
    return

FuchsiaCity_House3_EventScript_SetHasTinyMushrooms::
    setflag HAS_TINY_MUSHROOMS
    return

FuchsiaCity_House3_EventScript_SetHasBothMushrooms::
    setflag HAS_BOTH_MUSHROOMS
    return

FuchsiaCity_House3_Text_WouldYouLikeToForgetMove::
    .string "Uh…\n"
    .string "Oh, yes, I'm the Move Deleter.\p"
    .string "I can make Pokémon forget their\n"
    .string "moves.\p"
    .string "Would you like me to do that?$"

FuchsiaCity_House3_Text_WhichMonShouldForgetMove::
    .string "Which Pokémon should forget a\n"
    .string "move?$"

FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten::
    .string "Which move should be forgotten?$"

FuchsiaCity_House3_Text_MonOnlyKnowsOneMove::
    .string "{STR_VAR_1} seems to know only one\n"
    .string "move…$"

FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten::
    .string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
    .string "That move should be forgotten?$"

FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely::
    .string "It worked to perfection!\p"
    .string "{STR_VAR_1} has forgotten\n"
    .string "{STR_VAR_2} completely.$"

FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves::
    .string "Come again if there are other\n"
    .string "moves to be forgotten.$"

FuchsiaCity_House3_Text_NoEggShouldKnowMoves::
    .string "What?\n"
    .string "No Egg should know any moves.$"

FuchsiaCity_House3_Text_TeachMonMoveForMushroom::
    .string "I'm the Pokémon Move Maniac.\p"
    .string "I know every single move that\n"
    .string "Pokémon learn growing up.\p"
    .string "I'm also a mushroom maniac.\p"
    .string "Bring me two TinyMushrooms,\n"
    .string "or one Big Mushroom.\p"
    .string "If you do that for me, I'll teach\n"
    .string "a move to one Pokémon.$"

FuchsiaCity_House3_Text_WantMeToTeachMove::
    .string "Sniff, sniff…\n"
    .string "Hm! You smell of Mushrooms!\p"
    .string "Do you want me to teach a move\n"
    .string "to a Pokémon of yours?$"

FuchsiaCity_House3_Text_TutorWhichMon::
    .string "Which Pokémon needs tutoring?$"

FuchsiaCity_House3_Text_TeachWhichMove::
    .string "Which move should I teach?$"

FuchsiaCity_House3_Text_NoMoveICanTeachThatMon::
    .string "Sorry…\p"
    .string "It doesn't appear as if I have a\n"
    .string "move I can teach that Pokémon.$"

FuchsiaCity_House3_Text_IllNeedMushroomOrTwo::
    .string "Then, I'll need a Mushroom or two.\n"
    .string "What are you going to give me?$"

FuchsiaCity_House3_Text_HandedOverTwoTinyMushrooms::
    .string "{PLAYER} handed over two\n"
    .string "TinyMushrooms in exchange.$"

FuchsiaCity_House3_Text_HandedOverOneBigMushroom::
    .string "{PLAYER} handed over one\n"
    .string "Big Mushroom in exchange.$"

FuchsiaCity_House3_Text_NeedMushroomOrTwoToLearnMove::
    .string "If your Pokémon need to learn a\n"
    .string "move, I need a Mushroom or two.$"

FuchsiaCity_House3_Text_CantTeachAnEgg::
    .string "Hunh? There isn't a single move\n"
    .string "that I can teach an Egg.$"
