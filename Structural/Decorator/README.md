### Decorator

Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality. The Decorator holds an object instance member that can be extended by attaching decorators to it.

```mermaid
classDiagram
	
	Decorator <|.. Sandwich:implements
	Sandwich <|-- SandwichDecorator:extends
	SandwichDecorator <|-- CheeseDecorator:extends
	SandwichDecorator <|-- PastramiDecorator:extends
	
	class Decorator {
		+void make()
	}
	
	class Sandwich {
		+void make()
	}
	
	class SandwichDecorator {
		+void make()
		#Sandwich *sandwich
	}
	
	class CheeseDecorator {
		+void make()
		+void add_cheese()
	}
	
	class PastramiDecorator {
		+void make()
		+void add_pastrami()
	}
	
	
```

