.set LOCALID_OWNER, 1

PrettyPetalFlowerShop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PrettyPetalFlowerShop_OnTransition
	.byte 0

PrettyPetalFlowerShop_OnTransition:
	setflag FLAG_LANDMARK_FLOWER_SHOP
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, PrettyPetalFlowerShop_EventScript_MoveShopOwner
	goto_if_unset FLAG_BADGE03_GET, PrettyPetalFlowerShop_EventScript_MoveShopOwner
	setflag FLAG_TEMP_1
	end

PrettyPetalFlowerShop_EventScript_MoveShopOwner::
	setobjectxyperm LOCALID_OWNER, 4, 6
	end

PrettyPetalFlowerShop_EventScript_ShopOwner::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, PrettyPetalFlowerShop_EventScript_SellDecorations
	msgbox PrettyPetalFlowerShop_Text_ThisIsPrettyPetalFlowerShop, MSGBOX_DEFAULT
	goto_if_set FLAG_MET_PRETTY_PETAL_SHOP_OWNER, PrettyPetalFlowerShop_EventScript_AlreadyMet
	setflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
	msgbox PrettyPetalFlowerShop_Text_IntroLearnAboutBerries, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PrettyPetalFlowerShop_EventScript_ExplainBerries
	call_if_eq VAR_RESULT, NO, PrettyPetalFlowerShop_EventScript_DontExplainBerries
	release
	end

PrettyPetalFlowerShop_EventScript_AlreadyMet::
	msgbox PrettyPetalFlowerShop_Text_LearnAboutBerries, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PrettyPetalFlowerShop_EventScript_ExplainBerries
	call_if_eq VAR_RESULT, NO, PrettyPetalFlowerShop_EventScript_DontExplainBerries
	release
	end

PrettyPetalFlowerShop_EventScript_ExplainBerries::
	msgbox PrettyPetalFlowerShop_Text_BerriesExplanation, MSGBOX_DEFAULT
	return

PrettyPetalFlowerShop_EventScript_DontExplainBerries::
	msgbox PrettyPetalFlowerShop_Text_FlowersBringHappiness, MSGBOX_DEFAULT
	return

PrettyPetalFlowerShop_EventScript_SellDecorations::
	message gText_PlayerWhatCanIDoForYou
	waitmessage
	pokemartdecoration2 PrettyPetalFlowerShop_Pokemart_Plants
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PrettyPetalFlowerShop_Pokemart_Plants:
	.2byte DECOR_RED_PLANT
	.2byte DECOR_TROPICAL_PLANT
	.2byte DECOR_PRETTY_FLOWERS
	.2byte DECOR_COLORFUL_PLANT
	.2byte DECOR_BIG_PLANT
	.2byte DECOR_GORGEOUS_PLANT
	.2byte DECOR_NONE
	release
	end

PrettyPetalFlowerShop_EventScript_SquirtBottleGirl::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SQUIRT_BOTTLE, PrettyPetalFlowerShop_EventScript_GiveSquirtBottle
	msgbox PrettyPetalFlowerShop_Text_SquirtBottleExplanation, MSGBOX_DEFAULT
	release
	end

PrettyPetalFlowerShop_EventScript_GiveSquirtBottle::
	msgbox PrettyPetalFlowerShop_Text_YouCanHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_SQUIRT_BOTTLE
	msgbox PrettyPetalFlowerShop_Text_SquirtBottleExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_SQUIRT_BOTTLE
	release
	end

PrettyPetalFlowerShop_EventScript_RandomBerryGirl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry
	msgbox PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
	random 8
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
	msgbox PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry::
	msgbox PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

PrettyPetalFlowerShop_Text_ThisIsPrettyPetalFlowerShop:
	.string "Hello!\p"
	.string "This is the Pretty Petal Flower Shop.\n"
	.string "Spreading flowers all over the world!$"

PrettyPetalFlowerShop_Text_LearnAboutBerries:
	.string "{PLAYER}{KUN}, would you like to learn about\n"
	.string "berries?$"

PrettyPetalFlowerShop_Text_IntroLearnAboutBerries:
	.string "Your name is?\p"
	.string "{PLAYER}{KUN}.\n"
	.string "That's a nice name.\p"
	.string "{PLAYER}{KUN}, would you like to learn about\n"
	.string "berries?$"

PrettyPetalFlowerShop_Text_BerriesExplanation:
	.string "Berries grow on trees that thrive\n"
	.string "only in soft, loamy soil.\p"
	.string "If you take some berries, be sure to\n"
	.string "plant one in the loamy soil again.\p"
	.string "A planted berry will soon sprout,\n"
	.string "grow into a plant, flower beautifully,\l"
	.string "then grow berries again.\p"
	.string "I want to see the whole wide world\n"
	.string "filled with beautiful flowers.\l"
	.string "That's my dream.\p"
	.string "Please help me, {PLAYER}{KUN}. Plant berries\n"
	.string "and bring more flowers into the world.$"

PrettyPetalFlowerShop_Text_FlowersBringHappiness:
	.string "Flowers bring so much happiness to\n"
	.string "people, don't they?$"

PrettyPetalFlowerShop_Text_YouCanHaveThis:
	.string "Hello!\p"
	.string "The more attention you give to flowers,\n"
	.string "the more beautifully they bloom.\p"
	.string "You'll like tending flowers. I'm sure\n"
	.string "of it. You can have this.$"

PrettyPetalFlowerShop_Text_SquirtBottleExplanation:
	.string "While berry plants are growing,\n"
	.string "water them with the Squirt Bottle.\p"
	.string "Oh, another thing.\p"
	.string "If you don't pick berries for a while,\n"
	.string "they'll drop off onto the ground.\l"
	.string "But they'll sprout again.\p"
	.string "Isn't that awesome?\n"
	.string "It's like they have the will to live.$"

PrettyPetalFlowerShop_Text_ImGrowingFlowers:
	.string "I'm trying to be like my big sisters.\n"
	.string "I'm growing flowers, too!\p"
	.string "Here you go!\n"
	.string "It's for you!$"

PrettyPetalFlowerShop_Text_MachineMixesBerries:
	.string "You can plant a berry and grow it big,\n"
	.string "or you can make a Pokémon hold it.\p"
	.string "But now they have a machine that mixes\n"
	.string "up different berries and makes candies\l"
	.string "for Pokémon.\p"
	.string "I want some candy, too.$"
