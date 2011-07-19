#include <iostream>
#include <epic.math/Vector2.h>

int main(int argc, char** argv) {

    Epic::Math::Vector2F a(1.0f, 2.0f), b(2.0f, 3.0f);

    std::cout << "Suma igual a " << (a + b) << std::endl;
    std::cout << "Resta igual a" << (a - b) << std::endl;
    std::cout << "Producto igual a" << (a * b) << std::endl;
    std::cout << "Division igual a" << (a / b) << std::endl;

    std::cout << "Suma escalar" << (a + 2.0f) << std::endl;
    std::cout << "Resta escalar" << (a - 2.0f) << std::endl;

    std::cout << "Producto escalar" << (a * 2.0f) << std::endl;
    std::cout << "Division escalar" << (a / 2.0f) << std::endl;

    std::cout << "Producto escalar" << (2.0f * a ) << std::endl;
    std::cout << "Division escalar" << (2.0f / a) << std::endl;

    std::cout << "Largo de a = " << a.length() << std::endl;
    std::cout << "a normalized = " << a.normalized() << std::endl;

    Epic::Math::Vector2F r;

    std::cout << "Uninitialized vector is " << r << std::endl;

    float *data = a.data();

    std::cout << "data[0] = " << data[0] << ", data[1] = " << data[1] << std::endl;

    return 0;
}

#include <cstdlib>
