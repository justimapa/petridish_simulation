#pragma once
#include "petridish.hpp"
#include "Nutriment.hpp"

class Lab
{
private:
    Petridish dish;

public:
    Lab();
    bool contains(const CircularBody&);
    void addNutriment(Nutriment*);
    void drawOn(sf::RenderTarget& targetWindow)const;
    bool update(sf::Time dt);
    void reset();
    ~Lab();
};
