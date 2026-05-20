class DoublyLinkedIntNode {
public:
    DoublyLinkedIntNode() {}
    DoublyLinkedIntNode(int theData, DoublyLinkedIntNode *previous, DoublyLinkedIntNode *next)
        : data(theData), previousLink(previous), nextLink(next) {}
    int getData() const { return data; }
    DoublyLinkedIntNode *getPreviousLink() const { return previousLink; }
    DoublyLinkedIntNode *getNextLink() const { return nextLink; }
    void setData(int theData) { data = theData; }
    void setPreviousLink(DoublyLinkedIntNode *previous) { previousLink = previous; }
    void setNextLink(DoublyLinkedIntNode *next) { nextLink = next; }
private:
    int data;
    DoublyLinkedIntNode *previousLink;
    DoublyLinkedIntNode *nextLink;
}; // end class DoublyLinkedIntNode
typedef DoublyLinkedIntNode *DoublyLinkedIntNodePtr;

void headInsert(DoublyLinkedIntNodePtr &head, int theData)
{
    DoublyLinkedIntNodePtr newHead = new DoublyLinkedIntNode(theData, nullptr, head);
    head->setPreviousLink(newHead);
    head = newHead;
}

void deleteNode(DoublyLinkedIntNodePtr &head, DoublyLinkedIntNodePtr discard)
{
    if (head == discard) {
        head = head->getNextLink();
        head->setPreviousLink(nullptr);
    } else {
        DoublyLinkedIntNodePtr prev = discard->getPreviousLink();
        DoublyLinkedIntNodePtr next = discard->getNextLink();
        prev->setNextLink(next);
        if (next != nullptr) {
            next ->setPreviousLink(prev);
        }
    }
    delete discard;
}
