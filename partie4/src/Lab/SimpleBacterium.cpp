#include "SimpleBacterium.hpp"
#include "Random/Random.hpp"
#include "JSON/JSONImpl.hpp"
#include "Application.hpp"
#include <string>
#include <vector>

using namespace std;

SimpleBacterium::SimpleBacterium(const Vec2d& position)
: Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()),
            position,
            Vec2d::fromRandomAngle(),
            uniform(getConfig()["radius"]["min"].toDouble(),getConfig()["radius"]["max"].toDouble()),
            getConfig()["color"]),
  t(uniform(0.0,PI)),
  rotation(getDirection().angle()),
  oldScore(0.0),
  tLastTumble(sf::Time::Zero),
  algo(getConfig()["tumble"]["algo"].toString())
{
    addProperty("speed",MutableNumber::positive(getConfig()["speed"]));
    addProperty("tumble better",MutableNumber::positive(getConfig()["tumble"]["better"]));
    addProperty("tumble worse",MutableNumber::positive(getConfig()["tumble"]["worse"]));
}
SimpleBacterium::SimpleBacterium(SimpleBacterium & other):
    Bacterium(other),
              rotation(other.rotation),
              oldScore(other.oldScore),
              algo(other.algo)
{ }
void SimpleBacterium::move(sf::Time dt){
    Vec2d movement = stepDiffEq(getPosition(),getSpeedVector(),dt,(*this),DiffEqAlgorithm::EC).position - getPosition();
    if(movement.lengthSquared()>0.001){
    (*this).CircularBody::move(movement);
    consumeEnergy((movement).length()*getEnergyConsumption().toDouble());
    }
}
Vec2d SimpleBacterium::f(Vec2d position, Vec2d direction) const{
    return Vec2d(0,0);
}
Vec2d SimpleBacterium::getSpeedVector(){
    return getDirection()*(getProperty("speed").get());
}
void SimpleBacterium::drawOn(sf::RenderTarget& target) const{
    Bacterium::drawOn(target);
    drawFlagella(target);
}
void SimpleBacterium::update(sf::Time dt){
    Bacterium::update(dt);
    tLastTumble+=dt;
    updateProbability();
    tumble();
    updateFlagella(dt);
}
void SimpleBacterium::drawFlagella(sf::RenderTarget& target) const{
    auto flagella = sf::VertexArray(sf::LinesStrip);
    flagella.append( {{0,0},getColor().get()});
    for(int i=1; i<=30;++i){
        flagella.append({{static_cast<float>((-i*getRadius()/10.0)-0.75),static_cast<float>((getRadius()*sin(t)*sin(2*i/10.0))-0.75)},getColor().get()});
        flagella.append({{static_cast<float>((-i*getRadius()/10.0)+0.75),static_cast<float>((getRadius()*sin(t)*sin(2*i/10.0))+0.75)},getColor().get()});
    }
    auto transform = sf::Transform();
    transform.translate(getPosition());
    transform.rotate(rotation/DEG_TO_RAD);
    target.draw(flagella,transform);
}
void SimpleBacterium::updateFlagella(sf::Time dt){
    t+=(3*dt.asSeconds());
    auto const angleDiff = angleDelta(getDirection().angle(),rotation);
    auto dalpha = PI * dt.asSeconds();
    dalpha = min(dalpha,abs(angleDiff));
    dalpha = copysign(dalpha,angleDiff);
    rotation+=dalpha;
}
void SimpleBacterium::updateProbability(){
    if(getAppEnv().getPositionScore(getPosition())>=oldScore){
        tumblingProbability=1-exp(-tLastTumble.asSeconds()/getProperty("tumble better").get());
    }else{
        tumblingProbability=1-exp(-tLastTumble.asSeconds()/getProperty("tumble worse").get());
    }

    oldScore=getAppEnv().getPositionScore(getPosition());
}
bool SimpleBacterium::isTumbling(){
    return bernoulli(tumblingProbability);
}
void SimpleBacterium::tumble(){
    if(isTumbling() and algo=="single random vector"){
        setDirection(Vec2d::fromRandomAngle());
        tLastTumble = sf::Time::Zero;
    }
    if(isTumbling() and algo=="best of N"){
        setDirection(Vec2d::fromRandomAngle());
        Vec2d nextDirection=Vec2d::fromRandomAngle();
        for(int i=0;i<20;++i){
            if(getAppEnv().getPositionScore(nextDirection+getPosition())>getAppEnv().getPositionScore(getDirection()+getPosition())){
                setDirection(nextDirection);
            }
            nextDirection=Vec2d::fromRandomAngle();
        }
    }
}
j::Value& SimpleBacterium::getConfig() const{
    return getAppConfig()["simple bacterium"];
}
Bacterium* SimpleBacterium::clone(){
    if(getMinEnergyDivision()<=getEnergy()){
        Bacterium* new_Bact(new SimpleBacterium(*this));
        mutation(new_Bact);
        return new_Bact;
    }
    return nullptr;
}
SimpleBacterium::~SimpleBacterium()
{ }
