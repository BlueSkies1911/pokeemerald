#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "ereader_helpers.h"
#include "link.h"
#include "main.h"
#include "union_room.h"
#include "save.h"
#include "sprite.h"
#include "task.h"
#include "util.h"
#include "trainer_tower.h"
#include "constants/trainers.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/trainer_tower.h"

// Save data using TryWriteSpecialSaveSector is allowed to exceed SECTOR_DATA_SIZE (up to the counter field)
STATIC_ASSERT(sizeof(struct TrainerTowerChallenge) <= SECTOR_COUNTER_OFFSET, TrainerTowerChallengeFreeSpace);

struct SendRecvMgr
{
    bool8 isParent;
    u8 state;              // EREADER_XFR_STATE_*
    u8 xferState;          // EREADER_XFER_*
    u8 checksumResult;     // EREADER_CHECKSUM_*
    u8 cancellationReason; // EREADER_CANCEL_*
    u32 *data;             // Payload source or destination
    int cursor;            // Index of the next word
    int size;              // Last word index
    int checksum;
};

static void GetKeyInput(void);
static u16 DetermineSendRecvState(u8);
static void EnableSio(void);
static void DisableTm3(void);
static void SetUpTransferManager(size_t, const void *, void *);
static void StartTm3(void);

static struct SendRecvMgr sSendRecvMgr;
static u16 sJoyNewOrRepeated;
static u16 sJoyNew;
static u16 sSendRecvStatus;
static u16 sCounter1;
static u32 sCounter2;
static u16 sSavedIme;
static u16 sSavedIe;
static u16 sSavedTm3Cnt;
static u16 sSavedSioCnt;
static u16 sSavedRCnt;

