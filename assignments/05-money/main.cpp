#include <iostream>
#include <string>
#include <iomanip>
#include "Money.h"

/**
 * HELPER: Formats output consistently for the autograder.
 * This prevents "100.5" vs "100.50" diff failures.
 */
void printResult(const Money& m) {
    std::cout << std::fixed << std::setprecision(2) << m << std::endl;
}

// Case 1: Default Constructor
void testDefaultConstructor() {
    Money m;
    printResult(m);
}

// Case 2: Parameterized Constructor
void testParamConstructor() {
    Money m(123.456, "EUR");
    printResult(m);
}

// Case 3: Copy Constructor
void testCopyConstructor() {
    Money m1(99.99, "JPY");
    Money m2(m1);
    printResult(m2);
}

// Case 4: Addition (Success)
void testAdditionSuccess() {
    Money m1(50.50, "USD");
    Money m2(20.25, "USD");
    printResult(m1 + m2);
}

// Case 5: Addition (Mismatch Currency)
void testAdditionMismatch() {
    Money m1(50.0, "USD");
    Money m2(50.0, "EUR");
    printResult(m1 + m2);
}

// Case 6: Subtraction
void testSubtraction() {
    Money m1(100.0, "USD");
    Money m2(30.0, "USD");
    printResult(m1 - m2);
}

// Case 7: Relational == and !=
void testEquality() {
    Money m1(10.0, "USD");
    Money m2(10.0, "USD");
    Money m3(10.0, "GBP");
    std::cout << (m1 == m2 ? "TRUE" : "FALSE") << " ";
    std::cout << (m1 != m3 ? "TRUE" : "FALSE") << std::endl;
}

// Case 8: Relational < and >
void testComparison() {
    Money m1(10.0, "USD");
    Money m2(20.0, "USD");
    std::cout << (m1 < m2 ? "TRUE" : "FALSE") << " ";
    std::cout << (m2 > m1 ? "TRUE" : "FALSE") << " ";
    std::cout << (m1 > m2 ? "TRUE" : "FALSE") << std::endl;
}

int main() {
    int testId;
    if (!(std::cin >> testId)) {
        return 0;
    }

    switch (testId) {
        case 1: testDefaultConstructor(); break;
        case 2: testParamConstructor();    break;
        case 3: testCopyConstructor();     break;
        case 4: testAdditionSuccess();    break;
        case 5: testAdditionMismatch();   break;
        case 6: testSubtraction();        break;
        case 7: testEquality();           break;
        case 8: testComparison();         break;
        default:
            std::cout << "Invalid Test ID" << std::endl;
            break;
    }

    return 0;
}