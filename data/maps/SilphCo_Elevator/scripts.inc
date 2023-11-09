SilphCo_Elevator_MapScripts::
	.byte 0

SilphCo_Elevator_EventScript_FloorSelect::
    lockall
    setvar VAR_0x8004, 1
    call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
    copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
    special ShowDeptStoreElevatorFloorSelect
    message gText_WantWhichFloor
    waitmessage
    setvar VAR_0x8004, SCROLL_MULTI_SILPHCO_FLOORS
    specialvar VAR_RESULT, GetDeptStoreDefaultFloorChoice
    special ShowScrollableMultichoice
    waitstate
    switch VAR_RESULT
    case 0, SilphCo_Elevator_EventScript_To11F
    case 1, SilphCo_Elevator_EventScript_To10F
    case 2, SilphCo_Elevator_EventScript_To9F
    case 3, SilphCo_Elevator_EventScript_To8F
    case 4, SilphCo_Elevator_EventScript_To7F
    case 5, SilphCo_Elevator_EventScript_To6F
    case 6, SilphCo_Elevator_EventScript_To5F
    case 7, SilphCo_Elevator_EventScript_To4F
    case 8, SilphCo_Elevator_EventScript_To3F
    case 9, SilphCo_Elevator_EventScript_To2F
    case 10, SilphCo_Elevator_EventScript_To1F
    case 11, SilphCo_Elevator_EventScript_ExitFloorSelect
    case 127, SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To1F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_1F
    setdynamicwarp MAP_SILPH_CO_1F, 255, 22, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To2F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_2F
    setdynamicwarp MAP_SILPH_CO_2F, 255, 22, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To3F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_3F
    setdynamicwarp MAP_SILPH_CO_3F, 255, 22, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To4F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_4F
    setdynamicwarp MAP_SILPH_CO_4F, 255, 22, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To5F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_5F
    setdynamicwarp MAP_SILPH_CO_5F, 255, 22, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To6F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_6F
    setdynamicwarp MAP_SILPH_CO_6F, 255, 20, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_6F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_6F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To7F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_7F
    setdynamicwarp MAP_SILPH_CO_7F, 255, 23, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_7F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_7F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To8F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_8F
    setdynamicwarp MAP_SILPH_CO_8F, 255, 22, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_8F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_8F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To9F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_9F
    setdynamicwarp MAP_SILPH_CO_9F, 255, 24, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_9F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_9F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To10F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_10F
    setdynamicwarp MAP_SILPH_CO_10F, 255, 13, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_10F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_10F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_To11F::
    setvar VAR_0x8006, DEPT_STORE_FLOORNUM_11F
    setdynamicwarp MAP_SILPH_CO_11F, 255, 13, 3
    compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_11F
    goto_if_eq SilphCo_Elevator_EventScript_ExitFloorSelect
    call SilphCo_Elevator_EventScript_MoveElevator
    setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_11F
    goto SilphCo_Elevator_EventScript_ExitFloorSelect
    end

SilphCo_Elevator_EventScript_ExitFloorSelect::
    special CloseDeptStoreElevatorWindow
    releaseall
    end

SilphCo_Elevator_EventScript_MoveElevator::
    special CloseDeptStoreElevatorWindow
    closemessage
    waitse
    special MoveElevator
    waitstate
    setflag FLAG_TEMP_2
    return
