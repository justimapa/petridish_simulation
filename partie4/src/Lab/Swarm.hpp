#pragma once
#include "Interface/Updatable.hpp"
#include <string>
#include "Utility/Vec2d.hpp"
#include "Utility/Utility.hpp"


class SwarmBacterium;

class Swarm: public Updatable
{
public:
    Swarm(const std::string& id);
    /*!
     * @brief Adds a SwarmBacterium:: to the group
     */
    void addSwarmBacterium(SwarmBacterium* );
    /*!
     * @brief removes a SwarmBacterium:: to the group
     */
    void removeSwarmBacterium(SwarmBacterium* );
    /*!
     * @brief Getter for the position of the leader
     * @return Position (Vec2d) of the leader
     */
    const Vec2d& getLeaderPosition()const;
    /*!
     * @brief Getter for the inital color of the Swarm
     * @return THe value of the inital color form the configuration file
     */
    j::Value& getInitialColor()const;
    /*!
     * @brief Getter for the Id
     * @return id (string) of the Swarm::
     */
    std::string getId()const;
    /*!
     * @brief Updates the swarm
     * @param Time delay between updates
     */
    void update(sf::Time dt);
    bool isLeader(const SwarmBacterium *)const;
    bool hasLeader()const;
    ~Swarm();
private:
    std::string id;
    std::vector<SwarmBacterium*> group;
    SwarmBacterium* leader;
};
