#pragma once
#include <SFML/Graphics.hpp>
#include "Interface/Updatable.hpp"
#include "NutrimentA.hpp"
#include "NutrimentB.hpp"

class NutrimentGenerator : public Updatable
{
public:
    NutrimentGenerator();
    void update(sf::Time dt) override;
    void reset();
private:
    sf::Time stopwatch;
    NutrimentA* nutrA;
    NutrimentB* nutrB;
};

