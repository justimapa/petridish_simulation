#pragma once
#include "CircularBody.hpp"
#include "Utility/Types.hpp"
#include "Utility/Vec2d.hpp"
#include "SFML/Graphics.hpp"

/*!
 * @class Nutriment
 * @brief class representing the nutrient sources within the PetriDish:: which
 * can be consumed by the Bacterium::
 *
 * Subclass of CircularBody::
 */
class Nutriment : public CircularBody
{
public:
    /*!
     * @brief Constructs a Nutriment:: fully set up
     * @param Position of the Nutriment::
     * @param Quantity of the Nutriment::
     * @return A Nutriment:: with all parameters set
     */
    Nutriment(Quantity const& quantity,Vec2d const& position);
    /*!
     * @brief Take a certain quantity of Nutriment::
     * @param Quantity of Nutriment:: to take
     * @return Amount of Nutriment:: taken
     */
    Quantity takeQuantity(Quantity quantity_);
    /*!
     * @brief Setter for the quantity
     * @param Quantity that will be set
     */
    void setQuantity(Quantity quantity_);
    /*!
     * @brief draws the Nutriment::
     * @param targetWindow where the Nutriment:: will be drawn
     */
    void drawOn(sf::RenderTarget& target) const;
    /*!
     * @brief Shortcut for method getAppConfig() in Application.hpp
     */
    j::Value const& getConfig() const;
    /*!
     * @brief updates nutriments within Petridish:: at every fraction
     * of time dt
     * @param Fraction of time dt
     */
    void update(sf::Time dt);
    /*!
     * @brief Checks whether temperature is within specified boundaries
     * @return True if temperature is within boundaries, false if not
     */
    bool isTemperatureOK() const;
    /*!
     * @brief Checks whether the quantity of Nutriment:: does not surpass specified quota
     * @return True if quantity is within boundaries, false if not
     */
    bool isQuantityOK() const;
    /*!
     * @brief Checks whether the Nutriment:: is still within the Petridish::
     * @return True if it is, false if not
     */
    bool isContained() const;

private:
    Quantity quantity;
};

