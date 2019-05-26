#ifndef ENEMY_H
# define ENEMY_H
# include "AMovingObject.hpp"
# include "Spaceship.hpp"

class Spaceship;

class Enemy: public AMovingObject {

public:

    Enemy( void );
    Enemy(int x, int y);
    Enemy(Enemy const & src);
    ~Enemy( void );

    Enemy &  operator=(Enemy const & rhs);

    
private:

    

};

#endif