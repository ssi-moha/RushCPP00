#ifndef MOVINGOBJECT_H
# define MOVINGOBJECT_H

class MovingObject {

public:

    MovingObject( void );
    MovingObject(int x, int y);
    MovingObject(MovingObject const & src);
    ~MovingObject( void );

    MovingObject &  operator=(MovingObject const & rhs);

    virtual void move(int new_x, int new_y) = 0;
    
private:

    Vector const & _position; 

};

#endif