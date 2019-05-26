/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:01:53 by avinas            #+#    #+#             */
/*   Updated: 2019/05/25 17:44:09 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
Player::Player(void) : _alive(true), _score(0) {
       this->_alive = true;
}
Player::Player(std::string const & name) : _alive(true), _name(name), _score(0) {
    this->_alive = true;
}

Player::Player(Player const & src) {
    *this = src;
}

Player::~Player() {
    
}

void	Player::setScore(int score) {
    _score = score;
}

int	Player::getScore(void) const {
    return this->_score;
}

Player       &Player::operator=(Player const & rhs) {
    if ( this != &rhs )
    {
        this->_name = rhs._name;
    }
    return *this;
}

bool        Player::isAlive() const {
    return this->_alive;
}
void        Player::setAlive(bool alive) {
    this->_alive = alive;
}
std::string Player::getName() const {
    return this->_name;
}
