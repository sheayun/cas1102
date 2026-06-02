#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>
#include "Canvas.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using std::cout;
using std::endl;

using namespace ShapesCAS1102;

int main()
{
    // Allocate a new canvas for testing purposes
    Canvas *canvas = new Canvas();

    // Add shapes to three different layers
    canvas->addShapeToLayer("UI", new Circle("Button", "Blue", 3));
    canvas->addShapeToLayer("UI", new Rectangle("Panel", "Red", 5, 3));
    canvas->addShapeToLayer("Garbage", new Triangle("Trash1", "Green", 4, 6));
    canvas->addShapeToLayer("Garbage", new Circle("Trash2", "Black", 2));
    canvas->addShapeToLayer("Background", new Rectangle("Sky", "Cyan", 10, 5));

    // Display areas for each layer
    cout << "UI Layer Area: " << canvas->calcLayerArea("UI") << endl;
    cout << "Garbage Layer Area: " << canvas->calcLayerArea("Garbage") << endl;
    cout << "Background Layer Area: " << canvas->calcLayerArea("Background") << endl;

    // Display total canvas area and structure
    cout << "Total Canvas Area: " << canvas->calcTotalCanvasArea() << endl;
    canvas->printCanvasStructure();

    // Remove the "Garbage" layer and verify it was removed
    bool removed = canvas->removeLayer("Garbage");
    cout << "Garbage layer removed: " << (removed ? "Yes" : "No") << endl;
    cout << "Garbage Layer Area after removal: " << canvas->calcLayerArea("Garbage") << endl;

    // Again, display total canvas area and structure after removal
    cout << "Total Canvas Area after Garbage removal: " << canvas->calcTotalCanvasArea() << endl;
    canvas->printCanvasStructure();

    // Clean up memory by deleting the canvas (which should trigger destructors for all shapes)
    delete canvas;

    return 0;
}
