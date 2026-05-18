#include <iostream>
#include "Triangle.h"
using std::cout;
using std::endl;

namespace ShapesCAS1102 {

Triangle::Triangle() : base(0), height(0) { }

Triangle::Triangle(const string &name, const string &color, int base, int height)
    : Shape(name, color), base(base), height(height) { }

Triangle::~Triangle()
{
    cout << "Triangle destructor called for " << getName() << endl;
}

double Triangle::calcArea() const {
    return 0.5 * base * height;
}

void Triangle::displayInfo() const {
    cout << "Triangle (" << getName() << ", " << getColor()
         << ") - Base: " << base << ", Height: " << height << endl;
}

} // end namespace ShapesCAS1102
