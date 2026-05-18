#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using std::string;

namespace ShapesCAS1102 {

class Shape {
public:
    Shape();
    Shape(const string &name, const string &color);
    virtual ~Shape();
    string getName() const;
    string getColor() const;
    void setName(const string &name);
    void setColor(const string &color);
    virtual double calcArea() const = 0;
    virtual void displayInfo() const = 0;
private:
    string name;
    string color;
}; // end class Shape

}; // end namespace ShapesCAS1102

#endif // SHAPE_H
