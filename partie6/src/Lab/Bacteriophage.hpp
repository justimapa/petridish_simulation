#pragma once
#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include "Utility/DiffEqSolver.hpp"

/*!
 * @class Bacterium
 * @brief class that represents the functions and behavior
 * of bacteriophage within a Petridish
 *
 * Subclass of CircularBody, Drawable and Updatable
 */
class Bacteriophage : public CircularBody, public Drawable, public Updatable, public DiffEqFunction
{
public:
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
     * @brief Changes the direction of tumble depending
     */
    void aim(sf::Time dt);
    void infect() const;
    void statusSwap();
    Vec2d getDirection() const;
    void setDirection(const Vec2d& direction_);
    virtual Vec2d f(Vec2d position, Vec2d speed) const override;
    Vec2d getSpeedVector() const;
    void resetDelay();
    bool isLytic();
    virtual ~Bacteriophage();
private:
    Vec2d direction;
    sf::Color color;
    std::string status;
    sf::Time delay;
};
