@ Note: data/scripts/berry_blender.inc is for the same map, so shares local IDs
.set LOCALID_RECEPTIONIST, 1
.set LOCALID_LINK_RECEPTIONIST, 2
.set LOCALID_ARTIST, 4
.set LOCALID_ARTIST_LINK, 11

CeladonCity_ContestLobby_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_ContestLobby_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonCity_ContestLobby_OnFrame
	.byte 0

@ Some scripts for this room are split into data/scripts/contest_hall and data/scripts/berry_blender

CeladonCity_ContestLobby_OnTransition:
	call CeladonCity_ContestLobby_EventScript_TryShowContestReporter
	call CeladonCity_ContestLobby_EventScript_TryShowBlendMaster
	end

CeladonCity_ContestLobby_EventScript_TryShowBlendMaster::
	getpokenewsactive POKENEWS_BLENDMASTER
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_ContestLobby_EventScript_ShowBlendMaster
	clearflag FLAG_HIDE_CELADON_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
	setflag FLAG_HIDE_CELADON_CONTEST_HALL_BLEND_MASTER
	return

CeladonCity_ContestLobby_EventScript_ShowBlendMaster::
	setflag FLAG_HIDE_CELADON_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
	clearflag FLAG_HIDE_CELADON_CONTEST_HALL_BLEND_MASTER
	return

CeladonCity_ContestLobby_OnFrame:
	map_script_2 VAR_CELADON_CONTEST_LOBBY_STATE, 1, CeladonCity_ContestLobby_EventScript_TryDoContestArtist
	map_script_2 VAR_CELADON_CONTEST_LOBBY_STATE, 2, CeladonCity_ContestLobby_EventScript_TryDoLinkContestArtist
	.2byte 0

CeladonCity_ContestLobby_EventScript_TryDoContestArtist::
	goto_if_set FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR, CeladonCity_ContestLobby_EventScript_ContestArtist
	setvar VAR_CELADON_CONTEST_LOBBY_STATE, 0
	end

CeladonCity_ContestLobby_EventScript_ContestArtist::
	lockall
	addobject LOCALID_ARTIST
	applymovement LOCALID_ARTIST, CeladonCity_ContestLobby_Movement_ArtistApproachPlayer
	waitmovement LOCALID_ARTIST
	applymovement OBJ_EVENT_ID_PLAYER, CeladonCity_ContestLobby_Movement_PlayerFaceArtist
	waitmovement 0
	msgbox CeladonCity_ContestLobby_Text_YourPokemonSpurredMeToPaint, MSGBOX_DEFAULT
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_ARTIST
	lockall
	msgbox CeladonCity_ContestLobby_Text_ShouldITakePaintingToMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeladonCity_ContestLobby_EventScript_TakePaintingToMuseum
	goto_if_eq VAR_RESULT, NO, CeladonCity_ContestLobby_EventScript_ConfirmDontTakePainting
	releaseall
	end

CeladonCity_ContestLobby_EventScript_TakePaintingToMuseum::
	msgbox CeladonCity_ContestLobby_Text_IllTakePaintingToMuseum, MSGBOX_DEFAULT
	closemessage
	special SaveMuseumContestPainting
	setvar VAR_CELADON_CONTEST_LOBBY_STATE, 0
	specialvar VAR_RESULT, GiveMonArtistRibbon
	call_if_eq VAR_RESULT, TRUE, CeladonCity_ContestLobby_EventScript_ReceivedArtistRibbon
	applymovement LOCALID_ARTIST, CeladonCity_ContestLobby_Movement_ArtistExit
	waitmovement 0
	removeobject LOCALID_ARTIST
	call CeladonCity_ContestLobby_EventScript_UpdateMuseumPatrons
	call CeladonCity_ContestLobby_EventScript_SetPaintingFlag
	releaseall
	end

CeladonCity_ContestLobby_EventScript_ConfirmDontTakePainting::
	msgbox CeladonCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeladonCity_ContestLobby_EventScript_TakePaintingToMuseum
	msgbox CeladonCity_ContestLobby_Text_FineThatsTheWayItIs, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTIST, CeladonCity_ContestLobby_Movement_ArtistExit
	waitmovement 0
	setvar VAR_CELADON_CONTEST_LOBBY_STATE, 0
	removeobject LOCALID_ARTIST
	releaseall
	end

CeladonCity_ContestLobby_EventScript_ReceivedArtistRibbon::
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	special BufferContestWinnerMonName
	applymovement LOCALID_ARTIST, CeladonCity_ContestLobby_Movement_ArtistBeginToExit
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_ARTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ARTIST, CeladonCity_ContestLobby_Movement_ArtistReturnToPlayer
	waitmovement 0
	msgbox CeladonCity_ContestLobby_Text_TakeMementoOfPainting, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox CeladonCity_ContestLobby_Text_ReceivedARibbon, MSGBOX_DEFAULT
	waitfanfare
	msgbox CeladonCity_ContestLobby_Text_PutTheRibbonOnMon, MSGBOX_DEFAULT
	msgbox CeladonCity_ContestLobby_Text_OkaySeeYou, MSGBOX_DEFAULT
	closemessage
	return

