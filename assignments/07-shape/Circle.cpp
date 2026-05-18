#include <iostream>
#include <cmath>
#include "Circle.h"
using std::cout;
using std::endl;

namespace ShapesCAS1102 {

Circle::Circle() : radius(0) { }

Circle::Circle(const string &name, const string &color, int radius)
    : Shape(name, color), radius(radius) { }

    Circle::~Circle()
{
    cout << "Circle destructor called for " << getName() << endl;
}

double Circle::calcArea() const {
    return M_PI * radius * radius;
}

void Circle::displayInfo() const {
    cout << "Circle (" << getName() << ", " << getColor()
         << ") - Radius: " << radius << endl;
}

}; // end namespace ShapesCAS1102
