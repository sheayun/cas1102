#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "Queue.h"

using std::cerr;

namespace QueueCAS1102 {

template<class T>
Queue<T>::Queue() : front(nullptr), back(nullptr) {}

template<class T>
Queue<T>::Queue(const Queue<T> &aQueue)
{
    if (aQueue.isEmpty()) {
        front = back = nullptr;
    } else {
        Node<T> *temp = aQueue.front;
        back = new Node<T>(temp->getData(), nullptr);
        front = back;
        temp = temp->getLink();
        while (temp != nullptr) {
            back->setLink(new Node<T>(temp->getData(), nullptr));
            temp = temp->getLink();
            back = back->getLink();
        }
    }
}

template<class T>
Queue<T> &Queue<T>::operator =(const Queue<T> &rightSide)
{
    if (front == rightSide.front) {
        return *this;
    } else {
        T next;
        while (!isEmpty()) {
            next = remove();
        }
    }
    if (rightSide.isEmpty()) {
        front = back = nullptr;
    } else {
        Node<T> *temp = rightSide.front;
        back = new Node<T>(temp->getData(), nullptr);
        front = back;
        temp = temp->getLink();
        while (temp != nullptr) {
            back->setLink(new Node<T>(temp->getData(), nullptr));
            temp = temp->getLink();
            back = back->getLink();
        }
    }
    return *this;
}

template<class T>
Queue<T>::~Queue()
{
    T next;
    while (!isEmpty()) {
        next = remove();
    }
}

template<class T>
void Queue<T>::add(const T &item)
{
    if (isEmpty()) {
        front = back = new Node<T>(item, nullptr);
    } else {
        back->setLink(new Node<T>(item, nullptr));
        back = back->getLink();
    }
}

template<class T>
T Queue<T>::remove()
{
    if (isEmpty()) {
        cerr << "Error: Removing an item from an empty queue.\n";
        exit(1);
    } else {
        T result = front->getData();
        Node<T> *discard = front;
        front = front->getLink();
        if (front == nullptr) {
            back = nullptr;
        }
        delete discard;
        return result;
    }
}

template<class T>
bool Queue<T>::isEmpty() const
{
    return (back == nullptr);
}

} // end namespace QueueCAS1102
