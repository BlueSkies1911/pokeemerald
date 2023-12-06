#include "global.h"
#include "bike.h"
#include "clock.h"
#include "day_night.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "field_special_scene.h"
#include "field_tasks.h"
#include "fieldmap.h"
#include "item.h"
#include "main.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "script.h"
#include "secret_base.h"
#include "sound.h"
#include "task.h"
#include "constants/field_tasks.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

/*  This file handles some persistent tasks that run in the overworld.
 *  - Task_RunTimeBasedEvents: Periodically updates local time and RTC events. Also triggers ambient cries.
 *  - Task_MuddySlope: Handles the metatile animation when the player steps on muddy slopes.
 *  - Task_RunPerStepCallback: Calls one of the functions in sPerStepCallbacks, listed below...
 *      . DummyPerStepCallback: Default, does nothing
 *      . AshGrassPerStepCallback: Removes the ash from ash-covered grass that the player steps on.
 *      . SootopolisGymIcePerStepCallback: Cracks/breaks ice in Sootopolis Gym that the player steps on.
 *      . SecretBasePerStepCallback: Records the decorations in a friend's secret base that the player steps on.
 *
 *  NOTE: "PerStep" is perhaps misleading. One function in sPerStepCallbacks is called
 *        every frame while in the overworld by Task_RunPerStepCallback regardless of
 *        whether or not steps are being taken. However, nearly all of the functions in
 *        the table check if the player has moved from their previous position before
 *        doing anything else.
 */

static void DummyPerStepCallback(u8);
static void AshGrassPerStepCallback(u8);
static void IcefallCaveIcePerStepCallback(u8 taskId);
static void Task_MuddySlope(u8);

static const TaskFunc sPerStepCallbacks[] =
{
    [STEP_CB_DUMMY]             = DummyPerStepCallback,
    [STEP_CB_ASH]               = AshGrassPerStepCallback,
    [STEP_CB_FORTREE_BRIDGE]    = DummyPerStepCallback,
    [STEP_CB_PACIFIDLOG_BRIDGE] = DummyPerStepCallback,
    [STEP_CB_ICE]               = IcefallCaveIcePerStepCallback,
    [STEP_CB_TRUCK]             = DummyPerStepCallback,
    [STEP_CB_SECRET_BASE]       = SecretBasePerStepCallback,
    [STEP_CB_CRACKED_FLOOR]     = DummyPerStepCallback
};

// Each element corresponds to a y coordinate row in the sootopolis gym 1F map.
// The rows with ice each have a temp var used to track the ice steps. Each bit in the var
// represents whether ice at that x coordinate (starting from the left edge) has been visited.
// This method of tracking steps will break if the ice puzzle is more than 16 map spaces wide.
static const u16 sSootopolisGymIceRowVars[] =
{
    0,
    0,
    0,
    0,
    0,
    0,
    VAR_TEMP_1,
    VAR_TEMP_2,
    VAR_TEMP_3,
    VAR_TEMP_4,
    0,
    0,
    VAR_TEMP_5,
    VAR_TEMP_6,
    VAR_TEMP_7,
    0,
    0,
    VAR_TEMP_8,
    VAR_TEMP_9,
    VAR_TEMP_A,
    0,
    0,
    0,
    0,
    0,
    0
};

#define tCallbackId data[0]

static void Task_RunPerStepCallback(u8 taskId)
{
    int idx = gTasks[taskId].tCallbackId;
    sPerStepCallbacks[idx](taskId);
}

#define tState           data[0]
#define tAmbientCryState data[1]
#define tAmbientCryDelay data[2]
#define tForceTimeUpdate data[3]

#define TIME_UPDATE_INTERVAL (1 << 12)

static void RunTimeBasedEvents(s16 *data)
{
    switch (tState)
    {
    case 0:
        if (gMain.vblankCounter1 & TIME_UPDATE_INTERVAL)
        {
            DoTimeBasedEvents();
            tState++;
        }
        break;
    case 1:
        if (!(gMain.vblankCounter1 & TIME_UPDATE_INTERVAL))
            tState--;
        break;
    }
}

static void Task_RunTimeBasedEvents(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    ProcessImmediateTimeEvents();

    if (!ArePlayerFieldControlsLocked())
    {
        RunTimeBasedEvents(data);
        UpdateAmbientCry(&tAmbientCryState, (u16*) &tAmbientCryDelay);
    }

    if (tForceTimeUpdate)
    {
        tForceTimeUpdate = 0;
        DoTimeBasedEvents();
    }
}

