#ifndef GUARD_BATTLE_UTIL_H
#define GUARD_BATTLE_UTIL_H

#define MOVE_LIMITATION_ZEROMOVE                (1 << 0)
#define MOVE_LIMITATION_PP                      (1 << 1)
#define MOVE_LIMITATION_DISABLED                (1 << 2)
#define MOVE_LIMITATION_TORMENTED               (1 << 3)
#define MOVE_LIMITATION_TAUNT                   (1 << 4)
#define MOVE_LIMITATION_IMPRISON                (1 << 5)
#define MOVE_LIMITATION_ENCORE                  (1 << 6)
#define MOVE_LIMITATION_CHOICE_ITEM             (1 << 7)
#define MOVE_LIMITATION_ASSAULT_VEST            (1 << 8)
#define MOVE_LIMITATION_GRAVITY                 (1 << 9)
#define MOVE_LIMITATION_HEAL_BLOCK              (1 << 10)
#define MOVE_LIMITATION_BELCH                   (1 << 11)
#define MOVE_LIMITATIONS_ALL                    0xFFFF

#define ABILITYEFFECT_ON_SWITCHIN                0
#define ABILITYEFFECT_ENDTURN                    1
#define ABILITYEFFECT_MOVES_BLOCK                2
#define ABILITYEFFECT_ABSORBING                  3
#define ABILITYEFFECT_MOVE_END_ATTACKER          4
#define ABILITYEFFECT_MOVE_END                   5
#define ABILITYEFFECT_IMMUNITY                   6
#define ABILITYEFFECT_SYNCHRONIZE                7
#define ABILITYEFFECT_ATK_SYNCHRONIZE            8
#define ABILITYEFFECT_TRACE1                     9
#define ABILITYEFFECT_TRACE2                     10
// Special cases
#define ABILITYEFFECT_SWITCH_IN_TERRAIN          254
#define ABILITYEFFECT_SWITCH_IN_WEATHER          255

// For the first argument of ItemBattleEffects, to deteremine which block of item effects to try
#define ITEMEFFECT_ON_SWITCH_IN                 0
#define ITEMEFFECT_NORMAL                       1
#define ITEMEFFECT_DUMMY                        2 // Unused, empty
#define ITEMEFFECT_MOVE_END                     3
#define ITEMEFFECT_KINGSROCK                    4
#define ITEMEFFECT_TARGET                       5
#define ITEMEFFECT_ORBS                         6
#define ITEMEFFECT_LIFEORB_SHELLBELL            7
#define ITEMEFFECT_USE_LAST_ITEM                8 // move end effects for just the battler, not whole field

#define WEATHER_HAS_EFFECT ((!IsAbilityOnField(ABILITY_CLOUD_NINE) && !IsAbilityOnField(ABILITY_AIR_LOCK)))

// for Natural Gift and Fling
struct TypePower
{
    u8 type;
    u8 power;
    u16 effect;
};

enum
{
    CANCELLER_FLAGS,
    CANCELLER_SKY_DROP,
    CANCELLER_ASLEEP,
    CANCELLER_FROZEN,
    CANCELLER_TRUANT,
    CANCELLER_RECHARGE,
    CANCELLER_FLINCH,
    CANCELLER_DISABLED,
    CANCELLER_GRAVITY,
    CANCELLER_HEAL_BLOCKED,
    CANCELLER_TAUNTED,
    CANCELLER_IMPRISONED,
    CANCELLER_CONFUSED,
    CANCELLER_PARALYSED,
    CANCELLER_GHOST,
    CANCELLER_IN_LOVE,
    CANCELLER_BIDE,
    CANCELLER_THAW,
    CANCELLER_POWDER_MOVE,
    CANCELLER_MULTIHIT_MOVES,
    CANCELLER_END,
    CANCELLER_PSYCHIC_TERRAIN,
    CANCELLER_END2,
};

extern const struct TypePower gNaturalGiftTable[];

