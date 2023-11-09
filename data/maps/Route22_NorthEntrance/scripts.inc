Route22_NorthEntrance_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route22_NorthEntrance_OnTransition
	.byte 0

Route22_NorthEntrance_OnTransition:
    setflag FLAG_LANDMARK_RECEPTION_GATE
    end

Route22_NorthEntrance_EventScript_BoulderBadgeGuard::
    lock
    faceplayer
    setvar VAR_TEMP_1, 1
    bufferstdstring 0, STDSTRING_BOULDER_BADGE
    goto Route22_NorthEntrance_EventScript_BadgeGuard
    end

Route22_NorthEntrance_EventScript_BoulderBadgeGuardTrigger::
    lockall
    setvar VAR_TEMP_1, 1
    setvar VAR_0x8009, 1
    bufferstdstring 0, STDSTRING_BOULDER_BADGE
    goto Route23_EventScript_BadgeGuardTrigger
    end
