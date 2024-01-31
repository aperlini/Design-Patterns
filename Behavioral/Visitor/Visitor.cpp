#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Book;
class Fruit;

/*
 * Visitor interface provide different visiting
 * methods that can be overloaded based on the
 * necessary implementations
 *
 */
class Visitor {
	public:
		virtual ~Visitor() { } 
		virtual int visit(Book *b) = 0;
		virtual int visit(Fruit *f) = 0;
};

/*
 * Item interface in which 'accept' methods
 * takes a Visitor interface as unique param
 *
 */

class Item {
	public:
		virtual ~Item() { }
		virtual int accept(Visitor *v) = 0;
		virtual int get_price() const = 0;
};

/*
 * Every Concrete Class that implements 
 * Item interface must redefine the 
 * 'accept' method and pass themselves as
 * argument in the 'visit' method when invoked
 *
 */

class Book : public Item {
	public:
		Book(std::string t, int p) : title(t), price(p) { }
	
		int accept(Visitor *v) override {
			return v->visit(this);
		}
		
		int get_price() const override {
			return this->price;
		}
		
	
	private:
		std::string title;
		int price;
};

class Fruit : public Item {
	public:	
		Fruit(std::string n, int p) : name(n), price(p) { }
		
		int accept(Visitor *v) override {
			return v->visit(this);
		}
		
		int get_price() const override {
			return this->price;
		}

	private:
		std::string name;
		int price;
};

/*
 * Concrete class implementing the Visitor
 * interface is responsible to redefine all
 * its methods and set the logic that must
 * be implemented
 *
 */

class ShoppingCart : public Visitor {
	public:
		int visit(Book *b) override {
			return b->get_price();
		}
		
		int visit(Fruit *f) override {
			return f->get_price();
		}
};


int main() {

	// Declaring a list of items
	std::vector<Item*> items{new Fruit("apple", 23), new Fruit("banana", 34), new Book("some title", 123)};
	
	// Creating the Shopping Cart	
	ShoppingCart *cart = new ShoppingCart();
	
	// Total sum of items in the cart
	int total = 0;
	for(const auto& item : items) {
		// each item takes the cart (visitor)
		total += item->accept(cart);
	}
	
	std::cout << "total cost : " << total << "\n";


	for(const auto& item : items) {
		delete item;
	}

	delete cart;

	return 0;
}
