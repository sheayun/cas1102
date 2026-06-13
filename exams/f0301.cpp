#include <iostream>
using namespace std;

int main() {
    int v[] = {1, 2, 3, 4};
    int *p1 = v;
    int *p2 = (v + 2);
    *p1++ = 10;
    ++*p1;
    (*p2)++;
    cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    return 0;
}
