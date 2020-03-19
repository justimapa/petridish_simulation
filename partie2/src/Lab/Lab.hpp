#pragma once
#include "petridish.hpp"
#include "Nutriment.hpp"

class Lab
{
public:
    /*!
     * @brief Default constructor
     */
    Lab();
    double getTemperature()const;
    void decreaseTemperature();
    void increaseTemperature();
    bool contains(const CircularBody&);
    void addNutriment(Nutriment*);
    void drawOn(sf::RenderTarget& targetWindow)const;
    bool update(sf::Time dt);
    void reset();
    ~Lab();

private:
    Petridish dish;
};
