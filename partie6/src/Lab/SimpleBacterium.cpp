#include "SimpleBacterium.hpp"
#include "Nutriment.hpp"
#include "NutrimentA.hpp"
#include "NutrimentB.hpp"
#include "Random/Random.hpp"
#include "JSON/JSONImpl.hpp"
#include "Application.hpp"
#include <string>
#include <vector>

using namespace std;

map<int,int> SimpleBacterium::simpleCounterMap;
map<int,double> SimpleBacterium::betterMap;
map<int,double> SimpleBacterium::worseMap;

SimpleBacterium::SimpleBacterium(const Vec2d& position)
: Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()),
            position,
            Vec2d::fromRandomAngle(),
            uniform(getConfig()["radius"]["min"].toDouble(),getConfig()["radius"]["max"].toDouble()),
            getConfig()["color"], MutableNumber::probability(getConfig()["immunity"])),
  t(uniform(0.0,PI)),
  rotation(getDirection().angle()),
  oldScore(0.0),
  tLastTumble(sf::Time::Zero),
  algo(getConfig()["tumble"]["algo"].toString())
{
    addProperty("speed",MutableNumber::positive(getConfig()["speed"]));
    addProperty("tumble better",MutableNumber::positive(getConfig()["tumble"]["better"]));
    addProperty("tumble worse",MutableNumber::positive(getConfig()["tumble"]["worse"]));
    addProperty("immunity", MutableNumber::probability(getConfig()["immunity"]));
    ++simpleCounterMap[getAppEnv().getCurrentPetridishId()];
    betterMap[petridishId]+=getProperty("tumble better").get();
    worseMap[petridishId]+=getProperty("tumble worse").get();
    speedMap[petridishId]+=getProperty("speed").get();
}

SimpleBacterium::SimpleBacterium(SimpleBacterium & other):
    Bacterium(other),
              rotation(other.rotation),
              oldScore(other.oldScore),
              algo(other.algo)
{
    ++simpleCounterMap[petridishId];
}

void SimpleBacterium::move(sf::Time dt){
    Vec2d movement = stepDiffEq(getPosition(),getSpeedVector(),dt,(*this),DiffEqAlgorithm::EC).position - getPosition();
    if(movement.lengthSquared()>0.001){
    (*this).CircularBody::move(movement);
    consumeEnergy((movement).length()*getEnergyConsumption().toDouble());
    }
}
Quantity SimpleBacterium::eatableQuantity(NutrimentA& nutriment){
    return nutriment.eatenBy(*this);
}
Quantity SimpleBacterium::eatableQuantity(NutrimentB& nutriment){
    return nutriment.eatenBy(*this);
}
Vec2d SimpleBacterium::f(Vec2d position, Vec2d direction) const{
    return Vec2d(0,0);
}
Vec2d SimpleBacterium::getSpeedVector() const{
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
    if(getAppEnv().getPositionScore(getPosition(),petridishId)>=oldScore){
        tumblingProbability=1-exp(-tLastTumble.asSeconds()/getProperty("tumble better").get());
    }else{
        tumblingProbability=1-exp(-tLastTumble.asSeconds()/getProperty("tumble worse").get());
    }

    oldScore=getAppEnv().getPositionScore(getPosition(),petridishId);
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
            if(getAppEnv().getPositionScore(nextDirection+getPosition(),petridishId)>getAppEnv().getPositionScore(getDirection()+getPosition(),petridishId)){
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
        Bacterium* new_Bact(new SimpleBacterium(*this));
        mutation(new_Bact);
        betterMap[petridishId]+=new_Bact->getProperty("tumble better").get();
        worseMap[petridishId]+=new_Bact->getProperty("tumble worse").get();
        speedMap[petridishId]+=new_Bact->getProperty("speed").get();
        return new_Bact;
}
SimpleBacterium::~SimpleBacterium()
{
    --simpleCounterMap[petridishId];
    betterMap[petridishId]-=getProperty("tumble better").get();
    worseMap[petridishId]-=getProperty("tumble worse").get();
    speedMap[petridishId]-=getProperty("speed").get();
}

