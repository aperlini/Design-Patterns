#include <iostream>
#include <vector>
#include "Prototype.h"
#include "Circle.h"
#include "Rect.h"
#include "Square.h"

using namespace std;

int main() {
	Circle circle(20, 20, 200);
	Rect rect(400, 400);
	Square square(10, 10, 100);

	Shape *shape1 = &circle;
	Shape *shape2 = &rect;
	Shape *shape3 = &square;

	
	std::vector<Shape*> originals = {shape1, shape2, shape3};
	
	cout << "Displaying original shapes" << endl;

	for(const Shape* s : originals) {
		cout << s->to_string() << endl;
	}
	
	cout << endl;

	std::vector<Shape*> copies;
	for(const Shape* s : originals) {
		copies.push_back(s->clone());

	}
	
	cout << "Displaying copies" << endl;

	for(const Shape* c : copies) {
		cout << c->to_string() << endl;
	}


	return 0;
};
