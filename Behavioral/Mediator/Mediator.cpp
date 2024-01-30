#include <iostream>
#include <string>
#include <vector>

/*
 * Connected Users do not communicate directly on the server
 * The Mediator will handle the task of communications between
 * server and users
 *
 */

class ChatServer;
class ChatServerMediator;
class ConnectedUser;

/*
 * Chat Server interface creates abstractions
 * to add a user and msg from specific user
 *
 */

class ChatServer {
	public:
		virtual ~ChatServer() {}
		virtual void add_user(ConnectedUser *user) = 0;
		virtual void send_msg(ConnectedUser *user, std::string s) = 0;
};

/*
 * Chat Server Mediator hold a reference to 
 * a list of connected users. It implements 
 * the Chat Server interface, add new user to 
 * the list and dispatch all communications from 
 * clients.
 *
 */

class ChatServerMediator : public ChatServer {
	public:
		void add_user(ConnectedUser *user) override;
		void send_msg(ConnectedUser *user, std::string s) override;
	private:
		std::vector<ConnectedUser *> users_list;

};

/*
 * Connected User class hold a reference to 
 * a server instance. It enable a user to join 
 * a specific server and send and receive messages 
 *
 */

class ConnectedUser {
	public:
		ConnectedUser(std::string n) : username(n) {}
		std::string get_username();
		void join(ChatServer *server);
		void send_msg(std::string s);
		void recv_msg(ConnectedUser *user, std::string s);
	private:
		std::string username;
		ChatServer* mediator_server;
};

/*
 * ConnectedUser
 *
 */

std::string ConnectedUser::get_username() {
	return this->username;
} 

void ConnectedUser::join(ChatServer *server) {
	this->mediator_server = server;
	this->mediator_server->add_user(this);
}

void ConnectedUser::send_msg(std::string s) {
	std::cout << this->username << " sends : " << s << "\n";
	this->mediator_server->send_msg(this, s);
}

void ConnectedUser::recv_msg(ConnectedUser *user, std::string s) {
	std::cout << "Receiving : " << s << ", from : " << user->get_username() << "\n";
}

/*
 * ChatServerMediator
 *
 */


void ChatServerMediator::add_user(ConnectedUser *user) {
	this->users_list.push_back(user);
}


void ChatServerMediator::send_msg(ConnectedUser *user, std::string s) {
	for(const auto &u : this->users_list) {
		if(u != user) {
			u->recv_msg(user, s);
		}
	}
}

int main() {
	
	// Creating new Mediator Server
	ChatServer* server = new ChatServerMediator();
	
	// Creating users
	ConnectedUser user1("John");
	ConnectedUser user2("Jack");
	ConnectedUser user3("Daniel");
	
	// Users join the server
	user1.join(server);
	user2.join(server);
	user3.join(server);
	
	// Every msg sent will be displayed to everyone
	user1.send_msg("Hello World!");
	user2.send_msg("Hello Universe!");
	user3.send_msg("Hello!");

	delete server;

	return 0;
}
