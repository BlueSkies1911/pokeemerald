.equ LOCALID_ANTIBIKER1, 1
.equ LOCALID_ANTIBIKER2, 2
.equ LOCALID_PAXTON, 3
.equ LOCALID_BIKER1, 5
.equ LOCALID_BIKER2, 7
.equ LOCALID_BIKER3, 4
.equ LOCALID_BIKER4, 6
.equ LOCALID_BIKER5, 8
.equ LOCALID_BIKER6, 14

ThreeIsland_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_OnTransition
    .byte 0

ThreeIsland_OnTransition:
    setflag FLAG_WORLD_MAP_THREE_ISLAND
    call_if_set FLAG_RESCUED_LOSTELLE, ThreeIsland_EventScript_HideAntiBikers
    compare VAR_MAP_SCENE_THREE_ISLAND, 4
    call_if_eq ThreeIsland_EventScript_SetAntiBikersMovementAfterBikers
    end

ThreeIsland_EventScript_HideAntiBikers::
    setflag FLAG_HIDE_THREE_ISLAND_ANTIBIKERS
    return

ThreeIsland_EventScript_SetAntiBikersMovementAfterBikers::
    setobjectmovementtype LOCALID_ANTIBIKER1, MOVEMENT_TYPE_LOOK_AROUND
    setobjectmovementtype LOCALID_ANTIBIKER2, MOVEMENT_TYPE_LOOK_AROUND
    return

ThreeIsland_EventScript_Biker::
    lock
    setvar VAR_TEMP_1, 2
    call ThreeIsland_EventScript_BikerArgumentScene
    release
    end

ThreeIsland_EventScript_AntiBiker1::
    lock
    goto_if_set FLAG_GOT_FULL_RESTORE_FROM_THREE_ISLAND_DEFENDER, ThreeIsland_EventScript_AntiBiker1GotFullRestore
    compare VAR_MAP_SCENE_THREE_ISLAND, 4
    goto_if_eq ThreeIsland_EventScript_GiveFullRestore
    setvar VAR_TEMP_1, 0
    call ThreeIsland_EventScript_BikerArgumentScene
    release
    end

ThreeIsland_EventScript_AntiBiker1GotFullRestore::
    applymovement LOCALID_ANTIBIKER1, Common_Movement_FacePlayer
    waitmovement 0
    msgbox ThreeIsland_Text_YouveGotImpressiveMons, MSGBOX_DEFAULT
    release
    end

ThreeIsland_EventScript_GiveFullRestore::
    applymovement LOCALID_ANTIBIKER1, Common_Movement_FacePlayer
    waitmovement 0
    msgbox ThreeIsland_Text_ThankYouOhYourMonGotHurt, MSGBOX_DEFAULT
    checkitemspace ITEM_FULL_RESTORE, 1
    compare VAR_RESULT, FALSE
    goto_if_eq ThreeIsland_EventScript_NoRoomForFullRestore
    msgreceiveditem ThreeIsland_Text_GivenFullRestore, ITEM_FULL_RESTORE
    additem ITEM_FULL_RESTORE
    setflag FLAG_GOT_FULL_RESTORE_FROM_THREE_ISLAND_DEFENDER
    msgbox ThreeIsland_Text_YouveGotImpressiveMons, MSGBOX_DEFAULT
    release
    end

ThreeIsland_EventScript_NoRoomForFullRestore::
    msgbox ThreeIsland_Text_OhYourBagIsFull, MSGBOX_DEFAULT
    release
    end

ThreeIsland_EventScript_BikerArgumentScene::
    compare VAR_TEMP_1, 1
    call_if_eq ThreeIsland_EventScript_PlayerFaceLeft
    compare VAR_TEMP_1, 2
    call_if_eq ThreeIsland_EventScript_PlayerFaceLeft
    applymovement LOCALID_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
    waitmovement 0
    msgbox ThreeIsland_Text_GoBackToKanto, MSGBOX_DEFAULT
    compare VAR_TEMP_1, 0
    call_if_eq ThreeIsland_EventScript_PlayerFaceRight
    compare VAR_TEMP_1, 1
    call_if_eq ThreeIsland_EventScript_PlayerFaceRight
    compare VAR_TEMP_1, 2
    call_if_eq ThreeIsland_EventScript_PlayerFaceBiker
    applymovement LOCALID_BIKER1, ThreeIsland_Movement_SpeakLeft
    waitmovement 0
    msgbox ThreeIsland_Text_BossIsOnHisWay, MSGBOX_DEFAULT
    compare VAR_TEMP_1, 0
    call_if_eq ThreeIsland_EventScript_PlayerFaceUp
    compare VAR_TEMP_1, 1
    call_if_eq ThreeIsland_EventScript_PlayerFaceUp
    compare VAR_TEMP_1, 2
    call_if_eq ThreeIsland_EventScript_PlayerFaceAntiBiker
    applymovement LOCALID_ANTIBIKER2, ThreeIsland_Movement_SpeakRight
    waitmovement 0
    msgbox ThreeIsland_Text_GetOffIslandNow, MSGBOX_DEFAULT
    compare VAR_TEMP_1, 0
    call_if_eq ThreeIsland_EventScript_PlayerFaceRight
    compare VAR_TEMP_1, 1
    call_if_eq ThreeIsland_EventScript_PlayerFaceRight
    compare VAR_TEMP_1, 2
    call_if_eq ThreeIsland_EventScript_PlayerFaceBiker
    applymovement LOCALID_BIKER3, ThreeIsland_Movement_SpeakLeft
    waitmovement 0
    msgbox ThreeIsland_Text_WhosGonnaMakeMe, MSGBOX_DEFAULT
    return

