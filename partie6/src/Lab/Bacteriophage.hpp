#pragma once
#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include "Utility/DiffEqSolver.hpp"

/*!
 * @class Bacteriophage
 * @brief class that represents the functions and behavior
 * of a bacteriophage within a Petridish
 *
 * Subclass of CircularBody, Drawable, Updatable and DiffEqFunction
 */
class Bacteriophage : public CircularBody, public Drawable, public Updatable, public DiffEqFunction
{
public:
    static std::map<int, int> phageCounterMap;
    /*!
     * @brief Constructs a Bacteriophage:: fully set up
     * @param Position
     * @param Radius
     * @param Radius
     * @return A Bacteriophage:: with all parameters set
     */
    Bacteriophage(Vec2d const& position, double const& radius, Vec2d const& direction);
    /*!
     * @brief Draws the Bacteriophage::
     * @param targetWindow where the Bacteriophage:: will be drawn
     */
    virtual void drawOn(sf::RenderTarget &target) const override;
    /*!
     * @brief Updates phages within Petridish:: at every fraction
     * of time dt
     * @param Fraction of time dt
     */
    virtual void update(sf::Time dt) override;
    /*!
     * @brief Moves the Bacteriophage:: within the Petridish::
     * @param Time dt after which movement will take place
     */
    void move(sf::Time dt);
    /*!
     * @brief Changes the direction of movement along Bacterium:: gradient
     */
    void aim(sf::Time dt);
    /*!
     * @brief Infects a Bacterium:: it touches
     */
    void infect() const;
    /*!
     * @brief Switches between LYTIC and LYSOGENIC at random every 5 seconds
     */
    void statusSwap();
    /*!
     * @brief Getter for the direction of the Bacteriophage::
     * @return Direction (unit vector) of the Bacteriophage::
     */
    Vec2d getDirection() const;
    /*!
     * @brief Setter for the Direction of the Bacteriophage::
     */
    void setDirection(const Vec2d& direction_);
    /*!
     * @brief Getter for the speed vector of the Bacteriophage::
     * @return The speed vector of the Bacteriophage::
     */
    Vec2d getSpeedVector() const;
    /*!
     * @brief Returns a zero force
     * @param Position
     * @param Direction
     * @return Returns the zero 2d vector
     */
    virtual Vec2d f(Vec2d position, Vec2d speed) const override;
    /*!
     * @brief Resets the delay between state switches
     */
    void resetDelay();
    /*!
     * @brief Destructor for the class
     */
    virtual ~Bacteriophage();
private:
    Vec2d direction;
    sf::Color color;
    //Status can be LYTIC or LYSOGENIC, determines infection effect on Bacterium::
    std::string status;
    sf::Time delay;
};