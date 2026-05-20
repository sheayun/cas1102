#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

using std::cin;
using std::cout;
using std::endl;
using StackCAS1102::Stack;

int main() {
    char next, ans;
    do {
        Stack<char> s;
        cout << "Enter a line of text:\n";
        cin.get(next);
        while (next != '\n') {
            s.push(next);
            cin.get(next);
        }
        cout << "Written backeard that is:\n";
        while (!s.isEmpty()) {
            cout << s.pop();
        }
        cout << endl;
        cout << "Again? (y/n): ";
        cin >> ans;
        cin.ignore(10000, '\n');
    } while (ans != 'n' && ans != 'N');
    return 0;
}
