.set LOCALID_WOMAN, 1
.set LOCALID_LASS,  2

ViridianCity_House2_MapScripts::
    .byte 0

ViridianCity_House2_EventScript_Lass::
    lock
    faceplayer
    msgbox ViridianCity_House2_Text_TryingToMemoriseNotes, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    release
    end

ViridianCity_House2_EventScript_Woman::
    lock
    faceplayer
    msgbox ViridianCity_House2_Text_ReadBlackboardCarefully, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

ViridianCity_House2_EventScript_Notebook::
    lockall
    msgbox ViridianCity_House2_Text_NotebookFirstPage, MSGBOX_DEFAULT
    msgbox ViridianCity_House2_Text_TurnThePage, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq ViridianCity_House2_EventScript_StopReadingNotebook
    msgbox ViridianCity_House2_Text_NotebookSecondPage, MSGBOX_DEFAULT
    msgbox ViridianCity_House2_Text_TurnThePage, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq ViridianCity_House2_EventScript_StopReadingNotebook
    msgbox ViridianCity_House2_Text_NotebookThirdPage, MSGBOX_DEFAULT
    msgbox ViridianCity_House2_Text_TurnThePage, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq ViridianCity_House2_EventScript_StopReadingNotebook
    msgbox ViridianCity_House2_Text_NotebookFourthPage, MSGBOX_DEFAULT
    applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox ViridianCity_House2_Text_HeyDontLookAtMyNotes, MSGBOX_DEFAULT
    releaseall
    end

ViridianCity_House2_EventScript_StopReadingNotebook::
    releaseall
    end

ViridianCity_House2_EventScript_Blackboard::
    lockall
    msgbox ViridianCity_House2_Text_BlackboardListsStatusProblems, MSGBOX_DEFAULT
    goto ViridianCity_House2_EventScript_ChooseBlackboardTopic
    end

ViridianCity_House2_EventScript_ChooseBlackboardTopic::
    msgbox ViridianCity_House2_Text_ReadWhichTopic, MSGBOX_DEFAULT
    waitmessage
    multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
    switch VAR_RESULT
    case 0, ViridianCity_House2_EventScript_ReadPoison
    case 1, ViridianCity_House2_EventScript_ReadParalysis
    case 2, ViridianCity_House2_EventScript_ReadSleep
    case 3, ViridianCity_House2_EventScript_ReadBurn
    case 4, ViridianCity_House2_EventScript_ReadFreeze
    case 5, ViridianCity_House2_EventScript_ExitBlackboard
    case MULTI_B_PRESSED, ViridianCity_House2_EventScript_ExitBlackboard
    end

ViridianCity_House2_EventScript_ReadSleep::
    msgbox ViridianCity_House2_Text_ExplainSleep, MSGBOX_DEFAULT
    goto ViridianCity_House2_EventScript_ChooseBlackboardTopic
    end

ViridianCity_House2_EventScript_ReadBurn::
    msgbox ViridianCity_House2_Text_ExplainBurn, MSGBOX_DEFAULT
    goto ViridianCity_House2_EventScript_ChooseBlackboardTopic
    end

ViridianCity_House2_EventScript_ReadPoison::
    msgbox ViridianCity_House2_Text_ExplainPoison, MSGBOX_DEFAULT
    goto ViridianCity_House2_EventScript_ChooseBlackboardTopic
    end

ViridianCity_House2_EventScript_ReadFreeze::
    msgbox ViridianCity_House2_Text_ExplainFreeze, MSGBOX_DEFAULT
    goto ViridianCity_House2_EventScript_ChooseBlackboardTopic
    end

ViridianCity_House2_EventScript_ReadParalysis::
    msgbox ViridianCity_House2_Text_ExplainParalysis, MSGBOX_DEFAULT
    goto ViridianCity_House2_EventScript_ChooseBlackboardTopic
    end

ViridianCity_House2_EventScript_ExitBlackboard::
    releaseall
    end
    
ViridianCity_House2_EventScript_PokemonJournal::
    lock
    faceplayer
    msgbox PokemonJournal_Text_SpecialFeatureProfOak, MSGBOX_DEFAULT
    release
    end

