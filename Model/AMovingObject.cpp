#include "AMovingObject.hpp" 
#include <iostream>
#include <sstream>

AMovingObject::AMovingObject(void) {

}

AMovingObject::AMovingObject(int x, int y) : _position(Vector(x, y)), _movementVector(0, 0) {
    
}

AMovingObject::AMovingObject(AMovingObject const & src) {
    *this = src;
}

AMovingObject &	AMovingObject::operator=(AMovingObject const & rhs) {
    this->_position = rhs.getPosition();
    
    return *this;
}

AMovingObject::~AMovingObject(void) {
    
}

void	AMovingObject::move(void) {
    this->_position = this->_position + this->_movementVector; 
}

Vector	AMovingObject::getPosition(void) const {
    return this->_position;
}

void	AMovingObject::setMovementVector(Vector const & movementVector) {
    this->_movementVector = movementVector;
}

std::ostream & operator<<(std::ostream & o, AMovingObject const & rhs) {
    o << rhs.getPosition();
    return o;
}