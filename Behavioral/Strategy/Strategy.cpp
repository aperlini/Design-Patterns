#include <iostream>
#include <string>


// Common Strategy interface which 
// every class must implement

class Gun {
	public:
		virtual ~Gun() {}
		virtual void fire() const = 0;
};


// All subsequent concrete classes 
// that implements the interface

class Snipper : public Gun {
	public:
		void fire() const override {
			std::cout << "snipper shoot" << std::endl;
		}
};


class MachineGun : public Gun {
	public:
		void fire() const override {
			std::cout << "machine gun shoot" << std::endl;
		}
};


class GrenadeLauncher : public Gun {
	public:
		void fire() const override {
			std::cout << "grenade launcher shoot" << std::endl;
		}
};


// Soldier concrete class contains a reference to the Strategy object instance
// When it receives request, it delegates the action to the instance for it to 
// perform the appropriate behaviour.

class Soldier {
	public:
		// Using pointers to manage object ownership
		Soldier(Gun *g) : gun(g) {}
		~Soldier() {
			delete this->gun;
		}
		void change_gun(Gun* g) {
			delete this->gun;
			this->gun = g;
		}
		void fire_at_enemy() {
			if(this->gun) {
				this->gun->fire();
			}
		}
	private:
		Gun *gun;
};

int main() {
	
	// Using pointers is necessary to manage object ownership
	// and to allow object change during the container object's lifecycle
	Gun *snipper = new Snipper();
	Gun *machine = new MachineGun();
	Gun *grenade = new GrenadeLauncher();

	Soldier *s = new Soldier(snipper);
	s->fire_at_enemy();
	s->change_gun(machine);
	s->fire_at_enemy();
	s->change_gun(grenade);
	s->fire_at_enemy();

	delete s;

	return 0;
}
