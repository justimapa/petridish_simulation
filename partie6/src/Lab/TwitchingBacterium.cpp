#include "TwitchingBacterium.hpp"
#include "Nutriment.hpp"
#include "NutrimentA.hpp"
#include "NutrimentB.hpp"
#include "Application.hpp"
#include "Random/Random.hpp"
#include "Utility/Utility.hpp"

using namespace std;


std::map<int,int> TwitchingBacterium::twitchingCounterMap;
std::map<int,double> TwitchingBacterium::tentacleLengthMap;
std::map<int,double> TwitchingBacterium::tentacleSpeedMap;

TwitchingBacterium::TwitchingBacterium(const Vec2d& position_)
    : Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()),
                position_,
                Vec2d::fromRandomAngle(),
                uniform(getConfig()["radius"]["min"].toDouble(),getConfig()["radius"]["max"].toDouble()),
                getConfig()["color"]),
      grip(position_, getRadius()/4.0),
      current_state(IDLE)
{
    addProperty("max tentacle length", MutableNumber::positive(getConfig()["tentacle"]["length"]));
    addProperty("tentacle speed", MutableNumber::positive(getConfig()["tentacle"]["speed"]));
    addProperty("immunity", MutableNumber::probability(getConfig()["immunity"]));
    toggleImmunity();
    ++twitchingCounterMap[petridishId];
    tentacleLengthMap[petridishId]+=getProperty("max tentacle length").get();
    tentacleSpeedMap[petridishId]+=getProperty("tentacle speed").get();
    if(getImmunity()) {
        ++immuneCounter[petridishId];
    } else {
        ++vulnerableCounter[petridishId];
    }
}
TwitchingBacterium::TwitchingBacterium(TwitchingBacterium & other)
    :
    Bacterium(other),
    grip(other.grip),
    current_state(IDLE)
{
    CircularBody::move(Vec2d(10,10));
    ++twitchingCounterMap[petridishId];
    toggleImmunity();
    tentacleLengthMap[petridishId]+=getProperty("max tentacle length").get();
    tentacleSpeedMap[petridishId]+=getProperty("tentacle speed").get();
    if(getImmunity()) {
        ++immuneCounter[petridishId];
    } else {
        ++vulnerableCounter[petridishId];
    }
}
void TwitchingBacterium::drawOn(sf::RenderTarget& targetWindow) const
{
    auto line = buildLine(getPosition(), grip.getPosition(), getColor().get(), 1.0);
    auto border = buildAnnulus(grip.getPosition(),grip.getRadius(), getColor().get(), 1);
    targetWindow.draw(line);
    targetWindow.draw(border);
    Bacterium::drawOn(targetWindow);
}
void TwitchingBacterium::update(sf::Time dt)
{
    Bacterium::update(dt);
    if(getAppEnv().getNutrimentColliding(grip,petridishId)!=nullptr) {
        current_state = ATTRACT;
        if(getAppEnv().getNutrimentColliding(*this,petridishId)!=nullptr) {
            current_state = EAT;
        }
    }
    if ((grip.getPosition()-getPosition()).length() >= getProperty("max tentacle length").get() or getAppEnv().doesCollideWithDish(grip, petridishId)) {
        current_state = RETRACT;
    }
    if((grip.getPosition()-getPosition()).length() <= getRadius()) {
        current_state = IDLE;
    }

}
void TwitchingBacterium::move(sf::Time dt)
{
    switch(current_state) {
    case IDLE: {
        //Fallthrough
    }
    case WAIT_TO_DEPLOY: {
        Vec2d nextDirection=Vec2d::fromRandomAngle();
        for(int i=0; i<20; ++i) {
            if(getAppEnv().getPositionScore(nextDirection+getPosition(),petridishId)>getAppEnv().getPositionScore(getDirection()+getPosition(),petridishId)) {
                setDirection(nextDirection);
            }
            nextDirection=Vec2d::fromRandomAngle();
        }
        //Fallthrough
    }
    case DEPLOY: {
        grip.move(getDirection()*getProperty("tentacle speed").get()*dt.asSeconds());
        consumeEnergy(getTentacleEnergy().toDouble()*getProperty("tentacle speed").get()*dt.asSeconds());
        break;
    }
    case ATTRACT: {
        Vec2d dir_tentacle((grip.getPosition()-getPosition()).normalised());
        Vec2d distance(dir_tentacle*getProperty("tentacle speed").get()*(getConfig()["speed factor"].toDouble())*dt.asSeconds());
        CircularBody::move(distance);
        consumeEnergy(distance.length()*getMovementEnergy().toDouble());
        break;
    }
    case RETRACT: {
        Vec2d dir_tentacle((getPosition()-grip.getPosition()).normalised());
        grip.move(dir_tentacle*getProperty("tentacle speed").get()*dt.asSeconds());
        consumeEnergy(getTentacleEnergy().toDouble()*getProperty("tentacle speed").get()*dt.asSeconds());
        break;
    }
    case EAT: {
        if(getAppEnv().getNutrimentColliding(*this,petridishId) == nullptr) {
            current_state = IDLE;
        }
        break;
    }
    }
}
Bacterium* TwitchingBacterium::clone()
{
    Bacterium* new_Bact(new TwitchingBacterium(*this));
    return new_Bact;
}
Quantity TwitchingBacterium::eatableQuantity(NutrimentA& nutriment)
{
    return nutriment.eatenBy(*this);
}
Quantity TwitchingBacterium::eatableQuantity(NutrimentB& nutriment)
{
    return nutriment.eatenBy(*this);
}
j::Value& TwitchingBacterium::getConfig() const
{
    return getAppConfig()["twitching bacterium"];
}
j::Value& TwitchingBacterium::getMovementEnergy() const
{
    return getEnergyConsumption()["move"];
}
j::Value& TwitchingBacterium::getTentacleEnergy() const
{
    return getEnergyConsumption()["tentacle"];
}
void TwitchingBacterium::moveGrip(const Vec2d& delta)
{
    grip.move(delta);
}
TwitchingBacterium::~TwitchingBacterium()
{
    --twitchingCounterMap[petridishId];
    tentacleLengthMap[petridishId]-=getProperty("max tentacle length").get();
    tentacleSpeedMap[petridishId]-=getProperty("tentacle speed").get();

}

