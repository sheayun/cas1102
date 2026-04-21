#include <iostream>
using namespace std;

class A
{
public:
    static int getX() { return ++x; }
private:
    static int x;
};

int A::x = 0;

int main()
{
    A k, m, n;
    cout << k.getX() << ", "
         << m.getX() << ", "
         << n.getX() << endl;
}
