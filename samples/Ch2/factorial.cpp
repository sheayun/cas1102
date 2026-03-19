#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Give me a number n: ";
    cin >> n;

    int f = 1;
    for (int x = 2; x <= n; x++) {
        f *= x;
    }

    cout << n << "! = " << f << endl;
}

