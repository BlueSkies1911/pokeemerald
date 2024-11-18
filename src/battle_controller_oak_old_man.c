#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "bg.h"
#include "data.h"
#include "item.h"
#include "item_menu.h"
#include "link.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "constants/battle_string_ids.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"

static void OakOldManHandleDrawTrainerPic(u32 battler);
static void OakOldManHandleTrainerSlide(u32 battler);
static void OakOldManHandleSuccessBallThrowAnim(u32 battler);
static void OakOldManHandleBallThrowAnim(u32 battler);
static void OakOldManHandleMoveAnimation(u32 battler);
static void OakOldManHandlePrintString(u32 battler);
static void OakOldManHandlePrintSelectionString(u32 battler);
static void OakOldManHandleChooseAction(u32 battler);
static void OakOldManHandleChooseMove(u32 battler);
static void OakOldManHandleChooseItem(u32 battler);
static void OakOldManHandleChoosePokemon(u32 battler);
static void OakOldManHandleHealthBarUpdate(u32 battler);
static void OakOldManHandlePlaySE(u32 battler);
static void OakOldManHandlePlayFanfare(u32 battler);
static void OakOldManHandleFaintingCry(u32 battler);
static void OakOldManHandleIntroTrainerBallThrow(u32 battler);
static void OakOldManHandleDrawPartyStatusSummary(u32 battler);
static void OakOldManHandleEndBounceEffect(u32 battler);
static void OakOldManHandleBattleAnimation(u32 battler);
static void OakOldManHandleLinkStandbyMsg(u32 battler);
static void OakOldManHandleCmd55(u32 battler);

static void OakOldManBufferRunCommand(u32 battler);
static void OakOldManBufferExecCompleted(u32 battler);
static void CompleteWhenChoseItem(u32 battler);
static void PrintOakText_KeepAnEyeOnHP(u32 battler);
static void Intro_WaitForShinyAnimAndHealthbox(u32 battler);
static void PrintOakText_ForPetesSake(u32 battler);
static void PrintOakTextWithMainBgDarkened(u32 battler, const u8 *text, u8 delay);
static void HandleInputChooseAction(u32 battler);

static void (*const sOakOldManBufferCommands[CONTROLLER_CMDS_COUNT])(u32 battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_HandleGetRawMonData,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_LOADMONSPRITE]            = BtlController_Empty,
    [CONTROLLER_SWITCHINANIM]             = BtlController_Empty,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = OakOldManHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = OakOldManHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = BtlController_Empty,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = OakOldManHandleSuccessBallThrowAnim,
    [CONTROLLER_BALLTHROWANIM]            = OakOldManHandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = OakOldManHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = OakOldManHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = OakOldManHandlePrintSelectionString,
    [CONTROLLER_CHOOSEACTION]             = OakOldManHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = OakOldManHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = OakOldManHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = OakOldManHandleChoosePokemon,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = OakOldManHandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = PlayerHandleExpUpdate,
    [CONTROLLER_STATUSICONUPDATE]         = BtlController_Empty,
    [CONTROLLER_STATUSANIMATION]          = BtlController_Empty,
    [CONTROLLER_STATUSXOR]                = BtlController_Empty,
    [CONTROLLER_DATATRANSFER]             = BtlController_Empty,
    [CONTROLLER_DMA3TRANSFER]             = BtlController_Empty,
    [CONTROLLER_PLAYBGM]                  = BtlController_Empty,
    [CONTROLLER_32]                       = BtlController_Empty,
    [CONTROLLER_TWORETURNVALUES]          = BtlController_Empty,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE]           = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = BtlController_Empty,
    [CONTROLLER_CLEARUNKVAR]              = BtlController_Empty,
    [CONTROLLER_SETUNKVAR]                = BtlController_Empty,
    [CONTROLLER_CLEARUNKFLAG]             = BtlController_Empty,
    [CONTROLLER_TOGGLEUNKFLAG]            = BtlController_Empty,
    [CONTROLLER_HITANIMATION]             = BtlController_HandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = BtlController_Empty,
    [CONTROLLER_PLAYSE]                   = OakOldManHandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = OakOldManHandlePlayFanfare,
    [CONTROLLER_FAINTINGCRY]              = OakOldManHandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = OakOldManHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = OakOldManHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_Empty,
    [CONTROLLER_ENDBOUNCE]                = OakOldManHandleEndBounceEffect,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_Empty,
    [CONTROLLER_BATTLEANIMATION]          = OakOldManHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = OakOldManHandleLinkStandbyMsg,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = OakOldManHandleCmd55,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop,
};

