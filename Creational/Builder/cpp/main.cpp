#include <iostream>
#include "Builder.h"

using namespace std;

int main() {
	Computer::Builder builder;
	builder.setDiskSpace(200)
		   .setRAM(20)
		   .setBrand("Toshiba")
		   .setHDMI(true)
		   .build();

	std::cout << builder.toString() << std::endl;
	return 0;
};
