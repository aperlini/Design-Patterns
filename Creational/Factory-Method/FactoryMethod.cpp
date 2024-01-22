#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>

class Button {
	public:
		virtual ~Button() {}
		virtual void render() const = 0;
		virtual void click() const = 0;
};

class Dialog {
	public:
		virtual ~Dialog() {}
		virtual Button *createBtn() const = 0;
		void render() {
			Button *btn = createBtn();
			btn->render();
			btn->click();
			delete btn;
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
		Button *createBtn() const override {
			return new WindowsBtn();
		}
};

class LinuxDialog : public Dialog {
	public:
		Button *createBtn() const override {
			return new LinuxBtn();
		}
};

class WebDialog : public Dialog {
	public:
		Button *createBtn() const override {
			return new WebBtn();
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
	Dialog *dialog;
	
	// Getting random config
	confs config = get_config();
	
	// Creating random Dialog
	switch(config) {
		case Windows:
			dialog = new WindowsDialog();
			break;
		case Linux:
			dialog = new LinuxDialog();
			break;
		case Web:
			dialog = new WebDialog();
			break;
		default:
			throw std::invalid_argument("configuration does not exists.");
			
	}
	
	// Calling method on dialog
	dialog->render();
	
	// Free Memory
	delete dialog;

	return 0;
}

