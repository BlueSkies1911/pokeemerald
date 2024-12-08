SixIsland_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_OnTransition
    .byte 0

SixIsland_OnTransition:
    setflag FLAG_WORLD_MAP_SIX_ISLAND
    end

SixIsland_EventScript_Hiker::
    msgbox SixIsland_Text_ThatWayToWaterPathRuinValley, MSGBOX_NPC
    end

SixIsland_EventScript_Boy::
    msgbox SixIsland_Text_SkyAtNightIsFantastic, MSGBOX_NPC
    end

SixIsland_EventScript_IslandSign::
    msgbox SixIsland_Text_IslandSign, MSGBOX_SIGN
    end

SixIsland_Text_IslandSign::
    .string "Six Island\n"
    .string "Fortune Island of Aged Wisdom$"

SixIsland_Text_ThatWayToWaterPathRuinValley::
    .string "Keep going this way and you'll get\n"
    .string "to the Water Path.\p"
    .string "Stay on that and you'll get to\n"
    .string "the Ruin Valley.$"

SixIsland_Text_SkyAtNightIsFantastic::
    .string "When you're this far away from the\n"
    .string "city, the sky at night is fantastic.$"