void SetControllerToOakOrOldMan(u32 battler)
{
    gBattlerControllerEndFuncs[battler] = OakOldManBufferExecCompleted;
    gBattlerControllerFuncs[battler] = OakOldManBufferRunCommand;
    gBattleStruct->oakOldManBattleState = 0;
    gBattleStruct->oakOldManMovesState = 0;
    gBattleStruct->oakOldManWaitFrames = 0;
    gBattleStruct->oakOldManMoveFrames = 0;
}

static void OakOldManBufferRunCommand(u32 battler)
{
    if (gBattleControllerExecFlags & gBitTable[battler])
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sOakOldManBufferCommands))
            sOakOldManBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            OakOldManBufferExecCompleted(battler);
    }
}

static void HandleInputChooseAction(u32 battler)
{
    // Like player, but specifically for Rival in Oak's Lab
    u16 itemId = gBattleResources->bufferA[battler][2] | (gBattleResources->bufferA[battler][3] << 8);

    DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
    DoBounceEffect(battler, BOUNCE_MON, 7, 1);
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        switch (gActionSelectionCursor[battler])
        {
        case 0:
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_USE_MOVE, 0);
            break;
        case 1:
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_USE_ITEM, 0);
            break;
        case 2:
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_SWITCH, 0);
            break;
        case 3:
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_RUN, 0);
            break;
        }
        OakOldManBufferExecCompleted(battler);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gActionSelectionCursor[battler] & 1) // if is B_ACTION_USE_ITEM or B_ACTION_RUN
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (!(gActionSelectionCursor[battler] & 1)) // if is B_ACTION_USE_MOVE or B_ACTION_SWITCH
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gActionSelectionCursor[battler] & 2) // if is B_ACTION_SWITCH or B_ACTION_RUN
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (!(gActionSelectionCursor[battler] & 2)) // if is B_ACTION_USE_MOVE or B_ACTION_USE_ITEM
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
         && GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT
         && !(gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)])
         && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            if (gBattleResources->bufferA[battler][1] == B_ACTION_USE_ITEM)
            {
                // Add item to bag if it is a ball
                if (itemId <= ITEM_PREMIER_BALL)
                    AddBagItem(itemId, 1);
                else
                    return;
            }
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_CANCEL_PARTNER, 0);
            OakOldManBufferExecCompleted(battler);
        }
    }
    else if (JOY_NEW(START_BUTTON))
    {
        SwapHpBarsWithHpText();
    }
}

static void SimulateInputChooseAction(u32 battler)
{
    // Old Man
    switch (gBattleStruct->oakOldManBattleState)
    {
    case 0:
        gBattleStruct->oakOldManWaitFrames = 64;
        ++gBattleStruct->oakOldManBattleState;
        // fall through
    case 1:
        if (--gBattleStruct->oakOldManWaitFrames == 0)
        {
            // Move cursor to BAG
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(0);
            ActionSelectionCreateCursorAt(1, 0);
            gBattleStruct->oakOldManWaitFrames = 64;
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 2:
        if (--gBattleStruct->oakOldManWaitFrames == 0)
        {
            // Open bag
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_USE_ITEM, 0);
            OakOldManBufferExecCompleted(battler);
        }
        break;
    }
}

