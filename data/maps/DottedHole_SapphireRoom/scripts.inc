.equ LOCALID_SAPPHIRE, 1
.equ LOCALID_THIEF,    2

DottedHole_SapphireRoom_MapScripts::
    .byte 0

DottedHole_SapphireRoom_EventScript_Sapphire::
    lock
    faceplayer
    playfanfare MUS_RG_OBTAIN_KEY_ITEM
    message DottedHole_SapphireRoom_Text_FoundSapphire
    waitmessage
    waitfanfare
    closemessage
    setobjectxyperm LOCALID_THIEF, 5, 0
    addobject LOCALID_THIEF
    playse SE_FALL
    applymovement LOCALID_THIEF, DottedHole_SapphireRoom_Movement_ThiefFallIn
    waitmovement 0
    playse SE_M_STRENGTH
    compare VAR_FACING, DIR_NORTH
    call_if_eq DottedHole_SapphireRoom_EventScript_PlayerFaceThiefLeft
    compare VAR_FACING, DIR_SOUTH
    call_if_eq DottedHole_SapphireRoom_EventScript_PlayerFaceThiefLeft
    compare VAR_FACING, DIR_EAST
    call_if_eq DottedHole_SapphireRoom_EventScript_PlayerFaceThiefDown
    compare VAR_FACING, DIR_WEST
    call_if_eq DottedHole_SapphireRoom_EventScript_PlayerFaceThiefDown
    setvar VAR_0x8004, 3
    setvar VAR_0x8005, 0
    setvar VAR_0x8006, 12
    setvar VAR_0x8007, 3
    special ShakeCamera
    delay 60
    compare VAR_FACING, DIR_NORTH
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefLookAtSapphireNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefLookAtSapphireNorth
    compare VAR_FACING, DIR_EAST
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefLookAtSapphireEast
    compare VAR_FACING, DIR_WEST
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefLookAtSapphireEast
    msgbox DottedHole_SapphireRoom_Text_IWasRightInTailingYou, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_NORTH
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefGetSapphireNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefGetSapphireSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefGetSapphireEast
    compare VAR_FACING, DIR_WEST
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefGetSapphireWest
    removeobject LOCALID_SAPPHIRE
    compare VAR_FACING, DIR_NORTH
    call_if_eq DottedHole_SapphireRoom_EventScript_PlayerFaceThiefLeft
    compare VAR_FACING, DIR_SOUTH
    call_if_eq DottedHole_SapphireRoom_EventScript_PlayerFaceThiefLeft
    compare VAR_FACING, DIR_EAST
    call_if_eq DottedHole_SapphireRoom_EventScript_PlayerFaceThiefDown
    compare VAR_FACING, DIR_WEST
    call_if_eq DottedHole_SapphireRoom_EventScript_PlayerFaceThiefDown
    msgbox DottedHole_SapphireRoom_Text_SellToTeamRocketTellPassword, MSGBOX_DEFAULT
    closemessage
    compare VAR_FACING, DIR_NORTH
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefExitNorth
    compare VAR_FACING, DIR_SOUTH
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefExitSouth
    compare VAR_FACING, DIR_EAST
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefExitEast
    compare VAR_FACING, DIR_WEST
    call_if_eq DottedHole_SapphireRoom_EventScript_ThiefExitEast
    playse SE_EXIT
    delay 35
    removeobject LOCALID_THIEF
    setflag FLAG_LEARNED_YES_NAH_CHANSEY
    release
    end

DottedHole_SapphireRoom_EventScript_PlayerFaceThiefLeft::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    return

DottedHole_SapphireRoom_EventScript_PlayerFaceThiefDown::
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

DottedHole_SapphireRoom_EventScript_ThiefLookAtSapphireNorth::
    applymovement LOCALID_THIEF, DottedHole_SapphireRoom_Movement_ThiefLookAtSapphireFromLeft
    waitmovement 0
    return

DottedHole_SapphireRoom_EventScript_ThiefLookAtSapphireEast::
    applymovement LOCALID_THIEF, DottedHole_SapphireRoom_Movement_ThiefLookAtSapphireFromBelow
    waitmovement 0
    return

DottedHole_SapphireRoom_EventScript_ThiefGetSapphireNorth::
    applymovement LOCALID_THIEF, DottedHole_SapphireRoom_Movement_ThiefGetSapphireFromLeft
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    return

DottedHole_SapphireRoom_EventScript_ThiefGetSapphireSouth::
    applymovement LOCALID_THIEF, DottedHole_SapphireRoom_Movement_ThiefGetSapphireFromLeft
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    return

DottedHole_SapphireRoom_EventScript_ThiefGetSapphireEast::
    applymovement LOCALID_THIEF, DottedHole_SapphireRoom_Movement_ThiefGetSapphireFromBelow
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
    waitmovement 0
    return

