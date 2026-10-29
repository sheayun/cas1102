#include <iostream>
using namespace std;

double &sampleFunction(double &variable)
{
	return variable;
}

int main()
{
	double m = 99;
	cout << sampleFunction(m) << endl;
	sampleFunction(m) = 42;
	cout << m << endl;

	return 0;
}
