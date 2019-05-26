#include <iostream>
#include <ncurses.h>
#include "Model/MovingObject/Enemy.hpp"
#include "Vue/Render.hpp"
#include "Model/Player.hpp"
#include "Model/MovingObject/Spaceship.hpp"
#include "Model/ObjectList.hpp"

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define WIDTH 150
#define HEIGHT 50
#define SPACE 32


int     randomspown() {
    return rand() % WIDTH;
}

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

Vector  getInputMove(int ch) {
    Vector vector;
    
    switch(ch)
    {
        case UP  :
            vector.setOrdinate(-1);
        break;
        case DOWN : 
            vector.setOrdinate(1);
        break;
        case LEFT : 
            vector.setAbsciss(-1);
        break;
        case RIGHT : 
            vector.setAbsciss(+1);
        break;
        case SPACE : 
            vector.setAbsciss(32);
        break;

    }
    
    return vector;
}


int main()
{	

    srand(time(NULL));
	initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    //keypad();

    curs_set(0);
    scrollok(stdscr, TRUE);
    
    Player player("roger");
    Render render;
    Vector move;
    ObjectList movingthing;
    Spaceship spaceship(WIDTH / 2, HEIGHT - 2);
    while(1)
    {
        if (kbhit())
        {   
            move = getInputMove(getch());
            if (move.getAbsciss() == SPACE) {
                spaceship.shoot(&movingthing);
            } else {
                spaceship.setMovementVector(move);
            }
            getch();
        }
        erase();
        movingthing.add(new Enemy(randomspown(), 0));
        movingthing.add(&spaceship);

        napms(100);
        movingthing.moveAll();
        spaceship.move();
        movingthing.displayAll(render);
        
        
        refresh();
    }
    return 0;
    
    endwin();
}
