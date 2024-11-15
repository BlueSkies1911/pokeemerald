.equ LOCALID_SELPHY, 1
.equ LOCALID_BUTLER, 2

.equ SHOWN_REQUESTED_MON, FLAG_TEMP_2

ResortGorgeous_House_MapScripts::
	.byte 0

ResortGorgeous_House_EventScript_Selphy::
    lock
    faceplayer
    goto_if_set SHOWN_REQUESTED_MON, ResortGorgeous_House_EventScript_JustFulfilledRequest
    compare VAR_RESORT_GORGEOUS_REQUESTED_MON, 0xFFFF
    goto_if_eq ResortGorgeous_House_EventScript_RequestTookTooLong
    compare VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE
    goto_if_ne ResortGorgeous_House_EventScript_CheckForRequestedMon
    msgbox ResortGorgeous_House_Text_PleaseHearMyWish, MSGBOX_DEFAULT
    goto ResortGorgeous_House_EventScript_RequestMon
    end

ResortGorgeous_House_EventScript_RequestMon::
    special SampleResortGorgeousMonAndReward
    msgbox ResortGorgeous_House_Text_WishToSeeMonPlease, MSGBOX_DEFAULT
    release
    end

ResortGorgeous_House_EventScript_RequestTookTooLong::
    msgbox ResortGorgeous_House_Text_OhImTiredOfWaiting, MSGBOX_DEFAULT
    goto ResortGorgeous_House_EventScript_RequestMon
    end

ResortGorgeous_House_EventScript_CheckForRequestedMon::
    copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
    specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
    compare VAR_RESULT, TRUE
    goto_if_eq ResortGorgeous_House_EventScript_ShowRequestedMon
    goto ResortGorgeous_House_EventScript_RequestMon
    end

ResortGorgeous_House_EventScript_ShowRequestedMon::
    special SampleResortGorgeousMonAndReward
    msgbox ResortGorgeous_House_Text_MonYouCaughtForMeThankYou, MSGBOX_DEFAULT
    addobject LOCALID_BUTLER
    applymovement LOCALID_BUTLER, ResortGorgeous_House_Movement_ButlerEnter
    waitmovement 0
    msgbox ResortGorgeous_House_Text_ButlerYesMyLady, MSGBOX_DEFAULT
    applymovement LOCALID_SELPHY, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox ResortGorgeous_House_Text_SelphyGiveTokenOfAppreciation, MSGBOX_DEFAULT
    msgbox ResortGorgeous_House_Text_ButlerIShallDoAsYouBid, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_NORTH
    call_if_eq ResortGorgeous_House_EventScript_ButlerApproachPlayerNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq ResortGorgeous_House_EventScript_ButlerApproachPlayerSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq ResortGorgeous_House_EventScript_ButlerApproachPlayerEast
    compare VAR_FACING, DIR_WEST
    call_if_eq ResortGorgeous_House_EventScript_ButlerApproachPlayerWest
    copyobjectxytoperm LOCALID_BUTLER
    msgbox ResortGorgeous_House_Text_ButlerPleaseAcceptThisAsHerThanks, MSGBOX_DEFAULT
    giveitem VAR_RESORT_GORGEOUS_REWARD
    compare VAR_RESULT, FALSE
    goto_if_eq ResortGorgeous_House_EventScript_NoRoomForReward
    setflag SHOWN_REQUESTED_MON
    setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE
    release
    end

ResortGorgeous_House_EventScript_ButlerApproachPlayerNorth::
    applymovement LOCALID_SELPHY, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_BUTLER, ResortGorgeous_House_Movement_ButlerApproachPlayerNorth
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    return

ResortGorgeous_House_EventScript_ButlerApproachPlayerSouth::
    applymovement LOCALID_BUTLER, ResortGorgeous_House_Movement_ButlerApproachPlayerSouth
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

ResortGorgeous_House_EventScript_ButlerApproachPlayerEast::
    applymovement LOCALID_SELPHY, Common_Movement_WalkInPlaceFasterLeft
    applymovement LOCALID_BUTLER, ResortGorgeous_House_Movement_ButlerApproachPlayerEast
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

ResortGorgeous_House_EventScript_ButlerApproachPlayerWest::
    applymovement LOCALID_BUTLER, ResortGorgeous_House_Movement_ButlerApproachPlayerWest
    waitmovement 0
    return

ResortGorgeous_House_EventScript_NoRoomForReward::
    msgbox ResortGorgeous_House_Text_ButlerBagAppearsToBeFull, MSGBOX_DEFAULT
    msgbox ResortGorgeous_House_Text_OhHowDisappointing, MSGBOX_DEFAULT
    setflag SHOWN_REQUESTED_MON
    setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE
    release
    end

