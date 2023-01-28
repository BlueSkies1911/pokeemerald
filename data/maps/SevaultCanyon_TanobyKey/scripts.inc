.set LOCALID_BOULDER1, 1
.set LOCALID_BOULDER2, 2
.set LOCALID_BOULDER3, 3
.set LOCALID_BOULDER4, 4
.set LOCALID_BOULDER5, 5
.set LOCALID_BOULDER6, 6
.set LOCALID_BOULDER7, 7

.equ NUM_SWITCHES_PRESSED, VAR_TEMP_8

SevaultCanyon_TanobyKey_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SevaultCanyon_TanobyKey_OnTransition
    .byte 0

SevaultCanyon_TanobyKey_OnTransition:
    setflag FLAG_WORLD_MAP_SEVAULT_CANYON_TANOBY_KEY
    call_if_set FLAG_SYS_UNLOCKED_TANOBY_RUINS, SevaultCanyon_TanobyKey_EventScript_MoveBouldersToSolvedPos
    setvar VAR_TEMP_1, 0
    setvar VAR_TEMP_2, 0
    setvar VAR_TEMP_3, 0
    setvar VAR_TEMP_4, 0
    setvar VAR_TEMP_5, 0
    setvar VAR_TEMP_6, 0
    setvar VAR_TEMP_7, 0
    setvar NUM_SWITCHES_PRESSED, 0
    end

SevaultCanyon_TanobyKey_EventScript_MoveBouldersToSolvedPos::
    setobjectxyperm LOCALID_BOULDER1, 7, 2
    setobjectxyperm LOCALID_BOULDER2, 4, 4
    setobjectxyperm LOCALID_BOULDER3, 10, 4
    setobjectxyperm LOCALID_BOULDER4, 5, 6
    setobjectxyperm LOCALID_BOULDER5, 9, 6
    setobjectxyperm LOCALID_BOULDER6, 5, 8
    setobjectxyperm LOCALID_BOULDER7, 9, 8
    return

SevaultCanyon_TanobyKey_EventScript_Switch1::
    lockall
    compare VAR_TEMP_1, 100
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_SwitchAlreadyPressed
    call SevaultCanyon_TanobyKey_EventScript_SwitchPressed
    setvar VAR_TEMP_1, 100
    compare NUM_SWITCHES_PRESSED, 7
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_PuzzleSolved
    releaseall
    end

SevaultCanyon_TanobyKey_EventScript_Switch2::
    lockall
    compare VAR_TEMP_2, 100
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_SwitchAlreadyPressed
    call SevaultCanyon_TanobyKey_EventScript_SwitchPressed
    setvar VAR_TEMP_2, 100
    compare NUM_SWITCHES_PRESSED, 7
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_PuzzleSolved
    releaseall
    end

SevaultCanyon_TanobyKey_EventScript_Switch3::
    lockall
    compare VAR_TEMP_3, 100
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_SwitchAlreadyPressed
    call SevaultCanyon_TanobyKey_EventScript_SwitchPressed
    setvar VAR_TEMP_3, 100
    compare NUM_SWITCHES_PRESSED, 7
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_PuzzleSolved
    releaseall
    end

SevaultCanyon_TanobyKey_EventScript_Switch4::
    lockall
    compare VAR_TEMP_4, 100
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_SwitchAlreadyPressed
    call SevaultCanyon_TanobyKey_EventScript_SwitchPressed
    setvar VAR_TEMP_4, 100
    compare NUM_SWITCHES_PRESSED, 7
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_PuzzleSolved
    releaseall
    end

SevaultCanyon_TanobyKey_EventScript_Switch5::
    lockall
    compare VAR_TEMP_5, 100
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_SwitchAlreadyPressed
    call SevaultCanyon_TanobyKey_EventScript_SwitchPressed
    setvar VAR_TEMP_5, 100
    compare NUM_SWITCHES_PRESSED, 7
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_PuzzleSolved
    releaseall
    end

SevaultCanyon_TanobyKey_EventScript_Switch6::
    lockall
    compare VAR_TEMP_6, 100
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_SwitchAlreadyPressed
    call SevaultCanyon_TanobyKey_EventScript_SwitchPressed
    setvar VAR_TEMP_6, 100
    compare NUM_SWITCHES_PRESSED, 7
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_PuzzleSolved
    releaseall
    end

SevaultCanyon_TanobyKey_EventScript_Switch7::
    lockall
    compare VAR_TEMP_7, 100
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_SwitchAlreadyPressed
    call SevaultCanyon_TanobyKey_EventScript_SwitchPressed
    setvar VAR_TEMP_7, 100
    compare NUM_SWITCHES_PRESSED, 7
    goto_if_eq SevaultCanyon_TanobyKey_EventScript_PuzzleSolved
    releaseall
    end

SevaultCanyon_TanobyKey_EventScript_SwitchPressed::
    addvar NUM_SWITCHES_PRESSED, 1
    playse SE_TRUCK_MOVE
    setvar VAR_0x8004, 1
    setvar VAR_0x8005, 1
    setvar VAR_0x8006, 8
    setvar VAR_0x8007, 3
    special ShakeCamera
    delay 60
    return

SevaultCanyon_TanobyKey_EventScript_PuzzleSolvedShakeScreen::
    setvar VAR_0x8004, 2
    setvar VAR_0x8005, 2
    setvar VAR_0x8006, 10
    setvar VAR_0x8007, 3
    special ShakeCamera
    delay 60
    setvar VAR_0x8004, 3
    setvar VAR_0x8005, 3
    setvar VAR_0x8006, 12
    setvar VAR_0x8007, 2
    special ShakeCamera
    delay 60
    playse SE_LAVARIDGE_FALL_WARP
    waitse
    return

SevaultCanyon_TanobyKey_EventScript_SwitchAlreadyPressed::
    releaseall
    end

SevaultCanyon_TanobyKey_EventScript_PuzzleSolved::
    call SevaultCanyon_TanobyKey_EventScript_PuzzleSolvedShakeScreen
    msgbox SevaultCanyon_TanobyKey_Text_MysteriousRumbleFarAway, MSGBOX_DEFAULT
    setflag FLAG_SYS_UNLOCKED_TANOBY_RUINS
    releaseall
    end

SevaultCanyon_TanobyKey_Text_MysteriousRumbleFarAway::
    .string "A mysterious rumble echoed\n"
    .string "somewhere far away.$"
