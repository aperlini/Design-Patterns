### Builder

Separate the construction of a complex object from its representation so that the same construction process can create different representations.

```mermaid
classDiagram
	
	Builder <-- Computer:contains	
	
	class Computer {
		-disk_space:int
		-ram:int
		-brand:string
		-hdmi:bool
		+to_string():string
		+class Builder
	}
	
	class Builder {
		-disk_space:int
		-ram:int
		-brand:string
		-hdmi:bool
		+set_disk_space(ds:int):Builder
		+set_ram(ram:int):Builder
		+set_brand(b:string):Builder
		+set_hdmi(h:bool):Builder
		+build():Computer
	}
	
	
```

