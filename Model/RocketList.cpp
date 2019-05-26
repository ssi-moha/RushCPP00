#include "RocketList.hpp"
#include "MovingObject/AMovingObject.hpp"
#include "MovingObject/Spaceship.hpp"
#include "Object.hpp"
#include <ncurses.h>

RocketList::RocketList() : ObjectList(){
    
}

RocketList::~RocketList() {
    
}

RocketList::RocketList(RocketList const & src) {
    *this = src;
}

RocketList &       RocketList::operator=(RocketList const & rhs) {
    if ( this != &rhs )
    {
        this->_first = rhs.getFirst();
        this->_actual = rhs.getActual();
    }
    return *this;
}

bool    RocketList::hit(Object *elem, ObjectList *enemyList ){
    Object *tmp;
    tmp = enemyList->getFirst();
    while (tmp != NULL) {

        if (elem->getElem()->collision(*(tmp->getElem()))) {
            enemyList->remove(tmp->getElem());
            this->remove(elem->getElem());
            return false;
        }
        tmp = tmp->getNext();
    }
    
    return true;
}

bool    RocketList::moveAll(ObjectList *enemyList) {
    
    Object *elem;

    
    elem = this->_first;
        
    while(elem != NULL)
    {

        if(!this->hit(elem, enemyList))
            return false;
        elem->getElem()->setMovementVector(Vector(0, -1));
        elem->getElem()->move();

        if(!this->hit(elem, enemyList))
            return false;
        elem = elem->getNext();
    }
    return true;
}