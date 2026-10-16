#include <iostream>
#include <string>
using namespace std;

class ExceptionA {
public:
    string getMsg() const { return "ExceptionA"; }
};

class ExceptionB {
public:
    string getMsg() const { return "ExceptionB"; }
};

void g(int code) {
    if (code == 1) throw ExceptionB();
    else if (code == 2) throw ExceptionA();
    cout << "G-end ";
}

void f(int code) {
    try {
        g(code);
        cout << "F-safe ";
    }
    catch (ExceptionB &e) {
        cout << e.getMsg() << " ";
        throw ExceptionA();
    }
    cout << "F-end ";
}

int main() {
    int codes[] = {1, 0};
    for (int code : codes) {
        try {
            f(code);
            cout << "M-next ";
        }
        catch (ExceptionA &e) {
            cout << e.getMsg() << "-Caught ";
        }
        catch (ExceptionB &e) {
            cout << e.getMsg() << "-Caught ";
        }
    }
    cout << "M-end " << endl;
    return 0;
}
