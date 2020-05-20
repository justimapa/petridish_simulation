/*#pragma once
#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include "Utility/MutableColor.hpp"
#include "Utility/DiffEqSolver.hpp"

class Bacteriophage : public CircularBody, public Drawable, public Updatable, public DiffEqFunction
{
public:
    Bacteriophage(Vec2d const& position, double const& radius, Vec2d const& direction);
    virtual void drawOn(sf::RenderTarget&) const;
    virtual void update(sf::Time dt);
    void move(sf::Time dt);
    void aim();
    Vec2d getDirection() const;
    void setDirection(const Vec2d& direction_);
    Vec2d f(Vec2d position, Vec2d direction) const;
    Vec2d getSpeedVector() const;
    void resetDelay();
    bool isLytic();
private:
    Vec2d direction;
    sf::Color color;
    std::string status;
    sf::Time delay;
};
*/
