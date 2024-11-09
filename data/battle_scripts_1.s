#include "constants/global.h"
#include "constants/battle.h"
#include "constants/pokemon.h"
#include "constants/battle_arena.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_anim.h"
#include "constants/battle_string_ids.h"
#include "constants/abilities.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
#include "constants/trainers.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

BattleScript_MoveSwitch:
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_MoveSwitchEnd
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_MoveSwitchEnd
	printstring STRINGID_PKMNWENTBACK
	waitmessage B_WAIT_TIME_SHORT
	openpartyscreen BS_ATTACKER, BattleScript_MoveSwitchEnd
	switchoutabilities BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	switchineffects BS_ATTACKER
BattleScript_MoveSwitchEnd:
	end

BattleScript_StealthRockActivates::
	setstealthrock BattleScript_MoveEnd
	printfromtable gDmgHazardsStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SpikesActivates::
	trysetspikes BattleScript_MoveEnd
	printfromtable gDmgHazardsStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectSkyDrop::
	attackcanceler
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_SkyDropTurn2
	ppreduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpiftargetally BattleScript_ButItFailed
	jumpifunder200 BS_TARGET, BattleScript_SkyDropWork
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_TARGETTOOHEAVY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SkyDropWork:
	setskydrop
	call BattleScript_FirstChargingTurnAfterAttackString
	goto BattleScript_MoveEnd
BattleScript_SkyDropTurn2:
	call BattleScript_TwoTurnMovesSecondTurnRet
	attackstring
	clearskydrop BattleScript_SkyDropChangedTarget
	jumpiftype BS_TARGET, TYPE_FLYING, BattleScript_SkyDropFlyingType
	goto BattleScript_HitFromCritCalc
BattleScript_SkyDropFlyingType:
	makevisible BS_TARGET
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	makevisible BS_ATTACKER
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_SkyDropFlyingAlreadyConfused
	jumpifstatus2 BS_TARGET, STATUS2_LOCK_CONFUSE, BattleScript_SkyDropFlyingConfuseLock
	goto BattleScript_MoveEnd
BattleScript_SkyDropChangedTarget:
	pause B_WAIT_TIME_SHORT
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	makevisible BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_SkyDropFlyingConfuseLock:
	seteffectprimary MOVE_EFFECT_CONFUSION
BattleScript_SkyDropFlyingAlreadyConfused:
	clearstatusfromeffect BS_TARGET, MOVE_EFFECT_THRASH
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_MoveEnd
	setbyte BS_ATTACKER, BS_TARGET
	goto BattleScript_ThrashConfuses

BattleScript_EffectFling::
	attackcanceler
	jumpifcantfling BS_ATTACKER, BattleScript_FailedFromAtkString
	setlastuseditem BS_ATTACKER
	accuracycheck BattleScript_FlingMissed, ACC_CURR_MOVE
	attackstring
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNFLUNG
	waitmessage B_WAIT_TIME_SHORT
	ppreduce
	critcalc
	damagecalc
	adjustdamage
	removeitem BS_ATTACKER
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_MED
	resultmessage
	waitmessage B_WAIT_TIME_MED
	jumpiflastuseditemberry BattleScript_EffectFlingConsumeBerry
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_FLAME_ORB, BattleScript_FlingFlameOrb
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_FLINCH, BattleScript_FlingFlinch
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_LIGHT_BALL, BattleScript_FlingLightBall
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_MENTAL_HERB, BattleScript_FlingMentalHerb
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_POISON_POWER, BattleScript_FlingPoisonBarb
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_TOXIC_ORB, BattleScript_FlingToxicOrb
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_RESTORE_STATS, BattleScript_FlingWhiteHerb
	goto BattleScript_FlingEnd
BattleScript_EffectFlingConsumeBerry:
	savebattleritem BS_TARGET
	battleritemtolastuseditem BS_TARGET
	setbyte sBERRY_OVERRIDE, 1 @ override the requirements for eating berries
	orword gHitMarker, HITMARKER_DISABLE_ANIMATION
	consumeberry BS_TARGET, TRUE
	bicword gHitMarker, HITMARKER_DISABLE_ANIMATION
	setbyte sBERRY_OVERRIDE, 0
	restorebattleritem BS_TARGET
BattleScript_FlingEnd:
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_FlingFailConsumeItem::
	removeitem BS_ATTACKER
	goto BattleScript_FailedFromAtkString

BattleScript_FlingFlameOrb:
	seteffectsecondary MOVE_EFFECT_BURN
	goto BattleScript_FlingEnd
BattleScript_FlingFlinch:
	seteffectsecondary MOVE_EFFECT_FLINCH
	goto BattleScript_FlingEnd
BattleScript_FlingLightBall:
	seteffectsecondary MOVE_EFFECT_PARALYSIS
	goto BattleScript_FlingEnd
BattleScript_FlingMentalHerb:
	curecertainstatuses BS_TARGET
	savetarget
	copybyte gBattlerAttacker, gBattlerTarget
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printfromtable gMentalHerbCureStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	restoretarget
	goto BattleScript_FlingEnd
BattleScript_FlingPoisonBarb:
	seteffectsecondary MOVE_EFFECT_POISON
	goto BattleScript_FlingEnd
BattleScript_FlingToxicOrb:
	seteffectsecondary MOVE_EFFECT_TOXIC
	goto BattleScript_FlingEnd
BattleScript_FlingWhiteHerb:
	tryresetnegativestatstages BS_TARGET
	swapattackerwithtarget
	printstring STRINGID_PKMNSTATUSNORMAL
	waitmessage B_WAIT_TIME_MED
	swapattackerwithtarget
	goto BattleScript_FlingEnd

BattleScript_FlingMissed:
	removeitem BS_ATTACKER
	attackstring
	ppreduce
	goto BattleScript_MoveMissedPause

BattleScript_EffectAllySwitch::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifnoally BS_ATTACKER, BattleScript_ButItFailed
	allyswitchfailchance BattleScript_ButItFailed
	attackanimation
	waitanimation
	@ The actual data/gfx swap happens in the move animation. Here it's just the gBattlerAttacker / scripting battler change
	allyswitchswapbattlers
	printstring STRINGID_ALLYSWITCHPOSITION
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_FailIfNotArgType::
	attackcanceler
	attackstring
	ppreduce
	jumpifnotcurrentmoveargtype BS_ATTACKER, BattleScript_ButItFailed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_RemoveFireType::
	printstring STRINGID_ATTACKERLOSTFIRETYPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectStrengthSap::
	setstatchanger STAT_ATK, 1, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_ATK, MIN_STAT_STAGE, BattleScript_StrengthSapTryLower
	pause B_WAIT_TIME_SHORT
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_StrengthSapTryLower:
	getstatvalue BS_TARGET, STAT_ATK
	jumpiffullhp BS_ATTACKER, BattleScript_StrengthSapMustLower
	attackanimation
	waitanimation
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_StrengthSapHp
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_StrengthSapHp
BattleScript_StrengthSapLower:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_StrengthSapHp
	jumpiffullhp BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
BattleScript_StrengthSapHp:
	jumpifability BS_TARGET, ABILITY_LIQUID_OOZE, BattleScript_StrengthSapManipulateDmg
	jumpifstatus3 BS_ATTACKER, STATUS3_HEAL_BLOCK, BattleScript_MoveEnd
	jumpiffullhp BS_ATTACKER, BattleScript_MoveEnd
BattleScript_StrengthSapManipulateDmg:
	manipulatedamage DMG_BIG_ROOT
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	jumpifability BS_TARGET, ABILITY_LIQUID_OOZE, BattleScript_StrengthSapLiquidOoze
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNENERGYDRAINED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_StrengthSapLiquidOoze:
	call BattleScript_AbilityPopUpTarget
	manipulatedamage DMG_CHANGE_SIGN
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB_OOZE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printfromtable gAbsorbDrainStringIds
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd
BattleScript_StrengthSapMustLower:
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_MoveEnd
	attackanimation
	waitanimation
	goto BattleScript_StrengthSapLower

BattleScript_MoveEffectBugBite::
	printstring STRINGID_BUGBITE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_DISABLE_ANIMATION
	setbyte sBERRY_OVERRIDE, 1   @ override the requirements for eating berries
	savetarget
	consumeberry BS_ATTACKER, FALSE
	bicword gHitMarker, HITMARKER_DISABLE_ANIMATION
	setbyte sBERRY_OVERRIDE, 0
	restoretarget
	return

BattleScript_EffectLaserFocus::
	attackcanceler
	attackstring
	ppreduce
	setuserstatus3 STATUS3_LASER_FOCUS, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_LASERFOCUS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMagneticFlux::
	attackcanceler
	attackstring
	ppreduce
	setbyte gBattleCommunication, 0
BattleScript_EffectMagneticFluxStart:
	jumpifability BS_TARGET, ABILITY_MINUS, BattleScript_EffectMagneticFluxCheckStats
	jumpifability BS_TARGET, ABILITY_PLUS, BattleScript_EffectMagneticFluxCheckStats
	goto BattleScript_EffectMagneticFluxLoop
BattleScript_EffectMagneticFluxCheckStats:
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_EffectMagneticFluxTryDef
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_EffectMagneticFluxLoop
BattleScript_EffectMagneticFluxTryDef:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0, BattleScript_EffectMagneticFluxSkipAnim
	attackanimation
	waitanimation
BattleScript_EffectMagneticFluxSkipAnim:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_DEF | BIT_SPDEF, 0
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectMagneticFluxTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectMagneticFluxTrySpDef
	addbyte gBattleCommunication, 1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMagneticFluxTrySpDef:
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectMagneticFluxLoop
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectMagneticFluxLoop
	addbyte gBattleCommunication, 1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMagneticFluxLoop:
	jumpifbytenotequal gBattlerTarget, gBattlerAttacker, BattleScript_EffectMagneticFluxEnd
	setallytonexttarget BattleScript_EffectMagneticFluxStart
BattleScript_EffectMagneticFluxEnd:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0, BattleScript_MoveEnd
	goto BattleScript_ButItFailed

BattleScript_EffectAcupressure::
	attackcanceler
	jumpifbyteequal gBattlerTarget, gBattlerAttacker, BattleScript_EffectAcupressureTry
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_PrintMoveMissed
BattleScript_EffectAcupressureTry:
	attackstring
	ppreduce
	tryaccupressure BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	statbuffchange MOVE_EFFECT_CERTAIN, BattleScript_MoveEnd
	printstring STRINGID_DEFENDERSSTATROSE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveEffectFeint::
	printstring STRINGID_FELLFORFEINT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectRototiller::
	attackcanceler
	attackstring
	ppreduce
	getrototillertargets BattleScript_ButItFailed
	@ at least one battler is affected
	attackanimation
	waitanimation
	savetarget
	setbyte gBattlerTarget, 0
BattleScript_RototillerLoop:
	movevaluescleanup
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_RototillerCheckAffected
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_RototillerCantRaiseMultipleStats
BattleScript_RototillerCheckAffected:
	jumpifnotrototilleraffected BS_TARGET, BattleScript_RototillerNoEffect
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_RototillerTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_RototillerTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_RototillerTrySpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_RototillerMoveTargetEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_RototillerMoveTargetEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_RototillerMoveTargetEnd:
	moveendto MOVEEND_NEXT_TARGET
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_RototillerLoop
	end

BattleScript_RototillerCantRaiseMultipleStats:
	copybyte gBattlerAttacker, gBattlerTarget
	printstring STRINGID_STATSWONTINCREASE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_RototillerMoveTargetEnd

BattleScript_RototillerNoEffect:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_NOEFFECTONTARGET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_RototillerMoveTargetEnd

BattleScript_EffectBestow::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, NO_ACC_CALC_CHECK_LOCK_ON
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	trybestow BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_BESTOWITEMGIVING
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAfterYou::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryafteryou BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_KINDOFFER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveEffectFlameBurst::
	tryfaintmon BS_TARGET
	copybyte sBATTLER, sSAVED_BATTLER
	printstring STRINGID_BURSTINGFLAMESHIT
	waitmessage B_WAIT_TIME_LONG
	savetarget
	copybyte gBattlerTarget, sSAVED_BATTLER
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET
	restoretarget
	goto BattleScript_MoveEnd

BattleScript_EffectPowerTrick::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	powertrick BS_ATTACKER
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDATKANDDEF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPsychoShift::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifstatus BS_ATTACKER, STATUS1_ANY, BattleScript_EffectPsychoShiftCanWork
	goto BattleScript_ButItFailed
BattleScript_EffectPsychoShiftCanWork:
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifsafeguard BattleScript_SafeguardProtected
	trypsychoshift BattleScript_ButItFailed
	attackanimation
	waitanimation
	copybyte gEffectBattler, gBattlerTarget
	printfromtable gStatusConditionsStringIds
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_TARGET
	updatestatusicon BS_TARGET
	curestatus BS_ATTACKER
	printstring STRINGID_PKMNSTATUSNORMAL
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectSynchronoise::
	attackcanceler
	attackstring
	ppreduce
	selectfirstvalidtarget
BattleScript_SynchronoiseLoop:
	movevaluescleanup
	jumpifcantusesynchronoise BattleScript_SynchronoiseNoEffect
	accuracycheck BattleScript_SynchronoiseMissed, ACC_CURR_MOVE
	critcalc
	damagecalc
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	flushtextbox
	tryfaintmon BS_TARGET
BattleScript_SynchronoiseMoveTargetEnd:
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_SynchronoiseLoop
	end
BattleScript_SynchronoiseMissed:
	pause B_WAIT_TIME_SHORT
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_SynchronoiseMoveTargetEnd
BattleScript_SynchronoiseNoEffect:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_NOEFFECTONTARGET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_SynchronoiseMoveTargetEnd

BattleScript_MoveEffectSmackDown::
	printstring STRINGID_FELLSTRAIGHTDOWN
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectDefog::
	setstatchanger STAT_EVASION, 1, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_DefogIfCanClearHazards
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_EVASION, MIN_STAT_STAGE, BattleScript_DefogWorks
BattleScript_DefogIfCanClearHazards:
	trydefog FALSE, BattleScript_FailedFromAtkString
BattleScript_DefogWorks:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_DefogTryHazardsWithAnim
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_DefogDoAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_DefogTryHazardsWithAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_DefogPrintString
BattleScript_DefogDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_DefogPrintString::
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DefogTryHazards::
	copybyte gEffectBattler, gBattlerAttacker
	trydefog TRUE, NULL
	copybyte gBattlerAttacker, gEffectBattler
	goto BattleScript_MoveEnd
BattleScript_DefogTryHazardsWithAnim:
	attackanimation
	waitanimation
	goto BattleScript_DefogTryHazards

BattleScript_EffectCopycat::
	attackcanceler
	attackstring
	pause 5
	trycopycat BattleScript_CopycatFail
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE
BattleScript_CopycatFail:
	ppreduce
	goto BattleScript_ButItFailed

BattleScript_EffectAutotomise::
	setstatchanger STAT_SPEED, 2, FALSE
	attackcanceler
	attackstring
	ppreduce
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AutotomiseWeightLoss
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AutotomiseAttackAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_AutotomisePrintString
BattleScript_AutotomiseAttackAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_AutotomisePrintString::
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AutotomiseWeightLoss::
	jumpifmovehadnoeffect BattleScript_MoveEnd
	tryautotomise BS_ATTACKER, BattleScript_MoveEnd
	printstring STRINGID_BECAMENIMBLE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFinalGambit::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	critcalc
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	dmgtocurrattackerhp
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	dmgtocurrattackerhp
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	setadditionaleffects
	tryfaintmon BS_ATTACKER
	tryfaintmon BS_TARGET
	jumpifmovehadnoeffect BattleScript_MoveEnd
	goto BattleScript_MoveEnd

BattleScript_EffectHitSwitchTarget::
	call BattleScript_EffectHit_Ret
	tryfaintmon BS_TARGET
	jumpiffainted BS_TARGET, TRUE, BattleScript_MoveEnd
	jumpifability BS_TARGET, ABILITY_SUCTION_CUPS, BattleScript_AbilityPreventsPhasingOut
	jumpifstatus3 BS_TARGET, STATUS3_ROOTED, BattleScript_PrintMonIsRooted
	tryhitswitchtarget BattleScript_MoveEnd
	forcerandomswitch BattleScript_HitSwitchTargetForceRandomSwitchFailed
	goto BattleScript_MoveEnd

BattleScript_HitSwitchTargetForceRandomSwitchFailed:
	hitswitchtargetfailed
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	goto BattleScript_MoveEnd

BattleScript_EffectVenomDrench::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus BS_TARGET, STATUS1_PSN_ANY, BattleScript_EffectVenomDrenchCanBeUsed
	goto BattleScript_ButItFailed
BattleScript_EffectVenomDrenchCanBeUsed:
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_ATK, MIN_STAT_STAGE, BattleScript_VenomDrenchDoMoveAnim
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_SPATK, MIN_STAT_STAGE, BattleScript_VenomDrenchDoMoveAnim
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPEED, MIN_STAT_STAGE, BattleScript_CantLowerMultipleStats
BattleScript_VenomDrenchDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK | BIT_SPEED, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_VenomDrenchTryLowerSpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_VenomDrenchTryLowerSpAtk
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_VenomDrenchTryLowerSpAtk::
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_SPATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_VenomDrenchTryLowerSpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_VenomDrenchTryLowerSpeed
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_VenomDrenchTryLowerSpeed::
	playstatchangeanimation BS_TARGET, BIT_SPEED, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_VenomDrenchEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_VenomDrenchEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_VenomDrenchEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectShellSmash::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_DEF, MIN_STAT_STAGE, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MIN_STAT_STAGE, BattleScript_ButItFailed
