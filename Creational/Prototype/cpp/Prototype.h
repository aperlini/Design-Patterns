#ifndef __PROTOTYPE__H
#define __PROTOTYPE__H

#include <string>

class Shape {
private:
    int x;
    int y;

public:
    Shape(int x, int y);
    virtual Shape* clone() const = 0;
    int get_x() const;
    int get_y() const;
	virtual std::string to_string() const;
};

#endif

