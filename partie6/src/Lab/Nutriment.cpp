#include "Nutriment.hpp"
#include "Bacterium.hpp"
#include "SimpleBacterium.hpp"
#include "TwitchingBacterium.hpp"
#include "SwarmBacterium.hpp"
#include <string>
#include "Application.hpp"
#include "Petridish.hpp"

using namespace std;

std::map<int,int> Nutriment::nutrimentCounterMap;
std::map<int,Quantity> Nutriment::quantityCounterMap;

Nutriment::Nutriment(Quantity const& quantity_,Vec2d const& position_)
: CircularBody(position_, quantity_),
  quantity(quantity_)
{
    ++nutrimentCounterMap[getAppEnv().getCurrentPetridishId()];
    quantityCounterMap[getAppEnv().getCurrentPetridishId()]+=quantity;
}

Quantity Nutriment::takeQuantity(Quantity quantity_){
    Quantity initial_quantity(quantity);
    setQuantity(quantity - quantity_);
    quantityCounterMap[getAppEnv().getCurrentPetridishId()]-=(initial_quantity-getQuantity());
    return initial_quantity-getQuantity();
}
void Nutriment::setQuantity(Quantity quantity_){
    if(quantity_ >= 0.0){
        quantity = quantity_;
    } else {
        quantity = 0.0;
    }
    setRadius(quantity);
}
Quantity Nutriment::getQuantity() const{
    return quantity;
}
void Nutriment::drawOn(sf::RenderTarget& target) const{

    auto const& texture = getAppTexture(getConfig()["texture"].toString());
    auto nutrimentSprite = buildSprite(getPosition(),6,texture);
    nutrimentSprite.setScale(2 * getRadius() / texture.getSize().x,
                             2 * getRadius() / texture.getSize().y);
    target.draw(nutrimentSprite);
    if(isDebugOn()){
        string message="Qte : " + to_string((int)quantity);
        Vec2d textposition(getPosition()[0], getPosition()[1]+getRadius());
        auto const text=buildText(message,textposition,getAppFont(),15,sf::Color::Black);
        target.draw(text);
    }
}
void Nutriment::update(sf::Time dt){
    if(isTemperatureOK() and isQuantityOK()){
        auto growth = getConfig()["growth"]["speed"].toDouble() * dt.asSeconds();
        quantity+=growth;
        quantityCounterMap[getAppEnv().getCurrentPetridishId()]+=growth;
        setRadius(quantity);
        if(not isContained()){
            quantity-=growth;
            quantityCounterMap[getAppEnv().getCurrentPetridishId()]-=growth;
            setRadius(quantity);
        }
    }
}
bool Nutriment::isTemperatureOK() const{
    return getAppEnv().getTemperature() >= getConfig()["growth"]["min temperature"].toDouble()
            and getAppEnv().getTemperature() <= getConfig()["growth"]["max temperature"].toDouble();
}
bool Nutriment::isQuantityOK() const{
    return quantity <= 2 * getConfig()["quantity"]["max"].toDouble();
}
bool Nutriment::isContained() const{
    return getAppEnv().contains(*this);
}
bool Nutriment::isDead()const{
    return quantity<=0;
}
Nutriment::~Nutriment(){
    --nutrimentCounterMap[getAppEnv().getCurrentPetridishId()];
    quantityCounterMap[getAppEnv().getCurrentPetridishId()]-=quantity;
}

