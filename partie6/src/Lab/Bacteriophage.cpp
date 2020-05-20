#include "Bacteriophage.hpp"
#include "Application.hpp"

Bacteriophage::Bacteriophage(Vec2d const& position, double const& radius, Vec2d const& direction)
: CircularBody(position, radius),
  direction(direction),
  color(sf::Color::Yellow),
  status("LYTIC")
{

}

void Bacteriophage::drawOn(sf::RenderTarget& target) const{
    auto const circle = buildCircle(getPosition(), getRadius(), color);
    target.draw(circle);
    if(isDebugOn()){
        Vec2d textposition(getPosition()[0], getPosition()[1]+getRadius());
        std::string message;
        if(status == "Lytic") {
            message = "Status : Lytic";
        }else{
            message = "Status : Lysogenic";
        }
        auto const text = buildText(message, textposition, getAppFont(), 15, sf::Color::Red);
        target.draw(text);
    }
}