ThreeIsland_EventScript_PlayerFaceUp::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

ThreeIsland_EventScript_PlayerFaceLeft::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    return

ThreeIsland_EventScript_PlayerFaceRight::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    return

ThreeIsland_EventScript_PlayerFaceBiker::
    getplayerxy VAR_0x8004, VAR_0x8005
    compare VAR_0x8004, 9
    goto_if_ge ThreeIsland_EventScript_PlayerFaceUp
    goto ThreeIsland_EventScript_PlayerFaceRight
    end

ThreeIsland_EventScript_PlayerFaceAntiBiker::
    getplayerxy VAR_0x8004, VAR_0x8005
    compare VAR_0x8004, 9
    goto_if_ge ThreeIsland_EventScript_PlayerFaceLeft
    goto ThreeIsland_EventScript_PlayerFaceUp
    end

ThreeIsland_EventScript_AntiBiker2::
    lock
    compare VAR_MAP_SCENE_THREE_ISLAND, 4
    goto_if_eq ThreeIsland_EventScript_AntiBiker2BikersGone
    setvar VAR_TEMP_1, 1
    call ThreeIsland_EventScript_BikerArgumentScene
    release
    end

ThreeIsland_EventScript_AntiBiker2BikersGone::
    applymovement LOCALID_ANTIBIKER2, Common_Movement_FacePlayer
    waitmovement 0
    msgbox ThreeIsland_Text_LostelleWentOffTowardsBondBridge
    release
    end

ThreeIsland_EventScript_BikerBossIntroTrigger::
    lockall
    applymovement LOCALID_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
    waitmovement 0
    msgbox ThreeIsland_Text_AreYouBossGoBackToKanto, MSGBOX_DEFAULT
    applymovement LOCALID_PAXTON, ThreeIsland_Movement_SpeakLeft
    waitmovement 0
    msgbox ThreeIsland_Text_JustGotHerePal, MSGBOX_DEFAULT
    applymovement LOCALID_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
    waitmovement 0
    msgbox ThreeIsland_Text_FollowersRaisingHavoc, MSGBOX_DEFAULT
    applymovement LOCALID_PAXTON, ThreeIsland_Movement_SpeakLeft
    waitmovement 0
    msgbox ThreeIsland_Text_OughtToBeThankingUs, MSGBOX_DEFAULT
    applymovement LOCALID_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
    waitmovement 0
    msgbox ThreeIsland_Text_YouCowardsToughInPack, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_THREE_ISLAND, 3
    releaseall
    end

ThreeIsland_Movement_SpeakLeft::
    walk_in_place_left
    step_end

ThreeIsland_Movement_SpeakRight::
    walk_in_place_right
    step_end

ThreeIsland_EventScript_BattleBikersTriggerLeft::
    lockall
    setvar VAR_TEMP_1, 0
    goto ThreeIsland_EventScript_BattleBikersScene
    end

ThreeIsland_EventScript_BattleBikersTriggerMidLeft::
    lockall
    setvar VAR_TEMP_1, 1
    goto ThreeIsland_EventScript_BattleBikersScene
    end

ThreeIsland_EventScript_BattleBikersTriggerMid::
    lockall
    setvar VAR_TEMP_1, 2
    goto ThreeIsland_EventScript_BattleBikersScene
    end

ThreeIsland_EventScript_BattleBikersTriggerMidRight::
    lockall
    setvar VAR_TEMP_1, 3
    goto ThreeIsland_EventScript_BattleBikersScene
    end

