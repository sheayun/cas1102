#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "constructor: Base\n"; }
    virtual ~Base() { cout << "destructor: Base\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "constructor: Derived\n"; }
    ~Derived() { cout << "destructor: Derived\n"; }
};

int main()
{
    Base *p = new Derived;
    delete p;

    return 0;
}
