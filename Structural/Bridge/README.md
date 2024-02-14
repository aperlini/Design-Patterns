### Bridge

Decouple an abstraction from its implementation so that the two can vary independently. It decouples *abstract* class and implementation classes. Implementations can vary without affecting client code.

```mermaid
classDiagram
		
      Bird <|.. Crow:implements
      Bird <|.. Duck:implements
      Bird <-- Flyable:uses
      Flyable <|-- FlyingCharacter:extends
	
      class Bird {
      	  <<interface>>
          +make_sound():void
          +change_pos(x:int, y:int):void
      }
      class Crow {
          +make_sound():void
          +change_pos(x:int, y:int):void
          -type:string
          -x:int
          -y:int
      }
      class Duck {
          +make_sound():void
          +change_pos(x:int, y:int):void
          -type:string
          -x:int
          -y:int
      }
      class Flyable {
      	  <<abstract>>
          +tweet():void
          +move(x:int, y:int):void
          #bird:Bird
      }
      class FlyingCharacter {
          +tweet(i:int):void
          +move(x:int, y:int):void
          -x:int
          -y:int
      }
```

