#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

namespace EmployeeCAS1102 {

class Employee
{
public:
    Employee();
    Employee(const string &name, const string &ssn);
    string getName() const;
    string getSsn() const;
    double getNetPay() const;
    void setName(const string &newName);
    void setSsn(const string &newSsn);
    void setNetPay(double newNetPay);
    void printCheck() const;
private:
    string name;
    string ssn;
    double netPay;
}; // end Employee

} // end namespace EmployeeCAS1102

#endif // EMPLOYEE_H
