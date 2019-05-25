#ifndef AMOVINGOBJECT_H
# define AMOVINGOBJECT_H
# include <sstream>
# include "Vector.hpp"

class AMovingObject {

public:

    AMovingObject( void );
    AMovingObject(int x, int y);
    AMovingObject(AMovingObject const & src);
    ~AMovingObject( void );

    AMovingObject &  operator=(AMovingObject const & rhs);

    virtual void    move(int new_x, int new_y) = 0;
    Vector          getPosition( void ) const;

private:

    Vector          _position; 

};

std::ostream & operator<<(std::ostream & o, AMovingObject const & rhs);

#endif