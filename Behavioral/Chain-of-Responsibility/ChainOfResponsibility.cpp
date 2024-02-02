#include <iostream>
#include <string>
#include <vector>



enum FOOD_TYPE{
	BURGER,
	PIZZA,
	HOTDOG
};


// Request class simply stores 
// current order type 

class Request {
	
	public:
		Request(enum FOOD_TYPE o) : order_type(o) {}
		FOOD_TYPE get_order() const { 
			return order_type; 
		}
	private:
		enum FOOD_TYPE order_type;
};


// Handler Abstract Class hold a reference
// to the next handler and define successors
// accessors default methods. 

class Handler {
	public:
		virtual ~Handler() { }
		void set_successor(Handler *h) {
			this->successor = h;
		}
		virtual void handle_request(Request request) = 0;
		Handler *get_successor() const {
			return this->successor;
		}
	private:
		Handler *successor;
		
};


// All Concrete Classes extend Handler Abstract class
// They must redefine 'handle_request' method by choosing
// how to treat the incoming request

class PizzaHandler : public Handler {
	public:
		virtual ~PizzaHandler() {}
		void handle_request(Request request) override {
				
			FOOD_TYPE order = request.get_order();
			if(order == PIZZA) {
				std::cout << "handling 'pizza' order request\n";
			} else {
				this->get_successor()->handle_request(request);
			}
		}
};

class BurgerHandler : public Handler {
	public:
		virtual ~BurgerHandler() {}
		void handle_request(Request request) override {
			FOOD_TYPE order = request.get_order();
			if(order == BURGER) {
				std::cout << "handling 'burger' order request\n";
			} else {
				this->get_successor()->handle_request(request);
			}
		}
};

class HotDogHandler : public Handler {
	public:
		virtual ~HotDogHandler() {}
		void handle_request(Request request) override {
			FOOD_TYPE order = request.get_order();
			if(order == HOTDOG) {
				std::cout << "handling 'hot-dog' order request\n";
			} else {
				this->get_successor()->handle_request(request);
			}
		}
};

int main() {
	
	// Creating handlers
	Handler *h1 = new PizzaHandler();
	Handler *h2 = new BurgerHandler();
	Handler *h3 = new HotDogHandler();
	
	// Defining chain of reponsibility
	// for each handler and its successor
	h1->set_successor(h2);
	h2->set_successor(h3);
	
	// Sending requests to the 
	// first handler in the chain
	h1->handle_request(Request(BURGER));
	h1->handle_request(Request(HOTDOG));

	delete h1;
	delete h2;
	delete h3;

	return 0;
}
