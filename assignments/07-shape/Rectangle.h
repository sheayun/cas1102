#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

namespace ShapesCAS1102 {

class Rectangle : public Shape {
public:
    Rectangle();
    Rectangle(const string &name, const string &color, int width, int height);
    ~Rectangle();
    double calcArea() const override;
    void displayInfo() const override;
private:
    int width;
    int height;
}; // end class Rectangle

} // end namespace ShapesCAS1102

#endif // RECTANGLE_H
