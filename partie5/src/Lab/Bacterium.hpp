#pragma once
#include "CircularBody.hpp"
#include "NutrimentA.hpp"
#include "NutrimentB.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include "Utility/Types.hpp"
#include "Utility/Utility.hpp"
#include "Utility/MutableColor.hpp"
#include "Utility/MutableNumber.hpp"
#include <string>

/*!
 * @class Bacterium
 * @brief class that represents the functions and behavior
 * of bacteria within a Petridish
 *
 * Subclass of CircularBody, Drawable and Updatable
 */
class Bacterium : public CircularBody, public Drawable, public Updatable
{
public:
    /*!
     * @brief Constructs a Bacterium:: fully set up
     * @param Energy qty
     * @param Position
     * @param Direction unit vector
     * @param Radius
     * @param Color that can change over time
     * @return A Bacterium:: with all parameters set
     */
    Bacterium(Quantity const&,Vec2d const& position_,Vec2d const& direction_,double const& radius_,MutableColor const&);
    /*!
     * @brief Copy Constructor for Bacterium::
     * @param Original Bacterium:: who's energy will be halved
     * @return Returns a Copy of the Original Bacterium with half of original energy and the other direction
     */
    Bacterium(Bacterium&);
    /*!
     * @brief Draws the Bacterium::
     * @param targetWindow where the Bacterium:: will be drawn
     */
    virtual void drawOn(sf::RenderTarget&) const;
    /*!
     * @brief Updates bacteria within Petridish:: at every fraction
     * of time dt
     * @param Fraction of time dt
     */
    virtual void update(sf::Time);
    /*!
     * @brief Checks whether Bacterium:: has no energy left
     * @return True if it has no energy, false otherwise
     */
    bool isDead() const;
    /*!
     * @brief Getter for the direction of the Bacterium::
     * @return Direction (unit vector) of the Bacterium::
     */
    Vec2d getDirection() const;
    /*!
     * @brief Setter for the Direction of the Bacterium::
     */
    void setDirection(const Vec2d&);
    /*!
     * @brief Getter for the Energy of the Bacterium::
     * @return Energy of the Bacterium::
     */
    Quantity getEnergy() const;
    /*!
     * @brief Setter for the Energy of the Bacterium::
     */
    void setEnergy(Quantity const&);
    /*!
     * @brief Gets config value for min division energy
     * @return Minimum energy qty required for division
     */
    Quantity getMinEnergyDivision() const;
    /*!
     * @brief Gets config value for meal delay
     * @return Time between nutrient consumption
     */
    sf::Time getDelay() const;
    /*!
     * @brief Gets config value for consumption factor
     * @return Energy spent per movement
     */
    j::Value& getEnergyConsumption() const;
    /*!
     * @brief Gets config value for max eatable quantity
     * for each Bacterium:: type
     * @return Max eatable quantity
     */
    j::Value& getMaxEatableQuantity() const;
    /*!
     * @brief Getter for the color of the Bacterium::
     * @return Color of the Bacterium::
     */
    MutableColor getColor() const;
    /*!
     * @brief Adds a new property to mutations map
     * @param Key of the property
     * @param Value of the Property
     */
    void addProperty(const std::string&, const MutableNumber &);
    /*!
     * @brief Gets a Property from the mutations map
     * @param Key of the Property
     * @return Value (Mutable Number) of the Property
     */
    MutableNumber getProperty(const std::string&);
    /*!
     * @brief Resets the Delay between energy consumptions
     */
    void reset();
    /*!
     * @brief Subtracts certain quantity of energy
     * @param Energy to be subtracted
     */
    void consumeEnergy(Quantity qt);
    /*!
     * @brief Mutates the mutations of a Bacterium::
     * @param The Bacterium:: that will be mutated
     */
    void mutation(Bacterium*);
    /*!
     * @brief Moves the Bacterium:: within the Petridish::
     * @param Time dt after which movement will take place
     *
     * Pure virtual method
     */
    virtual void move(sf::Time dt) = 0;
    /*!
     * @brief Clones the Bacterium::
     * @return Copy of the initial Bacterium::
     *
     * Pure virtual method
     */
    virtual Bacterium* clone() = 0;
    /*!
     * @brief Controls the eating process of the different Bacterium::
     * @param Copy of the initial Bacterium::nutriment that will be eaten
     */
    void eat(Nutriment& nutriment);
    /*!
     * @brief Looks at the value of the quantity of NutrimentA::
     * that is eatable
     * @param A NutrimentA::
     * @return Quantity that is consumable
     *
     * Pure virtual method
     */
    virtual Quantity eatableQuantity(NutrimentA& nutriment) const = 0;
    /*!
     * @brief Looks at the value of the quantity of NutrimentB::
     * that is eatable
     * @param A NutrimentB::
     * @return Quantity that is consumable
     *
     * Pure virtual method
     */
    virtual Quantity eatableQuantity(NutrimentB& nutriment) const = 0;
    /*!
     * @brief Gets config value corresponding to each subclass
     * of Bacterium::
     *
     * Pure virtual method
     */
    virtual j::Value& getConfig() const = 0;
    /*!
     * @brief Destructor for the class
     */
    virtual ~Bacterium();

private:
    Quantity energy;
    Vec2d direction;
    MutableColor color;
    bool abstinence;
    std::map <std::string,MutableNumber> mutations;
    sf::Time delay;
    std::vector<Bacterium*> clones;
};
