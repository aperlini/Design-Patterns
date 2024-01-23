#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// Bird Interface
class Bird {
	public:
		virtual ~Bird() {}
		virtual void make_sound() const = 0;
		virtual void change_pos(int x, int y) = 0;
};

// Implements Interface
class Crow : public Bird {
	private:
		std::string type;
		int x;
		int y;
	public:
		Crow(std::string t) : type(t) {}
		void make_sound() const override {
			std::cout << "Caw Caw... " << std::endl;
		}
		void change_pos(int x, int y) override {
			std::cout << "Crow position updated (x=" << x << ", y=" << y << ")" << std::endl;
			this->x = x;
			this->y = y;
		}
};

// Implements Interface
class Duck : public Bird {
	private:
		std::string type;
		int x;
		int y;
	public:
		Duck(std::string t) : type(t) {}
		void make_sound() const override {
			std::cout << "Quack Quack... " << std::endl;
		}
		void change_pos(int x, int y) override {
			std::cout << "Duck position updated (x=" << x << ", y=" << y << ")" << std::endl;
			this->x = x;
			this->y = y;
		}
};


// Flyable Abstract Class
class Flyable {
	protected:
		Bird *bird;
		Flyable(Bird *bird) : bird(bird) {}	
	public:
		virtual ~Flyable() {}
		virtual void tweet() const = 0;
		virtual void move(int x, int y) = 0;
};


// Extends Abstract Class
class FlyingCharacter : public Flyable {
	private:
		int x;
		int y;
	public:
		FlyingCharacter(Bird *bird, int x, int y) : Flyable(bird), x(x), y(y) {}
		void tweet() const override {
			this->bird->make_sound();
		}
		void move(int x, int y) override {
			this->bird->change_pos(x, y);
			this->x = x;
			this->y = y;
		}
};


int main() {
	
	// Duck and Crow instances of type Bird
	Bird *d = new Duck("Duck");
	Bird *c = new Crow("Crow");
	
	// Setting FlyCharacters of type Flyable
	Flyable *duck = new FlyingCharacter(d, 0, 0);
	Flyable *crow = new FlyingCharacter(c, 0, 0);
	
	// Flyable Actions
	int i=0;
	while(i <4) {
		duck->tweet();
		duck->move(i, i*2);
		crow->tweet();
		crow->move(i*2, i);
		i++;
		std::cout << std::endl;
	}

	// Free memory
	delete d;
	delete c;
	delete duck;
	delete crow;

	return 0;
}
