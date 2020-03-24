#include "NutrimentA.hpp"
#include "Application.hpp"

using namespace std;

NutrimentA::NutrimentA(Quantity const& quantity,Vec2d const& position):
    Nutriment(quantity,position)
{
}


j::Value const& NutrimentA::getConfig()const
{
    return getAppConfig()["nutriments"]["A"];
}
NutrimentA::~NutrimentA(){
    cerr<<"You dead nutriment A"<<endl;
}
