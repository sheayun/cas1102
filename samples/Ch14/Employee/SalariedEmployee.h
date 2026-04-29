#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "Employee.h"
using std::string;

namespace EmployeeCAS1102 {

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee();
    SalariedEmployee(const string &name, const string &ssn,
                     double weeklySalary);
    void setSalary(double newWeeklySalary);
    double getSalary() const;
    void printCheck();
private:
    double weeklySalary;
}; // end SalariedEmployee

}; // end namespace EmployeeCAS1102

#endif // SALARIEDEMPLOYEE_H
