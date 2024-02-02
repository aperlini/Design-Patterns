#include <iostream>
#include <memory>
#include <vector>


// Abstract Shape skeleton defines default 
// object structure and the 'clone' method
// that must be implemented

class Shape {
	private:
		int x;
		int y;

	public:
		Shape(int x, int y) : x(x), y(y) {}
		virtual ~Shape() = default;
		virtual std::shared_ptr<Shape> clone() const = 0;
		int get_x() const { return this->x; };
		int get_y() const { return this->y; };
		virtual std::string to_string() const = 0;
};


// All the subsequent concrete prototype classes
// must redefine the 'clone' method that will return 
// a new object by calling the constructor of the 
// current class

class Circle : public Shape {
	private:
		int radius;

	public:
		Circle(int x, int y, int radius) : Shape(x, y), radius(radius) {}
		std::shared_ptr<Shape> clone() const override {
			return std::make_shared<Circle>(*this);
		}
		std::string to_string() const override {
			return "Circle(x=" + std::to_string(get_x()) + ", y=" + std::to_string(get_y()) + ", radius=" + std::to_string(radius) + ")";
		}
};


class Square : public Shape {
	private:
		int side;

	public:
		Square(int x, int y, int side) : Shape(x, y), side(side) {}
		std::shared_ptr<Shape> clone() const override {
			return std::make_shared<Square>(*this);
		}
		std::string to_string() const override {
			return "Square(x=" + std::to_string(get_x()) + ", y=" + std::to_string(get_y()) + ", side=" + std::to_string(side) + ")";
		}
};


class Rect : public Shape {
	private:
		int len;
		int bre;

	public:
		Rect(int len, int bre) : Shape(0, 0), len(len), bre(bre) {}
		std::shared_ptr<Shape> clone() const override {
			return std::make_shared<Rect>(*this);
		}
		int get_len() const { return this->len; }
		int get_bre() const { return this->bre; }
		std::string to_string() const override {
			return "Rect(bre=" + std::to_string(get_bre()) + ", len=" + std::to_string(get_len()) + ")";
		}
};

int main() {

	// Creating 'original' shapes
    std::vector<std::shared_ptr<Shape>> originals = {
        std::make_shared<Circle>(20, 20, 200),
        std::make_shared<Rect>(400, 400),
        std::make_shared<Square>(10, 10, 100)};

    std::cout << "Displaying original shapes" << std::endl;

    for (const auto &s : originals) {
        std::cout << s->to_string() << std::endl;
    }

	// Generating copies from originals
    std::vector<std::shared_ptr<Shape>> copies;

	std::cout << "\nDisplaying copies" << std::endl;

    for (const auto &s : originals) {
        copies.push_back(s->clone());
    }

    for (const auto &c : copies) {
        std::cout << c->to_string() << std::endl;
    }
    return 0;
}

