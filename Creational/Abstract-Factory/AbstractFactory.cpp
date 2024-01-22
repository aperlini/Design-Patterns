#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// Button interface
class Button {
	public:
		virtual void paint() const = 0;
};

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

// CheckBox interface
class CheckBox {
	public:
		virtual void paint() const = 0;
};

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

// AbstractFactory interface
class GUIFactory {
	public:
		virtual std::shared_ptr<Button> createBtn() const = 0;
		virtual std::shared_ptr<CheckBox> createCheckBox() const = 0;
};

class WindowsFactory : public GUIFactory {
	public:
		std::shared_ptr<Button> createBtn() const override {
			return std::make_shared<WindowsBtn>();
		}
		std::shared_ptr<CheckBox> createCheckBox() const override {
			return std::make_shared<WindowsCheckBox>();
		}
};

class MacOSFactory : public GUIFactory {
	public:
		std::shared_ptr<Button> createBtn() const override {
			return std::make_shared<MacOSBtn>();
		}
		std::shared_ptr<CheckBox> createCheckBox() const override {
			return std::make_shared<MacOSCheckBox>();
		}
};

class LinuxFactory : public GUIFactory {
	public:
		std::shared_ptr<Button> createBtn() const override {
			return std::make_shared<LinuxBtn>();
		}
		std::shared_ptr<CheckBox> createCheckBox() const override {
			return std::make_shared<LinuxCheckBox>();
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
	std::shared_ptr<GUIFactory> factory;

	// Getting Random Config
	confs config = get_config();

	// Creating Random Factory
	switch(config) {
		case Windows:
			factory = std::make_shared<WindowsFactory>();
			break;
		case Linux:
			factory = std::make_shared<LinuxFactory>();
			break;
		case MacOS:
			factory = std::make_shared<MacOSFactory>();
			break;
		default:
			throw std::invalid_argument("configuration does not exists.");

	}
	
	
	// Creating Factory Elements
	std::shared_ptr<Button> btn = factory->createBtn();
	std::shared_ptr<CheckBox> check = factory->createCheckBox();
	
	// Calling Respective Actions
	btn->paint();
	check->paint();

	return 0;
}

