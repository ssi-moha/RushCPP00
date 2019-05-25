#ifndef SPACESHIP_H
# define SPACESHIP_H
# include "AMovingObject.hpp"

class Spaceship : public AMovingObject {

public:

    Spaceship( void );
    Spaceship(int x, int y);
    Spaceship(Spaceship const & src);
    ~Spaceship( void );

    Spaceship &  operator=(Spaceship const & rhs);

    virtual bool        move(void);           

private:

    

};

#endif