CeladonCity_ContestLobby_EventScript_UpdateMuseumPatrons::
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 1, CeladonCity_ContestLobby_EventScript_ShowPatron1
	case 2, CeladonCity_ContestLobby_EventScript_ShowPatron2
	case 3, CeladonCity_ContestLobby_EventScript_ShowPatron3
	case 4, CeladonCity_ContestLobby_EventScript_ShowPatron4
	case 5, CeladonCity_ContestLobby_EventScript_ShowTourists
	return

CeladonCity_ContestLobby_EventScript_ShowPatron1::
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1
	return

CeladonCity_ContestLobby_EventScript_ShowPatron2::
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2
	return

CeladonCity_ContestLobby_EventScript_ShowPatron3::
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3
	return

CeladonCity_ContestLobby_EventScript_ShowPatron4::
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4
	return

CeladonCity_ContestLobby_EventScript_ShowTourists::
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS
	return

CeladonCity_ContestLobby_EventScript_SetPaintingFlag::
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, CeladonCity_ContestLobby_EventScript_MadeCoolPainting
	case CONTEST_CATEGORY_BEAUTY, CeladonCity_ContestLobby_EventScript_MadeBeautyPainting
	case CONTEST_CATEGORY_CUTE, CeladonCity_ContestLobby_EventScript_MadeCutePainting
	case CONTEST_CATEGORY_SMART, CeladonCity_ContestLobby_EventScript_MadeSmartPainting
	case CONTEST_CATEGORY_TOUGH, CeladonCity_ContestLobby_EventScript_MadeToughPainting
	return

CeladonCity_ContestLobby_EventScript_MadeCoolPainting::
	setflag FLAG_COOL_PAINTING_MADE
	return

CeladonCity_ContestLobby_EventScript_MadeBeautyPainting::
	setflag FLAG_BEAUTY_PAINTING_MADE
	return

CeladonCity_ContestLobby_EventScript_MadeCutePainting::
	setflag FLAG_CUTE_PAINTING_MADE
	return

CeladonCity_ContestLobby_EventScript_MadeSmartPainting::
	setflag FLAG_SMART_PAINTING_MADE
	return

CeladonCity_ContestLobby_EventScript_MadeToughPainting::
	setflag FLAG_TOUGH_PAINTING_MADE
	return

CeladonCity_ContestLobby_Movement_ArtistApproachPlayer:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CeladonCity_ContestLobby_Movement_ArtistExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeladonCity_ContestLobby_Movement_PlayerFaceArtist:
	walk_in_place_faster_left
	step_end

CeladonCity_ContestLobby_Movement_ArtistBeginToExit:
	walk_down
	walk_down
	walk_down
	step_end

CeladonCity_ContestLobby_Movement_ArtistReturnToPlayer:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_right
	step_end

CeladonCity_ContestLobby_EventScript_TryDoLinkContestArtist::
	goto_if_set FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR, CeladonCity_ContestLobby_EventScript_LinkContestArtist
	setvar VAR_CELADON_CONTEST_LOBBY_STATE, 0
	end

CeladonCity_ContestLobby_EventScript_LinkContestArtist::
	lockall
	addobject LOCALID_ARTIST_LINK
	applymovement LOCALID_ARTIST_LINK, CeladonCity_ContestLobby_Movement_LinkArtistApproachPlayer
	waitmovement LOCALID_ARTIST_LINK
	applymovement OBJ_EVENT_ID_PLAYER, CeladonCity_ContestLobby_Movement_PlayerFaceLinkArtist
	waitmovement 0
	msgbox CeladonCity_ContestLobby_Text_YourPokemonSpurredMeToPaint, MSGBOX_DEFAULT
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_ARTIST
	msgbox CeladonCity_ContestLobby_Text_ShouldITakePaintingToMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeladonCity_ContestLobby_EventScript_TakePaintingToMuseumLink
	goto_if_eq VAR_RESULT, NO, CeladonCity_ContestLobby_EventScript_ConfirmDontTakePaintingLink
	end

CeladonCity_ContestLobby_EventScript_TakePaintingToMuseumLink::
	msgbox CeladonCity_ContestLobby_Text_IllTakePaintingToMuseum, MSGBOX_DEFAULT
	closemessage
	special SaveMuseumContestPainting
	setvar VAR_CELADON_CONTEST_LOBBY_STATE, 0
	specialvar VAR_RESULT, GiveMonArtistRibbon
	call_if_eq VAR_RESULT, TRUE, CeladonCity_ContestLobby_EventScript_ReceivedLinkArtistRibbon
	applymovement LOCALID_ARTIST_LINK, CeladonCity_ContestLobby_Movement_LinkArtistExit
	waitmovement 0
	removeobject LOCALID_ARTIST_LINK
	call CeladonCity_ContestLobby_EventScript_UpdateMuseumPatrons
	call CeladonCity_ContestLobby_EventScript_SetPaintingFlag
	releaseall
	end

