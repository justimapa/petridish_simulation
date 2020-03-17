#include "petridish.hpp"
#include <vector>
#include <Application.hpp>

using namespace std;

Petridish::Petridish(Vec2d position,double radius, double Temperature)
: CircularBody(position,radius),
  temperature(Temperature)
{
    //Done.
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
bool Petridish::addBacterium(Bacterium*){
   //TO DO: add a bacteria in the dish if impossible return false
}
bool Petridish::addNutriment(Nutriment* nutriment_){
    if(contains(*nutriment_)){
        nutriment.push_back(nutriment_);
    }else{
        return false;
    }
    return true;
}
void Petridish::update(sf::Time dt){
        nutriment_->update(dt);
    }
}
void Petridish::drawOn(sf::RenderTarget& targetWindow) const
{
    auto border=buildAnnulus(getPosition(),getRadius(),sf::Color::Black,5);
    for(auto& nutriment_:nutriment){
        nutriment_->drawOn(targetWindow);
    }
    targetWindow.draw(border);
}
void Petridish::reset(){
    temperature=getAppConfig()["petri dish"]["temperature"]["default"].toDouble();
}
Petridish::~Petridish(){
    reset();
}


