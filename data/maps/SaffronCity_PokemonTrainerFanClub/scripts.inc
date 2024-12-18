.set LOCALID_BATTLE_GIRL, 1
.set LOCALID_LITTLE_GIRL, 2
.set LOCALID_YOUNGSTER,   3
.set LOCALID_GENTLEMAN,   4
.set LOCALID_WOMAN,       5
.set LOCALID_ROCKER,      6
.set LOCALID_BEAUTY,      7
.set LOCALID_BLACK_BELT,  8

SaffronCity_PokemonTrainerFanClub_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_PokemonTrainerFanClub_OnFrame
    map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonTrainerFanClub_OnTransition
	.byte 0

SaffronCity_PokemonTrainerFanClub_OnFrame:
    map_script_2 VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1, SaffronCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
    .2byte 0

SaffronCity_PokemonTrainerFanClub_EventScript_MeetFirstFans::
    lockall
    applymovement LOCALID_BATTLE_GIRL, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_BATTLE_GIRL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_BATTLE_GIRL, Common_Movement_Delay48
    waitmovement 0
    msgbox SaffronCity_PokemonTrainerFanClub_Text_HuhYou, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_BATTLE_GIRL, SaffronCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    msgbox SaffronCity_PokemonTrainerFanClub_Text_YourePlayerWereYourFansNow, MSGBOX_DEFAULT
    setvar VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 2
    releaseall
    end

SaffronCity_PokemonTrainerFanClub_Movement_FanApproachPlayer::
    delay_16
    delay_8
    walk_down
    delay_16
    walk_down
    delay_8
    walk_left
    step_end

SaffronCity_PokemonTrainerFanClub_OnTransition:
    call SaffronCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer
    compare VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_SetMemberPosForFirstMeeting
    compare VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 2
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
    end

SaffronCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer::
    specialvar VAR_RESULT, ShouldHideFanClubInterviewer
    goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_HideInterviewer
    clearflag FLAG_HIDE_SAFFRON_FAN_CLUB_INTERVIEWER
    clearflag FLAG_FAN_CLUB_STRENGTH_SHARED
    return

SaffronCity_PokemonTrainerFanClub_EventScript_HideInterviewer::
    setflag FLAG_HIDE_SAFFRON_FAN_CLUB_INTERVIEWER
    return

SaffronCity_PokemonTrainerFanClub_EventScript_SetMemberPosForFirstMeeting::
    call SaffronCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
    call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
    call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
    call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
    call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
    call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
    end

SaffronCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions::
    special TryLoseFansFromPlayTime
    call SaffronCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
    setvar VAR_0x8004, FANCLUB_MEMBER1
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, FALSE
    call_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
    setvar VAR_0x8004, FANCLUB_MEMBER2
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, FALSE
    call_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
    setvar VAR_0x8004, FANCLUB_MEMBER3
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, FALSE
    call_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
    setvar VAR_0x8004, FANCLUB_MEMBER4
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, FALSE
    call_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
    setvar VAR_0x8004, FANCLUB_MEMBER5
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, FALSE
    call_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
    setvar VAR_0x8004, FANCLUB_MEMBER6
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, FALSE
    call_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
    setvar VAR_0x8004, FANCLUB_MEMBER7
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, FALSE
    call_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
    setvar VAR_0x8004, FANCLUB_MEMBER8
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, FALSE
    call_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
    end

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable::
    setobjectxyperm LOCALID_BATTLE_GIRL, 5, 2
    setobjectmovementtype LOCALID_BATTLE_GIRL, MOVEMENT_TYPE_FACE_UP
    return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable::
    setobjectxyperm LOCALID_YOUNGSTER, 7, 4
    setobjectmovementtype LOCALID_YOUNGSTER, MOVEMENT_TYPE_FACE_LEFT
    return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable::
    setobjectxyperm LOCALID_GENTLEMAN, 2, 2
    setobjectmovementtype LOCALID_GENTLEMAN, MOVEMENT_TYPE_FACE_UP
    return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable::
    setobjectxyperm LOCALID_LITTLE_GIRL, 3, 4
    setobjectmovementtype LOCALID_LITTLE_GIRL, MOVEMENT_TYPE_FACE_RIGHT
    return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable::
    setobjectxyperm LOCALID_ROCKER, 4, 6
    setobjectmovementtype LOCALID_ROCKER, MOVEMENT_TYPE_FACE_UP
    return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable::
    setobjectxyperm LOCALID_WOMAN, 10, 3
    setvar VAR_TEMP_1, 1
    setobjectmovementtype LOCALID_WOMAN, MOVEMENT_TYPE_FACE_UP
    return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable::
    setobjectxyperm LOCALID_BEAUTY, 7, 5
    setobjectmovementtype LOCALID_BEAUTY, MOVEMENT_TYPE_FACE_LEFT
    return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable::
    setobjectxyperm LOCALID_BLACK_BELT, 9, 6
    setobjectmovementtype LOCALID_BLACK_BELT, MOVEMENT_TYPE_FACE_LEFT
    return

SaffronCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow::
    setvar VAR_0x8005, NUM_TRAINER_FAN_CLUB_MEMBERS
    setvar VAR_0x8004, FANCLUB_MEMBER1
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
    setvar VAR_0x8004, FANCLUB_MEMBER2
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
    setvar VAR_0x8004, FANCLUB_MEMBER3
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
    setvar VAR_0x8004, FANCLUB_MEMBER4
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
    setvar VAR_0x8004, FANCLUB_MEMBER5
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
    setvar VAR_0x8004, FANCLUB_MEMBER6
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
    setvar VAR_0x8004, FANCLUB_MEMBER7
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
    setvar VAR_0x8004, FANCLUB_MEMBER8
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
    goto_if_ge VAR_0x8005, 5, SaffronCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow
    return

SaffronCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan::
    subvar VAR_0x8005, 1
    return

SaffronCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow::
    special TryPutTrainerFanClubOnAir
    return

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirl::
    lock
    faceplayer
    setvar VAR_0x8004, FANCLUB_MEMBER1
    special BufferFanClubTrainerName
    compare VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayerNotChampion
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, TRUE
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayersFan
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyNonFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_WasYourFanNotAnymore
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayersFan::
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, 1
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_IllAlwaysBelieveInYou, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyNonFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryonesYourFanButICantBe, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayerNotChampion::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_TrainersCoolWhenBattling, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirl::
    lock
    faceplayer
    setvar VAR_0x8004, FANCLUB_MEMBER4
    special BufferFanClubTrainerName
    compare VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, TRUE
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeSabrina, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan::
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, 1
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeYouOneDay, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryoneButMeStoppedBeingYourFan, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingSabrinasFan, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_CanIBecomeCoolTrainerOneDay, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_Youngster::
    lock
    faceplayer
    setvar VAR_0x8004, FANCLUB_MEMBER2
    special BufferFanClubTrainerName
    compare VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayerNotChampion
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, TRUE
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayersFan
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyNonFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksMyHero, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayersFan::
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, 1
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_CanYouAutographShorts, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_CountingOnYou, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyNonFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksFanToBitterEnd, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayerNotChampion::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksLastWordOnCool, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_Gentleman::
    lock
    faceplayer
    setvar VAR_0x8004, FANCLUB_MEMBER3
    special BufferFanClubTrainerName
    compare VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayerNotChampion
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, TRUE
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayersFan
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyNonFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_HmmAndYouAre, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayersFan::
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, 1
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_HadPleasureOfWatchingYouBattle, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_NeverSeenTrainerOfYourMagnificence, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyNonFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_YouveStillAWaysToGo, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayerNotChampion::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_YoullBeTalkedAboutIfYouKeepWinning, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_Woman::
    lock
    faceplayer
    setvar VAR_0x8004, FANCLUB_MEMBER6
    special BufferFanClubTrainerName
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, TRUE
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_TrainerHasBeenOnFire, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan::
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, 1
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_AdoreWayYouBattle, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_ImYourNumberOneFan, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryoneTalksAboutYou, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_Rocker::
    lock
    faceplayer
    setvar VAR_0x8004, FANCLUB_MEMBER5
    special BufferFanClubTrainerName
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, TRUE
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_RockerPlayersFan
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyNonFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_LoveWayTrainerTalks, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerPlayersFan::
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, 1
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_TheWayYouBattleIsCool, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_ImOnlyOneLeftOfYourFans, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyNonFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_ImLoneTrainerFan, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_Beauty::
    lock
    faceplayer
    setvar VAR_0x8004, FANCLUB_MEMBER7
    special BufferFanClubTrainerName
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, TRUE
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_BeautyPlayersFan
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyNonFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_WhyCantOthersSeeMastersDignity, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyPlayersFan::
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, 1
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_YouReallyAreAmazing, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_ImYourOnlyFan, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyNonFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_BelieveInMasterWithAllMyHeart, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBelt::
    lock
    faceplayer
    setvar VAR_0x8004, FANCLUB_MEMBER8
    special BufferFanClubTrainerName
    specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
    compare VAR_RESULT, TRUE
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltPlayersFan
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyNonFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_OnlyMasterHasMyRespect, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltPlayersFan::
    specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
    compare VAR_RESULT, 1
    goto_if_eq SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyFan
    msgbox SaffronCity_PokemonTrainerFanClub_Text_YourBattleStyleIsEducational, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingYourFan, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyNonFan::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_NeverBeFanOfAnyoneButMaster, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_Interviewer::
    lock
    faceplayer
    goto_if_set FLAG_FAN_CLUB_STRENGTH_SHARED, SaffronCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed
    goto_if_unset FLAG_FAN_CLUB_STRENGTH_SHARED, SaffronCity_PokemonTrainerFanClub_EventScript_Interview
    end

