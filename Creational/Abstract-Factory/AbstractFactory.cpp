#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


// Button interface provides abstractions
// to represent any type of button

class Button {
	public:
		virtual ~Button() {}
		virtual void paint() const = 0;
};


// All subsequent concrete implementations 
// of the Button interface 

class MacOSBtn : public Button {
	void paint() const override {
		std::cout << "MacOSBtn paint action" << std::endl;
	}
};


class WindowsBtn : public Button {
	void paint() const override {
		std::cout << "WindowsBtn paint action" << std::endl;
	}
};


class LinuxBtn : public Button {
	void paint() const override {
		std::cout << "LinuxBtn paint action" << std::endl;
	}
};


// CheckBox interface provides abstractions
// to represent any type of CheckBox

class CheckBox {
	public:
		virtual ~CheckBox() {}
		virtual void paint() const = 0;
};


// All subsequent concrete implementations 
// of the CheckBox interface 

class MacOSCheckBox : public CheckBox {
	void paint() const override {
		std::cout << "MacOSCheckBox paint action" << std::endl;
	}
};

class WindowsCheckBox : public CheckBox {
	void paint() const override {
		std::cout << "WindowsCheckBox paint action" << std::endl;
	}
};

class LinuxCheckBox : public CheckBox {
	void paint() const override {
		std::cout << "LinuxCheckBox paint action" << std::endl;
	}
};


// AbstractFactory interface declares methods 
// to create buttons and checkboxes

class GUIFactory {
	public:
		virtual ~GUIFactory() {}
		virtual Button *createBtn() const = 0;
		virtual CheckBox *createCheckBox() const = 0;
};


// All subsequent concrete implementations of the AbstractFactory 
// interface that are responsible for creating GUI elements for each
// related type 

class WindowsFactory : public GUIFactory {
	public:
		Button *createBtn() const override {
			return new WindowsBtn();
		}
		CheckBox *createCheckBox() const override {
			return new WindowsCheckBox();
		}
};

class MacOSFactory : public GUIFactory {
	public:
		Button *createBtn() const override {
			return new MacOSBtn();
		}
		CheckBox *createCheckBox() const override {
			return new MacOSCheckBox();
		}
};

class LinuxFactory : public GUIFactory {
	public:
		Button *createBtn() const override {
			return new LinuxBtn();
		}
		CheckBox *createCheckBox() const override {
			return new LinuxCheckBox();
		}
};


enum confs {
	Windows,
	Linux,
	MacOS
};

int get_rand(int from, int to) {
	return from + std::rand() / ((RAND_MAX) / to);
}

confs get_config() {
	return (confs)(get_rand(0, 3));
}

int main() {
    
	std::srand(std::time(nullptr));
	
	// Factory pointer
	GUIFactory *factory;

	// Getting Random Config
	confs config = get_config();

	// Creating Random Factory
	switch(config) {
		case Windows:
			factory = new WindowsFactory();
			break;
		case Linux:
			factory = new LinuxFactory();
			break;
		case MacOS:
			factory = new MacOSFactory();
			break;
		default:
			throw std::invalid_argument("configuration does not exists.");

	}
		
	// Creating Factory Elements
	Button *btn = factory->createBtn();
	CheckBox *check = factory->createCheckBox();
	
	// Calling Respective Actions
	btn->paint();
	check->paint();
	
	// Free memory
	delete btn;
	delete check;
	delete factory;

	return 0;
}

