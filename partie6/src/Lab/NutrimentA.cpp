#include "NutrimentA.hpp"
#include "Bacterium.hpp"
#include "SimpleBacterium.hpp"
#include "TwitchingBacterium.hpp"
#include "SwarmBacterium.hpp"
#include "Application.hpp"


NutrimentA::NutrimentA(Quantity const& quantity,Vec2d const& position,int const& id):
    Nutriment(quantity,position,id)
{
}

Quantity NutrimentA::eatenBy(Bacterium& bact){
    return bact.eatableQuantity(*this);
}

Quantity NutrimentA::eatenBy(SimpleBacterium& bact){
    return takeQuantity(bact.getMaxEatableQuantity().toDouble());
}

Quantity NutrimentA::eatenBy(TwitchingBacterium& bact){
    return takeQuantity(bact.getMaxEatableQuantity().toDouble());
}

Quantity NutrimentA::eatenBy(SwarmBacterium& bact){
    return takeQuantity(bact.getMaxEatableQuantity().toDouble());
}

j::Value const& NutrimentA::getConfig() const
{
    return getAppConfig()["nutriments"]["A"];
}
NutrimentA::~NutrimentA(){
}
