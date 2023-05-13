	@ Initialize the Trainer Tower challenge and start the timer
	.macro trainertower_start
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_START
	special CallTrainerTowerFunction
	.endm

	@ 0 if not spoken to yet, 1 if spoken to but not received prize, 2 if received prize
	.macro trainertower_getownerstate
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_OWNER_STATE
	special CallTrainerTowerFunction
	.endm

	@ Try to give prize. 0 if given successfully, 1 if no room for prize, 2 if giving prize should be skipped
	.macro trainertower_giveprize
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GIVE_PRIZE
	special CallTrainerTowerFunction
	.endm

	@ Check the final challenge time. 0 if new record, 1 if not, 2 if time has already been checked
	.macro trainertower_finaltime
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_CHECK_FINAL_TIME
	special CallTrainerTowerFunction
	.endm

	@ Resume the timer. Wont resume if owner has been spoken to or max time has been reached
	.macro trainertower_resumetimer
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_RESUME_TIMER
	special CallTrainerTowerFunction
	.endm

	@ Set player lost the challenge (trainerTower.hasLost) to TRUE
	.macro trainertower_lost
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_SET_LOST
	special CallTrainerTowerFunction
	.endm

	@ Get the current challenge status (TRAINER_TOWER_PLAYER_STATUS_*)
	.macro trainertower_getstatus
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_CHALLENGE_STATUS
	special CallTrainerTowerFunction
	.endm

	@ Buffer the current timer to string vars (mins to STR_VAR_1, secs to STR_VAR_2, fraction of sec to STR_VAR_3)
	.macro trainertower_gettime
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_CHALLENGE_TIME
	special CallTrainerTowerFunction
	.endm

	@ FALSE if fewer than all 4 floors used, TRUE otherwise. Only FALSE in JP-exclusive modes
	.macro trainertower_allfloorsused
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_ALL_FLOORS_USED
	special CallTrainerTowerFunction
	.endm

	@ Unknown, dummied. E-Reader association is assumed. Only side effect is setting VAR_RESULT to 0.
	.macro trainertower_getusingereader
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_IN_EREADER_MODE
	special CallTrainerTowerFunction
	.endm

	@ TRUE if currently in a Trainer Tower challenge
	.macro trainertower_inchallenge
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_IN_CHALLENGE
	special CallTrainerTowerFunction
	.endm

	@ Show the post battle text for the spoken to Trainer Tower trainer
	.macro trainertower_postbattletext
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_POST_BATTLE_TEXT
	special CallTrainerTowerFunction
	.endm

	@ Set all Trainer Tower trainers defeated
	.macro trainertower_settrainerflags
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_SET_ALL_TRAINER_FLAGS
	special CallTrainerTowerFunction
	.endm

	@ TRUE if the game has been saved for the challenge, FALSE otherwise
	.macro trainertower_getsaved
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_GAME_SAVED
	special CallTrainerTowerFunction
	.endm

	@ Set that the game has been saved for the challenge
	.macro trainertower_setsaved
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_SET_GAME_SAVED
	special CallTrainerTowerFunction
	.endm

	@ Clear that the game has been saved for the challenge
	.macro trainertower_clearsaved
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_CLEAR_GAME_SAVED
	special CallTrainerTowerFunction
	.endm

	@ FALSE if the Trainer Tower challenge was lost, TRUE otherwise
	.macro trainertower_getwon
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_WON
	special CallTrainerTowerFunction
	.endm

	@ Set the challenge mode to TOWER_MODE_* (Normal, Variety, Unique, or Expert)
	.macro trainertower_setmode mode:req
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_SET_MODE
	copyvar VAR_0x8005, \mode
	special CallTrainerTowerFunction
	.endm
