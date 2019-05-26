#include "AMovingObject.hpp" 
#include <iostream>
#include <sstream>
#include <ncurses.h>

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

bool	AMovingObject::move(void) {
    if (this->_position == this->_position + this->_movementVector) {
        return false;
    }

    this->_position = this->_position + this->_movementVector; 
    return true;
}

bool	AMovingObject::isOut(void) {
    
    return  this->getPosition().getOrdinate() > HEIGHT || this->getPosition().getOrdinate() < 0 ||
            this->getPosition().getAbsciss() > WIDTH || this->getPosition().getAbsciss() < 0 ? true : false;
}

Vector	AMovingObject::getPosition(void) const {
    return this->_position;
}

void	AMovingObject::setMovementVector(Vector const & movementVector) {
    this->_movementVector = movementVector;
}

void    AMovingObject::setMovementVectorRand(AMovingObject spaceship) {
    
    int i = rand() % 100;
    
    if(spaceship.getPosition().getAbsciss() > this->getPosition().getAbsciss())
    {
        if (i < 80)
        {
            this->_movementVector = Vector(0, 1);
        }
        else if (i >= 80 && i < 95)
        {
            this->_movementVector = Vector(1, 1);
        }
        else
        {
            this->_movementVector = Vector(-1 , 1);
        }
    }
    else
    {
        if (i < 80)
        {
            this->_movementVector = Vector(0, 1);
        }
        else if (i >= 80 && i < 95)
        {
            this->_movementVector = Vector(-1, 1);
        }
        else
        {
            this->_movementVector = Vector(1 , 1);
        }
    }
}

bool	AMovingObject::collision(AMovingObject const & object) {
    Vector vector(1, 0);
    
    if (this->getCharacter() != "|" && this->getCharacter() != "V")
    {
        return (
            (this->getPosition().getAbsciss() - 2 < object.getPosition().getAbsciss() &&
            this->getPosition().getAbsciss() + 2 > object.getPosition().getAbsciss()) &&
            this->getPosition().getOrdinate() == object.getPosition().getOrdinate()
        );
    }
    else
    {
        return (
            this->getPosition() == object.getPosition()
        );
    }
       
        

}

std::ostream & operator<<(std::ostream & o, AMovingObject const & rhs) {
    o << rhs.getPosition() << "character: " << rhs.getCharacter();
    return o;
}