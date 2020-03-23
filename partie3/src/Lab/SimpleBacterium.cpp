#include "SimpleBacterium.hpp"
#include "Random/Random.hpp"
#include "JSON/JSONImpl.hpp"
#include "Application.hpp"

using namespace std;

SimpleBacterium::SimpleBacterium(const Vec2d & position):
    Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()),
    position,Vec2d::fromRandomAngle(),
    uniform(getConfig()["radius"]["min"].toDouble(),getConfig()["radius"]["max"].toDouble()),
    getConfig()["color"]),
    t(uniform(0.0,PI)),
    rotation(getDirection().angle())
{

}
void SimpleBacterium::move(sf::Time dt){

    Vec2d movement=stepDiffEq(getPosition(),getSpeedVector(),dt,(*this),DiffEqAlgorithm::EC).position-getPosition();
    if((movement).lengthSquared()>0.001){
    (*this).CircularBody::move(movement);
    consumeEnergy((movement).length()*getEnergyConsumption());
    }
}

void SimpleBacterium::drawOn(sf::RenderTarget& target) const{
    Bacterium::drawOn(target);
    drawFlagella(target);
}
void SimpleBacterium::update(sf::Time dt){
    Bacterium::update(dt);
    updateFlagella(dt);
}
void SimpleBacterium::updateFlagella(sf::Time dt){
    t+=(3*dt.asSeconds());
    auto const angleDiff = angleDelta(getDirection().angle(),rotation);
    auto dalpha = PI * dt.asSeconds();
    dalpha= min(dalpha,abs(angleDiff));
    dalpha=copysign(dalpha,angleDiff);
    rotation+=dalpha;

}
void SimpleBacterium::drawFlagella(sf::RenderTarget& target)const
{
    auto flagella= sf::VertexArray(sf::TriangleStrip);
    flagella.append( {{0,0},sf::Color::Black});
    for(int i=1; i<=30;++i){
        flagella.append({{static_cast<float>(-i*getRadius()/10.0),static_cast<float>(getRadius()*sin(t)*sin(2*i/10.0))},sf::Color::Black});
    }
    auto transform = sf::Transform();
    transform.translate(getPosition());
    transform.rotate(rotation/DEG_TO_RAD);
    target.draw(flagella,transform);
}
j::Value& SimpleBacterium::getConfig()const{
    return getAppConfig()["simple bacterium"];
}
Vec2d SimpleBacterium::getSpeedVector() const{
    return getDirection().normalised()*10;
}
Vec2d SimpleBacterium::f(Vec2d position, Vec2d direction) const{
    return Vec2d(0,0);
}
Bacterium* SimpleBacterium::clone()const{
    //I do jack shit for now
}
