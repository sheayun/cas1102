#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

using std::cout;
using std::cin;
using std::endl;
using TreeCAS1102::SearchTree;

int main() {
    SearchTree<int> t;
    cout << "Enter a list of nonnegative integers.\n"
         << "Place a negative integer at the end.\n";

    int next;
    cin >> next;
    while (next >= 0) {
        t.insert(next);
        cin >> next;
    }
    cout << "In sorted order:\n";
    t.inorderShow();
    cout << endl;

    return 0;
}