BattleScript_ShellSmashTryDef::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_CANT_PREVENT
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_ShellSmashTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShellSmashTrySpDef:
	setstatchanger STAT_SPDEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_ShellSmashTryAttack
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTryAttack
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShellSmashTryAttack:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_ATK | BIT_SPEED, STAT_CHANGE_BY_TWO
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShellSmashTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShellSmashTrySpAtk:
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShellSmashTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShellSmashTrySpeed:
	setstatchanger STAT_SPEED, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShellSmashEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShellSmashEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectLastResort::
	attackcanceler
	attackstring
	ppreduce
	jumpifcantuselastresort BS_ATTACKER, BattleScript_ButItFailed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_EffectGrowth::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_GrowthDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_GrowthDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPATK, 0
	jumpifweatheraffected BS_ATTACKER, B_WEATHER_SUN, BattleScript_GrowthAtk2
	setstatchanger STAT_ATK, 1, FALSE
	goto BattleScript_GrowthAtk
BattleScript_GrowthAtk2:
	setstatchanger STAT_ATK, 2, FALSE
BattleScript_GrowthAtk:
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_GrowthTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_GrowthTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_GrowthTrySpAtk::
	jumpifweatheraffected BS_ATTACKER, B_WEATHER_SUN, BattleScript_GrowthSpAtk2
	setstatchanger STAT_SPATK, 1, FALSE
	goto BattleScript_GrowthSpAtk
BattleScript_GrowthSpAtk2:
	setstatchanger STAT_SPATK, 2, FALSE
BattleScript_GrowthSpAtk:
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_GrowthEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_GrowthEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_GrowthEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectSoak::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	attackanimation
	waitanimation
	trysoak BattleScript_ButItFailed
	printstring STRINGID_TARGETCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectReflectType::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryreflecttype BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_REFLECTTARGETSTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectCoil::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_CoilDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_CoilDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_ACC, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_CoilDoMoveAnim:
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_ACC, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CoilTryDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CoilTryDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CoilTryDef:
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CoilTryAcc
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CoilTryAcc
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CoilTryAcc:
	setstatchanger STAT_ACC, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CoilEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CoilEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CoilEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectQuiverDance::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_QuiverDanceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_QuiverDanceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_QuiverDanceDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF | BIT_SPEED, 0
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_QuiverDanceTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_QuiverDanceTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_QuiverDanceTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_QuiverDanceTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_QuiverDanceTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_QuiverDanceTrySpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_QuiverDanceEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_QuiverDanceEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_QuiverDanceEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectMeFirst::
	attackcanceler
	attackstring
	trymefirst BattleScript_FailedFromPpReduce
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE

BattleScript_EffectAttackSpAttackUp::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_AttackSpAttackUpDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_AttackSpAttackUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPATK, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackSpAttackUpTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackSpAttackUpTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackSpAttackUpTrySpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackSpAttackUpEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackSpAttackUpEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackSpAttackUpEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectAttackAccUp::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_AttackAccUpDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_ACC, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_AttackAccUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackAccUpTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackAccUpTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackAccUpTrySpDef::
	setstatchanger STAT_ACC, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackAccUpEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackAccUpEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackAccUpEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectMistyTerrain::
BattleScript_EffectGrassyTerrain::
BattleScript_EffectElectricTerrain::
BattleScript_EffectPsychicTerrain::
	attackcanceler
	attackstring
	ppreduce
	setremoveterrain BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	goto BattleScript_MoveEnd

BattleScript_EffectIonDeluge::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	orword gFieldStatuses, STATUS_FIELD_ION_DELUGE
	attackanimation
	waitanimation
	printstring STRINGID_IONDELUGEON
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectQuash::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryquash BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_QUASHSUCCESS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHealPulse::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus3 BS_ATTACKER, STATUS3_HEAL_BLOCK, BattleScript_MoveUsedHealBlockPrevents @ stops pollen puff
	jumpifstatus3 BS_TARGET, STATUS3_HEAL_BLOCK, BattleScript_MoveUsedHealBlockPrevents
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifsubstituteblocks BattleScript_ButItFailed
	tryhealpulse BattleScript_AlreadyAtFullHp
	attackanimation
	waitanimation
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectEntrainment::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryentrainment BattleScript_ButItFailed
	attackanimation
	waitanimation
	setlastusedability BS_TARGET
	printstring STRINGID_PKMNACQUIREDABILITY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSimpleBeam::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setabilitysimple BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNACQUIREDSIMPLE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSuckerPunch::
	attackcanceler
	suckerpunchcheck BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromAtkString

BattleScript_EffectLuckyChant::
	attackcanceler
	attackstring
	ppreduce
	setluckychant BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_SHIELDEDFROMCRITICALHITS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMetalBurst::
	attackcanceler
	metalburstdamagecalculator BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectHealingWish::
	attackcanceler
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	instanthpdrop BS_ATTACKER
	setatkhptozero
	tryfaintmon BS_ATTACKER
	storehealingwish BS_ATTACKER
	moveendall
	end

BattleScript_HealingWishActivates::
	setbyte cMULTISTRING_CHOOSER, 0
	printfromtable gHealingWishStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_WISH_HEAL
	waitanimation
	dmgtomaxattackerhp
	manipulatedamage DMG_CHANGE_SIGN
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	clearstatus BS_ATTACKER
	waitstate
	updatestatusicon BS_ATTACKER
	waitstate
	printstring STRINGID_HEALINGWISHHEALED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectWorrySeed::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryworryseed BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNACQUIREDABILITY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPowerSplit::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	averagestats STAT_ATK
	averagestats STAT_SPATK
	attackanimation
	waitanimation
	printstring STRINGID_SHAREDITSPOWER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGuardSplit::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	averagestats STAT_DEF
	averagestats STAT_SPDEF
	attackanimation
	waitanimation
	printstring STRINGID_SHAREDITSGUARD
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHeartSwap::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstatstages STAT_ATK
	swapstatstages STAT_DEF
	swapstatstages STAT_SPEED
	swapstatstages STAT_SPATK
	swapstatstages STAT_SPDEF
	swapstatstages STAT_EVASION
	swapstatstages STAT_ACC
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPowerSwap::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstatstages STAT_ATK
	swapstatstages STAT_SPATK
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGuardSwap::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstatstages STAT_DEF
	swapstatstages STAT_SPDEF
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTelekinesis::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, NO_ACC_CALC_CHECK_LOCK_ON
	attackstring
	ppreduce
	settelekinesis BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_HURLEDINTOTHEAIR
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectStealthRock::
	attackcanceler
	attackstring
	ppreduce
	setstealthrock BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_POINTEDSTONESFLOAT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGastroAcid::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setgastroacid BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSABILITYSUPPRESSED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectToxicSpikes::
	attackcanceler
	attackstring
	ppreduce
	settoxicspikes BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_POISONSPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMagnetRise::
	attackcanceler
	attackstring
	ppreduce
	setuserstatus3 STATUS3_MAGNET_RISE, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNLEVITATEDONELECTROMAGNETISM
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTrickRoom::
	attackcanceler
	attackstring
	ppreduce
	setroom
	attackanimation
	waitanimation
	printfromtable gRoomsStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectWonderRoom::
BattleScript_EffectMagicRoom::
	attackcanceler
	attackstring
	ppreduce
	setroom
	attackanimation
	waitanimation
	printfromtable gRoomsStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAquaRing::
	attackcanceler
	attackstring
	ppreduce
	setuserstatus3 STATUS3_AQUA_RING, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSURROUNDEDWITHVEILOFWATER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectEmbargo::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setembargo BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCANTUSEITEMSANYMORE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTailwind::
	attackcanceler
	attackstring
	ppreduce
	settailwind BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_TAILWINDBLEW
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMiracleEye::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmiracleeye BattleScript_ButItFailed
	goto BattleScript_IdentifiedFoe

BattleScript_EffectGravity::
	attackcanceler
	attackstring
	ppreduce
	setgravity BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_GRAVITYINTENSIFIED
	waitmessage B_WAIT_TIME_LONG
	selectfirstvalidtarget
BattleScript_GravityLoop:
	movevaluescleanup
	jumpifstatus3 BS_TARGET, STATUS3_ON_AIR | STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS, BattleScript_GravityLoopDrop
	goto BattleScript_GravityLoopEnd
BattleScript_GravityLoopDrop:
	bringdownairbornebattler BS_TARGET
	printstring STRINGID_GRAVITYGROUNDING
	waitmessage B_WAIT_TIME_LONG
BattleScript_GravityLoopEnd:
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_GravityLoop
	end

BattleScript_EffectRoost::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_TARGET
	setroost
	goto BattleScript_PresentHealTarget

BattleScript_EffectCaptivate::
	setstatchanger STAT_SPATK, 2, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	jumpifoppositegenders BattleScript_CaptivateCheckAcc
	goto BattleScript_FailedFromAtkString
BattleScript_CaptivateCheckAcc:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_StatDownFromAttackString

BattleScript_EffectHealBlock::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	sethealblock BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNPREVENTEDFROMHEALING
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHitEscape::
	call BattleScript_EffectHit_Ret
	jumpifmovehadnoeffect BattleScript_MoveEnd
	tryfaintmon BS_TARGET
	moveendto MOVEEND_ATTACKER_VISIBLE
	moveendfrom MOVEEND_TARGET_VISIBLE
	jumpifbattleend BattleScript_HitEscapeEnd
	jumpifbyte CMP_NOT_EQUAL, gBattleOutcome, 0, BattleScript_HitEscapeEnd
	goto BattleScript_MoveSwitch
BattleScript_HitEscapeEnd:
	end

BattleScript_EffectHit::
	attackcanceler
BattleScript_HitFromAccCheck::
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
BattleScript_HitFromAtkString::
	attackstring
	ppreduce
BattleScript_HitFromCritCalc::
	critcalc
	damagecalc
	adjustdamage
BattleScript_HitFromAtkAnimation::
	call BattleScript_Hit_RetFromAtkAnimation
BattleScript_TryFaintMon::
	tryfaintmon BS_TARGET
BattleScript_MoveEnd::
	moveendall
	end

BattleScript_EffectHit_Ret::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
BattleScript_EffectHit_RetFromCritCalc::
	critcalc
	damagecalc
	adjustdamage
BattleScript_Hit_RetFromAtkAnimation::
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	setadditionaleffects
	return

BattleScript_EffectNaturalGift::
	attackcanceler
	attackstring
	ppreduce
	jumpifnotberry BS_ATTACKER, BattleScript_ButItFailed
	jumpifword CMP_COMMON_BITS, gFieldStatuses, STATUS_FIELD_MAGIC_ROOM, BattleScript_ButItFailed
	jumpifstatus3 BS_ATTACKER, STATUS3_EMBARGO, BattleScript_ButItFailed
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	call BattleScript_EffectHit_RetFromCritCalc
	jumpifmovehadnoeffect BattleScript_EffectNaturalGiftEnd
	removeitem BS_ATTACKER
BattleScript_EffectNaturalGiftEnd:
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_MakeMoveMissed::
	orhalfword gMoveResultFlags, MOVE_RESULT_MISSED
BattleScript_PrintMoveMissed::
	attackstring
	ppreduce
BattleScript_MoveMissedPause::
	pause B_WAIT_TIME_SHORT
BattleScript_MoveMissed::
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSleep::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_AlreadyAsleep
	jumpifuproarwakes BattleScript_CantMakeAsleep
	jumpifability BS_TARGET, ABILITY_INSOMNIA, BattleScript_InsomniaProtects
	jumpifability BS_TARGET, ABILITY_VITAL_SPIRIT, BattleScript_InsomniaProtects
	jumpifleafguardprotected BS_TARGET, BattleScript_AbilityProtectsDoesntAffect
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_ELECTRIC_TERRAIN, BattleScript_ElectricTerrainPrevents
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_SLEEP
	goto BattleScript_MoveEnd

BattleScript_TerrainPreventsEnd2::
	pause B_WAIT_TIME_SHORT
	printfromtable gTerrainPreventsStringIds
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_ElectricTerrainPrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ELECTRICTERRAINPREVENTS
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_MistyTerrainPrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MISTYTERRAINPREVENTS
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_AbilityProtectsDoesntAffectRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityProtectsDoesntAffect:
	call BattleScript_AbilityProtectsDoesntAffectRet
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_InsomniaProtects:
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSTAYEDAWAKEUSING
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_AlreadyAsleep::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYASLEEP
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_WasntAffected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNWASNTAFFECTED
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_CantMakeAsleep::
	pause B_WAIT_TIME_SHORT
	printfromtable gUproarAwakeStringIds
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_EffectAbsorb::
	call BattleScript_EffectHit_Ret
	jumpifstatus3 BS_ATTACKER, STATUS3_HEAL_BLOCK, BattleScript_AbsorbHealBlock
	setdrainedhp
	manipulatedamage DMG_BIG_ROOT
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	jumpifability BS_TARGET, ABILITY_LIQUID_OOZE, BattleScript_AbsorbLiquidOoze
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB
	goto BattleScript_AbsorbUpdateHp
BattleScript_AbsorbLiquidOoze::
	call BattleScript_AbilityPopUpTarget
	manipulatedamage DMG_CHANGE_SIGN
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB_OOZE
BattleScript_AbsorbUpdateHp::
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	jumpifmovehadnoeffect BattleScript_AbsorbTryFainting
	printfromtable gAbsorbDrainStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AbsorbTryFainting::
	tryfaintmon BS_ATTACKER
BattleScript_AbsorbHealBlock::
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectExplosion::
	attackcanceler
	attackstring
	ppreduce
	tryexplosion
	setatkhptozero
	waitstate
	jumpiffainted BS_TARGET, TRUE, BattleScript_MoveEnd
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_FaintAttackerForExplosion::
	tryfaintmon BS_ATTACKER
	return

BattleScript_EffectDreamEater::
	attackcanceler
	jumpifsubstituteblocks BattleScript_DreamEaterNoEffect
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_DreamEaterWorked
BattleScript_DreamEaterNoEffect:
	attackstring
	ppreduce
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_WasntAffected
BattleScript_DreamEaterWorked:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	critcalc
	damagecalc
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifstatus3 BS_ATTACKER, STATUS3_HEAL_BLOCK, BattleScript_DreamEaterTryFaintEnd
	setdrainedhp
	manipulatedamage DMG_BIG_ROOT
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	jumpifmovehadnoeffect BattleScript_DreamEaterTryFaintEnd
	printstring STRINGID_PKMNDREAMEATEN
	waitmessage B_WAIT_TIME_LONG
BattleScript_DreamEaterTryFaintEnd:
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectMirrorMove::
	attackcanceler
	attackstring
	pause B_WAIT_TIME_LONG
	trymirrormove
	ppreduce
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_MIRRORMOVEFAILED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUp::
	setstatchanger STAT_ATK, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp::
	setstatchanger STAT_DEF, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp::
	setstatchanger STAT_SPATK, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpeedUp::
	setstatchanger STAT_SPEED, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialDefenseUp::
	setstatchanger STAT_SPDEF, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectAccuracyUp::
	setstatchanger STAT_ACC, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectEvasionUp::
	setstatchanger STAT_EVASION, 1, FALSE
BattleScript_EffectStatUp::
	attackcanceler
BattleScript_EffectStatUpAfterAtkCanceler::
	attackstring
	ppreduce
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_StatUpEnd
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_StatUpAttackAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_StatUpPrintString
BattleScript_StatUpAttackAnim::
	attackanimation
	waitanimation
BattleScript_StatUpDoAnim::
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_StatUpPrintString::
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_StatUpEnd::
	goto BattleScript_MoveEnd

BattleScript_StatUp::
	playanimation BS_EFFECT_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectAttackDown::
	setstatchanger STAT_ATK, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectDefenseDown::
	setstatchanger STAT_DEF, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpeedDown::
	setstatchanger STAT_SPEED, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectAccuracyDown::
	setstatchanger STAT_ACC, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialAttackDown::
	setstatchanger STAT_SPATK, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialDefenseDown::
	setstatchanger STAT_SPDEF, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectEvasionDown::
	setstatchanger STAT_EVASION, 1, TRUE
BattleScript_EffectStatDown:
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
BattleScript_StatDownFromAttackString:
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_StatDownEnd
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_StatDownDoAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_StatDownEnd
	pause B_WAIT_TIME_SHORT
	goto BattleScript_StatDownPrintString
BattleScript_StatDownDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_StatDownPrintString::
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_StatDownEnd::
	goto BattleScript_MoveEnd

BattleScript_StatDown::
	playanimation BS_EFFECT_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectHaze::
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	normalisebuffs
	printstring STRINGID_STATCHANGESGONE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectBide::
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_CHARGING
	setbide
	goto BattleScript_MoveEnd

