.set LOCALID_ATTENDANT, 1

TrainerTower_Elevator_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_Elevator_OnFrame
	.byte 0

TrainerTower_Elevator_OnFrame:
	map_script_2 VAR_TEMP_4, 0, TrainerTower_Elevator_EventScript_EnterElevator
	.2byte 0

TrainerTower_Elevator_EventScript_Attendant::
	end

TrainerTower_Elevator_EventScript_ExitToRoof::
	applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Elevator_Movement_PlayerExitElevatorToRoof
	waitmovement 0
	releaseall
	warp MAP_TRAINER_TOWER_ROOF, 15, 5
	waitstate
	end

TrainerTower_Elevator_EventScript_EnterElevator::
	applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Elevator_Movement_PlayerApproachAttendant
	waitmovement 0
	applymovement LOCALID_ATTENDANT, TrainerTower_Elevator_Movement_AttendantFacePlayer
	waitmovement 0
	lockall
	msgbox TrainerTower_Elevator_Text_ReturnToReception, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerTower_Elevator_EventScript_ExitToRoof
	releaseall
	applymovement LOCALID_ATTENDANT, TrainerTower_Elevator_Movement_AttendantFaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Elevator_Movement_PlayerMoveToCenterOfElevator
	waitmovement 0
	call TrainerTower_Elevator_EventScript_MoveElevator
	delay 25
	applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Elevator_Movement_PlayerExitElevator
	waitmovement 0
	warp MAP_TRAINER_TOWER_LOBBY, 17, 8
	waitstate
	end

TrainerTower_Elevator_EventScript_MoveElevator::
	waitse
	special MoveElevator
	waitstate
	return

TrainerTower_Elevator_Movement_PlayerMoveToCenterOfElevator:
	walk_up
	walk_up
	walk_right
	face_down
	step_end

TrainerTower_Elevator_Movement_PlayerApproachAttendant:
	delay_16
	walk_left
	step_end

TrainerTower_Elevator_Movement_PlayerExitElevator:
	delay_16
	walk_down
	walk_down
	step_end

TrainerTower_Elevator_Movement_PlayerExitElevatorToRoof:
	face_down
	delay_16
	step_end

TrainerTower_Elevator_Movement_AttendantFacePlayer:
	face_right
	step_end

TrainerTower_Elevator_Movement_AttendantFaceDown:
	face_down
	step_end

TrainerTower_Elevator_Text_ReturnToReception:
	.string "Would you like to return to\n"
	.string "the reception counter?$"
