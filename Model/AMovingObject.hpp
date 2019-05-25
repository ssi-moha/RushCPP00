#ifndef AMOVINGOBJECT_H
# define AMOVINGOBJECT_H
# include <sstream>
# include "Vector.hpp"

class AMovingObject {

public:

    AMovingObject( void );
    AMovingObject(int x, int y, std::string character);
    AMovingObject(AMovingObject const & src);
    ~AMovingObject( void );

    AMovingObject &     operator=(AMovingObject const & rhs);
    bool                operator==(AMovingObject const & rhs);

    virtual bool                move( void );                                       // add _movementVector to _position
    Vector                      getPosition( void ) const;
    std::string                 getCharacter( void ) const;
    void                        setMovementVector(Vector const & movementVector);

protected:

    Vector          _position; 
    Vector          _movementVector;
    std::string     _character;            
};

std::ostream & operator<<(std::ostream & o, AMovingObject const & rhs);

#endif