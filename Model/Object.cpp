#include "Object.hpp"

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

Object  *Object::getNext() {
    return this->_next;
}

AMovingObject  *Object::getElem() {
    return this->_elem;
}