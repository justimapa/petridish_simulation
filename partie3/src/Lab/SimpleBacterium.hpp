#pragma once
#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

class SimpleBacterium : public Bacterium, public DiffEqFunction
{
public:
    SimpleBacterium(Vec2d const&);
    void move(sf::Time) override;
    Bacterium* clone()const override;
    j::Value& getConfig()const override;
    Vec2d getSpeedVector() const;
    void drawFlagella()const;
    Vec2d f(Vec2d position, Vec2d direction) const override;
};


