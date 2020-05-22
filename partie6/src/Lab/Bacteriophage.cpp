#include "Bacteriophage.hpp"
#include "Application.hpp"
#include "Random/Random.hpp"

Bacteriophage::Bacteriophage(Vec2d const& position, double const& radius, Vec2d const& direction)
: CircularBody(position, radius),
  direction(direction),
  color(sf::Color::Yellow),
  status("LYTIC"),
  delay(sf::Time::Zero)
{

}

void Bacteriophage::drawOn(sf::RenderTarget &target) const{
    auto const circle = buildCircle(getPosition(), getRadius(), color);
    target.draw(circle);
    if(isDebugOn()){
        Vec2d textposition(getPosition()[0], getPosition()[1]+getRadius());
        std::string message;
        if(status=="LYTIC"){
            message = "Status : Lytic";
        } else {
            message = "Status : Lysogenic";
        }
        auto const text = buildText(message, textposition, getAppFont(), 15, sf::Color::Red);
        target.draw(text);
    }
}

void Bacteriophage::update(sf::Time dt){
   delay+=dt;
   move(dt);
   infect();
   if(delay >= sf::seconds(5.0)){
       statusSwap();
       resetDelay();
   }
   if(getAppEnv().doesCollideWithDish((*this))){
       direction=-direction;
   }
}

void Bacteriophage::move(sf::Time dt){
    Vec2d movement = stepDiffEq(getPosition(), getSpeedVector(), dt, (*this), DiffEqAlgorithm::EC).position - getPosition();
    if(movement.lengthSquared()>0.001){
        (*this).CircularBody::move(movement);
    }
    aim(dt);
}

void Bacteriophage::aim(sf::Time dt){
    setDirection(Vec2d::fromRandomAngle());
    Vec2d nextDirection = Vec2d::fromRandomAngle();
    for(int i=0; i<20; ++i){
        if(getAppEnv().getBacteriaScore(nextDirection+getPosition())>getAppEnv().getBacteriaScore(getDirection()+getPosition())){
            setDirection(nextDirection);
        }
        nextDirection=Vec2d::fromRandomAngle();
    }
}

void Bacteriophage::infect() const{
    if(getAppEnv().getBacteriumColliding(*this) != nullptr and status == "LYTIC"){
        (*getAppEnv().getBacteriumColliding(*this)).consumeEnergy(20);
    }
    if(getAppEnv().getBacteriumColliding(*this) != nullptr and status == "LYSOGENIC"){
        (*getAppEnv().getBacteriumColliding(*this)).setAbstinence(true);
    }
}

void Bacteriophage::statusSwap(){
    if(bernoulli(0.5)){
        if(status=="LYTIC"){
            status = "LYSOGENIC";
            return;
        }
        if(status=="LYSOGENIC"){
            status = "LYTIC";
        }
    }
}

Vec2d Bacteriophage::getSpeedVector() const{
    return getDirection()*20;
}

Vec2d Bacteriophage::f(Vec2d position, Vec2d direction) const{
    return Vec2d(0,0);
}

Vec2d Bacteriophage::getDirection() const{
    return direction;
}

void Bacteriophage::setDirection(const Vec2d& direction_){
    direction=direction_;
}

void Bacteriophage::resetDelay(){
    delay=sf::Time::Zero;
}

Bacteriophage::~Bacteriophage(){

}
