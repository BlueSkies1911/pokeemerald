Route10_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
    .byte 0

Route10_OnTransition:
	randomweather
    end

Route10_EventScript_Heidi::
    trainerbattle_single TRAINER_PICNICKER_HEIDI, Route10_Text_HeidiIntro, Route10_Text_HeidiDefeat
    msgbox Route10_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
    end

Route10_EventScript_Carol::
    trainerbattle_single TRAINER_PICNICKER_CAROL, Route10_Text_CarolIntro, Route10_Text_CarolDefeat
    msgbox Route10_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
    end

Route10_EventScript_Mark::
    trainerbattle_single TRAINER_POKEMANIAC_MARK, Route10_Text_MarkIntro, Route10_Text_MarkDefeat, Route10_EventScript_RegisterMark
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route10_EventScript_MarkRematch
    msgbox Route10_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
    end

Route10_EventScript_RegisterMark::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route10_Text_MarkRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_POKEMANIAC_MARK
	release
	end

Route10_EventScript_MarkRematch::
    trainerbattle_rematch TRAINER_POKEMANIAC_MARK, Route10_Text_MarkRematchIntro, Route10_Text_MarkDefeat
    msgbox Route10_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
    end

Route10_EventScript_Herman::
    trainerbattle_single TRAINER_POKEMANIAC_HERMAN, Route10_Text_HermanIntro, Route10_Text_HermanDefeat, Route10_EventScript_RegisterHerman
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route10_EventScript_HermanRematch
    msgbox Route10_Text_HermanPostBattle, MSGBOX_AUTOCLOSE
    end

Route10_EventScript_RegisterHerman::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route10_Text_HermanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_POKEMANIAC_HERMAN
	release
	end

Route10_EventScript_HermanRematch::
    trainerbattle_rematch TRAINER_POKEMANIAC_HERMAN, Route10_Text_HermanRematchIntro, Route10_Text_HermanDefeat
    msgbox Route10_Text_HermanPostBattle, MSGBOX_AUTOCLOSE
    end

Route10_EventScript_Clark::
    trainerbattle_single TRAINER_HIKER_CLARK, Route10_Text_ClarkIntro, Route10_Text_ClarkDefeat
    specialvar VAR_RESULT, ShouldTryRematchBattle
    msgbox Route10_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
    end

Route10_EventScript_Trent::
    trainerbattle_single TRAINER_HIKER_TRENT, Route10_Text_TrentIntro, Route10_Text_TrentDefeat, Route10_EventScript_RegisterTrent
    specialvar VAR_RESULT, ShouldTryRematchBattle
    compare VAR_RESULT, TRUE
    goto_if_eq Route10_EventScript_TrentRematch
    msgbox Route10_Text_TrentPostBattle, MSGBOX_AUTOCLOSE
    end

Route10_EventScript_RegisterTrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route10_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HIKER_TRENT
	release
	end

Route10_EventScript_TrentRematch::
    trainerbattle_rematch TRAINER_HIKER_TRENT, Route10_Text_TrentRematchIntro, Route10_Text_TrentDefeat
    msgbox Route10_Text_TrentPostBattle, MSGBOX_AUTOCLOSE
    end

Route10_EventScript_NorthRockTunnelSign::
    msgbox Route10_Text_RockTunnelDetourToLavender, MSGBOX_SIGN
    end

Route10_EventScript_SouthRockTunnelSign::
    msgbox Route10_Text_RockTunnel, MSGBOX_SIGN
    end

Route10_EventScript_PowerPlantSign::
    msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
    end

Route10_Text_RockTunnelDetourToLavender::
    .string "Rock Tunnel\n"
    .string "Detour to Lavender Town$"

Route10_Text_RockTunnel::
    .string "Rock Tunnel$"

Route10_Text_PowerPlant::
    .string "Power Plant$"
