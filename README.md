# Design Patterns

Mostly implemented in C++ (at the moment) and Java. The aim of this repository is to provide a better understanding of these design patterns by implementing them using different programming language for learning purpose.

## Design patterns

A design pattern is a reusable solution to a commonly occurring problem within a given context in software design. [...] It is a description or template for how to solve a problem that can be used in many different situations.[^1] 

### Creational

> How to instantiate objects while increasing flexibility and code reuse

- [Abstract Factory](Creational/Abstract-Factory) : an interface for creating a family of objects without specifying their concrete classes
- [Builder](Creational/Builder) : separate the construction of an object from its representation 
- [Factory Method](Creational/Factory-Method) : defines an interface for creating objects, subclasses decide which class to instantiate
- [Prototype](Creational/Prototype) : make new instances by copying existing instances
- [Singleton](Creational/Singleton) : ensures a class has only one instance and provides a global point of access to it

### Structural

> How to assemble classes and objects into larger structures

- [Adapter](Structural/Adapter) : convert an interface of a class into another interface the client expects
- [Bridge](Structural/Bridge) : decouple abstraction from implementation, so the two can be extended independently
- [Composite](Structural/Composite) : compose objects into tree structures
- [Decorator](Structural/Decorator) : attaches additional responsibilities to an object dynamically 
- [Facade](Structural/Facade) : provide a unified interface to a set of interfaces in a subsystem
- [Fly-Weight](Structural/Fly-Weight) : one instance of a class provides many "virtual instances" of a similar object
- [Proxy](Structural/Proxy) : placeholder for another object to control access to it

### Behavioral

> How classes and objects interact and distribute responsibility

- [Chain of responsibility](Behavioral/Chain-of-Responsibility) : pass a request along the chain until an object handles it
- [Command](Behavioral/Command) : encapsulates a request as an object
- [Iterator](Behavioral/Iterator) : provides a way to access elements of an aggregate object sequentially
- [Mediator](Behavioral/Mediator) : defines an object that encapsulates how a set of objects interact
- [Memento](Behavioral/Memento) : allows an object to return to one of its previous state
- [Observer](Behavioral/Observer) : defines one-to-many relationship between a set of objects
- [State](Behavioral/State) : allows an object to alter its behavior when its internal state changes
- [Strategy](Behavioral/Strategy) : define a family of algorithms and let subclasses how to implement them
- [Template Method](Behavioral/Template-Method) : lets subclasses redefine certain steps of an algorithm 
- [Visitor](Behavioral/Visitor) : represents an operation to be performed on instances of a set of classes

## References

Most of the definitions were taken from *Design Patterns: Elements of Reusable Object-Oriented Software* book written in 1994[^2] by Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides (also known as the *gang-of-four*) and *Head First : Design Patterns*[^3] by Eric Freeman, Elisabeth Freeman, Kathy Sierra and Bert Bate.

Most of the code is inspired or adapted from existing examples available on :

- [Refactoring Guru](https://refactoring.guru)
- [BTechGeeks](https://btechgeeks.com/)
- [Digital Ocean](https://www.digitalocean.com) 
- [Baeldung](https://www.baeldung.com/)

## TBD

- [x] C++ implementations
- [ ] Java implementations
- [ ] UML schemas

---

[^1]: https://en.wikipedia.org/wiki/Software_design_pattern
[^2]: https://en.wikipedia.org/wiki/Design_Patterns
[^3]: https://www.goodreads.com/en/book/show/56083609







