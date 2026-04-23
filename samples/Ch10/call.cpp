#include <iostream>
using namespace std;

void f(int v, int *p)
{
    cout << "Inside function f, before modification:" << endl
         << "v, *p: " << v << ", " << *p << endl;
    v = 10;
    *p = 20;
    cout << "Inside function f, after modification:" << endl
         << "v, *p: " << v << ", " << *p << endl;
}

int main()
{
    int x = 1, y = 2;
    int *p = &y;
    cout << "Before calling function f:" << endl
         << "x, y: " << x << ", " << y << endl;
    f(x, p);
    cout << "After calling function f:" << endl
         << "x, y: " << x << ", " << y << endl;
    return 0;
}
