#include <iostream>
using namespace std;

class A
{
public:
    A(int x) : i(x), d(0.0) { }                 // A
    A(int x, double y) : i(x), d(y) { }         // B
    A() : i(0), d(0.0) { }                      // C
    void output(void) const { cout << i << ", " << d << endl; }
private:
    int i;
    double d;
};

int main()
{
    A obj(3, 4);
    obj.output();
}