CeladonCity_ContestLobby_EventScript_ConfirmDontTakePaintingLink::
	msgbox CeladonCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeladonCity_ContestLobby_EventScript_TakePaintingToMuseumLink
	msgbox CeladonCity_ContestLobby_Text_FineThatsTheWayItIs, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTIST_LINK, CeladonCity_ContestLobby_Movement_LinkArtistExit
	waitmovement 0
	setvar VAR_CELADON_CONTEST_LOBBY_STATE, 0
	removeobject LOCALID_ARTIST_LINK
	releaseall
	end

CeladonCity_ContestLobby_EventScript_ReceivedLinkArtistRibbon::
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	setflag FLAG_SYS_RIBBON_GET
	special BufferContestWinnerMonName
	applymovement LOCALID_ARTIST_LINK, CeladonCity_ContestLobby_Movement_LinkArtistBeginExit
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_ARTIST_LINK, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ARTIST_LINK, CeladonCity_ContestLobby_Movement_LinkArtistReturnToPlayer
	waitmovement 0
	msgbox CeladonCity_ContestLobby_Text_TakeMementoOfPainting, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox CeladonCity_ContestLobby_Text_ReceivedARibbon, MSGBOX_DEFAULT
	waitfanfare
	msgbox CeladonCity_ContestLobby_Text_PutTheRibbonOnMon, MSGBOX_DEFAULT
	msgbox CeladonCity_ContestLobby_Text_OkaySeeYou, MSGBOX_DEFAULT
	closemessage
	return

CeladonCity_ContestLobby_Movement_LinkArtistApproachPlayer:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CeladonCity_ContestLobby_Movement_LinkArtistExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeladonCity_ContestLobby_Movement_PlayerFaceLinkArtist:
	walk_in_place_faster_right
	step_end

CeladonCity_ContestLobby_Movement_LinkArtistBeginExit:
	walk_down
	walk_down
	walk_down
	step_end

CeladonCity_ContestLobby_Movement_LinkArtistReturnToPlayer:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

@ EventScript_SpeakToContestReceptionist either ends or returns after a contest entry is submitted
CeladonCity_ContestLobby_EventScript_ContestReceptionist::
	special ClearLinkContestFlags
	specialvar VAR_RESULT, IsContestDebugActive  @ Always FALSE
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_ContestLobby_EventScript_SetDebug
	call CeladonCity_ContestLobby_EventScript_SpeakToContestReceptionist
	call CeladonCity_ContestLobby_EventScript_LeadToContestHall
	special SetContestTrainerGfxIds
	call CeladonCity_ContestLobby_EventScript_SetPlayerGfx
	call CeladonCity_ContestLobby_EventScript_SetContestType
	call CeladonCity_ContestLobby_EventScript_WarpToContestHall
	waitstate
	end

CeladonCity_ContestLobby_EventScript_SetContestType::
	switch VAR_CONTEST_RANK
	case CONTEST_RANK_NORMAL, CeladonCity_ContestLobby_EventScript_SetNormalContestType
	case CONTEST_RANK_SUPER, CeladonCity_ContestLobby_EventScript_SetSuperContestType
	case CONTEST_RANK_HYPER, CeladonCity_ContestLobby_EventScript_SetHyperContestType
	case CONTEST_RANK_MASTER, CeladonCity_ContestLobby_EventScript_SetMasterContestType
	return

CeladonCity_ContestLobby_EventScript_SetNormalContestType::
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
	return

CeladonCity_ContestLobby_EventScript_SetSuperContestType::
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
	return

CeladonCity_ContestLobby_EventScript_SetHyperContestType::
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER
	return

CeladonCity_ContestLobby_EventScript_SetMasterContestType::
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_MASTER
	return

@ Functionally unused
CeladonCity_ContestLobby_EventScript_SetDebug::
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
	additem ITEM_CONTEST_PASS
	setvar VAR_0x800B, 8
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	setvar VAR_CELADON_CONTEST_LOBBY_STATE, 1
	setflag FLAG_SYS_RIBBON_GET
	end

CeladonCity_ContestLobby_EventScript_WarpToContestHall::
	setflag FLAG_ENTERED_CONTEST
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, CeladonCity_ContestLobby_EventScript_WarpToCoolContestHall
	case CONTEST_CATEGORY_BEAUTY, CeladonCity_ContestLobby_EventScript_WarpToBeautyContestHall
	case CONTEST_CATEGORY_CUTE, CeladonCity_ContestLobby_EventScript_WarpToCuteContestHall
	case CONTEST_CATEGORY_SMART, CeladonCity_ContestLobby_EventScript_WarpToSmartContestHall
	case CONTEST_CATEGORY_TOUGH, CeladonCity_ContestLobby_EventScript_WarpToToughContestHall
	return

CeladonCity_ContestLobby_EventScript_WarpToCoolContestHall::
	setwarp MAP_CONTEST_HALL_COOL, 7, 5
	special DoContestHallWarp
	waitstate
	return

CeladonCity_ContestLobby_EventScript_WarpToBeautyContestHall::
	setwarp MAP_CONTEST_HALL_BEAUTY, 7, 5
	special DoContestHallWarp
	waitstate
	return

