#include <iostream>
using namespace std;

class Record {
private:
    char s[100];
public:
    void doSomething(char x[]) {
        s = x;
        // strcpy(s, x);
        // strncpy(s, x, 100);
    }
    void nowLetsSee() {
        cout << s << endl;
    }
};

int main()
{
    Record r;
    char s[] = "Hello, world!";
    r.doSomething(s);
    r.nowLetsSee();

    return 0;
}
