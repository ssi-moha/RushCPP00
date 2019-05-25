/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:01:53 by avinas            #+#    #+#             */
/*   Updated: 2019/05/25 17:14:03 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
Player::Player(void) {
       
}
Player::Player(std::string const & name) : _alive(true), _name(name) {
    
}

Player::Player(Player const & src) {
    *this = src;
}

Player::~Player() {
    
}

Player       &Player::operator=(Player const & rhs) {
    if ( this != &rhs )
    {
        this->_name = rhs._name;
    }
    return *this;
}

bool        Player::isAlive() {
    return this->_alive;
}
