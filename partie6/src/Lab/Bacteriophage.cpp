/*#include "Bacteriophage.hpp"
#include "Application.hpp"

Bacteriophage::Bacteriophage(Vec2d const& position, double const& radius, Vec2d const& direction)
: CircularBody(position, radius),
  direction(direction),
  color(sf::Color::Yellow),
  status("LYTIC"),
  delay(sf::Time::Zero)
{

}

void Bacteriophage::drawOn(sf::RenderTarget& target) const{
    auto const circle = buildCircle(getPosition(), getRadius(), color);
    target.draw(circle);
    if(isDebugOn()){
        Vec2d textposition(getPosition()[0], getPosition()[1]+getRadius());
        std::string message;
        if(status == "Lytic") {
            message = "Status : Lytic";
        }else{
            message = "Status : Lysogenic";
        }
        auto const text = buildText(message, textposition, getAppFont(), 15, sf::Color::Red);
        target.draw(text);
    }
}

void Bacteriophage::update(sf::Time dt){
    delay+=dt;
    move(dt);
    if(getAppEnv().doesCollideWithDish(*this)){
        direction=-direction;
    }
    resetDelay();
}

void Bacteriophage::move(sf::Time dt){
    Vec2d movement = stepDiffEq(getPosition(),getSpeedVector(),dt,(*this),DiffEqAlgorithm::EC).position - getPosition();
    if(movement.lengthSquared()>0.001){
    (*this).CircularBody::move(movement);
    }
    aim();
}

void Bacteriophage::aim(){
    setDirection(Vec2d::fromRandomAngle());
    Vec2d nextDirection=Vec2d::fromRandomAngle();
    for(int i=0;i<20;++i){
        if(getAppEnv().getBacteriaScore(nextDirection+getPosition())>getAppEnv().getBacteriaScore(getDirection()+getPosition())){
            setDirection(nextDirection);
        }
        nextDirection=Vec2d::fromRandomAngle();
    }
}

Vec2d Bacteriophage::getSpeedVector() const{
    return getDirection()*5.0;
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
*/
