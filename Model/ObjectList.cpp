#include "ObjectList.hpp"
#include "MovingObject/Spaceship.hpp"
#include "MovingObject/AMovingObject.hpp"
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
        if(this->_actual->getElem()->isOut())
        {
            //this->remove(this->_actual->getElem());
        }
        this->_actual = this->_actual->getNext();
    }
    return true;
}