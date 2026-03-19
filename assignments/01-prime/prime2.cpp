#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter a number between 2 and 1,000 (inclusive): ";
    cin >> n;
    for (int j = 2; j <= n; j++) {
        bool prime = true;
        int i = 2;
        while (i <= j / 2 && prime) {
            if (j % i == 0) {
                prime = false;
            }
            i++;
        }
        if (prime) {
            cout << j << endl;
        }
    }

    return 0;
}