static void CompleteOnInactiveTextPrinter(u32 battler)
{
    if (!IsTextPrinterActive(0))
        OakOldManBufferExecCompleted(battler);
}

static void OakOldManSetBattleEndCallbacks(u32 battler)
{
    if (!gPaletteFade.active)
    {
        gMain.inBattle = FALSE;
        gMain.callback1 = gPreBattleCallback1;
        SetMainCallback2(gMain.savedCallback);
    }
}

void OakOldManHandleInputChooseMove(u32 battler)
{
    HandleInputChooseMove(battler);
    if (!(gBattleControllerExecFlags & gBitTable[battler]))
        OakOldManBufferExecCompleted(battler);
}

static void OpenBagAndChooseItem(u32 battler)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[battler] = CompleteWhenChoseItem;
        ReshowBattleScreenDummy();
        FreeAllWindowBuffers();
        if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
            CB2_BagMenuFromBattle();
        else
            DoWallyTutorialBagMenu();
    }
}

static void CompleteWhenChoseItem(u32 battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        if (!BtlCtrl_OakOldMan_TestState2Flag(FIRST_BATTLE_MSG_FLAG_HP_RESTORE)
         && gSpecialVar_ItemId == ITEM_POTION
         && gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        {
            BtlCtrl_OakOldMan_SetState2Flag(FIRST_BATTLE_MSG_FLAG_HP_RESTORE);
            gBattlerControllerFuncs[battler] = PrintOakText_KeepAnEyeOnHP;
        }
        else
        {
            BtlController_EmitOneReturnValue(battler, 1, gSpecialVar_ItemId);
            OakOldManBufferExecCompleted(battler);
        }
    }
}

static void Intro_TryShinyAnimShowHealthbox(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
        TryShinyAnimation(battler, &gPlayerParty[gBattlerPartyIndexes[battler]]);

    if (!gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive)
        TryShinyAnimation(BATTLE_PARTNER(battler), &gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]]);

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive)
    {
        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            DestroySprite(&gSprites[gBattleControllerData[BATTLE_PARTNER(battler)]]);
            UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(battler)], &gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]], HEALTHBOX_ALL);
            StartHealthboxSlideIn(BATTLE_PARTNER(battler));
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[BATTLE_PARTNER(battler)]);
        }
        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);
        StartHealthboxSlideIn(battler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);

        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = FALSE;
        gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(u32 battler)
{
    bool32 healthboxAnimDone = FALSE;

    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
        healthboxAnimDone = TRUE;

    if (healthboxAnimDone && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
        && gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;

        gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim = FALSE;

        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

        CreateTask(Task_PlayerController_RestoreBgmAfterCry, 10);
        HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);

        gBattlerControllerFuncs[battler] = PrintOakText_ForPetesSake;
    }
}

