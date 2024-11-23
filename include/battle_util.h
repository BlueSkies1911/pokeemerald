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
#define ABILITYEFFECT_SYNCHRONISE                7
#define ABILITYEFFECT_ATK_SYNCHRONISE            8
#define ABILITYEFFECT_TRACE1                     9
#define ABILITYEFFECT_TRACE2                     10
#define ABILITYEFFECT_SWITCH_IN_TERRAIN          16
#define ABILITYEFFECT_SWITCH_IN_WEATHER          17

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
#define ITEMEFFECT_STATS_CHANGED                9 // For White Herb and Eject Pack

#define WEATHER_HAS_EFFECT ((!IsAbilityOnField(ABILITY_CLOUD_NINE) && !IsAbilityOnField(ABILITY_AIR_LOCK)))

#define IS_ALIVE_AND_PRESENT(battler)   (IsBattlerAlive(battler) && IsBattlerSpritePresent(battler))

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

bool32 IsAffectedByFollowMe(u32 defSide, u32 move);
void HandleAction_UseMove(void);
void HandleAction_Switch(void);
void HandleAction_UseItem(void);
bool32 TryRunFromBattle(u32 battler);
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
extern const uq4_12_t sTypeEffectivenessTable[NUMBER_OF_MON_TYPES][NUMBER_OF_MON_TYPES];
u8 GetBattlerForBattleScript(u8 caseId);
bool32 IsBattlerMarkedForControllerExec(u32 battler);
void MarkBattlerForControllerExec(u32 battler);
void MarkBattlerReceivedLinkData(u32 battler);
const u8* CancelMultiTurnMoves(u32 battler);
bool32 WasUnableToUseMove(u32 battler);
void PrepareStringBattle(u16 stringId, u32 battler);
void ResetSentPokesToOpponentValue(void);
void UpdateSentPokesToOpponentValue(u32 battler);
void BattleScriptPush(const u8 *bsPtr);
void BattleScriptPushCursor(void);
void BattleScriptPop(void);
u32 TrySetCantSelectMoveBattleScript(u32 battler);
u8 CheckMoveLimitations(u32 battler, u8 unusableMoves, u16 check);
bool32 AreAllMovesUnusable(u32 battler);
u8 GetImprisonedMovesCount(u32 battler, u16 move);
u8 DoFieldEndTurnEffects(void);
s32 GetDrainedBigRootHp(u32 battler, s32 hp);
u8 DoBattlerEndTurnEffects(void);
bool32 HandleWishPerishSongOnTurnEnd(void);
bool32 HandleFaintedMonActions(void);
void TryClearRageAndFuryCutter(void);
u8 AtkCanceller_UnableToUseMove(u32 moveType);
void SetAtkCancellerForCalledMove(void);
u8 AtkCanceller_UnableToUseMove2(void);
bool32 HasNoMonsToSwitch(u32 battler, u8 r1, u8 r2);
bool32 TryChangeBattleWeather(u32 battler, u32 weatherEnumId, bool32 viaAbility);
u32 AbilityBattleEffects(u32 caseID, u32 battler, u32 ability, u32 special, u32 moveArg);
u32 GetBattlerAbility(u32 battler);
u32 IsAbilityOnSide(u32 battler, u32 ability);
u32 IsAbilityOnOpposingSide(u32 battler, u32 ability);
u32 IsAbilityOnField(u32 ability);
u32 IsAbilityPreventingEscape(u32 battler);
bool32 IsBattlerProtected(u32 battler, u32 move);
bool32 CanBattlerEscape(u32 battler); // no ability check
void BattleScriptExecute(const u8 *BS_ptr);
void BattleScriptPushCursorAndCallback(const u8 *BS_ptr);
u8 ItemBattleEffects(u8 caseID, u32 battler, bool32 moveTurn);
void ClearVariousBattlerFlags(u32 battler);
void HandleAction_RunBattleScript(void);
u32 SetRandomTarget(u32 battler);
u32 GetMoveTarget(u16 move, u8 setTarget);
u8 IsMonDisobedient(void);
u32 GetBattlerHoldEffect(u32 battler, bool32 checkNegating);
u32 GetBattlerHoldEffectInternal(u32 battler, bool32 checkNegating, bool32 checkAbility);
u32 GetBattlerHoldEffectParam(u32 battler);
bool32 IsBattlerGrounded(u32 battler);
bool32 IsBattlerAlive(u32 battler);
u32 GetMoveSlot(u16 *moves, u32 move);
u32 GetBattlerWeight(u32 battler);
u32 CalcRolloutBasePower(u32 battlerAtk, u32 basePower, u32 rolloutTimer);
u32 CalcFuryCutterBasePower(u32 basePower, u32 furyCutterCounter);
s32 CalculateMoveDamage(u32 move, u32 battlerAtk, u32 battlerDef, u32 moveType, s32 fixedBasePower, bool32 isCrit, bool32 randomFactor, bool32 updateFlags);
s32 CalculateMoveDamageVars(u32 move, u32 battlerAtk, u32 battlerDef, u32 moveType, s32 fixedBasePower, uq4_12_t typeEffectivenessModifier,
                                          u32 weather, bool32 isCrit, u32 holdEffectAtk, u32 holdEffectDef, u32 abilityAtk, u32 abilityDef);
