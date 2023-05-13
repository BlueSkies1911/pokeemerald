TrainerTower_OnResume:
	setvar VAR_TEMP_2, 0
	trainertower_resumetimer
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, TrainerTower_1F_EventScript_Lost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, TrainerTower_1F_EventScript_Lost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, TrainerTower_1F_EventScript_Lost
	end

TrainerTower_OnWarp:
	map_script_2 VAR_TEMP_3, 0, TrainerTower_1F_EventScript_DummyOnWarp
	.2byte 0

TrainerTower_1F_EventScript_DummyOnWarp::
	setvar VAR_TEMP_3, 1
.ifdef BUGFIX
	end  @ Missing end. By chance, the next byte (0x02 of VAR_TEMP_2) is also the id for the end cmd
.endif

TrainerTower_OnFrame:
	map_script_2 VAR_TEMP_2, 0, TrainerTower_1F_EventScript_DummyWarpToEntranceCounter
	map_script_2 VAR_TEMP_1, 1, TrainerTower_Lobby_WarpToEntranceCounter
	.2byte 0

EventScript_TrainerTowerTimer::
	lockall
	trainertower_gettime
	msgbox TrainerTower_Lobby_Text_ChallengeTime, MSGBOX_DEFAULT
	releaseall
	end

TrainerTower_1F_EventScript_DummyWarpToEntranceCounter::
	setvar VAR_TEMP_2, 1
	trainertower_getusingereader
	goto_if_eq VAR_RESULT, TRUE, TrainerTower_1F_EventScript_WarpSilentToEntranceCounter  @ VAR_RESULT always FALSE here
	end

@ Never reached
TrainerTower_1F_EventScript_WarpSilentToEntranceCounter::
	warpsilent MAP_TRAINER_TOWER_LOBBY, 9, 6
	waitstate
	end

TrainerTower_1F_EventScript_Lost::
	trainertower_settrainerflags
	trainertower_lost
	setvar VAR_TEMP_1, 1
	end

TrainerTower_Lobby_WarpToEntranceCounter::
	setvar VAR_TEMP_1, 0
	warp MAP_TRAINER_TOWER_LOBBY, 9, 6
	waitstate
	end

@ TRAINER_SCIENTIST_TAYLOR is an actual Trainer on the SS Tidal, but is used as a placeholder here
TrainerTower_EventScript_TrainerBattle::
    trainerbattle TRAINER_BATTLE_TOWER, TRAINER_SCIENTIST_TAYLOR, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
    trainertower_postbattletext
    waitmessage
    waitbuttonpress
    closemessage
    end

TrainerTower_Lobby_Text_ChallengeTime:
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"
