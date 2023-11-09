TanobyRuins_MapScripts::
	.byte 0

TanobyRuins_EventScript_Brandon::
    trainerbattle_single TRAINER_RUIN_MANIAC_BRANDON, TanobyRuins_Text_BrandonIntro, TanobyRuins_Text_BrandonDefeat
    msgbox TanobyRuins_Text_BrandonPostBattle, MSGBOX_AUTOCLOSE
    end

TanobyRuins_EventScript_Benjamin::
    trainerbattle_single TRAINER_RUIN_MANIAC_BENJAMIN, TanobyRuins_Text_BenjaminIntro, TanobyRuins_Text_BenjaminDefeat
    msgbox TanobyRuins_Text_BenjaminPostBattle, MSGBOX_AUTOCLOSE
    end

TanobyRuins_EventScript_Edna::
    trainerbattle_single TRAINER_PAINTER_EDNA, TanobyRuins_Text_EdnaIntro, TanobyRuins_Text_EdnaDefeat
    msgbox TanobyRuins_Text_EdnaPostBattle, MSGBOX_AUTOCLOSE
    end

TanobyRuins_EventScript_Clifford::
    trainerbattle_single TRAINER_GENTLEMAN_CLIFFORD, TanobyRuins_Text_CliffordIntro, TanobyRuins_Text_CliffordDefeat
    msgbox TanobyRuins_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
    end
