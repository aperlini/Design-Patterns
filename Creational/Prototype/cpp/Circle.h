#ifndef __CIRCLE__H
#define __CIRCLE__H

#include "Prototype.h"

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int x, int y, int radius);
    Circle(const Circle& other);
    Shape* clone() const override;
	std::string to_string() const;
};

#endif

