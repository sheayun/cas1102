#include <string>
#include <iostream>
#include "HashTable.h"
#include "ListTools.h"

using std::string;
using std::cout;
using std::endl;
using HashTableCAS1102::HashTable;

int main()
{
    HashTable h;

    cout << "Adding dog, cat, turtle, bird" << endl;
    h.put("dog");
    h.put("cat");
    h.put("turtle");
    h.put("bird");
    cout << "Contains dog? " << h.containsString("dog") << endl;
    cout << "Contains cat? " << h.containsString("cat") << endl;
    cout << "Contains turtle? " << h.containsString("turtle") << endl;
    cout << "Contains bird? " << h.containsString("bird") << endl;
    cout << "Contains fish? " << h.containsString("fish") << endl;
    cout << "Contains cow? " << h.containsString("cow") << endl;

    return 0;
}
