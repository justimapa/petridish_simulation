#pragma once
#include "CircularBody.hpp"
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
    Nutriment(Quantity const& quantity,Vec2d const& position);

    /*!
     * @brief Take a certain quantity of Nutriment::
    *
    * @param quantity of Nutriment:: to take
    *
    * @return amount of Nutriment:: taken
    */



    Quantity takeQuantity(Quantity quantity_);

    /*!
     * @brief Sets a Quantity
    *
    * @param Quantity that will be set
    */
    void setQuantity(Quantity quantity_);

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

    /*!
     * @brief updates nutriments within Petridish:: at every fraction
     * of time dt
    *
    * @param time dt
    */
    void update(sf::Time dt);
private:
    Quantity quantity;
};

