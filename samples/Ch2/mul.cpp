#include <iostream>
using namespace std;

int main()
{
    for (int x = 2; x <= 9; x++) {
        for (int y = 2; y <= 9; y++) {
            cout << x << " * " << y << " = " << x * y << endl;
        }
        cout << endl;
    }
}

