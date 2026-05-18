#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

namespace ShapesCAS1102 {

class Triangle : public Shape {
public:
    Triangle();
    Triangle(const string &name, const string &color, int base, int height);
    ~Triangle();
    double calcArea() const override;
    void displayInfo() const override;
private:
    int base;
    int height;
}; // end class Triangle

}; // end namespace ShapesCAS1102

#endif // TRIANGLE_H
