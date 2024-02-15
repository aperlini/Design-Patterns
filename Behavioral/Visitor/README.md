### Visitor

Represent an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates. It places a new behavior into a separate class (visitor) instead of implementing it in each individual classes.

```mermaid
classDiagram
	
	Item <|.. Book:implements
	Item <|.. Fruit:implements
	Visitor <|.. ShoppingCart:implements
    
	class Visitor {
		<<interface>>
		+ visit(b:Book):void
		+ visit(f:Fruit):void
	}
	
	class Item {
		<<interface>>
		+ accept(v:Visitor):int
		+ get_price():int
	}
	
	class Book {
		- title:string
		- price:int
		+ accept(v:Visitor):int
		+ get_price():int
	}
	
	class Fruit {
		- name:string
		- price:int
		+ accept(v:Visitor):int
		+ get_price():int
	}
	
	class ShoppingCart {
		+ visit(b:Book):void
		+ visit(f:Fruit):void
	}
```

