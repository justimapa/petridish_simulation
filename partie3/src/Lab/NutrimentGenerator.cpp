#include "NutrimentGenerator.hpp"
#include "Application.hpp"
#include "Random/Random.hpp"
#include "Config.hpp"

using namespace std;

NutrimentGenerator::NutrimentGenerator()
: stopwatch(sf::Time::Zero)
{ }

void NutrimentGenerator::update(sf::Time dt)
{
    stopwatch += dt;
    if(stopwatch > sf::seconds(getAppConfig()["generator"]["nutriment"]["delay"].toDouble())){
        reset();
        if(bernoulli(getAppConfig()["generator"]["nutriment"]["prob"].toDouble())){
           cerr<< "Entered generator update" << endl;
           NutrimentA to_add(uniform(getShortConfig().nutrimentA_min_qty,
                                     getShortConfig().nutrimentA_max_qty),
                             normal(getApp().getLabSize()/2, getApp().getLabSize()/4));
           NutrimentA* nutrA_to_add(&to_add);
           getAppEnv().addNutriment(nutrA_to_add);
        } else {
            NutrimentB to_add(uniform(getShortConfig().nutrimentB_min_qty,
                                      getShortConfig().nutrimentB_max_qty),
                              normal(getApp().getLabSize()/2, getApp().getLabSize()/4));
            NutrimentB* nutrB_to_add(&to_add);
            getAppEnv().addNutriment(nutrB_to_add);
        }
    }
}

void NutrimentGenerator::reset()
{
    stopwatch = sf::Time::Zero;
}
