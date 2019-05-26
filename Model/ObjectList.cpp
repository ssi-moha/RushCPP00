#include "ObjectList.hpp"
#include <ncurses.h>

ObjectList::ObjectList() : _first(NULL), _actual(NULL){
    
}
ObjectList::~ObjectList() {
    
}

ObjectList::ObjectList(ObjectList const & src) {
    *this = src;
}

ObjectList       &ObjectList::operator=(ObjectList const & rhs) {
    if ( this != &rhs )
    {
        this->_first = rhs._first;
        this->_actual = rhs._actual;
    }
    return *this;
}

Object *	ObjectList::getFirst(void) const {
    return this->_first;
}

Object *	ObjectList::getActual(void) const {
    return this->_actual;
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

void    ObjectList::displayAll(Render render) {
    this->_actual = this->_first;

    while(this->_actual != NULL)
    {
        render.display(*(this->_actual->getElem()));
        this->_actual = this->_actual->getNext();
    }
}

bool    ObjectList::moveAll(Spaceship spaceship) {
    this->_actual = this->_first;

    while(this->_actual != NULL)
    {
        if (!this->_actual->getElem()->getCharacter().compare("V")) {
            this->_actual->getElem()->setMovementVector(Vector(0, 1));
            if (spaceship.collision(*(this->_actual->getElem())) == true)
                return false;
        }
        this->_actual->getElem()->move();
        this->_actual = this->_actual->getNext();
    }
    return true;
}