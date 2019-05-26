#include "RocketList.hpp"
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

bool    RocketList::moveAll(ObjectList *enemyList) {
    Object *tmp;
    Object *elem;

    tmp = enemyList->getFirst();
    elem = this->_first;
        
    while(elem != NULL)
    {
        elem->getElem()->setMovementVector(Vector(0, -1));
        elem->getElem()->move();

         while (tmp != NULL) {

            if (elem->getElem()->collision(*(tmp->getElem()))) {
                // remove elem
                return false;
            }
            tmp = tmp->getNext();
        }
        elem = elem->getNext();
    }
    return true;
}