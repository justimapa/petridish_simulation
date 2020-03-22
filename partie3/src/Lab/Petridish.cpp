#include "Petridish.hpp"
#include "Application.hpp"

using namespace std;

Petridish::Petridish(Vec2d position,double radius, double Temperature)
: CircularBody(position,radius),
  temperature(Temperature)
{ }

vector<Nutriment*>& getNutriments()const{
    return nutriments;
}
double Petridish::getTemperature() const
{
    return temperature;
}
void Petridish::decreaseTemperature(){
    temperature-=getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}
void Petridish::increaseTemperature(){
    temperature+=getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}
bool Petridish::addBacterium(Bacterium* bacteria){
    if(contains(*bacteria)){
        bacterium.push_back(bacteria);
    }else{
        return false;
    }
    return true;
}
bool Petridish::addNutriment(Nutriment* nutriment){
    if(contains(*nutriment)){
        nutriments.push_back(nutriment);
    } else {
        return false;
    }
    return true;
}
void Petridish::update(sf::Time dt){
    for(auto& nutriment : nutriments){
        nutriment->update(dt);
    }
    for(auto& bacterium:bacteria){
        bacterium->update(dt);
    }
}
void Petridish::drawOn(sf::RenderTarget& targetWindow) const
{
    auto border=buildAnnulus(getPosition(),getRadius(),sf::Color::Black,5);
    for(auto& nutriment_ : nutriments){
        nutriment_->drawOn(targetWindow);
    }
    targetWindow.draw(border);
}
void Petridish::resetTemperature(){
    temperature=getAppConfig()["petri dish"]["temperature"]["default"].toDouble();
}
void Petridish::reset(){
    nutriments.clear();
    for(auto* nutr: nutriments){
        delete nutr;
    }
    bacteria.clear();
    for(auto* bact : bacteria){
        delete bact;
    }
    resetTemperature();
}
Petridish::~Petridish(){
    reset();
}


