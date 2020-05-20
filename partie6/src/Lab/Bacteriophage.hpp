#pragma once
#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include "Utility/MutableColor.hpp"

class Bacteriophage : public CircularBody, public Drawable, public Updatable
{
public:
    Bacteriophage(Vec2d const& position, double const& radius, Vec2d const& direction);
    virtual void drawOn(sf::RenderTarget&) const;
    bool isLytic();
private:
    Vec2d direction;
    sf::Color color;
    std::string status;

};
