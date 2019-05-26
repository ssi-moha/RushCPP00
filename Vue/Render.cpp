# include "Render.hpp"
# include "../Model/MovingObject/AMovingObject.hpp"
# include "../Model/Player.hpp"
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

void	Render::display(Player player) {
    mvprintw(WIDTH / 4, HEIGHT / 2, "Name: %s\nScore: %d", player.getName().c_str(), player.getScore());
}

Render &	Render::operator=(Render const & rhs) {
    (void)rhs;
    return *this;
}