#include "Meteor.hpp"

Meteor::Meteor(void) {
    
}

Meteor::Meteor(int x, int y): AMovingObject(x, y, "*") {
    
}

Meteor::Meteor(Meteor const & src) {
    *this = src;
}

Meteor::~Meteor(void) {
    
}

Meteor &	Meteor::operator=(Meteor const & rhs) {
    this->_position = rhs.getPosition();

    return *this;
}