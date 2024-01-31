#include <iostream>
#include <string>
#include <vector>
#include <map>

/*
 * Memento Class is used as a representation
 * of the Originator state
 *
 */
class Memento {

	public:
		Memento(double t, double p, double v) : temp(t), pressure(p), volume(v) {}
		~Memento () {}
		double get_temp() {
			return this->temp;
		}
		double get_pressure() {
			return this->pressure;
		}
		double get_volume() {
			return this->volume;
		}
		void print() {
			std::cout << this->to_string();
		}
		std::string to_string() {
			return "Memento(temp=" + std::to_string(this->temp) +
						 ", pressure=" + std::to_string(this->pressure) + 
						 ", volume=" + std::to_string(this->volume) +")\n";
			
		}
		
	private:
		double temp;
		double pressure;
		double volume;

};

/*
 * Originator class offer methods to 
 * modify, save and restore the current
 * Memento instance
 *
 */

class Originator {

	public:
		void set_values(double t, double p, double v) {
			this->temp = t;
			this->pressure = p;
			this->volume = v;
		}
		Memento *save() {
			return new Memento(this->temp, this->pressure, this->volume);
		}
		void restore(Memento *m) {
			this->temp = m->get_temp();
			this->pressure = m->get_pressure();
			this->volume = m->get_volume();
		}
		std::string to_string() {
			return "Originator(temp=" + std::to_string(this->temp) +
						 ", pressure=" + std::to_string(this->pressure) + 
						 ", volume=" + std::to_string(this->volume) +")\n";
		
		}
		void print() {
			std::cout << "\ncurrent object => " << this->to_string();
		}
	private:
		double temp;
		double pressure;
		double volume;
};

/*
 * StateHistory class holds a reference to 
 * a Memento map that will store every Memento 
 * instance being saved. It offers methods to 
 * save, remove or retrieve a specific state
 * of the object
 *
 */

class StateHistory {
	public:
		~StateHistory() {
			for(const auto& pair : this->history) {
				delete pair.second;
			}
		}
		void add_state(Memento *m) {
			this->history[counter] = m;
			this->counter++;
		}
		void remove_state(int index) {
			this->history.erase(index);
		}
		Memento *get_state(int index) {
			return this->history[index];
		}
		void print_states() {
			std::string output = "\nHistory [\n";
			for(const auto &[k, v] : this->history) {
				output += "["+std::to_string(k)+"] : " + v->to_string();
			}
			std::cout << output << "\n";
		}
	private:
		int counter;
		std::map<int, Memento *> history;
};


int main() {
	
	// Creating originator and states instances
	Originator *originator = new Originator();
	StateHistory *states = new StateHistory();
	
	// setting new values and saving state
	originator->set_values(0.2, 0.3, 0.4);
	states->add_state(originator->save());
	
	// setting new values and saving state
	originator->set_values(0.9, 1.3, 2.8);	
	states->add_state(originator->save());

	// setting new values and saving state
	originator->set_values(1.2, 3.2, 1.0);
	states->add_state(originator->save());
	
	// print current values
	originator->print();

	// print states history
	states->print_states();

	// restore originator to initial state
	originator->restore(states->get_state(1));
	
	// print current values
	originator->print();

	delete originator;
	delete states;


	return 0;
}