BattleScript_EffectRoar::
	attackcanceler
	attackstring
	ppreduce
	jumpifroarfails BattleScript_ButItFailed
	jumpifability BS_TARGET, ABILITY_SUCTION_CUPS, BattleScript_AbilityPreventsPhasingOut
	jumpifstatus3 BS_TARGET, STATUS3_ROOTED, BattleScript_PrintMonIsRooted
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_ButItFailed
	forcerandomswitch BattleScript_ButItFailed

BattleScript_MultiHitLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_MultiHitEnd
	jumpifhasnohp BS_TARGET, BattleScript_MultiHitPrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoMultiHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_MultiHitPrintStrings
BattleScript_DoMultiHit::
	movevaluescleanup
	copyhword sMOVE_EFFECT, sMULTIHIT_EFFECT
	critcalc
	damagecalc
	jumpifmovehadnoeffect BattleScript_MultiHitNoMoreHits
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	multihitresultmessage
	flushtextbox
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_MultiHitPrintStrings
	decrementmultihit BattleScript_MultiHitLoop
	goto BattleScript_MultiHitPrintStrings
BattleScript_MultiHitNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_MultiHitPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifmovehadnoeffect BattleScript_MultiHitEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MultiHitEnd::
	setadditionaleffects
	tryfaintmon BS_TARGET
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end

BattleScript_EffectConversion::
	attackcanceler
	attackstring
	ppreduce
	tryconversiontypechange BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRestoreHp::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_ATTACKER
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectToxic::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_IMMUNITY, BattleScript_ImmunityProtected
	jumpifleafguardprotected BS_TARGET, BattleScript_AbilityProtectsDoesntAffect
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_POISON | STATUS1_TOXIC_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	trypoisontype BS_ATTACKER, BS_TARGET, BattleScript_NotAffected
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_TOXIC
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyPoisoned::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_LONG
	printstring STRINGID_PKMNALREADYPOISONED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_ImmunityProtected::
	copybyte gEffectBattler, gBattlerTarget
	call BattleScript_AbilityPopUp
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_PSNPrevention
	goto BattleScript_MoveEnd

BattleScript_EffectAuroraVeil::
	attackcanceler
	attackstring
	ppreduce
	setauroraveil BS_ATTACKER
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectLightScreen::
	attackcanceler
	attackstring
	ppreduce
	setlightscreen
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectRest::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_RestIsAlreadyAsleep
	jumpifuproarwakes BattleScript_RestCantSleep
	jumpifability BS_TARGET, ABILITY_INSOMNIA, BattleScript_InsomniaProtects
	jumpifability BS_TARGET, ABILITY_VITAL_SPIRIT, BattleScript_InsomniaProtects
	trysetrest BattleScript_AlreadyAtFullHp
	pause B_WAIT_TIME_SHORT
	printfromtable gRestUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	waitstate
	goto BattleScript_PresentHealTarget

BattleScript_RestCantSleep::
	pause B_WAIT_TIME_LONG
	printfromtable gUproarAwakeStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_RestIsAlreadyAsleep::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYASLEEP2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectOHKO::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	typecalc
	jumpifmovehadnoeffect BattleScript_HitFromAtkAnimation
	tryKO BattleScript_KOFail
	trysetdestinybondtohappen
	goto BattleScript_HitFromAtkAnimation
BattleScript_KOFail::
	pause B_WAIT_TIME_LONG
	printfromtable gKOFailedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSuperFang::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	damagetohalftargethp
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectRecoilIfMiss::
	attackcanceler
	accuracycheck BattleScript_MoveMissedDoDamage, ACC_CURR_MOVE
	typecalc
	jumpifhalfword CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_MoveMissedDoDamage
	goto BattleScript_HitFromAtkString
BattleScript_MoveMissedDoDamage::
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_PrintMoveMissed
	attackstring
	ppreduce
	pause B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifhasnohp BS_ATTACKER, BattleScript_MoveEnd
	printstring STRINGID_PKMNCRASHED
	waitmessage B_WAIT_TIME_LONG
	damagecalc
	typecalc
	adjustdamage
	manipulatedamage DMG_RECOIL_FROM_MISS
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	orhalfword gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_EffectMist::
	attackcanceler
	attackstring
	ppreduce
	setmist
	attackanimation
	waitanimation
	printfromtable gMistUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFocusEnergy::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_ATTACKER, STATUS2_FOCUS_ENERGY, BattleScript_ButItFailed
	setfocusenergy BS_TARGET
	attackanimation
	waitanimation
	printfromtable gFocusEnergyUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectConfuse::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_AlreadyConfused
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_CONFUSION
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyConfused::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYCONFUSED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUp2::
	setstatchanger STAT_ATK, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp2::
	setstatchanger STAT_DEF, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpeedUp2::
	setstatchanger STAT_SPEED, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp2::
	setstatchanger STAT_SPATK, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp3::
	setstatchanger STAT_SPATK, 3, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialDefenseUp2::
	setstatchanger STAT_SPDEF, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectAccuracyUp2::
	setstatchanger STAT_ACC, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectEvasionUp2::
	setstatchanger STAT_EVASION, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectTransform::
	attackcanceler
	attackstring
	ppreduce
	transformdataexecution
	attackanimation
	waitanimation
	printfromtable gTransformUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAttackDown2::
	setstatchanger STAT_ATK, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectDefenseDown2::
	setstatchanger STAT_DEF, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpeedDown2::
	setstatchanger STAT_SPEED, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialDefenseDown2::
	setstatchanger STAT_SPDEF, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialAttackDown2::
	setstatchanger STAT_SPATK, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectAccuracyDown2::
	setstatchanger STAT_ACC, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectEvasionDown2::
	setstatchanger STAT_EVASION, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectReflect::
	attackcanceler
	attackstring
	ppreduce
	setreflect
BattleScript_PrintReflectLightScreenSafeguardString::
	attackanimation
	waitanimation
	printfromtable gReflectLightScreenSafeguardStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPoison::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_IMMUNITY, BattleScript_ImmunityProtected
	jumpifleafguardprotected BS_TARGET, BattleScript_AbilityProtectsDoesntAffect
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_TOXIC_POISON, BattleScript_AlreadyPoisoned
	trypoisontype BS_ATTACKER, BS_TARGET, BattleScript_NotAffected
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_POISON
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectParalyze::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_LIMBER, BattleScript_LimberProtected
	jumpifleafguardprotected BS_TARGET, BattleScript_AbilityProtectsDoesntAffect
	jumpifsubstituteblocks BattleScript_ButItFailed
	typecalc
	jumpifmovehadnoeffect BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_PARALYSIS, BattleScript_AlreadyParalyzed
	jumpifabsorbaffected BS_TARGET, BattleScript_VoltAbsorbHeal
	tryparalyzetype BS_ATTACKER, BS_TARGET, BattleScript_NotAffected
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_PARALYSIS
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_VoltAbsorbHeal:
	copybyte gBattlerAbility, gBattlerTarget
	tryhealquarterhealth BS_TARGET BattleScript_MonMadeMoveUseless @ Check if max hp
	goto BattleScript_MoveHPDrain

BattleScript_AlreadyParalyzed:
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNISALREADYPARALYZED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_LimberProtected::
	copybyte gEffectBattler, gBattlerTarget
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_PRLZPrevention
	goto BattleScript_MoveEnd

BattleScript_PowerHerbActivation:
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_POWERHERB
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER
	return

BattleScript_EffectTwoTurnsAttack::
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	tryfiretwoturnmovewithoutcharging BS_ATTACKER, BattleScript_EffectHit @ e.g. Solar Beam
	call BattleScript_FirstChargingTurn
	tryfiretwoturnmoveaftercharging BS_ATTACKER, BattleScript_TwoTurnMovesSecondTurn @ e.g. Electro Shot
	jumpifholdeffect BS_ATTACKER, HOLD_EFFECT_POWER_HERB, BattleScript_TwoTurnMovesSecondPowerHerbActivates
	goto BattleScript_MoveEnd

BattleScript_FirstChargingTurn::
	attackcanceler
	flushtextbox
	attackstring
	waitmessage B_WAIT_TIME_LONG
	ppreduce
BattleScript_FirstChargingTurnAfterAttackString:
	setsemiinvulnerablebit @ only for moves with EFFECT_SEMI_INVULNERABLE/EFFECT_SKY_DROP
	orword gHitMarker, HITMARKER_CHARGING
	seteffectprimary MOVE_EFFECT_CHARGING | MOVE_EFFECT_AFFECTS_USER
	twoturnmoveschargestringandanimation
	setadditionaleffects @ only onChargeTurnOnly effects will work here
	return

BattleScript_TwoTurnMovesSecondPowerHerbActivates:
	call BattleScript_PowerHerbActivation
	call BattleScript_TwoTurnMovesSecondTurnRet
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_TwoTurnMovesSecondTurn::
	attackcanceler
	call BattleScript_TwoTurnMovesSecondTurnRet
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	goto BattleScript_HitFromAccCheck

BattleScript_TwoTurnMovesSecondTurnRet:
	setbyte sB_ANIM_TURN, 1
	clearstatusfromeffect BS_ATTACKER, MOVE_EFFECT_CHARGING
	clearsemiinvulnerablebit @ only for moves with EFFECT_SEMI_INVULNERABLE/EFFECT_SKY_DROP
	return

BattleScript_EffectSubstitute::
	attackcanceler
	ppreduce
	attackstring
	waitstate
	jumpifstatus2 BS_ATTACKER, STATUS2_SUBSTITUTE, BattleScript_AlreadyHasSubstitute
	setsubstitute
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_SUBSTITUTE_FAILED, BattleScript_SubstituteString
	orword gHitMarker, HITMARKER_PASSIVE_DAMAGE
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
BattleScript_SubstituteString::
	pause B_WAIT_TIME_SHORT
	printfromtable gSubstituteUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_AlreadyHasSubstitute::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHASSUBSTITUTE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveUsedMustRecharge::
	printstring STRINGID_PKMNMUSTRECHARGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRage::
	attackcanceler
	accuracycheck BattleScript_RageMiss, ACC_CURR_MOVE
	seteffectprimary MOVE_EFFECT_RAGE
	goto BattleScript_HitFromAtkString
BattleScript_RageMiss::
	clearstatusfromeffect BS_ATTACKER, MOVE_EFFECT_RAGE
	goto BattleScript_PrintMoveMissed

BattleScript_EffectMimic::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	mimicattackcopy BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNLEARNEDMOVE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMetronome::
	attackcanceler
	attackstring
	pause B_WAIT_TIME_SHORT
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	metronome

BattleScript_EffectLeechSeed::
	attackcanceler
	attackstring
	pause B_WAIT_TIME_SHORT
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_DoLeechSeed, ACC_CURR_MOVE
BattleScript_DoLeechSeed::
	setseeded
	attackanimation
	waitanimation
	printfromtable gLeechSeedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDoNothing::
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	incrementgamestat GAME_STAT_USED_SPLASH
	printstring STRINGID_BUTNOTHINGHAPPENED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDisable::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	disablelastusedattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNMOVEWASDISABLED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectLevelDamage::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	dmgtolevel
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectPsywave::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	psywavedamageeffect
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectCounter::
	attackcanceler
	counterdamagecalculator BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectEncore::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trysetencore BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNGOTENCORE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPainSplit::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	painsplitdmgcalc BattleScript_ButItFailed
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, sPAINSPLIT_HP
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_SHAREDPAIN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSnore::
	attackcanceler
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_SnoreIsAsleep
	attackstring
	ppreduce
	goto BattleScript_ButItFailed
BattleScript_SnoreIsAsleep::
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoSnore
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
BattleScript_DoSnore::
	attackstring
	ppreduce
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_EffectConversion2::
	attackcanceler
	attackstring
	ppreduce
	settypetorandomresistance BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectLockOn::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	setalwayshitflag
	attackanimation
	waitanimation
	printstring STRINGID_PKMNTOOKAIM
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSketch::
	attackcanceler
	attackstring
	ppreduce
	copymovepermanently BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSKETCHEDMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSleepTalk::
	attackcanceler
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_SleepTalkIsAsleep
	attackstring
	ppreduce
	goto BattleScript_ButItFailed
BattleScript_SleepTalkIsAsleep::
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	attackstring
	ppreduce
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	trychoosesleeptalkmove BattleScript_SleepTalkUsingMove
	pause B_WAIT_TIME_LONG
	goto BattleScript_ButItFailed
BattleScript_SleepTalkUsingMove::
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE

BattleScript_EffectDestinyBond::
	attackcanceler
	attackstring
	ppreduce
	setdestinybond
	attackanimation
	waitanimation
	printstring STRINGID_PKMNTRYINGTOTAKEFOE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSpite::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryspiteppreduce BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREDUCEDPP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHealBell::
	attackcanceler
	attackstring
	ppreduce
	healpartystatus
	waitstate
	attackanimation
	waitanimation
	printfromtable gPartyStatusHealStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifnotmove MOVE_HEAL_BELL, BattleScript_PartyHealEnd
	jumpifbyte CMP_NO_COMMON_BITS, cMULTISTRING_CHOOSER, B_MSG_BELL_SOUNDPROOF_ATTACKER, BattleScript_CheckHealBellMon2Unaffected
	printstring STRINGID_PKMNSXBLOCKSY
	waitmessage B_WAIT_TIME_LONG
BattleScript_CheckHealBellMon2Unaffected::
	jumpifbyte CMP_NO_COMMON_BITS, cMULTISTRING_CHOOSER, B_MSG_BELL_SOUNDPROOF_PARTNER, BattleScript_PartyHealEnd
	printstring STRINGID_PKMNSXBLOCKSY2
	waitmessage B_WAIT_TIME_LONG
BattleScript_PartyHealEnd::
	updatestatusicon BS_ATTACKER_WITH_PARTNER
	waitstate
	goto BattleScript_MoveEnd

BattleScript_EffectMeanLook::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifstatus2 BS_TARGET, STATUS2_ESCAPE_PREVENTION, BattleScript_ButItFailed
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpiftype BS_TARGET, TYPE_GHOST, BattleScript_ButItFailed
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_PREVENT_ESCAPE
	printstring STRINGID_TARGETCANTESCAPENOW
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectNightmare::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_NIGHTMARE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_NightmareWorked
	goto BattleScript_ButItFailed
BattleScript_NightmareWorked::
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_NIGHTMARE
	printstring STRINGID_PKMNFELLINTONIGHTMARE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMinimise::
	attackcanceler
	setminimise
	setstatchanger STAT_EVASION, 2, FALSE
	goto BattleScript_EffectStatUpAfterAtkCanceler

BattleScript_EffectCurse::
	jumpiftype BS_ATTACKER, TYPE_GHOST, BattleScript_GhostCurse
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_SPEED, MIN_STAT_STAGE, BattleScript_CurseTrySpeed
	jumpifstat BS_ATTACKER, CMP_NOT_EQUAL, STAT_ATK, MAX_STAT_STAGE, BattleScript_CurseTrySpeed
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_DEF, MAX_STAT_STAGE, BattleScript_ButItFailed
BattleScript_CurseTrySpeed::
	copybyte gBattlerTarget, gBattlerAttacker
	setbyte sB_ANIM_TURN, 1
	attackanimation
	waitanimation
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseTryAttack
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CurseTryAttack::
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseTryDefense
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CurseTryDefense::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CurseEnd::
	goto BattleScript_MoveEnd
BattleScript_GhostCurse::
	jumpifbytenotequal gBattlerAttacker, gBattlerTarget, BattleScript_DoGhostCurse
	getmovetarget BS_ATTACKER
BattleScript_DoGhostCurse::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	cursetarget BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	setbyte sB_ANIM_TURN, 0
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNLAIDCURSE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectProtect::
BattleScript_EffectEndure::
	attackcanceler
BattleScript_ProtectLikeAtkString:
	attackstring
	ppreduce
	setprotectlike
	attackanimation
	waitanimation
	printfromtable gProtectLikeUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSpikes::
	attackcanceler
	trysetspikes BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	printstring STRINGID_SPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectForesight::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifstatus2 BS_TARGET, STATUS2_FORESIGHT, BattleScript_ButItFailed
	setforesight
BattleScript_IdentifiedFoe:
	attackanimation
	waitanimation
	printstring STRINGID_PKMNIDENTIFIED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPerishSong::
	attackcanceler
	attackstring
	ppreduce
	trysetperishsong BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_FAINTINTHREE
	waitmessage B_WAIT_TIME_LONG
	setbyte gBattlerTarget, 0
BattleScript_PerishSongLoop::
	jumpifability BS_TARGET, ABILITY_SOUNDPROOF, BattleScript_PerishSongBlocked
BattleScript_PerishSongLoopIncrement::
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_PerishSongLoop
	goto BattleScript_MoveEnd

BattleScript_PerishSongBlocked::
	copybyte sBATTLER, gBattlerTarget
	printstring STRINGID_PKMNSXBLOCKSY2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_PerishSongLoopIncrement

BattleScript_EffectSandstorm::
	attackcanceler
	attackstring
	ppreduce
	setsandstorm
	goto BattleScript_MoveWeatherChange

BattleScript_EffectRollout::
	attackcanceler
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_RolloutCheckAccuracy
	ppreduce
BattleScript_RolloutCheckAccuracy::
	accuracycheck BattleScript_RolloutHit, ACC_CURR_MOVE
BattleScript_RolloutHit::
	typecalc
	handlerollout
	goto BattleScript_HitFromCritCalc

