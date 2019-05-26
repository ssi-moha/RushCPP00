#include <iostream>
#include <ncurses.h>
#include "Model/MovingObject/Enemy.hpp"
#include "Vue/Render.hpp"
#include "Model/Player.hpp"
#include "Controller/Game.hpp"

int main()
{	

    srand(time(NULL));
	initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    //keypad();

    //curs_set(0);
    scrollok(stdscr, TRUE);
    Player player("roger");
    Game game(player);
    game.run();
    
    endwin();
}
