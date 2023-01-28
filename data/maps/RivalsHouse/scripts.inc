.set LOCALID_DAISY, 1
.equ LOCALID_TOWN_MAP, 2

RivalsHouse_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, RivalsHouse_OnTransition
    .byte 0

RivalsHouse_OnTransition:
    compare VAR_MAP_SCENE_RIVALS_HOUSE, 2
    call_if_lt RivalsHouse_EventScript_MoveDaisyToTable

RivalsHouse_EventScript_MoveDaisyToTable::
    setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
    setobjectxyperm LOCALID_DAISY, 5, 4
    return

RivalsHouse_EventScript_Daisy::
    lock
    faceplayer
    compare VAR_MAP_SCENE_RIVALS_HOUSE, 3
    goto_if_eq RivalsHouse_EventScript_GroomMon
    compare VAR_MAP_SCENE_RIVALS_HOUSE, 2
    goto_if_eq RivalsHouse_EventScript_DaisyNotReadyYet
    compare VAR_MAP_SCENE_RIVALS_HOUSE, 1
    goto_if_eq RivalsHouse_EventScript_NoTownMap
    compare VAR_MAP_SCENE_PROFESSOR_OAKS_LAB, 1
    goto_if_ge RivalsHouse_EventScript_HeardBattledRival
    msgbox RivalsHouse_Text_HiBrothersAtLab, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

RivalsHouse_EventScript_GroomMon::
	compare VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500
	goto_if_lt RivalsHouse_EventScript_RateMonFriendship
	msgbox RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RivalsHouse_EventScript_DeclineGrooming
	msgbox RivalsHouse_Text_GroomWhichOne, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq RivalsHouse_EventScript_CantGroomEgg
	msgbox RivalsHouse_Text_LookingNiceInNoTime, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox RivalsHouse_Text_ThereYouGoAllDone
	release
	end

RivalsHouse_EventScript_CantGroomEgg::
	msgbox RivalsHouse_Text_CantGroomAnEgg, MSGBOX_DEFAULT
	release
	end

RivalsHouse_EventScript_DeclineGrooming::
	msgbox RivalsHouse_Text_DontNeedAnyGrooming, MSGBOX_DEFAULT
	release
	end

RivalsHouse_EventScript_RateMonFriendship::
    msgbox RivalsHouse_Text_MayISeeFirstMon, MSGBOX_DEFAULT
    specialvar VAR_RESULT, GetLeadMonFriendshipScore
    switch VAR_RESULT
    case 0, RivalsHouse_EventScript_DetestsYou
    case 1, RivalsHouse_EventScript_VeryWary
    case 2, RivalsHouse_EventScript_NotUsedToYou
    case 3, RivalsHouse_EventScript_GettingUsedToYou
    case 4, RivalsHouse_EventScript_LikesYouQuiteALot
    case 5, RivalsHouse_EventScript_VeryHappy
    case 6, RivalsHouse_EventScript_AdoresYou
    release
    end

RivalsHouse_EventScript_DetestsYou::
    msgbox RivalsHouse_Text_DetestsYou, MSGBOX_DEFAULT
    release
    end

RivalsHouse_EventScript_VeryWary::
    msgbox RivalsHouse_Text_VeryWary, MSGBOX_DEFAULT
    release
    end

RivalsHouse_EventScript_NotUsedToYou::
    msgbox RivalsHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
    release
    end

RivalsHouse_EventScript_GettingUsedToYou::
    msgbox RivalsHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
    release
    end

RivalsHouse_EventScript_LikesYouQuiteALot::
    msgbox RivalsHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
    release
    end

RivalsHouse_EventScript_VeryHappy::
    msgbox RivalsHouse_Text_VeryHappy, MSGBOX_DEFAULT
    release
    end

RivalsHouse_EventScript_AdoresYou::
    msgbox RivalsHouse_Text_AdoresYou, MSGBOX_DEFAULT
    release
    end

RivalsHouse_EventScript_DaisyNotReadyYet::
    msgbox RivalsHouse_Text_DaisyNotReadyYet, MSGBOX_DEFAULT
    release
    end

RivalsHouse_EventScript_NoTownMap::
    msgbox RivalsHouse_Text_NoTownMap, MSGBOX_DEFAULT
    msgbox RivalsHouse_Text_DaisyApology, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_DAISY, Common_Movement_FaceRight
    waitmovement 0
    delay 30
    message RivalsHouse_Text_DaisyThinking
    waitmessage
    delay 96
    closemessage
    playse SE_PIN
    applymovement LOCALID_DAISY, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_DAISY, Common_Movement_FacePlayer
    waitmovement 0
    msgbox RivalsHouse_Text_OfferGroomMons, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_DAISY, Common_Movement_FaceRight
    waitmovement 0
    delay 30
    applymovement LOCALID_DAISY, Common_Movement_FacePlayer
    waitmovement 0
    msgbox RivalsHouse_Text_HeadToViridianForest, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_RIVALS_HOUSE, 2
    release
    end

