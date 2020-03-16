#pragma once
#include "Bacterium.hpp"
#include "Utility/Vec2d.hpp"
#include "Nutriment.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Petridish:public CircularBody
{
private:
    std::vector<Bacterium*> bacterium;
    std::vector<Nutriment*> nutriment;
public:
    /*!
     * Deletes = operator inherited form CircularBody
     *
     */
    Petridish& operator=(Petridish const &) = delete;
    Petridish(Vec2d position,double radius);
    bool addBacterium(Bacterium*);
    bool addNutriment(Nutriment*);
    void update(sf::Time dt);
    void drawOn(sf::RenderTarget& targetWindow)const;
    void reset();
    ~Petridish();
};

