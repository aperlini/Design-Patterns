#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


enum SUBTYPE {
	WEEKLY,
	MONTHLY,
	YEARLY
};

/*
 * Observer interface must be implemented
 * wherever a class need to receive notification
 * through the 'update' method
 *
 */
class Observer {
	public:
		virtual ~Observer() { }
		virtual void update(SUBTYPE, std::string msg) const = 0;
};

/*
 * NewsletterManager class holds a reference to a map containing
 * a list of Observers related to specific subscription type.
 * The class offer methods to un/subscribe new Observers and
 * will notify every reader based on their subscription type.
 *
 */
class NewsLetterManager {
	public:
		NewsLetterManager(std::vector<enum SUBTYPE> sub_types) {
			for(const auto& s : sub_types) {
				std::vector<Observer*> empty_listener;
				this->listeners[s] = empty_listener;
			}
		}

		void subscribe(enum SUBTYPE sub_type, Observer *listener) {
			std::vector<Observer*>& users = this->listeners[sub_type];
			users.push_back(listener);
		}
		
		void unsubscribe(enum SUBTYPE sub_type, Observer *listener) {
			std::vector<Observer*>& users = this->listeners[sub_type];
			auto it = std::find(users.begin(), users.end(), listener);
			if(it != users.end()) {
				users.erase(it);
			}
		}

		void notify(enum SUBTYPE sub_type, std::string msg) {
			std::vector<Observer*>& users = this->listeners[sub_type];
			for(const auto &user : users) {
				user->update(sub_type, msg);
			}
			
		}

		std::map<enum SUBTYPE, std::vector<Observer*>> listeners;
};

/*
 * Publisher class holds a reference to a NewsLetterManager instance.
 * It triggers notification for weekkly and monthly subscribed users.
 *
 */

class Publisher {
	public:
		~Publisher() {
			delete events;
		}
		Publisher() {
			std::vector<enum SUBTYPE> subscriptions_type{WEEKLY, MONTHLY, YEARLY};
			this->events = new NewsLetterManager(subscriptions_type);
		}
		
		void weekly() {
			this->msg = "Weekly NewsLetter Content...";
			this->events->notify(WEEKLY, this->msg);
		}
		
		void monthly() {
			this->msg = "Monthly NewsLetter Content...";
			this->events->notify(MONTHLY, this->msg);
		}

		NewsLetterManager *events;
		std::string msg;
};

/*
 * Reader class implements the Observer and
 * redefine the 'update' method logic whenever
 * a notification may occur
 *
 */

class Reader : public Observer {
	public:
		Reader(std::string s, enum SUBTYPE t) : email(s), sub_type(t) {}
		void update(enum SUBTYPE type, std::string msg) const override {
			std::string subscription_type;
			switch(sub_type) {
				case WEEKLY:
					subscription_type = "weekly";
					break;
				case MONTHLY:
					subscription_type = "monthly";
					break;
				case YEARLY:
					subscription_type = "yearly";
					break;
			}
			if(this->sub_type == type) {
				std::cout << "User : " << this->email <<  " receives " << subscription_type  << " newsletter, with msg : " << msg << "\n";
			}
		}

	private:
		std::string email;
		enum SUBTYPE sub_type;

};


int main() {
	
	// Creating new publisher
	Publisher *publisher = new Publisher();
	
	// Creating new readers
	Reader *weekly_reader_1 = new Reader("user123@email.com", WEEKLY);
	Reader *weekly_reader_2 = new Reader("user-xyz@email.com", WEEKLY);
	Reader *monthly_reader = new Reader("user789@email.com", MONTHLY);
	
	// Publisher subscribe readers
	publisher->events->subscribe(MONTHLY, monthly_reader);
	publisher->events->subscribe(WEEKLY, weekly_reader_1);
	publisher->events->subscribe(WEEKLY, weekly_reader_2);
	

	// Publisher triggers weekly and 
	// monthly notifications
	publisher->weekly();
	publisher->monthly();

	delete publisher;
	delete monthly_reader;
	delete weekly_reader_1;
	delete weekly_reader_2;

	return 0;
}
