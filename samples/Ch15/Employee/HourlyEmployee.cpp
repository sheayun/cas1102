#include <string>
#include <iostream>
#include "HourlyEmployee.h"
using std::string;
using std::cout;
using std::endl;

namespace EmployeeCAS1102
{

HourlyEmployee::HourlyEmployee() : Employee(), wageRate(0.0), hours(0.0) { }
HourlyEmployee::HourlyEmployee(const string &name, const string &ssn,
                               double wageRate, double hours)
    : Employee(name, ssn), wageRate(wageRate), hours(hours) { }
void HourlyEmployee::setRate(double newWageRate) { wageRate = newWageRate; }
void HourlyEmployee::setHours(double newHours) { hours = newHours; }
double HourlyEmployee::getRate() const { return wageRate; }
double HourlyEmployee::getHours() const { return hours; }
void HourlyEmployee::printCheck()
{
    setNetPay(wageRate * hours);
    cout << "\n___________________________________________________________\n";
    cout << "Pay to the order of " << getName() << endl;
    cout << "The sum of " << getNetPay() << " Dollars\n";
    cout << "___________________________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << getSsn() << endl;
    cout << "Hourly Employee.\nHourss worked: " << hours
         << " Rate: " << wageRate << " Pay: " << getNetPay() << endl;
    cout << "___________________________________________________________\n";
}

} // namespace EmployeeCAS1102
