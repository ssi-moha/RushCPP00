#include "Enemy.hpp"

Enemy::Enemy(void) {
    
}

Enemy::Enemy(int x, int y) : AMovingObject(x, y) {
    
}

Enemy::Enemy(Enemy const &src) {
    *this = src;
}

Enemy::~Enemy(void) {
    
}

Enemy &	Enemy::operator=(Enemy const & rhs) {
    this->_position = rhs.getPosition();

    return *this;
}

void	Enemy::move(Vector const & movingVector) {
    this->_position = this->_position + movingVector; 
}