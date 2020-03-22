#include "Application.hpp"
#include "Lab.hpp"

Lab::Lab()
    : dish(getApp().getCentre(),getApp().getLabSize().x*(0.95/2),
           getAppConfig()["petri dish"]["temperature"]["default"].toDouble())
{ }
Nutriment* Lab::getNutrimentColliding(CircularBody const& body)const{
    for(auto& nutriment:dish.getNutriments()){
        if(*nutriment&body){
            return nutriment;
        }
    }
    return nullptr;
}
double Lab::getTemperature() const
{
    return dish.getTemperature();
}
void Lab::decreaseTemperature()
{
    dish.decreaseTemperature();
}
void Lab::increaseTemperature()
{
    dish.increaseTemperature();
}
void Lab::refreshConfig(){
    dish.resetTemperature();
}

void Lab::addBacterium(Bacterium* bact){
    dish.addBacterium(bact);
}

void Lab::addNutriment(Nutriment* nutriment)
{
    dish.addNutriment(nutriment);
}
bool Lab::doesCollideWithDish(const CircularBody & body){
    return dish&body;
}
void Lab::drawOn(sf::RenderTarget& targetWindow) const
{
    dish.drawOn(targetWindow);
}
bool Lab::update(sf::Time dt)
{
    dish.update(dt);
    generator.update(dt);
}
bool Lab::contains(const CircularBody& body)
{
    return (dish > body);
}
void Lab::reset(){
    dish.reset();
    generator.reset();
}
Lab::~Lab()
{
    reset();
}
