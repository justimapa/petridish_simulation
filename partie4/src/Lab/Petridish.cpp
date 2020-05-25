#include "Petridish.hpp"
#include "Application.hpp"
#include <cmath>

using namespace std;

Petridish::Petridish(const Vec2d &position_, const double &radius_, const double &temperature_, const double &gradientExponent_)
    : CircularBody(position_,radius_),
      temperature(temperature_),
      gradientExponent(gradientExponent_)
{ }

bool Petridish::addBacterium(Bacterium* bacterium)
{
    if(bacterium!=nullptr) {
        if(*this > *bacterium) {
            bacteria.push_back(bacterium);
            return true;
        }
    }
    delete bacterium;
    return false;
}
bool Petridish::addNutriment(Nutriment* nutriment)
{
    if(nutriment!=nullptr) {
        if(*this > *nutriment) {
            nutriments.push_back(nutriment);
            return true;
        }
    }
    delete nutriment;
    return false;
}
bool Petridish::addSwarm(Swarm* swarm)
{
    if(swarm!=nullptr) {
        swarms.push_back(swarm);
        return true;
    }
    delete swarm;
    return false;
}

void Petridish::update(sf::Time dt)
{
    for(auto& swarm:swarms) {
        swarm->update(dt);
    }
    for(auto& nutriment : nutriments) {
        if(nutriment!=nullptr) {
            nutriment->update(dt);
        }
        if(nutriment->isDead()) {
            nutriment=nullptr;

        }
    }
    nutriments.erase(remove(nutriments.begin(),nutriments.end(),nullptr),nutriments.end());
    for(auto& bacterium:bacteria) {
        if(bacterium!=nullptr) {
            bacterium->update(dt);
        }
        if(bacterium->isDead()) {
            bacterium=nullptr;
        }
    }
    bacteria.erase(remove(bacteria.begin(),bacteria.end(),nullptr),bacteria.end());
}
void Petridish::drawOn(sf::RenderTarget& targetWindow) const
{
    auto border=buildAnnulus(getPosition(),getRadius(),sf::Color::Black,5);
    for(auto& nutriment : nutriments) {
        nutriment->drawOn(targetWindow);
    }
    for(auto& bacterium : bacteria) {
        bacterium->drawOn(targetWindow);
    }
    targetWindow.draw(border);
}

void Petridish::reset()
{
    for(auto& nutr: nutriments) {
        nutr = nullptr;
    }
    nutriments.erase(remove(nutriments.begin(),nutriments.end(),nullptr),nutriments.end());
    for(auto& bact : bacteria) {
        bact = nullptr;
    }
    bacteria.erase(remove(bacteria.begin(),bacteria.end(),nullptr),bacteria.end());
    resetGradientExponent();
    resetTemperature();
}
Petridish::~Petridish()
{
    reset();
}

double Petridish::getGradientExponent() const
{
    return gradientExponent;
}
void Petridish::decreaseGradientExponent()
{
    if(gradientExponent>getAppConfig()["petri dish"]["gradient"]["exponent"]["delta"].toDouble()) {
        gradientExponent-=getAppConfig()["petri dish"]["gradient"]["exponent"]["delta"].toDouble();

    }
}
void Petridish::increaseGradientExponent()
{
    gradientExponent+=getAppConfig()["petri dish"]["gradient"]["exponent"]["delta"].toDouble();
}
void Petridish::resetGradientExponent()
{
    gradientExponent=(getAppConfig()["petri dish"]["gradient"]["exponent"]["min"].toDouble()+getAppConfig()["petri dish"]["gradient"]["exponent"]["max"].toDouble())/2;
}

double Petridish::getTemperature() const
{
    return temperature;
}
void Petridish::decreaseTemperature()
{
    temperature-=getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}
void Petridish::increaseTemperature()
{
    temperature+=getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}
void Petridish::resetTemperature()
{
    temperature=getAppConfig()["petri dish"]["temperature"]["default"].toDouble();
}
Nutriment* Petridish::getNutrimentColliding(CircularBody const& body) const
{
    for(auto* nutriment:nutriments) {
        if((*nutriment)&body) {
            return nutriment;
        }
    }
    return nullptr;
}
double Petridish::getPositionScore(Vec2d const& position) const
{
    double score = 0.0;
    for(auto& nutriment:nutriments) {
        score+=(nutriment->getQuantity())/pow(distance(position,nutriment->getPosition()),gradientExponent);
    }
    return score;
}

Swarm* Petridish::getSwarmWithId(const string &id)const
{
    for(Swarm* swarm:swarms) {
        if(id==swarm->getId()) {
            return swarm;
        }
    }
    return nullptr;
}