BattleScript_EffectSwagger::
	attackcanceler
	jumpifsubstituteblocks BattleScript_MakeMoveMissed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifconfusedandstatmaxed STAT_ATK, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_SwaggerTryConfuse
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_SwaggerTryConfuse
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SwaggerTryConfuse:
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifsafeguard BattleScript_SafeguardProtected
	seteffectprimary MOVE_EFFECT_CONFUSION
	goto BattleScript_MoveEnd

BattleScript_EffectFuryCutter::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_FuryCutterHit, ACC_CURR_MOVE
BattleScript_FuryCutterHit:
	handlefurycutter
	critcalc
	damagecalc
	jumpifmovehadnoeffect BattleScript_FuryCutterHit
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_TryDestinyKnotTarget:
	jumpifnoholdeffect BS_ATTACKER, HOLD_EFFECT_DESTINY_KNOT, BattleScript_TryDestinyKnotTargetRet
	infatuatewithbattler BS_TARGET, BS_ATTACKER
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	status2animation BS_TARGET, STATUS2_INFATUATION
	waitanimation
	printstring STRINGID_DESTINYKNOTACTIVATES
	waitmessage B_WAIT_TIME_LONG
BattleScript_TryDestinyKnotTargetRet:
	return

BattleScript_TryDestinyKnotAttacker:
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_DESTINY_KNOT, BattleScript_TryDestinyKnotAttackerRet
	infatuatewithbattler BS_ATTACKER, BS_TARGET
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	waitanimation
	printstring STRINGID_DESTINYKNOTACTIVATES
	waitmessage B_WAIT_TIME_LONG
BattleScript_TryDestinyKnotAttackerRet:
	return

BattleScript_EffectAttract::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryinfatuating BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLINLOVE
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryDestinyKnotAttacker
	goto BattleScript_MoveEnd

BattleScript_EffectPresent::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	presentdamagecalculation

BattleScript_EffectSafeguard::
	attackcanceler
	attackstring
	ppreduce
	setsafeguard
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectMagnitude::
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING | HITMARKER_NO_PPDEDUCT, BattleScript_EffectMagnitudeTarget
	attackcanceler
	attackstring
	ppreduce
	magnitudedamagecalculation
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MAGNITUDESTRENGTH
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMagnitudeTarget:
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_EffectBatonPass::
	attackcanceler
	attackstring
	ppreduce
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_ButItFailed
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	openpartyscreen BS_ATTACKER, BattleScript_ButItFailed
	switchoutabilities BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	switchineffects BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectFixedDamageArg::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	setargtobattledamage
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectMorningSun::
BattleScript_EffectSynthesis::
BattleScript_EffectMoonlight::
	attackcanceler
	attackstring
	ppreduce
	recoverbasedonsunlight BattleScript_AlreadyAtFullHp
	goto BattleScript_PresentHealTarget

BattleScript_EffectRainDance::
	attackcanceler
	attackstring
	ppreduce
	setrain
BattleScript_MoveWeatherChange::
	attackanimation
	waitanimation
	call BattleScript_MoveWeatherChangeRet
	goto BattleScript_MoveEnd

BattleScript_MoveWeatherChangeRet::
	printfromtable gMoveWeatherChangeStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectSunnyDay::
	attackcanceler
	attackstring
	ppreduce
	setsunny
	goto BattleScript_MoveWeatherChange

BattleScript_EffectBellyDrum::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_ATK, MAX_STAT_STAGE, BattleScript_ButItFailed
	halvehp BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	playstatchangeanimation BS_ATTACKER, BIT_ATK, STAT_CHANGE_BY_TWO
	setstatchanger STAT_ATK, MAX_STAT_STAGE, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	printstring STRINGID_PKMNCUTHPMAXEDATTACK
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPsychUp::
	attackcanceler
	attackstring
	ppreduce
	copyfoestats BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCOPIEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMirrorCoat::
	attackcanceler
	mirrorcoatdamagecalculator BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectFutureSight::
	attackcanceler
	attackstring
	ppreduce
	trysetfutureattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gFutureMoveUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTeleport::
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_EffectBatonPass
	jumpifside BS_ATTACKER, B_SIDE_PLAYER, BattleScript_EffectBatonPass
	attackcanceler
	attackstring
	ppreduce
	getifcantrunfrombattle BS_ATTACKER
	jumpifbyte CMP_EQUAL, gBattleCommunication, BATTLE_RUN_FORBIDDEN, BattleScript_ButItFailed
	jumpifbyte CMP_EQUAL, gBattleCommunication, BATTLE_RUN_FAILURE, BattleScript_PrintAbilityMadeIneffective
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFLEDFROMBATTLE
	waitmessage B_WAIT_TIME_LONG
	setoutcomeonteleport BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectBeatUp::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	pause B_WAIT_TIME_SHORT
	ppreduce
	setbyte gBattleCommunication, 0
BattleScript_BeatUpLoop::
	movevaluescleanup
	trydobeatup BattleScript_BeatUpEnd, BattleScript_ButItFailed
	printstring STRINGID_PKMNATTACK
	critcalc
	jumpifbyte CMP_NOT_EQUAL, gIsCriticalHit, TRUE, BattleScript_BeatUpAttack
	manipulatedamage DMG_DOUBLED
BattleScript_BeatUpAttack::
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET
	moveendto MOVEEND_NEXT_TARGET
	goto BattleScript_BeatUpLoop
BattleScript_BeatUpEnd::
	end

BattleScript_EffectDefenseCurl::
	attackcanceler
	attackstring
	ppreduce
	setdefensecurlbit
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DefenseCurlDoStatUpAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_StatUpPrintString
	attackanimation
	waitanimation
BattleScript_DefenseCurlDoStatUpAnim::
	goto BattleScript_StatUpDoAnim

BattleScript_EffectSoftboiled::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_TARGET
BattleScript_PresentHealTarget::
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyAtFullHp::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHPFULL
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFirstTurnOnly::
	attackcanceler
	jumpifnotfirstturn BattleScript_FailedFromAtkString
	goto BattleScript_EffectHit

BattleScript_FailedFromAtkCanceler::
	attackcanceler
BattleScript_FailedFromAtkString::
	attackstring
BattleScript_FailedFromPpReduce::
	ppreduce
BattleScript_ButItFailed::
	pause B_WAIT_TIME_SHORT
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NotAffected::
	pause B_WAIT_TIME_SHORT
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NotAffectedAbilityPopUp::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUpTarget
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectUproar::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_UproarHit
	ppreduce
BattleScript_UproarHit::
	goto BattleScript_HitFromCritCalc

BattleScript_EffectStockpile::
	attackcanceler
	attackstring
	ppreduce
	stockpile 0
	attackanimation
	waitanimation
	printfromtable gStockpileUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifmovehadnoeffect BattleScript_EffectStockpileEnd
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_EffectStockpileDef
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_EffectStockpileEnd
BattleScript_EffectStockpileDef:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, 0
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectStockpileSpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectStockpileSpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectStockpileSpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectStockpileEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectStockpileEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectStockpileEnd:
	stockpile 1
	goto BattleScript_MoveEnd

BattleScript_MoveEffectStockpileWoreOff::
	dostockpilestatchangeswearoff BS_ATTACKER, BattleScript_StockpileStatChangeDown
	printstring STRINGID_STOCKPILEDEFFECTWOREOFF
	waitmessage B_WAIT_TIME_SHORT
	return

BattleScript_StockpileStatChangeDown:
	statbuffchange MOVE_EFFECT_AFFECTS_USER, BattleScript_StockpileStatChangeDown_Ret
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_StockpileStatChangeDown_Ret:
	return

BattleScript_EffectSpitUp::
	attackcanceler
	jumpifbyte CMP_EQUAL, cMISS_TYPE, B_MSG_PROTECTED, BattleScript_SpitUpFailProtect
	attackstring
	ppreduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	setbyte gIsCriticalHit, FALSE
	damagecalc
	adjustdamage
	stockpiletobasedamage BattleScript_SpitUpFail
	goto BattleScript_HitFromAtkAnimation
BattleScript_SpitUpFail::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_FAILEDTOSPITUP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SpitUpFailProtect::
	attackstring
	ppreduce
	pause B_WAIT_TIME_LONG
	stockpiletobasedamage BattleScript_SpitUpFail
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSwallow::
	attackcanceler
	attackstring
	ppreduce
	stockpiletohpheal BattleScript_SwallowFail
	goto BattleScript_PresentHealTarget

BattleScript_SwallowFail::
	pause B_WAIT_TIME_SHORT
	printfromtable gSwallowFailStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHail::
	attackcanceler
	attackstring
	ppreduce
	sethail
	goto BattleScript_MoveWeatherChange

BattleScript_EffectTorment::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	settorment BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSUBJECTEDTOTORMENT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFlatter::
	attackcanceler
	jumpifsubstituteblocks BattleScript_MakeMoveMissed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifconfusedandstatmaxed STAT_SPATK, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_FlatterTryConfuse
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_FlatterTryConfuse
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_FlatterTryConfuse::
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifsafeguard BattleScript_SafeguardProtected
	seteffectprimary MOVE_EFFECT_CONFUSION
	goto BattleScript_MoveEnd

BattleScript_EffectWillOWisp::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_BURN, BattleScript_AlreadyBurned
	jumpiftype BS_TARGET, TYPE_FIRE, BattleScript_NotAffected
	jumpifability BS_TARGET, ABILITY_WATER_VEIL, BattleScript_WaterVeilPrevents
	jumpifleafguardprotected BS_TARGET, BattleScript_AbilityProtectsDoesntAffect
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_BURN
	goto BattleScript_MoveEnd

BattleScript_WaterVeilPrevents::
	call BattleScript_AbilityPopUp
	copybyte gEffectBattler, gBattlerTarget
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_BRNPrevention
	goto BattleScript_MoveEnd

BattleScript_AlreadyBurned::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYHASBURN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMemento::
	attackcanceler
	jumpifbyte CMP_EQUAL, cMISS_TYPE, B_MSG_PROTECTED, BattleScript_MementoTargetProtect
	attackstring
	ppreduce
	trymemento BattleScript_ButItFailed
	setatkhptozero
	attackanimation
	waitanimation
	jumpifsubstituteblocks BattleScript_EffectMementoPrintNoEffect
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO
	setstatchanger STAT_ATK, 2, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectMementoTrySpAtk
@ Greater than B_MSG_DEFENDER_STAT_FELL is checking if the stat cannot decrease
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_EffectMementoTrySpAtk
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMementoTrySpAtk:
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO
	setstatchanger STAT_SPATK, 2, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectMementoTryFaint
@ Greater than B_MSG_DEFENDER_STAT_FELL is checking if the stat cannot decrease
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_EffectMementoTryFaint
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMementoTryFaint:
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd
BattleScript_EffectMementoPrintNoEffect:
	printstring STRINGID_BUTNOEFFECT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_EffectMementoTryFaint
@ If the target is protected there's no need to check the target's stats or animate, the user will just faint
BattleScript_MementoTargetProtect:
	attackstring
	ppreduce
	trymemento BattleScript_MementoTargetProtectEnd
BattleScript_MementoTargetProtectEnd:
	setatkhptozero
	pause B_WAIT_TIME_LONG
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectFocusPunch::
	attackcanceler
	jumpifnodamage BattleScript_HitFromAccCheck
	ppreduce
	printstring STRINGID_PKMNLOSTFOCUS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFollowMe::
	attackcanceler
	attackstring
	ppreduce
	jumpifnotbattletype BATTLE_TYPE_DOUBLE, BattleScript_ButItFailed
	setforcedtarget
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCENTERATTENTION
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectNaturePower::
	attackcanceler
	attackstring
	pause B_WAIT_TIME_SHORT
	callterrainattack
	printstring STRINGID_NATUREPOWERTURNEDINTO
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectCharge::
	attackcanceler
	attackstring
	ppreduce
	setcharge BS_ATTACKER
	attackanimation
	waitanimation
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectChargeString
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectChargeString
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectChargeString:
	printstring STRINGID_PKMNCHARGINGPOWER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTaunt::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	settaunt BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLFORTAUNT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHelpingHand::
	attackcanceler
	attackstring
	ppreduce
	trysethelpinghand BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREADYTOHELP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTrick::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryswapitems BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDITEMS
	waitmessage B_WAIT_TIME_LONG
	printfromtable gItemSwapStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRolePlay::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	trycopyability BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setbyte sFIXED_ABILITY_POPUP, TRUE
	showabilitypopup BS_ATTACKER
	pause 60
	sethword sABILITY_OVERWRITE, 0
	updateabilitypopup BS_ATTACKER
	pause 20
	destroyabilitypopup
	pause 40
	printstring STRINGID_PKMNCOPIEDFOE
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectWish::
	attackcanceler
	attackstring
	ppreduce
	trywish 0, BattleScript_ButItFailed
	attackanimation
	waitanimation
	goto BattleScript_MoveEnd

BattleScript_EffectAssist::
	attackcanceler
	attackstring
	assistattackselect BattleScript_FailedFromPpReduce
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE

BattleScript_EffectIngrain::
	attackcanceler
	attackstring
	ppreduce
	setuserstatus3 STATUS3_ROOTED, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNPLANTEDROOTS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMagicCoat::
	attackcanceler
	trysetmagiccoat BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSHROUDEDITSELF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRecycle::
	attackcanceler
	attackstring
	ppreduce
	tryrecycleitem BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_XFOUNDONEY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectBrickBreak::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	removelightscreenreflect
	critcalc
	damagecalc
	adjustdamage
	jumpifbyte CMP_EQUAL, sB_ANIM_TURN, 0, BattleScript_BrickBreakAnim
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
BattleScript_BrickBreakAnim::
	attackanimation
	waitanimation
	jumpifbyte CMP_LESS_THAN, sB_ANIM_TURN, 2, BattleScript_BrickBreakDoHit
	printstring STRINGID_THEWALLSHATTERED
	waitmessage B_WAIT_TIME_LONG
BattleScript_BrickBreakDoHit::
	typecalc
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	setadditionaleffects
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectYawn::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_VITAL_SPIRIT, BattleScript_PrintBattlerAbilityMadeIneffective
	jumpifability BS_TARGET, ABILITY_INSOMNIA, BattleScript_PrintBattlerAbilityMadeIneffective
	jumpifleafguardprotected BS_TARGET, BattleScript_AbilityProtectsDoesntAffect
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifsafeguard BattleScript_SafeguardProtected
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifuproarwakes BattleScript_ButItFailed
	setyawn BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNWASMADEDROWSY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_PrintBattlerAbilityMadeIneffective::
	copybyte sBATTLER, gBattlerAbility
BattleScript_PrintAbilityMadeIneffective::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXMADEITINEFFECTIVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectEndeavor::
	attackcanceler
	attackstring
	ppreduce
	setdamagetohealthdifference BattleScript_ButItFailed
	copyword gHpDealt, gBattleMoveDamage
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	typecalc
	jumpifmovehadnoeffect BattleScript_HitFromAtkAnimation
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	copyword gBattleMoveDamage, gHpDealt
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectSkillSwap::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	tryswapabilities BattleScript_ButItFailed
	attackanimation
	waitanimation
	call BattleScript_AbilityPopUpTarget
	pause 20
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSWAPPEDABILITIES
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_ATTACKER
	switchinabilities BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectImprison::
	attackcanceler
	attackstring
	ppreduce
	tryimprison BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSEALEDOPPONENTMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRefresh::
	attackcanceler
	attackstring
	ppreduce
	cureifburnedparalysedorpoisoned BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSTATUSNORMAL
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectGrudge::
	attackcanceler
	attackstring
	ppreduce
	setuserstatus3 STATUS3_GRUDGE, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNWANTSGRUDGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSnatch::
	attackcanceler
	trysetsnatch BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNWAITSFORTARGET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRecoilHP25::
	jumpifnotmove MOVE_STRUGGLE, BattleScript_EffectHit
	incrementgamestat GAME_STAT_USED_STRUGGLE
	goto BattleScript_EffectHit

BattleScript_EffectMudSport::
BattleScript_EffectWaterSport::
	attackcanceler
	attackstring
	ppreduce
	settypebasedhalvers BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gSportsUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTickle::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_ATK, MIN_STAT_STAGE, BattleScript_TickleDoMoveAnim
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_DEF, MIN_STAT_STAGE, BattleScript_CantLowerMultipleStats
BattleScript_TickleDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_DEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TickleTryLowerDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_TickleTryLowerDef
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_TickleTryLowerDef::
	playstatchangeanimation BS_TARGET, BIT_DEF, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TickleEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_TickleEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_TickleEnd::
	goto BattleScript_MoveEnd

BattleScript_CantLowerMultipleStats::
	pause B_WAIT_TIME_SHORT
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_STATSWONTDECREASE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectCosmicPower::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_CosmicPowerDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_CosmicPowerDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, 0
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicPowerTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicPowerTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CosmicPowerTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicPowerEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicPowerEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CosmicPowerEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectBulkUp::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_BulkUpDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_DEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_BulkUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_BulkUpTryDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_BulkUpTryDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_BulkUpTryDef::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_BulkUpEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_BulkUpEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_BulkUpEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectCalmMind::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_CalmMindDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_CalmMindDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CalmMindTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CalmMindTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CalmMindTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CalmMindEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CalmMindEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CalmMindEnd::
	goto BattleScript_MoveEnd

