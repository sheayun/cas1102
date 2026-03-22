#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1(5);
    vector<int> v2(5, 2);
    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int> v4 {10, 20, 30, 40, 50};

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;

    for (int i = 0; i < v3.size(); i++)
        cout << v3[i] << " ";
    cout << endl;

    for (int i = 0; i < v4.size(); i++)
        cout << v4[i] << " ";
    cout << endl;

    vector<int> v5(2);
    cout << v5[10] << endl;

    vector<int> v6(v2);
    v2[2] = 50;
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;
    for (int i = 0; i < v6.size(); i++)
        cout << v6[i] << " ";
    cout << endl;

    return 0;
}
