### Adapter

Convert the interface of a class into another interface clients expect. Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.

```mermaid
classDiagram
      Square <|.. ChessBoard:implements
      Rect <|.. TennisCourt:implements
      Square <|.. RectAdapter:implements

      class Square {
          +void set_side(int i)
          +void print_area()
      }
      class Rect {
          +void set_len(int i)
          +void set_width(int w)
          +void print_area()
      }
      class ChessBoard {
          +void set_side(int i)
          +void print_area()
          -int side
      }
      class TennisCourt {
          +void set_len(int i)
          +void set_width(int w)
          +void print_area()
          -int len
          -int width
      }
      class RectAdapter {
          +void set_side(int i)
          +void print_area()
          -Rect *rect
      }
```

