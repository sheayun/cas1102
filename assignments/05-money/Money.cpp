#include <string>
using std::string;
#include "Money.h"

Money::Money() : amount(0.0), currency("USD") {}
Money::Money(double amt, string curr) : amount(amt), currency(curr) {}
Money::Money(const Money &other) : amount(other.amount), currency(other.currency) {}

double Money::getAmount() const { return amount; }
string Money::getCurrency() const { return currency; }

Money Money::operator +(const Money &other) const
{
    if (currency != other.currency) return Money(-1.0, "ERR");
    return Money(amount + other.amount, currency);
}
Money Money::operator -(const Money &other) const
{
    if (currency != other.currency) return Money(-1.0, "ERR");
    return Money(amount - other.amount, currency);
}
bool Money::operator ==(const Money &other) const
{
    return (amount == other.amount) && (currency == other.currency);
}
bool Money::operator !=(const Money &other) const
{
    return !(*this == other);
}
bool Money::operator <(const Money &other) const
{
    if (currency != other.currency) return false;
    return amount < other.amount;
}
bool Money::operator >(const Money &other) const
{
    if (currency != other.currency) return false;
    return amount > other.amount;
}

ostream &operator <<(ostream &os, const Money &m)
{
    os << m.currency << " " << m.amount;
    return os;
}
