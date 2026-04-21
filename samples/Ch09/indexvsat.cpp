#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("Mary");
    cout << '[' << str[6] << ']' << endl;  // undefined behavior
    cout << '[' << str.at(6) << ']' << endl;  // throws an out_of_range exception
}
