#include <iostream>
#include "CircularBody.hpp"


using namespace std;

Vec2d CircularBody::getPosition()const
{
    return position;
}
double  CircularBody::getRadius()const
{
    return radius;
}

CircularBody& CircularBody::operator=(CircularBody& other)
{
    position=other.position;
    radius=other.radius;
    return (*this);
}
bool CircularBody::operator>(CircularBody const& body)
{
    return contains(body);
}
bool CircularBody::operator&(CircularBody const& body)
{
    return isColliding(body);
}
bool CircularBody::operator>(Vec2d const& point)
{
    return contains(point);
}

void CircularBody::move(Vec2d distance)
{
    position+=distance;
}
bool CircularBody::contains(CircularBody const& other)const
{
    return(radius>=other.radius and distance(position,other.position)<=radius-other.radius);
}
bool CircularBody::contains(Vec2d const& point)const
{
    return distance(position,point)<=radius;
}
bool CircularBody::isColliding(CircularBody const& other)const
{
    return distance(position,other.position)<=radius+other.radius;
}
ostream& CircularBody::print(ostream& out) const
{
    out << "CircularBody: position = " << position << " radius = " << radius;
    return out;
}

CircularBody::CircularBody(Vec2d const& position,double const& radius)
: position(position),
  radius(radius)
{ }
CircularBody::CircularBody(CircularBody const& copy)
: position(copy.getPosition()),
  radius(copy.getRadius())
{ }

void CircularBody::setPosition(const Vec2d& position_)
{
    position=position_;
}
void CircularBody::setRadius(double radius_)
{
    radius=radius_;
}

ostream& operator<<(ostream& out, CircularBody const& body)
{
    return body.print(out);
}