ThreeIsland_EventScript_BattleBikersTriggerRight::
    lockall
    setvar VAR_TEMP_1, 4
    goto ThreeIsland_EventScript_BattleBikersScene
    end

ThreeIsland_EventScript_BattleBikersScene::
    applymovement LOCALID_BIKER1, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_BIKER1, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_BIKER1, Common_Movement_Delay48
    waitmovement 0
    applymovement LOCALID_BIKER1, ThreeIsland_Movement_BikerApproach
    waitmovement 0
    playbgm MUS_RG_ENCOUNTER_BOY, 0
    msgbox ThreeIsland_Text_WannaMakeSomethingOfYourStaring, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq ThreeIsland_EventScript_LeaveBikersAlone
    msgbox ThreeIsland_Text_Biker1Intro, MSGBOX_DEFAULT
    setvar VAR_LAST_TALKED, LOCALID_BIKER1
    trainerbattle_no_intro TRAINER_BIKER_GOON, ThreeIsland_Text_Biker1Defeat
    applymovement LOCALID_BIKER1, ThreeIsland_Movement_BikerSpeak
    waitmovement 0
    msgbox ThreeIsland_Text_Biker1PostBattle, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_BIKER2, ThreeIsland_Movement_BikerApproach
    waitmovement 0
    playbgm MUS_RG_ENCOUNTER_BOY, 0
    msgbox ThreeIsland_Text_Biker2Intro, MSGBOX_DEFAULT
    setvar VAR_LAST_TALKED, LOCALID_BIKER2
    trainerbattle_no_intro TRAINER_BIKER_GOON_2, ThreeIsland_Text_Biker2Defeat
    applymovement LOCALID_BIKER2, ThreeIsland_Movement_BikerSpeak
    waitmovement 0
    msgbox ThreeIsland_Text_Biker2PostBattle, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_BIKER3, ThreeIsland_Movement_BikerApproach
    waitmovement 0
    playbgm MUS_RG_ENCOUNTER_BOY, 0
    msgbox ThreeIsland_Text_Biker3Intro, MSGBOX_DEFAULT
    setvar VAR_LAST_TALKED, LOCALID_BIKER3
    trainerbattle_no_intro TRAINER_BIKER_GOON_3, ThreeIsland_Text_Biker3Defeat
    applymovement LOCALID_BIKER3, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    applymovement LOCALID_BIKER4, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_BIKER5, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    msgbox ThreeIsland_Text_Biker3PostBattle, MSGBOX_DEFAULT
    closemessage
    delay 45
    compare VAR_TEMP_1, 0
    call_if_eq ThreeIsland_EventScript_PaxtonApproachLeft
    compare VAR_TEMP_1, 1
    call_if_eq ThreeIsland_EventScript_PaxtonApproachMidLeft
    compare VAR_TEMP_1, 2
    call_if_eq ThreeIsland_EventScript_PaxtonApproachMid
    compare VAR_TEMP_1, 3
    call_if_eq ThreeIsland_EventScript_PaxtonApproachMidRight
    compare VAR_TEMP_1, 4
    call_if_eq ThreeIsland_EventScript_PaxtonApproachRight
    playbgm MUS_RG_ENCOUNTER_BOY, 0
    msgbox ThreeIsland_Text_PaxtonIntro, MSGBOX_DEFAULT
    setvar VAR_LAST_TALKED, LOCALID_PAXTON
    trainerbattle_no_intro TRAINER_CUE_BALL_PAXTON, ThreeIsland_Text_PaxtonDefeat
    msgbox ThreeIsland_Text_PaxtonPostBattle, MSGBOX_DEFAULT
    closemessage
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_PAXTON
    removeobject LOCALID_BIKER1
    removeobject LOCALID_BIKER2
    removeobject LOCALID_BIKER3
    removeobject LOCALID_BIKER4
    removeobject LOCALID_BIKER5
    removeobject LOCALID_BIKER6
    fadescreen FADE_FROM_BLACK
    setvar VAR_MAP_SCENE_THREE_ISLAND, 4
    releaseall
    end

ThreeIsland_EventScript_PaxtonApproachLeft::
    applymovement LOCALID_BIKER3, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachLeft
    waitmovement 0
    return

ThreeIsland_EventScript_PaxtonApproachMidLeft::
    applymovement LOCALID_BIKER3, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachMidLeft
    waitmovement 0
    return

ThreeIsland_EventScript_PaxtonApproachMid::
    applymovement LOCALID_BIKER3, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachMid
    applymovement OBJ_EVENT_ID_PLAYER, ThreeIsland_Movement_PlayerFacePaxton
    waitmovement 0
    return

