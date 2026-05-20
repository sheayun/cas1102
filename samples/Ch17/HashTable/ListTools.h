#ifndef LISTTOOLS_H
#define LISTTOOLS_H

namespace LinkedListCAS1102 {

template<class T>
class Node {
public:
    Node (const T& theData, Node<T> *theLink) : data(theData), link(theLink) {}
    Node<T> *getLink() const { return link; }
    const T getData() const { return data; }
    void setLink(Node<T> *theLink) { link = theLink; }
    void setData(const T &theData) { data = theData; }
private:
    T data;
    Node<T> *link;
};

template<class T>
void headInsert(Node<T> *&head, const T &theData);

template<class T>
void insert(Node<T> *afterMe, const T &theData);

template<class T>
void deleteNode(Node<T> *before);

template<class T>
void deleteFirstNode(Node<T> *&head);

template<class T>
Node<T> *search(Node<T> *head, const T &target);

} // end namespace LinkedListCAS1102

#endif // LISTTOOLS_H