DottedHole_SapphireRoom_EventScript_ThiefGetSapphireWest::
    applymovement LOCALID_THIEF, DottedHole_SapphireRoom_Movement_ThiefGetSapphireFromBelow
    waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    return

DottedHole_SapphireRoom_EventScript_ThiefExitNorth::
    applymovement OBJ_EVENT_ID_PLAYER, DottedHole_SapphireRoom_Movement_PlayerWatchThiefExit
    applymovement LOCALID_THIEF, DottedHole_SapphireRoom_Movement_ThiefExitNorth
    waitmovement 0
    return

DottedHole_SapphireRoom_EventScript_ThiefExitSouth::
    applymovement OBJ_EVENT_ID_PLAYER, DottedHole_SapphireRoom_Movement_PlayerWatchThiefExit
    applymovement LOCALID_THIEF, DottedHole_SapphireRoom_Movement_ThiefExitSouth
    waitmovement 0
    return

DottedHole_SapphireRoom_EventScript_ThiefExitEast::
    applymovement OBJ_EVENT_ID_PLAYER, DottedHole_SapphireRoom_Movement_PlayerWatchThiefExit
    applymovement LOCALID_THIEF, DottedHole_SapphireRoom_Movement_ThiefExitEastWest
    waitmovement 0
    return

DottedHole_SapphireRoom_Movement_ThiefLookAtSapphireFromLeft::
    walk_up
    walk_up
    walk_in_place_faster_right
    step_end

DottedHole_SapphireRoom_Movement_ThiefLookAtSapphireFromBelow::
    walk_right
    walk_right
    walk_in_place_faster_up
    step_end

DottedHole_SapphireRoom_Movement_ThiefGetSapphireFromLeft::
    walk_right
    step_end

DottedHole_SapphireRoom_Movement_ThiefGetSapphireFromBelow::
    walk_up
    step_end

DottedHole_SapphireRoom_Movement_ThiefExitNorth::
    walk_fast_up
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_down
    walk_fast_right
    walk_fast_right
    step_end

DottedHole_SapphireRoom_Movement_ThiefExitSouth::
    walk_fast_down
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_up
    walk_fast_right
    walk_fast_right
    step_end

DottedHole_SapphireRoom_Movement_ThiefExitEastWest::
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_up
    step_end

DottedHole_SapphireRoom_Movement_ThiefFallIn::
    face_down
    disable_anim
    slide_down
    slide_down
    slide_down
    slide_down
    slide_down
    slide_down
    slide_down
    slide_down
    slide_down
    restore_anim
    step_end

DottedHole_SapphireRoom_Movement_PlayerWatchThiefExit::
    delay_16
    walk_in_place_faster_right
    step_end

DottedHole_SapphireRoom_EventScript_BrailleMessage::
    lockall
    setvar VAR_0x8005, 130
    braillemsgbox Braille_Text_LetTheTwo
    braillemsgbox Braille_Text_Glittering
    braillemsgbox Braille_Text_Stones
    braillemsgbox Braille_Text_OneInRed
    braillemsgbox Braille_Text_OneInBlue
    braillemsgbox Braille_Text_ConnectThe
    braillemsgbox Braille_Text_Past
    braillemsgbox Braille_Text_TwoFriends
    braillemsgbox Braille_Text_Sharing
    braillemsgbox Braille_Text_PowerOpen
    braillemsgbox Braille_Text_AWindowTo
    braillemsgbox Braille_Text_ANewWorld
    braillemsgbox Braille_Text_ThatGlows
    braillemsgbox Braille_Text_TheNext
    braillemsgbox Braille_Text_WorldWaits
    braillemsgbox Braille_Text_ForYou
    releaseall
    end

DottedHole_SapphireRoom_Text_FoundSapphire::
    .string "{PLAYER} found a Sapphire!$"

DottedHole_SapphireRoom_Text_IWasRightInTailingYou::
    .string "Fufu… Fufufufu…\n"
    .string "I guessed right.\p"
    .string "I was right in tailing you!$"

DottedHole_SapphireRoom_Text_SellToTeamRocketTellPassword::
    .string "I knew that there was a Sapphire\n"
    .string "here, so it belongs to me!\p"
    .string "I'll sell it to Team Rocket for\n"
    .string "serious money.\p"
    .string "…D-don't glare at me like that!\p"
    .string "If you want it back, why don't you\n"
    .string "go get it after I sell it?\p"
    .string "I'll even tell you one of the\n"
    .string "passwords to Team Rocket's\l"
    .string "Warehouse.\p"
    .string "The Warehouse password I know is\n"
    .string "“Yes, nah, Chansey.”\p"
    .string "I'm done.\n"
    .string "Don't think badly of me!$"
