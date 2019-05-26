#include "Rocket.hpp"

Rocket::Rocket() {
    
}

Rocket::Rocket(int x, int y): AMovingObject(x, y, "|") {
    
}

Rocket::Rocket(Rocket const & src) {
    *this = src;
}

Rocket::~Rocket(void) {
    
}

Rocket &	Rocket::operator=(Rocket const & rhs) {
    this->_position = rhs.getPosition();

    return *this;
}

