#include <iostream>
#include <stdexcept>
#include "Circle.h"

int main()
{
    Circle c1;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "area: " << c1.area() << std::endl;
    std::cout << "perimeter: " << c1.perimeter() << std::endl;

    std::cout << std::endl;

    Circle c2("blue", Point2D(2, 3), 5);

    std::cout << "c2: " << c2 << std::endl;
    std::cout << "center: " << c2.get_center() << std::endl;
    std::cout << "radius: " << c2.get_radius() << std::endl;

    c2.translate(3, -1);

    std::cout << "after translate: " << c2 << std::endl;

    std::cout << std::endl;

    c2.print();

    try
    {
        c2.set_radius(-4);
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
