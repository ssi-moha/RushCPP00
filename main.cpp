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
    Player player("roger");
    Game game(player);
    game.run();
    
    endwin();
}
