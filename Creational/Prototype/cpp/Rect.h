#ifndef __RECT__H
#define __RECT__H

#include <string>
#include "Prototype.h"

class Rect : public Shape {
private:
    int len;
    int bre;

public:
	Rect(int len, int bre);
    Rect(const Rect& other);  
    Shape* clone() const override;
    int get_len() const;
    int get_bre() const;
	std::string to_string() const;
};

#endif