void ForceTimeBasedEvents(void)
{
    u8 taskId = FindTaskIdByFunc(Task_RunTimeBasedEvents);

    if (taskId != 0xFF)
        gTasks[taskId].tForceTimeUpdate = 1;
}

#undef tState
#undef tForceTimeUpdate

void SetUpFieldTasks(void)
{
    if (!FuncIsActiveTask(Task_RunPerStepCallback))
    {
        u8 taskId = CreateTask(Task_RunPerStepCallback, 80);
        gTasks[taskId].tCallbackId = STEP_CB_DUMMY;
    }

    if (!FuncIsActiveTask(Task_MuddySlope))
        CreateTask(Task_MuddySlope, 80);

    if (!FuncIsActiveTask(Task_RunTimeBasedEvents))
        CreateTask(Task_RunTimeBasedEvents, 80);
}

void ActivatePerStepCallback(u8 callbackId)
{
    u8 taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != TASK_NONE)
    {
        s32 i;
        s16 *data = gTasks[taskId].data;

        for (i = 0; i < NUM_TASK_DATA; i++)
            data[i] = 0;

        if (callbackId >= ARRAY_COUNT(sPerStepCallbacks))
            tCallbackId = STEP_CB_DUMMY;
        else
            tCallbackId = callbackId;
    }
}

void ResetFieldTasksArgs(void)
{
    u8 taskId;
    s16 *data;

    taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != TASK_NONE)
        data = gTasks[taskId].data;

    taskId = FindTaskIdByFunc(Task_RunTimeBasedEvents);
    if (taskId != TASK_NONE)
    {
        data = gTasks[taskId].data;
        tAmbientCryState = 0;
        tAmbientCryDelay = 0;
    }
}

#undef tAmbientCryState
#undef tAmbientCryDelay

static void DummyPerStepCallback(u8 taskId)
{

}

static const u8 sIcefallCaveIceTileCoords[][2] =
{
    {  8,  3 },
    { 10,  5 },
    { 15,  5 },
    {  8,  9 },
    {  9,  9 },
    { 16,  9 },
    {  8, 10 },
    {  9, 10 },
    {  8, 14 }
};

static void MarkIcefallCaveCoordVisited(s16 x, s16 y)
{
    u8 i = 0;
    for (; i < NELEMS(sIcefallCaveIceTileCoords); ++i)
    {
        if (sIcefallCaveIceTileCoords[i][0] + 7 == x && sIcefallCaveIceTileCoords[i][1] + 7 == y)
        {
            FlagSet(i + 1);
            break;
        }
    }
}

void SetIcefallCaveCrackedIceMetatiles(void)
{
    u8 i = 0;
    for (; i < NELEMS(sIcefallCaveIceTileCoords); ++i)
    {
        if (FlagGet(i + 1) == TRUE)
        {
            int x = sIcefallCaveIceTileCoords[i][0] + 7;
            int y = sIcefallCaveIceTileCoords[i][1] + 7;
            MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_CrackedIce);
        }
    }
}

#define tState data[1]
#define tPrevX data[2]
#define tPrevY data[3]
#define tIceX  data[4]
#define tIceY  data[5]
#define tDelay data[6]

static void IcefallCaveIcePerStepCallback(u8 taskId)
{
    s16 x, y;
    u8 tileBehavior;
    u16 *iceStepCount;
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
        case 0:
            PlayerGetDestCoords(&x, &y);
            tPrevX = x;
            tPrevY = y;
            tState = 1;
            break;
        case 1:
            PlayerGetDestCoords(&x, &y);
            if (x != tPrevX || y != tPrevY)
            {
                tPrevX = x;
                tPrevY = y;
                tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                if (MetatileBehavior_IsThinIce(tileBehavior) == TRUE)
                {
                    MarkIcefallCaveCoordVisited(x, y);
                    tDelay = 4;
                    tState = 2;
                    tIceX = x;
                    tIceY = y;
                }
                else if (MetatileBehavior_IsCrackedIce(tileBehavior) == TRUE)
                {
                    tDelay = 4;
                    tState = 3;
                    tIceX = x;
                    tIceY = y;
                }
            }
            break;
        case 2:
            if (tDelay != 0)
            {
                tDelay--;
            }
            else
            {
                x = tIceX;
                y = tIceY;
                PlaySE(SE_ICE_CRACK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_CrackedIce);
                CurrentMapDrawMetatileAt(x, y);
                tState = 1;
            }
            break;
        case 3:
            if (tDelay != 0)
            {
                tDelay--;
            }
            else
            {
                x = tIceX;
                y = tIceY;
                PlaySE(SE_ICE_BREAK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_IceHole);
                CurrentMapDrawMetatileAt(x, y);
                VarSet(VAR_TEMP_1, 1);
                tState = 1;
            }
            break;
    }
}

