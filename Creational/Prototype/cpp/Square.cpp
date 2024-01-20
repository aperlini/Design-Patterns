#include "Square.h"

Square::Square(int x, int y, int side) : Shape(x, y), side(side) {}

Square::Square(const Square& other) : Shape(other.get_x(), other.get_y()), side(other.side) {}

Shape* Square::clone() const {
    return new Square(*this);
}

std::string Square::to_string() const  {
    return "Square(x=" + std::to_string(get_x()) + ", y=" + std::to_string(get_y()) + ", side=" + std::to_string(side) + ")";
}

