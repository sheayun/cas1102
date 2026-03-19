#include <iostream>
using namespace std;

int f(void);

int main()
{
    int x;
    x = f();
    cout << "In main, return value was " << x << endl;

    return 0;
}

int f(void)
{
    cout << "function called\n";
}

