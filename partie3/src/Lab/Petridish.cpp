#include "Petridish.hpp"
#include "Application.hpp"


using namespace std;

Petridish::Petridish(Vec2d position,double radius, double Temperature,double gradientExponent)
: CircularBody(position,radius),
  temperature(Temperature),
  gradientExponent(gradientExponent)
{ }

vector<Nutriment*> Petridish::getNutriments()const{
    return nutriments;
}
double Petridish::getGradientExponent()const{
    return gradientExponent;
}
void Petridish::decreaseGradientExponent(){
    cerr<<gradientExponent<<endl;
    gradientExponent-=getAppConfig()["petri dish"]["gradient"]["exponent"]["delta"].toDouble();
}
void Petridish::increaseGradientExponent(){
    gradientExponent+=getAppConfig()["petri dish"]["gradient"]["exponent"]["delta"].toDouble();
}
void Petridish::resetGradientExponent(){
    gradientExponent=getAppConfig()["petri dish"]["gradient"]["exponent"]["min"].toDouble()+getAppConfig()["petri dish"]["gradient"]["exponent"]["max"].toDouble()/2;
}

double Petridish::getTemperature() const
{
    return temperature;
}
void Petridish::decreaseTemperature(){
    temperature-=getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}
void Petridish::increaseTemperature(){
    temperature+=getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}
void Petridish::resetTemperature(){
    temperature=getAppConfig()["petri dish"]["temperature"]["default"].toDouble();
}
bool Petridish::addBacterium(Bacterium* bacterium){

    if(contains(*bacterium)){
        bacteria.push_back(bacterium);
    }else{
        return false;
    }
    return true;
}
bool Petridish::addNutriment(Nutriment* nutriment){

    if(contains(*nutriment)){
        nutriments.push_back(nutriment);
    } else {
        return false;
    }
    return true;
}

void Petridish::update(sf::Time dt){
    for(auto& nutriment : nutriments){
        nutriment->update(dt);
        if(nutriment->isDead()){
            nutriment=nullptr;
        }
    }
    nutriments.erase(remove(nutriments.begin(),nutriments.end(),nullptr),nutriments.end());
    for(auto& bacterium:bacteria){
        bacterium->update(dt);
        if(bacterium->isDead()){
            bacterium=nullptr;
        }
    }
    bacteria.erase(remove(bacteria.begin(),bacteria.end(),nullptr),bacteria.end());
}
void Petridish::drawOn(sf::RenderTarget& targetWindow) const
{
    auto border=buildAnnulus(getPosition(),getRadius(),sf::Color::Black,5);
    for(auto& nutriment : nutriments){
        nutriment->drawOn(targetWindow);
    }
    for(auto& bacterium : bacteria){
        bacterium->drawOn(targetWindow);

    }
    targetWindow.draw(border);
}
void Petridish::reset(){
    nutriments.clear();
    for(auto* nutr: nutriments){
        delete nutr;
    }
    bacteria.clear();
    for(auto* bact : bacteria){
        delete bact;
    }
    resetGradientExponent();
    resetTemperature();
}
Petridish::~Petridish(){
    reset();
}

