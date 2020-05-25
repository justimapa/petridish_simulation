#include "NutrimentB.hpp"
#include "Bacterium.hpp"
#include "SimpleBacterium.hpp"
#include "TwitchingBacterium.hpp"
#include "SwarmBacterium.hpp"
#include "Application.hpp"

using namespace std;

NutrimentB::NutrimentB(Quantity const& quantity,Vec2d const& position,int const& id):
    Nutriment(quantity,position,id)
{ }

Quantity NutrimentB::eatenBy(Bacterium& bact)
{
    return bact.eatableQuantity(*this);
}

Quantity NutrimentB::eatenBy(SimpleBacterium& bact)
{
    double factor(getResistanceFactor().toDouble());
    return takeQuantity(bact.getMaxEatableQuantity().toDouble()/factor);
}

Quantity NutrimentB::eatenBy(TwitchingBacterium& bact)
{
    return getNutritiveFactor().toDouble()*takeQuantity(bact.getMaxEatableQuantity().toDouble());
}

Quantity NutrimentB::eatenBy(SwarmBacterium& bact)
{
    return -getPoisonFactor().toDouble()*takeQuantity(bact.getMaxEatableQuantity().toDouble());
}

j::Value const& NutrimentB::getConfig() const
{
    return getAppConfig()["nutriments"]["B"];
}

j::Value const& NutrimentB::getResistanceFactor() const
{
    return getConfig()["resistance factor"];
}

j::Value const& NutrimentB::getNutritiveFactor() const
{
    return getConfig()["nutritive factor"];
}

j::Value const& NutrimentB::getPoisonFactor() const
{
    return getConfig()["poison factor"];
}
NutrimentB::~NutrimentB()
{
}
