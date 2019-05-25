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

    virtual void    move( void );                                       // add _movementVector to _position
    Vector          getPosition( void ) const;
    void            setMovementVector(Vector const & movementVector);

protected:

    Vector          _position; 
    Vector          _movementVector;
};

std::ostream & operator<<(std::ostream & o, AMovingObject const & rhs);

#endif