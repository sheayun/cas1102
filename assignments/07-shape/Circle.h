#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
namespace ShapesCAS1102 {

class Circle : public Shape {
public:
    Circle();
    Circle(const string &name, const string &color, int radius);
    ~Circle();
    double calcArea() const override;
    void displayInfo() const override;
private:
    int radius;
}; // end class Circle

}; // end namespace ShapesCAS1102

#endif // CIRCLE_H
