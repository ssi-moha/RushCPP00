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

void    ObjectList::add(AMovingObject *elem) {
     Object *newObj = new Object(elem, _first);
     
     this->_first = newObj;
}

void    ObjectList::remove(AMovingObject *elem) {
    Object *temp = NULL;
    
    this->_actual = this->_first;
    
    while(this->_actual != NULL)
    {
        
        if (this->_actual->getElem() == elem)
        {
            if (temp != NULL)
                temp->setNext(this->_actual->getNext());
            else
                this->_first = this->_actual->getNext();
            delete _actual->getElem();
            delete _actual;
            break;
        }
        temp = _actual;
        this->_actual = this->_actual->getNext();
    }
}

void    ObjectList::displayAll(Render render) {
    this->_actual = this->_first;

    while(this->_actual != NULL)
    {
        render.display(*(this->_actual->getElem()));

        
        if (this->_actual->getElem()->isOut() && this->_actual->getElem()->getCharacter() == "V")
        {     
            this->remove(this->_actual->getElem());   
        }
        this->_actual = this->_actual->getNext();
        
    }
}

void    ObjectList::moveAll(void) {
    this->_actual = this->_first;

    while(this->_actual != NULL)
    {
        if (!this->_actual->getElem()->getCharacter().compare("V")) {
            this->_actual->getElem()->setMovementVector(Vector(0, 1));
        } else if (!this->_actual->getElem()->getCharacter().compare("|")) {
            this->_actual->getElem()->setMovementVector(Vector(0, -1));
        }
        this->_actual->getElem()->move();
        this->_actual = this->_actual->getNext();
    }
}