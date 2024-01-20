#ifndef __SQUARE__H
#define __SQUARE__H

#include "Prototype.h"

class Square : public Shape {
private:
    int side;

public:
    Square(int x, int y, int side);
    Square(const Square& other);
    Shape* clone() const override;
	std::string to_string() const;
};

#endif

