#include <iostream>
#include "Rectangle.h"
using std::cout;
using std::endl;

namespace ShapesCAS1102 {

Rectangle::Rectangle() : width(0), height(0) { }

Rectangle::Rectangle(const string &name, const string &color, int width, int height)
    : Shape(name, color), width(width), height(height) { }

Rectangle::~Rectangle()
{
    cout << "Rectangle destructor called for " << getName() << endl;
}

double Rectangle::calcArea() const {
    return width * height;
}

void Rectangle::displayInfo() const {
    cout << "Rectangle (" << getName() << ", " << getColor()
         << ") - Width: " << width << ", Height: " << height << endl;
}

}; // end namespace ShapesCAS1102
