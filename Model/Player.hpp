#ifndef PLAYER_H
# define PLAYER_H

# include <iostream>


class Player {

public:

    Player( void );
    Player(std::string const & name);
    Player(Player const & src);
    ~Player( void );

    Player &  operator=(Player const & rhs);

    bool isAlive();

private:
    bool _alive;
    std::string _name;
    //Spaceship
};

#endif