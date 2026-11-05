#include "Circle.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

Circle::Circle()
    : Shape(), center(), radius(1)
{
}

Circle::Circle(std::string color, Point2D center, double radius)
    : Shape(color), center(center)
{
    set_radius(radius);
}

Point2D Circle::get_center() const
{
    return center;
}

void Circle::set_center(Point2D p)
{
    center = p;
}

double Circle::get_radius() const
{
    return radius;
}

void Circle::set_radius(double r)
{
    if (r < 0)
    {
        throw std::invalid_argument("Radio inválido");
    }

    radius = r;
}

double Circle::area() const
{
    return 3.141592 * pow(radius, 2);
}

double Circle::perimeter() const
{
    return 2 * 3.141592 * radius;
}

void Circle::translate(double incX, double incY)
{
    center.x += incX;
    center.y += incY;
}

void Circle::print()
{
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Circle& c)
{
    out << "Circle: color=" << c.get_color()
        << ", center=" << c.center
        << ", radius=" << c.radius;

    return out;
}
