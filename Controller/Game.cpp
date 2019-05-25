/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:02:00 by avinas            #+#    #+#             */
/*   Updated: 2019/05/25 18:03:14 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

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
    
    while(this->_player.isAlive())
    {
        Vector move = this->_getInputMove();
        
        _movingthing.add(new Enemy(_randomspown(), 0));
        
    }
    return true;
}

int     Game::_randomspown() const {
    return rand() % 50;
}

Vector  Game::_getInputMove() const {
    int ch = getch();
    Vector vector;
    if (ch != ERR) {
        ungetch(ch);
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