ResortGorgeous_House_EventScript_JustFulfilledRequest::
    msgbox ResortGorgeous_House_Text_SelphyWishYouBestOfLuck, MSGBOX_DEFAULT
    release
    end

ResortGorgeous_House_Movement_ButlerApproachPlayerNorth::
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_in_place_faster_right
    step_end

ResortGorgeous_House_Movement_ButlerApproachPlayerSouth::
    walk_left
    walk_left
    walk_in_place_faster_down
    step_end

ResortGorgeous_House_Movement_ButlerApproachPlayerEast::
    walk_left
    walk_left
    walk_left
    walk_down
    step_end

@ Very odd. If the player is talking to Selphy facing West, then the player has clipped through the table
@ In this case rather than approach the player the Butler walks up, which clips the Butler into a wall
ResortGorgeous_House_Movement_ButlerApproachPlayerWest::
    walk_up
    step_end

ResortGorgeous_House_Movement_ButlerEnter::
    walk_in_place_down
    step_end

@ Addressed as "Sebastian" but speaks only as "Butler"
ResortGorgeous_House_EventScript_Butler::
    msgbox ResortGorgeous_House_Text_LadySelphySmileHasBrillianceOfSun, MSGBOX_NPC
    end

ResortGorgeous_House_EventScript_PokemonJournal::
    msgbox PokemonJournal_Text_SpecialFeatureBlaine, MSGBOX_SIGN
    end

ResortGorgeous_House_Text_PleaseHearMyWish::
    .string "Selphy: Oh?\n"
    .string "Do I know you from somewhere?\p"
    .string "Oh, but that doesn't matter.\p"
    .string "I am exquisitely bored.\n"
    .string "Please, hear my wish.$"

ResortGorgeous_House_Text_WishToSeeMonPlease::
    .string "I wish to see a Pokémon.\n"
    .string "A darling {STR_VAR_1}.\p"
    .string "I want to see one right away.\n"
    .string "Please, make my wish come true.$"

ResortGorgeous_House_Text_OhImTiredOfWaiting::
    .string "Selphy: Oh, I'm tired of this.\n"
    .string "I'm tired of waiting for you.\p"
    .string "I'll forgive you this time, but\n"
    .string "please don't fail me next time.$"

ResortGorgeous_House_Text_MonYouCaughtForMeThankYou::
    .string "Selphy: Oh, hello, there.\p"
    .string "Oh, my gracious. That must be the\n"
    .string "{STR_VAR_1} you caught for me.\p"
    .string "Giggle…\n"
    .string "I see a resemblance to you.\p"
    .string "Thank you so kindly.\p"
    .string "… …  … …  … …\n"
    .string "Is something the matter?\p"
    .string "You may leave.\p"
    .string "… …  … …  … …\n"
    .string "Oh, fine. I understand now.\p"
    .string "Sebastian!\n"
    .string "I need you here this instant!$"

ResortGorgeous_House_Text_ButlerYesMyLady::
    .string "Butler: Yes, my lady.$"

ResortGorgeous_House_Text_SelphyGiveTokenOfAppreciation::
    .string "Selphy: See to it that this person\n"
    .string "is given a token of appreciation.$"

ResortGorgeous_House_Text_ButlerIShallDoAsYouBid::
    .string "Butler: I shall do as you bid,\n"
    .string "my lady.$"

ResortGorgeous_House_Text_ButlerPleaseAcceptThisAsHerThanks::
    .string "Butler: I sincerely thank you for\n"
    .string "pleasing Lady Selphy.\p"
    .string "Please accept this as her thanks…$"

ResortGorgeous_House_Text_ButlerBagAppearsToBeFull::
    .string "Butler: Your bag appears to be\n"
    .string "unfortunately full.$"

ResortGorgeous_House_Text_OhHowDisappointing::
    .string "Oh…\n"
    .string "How disappointing.$"

ResortGorgeous_House_Text_SelphyWishYouBestOfLuck::
    .string "Selphy: I wish you the best of\n"
    .string "luck.$"

ResortGorgeous_House_Text_LadySelphySmileHasBrillianceOfSun::
    .string "Butler: The smile of Lady Selphy\n"
    .string "has the brilliance of the sun.\p"
    .string "Please, I beg you to bring joy\n"
    .string "to Lady Selphy.$"

PokemonJournal_Text_SpecialFeatureBlaine::
    .string "Pokémon Journal\p"
    .string "Special Feature: Cinnabar Gym\n"
    .string "Leader Blaine!\p"
    .string "Blaine is said to remove his dark\n"
    .string "shades only when he is thinking up\l"
    .string "new quiz questions.$"