static const struct TrainerTowerTrainer sTrainerTowerTrainerTemplates_JP[] = {
    [0] = {
        .name = __("マキエ$$$$$   "),
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .unused = 0x1,
        .speechBefore = { EC_WORD_PREPOSTEROUS, EC_WORD_CASE, EC_WORD_THERE, EC_WORD_TO_HER, EC_WORD_CHALLENGE, EC_WORD_JOKING },
        .speechWin = { EC_WORD_HERS, EC_WORD_TRUMP_CARD, EC_MOVE2(SECRET_POWER), EC_WORD_USING, EC_WORD_WON, EC_WORD_EXCL_EXCL },
        .speechLose = { EC_WORD_TO_HER, EC_WORD_WIN, EC_WORD_JOKING, EC_WORD_HIGHS, EC_WORD_SCARY, EC_WORD_ELLIPSIS_EXCL },
        .speechAfter = { EC_WORD_IGNORANT, EC_WORD_SO, EC_WORD_TODAY, EC_WORD_NIGHTTIME, EC_WORD_YOU_RE, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS },
        .mons = {
            [0] = DUMMY_TOWER_MON,
            [1] = DUMMY_TOWER_MON,
            [2] = DUMMY_TOWER_MON,
            [3] = {
                .species = SPECIES_MUK,
                .heldItem = ITEM_SHELL_BELL,
                .moves = { MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_PAIN_SPLIT, MOVE_TOXIC },
                .hpEV = 55,
                .attackEV = 255,
                .defenseEV = 100,
                .speedEV = 0,
                .spAttackEV = 0,
                .spDefenseEV = 100,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 1,
                .personality = 0x80,
                .nickname = __("マルノーム$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
            [4] = {
                .species = SPECIES_VENOMOTH,
                .heldItem = ITEM_BRIGHT_POWDER,
                .moves = { MOVE_SILVER_WIND, MOVE_SLUDGE_BOMB, MOVE_PSYBEAM, MOVE_GIGA_DRAIN },
                .hpEV = 0,
                .attackEV = 255,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 0,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x6,
                .nickname = __("ドクケイル$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
            [5] = {
                .species = SPECIES_OMASTAR,
                .heldItem = ITEM_QUICK_CLAW,
                .moves = { MOVE_ANCIENT_POWER, MOVE_SURF, MOVE_EARTH_POWER, MOVE_IRON_DEFENSE },
                .hpEV = 100,
                .attackEV = 0,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 155,
                .spDefenseEV = 255,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x2f,
                .nickname = __("ジーランス$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
        }
    },
    [1] = {
        .name = __("ハルヒト$$$$   "),
        .facilityClass = FACILITY_CLASS_CAMPER,
        .unused = 0x1,
        .speechBefore = { EC_MOVE2(BOUNCE), EC_WORD_AS_MUCH_AS, EC_EMPTY_WORD, EC_WORD_THEY_RE, EC_WORD_STRONG, EC_WORD_EXCL },
        .speechWin = { EC_MOVE(FLY), EC_WORD_AS_MUCH_AS, EC_EMPTY_WORD, EC_WORD_THEY_RE, EC_WORD_HAPPY, EC_WORD_EXCL },
        .speechLose = { EC_MOVE2(MINIMISE), EC_WORD_AS_MUCH_AS, EC_EMPTY_WORD, EC_WORD_THEY_RE, EC_WORD_SAD, EC_WORD_EXCL },
        .speechAfter = { EC_MOVE(BITE), EC_WORD_AS_MUCH_AS, EC_EMPTY_WORD, EC_WORD_THEY_RE, EC_WORD_ANGRY, EC_WORD_EXCL },
        .mons = {
            [0] = DUMMY_TOWER_MON,
            [1] = DUMMY_TOWER_MON,
            [2] = DUMMY_TOWER_MON,
            [3] = {
                .species = SPECIES_WIGGLYTUFF,
                .heldItem = ITEM_QUICK_CLAW,
                .moves = { MOVE_DRAIN_PUNCH, MOVE_FEINT_ATTACK, MOVE_THUNDER_PUNCH, MOVE_LIGHT_SCREEN },
                .hpEV = 55,
                .attackEV = 0,
                .defenseEV = 100,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 100,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x8c,
                .nickname = __("ノクタス$$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
            [4] = {
                .species = SPECIES_PIDGEOT,
                .heldItem = ITEM_BRIGHT_POWDER,
                .moves = { MOVE_FACADE, MOVE_AERIAL_ACE, MOVE_QUICK_ATTACK, MOVE_DOUBLE_TEAM },
                .hpEV = 255,
                .attackEV = 255,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 0,
                .spDefenseEV = 0,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x80,
                .nickname = __("オオスバメ$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
            [5] = {
                .species = SPECIES_STARMIE,
                .heldItem = ITEM_CHESTO_BERRY,
                .moves = { MOVE_SURF, MOVE_PSYCHIC, MOVE_LIGHT_SCREEN, MOVE_REST },
                .hpEV = 0,
                .attackEV = 255,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 0,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x0,
                .nickname = __("ナマズン$$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
        }
    },
    [2] = {
        .name = __("メイコ$$$$$   "),
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .unused = 0x1,
        .speechBefore = { EC_WORD_SHINE, EC_WORD_POKEMON, EC_WORD_RELEASE, EC_WORD_WAS, EC_MOVE2(FRUSTRATION), EC_WORD_WITHOUT },
        .speechWin = { EC_WORD_SHINE, EC_WORD_POKEMON, EC_WORD_TO_HER, EC_MOVE2(PRESENT), EC_WORD_KNOWS, EC_WORD_WITHOUT },
        .speechLose = { EC_WORD_THAT, EC_WORD_ABOVE, EC_WORD_LOST, EC_WORD_STORES, EC_WORD_JOKING, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS },
        .speechAfter = { EC_WORD_ENTERTAINING, EC_WORD_NONE, EC_WORD_HEY_QUES, EC_WORD_ALMOST, EC_WORD_EXCL, EC_EMPTY_WORD },
        .mons = {
            [0] = DUMMY_TOWER_MON,
            [1] = DUMMY_TOWER_MON,
            [2] = DUMMY_TOWER_MON,
            [3] = {
                .species = SPECIES_WIGGLYTUFF,
                .heldItem = ITEM_LUM_BERRY,
                .moves = { MOVE_SING, MOVE_BODY_SLAM, MOVE_SHADOW_BALL, MOVE_KNOCK_OFF },
                .hpEV = 0,
                .attackEV = 255,
                .defenseEV = 0,
                .speedEV = 255,
                .spAttackEV = 0,
                .spDefenseEV = 0,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x3,
                .nickname = __("エネコロロ$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
            [4] = {
                .species = SPECIES_IVYSAUR,
                .heldItem = ITEM_LEFTOVERS,
                .moves = { MOVE_GIGA_DRAIN, MOVE_GRASS_WHISTLE, MOVE_TOXIC, MOVE_LEECH_SEED },
                .hpEV = 255,
                .attackEV = 0,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 0,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 1,
                .personality = 0x6,
                .nickname = __("ロゼリア$$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
            [5] = {
                .species = SPECIES_BUTTERFREE,
                .heldItem = ITEM_BRIGHT_POWDER,
                .moves = { MOVE_SILVER_WIND, MOVE_AERIAL_ACE, MOVE_ATTRACT, MOVE_PSYCHIC },
                .hpEV = 100,
                .attackEV = 200,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 200,
                .spDefenseEV = 0,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x6,
                .nickname = __("アゲハント$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
        }
    },
    [3] = {
        .name = __("ピエール$$$$   "),
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .unused = 0x1,
        .speechBefore = { EC_WORD_SHE_WAS, EC_WORD_NO_1, EC_WORD_STRONG, EC_WORD_UNCLE, EC_WORD_THERE, EC_WORD_EXCL },
        .speechWin = { EC_WORD_HAHAHA, EC_WORD_TEACHER, EC_WORD_BECOMES, EC_WORD_GIVE, EC_WORD_IS_IT_QUES, EC_EMPTY_WORD },
        .speechLose = { EC_WORD_OUTSIDE, EC_WORD_UNCLE, EC_WORD_SURPRISE, EC_WORD_THESE, EC_WORD_HEY_QUES, EC_WORD_ELLIPSIS_EXCL },
        .speechAfter = { EC_WORD_HE_S, EC_WORD_NO_1, EC_WORD_STRONG, EC_WORD_CHILDREN, EC_WORD_CAN_T, EC_WORD_EXCL_EXCL },
        .mons = {
            [0] = DUMMY_TOWER_MON,
            [1] = DUMMY_TOWER_MON,
            [2] = DUMMY_TOWER_MON,
            [3] = {
                .species = SPECIES_NIDOQUEEN,
                .heldItem = ITEM_BRIGHT_POWDER,
                .moves = { MOVE_CRUNCH, MOVE_FLAMETHROWER, MOVE_THUNDER_PUNCH, MOVE_FURY_SWIPES },
                .hpEV = 0,
                .attackEV = 0,
                .defenseEV = 100,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 155,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 1,
                .personality = 0x0,
                .nickname = __("クチート$$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
            [4] = {
                .species = SPECIES_RHYDON,
                .heldItem = ITEM_SCOPE_LENS,
                .moves = { MOVE_SURF, MOVE_CRUNCH, MOVE_RETURN, MOVE_EARTHQUAKE },
                .hpEV = 255,
                .attackEV = 0,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 0,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x96,
                .nickname = __("サメハダー$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
            [5] = {
                .species = SPECIES_GENGAR,
                .heldItem = ITEM_LUM_BERRY,
                .moves = { MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_WILL_O_WISP },
                .hpEV = 255,
                .attackEV = 0,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 0,
                .otId = TRAINER_TOWER_OTID,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x96,
                .nickname = __("ジュペッタ$$$$$$"),
                .friendship = MAX_FRIENDSHIP
            },
        }
    },
};

static u8 GetTrainerTowerUnkVal(void)
{
    return (gSaveBlock1Ptr->trainerTower.unused + 1) % 256;
}

static bool32 ValidateTrainerChecksum(struct EReaderTrainerTowerTrainer * towerTrainer)
{
    int checksum = CalcByteArraySum((u8 *)towerTrainer, offsetof(typeof(*towerTrainer), checksum));
    if (checksum != towerTrainer->checksum)
        return FALSE;

    return TRUE;
}

bool8 ValidateTrainerTowerData(struct EReaderTrainerTowerSet * towerSet)
{
    u32 i;
    u32 checksum;
    int numTrainers = towerSet->numTrainers;

    // Validate number of trainers
    if (numTrainers < 1 || numTrainers > NUM_TRAINER_TOWER_TRAINERS)
        return FALSE;

    // Validate trainers
    for (i = 0; i < numTrainers; i++)
    {
        if (!ValidateTrainerChecksum(&towerSet->trainers[i]))
            return FALSE;
    }

    // Validate checksum
    checksum = CalcByteArraySum((u8 *)towerSet->trainers, numTrainers * sizeof(struct EReaderTrainerTowerTrainer));
    if (checksum != towerSet->checksum)
        return FALSE;

    return TRUE;
}

static bool32 ValidateTrainerTowerChecksum(struct EReaderTrainerTowerSet *towerSet)
{
    u32 checksum;
    int numTrainers = towerSet->numTrainers;
    if (numTrainers < 1 || numTrainers > NUM_TRAINER_TOWER_TRAINERS)
        return FALSE;

    checksum = CalcByteArraySum((u8 *)towerSet->trainers, sizeof(struct EReaderTrainerTowerSet) - offsetof(struct EReaderTrainerTowerSet, trainers));
    if (checksum != towerSet->checksum)
        return FALSE;

    return TRUE;
}

static bool32 TryWriteTrainerTower_Internal(struct EReaderTrainerTowerSet * towerSet, struct TrainerTowerChallenge * challenge)
{
    int i;

    AGB_ASSERT_EX(towerSet->dummy == 0, "cereader_tool.c", 450);
    AGB_ASSERT_EX(towerSet->id == 0, "cereader_tool.c", 452);

    memset(challenge, 0, SECTOR_SIZE);
    challenge->numTrainers = towerSet->numTrainers;
    challenge->unused1 = GetTrainerTowerUnkVal();
    challenge->numFloors = (towerSet->numTrainers + 1) / TOWER_TRAINERS_PER_FLOOR;

    for (i = 0; i < towerSet->numTrainers; i++)
    {
        if (!(i & 1))
        {
            challenge->floors[i / TOWER_TRAINERS_PER_FLOOR].trainerNum1 = towerSet->trainers[i].trainerNum;
            challenge->floors[i / TOWER_TRAINERS_PER_FLOOR].map = towerSet->trainers[i].map;
            challenge->floors[i / TOWER_TRAINERS_PER_FLOOR].trainers[0] = towerSet->trainers[i].trainer;
        }
        else
        {
            challenge->floors[i / TOWER_TRAINERS_PER_FLOOR].trainerNum2 = towerSet->trainers[i].trainerNum;
            challenge->floors[i / TOWER_TRAINERS_PER_FLOOR].trainers[1] = towerSet->trainers[i].trainer;
        }
    }

    if (i & 1)
    {
        challenge->floors[i / TOWER_TRAINERS_PER_FLOOR].trainers[1] = sTrainerTowerTrainerTemplates_JP[i / TOWER_TRAINERS_PER_FLOOR];
    }

    challenge->checksum = CalcByteArraySum((u8 *)challenge->floors, NUM_TRAINER_TOWER_FLOORS * sizeof(struct TrainerTowerFloor));
    if (TryWriteSpecialSaveSector(SECTOR_ID_TRAINER_TOWER, (u8 *)challenge) != SAVE_STATUS_OK)
        return FALSE;

    return TRUE;
}

bool32 TryWriteTrainerTower(struct EReaderTrainerTowerSet * towerSet)
{
    void *buffer = AllocZeroed(SECTOR_SIZE);
    bool32 result = TryWriteTrainerTower_Internal(towerSet, buffer);
    Free(buffer);
    return result;
}

static bool32 TryReadTrainerTower_Internal(struct EReaderTrainerTowerSet * dest, u8 *buffer)
{
    if (TryReadSpecialSaveSector(SECTOR_ID_TRAINER_TOWER, buffer) != SAVE_STATUS_OK)
        return FALSE;

    memcpy(dest, buffer, sizeof(struct EReaderTrainerTowerSet));
    if (!ValidateTrainerTowerChecksum(dest))
        return FALSE;

    return TRUE;
}

static bool32 TryReadTrainerTower(struct EReaderTrainerTowerSet * towerSet)
{
    u8 *buffer = AllocZeroed(SECTOR_SIZE);
    bool32 result = TryReadTrainerTower_Internal(towerSet, buffer);
    Free(buffer);
    return result;
}

bool32 ReadTrainerTowerAndValidate(void)
{
    struct EReaderTrainerTowerSet *towerSet = AllocZeroed(SECTOR_SIZE);
    bool32 result = TryReadTrainerTower(towerSet);
    Free(towerSet);
    return result;
}

int EReader_Send(int size, const void * src)
{
    int result;
    int sendStatus;

    EReaderHelper_SaveRegsState();
    while (1)
    {
        GetKeyInput();
        if (sJoyNew & B_BUTTON)
            gShouldAdvanceLinkState = 2;

        sendStatus = EReaderHandleTransfer(1, size, src, NULL);
        sSendRecvStatus = sendStatus;
        if ((sSendRecvStatus & EREADER_XFER_MASK) == 0 && sSendRecvStatus & EREADER_CHECKSUM_OK_MASK)
        {
            result = 0;
            break;
        }
        else if (sSendRecvStatus & EREADER_CANCEL_KEY_MASK)
        {
            result = 1;
            break;
        }
        else if (sSendRecvStatus & EREADER_CANCEL_TIMEOUT_MASK)
        {
            result = 2;
            break;
        }
        else
        {
            gShouldAdvanceLinkState = 0;
            VBlankIntrWait();
        }
    }

    CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
    EReaderHelper_RestoreRegsState();
    return result;
}

int EReader_Recv(void * dest)
{
    int result;
    int recvStatus;

    EReaderHelper_SaveRegsState();
    while (1)
    {
        GetKeyInput();
        if (sJoyNew & B_BUTTON)
            gShouldAdvanceLinkState = 2;

        recvStatus = EReaderHandleTransfer(0, 0, NULL, dest);
        sSendRecvStatus = recvStatus;
        if ((sSendRecvStatus & EREADER_XFER_MASK) == 0 && sSendRecvStatus & EREADER_CHECKSUM_OK_MASK)
        {
            result = 0;
            break;
        }
        else if (sSendRecvStatus & EREADER_CANCEL_KEY_MASK)
        {
            result = 1;
            break;
        }
        else if (sSendRecvStatus & EREADER_CANCEL_TIMEOUT_MASK)
        {
            result = 2;
            break;
        }
        else
        {
            gShouldAdvanceLinkState = 0;
            VBlankIntrWait();
        }
    }

    CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
    EReaderHelper_RestoreRegsState();
    return result;
}

static void CloseSerial(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_SIOCNT = 0;
    REG_TM3CNT_H = 0;
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
}

static void OpenSerialMulti(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= SIO_INTR_ENABLE | SIO_115200_BPS;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = 1;

    if (sSendRecvMgr.state == 0)
        CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
}

static void OpenSerial32(void)
{
    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE | SIO_INTR_ENABLE;
    REG_SIOCNT |= SIO_MULTI_SD;
    gShouldAdvanceLinkState = 0;
    sCounter1 = 0;
    sCounter2 = 0;
}

int EReaderHandleTransfer(u8 mode, size_t size, const void * data, void * recvBuffer)
{
    switch (sSendRecvMgr.state)
    {
    case EREADER_XFR_STATE_INIT:
        OpenSerialMulti();
        sSendRecvMgr.xferState = EREADER_XFER_EXE;
        sSendRecvMgr.state = EREADER_XFR_STATE_HANDSHAKE;
        break;
    case EREADER_XFR_STATE_HANDSHAKE:
        if (DetermineSendRecvState(mode))
            EnableSio();

        if (gShouldAdvanceLinkState == 2)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_KEY;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
    case EREADER_XFR_STATE_START:
        OpenSerial32();
        SetUpTransferManager(size, data, recvBuffer);
        sSendRecvMgr.state = EREADER_XFR_STATE_TRANSFER;
        // fall through
    case EREADER_XFR_STATE_TRANSFER:
        if (gShouldAdvanceLinkState == 2)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_KEY;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        else
        {
            sCounter1++;
            sCounter2++;
            if (!sSendRecvMgr.isParent && sCounter2 > 60)
            {
                sSendRecvMgr.cancellationReason = EREADER_CANCEL_TIMEOUT;
                sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
            }

            if (sSendRecvMgr.xferState != EREADER_XFER_CHK)
            {
                if (sSendRecvMgr.isParent && sCounter1 > 2)
                {
                    EnableSio();
                    sSendRecvMgr.xferState = EREADER_XFER_CHK;
                }
                else
                {
                    EnableSio();
                    sSendRecvMgr.xferState = EREADER_XFER_CHK;
                }
            }
        }
        break;
    case EREADER_XFR_STATE_TRANSFER_DONE:
        OpenSerialMulti();
        sSendRecvMgr.state = EREADER_XFR_STATE_CHECKSUM;
        break;
    case EREADER_XFR_STATE_CHECKSUM:
        if (sSendRecvMgr.isParent == TRUE && sCounter1 > 2)
            EnableSio();

        if (++sCounter1 > 60)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_TIMEOUT;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
    case EREADER_XFR_STATE_DONE:
        if (sSendRecvMgr.xferState)
        {
            CloseSerial();
            sSendRecvMgr.xferState = 0;
        }
        break;
    }

    return (sSendRecvMgr.xferState << EREADER_XFER_SHIFT)
         | (sSendRecvMgr.cancellationReason << EREADER_CANCEL_SHIFT)
         | (sSendRecvMgr.checksumResult << EREADER_CHECKSUM_SHIFT);
}

static u16 DetermineSendRecvState(u8 mode)
{
    bool16 resp;
    if ((*(vu32 *)REG_ADDR_SIOCNT & (SIO_MULTI_SI | SIO_MULTI_SD)) == SIO_MULTI_SD && mode)
        resp = sSendRecvMgr.isParent = TRUE;
    else
        resp = sSendRecvMgr.isParent = FALSE;
    return resp;
}

static void SetUpTransferManager(size_t size, const void * data, void * recvBuffer)
{
    if (sSendRecvMgr.isParent)
    {
        REG_SIOCNT |= SIO_38400_BPS;
        sSendRecvMgr.data = (void *)data;
        REG_SIODATA32 = size;
        sSendRecvMgr.size = size / 4 + 1;
        StartTm3();
    }
    else
    {
        REG_SIOCNT = REG_SIOCNT;
        sSendRecvMgr.data = recvBuffer;
    }
}

static void StartTm3(void)
{
    REG_TM3CNT_L = -601;
    REG_TM3CNT_H = TIMER_INTR_ENABLE;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_TIMER3;
    REG_IME = 1;
}

void EReaderHelper_Timer3Callback(void)
{
    DisableTm3();
    EnableSio();
}

void EReaderHelper_SerialCallback(void)
{
    u16 i, cnt1, cnt2;
    u32 recv32;
    u16 recv[4];

    switch (sSendRecvMgr.state)
    {
    case EREADER_XFR_STATE_HANDSHAKE:
        REG_SIOMLT_SEND = EREADER_HANDSHAKE;
        *(u64 *)recv = REG_SIOMLT_RECV;
        for (i = 0, cnt1 = 0, cnt2 = 0; i < 4; i++)
        {
            if (recv[i] == EREADER_HANDSHAKE)
                cnt1++;
            else if (recv[i] != 0xFFFF)
                cnt2++;
        }

        if (cnt1 == 2 && cnt2 == 0)
            sSendRecvMgr.state = 2;
        break;
    case EREADER_XFR_STATE_TRANSFER:
        recv32 = REG_SIODATA32;
        // The first value sent by the EReader is the payload size
        if (!sSendRecvMgr.cursor && !sSendRecvMgr.isParent)
            sSendRecvMgr.size = recv32 / 4 + 1;

        if (sSendRecvMgr.isParent == TRUE)
        {
            // Send mode
            if (sSendRecvMgr.cursor < sSendRecvMgr.size)
            {
                REG_SIODATA32 = sSendRecvMgr.data[sSendRecvMgr.cursor];
                sSendRecvMgr.checksum += sSendRecvMgr.data[sSendRecvMgr.cursor];
            }
            else
            {
                REG_SIODATA32 = sSendRecvMgr.checksum;
            }
        }
        else
        {
            // Receive mode
            if (sSendRecvMgr.cursor > 0 && sSendRecvMgr.cursor < sSendRecvMgr.size + 1)
            {
                sSendRecvMgr.data[sSendRecvMgr.cursor - 1] = recv32;
                sSendRecvMgr.checksum += recv32;
            }
            else if (sSendRecvMgr.cursor)
            {
                if (sSendRecvMgr.checksum == recv32)
                    sSendRecvMgr.checksumResult = EREADER_CHECKSUM_OK;
                else
                    sSendRecvMgr.checksumResult = EREADER_CHECKSUM_ERR;
            }

            sCounter2 = 0;
        }

        if (++sSendRecvMgr.cursor < sSendRecvMgr.size + 2)
        {
            if (sSendRecvMgr.isParent)
                REG_TM3CNT_H |= TIMER_ENABLE;
            else
                EnableSio();
        }
        else
        {
            sSendRecvMgr.state = EREADER_XFR_STATE_TRANSFER_DONE;
            sCounter1 = 0;
        }
        break;
    case EREADER_XFR_STATE_CHECKSUM:
        if (!sSendRecvMgr.isParent)
            REG_SIOMLT_SEND = sSendRecvMgr.checksumResult;

        *(vu64 *)recv = REG_SIOMLT_RECV;
        if (recv[1] == EREADER_CHECKSUM_OK || recv[1] == EREADER_CHECKSUM_ERR)
        {
            if (sSendRecvMgr.isParent == TRUE)
                sSendRecvMgr.checksumResult = recv[1]; // EReader has (in)validated the payload

            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
    }
}

static void EnableSio(void)
{
    REG_SIOCNT |= SIO_ENABLE;
}

static void DisableTm3(void)
{
    REG_TM3CNT_H &= ~TIMER_ENABLE;
    REG_TM3CNT_L = 0xFDA7;
}

static void GetKeyInput(void)
{
    int rawKeys = REG_KEYINPUT ^ KEYS_MASK;
    sJoyNew = rawKeys & ~sJoyNewOrRepeated;
    sJoyNewOrRepeated = rawKeys;
}

void EReaderHelper_SaveRegsState(void)
{
    sSavedIme = REG_IME;
    sSavedIe = REG_IE;
    sSavedTm3Cnt = REG_TM3CNT_H;
    sSavedSioCnt = REG_SIOCNT;
    sSavedRCnt = REG_RCNT;
}

void EReaderHelper_RestoreRegsState(void)
{
    REG_IME = sSavedIme;
    REG_IE = sSavedIe;
    REG_TM3CNT_H = sSavedTm3Cnt;
    REG_SIOCNT = sSavedSioCnt;
    REG_RCNT = sSavedRCnt;
}

void EReaderHelper_ClearSendRecvMgr(void)
{
    CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
}
