#ifndef OBJECTLIST_H
# define OBJECTLIST_H

# include "Object.hpp"
# include "AMovingObject.hpp"


class ObjectList {

public:

    ObjectList( void );
    ObjectList(ObjectList const & src);
    ~ObjectList( void );

    ObjectList &  operator=(ObjectList const & rhs);

    void    remove(AMovingObject *rElem);
    void    add(AMovingObject *elem);
    void    updateAll();

private:
    Object   *_first;
    Object   *_actual;
};

#endif