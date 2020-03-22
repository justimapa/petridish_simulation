#include "Bacterium.hpp"
#include "Application.hpp"

using namespace std;

Bacterium::Bacterium(Quantity const& energy,Vec2d const& position,Vec2d const& direction,
                     double const& radius,MutableColor const& color):
    CircularBody(position,radius),
    energy(energy),
    direction(direction),
    color(color),
    abstinence(false)
{
 //Done.
}
Bacterium::Bacterium(Bacterium& other):
    CircularBody(other.getPosition(),other.getRadius()),
    energy(other.energy),
    direction(other.direction),
    color(other.color),
    abstinence(other.abstinence),
    mutations(other.mutations)
{
//Done.
}


    void Bacterium::drawOn(sf::RenderTarget& target) const{
        auto const circle= buildCircle(getPosition(),getRadius(),(sf::Color)(color["r"]["initial"].toDouble(),color["g"]["initial"].toDouble(),color["b"]["initial"].toDouble()));
        target.draw(circle);
        if(isDebugOn()){
            string message="Energy : "+to_string((int)energy);
            auto const text=buildText(message,getPosition(),getAppFont(),15,sf::Color::Black);
            target.draw(text);
        }
    }

    void Bacterium::update(sf::Time dt){
        delay+=dt;
        move(dt);
        if(getAppEnv().doesCollideWithDish((*this))){
            direction=-direction;
        }
        if(getAppEnv().getNutrimentColliding((*this))!=nullptr
                and not abstinence
                and delay<=getDelay()
                ){
            //Consumes energy of nutriment
        }
}
    void Bacterium::consumeEnergy(Quantity qt){
        energy-=qt;
    }
    bool Bacterium::isDead()const{
    return energy<=0;
}
    Quantity Bacterium::getMinEnergyDivision()const{
        return getConfig()["energy"]["division"].toDouble();
    }
    sf::Time Bacterium::getDelay()const{
        return sf::seconds(getConfig()["meal"]["delay"].toDouble());
    }
    Quantity Bacterium::getEnergyConsumption()const{
        return getConfig()["energy"]["consumption"].toDouble();
    }
    void Bacterium::reset(){
        delay=sf::Time::Zero;
    }
