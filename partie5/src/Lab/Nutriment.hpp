#pragma once
#include "CircularBody.hpp"
#include "Utility/Types.hpp"
#include "Utility/Vec2d.hpp"
#include <SFML/Graphics.hpp>
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"

class Bacterium;
class SimpleBacterium;
class TwitchingBacterium;
class SwarmBacterium;
/*!
 * @class Nutriment
 * @brief class representing the nutrient sources within the Petridish:: which
 * can be consumed by the Bacterium::
 *
 * Subclass of CircularBody::, Drawable:: and Updatable
 * Abstract class that can't have any instances
 */
class Nutriment : public CircularBody,public Drawable,public Updatable{
public:
    //counter for the number of nutrient sources
    static int counter;
    //counter for the total quantity of nutrient in the Petridish::
    static Quantity quantitycounter;
    /*!
     * @brief Constructs a Nutriment:: fully set up
     * @param Position of the Nutriment::
     * @param Quantity of the Nutriment::
     * @return A Nutriment:: with all parameters set
     */
    Nutriment(Quantity const& quantity_,Vec2d const& position_);
    /*!
     * @brief Pure virtual methods, inherited by classes NutrimentA::
     * and NutrimentB::, specific to each type of Bacterium
     */
    virtual Quantity eatenBy(Bacterium& bact) = 0;
    virtual Quantity eatenBy(SimpleBacterium& bact) = 0;
    virtual Quantity eatenBy(TwitchingBacterium& bact) = 0;
    virtual Quantity eatenBy(SwarmBacterium& bact) = 0;
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
     * @brief Getter for the quantity
     * @return Quantity of current instance
     */
    Quantity getQuantity()const;
    /*!
     * @brief Draws the Nutriment::
     * @param targetWindow where the Nutriment:: will be drawn
     */
    virtual void drawOn(sf::RenderTarget& target) const override;
    /*!
     * @brief Pure virtual method, inherited by classes NutrimentA::
     * and NutrimentB::
     */
    virtual j::Value const& getConfig() const = 0;
    /*!
     * @brief Updates nutriments within Petridish:: at every fraction
     * of time dt
     * @param Fraction of time dt
     */
    virtual void update(sf::Time dt) override;
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
    /*!
     * @brief Checks whether the Nutriment::'s quantity is greater than 0
     * @return True if it is, false if not
     */
    bool isDead() const;
    /*!
     * @brief Destructor for the Nutriment::
     */
    virtual ~Nutriment();
private:
    Quantity quantity;
};

