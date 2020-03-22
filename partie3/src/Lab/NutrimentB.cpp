#include "NutrimentB.h"

NutrimentB::NutrimentB(Quantity const& quantity,Vec2d const& position):
    Nutriment(quantity,position)
{
    //Done.
}

j::Value const& NutrimentB::getConfig()const
{
    return getAppConfig()["nutriements"]["B"];
}
