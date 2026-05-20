#ifndef QUEUE_H
#define QUEUE_H

namespace QueueCAS1102 {

template <class T>
class Node {
public:
    Node(T theData, Node<T> *theLink) : data(theData), link(theLink) {}
    Node<T> *getLink() const { return link; }
    const T getData() const { return data; }
    void setLink(Node<T> *theLink) { link = theLink; }
    void setData(const T &theData) { data = theData; }
private:
    T data;
    Node<T> *link;
}; // end class Node

template <class T>
class Queue {
public:
    Queue();
    Queue(const Queue<T> &aQueue);
    Queue<T> &operator =(const Queue<T> &rightSide);
    virtual ~Queue();
    void add(T item);
    T remove();
    bool isEmpty() const;
private:
    Node<T> *front;
    Node<T> *back;
}; // end class Queue

} // end namespace QueueCAS1102
#endif // QUEUE_H
