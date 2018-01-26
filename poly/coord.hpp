#ifndef COORD_HPP
#define COORD_HPP
#include <cstdlib>

class Coord {
  private:
    int x, y;
  public:
    Coord (int i1, int i2) : x(i1), y(i2) {
    }
    friend Coord operator- (Coord const& c1, Coord const& c2) {
        return Coord(c1.x-c2.x, c1.y-c2.y);
    }
    Coord abs() {
        return Coord(std::abs(x),std::abs(y));
    }
};
#endif // COORD_HPP
