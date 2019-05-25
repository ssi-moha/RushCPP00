/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:01:53 by avinas            #+#    #+#             */
/*   Updated: 2019/05/25 13:52:25 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(std::string name) : _name(name), _alive(true) {
    
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
