#include <iostream>
using namespace std;

int f(int x, int &y)
{
    x = 5;
    y = 7;
    return x + y;
}

int main()
{
    int a = 3, b = 2;
    cout << "f: " << f(a, b) << endl
         << "a: " << a << endl
         << "b: " << b << endl;
    return 0;
}
