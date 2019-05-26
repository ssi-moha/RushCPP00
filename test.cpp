#include "Model/Vector.hpp"
#include "Model/MovingObject/Enemy.hpp"
#include "Model/MovingObject/Spaceship.hpp"
#include "Model/Object.hpp"
#include "Model/ObjectList.hpp"
#include <iostream>

void    print(AMovingObject *elem) {
    std::cout << *elem << std::endl;
}

int main(void) {
    Spaceship *a = new Spaceship(7, 9);
    Enemy *b = new Enemy(15, 10);
    ObjectList list;

    list.add(a);
    list.add(b);
    
    list.forEach(&print);

    return 0;
}