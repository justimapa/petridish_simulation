#include "Bacterium.hpp"
#include "Application.hpp"
#include <cmath>
using namespace std;

Bacterium::Bacterium(Quantity const& energy,Vec2d const& position,Vec2d const& direction,
                     double const& radius,MutableColor const& color):
    CircularBody(position,radius),
    energy(energy),
    direction(direction),
    color(color),
    abstinence(false)
{ }
Bacterium::Bacterium(Bacterium& other):
    CircularBody(other.getPosition(),other.getRadius()),
    energy(other.energy/2),
    direction(-other.direction),
    color(other.color),
    abstinence(other.abstinence),
    mutations(other.mutations)
{
    other.energy=energy;
}
void Bacterium::drawOn(sf::RenderTarget& target) const{
    auto const circle = buildCircle(getPosition(),getRadius(),color.get());
    target.draw(circle);
    //drawFlagella(target);
    if(isDebugOn()){
        string message="Energy : "+to_string((int)energy);
        Vec2d textposition(getPosition()[0], getPosition()[1]+getRadius());
        auto const text=buildText(message, textposition, getAppFont(), 15, sf::Color::Red);
        target.draw(text);
    }
}
void Bacterium::update(sf::Time dt){
    delay+=dt;
    move(dt);
    if(getAppEnv().doesCollideWithDish((*this))){
        direction=-direction;
    }
    double max_consumption(getConfig()["meal"]["max"].toDouble());
    if((getAppEnv().getNutrimentColliding((*this))!=nullptr)
        and (not abstinence) and (delay>=getDelay())){
        energy+=getAppEnv().getNutrimentColliding((*this))->takeQuantity(max_consumption);
        if(getMinEnergyDivision()<=energy){
            getAppEnv().addBacterium(clone());
        }
        reset();
    }
}
void Bacterium::consumeEnergy(Quantity qt){
    energy-=qt;
}
bool Bacterium::isDead() const{
    return energy <= 0.0;
}
void Bacterium::setEnergy(Quantity const& energy_){
    energy=energy_;
}
Quantity Bacterium::getEnergy() const{
    return energy;
}
Quantity Bacterium::getMinEnergyDivision() const{
    return getConfig()["energy"]["division"].toDouble();
}
sf::Time Bacterium::getDelay() const{
    return sf::seconds(getConfig()["meal"]["delay"].toDouble());
}
Quantity Bacterium::getEnergyConsumption() const{
    return getConfig()["energy"]["consumption factor"].toDouble();
}
Vec2d Bacterium::getDirection() const{
    return direction;
}
void Bacterium::setDirection(const Vec2d& direction_){
    direction=direction_;
}
MutableColor Bacterium::getColor() const{
    return color;
}
void Bacterium::addProperty(const string& key,const MutableNumber& value){
    mutations[key] = value;
}
MutableNumber Bacterium::getProperty(const string& key){
    try{
        auto paire=mutations.find(key);
        return  paire->second;
    }catch(std::out_of_range){
        cerr<<"Out of range"<<endl;
    }catch(std::invalid_argument){
        cerr<<"Invalid_argument"<<endl;
    }
}
void Bacterium::mutation(Bacterium*){
    color.mutate();
    for(auto& mutation:mutations){
        (mutation.second).mutate();
    }
}
void Bacterium::reset(){
    delay=sf::Time::Zero;
}
Bacterium::~Bacterium(){
}
