#include <string>
#include <iostream>
#include "SalariedEmployee.h"
using std::string;
using std::cout;
using std::endl;

namespace EmployeeCAS1102 {

SalariedEmployee::SalariedEmployee() : Employee(), weeklySalary(0.0) { }
SalariedEmployee::SalariedEmployee(const string &name, const string &ssn,
                                   double weeklySalary)
    : Employee(name, ssn), weeklySalary(weeklySalary) { }
void SalariedEmployee::setSalary(double newWeeklySalary)
    { weeklySalary = newWeeklySalary; }
double SalariedEmployee::getSalary() const { return weeklySalary; }
void SalariedEmployee::printCheck()
{
    setNetPay(weeklySalary);
    cout << "\n___________________________________________________________\n";
    cout << "Pay to the order of " << getName() << endl;
    cout << "The sum of " << getNetPay() << " Dollars\n";
    cout << "___________________________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << getSsn() << endl;
    cout << "Salaried Employee. Regular Pay: " << getNetPay() << endl;
    cout << "___________________________________________________________\n";
}

} // end namespace EmployeeCAS1102
