#ifndef ROCKETLIST_H
# define ROCKETLIST_H
# include "ObjectList.hpp"

class RocketList: public ObjectList {

public:

    RocketList( void );
    RocketList(RocketList const & src);
    ~RocketList( void );

    RocketList &  operator=(RocketList const & rhs);
    
    bool    moveAll(ObjectList *enemyList);

private:

    bool    hit(Object *elem, ObjectList *enemyList );

};

#endif