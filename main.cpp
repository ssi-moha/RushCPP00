#include <iostream>
#include <ncurses.h>


#include <ncurses.h>
#include <unistd.h>  /* only for sleep() */
#include "Controleur/Game.hpp"

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
/*
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
    int x,y;
    x=y=10;
    int input;

    initscr();

    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    scrollok(stdscr, TRUE);
    move(x,y);
    printw("x");
    curs_set(0);
    while (1) {
        
        if (kbhit()) {
            clear();
            input = getch();
            if(input == UP)
            {
                y -= 1;
                move(y,x);
                printw("up");
            } 
            if(input == DOWN)
            {
                y += 1;
                move(y,x);
                printw("down");
            } 
            if(input == LEFT)
            {
                x -= 1;
                move(y,x);
                printw("left");
            } 
            if(input == RIGHT)
            {
                move(y,x);
                printw("rigth");
                x += 1;
            }
            else
            {
                
            }
            
            move(y,x);
            
            printw("x");
            refresh();
        } else {
            usleep(100);
        }
    }
}
