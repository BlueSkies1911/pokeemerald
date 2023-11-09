#ifndef GUARD_TRAINER_TOWER_H
#define GUARD_TRAINER_TOWER_H

#define DUMMY_TOWER_MON { .nickname = __("$$$$$$$$$$$") }

struct TrainerTowerTrainer
{
    u8 name[TRAINER_NAME_LENGTH + 1];
    u8 facilityClass;
    bool32 unused; // Set to TRUE on JP trainers
    u16 speechBefore[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechWin[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechLose[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechAfter[EASY_CHAT_BATTLE_WORDS_COUNT];
    struct BattleTowerPokemon mons[PARTY_SIZE];
};

struct TrainerTowerFloorMap
{
    u8 metatileData[TOWER_FLOOR_WIDTH * TOWER_FLOOR_HEIGHT_MAIN]; // Add NUM_METATILES_IN_PRIMARY to the values in this array to get metatile ids.
    u16 collisionData[TOWER_FLOOR_WIDTH]; // One bit for each tile in column-major order, so every array entry is one row. 1 = impassable, 0 = passable
    u8 trainerCoords[TOWER_TRAINERS_PER_FLOOR]; // Starting at (0,6). Format is 0bYYYYXXXX.
    u8 trainerDirections; // DIR_* - 1, 4 bits per trainer
    u8 trainerRanges; // 4 bits per trainer
};

struct TrainerTowerFloor
{
    u8 trainerNum1;
    u8 trainerNum2;
    struct TrainerTowerTrainer trainers[TOWER_TRAINERS_PER_FLOOR];
    struct TrainerTowerFloorMap map;
};

struct TrainerTowerChallenge
{
    u8 numTrainers;
    u8 unused1;
    u8 numFloors;
    u32 checksum; // A byte array sum of the floor data
    struct TrainerTowerFloor floors[0]; // Floor data is assumed to follow, so this will be intentionally read out of bounds
};

extern u32 *gTrainerTowerVBlankCounter;

void CallTrainerTowerFunction(void);
void ResetTrainerTowerResults(void);
u8 GetTrainerTowerOpponentClass(u16 trainerId);
void GetTrainerTowerTrainerName(u8 *dst, u16 trainerId);
u8 GetTrainerTowerTrainerFrontSpriteId(u16 trainerId);
void InitTrainerTowerBattleStruct(void);
void FreeTrainerTowerBattleStruct(void);
void CopyTrainerTowerTrainerText(u8 which, u16 trainerId);
bool8 InTrainerTowerChallenge(void);
void PrintOnTrainerTowerRecordsWindow(void);
void LoadTrainerTowerObjectEventTemplates(void);
bool32 LoadTrainerTowerFloorObjectEventScripts(void);
void GenerateTrainerTowerFloorLayout(u16 *mapArg);
bool32 InTrainerTower(void);
u8 GetCurrentTrainerTowerMapId(void);
const struct WarpEvent* SetWarpDestinationTrainerTower4F(void);
const struct WarpEvent* SetWarpDestinationTrainerTowerFinalFloor(u8 warpEventId);
u16 LocalIdToTowerTrainerId(u8 localId);
bool8 GetTowerTrainerFlag(u8 objectEventId);
void SetTowerTrainerFlag(void);
const u8 *GetTrainerTowerTrainerScript(void);
void FillTowerTrainerParty(void);
void FillTowerTrainersParties(void);
u8 GetTrainerEncounterMusicIdInTrainerTower(u16 trainerId);
u8 GetNumFloorsInTrainerTowerChallenge(void);
void TryLoadTrainerTowerEReaderPalette(void);
bool32 OnTrainerTowerEReaderChallengeFloor(void);

#endif // GUARD_TRAINER_TOWER_H
