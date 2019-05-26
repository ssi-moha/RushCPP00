#ifndef OBJECTLIST_H
# define OBJECTLIST_H

# include "Object.hpp"
# include "MovingObject/AMovingObject.hpp"
# include "../Vue/Render.hpp"


class ObjectList {

public:

    ObjectList( void );
    ObjectList(ObjectList const & src);
    ~ObjectList( void );

    ObjectList &  operator=(ObjectList const & rhs);

    void    remove(AMovingObject *rElem);
    void    add(AMovingObject *elem);
    void    displayAll(Render render);
    void    moveAll( void );

private:
    Object   *_first;
    Object   *_actual;
};

#endif