ThreeIsland_EventScript_PaxtonApproachMidRight::
    applymovement LOCALID_BIKER3, Common_Movement_WalkInPlaceFasterDown
    applymovement OBJ_EVENT_ID_PLAYER, ThreeIsland_Movement_PlayerFacePaxton
    applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachMidRight
    waitmovement 0
    return

ThreeIsland_EventScript_PaxtonApproachRight::
    applymovement LOCALID_BIKER3, Common_Movement_WalkInPlaceFasterDown
    applymovement OBJ_EVENT_ID_PLAYER, ThreeIsland_Movement_PlayerFacePaxton
    applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachRight
    waitmovement 0
    return

ThreeIsland_EventScript_LeaveBikersAlone::
    msgbox ThreeIsland_Text_ThatsSmart, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, ThreeIsland_Movement_PlayerLeaveBikers
    waitmovement 0
    applymovement LOCALID_BIKER1, ThreeIsland_Movement_Biker1ReturnToPack
    waitmovement 0
    fadedefaultbgm
    releaseall
    end

ThreeIsland_Movement_PlayerLeaveBikers::
    walk_down
    step_end

ThreeIsland_Movement_BikerApproach::
    walk_down
    step_end

ThreeIsland_Movement_Biker1ReturnToPack::
    walk_up
    walk_in_place_faster_left
    step_end

ThreeIsland_Movement_BikerSpeak::
    walk_in_place_down
    step_end

ThreeIsland_Movement_PaxtonApproachLeft::
    walk_down
    walk_left
    walk_in_place_faster_down
    step_end

ThreeIsland_Movement_PaxtonApproachMidLeft::
    walk_down
    step_end

ThreeIsland_Movement_PaxtonApproachMid::
    walk_down
    walk_down
    walk_in_place_faster_right
    step_end

ThreeIsland_Movement_PlayerFacePaxton::
    delay_16
    delay_16
    walk_in_place_faster_left
    step_end

ThreeIsland_Movement_PaxtonApproachMidRight::
    walk_down
    walk_down
    walk_right
    walk_in_place_faster_right
    step_end

ThreeIsland_Movement_PaxtonApproachRight::
    walk_down
    walk_down
    walk_right
    walk_right
    walk_in_place_faster_right
    step_end

ThreeIsland_EventScript_Woman::
    msgbox ThreeIsland_Text_WouldntWantToSeeBikersHereAgain, MSGBOX_NPC
    end

ThreeIsland_EventScript_LittleBoy::
    msgbox ThreeIsland_Text_WhenDodouEvolvesGoingToPlayGame, MSGBOX_NPC
    end

ThreeIsland_EventScript_Doduo::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_DODUO, 0
    msgbox ThreeIsland_Text_Doduo, MSGBOX_DEFAULT
    waitmoncry
    release
    end

ThreeIsland_EventScript_IslandSign::
    msgbox ThreeIsland_Text_IslandSign, MSGBOX_SIGN
    end

ThreeIsland_EventScript_Biker6::
    msgbox ThreeIsland_Text_IslandBelongsToUs, MSGBOX_NPC
    end

ThreeIsland_Text_GoBackToKanto::
    .string "We don't need you people bringing\n"
    .string "your noise and trouble here!\p"
    .string "We're asking you to go back to\n"
    .string "Kanto!$"

ThreeIsland_Text_BossIsOnHisWay::
    .string "Hey, go cry somewhere else.\n"
    .string "Our boss is on his way.\p"
    .string "When he gets here, we'll give you\n"
    .string "a k-rad motorbike show you won't\l"
    .string "soon forget!$"

ThreeIsland_Text_GetOffIslandNow::
    .string "W-what!? Not on your life!\n"
    .string "Get off the island now!$"

ThreeIsland_Text_WhosGonnaMakeMe::
    .string "Who's gonna make me?$"

ThreeIsland_Text_AreYouBossGoBackToKanto::
    .string "Are you the boss?\n"
    .string "Go back to Kanto right now!$"

ThreeIsland_Text_JustGotHerePal::
    .string "Hah?\p"
    .string "I just got here, pal.\p"
    .string "What's with the hostile attitude?\n"
    .string "It's mighty cold of you!$"

ThreeIsland_Text_FollowersRaisingHavoc::
    .string "Your gang of followers have been\n"
    .string "raising havoc on their bikes.\p"
    .string "Do you have any idea how much\n"
    .string "trouble they've caused us on the\l"
    .string "island?$"

