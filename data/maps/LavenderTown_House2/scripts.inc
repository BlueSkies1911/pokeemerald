LavenderTown_House2_MapScripts::
	.byte 0

LavenderTown_House2_EventScript_NameRater::
    lock
    faceplayer
    msgbox LavenderTown_House2_Text_WantMeToRateNicknames, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseMon
    goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
    end

LavenderTown_House2_EventScript_ChooseMon::
    msgbox LavenderTown_House2_Text_CritiqueWhichMonsNickname, MSGBOX_DEFAULT
    special ChoosePartyMon
    waitstate
    goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, LavenderTown_House2_EventScript_CheckCanRateMon
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LavenderTown_House2_EventScript_DontRateNickname
    end

LavenderTown_House2_EventScript_DontRateNickname::
    msgbox LavenderTown_House2_Text_ISeeComeVisitAgain, MSGBOX_DEFAULT
    release
    end

LavenderTown_House2_EventScript_CheckCanRateMon::
    specialvar VAR_RESULT, ScriptGetPartyMonSpecies
    goto_if_eq VAR_RESULT, SPECIES_EGG, LavenderTown_House2_EventScript_CantNicknameEgg
    special BufferMonNickname
    msgbox LavenderTown_House2_Text_GiveItANicerName, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseNewNickname
    goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
    end

LavenderTown_House2_EventScript_CantNicknameEgg::
    msgbox LavenderTown_House2_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
    release
    end

LavenderTown_House2_EventScript_CantNicknameTradeMon::
    msgbox LavenderTown_House2_Text_TrulyImpeccableName, MSGBOX_DEFAULT
    release
    end

LavenderTown_House2_EventScript_ChooseNewNickname::
    msgbox LavenderTown_House2_Text_WhatShallNewNicknameBe, MSGBOX_DEFAULT
    call Common_EventScript_NameReceivedPartyMon
    specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
    special BufferMonNickname
    goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_ChoseNewNickname
    msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName, MSGBOX_DEFAULT
    release
    end

LavenderTown_House2_EventScript_ChoseNewNickname::
    msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsName, MSGBOX_DEFAULT
    release
    end

LavenderTown_House2_Text_WantMeToRateNicknames::
    .string "Hello, hello!\n"
    .string "I am the official Name Rater!\p"
    .string "Want me to rate the nicknames of\n"
    .string "your Pokémon?$"

LavenderTown_House2_Text_CritiqueWhichMonsNickname::
    .string "Which Pokémon's nickname should\n"
    .string "I critique?$"

LavenderTown_House2_Text_GiveItANicerName::
    .string "{STR_VAR_1}, is it?\n"
    .string "That is a decent nickname!\p"
    .string "But, would you like me to give it\n"
    .string "a nicer name?\p"
    .string "How about it?$"

LavenderTown_House2_Text_WhatShallNewNicknameBe::
    .string "Ah, good. Then, what shall the new\n"
    .string "nickname be?$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsName::
    .string "Done! From now on, this Pokémon\n"
    .string "shall be known as {STR_VAR_1}!\p"
    .string "It is a better name than before!\n"
    .string "How fortunate for you!$"

LavenderTown_House2_Text_ISeeComeVisitAgain::
    .string "I see.\n"
    .string "Do come visit again.$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName::
    .string "Done! From now on, this Pokémon\n"
    .string "shall be known as {STR_VAR_1}!\p"
    .string "It looks no different from before,\n"
    .string "and yet, this is vastly superior!\p"
    .string "How fortunate for you!$"

LavenderTown_House2_Text_TrulyImpeccableName::
    .string "{STR_VAR_1}, is it?\n"
    .string "That is a truly impeccable name!\p"
    .string "Take good care of {STR_VAR_1}!$"

LavenderTown_House2_Text_ThatIsMerelyAnEgg::
    .string "Now, now.\n"
    .string "That is merely an Egg!$"
