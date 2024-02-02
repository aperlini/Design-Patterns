#ifndef __SINGLETON_PATTERN__H
#define __SINGLETON_PATTERN__H

#include <string>

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! unfinished implementation !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

using namespace std;

class Singleton {
	
	private:
		static Singleton *instance_;
		string data;
		Singleton(string d);

	public:
		static Singleton *getInstance(string s);
		string get_data();
};

#endif
