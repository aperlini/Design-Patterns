### Factory Method

Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses

```mermaid
classDiagram
	
	Button <|.. WinBtn:implements
	Button <|.. LinuxBtn:implements
	Dialog <|-- WinDialog:extends
	Dialog <|-- LinuxDialog:extends
	
	class Button {
		<<interface>> 
		+render():void
		+click():void
	}
	
	class Dialog {
		<<abstract>>
		+create_btn():Button
		+render():void
	}
	
	class WinBtn {
		+render():void
		+click():void
	}
	
	class LinuxBtn {
		+render():void
		+click():void
	}
	
	class WinDialog {
		+create_btn():Button
	}
	
	class LinuxDialog {
		+create_btn():Button
	}
	
	
```

