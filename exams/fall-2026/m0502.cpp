#include <iostream>
using namespace std;

void f(int n, double m)
{
	cout << 1 << endl;
}

void f(double n, int m)
{
	cout << 2 << endl;
}

void f(int n, int m)
{
	cout << 3 << endl;
}

int main()
{
	f(10, 11);
	f(6.2, 4);
	// f(4.3, 1.2);
	f(7, 9.2);
}
