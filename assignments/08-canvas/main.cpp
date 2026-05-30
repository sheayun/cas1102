#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>
#include "Canvas.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace ShapesCAS1102;
using std::cout;
using std::endl;
using std::cin;

// Helper function to check if a substring exists in the captured output
bool contains(const std::string& haystack, const std::string& needle) {
    return haystack.find(needle) != std::string::npos;
}

// Helper to count occurrences of a substring
int countOccurrences(const std::string& haystack, const std::string& needle) {
    int count = 0;
    size_t pos = haystack.find(needle, 0);
    while(pos != std::string::npos) {
        count++;
        pos = haystack.find(needle, pos + needle.length());
    }
    return count;
}

int main() {
    int testCase = 0;
    if (!(cin >> testCase)) {
        cout << "Invalid test case token specified." << endl;
        return 1;
    }

    switch (testCase) {
        // --------------------------------------------------------
        // TEST 1: Basic Insertion and Polymorphic Area Calculation
        // --------------------------------------------------------
        case 1: {
            Canvas canvas;
            canvas.addShapeToLayer("UI", new Circle("Button", "Red", 2));
            canvas.addShapeToLayer("Background", new Rectangle("Sky", "Blue", 10, 5));
            canvas.addShapeToLayer("UI", new Rectangle("Panel", "Gray", 4, 3));

            assert(std::abs(canvas.calcLayerArea("Background") - 50.0) < 0.001);
            assert(std::abs(canvas.calcLayerArea("UI") - (M_PI * 4.0 + 12.0)) < 0.01);
            assert(std::abs(canvas.calcTotalCanvasArea() - (50.0 + M_PI * 4.0 + 12.0)) < 0.01);
            assert(canvas.calcLayerArea("NonExistent") == 0.0);

            cout << "[PASS] Test 1: Layer insertion and Area computations." << endl;
            break;
        }

        // --------------------------------------------------------
        // TEST 2: Destructor Output Verification via Capturing stdout
        // --------------------------------------------------------
        case 2: {
            std::stringstream buffer;
            std::streambuf *oldCout = cout.rdbuf(buffer.rdbuf());

            {
                Canvas tempCanvas;
                tempCanvas.addShapeToLayer("Game", new Circle("Enemy1", "Green", 1)); // Radius updated to int
            }

            cout.rdbuf(oldCout);
            std::string output = buffer.str();

            assert(contains(output, "Circle destructor called for Enemy1"));
            assert(contains(output, "Shape destructor called for Enemy1"));

            cout << "[PASS] Test 2: Destructor memory lifecycle strings verified." << endl;
            break;
        }

        // --------------------------------------------------------
        // TEST 3: Rule of 3 (Deep Copy Constructor - Complex Environment)
        // --------------------------------------------------------
        case 3: {
            Canvas* canvasOriginal = new Canvas();
            canvasOriginal->addShapeToLayer("Background", new Rectangle("Sky", "Blue", 10, 10));
            canvasOriginal->addShapeToLayer("UI", new Circle("Cursor", "White", 1)); // Radius updated to int
            canvasOriginal->addShapeToLayer("UI", new Triangle("Widget", "Black", 3, 4));

            // Trigger Copy Constructor
            Canvas* canvasCopy = new Canvas(*canvasOriginal);

            std::stringstream buffer;
            std::streambuf *oldCout = cout.rdbuf(buffer.rdbuf());

            delete canvasOriginal; // Wipe original completely

            cout.rdbuf(oldCout);
            std::string output = buffer.str();

            // Verify original assets were fully deleted
            assert(contains(output, "Rectangle destructor called for Sky"));
            assert(contains(output, "Circle destructor called for Cursor"));
            assert(contains(output, "Triangle destructor called for Widget"));

            // Verify copy functions beautifully and entirely standalone
            assert(std::abs(canvasCopy->calcLayerArea("Background") - 100.0) < 0.001);
            assert(std::abs(canvasCopy->calcLayerArea("UI") - (M_PI * 1.0 + 6.0)) < 0.01);
            assert(std::abs(canvasCopy->calcTotalCanvasArea() - (106.0 + M_PI)) < 0.01);

            delete canvasCopy;
            cout << "[PASS] Test 3: Deep copy constructor verified with complex layers." << endl;
            break;
        }

        // --------------------------------------------------------
        // TEST 4: Rule of 3 (Copy Assignment Operator - Complex Replacement)
        // --------------------------------------------------------
        case 4: {
            Canvas canvasA;
            canvasA.addShapeToLayer("L1", new Circle("Target", "Red", 3));
            canvasA.addShapeToLayer("L2", new Rectangle("Prop", "Green", 2, 2));

            Canvas canvasB;
            canvasB.addShapeToLayer("OldLayer", new Rectangle("Floor", "Brown", 20, 2));
            canvasB.addShapeToLayer("OldLayer", new Circle("Obstacle", "Grey", 5)); // Radius updated to int

            std::stringstream buffer;
            std::streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            canvasB = canvasA; // Trigger Assignment

            cout.rdbuf(oldCout);
            std::string output = buffer.str();

            // Verify clean disposal of preexisting structures inside CanvasB
            assert(contains(output, "Rectangle destructor called for Floor"));
            assert(contains(output, "Circle destructor called for Obstacle"));

            // Verify copy assignments matched data correctly
            assert(std::abs(canvasB.calcLayerArea("L1") - (M_PI * 9.0)) < 0.001);
            assert(std::abs(canvasB.calcLayerArea("L2") - 4.0) < 0.001);
            assert(std::abs(canvasB.calcTotalCanvasArea() - (M_PI * 9.0 + 4.0)) < 0.001);

            cout << "[PASS] Test 4: Copy assignment operator verified with multi-layer replacement." << endl;
            break;
        }

        // --------------------------------------------------------
        // TEST 5: Single Layer Removal Engine
        // --------------------------------------------------------
        case 5: {
            Canvas canvas;
            canvas.addShapeToLayer("Static", new Rectangle("Wall1", "Black", 1, 10));
            canvas.addShapeToLayer("Static", new Rectangle("Wall2", "Black", 2, 5));
            canvas.addShapeToLayer("Dynamic", new Circle("Player", "White", 1)); // Radius updated to int

            std::stringstream buffer;
            std::streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            bool removed = canvas.removeLayer("Static");

            cout.rdbuf(oldCout);
            std::string output = buffer.str();

            assert(removed == true);
            assert(contains(output, "Rectangle destructor called for Wall1"));
            assert(contains(output, "Rectangle destructor called for Wall2"));
            assert(!contains(output, "Circle destructor called for Player"));
            assert(canvas.calcLayerArea("Static") == 0.0);
            assert(canvas.removeLayer("NonExistent") == false);

            cout << "[PASS] Test 5: Layer removal frees memory and handles tracking arrays." << endl;
            break;
        }

        // --------------------------------------------------------
        // TEST 6: Rule of 3 (Self-Assignment Protection Safeguard)
        // --------------------------------------------------------
        case 6: {
            Canvas canvas;
            canvas.addShapeToLayer("Main", new Circle("Avatar", "Gold", 4));
            canvas.addShapeToLayer("Main", new Rectangle("Banner", "Blue", 3, 7));

            std::stringstream buffer;
            std::streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            canvas = canvas;

            cout.rdbuf(oldCout);
            std::string output = buffer.str();

            assert(output.empty() || !contains(output, "destructor called"));
            assert(std::abs(canvas.calcLayerArea("Main") - (M_PI * 16.0 + 21.0)) < 0.001);

            cout << "[PASS] Test 6: Self-assignment safe-guards verified." << endl;
            break;
        }

        // --------------------------------------------------------
        // TEST 7: Multi-Layer Aggregation Deep-Validation Chain
        // --------------------------------------------------------
        case 7: {
            Canvas canvasSource;
            canvasSource.addShapeToLayer("HUD", new Circle("HealthBar", "Red", 2));
            canvasSource.addShapeToLayer("HUD", new Rectangle("Frame", "Silver", 10, 2));
            canvasSource.addShapeToLayer("Environment", new Triangle("Tree", "Green", 4, 10));
            canvasSource.addShapeToLayer("Environment", new Rectangle("Ground", "Brown", 100, 5));
            canvasSource.addShapeToLayer("FX", new Circle("Particle1", "Orange", 1)); // Radius updated to 1 int

            Canvas canvasDest;
            canvasDest.addShapeToLayer("Temp", new Circle("Trash", "Pink", 1));

            canvasDest = canvasSource;

            // Double validation layer queries checking target data matching accuracy
            double expectedHud = M_PI * 4.0 + 20.0;
            double expectedEnv = 20.0 + 500.0;
            double expectedFx  = M_PI * 1.0; // Updated to match radius 1 math (pi * 1^2)

            assert(std::abs(canvasDest.calcLayerArea("HUD") - expectedHud) < 0.01);
            assert(std::abs(canvasDest.calcLayerArea("Environment") - expectedEnv) < 0.01);
            assert(std::abs(canvasDest.calcLayerArea("FX") - expectedFx) < 0.01);
            assert(std::abs(canvasDest.calcTotalCanvasArea() - (expectedHud + expectedEnv + expectedFx)) < 0.01);

            cout << "[PASS] Test 7: Multi-layer aggregation and state copy transfer." << endl;
            break;
        }

        // --------------------------------------------------------
        // TEST 8: Deep Copy Lifetime Autonomy Verification
        // --------------------------------------------------------
        case 8: {
            Canvas* original = new Canvas();
            original->addShapeToLayer("LayerA", new Circle("SharedName", "Blue", 2));
            original->addShapeToLayer("LayerB", new Circle("SharedName", "Red", 4));

            Canvas* cloneObj = new Canvas(*original);

            std::stringstream buffer;
            std::streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            delete original;

            cout.rdbuf(oldCout);
            std::string output = buffer.str();

            assert(countOccurrences(output, "Circle destructor called for SharedName") == 2);

            assert(std::abs(cloneObj->calcLayerArea("LayerA") - (M_PI * 4.0)) < 0.001);
            assert(std::abs(cloneObj->calcLayerArea("LayerB") - (M_PI * 16.0)) < 0.001);

            delete cloneObj;
            cout << "[PASS] Test 8: Deep copy independent lifetimes verified." << endl;
            break;
        }

        default:
            cout << "Error: Unknown test case sequence code specified." << endl;
            return 1;
    }

    return 0;
}