static void PrintOakText_ForPetesSake(u32 battler)
{
    u32 mask;

    switch (gBattleStruct->oakOldManBattleState)
    {
    case 0:
        if (!gPaletteFade.active)
        {
            DoLoadHealthboxPalsForLevelUp(&gBattleStruct->oakOldManMovesState, &gBattleStruct->oakOldManMoveFrames, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   0,
                                   8,
                                   RGB_BLACK);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            BtlCtrl_DrawVoiceoverMessageFrame();
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 2:
        BattleStringExpandPlaceholdersToDisplayedString(gText_ForPetesSake);
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_OAK_TUTORIAL);
        ++gBattleStruct->oakOldManBattleState;
        break;
    case 3:
        if (!IsTextPrinterActive(24))
        {
            mask = (gBitTable[gBattleStruct->oakOldManMovesState] | gBitTable[gBattleStruct->oakOldManMoveFrames]) << 16;
            BeginNormalPaletteFade(mask,
                                   4,
                                   8,
                                   0,
                                   RGB_BLACK);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            BattleStringExpandPlaceholdersToDisplayedString(gText_TheTrainerThat);
            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_OAK_TUTORIAL);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 5:
        if (!IsTextPrinterActive(24))
        {
            mask = (gBitTable[gBattleStruct->oakOldManMovesState] | gBitTable[gBattleStruct->oakOldManMoveFrames]) << 16;
            BeginNormalPaletteFade(mask,
                                   4,
                                   0,
                                   8,
                                   RGB_BLACK);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            BattleStringExpandPlaceholdersToDisplayedString(gText_TryBattling);
            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_OAK_TUTORIAL);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 7:
        if (!IsTextPrinterActive(24))
        {
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   8,
                                   0,
                                   RGB_BLACK);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 8:
        if (!gPaletteFade.active)
        {
            DoFreeHealthboxPalsForLevelUp(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
            BtlCtrl_RemoveVoiceoverMessageFrame();
            gBattleStruct->oakOldManBattleState = 0;
            OakOldManBufferExecCompleted(battler);
        }
        break;
    }
}

void PrintOakText_InflictingDamageIsKey(u32 battler)
{
    PrintOakTextWithMainBgDarkened(battler, gText_InflictingDamageIsKey, 1);
}

static void PrintOakText_LoweringStats(u32 battler)
{
    PrintOakTextWithMainBgDarkened(battler, gText_LoweringStats, 64);
}

void PrintOakText_OakNoRunningFromATrainer(u32 battler)
{
    PrintOakTextWithMainBgDarkened(battler, gText_OakNoRunningFromATrainer, 1);
}

static void PrintOakText_WinEarnsPrizeMoney(u32 battler)
{
    PrintOakTextWithMainBgDarkened(battler, gText_WinEarnsPrizeMoney, 64);
}

void PrintOakText_HowDisappointing(u32 battler)
{
    PrintOakTextWithMainBgDarkened(battler, gText_HowDisappointing, 64);
}

static void PrintOakTextWithMainBgDarkened(u32 battler, const u8 *text, u8 delay)
{
    // If delay is 0, it's treated as 256.
    switch (gBattleStruct->oakOldManBattleState)
    {
    case 0:
        if (!IsTextPrinterActive(0))
        {
            gBattleStruct->oakOldManMoveFrames = delay;
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 1:
        if (--gBattleStruct->oakOldManMoveFrames == 0)
        {
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   0,
                                   8,
                                   RGB_BLACK);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            BtlCtrl_DrawVoiceoverMessageFrame();
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 3:
        BattleStringExpandPlaceholdersToDisplayedString(text);
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_OAK_TUTORIAL);
        ++gBattleStruct->oakOldManBattleState;
        break;
    case 4:
        if (!IsTextPrinterActive(24))
        {
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   8,
                                   0,
                                   RGB_BLACK);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 5:
        if (!gPaletteFade.active)
        {
            BtlCtrl_RemoveVoiceoverMessageFrame();
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                OakOldManBufferExecCompleted(battler);
            else
                OpponentBufferExecCompleted(battler);
            gBattleCommunication[MSG_DISPLAY] = 0;
            gBattleStruct->oakOldManBattleState = 0;
        }
        break;
    }
}

static void PrintOakText_KeepAnEyeOnHP(u32 battler)
{
    u32 mask;

    switch (gBattleStruct->oakOldManBattleState)
    {
    case 0:
        if (!gPaletteFade.active)
        {
            DoLoadHealthboxPalsForLevelUp(&gBattleStruct->oakOldManMovesState, &gBattleStruct->oakOldManMoveFrames, battler);
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   0,
                                   8,
                                   RGB_BLACK);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            mask = (gBitTable[gBattleStruct->oakOldManMovesState] | gBitTable[gBattleStruct->oakOldManMoveFrames]) << 16;
            BeginNormalPaletteFade(mask,
                                   4,
                                   8,
                                   0,
                                   RGB_BLACK);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            BtlCtrl_DrawVoiceoverMessageFrame();
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 3:
        BattleStringExpandPlaceholdersToDisplayedString(gText_KeepAnEyeOnHP);
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_OAK_TUTORIAL);
        ++gBattleStruct->oakOldManBattleState;
        break;
    case 4:
        if (!IsTextPrinterActive(24))
        {
            mask = (gBitTable[gBattleStruct->oakOldManMovesState] | gBitTable[gBattleStruct->oakOldManMoveFrames]) << 16;
            BeginNormalPaletteFade(mask,
                                   4,
                                   0,
                                   8,
                                   RGB_BLACK);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 5:
        if (!gPaletteFade.active)
        {
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   8,
                                   0,
                                   RGB_BLACK);
            ++gBattleStruct->oakOldManBattleState;
        }
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            BtlCtrl_RemoveVoiceoverMessageFrame();
            BtlController_EmitOneReturnValue(battler, 1, gSpecialVar_ItemId);
            OakOldManBufferExecCompleted(battler);
            gBattleStruct->oakOldManBattleState = 0;
        }
        break;
    }
}

