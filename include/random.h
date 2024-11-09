#ifndef GUARD_RANDOM_H
#define GUARD_RANDOM_H

// The number 1103515245 comes from the example implementation of rand and srand
// in the ISO C standard.
#define ISO_RANDOMIZE1(val)(1103515245 * (val) + 24691)
#define ISO_RANDOMIZE2(val)(1103515245 * (val) + 12345)

typedef u32 rng_value_t;

#define RNG_VALUE_EMPTY 0

//Returns a 16-bit pseudorandom number
u16 Random(void);
u16 Random2(void);

//Sets the initial seed value of the pseudorandom number generator
void SeedRng(u16 seed);
void SeedRng2(u16 seed);

//Returns a 32-bit pseudorandom number
#define Random32() (Random() | (Random() << 16))

static inline u16 LocalRandom(rng_value_t *val)
{
    *val = ISO_RANDOMIZE1(*val);
    return *val >> 16;
}

extern rng_value_t gRngValue;
extern rng_value_t gRng2Value;

void Shuffle8(void *data, size_t n);
void Shuffle16(void *data, size_t n);
void Shuffle32(void *data, size_t n);
void ShuffleN(void *data, size_t n, size_t size);

static inline void Shuffle(void *data, size_t n, size_t size)
{
    switch (size)
    {
    case 1: Shuffle8(data, n); break;
    case 2: Shuffle16(data, n); break;
    case 4: Shuffle32(data, n); break;
    default: ShuffleN(data, n, size); break;
    }
}

/* Structured random number generator.
 * Instead of the caller converting bits from Random() to a meaningful
 * value, the caller provides metadata that is used to return the
 * meaningful value directly. This allows code to interpret the random
 * call, for example, battle tests know what the domain of a random call
 * is, and can exhaustively test it.
 *
 * RandomTag identifies the purpose of the value.
 *
 * RandomUniform(tag, lo, hi) returns a number from lo to hi inclusive
 * with uniform probability.
 *
 * RandomUniformExcept(tag, lo, hi, reject) returns a number from lo to
 * hi inclusive with uniform probability, excluding those for which
 * reject returns TRUE.
 *
 * RandomElement(tag, array) returns an element in array with uniform
 * probability. The array must be known at compile-time (e.g. a global
 * const array).
 *
 * RandomPercentage(tag, t) returns FALSE with probability (1-t)/100,
 * and TRUE with probability t/100.
 *
 * RandomWeighted(tag, w0, w1, ... wN) returns a number from 0 to N
 * inclusive. The return value is proportional to the weights, e.g.
 * RandomWeighted(..., 1, 1) returns 50% 0s and 50% 1s.
 * RandomWeighted(..., 2, 1) returns 2/3 0s and 1/3 1s. */

enum RandomTag
{
    RNG_ACCURACY,
    RNG_CONFUSION,
    RNG_CRITICAL_HIT,
    RNG_CUTE_CHARM,
    RNG_DAMAGE_MODIFIER,
    RNG_FLAME_BODY,
    RNG_FORCE_RANDOM_SWITCH,
    RNG_FROZEN,
    RNG_HITS,
    RNG_HOLD_EFFECT_FLINCH,
    RNG_INFATUATION,
    RNG_METRONOME,
    RNG_PARALYSIS,
    RNG_POISON_POINT,
    RNG_RAMPAGE_TURNS,
    RNG_SECONDARY_EFFECT,
    RNG_SLEEP_TURNS,
    RNG_STATIC,
    RNG_STENCH,
    RNG_TRI_ATTACK,
    RNG_QUICK_CLAW,
    RNG_TRACE,
};

#define RandomWeighted(tag, ...) \
    ({ \
        const u8 weights[] = { __VA_ARGS__ }; \
        u32 sum, i; \
        for (i = 0, sum = 0; i < ARRAY_COUNT(weights); i++) \
            sum += weights[i]; \
        RandomWeightedArray(tag, sum, ARRAY_COUNT(weights), weights); \
    })

#define RandomPercentage(tag, t) \
    ({ \
        u32 r; \
        if (t <= 0) \
        { \
            r = FALSE; \
        } \
        else if (t >= 100) \
        { \
            r = TRUE; \
        } \
        else \
        { \
          const u8 weights[] = { 100 - t, t }; \
          r = RandomWeightedArray(tag, 100, ARRAY_COUNT(weights), weights); \
        } \
        r; \
    })

#define RandomElement(tag, array) \
    ({ \
        *(typeof((array)[0]) *)RandomElementArray(tag, array, sizeof((array)[0]), ARRAY_COUNT(array)); \
    })

u32 RandomUniform(enum RandomTag, u32 lo, u32 hi);
u32 RandomUniformExcept(enum RandomTag, u32 lo, u32 hi, bool32 (*reject)(u32));
u32 RandomWeightedArray(enum RandomTag, u32 sum, u32 n, const u8 *weights);
const void *RandomElementArray(enum RandomTag, const void *array, size_t size, size_t count);

#endif // GUARD_RANDOM_H
