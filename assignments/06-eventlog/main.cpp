#include <iostream>
#include <cassert>
#include <cmath>
#include "EventLog.h"

using namespace EventLogCAS1102;

// Helper function to check double equality
bool isClose(double a, double b) {
    return std::abs(a - b) < 0.0001;
}

// Below for checking correct implementation of the destructor
// preventing a memory leak.
static size_t active_allocations = 0;

void* operator new(size_t size) {
    active_allocations++;
    return std::malloc(size);
}

void operator delete(void* ptr) noexcept {
    if (ptr) active_allocations--;
    std::free(ptr);
}

// Special version for arrays
void* operator new[](size_t size) {
    active_allocations++;
    return std::malloc(size);
}

void operator delete[](void* ptr) noexcept {
    if (ptr) active_allocations--;
    std::free(ptr);
}

int main() {
    int testCaseId;
    if (!(std::cin >> testCaseId)) return 1;

    switch (testCaseId) {
        case 1: { // Basic Functionality
            EventLog log(5);
            log.addElement(10.5);
            log.addElement(20.5);
            if (log.getCount() == 2 && isClose(log.getAverage(), 15.5)) {
                std::cout << "Test #1: SUCCESS" << std::endl;
            } else {
                std::cout << "Test #1: FAIL" << std::endl;
            }
            break;
        }

        case 2: { // Zero Capacity Corner Case
            EventLog log(0);
            bool added = log.addElement(1.0);
            if (log.getCapacity() == 0 && added == false && log.getAverage() == 0.0) {
                std::cout << "Test #2: SUCCESS" << std::endl;
            } else {
                std::cout << "Test #2: FAIL" << std::endl;
            }
            break;
        }

        case 3: { // Deep Copy Constructor Test
            EventLog* log1 = new EventLog(10);
            log1->addElement(50.0);

            // Trigger copy constructor
            EventLog log2 = *log1;

            // Delete original to see if log2 survives (checks for dangling pointer)
            delete log1;

            if (log2.getCount() == 1 && isClose(log2.getAverage(), 50.0)) {
                std::cout << "Test #3: SUCCESS" << std::endl;
            } else {
                std::cout << "Test #3: FAIL" << std::endl;
            }
            break;
        }

        case 4: { // Self-Assignment Corner Case
            EventLog log(10);
            log.addElement(100.0);

            // Standard check for assignment operator robustness
            log = log;

            if (log.getCount() == 1 && isClose(log.getAverage(), 100.0)) {
                std::cout << "Test #4: SUCCESS" << std::endl;
            } else {
                std::cout << "Test #4: FAIL" << std::endl;
            }
            break;
        }

        case 5: { // Buffer Overflow Case
            EventLog log(2);
            log.addElement(1.0);
            log.addElement(2.0);
            bool thirdAdded = log.addElement(3.0);

            if (log.getCount() == 2 && thirdAdded == false) {
                std::cout << "Test #5: SUCCESS" << std::endl;
            } else {
                std::cout << "Test #5: FAIL" << std::endl;
            }
            break;
        }

        case 6: { // Negative Capacity Corner Case
            // Constructor should handle negative input gracefully (e.g., treat as 0)
            EventLog log(-5);
            if (log.getCapacity() == 0 && log.getCount() == 0) {
                std::cout << "Test #6: SUCCESS" << std::endl;
            } else {
                std::cout << "Test #6: FAIL" << std::endl;
            }
            break;
        }

        case 7: { // Nominal Assignment Operator (Independence Test)
            EventLog logA(5);
            logA.addElement(1.1);

            EventLog logB(5);
            logB = logA; // Perform assignment

            // Modify logB - this should NOT affect logA
            logB.addElement(2.2);

            bool logA_untouched = (logA.getCount() == 1 && isClose(logA.getAverage(), 1.1));
            bool logB_updated = (logB.getCount() == 2 && isClose(logB.getAverage(), 1.65));

            if (logA_untouched && logB_updated) {
                std::cout << "Test #7: SUCCESS" << std::endl;
            } else {
                std::cout << "Test #7: FAIL" << std::endl;
            }
            break;
        }

        case 8: {
            size_t initial = active_allocations;
            {
                EventLog temp(10);
            } // temp is destroyed here

            if (active_allocations == initial) {
                std::cout << "Test #8: SUCCESS" << std::endl;
            } else {
                std::cout << "Test #8: FAIL (Memory Leak Detected)" << std::endl;
            }
            break;
        }

        default:
            std::cout << "Invalid Test Case ID" << std::endl;
            return 1;
    }

    return 0;
}
