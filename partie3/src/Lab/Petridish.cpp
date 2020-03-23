#include "Petridish.hpp"
#include "Application.hpp"

using namespace std;

Petridish::Petridish(Vec2d position,double radius, double Temperature)
: CircularBody(position,radius),
  temperature(Temperature)
{ }

vector<Nutriment*> Petridish::getNutriments()const{
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
bool Petridish::addBacterium(Bacterium* bacterium){

    if(contains(*bacterium)){
        bacteria.push_back(bacterium);
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
        if(nutriment->isDead()){
            nutriment=nullptr;
        }
    }
    nutriments.erase(remove(nutriments.begin(),nutriments.end(),nullptr),nutriments.end());
    for(auto& bacterium:bacteria){
        bacterium->update(dt);
        if(bacterium->isDead()){
            bacterium=nullptr;
        }
    }
    bacteria.erase(remove(bacteria.begin(),bacteria.end(),nullptr),bacteria.end());
}
void Petridish::drawOn(sf::RenderTarget& targetWindow) const
{
    auto border=buildAnnulus(getPosition(),getRadius(),sf::Color::Black,5);
    for(auto& nutriment : nutriments){
        nutriment->drawOn(targetWindow);
    }
    for(auto& bacterium : bacteria){
        bacterium->drawOn(targetWindow);

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


