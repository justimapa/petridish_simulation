#include "MutableColor.hpp"

MutableColor::MutableColor(j::Value const& config)
    : RGBA({MutableNumber(config["r"]), MutableNumber(config["g"]), MutableNumber(config["b"]), MutableNumber(config["a"])})
{}

void MutableColor::mutate()
{
    RGBA[0].mutate();
    RGBA[1].mutate();
    RGBA[2].mutate();
    RGBA[3].mutate();
}

sf::Color MutableColor::get() const
{
    return { static_cast<sf::Uint8>(RGBA[0].get() * 255),
             static_cast<sf::Uint8>(RGBA[1].get() * 255),
             static_cast<sf::Uint8>(RGBA[2].get() * 255),
             static_cast<sf::Uint8>(RGBA[3].get() * 255)};
}

MutableColor::~MutableColor()
{

}
