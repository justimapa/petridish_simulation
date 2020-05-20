#pragma once
#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include "Utility/DiffEqSolver.hpp"

class Bacteriophage : public CircularBody, public Drawable, public Updatable, public DiffEqFunction
{
public:
    Bacteriophage(Vec2d const& position, double const& radius, Vec2d const& direction);
    virtual void drawOn(sf::RenderTarget &target) const override;
    virtual void update(sf::Time dt) override;
    void move(sf::Time dt);
    void aim(sf::Time dt);
    Vec2d getDirection() const;
    void setDirection(const Vec2d& direction_);
    virtual Vec2d f(Vec2d position, Vec2d speed) const override;
    Vec2d getSpeedVector() const;
    void resetDelay();
    bool isLytic();
    virtual ~Bacteriophage();
private:
    Vec2d direction;
    sf::Color color;
    std::string status;
    sf::Time delay;
};
