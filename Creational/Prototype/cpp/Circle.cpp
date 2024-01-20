#include "Circle.h"

Circle::Circle(int x, int y, int radius) : Shape(x, y), radius(radius) {}

Circle::Circle(const Circle& other) : Shape(other.get_x(), other.get_y()), radius(other.radius) {}

Shape* Circle::clone() const {
    return new Circle(*this);
}

std::string Circle::to_string() const  {
    return "Circle(x=" + std::to_string(get_x()) + ", y=" + std::to_string(get_y()) + ", radius=" + std::to_string(radius) + ")";
}

