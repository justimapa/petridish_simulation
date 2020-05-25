#include "Application.hpp"
#include "SwarmBacterium.hpp"
#include "TwitchingBacterium.hpp"
#include "SimpleBacterium.hpp"
#include "Lab.hpp"

Lab::Lab():
    currentDishId(0)
{
}
void Lab::drawOn(sf::RenderTarget& targetWindow) const
{
    getCurrentPetridish()->drawOn(targetWindow);
}
void Lab::update(sf::Time dt)
{
    for(auto& generator:generators) {
        (generator.second)->update(dt);
    }
    for(auto& dish:dishes) {
        (dish.second)->update(dt);
    }

}
bool Lab::contains(const CircularBody& body,int const& id) const
{
    return ((*getPetridishwithId(id)) > body);
}


Nutriment* Lab::getNutrimentColliding(CircularBody const& body, int const& id) const
{
    return getPetridishwithId(id)->getNutrimentColliding(body);
}
Bacterium* Lab::getBacteriumColliding(CircularBody const& body, int const& id)const
{
    return getPetridishwithId(id)->getBacteriumColliding(body);
}
double Lab::getPositionScore(Vec2d const& position,int const& id) const
{
    return getPetridishwithId(id)->getPositionScore(position);
}
double Lab::getBacteriaScore(Vec2d const& position,int const& id)const
{
    return getPetridishwithId(id)->getBacteriaScore(position);
}
double Lab::getGradientExponent() const
{
    return getCurrentPetridish()->getGradientExponent();
}
void Lab::decreaseGradientExponent()
{
    getCurrentPetridish()->decreaseGradientExponent();

}
void Lab::increaseGradientExponent()
{
    getCurrentPetridish()->increaseGradientExponent();

}
double Lab::getTemperature() const
{
    return getCurrentPetridish()->getTemperature();

}
void Lab::decreaseTemperature()
{
    getCurrentPetridish()->decreaseTemperature();
}
void Lab::increaseTemperature()
{
    getCurrentPetridish()->increaseTemperature();
}
void Lab::refreshConfig()
{

    getCurrentPetridish()->resetTemperature();
    getCurrentPetridish()->resetGradientExponent();

}
void Lab::addBacterium(Bacterium* bact, const int &id)
{
    getPetridishwithId(id)->addBacterium(bact);
}
void Lab::addPhage(Bacteriophage* phage, const int &id)
{
    getPetridishwithId(id)->addPhage(phage);
}
void Lab::addNutriment(Nutriment* nutriment, const int &id)
{
    getPetridishwithId(id)->addNutriment(nutriment);
}
Swarm* Lab::getSwarmWithId(const std::string& id)const
{
    return getCurrentPetridish()->getSwarmWithId(id);

}
void Lab::addSwarm(Swarm* swarm)
{
    getCurrentPetridish()->addSwarm(swarm);
}
bool Lab::doesCollideWithDish(CircularBody const& body, const int &id) const
{
    return (((*getCurrentPetridish())&body) and not ((*getCurrentPetridish())>body.getPosition()));
}

std::unordered_map<std::string, double> Lab::fetchData(const std::string & str) const
{
    std::unordered_map<std::string,double> mymap;
    //Draws the stats corresponding to the current Petridish
    if(str==s::GENERAL) {
        mymap[s::SIMPLE_BACTERIA]=SimpleBacterium::simpleCounterMap[getCurrentPetridishId()];
        mymap[s::TWITCHING_BACTERIA]=TwitchingBacterium::twitchingCounterMap[getCurrentPetridishId()];
        mymap[s::SWARM_BACTERIA]=SwarmBacterium::swarmCounterMap[getCurrentPetridishId()];
        mymap[s::NUTRIMENT_SOURCES]=Nutriment::nutrimentCounterMap[getCurrentPetridishId()];
        mymap[s::DISH_TEMPERATURE]=getCurrentPetridish()->getTemperature();
    }
    if(str==s::NUTRIMENT_QUANTITY) {
        mymap[s::NUTRIMENT_QUANTITY]=Nutriment::quantityCounterMap[getCurrentPetridishId()];
    }
    if(str==s::SIMPLE_BACTERIA) {
        mymap[s::BETTER]=SimpleBacterium::betterMap[getCurrentPetridishId()]/SimpleBacterium::simpleCounterMap[getCurrentPetridishId()];
        mymap[s::WORSE]=SimpleBacterium::worseMap[getCurrentPetridishId()]/SimpleBacterium::simpleCounterMap[getCurrentPetridishId()];
    }
    if(str==s::TWITCHING_BACTERIA) {
        mymap[s::TENTACLE_LENGTH]=TwitchingBacterium::tentacleLengthMap[getCurrentPetridishId()]/TwitchingBacterium::twitchingCounterMap[getCurrentPetridishId()];
        mymap[s::TENTACLE_SPEED]=TwitchingBacterium::tentacleSpeedMap[getCurrentPetridishId()]/TwitchingBacterium::twitchingCounterMap[getCurrentPetridishId()];
    }
    if(str==s::BACTERIA) {
        mymap[s::SPEED]=Bacterium::speedMap[getCurrentPetridishId()]/double(SimpleBacterium::simpleCounterMap[getCurrentPetridishId()]+SwarmBacterium::swarmCounterMap[getCurrentPetridishId()]);
    }
    if(str==s::IMMUNE) {
        mymap[s::TOTAL_IMMUNE]=Bacterium::immuneCounter[getCurrentPetridishId()];
        mymap[s::TOTAL_VULNERABLE]=Bacterium::vulnerableCounter[getCurrentPetridishId()];
        mymap[s::BACTERIOPHAGES]=Bacteriophage::phageCounterMap[getCurrentPetridishId()];
    }
    return mymap;

}
//The following methods were added for the multiple petridish extension
void Lab::setCurrentDishId(int id)
{
    currentDishId=id;
}
int Lab::getCurrentPetridishId()const
{
    return currentDishId;
}
Petridish* Lab::getCurrentPetridish()const
{
    try {
        auto paire=dishes.find(currentDishId);
        return (paire->second);
    } catch(std::out_of_range) {
        std::cerr<<"Out of range"<<std::endl;
    } catch(std::invalid_argument) {
        std::cerr<<"Invalid_argument"<<std::endl;
    }
}

Petridish* Lab::getPetridishwithId(int const& id)const
{
    try {
        auto paire=dishes.find(id);
        return (paire->second);
    } catch(std::out_of_range) {
        std::cerr<<"Out of range"<<std::endl;
    } catch(std::invalid_argument) {
        std::cerr<<"Invalid_argument"<<std::endl;
    }
}
void Lab::nextPetridish()
{
    currentDishId=(++currentDishId)%dishes.size();

}
void Lab::previousPetridish()
{
    currentDishId=(--currentDishId)%dishes.size();
}
void Lab::addPetridish(int id)
{
    generators[id]=(new NutrimentGenerator(id));
    dishes[id]=(new Petridish(getApp().getCentre(), getApp().getLabSize().x*(0.95/2),
                              getAppConfig()["petri dish"]["temperature"]["default"].toDouble(),
                              (getAppConfig()["petri dish"]["gradient"]["exponent"]["min"].toDouble()+getAppConfig()["petri dish"]["gradient"]["exponent"]["max"].toDouble())/2));
}

void Lab::reset()
{
    getCurrentPetridish()->reset();
    generators[getCurrentPetridishId()]->resetStopwatch();
}
Lab::~Lab()
{
    for(auto& dish:dishes) {
        (dish.second)->reset();
    }
    reset();
}
