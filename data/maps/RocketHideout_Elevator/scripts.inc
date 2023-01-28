RocketHideout_Elevator_MapScripts::
	.byte 0

RocketHideout_Elevator_EventScript_FloorSelect::
    lockall
    goto_if_unset FLAG_CAN_USE_ROCKET_HIDEOUT_LIFT, RocketHideout_Elevator_EventScript_NeedKey
    setvar VAR_0x8004, 0
    call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
    copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
    special ShowDeptStoreElevatorFloorSelect
    message gText_WantWhichFloor
    waitmessage
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, GetDeptStoreDefaultFloorChoice
    switch VAR_RESULT
    case 0, RocketHideout_Elevator_EventScript_FloorSelectFromB1F
    case 1, RocketHideout_Elevator_EventScript_FloorSelectFromB2F
    case 2, RocketHideout_Elevator_EventScript_FloorSelectFromB4F
    end

RocketHideout_Elevator_EventScript_FloorSelectFromB1F::
    multichoicedefault 0, 0, MULTI_ROCKET_HIDEOUT_ELEVATOR, 0, FALSE
    goto RocketHideout_Elevator_EventScript_ChooseFloor
    end

RocketHideout_Elevator_EventScript_FloorSelectFromB2F::
    multichoicedefault 0, 0, MULTI_ROCKET_HIDEOUT_ELEVATOR, 1, FALSE
    goto RocketHideout_Elevator_EventScript_ChooseFloor
    end

RocketHideout_Elevator_EventScript_FloorSelectFromB4F::
    multichoicedefault 0, 0, MULTI_ROCKET_HIDEOUT_ELEVATOR, 2, FALSE
    goto RocketHideout_Elevator_EventScript_ChooseFloor
    end

RocketHideout_Elevator_EventScript_ChooseFloor::
    switch VAR_RESULT
    case 0, RocketHideout_Elevator_EventScript_ToB1F
    case 1, RocketHideout_Elevator_EventScript_ToB2F
    case 2, RocketHideout_Elevator_EventScript_ToB4F
    case 3, RocketHideout_Elevator_EventScript_ExitFloorSelect
    case MULTI_B_PRESSED, RocketHideout_Elevator_EventScript_ExitFloorSelect
    end

RocketHideout_Elevator_EventScript_ToB1F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_B1F
    setdynamicwarp MAP_ROCKET_HIDEOUT_B1F, 24, 25
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B1F
    goto_if_eq RocketHideout_Elevator_EventScript_ExitFloorSelect
    call RocketHideout_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B1F
    goto RocketHideout_Elevator_EventScript_ExitFloorSelect
    end

RocketHideout_Elevator_EventScript_ToB2F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_B2F
    setdynamicwarp MAP_ROCKET_HIDEOUT_B2F, 28, 16
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B2F
    goto_if_eq RocketHideout_Elevator_EventScript_ExitFloorSelect
    call RocketHideout_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B2F
    goto RocketHideout_Elevator_EventScript_ExitFloorSelect
    end

RocketHideout_Elevator_EventScript_ToB4F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_B4F
    setdynamicwarp MAP_ROCKET_HIDEOUT_B4F, 20, 23
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B4F
    goto_if_eq RocketHideout_Elevator_EventScript_ExitFloorSelect
    call RocketHideout_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_B4F
    goto RocketHideout_Elevator_EventScript_ExitFloorSelect
    end

RocketHideout_Elevator_EventScript_ExitFloorSelect::
    special CloseDeptStoreElevatorWindow
    releaseall
    end

RocketHideout_Elevator_EventScript_MoveElevator::
    special CloseDeptStoreElevatorWindow
    closemessage
    waitse
    special MoveElevator
    waitstate
    setflag FLAG_TEMP_2
    return

RocketHideout_Elevator_EventScript_NeedKey::
    msgbox RocketHideout_Elevator_Text_AppearsToNeedAKey, MSGBOX_DEFAULT
    releaseall
    end

RocketHideout_Elevator_Text_AppearsToNeedAKey::
    .string "It appears to need a key.$"
