#include <iostream>
#include "SingletonPattern.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! unfinished implementation !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

using namespace std;

int main() {
	Singleton *s = Singleton::getInstance("default instance");
	std::cout << s->get_data() << std::endl;
	return 0;
};
