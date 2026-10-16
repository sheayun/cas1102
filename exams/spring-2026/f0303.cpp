#include <iostream>
using namespace std;

class A {
public:
    A(int val) : x(val) {}
    void f() { cout << x << endl; }
private:
    int x;
};

int main() {
    A *a = new A(10);
    // a->f();
    // (*a).f();
    *a.f();
    delete a;
    return 0;
}
