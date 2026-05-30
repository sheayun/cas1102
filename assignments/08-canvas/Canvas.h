#ifndef CANVAS_H
#define CANVAS_H

#include <unordered_map>
#include <vector>
#include <string>
#include "Shape.h"

using std::string;
using std::unordered_map;
using std::vector;

namespace ShapesCAS1102 {

class Canvas {
public:
    Canvas();
    Canvas(const Canvas &other);
    Canvas &operator =(const Canvas &other);
    virtual ~Canvas();
    void addShapeToLayer(const string& layerName, Shape* shape);
    bool removeLayer(const string& layerName);
    double calcLayerArea(const string& layerName) const;
    double calcTotalCanvasArea() const;
    void printCanvasStructure() const;
private:
    unordered_map<string, vector<Shape *>> layers;
}; // end class Canvas

} // end namespace ShapesCAS1102

#endif // CANVAS_H
