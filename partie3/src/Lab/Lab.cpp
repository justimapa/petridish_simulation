#include "Application.hpp"
#include "Lab.hpp"

Lab::Lab()
    : dish(getApp().getCentre(), getApp().getLabSize().x*(0.95/2),
           getAppConfig()["petri dish"]["temperature"]["default"].toDouble(),
      getAppConfig()["petri dish"]["gradient"]["exponent"]["min"].toDouble()+getAppConfig()["petri dish"]["gradient"]["exponent"]["max"].toDouble()/2)
{ }
void Lab::drawOn(sf::RenderTarget& targetWindow) const{
    dish.drawOn(targetWindow);
}
void Lab::update(sf::Time dt){
    generator.update(dt);
    dish.update(dt);
}
bool Lab::contains(const CircularBody& body) const{
    return (dish > body);
}
void Lab::reset(){
    dish.reset();
    generator.reset();
}
Lab::~Lab(){
    reset();
}
Nutriment* Lab::getNutrimentColliding(CircularBody const& body)const{
    return dish.getNutrimentColliding(body);
}
double Lab::getPositionScore(Vec2d const& position)const{
    return dish.getPositionScore(position);
}
double Lab::getGradientExponent() const{
    return dish.getGradientExponent();
}
void Lab::decreaseGradientExponent(){
    dish.decreaseGradientExponent();
}
void Lab::increaseGradientExponent(){
    dish.increaseGradientExponent();
}
double Lab::getTemperature() const{
    return dish.getTemperature();
}
void Lab::decreaseTemperature(){
    dish.decreaseTemperature();
}
void Lab::increaseTemperature(){
    dish.increaseTemperature();
}
void Lab::refreshConfig(){
    dish.resetTemperature();
    dish.resetGradientExponent();
}
void Lab::addBacterium(Bacterium* bact){
    dish.addBacterium(bact);
}
void Lab::addNutriment(Nutriment* nutriment){
    dish.addNutriment(nutriment);
}
bool Lab::doesCollideWithDish(CircularBody const& body){
    return ((dish&body) and not (dish>body));
}
