#include "Prototype.h"
#include "Rect.h"

Rect::Rect(int len, int bre) : Shape(0, 0), len(len), bre(bre) {}

Rect::Rect(const Rect& other) : Shape(0, 0), len(other.len), bre(other.bre) {}

Shape* Rect::clone() const {
    return new Rect(*this);
}

int Rect::get_len() const {
    return this->len;
}

int Rect::get_bre() const {
    return this->bre;
}

std::string Rect::to_string() const {
    return "Rect(bre=" + std::to_string(get_bre()) + ", len=" + std::to_string(get_len()) + ")";
}



