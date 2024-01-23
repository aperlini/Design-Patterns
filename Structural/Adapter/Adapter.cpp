#include <iostream>

// Square Interface
class Square {
	public:
		virtual ~Square() {}
		virtual void set_side(int i) = 0;
		virtual void print_area() const = 0;
};

// Rectangle Interface
class Rect {
	public:
		virtual ~Rect() {}
		virtual void set_len(int l) = 0;
		virtual void set_width(int w) = 0;
		virtual void print_area() const = 0;
};

class ChessBoard : public Square {
	private:
		int side;
	public:
		void set_side(int i) override {
			this->side = i;
		}
		void print_area() const override {
			std::cout << (this->side * this->side) << std::endl;
		}
};

class TennisCourt : public Rect {
	private:
		int len;
		int width;
	public:
		void set_len(int l) override {
			this->len = l;
		}
		void set_width(int w) override {
			this->width = w;
		}
		void print_area() const override {
			std::cout << (this->width * this->len) << std::endl;
		}
};

class RectAdapter : public Square {
	public:
		Rect *rect;
		RectAdapter(Rect *rect) : rect(rect) {}
		void set_side(int i) override {
			rect->set_len(i);
			rect->set_width(i);
		}
		void print_area() const override {
			rect->print_area();
		}
};


int main() {

	// New ChessBoard instance of type Square
	Square *square = new ChessBoard();
	square->set_side(5);
	std::cout << "Printing Square Area: " << std::endl;
	square->print_area();
	
	// New TennisCourt instance of type Rect
	Rect *rectangle = new TennisCourt();
	rectangle->set_len(10);
	rectangle->set_width(20);
	std::cout << "Printing Rectangle Area: " << std::endl;
	rectangle->print_area();
	
	// Adapter for our rectangle
	Square *adapter = new RectAdapter(rectangle);

	// Modifying rectangle using Square methods
	adapter->set_side(12);
	std::cout << "Printing Area Using Adapter: " << std::endl;
	adapter->print_area();
	
	// Free memory
	delete square;
	delete rectangle;
	delete adapter;

	return 0;
}
