#ifndef ITERATOR_H
#define ITERATOR_H

namespace ListNodeCAS1102 {

template<class T>
class Node {
public:
    Node(T theData, Node<T> *theLink) : data(theData), link(theLink) {}
    const T &getData() const { return data; }
    Node<T> *getLink() const { return link; }
    void setData(const T &theData) { data = theData; }
    void setLink(Node<T> *theLink) { link = theLink; }
private:
    T data;
    Node<T> *link;
}; // end class Node

template<class T>
class ListIterator {
public:
    ListIterator() : current(nullptr) {}
    ListIterator(Node<T> *initial) : current(initial) {}
    const T &operator *() const { return current->getData(); }
    const T &operator ++() // prefix increment
    {
        current = current->getLink();
        return *this;
    }
    ListIterator operator ++(int) // postfix increment
    {
        ListIterator startVersion(current);
        current = current->getLink();
        return startVersion;
    }
    bool operator ==(const ListIterator &rightSide) const
        { return current == rightSide.current; }
    bool operator !=(const ListIterator &rightSide) const
        { return current != rightSide.current; }
    // The default assignment operator and copy constructor
    // should work correctly for ListIterator.
private:
    Node<T> *current;
}; // end class ListIterator

} // end namespace ListNodeCAS1102

#endif // ITERATOR_H
