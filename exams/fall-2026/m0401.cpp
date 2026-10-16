#include <iostream>
using namespace std;

int main()
{
    int a[] = {3, 6, 9, 12, 15, 18};
    int s = 0;
    for (int i = 1; i < 5; i++) {
        s += a[++i];
    }
    cout << s << endl;
    return 0;
}
