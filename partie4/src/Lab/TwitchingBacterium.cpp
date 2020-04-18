#include "TwitchingBacterium.hpp"
#include "Application.hpp"
#include "Random/Random.hpp"
#include "Utility/Utility.hpp"

TwitchingBacterium::TwitchingBacterium(const Vec2d& position_)
: Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()),
  position_,
  Vec2d::fromRandomAngle(),
  uniform(getConfig()["radius"]["min"].toDouble(),getConfig()["radius"]["max"].toDouble()),
  getConfig()["color"]),
  grip(position_, getRadius()/4.0)
{
    addProperty("max tentacle length", MutableNumber::positive(getConfig()["tentacle"]["length"]));
    addProperty("tentacle speed", MutableNumber::positive(getConfig()["tentacle"]["speed"]));
}
void TwitchingBacterium::drawOn(sf::RenderTarget& targetWindow) const{
    auto line = buildLine(getPosition(), grip.getPosition(), getColor().get(), 1.0);
    auto border = buildAnnulus(grip.getPosition(),grip.getRadius(), getColor().get(), 1);
    targetWindow.draw(line);
    targetWindow.draw(border);
    Bacterium::drawOn(targetWindow);
}
void TwitchingBacterium::move(sf::Time dt){
    enum STATES{IDLE, WAIT_TO_DEPLOY, DEPLOY, ATTRACT, RETRACT, EAT};
    STATES initial(IDLE);
    switch(initial){
    case IDLE: {}
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
        double tentacle_speed(getProperty("tentacle speed").get());
        grip.move(getDirection()*tentacle_speed*dt.asSeconds());
        consumeEnergy(getTentacleEnergy().toDouble()*tentacle_speed*dt.asSeconds());
        if(getAppEnv().getNutrimentColliding(grip)){
        case ATTRACT: {
            if(!getAppEnv().getNutrimentColliding(*this)){
                Vec2d dir_tentacle((grip.getPosition()-getPosition())/distance(grip.getPosition(),getPosition()));
                CircularBody::move(getDirection()*
            }
        }
        }
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

