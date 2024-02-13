#include "global.h"
#include "battle_anim.h"
#include "gpu_regs.h"
#include "item_icon.h"

// function declarations
static void SpriteCB_SpriteOnMonForDuration(struct Sprite *sprite);
static void SpriteCB_ToxicThreadWrap(struct Sprite *sprite);
static void SpriteCB_SurroundingRing(struct Sprite *sprite);
static void AnimSkyDropBallUp(struct Sprite *sprite);

// GEN 4
// shadow sneak
const struct SpriteTemplate gShadowSneakImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimIceEffectParticle
};

// power trick
const struct SpriteTemplate gPowerTrickSpriteTemplate =
{
    .tileTag = ANIM_TAG_POWER_TRICK,
    .paletteTag = ANIM_TAG_POWER_TRICK,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_SpinningBone,
    .callback = SpriteCB_SpriteOnMonForDuration
};


//// GEN 5
//shell smash
const struct SpriteTemplate gShellSmashLeftShellSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHELL_RIGHT,
    .paletteTag = ANIM_TAG_SHELL_RIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Bite,
    .callback = AnimBite
};

const struct SpriteTemplate gShellSmashRightShellSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHELL_LEFT,
    .paletteTag = ANIM_TAG_SHELL_LEFT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Bite,
    .callback = AnimBite
};

const struct SpriteTemplate gShellSmashPurpleRocksSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_SHELL_RIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlyingRock,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRockFragment
};

//wide guard
const struct SpriteTemplate gWideGuardBlueConversionTemplate =
{
    .tileTag = ANIM_TAG_CONVERSION,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_8x8,
    .anims = gConversionAnimTable,
    .images = NULL,
    .affineAnims = gConversionAffineAnimTable,
    .callback = AnimConversion
};

//guard split
const struct SpriteTemplate gGuardSwapOrbs1Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_BLUEGREEN_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMimicOrb
};

const struct SpriteTemplate gGuardSwapOrbs2Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_BLUEGREEN_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMissileArc
};

// power split
const struct SpriteTemplate gPowerSplitOrbs1Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMimicOrb
};

const struct SpriteTemplate gPowerSplitOrbs2Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMissileArc
};

// automotise
const struct SpriteTemplate gAutotomiseMetalShardsTemplate =
{
    .tileTag = ANIM_TAG_METAL_BITS,
    .paletteTag = ANIM_TAG_METAL_BITS,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_TearDrop,
    .callback = AnimTearDrop
};

//rage powder
const struct SpriteTemplate gRagePowderRedPowderTemplate =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_HEART_STAMP,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSporeParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSporeParticle
};

//flame charge
const struct SpriteTemplate gFlameChargeEmberTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlamethrowerFlame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPetalDanceBigFlower
};

//final gambit
const struct SpriteTemplate gFinalGambitBlueYawnTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_WATER_IMPACT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall
};

const struct SpriteTemplate gFinalGambitExplosionTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_WATER_IMPACT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//synchronoise
const struct SpriteTemplate gSynchronoiseVioletRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing
};

const struct SpriteTemplate gSynchronoiseYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing
};

const struct SpriteTemplate gSynchronoiseBlueRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing
};

const struct SpriteTemplate gSynchronoiseAeroWheelTemplate =
{
    .tileTag = ANIM_TAG_AIR_WAVE_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gAffineAnims_AirWaveCrescent,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpread
};

//electro ball
const struct SpriteTemplate gElectroBallCannonBallTemplate =
{
    .tileTag = ANIM_TAG_FLASH_CANNON_BALL,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall
};

//foul play
const struct SpriteTemplate gFoulPlayImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

const struct SpriteTemplate gFoulPlayRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//simple beam
const struct SpriteTemplate gSimpleBeamBrownTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};

const struct SpriteTemplate gSimpleBeamPinkTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};

const struct SpriteTemplate gSimpleBeamBrownRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

const struct SpriteTemplate gSimpleBeamPinkRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

// after you
const struct SpriteTemplate gAfterYouGreenRageTemplate =
{
    .tileTag = ANIM_TAG_ANGER,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAngerMarkAffineAnimTable,
    .callback = AnimAngerMark
};

//quick guard
const struct SpriteTemplate gQuickGuardArmImpactTemplate =
{
    .tileTag = ANIM_TAG_QUICK_GUARD_HAND,
    .paletteTag = ANIM_TAG_QUICK_GUARD_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBasicFistOrFoot
};

