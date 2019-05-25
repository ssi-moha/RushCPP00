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

    virtual void    move(Vector const & movingVector) = 0;
    Vector          getPosition( void ) const;

protected:

    Vector          _position; 

};

std::ostream & operator<<(std::ostream & o, AMovingObject const & rhs);

#endif