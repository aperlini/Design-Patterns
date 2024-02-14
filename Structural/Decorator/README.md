### Decorator

Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality. The Decorator holds an object instance member that can be extended by attaching decorators to it.

```mermaid
classDiagram
	
	Decorator <|.. Sandwich:implements
	Sandwich <|-- SandwichDecorator:extends
	SandwichDecorator <|-- CheeseDecorator:extends
	SandwichDecorator <|-- PastramiDecorator:extends
	
	class Decorator {
		<<interface>>
		+make():void
	}
	
	class Sandwich {
		+make():void
	}
	
	class SandwichDecorator {
		<<abstract>>
		+make():void
		#sandwich:Sandwich
	}
	
	class CheeseDecorator {
		+make():void
		+add_cheese():void
	}
	
	class PastramiDecorator {
		+make():void
		+add_pastrami():void
	}
	
	
```

