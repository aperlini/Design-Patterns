# Design Patterns

Design patterns mostly implemented in C++ and Java for learning purpose.

## About

Most of the definitions were taken from *Design Patterns: Elements of Reusable Object-Oriented Software* book written in 1994[^ 1] by Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides (also known as the *gang-of-four*) 

### Inspiration

Most of the code is inspired or adapted from existing examples available on [BTechGeeks](https://btechgeeks.com/), [Refactoring Guru](https://refactoring.guru),  [digital ocean](https://www.digitalocean.com) or [baeldung](https://www.baeldung.com/)

## Purpose

The purpose of this repository is to provide a better understanding of these design patterns by implementing them using different programming language.

## Definitions

### Design patterns

A design pattern is a reusable solution to a commonly occurring problem within a given context in software design. [...] It is a description or template for how to solve a problem that can be used in many different situations.[^2]

### Behavioral

> Behavioral patterns involve algorithms and the delegation of  responsibilities between objects, emphasizing communication patterns.  They shift the focus from control flow to concentrate on how objects are interconnected.

### Creational

> Creational design patterns abstract the instantiation process, making a system independent of how its objects are created, composed, and represented. These patterns offer mechanisms for object creation that enhance flexibility and facilitate the reuse of existing code.


### Structural

> Structural patterns focus on the composition of classes and objects to  create larger structures. In structural class patterns, inheritance is  employed to compose interfaces or implementations. These patterns extend objects and classes into larger structures, ensuring flexibility and  efficiency in their composition.

## Implementations

- [Behavioral](Behavioral)
  - [Chain of responsibility](Behavioral/Chain-of-Responsibility)
  - [Command](Behavioral/Command)
  - [Iterator](Behavioral/Iterator)
  - [Mediator](Behavioral/Mediator)
  - [Memento](Behavioral/Memento)
  - [Observer](Behavioral/Observer)
  - [State](Behavioral/State)
  - [Strategy](Behavioral/Strategy)
  - [Template Method](Behavioral/Template-Method)
  - [Visitor](Behavioral/Visitor)
- [Creational](Creational)
  - [Abstract Factory](Creational/Abstract-Factory)
  - [Builder](Creational/Builder)
  - [Factory Method](Creational/Factory-Method)
  - [Prototype](Creational/Prototype)
  - [Singleton](Creational/Singleton)
- [Structural](Structural)
  - [Adapter](Structural/Adapter)
  - [Bridge](Structural/Bridge)
  - [Composite](Structural/Composite)
  - Decorator
  - Facade
  - Fly-Weight
  - Proxy

[^1]: https://en.wikipedia.org/wiki/Design_Patterns
[^2]: https://en.wikipedia.org/wiki/Software_design_pattern