@ The interviewer doesnt count as an individual fan club member
@ Instead they always ask about whoever the Lass would be interested in, if not the player
SaffronCity_PokemonTrainerFanClub_EventScript_Interview::
    setvar VAR_0x8005, TVSHOW_FAN_CLUB_SPECIAL
    special InterviewBefore
    goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2
    copyvar VAR_0x800A, VAR_0x8006
    setvar VAR_0x8004, FANCLUB_MEMBER1
    special BufferFanClubTrainerName
    msgbox SaffronCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer, MSGBOX_DEFAULT
    setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
    copyvar VAR_0x8005, VAR_0x800A
    call Common_ShowEasyChatScreen
    lock
    faceplayer
    goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
    goto_if_eq VAR_RESULT, 0, SaffronCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
    end

SaffronCity_PokemonTrainerFanClub_EventScript_SubmitOpinion::
    msgbox SaffronCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink, MSGBOX_DEFAULT
    goto SaffronCity_PokemonTrainerFanClub_EventScript_RateTrainer
    end

SaffronCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion::
    setvar VAR_0x8004, FANCLUB_MEMBER1
    special BufferFanClubTrainerName
    msgbox SaffronCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, SaffronCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
    goto_if_eq VAR_RESULT, NO, SaffronCity_PokemonTrainerFanClub_EventScript_AskForOpinion
    end

SaffronCity_PokemonTrainerFanClub_EventScript_AskForOpinion::
    setvar VAR_0x8004, FANCLUB_MEMBER1
    special BufferFanClubTrainerName
    msgbox SaffronCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2, MSGBOX_DEFAULT
    setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
    copyvar VAR_0x8005, VAR_0x800A
    call Common_ShowEasyChatScreen
    lock
    faceplayer
    goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
    goto_if_eq VAR_RESULT, 0, SaffronCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
    end

