.set LOCALID_FAT_MAN,   2
.set LOCALID_POLIWRATH, 3

CeladonCity_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
    .byte 0

CeladonCity_OnTransition:
    setflag FLAG_WORLD_MAP_CELADON_CITY
    end

CeladonCity_EventScript_LittleGirl::
    msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
    end

CeladonCity_EventScript_OldMan1::
    lock
    msgbox CeladonCity_Text_GymIsGreatFullOfWomen, MSGBOX_DEFAULT
    release
    end

CeladonCity_EventScript_Woman::
    msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
    end

CeladonCity_EventScript_OldMan2::
    msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
    end

CeladonCity_EventScript_SoftboiledTutor::
    goto EventScript_SoftboiledTutor
    end

CeladonCity_EventScript_FatMan::
    lock
    faceplayer
    msgbox CeladonCity_Text_MyTrustedPalPoliwrath, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

CeladonCity_EventScript_Poliwrath::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_POLIWRATH, 0
    msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
    closemessage
    waitmoncry
    applymovement LOCALID_POLIWRATH, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

CeladonCity_EventScript_RocketGrunt1::
    msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
    end

CeladonCity_EventScript_RocketGrunt2::
    msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
    end

CeladonCity_EventScript_Boy::
    msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
    end

CeladonCity_EventScript_SilphCoScientist::
    msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
    end

CeladonCity_EventScript_TrainerTips1::
    msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
    end

CeladonCity_EventScript_CitySign::
    msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
    end

CeladonCity_EventScript_GymSign::
    msgbox CeladonCity_Text_GymSign, MSGBOX_SIGN
    end

CeladonCity_EventScript_MansionSign::
    msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
    end

CeladonCity_EventScript_DeptStoreSign::
    msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
    end

CeladonCity_EventScript_TrainerTips2::
    msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
    end

CeladonCity_EventScript_PrizeExchangeSign::
    msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
    end

CeladonCity_EventScript_GameCornerSign::
    msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
    end

CeladonCity_Text_GotMyKoffingInCinnabar::
    .string "I got my Koffing in Cinnabar.\p"
    .string "It's usually nice, but it breathes\n"
    .string "poison when it's angry.$"

CeladonCity_Text_GymIsGreatFullOfWomen::
    .string "Heheh! This Gym is great!\n"
    .string "It's full of women!$"

CeladonCity_Text_GameCornerIsBadForCitysImage::
    .string "Celadon takes pride in its efforts\n"
    .string "to keep the city beautiful.\p"
    .string "That's why the new Game Corner is\n"
    .string "bad for our city's image.$"

CeladonCity_Text_BlewItAllAtSlots::
    .string "Moan…\n"
    .string "I blew it all at the slots!\p"
    .string "I knew I should have cashed in my\n"
    .string "Coins for prizes!$"

CeladonCity_Text_MyTrustedPalPoliwrath::
    .string "This is my trusted pal, Poliwrath.\p"
    .string "It evolved from a Poliwhirl when\n"
    .string "I used a Water Stone.$"

CeladonCity_Text_Poliwrath::
    .string "Poliwrath: Ribi ribit!$"

CeladonCity_Text_GetLostOrIllPunchYou::
    .string "What are you staring at?\n"
    .string "Get lost, or I'll punch you.$"

CeladonCity_Text_KeepOutOfTeamRocketsWay::
    .string "Keep out of Team Rocket's way!$"

CeladonCity_Text_ScaldedTongueOnTea::
    .string "Aaaagh, ow…\n"
    .string "I scalded my tongue!\p"
    .string "This nice old lady in the Mansion\n"
    .string "gave me some Tea.\p"
    .string "But it was boiling hot!\n"
    .string "Gotta cool it to drink it.$"

CeladonCity_Text_SomeoneStoleSilphScope::
    .string "Oh, what am I to do…\p"
    .string "Someone stole our Silph Scope.\p"
    .string "The thief came running this way,\n"
    .string "I'm sure of it.\p"
    .string "But I lost sight of him!\n"
    .string "Where'd he go?$"

CeladonCity_Text_ExplainXAccuracyDireHit::
    .string "Trainer Tips\p"
    .string "X Accuracy boosts the accuracy of\n"
    .string "techniques.\p"
    .string "Dire Hit jacks up the likelihood\n"
    .string "of critical hits.\p"
    .string "Get your items at the Celadon\n"
    .string "Dept. Store!$"

CeladonCity_Text_CitySign::
    .string "CELADON CITY\n"
    .string "The City of Rainbow Dreams$"

CeladonCity_Text_GymSign::
    .string "Celadon City Pokémon Gym\n"
    .string "Leader: Erika\l"
    .string "The Nature-Loving Princess!$"

CeladonCity_Text_MansionSign::
    .string "Celadon Mansion$"

CeladonCity_Text_DeptStoreSign::
    .string "Find what you need at the\n"
    .string "Celadon Dept. Store!$"

CeladonCity_Text_GuardSpecProtectsFromStatus::
    .string "Trainer Tips\p"
    .string "Guard Spec. protects Pokémon\n"
    .string "from status-reduction moves during\l"
    .string "battle.\p"
    .string "Get your items at the\n"
    .string "Celadon Dept. Store!$"

CeladonCity_Text_PrizeExchangeSign::
    .string "Prize Exchange\n"
    .string "Coins exchanged for prizes!$"

CeladonCity_Text_GameCornerSign::
    .string "Rocket Game Corner\n"
    .string "The playground for grown-ups!$"
