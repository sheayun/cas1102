#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <string>
using std::string;
using std::ostream;

class Money {
private:
    double amount;
    string currency;

public:
    // Constructors
    Money();                         // Default: 0.0 USD
    Money(double amt, string curr);  // Parameterized
    Money(const Money &other);       // Copy Constructor

    double getAmount() const;
    string getCurrency() const;

    // Operator Overloading
    Money operator +(const Money &other) const;       // Add same currencies
    Money operator -(const Money &other) const;       // Subtract same currencies
    bool operator ==(const Money &other) const;       // Compare amount and currency
    bool operator !=(const Money &other) const;       // Negation of ==
    bool operator <(const Money &other) const;        // Compare amounts (same currency)
    bool operator >(const Money &other) const;        // Compare amounts (same currency)

    // Friend function for stream output
    friend ostream &operator <<(ostream &os, const Money &m);
};

#endif // MONEY_H
