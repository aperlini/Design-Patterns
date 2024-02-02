#include <iostream>
#include <string>


// All members from Computer class
// must be declared private as we must
// ensure all building stages are delegated
// to the nested builder class

class Computer {
	
	private:
		int disk_space;
		int ram;
		std::string brand;
		bool hdmi;
		Computer(int ds, int ram, std::string brand, bool hdmi) {
			this->disk_space = ds;
			this->ram = ram;
			this->brand = brand;
			this->hdmi = hdmi;
		}
	public:
		std::string to_string() {
			return "Computer(disk_space="+std::to_string(this->disk_space)+
						  ", ram="+std::to_string(this->ram)+
						  ", brand="+this->brand+
						  ", hdmi="+ (this->hdmi ? "true" : "false") +")";
		}



	// Nested Builder class whose aim 
	// is to build the computer parts

	public:
		class Builder {
			private:
				int disk_space;
				int ram;
				std::string brand;
				bool hdmi;
			
			public:
				Builder() : disk_space(0), ram(0), brand(""), hdmi(false) {}
				Builder& setDiskSpace(int ds) {
					this->disk_space = ds;	
					return *this;
				}

				Builder& setRAM(int ram) {
					this->ram = ram;
					return *this;
				}

				Builder& setBrand(std::string brand) {
					this->brand = brand;
					return *this;
				}

				Builder& setHDMI(bool hdmi) {
					this->hdmi = hdmi;
					return *this;
				}
				Computer build() {
					return Computer(this->disk_space, this->ram, this->brand, this->hdmi);
				}


		};
};

				
int main() {
	
	// Creating a new builder instance
	Computer::Builder builder;

	// Building custom computer c1
	Computer c1 = builder.setDiskSpace(200)
		   				  .setRAM(20)
			   			  .setBrand("Toshiba")
			   			  .setHDMI(true)
			   			  .build();
	
	// Building custom computer c2
	Computer c2 = builder.setDiskSpace(500)
		   				  .setRAM(10)
			   			  .setBrand("Lenovo")
			   			  .build();

	std::cout << c1.to_string() << "\n";
	std::cout << c2.to_string() << "\n";

	return 0;
};