ThreeIsland_Text_OughtToBeThankingUs::
    .string "No, man, I don't get it at all.\p"
    .string "Look at this place.\n"
    .string "What do you do for entertainment?\p"
    .string "You ought to be thanking us for\n"
    .string "livening up this sleepy village.\p"
    .string "But hey, if you insist, you can try\n"
    .string "making us leave.$"

ThreeIsland_Text_YouCowardsToughInPack::
    .string "Grr… You cowards…\n"
    .string "So tough in a pack…$"

ThreeIsland_Text_WannaMakeSomethingOfYourStaring::
    .string "You, what are you staring at?\n"
    .string "Don't you know it's not polite?\p"
    .string "You wanna make something of it\n"
    .string "or what?$"

ThreeIsland_Text_ThatsSmart::
    .string "That's smart.\n"
    .string "Keep your nose out of this.$"

ThreeIsland_Text_Biker1Intro::
    .string "Heh, I like your guts.\n"
    .string "You'll be losing money to me, but…$"

ThreeIsland_Text_Biker1Defeat::
    .string "Wha…\n"
    .string "What is this kid?!$"

ThreeIsland_Text_Biker1PostBattle::
    .string "Aww, man…\n"
    .string "Don't you dare laugh!$"

ThreeIsland_Text_Biker2Intro::
    .string "Aren't you from Kanto?\n"
    .string "You should be on our side!$"

ThreeIsland_Text_Biker2Defeat::
    .string "Stop fooling around!$"

ThreeIsland_Text_Biker2PostBattle::
    .string "What's the matter with you,\n"
    .string "getting all hot like that?\p"
    .string "Totally uncool, man!$"

ThreeIsland_Text_Biker3Intro::
    .string "We invited the boss out here,\n"
    .string "but you had to mess it up!\p"
    .string "You embarrassed us, man!$"

ThreeIsland_Text_Biker3Defeat::
    .string "… … …   … … …$"

ThreeIsland_Text_Biker3PostBattle::
    .string "Boss, I'm telling you, you've gotta\n"
    .string "do something about this kid!$"

ThreeIsland_Text_PaxtonIntro::
    .string "I've been watching you, and I'd say\n"
    .string "you've done enough.\p"
    .string "What are you, their friend or\n"
    .string "something?\p"
    .string "Then I guess you'll be battling me\n"
    .string "in their place.$"

ThreeIsland_Text_PaxtonDefeat::
    .string "All right, enough!\n"
    .string "We'll leave like you wanted!\p"
    .string "We'll be happy to see the last of\n"
    .string "this boring island!$"

ThreeIsland_Text_PaxtonPostBattle::
    .string "Humph! Yeah, go right on hanging\n"
    .string "around with these hayseeds!$"

ThreeIsland_Text_ThankYouOhYourMonGotHurt::
    .string "Thank you! Those goons were\n"
    .string "nothing but bad trouble.\p"
    .string "Oh, look, your Pokémon got hurt\n"
    .string "on my account.$"

ThreeIsland_Text_GivenFullRestore::
    .string "{PLAYER} was given\n"
    .string "a Full Restore.$"

ThreeIsland_Text_OhYourBagIsFull::
    .string "Oh?\n"
    .string "Your bag is full.$"

ThreeIsland_Text_YouveGotImpressiveMons::
    .string "You've got seriously impressive\n"
    .string "Pokémon with you.$"

ThreeIsland_Text_LostelleWentOffTowardsBondBridge::
    .string "It'd be fantastic if someone as\n"
    .string "strong as you lived here.\p"
    .string "I hope you'll at least stay here\n"
    .string "a while.\p"
    .string "…I beg your pardon?\n"
    .string "You're looking for Lostelle?\p"
    .string "Lostelle went off towards Bond\n"
    .string "Bridge a while ago.$"

ThreeIsland_Text_WouldntWantToSeeBikersHereAgain::
    .string "Three Island is actually the most\n"
    .string "populous of the islands here.\p"
    .string "Still, it could be less sleepy.\p"
    .string "But I wouldn't want to see goons\n"
    .string "like those Bikers here again.$"

ThreeIsland_Text_WhenDodouEvolvesGoingToPlayGame::
    .string "I'm going to train my Doduo in the\n"
    .string "Berry Forest.\p"
    .string "When it evolves, I'm going to play\n"
    .string "a game on Two Island.$"

ThreeIsland_Text_Doduo::
    .string "Doduo: Gigiih!$"

ThreeIsland_Text_IslandSign::
    .string "Three Island\n"
    .string "Kin Island of Family Bonding$"

ThreeIsland_Text_IslandBelongsToUs::
    .string "Hyahoo!\p"
    .string "From this day on, this island\n"
    .string "belongs to us!$"
