#include "Application.hpp"
#include "SwarmBacterium.hpp"
#include "TwitchingBacterium.hpp"
#include "SimpleBacterium.hpp"
#include "Lab.hpp"

Lab::Lab():
    currentDishId(0)
{
}
void Lab::drawOn(sf::RenderTarget& targetWindow) const{
    getCurrentPetridish()->drawOn(targetWindow);
}
void Lab::update(sf::Time dt){
    generator.update(dt);
    getCurrentPetridish()->update(dt);

}
bool Lab::contains(const CircularBody& body) const{
    return ((*getCurrentPetridish()) > body);
}
void Lab::reset(){
    getCurrentPetridish()->reset();
    generator.resetStopwatch();
}
Lab::~Lab(){
    for(auto& dish:dishes){
        (dish.second)->reset();
    }
    generator.resetStopwatch();
}
Nutriment* Lab::getNutrimentColliding(CircularBody const& body) const{
    return getCurrentPetridish()->getNutrimentColliding(body);
}
Bacterium* Lab::getBacteriumColliding(CircularBody const& body)const{
    return getCurrentPetridish()->getBacteriumColliding(body);
}
double Lab::getPositionScore(Vec2d const& position) const{
    return getCurrentPetridish()->getPositionScore(position);
}
double Lab::getBacteriaScore(Vec2d const& position)const{
    return getCurrentPetridish()->getBacteriaScore(position);
}
double Lab::getGradientExponent() const{
    return getCurrentPetridish()->getGradientExponent();
}
void Lab::decreaseGradientExponent(){
    getCurrentPetridish()->decreaseGradientExponent();

}
void Lab::increaseGradientExponent(){
        getCurrentPetridish()->increaseGradientExponent();

}
double Lab::getTemperature() const{
    return getCurrentPetridish()->getTemperature();

}
void Lab::decreaseTemperature(){
    getCurrentPetridish()->decreaseTemperature();
}
void Lab::increaseTemperature(){
    getCurrentPetridish()->increaseTemperature();
}
void Lab::refreshConfig(){

    getCurrentPetridish()->resetTemperature();
    getCurrentPetridish()->resetGradientExponent();

}
void Lab::addBacterium(Bacterium* bact){
    getCurrentPetridish()->addBacterium(bact);
}
void Lab::addPhage(Bacteriophage* phage){
    getCurrentPetridish()->addPhage(phage);
}
void Lab::addNutriment(Nutriment* nutriment){
    getCurrentPetridish()->addNutriment(nutriment);
}
Swarm* Lab::getSwarmWithId(const std::string& id)const{
    return getCurrentPetridish()->getSwarmWithId(id);

}
void Lab::addSwarm(Swarm* swarm){
        getCurrentPetridish()->addSwarm(swarm);
}
bool Lab::doesCollideWithDish(CircularBody const& body) const{
    (((*getCurrentPetridish())&body) and not ((*getCurrentPetridish())>body.getPosition()));
}
std::unordered_map<std::string, double> Lab::fetchData(const std::string & str) const{
   std::unordered_map<std::string,double> mymap;
   //Draws the stats corresponding to the current Petridish
   if(str==s::GENERAL){
       mymap[s::SIMPLE_BACTERIA]=SimpleBacterium::simpleCounterMap[getCurrentPetridishId()];
       mymap[s::TWITCHING_BACTERIA]=TwitchingBacterium::twitchingCounterMap[getCurrentPetridishId()];
       mymap[s::SWARM_BACTERIA]=SwarmBacterium::swarmCounterMap[getCurrentPetridishId()];
       mymap[s::BACTERIOPHAGES]=Bacteriophage::phageCounterMap[getCurrentPetridishId()];
       mymap[s::NUTRIMENT_SOURCES]=Nutriment::nutrimentCounterMap[getCurrentPetridishId()];
       mymap[s::DISH_TEMPERATURE]=getCurrentPetridish()->getTemperature();
   }
   if(str==s::NUTRIMENT_QUANTITY){
       mymap[s::NUTRIMENT_QUANTITY]=Nutriment::quantityCounterMap[getCurrentPetridishId()];
   }
   if(str==s::SIMPLE_BACTERIA){
       mymap[s::BETTER]=SimpleBacterium::betterMap[getCurrentPetridishId()]/SimpleBacterium::simpleCounterMap[getCurrentPetridishId()];
       mymap[s::WORSE]=SimpleBacterium::worseMap[getCurrentPetridishId()]/SimpleBacterium::simpleCounterMap[getCurrentPetridishId()];
   }
   if(str==s::TWITCHING_BACTERIA){
       mymap[s::TENTACLE_LENGTH]=TwitchingBacterium::tentacleLengthMap[getCurrentPetridishId()]/TwitchingBacterium::twitchingCounterMap[getCurrentPetridishId()];
       mymap[s::TENTACLE_SPEED]=TwitchingBacterium::tentacleSpeedMap[getCurrentPetridishId()]/TwitchingBacterium::twitchingCounterMap[getCurrentPetridishId()];
   }
   if(str==s::BACTERIA){
       mymap[s::SPEED]=Bacterium::speedMap[getCurrentPetridishId()]/double(SimpleBacterium::simpleCounterMap[getCurrentPetridishId()]+SwarmBacterium::swarmCounterMap[getCurrentPetridishId()]);
   }
   return mymap;

}
//The following methods were added for the multiple petridish extension
void Lab::setCurrentDishId(int id){
    currentDishId=id;
}
int Lab::getCurrentPetridishId()const{
    return currentDishId;
}
Petridish* Lab::getCurrentPetridish()const{
    try{
        auto paire=dishes.find(currentDishId);
        return (paire->second);
    }catch(std::out_of_range){
        std::cerr<<"Out of range"<<std::endl;
    }catch(std::invalid_argument){
        std::cerr<<"Invalid_argument"<<std::endl;
    }
}
void Lab::nextPetridish(){
    currentDishId=(++currentDishId)%dishes.size();

}
void Lab::previousPetridish(){
    currentDishId=(--currentDishId)%dishes.size();
}
void Lab::addPetridish(int id){
    dishes[id]=(new Petridish(getApp().getCentre(), getApp().getLabSize().x*(0.95/2),
                             getAppConfig()["petri dish"]["temperature"]["default"].toDouble(),
                        (getAppConfig()["petri dish"]["gradient"]["exponent"]["min"].toDouble()+getAppConfig()["petri dish"]["gradient"]["exponent"]["max"].toDouble())/2));
}