SaffronCity_PokemonTrainerFanClub_EventScript_RateTrainer::
    setvar VAR_0x8004, FANCLUB_MEMBER1
    special BufferFanClubTrainerName
    message SaffronCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer
    waitmessage
    setvar VAR_0x8004, SCROLL_MULTI_POKEMON_FAN_CLUB_RATER
    special ShowScrollableMultichoice
    waitstate
    setvar VAR_0x8004, FANCLUB_MEMBER1
    switch VAR_RESULT
    case 11, SaffronCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
    case MULTI_B_PRESSED, SaffronCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
    setvar VAR_0x8004, FANCLUB_MEMBER1
    special BufferFanClubTrainerName
    copyvar VAR_0x8006, VAR_0x800A
    copyvar VAR_0x8005, VAR_RESULT
    special PutFanClubSpecialOnTheAir
    goto SaffronCity_PokemonTrainerFanClub_EventScript_CompleteInterview
    end

SaffronCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer::
    setvar VAR_0x8004, FANCLUB_MEMBER1
    special BufferFanClubTrainerName
    msgbox SaffronCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, SaffronCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
    goto_if_eq VAR_RESULT, NO, SaffronCity_PokemonTrainerFanClub_EventScript_RateTrainer
    end

SaffronCity_PokemonTrainerFanClub_EventScript_ForgetTrainer::
    setvar VAR_0x8004, FANCLUB_MEMBER1
    special BufferFanClubTrainerName
    msgbox SaffronCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer, MSGBOX_DEFAULT
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_CompleteInterview::
    setvar VAR_0x8004, FANCLUB_MEMBER1
    special BufferFanClubTrainerName
    msgbox SaffronCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo, MSGBOX_DEFAULT
    setflag FLAG_FAN_CLUB_STRENGTH_SHARED
    release
    end

SaffronCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed::
    setvar VAR_0x8004, FANCLUB_MEMBER1
    special BufferFanClubTrainerName
    msgbox SaffronCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial, MSGBOX_DEFAULT
    release
    end

@ Shouldnt be reached
SaffronCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2::
    end

SaffronCity_PokemonTrainerFanClub_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_WOMAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WOMAN, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SaffronCity_PokemonTrainerFanClub_Movement_PlayerPushFromTV
	applymovement LOCALID_WOMAN, SaffronCity_PokemonTrainerFanClub_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_WOMAN, SaffronCity_PokemonTrainerFanClub_Movement_OwnerReturn
	waitmovement 0
	release
	end

SaffronCity_PokemonTrainerFanClub_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SaffronCity_PokemonTrainerFanClub_Movement_OwnerPushPlayer:
	walk_up
	step_end

SaffronCity_PokemonTrainerFanClub_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

SaffronCity_PokemonTrainerFanClub_EventScript_PokemonJournalBruno::
    lockall
    msgbox PokemonJournal_Text_SpecialFeatureBruno, MSGBOX_DEFAULT
    releaseall
    end

SaffronCity_PokemonTrainerFanClub_Text_HuhYou::
    .string "Huh?\n"
    .string "You…$"

SaffronCity_PokemonTrainerFanClub_Text_YourePlayerWereYourFansNow::
    .string "Are you maybe…\n"
    .string "… …\p"
    .string "You are!\n"
    .string "You are {PLAYER}!\p"
    .string "We were just talking about you!\p"
    .string "We were talking about how an\n"
    .string "incredibly good Trainer appeared.\p"
    .string "And that someone is you!\n"
    .string "You're so cool!\p"
    .string "So, we decided that we'll become\n"
    .string "your Fan Club!\p"
    .string "We all hope you'll keep battling\n"
    .string "and show us how cool you are.\p"
    .string "That way, maybe other people will\n"
    .string "become fans just like me.$"

SaffronCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou::
    .string "I'll always be cheering for you!\p"
    .string "Go, {PLAYER}, go!$"

