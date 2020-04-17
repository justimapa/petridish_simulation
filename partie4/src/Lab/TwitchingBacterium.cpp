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

