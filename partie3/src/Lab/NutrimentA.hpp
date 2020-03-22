#pragma once
#include "Nutriment.hpp"


class NutrimentA:public Nutriment
{
public:
    NutrimentA(Quantity const& quantity,Vec2d const& position);
    j::Value const& getConfig() const override;
};