//sky drop
static const union AffineAnimCmd sSkyDropFlyBallAffineAnimCmd_0[] =
{
    AFFINEANIMCMD_FRAME(0xa0, 0x100, 0x50, 0x0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSkyDropFlyBallAffineAnimCmds[] =
{
    sSkyDropFlyBallAffineAnimCmd_0
};

const struct SpriteTemplate gSkyDropFlyBallTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSkyDropFlyBallAffineAnimCmds,
    .callback = AnimThrowMistBall
};

const struct SpriteTemplate gSkyDropTargetFlyingTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimSkyDropBallUp
};

//circle throw
const struct SpriteTemplate gCircleThrowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//reflect type
const struct SpriteTemplate gReflectTypeBlueStringTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ToxicThreadWrap
};

const struct SpriteTemplate gReflectTypeVioletStringTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ToxicThreadWrap
};

const struct SpriteTemplate gReflectTypeWhiteStringTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ToxicThreadWrap
};

const struct SpriteTemplate gReflectTypeWhiteRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

const struct SpriteTemplate gReflectTypePinkRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

const struct SpriteTemplate gReflectTypeVioletRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

const struct SpriteTemplate gReflectTypeBlueRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

//frost breath
const struct SpriteTemplate gFrostBreathBlueRageTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DragonRageFirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDragonRageFirePlume
};

const struct SpriteTemplate gFrostBreathBlueBreathTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonRageFire,
    .images = NULL,
    .affineAnims = gAffineAnims_DragonRageFire,
    .callback = AnimDragonFireToTarget
};

//heart stamp
const struct SpriteTemplate gHeartStampSpinningHeartTemplate =
{
    .tileTag = ANIM_TAG_HEART_STAMP,
    .paletteTag = ANIM_TAG_HEART_STAMP,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gAffineAnims_SpinningHandOrFoot,
    .callback = AnimSpinningKickOrPunch
};

//dual chop
const struct SpriteTemplate gDualChopImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//razor shell
const struct SpriteTemplate gRazorShellTemplate =
{
    .tileTag = ANIM_TAG_RAZOR_SHELL,
    .paletteTag = ANIM_TAG_RAZOR_SHELL,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = SpriteCB_SpriteOnMonForDuration
};

//leaf tornado
const struct SpriteTemplate gLeafTornadoVortexTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};

//tail slap
const struct SpriteTemplate gTailSlapTemplate =
{
    .tileTag = ANIM_TAG_PUNISHMENT_BLADES,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gScratchAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//icicle crash
static const union AffineAnimCmd sSpriteAffineAnim_IcicleCrash[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 128, 1), //180 degree turn
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sSpriteAffineAnimTable_IcicleCrash[] =
{
    sSpriteAffineAnim_IcicleCrash,
};
const struct SpriteTemplate gIcicleCrashSpearTemplate =
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ICICLE_SPEAR,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_IcicleCrash,
    .callback = AnimFallingRock
};

// GEN 6
//belch
static const union AnimCmd sAnimCmdBerryEaten[] =
{
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnimCmdFramesBerryEaten[] =
{
    sAnimCmdBerryEaten,
};
const struct SpriteTemplate gBelchBerryTemplate =
{
    .tileTag = ANIM_TAG_BERRY_NORMAL,
    .paletteTag = ANIM_TAG_BERRY_NORMAL,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = sAnimCmdFramesBerryEaten,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMissileArc
};

//petal blizzard
static const union AnimCmd sAnimCmd_PetalBlizzard1_0[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const sAnimCmdTable_PetalBlizzard1[] =
{
    sAnimCmd_PetalBlizzard1_0,
};
const struct SpriteTemplate gPetalBlizzardTwister1Template =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnimCmdTable_PetalBlizzard1,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveTwisterParticle
};
static const u16 sPetalBlizzardFlowerOam[] = {0x0, 0x2000,0x0800,0x0};  //todo: convert to oam data
static const union AnimCmd sAnimCmd_PetalBlizzard2_0[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnimCmdTable_PetalBlizzard2[] =
{
    sAnimCmd_PetalBlizzard2_0,
};
const struct SpriteTemplate gPetalBlizzardTwister2Template =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = (const struct OamData *) &sPetalBlizzardFlowerOam,
    .anims = sAnimCmdTable_PetalBlizzard2,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveTwisterParticle
};

//grassy terrain
const struct SpriteTemplate gGrassyTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimOrbitFast
};