ViridianCity_House2_Text_TryingToMemoriseNotes::
    .string "Whew! I'm trying to memorise all my\n"
    .string "notes.$"

ViridianCity_House2_Text_ReadBlackboardCarefully::
    .string "Okay!\p"
    .string "Be sure to read what's on the\n"
    .string "blackboard carefully!$"

ViridianCity_House2_Text_NotebookFirstPage::
    .string "Let's check out the notebook.\p"
    .string "First page…\p"
    .string "Pokéballs are used to catch\n"
    .string "Pokémon.\p"
    .string "Up to six Pokémon can be carried\n"
    .string "in your party.\p"
    .string "People who raise and battle\n"
    .string "with Pokémon are called Trainers.$"

ViridianCity_House2_Text_NotebookSecondPage::
    .string "Second page…\p"
    .string "A healthy Pokémon may be hard to\n"
    .string "catch, so weaken it first.\p"
    .string "Poison, burn, or cause another\n"
    .string "status problem to weaken it.$"

ViridianCity_House2_Text_NotebookThirdPage::
    .string "Third page…\p"
    .string "Pokémon Trainers seek others to\n"
    .string "engage in Pokémon battles.\p"
    .string "To Trainers, the taste of victory\n"
    .string "is sweet, indeed.\p"
    .string "Battles are constantly waged at\n"
    .string "Pokémon Gyms everywhere.$"

ViridianCity_House2_Text_NotebookFourthPage::
    .string "Fourth page…\p"
    .string "The ultimate goal for all Pokémon\n"
    .string "Trainers is simple.\p"
    .string "It is to defeat the top eight\n"
    .string "Pokémon Gym Leaders.\p"
    .string "Do so to earn the right to face…\p"
    .string "The Elite Four of the Pokémon\n"
    .string "League!$"

ViridianCity_House2_Text_TurnThePage::
    .string "Turn the page?$"

ViridianCity_House2_Text_HeyDontLookAtMyNotes::
    .string "Girl: Hey!\n"
    .string "Don't look at my notes!$"

ViridianCity_House2_Text_BlackboardListsStatusProblems::
    .string "The blackboard lists Pokémon\n"
    .string "Status problems during battles.$"

ViridianCity_House2_Text_ReadWhichTopic::
    .string "Which topic do you want to read?$"

ViridianCity_House2_Text_ExplainSleep::
    .string "A Pokémon can't attack if it's\n"
    .string "asleep.\p"
    .string "Pokémon will stay asleep even\n"
    .string "after battles.\p"
    .string "Use Awakening to awaken one\n"
    .string "from sleep.$"

ViridianCity_House2_Text_ExplainBurn::
    .string "A burn reduces Attack power.\n"
    .string "It also causes ongoing HP loss.\p"
    .string "A burn remains after a battle.\n"
    .string "Use Burn Heal to cure a burn.$"

ViridianCity_House2_Text_ExplainPoison::
    .string "When poisoned, a Pokémon's health\n"
    .string "steadily drops.\p"
    .string "Poison lingers after battles.\n"
    .string "Use an Antidote to cure poison!$"

ViridianCity_House2_Text_ExplainFreeze::
    .string "A frozen Pokémon becomes\n"
    .string "helplessly immobile.\p"
    .string "It stays frozen even after the\n"
    .string "battle ends.\p"
    .string "Use Ice Heal to thaw out the\n"
    .string "suffering Pokémon.$"

ViridianCity_House2_Text_ExplainParalysis::
    .string "Paralysis reduces Speed and may\n"
    .string "prevent the Pokémon from moving.\p"
    .string "Paralysis remains after battles.\n"
    .string "Use Parlyz Heal for treatment.$"

PokemonJournal_Text_SpecialFeatureProfOak::
    .string "Pokémon Journal\p"
    .string "Special Feature: Prof. Oak,\n"
    .string "the Pokémon Researcher!\p"
    .string "Prof. Oak reportedly lives with his\n"
    .string "grandchildren Daisy and {RIVAL}.$"
