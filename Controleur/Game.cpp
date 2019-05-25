/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:02:00 by avinas            #+#    #+#             */
/*   Updated: 2019/05/25 13:07:10 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(Player player) : player(player) {
    
}

Game::~Game() {
    
}

bool    Game::run() {
    
    while(this->player.isAlive())
    {
        Vector move = this->getInputMove();
        
        
    }
    return true;
}

Vector  Game::getInputMove() const {
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