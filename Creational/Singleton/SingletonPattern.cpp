#include "SingletonPattern.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! unfinished implementation !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Singleton *Singleton::instance_ = nullptr;
	
Singleton::Singleton(string s) : data(s) {}

Singleton *Singleton::getInstance(string s) {
	if(instance_ == nullptr) {
		instance_ = new Singleton(s);
	}
	return instance_;
}

string Singleton::get_data() {
	return data;
}






