#pragma once
#include "Interface/Updatable.hpp"
#include <string>
#include "Utility/Vec2d.hpp"
#include "Utility/Utility.hpp"

/*!
 *Predeclaration of the SwarmBacterium:: class
 */
class SwarmBacterium;

/*!
 * @class Swarm
 * @brief class representing the swarm of the SwarmBacterium::
 *
 * Subclass of Updatable
 */
class Swarm: public Updatable
{
public:
    /*!
     * @brief Swarm:: Constructor
     * @param The ID of the swarm
     */
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
    virtual void update(sf::Time dt) override;
    /*!
     * @brief Checks if a SwarmBacterium:: is the Leader of the Swarm::
     * @return True if the SwarmBacterium:: is the Leader, false otherwise.
     */
    bool isLeader(const SwarmBacterium *)const;
    /*!
     * @brief Checks if the Swarm:: has a leader
     * @return True if the leader is not a nullptr, false otherwise.
     */
    bool hasLeader()const;
    /*!
     * @brief Resets the Swarm
     */
    void resetSwarm();
    /*!
      *@brief Destructor for the Swarm::
      */
    virtual ~Swarm() override;
private:
    std::string id;
    std::vector<SwarmBacterium*> group;
    SwarmBacterium* leader;
    //Id of the petridish the Swarm is in::
    int petridishId;
};
