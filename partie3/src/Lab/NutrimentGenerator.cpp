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
           getAppEnv().addNutriment(
                       new NutrimentA (uniform(getShortConfig().nutrimentA_min_qty,
                                     getShortConfig().nutrimentA_max_qty),
                             Vec2d(normal(getApp().getLabSize()[0]/2, (getApp().getLabSize()[0]/4)*(getApp().getLabSize()[0]/4)),
                             normal(getApp().getLabSize()[1]/2, (getApp().getLabSize()[1]/4)*(getApp().getLabSize()[1]/4)))));
        } else {
            getAppEnv().addNutriment(new NutrimentB (uniform(getShortConfig().nutrimentB_min_qty,
                          getShortConfig().nutrimentB_max_qty),
                  Vec2d(normal(getApp().getLabSize()[0]/2, (getApp().getLabSize()[0]/4)*(getApp().getLabSize()[0]/4)),
                  normal(getApp().getLabSize()[1]/2, (getApp().getLabSize()[1]/4)*(getApp().getLabSize()[1]/4)))));
        }
    }
}

void NutrimentGenerator::reset()
{
    stopwatch = sf::Time::Zero;
}
