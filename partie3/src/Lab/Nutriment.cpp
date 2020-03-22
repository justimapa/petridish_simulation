#include "Nutriment.hpp"
#include <string>
#include "Application.hpp"
#include "Petridish.hpp"

using namespace std;

Nutriment::Nutriment(Quantity const& quantity,Vec2d const& position)
: CircularBody(position, quantity),
  quantity(quantity)
{ }
Quantity Nutriment::takeQuantity(Quantity quantity_)
{
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
void Nutriment::setQuantity(Quantity quantity_)
{
    if(quantity_ >= 0.0){
        quantity = quantity_;
    } else {
        quantity = 0.0;
    }
}
void Nutriment::drawOn(sf::RenderTarget& target) const
{
    if(not isDebugOn()){
    auto const& texture = getAppTexture(getConfig()["texture"].toString());
    auto nutrimentSprite = buildSprite(getPosition(),getRadius(), texture);
    nutrimentSprite.setScale(2 * getRadius() / texture.getSize().x, 2 * getRadius() /
                             texture.getSize().y);
    target.draw(nutrimentSprite);
    }else{
        string message="Qte : "+to_string((int)quantity);
        auto const text=buildText(message,getPosition(),getAppFont(),15,sf::Color::Black);
        auto border = buildAnnulus(getPosition(),getRadius(),sf::Color::Green,2);
        target.draw(text);
        target.draw(border);
    }
}
j::Value const& Nutriment::getConfig() const
{
    return getAppConfig()["nutriments"];
}
void Nutriment::update(sf::Time dt)
{
    if(isTemperatureOK() and isQuantityOK() ){
        auto growth = getConfig()["growth"]["speed"].toDouble() * dt.asSeconds();
        quantity+=growth;
        setRadius(quantity);
        if(not isContained()){
            quantity-=growth;
            setRadius(quantity);
        }
    }
}
bool Nutriment::isTemperatureOK() const
{
    return getAppEnv().getTemperature() >= getConfig()["growth"]["min temperature"].toDouble()
            and getAppEnv().getTemperature() <= getConfig()["growth"]["max temperature"].toDouble();
}
bool Nutriment::isQuantityOK() const
{
    return quantity <= 2 * getConfig()["quantity"]["max"].toDouble();
}
bool Nutriment::isContained() const
{
    return getAppEnv().contains(*this);
}
