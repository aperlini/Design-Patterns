### Facade

Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use. Any modification to the subsystem components can be carried out without requiring any modification to the client code, since the latter interacts only with the Facade.

```mermaid
classDiagram
	
	Device <|-- Soundcard:extends
	Device <|-- Amplifier:extends
	Amplifier <-- Facade:uses
	Speaker <-- Facade:uses
	Soundcard <-- Facade:uses
	
	class Device {
		+on():void
		+off():void
		+volume_up():void
		+volume_down():void
		+get_volume():int
		#volume:int
		#state:bool
	}
	
	class Speaker {
		+are_connected():bool
		+disconnect():void
		+connect():void
		+to_string():string
		-connected:bool
	}
	
	class Soundcard {
		-channels:int
	}
	
	class Amplifier {
		+get_options(opts:vector~Options~):string
		+get_opt(opt:Options):string
		-options:vector(Options)
		-options_map:map~Options/string~
	}
	
	class Facade {
		+turn_on():void
		+turn_off():void
		-amp:Amplifier
		-speakers:Speaker
		-soundcard:Soundcard
		-default_options:vector~Options~
		-build_system():void
		-power_up_devices():void
		-power_off_devices():void
		-turn_up_soundcard(n:int):void
		-turn_up_amp(n:int):void
		-turn_down_soundcard():void
		-turn_down_amp():void
		-system_status():string
		-display_current_status():void
	}
	
```

