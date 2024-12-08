Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	.byte 0

Route1_OnTransition:
	randomweather
	end

Route1_EventScript_MartClerk::
    lock
    faceplayer
    goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Route1_EventScript_AlreadyGotPotion
    msgbox Route1_Text_WorkAtPokeMartTakeSample, MSGBOX_DEFAULT
    checkitemspace ITEM_POTION,
    compare VAR_RESULT, FALSE
    goto_if_eq Common_EventScript_BagIsFull
    bufferitemname 1, ITEM_POTION
    giveitem ITEM_POTION
    setflag FLAG_GOT_POTION_ON_ROUTE_1
    release
    end

Route1_EventScript_AlreadyGotPotion::
    msgbox Route1_Text_ComeSeeUsIfYouNeedPokeBalls, MSGBOX_DEFAULT
    release
    end

Route1_EventScript_Boy::
    msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
    end

Route1_EventScript_RouteSign::
    msgbox Route1_Text_RouteSign, MSGBOX_SIGN
    end

Route1_Text_WorkAtPokeMartTakeSample::
    .string "Hi!\n"
    .string "I work at a Pokémon Mart.\p"
    .string "It's part of a convenient chain\n"
    .string "selling all sorts of items.\p"
    .string "Please, visit us in Viridian City.\p"
    .string "I know, I'll give you a sample.\n"
    .string "Here you go!$"

Route1_Text_ComeSeeUsIfYouNeedPokeBalls::
    .string "Please come see us if you need\n"
    .string "Poké Balls for catching Pokémon.$"

Route1_Text_CanJumpFromLedges::
    .string "See those ledges along the road?\p"
    .string "It's a bit scary, but you can jump\n"
    .string "from them.\p"
    .string "You can get back to Pallet Town\n"
    .string "quicker that way.$"

Route1_Text_RouteSign::
    .string "Route 1\n"
    .string "Pallet Town - Viridian City$"


