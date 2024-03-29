### Proxy

Provide a surrogate or placeholder for another object to control access to it. The proxy interface creates an intermediatary to another ressource. It is especially usefull when clients want to access an object that handles a massive amount of ressources. The Proxy interface will enable some lazy initialization and provide control access to the real object which will be created only when needed.

```mermaid
classDiagram
	
	Proxy <|.. Service:implements
	Proxy <|.. ProxyService:implements
	
	class Proxy {
		<<interface>>
		+process():void
	}
	
	class Service {
		+process();void
		-init_heavy_config():void
	}
	
	class ProxyService {
		+process():void
		-obj:Service
	}
	
	
```