RivalsHouse_EventScript_HeardBattledRival::
    msgbox RivalsHouse_Text_HeardYouBattledRival, MSGBOX_DEFAULT
    release
    end

RivalsHouse_EventScript_TownMap::
    msgbox RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
    end

RivalsHouse_EventScript_Picture::
    msgbox RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
    end
    
RivalsHouse_Text_HiBrothersAtLab:
    .string "Daisy: Hi, {PLAYER}!\p"
    .string "My brother, {RIVAL}, is out at\n"
    .string "Grandpa's Lab.$"

RivalsHouse_Text_LikeMeToGroomMon:
    .string "Daisy: Hi, {PLAYER}!\n"
    .string "Good timing.\p"
    .string "I'm about to have some tea.\n"
    .string "Would you like to join me?\p"
    .string "Oh, but look.\n"
    .string "Your Pokémon are a little dirty.\p"
    .string "Would you like me to groom one?$"

RivalsHouse_Text_DontNeedAnyGrooming:
    .string "You don't need any grooming done?\n"
    .string "Okay, we'll just have tea.$"

RivalsHouse_Text_GroomWhichOne:
    .string "Which one should I groom?$"

RivalsHouse_Text_LookingNiceInNoTime:
    .string "Daisy: Okay, I'll get it looking\n"
    .string "nice in no time.$"

RivalsHouse_Text_ThereYouGoAllDone:
    .string "{STR_VAR_1} looks dreamily content…\p"
    .string "Daisy: There you go! All done.\n"
    .string "See? Doesn't it look nice?\p"
    .string "Giggle…\n"
    .string "It's such a cute Pokémon.$"

RivalsHouse_Text_CantGroomAnEgg:
    .string "Oh, sorry. I honestly can't\n"
    .string "groom an egg.$"

RivalsHouse_Text_MayISeeFirstMon:
    .string "Daisy: Your Pokémon grow to love\n"
    .string "you if you raise them with love.\p"
    .string "For example, {PLAYER}, may I see\n"
    .string "your first Pokémon?$"

RivalsHouse_Text_AdoresYou:
    .string "It couldn't possibly love you\n"
    .string "any more than it does now.\p"
    .string "Your Pokémon is happy beyond\n"
    .string "words.$"

RivalsHouse_Text_VeryHappy:
    .string "It looks very happy.\p"
    .string "I wish {RIVAL} could see this and\n"
    .string "learn something from it.$"

RivalsHouse_Text_LikesYouQuiteALot:
    .string "It's quite friendly with you.\n"
    .string "Keep being good to it!$"

RivalsHouse_Text_GettingUsedToYou:
    .string "It's warming up to you.\n"
    .string "Trust must be growing between you.$"

RivalsHouse_Text_NotUsedToYou:
    .string "It's not quite familiar with you\n"
    .string "yet.\p"
    .string "Pokémon are all quite wary when\n"
    .string "you first get them.$"

RivalsHouse_Text_VeryWary:
    .string "{PLAYER}, I don't like the way it\n"
    .string "glares at you.\p"
    .string "Could you try being a little nicer\n"
    .string "to it?$"

RivalsHouse_Text_DetestsYou:
    .string "…Um, it's not easy for me to say\n"
    .string "this, but…\p"
    .string "Is there some reason why your\n"
    .string "Pokémon would hate you so much?$"

RivalsHouse_Text_DaisyNotReadyYet::
    .string "Daisy: I'll let you know when\n"
    .string "I'm ready to give massages.$"

RivalsHouse_Text_NoTownMap::
    .string "Daisy: Hi, {PLAYER}!\n"
    .string "How are you?$"
    
RivalsHouse_Text_DaisyApology::
    .string "… … … … … … … …\n"
    .string "… … … … … … … …\p"
    .string "Oh, I'm sorry {PLAYER}.\n"
    .string "{RIVAL} took the only map I had.$"
    
RivalsHouse_Text_DaisyThinking::
    .string "Hmmmmm… … … …$"

RivalsHouse_Text_OfferGroomMons::
    .string "I know!\p"
    .string "I'm learning how to give Pokémon\n"
    .string "massages to increase their happiness.\p"
    .string "When I'm ready, I'll happily give\n"
    .string "your Pokémon free massages!\p"
    .string "It'll be good practice for me too!$"

RivalsHouse_Text_HeadToViridianForest::
    .string "Oh!\n"
    .string "One more thing…\p"
    .string "{RIVAL} mumbled something about\n"
    .string "Viridian Forest while leaving.\l"
    .string "Maybe you should head in that\p"
    .string "direction to start your journey!$"

RivalsHouse_Text_HeardYouBattledRival::
    .string "Daisy: {PLAYER}, I heard you had\n"
    .string "a battle against {RIVAL}.\p"
    .string "I wish I'd seen that!$"

RivalsHouse_Text_ItsBigMapOfKanto::
    .string "It's a big map of the Kanto region.\n"
    .string "Now this would be useful!$"

RivalsHouse_Text_LovelyAndSweetClefairy::
    .string "“The lovely and sweet\n"
    .string "Clefairy”$"
