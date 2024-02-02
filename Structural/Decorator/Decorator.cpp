#include <iostream>
#include <string>


// Decorator interface provides 'make'
// method that must be implemented

class Decorator {
	public:
		virtual ~Decorator() = default;
		virtual std::string make() = 0;
};


// The Sandwich class, a concrete component
// implements the Decorator interface and 
// redefines the 'make()' method

class Sandwich : public Decorator {
	public:
		std::string make() override {
			return "Sandwich";
		}
		
};


// The SandwichDecorator abstract class extends 
// the Sandwich class and serves as a base class 
// for concrete decorators. It contains a reference 
// to a Sandwich object used during the 'make()' method

class SandwichDecorator : public Sandwich {
	public:
		SandwichDecorator(Sandwich *special_sandwich) : sandwich(special_sandwich) {}
		~SandwichDecorator() {
			delete sandwich;
		}
		std::string make() override {
			return this->sandwich->make();
		}
	protected:
		Sandwich *sandwich;

};


// The CheeseDecorator and PastramiDecorator classes 
// extend SandwichDecorator. They augment the sandwich 
// with specific functionalities (cheese and pastrami)

class CheeseDecorator : public SandwichDecorator {
	public:
		CheeseDecorator(Sandwich *special_sandwich) : SandwichDecorator(special_sandwich) {}
		std::string make() override {
			return this->sandwich->make() + this->add_cheese();
		}
	private:
		std::string add_cheese() {
			return " w/ cheese";
		}

};

class PastramiDecorator : public SandwichDecorator {
	public:
		PastramiDecorator(Sandwich *special_sandwich) : SandwichDecorator(special_sandwich) {}
		std::string make() override {
			return this->sandwich->make() + this->add_pastrami();
		}
	private:
		std::string add_pastrami() {
			return " w/ pastrami";
		}
};

int main() {
	
	// A sandwich is created by combining decorators (pastrami and cheese) 
	Decorator *sandwich = new PastramiDecorator(new CheeseDecorator(new Sandwich()));

	// 'make()' is invoked on the decorated object to display the result
	std::cout << sandwich->make() << "\n";

	delete sandwich;

	return 0;
}
