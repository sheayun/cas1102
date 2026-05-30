#include <iostream>
#include "Canvas.h"

using std::string;
using std::cout;
using std::endl;

namespace ShapesCAS1102 {

Canvas::Canvas() { }

Canvas::Canvas(const Canvas &other)
{
    for (const auto &layer : other.layers) {
        const string &layerName = layer.first;
        const vector<Shape *> &originalVector = layer.second;
        vector<Shape *> copiedVector;
        for (const auto &shapePtr : originalVector) {
            copiedVector.push_back(shapePtr->clone());
        }
        layers[layerName] = copiedVector;
    }
}

Canvas &Canvas::operator =(const Canvas &other)
{
    if (this == &other) {
        return *this;
    }

    // 1. Clean up existing dynamically allocated shapes
    for (auto &layer : layers) {
        for (Shape *shape : layer.second) {
            delete shape;
        }
    }
    layers.clear();

    // 2. Deep copy data from the other object
    for (const auto &layer : other.layers) {
        vector<Shape *> copiedVector;
        for (const auto &shapePtr : layer.second) {
            copiedVector.push_back(shapePtr->clone());
        }
        layers[layer.first] = copiedVector;
    }
    return *this;
}

Canvas::~Canvas()
{
    for (auto &layer : layers) {
        for (Shape *shape : layer.second) {
            delete shape;
        }
    }
}

void Canvas::addShapeToLayer(const string& layerName, Shape* shape)
{
    if (shape != nullptr) {
        layers[layerName].push_back(shape);
    }
}

bool Canvas::removeLayer(const string& layerName)
{
    auto it = layers.find(layerName);
    if (it == layers.end()) {
        return false;
    }

    for (Shape *shape : it->second) {
        delete shape;
    }
    layers.erase(it);
    return true;
}

double Canvas::calcLayerArea(const string& layerName) const
{
    auto it = layers.find(layerName);
    if (it == layers.end()) {
        return 0.0;
    }

    double totalArea = 0.0;
    for (const auto &shapePtr : it->second) {
        totalArea += shapePtr->calcArea();
    }
    return totalArea;
}

double Canvas::calcTotalCanvasArea() const
{
    double totalArea = 0.0;
    for (const auto &layer : layers) {
        for (const auto &shapePtr : layer.second) {
            totalArea += shapePtr->calcArea();
        }
    }
    return totalArea;
}

void Canvas::printCanvasStructure() const
{
    for (const auto &layer : layers) {
        cout << "Layer: " << layer.first << endl;
        for (const auto &shapePtr : layer.second) {
            shapePtr->displayInfo();
        }
    }
}

} // end namespace ShapesCAS1102