#include "Model/Vector.hpp"
#include "Model/Enemy.hpp"
#include "Model/Spaceship.hpp"
#include <iostream>

int main(void) {
    Spaceship a(7, 9);

    std::cout << a << std::endl;
    
    a.setMovementVector(Vector(2, 3));
    a.move();
    std::cout << a << std::endl;

    a.move();
    std::cout << a << std::endl;

    return 0;
}