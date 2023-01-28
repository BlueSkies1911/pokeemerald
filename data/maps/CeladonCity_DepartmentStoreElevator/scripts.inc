CeladonCity_DepartmentStoreElevator_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelect::
    lockall
    setvar VAR_0x8004, 0
    call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
    copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
    special ShowDeptStoreElevatorFloorSelect
    message gText_WantWhichFloor
    waitmessage
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, GetDeptStoreDefaultFloorChoice
    switch VAR_RESULT
    case 0, CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom5F
    case 1, CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom4F
    case 2, CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom3F
    case 3, CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom2F
    case 4, CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom1F
    end

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom5F::
    multichoicedefault 0, 0, MULTI_FLOORS, 0, FALSE
    goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
    end

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom4F::
    multichoicedefault 0, 0, MULTI_FLOORS, 1, FALSE
    goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
    end

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom3F::
    multichoicedefault 0, 0, MULTI_FLOORS, 2, FALSE
    goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
    end

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom2F::
    multichoicedefault 0, 0, MULTI_FLOORS, 3, FALSE
    goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
    end

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom1F::
    multichoicedefault 0, 0, MULTI_FLOORS, 4, FALSE
    goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
    end

CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor::
    switch VAR_RESULT
    case 0, CeladonCity_DepartmentStore_Elevator_EventScript_To5F
    case 1, CeladonCity_DepartmentStore_Elevator_EventScript_To4F
    case 2, CeladonCity_DepartmentStore_Elevator_EventScript_To3F
    case 3, CeladonCity_DepartmentStore_Elevator_EventScript_To2F
    case 4, CeladonCity_DepartmentStore_Elevator_EventScript_To1F
    case 5, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    case MULTI_B_PRESSED, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    end

CeladonCity_DepartmentStore_Elevator_EventScript_To1F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_1F
    setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_1F, 6, 1
    goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F
    goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    end

CeladonCity_DepartmentStore_Elevator_EventScript_To2F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_2F
    setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_2F, 6, 1
    goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F
    goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    end

CeladonCity_DepartmentStore_Elevator_EventScript_To3F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_3F
    setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_3F, 6, 1
    goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F
    goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    end

CeladonCity_DepartmentStore_Elevator_EventScript_To4F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_4F
    setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_4F, 6, 1
    goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F
    goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    end

CeladonCity_DepartmentStore_Elevator_EventScript_To5F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_5F
    setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_5F, 6, 1
    goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F
    goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
    end

CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect::
    special CloseDeptStoreElevatorWindow
    release
    end

CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator::
    special CloseDeptStoreElevatorWindow
    closemessage
    waitse
    special MoveElevator
    waitstate
    setflag FLAG_TEMP_2
    return