CeladonCity_ContestLobby_EventScript_WarpToCuteContestHall::
	setwarp MAP_CONTEST_HALL_CUTE, 7, 5
	special DoContestHallWarp
	waitstate
	return

CeladonCity_ContestLobby_EventScript_WarpToSmartContestHall::
	setwarp MAP_CONTEST_HALL_SMART, 7, 5
	special DoContestHallWarp
	waitstate
	return

CeladonCity_ContestLobby_EventScript_WarpToToughContestHall::
	setwarp MAP_CONTEST_HALL_TOUGH, 7, 5
	special DoContestHallWarp
	waitstate
	return

CeladonCity_ContestLobby_EventScript_LeadToContestHall::
	lockall
	applymovement LOCALID_RECEPTIONIST, CeladonCity_ContestLobby_Movement_ReceptionistApproachCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 12, 2, METATILE_Contest_WallShadow, TRUE
	setmetatile 12, 3, METATILE_Contest_FloorShadow, TRUE
	special DrawWholeMapView
	applymovement LOCALID_RECEPTIONIST, CeladonCity_ContestLobby_Movement_ReceptionistExitCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 12, 2, METATILE_Contest_CounterFlap_Top, TRUE
	setmetatile 12, 3, METATILE_Contest_CounterFlap_Bottom, TRUE
	special DrawWholeMapView
	delay 20
	applymovement LOCALID_RECEPTIONIST, CeladonCity_ContestLobby_Movement_ReceptionistFacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CeladonCity_ContestLobby_Movement_PlayerApproachReceptionist
	waitmovement 0
	msgbox CeladonCity_ContestLobby_Text_ComeThroughHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RECEPTIONIST, CeladonCity_ContestLobby_Movement_ReceptionistWalkToContestHall
	applymovement OBJ_EVENT_ID_PLAYER, CeladonCity_ContestLobby_Movement_PlayerWalkToContestHall
	waitmovement 0
	releaseall
	return

CeladonCity_ContestLobby_Movement_PlayerWalkToContestHall:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

CeladonCity_ContestLobby_Movement_PlayerApproachReceptionist:
	walk_in_place_faster_left
	walk_left
	step_end

CeladonCity_ContestLobby_Movement_ReceptionistApproachCounter:
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

CeladonCity_ContestLobby_Movement_ReceptionistExitCounter:
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

CeladonCity_ContestLobby_Movement_ReceptionistWalkToContestHall:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

CeladonCity_ContestLobby_Movement_ReceptionistFacePlayer:
	walk_in_place_faster_right
	step_end

CeladonCity_ContestLobby_EventScript_BlackBelt::
	msgbox CeladonCity_ContestLobby_Text_MasterRankHereICome, MSGBOX_NPC
	end

CeladonCity_ContestLobby_EventScript_Girl::
	msgbox CeladonCity_ContestLobby_Text_WholeVarietyOfPokemonHere, MSGBOX_NPC
	end

CeladonCity_ContestLobby_EventScript_Artist::
	msgbox CeladonCity_ContestLobby_Text_ContestFeastForEyes, MSGBOX_NPC
	end

CeladonCity_ContestLobby_EventScript_FatMan::
	msgbox CeladonCity_ContestLobby_Text_ToughContestIsExtreme, MSGBOX_NPC
	end

CeladonCity_ContestLobby_EventScript_Fisherman::
	msgbox CeladonCity_ContestLobby_Text_LavishedCareOnMon, MSGBOX_NPC
	end

CeladonCity_ContestLobby_EventScript_NinjaBoy::
	msgbox CeladonCity_ContestLobby_Text_MadePokeblocksWithFamily, MSGBOX_NPC
	end

CeladonCity_ContestLobby_EventScript_ContestWinner1::
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_1
	releaseall
	end

CeladonCity_ContestLobby_EventScript_ContestWinner2::
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_2
	releaseall
	end

CeladonCity_ContestLobby_EventScript_ContestWinner3::
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_3
	releaseall
	end

CeladonCity_ContestLobby_EventScript_ContestWinner4::
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_4
	releaseall
	end

CeladonCity_ContestLobby_EventScript_ContestWinner5::
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_5
	releaseall
	end

CeladonCity_ContestLobby_EventScript_ContestWinner6::
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_6
	releaseall
	end

CeladonCity_ContestLobby_EventScript_Blender3Boy::
	msgbox BerryBlender_Text_LetsGetBlendingAlready, MSGBOX_NPC
	end

CeladonCity_ContestLobby_EventScript_Blender3Girl::
	msgbox BerryBlender_Text_WhatKindOfPokeblockWillIGet, MSGBOX_NPC
	end

CeladonCity_ContestLobby_EventScript_BerryBlenderSpeedRecords::
	lockall
	special ShowBerryBlenderRecordWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

CeladonCity_ContestLobby_EventScript_LinkContestResults::
	lockall
	frontier_results FACILITY_LINK_CONTEST
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

CeladonCity_ContestLobby_EventScript_BlendMaster::
	lock
	faceplayer
	msgbox BerryBlender_Text_BlendWithTheBlendMaster, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_FaceOriginalDirection
	end

