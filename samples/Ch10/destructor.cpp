#include <iostream>
#include <string>
using namespace std;

class C
{
public:
    C() : name("Unnamed") { cout << "Constructor called for " << name << endl; }
    C(const string &n) : name(n) { cout << "Constructor called for " << name << endl; }
    ~C() { cout << "Destructor called for " << name << endl; }
private:
    string name;
};

int main()
{
    C c; // Constructor is called
    C *p = new C("Dynamic"); // Constructor is called for the object created on the heap
    delete p; // Destructor is called when p is deleted
    return 0; // Destructor is called when c goes out of scope
}
