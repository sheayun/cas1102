#ifndef QUEUE_H
#define QUEUE_H

#include "Iterator.h"
using namespace ListNodeCAS1102;

namespace QueueCAS1102 {

template<class T>
class Queue {
public:
    typedef ListIterator<T> Iterator;
    Queue();
    Queue(const Queue<T> &aQueue);
    Queue<T> &operator =(const Queue<T> &rightSide);
    virtual ~Queue();
    void add(const T &item);
    T remove();
    bool isEmpty() const;
    Iterator begin() const { return Iterator(front); }
    Iterator end() const { return Iterator(); }
private:
    Node<T> *front;
    Node<T> *back;
}; // end class Queue

} // end namespace QueueCAS1102

#endif // QUEUE_H