CeladonCity_ContestLobby_EventScript_BlendMasterOnlooker1::
	lock
	msgbox BerryBlender_Text_WhoaAwesome, MSGBOX_DEFAULT
	release
	end

CeladonCity_ContestLobby_EventScript_BlendMasterOnlooker2::
	lock
	msgbox BerryBlender_Text_WickedlyFast, MSGBOX_DEFAULT
	release
	end

CeladonCity_ContestLobby_EventScript_BlendMasterOnlooker3::
	lock
	msgbox BerryBlender_Text_WhatAnExpert, MSGBOX_DEFAULT
	release
	end

CeladonCity_ContestLobby_EventScript_BlendMasterOnlooker4::
	lock
	faceplayer
	msgbox BerryBlender_Text_MadeAmazingPokeblocksWithMaster, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_FaceOriginalDirection
	end

CeladonCity_ContestLobby_EventScript_BlendMasterOnlooker5::
	lock
	faceplayer
	msgbox BerryBlender_Text_QualitiesOfBlendMaster, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_FaceOriginalDirection
	end

CeladonCity_ContestLobby_EventScript_BlendMasterOnlooker6::
	lock
	faceplayer
	msgbox BerryBlender_Text_MasterWorksOnSkillsInMountains, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_FaceOriginalDirection
	end

CeladonCity_ContestLobby_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_ContestLobby_EventScript_LinkContestReceptionist::
	special ClearLinkContestFlags
	lock
	faceplayer
	msgbox CeladonCity_ContestLobby_Text_LinkContestReception, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_AskEnterLinkContest
	end

CeladonCity_ContestLobby_EventScript_AskEnterLinkContest::
	message CeladonCity_ContestLobby_Text_EnterContest3
	waitmessage
	multichoice 0, 0, MULTI_ENTERINFO, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_ContestLobby_EventScript_TryEnterLinkContest
	case 1, CeladonCity_ContestLobby_EventScript_LinkContestInfo
	case 2, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	end

CeladonCity_ContestLobby_EventScript_TryEnterLinkContest::
	msgbox CeladonCity_ContestLobby_Text_ProgressWillBeSaved, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	message CeladonCity_ContestLobby_Text_WhichContestMode
	waitmessage
	specialvar VAR_TEMP_D, IsWirelessAdapterConnected
	multichoice 0, 0, MULTI_LINK_CONTEST_MODE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_ContestLobby_EventScript_EmeraldMode  @ Shortened to E-Mode
	case 1, CeladonCity_ContestLobby_EventScript_GlobalMode   @ Shortened to G-Mode
	case 2, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	end

CeladonCity_ContestLobby_EventScript_EmeraldMode::
	setvar VAR_TEMP_C, 0
	goto CeladonCity_ContestLobby_EventScript_ChooseLinkContestType
	end

CeladonCity_ContestLobby_EventScript_GlobalMode::
	setvar VAR_TEMP_C, 1
	goto_if_eq VAR_TEMP_D, 1, CeladonCity_ContestLobby_EventScript_CancelLinkNoWirelessGMode
	goto CeladonCity_ContestLobby_EventScript_ChooseLinkContestType
	end

CeladonCity_ContestLobby_EventScript_ChooseLinkContestType::
	message CeladonCity_ContestLobby_Text_EnterWhichContest3
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_TYPE, FALSE
	switch VAR_RESULT
	case CONTEST_CATEGORIES_COUNT, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto CeladonCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

CeladonCity_ContestLobby_EventScript_LinkContestInfo::
	message CeladonCity_ContestLobby_Text_WhichTopic2
	waitmessage
	multichoice 0, 0, MULTI_LINK_CONTEST_INFO, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_ContestLobby_EventScript_ExplainLinkContest
	case 1, CeladonCity_ContestLobby_EventScript_ExplainEMode
	case 2, CeladonCity_ContestLobby_EventScript_ExplainGMode
	case 3, CeladonCity_ContestLobby_EventScript_AskEnterLinkContest
	case MULTI_B_PRESSED, CeladonCity_ContestLobby_EventScript_AskEnterLinkContest
	end

CeladonCity_ContestLobby_EventScript_ExplainLinkContest::
	msgbox CeladonCity_ContestLobby_Text_ExplainLinkContest, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_LinkContestInfo
	end

CeladonCity_ContestLobby_EventScript_ExplainEMode::
	msgbox CeladonCity_ContestLobby_Text_ExplainEMode, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_LinkContestInfo
	end

CeladonCity_ContestLobby_EventScript_ExplainGMode::
	msgbox CeladonCity_ContestLobby_Text_ExplainGMode, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_LinkContestInfo
	end

CeladonCity_ContestLobby_EventScript_CancelLinkContest::
	special CloseLink
	msgbox CeladonCity_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
	release
	end

