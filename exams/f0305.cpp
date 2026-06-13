#include <iostream>

class Base {
public:
    virtual ~Base() { std::cout << "Base "; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived "; }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}