SaffronCity_PokemonTrainerFanClub_Text_IllAlwaysBelieveInYou::
    .string "I'll always believe in you,\n"
    .string "{PLAYER}.\p"
    .string "Please show the others what you're\n"
    .string "like when you battle seriously.$"

SaffronCity_PokemonTrainerFanClub_Text_WasYourFanNotAnymore::
    .string "I'm sorry.\n"
    .string "I was your fan before.\p"
    .string "But now, you seem to have lost\n"
    .string "the drive you had before.\p"
    .string "Lately, I think {STR_VAR_1} has been\n"
    .string "a lot cooler.$"

SaffronCity_PokemonTrainerFanClub_Text_EveryonesYourFanButICantBe::
    .string "Oh!\n"
    .string "{PLAYER}!\p"
    .string "Everyone's been all excited about\n"
    .string "you recently.\p"
    .string "I can understand why.\n"
    .string "I know that you're strong.\p"
    .string "But, do you know what?\p"
    .string "Once I became {STR_VAR_1}'s fan,\n"
    .string "I can't just stop being a fan.$"

SaffronCity_PokemonTrainerFanClub_Text_TrainersCoolWhenBattling::
    .string "I think Trainers are so cool when\n"
    .string "they're battling.\p"
    .string "Don't you think so, too?$"

SaffronCity_PokemonTrainerFanClub_Text_CanYouAutographShorts::
    .string "Oh! It's {PLAYER}!\n"
    .string "Too cool!\p"
    .string "Oh!\n"
    .string "Oh, yeah!\p"
    .string "Can you autograph something?\n"
    .string "How about my shorts?$"

SaffronCity_PokemonTrainerFanClub_Text_CountingOnYou::
    .string "However hot it's been…\p"
    .string "And however cold it may get…\p"
    .string "I've always believed in, and worn,\n"
    .string "shorts!\p"
    .string "I'm counting on you to keep\n"
    .string "winning!\p"
    .string "I believe in you just as much as\n"
    .string "I believe in shorts!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksMyHero::
    .string "Brock's my hero!\n"
    .string "He's a man among men!\p"
    .string "Heheh, I got my mom to do\n"
    .string "something for me.\p"
    .string "I got her to embroider “Brock”\n"
    .string "on my shorts!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksFanToBitterEnd::
    .string "…  …\p"
    .string "…  …\n"
    .string "I'm Brock's fan!\p"
    .string "Even if I were his only fan,\n"
    .string "I swear it on my rock-hard will,\l"
    .string "and on my shorts!\p"
    .string "I'll be his fan to the bitter end!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksLastWordOnCool::
    .string "Brock's the last word on cool,\n"
    .string "end of story!\p"
    .string "Now there's a guy who I want to\n"
    .string "be like!$"

SaffronCity_PokemonTrainerFanClub_Text_HadPleasureOfWatchingYouBattle::
    .string "{PLAYER}, I've had the pleasure of\n"
    .string "watching you battle.\p"
    .string "It brings back sweet memories of\n"
    .string "my own long-lost youth.\p"
    .string "May you continue to find success.\n"
    .string "You have a fan in me!$"

SaffronCity_PokemonTrainerFanClub_Text_NeverSeenTrainerOfYourMagnificence::
    .string "I have journeyed far and wide\n"
    .string "across the lands.\p"
    .string "But never have I seen a Trainer\n"
    .string "of your magnificence.\p"
    .string "Take courage in your abilities\n"
    .string "and keep battling on!\p"
    .string "Make that a promise to me,\n"
    .string "my young idol!$"

SaffronCity_PokemonTrainerFanClub_Text_HmmAndYouAre::
    .string "Hmm…\n"
    .string "And you are?\p"
    .string "Were you hoping to sign up for\n"
    .string "a membership in our Fan Club?$"

