#include "NutrimentA.hpp"

NutrimentA::NutrimentA(Quantity const& quantity,Vec2d const& position):
    Nutriment(quantity,position)
{
    //Done.
}

j::Value const& NutrimentA::getConfig()const
{
    return getAppConfig()["nutriements"]["A"];
}
