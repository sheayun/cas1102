#include <iostream>
using namespace std;

void f(int v, int *p, int &r)
{
    cout << "Inside function f:" << endl;
    cout << "Address of v: " << &v << endl;
    cout << "Value of p: " << p << endl;
    cout << "Address of r: " << &r << endl;
}

int main()
{
    int x = 10;
    int *y = &x;
    int &z = x;
    cout << "In main:" << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of y: " << y << endl;
    cout << "Address of z: " << &z << endl;
    f(x, y, z);
    return 0;
}
