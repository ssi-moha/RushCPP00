#ifndef PLAYER_H
# define PLAYER_H

# include<iostream>

class Player {

public:

    
    Player(std::string name);
    Player(Player const & src);
    ~Player( void );

    Player &  operator=(Player const & rhs);

    bool isAlive();

private:
    Player( void );
    bool alive;
    std::string name;
};

#endif