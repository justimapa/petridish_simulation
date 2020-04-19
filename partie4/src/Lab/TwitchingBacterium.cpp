#include "TwitchingBacterium.hpp"
#include "Application.hpp"
#include "Random/Random.hpp"
#include "Utility/Utility.hpp"

using namespace std;

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
}
TwitchingBacterium::TwitchingBacterium(TwitchingBacterium & other)
:
    Bacterium(other),
    grip(other.grip),
    current_state(IDLE)
{
    CircularBody::move(Vec2d(5,5));
}
void TwitchingBacterium::drawOn(sf::RenderTarget& targetWindow) const{
    auto line = buildLine(getPosition(), grip.getPosition(), getColor().get(), 1.0);
    auto border = buildAnnulus(grip.getPosition(),grip.getRadius(), getColor().get(), 1);
    targetWindow.draw(line);
    targetWindow.draw(border);
    Bacterium::drawOn(targetWindow);
}
void TwitchingBacterium::update(sf::Time dt){
    Bacterium::update(dt);
    if(getAppEnv().getNutrimentColliding(grip)!=nullptr){
        current_state = ATTRACT;
        if(getAppEnv().getNutrimentColliding(*this)!=nullptr){
            current_state = EAT;
        }
    }
    if ((grip.getPosition()-getPosition()).length() >= getProperty("max tentacle length").get()){
            current_state = RETRACT;
    }
    if((grip.getPosition()-getPosition()).length() <= getRadius()){
                current_state = IDLE;
    }

}
void TwitchingBacterium::move(sf::Time dt){
    switch(current_state){
    case IDLE: {
    }
    case WAIT_TO_DEPLOY: {
        Vec2d nextDirection=Vec2d::fromRandomAngle();
        for(int i=0;i<20;++i){
            if(getAppEnv().getPositionScore(nextDirection+getPosition())>getAppEnv().getPositionScore(getDirection()+getPosition())){
                setDirection(nextDirection);
            }
            nextDirection=Vec2d::fromRandomAngle();
        }
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
        if(getAppEnv().getNutrimentColliding(*this)== nullptr){
            current_state = IDLE;
        }
    break;
    }
    }
}
Bacterium* TwitchingBacterium::clone(){
    if(getMinEnergyDivision()<=getEnergy()){
        Bacterium* new_Bact(new TwitchingBacterium(*this));
        mutation(new_Bact);
        return new_Bact;
    }
    return nullptr;
}
j::Value& TwitchingBacterium::getConfig() const{
    return getAppConfig()["twitching bacterium"];
}
j::Value& TwitchingBacterium::getMovementEnergy() const{
    return getEnergyConsumption()["move"];
}
j::Value& TwitchingBacterium::getTentacleEnergy() const{
    return getEnergyConsumption()["tentacle"];
}
void TwitchingBacterium::moveGrip(const Vec2d& delta){
    grip.move(delta);
}
TwitchingBacterium::~TwitchingBacterium(){

}

