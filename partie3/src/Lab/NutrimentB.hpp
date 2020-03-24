#pragma once
#include "Nutriment.hpp"


class NutrimentB : public Nutriment
{
public:
    NutrimentB(Quantity const& quantity,Vec2d const& position);
    j::Value const& getConfig() const override;
    virtual ~NutrimentB() override;
};


