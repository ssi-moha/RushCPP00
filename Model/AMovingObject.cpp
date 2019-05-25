#include "AMovingObject.hpp" 
#include <iostream>
#include <sstream>

AMovingObject::AMovingObject(void) {

}

AMovingObject::AMovingObject(int x, int y, std::string character)
:   _position(Vector(x, y)),
    _movementVector(0, 0),
    _character(character) {
    
}

AMovingObject::AMovingObject(AMovingObject const & src) {
    *this = src;
}

AMovingObject &	AMovingObject::operator=(AMovingObject const & rhs) {
    this->_position = rhs.getPosition();
    
    return *this;
}

bool	    AMovingObject::operator=(AMovingObject const & rhs) {
    return(
        this->_position == rhs.getPosition()
        && this->_movementVector == rhs._movementVector()
        && this->_character == rhs._character()
    );
}

AMovingObject::~AMovingObject(void) {
    
}

std::string	AMovingObject::getCharacter(void) const {
    return this->_character;
}


bool	AMovingObject::move(void) {
    if (this->_position == this->_position + this->_movementVector) {
        return false;
    }

    this->_position = this->_position + this->_movementVector; 
    return true;
}

Vector	AMovingObject::getPosition(void) const {
    return this->_position;
}

void	AMovingObject::setMovementVector(Vector const & movementVector) {
    this->_movementVector = movementVector;
}

std::ostream & operator<<(std::ostream & o, AMovingObject const & rhs) {
    o << rhs.getPosition() << "character: " << rhs.getCharacter();
    return o;
}