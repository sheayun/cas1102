#include <iostream>
#include <cstdlib>
#include "Sale.h"
using std::cerr;

namespace SaleCAS1102 {

Sale::Sale() : price(0.0) {}

Sale::Sale(double thePrice)
{
    if (thePrice >= 0) price = thePrice;
    else {
        cerr << "Error: Cannot have a negative price!\n";
        exit(1);
    }
}

double Sale::getPrice() const { return price; }

void Sale::setPrice(double newPrice)
{
    if (newPrice >= 0) price = newPrice;
    else {
        cerr << "Error: Cannot have a negative price!\n";
        exit(1);
    }
}

double Sale::bill() const { return price; }

double Sale::savings(const Sale &other) const
    { return bill() - other.bill(); }

bool operator <(const Sale &first, const Sale &second)
    { return first.bill() < second.bill(); }

} // end namespace SaleCAS1102
