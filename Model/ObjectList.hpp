#ifndef OBJECTLIST_H
# define OBJECTLIST_H

# include "Object.hpp"
# include "MovingObject/AMovingObject.hpp"
# include "MovingObject/Spaceship.hpp"
# include "../Vue/Render.hpp"


class ObjectList {

public:

    ObjectList( void );
    ObjectList(ObjectList const & src);
    ~ObjectList( void );

    ObjectList &  operator=(ObjectList const & rhs);

    void        remove(AMovingObject *rElem);
    void        add(AMovingObject *elem);
    void        displayAll(Render render);
    bool        moveAll(Spaceship spaceship);
    Object *    getFirst( void ) const;
    Object *    getActual( void ) const;

protected:
    Object   *_first;
    Object   *_actual;
};

#endif