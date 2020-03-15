#pragma once

#include <iostream>
#include "Utility/Vec2d.hpp"
#include "Utility/Utility.hpp"

class CircularBody
{


public:
    /*!
     * @brief Construct a CircularBody:: fully set up
    *
    * @param position of the position of the CircularBody
    * @param radius of the CircularBody
    *
    * @return a CircularBody:: with all parameters set
    */
   CircularBody(Vec2d const& position,double const& radius);
   /*!
    * @brief Construct a CircularBody:: from an instance of CircularBody::
    *
    * @param Fully constructed CirucularBody::
    *
    * @return a copy of CircularBody::
    */
   CircularBody(CircularBody const& copy);
   /*!
    * @brief Get the postion of the instance
    *
    * @return Postion of the CircularBody
    */
   Vec2d getPosition()const;
   /*!
    * @brief Gets the radius of the instance
    * @return returns radius
    */
   double getRadius()const;
   /*!
    * @brief Sets the position of the instance
    * @return returns position
    */
   void setPosition(Vec2d& position_);
   /*!
    * @brief Sets the radius
    * @param Radius that will be set
    */
   void setRadius(double& radius);
   /*!
    * @brief Overloading the = operator for the Circulbody::
    * @param Value of the CircularBody::
    * @return New value for CircularBody::
    */
   CircularBody& operator=(CircularBody& other);
   /*!
    * @brief Increments the position of the CircularBody::
    * @param The ammount of the movement
    */
   void move(Vec2d distance);
   /*!
    * @brief Tests if a CircularBody is inside another
    * @param The other CircularBody
    * @return true if the other CircularBody has a smaller radius and the center is
    * withing our CircularBody if not it returns false
    */
   bool contains(CircularBody const& other)const;
   /*!
    * @brief Tests if a CircularBody is in collision with another
    * @param The other CircularBody
    * @return True if the other CircularBody is in collision with our instance false if not
    */
   bool isColliding(CircularBody const& other)const;
   /*!
    * @brief Tests if a Point in space is inside our CircularBody
    * @param The point in space that will be tested
    * @return True if the point is in our CircularBody false if not
    */
   bool contains(Vec2d const& point)const;
   /*!
    * @brief Prints the attributes of the current instance of CircularBody
    * @param The output flot of the print
    * @return the flot that we printed in.
    */
   std::ostream& print(std::ostream& out)const;
   /*!
    * @brief Overloading the > operator for the class
    * @param A CircularBody
    * @return true if the Body is contained in another false if not
    */
   bool operator>(CircularBody const& body);
   /*!
    * @brief Overloading the > operator for the class
    * @param A point
    * @return true if the point is contained in a body false if not
    */
   bool operator>(Vec2d const& point);
   /*!
    * @brief Overloading the & operator for the class
    * @param A Body
    * @return true if the body is colliding with another body false if not
    */
   bool operator&(CircularBody const& body);
private:
    Vec2d position;
    double radius;

};
/*!
 * @brief Overloading the << operator for the class
 * @param flot where will be printing
 * @param The body who's attributed we will printing
 * @return The flot where we printed
 */
std::ostream& operator<<(std::ostream& out, CircularBody const& body);
