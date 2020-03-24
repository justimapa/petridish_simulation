#include "NutrimentB.hpp"
#include "Application.hpp"

using namespace std;

NutrimentB::NutrimentB(Quantity const& quantity,Vec2d const& position):
    Nutriment(quantity,position)
{
}

j::Value const& NutrimentB::getConfig() const
{
    return getAppConfig()["nutriments"]["B"];
}

NutrimentB::~NutrimentB(){
}
