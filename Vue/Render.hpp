#ifndef RENDER_H
# define RENDER_H
# include "../Model/MovingObject/AMovingObject.hpp"

class Render {

public:

    Render( void );
    Render(Render const & src);
    ~Render( void );

    Render &  operator=(Render const & rhs);

    void    display(AMovingObject const & objectToDisplay);

private:

    

};

#endif