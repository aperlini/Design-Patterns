### Bridge

Decouple an abstraction from its implementation so that the two can vary independently. It decouples *abstract* class and implementation classes. Implementations can vary without affecting client code.

```mermaid
classDiagram
		
      Bird <|.. Crow:implements
      Bird <|.. Duck:implements
      Bird <-- Flyable:uses
      Flyable <|-- FlyingCharacter:extends
	
      class Bird {
          +void make_sound()
          +void change_pos(int x, int y)
      }
      class Crow {
          +void make_sound()
          +void change_pos(int x, int y)
          -string type
          -int x
          -int y
      }
      class Duck {
          +void make_sound()
          +void change_pos(int x, int y)
          -string type
          -int x
          -int y
      }
      class Flyable {
          +void tweet()
          +void move(int x, int y)
          #Bird bird
      }
      class FlyingCharacter {
          +void tweet(int i)
          +void move(int x, int y)
          -int x
          -int y
      }
```

