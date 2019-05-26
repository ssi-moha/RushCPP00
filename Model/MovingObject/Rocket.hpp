#ifndef ROCKET_H
# define ROCKET_H
# include "AMovingObject.hpp"

class Rocket {

public:

    Rocket( void );
    Rocket(int x, int y);
    Rocket(Rocket const & src);
    ~Rocket( void );

    Rocket &  operator=(Rocket const & rhs);


private:

    

};

#endif