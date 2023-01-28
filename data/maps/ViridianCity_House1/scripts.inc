ViridianCity_House1_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_BaldingMan::
    msgbox ViridianCity_House1_Text_NicknamingIsFun, MSGBOX_NPC
    end

ViridianCity_House1_EventScript_LittleGirl::
    msgbox ViridianCity_House1_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
    end

ViridianCity_House1_EventScript_Speary::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_SPEAROW, 0
    msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
    waitmoncry
    release
    end

ViridianCity_House1_EventScript_NicknameSign::
    msgbox ViridianCity_House1_Text_SpearowNameSpeary, MSGBOX_SIGN
    end

ViridianCity_House1_Text_NicknamingIsFun::
    .string "Coming up with nicknames is fun,\n"
    .string "but it's not so easy to do.\p"
    .string "Clever names are nice, but simple\n"
    .string "names are easier to remember.$"

ViridianCity_House1_Text_MyDaddyLovesMonsToo::
    .string "My daddy loves Pokémon, too.$"

ViridianCity_House1_Text_Speary::
    .string "Speary: Tetweet!$"

ViridianCity_House1_Text_SpearowNameSpeary::
    .string "Spearow\n"
    .string "Name: Speary$"