static void OakOldManBufferExecCompleted(u32 battler)
{
    gBattlerControllerFuncs[battler] = OakOldManBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(battler, 2, 4, &playerId);
        gBattleResources->bufferA[battler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleControllerExecFlags &= ~gBitTable[battler];
    }
}

static void OakOldManHandleDrawTrainerPic(u32 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        BtlController_HandleDrawTrainerPic(battler, TRAINER_BACK_PIC_RED + gSaveBlock2Ptr->playerGender, FALSE,
                                           80, 80 + 4 * (8 - gTrainerBacksprites[TRAINER_BACK_PIC_RED + gSaveBlock2Ptr->playerGender].coordinates.size),
                                           30);
    else
        BtlController_HandleDrawTrainerPic(battler, TRAINER_BACK_PIC_OLDMAN, FALSE,
                                           80, 80 + 4 * (8 - gTrainerBacksprites[TRAINER_BACK_PIC_OLDMAN].coordinates.size),
                                           30);
}

static void OakOldManHandleTrainerSlide(u32 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        BtlController_HandleTrainerSlide(battler, TRAINER_BACK_PIC_RED + gSaveBlock2Ptr->playerGender);
    else
        BtlController_HandleTrainerSlide(battler, TRAINER_BACK_PIC_OLDMAN);
}

static void OakOldManHandleSuccessBallThrowAnim(u32 battler)
{
    BtlController_HandleSuccessBallThrowAnim(battler, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), B_ANIM_BALL_THROW_WITH_TRAINER, FALSE);
}

static void OakOldManHandleBallThrowAnim(u32 battler)
{
    BtlController_HandleBallThrowAnim(battler, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), B_ANIM_BALL_THROW_WITH_TRAINER, FALSE);
}

static void OakOldManHandleMoveAnimation(u32 battler)
{
    BtlController_HandleMoveAnimation(battler, FALSE);
}

static void OakOldManHandlePrintString(u32 battler)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16 *)(&gBattleResources->bufferA[battler][2]);
    if (gBattleTypeFlags & BATTLE_TYPE_OLD_MAN_TUTORIAL && *stringId == 1)
    {
        OakOldManBufferExecCompleted(battler);
    }
    else
    {
        BufferStringBattle(*stringId, battler);
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MSG);
        if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        {
            switch (*stringId)
            {
            case STRINGID_DEFENDERSSTATFELL:
                if (!BtlCtrl_OakOldMan_TestState2Flag(FIRST_BATTLE_MSG_FLAG_STAT_CHG))
                {
                    BtlCtrl_OakOldMan_SetState2Flag(FIRST_BATTLE_MSG_FLAG_STAT_CHG);
                    gBattlerControllerFuncs[battler] = PrintOakText_LoweringStats;
                    return;
                }
                break;
            case STRINGID_PLAYERGOTMONEY:
                gBattlerControllerFuncs[battler] = PrintOakText_WinEarnsPrizeMoney;
                return;
            case STRINGID_RIVALWINTEXT:
                gBattlerControllerFuncs[battler] = PrintOakText_HowDisappointing;
                return;
            case STRINGID_DONTLEAVEBIRCH:
                gBattlerControllerFuncs[battler] = PrintOakText_OakNoRunningFromATrainer;
                return;
            }
        }
        gBattlerControllerFuncs[battler] = CompleteOnInactiveTextPrinter;
    }
}

