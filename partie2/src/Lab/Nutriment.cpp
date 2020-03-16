#include "Nutriment.hpp"


Nutriment::Nutriment(Vec2d const& position, Quantity const& quantity)
: CircularBody(position, quantity),
  quantity(quantity){
    //Done.
}

Quantity Nutriment::takeQuantity(Quantity quantity_) const{
    if(quantity >= quantity_){
        return quantity_;
    } else {
        return quantity;
    }
}

void Nutriment::setQuantity(Quantity& quantity_){
    if(quantity_ >= 0.0){
        quantity = quantity_;
    } else {
        quantity = 0.0;
    }
}

void Nutriment::drawOn(sf::RenderTarget& target) const{
    auto nutrimentSprite = buildSprite(position, graphic_size, texture);
    nutrimentSprite.setScale(2 * radius / texture.getSize().x, 2 * radius /
                             texture.getSize().y);
    target.draw(nutrimentSprite);
}

j::Value const& Nutriment::getConfig() const{
    return getAppConfig()["nutriments"];
}
\
\

