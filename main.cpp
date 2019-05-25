#include <iostream>
#include <ncurses.h>



#include <ncurses.h>
#include <unistd.h>  /* only for sleep() */

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

/*
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
            input = getch();
            if(input == 119)
            {
                x -= 1;  
            } 
            if(input == 115)
            {
                x += 1;
            } 
            if(input == 97)
            {
                y -= 1;
            } 
            if(input == 100)
            {
                y += 1;
            }
            else
            {
                
            }
            clear();
            move(x,y);
            
            printw("x");
            refresh();
        } else {
            usleep(100);
        }
    }
}
*/