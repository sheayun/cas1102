#include <iostream>
using namespace std;

void f(int i)
{
    cout << "f(int) called with " << i << endl;
}

void f(int *p)
{
    cout << "f(int *) called with " << *p << endl;
}

int main()
{
    int x = 1;
    int *y = new int(2);
    f(x);
    f(y);
    f(NULL);
    delete y;
    return 0;
}
