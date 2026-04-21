#include <iostream>
using namespace std;

class IntPair
{
public:
    const IntPair operator +(const IntPair &x) const;
    // friend ostream &operator <<(ostream &s, const IntPair &x);
    friend ostream &operator <<(ostream &s, IntPair &x);
    void set(int x, int y);
private:
    int i1;
    int i2;
};

const IntPair IntPair::operator +(const IntPair &x) const
{
    IntPair a;
    a.i1 = i1 + x.i1;
    a.i2 = i2 + x.i2;
    return a;
}

void IntPair::set(int x, int y)
{
    i1 = x;
    i2 = y;
}

// ostream &operator <<(ostream &s, const IntPair &x)
ostream &operator <<(ostream &s, IntPair &x)
{
    s << x.i1 << ", " << x.i2;
    return s;
}

int main()
{
    IntPair k, m;
    k.set(4, 3);
    m.set(2, 8);
    cout << k + m << endl;
    return 0;
}