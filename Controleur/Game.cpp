/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:02:00 by avinas            #+#    #+#             */
/*   Updated: 2019/05/25 12:12:59 by avinas           ###   ########.fr       */
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
        this->getInput();

        
    }
    return true;
}