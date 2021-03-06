#include "Object.hpp"
# include "MovingObject/AMovingObject.hpp"

Object::Object(AMovingObject *elem, Object *next) : _elem(elem), _next(next) {
    
}
Object::~Object() {
    
}

Object       &Object::operator=(Object const & rhs) {
    if ( this != &rhs )
    {
        this->_elem = rhs._elem;
        this->_next = rhs._next;
    }
    return *this;
}

Object  *Object::getNext() const {
    return this->_next;
}
void    Object::setNext(Object *next) {
    this->_next = next;
}

AMovingObject  *Object::getElem() {
    return this->_elem;
}