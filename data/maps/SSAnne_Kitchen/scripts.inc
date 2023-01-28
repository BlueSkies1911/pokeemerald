SSAnne_Kitchen_MapScripts::
	.byte 0

SSAnne_Kitchen_EventScript_Chef1::
    msgbox SSAnne_Kitchen_Text_BusyOutOfTheWay, MSGBOX_NPC
    end

SSAnne_Kitchen_EventScript_Chef2::
    msgbox SSAnne_Kitchen_Text_SawOddBerryInTrash, MSGBOX_NPC
    end

SSAnne_Kitchen_EventScript_Chef3::
    msgbox SSAnne_Kitchen_Text_SoBusyImDizzy, MSGBOX_NPC
    end

SSAnne_Kitchen_EventScript_Chef4::
    lock
    faceplayer
    msgbox SSAnne_Kitchen_Text_IAmLeChefMainCourseIs, MSGBOX_DEFAULT
    random 3
    copyvar VAR_0x8008, VAR_RESULT
    compare VAR_0x8008, 0
    call_if_eq SSAnne_Kitchen_EventScript_SalmonDuSalad
    compare VAR_0x8008, 1
    call_if_eq SSAnne_Kitchen_EventScript_EelsAuBarbecue
    compare VAR_0x8008, 2
    call_if_eq SSAnne_Kitchen_EventScript_PrimeBeefsteak
    release
    end

SSAnne_Kitchen_EventScript_SalmonDuSalad::
    msgbox SSAnne_Kitchen_Text_SalmonDuSalad, MSGBOX_DEFAULT
    return

SSAnne_Kitchen_EventScript_EelsAuBarbecue::
    msgbox SSAnne_Kitchen_Text_EelsAuBarbecue, MSGBOX_DEFAULT
    return

SSAnne_Kitchen_EventScript_PrimeBeefsteak::
    msgbox SSAnne_Kitchen_Text_PrimeBeefsteak, MSGBOX_DEFAULT
    return

SSAnne_Kitchen_EventScript_Chef5::
    msgbox SSAnne_Kitchen_Text_PeelSpudsEveryDay, MSGBOX_NPC
    end

SSAnne_Kitchen_EventScript_Chef6::
    msgbox SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton, MSGBOX_NPC
    end

SSAnne_Kitchen_EventScript_Chef7::
    msgbox SSAnne_Kitchen_Text_OnlyGetToPeelOnions, MSGBOX_NPC
    end

SSAnne_Kitchen_Text_BusyOutOfTheWay::
    .string "You, mon petit!\n"
    .string "We're busy here!\l"
    .string "Out of the way!$"

SSAnne_Kitchen_Text_SawOddBerryInTrash::
    .string "I saw an odd berry in the trash.\n"
    .string "I wonder what that was?$"

SSAnne_Kitchen_Text_SoBusyImDizzy::
    .string "I'm so busy I'm getting dizzy!\n"
    .string "You have to give me room here!$"

SSAnne_Kitchen_Text_PeelSpudsEveryDay::
    .string "Hum-de-hum-de-ho…\p"
    .string "I peel spuds every day!\n"
    .string "Hum-hum…$"

SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton::
    .string "Did you hear about Snorlax?\n"
    .string "It's a glutton.\p"
    .string "No other Pokémon eats and sleeps\n"
    .string "the way Snorlax can and does!$"

SSAnne_Kitchen_Text_OnlyGetToPeelOnions::
    .string "Snivel… Sniff…\p"
    .string "I only get to peel onions…\n"
    .string "Snivel…$"

SSAnne_Kitchen_Text_IAmLeChefMainCourseIs::
    .string "Er-hem!\n"
    .string "Indeed I am le Chef!\p"
    .string "Le main course is$"

SSAnne_Kitchen_Text_SalmonDuSalad::
    .string "Salmon du Salad!\p"
    .string "Les guests may gripe it's fish\n"
    .string "again, however!$"

SSAnne_Kitchen_Text_EelsAuBarbecue::
    .string "Eels au Barbecue!\p"
    .string "Les guests will mutiny, I fear.$"

SSAnne_Kitchen_Text_PrimeBeefsteak::
    .string "Prime Beefsteak!\p"
    .string "But, have I enough fillets du\n"
    .string "beef?$"
