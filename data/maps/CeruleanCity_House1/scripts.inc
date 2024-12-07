CeruleanCity_House1_MapScripts::
	.byte 0

CeruleanCity_House1_EventScript_BadgeGuy::
    lock
    faceplayer
    msgbox CeruleanCity_House1_Text_BadgesHaveAmazingSecrets, MSGBOX_DEFAULT
    message CeruleanCity_House1_Text_DescribeWhichBadge
    waitmessage
    setvar VAR_0x8004, SCROLL_MULTI_BADGES
    special ShowScrollableMultichoice
    waitstate
    switch VAR_RESULT
    case 0, CeruleanCity_House1_EventScript_DescribeBoulderBadge
    case 1, CeruleanCity_House1_EventScript_DescribeCascadeBadge
    case 2, CeruleanCity_House1_EventScript_DescribeThunderBadge
    case 3, CeruleanCity_House1_EventScript_DescribeRainbowBadge
    case 4, CeruleanCity_House1_EventScript_DescribeSoulBadge
    case 5, CeruleanCity_House1_EventScript_DescribeMarshBadge
    case 6, CeruleanCity_House1_EventScript_DescribeVolcanoBadge
    case 7, CeruleanCity_House1_EventScript_DescribeEarthBadge
    case 8, CeruleanCity_House1_EventScript_StopDescribingBadges
    case MULTI_B_PRESSED, CeruleanCity_House1_EventScript_StopDescribingBadges
    end

CeruleanCity_House1_EventScript_DescribeAnotherBadge::
    message CeruleanCity_House1_Text_DescribeWhichBadge
    waitmessage
    special ShowScrollableMultichoice
    waitstate
    switch VAR_RESULT
    case 0, CeruleanCity_House1_EventScript_DescribeBoulderBadge
    case 1, CeruleanCity_House1_EventScript_DescribeCascadeBadge
    case 2, CeruleanCity_House1_EventScript_DescribeThunderBadge
    case 3, CeruleanCity_House1_EventScript_DescribeRainbowBadge
    case 4, CeruleanCity_House1_EventScript_DescribeSoulBadge
    case 5, CeruleanCity_House1_EventScript_DescribeMarshBadge
    case 6, CeruleanCity_House1_EventScript_DescribeVolcanoBadge
    case 7, CeruleanCity_House1_EventScript_DescribeEarthBadge
    case 8, CeruleanCity_House1_EventScript_StopDescribingBadges
    case MULTI_B_PRESSED, CeruleanCity_House1_EventScript_StopDescribingBadges
    end

CeruleanCity_House1_EventScript_DescribeBoulderBadge::
    msgbox CeruleanCity_House1_Text_AttackStatFlash, MSGBOX_DEFAULT
    goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
    end

CeruleanCity_House1_EventScript_DescribeCascadeBadge::
    msgbox CeruleanCity_House1_Text_ObeyLv30Cut, MSGBOX_DEFAULT
    goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
    end

CeruleanCity_House1_EventScript_DescribeThunderBadge::
    msgbox CeruleanCity_House1_Text_SpeedStatRockSmash, MSGBOX_DEFAULT
    goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
    end

CeruleanCity_House1_EventScript_DescribeRainbowBadge::
    msgbox CeruleanCity_House1_Text_ObeyLv50Strength, MSGBOX_DEFAULT
    goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
    end

CeruleanCity_House1_EventScript_DescribeSoulBadge::
    msgbox CeruleanCity_House1_Text_DefenseStatSurf, MSGBOX_DEFAULT
    goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
    end

CeruleanCity_House1_EventScript_DescribeMarshBadge::
    msgbox CeruleanCity_House1_Text_ObeyLv70Teleport, MSGBOX_DEFAULT
    goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
    end

CeruleanCity_House1_EventScript_DescribeVolcanoBadge::
    msgbox CeruleanCity_House1_Text_SpStatsWaterfall, MSGBOX_DEFAULT
    goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
    end

CeruleanCity_House1_EventScript_DescribeEarthBadge::
    msgbox CeruleanCity_House1_Text_AllMonsWillObeyYou, MSGBOX_DEFAULT
    goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
    end

CeruleanCity_House1_EventScript_StopDescribingBadges::
    msgbox CeruleanCity_House1_Text_ComeVisitAnytime, MSGBOX_DEFAULT
    release
    end

CeruleanCity_House1_Text_BadgesHaveAmazingSecrets::
    .string "Only skilled Trainers can collect\n"
    .string "Pokémon Badges.\p"
    .string "I see you have at least one.\p"
    .string "Those badges have amazing secrets,\n"
    .string "did you know?$"

CeruleanCity_House1_Text_DescribeWhichBadge::
    .string "Now then…\p"
    .string "Which of the eight badges should\n"
    .string "I describe?$"

CeruleanCity_House1_Text_ComeVisitAnytime::
    .string "Come visit me anytime you wish.$"

CeruleanCity_House1_Text_AttackStatFlash::
    .string "The Attack stat of all your\n"
    .string "Pokémon increases a little bit.\p"
    .string "It also lets you use the move\n"
    .string "Flash outside of battle.$"

CeruleanCity_House1_Text_ObeyLv30Cut::
    .string "Pokémon up to Lv. 30 will obey\n"
    .string "you.\p"
    .string "That includes even outsiders you\n"
    .string "obtain in trades.\p"
    .string "Pokémon of higher levels will\n"
    .string "be unruly in battle, however.\p"
    .string "It also lets you use the move\n"
    .string "Cut outside of battle.$"

CeruleanCity_House1_Text_SpeedStatRockSmash::
    .string "The Speed stat of all your\n"
    .string "Pokémon increases a little bit.\p"
    .string "It also lets you use the move\n"
    .string "Rock Smash outside of battle.$"

CeruleanCity_House1_Text_ObeyLv50Strength::
    .string "Pokémon up to Lv. 50 will obey\n"
    .string "you.\p"
    .string "That includes even outsiders you\n"
    .string "obtain in trades.\p"
    .string "Pokémon of higher levels will\n"
    .string "be unruly in battle, however.\p"
    .string "It also lets you use the move\n"
    .string "Strength outside of battle.$"

CeruleanCity_House1_Text_DefenseStatSurf::
    .string "The Defense stat of all your\n"
    .string "Pokémon increases a little bit.\p"
    .string "It also lets you use the move\n"
    .string "Surf outside of battle.$"

CeruleanCity_House1_Text_ObeyLv70Teleport::
    .string "Pokémon up to Lv. 70 will obey\n"
    .string "you.\p"
    .string "That includes even outsiders you\n"
    .string "obtain in trades.\p"
    .string "Pokémon of higher levels will\n"
    .string "be unruly in battle, however.\p"
    .string "It also lets you use the move\n"
    .string "Teleport outside of battle.$"

CeruleanCity_House1_Text_SpStatsWaterfall::
    .string "The Sp. Atk and Sp. Def stats of\n"
    .string "all your Pokémon rise a little bit.\p"
    .string "It also lets you use the move\n"
    .string "Waterfall outside of battle.$"

CeruleanCity_House1_Text_AllMonsWillObeyYou::
    .string "All Pokémon will obey you!$"
