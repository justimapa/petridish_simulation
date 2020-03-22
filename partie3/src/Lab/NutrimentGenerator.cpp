#include "NutrimentGenerator.hpp"
#include "Application.hpp"
#include "Random/Random.hpp"
#include "Config.hpp"

NutrimentGenerator::NutrimentGenerator()
: stopwatch(sf::Time::Zero)
{ }

void NutrimentGenerator::update(sf::Time dt)
{
    stopwatch += dt;
    if(stopwatch >= sf::seconds(getAppConfig()["generator"]["nutriment"]["delay"].toDouble())){
        reset();
        if(bernoulli(getAppConfig()["generator"]["nutriment"]["prob"].toDouble())){
           NutrimentA* nutrA_to_add(new Nutr);
           nutrA_to_add->setPosition(normal(getApp().getLabSize()/2, getApp().getLabSize()/4));
           nutrA_to_add->setQuantity(uniform(getShortConfig().nutrimentA_min_qty,
                                           getShortConfig().nutrimentA_max_qty));
           getAppEnv().addNutriment(nutrA_to_add);
        } else {
            NutrimentB* nutrB_to_add;
            nutrB_to_add->setPosition(normal(getApp().getLabSize()/2, getApp().getLabSize()/4));
            nutrB_to_add->setQuantity(uniform(getShortConfig().nutrimentB_min_qty,
                                             getShortConfig().nutrimentB_max_qty));
            getAppEnv().addNutriment(nutrB_to_add);
        }
    }
}

void NutrimentGenerator::reset()
{
    stopwatch = sf::Time::Zero;
}
