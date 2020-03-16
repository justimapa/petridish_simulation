#include "Nutriment.hpp"
#include <SFML/Graphics.hpp>
#include "CircularBody.hpp"
#include <Utility/Types.hpp>
#include "Utility/Vec2d.hpp"
#include "Application.hpp"
#include "petridish.hpp"
#include <string>
using namespace std;


Nutriment::Nutriment(Quantity const& quantity,Vec2d const& position)
: CircularBody(position, quantity),
  quantity(quantity)
{
    //Done.
}



Quantity Nutriment::takeQuantity(Quantity quantity_){
    Quantity quantity_taken(quantity_);
    if(quantity >= quantity_){
        quantity -= quantity_;
        setRadius(quantity);
        return quantity_taken;
    } else {
        quantity_taken = quantity;
        quantity = 0.0;
        setRadius(0.0);
        return quantity_taken;
    }
}

void Nutriment::setQuantity(Quantity quantity_){
    if(quantity_ >= 0.0){
        quantity = quantity_;
    } else {
        quantity = 0.0;
    }
}

void Nutriment::drawOn(sf::RenderTarget& target) const{
    auto const& texture = getAppTexture(getConfig()["texture"].toString());
    auto nutrimentSprite = buildSprite(getPosition(), 6, texture);
    nutrimentSprite.setScale(2 * getRadius() / texture.getSize().x, 2 * getRadius() /
                             texture.getSize().y);
    target.draw(nutrimentSprite);
    if(isDebugOn()){

        string message="Qte : "+to_string(quantity);
        auto const text=buildText(message,getPosition(),getAppFont(),15,sf::Color::Black);
        target.draw(text);
    }
}

j::Value const& Nutriment::getConfig() const{
    return getAppConfig()["nutriments"];
}

void Nutriment::update(sf::Time dt) const{
    if(getAppEnv().dish.getTemperature() >= getConfig()["growth"]["min temperature"].toDouble()
       and getAppEnv().dish.getTemperature() <= getConfig()["growth"]["max temperature"].toDouble()
       and quantity <= 2 * getConfig()["quantity"]["max"].toDouble()
       and getAppEnv().contains(*this)){
        auto growth = getConfig()["growth"]["speed"].toDouble() * dt.asSeconds();
    }
}