SaffronCity_PokemonTrainerFanClub_Text_YouveStillAWaysToGo::
    .string "Ah, so you are the much-\n"
    .string "talked-about {PLAYER}.\p"
    .string "You certainly do have the look of\n"
    .string "a winner.\p"
    .string "But for me to accept you as\n"
    .string "a true Pokémon great…\p"
    .string "… …\p"
    .string "You've still a ways to go!$"

SaffronCity_PokemonTrainerFanClub_Text_YoullBeTalkedAboutIfYouKeepWinning::
    .string "All of us gathered here are fans\n"
    .string "of Pokémon Trainers.\p"
    .string "The way they look in battle…\n"
    .string "They are the picture of coolness.\p"
    .string "Perhaps you will be talked about\n"
    .string "here, too, if you keep winning.$"

SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeYouOneDay::
    .string "It's {PLAYER}!\n"
    .string "It's {PLAYER}!\p"
    .string "I want to be like {PLAYER} one day!$"

SaffronCity_PokemonTrainerFanClub_Text_EveryoneButMeStoppedBeingYourFan::
    .string "Everyone stopped being {PLAYER}'s\n"
    .string "fan…\p"
    .string "But that means I can have {PLAYER}\n"
    .string "all to myself!\p"
    .string "Yay! Go for it!\n"
    .string "My one and only {PLAYER}!$"

SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeSabrina::
    .string "Do you know what?\n"
    .string "I want to be like Sabrina!\p"
    .string "I want to be a psychic girl just\n"
    .string "like her!$"

SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingSabrinasFan::
    .string "Even if I'm the only one, I won't\n"
    .string "stop being Sabrina's fan.\p"
    .string "My dream is to be like Sabrina,\n"
    .string "cute, but cool.\p"
    .string "I want to be a psychic girl just\n"
    .string "like her!$"

SaffronCity_PokemonTrainerFanClub_Text_CanIBecomeCoolTrainerOneDay::
    .string "I wonder if I can become a cool\n"
    .string "Trainer one day?$"

SaffronCity_PokemonTrainerFanClub_Text_TheWayYouBattleIsCool::
    .string "Oh, man, oh, man!\n"
    .string "Cool! Too cool!\p"
    .string "…Huh?\n"
    .string "No, not you.\p"
    .string "Just the way you battle.\n"
    .string "That's cool.$"

SaffronCity_PokemonTrainerFanClub_Text_ImOnlyOneLeftOfYourFans::
    .string "Yo, {PLAYER}!\p"
    .string "Looks like I'm the only one left\n"
    .string "out of your fans.\p"
    .string "But, you know, I like being an only\n"
    .string "fan… It's less stressful.\p"
    .string "Keep up and at it!$"

SaffronCity_PokemonTrainerFanClub_Text_LoveWayTrainerTalks::
    .string "{STR_VAR_1}'s cool, huh?\n"
    .string "I love the way he talks.\p"
    .string "I'd really relish a chance to meet\n"
    .string "him in person once.$"

SaffronCity_PokemonTrainerFanClub_Text_ImLoneTrainerFan::
    .string "Huh, can you believe it?\n"
    .string "Everyone turned into your fans.\p"
    .string "So after all we've been through,\n"
    .string "I'm the lone {STR_VAR_1} fan?\p"
    .string "Eh, being the one and only\n"
    .string "{STR_VAR_1} fan's my style, anyway.$"

SaffronCity_PokemonTrainerFanClub_Text_AdoreWayYouBattle::
    .string "Oh, my goodness!\n"
    .string "Is it really you, {PLAYER}?\p"
    .string "I have to tell you, I adore the\n"
    .string "way you battle.\p"
    .string "I hope you'll keep at it.\n"
    .string "I'll be your number one fan!$"

SaffronCity_PokemonTrainerFanClub_Text_ImYourNumberOneFan::
    .string "Oh, my goodness!\n"
    .string "If it isn't {PLAYER}!\p"
    .string "It's so disappointing… I realised\n"
    .string "I'm your number-one-and-only fan!\p"
    .string "Well, it can't be helped!\n"
    .string "Let me cheer you on, at least!\p"
    .string "Hurray, hurray, {PLAYER}!$"

