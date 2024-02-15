### Memento

Without violating encapsulation, capture and externalize an object's internal state so that the object can be restored to this state later. It is used to store the internal state of an object so that any save state of the object can be restored.

```mermaid
classDiagram
	
	Memento <-- Originator:uses
	Memento <-- StateHistory:uses
	
	class Memento {
		- temp:double
		- pressure:double
		- volume:double
		+ get_temp():double
		+ get_pressure():double
		+ get_volume():double
		+ print():void
		+ to_string():string
	}
	
	class Originator {
		- temp:double
		- pressure:double
		- volume:double
		+ set_values(t:double, p:double, v:double):void
		+ save():Memento
		+ restore(m:Memento):void
		+ to_string():string
		+ print():void
	}
	
	class StateHistory {
		- counter:int
		- history:map~int/Memento~
		+ add_state(m:Memento):void
		+ remove_state(index:int):void
		+ get_state(index:int):Memento
		+ print_states():void
	}
```

