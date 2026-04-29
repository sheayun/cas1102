#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "Employee.h"
using std::string;

namespace EmployeeCAS1102 {
class HourlyEmployee : public Employee
{
public:
    HourlyEmployee();
    HourlyEmployee(const string &name, const string &ssn,
                   double wageRate, double hours);
    void setRate(double newWageRate);
    void setHours(double hours);
    double getRate() const;
    double getHours() const;
    void printCheck();
private:
    double wageRate;
    double hours;
}; // end HourlyEmployee

} // end namespace EmployeeCAS1102

#endif // HOURLYEMPLOYEE_H
