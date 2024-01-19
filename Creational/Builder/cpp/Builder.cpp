#include "Builder.h"

Computer::Computer(int ds, int ram, string brand, bool hdmi) {
	this->disk_space = ds;
	this->ram = ram;
	this->brand = brand;
	this->hdmi = hdmi;
}

Computer::Builder::Builder() : disk_space(0), ram(0), brand(""), hdmi(false) {}

Computer::Builder& Computer::Builder::setDiskSpace(int ds) {
	this->disk_space = ds;	
	return *this;
}

Computer::Builder& Computer::Builder::setRAM(int ram) {
	this->ram = ram;
	return *this;
}

Computer::Builder& Computer::Builder::setBrand(std::string brand) {
	this->brand = brand;
	return *this;
}

Computer::Builder& Computer::Builder::setHDMI(bool hdmi) {
	this->hdmi = hdmi;
	return *this;
}
				

Computer Computer::Builder::build() {
	return Computer(this->disk_space, this->ram, this->brand, this->hdmi);
}

std::string Computer::Builder::toString() {
	return "Computer(disk_space="+std::to_string(this->disk_space)+", ram="+std::to_string(this->ram)+", brand="+this->brand+", hdmi="+ (this->hdmi ? "true" : "false") +")";
}






