#pragma once
#include "Nutriment.hpp"
#include "petridish.hpp"


class Lab
{
public:
    /*!
     * @brief Default constructor
     */
    Lab();
    /*!
     * @brief Getter for the Petridish::'s temperature
     * @return Temperature of the Petridish::
     */
    double getTemperature() const;
    /*!
     * @brief Decreases temperature
     */
    void decreaseTemperature();
    /*!
     * @brief Increases temperature
     */
    void increaseTemperature();
    /*!
     * @brief Tests if a CircularBody:: is inside another
     * @param The other CircularBody::
     * @return true if the other CircularBody:: has a smaller radius and the center is
     * within our CircularBody::, false if not
     */
    bool contains(const CircularBody&);
    /*!
     * @brief Adds a Nutriment:: to the Petridish::
     * @param Nutriment:: to be added
     */
    void addNutriment(Nutriment*);
    /*!
     * @brief Draws Petridish:: on targetWindow
     * @param targetWindow
     */
    void drawOn(sf::RenderTarget& targetWindow) const;
    /*!
     * @brief Updates Lab:: after every fraction of time dt
     * @param Fraction of time dt after which the Lab:: is updates
     * @return true if update is a success, false if not
     */
    bool update(sf::Time dt);
    /*!
     * @brief Destructs Lab::
     */
    void reset();
    ~Lab();

private:
    Petridish dish;
};
