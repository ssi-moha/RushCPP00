#include "AMovingObject.hpp" 
#include <iostream>
#include <sstream>

AMovingObject::AMovingObject(void) {

}

AMovingObject::AMovingObject(int x, int y) : _position(Vector(x, y)) {
    
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

Vector	AMovingObject::getPosition(void) const {
    return this->_position;
}

std::ostream & operator<<(std::ostream & o, AMovingObject const & rhs) {
    o << rhs.getPosition();
    return o;
}