CeladonCity_ContestLobby_EventScript_ChooseLinkContestMon::
	msgbox CeladonCity_ContestLobby_Text_EnterWhichPokemon3, MSGBOX_DEFAULT
	setvar VAR_CONTEST_RANK, 0
	choosecontestmon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	special TryEnterContestMon
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST, CeladonCity_ContestLobby_EventScript_LinkCantEnterLowRank
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_EQUAL_RANK, CeladonCity_ContestLobby_EventScript_EnterMonForLinkContest
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_HIGH_RANK, CeladonCity_ContestLobby_EventScript_EnterMonForLinkContest
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_EGG, CeladonCity_ContestLobby_EventScript_LinkCantEnterEgg
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_FAINTED, CeladonCity_ContestLobby_EventScript_LinkCantEnterFainted
	end

CeladonCity_ContestLobby_EventScript_LinkCantEnterLowRank::
	msgbox CeladonCity_ContestLobby_Text_MonNotQualifiedForRank, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

CeladonCity_ContestLobby_EventScript_LinkCantEnterEgg::
	msgbox CeladonCity_ContestLobby_Text_EggCannotTakePart2, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

CeladonCity_ContestLobby_EventScript_LinkCantEnterFainted::
	msgbox CeladonCity_ContestLobby_Text_MonInNoCondition2, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

CeladonCity_ContestLobby_EventScript_EnterMonForLinkContest::
	copyvar VAR_0x8008, VAR_0x8004
	goto CeladonCity_ContestLobby_EventScript_TrySetUpLinkContest
	end

CeladonCity_ContestLobby_EventScript_TrySetUpLinkContest::
	goto_if_eq VAR_TEMP_D, 1, CeladonCity_ContestLobby_EventScript_SetLinkGroupType
	goto_if_ge VAR_TEMP_D, 2, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	message CeladonCity_ContestLobby_Text_PleaseWaitBButtonCancel
	waitmessage
	copyvar VAR_0x8004, VAR_RESULT
	call_if_eq VAR_TEMP_C, 0, CeladonCity_ContestLobby_EventScript_TryLinkEMode
	call_if_eq VAR_TEMP_C, 1, CeladonCity_ContestLobby_EventScript_TryLinkGMode
	goto_if_ge VAR_TEMP_C, 2, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CeladonCity_ContestLobby_EventScript_CancelLinkDifferentChoices
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CeladonCity_ContestLobby_EventScript_CancelLinkDifferentChoices
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CeladonCity_ContestLobby_EventScript_CancelLinkError
	goto_if_eq VAR_RESULT, LINKUP_FAILED_CONTEST_GMODE, CeladonCity_ContestLobby_EventScript_CancelLinkModeDifference
	messageinstant CeladonCity_ContestLobby_Text_Transmitting
	contestlinktransfer
	switch VAR_0x8004
	case 0, CeladonCity_ContestLobby_EventScript_StartLinkContest
	case 1, CeladonCity_ContestLobby_EventScript_CancelLinkDifferentContest
	case 2, CeladonCity_ContestLobby_EventScript_CancelLinkTransmissionError
	end

CeladonCity_ContestLobby_EventScript_TryLinkEMode::
	special TryContestEModeLinkup
	waitstate
	return

CeladonCity_ContestLobby_EventScript_TryLinkGMode::
	special TryContestGModeLinkup
	waitstate
	return

CeladonCity_ContestLobby_EventScript_CancelLinkDifferentContest::
	msgbox CeladonCity_ContestLobby_Text_PlayersChoseDifferentContest, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_CancelLinkContest
	end

CeladonCity_ContestLobby_EventScript_CancelLinkDifferentChoices::
	msgbox CeladonCity_ContestLobby_Text_PlayersMadeDifferentChoice, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_CancelLinkContest
	end

CeladonCity_ContestLobby_EventScript_CancelLinkModeDifference::
	msgbox CeladonCity_ContestLobby_Text_PlayerAt4PCounterUseGMode, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_CancelLinkContest
	end

CeladonCity_ContestLobby_EventScript_CancelLinkError::
	special CloseLink
	msgbox Text_LinkErrorPleaseReset, MSGBOX_DEFAULT
	release
	end

CeladonCity_ContestLobby_EventScript_CancelLinkNoWirelessGMode::
	special CloseLink
	msgbox CeladonCity_ContestLobby_Text_NoWirelessAdapterInGMode, MSGBOX_DEFAULT
	release
	end

CeladonCity_ContestLobby_EventScript_CancelLinkTransmissionError::
	msgbox CeladonCity_ContestLobby_Text_TransmissionError, MSGBOX_DEFAULT
	goto CeladonCity_ContestLobby_EventScript_CancelLinkContest
	end

CeladonCity_ContestLobby_EventScript_StartLinkContest::
	special GetContestPlayerId
	addvar VAR_0x8004, 1
	buffernumberstring STR_VAR_2, VAR_0x8004
	messageautoscroll CeladonCity_ContestLobby_Text_YourMonIsEntryNumX
	waitmessage
	subvar VAR_0x8004, 1
	call CeladonCity_ContestLobby_EventScript_LeadToLinkContestHall
	setvar VAR_CONTEST_HALL_STATE, 1
	special SetLinkContestPlayerGfx
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	call CeladonCity_ContestLobby_EventScript_WarpToContestHall
	end

