#include "Application.hpp"
#include "Lab.hpp"

Lab::Lab()
    : dish(getApp().getCentre(),getApp().getLabSize().x*(0.95/2),
           getAppConfig()["petri dish"]["temperature"]["default"].toDouble())
{ }

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
void Lab::addNutriment(Nutriment* nutriment)
{
    dish.addNutriment(nutriment);
}
void Lab::drawOn(sf::RenderTarget& targetWindow) const
{
    dish.drawOn(targetWindow);
}
bool Lab::update(sf::Time dt)
{
    dish.update(dt);
}
bool Lab::contains(const CircularBody& body)
{
    return (dish > body);
}
void Lab::reset(){
    dish.reset();
}
Lab::~Lab()
{
    reset();
}
