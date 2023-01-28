TanobyRuins_ViapoisChamber_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, TanobyRuins_ViapoisChamber_OnTransition
    .byte 0

TanobyRuins_ViapoisChamber_OnTransition:
    call EventScript_TryDarkenRuins
    end
