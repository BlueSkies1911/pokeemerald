TanobyRuins_DilfordChamber_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, TanobyRuins_DilfordChamber_OnTransition
    .byte 0

TanobyRuins_DilfordChamber_OnTransition:
    call EventScript_TryDarkenRuins
    end
