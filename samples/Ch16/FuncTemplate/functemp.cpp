#include <iostream>
using std::cout;
using std::endl;

template<class T>
void swapValues(T &variable1, T &variable2)
{
    T temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

int main()
{
    int integer1 = 1, integer2 = 2;
    cout << "Original integer valus are "
         << integer1 << " " << integer2 << endl;
    swapValues(integer1, integer2);
    cout << "Swpped integer valus are "
         << integer1 << " " << integer2 << endl;

    char symbol1 = 'A', symbol2 = 'B';
    cout << "Original character valus are "
         << symbol1 << " " << symbol2 << endl;
    swapValues(symbol1, symbol2);
    cout << "Swapped character valus are "
         << symbol1 << " " << symbol2 << endl;

    return 0;
}
