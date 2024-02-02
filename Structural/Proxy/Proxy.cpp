#include <iostream>


// Proxy interface will expose methods
// to be implemented both in the concrete class
// and in Proxy concrete class

class Proxy {
	public:
		virtual ~Proxy() { }
		virtual void process() = 0;
};


// Service class represents an expensive
// class to be used and implements the 'process'
// method of Proxy interface

class Service : public Proxy {
	public:
	
		Service() {
			this->init_heavy_config();
		}

		void process() override {
			std::cout << "processing completed.\n";
		}

	private:
		void init_heavy_config() const {
			std::cout << "Loading initial configuration...\n";
		}
};


// Proxy Service class implement the Proxy interface
// It holds a reference to a Service instance that will
// be instanciated in the redefined 'process' method,
// once the Service object is available

class ProxyService : public Proxy {
	public:
		~ProxyService() {
			delete obj;
		}
		void process() override {
			if(obj == nullptr) {
				obj = new Service();
			}
			obj->process();
		}
		
	private:
		Service *obj;

};



int main() {

	// Creating Proxy
	Proxy *obj = new ProxyService();

	// Invoking successive call to 'process' method
	obj->process();
	obj->process();

	delete obj;

	return 0;
}
