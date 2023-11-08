@ Fuchsia Tent

	@ Initialize the Fuchsia Battle Tent challenge
	.macro fuchsiatent_init
	setvar VAR_0x8004, FUCHSIA_TENT_FUNC_INIT
	special CallFuchsiaTentFunction
	.endm

	@ Get the current prize item id
	.macro fuchsiatent_getprize
	setvar VAR_0x8004, FUCHSIA_TENT_FUNC_GET_PRIZE
	special CallFuchsiaTentFunction
	.endm

	@ Unused. Set the prize item to be given
	.macro fuchsiatent_setprize unusedArg:req, itemId:req
	setvar VAR_0x8004, FUCHSIA_TENT_FUNC_SET_PRIZE
	setvar VAR_0x8005, \unusedArg
	setvar VAR_0x8006, \itemId
	special CallFuchsiaTentFunction
	.endm

	@ Unused. Set the opponent trainer and gfx. SetNextBattleTentOpponent is used through tower_setopponent instead
	.macro fuchsiatent_setopponentgfx
	setvar VAR_0x8004, FUCHSIA_TENT_FUNC_SET_OPPONENT_GFX
	special CallFuchsiaTentFunction
	.endm

	@ Buffers the opponents intro speech to STR_VAR_4. Despite being a Fuchsia Tent function, it serves the same purpose for all 3 tents.
	.macro battletent_getopponentintro
	setvar VAR_0x8004, FUCHSIA_TENT_FUNC_GET_OPPONENT_INTRO
	special CallFuchsiaTentFunction
	.endm

	@ Save the game and set the challenge status
	.macro fuchsiatent_save challengeStatus:req
	setvar VAR_0x8004, FUCHSIA_TENT_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallFuchsiaTentFunction
	.endm

	@ Set the prize item as randomly selected from a list. Randomness unnecessary, as the list is only 1 item
	.macro fuchsiatent_setrandomprize
	setvar VAR_0x8004, FUCHSIA_TENT_FUNC_SET_RANDOM_PRIZE
	special CallFuchsiaTentFunction
	.endm

	@ Give the current prize item. FALSE if no room for prize
	.macro fuchsiatent_giveprize
	setvar VAR_0x8004, FUCHSIA_TENT_FUNC_GIVE_PRIZE
	special CallFuchsiaTentFunction
	.endm


@ Saffron Tent

	@ Initialize the Saffron Battle Tent challenge
	.macro saffrontent_init
	setvar VAR_0x8004, SAFFRON_TENT_FUNC_INIT
	special CallSaffronTentFunction
	.endm

	@ Get the current prize item id
	.macro saffrontent_getprize
	setvar VAR_0x8004, SAFFRON_TENT_FUNC_GET_PRIZE
	special CallSaffronTentFunction
	.endm

	@ Unused. Set the prize item to be given
	.macro saffrontent_setprize unusedArg:req, itemId:req
	setvar VAR_0x8004, SAFFRON_TENT_FUNC_SET_PRIZE
	setvar VAR_0x8005, \unusedArg
	setvar VAR_0x8006, \itemId
	special CallSaffronTentFunction
	.endm

	@ Save the game and set the challenge status
	.macro saffrontent_save challengeStatus:req
	setvar VAR_0x8004, SAFFRON_TENT_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallSaffronTentFunction
	.endm

	@ Set the prize item as randomly selected from a list. Randomness unnecessary, as the list is only 1 item
	.macro saffrontent_setrandomprize
	setvar VAR_0x8004, SAFFRON_TENT_FUNC_SET_RANDOM_PRIZE
	special CallSaffronTentFunction
	.endm

	@ Give the current prize item. FALSE if no room for prize
	.macro saffrontent_giveprize
	setvar VAR_0x8004, SAFFRON_TENT_FUNC_GIVE_PRIZE
	special CallSaffronTentFunction
	.endm

	@ Buffer the opponent trainers name to STR_VAR_1
	.macro saffrontent_getopponentname
	setvar VAR_0x8004, SAFFRON_TENT_FUNC_GET_OPPONENT_NAME
	special CallSaffronTentFunction
	.endm


@ Cerulean Tent

	@ Initialize the Cerulean Battle Tent challenge
	.macro ceruleantent_init
	setvar VAR_0x8004, CERULEAN_TENT_FUNC_INIT
	special CallCeruleanTentFunction
	.endm

	@ Get the current prize item id
	.macro ceruleantent_getprize
	setvar VAR_0x8004, CERULEAN_TENT_FUNC_GET_PRIZE
	special CallCeruleanTentFunction
	.endm

	@ Unused. Set the prize item to be given
	.macro ceruleantent_setprize unusedArg:req, itemId:req
	setvar VAR_0x8004, CERULEAN_TENT_FUNC_SET_PRIZE
	setvar VAR_0x8005, \unusedArg
	setvar VAR_0x8006, \itemId
	special CallCeruleanTentFunction
	.endm

	@ Save the game and set the challenge status
	.macro ceruleantent_save challengeStatus:req
	setvar VAR_0x8004, CERULEAN_TENT_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallCeruleanTentFunction
	.endm

	@ Set the prize item as randomly selected from a list. Randomness unnecessary, as the list is only 1 item
	.macro ceruleantent_setrandomprize
	setvar VAR_0x8004, CERULEAN_TENT_FUNC_SET_RANDOM_PRIZE
	special CallCeruleanTentFunction
	.endm

	@ Give the current prize item. FALSE if no room for prize
	.macro ceruleantent_giveprize
	setvar VAR_0x8004, CERULEAN_TENT_FUNC_GIVE_PRIZE
	special CallCeruleanTentFunction
	.endm

	@ Cerulean Tent's version of factory_rentmons
	.macro ceruleantent_rentmons
	setvar VAR_0x8004, CERULEAN_TENT_FUNC_SELECT_RENT_MONS
	special CallCeruleanTentFunction
	.endm

	@ Cerulean Tent's version of factory_swapmons
	.macro ceruleantent_swapmons
	setvar VAR_0x8004, CERULEAN_TENT_FUNC_SWAP_RENT_MONS
	special CallCeruleanTentFunction
	.endm

	@ Cerulean Tent's version of factory_generateopponentmons
	.macro ceruleantent_generateopponentmons
	setvar VAR_0x8004, CERULEAN_TENT_FUNC_GENERATE_OPPONENT_MONS
	special CallCeruleanTentFunction
	.endm

	@ Cerulean Tent's version of factory_generaterentalmons
	.macro ceruleantent_generaterentalmons
	setvar VAR_0x8004, CERULEAN_TENT_FUNC_GENERATE_RENTAL_MONS
	special CallCeruleanTentFunction
	.endm

