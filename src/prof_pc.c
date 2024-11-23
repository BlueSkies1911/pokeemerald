#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "strings.h"

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetKantoPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetKantoPokedexCount(FLAG_GET_CAUGHT);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    }

    return IsNationalPokedexEnabled();
}

#define OAK_DEX_STRINGS 16

static const u8 *const sOakDexRatingTexts[OAK_DEX_STRINGS] =
{
    gPokedexRating_Text_LessThan10,
    gPokedexRating_Text_LessThan20,
    gPokedexRating_Text_LessThan30,
    gPokedexRating_Text_LessThan40,
    gPokedexRating_Text_LessThan50,
    gPokedexRating_Text_LessThan60,
    gPokedexRating_Text_LessThan70,
    gPokedexRating_Text_LessThan80,
    gPokedexRating_Text_LessThan90,
    gPokedexRating_Text_LessThan100,
    gPokedexRating_Text_LessThan110,
    gPokedexRating_Text_LessThan120,
    gPokedexRating_Text_LessThan130,
    gPokedexRating_Text_LessThan140,
    gPokedexRating_Text_LessThan150,
    gPokedexRating_Text_Complete,
};

// This shows your Kanto Pokédex rating and not your National Dex.
const u8 *GetPokedexRatingText(u32 count)
{
    return sOakDexRatingTexts[(count * (OAK_DEX_STRINGS - 1)) / KANTO_DEX_COUNT];
}

void ShowPokedexRatingMessage(void)
{
    ShowFieldMessage(GetPokedexRatingText(gSpecialVar_0x8004));
}
