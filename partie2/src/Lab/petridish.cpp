#include "petridish.hpp"
#include <vector>
#include <Application.hpp>

using namespace std;

Petridish::Petridish(Vec2d position,double radius, double Temperature)
: CircularBody(position,radius),
  Temperature(Temperature)
{
    //Done.
}

double Petridish::getTemperature() const{
    return Temperature;
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
    //updates bacterias
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
    //resets dish to zero
}
Petridish::~Petridish(){
    reset();
}


