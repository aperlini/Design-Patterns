### Strategy

Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it. A common interface defines which method must be implemented in every classes. The "context" class contains a reference to the *Strategy* object and implements behaviours depending on *Strategy* object. When the context object receives request, it delegates to the *Strategy* object to perform appropriate behaviour.

```mermaid
classDiagram
	
	Gun <|.. Snipper:implements
	Gun <|.. MachineGun:implements
	Gun <|.. GrenadeLauncher:implements
	Gun <-- Soldier:uses
	
	class Gun {
		<<interface>>
		+ fire():void
	}
	
	class Snipper {
		+ fire():void
	}
	
	class MachineGun {
		+ fire():void
	}
	
	class GrenadeLauncher {
		+ fire():void
	}
	
	class Soldier {
		- gun:Gun
		+ change_gun(g:Gun):void
		+ fire_at_enemy():void
	}
```

