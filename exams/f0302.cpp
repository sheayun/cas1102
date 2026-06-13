#include <iostream>
using namespace std;

int main() {
    double *d = new double[10];
    // delete d;
    // delete d[];
    // delete d[10];
    delete [] d;
    return 0;
}