BattleScript_CantRaiseMultipleStats::
	pause B_WAIT_TIME_SHORT
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_STATSWONTINCREASE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDragonDance::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_DragonDanceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_DragonDanceDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPEED, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DragonDanceTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DragonDanceTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DragonDanceTrySpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DragonDanceEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DragonDanceEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DragonDanceEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectCamouflage::
	attackcanceler
	attackstring
	ppreduce
	settypetoterrain BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_FaintAttacker::
	playfaintcry BS_ATTACKER
	pause B_WAIT_TIME_LONG
	dofaintanimation BS_ATTACKER
	printstring STRINGID_ATTACKERFAINTED
	cleareffectsonfaint BS_ATTACKER
	return

BattleScript_FaintTarget::
	playfaintcry BS_TARGET
	pause B_WAIT_TIME_LONG
	dofaintanimation BS_TARGET
	printstring STRINGID_TARGETFAINTED
	cleareffectsonfaint BS_TARGET
	tryactivatefellstinger BS_ATTACKER
	tryactivatemoxie BS_ATTACKER        @ and chilling neigh, as one ice rider
	return

BattleScript_GiveExp::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	end2

BattleScript_HandleFaintedMon::
	setbyte sSHIFT_SWITCHED, 0
	checkteamslost BattleScript_LinkHandleFaintedMonMultiple
	jumpifbyte CMP_NOT_EQUAL, gBattleOutcome, 0, BattleScript_FaintedMonEnd
	jumpifbattletype BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonTryChoose
	jumpifword CMP_NO_COMMON_BITS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonTryChoose
@ Yes/No for sending out a new Pokémon if one is defeated in a wild battle
	printstring STRINGID_USENEXTPKMN
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 0, BattleScript_FaintedMonTryChoose
@ Player said no, try to run
	jumpifplayerran BattleScript_FaintedMonEnd
	printstring STRINGID_CANTESCAPE2
BattleScript_FaintedMonTryChoose:
	openpartyscreen BS_FAINTED, BattleScript_FaintedMonEnd
	switchhandleorder BS_FAINTED, 2
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_LINK, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_RECORDED_LINK, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_FRONTIER, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonSendOutNew
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonSendOutNew
	jumpifbyte CMP_EQUAL, sBATTLE_STYLE, OPTIONS_BATTLE_STYLE_SET, BattleScript_FaintedMonSendOutNew
	jumpifcantswitch BS_PLAYER1, BattleScript_FaintedMonSendOutNew
@ Yes/No for sending out a new Pokémon when the opponent is switching
	printstring STRINGID_ENEMYABOUTTOSWITCHPKMN
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 1, BattleScript_FaintedMonSendOutNew
@ Player said yes, go to party screen (note optional flag, player may exit the menu instead)
	setatktoplayer0
	openpartyscreen BS_ATTACKER | PARTY_SCREEN_OPTIONAL, BattleScript_FaintedMonSendOutNew
	switchhandleorder BS_ATTACKER, 2
	jumpifbyte CMP_EQUAL, gBattleCommunication, PARTY_SIZE, BattleScript_FaintedMonSendOutNew
@ Switch Pokémon before opponent
	atknameinbuff1
	resetswitchinabilitybits BS_ATTACKER
	hpthresholds2 BS_ATTACKER
	printstring STRINGID_RETURNMON
	switchoutabilities BS_ATTACKER
	waitstate
	returnatktoball
	waitstate
	drawpartystatussummary BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, 0
	waitstate
	setbyte sSHIFT_SWITCHED, 1
BattleScript_FaintedMonSendOutNew:
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, FALSE
	waitstate
	resetplayerfainted
	jumpifbytenotequal sSHIFT_SWITCHED, sZero, BattleScript_FaintedMonShiftSwitched
BattleScript_FaintedMonSendOutNewEnd:
	switchineffects BS_FAINTED
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonEnd
	cancelallactions
BattleScript_FaintedMonEnd::
	end2
BattleScript_FaintedMonShiftSwitched:
	copybyte sSAVED_BATTLER, gBattlerTarget
	switchineffects BS_ATTACKER
	resetsentmonsvalue
	copybyte gBattlerTarget, sSAVED_BATTLER
	goto BattleScript_FaintedMonSendOutNewEnd

BattleScript_LinkHandleFaintedMonMultiple::
	openpartyscreen BS_FAINTED_LINK_MULTIPLE_1, BattleScript_LinkHandleFaintedMonMultipleStart
BattleScript_LinkHandleFaintedMonMultipleStart::
	switchhandleorder BS_FAINTED, 0
	openpartyscreen BS_FAINTED_LINK_MULTIPLE_2, BattleScript_LinkHandleFaintedMonMultipleEnd
	switchhandleorder BS_FAINTED, 0
BattleScript_LinkHandleFaintedMonLoop::
	switchhandleorder BS_FAINTED, 3
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, FALSE
	waitstate
	switchineffects BS_FAINTED_LINK_MULTIPLE_1
	jumpifbytenotequal gBattlerFainted, gBattlersCount, BattleScript_LinkHandleFaintedMonLoop
BattleScript_LinkHandleFaintedMonMultipleEnd::
	end2

BattleScript_LocalTrainerBattleWon::
	jumpifbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalTwoTrainersDefeated
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	goto BattleScript_LocalBattleWonLoseTexts
BattleScript_LocalTwoTrainersDefeated::
	printstring STRINGID_TWOENEMIESDEFEATED
BattleScript_LocalBattleWonLoseTexts::
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalBattleWonReward
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT
BattleScript_LocalBattleWonReward::
	getmoneyreward
	printstring STRINGID_PLAYERGOTMONEY
	waitmessage B_WAIT_TIME_LONG
BattleScript_PayDayMoneyAndPickUpItems::
	givepaydaymoney
	pickup
	end2

BattleScript_LocalBattleLost::
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, 0, BattleScript_RivalBattleLost
	jumpifbattletype BATTLE_TYPE_INGAME_PARTNER, BattleScript_LocalBattleLostPrintWhiteOut
	jumpifbattletype BATTLE_TYPE_DOME, BattleScript_CheckDomeDrew
	jumpifbattletype BATTLE_TYPE_FRONTIER, BattleScript_LocalBattleLostPrintTrainersWinText
	jumpifbattletype BATTLE_TYPE_TRAINER_TOWER, BattleScript_LocalBattleLostPrintTrainersWinText
	jumpifbattletype BATTLE_TYPE_EREADER_TRAINER, BattleScript_LocalBattleLostEnd
	jumpifhalfword CMP_EQUAL, gTrainerBattleOpponent_A, TRAINER_SECRET_BASE, BattleScript_LocalBattleLostEnd
BattleScript_LocalBattleLostPrintWhiteOut::
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_LocalBattleLostEnd
	printstring STRINGID_PLAYERWHITEOUT
	waitmessage B_WAIT_TIME_LONG
	getmoneyreward
	printstring STRINGID_PLAYERWHITEOUT2
	waitmessage B_WAIT_TIME_LONG
	end2
BattleScript_LocalBattleLostEnd::
	printstring STRINGID_PLAYERLOSTTOENEMYTRAINER
	waitmessage B_WAIT_TIME_LONG
	getmoneyreward
	printstring STRINGID_PLAYERPAIDPRIZEMONEY
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_RivalBattleLost::
    jumpifhasnohp BS_ATTACKER, BattleScript_RivalBattleLostSkipMonRecall
    printstring STRINGID_TRAINER1MON1COMEBACK
    waitmessage B_WAIT_TIME_LONG
    returnatktoball
    waitstate
BattleScript_RivalBattleLostSkipMonRecall::
    trainerslidein BS_ATTACKER
    waitstate
    printstring STRINGID_RIVALWINTEXT
    jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_LocalBattleLostPrintWhiteOut
    end2

BattleScript_CheckDomeDrew::
	jumpifbyte CMP_EQUAL, gBattleOutcome, B_OUTCOME_DREW, BattleScript_LocalBattleLostEnd_
BattleScript_LocalBattleLostPrintTrainersWinText::
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_LocalBattleLostPrintWhiteOut
	returnopponentmon1toball BS_ATTACKER
	waitstate
	returnopponentmon2toball BS_ATTACKER
	waitstate
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	jumpifbattletype BATTLE_TYPE_TOWER_LINK_MULTI, BattleScript_LocalBattleLostDoTrainer2WinText
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalBattleLostEnd_
BattleScript_LocalBattleLostDoTrainer2WinText::
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2WINTEXT
BattleScript_LocalBattleLostEnd_::
	end2

BattleScript_FrontierLinkBattleLost::
	returnopponentmon1toball BS_ATTACKER
	waitstate
	returnopponentmon2toball BS_ATTACKER
	waitstate
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2WINTEXT
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_FrontierLinkBattleLostEnd
	endlinkbattle
BattleScript_FrontierLinkBattleLostEnd::
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_LinkBattleWonOrLost::
	jumpifbattletype BATTLE_TYPE_BATTLE_TOWER, BattleScript_TowerLinkBattleWon
	printstring STRINGID_BATTLEEND
	waitmessage B_WAIT_TIME_LONG
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_LinkBattleWonOrLostWaitEnd
	endlinkbattle
BattleScript_LinkBattleWonOrLostWaitEnd::
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TowerLinkBattleWon::
	playtrainerdefeatbgm BS_ATTACKER
	printstring STRINGID_BATTLEEND
	waitmessage B_WAIT_TIME_LONG
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_TowerLinkBattleWonEnd
	endlinkbattle
BattleScript_TowerLinkBattleWonEnd::
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_FrontierTrainerBattleWon::
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_PayDayMoneyAndPickUpItems
	jumpifbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_FrontierTrainerBattleWon_TwoDefeated
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	goto BattleScript_FrontierTrainerBattleWon_LoseTexts
BattleScript_FrontierTrainerBattleWon_TwoDefeated:
	printstring STRINGID_TWOENEMIESDEFEATED
BattleScript_FrontierTrainerBattleWon_LoseTexts:
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_TryPickUpItems
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT
BattleScript_TryPickUpItems:
	jumpifnotbattletype BATTLE_TYPE_PYRAMID, BattleScript_FrontierTrainerBattleWon_End
	pickup
BattleScript_FrontierTrainerBattleWon_End:
	end2

BattleScript_SmokeBallEscape::
	playanimation BS_ATTACKER, B_ANIM_SMOKEBALL_ESCAPE
	printstring STRINGID_PKMNFLEDUSINGITS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_RanAwayUsingMonAbility::
	printstring STRINGID_PKMNFLEDUSING
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_GotAwaySafely::
	printstring STRINGID_GOTAWAYSAFELY
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_WildMonFled::
	printstring STRINGID_WILDPKMNFLED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_PrintCantRunFromTrainer::
	printstring STRINGID_NORUNNINGFROMTRAINERS
	end2

BattleScript_PrintFailedToRunString::
	printfromtable gNoEscapeStringIds
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_PrintCantEscapeFromBattle::
	printselectionstringfromtable gNoEscapeStringIds
	endselectionscript

BattleScript_PrintFullBox::
	printselectionstring STRINGID_BOXISFULL
	endselectionscript

BattleScript_ActionSwitch::
	hpthresholds2 BS_ATTACKER
	copybyte sSAVED_BATTLER, gBattlerAttacker
	printstring STRINGID_RETURNMON
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_PursuitSwitchDmgSetMultihit
	setmultihit 1
	goto BattleScript_PursuitSwitchDmgLoop
BattleScript_PursuitSwitchDmgSetMultihit::
	setmultihit 2
BattleScript_PursuitSwitchDmgLoop::
	jumpifnopursuitswitchdmg BattleScript_DoSwitchOut
	swapattackerwithtarget
	trysetdestinybondtohappen
	call BattleScript_PursuitDmgOnSwitchOut
	swapattackerwithtarget
BattleScript_DoSwitchOut::
	decrementmultihit BattleScript_PursuitSwitchDmgLoop
	switchoutabilities BS_ATTACKER
	waitstate
	copybyte gBattlerAttacker, sSAVED_BATTLER
	returnatktoball
	waitstate
	drawpartystatussummary BS_ATTACKER
	switchhandleorder BS_ATTACKER, 1
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, FALSE
	waitstate
	switchineffects BS_ATTACKER
	moveendcase MOVEEND_STATUS_IMMUNITY_ABILITIES
	moveendcase MOVEEND_MIRROR_MOVE
	end2

BattleScript_PursuitDmgOnSwitchOut::
	pause B_WAIT_TIME_SHORT
	attackstring
	ppreduce
	critcalc
	damagecalc
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET
	moveendfromto MOVEEND_ABILITIES, MOVEEND_CHOICE_MOVE
	jumpiffainted BS_TARGET, FALSE, BattleScript_PursuitDmgOnSwitchOutRet
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
BattleScript_PursuitDmgOnSwitchOutRet:
	return

BattleScript_Pausex20::
	pause B_WAIT_TIME_SHORT
	return

BattleScript_LevelUp::
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNGREWTOLV
	setbyte sLVLBOX_STATE, 0
	drawlvlupbox
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnMoveReturn, TRUE
	goto BattleScript_AskToLearnMove
BattleScript_TryLearnMoveLoop::
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnMoveReturn, FALSE
BattleScript_AskToLearnMove::
	buffermovetolearn
	printstring STRINGID_TRYTOLEARNMOVE1
	printstring STRINGID_TRYTOLEARNMOVE2
	printstring STRINGID_TRYTOLEARNMOVE3
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxlearnmove BattleScript_ForgotAndLearnedNewMove
	printstring STRINGID_STOPLEARNINGMOVE
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxstoplearningmove BattleScript_AskToLearnMove
	printstring STRINGID_DIDNOTLEARNMOVE
	goto BattleScript_TryLearnMoveLoop
BattleScript_ForgotAndLearnedNewMove::
	printstring STRINGID_123POOF
	printstring STRINGID_PKMNFORGOTMOVE
	printstring STRINGID_ANDELLIPSIS
BattleScript_LearnedNewMove::
	buffermovetolearn
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNLEARNEDMOVE
	waitmessage B_WAIT_TIME_LONG
	updatechoicemoveonlvlup BS_ATTACKER
	goto BattleScript_TryLearnMoveLoop
BattleScript_LearnMoveReturn::
	return

BattleScript_RainContinuesOrEnds::
	printfromtable gRainContinuesStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_RAIN_STOPPED, BattleScript_RainContinuesOrEndsEnd
	playanimation BS_ATTACKER, B_ANIM_RAIN_CONTINUES
BattleScript_RainContinuesOrEndsEnd::
	end2

BattleScript_DamagingWeatherContinues::
	printfromtable gSandStormHailContinuesStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation_var BS_ATTACKER, sB_ANIM_ARG1
	setbyte gBattleCommunication, 0
BattleScript_DamagingWeatherLoop::
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	weatherdamage
	jumpifword CMP_EQUAL, gBattleMoveDamage, 0, BattleScript_DamagingWeatherLoopIncrement
	jumpifword CMP_COMMON_BITS gBattleMoveDamage, 1 << 31, BattleScript_DamagingWeatherHeal
	printfromtable gSandStormHailDmgStringIds
	waitmessage B_WAIT_TIME_LONG
	effectivenesssound
	hitanimation BS_ATTACKER
	goto BattleScript_DamagingWeatherHpChange
BattleScript_DamagingWeatherHeal:
	call BattleScript_AbilityPopUp
	printstring STRINGID_ICEBODYHPGAIN
	waitmessage B_WAIT_TIME_LONG
BattleScript_DamagingWeatherHpChange:
	orword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE | HITMARKER_GRUDGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	checkteamslost BattleScript_DamagingWeatherLoopIncrement
BattleScript_DamagingWeatherLoopIncrement::
	jumpifbyte CMP_NOT_EQUAL, gBattleOutcome, 0, BattleScript_DamagingWeatherContinuesEnd
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_DamagingWeatherLoop
BattleScript_DamagingWeatherContinuesEnd::
	bicword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE | HITMARKER_GRUDGE
	end2

BattleScript_SandStormHailEnds::
	printfromtable gSandStormHailEndStringIds
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SunlightContinues::
	printstring STRINGID_SUNLIGHTSTRONG
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_SUN_CONTINUES
	end2

BattleScript_SunlightFaded::
	printstring STRINGID_SUNLIGHTFADED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_OverworldWeatherStarts::
	printfromtable gWeatherStartsStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation_var BS_BATTLER_0, sB_ANIM_ARG1
	end3

BattleScript_OverworldTerrain::
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_BATTLER_0, B_ANIM_RESTORE_BG
	call BattleScript_ActivateTerrainEffects
	end3

BattleScript_SideStatusWoreOff::
	printstring STRINGID_PKMNSXWOREOFF
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SideStatusWoreOffReturn::
	printstring STRINGID_PKMNSXWOREOFF
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_LuckyChantEnds::
	printstring STRINGID_LUCKYCHANTENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TailwindEnds::
	printstring STRINGID_TAILWINDENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TrickRoomEnds::
	printstring STRINGID_TRICKROOMENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_WonderRoomEnds::
	printstring STRINGID_WONDERROOMENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_MagicRoomEnds::
	printstring STRINGID_MAGICROOMENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TerrainEnds_Ret::
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG
	return

