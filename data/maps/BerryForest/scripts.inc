.set LOCALID_LOSTELLE, 1

BerryForest_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, BerryForest_OnTransition
    .byte 0

BerryForest_OnTransition:
    setflag FLAG_WORLD_MAP_BERRY_FOREST
    setescapewarp MAP_BOND_BRIDGE, 255, 12, 6
    end

BerryForest_EventScript_Lostelle::
    lock
    faceplayer
    msgbox BerryForest_Text_HelpScaryPokemon, MSGBOX_DEFAULT
    playse SE_PIN
    applymovement LOCALID_LOSTELLE, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_LOSTELLE, BerryForest_Movement_LostelleLookAround
    waitmovement 0
    msgbox BerryForest_Text_HereItComesAgain, MSGBOX_DEFAULT
    waitse
    playmoncry SPECIES_HYPNO, 2
    waitmoncry
    setwildbattle SPECIES_HYPNO, 30, ITEM_NONE
    dowildbattle
    applymovement LOCALID_LOSTELLE, Common_Movement_FacePlayer
    waitmovement 0
    msgbox BerryForest_Text_ThankYouHaveThis, MSGBOX_DEFAULT
    giveitem ITEM_IAPAPA_BERRY
    compare VAR_RESULT, FALSE
    call_if_eq BerryForest_EventScript_NoRoomForBerry
    special GetPlayerBigGuyGirlString
    msgbox BerryForest_Text_LetsGoHome, MSGBOX_DEFAULT
    closemessage
    setflag FLAG_RESCUED_LOSTELLE
    setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
    setvar VAR_MAP_SCENE_TWO_ISLAND_GAME_CORNER, 2
    clearflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
    warp MAP_TWO_ISLAND_GAME_CORNER, 255, 6, 6
    waitstate
    release
    end

BerryForest_EventScript_NoRoomForBerry::
    msgbox BerryForest_Text_BerryPouchIsFull, MSGBOX_DEFAULT
    return

BerryForest_Movement_LostelleLookAround::
    walk_in_place_faster_left
    delay_16
    walk_in_place_faster_right
    delay_8
    walk_in_place_faster_left
    step_end

BerryForest_EventScript_WelcomeSign::
    msgbox BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
    end

BerryForest_EventScript_BewareSign::
    msgbox BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
    end

BerryForest_Text_HelpScaryPokemon::
    .string "Lostelle: Whimper… Sniff…\n"
    .string "Oh! Please, help!\p"
    .string "A scary Pokémon appeared there\n"
    .string "a little while ago.\p"
    .string "It kept scaring.\n"
    .string "It made Lostelle scared.\p"
    .string "I'm too scared to move!\n"
    .string "But I want to go home…$"

BerryForest_Text_HereItComesAgain::
    .string "Oh! Here it comes again!\n"
    .string "No! Go away! It's scaring me!\p"
    .string "Waaaaaaah!\n"
    .string "I want my daddy!$"

BerryForest_Text_ThankYouHaveThis::
    .string "Ohh! That was so scary!\n"
    .string "Thank you!\p"
    .string "Lostelle came to pick some\n"
    .string "berries.\p"
    .string "You can have this!$"

BerryForest_Text_LetsGoHome::
    .string "What's your name?\p"
    .string "Lostelle's scared, so can I go\n"
    .string "with you to my daddy's house?\p"
    .string "Okay!\n"
    .string "Let's go home!$"

BerryForest_Text_BerryPouchIsFull::
    .string "Your Berry Pouch is full.\n"
    .string "I guess you don't want this.$"

BerryForest_Text_WelcomeToBerryForest::
    .string "Welcome to the Berry Forest\p"
    .string "Be friendly and share berries with\n"
    .string "others and Pokémon.$"

BerryForest_Text_BewareWildBerryLovingMons::
    .string "Beware of wild, berry-loving\n"
    .string "Pokémon!$"

