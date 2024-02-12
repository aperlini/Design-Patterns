### Fly-Weight

The Flyweight design pattern is used to optimize memory usage by efficiently sharing finite-granular objects. It is particularly useful when we want to create a large number of similar objects by sharing the common parts of their states, rather than storing all the data in each object. A Flyweight object can represent many 'virtual' instances, enabling more efficient use of resources.

```mermaid
classDiagram
	
	Shape <|.. Circle:implements
	Circle <-- ShapeFactory:creates
	
	
	class Shape {
		+void draw()
	}
	
	class Circle {
		+void draw()
		+void set_x(int x)
		+void set_y(int y)
		+void set_radius(int r)
		+string get_color(enum Color c)
		-int pos_x
		-int pos_y
		-enum Color c
		-map:Color,string colors
	}
	
	class ShapeFactory {
		+static Shape *get_circle(enum Color c)
		-static map:Color,Circle* circle_map
	}
	
```

