TanobyRuins_MoneanChamber_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, TanobyRuins_MoneanChamber_OnTransition
    .byte 0

TanobyRuins_MoneanChamber_OnTransition:
    setflag FLAG_WORLD_MAP_TANOBY_RUINS_MONEAN_CHAMBER
    call EventScript_TryDarkenRuins
    end
