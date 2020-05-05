#include "CircularBody.hpp"

using namespace std;

const Vec2d& CircularBody::getPosition() const
{
    return position;
}
double  CircularBody::getRadius() const
{
    return radius;
}

CircularBody& CircularBody::operator=(CircularBody& other)
{
    position=other.position;
    radius=other.radius;
    return (*this);
}
bool CircularBody::operator>(CircularBody const& body) const
{
    return contains(body);
}
bool CircularBody::operator&(CircularBody const& body) const
{
    return isColliding(body);
}
bool CircularBody::operator>(Vec2d const& point) const
{
    return contains(point);
}
void CircularBody::move(const Vec2d& distance)
{
    position+=distance;
}
bool CircularBody::contains(const CircularBody& other) const
{
    return(radius>=other.radius) and (distance(position,other.position)<=radius-other.radius);
}
bool CircularBody::isColliding(const CircularBody& other) const
{
    return distance(position,other.position)<=radius+other.radius;
}
bool CircularBody::contains(const Vec2d& point) const
{
    return distance(position,point)<=radius;
}

ostream& CircularBody::print(ostream& out) const
{
    out << "CircularBody: position = " << position << " radius = " << radius;
    return out;
}

CircularBody::CircularBody(const Vec2d& position,double radius)
    : position(position),
      radius(radius)
{ }
CircularBody::CircularBody(const CircularBody& copy)
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
