#include "Model/Vector.hpp"
#include "Model/Enemy.hpp"
#include <iostream>

int main(void) {
    Enemy a(5, 8);
    Enemy b(7, 9);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    
    a.move(Vector(8, 5));
    b.move(Vector(9, 7));

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}