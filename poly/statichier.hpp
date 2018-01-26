#include "coord.hpp"

// concrete geometric object class Circle
// - \bfseries not derived from any class
class Circle {
  public:
    void draw() const;
    Coord center_of_gravity() const;
    //...
};

// concrete geometric object class Line
// - \bfseries not derived from any class
class Line {
  public:
    void draw() const;
    Coord center_of_gravity() const;
    //...
};
//...
