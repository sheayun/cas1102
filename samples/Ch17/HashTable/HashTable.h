#ifndef HASTABLE_H
#define HASTABLE_H

#include <string>
#include "ListTools.h"

using std::string;
using LinkedListCAS1102::Node;

namespace HashTableCAS1102 {

const int SIZE = 10;

class HashTable {
public:
    HashTable();
    virtual ~HashTable();
    bool containsString(string target) const;
    void put(string s);
private:
    Node<string> *hashArray[SIZE];
    static int computeHash(string s);
}; // end class HashTable

} // end namespace HashTableCAS1102

#endif // HASTABLE_H
