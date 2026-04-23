#include <iostream>
#include <cstdlib>
using namespace std;

class PFArrayD
{
public:
    PFArrayD() : capacity(50), used(0) { a = new double[capacity]; }
    PFArrayD(int size) : capacity(size), used (0) { a = new double[capacity]; }
    PFArrayD(const PFArrayD &pfaObject);
    void addElement(double element);
    bool full() const { return (capacity == used); }
    void emtpyArray() { used = 0; }
    double &operator [](int index);
    PFArrayD &operator =(const PFArrayD &rightSide);
    ~PFArrayD();
    int getCapacity() const { return capacity; }
    int getUsed() const { return used; }
private:
    double *a;
    int capacity;
    int used;
};

PFArrayD::PFArrayD(const PFArrayD &pfaObject)
    : capacity(pfaObject.capacity), used(pfaObject.used)
{
    a = new double[capacity];
    for (int i = 0; i < used; i++)
    {
        a[i] = pfaObject.a[i];
    }
}

void PFArrayD::addElement(double element)
{
    if (used >= capacity) {
        cerr << "Attempto to exceed capacity in PFArrayD.\n";
        exit(1);
    }
    a[used++] = element;
}

double &PFArrayD::operator [](int index)
{
    if (index < 0 || index >= used) {
        cerr << "Illegal index in PFArrayD.\n";
        exit(1);
    }
    return a[index];
}

PFArrayD &PFArrayD::operator =(const PFArrayD &rightSide)
{
    if (capacity != rightSide.capacity) {
        delete [] a;
        a = new double[rightSide.capacity];
    }
    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
        a[i] = rightSide.a[i];
    return *this;
}

PFArrayD::~PFArrayD()
{
    delete [] a;
}

void testPFArrayD();

int main()
{
    cout << "This program tests the class PFArrayD.\n";
    char ans;
    do {
        testPFArrayD();
        cout << "Test again? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}

void testPFArrayD()
{
    int cap;
    cout << "Enter the capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n"
         << "Place a negative number at the end.\n";
    double next;
    cin >> next;
    while (next >= 0 && !temp.full()) {
        temp.addElement(next);
        cin >> next;
    }
    int count = temp.getUsed();
    cout << "You entered the following "
         << count << " numbers:\n";
    for (int index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value of " << next << ".)\n";
}
