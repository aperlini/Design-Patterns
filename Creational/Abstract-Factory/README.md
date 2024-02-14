### Abstract Factory

Provide an interface for creating families of related or dependent objects without specifying their concrete classes.

```mermaid
classDiagram
	
	Button <|.. LinuxBtn:implements
	Button <|.. WinBtn:implements
	CheckBox <|.. LinuxCheckBox:implements
	CheckBox <|.. WinCheckBox:implements
	GUIFactory <|-- LinuxFactory:extends
	GUIFactory <|-- WinFactory:extends
	
	class Button {
		<<interface>>
		+paint():void
	}
	
	class LinuxBtn {
		+paint():void
	}
	
	class WinBtn {
		+paint():void
	}
	
	class CheckBox {
		<<interface>>
		+paint():void
	}
	
	class LinuxCheckBox {
		+paint():void
	}
	
	class WinCheckBox {
		+void paint()
	}
	
	class GUIFactory {
		<<interface>>
		+createBtn():Button
		+createCheckBox():CheckBox
	}
	
	class LinuxFactory {
		+createBtn():Button
		+createCheckBox():CheckBox
	}
	
	class WinFactory {
		+createBtn():Button
		+createCheckBox():CheckBox
	}
```

