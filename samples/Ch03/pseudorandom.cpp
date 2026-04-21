#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int i;
    srand(99);
    for (i = 0; i < 10; i++) {
        cout << (rand() % 11) << endl;
    }
    srand(99);
    for (i = 0; i < 10; i++) {
        cout << (rand() % 11) << endl;
    }
}