BattleScript_TerrainEnds::
	call BattleScript_TerrainEnds_Ret
	end2

BattleScript_MudSportEnds::
	printstring STRINGID_MUDSPORTENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_WaterSportEnds::
	printstring STRINGID_WATERSPORTENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_GravityEnds::
	printstring STRINGID_GRAVITYENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SafeguardProtected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNUSEDSAFEGUARD
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SafeguardEnds::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNSAFEGUARDEXPIRED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_LeechSeedTurnDrain::
	playanimation BS_ATTACKER, B_ANIM_LEECH_SEED_DRAIN, sB_ANIM_ARG1
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, gHpDealt
	jumpifability BS_ATTACKER, ABILITY_LIQUID_OOZE, BattleScript_LeechSeedTurnPrintLiquidOoze
	setbyte cMULTISTRING_CHOOSER, B_MSG_LEECH_SEED_DRAIN
	jumpifstatus3 BS_TARGET, STATUS3_HEAL_BLOCK, BattleScript_LeechSeedHealBlock
	manipulatedamage DMG_BIG_ROOT
	goto BattleScript_LeechSeedTurnPrintAndUpdateHp
BattleScript_LeechSeedTurnPrintLiquidOoze::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setbyte cMULTISTRING_CHOOSER, B_MSG_LEECH_SEED_OOZE
BattleScript_LeechSeedTurnPrintAndUpdateHp::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printfromtable gLeechSeedStringIds
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	tryfaintmon BS_TARGET
	end2
BattleScript_LeechSeedHealBlock:
	setword gBattleMoveDamage, 0
	goto BattleScript_LeechSeedTurnPrintAndUpdateHp

BattleScript_BideStoringEnergy::
	printstring STRINGID_PKMNSTORINGENERGY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_BideAttack::
	attackcanceler
	clearstatusfromeffect BS_ATTACKER, MOVE_EFFECT_CHARGING
	printstring STRINGID_PKMNUNLEASHEDENERGY
	waitmessage B_WAIT_TIME_LONG
	accuracycheck BattleScript_MoveMissed, ACC_CURR_MOVE
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	copyword gBattleMoveDamage, sBIDE_DMG
	adjustdamage
	setbyte sB_ANIM_TURN, 1
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_BideNoEnergyToAttack::
	attackcanceler
	clearstatusfromeffect BS_ATTACKER, MOVE_EFFECT_CHARGING
	printstring STRINGID_PKMNUNLEASHEDENERGY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_ButItFailed

BattleScript_RoarSuccessSwitch::
	call BattleScript_RoarSuccessRet
	getswitchedmondata BS_TARGET
	switchindataupdate BS_TARGET
	switchinanim BS_TARGET, FALSE
	waitstate
	printstring STRINGID_PKMNWASDRAGGEDOUT
	switchineffects BS_TARGET
	jumpifbyte CMP_EQUAL, sSWITCH_CASE, B_SWITCH_RED_CARD, BattleScript_RoarSuccessSwitch_Ret
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	goto BattleScript_MoveEnd
BattleScript_RoarSuccessSwitch_Ret:
	swapattackerwithtarget  @ continuation of RedCardActivates
	restoretarget
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	return

BattleScript_RoarSuccessEndBattle::
	call BattleScript_RoarSuccessRet
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	setoutcomeonteleport BS_ATTACKER
	finishaction

BattleScript_RoarSuccessRet:
	jumpifbyte CMP_EQUAL, sSWITCH_CASE, B_SWITCH_HIT, BattleScript_RoarSuccessRet_Ret
	jumpifbyte CMP_EQUAL, sSWITCH_CASE, B_SWITCH_RED_CARD, BattleScript_RoarSuccessRet_Ret
	attackanimation
	waitanimation
BattleScript_RoarSuccessRet_Ret:
	switchoutabilities BS_TARGET
	returntoball BS_TARGET
	waitstate
	return

BattleScript_WeaknessPolicy::
	copybyte sBATTLER, gBattlerTarget
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_WeaknessPolicyAtk
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_WeaknessPolicyEnd
BattleScript_WeaknessPolicyAtk:
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, STAT_CHANGE_BY_TWO
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeaknessPolicySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WeaknessPolicySpAtk
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeaknessPolicySpAtk:
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeaknessPolicyRemoveItem
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WeaknessPolicyRemoveItem
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeaknessPolicyRemoveItem:
	removeitem BS_TARGET
BattleScript_WeaknessPolicyEnd:
	return

BattleScript_TargetItemStatRaise::
	copybyte sBATTLER, gBattlerTarget
	statbuffchange 0, BattleScript_TargetItemStatRaiseRemoveItemRet
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_TargetItemStatRaiseRemoveItemRet
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET
BattleScript_TargetItemStatRaiseRemoveItemRet:
	return

BattleScript_MistProtected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNPROTECTEDBYMIST
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RageIsBuilding::
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_RageIsBuildingEnd
	printstring STRINGID_PKMNRAGEBUILDING
	waitmessage B_WAIT_TIME_LONG
BattleScript_RageIsBuildingEnd:
	return

BattleScript_MoveUsedIsDisabled::
	printstring STRINGID_PKMNMOVEISDISABLED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingDisabledMove::
	printselectionstring STRINGID_PKMNMOVEISDISABLED
	endselectionscript

BattleScript_DisabledNoMore::
	printstring STRINGID_PKMNMOVEDISABLEDNOMORE
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SelectingDisabledMoveInPalace::
	printstring STRINGID_PKMNMOVEISDISABLED
BattleScript_SelectingUnusableMoveInPalace::
	moveendto MOVEEND_NEXT_TARGET
	end

BattleScript_EncoredNoMore::
	printstring STRINGID_PKMNENCOREENDED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_DestinyBondTakesLife::
	printstring STRINGID_PKMNTOOKFOE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	return

BattleScript_DmgHazardsOnAttacker::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_ATTACKER
	tryfaintmon_spikes BS_ATTACKER, BattleScript_DmgHazardsOnAttackerFainted
	return

BattleScript_DmgHazardsOnAttackerFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_ATTACKER
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_DmgHazardsOnTarget::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_TARGET
	tryfaintmon_spikes BS_TARGET, BattleScript_DmgHazardsOnTargetFainted
	return

BattleScript_DmgHazardsOnTargetFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_DmgHazardsOnBattlerScripting::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_SCRIPTING
	tryfaintmon_spikes BS_SCRIPTING, BattleScript_DmgHazardsOnBattlerScriptingFainted
	return

BattleScript_DmgHazardsOnBattlerScriptingFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_SCRIPTING
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_DmgHazardsOnFaintedBattler::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_FAINTED
	datahpupdate BS_FAINTED
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_FAINTED
	tryfaintmon_spikes BS_FAINTED, BattleScript_DmgHazardsOnFaintedBattlerFainted
	return

BattleScript_DmgHazardsOnFaintedBattlerFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_FAINTED
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_PrintHurtByDmgHazards::
	printfromtable gDmgHazardsStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ToxicSpikesAbsorbed::
	printstring STRINGID_TOXICSPIKESABSORBED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ToxicSpikesPoisoned::
	printstring STRINGID_TOXICSPIKESPOISONED
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_SCRIPTING
	updatestatusicon BS_SCRIPTING
	waitstate
	return

BattleScript_PerishSongTakesLife::
	printstring STRINGID_PKMNPERISHCOUNTFELL
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	end2

BattleScript_PerishSongCountGoesDown::
	printstring STRINGID_PKMNPERISHCOUNTFELL
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_AllStatsUp::
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_AllStatsUpRet
BattleScript_AllStatsUpAtk::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_SPEED | BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpDef::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpSpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpSpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpSpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpRet
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpRet::
	return

BattleScript_RapidSpinAway::
	rapidspinfree
	return

BattleScript_WrapFree::
	printstring STRINGID_PKMNGOTFREE
	waitmessage B_WAIT_TIME_LONG
	copybyte gBattlerTarget, sBATTLER
	return

BattleScript_LeechSeedFree::
	printstring STRINGID_PKMNSHEDLEECHSEED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SpikesFree::
	printstring STRINGID_PKMNBLEWAWAYSPIKES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ToxicSpikesFree::
	printstring STRINGID_PKMNBLEWAWAYTOXICSPIKES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_StealthRockFree::
	printstring STRINGID_PKMNBLEWAWAYSTEALTHROCK
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SpikesDefog::
	printstring STRINGID_SPIKESDISAPPEAREDFROMTEAM
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ToxicSpikesDefog::
	printstring STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_StealthRockDefog::
	printstring STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MonTookFutureAttack::
	printstring STRINGID_PKMNTOOKATTACK
	waitmessage B_WAIT_TIME_LONG
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_FUTURE_SIGHT, BattleScript_CheckDoomDesireMiss
	accuracycheck BattleScript_FutureAttackMiss, MOVE_FUTURE_SIGHT
	goto BattleScript_FutureAttackAnimate
BattleScript_CheckDoomDesireMiss::
	accuracycheck BattleScript_FutureAttackMiss, MOVE_DOOM_DESIRE
BattleScript_FutureAttackAnimate::
	critcalc
	damagecalc
	adjustdamage
	jumpifmovehadnoeffect BattleScript_DoFutureAttackResult
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_FUTURE_SIGHT, BattleScript_FutureHitAnimDoomDesire
	playanimation BS_ATTACKER, B_ANIM_FUTURE_SIGHT_HIT
	goto BattleScript_DoFutureAttackHit
BattleScript_FutureHitAnimDoomDesire::
	playanimation BS_ATTACKER, B_ANIM_DOOM_DESIRE_HIT
BattleScript_DoFutureAttackHit::
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
BattleScript_DoFutureAttackResult:
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET
	checkteamslost BattleScript_FutureAttackEnd
BattleScript_FutureAttackEnd::
	moveendcase MOVEEND_RAGE
	moveendcase MOVEEND_ABILITIES
	moveendfromto MOVEEND_ITEM_EFFECTS_ALL, MOVEEND_UPDATE_LAST_MOVES
	setbyte gMoveResultFlags, 0
	end2
BattleScript_FutureAttackMiss::
	pause B_WAIT_TIME_SHORT
	sethword gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	sethword gMoveResultFlags, 0
	end2

BattleScript_NoMovesLeft::
	printselectionstring STRINGID_PKMNHASNOMOVESLEFT
	endselectionscript

BattleScript_SelectingMoveWithNoPP::
	printselectionstring STRINGID_NOPPLEFT
	endselectionscript

BattleScript_NoPPForMove::
	attackstring
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BUTNOPPLEFT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingTormentedMove::
	printselectionstring STRINGID_PKMNCANTUSEMOVETORMENT
	endselectionscript

BattleScript_SelectingTormentedMoveInPalace::
	printstring STRINGID_PKMNCANTUSEMOVETORMENT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveTaunt::
	printselectionstring STRINGID_PKMNCANTUSEMOVETAUNT
	endselectionscript

BattleScript_MoveUsedIsTaunted::
	printstring STRINGID_PKMNCANTUSEMOVETAUNT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveTauntInPalace::
	printstring STRINGID_PKMNCANTUSEMOVETAUNT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveGravity::
	printselectionstring STRINGID_GRAVITYPREVENTSUSAGE
	endselectionscript

BattleScript_SelectingNotAllowedBelch::
	printselectionstring STRINGID_BELCHCANTSELECT
	endselectionscript

BattleScript_SelectingNotAllowedBelchInPalace::
	printstring STRINGID_BELCHCANTSELECT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_MoveUsedGravityPrevents::
	printstring STRINGID_GRAVITYPREVENTSUSAGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveGravityInPalace::
	printstring STRINGID_GRAVITYPREVENTSUSAGE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveHealBlock::
	printselectionstring STRINGID_HEALBLOCKPREVENTSUSAGE
	endselectionscript

BattleScript_MoveUsedHealBlockPrevents::
	printstring STRINGID_HEALBLOCKPREVENTSUSAGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveHealBlockInPalace::
	printstring STRINGID_HEALBLOCKPREVENTSUSAGE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_WishComesTrue::
	trywish 1, BattleScript_WishButFullHp
	playanimation BS_TARGET, B_ANIM_WISH_HEAL
	printstring STRINGID_PKMNWISHCAMETRUE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_WishButFullHp::
	printstring STRINGID_PKMNWISHCAMETRUE
	waitmessage B_WAIT_TIME_LONG
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHPFULL
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_IngrainTurnHeal::
	playanimation BS_ATTACKER, B_ANIM_INGRAIN_HEAL
	printstring STRINGID_PKMNABSORBEDNUTRIENTS
BattleScript_TurnHeal:
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	end2

BattleScript_AquaRingHeal::
	playanimation BS_ATTACKER, B_ANIM_AQUA_RING_HEAL
	printstring STRINGID_AQUARINGHEAL
	goto BattleScript_TurnHeal

BattleScript_PrintMonIsRooted::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNANCHOREDITSELF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AtkDefDown::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_ATK, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_ATTACKER, BIT_ATK, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_AtkDefDownTryDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_AtkDefDownTryDef
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AtkDefDownTryDef:
	playstatchangeanimation BS_ATTACKER, BIT_DEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_AtkDefDownRet
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_AtkDefDownRet
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AtkDefDownRet:
	return

BattleScript_DefSpDefDown::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_ATTACKER, BIT_DEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_DefSpDefDownTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_DefSpDefDownTrySpDef
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DefSpDefDownTrySpDef::
	playstatchangeanimation BS_ATTACKER, BIT_SPDEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger STAT_SPDEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_DefSpDefDownRet
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_DefSpDefDownRet
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DefSpDefDownRet::
	return

BattleScript_KnockedOff::
	playanimation BS_TARGET, B_ANIM_ITEM_KNOCKOFF
	printstring STRINGID_PKMNKNOCKEDOFF
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedIsImprisoned::
	printstring STRINGID_PKMNCANTUSEMOVESEALED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingImprisonedMove::
	printselectionstring STRINGID_PKMNCANTUSEMOVESEALED
	endselectionscript

BattleScript_SelectingImprisonedMoveInPalace::
	printstring STRINGID_PKMNCANTUSEMOVESEALED
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_GrudgeTakesPp::
	printstring STRINGID_PKMNLOSTPPGRUDGE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MagicCoatBounce::
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0, BattleScript_MagicCoatBounce_Print
	call BattleScript_AbilityPopUp
BattleScript_MagicCoatBounce_Print:
	printfromtable gMagicCoatBounceStringIds
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_ALLOW_NO_PP
	bicword gHitMarker, HITMARKER_NO_ATTACKSTRING
	setmagiccoattarget BS_ATTACKER
	return

BattleScript_SnatchedMove::
	attackstring
	ppreduce
	snatchsetbattlers
	playanimation BS_TARGET, B_ANIM_SNATCH_MOVE
	printstring STRINGID_PKMNSNATCHEDMOVE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_ALLOW_NO_PP
	swapattackerwithtarget
	return

BattleScript_EnduredMsg::
	printstring STRINGID_PKMNENDUREDHIT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SturdiedMsg::
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUpTarget
	printstring STRINGID_ENDUREDSTURDY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_OneHitKOMsg::
	printstring STRINGID_ONEHITKO
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SAtkDown2::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO
	setstatchanger STAT_SPATK, 2, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_SAtkDown2End
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_SAtkDown2End
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SAtkDown2End::
	return

BattleScript_MoveEffectClearSmog::
	printstring STRINGID_RESETSTARGETSSTATLEVELS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FocusPunchSetUp::
	flushtextbox
	playanimation BS_ATTACKER, B_ANIM_FOCUS_PUNCH_SETUP
	printstring STRINGID_PKMNTIGHTENINGFOCUS
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_AftermathDmg::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_AftermathDmgRet
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_AFTERMATHDMG
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
BattleScript_AftermathDmgRet:
	return

BattleScript_DampPreventsAftermath::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	pause 40
	copybyte gBattlerAbility, sBATTLER
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSABILITYPREVENTSABILITY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedIsAsleep::
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedWokeUp::
	bicword gHitMarker, HITMARKER_WAKE_UP_CLEAR
	printfromtable gWokeUpStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	return

BattleScript_MonWokeUpInUproar::
	printstring STRINGID_PKMNWOKEUPINUPROAR
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	end2

BattleScript_PoisonTurnDmg::
	printstring STRINGID_PKMNHURTBYPOISON
	waitmessage B_WAIT_TIME_LONG
BattleScript_DoStatusTurnDmg::
	statusanimation BS_ATTACKER
BattleScript_DoTurnDmg:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	checkteamslost BattleScript_DoTurnDmgEnd
BattleScript_DoTurnDmgEnd:
	end2

BattleScript_PoisonHealActivates::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_POISONHEALHPUP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	end2

BattleScript_BurnTurnDmg::
	printstring STRINGID_PKMNHURTBYBURN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoStatusTurnDmg

BattleScript_MoveUsedIsFrozen::
	printstring STRINGID_PKMNISFROZEN
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedUnfroze::
	printfromtable gGotDefrostedStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	return

