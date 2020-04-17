#include "Grip.hpp"

Grip::Grip(const Vec2d& position_, double radius_)
: CircularBody(position_, radius_)
{ }

void Grip::move(const Vec2d& distance){
    CircularBody::move(distance);
}

Grip::~Grip(){

}
