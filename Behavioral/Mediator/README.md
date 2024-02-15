### Mediator

Define an object that encapsulates how a set of objects interact. Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and it lets you vary their interaction independently. The model encapsulates the way in which a set of objects interacts. It promotes weak coupling by preventing objects from explicitly referencing each other, thus allowing their interactions to be varied independently. Its use is aimed at reducing the complexity of communication between several objects or classes. The mediator class manages all communications between the various classes.

```mermaid
classDiagram
	
	ChatServer <|-- ChatServerMediator:implements
	ChatServerMediator <-- ConnectedUser:uses
	
	class ChatServer {
		<<interface>>
		+ add_user(user:ConnectedUser):void
		+ send_msg(user:ConnectedUser, s:string):void
	}
	
	class ChatServerMediator {
		- users_list:vector~ConnectedUser~
		+ add_user(user:ConnectedUser):void
		+ send_msg(user:ConnectedUser, s:string):void
	}
	
	class ConnectedUser {
		- username:string
		- server:ChatServer
		+ get_username():string
		+ join(server:CharServer):void
		+ send_msg(s:string):void
		+ recv_msg(user:ConnectedUser, s:string)
		
	}
```

