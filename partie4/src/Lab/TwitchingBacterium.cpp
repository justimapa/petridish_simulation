#include "TwitchingBacterium.hpp"
#include "Application.hpp"
#include "Random/Random.hpp"

TwitchingBacterium::TwitchingBacterium(const Vec2d& position_)
: Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()),
  position_,
  Vec2d::fromRandomAngle(),
  uniform(getConfig()["radius"]["min"].toDouble(),getConfig()["radius"]["max"].toDouble()),
  getConfig()["color"])
{
    addProperty("max tentacle length", MutableNumber::positive(getConfig()["tentacle"]["length"]));
    addProperty("tentacle speed", MutableNumber::positive(getConfig()["tentacle"]["speed"]));
}
void TwitchingBacterium::drawOn(sf::RenderTarget& targetWindow) const{
    Bacterium::drawOn(targetWindow);
}
void TwitchingBacterium::move(sf::Time dt){

}
Bacterium* TwitchingBacterium::clone(){

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
TwitchingBacterium::~TwitchingBacterium(){

}

