#include <iostream>
#include <ncurses.h>



int main()
{	
	initscr();
	
    int x = 0;
    int y = 0;

    move(x, y);

    printw("Hello World!!!");

    int c = getch();
    refresh();

    move(x, y);
    printw("%d", c);
	refresh();

	getch();
	endwin();

	return 0;
}
