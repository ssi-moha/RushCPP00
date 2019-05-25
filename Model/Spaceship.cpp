#include "Spaceship.hpp"
#include <iostream>

Spaceship::Spaceship(void) {
    
}   

Spaceship::Spaceship(int x, int y) : AMovingObject(x, y, "A") {
    
}

Spaceship::Spaceship(Spaceship const & rhs) {
    *this = rhs;
}

Spaceship::~Spaceship(void) {
       
}   

bool	Spaceship::move(void) {
    if (this->_position == this->_position + this->_movementVector) {
        return false;
    }

    this->_position = this->_position + this->_movementVector;
    this->setMovementVector(Vector(0, 0));
    std::cout << "OK" << std::endl;

    return true;
}

Spaceship &	Spaceship::operator=(Spaceship const & rhs) {
    this->_position = rhs.getPosition();

    return *this;
}