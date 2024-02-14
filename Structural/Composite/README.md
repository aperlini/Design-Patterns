### Composite

Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

```mermaid
classDiagram

	Teacher *-- Teacher:contains

	class Teacher {
          +add(t:Teacher):void
          +addAll(reportees:vector(Teacher)):void
          +remove(t:Teacher):void
          +get_reportees():vector(Teacher)
          +print_infos():void
          +print_reportees():void
          -name:string
          -salary:int
          -reportees:vector(Teacher)
      }
```

