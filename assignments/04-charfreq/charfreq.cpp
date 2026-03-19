#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int count[26] = {0}; // Assuming 'a' to 'z'
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            count[c - 'A']++;
        }
        else if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            cout << (char)('a' + i) << ": " << count[i] << endl;
        }
    }
}
