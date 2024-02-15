### Chain of responsibility

Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.

```mermaid
classDiagram
	
	Handler <|-- PizzaHandler:extends
	Handler <|-- BurgerHandler:extends
	Handler <|-- HotDogHandler:extends
	
	class Request {
		- order_type:FOOD_TYPE
		+ get_order():FOOD_TYPE
	}
	
	class Handler {
		<<abstract>>
		- successor:Handler
		+ get_successor() : Handler
		+ set_successor(h:Handler):void
		+ handle_request(r:Request):void
	}
	
	class PizzaHandler {
		+ handle_request(r:Request):void
	}
	
	class BurgerHandler {
		+ handle_request(r:Request):void
	}
	
	class HotDogHandler {
		+ handle_request(r:Request):void
	}
	
	
```