BattleScript_DefrostedViaFireMove::
	printstring STRINGID_PKMNWASDEFROSTED
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_MoveUsedIsParalyzed::
	printstring STRINGID_PKMNISPARALYZED
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	cancelmultiturnmoves BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_PowderMoveNoEffect::
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	jumpiftype BS_TARGET, TYPE_GRASS, BattleScript_PowderMoveNoEffectPrint
	jumpifability BS_TARGET, ABILITY_OVERCOAT, BattleScript_PowderMoveNoEffectOvercoat
	printstring STRINGID_SAFETYGOGGLESPROTECTED
	goto BattleScript_PowderMoveNoEffectWaitMsg
BattleScript_PowderMoveNoEffectOvercoat:
	call BattleScript_AbilityPopUp
BattleScript_PowderMoveNoEffectPrint:
	printstring STRINGID_ITDOESNTAFFECT
BattleScript_PowderMoveNoEffectWaitMsg:
	waitmessage B_WAIT_TIME_LONG
	cancelmultiturnmoves BS_ATTACKER
	sethword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_MoveUsedFlinched::
	printstring STRINGID_PKMNFLINCHED
	waitmessage B_WAIT_TIME_LONG
	jumpifability BS_ATTACKER ABILITY_STEADFAST BattleScript_TryActivateSteadFast
BattleScript_MoveUsedFlinchedEnd:
	goto BattleScript_MoveEnd
BattleScript_TryActivateSteadFast:
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_MoveUsedFlinchedEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_MoveUsedFlinchedEnd
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	setbyte gBattleCommunication STAT_SPEED
	stattextbuffer BS_ATTACKER
	printstring STRINGID_ATTACKERABILITYSTATRAISE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveUsedFlinchedEnd

BattleScript_PrintUproarOverTurns::
	printfromtable gUproarOverTurnStringIds
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_ThrashConfuses::
	chosenstatus2animation BS_ATTACKER, STATUS2_CONFUSION
	printstring STRINGID_PKMNFATIGUECONFUSION
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_MoveUsedIsConfused::
	printstring STRINGID_PKMNISCONFUSED
	waitmessage B_WAIT_TIME_LONG
	status2animation BS_ATTACKER, STATUS2_CONFUSION
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, FALSE, BattleScript_MoveUsedIsConfusedRet
BattleScript_DoSelfConfusionDmg::
	cancelmultiturnmoves BS_ATTACKER
	adjustdamage
	printstring STRINGID_ITHURTCONFUSION
	waitmessage B_WAIT_TIME_LONG
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd
BattleScript_MoveUsedIsConfusedRet::
	return

BattleScript_MoveUsedIsConfusedNoMore::
	printstring STRINGID_PKMNHEALEDCONFUSION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PrintPayDayMoneyString::
	printstring STRINGID_PLAYERPICKEDUPMONEY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WrapTurnDmg::
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_DoTurnDmgEnd
	playanimation BS_ATTACKER, B_ANIM_TURN_TRAP, sB_ANIM_ARG1
	printstring STRINGID_PKMNHURTBY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoTurnDmg

BattleScript_WrapEnds::
	printstring STRINGID_PKMNFREEDFROM
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_MoveUsedIsInLove::
	printstring STRINGID_PKMNINLOVE
	waitmessage B_WAIT_TIME_LONG
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	return

BattleScript_MoveUsedIsInLoveCantAttack::
	printstring STRINGID_PKMNIMMOBILIZEDBYLOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NightmareTurnDmg::
	printstring STRINGID_PKMNLOCKEDINNIGHTMARE
	waitmessage B_WAIT_TIME_LONG
	status2animation BS_ATTACKER, STATUS2_NIGHTMARE
	goto BattleScript_DoTurnDmg

BattleScript_CurseTurnDmg::
	printstring STRINGID_PKMNAFFLICTEDBYCURSE
	waitmessage B_WAIT_TIME_LONG
	status2animation BS_ATTACKER, STATUS2_CURSED
	goto BattleScript_DoTurnDmg

BattleScript_TargetPRLZHeal::
	printstring STRINGID_PKMNHEALEDPARALYSIS
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_TargetWokeUp::
	printstring STRINGID_TARGETWOKEUP
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_TargetBurnHeal::
	printstring STRINGID_PKMNBURNHEALED
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_TooScaredToMove::
	printstring STRINGID_MONTOOSCAREDTOMOVE
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_MON_SCARED, NULL
	goto BattleScript_MoveEnd

BattleScript_GhostGetOutGetOut::
	printstring STRINGID_GHOSTGETOUTGETOUT
	playanimation BS_ATTACKER, B_ANIM_GHOST_GET_OUT, NULL
	goto BattleScript_MoveEnd

BattleScript_SilphScopeUnveiled::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_SILPHSCOPEUNVEILED
	waitstate
	playanimation BS_OPPONENT1, B_ANIM_SILPH_SCOPED, NULL
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_GHOSTWASMAROWAK
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_MoveEffectSleep::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gFellAsleepStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_UpdateEffectStatusIconRet::
	updatestatusicon BS_EFFECT_BATTLER
	waitstate
	return

BattleScript_YawnMakesAsleep::
	statusanimation BS_EFFECT_BATTLER
	printstring STRINGID_PKMNFELLASLEEP
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_EFFECT_BATTLER
	waitstate
	jumpifstatus3 BS_EFFECT_BATTLER, STATUS3_SKY_DROPPED, BattleScript_YawnEnd
	makevisible BS_EFFECT_BATTLER
	skydropyawn
BattleScript_YawnEnd:
	end2

BattleScript_EmbargoEndTurn::
	printstring STRINGID_EMBARGOENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TelekinesisEndTurn::
	printstring STRINGID_TELEKINESISENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_BufferEndTurn::
	printstring STRINGID_BUFFERENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_ToxicOrb::
	setbyte cMULTISTRING_CHOOSER, 0
	copybyte gEffectBattler, gBattlerAttacker
	call BattleScript_MoveEffectToxic
	end2

BattleScript_FlameOrb::
	setbyte cMULTISTRING_CHOOSER, 0
	copybyte gEffectBattler, gBattlerAttacker
	call BattleScript_MoveEffectBurn
	end2

BattleScript_MoveEffectPoison::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotPoisonedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectBurn::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotBurnedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectFreeze::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotFrozenStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectParalysis::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotParalyzedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectUproar::
	printstring STRINGID_PKMNCAUSEDUPROAR
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectToxic::
	statusanimation BS_EFFECT_BATTLER
	printstring STRINGID_PKMNBADLYPOISONED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectPayDay::
	printstring STRINGID_COINSSCATTERED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectWrap::
	printfromtable gWrappedStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectConfusion::
	chosenstatus2animation BS_EFFECT_BATTLER, STATUS2_CONFUSION
	printstring STRINGID_PKMNWASCONFUSED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectRecoil::
	jumpifmove MOVE_STRUGGLE, BattleScript_DoRecoil
	jumpifability BS_ATTACKER, ABILITY_ROCK_HEAD, BattleScript_RecoilEnd
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_RecoilEnd
BattleScript_DoRecoil::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNHITWITHRECOIL
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
BattleScript_RecoilEnd::
	return

BattleScript_ItemSteal::
	playanimation BS_TARGET, B_ANIM_ITEM_STEAL
	printstring STRINGID_PKMNSTOLEITEM
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_DrizzleActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNMADEITRAIN
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_RAIN_CONTINUES
	end3

BattleScript_AbilityRaisesDefenderStat::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	statbuffchange 0, NULL
	setgraphicalstatchangevalues
	playanimation BS_ABILITY_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_DEFENDERSSTATROSE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityPopUpTarget:
	copybyte gBattlerAbility, gBattlerTarget
BattleScript_AbilityPopUp:
	showabilitypopup BS_ABILITY_BATTLER
	pause 40
	recordability BS_ABILITY_BATTLER
	sethword sABILITY_OVERWRITE, 0
	return

BattleScript_AbilityPopUpScripting:
	showabilitypopup BS_SCRIPTING
	pause 40
	recordability BS_SCRIPTING
	sethword sABILITY_OVERWRITE, 0
	return

BattleScript_SpeedBoostActivates::
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_SpeedBoostActivatesEnd
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_PKMNRAISEDSPEED
	waitmessage B_WAIT_TIME_LONG
BattleScript_SpeedBoostActivatesEnd:
	end3

@ Can't compare directly to a value, have to compare to value at pointer
sZero:
.byte 0

BattleScript_TraceActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNTRACED
	waitmessage B_WAIT_TIME_LONG
	settracedability BS_SCRIPTING
	switchinabilities BS_SCRIPTING
	return

BattleScript_TraceActivatesEnd3::
	call BattleScript_TraceActivates
	end3

BattleScript_AbilityHpHeal:
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXRESTOREDHPALITTLE2
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_RainDishActivates::
	call BattleScript_AbilityHpHeal
	end3

BattleScript_HarvestActivates::
	pause 5
	tryrecycleitem BattleScript_HarvestActivatesEnd
	call BattleScript_AbilityPopUp
	printstring STRINGID_HARVESTBERRY
	waitmessage B_WAIT_TIME_LONG
BattleScript_HarvestActivatesEnd:
	end3

BattleScript_SolarPowerActivates::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	call BattleScript_AbilityPopUp
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_SOLARPOWERHPDROP
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	end3

BattleScript_HealerActivates::
	call BattleScript_AbilityPopUp
	curestatus BS_SCRIPTING
	updatestatusicon BS_SCRIPTING
	printstring STRINGID_HEALERCURE
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_SandstreamActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXWHIPPEDUPSANDSTORM
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SANDSTORM_CONTINUES
	end3

BattleScript_ShedSkinActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXCUREDYPROBLEM
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	end3

BattleScript_TryIntimidateHoldEffects:
	itemstatchangeeffects BS_TARGET
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_ADRENALINE_ORB, BattleScript_TryIntimidateHoldEffectsRet
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPEED, 12, BattleScript_TryIntimidateHoldEffectsRet
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange STAT_CHANGE_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_TryIntimidateHoldEffectsRet
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	copybyte sBATTLER, gBattlerTarget
	setlastuseditem BS_TARGET
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET
BattleScript_TryIntimidateHoldEffectsRet:
	return

BattleScript_IntimidateActivates::
	copybyte sSAVED_BATTLER, gBattlerTarget
	showabilitypopup BS_ATTACKER
	pause B_WAIT_TIME_LONG
	destroyabilitypopup
	setbyte gBattlerTarget, 0
BattleScript_IntimidateLoop:
	jumpifbyteequal gBattlerTarget, gBattlerAttacker, BattleScript_IntimidateLoopIncrement
	jumpiftargetally BattleScript_IntimidateLoopIncrement
	jumpifabsent BS_TARGET, BattleScript_IntimidateLoopIncrement
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_IntimidateLoopIncrement
	copybyte sBATTLER, gBattlerAttacker
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_NOT_PROTECT_AFFECTED | STAT_CHANGE_ALLOW_PTR, BattleScript_IntimidateLoopIncrement
	setgraphicalstatchangevalues
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_IntimidateWontDecrease
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_PKMNCUTSATTACKWITH
BattleScript_IntimidateEffect_WaitString:
	waitmessage B_WAIT_TIME_LONG
	copybyte sBATTLER, gBattlerTarget
	call BattleScript_TryIntimidateHoldEffects
BattleScript_IntimidateLoopIncrement:
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_IntimidateLoop
	copybyte sBATTLER, gBattlerAttacker
	destroyabilitypopup
	copybyte gBattlerTarget, sSAVED_BATTLER
	pause B_WAIT_TIME_MED
	end3

BattleScript_IntimidateWontDecrease:
	printstring STRINGID_STATSWONTDECREASE
	goto BattleScript_IntimidateEffect_WaitString

BattleScript_DroughtActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXINTENSIFIEDSUN
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SUN_CONTINUES
	end3

BattleScript_SnowWarningActivatesHail::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_SNOWWARNINGHAIL
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_HAIL_CONTINUES
	end3

BattleScript_ActivateTerrainEffects:
	savetarget
	setbyte gBattlerTarget, 0
BattleScript_ActivateTerrainSeed:
	copybyte sBATTLER, gBattlerTarget
	doterrainseed BS_TARGET, BattleScript_ActivateTerrainAbility
	removeitem BS_TARGET
BattleScript_ActivateTerrainAbility:
	addbyte gBattlerTarget, 0x1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_ActivateTerrainSeed
	restoretarget
	return

BattleScript_TookAttack::
	attackstring
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNSXTOOKATTACK
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED
	return

BattleScript_SturdyPreventsOHKO::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNPROTECTEDBY
	pause B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_DampStopsExplosion::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUpScripting
	printstring STRINGID_PKMNPREVENTSUSAGE
	pause B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	moveendcase MOVEEND_CLEAR_BITS
	end

BattleScript_MoveHPDrain_PPLoss::
	ppreduce
BattleScript_MoveHPDrain::
	attackstring
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNRESTOREDHPUSING
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_MoveStatDrain_PPLoss::
	ppreduce
BattleScript_MoveStatDrain::
	attackstring
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MoveStatDrain_Cont
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MoveStatDrain_Cont:
	clearsemiinvulnerablebit
	goto BattleScript_MoveEnd

BattleScript_MonMadeMoveUseless_PPLoss::
	ppreduce
BattleScript_MonMadeMoveUseless::
	attackstring
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXMADEYUSELESS
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_FlashFireBoost_PPLoss::
	ppreduce
BattleScript_FlashFireBoost::
	attackstring
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printfromtable gFlashFireStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AbilityPreventsPhasingOut::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNANCHORSITSELFWITH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AbilityNoStatLoss::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNPREVENTSSTATLOSSWITH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BRNPrevention::
	pause B_WAIT_TIME_SHORT
	printfromtable gBRNPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PRLZPrevention::
	pause B_WAIT_TIME_SHORT
	printfromtable gPRLZPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PSNPrevention::
	pause B_WAIT_TIME_SHORT
	printfromtable gPSNPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FlinchPrevention::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXPREVENTSFLINCHING
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_OwnTempoPrevents::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNPREVENTSCONFUSIONWITH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SoundproofProtected::
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXBLOCKSY
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_MoveUsedPsychicTerrainPrevents::
	printstring STRINGID_POKEMONCANNOTUSEMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_GrassyTerrainHeals::
	setbyte gBattleCommunication, 0
BattleScript_GrassyTerrainLoop:
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	checkgrassyterrainheal BS_ATTACKER, BattleScript_GrassyTerrainLoopIncrement
	printstring STRINGID_GRASSYTERRAINHEALS
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
BattleScript_GrassyTerrainLoopIncrement::
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_GrassyTerrainLoop
	bicword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	jumpifword CMP_COMMON_BITS, gFieldStatuses, STATUS_FIELD_TERRAIN_PERMANENT, BattleScript_GrassyTerrainHealEnd
BattleScript_GrassyTerrainHealEnd:
	end2

BattleScript_AbilityNoSpecificStatLoss::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXPREVENTSYLOSS
	waitmessage B_WAIT_TIME_LONG
	setbyte cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY
	orhalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	return

BattleScript_StickyHoldActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXMADEYINEFFECTIVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_ColorChangeActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNCHANGEDTYPEWITH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_CursedBodyActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_CURSEDBODYDISABLED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_TargetsStatWasMaxedOut::
	call BattleScript_AbilityPopUp
	statbuffchange STAT_CHANGE_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_TARGETSSTATWASMAXEDOUT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WeakArmorActivates::
	call BattleScript_AbilityPopUp
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeakArmorActivatesSpeed
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_WeakArmorDefAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_WeakArmorActivatesSpeed
	pause B_WAIT_TIME_SHORTEST
	printfromtable gStatDownStringIds
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED @ Set by statbuffchange when stat can't be decreased
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_WeakArmorActivatesSpeed
BattleScript_WeakArmorDefAnim:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_TARGETABILITYSTATLOWER
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeakArmorActivatesSpeed:
	setstatchanger STAT_SPEED, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeakArmorActivatesEnd
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WeakArmorSpeedAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_ROSE_EMPTY, BattleScript_WeakArmorActivatesEnd
	pause B_WAIT_TIME_SHORTEST
	printstring STRINGID_TARGETSTATWONTGOHIGHER
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_WeakArmorActivatesEnd
BattleScript_WeakArmorSpeedAnim:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_TARGETABILITYSTATRAISE
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeakArmorActivatesEnd:
	return

BattleScript_RaiseStatOnFaintingTarget::
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_RaiseStatOnFaintingTarget_End
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_LASTABILITYRAISEDSTAT
	waitmessage B_WAIT_TIME_LONG
BattleScript_RaiseStatOnFaintingTarget_End:
	return

BattleScript_AttackerAbilityStatRaise::
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackerAbilityStatRaise_End
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_ATTACKERABILITYSTATRAISE
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackerAbilityStatRaise_End:
	return

BattleScript_FellStingerRaisesStat::
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_FellStingerRaisesAtkEnd
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_ROSE, BattleScript_FellStingerRaisesAtkEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_FellStingerRaisesAtkEnd:
	return

BattleScript_AttackerAbilityStatRaiseEnd3::
	call BattleScript_AttackerAbilityStatRaise
	end3

BattleScript_SwitchInAbilityMsg::
	call BattleScript_AbilityPopUp
	printfromtable gSwitchInAbilityStringIds
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_FriskMsgWithPopup::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
BattleScript_FriskMsg::
	printstring STRINGID_FRISKACTIVATES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FriskActivates::
	tryfriskmsg BS_ATTACKER
	end3