static void OakOldManHandlePrintSelectionString(u32 battler)
{
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        OakOldManHandlePrintString(battler);
    else
        OakOldManBufferExecCompleted(battler);
}

static void HandleChooseActionAfterDma3(u32 battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 160;
        if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
            gBattlerControllerFuncs[battler] = HandleInputChooseAction;
        else
            gBattlerControllerFuncs[battler] = SimulateInputChooseAction;
    }
}

static void OakOldManHandleChooseAction(u32 battler)
{
    s32 i;

    gBattlerControllerFuncs[battler] = HandleChooseActionAfterDma3;
    BattlePutTextOnWindow(gText_EmptyString3, B_WIN_MSG);
    BattlePutTextOnWindow(gText_BattleMenu, B_WIN_ACTION_MENU);

    for (i = 0; i < MAX_MON_MOVES; ++i)
        ActionSelectionDestroyCursorAt((u8)i);

    ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, battler, gBattlerPartyIndexes[battler]);
    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillPkmnDo);
    else
        BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillOldManDo);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
}

static void OakHandleChooseMove_WaitDma3(u32 battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT * 2;
        gBattlerControllerFuncs[battler] = OakOldManHandleInputChooseMove;
    }
}

static void OakOldManHandleChooseMove(u32 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
    {
        InitMoveSelectionsVarsAndStrings(battler);
        gBattlerControllerFuncs[battler] = OakHandleChooseMove_WaitDma3;
    }
    else
    {
        switch (gBattleStruct->oakOldManMovesState)
        {
        case 0:
            InitMoveSelectionsVarsAndStrings(battler);
            ++gBattleStruct->oakOldManMovesState;
            gBattleStruct->oakOldManMoveFrames = 80;
            // fall through
        case 1:
            if (--gBattleStruct->oakOldManMoveFrames == 0)
            {
                PlaySE(SE_SELECT);
                BtlController_EmitTwoReturnValues(battler, 1, 10, 0x100);
                OakOldManBufferExecCompleted(battler);
            }
            break;
        }
    }
}

static void OakOldManHandleChooseItem(u32 battler)
{
    s32 i;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[battler] = OpenBagAndChooseItem;
    gBattlerInMenuId = battler;

    for (i = 0; i < ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = gBattleResources->bufferA[battler][i + 1];
}

static void OakOldManHandleChoosePokemon(u32 battler)
{
    s32 i;

    gBattleControllerData[battler] = CreateTask(TaskDummy, 0xFF);
    gTasks[gBattleControllerData[battler]].data[0] = gBattleResources->bufferA[battler][1] & 0xF;
    *(&gBattleStruct->battlerPreventingSwitchout) = gBattleResources->bufferA[battler][1] >> 4;
    *(&gBattleStruct->prevSelectedPartySlot) = gBattleResources->bufferA[battler][2];
    *(&gBattleStruct->abilityPreventingSwitchout) = gBattleResources->bufferA[battler][3];
    for (i = 0; i < 3; ++i)
        gBattlePartyCurrentOrder[i] = gBattleResources->bufferA[battler][4 + i];
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[battler] = OpenPartyMenuToChooseMon;
    gBattlerInMenuId = battler;
}

static void OakOldManHandleHealthBarUpdate(u32 battler)
{
    BtlController_HandleHealthBarUpdate(battler, TRUE);
}

static void OakOldManHandlePlaySE(u32 battler)
{
    PlaySE(gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8));
    OakOldManBufferExecCompleted(battler);
}

static void OakOldManHandlePlayFanfare(u32 battler)
{
    PlayFanfare(gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8));
    OakOldManBufferExecCompleted(battler);
}

