/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:02:00 by avinas            #+#    #+#             */
/*   Updated: 2019/05/25 20:20:02 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "../Vue/Render.hpp"
#include "../Model/MovingObject/Spaceship.hpp"
#include <unistd.h>

Game::Game(Player const & player) : _player(player) {
    this->_movingthing = ObjectList();
    this->_player.setAlive(true);
    
}
Game::Game(Game const & src) {
    *this = src;
}

Game::~Game() {
    
}

bool    Game::run() {
    Render render;
    Spaceship spaceship(50,110);
    while(1)
    {
        Vector move = this->_getInputMove();
        erase();
        _movingthing.add(new Enemy(_randomspown(), 0));
        usleep(100000);
        _movingthing.moveAll();
        
        _movingthing.displayAll(render);
        spaceship.move();
        render.display(spaceship);
        mvprintw(63, 110, "x: %d      y: %d", spaceship.getPosition().getOrdinate(), spaceship.getPosition().getAbsciss());
        
        refresh();
    }
    return true;
}

int     Game::_randomspown() const {
    return rand() % 220;
}

Vector  Game::_getInputMove() const {
    Vector vector;
    if (this->_kbhit()) {
        mvprintw(60, 110, "roger");
        int ch = getch();
        
        switch(ch)
        {
            case UP  :
                vector.setOrdinate(1);
            break;
            case DOWN : 
                vector.setOrdinate(-1);
            break;
            case LEFT : 
                vector.setAbsciss(-1);
            break;
            case RIGHT : 
                vector.setAbsciss(+1);
            break;

        }
    } 
    return vector;
}

Game       &Game::operator=(Game const & rhs) {
    if ( this != &rhs )
    {
        this->_player = rhs._player;
        this->_movingthing = rhs._movingthing;
    }
    return *this;
}

int Game::_kbhit(void) const {
    
    int ch = getch();
    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}
