#include <iostream>
using namespace std;

class A
{
public:
	A(int a) : x(a), y(1) {};
	A(int a, int b) : x(a), y(b) {};
	A(): x(5), y(3) {};
	void output() { cout << x << ", " << y << endl; }
private:
	int x;
	int y;
};

int main()
{
	A c(4, 5);
	A d(7);
    A e;
	c.output();
	d.output();
    e.output();
    return 0;
}
