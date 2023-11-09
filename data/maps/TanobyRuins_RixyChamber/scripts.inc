TanobyRuins_RixyChamber_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, TanobyRuins_RixyChamber_OnTransition
    .byte 0

TanobyRuins_RixyChamber_OnTransition:
    call EventScript_TryDarkenRuins
    end
