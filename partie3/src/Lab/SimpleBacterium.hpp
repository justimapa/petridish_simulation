#pragma once
#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

class SimpleBacterium : public Bacterium, public DiffEqFunction
{
public:
    SimpleBacterium(Vec2d const&);

    virtual void drawOn(sf::RenderTarget& target) const override;
    virtual void update(sf::Time) override;
    void updateFlagella(sf::Time);
    void drawFlagella(sf::RenderTarget& target)const;
    void move(sf::Time) override;
    Bacterium* clone()const override;
    j::Value& getConfig()const override;
    Vec2d getSpeedVector() const;
    void drawFlagella()const;
    Vec2d f(Vec2d position, Vec2d direction) const override;
private:
    double t;
    double rotation;
};


