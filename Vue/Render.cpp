# include "Render.hpp"
# include <ncurses.h>

Render::Render(void) {
    
}

Render::~Render(void) {
    
}

Render::Render(Render const & src) {
    *this = src;
}

void	Render::display(AMovingObject const & objectToDisplay) {
    Vector  printPosition(objectToDisplay.getPosition());
    
    mvprintw(printPosition.getOrdinate(), printPosition.getAbsciss(), objectToDisplay.getCharacter().c_str());
    
}

Render &	Render::operator=(Render const & rhs) {
    (void)rhs;
    return *this;
}