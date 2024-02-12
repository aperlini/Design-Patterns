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
		+void on()
		+void off()
		+void volume_up()
		+void volume_down()
		+int get_volume()
		#int volume
		#bool state
	}
	
	class Speaker {
		+bool are_connected()
		+void disconnect()
		+void connect()
		+string to_string()
		-bool connected
	}
	
	class Soundcard {
		-int channels
	}
	
	class Amplifier {
		+string get_options(vector:Options& opts)
		+string get_opt(Options opt)
		-vector:Options options
		-map:Options,string options_map
	}
	
	class Facade {
		+void turn_on()
		+void turn_off()
		-Amplifier amp
		-Speaker speakers
		-Soundcard soundcard
		-vector:Options default_options
		-void build_system()
		-void power_up_devices()
		-void power_off_devices()
		-void turn_up_soundcard(int n)
		-void turn_up_amp(int n)
		-void turn_down_soundcard()
		-void turn_down_amp()
		-string system_status()
		-void display_current_status()
	}
	
```

