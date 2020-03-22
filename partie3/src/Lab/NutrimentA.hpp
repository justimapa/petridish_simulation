#pragma once;
#include "Nutriment.hpp"


class NutrimentA:public Nutriment
{
public:
    NutrimentA(Quantity const& quantity,Vec2d const& position);
    virtual j::Value const& getConfig() const;
};


