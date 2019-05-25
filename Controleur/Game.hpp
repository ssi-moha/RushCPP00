/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:01:57 by avinas            #+#    #+#             */
/*   Updated: 2019/05/25 12:13:51 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "../Model/Player.hpp"


class Game {

public:

    Game(Player player);
    Game(Game const & src);
    ~Game( void );

    Game &  operator=(Game const & rhs);

    bool run();

private:
    Player player;
Vector  getInput() const;
    

};


#endif