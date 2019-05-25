#include "ObjectList.hpp"

ObjectList::ObjectList() : _first(NULL), _actual(NULL){
    
}
ObjectList::~ObjectList() {
    
}

ObjectList       &ObjectList::operator=(ObjectList const & rhs) {
    if ( this != &rhs )
    {
        this->_first = rhs._first;
        this->_actual = rhs._actual;
    }
    return *this;
}

void    ObjectList::add(AMovingObject *elem) {
     Object *newObj = new Object(elem, _first);
     
     this->_first = newObj;
}

void    ObjectList::remove(AMovingObject *elem) {
    Object *temp = this->_first;
     
    this->_actual = this->_first;

    while(this->_actual != NULL)
    {
        temp = this->_actual->getNext();
        
        if (this->_actual->getElem() == elem)
        {
            delete _actual;
            _actual = temp;
            break;
        }
    }
}

void    ObjectList::forEach(void (*callbackFunction)(AMovingObject *elem)) {
    this->_actual = this->_first;

    while(this->_actual != NULL)
    {
        callbackFunction(this->_actual->getElem());
        this->_actual = this->_actual->getNext();
    }
}