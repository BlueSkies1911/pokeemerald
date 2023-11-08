#include "global.h"
#include "battle_anim.h"

// function declarations
static void SpriteCB_SpriteOnMonForDuration(struct Sprite *sprite);

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