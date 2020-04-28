#include "Application.hpp"
#include "SwarmBacterium.hpp"
#include "TwitchingBacterium.hpp"
#include "SimpleBacterium.hpp"
#include "Lab.hpp"

Lab::Lab()
    : dish(getApp().getCentre(), getApp().getLabSize().x*(0.95/2),
           getAppConfig()["petri dish"]["temperature"]["default"].toDouble(),
      (getAppConfig()["petri dish"]["gradient"]["exponent"]["min"].toDouble()+getAppConfig()["petri dish"]["gradient"]["exponent"]["max"].toDouble())/2)
{ }
void Lab::drawOn(sf::RenderTarget& targetWindow) const{
    dish.drawOn(targetWindow);
}
void Lab::update(sf::Time dt){
    generator.update(dt);
    dish.update(dt);
}
bool Lab::contains(const CircularBody& body) const{
    return (dish > body);
}
void Lab::reset(){
    dish.reset();
    generator.resetStopwatch();
}
Lab::~Lab(){
    reset();
}
Nutriment* Lab::getNutrimentColliding(CircularBody const& body) const{
    return dish.getNutrimentColliding(body);
}
double Lab::getPositionScore(Vec2d const& position) const{
    return dish.getPositionScore(position);
}
double Lab::getGradientExponent() const{
    return dish.getGradientExponent();
}
void Lab::decreaseGradientExponent(){
    dish.decreaseGradientExponent();
}
void Lab::increaseGradientExponent(){
    dish.increaseGradientExponent();
}
double Lab::getTemperature() const{
    return dish.getTemperature();
}
void Lab::decreaseTemperature(){
    dish.decreaseTemperature();
}
void Lab::increaseTemperature(){
    dish.increaseTemperature();
}
void Lab::refreshConfig(){
    dish.resetTemperature();
    dish.resetGradientExponent();
}
void Lab::addBacterium(Bacterium* bact){
    dish.addBacterium(bact);
}
void Lab::addNutriment(Nutriment* nutriment){
    dish.addNutriment(nutriment);
}
Swarm* Lab::getSwarmWithId(const std::string& id)const{
    return dish.getSwarmWithId(id);
}
void Lab::addSwarm(Swarm* swarm){
    dish.addSwarm(swarm);
}
bool Lab::doesCollideWithDish(CircularBody const& body) const{
    return ((dish&body) and not (dish>body.getPosition()));
}
std::unordered_map<std::string, double> Lab::fetchData(const std::string & str){
   std::unordered_map<std::string,double> mymap;
   if(str==s::GENERAL){
       mymap[s::SIMPLE_BACTERIA]=SimpleBacterium::counter;
       mymap[s::TWITCHING_BACTERIA]=TwitchingBacterium::counter;
       mymap[s::SWARM_BACTERIA]=SwarmBacterium::counter;
       mymap[s::NUTRIMENT_SOURCES]=Nutriment::counter;
       mymap[s::DISH_TEMPERATURE]=dish.getTemperature();
   }
   if(str==s::NUTRIMENT_QUANTITY){
       mymap[s::NUTRIMENT_QUANTITY]=Nutriment::quantitycounter;
   }
   if(str==s::SIMPLE_BACTERIA){
       mymap[s::BETTER]=SimpleBacterium::better/SimpleBacterium::counter;
       mymap[s::WORSE]=SimpleBacterium::worse/SimpleBacterium::counter;
   }
   if(str==s::TWITCHING_BACTERIA){
       mymap[s::TENTACLE_LENGTH]=TwitchingBacterium::tentacle_length_tot/TwitchingBacterium::counter;
       mymap[s::TENTACLE_SPEED]=TwitchingBacterium::tentacle_speed_tot/TwitchingBacterium::counter;
   }
   if(str==s::BACTERIA){
       mymap[s::SPEED]=Bacterium::speed_tot/(SimpleBacterium::counter+SwarmBacterium::counter);
   }
   return mymap;

}
