#include <iostream>
#include <ncurses.h>
#include "Model/MovingObject/Enemy.hpp"
#include "Model/MovingObject/Meteor.hpp"
#include "Vue/Render.hpp"
#include "Model/Player.hpp"
#include "Model/MovingObject/Spaceship.hpp"
#include "Model/ObjectList.hpp"
#include "Model/RocketList.hpp"

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define WIDTH 150
#define HEIGHT 50
#define SPACE 32
#define WIDTH 150
#define HEIGHT 50


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
        flushinp();
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
    ObjectList enemyList;
    ObjectList meteorList;
    RocketList rocketList;
    Spaceship spaceship(WIDTH / 2, HEIGHT - 2);
    while(1)
    {
        if (kbhit())
        {   
            move = getInputMove(getch());
            if (move.getAbsciss() == SPACE) {
                spaceship.shoot(&rocketList);
            } else {
                spaceship.setMovementVector(move);
            }
            getch();
        }
        erase();
        if ((rand() % 10) <= 1) {
            meteorList.add(new Meteor(randomspown(), 0));
        }
        enemyList.add(new Enemy(randomspown(), 0));
        enemyList.add(&spaceship);

        napms(100);
        
        if (!rocketList.moveAll(&enemyList)) {
            player.setScore(player.getScore() + 5);
        }
        if (!enemyList.moveAll(spaceship) || !meteorList.moveAll(spaceship)) {
            break;
        }
        
        meteorList.displayAll(render);
        enemyList.displayAll(render);
        rocketList.displayAll(render);
        mvprintw(WIDTH / 4, HEIGHT / 2, "Name: %s\nScore: %d", player.getName().c_str(), player.getScore());
        refresh();
    }
    endwin();
}
