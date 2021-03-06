#include "SwarmBacterium.hpp"
#include "Swarm.hpp"
#include "Nutriment.hpp"
#include "NutrimentA.hpp"
#include "NutrimentB.hpp"
#include "Random/Random.hpp"
#include "Application.hpp"
#include "Lab.hpp"

std::map<int,int> SwarmBacterium::swarmCounterMap;

SwarmBacterium::SwarmBacterium(const Vec2d& position, Swarm* group)
    : Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()),
                position,
                Vec2d::fromRandomAngle(),
                uniform(getConfig()["radius"]["min"].toDouble(),getConfig()["radius"]["max"].toDouble()),
                group->getInitialColor()),
      swarm(group)
{
    swarm->addSwarmBacterium(this);
    addProperty("immunity", MutableNumber::probability(getConfig()["immunity"]));
    toggleImmunity();
    ++swarmCounterMap[petridishId];
    speedMap[petridishId]+=getConfig()["speed"]["initial"].toDouble();
    if(getImmunity()) {
        ++immuneCounter[petridishId];
    } else {
        ++vulnerableCounter[petridishId];
    }
}
SwarmBacterium::SwarmBacterium(SwarmBacterium & other)
    : Bacterium(other),
      swarm(other.swarm)
{
    swarm->addSwarmBacterium(this);
    ++swarmCounterMap[getAppEnv().getCurrentPetridishId()];
    toggleImmunity();
    speedMap[getAppEnv().getCurrentPetridishId()]+=getConfig()["speed"]["initial"].toDouble();
    if(getImmunity()) {
        ++immuneCounter[petridishId];
    } else {
        ++vulnerableCounter[petridishId];
    }
}
Vec2d SwarmBacterium::getSpeedVector() const
{
    return getDirection()*(getConfig()["speed"]["initial"].toDouble());
}

void SwarmBacterium::move(sf::Time dt)
{
    Vec2d movement = stepDiffEq(getPosition(),getSpeedVector(),dt,(*this),DiffEqAlgorithm::EC).position - getPosition();
    if(movement.lengthSquared()>0.001) {
        (*this).CircularBody::move(movement);
        consumeEnergy((movement).length()*getEnergyConsumption().toDouble());
    }
    if(swarm->isLeader(this) or not swarm->hasLeader()) {
        tumble();
    }
}
void SwarmBacterium::tumble()
{
    setDirection(Vec2d::fromRandomAngle());
    Vec2d nextDirection=Vec2d::fromRandomAngle();
    for(int i=0; i<20; ++i) {
        if(getAppEnv().getPositionScore(nextDirection+getPosition(),petridishId)>getAppEnv().getPositionScore(getDirection()+getPosition(),petridishId)) {
            setDirection(nextDirection);
        }
        nextDirection=Vec2d::fromRandomAngle();
    }
}
void SwarmBacterium::drawOn(sf::RenderTarget & targetWindow) const
{
    Bacterium::drawOn(targetWindow);
    if(isDebugOn() and swarm->isLeader(this)) {
        auto border=buildAnnulus(getPosition(),getRadius()+10,sf::Color::Red,2);
        targetWindow.draw(border);
    }
}

Bacterium* SwarmBacterium::clone()
{
    Bacterium* new_Bact(new SwarmBacterium(*this));
    return new_Bact;
}
Quantity SwarmBacterium::eatableQuantity(NutrimentA& nutriment)
{
    return nutriment.eatenBy(*this);
}
Quantity SwarmBacterium::eatableQuantity(NutrimentB& nutriment)
{
    return nutriment.eatenBy(*this);
}
Vec2d SwarmBacterium::f(Vec2d position, Vec2d) const
{
    if(swarm->hasLeader()) {
        return getAppConfig()["swarms"][swarm->getId()]["force factor"].toDouble()*(swarm->getLeaderPosition()-position);
    }
    return Vec2d(0,0);
}
j::Value& SwarmBacterium::getConfig( )const
{
    return getAppConfig()["swarm bacterium"];
}
SwarmBacterium::~SwarmBacterium()
{
    speedMap[petridishId]-=getConfig()["speed"]["initial"].toDouble();
    --swarmCounterMap[petridishId];
}
