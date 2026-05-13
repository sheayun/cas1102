#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include "PFArray.cpp"
#include "PFArrayBak.cpp"
using PFArrayCAS1102::PFArrayBak;

int main()
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayBak<string> a(cap);
    cout << "Enter " << cap << " strings\n"
         << "separated by blanks.\n";
    string next;
    for (int i = 0; i < cap; i++) {
        cin >> next;
        a.addElement(next);
    }
    int count = a.getNumberUsed();
    cout << "The following " << count
         << " strings read and stored:\n";
    int index;
    for (index = 0; index < count; index++) {
        cout << a[index] << " ";
    }
    cout << endl;

    cout << "Backing up array.\n";
    a.backup();
    cout << "Emptying array.\n";
    a.emptyArray();
    cout << a.getNumberUsed()
         << " strings are now stored in the array.\n";
    cout << "Restoring array.\n";
    a.restore();
    count = a.getNumberUsed();
    cout << "The following " << count
         << " strings are now stored:\n";
    for (index = 0; index < count; index++) {
        cout << a[index] << " ";
    }
    cout << endl;

    cout << "End of demonstration.\n";

    return 0;
}
