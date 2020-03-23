#pragma once
#include <array>
#include "MutableNumber.hpp"
#include "Utility/Utility.hpp"

class MutableColor
{
public:
    MutableColor(j::Value const& config);
    void mutate();
    sf::Color get() const;
private:
    std::array<MutableNumber, 4> RGBA;
};
