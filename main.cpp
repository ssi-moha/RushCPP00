#include <iostream>
#include <ncurses.h>


#include <ncurses.h>
#include <unistd.h>  /* only for sleep() */
#include "Controller/Game.hpp"

/*
int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}
int main(void)
{
    initscr();

    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    scrollok(stdscr, TRUE);
    while (1) {
        if (kbhit()) {
            printw("Key pressed! It was: %d\n", getch());
            printw("Key pressed! It was: %d\n", getch());
            refresh();
        } else {
            
            
        }
    }
}
*/

int main(void)
{
    initscr();

    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    curs_set(0);

    Player player("roger");
    Game game(player);    
}
