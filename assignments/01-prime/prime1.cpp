#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter a number between 2 and 1,000 (inclusive): ";
    cin >> n;
    bool prime = true;
    int i = 2;
    while (i <= n / 2 && prime) {
        if (n % i == 0) {
            prime = false;
        }
        i++;
    }
    if (prime) {
        cout << n << " is a prime.\n";
    } else {
        cout << n << " is not a prime.\n";
    }

    return 0;
}