BattleScript_ImposterActivates::
	call BattleScript_AbilityPopUp
	transformdataexecution
	playmoveanimation BS_ATTACKER, MOVE_TRANSFORM
	waitanimation
	printstring STRINGID_IMPOSTERTRANSFORM
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_HurtAttacker:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNHURTSWITH
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	return

BattleScript_RoughSkinActivates::
	call BattleScript_AbilityPopUp
	call BattleScript_HurtAttacker
	return

BattleScript_RockyHelmetActivates::
	@ don't play the animation for a fainted mon
	jumpifabsent BS_TARGET, BattleScript_RockyHelmetActivatesDmg
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
BattleScript_RockyHelmetActivatesDmg:
	call BattleScript_HurtAttacker
	return

BattleScript_CuteCharmActivates::
	call BattleScript_AbilityPopUp
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	printstring STRINGID_PKMNSXINFATUATEDY
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryDestinyKnotTarget
	return

BattleScript_AbilityStatusEffect::
	waitstate
	call BattleScript_AbilityPopUp
	seteffectsecondary
	return

BattleScript_SynchronizeActivates::
	waitstate
	call BattleScript_AbilityPopUp
	seteffectprimary
	return

BattleScript_NoItemSteal::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNSXMADEYINEFFECTIVE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityCuredStatus::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXCUREDITSYPROBLEM
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	return

BattleScript_BattlerShookOffTaunt::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSHOOKOFFTHETAUNT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BattlerGotOverItsInfatuation::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNGOTOVERITSINFATUATION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_IgnoresWhileAsleep::
	printstring STRINGID_PKMNIGNORESASLEEP
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	end

BattleScript_IgnoresAndUsesRandomMove::
	printstring STRINGID_PKMNIGNOREDORDERS
	waitmessage B_WAIT_TIME_LONG
	setbyte sMOVE_EFFECT, 0
	jumptocalledmove FALSE

BattleScript_MoveUsedLoafingAround::
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_LOAFING, BattleScript_MoveUsedLoafingAroundMsg
	@ Skip ahead if not the Battle Palace message
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_INCAPABLE_OF_POWER, BattleScript_MoveUsedLoafingAroundMsg
	setbyte gBattleCommunication, 0
	palacetryescapestatus BS_ATTACKER
	setbyte cMULTISTRING_CHOOSER, B_MSG_INCAPABLE_OF_POWER
BattleScript_MoveUsedLoafingAroundMsg::
	printfromtable gInobedientStringIds
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	end
BattleScript_TruantLoafingAround::
	call BattleScript_AbilityPopUp
	goto BattleScript_MoveUsedLoafingAroundMsg

BattleScript_IgnoresAndFallsAsleep::
	printstring STRINGID_PKMNBEGANTONAP
	waitmessage B_WAIT_TIME_LONG
	seteffectprimary MOVE_EFFECT_SLEEP | MOVE_EFFECT_AFFECTS_USER
	moveendto MOVEEND_NEXT_TARGET
	end

BattleScript_IgnoresAndHitsItself::
	printstring STRINGID_PKMNWONTOBEY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoSelfConfusionDmg

BattleScript_SubstituteFade::
	playanimation BS_TARGET, B_ANIM_SUBSTITUTE_FADE
	printstring STRINGID_PKMNSUBSTITUTEFADED
	return

BattleScript_BerryCurePrlzEnd2::
	call BattleScript_BerryCureParRet
	end2

BattleScript_BerryCureParRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMCUREDPARALYSIS
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCurePsnEnd2::
	call BattleScript_BerryCurePsnRet
	end2

BattleScript_BerryCurePsnRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMCUREDPOISON
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureBrnEnd2::
	call BattleScript_BerryCureBrnRet
	end2

BattleScript_BerryCureBrnRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMHEALEDBURN
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureFrzEnd2::
	call BattleScript_BerryCureFrzRet
	end2

BattleScript_BerryCureFrzRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMDEFROSTEDIT
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureSlpEnd2::
	call BattleScript_BerryCureSlpRet
	end2

BattleScript_BerryCureSlpRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMWOKEIT
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_GemActivates::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	setlastuseditem BS_ATTACKER
	printstring STRINGID_GEMACTIVATES
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER
	return

BattleScript_BerryReduceDmg::
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	setlastuseditem BS_TARGET
	printstring STRINGID_TARGETATEITEM
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET
	return

BattleScript_PrintBerryReduceString::
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_BERRYDMGREDUCES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BerryCureConfusionEnd2::
	call BattleScript_BerryCureConfusionRet
	end2

BattleScript_BerryCureConfusionRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMSNAPPEDOUT
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureChosenStatusEnd2::
	call BattleScript_BerryCureChosenStatusRet
	end2

BattleScript_BerryCureChosenStatusRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printfromtable gBerryEffectStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_MentalHerbCureRet::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	printfromtable gMentalHerbCureStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	copybyte gBattlerAttacker, sSAVED_BATTLER   @ restore the original attacker just to be safe
	return

BattleScript_MentalHerbCureEnd2::
	call BattleScript_MentalHerbCureRet
	end2

BattleScript_WhiteHerbEnd2::
	call BattleScript_WhiteHerbRet
	end2

BattleScript_WhiteHerbRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMRESTOREDSTATUS
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	return

BattleScript_ItemHealHP_RemoveItemRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_ItemHealHP_RemoveItemEnd2::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	removeitem BS_ATTACKER
	end2

BattleScript_BerryPPHealRet::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMRESTOREDPP
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER
	return

BattleScript_BerryPPHealEnd2::
	call BattleScript_BerryPPHealRet
	end2

BattleScript_ItemHealHP_End2::
	call BattleScript_ItemHealHP_Ret
	end2

BattleScript_AirBalloonMsgIn::
	printstring STRINGID_AIRBALLOONFLOAT
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_AirBalloonMsgPop::
	printstring STRINGID_AIRBALLOONPOP
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET
	return

BattleScript_ItemHurtRet::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_HURTBYITEM
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	return

BattleScript_ItemHurtEnd2::
	playanimation BS_ATTACKER, B_ANIM_MON_HIT
	waitanimation
	call BattleScript_ItemHurtRet
	end2

BattleScript_ItemHealHP_Ret::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMRESTOREDHPALITTLE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_SelectingNotAllowedMoveChoiceItem::
	printselectionstring STRINGID_ITEMALLOWSONLYYMOVE
	endselectionscript

BattleScript_SelectingNotAllowedMoveChoiceItemInPalace::
	printstring STRINGID_ITEMALLOWSONLYYMOVE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveAssaultVest::
	printselectionstring STRINGID_ASSAULTVESTDOESNTALLOW
	endselectionscript

BattleScript_SelectingNotAllowedMoveAssaultVestInPalace::
	printstring STRINGID_ASSAULTVESTDOESNTALLOW
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_HangedOnMsg::
	playanimation BS_TARGET, B_ANIM_HANGED_ON
	printstring STRINGID_PKMNHUNGONWITHX
	waitmessage B_WAIT_TIME_LONG
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_FOCUS_SASH, BattleScript_HangedOnMsgRet
	removeitem BS_TARGET
BattleScript_HangedOnMsgRet:
	return

BattleScript_BerryConfuseHealEnd2::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	printstring STRINGID_FORXCOMMAYZ
	waitmessage B_WAIT_TIME_LONG
	seteffectprimary MOVE_EFFECT_CONFUSION | MOVE_EFFECT_AFFECTS_USER
	removeitem BS_SCRIPTING
	end2

BattleScript_BerryConfuseHealRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	printstring STRINGID_FORXCOMMAYZ
	waitmessage B_WAIT_TIME_LONG
	seteffectprimary MOVE_EFFECT_CONFUSION | MOVE_EFFECT_CERTAIN
	removeitem BS_TARGET
	return

BattleScript_BerryStatRaiseEnd2::
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_BerryStatRaiseEnd2_End
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, sB_ANIM_ARG1
	setbyte cMULTISTRING_CHOOSER, B_MSG_STAT_ROSE_ITEM
	call BattleScript_StatUp
	removeitem BS_ATTACKER
BattleScript_BerryStatRaiseEnd2_End::
	end2

BattleScript_BerryStatRaiseRet::
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_BerryStatRaiseRet_End
	setgraphicalstatchangevalues
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, sB_ANIM_ARG1
	setbyte cMULTISTRING_CHOOSER, B_MSG_STAT_ROSE_ITEM
	call BattleScript_StatUp
	removeitem BS_SCRIPTING
BattleScript_BerryStatRaiseRet_End:
	return

BattleScript_BerryFocusEnergyRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_PKMNUSEDXTOGETPUMPED
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	return

BattleScript_BerryFocusEnergyEnd2::
	call BattleScript_BerryFocusEnergyRet
	end2

BattleScript_ActionSelectionItemsCantBeUsed::
	printselectionstring STRINGID_ITEMSCANTBEUSEDNOW
	endselectionscript

BattleScript_FlushMessageBox::
	flushtextbox
	return

BattleScript_PalacePrintFlavorText::
	setbyte gBattleCommunication + 1, 0
BattleScript_PalaceTryBattlerFlavorText::
	palaceflavortext BS_ATTACKER @ BS_ATTACKER here overwritten by gBattleCommunication + 1
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, TRUE, BattleScript_PalaceEndFlavorText
	printfromtable gBattlePalaceFlavorTextTable
	waitmessage B_WAIT_TIME_LONG
BattleScript_PalaceEndFlavorText::
	addbyte gBattleCommunication + 1, 1
	jumpifbytenotequal gBattleCommunication + 1, gBattlersCount, BattleScript_PalaceTryBattlerFlavorText
	setbyte gBattleCommunication, 0
	setbyte gBattleCommunication + 1, 0
	end2

BattleScript_ArenaTurnBeginning::
	waitcry BS_ATTACKER
	volumedown
	playse SE_ARENA_TIMEUP1
	pause 8
	playse SE_ARENA_TIMEUP1
	arenadrawreftextbox
	arenajudgmentstring B_MSG_REF_COMMENCE_BATTLE
	arenawaitmessage B_MSG_REF_COMMENCE_BATTLE
	pause B_WAIT_TIME_LONG
	arenaerasereftextbox
	volumeup
	end2

BattleScript_ArenaDoJudgment::
	makevisible BS_PLAYER1
	waitstate
	makevisible BS_OPPONENT1
	waitstate
	volumedown
	playse SE_ARENA_TIMEUP1
	pause 8
	playse SE_ARENA_TIMEUP1
	pause B_WAIT_TIME_LONG
	arenadrawreftextbox
	arenajudgmentstring B_MSG_REF_THATS_IT
	arenawaitmessage B_MSG_REF_THATS_IT
	pause B_WAIT_TIME_LONG
	setbyte gBattleCommunication, 0  @ Reset state for arenajudgmentwindow
	arenajudgmentwindow
	pause B_WAIT_TIME_LONG
	arenajudgmentwindow
	arenajudgmentstring B_MSG_REF_JUDGE_MIND
	arenawaitmessage B_MSG_REF_JUDGE_MIND
	arenajudgmentwindow
	arenajudgmentstring B_MSG_REF_JUDGE_SKILL
	arenawaitmessage B_MSG_REF_JUDGE_SKILL
	arenajudgmentwindow
	arenajudgmentstring B_MSG_REF_JUDGE_BODY
	arenawaitmessage B_MSG_REF_JUDGE_BODY
	arenajudgmentwindow
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, ARENA_RESULT_PLAYER_LOST, BattleScript_ArenaJudgmentPlayerLoses
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, ARENA_RESULT_TIE, BattleScript_ArenaJudgmentDraw
@ ARENA_RESULT_PLAYER_WON
	arenajudgmentstring B_MSG_REF_PLAYER_WON
	arenawaitmessage B_MSG_REF_PLAYER_WON
	arenajudgmentwindow
	arenaerasereftextbox
	printstring STRINGID_DEFEATEDOPPONENTBYREFEREE
	waitmessage B_WAIT_TIME_LONG
	playfaintcry BS_OPPONENT1
	waitcry BS_ATTACKER
	dofaintanimation BS_OPPONENT1
	cleareffectsonfaint BS_OPPONENT1
	arenaopponentmonlost
	end2

BattleScript_ArenaJudgmentPlayerLoses:
	arenajudgmentstring B_MSG_REF_OPPONENT_WON
	arenawaitmessage B_MSG_REF_OPPONENT_WON
	arenajudgmentwindow
	arenaerasereftextbox
	printstring STRINGID_LOSTTOOPPONENTBYREFEREE
	waitmessage B_WAIT_TIME_LONG
	playfaintcry BS_PLAYER1
	waitcry BS_ATTACKER
	dofaintanimation BS_PLAYER1
	cleareffectsonfaint BS_PLAYER1
	arenaplayermonlost
	end2

BattleScript_ArenaJudgmentDraw:
	arenajudgmentstring B_MSG_REF_DRAW
	arenawaitmessage B_MSG_REF_DRAW
	arenajudgmentwindow
	arenaerasereftextbox
	printstring STRINGID_TIEDOPPONENTBYREFEREE
	waitmessage B_WAIT_TIME_LONG
	playfaintcry BS_PLAYER1
	waitcry BS_ATTACKER
	dofaintanimation BS_PLAYER1
	cleareffectsonfaint BS_PLAYER1
	playfaintcry BS_OPPONENT1
	waitcry BS_ATTACKER
	dofaintanimation BS_OPPONENT1
	cleareffectsonfaint BS_OPPONENT1
	arenabothmonlost
	end2

BattleScript_AskIfWantsToForfeitMatch::
	printselectionstring STRINGID_QUESTIONFORFEITMATCH
	forfeityesnobox BS_ATTACKER
	endselectionscript

BattleScript_PrintPlayerForfeited::
	printstring STRINGID_FORFEITEDMATCH
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_PrintPlayerForfeitedLinkBattle::
	printstring STRINGID_FORFEITEDMATCH
	waitmessage B_WAIT_TIME_LONG
	endlinkbattle
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_AnnounceAirLockCloudNine::
	call BattleScript_AbilityPopUp
	printstring STRINGID_AIRLOCKACTIVATES
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_QuickClawActivation::
	flushtextbox
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	printstring STRINGID_CANACTFASTERTHANKSTO
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_CustapBerryActivation::
	flushtextbox
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	printstring STRINGID_CANACTFASTERTHANKSTO
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER
	end2

BattleScript_MicleBerryActivateEnd2::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_MICLEBERRYACTIVATES
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER
	end2

BattleScript_MicleBerryActivateRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_MICLEBERRYACTIVATES
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	return

BattleScript_JabocaRowapBerryActivates::
	jumpifabsent BS_TARGET, BattleScript_JabocaRowapBerryActivate_Dmg   @ dont play the animation for a fainted target
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
BattleScript_JabocaRowapBerryActivate_Dmg:
	call BattleScript_HurtAttacker
	removeitem BS_TARGET
	return

BattleScript_StickyBarbTransfer::
	playanimation BS_TARGET, B_ANIM_ITEM_STEAL
	printstring STRINGID_STICKYBARBTRANSFER
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET
	return

BattleScript_RedCardActivates::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_REDCARDACTIVATE
	waitmessage B_WAIT_TIME_LONG
	swapattackerwithtarget
	jumpifstatus3 BS_EFFECT_BATTLER, STATUS3_ROOTED, BattleScript_RedCardIngrain
	jumpifability BS_EFFECT_BATTLER, ABILITY_SUCTION_CUPS, BattleScript_RedCardSuctionCups
	removeitem BS_SCRIPTING
	setbyte sSWITCH_CASE, B_SWITCH_RED_CARD
	forcerandomswitch BattleScript_RedCardEnd
	@ changes the current battle script. the rest happens in BattleScript_RoarSuccessSwitch_Ret, if switch is successful
BattleScript_RedCardEnd:
	return
BattleScript_RedCardIngrain:
	printstring STRINGID_PKMNANCHOREDITSELF
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	swapattackerwithtarget
	return
BattleScript_RedCardSuctionCups:
	printstring STRINGID_PKMNANCHORSITSELFWITH
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	swapattackerwithtarget
	return

BattleScript_EjectButtonActivates::
	makevisible BS_ATTACKER
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printstring STRINGID_EJECTBUTTONACTIVATE
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	makeinvisible BS_SCRIPTING
	openpartyscreen BS_SCRIPTING, BattleScript_EjectButtonEnd
	switchoutabilities BS_SCRIPTING
	waitstate
	switchhandleorder BS_SCRIPTING 0x2
	returntoball BS_SCRIPTING
	getswitchedmondata BS_SCRIPTING
	switchindataupdate BS_SCRIPTING
	hpthresholds BS_SCRIPTING
	printstring 0x3
	switchinanim BS_SCRIPTING 0x1
	waitstate
	switchineffects BS_SCRIPTING
BattleScript_EjectButtonEnd:
	return

BattleScript_TargetAbilityStatRaiseRet::
	copybyte sSAVED_BATTLER, gBattlerAttacker
	copybyte gBattlerAbility, gEffectBattler
	copybyte gBattlerAttacker, gBattlerTarget
	call BattleScript_AbilityPopUp
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN, BattleScript_TargetAbilityStatRaiseRet_End
	setgraphicalstatchangevalues
	call BattleScript_StatUp
BattleScript_TargetAbilityStatRaiseRet_End:
	copybyte gBattlerAttacker, sSAVED_BATTLER
	return
