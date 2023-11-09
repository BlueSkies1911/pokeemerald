TanobyRuins_WeepthChamber_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, TanobyRuins_WeepthChamber_OnTransition
    .byte 0

TanobyRuins_WeepthChamber_OnTransition:
    call EventScript_TryDarkenRuins
    end
