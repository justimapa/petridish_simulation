#pragma once
#include <Utility/Types.hpp>
#include "Utility/Vec2d.hpp"
#include <SFML/Graphics.hpp>

/*!
 * @class Nutriment
 *
 * @brief class representing the nutrient sources within the PetriDish:: which
 * can be consumed by the Bacterium::
 *
 * Subclass of CircularBody::
 */
class Nutriment : public CircularBody
{
public:
    /*!
     * @brief Construct a Nutriment:: fully set up
    *
    * @param position of the Nutriment::
    * @param quantity of the Nutriment::
    *
    * @return a Nutriment:: with all parameters set
    */
    Nutriment(Vec2d const& position, Quantity const& quantity);

    /*!
     * @brief Take a certain quantity of Nutriment::
    *
    * @param quantity of Nutriment:: to take
    *
    * @return amount of Nutriment:: taken
    */
    Quantity takeQuantity(Quantity& quantity_) const;

    /*!
     * @brief Sets a Quantity
    *
    * @param Quantity that will be set
    */
    void setQuantity(Quantity& quantity_);

    /*!
     * @brief draws the Nutriment::
    *
    * @param (TO-DO)
    */
    void drawOn(sf::RenderTarget& target) const;

    /*!
     * @brief Shortcut for method getAppConfig()
    */
    j::Value const& getConfig() const;

private:
    Quantity quantity;
};

\
