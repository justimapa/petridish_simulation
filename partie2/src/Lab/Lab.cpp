#include "Lab.hpp"
#include "petridish.hpp"
#include "Nutriment.hpp"
#include <Application.hpp>

Lab::Lab()
    : dish(getApp().getCentre(),getApp().getLabSize().x*(0.95/2),
           getAppConfig()["petri dish"]["temperature"]["default"].toDouble())
{
  //Done.
}
double Lab::getTemperature()const{
    return dish.getTemperature();
}
void Lab::decreaseTemperature(){
    dish.decreaseTemperature();
}
void Lab::addNutriment(Nutriment* nutriment){
    dish.addNutriment(nutriment);
}
void Lab::drawOn(sf::RenderTarget& targetWindow)const{
    dish.drawOn(targetWindow);
}
bool Lab::update(sf::Time dt){
    dish.update(dt);
}
bool Lab::contains(const CircularBody& body){
    if(dish>body)return true;
    return false;
}
void Lab::reset(){
    dish.reset();
}

Lab::~Lab(){
    reset();
}
