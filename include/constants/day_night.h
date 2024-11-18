#ifndef GUARD_CONSTANTS_DAY_NIGHT_H
#define GUARD_CONSTANTS_DAY_NIGHT_H

#define HOUR_MORNING 6
#define HOUR_DAY 10
#define HOUR_NIGHT 20

// not real times of day but useful for specifying override times
#define HOUR_AFTERNOON 18
#define HOUR_MIDNIGHT_0 0
#define HOUR_MIDNIGHT_24 24

#define TIME_MORNING 0
#define TIME_DAY 1
#define TIME_NIGHT 2
#define TIMES_OF_DAY_COUNT 3

#define TINT_PERIODS_PER_HOUR 60
#define MINUTES_PER_TINT_PERIOD (60 / TINT_PERIODS_PER_HOUR)

#endif  // GUARD_CONSTANTS_DAY_NIGHT_H