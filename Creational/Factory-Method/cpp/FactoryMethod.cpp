#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>

class Button {
	public:
		virtual void render() const = 0;
		virtual void click() const = 0;
};

class Dialog {
	public:
		virtual std::shared_ptr<Button> createBtn() const = 0;
		void render() {
			std::shared_ptr<Button> btn = createBtn();
			btn->render();
			btn->click();
		}
};

class WindowsBtn : public Button {
	public:
		void render() const override {
			std::cout << "Render Windows Btn" << std::endl;
		}

		void click() const override {
			std::cout << "Click on Windows Btn" << std::endl;
		}
};

class LinuxBtn : public Button {
	public:
		void render() const override {
			std::cout << "Render Linux Btn" << std::endl;
		}

		void click() const override {
			std::cout << "Click on Linux Btn" << std::endl;
		}
};

class WebBtn : public Button {
	public:
		void render() const override {
			std::cout << "Render Web Btn" << std::endl;
		}

		void click() const override {
			std::cout << "Click on Web Btn" << std::endl;
		}
};

class WindowsDialog : public Dialog {
	public:
		WindowsDialog() {}
		~WindowsDialog() {};
		std::shared_ptr<Button> createBtn() const override {
			return std::make_shared<WindowsBtn>();
		}
};

class LinuxDialog : public Dialog {
	public:
		std::shared_ptr<Button> createBtn() const override {
			return std::make_shared<LinuxBtn>();
		}
};

class WebDialog : public Dialog {
	public:
		std::shared_ptr<Button> createBtn() const override {
			return std::make_shared<WebBtn>();
		}
};


void print(std::string s) {
	std::cout << s << std::endl;
}

enum confs {
	Windows,
	Linux,
	Web
};

int get_rand(int from, int to) {
	return from + std::rand() / ((RAND_MAX) / to);
}

confs get_config() {
	
	return (confs)(get_rand(0, 3));
}



int main() {
	
	std::srand(std::time(nullptr));
	
	// Dialog pointer
	std::shared_ptr<Dialog> dialog;
	
	// Getting random config
	confs config = get_config();
	
	// Creating random Dialog
	switch(config) {
		case Windows:
			dialog = std::make_shared<WindowsDialog>();
			break;
		case Linux:
			dialog = std::make_shared<LinuxDialog>();
			break;
		case Web:
			dialog = std::make_shared<WebDialog>();
			break;
		default:
			throw std::invalid_argument("configuration does not exists.");
			
	}
	
	// Calling method on dialog
	dialog->render();

	return 0;
}

