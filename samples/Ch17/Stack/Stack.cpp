#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "Stack.h"

using std::cerr;

namespace StackCAS1102 {

template <class T>
Stack<T>::Stack() : top(nullptr) {}

template <class T>
Stack<T>::Stack(const Stack<T> &aStack)
{
    if (aStack.isEmpty()) {
        top = nullptr;
    } else {
        Node<T> *temp = aStack.top;
        Node<T> *end;
        end = new Node<T>(temp->getData(), nullptr);
        top = end;
        temp = temp->getLink();
        while (temp != nullptr) {
            end->setLink(new Node<T>(temp->getData(), nullptr));
            temp = temp->getLink();
            end = end->getLink();
        }
    }
}

template <class T>
Stack<T> &Stack<T>::operator =(const Stack<T> &rightSide)
{
    if (top == rightSide.top) {
        return *this;
    } else {
        Node<T> *temp = rightSide.top;
        Node<T> *end;
        end = new Node<T>(temp->getData(), nullptr);
        top = end;
        temp = temp->getLink();
        while (temp != nullptr) {
            end->setLink(new Node<T>(temp->getData(), nullptr));
            temp = temp->getLink();
            end = end->getLink();
        }
    }
    return *this;
}

template <class T>
Stack<T>::~Stack()
{
    T next;
    while (!isEmpty()) {
        next = pop();
    }
}

template <class T>
void Stack<T>::push(T stackFrame)
{
    top = new Node<T>(stackFrame, top);
}

template <class T>
T Stack<T>::pop()
{
    if (isEmpty()) {
        cerr << "Error: popping an empty stack.\n";
        exit(1);
    }
    T result = top->getData();
    Node<T> *discard = top;
    top = top->getLink();
    delete discard;
    return result;
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return (top == nullptr);
}

} // end namespace StackCAS1102