#include "NutrimentGenerator.hpp"
#include "NutrimentA.hpp"
#include "NutrimentB.hpp"
#include "Application.hpp"
#include "Random/Random.hpp"
#include "Config.hpp"

using namespace std;

NutrimentGenerator::NutrimentGenerator()
: stopwatch(sf::Time::Zero)
{ }

void NutrimentGenerator::update(sf::Time dt){
    stopwatch += dt;
    Quantity quantityA(uniform(getShortConfig().nutrimentA_min_qty, getShortConfig().nutrimentA_max_qty));
    Quantity quantityB(uniform(getShortConfig().nutrimentB_min_qty, getShortConfig().nutrimentB_max_qty));
    Vec2d position(normal(getApp().getLabSize()[0]/2, (getApp().getLabSize()[0]/4)*(getApp().getLabSize()[0]/4)),
            normal(getApp().getLabSize()[1]/2, (getApp().getLabSize()[1]/4)*(getApp().getLabSize()[1]/4)));
    if(stopwatch > sf::seconds(getShortConfig().generator_nutriment_delay)){
        resetStopwatch();
        if(bernoulli(getAppConfig()["generator"]["nutriment"]["prob"].toDouble())){
           getAppEnv().addNutriment(new NutrimentA(quantityA, position));
        } else {
            getAppEnv().addNutriment(new NutrimentB(quantityB, position));
        }
    }
}

void NutrimentGenerator::resetStopwatch(){
    stopwatch = sf::Time::Zero;
}

NutrimentGenerator::~NutrimentGenerator(){

}