bool32 IsAffectedByFollowMe(u32 battlerAtk, u32 defSide, u32 move);
void HandleAction_UseMove(void);
void HandleAction_Switch(void);
void HandleAction_UseItem(void);
void HandleAction_Run(void);
void HandleAction_WatchesCarefully(void);
void HandleAction_SafariZoneBallThrow(void);
void HandleAction_ThrowPokeblock(void);
void HandleAction_ThrowRock(void);
void HandleAction_SafariZoneRun(void);
void HandleAction_WallyBallThrow(void);
void HandleAction_TryFinish(void);
void HandleAction_NothingIsFainted(void);
void HandleAction_ActionFinished(void);
u8 GetBattlerForBattleScript(u8 caseId);
void PressurePPLose(u8 target, u8 attacker, u16 move);
void PressurePPLoseOnUsingPerishSong(u8 attacker);
void PressurePPLoseOnUsingImprison(u8 attacker);
void MarkBattlerForControllerExec(u8 battlerId);
void MarkBattlerReceivedLinkData(u8 battlerId);
void CancelMultiTurnMoves(u8 battlerId);
bool8 WasUnableToUseMove(u8 battlerId);
void PrepareStringBattle(u16 stringId, u8 battlerId);
void ResetSentPokesToOpponentValue(void);
void OpponentSwitchInResetSentPokesToOpponentValue(u8 battlerId);
void UpdateSentPokesToOpponentValue(u8 battlerId);
void BattleScriptPush(const u8 *bsPtr);
void BattleScriptPushCursor(void);
void BattleScriptPop(void);
u8 TrySetCantSelectMoveBattleScript(void);
u8 CheckMoveLimitations(u8 battlerId, u8 unusableMoves, u16 check);
bool8 AreAllMovesUnusable(void);
u8 GetImprisonedMovesCount(u8 battlerId, u16 move);
u8 DoFieldEndTurnEffects(void);
s32 GetDrainedBigRootHp(u32 battler, s32 hp);
u8 DoBattlerEndTurnEffects(void);
bool8 HandleWishPerishSongOnTurnEnd(void);
bool8 HandleFaintedMonActions(void);
void TryClearRageAndFuryCutter(void);
u8 AtkCanceller_UnableToUseMove(void);
void SetAtkCancellerForCalledMove(void);
u8 AtkCanceller_UnableToUseMove2(void);
bool8 HasNoMonsToSwitch(u8 battlerId, u8 r1, u8 r2);
bool32 TryChangeBattleWeather(u8 battler, u32 weatherEnumId, bool32 viaAbility);
u8 AbilityBattleEffects(u8 caseID, u8 battlerId, u16 ability, u8 special, u16 moveArg);
u32 GetBattlerAbility(u8 battlerId);
u32 IsAbilityOnSide(u32 battlerId, u32 ability);
u32 IsAbilityOnOpposingSide(u32 battlerId, u32 ability);
u32 IsAbilityOnField(u32 ability);
u32 IsAbilityPreventingEscape(u32 battlerId);
bool32 IsBattlerProtected(u8 battlerId, u16 move);
bool32 CanBattlerEscape(u32 battlerId); // no ability check
void BattleScriptExecute(const u8 *BS_ptr);
void BattleScriptPushCursorAndCallback(const u8 *BS_ptr);
u8 ItemBattleEffects(u8 caseID, u8 battlerId, bool8 moveTurn);
void ClearFuryCutterDestinyBondGrudge(u8 battlerId);
void HandleAction_RunBattleScript(void);
u32 SetRandomTarget(u32 battlerId);
u32 GetMoveTarget(u16 move, u8 setTarget);
u8 IsMonDisobedient(void);
u32 GetBattlerHoldEffect(u8 battlerId, bool32 checkNegating);
bool32 IsMoveMakingContact(u16 move, u8 battlerAtk);
bool32 IsBattlerGrounded(u8 battlerId);
bool32 IsBattlerAlive(u8 battlerId);
u8 GetBattleMonMoveSlot(struct BattlePokemon *battleMon, u16 move);
u32 GetBattlerWeight(u8 battlerId);
s32 CalculateMoveDamage(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, s32 fixedBasePower, bool32 isCrit, bool32 randomFactor, bool32 updateFlags);
s32 CalculateMoveDamageAndEffectiveness(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, u16 *typeEffectivenessModifier);
u16 CalcTypeEffectivenessMultiplier(u16 move, u8 moveType, u8 battlerAtk, u8 battlerDef, bool32 recordAbilities);
u16 CalcPartyMonTypeEffectivenessMultiplier(u16 move, u16 speciesDef, u16 abilityDef);
s32 GetStealthHazardDamage(u8 hazardType, u8 battlerId);
s32 GetStealthHazardDamageByTypesAndHP(u8 hazardType, u8 type1, u8 type2, u32 maxHp);
extern const u16 sTypeEffectivenessTable[NUMBER_OF_MON_TYPES][NUMBER_OF_MON_TYPES];
bool32 DoBattlersShareType(u32 battler1, u32 battler2);
bool32 CanBattlerGetOrLoseItem(u8 battlerId, u16 itemId);
bool32 TestMoveFlags(u16 move, u32 flag);
struct Pokemon *GetBattlerPartyData(u8 battlerId);
bool32 CanFling(u8 battlerId);
bool32 IsTelekinesisBannedSpecies(u16 species);
bool32 IsHealBlockPreventingMove(u32 battler, u32 move);
bool32 HasEnoughHpToEatBerry(u32 battlerId, u32 hpFraction, u32 itemId);
bool32 IsPartnerMonFromSameTrainer(u8 battlerId);
void SortBattlersBySpeed(u8 *battlers, bool8 slowToFast);
bool32 TestSheerForceFlag(u8 battler, u16 move);
void TryRestoreStolenItems(void);
bool32 CanStealItem(u8 battlerStealing, u8 battlerItem, u16 item);
void TrySaveExchangedItem(u8 battlerId, u16 stolenItem);
u8 TryHandleSeed(u8 battler, u32 terrainFlag, u8 statId, u16 itemId, bool32 execute);
bool32 IsBattlerAffectedByHazards(u8 battlerId, bool32 toxicSpikes);
bool32 CompareStat(u8 battlerId, u8 statId, u8 cmpTo, u8 cmpKind);
void BufferStatChange(u8 battlerId, u8 statId, u8 stringId);
u16 GetUsedHeldItem(u8 battler);
bool32 IsBattlerWeatherAffected(u8 battlerId, u32 weatherFlags);
// Ability checks
bool32 IsRolePlayBannedAbility(u16 ability);
bool32 IsSkillSwapBannedAbility(u16 ability);
bool32 IsEntrainmentBannedAbilityAttacker(u16 ability);

bool32 CanSleep(u8 battlerId);
bool32 CanBePoisoned(u8 battlerAttacker, u8 battlerTarget);
bool32 CanBeBurned(u8 battlerId);
bool32 CanBeParalyzed(u8 battlerId);
bool32 CanBeFrozen(u8 battlerId);
bool32 CanBeConfused(u8 battlerId);
bool32 IsBattlerTerrainAffected(u8 battlerId, u32 terrainFlag);
u32 CountBattlerStatIncreases(u8 battlerId, bool32 countEvasionAcc);
u8 GetBattlerType(u32 battler, u8 typeIndex);

#endif // GUARD_BATTLE_UTIL_H
