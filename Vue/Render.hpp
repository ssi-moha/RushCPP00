#ifndef RENDER_H
# define RENDER_H


class AMovingObject;

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