### Composite

Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

```mermaid
classDiagram

	Teacher *-- Teacher:contains

	class Teacher {
          +void add(const Teacher& t)
          +void addAll(Args&&... reportees)
          +void remove(const Teacher& t)
          +vector:Teacher get_reportees()
          +void print_infos()
          +void print_reportees()
          -string name
          -int salary
          -vector:Teacher reportees
      }
```

