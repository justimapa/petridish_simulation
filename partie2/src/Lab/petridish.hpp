#pragma once
#include "Bacterium.hpp"
#include "Nutriment.hpp"

#include <vector>

class Petridish : public CircularBody
{
public:
    /*!
     * Deletes = operator inherited from CircularBody:: to avoid unnecessary memory usage
     */
    Petridish& operator=(Petridish const &) = delete;
   /*!
    * @brief Constructor for the Petridish::
    * @param Position of the Petridish::
    * @param Radius of the Petridish::
    * @param Temperature of the Petridish::
    */
    Petridish(Vec2d position,double radius, double Temperature);
   /*!
    * @brief Getter for the temperature
    * @return Temperature of the Petridish::
    */
    double getTemperature() const;
   /*!
    * @brief Decreases temperature of the Petridish::
    */
    void decreaseTemperature();
   /*!
    * @brief Increases temperature of the Petridish::
    */
    void increaseTemperature();
    /*!
     * @brief resets temperature of the petridish to config default
     */
    void resetTemperature();
   /*!
    * @brief Adds a Bacterium:: to the Petridish::
    * @param Bacterium:: to be added
    * @return True if the Bacterium:: could be added, false if not
    */
    bool addBacterium(Bacterium*);
   /*!
    * @brief Adds a Nutriment:: to the Petridish::
    * @param Nutriment:: to be added
    * @return True if the Nutriment:: could be added, false if not
    */
    bool addNutriment(Nutriment*);
   /*!
    * @brief Updates Lab:: after every fraction of time dt
    * @param Fraction of time dt after which the Lab:: is updates
    * @return true if update is a success, false if not
    */
    void update(sf::Time dt);
   /*!
    * @brief Draws Petridish:: on targetWindow
    * @param targetWindow
    */
    void drawOn(sf::RenderTarget& targetWindow) const;
   /*!
    * @brief Destructs Lab::
    */
    void reset();
    ~Petridish();

private:

    std::vector<Bacterium*> bacteria;
    std::vector<Nutriment*> nutriments;
    double temperature;
};

