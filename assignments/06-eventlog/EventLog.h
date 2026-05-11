#ifndef EVENTLOG_H
#define EVENTLOG_H

namespace EventLogCAS1102 {

class EventLog {
public:
    // Constructor: Allocate capacity on the heap
    EventLog(int cap);
    // Copy constructor: Perform a deep copy
    EventLog(const EventLog &other);
    // Destructor: Clean up
    ~EventLog();
    // Overloaded assignment operator; Perform a deep copy
    EventLog &operator=(const EventLog& other);
    // Add an element to the log; return false on buffer full
    bool addElement(double dataItem);
    // Retrieve the average over all logged data items; return 0.0 if empty
    double getAverage() const;
    // Accessor functions
    int getCapacity() const;
    int getCount() const;
private:
    double *logEntries;     // The dynamic array
    int capacity;           // Max size of the buffer
    int count;              // Actual number of entries
}; // end EventLog

}; // end namespace EventLogCAS1102

#endif // EVENTLOG_H
