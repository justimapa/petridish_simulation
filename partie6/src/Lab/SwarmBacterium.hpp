#pragma once
#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

/*!
 *Predeclaration of the Swarm:: class
 */
class Swarm;
/*!
 * @class SwarmBacterium
 * @brief class that represents the behavior and movement
 * of swarm bacteria within a Petridish
 *
 * Subclass of Bacterium
 */
class SwarmBacterium: public Bacterium, public DiffEqFunction
{
public:
    static std::map<int,int> swarmCounterMap;
    /*!
     * @brief Constructor for the SwarmBacterium::
     * @param The position of the SwarmBacterium::
     * @param The Swarm of the SwarmBacterium::
     * @return a Fully constructed SwarmBacterium::
     */
    SwarmBacterium(Vec2d const& position, Swarm* swarm);
    /*!
     * @brief Copy Constructory for the SwarmBacterium::
     * @param The SwarmBacterium:: that will be copied.
     */
    SwarmBacterium(SwarmBacterium & other);
    /*!
     * @brief Getter for the "Swarm Bacterium" config
     * @return The JSON configuration of the SwarmBacterium::
     */
    j::Value& getConfig()const override;
    /*!
     * @brief Force vector
     * @param Position
     * @param Direction
     * @return Returns the force vector exercised by the leader or a null vector when it is the leader
     */
    Vec2d f(Vec2d position, Vec2d direction) const override;
    /*!
     * @brief Getter for the speed vector of the SwarmBacterium::
     * @return The speed vector of the SwarmBacterium::
     */
    Vec2d getSpeedVector();
    /*!
     * @brief Draws the SwarmBacterium::
     * @param The Window where it will be drawn.
     */
    void drawOn(sf::RenderTarget &targetWindow) const override;
    /*!
     * @brief Clones the SwarmBacterium::
     * @return A mutated copy of the SwarmBacterium::
     */
    Bacterium* clone() override;
    /*!
     * @brief Moves the SwarmBacterium::
     * @param The delay between moves
     *
     * If the SwarmBacterium:: is the leader it will choose a new direction after moving.
     */
    void move(sf::Time dt) override;
    /*!
     * @brief Chooses the best direction from 20 random directions
     */
    void tumble();
    /*!
     * @brief Looks at the value of the quantity of NutrimentA::
     * that is eatable
     * @param A NutrimentA::
     * @return Quantity that is consumable
     */
    virtual Quantity eatableQuantity(NutrimentA& nutriment) override;
    /*!
     * @brief Looks at the value of the quantity of NutrimentB::
     * that is eatable
     * @param A NutrimentB::
     * @return Quantity that is consumable
     */
    virtual Quantity eatableQuantity(NutrimentB& nutriment) override;
    /*!
      *@ Destructor for the SwarmBacterium::
      */
    virtual ~SwarmBacterium() override;
private:
    Swarm* swarm;
};
