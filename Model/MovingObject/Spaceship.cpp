#include "Spaceship.hpp"
#include "Rocket.hpp"
#include "../ObjectList.hpp"
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
    if (this->isOut())
    {
        this->_position = this->_position - this->_movementVector;
    }
    this->_movementVector = Vector(0, 0);

    return true;
}

Spaceship &	Spaceship::operator=(Spaceship const & rhs) {
    this->_position = rhs.getPosition();

    return *this;
}

void	Spaceship::shoot(ObjectList *list) {
       
       list->add(new Rocket(_position.getAbsciss(), _position.getOrdinate()));
}