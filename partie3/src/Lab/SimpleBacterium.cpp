#include "SimpleBacterium.hpp"
#include "Random/Random.hpp"
#include "JSON/JSONImpl.hpp"
#include "Application.hpp"

using namespace std;

SimpleBacterium::SimpleBacterium(const Vec2d & position):
    Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()),
    position,Vec2d::fromRandomAngle(),
    uniform(getConfig()["radius"]["min"].toDouble(),getConfig()["radius"]["max"].toDouble()),
    getConfig()["color"])
{

}
void SimpleBacterium::move(sf::Time dt){

    Vec2d movement=stepDiffEq(getPosition(),getSpeedVector(),dt,(*this),DiffEqAlgorithm::EC).position-getPosition();
    if((movement).lengthSquared()>0.001){
    (*this).CircularBody::move(movement);
    consumeEnergy((movement).length()*getEnergyConsumption());
    }
}
void SimpleBacterium::drawFlagella(sf::RenderTarget& target,sf::Time dt)const{
    auto flagella= sf::VertexArray(sf::TriangleStrip);
    flagella.append( {{0,0},sf::Color::Black});
    for(int i=1; i<=30;++i){
        flagella.append({{static_cast<float>(-i*getRadius()/10.0),static_cast<float>(getRadius()*sin(dt.asSeconds())*sin(2*i/10.0))},sf::Color::Black});
    }
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
