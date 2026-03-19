#include <iostream>
using namespace std;

int main()
{
    double balance = 1000.0;
    int year = 0;
    while (balance <= 2000.0) {
        year++;
        balance += (0.05 * balance);
    }

    cout << "Total $" << balance << " after " << year << " years.\n";
}

