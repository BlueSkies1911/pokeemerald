#ifndef GUARD_BATTLE_RECORDS_H
#define GUARD_BATTLE_RECORDS_H

extern u8 gRecordsWindowId;

void ClearPlayerLinkBattleRecords(void);
void UpdatePlayerLinkBattleRecords(s32 battlerId);
void ShowLinkBattleRecords(void);
void RemoveRecordsWindow(void);
void ShowTrainerTowerRecords(void);

#endif // GUARD_BATTLE_RECORDS_H
