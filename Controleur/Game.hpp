/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:01:57 by avinas            #+#    #+#             */
/*   Updated: 2019/05/25 12:56:47 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include "../Model/Player.hpp"
#include "../Model/Vector.hpp"


#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

class Game {

public:

    Game(Player player);
    Game(Game const & src);
    ~Game( void );

    Game &  operator=(Game const & rhs);

    bool run();

private:
    Player  player;
    Vector  getInputMove() const;
    

};


#endif