uq4_12_t CalcTypeEffectivenessMultiplier(u32 move, u32 moveType, u32 battlerAtk, u32 battlerDef, u32 defAbility, bool32 recordAbilities);
uq4_12_t CalcPartyMonTypeEffectivenessMultiplier(u16 move, u16 speciesDef, u16 abilityDef);
s32 GetStealthHazardDamage(u8 hazardType, u32 battler);
s32 GetStealthHazardDamageByTypesAndHP(u8 hazardType, u8 type1, u8 type2, u32 maxHp);
bool32 DoBattlersShareType(u32 battler1, u32 battler2);
bool32 CanBattlerGetOrLoseItem(u32 battler, u16 itemId);
bool32 CanFling(u32 battler);
bool32 IsTelekinesisBannedSpecies(u16 species);
bool32 IsHealBlockPreventingMove(u32 battler, u32 move);
bool32 IsBelchPreventingMove(u32 battler, u32 move);
bool32 HasEnoughHpToEatBerry(u32 battler, u32 hpFraction, u32 itemId);
bool32 IsPartnerMonFromSameTrainer(u32 battler);
bool32 MoveIsAffectedBySheerForce(u32 move);
bool32 TestIfSheerForceAffected(u32 battler, u16 move);
void TryRestoreHeldItems(void);
bool32 CanStealItem(u32 battlerStealing, u32 battlerItem, u16 item);
void TrySaveExchangedItem(u32 battler, u16 stolenItem);
u8 TryHandleSeed(u32 battler, u32 terrainFlag, u8 statId, u16 itemId, bool32 execute);
void SortBattlersBySpeed(u8 *battlers, bool32 slowToFast);
bool32 CompareStat(u32 battler, u8 statId, u8 cmpTo, u8 cmpKind);
void BufferStatChange(u8 statId, u8 stringId);
u16 GetUsedHeldItem(u32 battler);
bool32 IsBattlerWeatherAffected(u32 battler, u32 weatherFlags);
void CopyMonLevelAndBaseStatsToBattleMon(u32 battler, struct Pokemon *mon);
bool32 IsAlly(u32 battlerAtk, u32 battlerDef);
bool32 MoveHasAdditionalEffect(u32 move, u32 moveEffect);
bool32 MoveHasAdditionalEffectWithChance(u32 move, u32 moveEffect, u32 chance);
bool32 MoveHasAdditionalEffectSelf(u32 move, u32 moveEffect);
bool32 MoveHasAdditionalEffectSelfArg(u32 move, u32 moveEffect, u32 argument);
bool32 MoveHasChargeTurnAdditionalEffect(u32 move);

bool32 CanSleep(u32 battler);
bool32 CanBePoisoned(u32 battlerAttacker, u32 battlerTarget);
bool32 CanBeBurned(u32 battler);
bool32 CanBeParalyzed(u32 battler);
bool32 CanBeFrozen(u32 battler);
bool32 CanBeConfused(u32 battler);
bool32 IsBattlerTerrainAffected(u32 battler, u32 terrainFlag);
void RemoveConfusionStatus(u32 battler);
u8 GetBattlerGender(u32 battler);
bool32 AreBattlersOfOppositeGender(u32 battler1, u32 battler2);
bool32 AreBattlersOfSameGender(u32 battler1, u32 battler2);
u32 CalcSecondaryEffectChance(u32 battler, u32 battlerAbility, const struct AdditionalEffect *additionalEffect);
bool32 MoveEffectIsGuaranteed(u32 battler, u32 battlerAbility, const struct AdditionalEffect *additionalEffect);
u8 GetBattlerType(u32 battler, u8 typeIndex);
void RemoveBattlerType(u32 battler, u8 type);

#endif // GUARD_BATTLE_UTIL_H
