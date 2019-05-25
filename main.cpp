#include <iostream>
#include <ncurses.h>
#include "Model/Enemy.hpp"
#include "Model/Render.hpp"

int main()
{	
	initscr();
	
    Enemy a(5, 8);
    Enemy b(7, 9);
    Render render;

    render.display(a);
    render.display(b);

	getch();
	endwin();

    Player player("roger");
    Game game(player);    
}
