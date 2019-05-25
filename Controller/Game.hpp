/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:01:57 by avinas            #+#    #+#             */
/*   Updated: 2019/05/25 18:50:45 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include "../Model/Player.hpp"
#include "../Model/Spaceship.hpp"
#include "../Model/Vector.hpp"
#include "../Model/Enemy.hpp"
#include "../Model/ObjectList.hpp"


#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

class Game {

public:

    Game(Player const & player);
    Game(Game const & src);
    ~Game( void );

    Game &  operator=(Game const & rhs);


    bool run();

private:
    Game(void);
    Player      _player;
    ObjectList  _movingthing;

    Vector  _getInputMove() const;
    int     _randomspown() const;
    int     _kbhit(void) const;
    

};


#endif