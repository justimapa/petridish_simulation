#include "NutrimentA.hpp"
#include "Application.hpp"

using namespace std;

NutrimentA::NutrimentA(Quantity const& quantity,Vec2d const& position):
    Nutriment(quantity,position)
{
}

Quantity NutrimentA::eatenBy(Bacterium& bact) const{
    return bact.eatableQuantity(*this);
}

Quantity NutrimentA::eatenBy(SimpleBacterium& bact) const{
    return takeQuantity(bact.get)
}

j::Value const& NutrimentA::getConfig()const
{
    return getAppConfig()["nutriments"]["A"];
}
NutrimentA::~NutrimentA(){
}
