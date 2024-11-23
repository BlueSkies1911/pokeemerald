.equ LOCALID_KARATE_MASTER,   5
.equ LOCALID_HITMONLEE_BALL,  6
.equ LOCALID_HITMONCHAN_BALL, 7

SaffronCity_Dojo_MapScripts::
    .byte 0

SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
    lockall
    setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
    applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    releaseall
    end

SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
    lockall
    setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
    applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    releaseall
    end

SaffronCity_Dojo_EventScript_HitmonleeBall::
    lock
    faceplayer
    goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
    showmonpic SPECIES_HITMONLEE, 10, 3
    setvar VAR_TEMP_1, SPECIES_HITMONLEE
    applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon
    hidemonpic
    release
    end

SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
    msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy, MSGBOX_DEFAULT
    release
    end

SaffronCity_Dojo_EventScript_HitmonchanBall::
    lock
    faceplayer
    goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
    showmonpic SPECIES_HITMONCHAN, 10, 3
    setvar VAR_TEMP_1, SPECIES_HITMONCHAN
    applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon
    hidemonpic
    release
    end

SaffronCity_Dojo_EventScript_GiveHitmon::
    hidemonpic
    givemon VAR_TEMP_1, 25, ITEM_NONE
    compare VAR_RESULT, 0
    goto_if_eq SaffronCity_Dojo_EventScript_ReceivedHitmonParty
    compare VAR_RESULT, 1
    goto_if_eq SaffronCity_Dojo_EventScript_ReceivedHitmonPC
    compare VAR_RESULT, 2
    goto_if_eq Common_EventScript_NoMoreRoomForPokemon
    release
    end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
    removeobject VAR_LAST_TALKED
    bufferspeciesname 0, VAR_TEMP_1
    playfanfare MUS_LEVEL_UP
    message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
    waitmessage
    waitfanfare
    setflag FLAG_GOT_HITMON_FROM_DOJO
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SaffronCity_Dojo_EventScript_EndGiveMon
    call Common_EventScript_GetGiftMonPartySlot
    call Common_EventScript_NameReceivedPartyMon
    goto SaffronCity_Dojo_EventScript_EndGiveMon
    end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
    removeobject VAR_LAST_TALKED
    bufferspeciesname 0, VAR_TEMP_1
    playfanfare MUS_LEVEL_UP
    message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
    waitmessage
    waitfanfare
    setflag FLAG_GOT_HITMON_FROM_DOJO
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SaffronCity_Dojo_EventScript_TransferredHitmonToPC
    call Common_EventScript_NameReceivedBoxMon
    goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
    end

SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
    call Common_EventScript_TransferredToPC
    goto SaffronCity_Dojo_EventScript_EndGiveMon
    end

SaffronCity_Dojo_EventScript_EndGiveMon::
    release
    end

SaffronCity_Dojo_EventScript_Statue::
    msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
    end

SaffronCity_Dojo_EventScript_LeftScroll::
    msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
    end

SaffronCity_Dojo_EventScript_RightScroll::
    msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
    end

SaffronCity_Dojo_EventScript_Hitoshi::
    trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
    msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Dojo_EventScript_Hideki::
    trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
    msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Dojo_EventScript_Aaron::
    trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
    msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Dojo_EventScript_Mike::
    trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
    msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
    end

SaffronCity_Dojo_EventScript_MasterKoichi::
    trainerbattle_single TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
    goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
    msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
    end

SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon::
    goto_if_set FLAG_GIVE_SECOND_HITMON, SaffronCity_Dojo_EventScript_KarateMasterGiveHitmonBegin
    msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs, MSGBOX_DEFAULT
    release
    end

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
    setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
    release
    end

SaffronCity_Dojo_EventScript_KarateMasterGiveHitmonBegin::
    msgbox SaffronCity_Dojo_Text_CongratsOnBecomingChampion, MSGBOX_DEFAULT
    goto_if_set FLAG_HIDE_DOJO_HITMONLEE_BALL, SaffronCity_Dojo_EventScript_GiveHitmonchan
    goto_if_set FLAG_HIDE_DOJO_HITMONCHAN_BALL, SaffronCity_Dojo_EventScript_GiveHitmonlee
    end

SaffronCity_Dojo_EventScript_GiveHitmonchan::
    removeobject LOCALID_HITMONCHAN_BALL
    setvar VAR_TEMP_1, SPECIES_HITMONCHAN
    goto SaffronCity_Dojo_EventScript_KarateMasterGiveHitmonEnd
    end

SaffronCity_Dojo_EventScript_GiveHitmonlee::
    removeobject LOCALID_HITMONLEE_BALL
    setvar VAR_TEMP_1, SPECIES_HITMONLEE
    goto SaffronCity_Dojo_EventScript_KarateMasterGiveHitmonEnd
    end

SaffronCity_Dojo_EventScript_KarateMasterGiveHitmonEnd::
    givemon VAR_TEMP_1, 25, ITEM_NONE
    compare VAR_RESULT, 0
    goto_if_eq SaffronCity_Dojo_EventScript_ReceivedSecondHitmonParty
    compare VAR_RESULT, 1
    goto_if_eq SaffronCity_Dojo_EventScript_ReceivedSecondHitmonPC
    compare VAR_RESULT, 2
    goto_if_eq Common_EventScript_NoMoreRoomForPokemon
    release
    end

