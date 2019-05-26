#ifndef METEOR_H
# define METEOR_H
# include "AMovingObject.hpp"

class Meteor: public AMovingObject {

public:

    Meteor( void );
    Meteor(int x, int y);
    Meteor(Meteor const & src);
    ~Meteor( void );

    Meteor &  operator=(Meteor const & rhs);

private:

    

};

#endif