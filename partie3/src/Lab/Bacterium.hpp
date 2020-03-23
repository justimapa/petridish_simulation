#pragma once
#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include "Utility/Types.hpp"
#include "Utility/Utility.hpp"

typedef j::Value& MutableColor;
typedef double MutableNumber;

class Bacterium : public CircularBody,public Drawable,public Updatable
{
public:
    Bacterium(Quantity const&,Vec2d const&,Vec2d const&,double const&,MutableColor const&);
    Bacterium(Bacterium&);
    void drawOn(sf::RenderTarget&)const;

    void update(sf::Time);
    bool isDead()const;
    Vec2d getDirection()const;
    Quantity getMinEnergyDivision()const;
    sf::Time getDelay()const;
    Quantity getEnergyConsumption()const;
    void reset();
    void consumeEnergy(Quantity qt);
    virtual void move(sf::Time)= 0;
    virtual Bacterium* clone()const = 0;
    virtual j::Value& getConfig()const=0;

private:
    Quantity energy;
    Vec2d direction;
    MutableColor color;
    bool abstinence;
    std::map <std::string,MutableNumber> mutations;
    sf::Time delay;
};
