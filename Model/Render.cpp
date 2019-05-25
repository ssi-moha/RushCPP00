# include "Render.hpp"
# include <ncurses.h>

Render::Render(void) {
    
}

Render::~Render(void) {
    
}   

void	Render::display(AMovingObject const & objectToDisplay) {
    Vector  printPosition(objectToDisplay.getPosition());

    
    mvprintw(printPosition.getOrdinate(), printPosition.getAbsciss(), objectToDisplay.getCharacter().c_str());
    refresh();
}