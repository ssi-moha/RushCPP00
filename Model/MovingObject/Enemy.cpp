#include "Enemy.hpp"

Enemy::Enemy(void) {
    
}

Enemy::Enemy(int x, int y) : AMovingObject(x, y, "V") {
    
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