#ifndef MOVINGOBJECT_H
# define MOVINGOBJECT_H

class MovingObject {

public:

    MovingObject( void );
    MovingObject(int x, int y);
    MovingObject(MovingObject const & src);
    ~MovingObject( void );

    MovingObject &  operator=(MovingObject const & rhs);


private:

    int x;
    int y;

};

#endif