#ifndef OBJECT_H
# define OBJECT_H

# include "AMovingObject.hpp"
class Object {

public:

    
    Object(AMovingObject *elem, Object *next);
    Object(Object const & src);
    ~Object( void );

    Object &  operator=(Object const & rhs);

    Object  *getNext();
    AMovingObject  *getElem();

private:
    Object( void );
    AMovingObject *_elem;
    Object *_next;
    
};

#endif