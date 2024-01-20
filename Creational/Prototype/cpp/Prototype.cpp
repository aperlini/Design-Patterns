#include "Prototype.h"

Shape::Shape(int x, int y) : x(x), y(y) {}

int Shape::get_x() const {
    return this->x;
}

int Shape::get_y() const {
    return this->y;
}

std::string Shape::to_string() const {
    return "Shape(x=" + std::to_string(get_x()) + ", y=" + std::to_string(get_y()) + ")";
}


