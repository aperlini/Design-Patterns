#include <iostream>
#include <string>
#include <vector>


// Common Order interface for all concrete command classes
// where `execute` method will encapsulates a specific action 
// or set of actions

class Order {
	public:
		virtual void execute() const = 0;
};


// Default Stock class that represents the object 
// receiver that will perform the different actions

class Stock {
	public:
		Stock(std::string n, int q) : name(n), quantity(q) {}
		void buy() {
			std::cout << "Stock(name="+this->name+", qty="+std::to_string(this->quantity)+") => action=bought" << std::endl;
		}
		void sell() {
			std::cout << "Stock(name="+this->name+", qty="+std::to_string(this->quantity)+") => action=sold" << std::endl;
		}
	private:
		std::string name;
		int quantity;
};


// Concrete Command classes hold a reference 
// to the receiver object (Stock). They implement
// and determine which behaviour will be called by
// invoking specific actions on the Receiver.

class BuyStockCommand : public Order {
	public:
		BuyStockCommand(Stock *s) : stock(s) {}
		void execute() const override {
			stock->buy();
		}
	private:
		Stock *stock;
};


class SellStockCommand : public Order {
	public:
		SellStockCommand(Stock *s) : stock(s) {}
		void execute() const override {
			stock->sell();
		}
	private:
		Stock *stock;
};


// The invoker contains a list of commands.
// Invokes the `execute` method on each object
// when needed

class Broker {
	public:
		void take_order(Order *order) {
			this->order_list.push_back(order);
		}
		
		void place_order() {
			for(const auto &order : this->order_list) {
				order->execute();
			}
			this->order_list.clear();
		}
	private:
		std::vector<Order *> order_list;
};


int main() {
	
	// Client determine stocks (Receiver class)
	Stock shoes("shoes", 160);	
	Stock socks("socks", 40);	
	
	// Creates concrete command classes
	// and associate them to specific receivers
	BuyStockCommand buy_socks_command(&socks);
	SellStockCommand sell_shoes_command(&shoes);
	
	// Add commands to the invoker
	Broker broker;
	broker.take_order(&buy_socks_command);
	broker.take_order(&sell_shoes_command);
	
	// Invoker then executes queued commands
	broker.place_order();


	return 0;
}