CeladonCity_ContestLobby_EventScript_SetLinkGroupType::
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_COOL, CeladonCity_ContestLobby_EventScript_SetLinkGroupCoolContest
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_BEAUTY, CeladonCity_ContestLobby_EventScript_SetLinkGroupBeautyContest
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_CUTE, CeladonCity_ContestLobby_EventScript_SetLinkGroupCuteContest
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_SMART, CeladonCity_ContestLobby_EventScript_SetLinkGroupSmartContest
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_TOUGH, CeladonCity_ContestLobby_EventScript_SetLinkGroupToughContest
	goto CeladonCity_ContestLobby_EventScript_DecideLinkLeader
	end

CeladonCity_ContestLobby_EventScript_SetLinkGroupCoolContest::
	setvar VAR_0x8004, LINK_GROUP_COOL_CONTEST
	return

CeladonCity_ContestLobby_EventScript_SetLinkGroupBeautyContest::
	setvar VAR_0x8004, LINK_GROUP_BEAUTY_CONTEST
	return

CeladonCity_ContestLobby_EventScript_SetLinkGroupCuteContest::
	setvar VAR_0x8004, LINK_GROUP_CUTE_CONTEST
	return

CeladonCity_ContestLobby_EventScript_SetLinkGroupSmartContest::
	setvar VAR_0x8004, LINK_GROUP_SMART_CONTEST
	return

CeladonCity_ContestLobby_EventScript_SetLinkGroupToughContest::
	setvar VAR_0x8004, LINK_GROUP_TOUGH_CONTEST
	return

CeladonCity_ContestLobby_EventScript_DecideLinkLeader::
	message CeladonCity_ContestLobby_Text_PleaseDecideLinkLeader
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_ContestLobby_EventScript_TryJoinGroup
	case 1, CeladonCity_ContestLobby_EventScript_TryLeadGroup
	case 2, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, CeladonCity_ContestLobby_EventScript_CancelLinkContest
	end

CeladonCity_ContestLobby_EventScript_TryLeadGroup::
	call CeladonCity_ContestLobby_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CeladonCity_ContestLobby_EventScript_LinkLeaderDecided
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CeladonCity_ContestLobby_EventScript_DecideLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CeladonCity_ContestLobby_EventScript_TryLeadGroup
	release
	end

CeladonCity_ContestLobby_EventScript_TryJoinGroup::
	call CeladonCity_ContestLobby_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CeladonCity_ContestLobby_EventScript_LinkLeaderDecided
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CeladonCity_ContestLobby_EventScript_DecideLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CeladonCity_ContestLobby_EventScript_TryJoinGroup
	release
	end

CeladonCity_ContestLobby_EventScript_TryBecomeLinkLeader::
	special TryBecomeLinkLeader
	waitstate
	return

CeladonCity_ContestLobby_EventScript_TryJoinLinkGroup::
	special TryJoinLinkGroup
	waitstate
	return

CeladonCity_ContestLobby_EventScript_LinkLeaderDecided::
	messageinstant CeladonCity_ContestLobby_Text_Transmitting
	contestlinktransfer
	goto CeladonCity_ContestLobby_EventScript_StartLinkContest
	end

CeladonCity_ContestLobby_EventScript_LeadToLinkContestHall::
	messageautoscroll CeladonCity_ContestLobby_Text_ContestBeginShortly
	waitmessage
	delay 20
	closemessage
	applymovement LOCALID_LINK_RECEPTIONIST, CeladonCity_ContestLobby_Movement_LinkReceptionistApproachCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 17, 2, METATILE_Contest_WallShadow, TRUE
	setmetatile 17, 3, METATILE_Contest_FloorShadow, TRUE
	special DrawWholeMapView
	applymovement LOCALID_LINK_RECEPTIONIST, CeladonCity_ContestLobby_Movement_LinkReceptionistExitCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 17, 2, METATILE_Contest_CounterFlap_Top, TRUE
	setmetatile 17, 3, METATILE_Contest_CounterFlap_Bottom, TRUE
	special DrawWholeMapView
	delay 20
	applymovement LOCALID_LINK_RECEPTIONIST, CeladonCity_ContestLobby_Movement_LinkReceptionistFacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CeladonCity_ContestLobby_Movement_PlayerApproachLinkReceptionist
	waitmovement 0
	messageautoscroll CeladonCity_ContestLobby_Text_ComeThroughHere
	waitmessage
	delay 20
	closemessage
	call CeladonCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer
	applymovement LOCALID_LINK_RECEPTIONIST, CeladonCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall
	applymovement OBJ_EVENT_ID_PLAYER, CeladonCity_ContestLobby_Movement_PlayerWalkToLinkContestHall
	waitmovement 0
	release
	return

CeladonCity_ContestLobby_Movement_PlayerWalkToLinkContestHall:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

CeladonCity_ContestLobby_Movement_PlayerApproachLinkReceptionist:
	walk_right
	step_end

CeladonCity_ContestLobby_Movement_LinkReceptionistApproachCounter:
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

CeladonCity_ContestLobby_Movement_LinkReceptionistExitCounter:
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

CeladonCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

CeladonCity_ContestLobby_Movement_LinkReceptionistFacePlayer:
	walk_in_place_faster_left
	step_end

CeladonCity_ContestLobby_EventScript_LittleGirl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKEBLOCK_CASE, CeladonCity_ContestLobby_EventScript_LittleGirlHaveCase
	msgbox CeladonCity_ContestLobby_Text_LadyGaveMePokeblockCase, MSGBOX_DEFAULT
	release
	end

CeladonCity_ContestLobby_EventScript_LittleGirlHaveCase::
	msgbox CeladonCity_ContestLobby_Text_MakePokeblocksDifferentBerries, MSGBOX_DEFAULT
	release
	end

CeladonCity_ContestLobby_Text_LadyGaveMePokeblockCase:
	.string "Yippee!\p"
	.string "The lady at the reception counter\n"
	.string "gave me a case for {POKEBLOCK}s!$"

CeladonCity_ContestLobby_Text_MakePokeblocksDifferentBerries:
	.string "Make {POKEBLOCK}s and put them in there.\p"
	.string "When you make a {POKEBLOCK}, everyone\n"
	.string "has to put in a different Berry.$"

CeladonCity_ContestLobby_Text_YourPokemonSpurredMeToPaint:
	.string "Congratulations!\p"
	.string "I did a painting of your Pokémon to\n"
	.string "commemorate its victory…\p"
	.string "Well, your Pokémon's appeals were\n"
	.string "so fantastic, it spurred me into\l"
	.string "painting better than I usually do.\l"
	.string "Look, see?$"

CeladonCity_ContestLobby_Text_ShouldITakePaintingToMuseum:
	.string "What do you think? I'm confident in\n"
	.string "what I've done, but do you like it?\p"
	.string "A work of this caliber, it wouldn't look\n"
	.string "out of place in an art museum.\p"
	.string "Huh? An art museum really is looking\n"
	.string "for paintings?\p"
	.string "Do you think I should take this there?$"

CeladonCity_ContestLobby_Text_IllTakePaintingToMuseum:
	.string "What, really? Then, sure, I will take\n"
	.string "this painting there right now.\p"
	.string "I'll give it a proper title, too.\p"
	.string "I hope they'll like it and consider\n"
	.string "exhibiting this.\p"
	.string "Please check if they did accept this.\n"
	.string "Thank you!$"

CeladonCity_ContestLobby_Text_TakeMementoOfPainting:
	.string "Oh, that's right!\p"
	.string "As a memento of me painting your\n"
	.string "Pokémon, please take this.$"

CeladonCity_ContestLobby_Text_ReceivedARibbon:
	.string "{PLAYER} received a Ribbon.$"

CeladonCity_ContestLobby_Text_PutTheRibbonOnMon:
	.string "{PLAYER} put the Ribbon on\n"
	.string "{STR_VAR_1}.$"

CeladonCity_ContestLobby_Text_OkaySeeYou:
	.string "Okay, see you!$"

CeladonCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum:
	.string "Oh… Then, I guess I'll just take\n"
	.string "this home with me…\p"
	.string "But, you know, I would like to take\n"
	.string "this to the art museum… Okay?$"

CeladonCity_ContestLobby_Text_FineThatsTheWayItIs:
	.string "Oh, fine, that's the way it is.\n"
	.string "I will hang this in my own house.\p"
	.string "I'll just have to try harder next time.\n"
	.string "Well, be seeing you.$"

CeladonCity_ContestLobby_Text_MasterRankHereICome:
	.string "Hoo, boy… Master Rank Contests,\n"
	.string "here I come.\p"
	.string "The world will know that my dearest\n"
	.string "Pokémon is the cutest being in all\l"
	.string "existence. The time has come!\l"
	.string "Uheheheh.$"

CeladonCity_ContestLobby_Text_WholeVarietyOfPokemonHere:
	.string "You can see a whole variety of\n"
	.string "Pokémon here.\p"
	.string "That's why I make this place a regular\n"
	.string "part of my daily stroll.$"

CeladonCity_ContestLobby_Text_ContestFeastForEyes:
	.string "Wow, coming out to a Contest is\n"
	.string "a feast for these eyes!\p"
	.string "Would you look at all the Pokémon\n"
	.string "that just scream to be painted?$"

CeladonCity_ContestLobby_Text_ToughContestIsExtreme:
	.string "The Toughness Contest is like\n"
	.string "extreme, man!\p"
	.string "Those muscular appeals…\n"
	.string "Cascading sweat… I swoon!$"

CeladonCity_ContestLobby_Text_LavishedCareOnMon:
	.string "Day in and day out, I lavished my care\n"
	.string "on this Pokémon.\p"
	.string "Its condition is peaking.\n"
	.string "Today, victory is mine!$"

CeladonCity_ContestLobby_Text_MadePokeblocksWithFamily:
	.string "I made {POKEBLOCK}s with Mom, Dad, and\n"
	.string "Big Sister. They turned out great!\p"
	.string "I bet you can make smoother, better\n"
	.string "{POKEBLOCK}s if you have more people.$"

