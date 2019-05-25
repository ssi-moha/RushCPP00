#include "Model/Vector.hpp"
#include <iostream>

int main(void) {
    Vector a(5, 8);
    Vector b(7, 9);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    
    a.setAbsciss(8);
    a.setOrdinate(5);
    b.setAbsciss(9);
    b.setOrdinate(7);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}