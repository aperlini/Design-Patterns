#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>

enum Color {
	red,
	blue,
	green,
	yellow
};

/*
 * Shape interface defines 'draw' method to implemented
 * in all subsequent concrete classes that will take advantage
 * of it
 *
 */
class Shape {
	public:
		virtual ~Shape() = default;
		virtual void draw() = 0;
};

/*
 * Circle class implement the Shape interface
 * and redefine 'draw' method to display circle
 * informations
 *
 */
class Circle : public Shape {

	public:
		virtual ~Circle() { }
		Circle(enum Color c) :  color(c) { }
		void draw() override {
			std::cout << "Circle(x=" << this->pos_x << ", y=" << this->pos_y << ", radius=" << this->radius <<  ", color=" << this->colors[this->color] << ") \n";
		}
		void set_x(int x) {
			this->pos_x = x;
		}
		void set_y(int y) {
			this->pos_y = y;
		}
		void set_radius(int r) {
			this->radius = r;
		}
		std::string get_color(enum Color color) {
			return this->colors[color];
		}
	private:
		int pos_x;
		int pos_y;
		int radius;
		enum Color color;
		std::map<enum Color, std::string> colors{
			{ red, "Red" }, { blue, "Blue" },{ green, "Green" }, { yellow, "Yellow" }
		};

};

/*
 * Static ShapeFactory holds a static map member
 * which will be shared accross all ShapeFactory instances
 * The 'circle_map' member will enable the creation of unique circle
 * object instances, based on their color. The 'get_circle' method will
 * handle the logic upon the creation of new objects or simply returning
 * the current existing circle
 *
 */

class ShapeFactory{
	public:
		static void clean_up() {
			for(const auto &[k, circle] : circle_map) {
				delete circle;
			}
		}
		static Shape *get_circle(enum Color color);
	private:
		static std::map<enum Color, Circle*> circle_map;
};

std::map<enum Color, Circle*> ShapeFactory::circle_map{};

Shape* ShapeFactory::get_circle(enum Color color) {
	Circle *c = circle_map[color];

	if(c == nullptr) {
		c = new Circle(color);
		circle_map[color] = c;
		std::cout << "\nnew " << c->get_color(color) << " circle has been created\n\n";
	}
	return c;
}

/*
 * Generate random integer
 * based on min/max range
 * 
 * @params:
 * 	- min range
 *	- max range
 *
 * @return:
 * 	- random value between min and max
 *
 */
int rand_pos(int min, int max) {
	return min + std::rand() / (RAND_MAX / max);
}

/*
 * Generate random Color
 *
 * @return:
 * 	- random enum Color value
 *
 */

enum Color rand_color() {
	int index = rand_pos(0, 4);
	return (enum Color)(index);
}

int main() {
	
	// using current time as seed for random generator
	std::srand(std::time(nullptr));	
	
	// Generate 20 circles
	int i=0;
	while(i<20) {
		Circle *c = static_cast<Circle*>(ShapeFactory::get_circle(rand_color()));
		c->set_x(rand_pos(0, 20));
		c->set_y(rand_pos(0, 20));
		c->set_radius(30);
		c->draw();
		i++;
	}
	
	ShapeFactory::clean_up();

	return 0;
}
