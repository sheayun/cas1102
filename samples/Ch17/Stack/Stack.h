#ifndef STACK_H
#define STACK_H

namespace StackCAS1102 {

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
class Stack {
public:
    Stack();
    Stack(const Stack<T> &aStack);
    Stack<T> &operator =(const Stack<T> &rightSide);
    virtual ~Stack();
    void push(T stackFrame);
    T pop();
    bool isEmpty() const;
private:
    Node<T> *top;
}; // end class Stack

} // end namespace StackCAS1102

#endif // STACK_H
