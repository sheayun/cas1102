#include <iostream>
#include <vector>
#include <iomanip>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using ShapesCAS1102::Shape;
using ShapesCAS1102::Circle;
using ShapesCAS1102::Rectangle;
using ShapesCAS1102::Triangle;

int main() {
    vector<Shape*> shapes;
    int numShapes;
    cin >> numShapes;
    for (int i = 0; i < numShapes; ++i) {
        char shapeType;
        string name, color;
        cin >> shapeType >> name >> color;
        switch (shapeType) {
            case 'C': {
                int radius;
                cin >> radius;
                shapes.push_back(new Circle(name, color, radius));
                break;
            }
            case 'R': {
                int width, height;
                cin >> width >> height;
                shapes.push_back(new Rectangle(name, color, width, height));
                break;
            }
            case 'T': {
                int base, height;
                cin >> base >> height;
                shapes.push_back(new Triangle(name, color, base, height));
                break;
            }
            default:
                cerr << "Unknown shape type: " << shapeType << endl;
                exit(1);
        }
    }
    for (const auto &shape : shapes) {
        double a = shape->calcArea();
        shape->displayInfo();
        cout << "\tArea: " << std::fixed << std::setprecision(2) << a << endl;
    }
    for (auto &shape : shapes) {
        delete shape;
    }
}
