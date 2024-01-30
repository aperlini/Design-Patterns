#include <iostream>
#include <string>
#include <vector>

/*
 * Abstract class Game defines a virtual display_rule
 * which must be defined in every subclass that extends
 * the class. Concrete method 'play' will set the order
 * of operation to occur, when being invoked.
 *
 */
class Game {
	public:
		Game(std::string s) : game_type(s) {}
		virtual ~Game() {}
		virtual void display_rules() const = 0;
		void play() {
			this->display_rules();
			this->begin();
			this->end();
		}
		std::string get_name() const {
			return this->game_type;
		}

	private:
		std::string game_type;
		void begin() const {
			std::cout << game_type << " game has started..." << "\n";
		} 
		
		void end() const  {
			std::cout << game_type << " game has ended..." << "\n";
		}
		
	
};

/*
 * Every subsequent classes must implement
 * 'display_rules" method
 *
 */

class Chess : public Game {
	public:
		Chess(std::string s="Chess") : Game(s) {}
		void display_rules() const override {
			std::cout << get_name() << " is a board game for two players..." << "\n";
		}
};

class Go : public Game {
	public:
		Go(std::string s="Go") : Game(s) {}
		void display_rules() const override {
			std::cout << get_name() << " is an abstract strategy board game for two players..." << "\n";
		}
};

int main() {
	
	// Creating new games
	Chess chess = Chess();
	Go go = Go();
	
	// Setting and playing chess
	Game &game = chess;
	game.play();
	
	// Setting and playing go
	game = go;
	game.play();


	return 0;
}
