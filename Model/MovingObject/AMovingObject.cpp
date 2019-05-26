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

bool	    AMovingObject::operator==(AMovingObject const & rhs) {
    return(
        this->_position == rhs.getPosition()
        && this->_movementVector == rhs._movementVector
        && this->_character == rhs.getCharacter()
    );
}

AMovingObject::~AMovingObject(void) {
    
}

std::string	AMovingObject::getCharacter(void) const {
    return this->_character;
}

bool	AMovingObject::isOut() {
    return this->getPosition().getOrdinate() > HEIGHT - 10 ? true : false;
}


bool	AMovingObject::move(void) {
    if (this->_position == this->_position + this->_movementVector) {
        return false;
    }

    this->_position = this->_position + this->_movementVector; 
    return true;
}

bool	AMovingObject::isOut(void) const{
    
    return  this->getPosition().getOrdinate() > HEIGHT || this->getPosition().getOrdinate() < 0 ||
            this->getPosition().getAbsciss() > WIDTH || this->getPosition().getAbsciss() < 0 ? true : false;
}

Vector	AMovingObject::getPosition(void) const {
    return this->_position;
}

void	AMovingObject::setMovementVector(Vector const & movementVector) {
    this->_movementVector = movementVector;
}

bool	AMovingObject::collision(AMovingObject const & object) {
    Vector vector(0, 1);
    Vector vector2(0, 2);

    return (
            this->getPosition() == object.getPosition()
            || this->getPosition() == (object.getPosition() + vector)
            || this->getPosition() == (object.getPosition() + vector2)
        );
}

std::ostream & operator<<(std::ostream & o, AMovingObject const & rhs) {
    o << rhs.getPosition() << "character: " << rhs.getCharacter();
    return o;
}