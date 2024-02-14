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
		class Builder {
			private:
				int disk_space;
				int ram;
				std::string brand;
				bool hdmi;
			
			public:
				Builder() : disk_space(0), ram(0), brand(""), hdmi(false) {}
				Builder& set_disk_space(int ds) {
					this->disk_space = ds;	
					return *this;
				}

				Builder& set_ram(int ram) {
					this->ram = ram;
					return *this;
				}

				Builder& set_brand(std::string brand) {
					this->brand = brand;
					return *this;
				}

				Builder& set_hdmi(bool hdmi) {
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
	Computer c1 = builder.set_disk_space(200)
		   				  .set_ram(20)
			   			  .set_brand("Toshiba")
			   			  .set_hdmi(true)
			   			  .build();
	
	// Building custom computer c2
	Computer c2 = builder.set_disk_space(500)
		   				  .set_ram(10)
			   			  .set_brand("Lenovo")
			   			  .build();

	std::cout << c1.to_string() << "\n";
	std::cout << c2.to_string() << "\n";

	return 0;
};
