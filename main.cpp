#include <iostream>
#include <ncurses.h>
#include "Model/Enemy.hpp"
#include "Model/Render.hpp"
#include "Model/Player.hpp"
#include "Controller/Game.hpp"

int main()
{	
    srand(time(NULL));
	initscr();

    Enemy a(5, 8);
    Enemy b(7, 9);
    Render render;

    render.display(a);
    render.display(b);
	
    Player player = Player("roger");
    Game game(player);
    game.run();
    
    endwin();
}
