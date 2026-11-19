#include <iostream>
#include <stdexcept>
#include "Square.h"

int main()
{
    Square s1;

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s1.area() => " << s1.area()
              << "; s1.perimeter() => " << s1.perimeter()
              << std::endl;

    Point2D vertices[4];

    vertices[0] = Point2D(-1, 1);
    vertices[1] = Point2D(1, 1);
    vertices[2] = Point2D(1, -1);
    vertices[3] = Point2D(-1, -1);

    Square s2("blue", vertices);

    std::cout << "s2 = " << s2 << std::endl;

    s2.translate(10, 10);

    std::cout << "s2 after translate = "
              << s2 << std::endl;

    // Intentamos convertirlo en un rectángulo que NO sea cuadrado
    vertices[0] = Point2D(-2, 1);
    vertices[1] = Point2D(2, 1);
    vertices[2] = Point2D(2, -1);
    vertices[3] = Point2D(-2, -1);

    try
    {
        s2.set_vertices(vertices);
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
