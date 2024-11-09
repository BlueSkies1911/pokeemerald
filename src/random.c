#include "global.h"
#include "random.h"

// IWRAM common
rng_value_t gRngValue;
rng_value_t gRng2Value;

EWRAM_DATA static u32 sRandCount = 0;

u16 Random(void)
{
    gRngValue = ISO_RANDOMIZE1(gRngValue);
    sRandCount++;
    return gRngValue >> 16;
}

void SeedRng(u16 seed)
{
    gRngValue = seed;
}

void SeedRng2(u16 seed)
{
    gRng2Value = seed;
}

u16 Random2(void)
{
    gRng2Value = ISO_RANDOMIZE1(gRng2Value);
    return gRng2Value >> 16;
}

#define LOOP_RANDOM_START
#define LOOP_RANDOM_END

#define LOOP_RANDOM (Random())

#define SHUFFLE_IMPL \
    u32 tmp; \
    LOOP_RANDOM_START; \
    --n; \
    while (n > 1) \
    { \
        int j = (LOOP_RANDOM * (n+1)) >> 16; \
        SWAP(data[n], data[j], tmp); \
        --n; \
    } \
    LOOP_RANDOM_END

void Shuffle8(void *data_, size_t n)
{
    u8 *data = data_;
    SHUFFLE_IMPL;
}

void Shuffle16(void *data_, size_t n)
{
    u16 *data = data_;
    SHUFFLE_IMPL;
}

void Shuffle32(void *data_, size_t n)
{
    u32 *data = data_;
    SHUFFLE_IMPL;
}

void ShuffleN(void *data, size_t n, size_t size)
{
    void *tmp = alloca(size);
    LOOP_RANDOM_START;
    --n;

    while (n > 1)
    {
        int j = (LOOP_RANDOM * (n+1)) >> 16;
        memcpy(tmp, (u8 *)data + n*size, size); // tmp = data[n];
        memcpy((u8 *)data + n*size, (u8 *)data + j*size, size); // data[n] = data[j];
        memcpy((u8 *)data + j*size, tmp, size); // data[j] = tmp;
        --n;
    }

    LOOP_RANDOM_END;
}

u32 RandomUniform(enum RandomTag tag, u32 lo, u32 hi)
{
    return lo + (((hi - lo + 1) * Random()) >> 16);
}

u32 RandomUniformExcept(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32))
{
    LOOP_RANDOM_START;
    while (TRUE)
    {
        u32 n = lo + (((hi - lo + 1) * LOOP_RANDOM) >> 16);
        if (!reject(n))
            return n;
    }
    LOOP_RANDOM_END;
}

u32 RandomWeightedArray(enum RandomTag tag, u32 sum, u32 n, const u8 *weights)
{
    s32 i, targetSum;
    targetSum = (sum * Random()) >> 16;
    for (i = 0; i < n - 1; i++)
    {
        targetSum -= weights[i];
        if (targetSum < 0)
            return i;
    }
    return n - 1;
}

const void *RandomElementArray(enum RandomTag tag, const void *array, size_t size, size_t count)
{
    return (const u8 *)array + size * RandomUniform(tag, 0, count - 1);
}
