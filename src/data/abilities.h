const struct Ability gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("Stench"),
        .description = COMPOUND_STRING("May cause a foe to flinch."),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("Drizzle"),
        .description = COMPOUND_STRING("Summons rain in battle."),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("Speed Boost"),
        .description = COMPOUND_STRING("Gradually boosts Speed."),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("Battle Armor"),
        .description = COMPOUND_STRING("Blocks critical hits."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("Sturdy"),
        .description = COMPOUND_STRING("Negates 1-hit KO attacks."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("Damp"),
        .description = COMPOUND_STRING("Prevents self-destruction."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("Limber"),
        .description = COMPOUND_STRING("Prevents paralysis."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("Sand Veil"),
        .description = COMPOUND_STRING("Ups evasion in a sandstorm."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("Static"),
        .description = COMPOUND_STRING("Paralyses on contact."),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("Volt Absorb"),
        .description = COMPOUND_STRING("Turns electricity into HP."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("Water Absorb"),
        .description = COMPOUND_STRING("Changes water into HP."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("Oblivious"),
        .description = COMPOUND_STRING("Prevents attraction."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("Cloud Nine"),
        .description = COMPOUND_STRING("Negates weather effects."),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Compound Eyes"),
    #else
        .name = _("CompoundEyes"),
    #endif
        .description = COMPOUND_STRING("Raises accuracy."),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("Insomnia"),
        .description = COMPOUND_STRING("Prevents sleep."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("Color Change"),
        .description = COMPOUND_STRING("Changes type to foe's move."),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("Immunity"),
        .description = COMPOUND_STRING("Prevents poisoning."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("Flash Fire"),
        .description = COMPOUND_STRING("Powers up if hit by fire."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("Shield Dust"),
        .description = COMPOUND_STRING("Prevents added effects."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("Own Tempo"),
        .description = COMPOUND_STRING("Prevents confusion."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("Suction Cups"),
        .description = COMPOUND_STRING("Firmly anchors the body."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("Intimidate"),
        .description = COMPOUND_STRING("Lowers the foe's Attack."),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("Shadow Tag"),
        .description = COMPOUND_STRING("Prevents the foe's escape."),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("Rough Skin"),
        .description = COMPOUND_STRING("Hurts to touch."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("Wonder Guard"),
        .description = COMPOUND_STRING("“Supereffective” hits."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("Levitate"),
        .description = COMPOUND_STRING("Not hit by Ground attacks."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("Effect Spore"),
        .description = COMPOUND_STRING("Leaves spores on contact."),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("Synchronize"),
        .description = COMPOUND_STRING("Passes on status problems."),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("Clear Body"),
        .description = COMPOUND_STRING("Prevents ability reduction."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("Natural Cure"),
        .description = COMPOUND_STRING("Heals upon switching out."),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Lightning Rod"),
    #else
        .name = _("LightningRod"),
    #endif
        .description = COMPOUND_STRING("Draws electrical moves."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("Serene Grace"),
        .description = COMPOUND_STRING("Promotes added effects."),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("Swift Swim"),
        .description = COMPOUND_STRING("Raises Speed in rain."),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("Chlorophyll"),
        .description = COMPOUND_STRING("Raises Speed in sunshine."),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("Illuminate"),
        .description = COMPOUND_STRING("Encounter rate increases."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("Trace"),
        .description = COMPOUND_STRING("Copies special ability."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("Huge Power"),
        .description = COMPOUND_STRING("Raises Attack."),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("Poison Point"),
        .description = COMPOUND_STRING("Poisons foe on contact."),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("Inner Focus"),
        .description = COMPOUND_STRING("Prevents flinching."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("Magma Armor"),
        .description = COMPOUND_STRING("Prevents freezing."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("Water Veil"),
        .description = COMPOUND_STRING("Prevents burns."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("Magnet Pull"),
        .description = COMPOUND_STRING("Traps Steel-type Pokémon."),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("Soundproof"),
        .description = COMPOUND_STRING("Avoids sound-based moves."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("Rain Dish"),
        .description = COMPOUND_STRING("Slight HP recovery in rain."),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("Sand Stream"),
        .description = COMPOUND_STRING("Summons a sandstorm."),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("Pressure"),
        .description = COMPOUND_STRING("Raises foe's PP usage."),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("Thick Fat"),
        .description = COMPOUND_STRING("Heat-and-cold protection."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("Early Bird"),
        .description = COMPOUND_STRING("Awakens quickly from sleep."),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("Flame Body"),
        .description = COMPOUND_STRING("Burns the foe on contact."),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("Run Away"),
        .description = COMPOUND_STRING("Makes escaping easier."),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("Keen Eye"),
        .description = COMPOUND_STRING("Prevents loss of accuracy."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("Hyper Cutter"),
        .description = COMPOUND_STRING("Prevents Attack reduction."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("Pickup"),
        .description = COMPOUND_STRING("May pick up items."),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("Truant"),
        .description = COMPOUND_STRING("Moves only every two turns."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("Hustle"),
        .description = COMPOUND_STRING("Trades accuracy for power."),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("Cute Charm"),
        .description = COMPOUND_STRING("Infatuates on contact."),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("Plus"),
        .description = COMPOUND_STRING("Powers up with Minus."),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("Minus"),
        .description = COMPOUND_STRING("Powers up with Plus."),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("Forecast"),
        .description = COMPOUND_STRING("Changes with the weather."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("Sticky Hold"),
        .description = COMPOUND_STRING("Prevents item theft."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("Shed Skin"),
        .description = COMPOUND_STRING("Heals the body by shedding."),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("Guts"),
        .description = COMPOUND_STRING("Ups Attack if suffering."),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("Marvel Scale"),
        .description = COMPOUND_STRING("Ups Defense if suffering."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("Liquid Ooze"),
        .description = COMPOUND_STRING("Draining causes injury."),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("Overgrow"),
        .description = COMPOUND_STRING("Ups Grass moves in a pinch."),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("Blaze"),
        .description = COMPOUND_STRING("Ups Fire moves in a pinch."),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("Torrent"),
        .description = COMPOUND_STRING("Ups Water moves in a pinch."),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("Swarm"),
        .description = COMPOUND_STRING("Ups Bug moves in a pinch."),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("Rock Head"),
        .description = COMPOUND_STRING("Prevents recoil damage."),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("Drought"),
        .description = COMPOUND_STRING("Summons sunlight in battle."),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("Arena Trap"),
        .description = COMPOUND_STRING("Prevents fleeing."),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("Vital Spirit"),
        .description = COMPOUND_STRING("Prevents sleep."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("White Smoke"),
        .description = COMPOUND_STRING("Prevents ability reduction."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("Pure Power"),
        .description = COMPOUND_STRING("Raises Attack."),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("Shell Armor"),
        .description = COMPOUND_STRING("Blocks critical hits."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("Air Lock"),
        .description = COMPOUND_STRING("Negates weather effects."),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("Tangled Feet"),
        .description = COMPOUND_STRING("Ups evasion if confused."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("Motor Drive"),
        .description = COMPOUND_STRING("Electricity raises Speed."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("Rivalry"),
        .description = COMPOUND_STRING("Powers up against rivals."),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("Steadfast"),
        .description = COMPOUND_STRING("Flinching raises Speed."),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("Snow Cloak"),
        .description = COMPOUND_STRING("Ups evasion in Hail or Snow."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("Gluttony"),
        .description = COMPOUND_STRING("Eats Berries early."),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("Anger Point"),
        .description = COMPOUND_STRING("Critical hits raise Attack."),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("Unburden"),
        .description = COMPOUND_STRING("Using a hold item ups Speed."),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("Heatproof"),
        .description = COMPOUND_STRING("Heat and burn protection."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("Simple"),
        .description = COMPOUND_STRING("Prone to wild stat changes."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("Dry Skin"),
        .description = COMPOUND_STRING("Prefers moisture to heat."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("Download"),
        .description = COMPOUND_STRING("Adjusts power favorably."),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("Iron Fist"),
        .description = COMPOUND_STRING("Boosts punching moves."),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("Poison Heal"),
        .description = COMPOUND_STRING("Restores HP if poisoned."),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("Adaptability"),
        .description = COMPOUND_STRING("Boosts same type attacks."),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("Skill Link"),
        .description = COMPOUND_STRING("Multi-hit moves hit 5 times."),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("Hydration"),
        .description = COMPOUND_STRING("Cures status in rain."),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("Solar Power"),
        .description = COMPOUND_STRING("Powers up in sunshine."),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("Quick Feet"),
        .description = COMPOUND_STRING("Ups Speed if suffering."),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("Normalize"),
        .description = COMPOUND_STRING("Moves become Normal-type."),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("Sniper"),
        .description = COMPOUND_STRING("Boosts critical hits."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("Magic Guard"),
        .description = COMPOUND_STRING("Only damaged by attacks."),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("No Guard"),
        .description = COMPOUND_STRING("Ensures that all moves hit."),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("Stall"),
        .description = COMPOUND_STRING("Always moves last."),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("Technician"),
        .description = COMPOUND_STRING("Boosts weaker moves."),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("Leaf Guard"),
        .description = COMPOUND_STRING("Blocks status in sunshine."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("Mold Breaker"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("Super Luck"),
        .description = COMPOUND_STRING("Critical hits land often."),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("Aftermath"),
        .description = COMPOUND_STRING("Fainting damages the foe."),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("Anticipation"),
        .description = COMPOUND_STRING("Senses dangerous moves."),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("Forewarn"),
        .description = COMPOUND_STRING("Determines a foe's move."),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("Unaware"),
        .description = COMPOUND_STRING("Ignores stat changes."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("Tinted Lens"),
        .description = COMPOUND_STRING("Ups “not very effective”."),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("Filter"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("Scrappy"),
        .description = COMPOUND_STRING("Hits Ghost-type Pokémon."),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("Storm Drain"),
        .description = COMPOUND_STRING("Draws in Water moves."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("Ice Body"),
        .description = COMPOUND_STRING("HP recovery in Hail or Snow."),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("Solid Rock"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("Snow Warning"),
        .description = COMPOUND_STRING("Summons a Hailstorm."),
        .aiRating = 8,
    },

    [ABILITY_FRISK] =
    {
        .name = _("Frisk"),
        .description = COMPOUND_STRING("Checks a foe's item."),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("Reckless"),
        .description = COMPOUND_STRING("Boosts moves with recoil."),
        .aiRating = 6,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("Sheer Force"),
        .description = COMPOUND_STRING("Trades effects for power."),
        .aiRating = 8,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("Unnerve"),
        .description = COMPOUND_STRING("Foes can't eat Berries."),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("Defiant"),
        .description = COMPOUND_STRING("Lowered stats up Attack."),
        .aiRating = 5,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("Cursed Body"),
        .description = COMPOUND_STRING("Disables moves on contact."),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("Healer"),
        .description = COMPOUND_STRING("Heals partner Pokémon."),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("Friend Guard"),
        .description = COMPOUND_STRING("Lowers damage to partner."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("Weak Armor"),
        .description = COMPOUND_STRING("Its stats change when hit."),
        .aiRating = 2,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("Light Metal"),
        .description = COMPOUND_STRING("Halves weight."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("Multiscale"),
        .description = COMPOUND_STRING("Halves damage at full HP."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("Harvest"),
        .description = COMPOUND_STRING("May recycle a used Berry."),
        .aiRating = 5,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("Overcoat"),
        .description = COMPOUND_STRING("Blocks weather and powder."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("Poison Touch"),
        .description = COMPOUND_STRING("Poisons foe on contact."),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("Regenerator"),
        .description = COMPOUND_STRING("Heals upon switching out."),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("Big Pecks"),
        .description = COMPOUND_STRING("Prevents Defense loss."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("Sand Rush"),
        .description = COMPOUND_STRING("Ups Speed in a sandstorm."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("Wonder Skin"),
        .description = COMPOUND_STRING("May avoid status problems."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("Analytic"),
        .description = COMPOUND_STRING("Moving last boosts power."),
        .aiRating = 5,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("Imposter"),
        .description = COMPOUND_STRING("Transforms into the foe."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("Infiltrator"),
        .description = COMPOUND_STRING("Passes through barriers."),
        .aiRating = 6,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("Moxie"),
        .description = COMPOUND_STRING("KOs raise Attack."),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("Justified"),
        .description = COMPOUND_STRING("Dark hits raise Attack."),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("Rattled"),
        .description = COMPOUND_STRING("Raises Speed when scared."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("Magic Bounce"),
        .description = COMPOUND_STRING("Reflects status moves."),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("Sand Force"),
        .description = COMPOUND_STRING("Powers up in a sandstorm."),
        .aiRating = 4,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("Competitive"),
        .description = COMPOUND_STRING("Lowered stats up Sp. Atk."),
        .aiRating = 5,
    },
};