#undef tState
#undef tPrevX
#undef tPrevY
#undef tIceX
#undef tIceY
#undef tDelay

#define tPrevX data[1]
#define tPrevY data[2]

static void AshGrassPerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 *ashGatherCount;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);

    // End if player hasn't moved
    if (x == tPrevX && y == tPrevY)
        return;

    tPrevX = x;
    tPrevY = y;
    if (MetatileBehavior_IsAshGrass(MapGridGetMetatileBehaviorAt(x, y)))
    {
        // Remove ash from grass
        if (MapGridGetMetatileIdAt(x, y) == 0x20a)
            StartAshFieldEffect(x, y, 0x212, 4);
        else
            StartAshFieldEffect(x, y, 0x206, 4);

        // Try to gather ash
        if (CheckBagHasItem(ITEM_SOOT_SACK, 1))
        {
            ashGatherCount = GetVarPointer(VAR_ASH_GATHER_COUNT);
            if (*ashGatherCount < 9999)
                (*ashGatherCount)++;
        }
    }
}

#undef tPrevX
#undef tPrevY

#define tMapId data[0]
#define tState data[1]
#define tPrevX data[2]
#define tPrevY data[3]
// data[4] - data[15] are data about up to 4 individual animating muddy slope metatiles
// They're divided into groups of 3, i.e data[4]-[6] track one metatile, data[7]-[9] another, and so on.
// For each data triplet, the 1sst is the animation time, and the 2nd/3rd are the x/y coordinates.
#define SLOPE_DATA_START 4
#define SLOPE_DATA_END  (3 * SLOPE_DATA_SIZE + SLOPE_DATA_START) // 13, which is the last slope data start point
enum {
    SLOPE_TIME,
    SLOPE_X,
    SLOPE_Y,
    SLOPE_DATA_SIZE
};
#define tSlopeAnimTime(i) data[(i) * SLOPE_DATA_SIZE + SLOPE_DATA_START + SLOPE_TIME]

static const u16 sMuddySlopeMetatiles[] = {
};

#define SLOPE_ANIM_TIME 32
#define SLOPE_ANIM_STEP_TIME (SLOPE_ANIM_TIME / (int)ARRAY_COUNT(sMuddySlopeMetatiles))

static void SetMuddySlopeMetatile(s16 *data, s16 x, s16 y)
{
}

static void Task_MuddySlope(u8 taskId)
{
    s16 x, y, cameraOffsetX, cameraOffsetY;
    int i;
    u16 mapId;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    mapId = (gSaveBlock1Ptr->location.mapGroup << 8) | gSaveBlock1Ptr->location.mapNum;
    switch (tState)
    {
    case 0:
        tMapId = mapId;
        tPrevX = x;
        tPrevY = y;
        tState = 1;
        tSlopeAnimTime(0) = 0;
        tSlopeAnimTime(1) = 0;
        tSlopeAnimTime(2) = 0;
        tSlopeAnimTime(3) = 0;
        break;
    case 1:
        // Skip if player hasn't moved
        if (tPrevX == x && tPrevY == y)
            break;

        tPrevX = x;
        tPrevY = y;
        if (MetatileBehavior_IsMuddySlope(MapGridGetMetatileBehaviorAt(x, y)))
        {
            for (i = SLOPE_DATA_START; i <= SLOPE_DATA_END; i += SLOPE_DATA_SIZE)
            {
                if (data[i] == 0)
                {
                    data[i + SLOPE_TIME] = SLOPE_ANIM_TIME;
                    data[i + SLOPE_X] = x;
                    data[i + SLOPE_Y] = y;
                    break;
                }
            }
        }
        break;
    }

    if (gCamera.active && mapId != tMapId)
    {
        tMapId = mapId;
        cameraOffsetX = gCamera.x;
        cameraOffsetY = gCamera.y;
    }
    else
    {
        cameraOffsetX = 0;
        cameraOffsetY = 0;
    }

    for (i = SLOPE_DATA_START; i <= SLOPE_DATA_END; i += SLOPE_DATA_SIZE)
    {
        if (data[i + SLOPE_TIME])
        {
            data[i + SLOPE_X] -= cameraOffsetX;
            data[i + SLOPE_Y] -= cameraOffsetY;
            SetMuddySlopeMetatile(&data[i + SLOPE_TIME], data[i + SLOPE_X], data[i + SLOPE_Y]);
        }
    }
}
