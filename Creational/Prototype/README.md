### Prototype

Specify the kinds of objects to create using a prototypical instance, and create new objects by copying this prototype.

```mermaid
classDiagram
	
	Shape <|-- Circle:extends
	Shape <|-- Square:extends
	Shape <|-- Rect:extends
	
	class Shape {
		<<abstract>>
		-x:int
		-y:int
		+clone():Shape
		+get_x():int
		+get_y():int
		+to_string():string
	}
	
	class Circle {
		-radius:int
		+clone():Shape
		+to_string():string
	}
	
	class Square {
		-side:int
		+clone():Shape
		+to_string():string
	}
	
	class Rect {
		-len:int
		-bre:int
		+clone():Shape
		+get_len():int
		+get_bre():int
		+to_string():string
	}
```

