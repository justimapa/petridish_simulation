#pragma once
#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include "Utility/Types.hpp"
#include "Utility/Utility.hpp"
#include "Utility/MutableColor.hpp"
#include "Utility/MutableNumber.hpp"

class Bacterium : public CircularBody,public Drawable,public Updatable
{
public:
    Bacterium(Quantity const&,Vec2d const&,Vec2d const&,double const&,MutableColor const&);
    Bacterium(Bacterium&);
    virtual void drawOn(sf::RenderTarget&)const;
    virtual void update(sf::Time);
    bool isDead()const;
    Vec2d getDirection()const;
    void setDirection(const Vec2d&);
    Quantity getMinEnergyDivision()const;
    sf::Time getDelay()const;
    Quantity getEnergyConsumption()const;
    MutableColor getColor()const;
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
