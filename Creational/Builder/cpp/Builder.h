#ifndef __BUILDER__H
#define __BUILDER__H

#include <string>

using namespace std;

class Computer {
	
	private:
		int disk_space;
		int ram;
		string brand;
		bool hdmi;
		Computer(int, int, std::string, bool);

	public:
		class Builder {
			private:
				int disk_space;
				int ram;
				string brand;
				bool hdmi;
			
			public:
				Builder();
				Builder& setDiskSpace(int);
				Builder& setRAM(int);
				Builder& setBrand(std::string);
				Builder& setHDMI(bool);
				Computer build();
				std::string toString();

		};
};

#endif
