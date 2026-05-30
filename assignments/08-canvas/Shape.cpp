#include <iostream>
#include "Shape.h"
using std::cout;
using std::endl;

namespace ShapesCAS1102 {

Shape::Shape() : name("unknown"), color ("unknown") { }
Shape::Shape(const string &name, const string &color)
    : name(name), color(color) { }
Shape::~Shape() { cout << "Shape destructor called for " << name << endl; }
string Shape::getName() const { return name; }
string Shape::getColor() const { return color; }
void Shape::setName(const string &name)
    { this->name = name; }
void Shape::setColor(const string &color)
    { this->color = color; }

}; // end namespace ShapesCAS1102
