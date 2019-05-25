#ifndef OBJECTLIST_H
# define OBJECTLIST_H

# include "AMovingObject.hpp"
class Object {

public:

    
    Object(AMovingObject *elem);
    Object(Object const & src);
    ~Object( void );

    Object &  operator=(Object const & rhs);


private:
    Object( void );
    AMovingObject *_elem;
    AMovingObject *next;
    

};

#endif