const struct SpriteTemplate gGrassyTerrainStarTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_GREEN_SPARKLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gMoonlightSparkleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOrbitScatter
};

//misty terrain
const struct SpriteTemplate gMistyTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimOrbitFast
};

const struct SpriteTemplate gMistyTerrainStarTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gMoonlightSparkleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOrbitScatter
};

//eerie impulse
const struct SpriteTemplate gEerieImpulseRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing
};

const struct SpriteTemplate gEerieImpulseImpactTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGrantingStars
};

//venom drench
const struct SpriteTemplate gVenomDrenchAcidTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFallingRock
};

//magnetic flux
const struct SpriteTemplate gMagneticFluxUproarTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

//electric terrain
const struct SpriteTemplate gElectricTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_ElectricChargingParticles,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOrbitFast
};

const struct SpriteTemplate gElectricTerrainFlyingBallTemplate =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_ElectricChargingParticles,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOrbitScatter
};

static u8 LoadBattleAnimTarget(u8 arg)
{
    u8 battler;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        switch (gBattleAnimArgs[arg])
        {
        case 0:
            battler = gBattleAnimAttacker;
            break;
        default:
            battler = gBattleAnimTarget;
            break;
        case 2:
            battler = BATTLE_PARTNER(gBattleAnimAttacker);
            break;
        case 3:
            battler = BATTLE_PARTNER(gBattleAnimTarget);
            break;
        }
    }
    else
    {
        if (gBattleAnimArgs[arg] == 0)
            battler = gBattleAnimAttacker;
        else
            battler = gBattleAnimTarget;
    }

    return battler;
}

static void SpriteCB_SpriteOnMonForDuration(struct Sprite *sprite)
{
    u8 target = LoadBattleAnimTarget(0);

    if (!IsBattlerSpriteVisible(target))
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(target, 0);
        sprite->y = GetBattlerSpriteCoord(target, 1);
        sprite->x += gBattleAnimArgs[1];
        sprite->y += gBattleAnimArgs[2];
        sprite->data[0] = 0;
        sprite->data[1] = gBattleAnimArgs[3];
        sprite->data[2] = gBattleAnimArgs[4];
        sprite->data[3] = 0;
        sprite->callback = AnimBrickBreakWall_Step;
    }
}

static void SpriteCB_ToxicThreadWrap(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    sprite->y += gBattleAnimArgs[1];
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        sprite->y += 8;

    sprite->callback = AnimStringWrap_Step;
}

static void SpriteCB_SurroundingRing(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1) + 40;

    sprite->data[0] = 13;
    sprite->data[2] = sprite->x;
    sprite->data[4] = sprite->y - 72;

    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimSkyDropBallUp(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->callback = AnimFlyBallUp_Step;
    gSprites[GetAnimBattlerSpriteId(ANIM_ATTACKER)].invisible = TRUE;
}

void AnimTask_CreateBestowItem(u8 taskId)
{
    u8 iconSpriteId = AddItemIconSprite(ANIM_TAG_ITEM_BAG, ANIM_TAG_ITEM_BAG, gLastUsedItem);

    if (iconSpriteId != MAX_SPRITES)
    {
        gSprites[iconSpriteId].oam.priority = 2;
        gSprites[iconSpriteId].callback = AnimThrowProjectile;
        ++gAnimVisualTaskCount;
    }
    DestroyAnimVisualTask(taskId);
}

//Creates purple flames that surround the target.
//No args.
void AnimTask_PurpleFlamesOnTarget(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 16;
    task->data[9] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    task->data[10] = GetBattlerYCoordWithElevation(gBattleAnimTarget);
    task->data[11] = (GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_WIDTH) / 2) + 8;
    task->data[7] = 0;
    task->data[5] = GetBattlerSpriteBGPriority(gBattleAnimTarget);
    task->data[6] = GetBattlerSpriteSubpriority(gBattleAnimTarget) - 2;
    task->data[3] = 0;
    task->data[4] = 16;
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0x10));
    task->data[8] = 0;
    task->func = AnimTask_GrudgeFlames_Step;
}
