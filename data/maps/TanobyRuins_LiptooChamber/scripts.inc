TanobyRuins_LiptooChamber_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, TanobyRuins_LiptooChamber_OnTransition
    .byte 0

TanobyRuins_LiptooChamber_OnTransition:
    call EventScript_TryDarkenRuins
    end