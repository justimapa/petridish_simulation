#prgama once
#include "bacterium.hpp"
#include "Utility/Vec2d.hpp"
#include <SFML/Graphics.hpp>

class Petridish:public CircularBody
{
    Bacterium bacterium;
    Nutrient nutrient;
public:
    Petridish(Vec2d position,double radius);
    bool addBacterium(Bacterium*);
    bool addNutrient(Nutriment*);
    void update(sf::Time dt);
    void drawOn(sf::RenderTarget& targetWindow);
    void reset();
};

