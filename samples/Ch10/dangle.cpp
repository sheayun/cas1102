#include <iostream>
using namespace std;

int main()
{
    int *p = new int(10); // Allocate an integer on the heap and initialize it to 10
    int *q = p; // q now points to the same memory location as p
    cout << "p: " << p << endl; // Output the address stored in p
    cout << "q: " << q << endl; // Output the address stored in q
    cout << "*p: " << *p << endl; // Output the value pointed to by p
    cout << "*q: " << *q << endl; // Output the value pointed to by q

    delete p; // Deallocate the memory pointed to by p
    p = nullptr; // Set p to nullptr to avoid dangling pointer

    cout << "After deleting p:" << endl;
    cout << "p: " << p << endl; // Output the value of p (should be nullptr)
    cout << "q: " << q << endl; // Output the address stored in q
    cout << "*p: " << *p << endl; // Output the value pointed to by p (undefined behavior, but will likely cause a runtime error)
    cout << "*q: " << *q << endl; // Output the value pointed to by q (undefined behavior, but will likely cause a runtime error)

    return 0;
}
