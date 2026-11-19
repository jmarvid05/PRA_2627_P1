#include "Square.h"
#include <stdexcept>

bool Square::check(Point2D* vertices)
{
    double l0 = Point2D::distance(vertices[0], vertices[1]);
    double l1 = Point2D::distance(vertices[1], vertices[2]);
    double l2 = Point2D::distance(vertices[2], vertices[3]);
    double l3 = Point2D::distance(vertices[3], vertices[0]);

    return l0 == l1 && l1 == l2 && l2 == l3;
}

Square::Square()
    : Rectangle()
{
    Point2D vertices[N_VERTICES];

    vertices[0] = Point2D(-1, 1);
    vertices[1] = Point2D(1, 1);
    vertices[2] = Point2D(1, -1);
    vertices[3] = Point2D(-1, -1);

    set_vertices(vertices);
}

Square::Square(std::string color, Point2D* vertices)
    : Rectangle(color, vertices)
{
    if (!check(vertices))
    {
        throw std::invalid_argument(
            "Provided vertices do not build a square"
        );
    }
}

void Square::set_vertices(Point2D* vertices)
{
    if (!check(vertices))
    {
        throw std::invalid_argument(
            "Provided vertices do not build a square"
        );
    }

    Rectangle::set_vertices(vertices);
}

std::ostream& operator<<(std::ostream& out, const Square& square)
{
    out << "[Square: color = " << square.get_color();

    for (int i = 0; i < Square::N_VERTICES; i++)
    {
        out << "; v" << i << " = " << square[i];
    }

    out << "]";

    return out;
}
