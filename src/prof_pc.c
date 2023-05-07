#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "strings.h"

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetHoennPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetHoennPokedexCount(FLAG_GET_CAUGHT);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    }

    return IsNationalPokedexEnabled();
}

// This shows your Hoenn Pokedex rating and not your National Dex.
const u8 *GetPokedexRatingText(u16 count)
{
    if (count < 10)
        return gPokedexRating_Text_LessThan10;
    if (count < 20)
        return gPokedexRating_Text_LessThan20;
    if (count < 30)
        return gPokedexRating_Text_LessThan30;
    if (count < 40)
        return gPokedexRating_Text_LessThan40;
    if (count < 50)
        return gPokedexRating_Text_LessThan50;
    if (count < 60)
        return gPokedexRating_Text_LessThan60;
    if (count < 70)
        return gPokedexRating_Text_LessThan70;
    if (count < 80)
        return gPokedexRating_Text_LessThan80;
    if (count < 90)
        return gPokedexRating_Text_LessThan90;
    if (count < 100)
        return gPokedexRating_Text_LessThan100;
    if (count < 110)
        return gPokedexRating_Text_LessThan110;
    if (count < 120)
        return gPokedexRating_Text_LessThan120;
    if (count < 130)
        return gPokedexRating_Text_LessThan130;
    if (count < 140)
        return gPokedexRating_Text_LessThan140;
    if (count < 150)
        return gPokedexRating_Text_LessThan150;
    
    if (count == HOENN_DEX_COUNT - 1)
    {
        if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_MEW), FLAG_GET_CAUGHT)) // Mew is not counted towards the dex completion. If the flag is enabled, it means the actual count is less than 150.
            return gPokedexRating_Text_LessThan150;
        return gPokedexRating_Text_Complete;
    }
    if (count == HOENN_DEX_COUNT)
        return gPokedexRating_Text_Complete;
    return gPokedexRating_Text_LessThan10;
}

void ShowPokedexRatingMessage(void)
{
    ShowFieldMessage(GetPokedexRatingText(gSpecialVar_0x8004));
}
