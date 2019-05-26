#include <ncurses.h>
#include <iostream>
#include "Model/Enemy.hpp"
#include "Model/Render.hpp"
#include "Model/Player.hpp"
#include "Model/Spaceship.hpp"
#include "Model/ObjectList.hpp"
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
            refresh();
        } else {
            printw("No key pressed yet...\n");
            refresh();
            napms(100);
        }
    }
}