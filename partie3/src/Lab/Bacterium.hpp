#pragma once
#include "CircularBody.hpp"
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
    void setDirection(const Vec2d&);
    Quantity getEnergy() const;
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
    Quantity getEnergyConsumption() const;
    /*!
     * @brief Getter for the color of the Bacterium::
     * @return Color of the Bacterium::
     */
    MutableColor getColor() const;
    void addProperty(const std::string&, const MutableNumber &);
    MutableNumber getProperty(const std::string&);
    void reset();
    /*!
     * @brief Subtracts certain quantity of energy
     * @param Energy to be subtracted
     */
    void consumeEnergy(Quantity qt);
    void mutation(Bacterium*);
    /*!
     * @brief Moves the Bacterium:: with in the Petridish::
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
