#ifndef AMOVINGOBJECT_H
# define AMOVINGOBJECT_H
# include <sstream>
# include "../Vector.hpp"
# include "../ObjectList.hpp"

#define WIDTH 150
#define HEIGHT 50

class AMovingObject {

public:

    AMovingObject( void );
    AMovingObject(int x, int y, std::string character);
    AMovingObject(AMovingObject const & src);
    virtual ~AMovingObject( void );

    AMovingObject &     operator=(AMovingObject const & rhs);
    bool                operator==(AMovingObject const & rhs);

    virtual bool                move( void );                                       // add _movementVector to _position
    Vector                      getPosition( void ) const;
    std::string                 getCharacter( void ) const;
    void                        setMovementVector(Vector const & movementVector);
    bool                        collision(AMovingObject const & enemy);
    
    bool                        isOut(void);                        

protected:
    Vector          _position; 
    Vector          _movementVector;
    std::string     _character;            
};

std::ostream & operator<<(std::ostream & o, AMovingObject const & rhs);

#endif