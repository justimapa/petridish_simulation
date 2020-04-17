#pragma once
#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"


class Swarm;

class SwarmBacterium: public Bacterium, public DiffEqFunction
{
public:
    SwarmBacterium(Vec2d const& position, Swarm* swarm);
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
     * @return Returns the force vector exercised by the leader
     */
    Vec2d f(Vec2d position, Vec2d direction) const override;
    /*!
     * @brief Getter for the speed vector of the SwarmBacterium::
     * @return The speed vector of the SwarmBacterium::
     */
    Vec2d getSpeedVector();
    void drawOn(sf::RenderTarget &targetWindow) const override;
    Bacterium* clone() override;
    void move(sf::Time dt) override;
    void tumble();
    ~SwarmBacterium();
private:
    Swarm* swarm;
};
