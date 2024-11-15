#ifndef GUARD_CONSTANTS_WEATHER_H
#define GUARD_CONSTANTS_WEATHER_H

#define WEATHER_NONE                    0
#define WEATHER_SUNNY_CLOUDS            1
#define WEATHER_SUNNY                   2
#define WEATHER_RAIN                    3
#define WEATHER_SNOW                    4   // Unused
#define WEATHER_RAIN_THUNDERSTORM       5
#define WEATHER_FOG_HORIZONTAL          6
#define WEATHER_VOLCANIC_ASH            7
#define WEATHER_SANDSTORM               8
#define WEATHER_FOG_DIAGONAL            9   // Unused
#define WEATHER_UNDERWATER              10  // Unused
#define WEATHER_SHADE                   11  // Original name was closer to WEATHER_CLOUDY/OVERCAST
#define WEATHER_DROUGHT                 12
#define WEATHER_DOWNPOUR                13
#define WEATHER_UNDERWATER_BUBBLES      14
#define WEATHER_ABNORMAL                15  // The alternating weather during Groudon/Kyogre conflict
#define WEATHER_ROUTE119_CYCLE          20
#define WEATHER_ROUTE123_CYCLE          21

// These are used in maps' coord_weather_event entries.
// They are not a one-to-one mapping with the engine's
// internal weather constants above.
#define COORD_EVENT_WEATHER_SUNNY_CLOUDS        1
#define COORD_EVENT_WEATHER_SUNNY               2
#define COORD_EVENT_WEATHER_RAIN                3
#define COORD_EVENT_WEATHER_SNOW                4
#define COORD_EVENT_WEATHER_RAIN_THUNDERSTORM   5
#define COORD_EVENT_WEATHER_FOG_HORIZONTAL      6
#define COORD_EVENT_WEATHER_FOG_DIAGONAL        7
#define COORD_EVENT_WEATHER_VOLCANIC_ASH        8
#define COORD_EVENT_WEATHER_SANDSTORM           9
#define COORD_EVENT_WEATHER_SHADE               10
#define COORD_EVENT_WEATHER_DROUGHT             11
#define COORD_EVENT_WEATHER_ROUTE119_CYCLE      20
#define COORD_EVENT_WEATHER_ROUTE123_CYCLE      21

#endif // GUARD_CONSTANTS_WEATHER_H
