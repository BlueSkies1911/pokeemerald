.equ LOCALID_SELPHY, 8

ResortGorgeous_MapScripts:: @ 81687E4
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ResortGorgeous_OnWarp
    map_script MAP_SCRIPT_ON_FRAME_TABLE, ResortGorgeous_OnFrame
    .byte 0

ResortGorgeous_OnWarp:
    map_script_2 VAR_MAP_SCENE_RESORT_GORGEOUS, 1, ResortGorgeous_EventScript_TurnPlayerNorth
    .2byte 0

ResortGorgeous_EventScript_TurnPlayerNorth::
    turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
    end

ResortGorgeous_OnFrame:
    map_script_2 VAR_MAP_SCENE_RESORT_GORGEOUS, 1, ResortGorgeous_EventScript_SelphyReturnHomeScene
    .2byte 0

ResortGorgeous_EventScript_SelphyReturnHomeScene::
    lockall
    msgbox ResortGorgeous_Text_SelphyThanksYouMayGoNow, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_SELPHY, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    opendoor 39, 8
    waitdooranim
    applymovement LOCALID_SELPHY, ResortGorgeous_Movement_SelphyEnterHome
    waitmovement 0
    closedoor 39, 8
    waitdooranim
    removeobject LOCALID_SELPHY
    clearflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
    setvar VAR_MAP_SCENE_RESORT_GORGEOUS, 2
    releaseall
    end

ResortGorgeous_Movement_SelphyEnterHome::
    walk_up
    set_invisible
    step_end

ResortGorgeous_EventScript_Daisy::
	trainerbattle_single TRAINER_PAINTER_DAISY, ResortGorgeous_Text_DaisyIntro, ResortGorgeous_Text_DaisyDefeat
	msgbox ResortGorgeous_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

ResortGorgeous_EventScript_Celina::
	trainerbattle_single TRAINER_PAINTER_CELINA, ResortGorgeous_Text_CelinaIntro, ResortGorgeous_Text_CelinaDefeat
	msgbox ResortGorgeous_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
	end

ResortGorgeous_EventScript_Rayna::
	trainerbattle_single TRAINER_PAINTER_RAYNA, ResortGorgeous_Text_RaynaIntro, ResortGorgeous_Text_RaynaDefeat, ResortGorgeous_EventScript_RegisterRayna
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq ResortGorgeous_EventScript_RaynaRematch
	msgbox ResortGorgeous_Text_RaynaPostBattle, MSGBOX_AUTOCLOSE
	end

ResortGorgeous_EventScript_RegisterRayna::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox ResortGorgeous_Text_RaynaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PAINTER_RAYNA
	release
	end

ResortGorgeous_EventScript_RaynaRematch::
	trainerbattle_rematch TRAINER_PAINTER_RAYNA, ResortGorgeous_Text_RaynaRematchIntro, ResortGorgeous_Text_RaynaDefeat
	msgbox ResortGorgeous_Text_RaynaPostBattle, MSGBOX_AUTOCLOSE
	end

ResortGorgeous_EventScript_Jacki::
	trainerbattle_single TRAINER_LADY_JACKI, ResortGorgeous_Text_JackiIntro, ResortGorgeous_Text_JackiDefeat
	msgbox ResortGorgeous_Text_JackiPostBattle, MSGBOX_AUTOCLOSE
	end

ResortGorgeous_EventScript_Gillian::
	trainerbattle_single TRAINER_LADY_GILLIAN, ResortGorgeous_Text_GillianIntro, ResortGorgeous_Text_GillianDefeat
	msgbox ResortGorgeous_Text_GillianPostBattle, MSGBOX_AUTOCLOSE
	end

ResortGorgeous_EventScript_Destin::
	trainerbattle_single TRAINER_YOUNGSTER_DESTIN, ResortGorgeous_Text_DestinIntro, ResortGorgeous_Text_DestinDefeat, ResortGorgeous_EventScript_RegisterDestin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq ResortGorgeous_EventScript_DestinRematch
	msgbox ResortGorgeous_Text_DestinPostBattle, MSGBOX_AUTOCLOSE
	end

ResortGorgeous_EventScript_RegisterDestin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox ResortGorgeous_Text_DestinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_YOUNGSTER_DESTIN
	release
	end

ResortGorgeous_EventScript_DestinRematch::
	trainerbattle_rematch TRAINER_YOUNGSTER_DESTIN, ResortGorgeous_Text_DestinRematchIntro, ResortGorgeous_Text_DestinDefeat
	msgbox ResortGorgeous_Text_DestinPostBattle, MSGBOX_AUTOCLOSE
	end

ResortGorgeous_EventScript_Toby::
	trainerbattle_single TRAINER_SWIMMER_MALE_TOBY, ResortGorgeous_Text_TobyIntro, ResortGorgeous_Text_TobyDefeat
	msgbox ResortGorgeous_Text_TobyPostBattle, MSGBOX_AUTOCLOSE
	end

ResortGorgeous_EventScript_SelphysHouseSign::
    msgbox ResortGorgeous_Text_SelphysHouse, MSGBOX_SIGN
    end

ResortGorgeous_Text_SelphyThanksYouMayGoNow::
    .string "Selphy: Thank you.\p"
    .string "You may go now.$"

ResortGorgeous_Text_SelphysHouse::
    .string "Selphy's House$"
