#include "EventLog.h"

namespace EventLogCAS1102 {

// Constructor: Allocates memory on the heap
EventLog::EventLog(int cap)
{
    if (cap <= 0) {
        capacity = 0;
        count = 0;
        logEntries = nullptr;
    } else {
        capacity = cap;
        count = 0;
        logEntries = new double[capacity];
    }
}

// Copy constructor: Performs a deep copy
EventLog::EventLog(const EventLog &other)
{
    capacity = other.capacity;
    count = other.count;
    if (other.logEntries != nullptr) {
        logEntries = new double[capacity];
        for (int i = 0; i < count; i++) {
            logEntries[i] = other.logEntries[i];
        }
    } else {
        logEntries = nullptr;
    }
}

// Destructor: Clean up
EventLog::~EventLog()
{
    delete [] logEntries;
}

// Overloaded assignment operator: Performs a deep copy
EventLog &EventLog::operator=(const EventLog& other)
{
    if (capacity != other.capacity) {
        delete [] logEntries;
        capacity = other.capacity;
        logEntries = new double[capacity];
    }
    count = other.count;
    for (int i = 0; i < count; i++) {
        logEntries[i] = other.logEntries[i];
    }
    return *this;
}

// Add an element to the log; return false on buffer full
bool EventLog::addElement(double dataItem)
{
    if (count < capacity) {
        logEntries[count++] = dataItem;
        return true;
    } else {
        return false;
    }
}

// Retrieve the average over all logged data items; return 0.0 if empty
double EventLog::getAverage() const
{
    double avg;
    if (count == 0) {
        avg = 0.0;
    } else {
        double sum = 0.0;
        for (int i = 0; i < count; i++) {
            sum += logEntries[i];
        }
        avg = sum / static_cast<double> (count);
    }
    return avg;
}

// Accessor functions
int EventLog::getCapacity() const { return capacity; }
int EventLog::getCount() const { return count; }

} // end namespace EventLogCAS1102
