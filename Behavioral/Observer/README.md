### Observer

Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically. It provides a way for any object implementing the observer to subscribe and be notified of changes in another object.

```mermaid
classDiagram
	
	Observer <|.. Reader:implements
	Observer <-- NewsLetterManager:uses
	
	class Observer {
		<<interface>>
		+ update(type:SUBTYPE, msg:string):void
	}
	
	class NewsLetterManager {
		- listeners:map~SUBTYPE/vector~Observer~~
		+ subscribe(type:SUBTYPE, listener:Observer):void
		+ unsubscribe(type:SUBTYPE, listener:Observer):void
		+ notify(type:SUBTYPE, msg:string):void
	}
	
	class Publisher {
		+ weekly():void
		+ monthly():void
		+ events:NewsLetterManager
		+ msg:string
	}
	
	class Reader {
		- email:string
		- type:SUBTYPE
		+ update(type:SUBTYPE, msg:string):void
	}
```

