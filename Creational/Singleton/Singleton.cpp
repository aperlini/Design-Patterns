#include <iostream>
#include <string>
#include <stdexcept>

// Singleton class can only be instanciated with
// 'get_instance' public static method to ensure
// only one instance can be created

class Singleton {
	
	private:
		static Singleton *instance;
		std::string data;
		Singleton(std::string d) : data(d) { }
	public:
		static Singleton *get_instance(std::string s) {
			if(instance == nullptr) {
				instance = new Singleton(s);
			}
			return instance;
		}
		std::string get_data() {
			if(instance == nullptr) {
				throw std::runtime_error("Singleton instance is null");
			}
			return this->data;
		}
		static void destroy() {
			if(instance != nullptr) {
				delete instance;
				instance = nullptr;
			}
		}
};

// Must me defined outside of the class
Singleton *Singleton::instance = nullptr;
	
int main() {
	
	Singleton *s = Singleton::get_instance("default instance");
	
	std::cout << s->get_data() << "\n";
	
	Singleton::destroy();
	
	return 0;
};






