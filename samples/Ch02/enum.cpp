#include <iostream>
using namespace std;

int main()
{
    enum class Days { Sun, Mon, Tue, Wed, Thu, Fri, Sat };
    Days d1 = Days::Mon;
    Days d2 = Days::Fri;

    cout << "d1 - " << static_cast<int> (d1) << endl << "d2 - " << static_cast<int> (d2) << endl;
}