SaffronCity_Dojo_EventScript_ReceivedSecondHitmonParty::
    bufferspeciesname 0, VAR_TEMP_1
    playfanfare MUS_LEVEL_UP
    message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
    waitmessage
    waitfanfare
    clearflag FLAG_GIVE_SECOND_HITMON
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SaffronCity_Dojo_EventScript_EndGiveMon
    call Common_EventScript_GetGiftMonPartySlot
    call Common_EventScript_NameReceivedPartyMon
    goto SaffronCity_Dojo_EventScript_EndGiveMon
    end

SaffronCity_Dojo_EventScript_ReceivedSecondHitmonPC::
    bufferspeciesname 0, VAR_TEMP_1
    playfanfare MUS_LEVEL_UP
    message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
    waitmessage
    waitfanfare
    clearflag FLAG_GIVE_SECOND_HITMON
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SaffronCity_Dojo_EventScript_TransferredHitmonToPC
    call Common_EventScript_NameReceivedBoxMon
    goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
    end

SaffronCity_Dojo_EventScript_KoichiCall::
    lockall
    pokenavcall SaffronCity_Dojo_Text_KoichiCall
    waitmessage
    clearflag FLAG_ENABLE_KOICHI_CALL
    setflag FLAG_GIVE_SECOND_HITMON
    releaseall
    end

SaffronCity_Dojo_Text_MasterKoichiIntro::
    .string "Grunt!\p"
    .string "I am the Karate Master!\n"
    .string "I am the Leader here!\p"
    .string "You wish to challenge us?\n"
    .string "Expect no mercy!\p"
    .string "Fwaaa!$"

SaffronCity_Dojo_Text_MasterKoichiDefeat::
    .string "Hwa!\n"
    .string "Arrgh! Beaten!$"

SaffronCity_Dojo_Text_ChoosePrizedFightingMon::
    .string "Indeed, I have lost!\p"
    .string "But, I beseech you, do not take\n"
    .string "our emblem as your trophy!\p"
    .string "In return, I will give you a prized\n"
    .string "Fighting Pokémon!\p"
    .string "Choose whichever one you like!$"

SaffronCity_Dojo_Text_StayAndTrainWithUs::
    .string "Grunt!\n"
    .string "Stay and train at karate with us!$"

SaffronCity_Dojo_Text_CongratsOnBecomingChampion::
    .string "Fwaaa! {PLAYER}!\p"
    .string "Congratulations on becoming\n"
    .string "the Pokémon Champion!\p"
    .string "I would like to give you\n"
    .string "this Pokémon as a reward!$"

SaffronCity_Dojo_Text_MikeIntro::
    .string "Hoargh!\n"
    .string "Take your shoes off!$"

SaffronCity_Dojo_Text_MikeDefeat::
    .string "I give up!$"

SaffronCity_Dojo_Text_MikePostBattle::
    .string "You wait 'til you see our Master!\n"
    .string "I'm a small fry compared to him!$"

SaffronCity_Dojo_Text_HidekiIntro::
    .string "I hear you're good!\n"
    .string "Show me!$"

SaffronCity_Dojo_Text_HidekiDefeat::
    .string "Judge!\n"
    .string "One point!$"

SaffronCity_Dojo_Text_HidekiPostBattle::
    .string "Our Master is a pro fighter.\n"
    .string "Be prepared to lose!$"

SaffronCity_Dojo_Text_AaronIntro::
    .string "Hiyah!\n"
    .string "I have no fear for anything tough!\p"
    .string "I shatter boulders for training\n"
    .string "every day!$"

SaffronCity_Dojo_Text_AaronDefeat::
    .string "Yow!\n"
    .string "Stubbed fingers!$"

SaffronCity_Dojo_Text_AaronPostBattle::
    .string "The only thing that frightens us is\n"
    .string "psychic power!$"

SaffronCity_Dojo_Text_HitoshiIntro::
    .string "Hwaah!\p"
    .string "You're trespassing in our\n"
    .string "Fighting Dojo!$"

SaffronCity_Dojo_Text_HitoshiDefeat::
    .string "Oof!\n"
    .string "I give up!$"

SaffronCity_Dojo_Text_HitoshiPostBattle::
    .string "The prime fighters across the land\n"
    .string "train here.$"

SaffronCity_Dojo_Text_YouWantHitmonlee::
    .string "You want the hard-kicking\n"
    .string "Hitmonlee?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster::
    .string "{PLAYER} received the {STR_VAR_1}\n"
    .string "from the Karate Master.$"

SaffronCity_Dojo_Text_YouWantHitmonchan::
    .string "You want the piston-punching\n"
    .string "Hitmonchan?$"

SaffronCity_Dojo_Text_BetterNotGetGreedy::
    .string "Better not get greedy…$"

SaffronCity_Dojo_Text_KoichiCall::
    .string "… … … … … …\n"
    .string "… … … … … Beep!\p"
    .string "Koichi: Hello, {PLAYER}!\n"
    .string "This is Koichi of the Fighting\l"
    .string "Dojo in Saffron City.\p"
    .string "Congratulations on becoming\n"
    .string "the Pokémon Champion!\p"
    .string "When your next in Saffron\n"
    .string "please drop by the Dojo, I have\l"
    .string "something I'd like to give you\l"
    .string "to celebrate!\p"
    .string "I'll see you soon, Champ!\n"
    .string "Fwaaa!\p"
    .string "… … … … … …\n"
    .string "… … … … … Click!$"

SaffronCity_Dojo_Text_EnemiesOnEverySide::
    .string "Enemies on every side!$"

SaffronCity_Dojo_Text_GoesAroundComesAround::
    .string "What goes around comes around.$"

SaffronCity_Dojo_Text_FightingDojo::
    .string "Fighting Dojo$"
