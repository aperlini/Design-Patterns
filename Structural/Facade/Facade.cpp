#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unistd.h>

/*
 * Device concrete class as a footprint
 * for all the subsequent classes of the
 * Audio System
 *
 */

class Device {
	public:
		Device() : volume(0), state(false) {}
		void on() {
			this->state = true;
		}
		
		void off() {
			this->state = false;
		}
		
		void volume_up() {
			this->volume++;
		}

		void volume_down() {
			if(this->volume >= 0) {
				this->volume--;
			}
		}
		
		int get_volume() {
			return this->volume;
		}
	
	protected:
		int volume;
		bool state;
};

/*
 * Subsequent concrete classes that constitute
 * each part from the Audio System
 *
 */

class Speakers {
	public:
		Speakers() {}
		Speakers(bool c) : connected(c) { }
		bool are_connected() {
			return this->connected;
		}
		void disconnect() {
			this->connected = false;
		}
		void connect() {
			this->connected = true;
		}
		std::string to_string() {
			return "\tSpeakers(connected="+std::to_string(this->connected) +")";
		}
	private:
		bool connected;
};

class Soundcard : public Device {
	public:
		Soundcard() {}
		Soundcard(int c) : channels(c) {}
		std::string to_string() {
			return "\tSoundcard(status="+std::to_string(this->state)+
						   ", volume="+std::to_string(this->volume) +
						   ", channels="+std::to_string(this->channels) +")\n";
		}
	private:
		int channels;
};

enum Options {
	aux,
	radio,
	phono
};

class Amplifier : public Device {
	public:
		Amplifier() { }
		Amplifier(std::vector<Options> opts): options(opts) { }
		std::string get_opt(Options opt) {
			return this->map_options[opt];
		}
		std::string get_options(std::vector<Options>& opts) {
			std::string settings;
			for(const auto& o : opts) {
				settings += this->get_opt(o) + " ";
			}
			return settings;
		}
		std::string to_string() {
			return "\tAmplifier(status="+std::to_string(this->state)+
						   ", volume="+std::to_string(this->volume) +
						   ", options="+this->get_options(this->options)+"\n";
		}
	private:
		std::vector<Options> options;
		std::map<Options, std::string> map_options{
			{ aux, "AUX" }, { radio, "RADIO" }, { phono, "PHONO" }
		};
};

/*
 * Facade concrete class holds references to the different
 * part of the whole system. It hides the complexity and 
 * offer public methods that will ease the setup of the system
 *
 */ 

class Facade {
	public:
		Facade() { };
		~Facade() {};
		void turn_on() {
			std::cout << "\nBuilding system...\n\n";
			sleep(0.5);
			this->build_system();
			this->display_current_status();
			sleep(1);

			std::cout << "\nPower up devices...\n";
			this->power_up_devices();
			sleep(0.5);
			std::cout << "\nTurning up volumes...\n";
			sleep(1);
			this->turn_up_soundcard(3);
			this->turn_up_amp(4);
			sleep(1);

			std::cout << "\nSystem ready : \n\n";
			this->display_current_status();
			sleep(2);
		}

		void turn_off() {
			std::cout << "\nTurning down volumes...\n";
			sleep(1);
			this->turn_down_amp();
			this->turn_down_soundcard();


			std::cout << "\nPower down devices...\n";
			sleep(1);
			this->power_off_devices();
			sleep(2);

			std::cout << "\nSystem was sucessfully turned off :  \n\n";
			this->display_current_status();
		}
	private:
		Amplifier amp;
		Speakers speakers;
		Soundcard soundcard;
		std::vector<Options> default_opts{aux, radio, phono};
		
		void build_system() {
			this->speakers = Speakers(true);
			this->soundcard = Soundcard(4);
			this->amp = Amplifier(this->default_opts);
		}	
		
		void power_up_devices() {
			this->soundcard.on();
			this->amp.on();
		}

		void power_off_devices() {
			this->soundcard.off();
			this->amp.off();
		}
		
		void turn_up_soundcard(int n) {
			for(int i=0; i<n; i++) {
				this->soundcard.volume_up();
			}
		}
		
		void turn_up_amp(int n) {
			for(int i=0; i<n; i++) {
				this->amp.volume_up();
			}
		}

		void turn_down_soundcard() {
			while(this->soundcard.get_volume() > 0) {
				this->soundcard.volume_down();
			}
		}
		
		void turn_down_amp() {
			while(this->amp.get_volume() > 0) {
				this->amp.volume_down();
			}
		}

		std::string system_status() {
			return "AudioSystem [ \n" + this->amp.to_string() + this->soundcard.to_string() + this->speakers.to_string() + "\n ]";
		}

		void display_current_status() {
			std::cout << this->system_status() << "\n";
		}

};


int main() {
	
	// Creating the Audio System
	Facade audio_sys;
	
	// Invoking turn on process
	audio_sys.turn_on();

	// Invoking turn off process
	audio_sys.turn_off();

	return 0;
}
