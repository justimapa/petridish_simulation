#include "Petridish.hpp"
#include "Application.hpp"
#include <cmath>

using namespace std;

Petridish::Petridish(Vec2d position_,double radius_, double temperature_,double gradientExponent_)
: CircularBody(position_,radius_),
  temperature(temperature_),
  gradientExponent(gradientExponent_)
{ }

bool Petridish::addBacterium(Bacterium* bacterium){
    if(bacterium!=nullptr){
        if(*this > *bacterium){
            bacteria.push_back(bacterium);
            return true;
        }
    }
    return false;
}
bool Petridish::addNutriment(Nutriment* nutriment){
    if(nutriment!=nullptr){
        if(*this > *nutriment){
            nutriments.push_back(nutriment);
            return true;
        }
    }
    return false;
}

void Petridish::update(sf::Time dt){
    for(auto& nutriment : nutriments){
        nutriment->update(dt);
        if(nutriment->isDead()){
            delete nutriment;
            nutriment=nullptr;
        }
    }
    nutriments.erase(remove(nutriments.begin(),nutriments.end(),nullptr),nutriments.end());
    for(auto& bacterium:bacteria){
        bacterium->update(dt);
        if(bacterium->isDead()){
            delete bacterium;
            bacterium=nullptr;
        }
    }
    bacteria.erase(remove(bacteria.begin(),bacteria.end(),nullptr),bacteria.end());
}
void Petridish::drawOn(sf::RenderTarget& targetWindow) const{
    auto border=buildAnnulus(getPosition(),getRadius(),sf::Color::Black,5);
    for(auto nutriment : nutriments){
        nutriment->drawOn(targetWindow);
    }
    for(auto& bacterium : bacteria){
        bacterium->drawOn(targetWindow);
    }
    targetWindow.draw(border);
}

void Petridish::reset(){
    for(auto* nutr: nutriments){
        delete nutr;
    }
    nutriments.clear();
    for(auto* bact : bacteria){
        delete bact;
    }
    bacteria.clear();
    resetGradientExponent();
    resetTemperature();
}
Petridish::~Petridish(){
    reset();
}

double Petridish::getGradientExponent() const{
    return gradientExponent;
}
void Petridish::decreaseGradientExponent(){
    cerr<<gradientExponent<<endl;
    gradientExponent-=getAppConfig()["petri dish"]["gradient"]["exponent"]["delta"].toDouble();
}
void Petridish::increaseGradientExponent(){
    gradientExponent+=getAppConfig()["petri dish"]["gradient"]["exponent"]["delta"].toDouble();
}
void Petridish::resetGradientExponent(){
    gradientExponent=getAppConfig()["petri dish"]["gradient"]["exponent"]["min"].toDouble()+getAppConfig()["petri dish"]["gradient"]["exponent"]["max"].toDouble()/2;
}

double Petridish::getTemperature() const{
    return temperature;
}
void Petridish::decreaseTemperature(){
    temperature-=getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}
void Petridish::increaseTemperature(){
    temperature+=getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}
void Petridish::resetTemperature(){
    temperature=getAppConfig()["petri dish"]["temperature"]["default"].toDouble();
}
Nutriment* Petridish::getNutrimentColliding(CircularBody const& body) const{
    for(auto& nutriment:nutriments){
        if((*nutriment)&body){
            return nutriment;
        }
    }
    return nullptr;
}
double Petridish::getPositionScore(Vec2d const& position) const{
    double score=0;
    for(auto& nutriment:nutriments){
        score+=(nutriment->getQuantity())/pow(distance(position,nutriment->getPosition()),gradientExponent);
    }
    return score;
}


