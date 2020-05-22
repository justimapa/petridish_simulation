#pragma once
#include <iostream>
#include "Utility/Vec2d.hpp"
#include "Utility/Utility.hpp"

/*!
 * @class CircularBody::
 * @brief class that represents the geometry and properties of a circular body
 */
class CircularBody
{
public:
   /*!
    * @brief Getter for the position of the center
    * @return Postion of the center of the CircularBody::
    */
   const Vec2d& getPosition() const;
   /*!
    * @brief Getter for the radius
    * @return Radius of the CircularBody::
    */
   double getRadius() const;
   /*!
    * @brief Overloading the = operator for the class
    * @param Value of the CircularBody::
    * @return New value of the CircularBody::
    */
   CircularBody& operator=(CircularBody& other);
   /*!
    * @brief Overloading the > operator for the class
    * @param A CircularBody::
    * @return True if the Body is contained in another, false if not
    */
   bool operator>(CircularBody const& body) const;
   /*!
    * @brief Overloading the & operator for the class
    * @param A Body
    * @return True if the body is colliding with another body, false if not
    */
   bool operator&(CircularBody const& body) const;
   /*!
    * @brief Overloading the > operator for the class
    * @param A point
    * @return True if the point is contained in a body, false if not
    */
   bool operator>(Vec2d const& point) const;
   /*!
    * @brief Changes the position of the CircularBody::
    * @param The amount of the movement
    */
   void move(const Vec2d& distance);
   /*!
    * @brief Tests if "other" is inside the current instance
    * @param The other CircularBody::
    * @return true if "other" is inside our CircularBody, false if not
    */
   bool contains(const CircularBody& other) const;
   /*!
    * @brief Tests if a CircularBody:: collides with another
    * @param The other CircularBody::
    * @return True if the other CircularBody:: collides with our instance, false if not
    */
   bool isColliding(const CircularBody& other) const;
   /*!
    * @brief Tests if a point in space is inside our CircularBody::
    * @param The point in space that will be tested
    * @return True if the point is in our CircularBody::, false if not
    */
   bool contains(const Vec2d& point) const;

   /*!
    * @brief Prints the attributes of the current instance of CircularBody::
    * @param The output float of the print
    * @return The float that we printed in
    */
   std::ostream& print(std::ostream& out) const;

protected:
   /*!
    * @brief Construct a CircularBody:: using values passed as parameters
    * @param Position of the center of the CircularBody::
    * @param Radius of the CircularBody::
    * @return A CircularBody:: with all parameters set
    */
   CircularBody(const Vec2d& position, double radius);
   /*!
    * @brief Construct a CircularBody:: from an exisiting instance of CircularBody::
    * @param Fully constructed CirucularBody::
    * @return A copy of CircularBody::
    */
   CircularBody(const CircularBody& copy);
   /*!
    * @brief Setter for the position
    * @param position to be set
    */
   void setPosition(const Vec2d& position_);
   /*!
    * @brief Setter for the radius
    * @param radius to be set
    */
   void setRadius(double radius);

private:
    Vec2d position;
    double radius;
};

/*!
 * @brief Overloading the << operator for the class
 * @param Float where we will be printing
 * @param The CircularBody:: who's attributes we will printing
 * @return The float where we printed
 */
std::ostream& operator<<(std::ostream& out, CircularBody const& body);
