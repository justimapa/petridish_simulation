#pragma once
#include "CircularBody.hpp"

/*!
 * @class Grip
 * @brief class that represents the tentacle
 * of a bacteria
 *
 * Subclass of CircularBody
 */
class Grip : public CircularBody
{
public:
    /*!
     * @brief Constructs a Grip:: fully set up
     * @param Position
     * @param Radius
     * @return A Grip:: with all parameters set
     */
    Grip(const Vec2d& position_, double radius_);
    /*!
     * @brief Changes the position of the Grip::
     * @param The amount of the movement
     */
    void move(const Vec2d& distance);
    /*!
     * @brief Destructor of the Grip::
     */
    ~Grip();
};