static void OakOldManHandleFaintingCry(u32 battler)
{
    u16 species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);

    PlayCry_Normal(species, 25);
    OakOldManBufferExecCompleted(battler);
}

static void OakOldManHandleIntroTrainerBallThrow(u32 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
    {
        const u32 *trainerPal = gTrainerBacksprites[TRAINER_BACK_PIC_RED + gSaveBlock2Ptr->playerGender].palette.data;
        BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F8, trainerPal, 31, Intro_TryShinyAnimShowHealthbox);
    }
    else
    {
        BtlController_HandleHidePartyStatusSummary(battler);
    }
}

static void OakOldManHandleDrawPartyStatusSummary(u32 battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_PLAYER, FALSE);
}

static void OakOldManHandleEndBounceEffect(u32 battler)
{
    EndBounceEffect(battler, BOUNCE_HEALTHBOX);
    EndBounceEffect(battler, BOUNCE_MON);
    OakOldManBufferExecCompleted(battler);
}

static void OakOldManHandleBattleAnimation(u32 battler)
{
    BtlController_HandleBattleAnimation(battler, TRUE, FALSE);
}

static void OakOldManHandleLinkStandbyMsg(u32 battler)
{
    switch (gBattleResources->bufferA[battler][1])
    {
    case LINK_STANDBY_MSG_STOP_BOUNCE:
    case LINK_STANDBY_STOP_BOUNCE_ONLY:
        EndBounceEffect(battler, BOUNCE_HEALTHBOX);
        EndBounceEffect(battler, BOUNCE_MON);
        break;
    case LINK_STANDBY_MSG_ONLY:
        break;
    }
    OakOldManBufferExecCompleted(battler);
}

static void OakOldManHandleCmd55(u32 battler)
{
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    OakOldManBufferExecCompleted(battler);

    if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER) && gBattleTypeFlags & BATTLE_TYPE_LINK)
        gBattlerControllerFuncs[battler] = OakOldManSetBattleEndCallbacks;
}

bool8 BtlCtrl_OakOldMan_TestState2Flag(u8 mask)
{
    return gBattleStruct->oakOldManWaitFrames & mask;
}

void BtlCtrl_OakOldMan_SetState2Flag(u8 mask)
{
    gBattleStruct->oakOldManWaitFrames |= mask;
}

void BtlCtrl_DrawVoiceoverMessageFrame(void)
{
    u8 width = 27;
    u8 palNum = 7;

    FillBgTilemapBufferRect(0, 0,    254, 14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0,    32,  14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0x31, 0,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x33, 1,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x34, 2,   14, width, 1, palNum);
    width++;
    FillBgTilemapBufferRect(0, 0x35, 28,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x36, 29,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x37, 0,   15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x39, 1,   15, width, 5, palNum);
    FillBgTilemapBufferRect(0, 0x3A, 29,  15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x831, 0,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x833, 1,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x834, 2,  19, width - 2, 1, palNum);
    FillBgTilemapBufferRect(0, 0x835, 28, 19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x836, 29, 19, 1,  1, palNum);
}

void BtlCtrl_RemoveVoiceoverMessageFrame(void)
{
    u8 width;
    u8 height;
    u8 palNum = 0;

    FillBgTilemapBufferRect(0, 3, 0, 14, 1, 1, palNum);
    height = 4;
    FillBgTilemapBufferRect(0, 4, 1, 14, 1, 1, palNum);
    width = 27;
    FillBgTilemapBufferRect(0, 5, 2, 14, width, 1, palNum);
    FillBgTilemapBufferRect(0, 6, 28, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 7, 29, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 8, 0, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 9, 1, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xA, 2, 15, width, height, palNum);
    FillBgTilemapBufferRect(0, 0xB, 28, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xC, 29, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xD, 0, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xE, 1, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xF, 2, 19, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0x10, 28, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0x11, 29, 19, 1, 1, palNum);
}