SaffronCity_PokemonTrainerFanClub_Text_TrainerHasBeenOnFire::
    .string "Recently, {STR_VAR_1} has been on\n"
    .string "fire.\p"
    .string "The way he battles… It's just \n"
    .string "the way that I like it!$"

SaffronCity_PokemonTrainerFanClub_Text_EveryoneTalksAboutYou::
    .string "Oh, hello!\n"
    .string "If it isn't {PLAYER}!\p"
    .string "Lately, all everyone talks about\n"
    .string "is you.\p"
    .string "I'm feeling lonesome because I\n"
    .string "prefer {STR_VAR_1}.$"

SaffronCity_PokemonTrainerFanClub_Text_YouReallyAreAmazing::
    .string "Amazing!\n"
    .string "{PLAYER}, you really are amazing!\p"
    .string "Instead of just watching, maybe\n"
    .string "I should become a Trainer, too.$"

SaffronCity_PokemonTrainerFanClub_Text_ImYourOnlyFan::
    .string "I'm your only fan…\n"
    .string "Sigh… This is lonely…\p"
    .string "Can't you try harder and make the\n"
    .string "others take notice of you?$"

SaffronCity_PokemonTrainerFanClub_Text_WhyCantOthersSeeMastersDignity::
    .string "Master {STR_VAR_1} is so dignified…\n"
    .string "He is so my type.\p"
    .string "Why can't the others see the\n"
    .string "dignity he simply oozes?$"

SaffronCity_PokemonTrainerFanClub_Text_BelieveInMasterWithAllMyHeart::
    .string "I believe in Master {STR_VAR_1}\n"
    .string "with all my heart.\p"
    .string "Even if I am the only one to\n"
    .string "believe in him.\p"
    .string "I won't ever feel lonesome, though.\p"
    .string "Not if I keep thinking about Master\n"
    .string "{STR_VAR_1}.$"

SaffronCity_PokemonTrainerFanClub_Text_YourBattleStyleIsEducational::
    .string "Hiyah!\p"
    .string "Your battling style is most\n"
    .string "educational.\p"
    .string "I hope that you will keep plugging\n"
    .string "away at success, hiyah!$"

SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingYourFan::
    .string "Instead of just watching others\n"
    .string "battle, battle yourself!\p"
    .string "…My Dojo's Master chewed me out\n"
    .string "like that…\p"
    .string "But I won't let that stop me from\n"
    .string "being your fan!\p"
    .string "I can't stop being your fan!$"

SaffronCity_PokemonTrainerFanClub_Text_OnlyMasterHasMyRespect::
    .string "Hiyah! There is but one Trainer\n"
    .string "who has my respect.\p"
    .string "And that is none other than my\n"
    .string "Master at the Fighting Dojo.\p"
    .string "You should become a fan of my\n"
    .string "Master like me! Hiyah!$"

SaffronCity_PokemonTrainerFanClub_Text_NeverBeFanOfAnyoneButMaster::
    .string "Hiyah! I respect my Master at the\n"
    .string "Fighting Dojo.\p"
    .string "I will never become a fan of\n"
    .string "anyone other than my Master!\p"
    .string "I will even sneak out of the Dojo\n"
    .string "to spread word of his greatness.\p"
    .string "Hiyah!$"

SaffronCity_PokemonTrainerFanClub_Text_CantSeeTheTV:
	.string "Hey, down in front!\n"
	.string "I can't see the TV!$"

PokemonJournal_Text_SpecialFeatureBruno::
    .string "Pokémon Journal\p"
    .string "Special Feature:\n"
    .string "Elite Four's Bruno!\p"
    .string "Bruno apparently joined the Elite\n"
    .string "Four out of his burning ambition to\l"
    .string "battle the best Trainers.$"
