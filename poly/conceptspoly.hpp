#include "conceptsreq.hpp"
#include <vector>

// draw any GeoObj
template<typename T>
requires GeoObj<T>
void myDraw (T const& obj)
{
    obj.draw();    // call draw() according to type of object
}

// compute distance of center of gravity between two GeoObjs
template<typename T1, typename T2>
requires GeoObj<T1> && GeoObj<T2>
Coord distance (T1 const& x1, T2 const& x2)
{
    Coord c = x1.center_of_gravity() - x2.center_of_gravity();
    return c.abs();  // return coordinates as absolute values
}

// draw homogeneous collection of GeoObjs
template<typename T>
requires GeoObj<T>
void drawElems (std::vector<T> const& elems)
{
    for (std::size_type i=0; i<elems.size(); ++i) {
        elems[i].draw();    // call draw() according to type of element
    }
}
