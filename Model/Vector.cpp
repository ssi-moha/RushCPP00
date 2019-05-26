#include "Vector.hpp"
#include <iostream>
#include <sstream>

Vector::Vector(void) : _x(0), _y(0) {
    
}

Vector::Vector(int x, int y) : _x(x), _y(y) {

}

Vector::Vector(Vector const & src) {
    *this = src;
}

Vector::~Vector(void) {
        
}

Vector &	Vector::operator=(Vector const & rhs) {
    _x = rhs.getAbsciss();
    _y = rhs.getOrdinate();
    
    return *this;
}

bool	Vector::operator==(Vector const & rhs) {
    return (this->_x == rhs.getAbsciss() && this->_y == rhs.getOrdinate());
}

Vector	    Vector::operator+(Vector const & rhs) {
    return Vector(_x + rhs.getAbsciss(), _y + rhs.getOrdinate());
}
Vector	    Vector::operator-(Vector const & rhs) {
    return Vector(_x - rhs.getAbsciss(), _y - rhs.getOrdinate());
}

int	    Vector::getAbsciss(void) const {
    return this->_x;
}

int	    Vector::getOrdinate(void) const {
    return this->_y;
}

void	Vector::setAbsciss(int new_x) {
    _x = new_x;
}

void	Vector::setOrdinate(int new_y) {
    _y = new_y;
}

std::ostream & operator<<(std::ostream & o, Vector const & rhs) {
    o << "x: " << rhs.getAbsciss() << std::endl << "y: " << rhs.getOrdinate() << std::endl;
    return o;
}