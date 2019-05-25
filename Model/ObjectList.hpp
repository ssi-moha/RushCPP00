#ifndef OBJECTLIST_H
# define OBJECTLIST_H

# include "Object.hpp"


class ObjectList {

public:

    ObjectList( void );
    ObjectList(ObjectList const & src);
    ~ObjectList( void );

    ObjectList &  operator=(ObjectList const & rhs);

private:
    Object   *_first;
    Object   *_actual;
    

};

#endif