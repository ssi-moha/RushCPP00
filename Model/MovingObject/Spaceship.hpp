#ifndef SPACESHIP_H
# define SPACESHIP_H
# include "AMovingObject.hpp"

class ObjectList;

class Spaceship : public AMovingObject {

public:

    Spaceship( void );
    Spaceship(int x, int y);
    Spaceship(Spaceship const & src);
    ~Spaceship( void );

    Spaceship &  operator=(Spaceship const & rhs);

    virtual bool        move(void);
    void                shoot(ObjectList *list);
    

private:

    

};

#endif